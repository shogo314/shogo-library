#!/usr/bin/env python3
"""外部ジャッジを使わず、ヘッダ・単体テスト・docs を検証する。"""

import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
import os
import re
import subprocess
import tempfile


ROOT = Path(__file__).resolve().parents[1]
SANITIZER_TESTS = (
    "algebra/monoid.test.cpp",
    "data_structures/binary-trie.1.test.cpp",
    "data_structures/binary-trie.2.test.cpp",
    "graph/max-flow.test.cpp",
    "math/modular-arithmetic.test.cpp",
    "math/number-theory.test.cpp",
    "math/fps.test.cpp",
)


def command(args, *, input=None, timeout=180):
    try:
        result = subprocess.run(
            args, input=input, cwd=ROOT, text=True, capture_output=True, timeout=timeout
        )
    except subprocess.TimeoutExpired as error:
        raise RuntimeError(f"timeout: {' '.join(map(str, args))}") from error
    if result.returncode:
        raise RuntimeError(
            f"exit {result.returncode}: {' '.join(map(str, args))}\n"
            f"{result.stdout}{result.stderr}"
        )
    if result.stderr:
        print(result.stderr, end="", flush=True)
    return result.stdout


def parallel_check(name, targets, check, jobs):
    failures = []
    with ThreadPoolExecutor(max_workers=jobs) as executor:
        futures = {executor.submit(check, path): path for path in targets}
        for done, future in enumerate(as_completed(futures), 1):
            try:
                future.result()
            except Exception as error:
                failures.append(f"{futures[future]}: {error}")
            if done % 20 == 0 or done == len(targets):
                print(f"{name}: {done}/{len(targets)}", flush=True)
    if failures:
        raise RuntimeError("\n".join(failures))


def check_headers(cxx, std, jobs):
    def check(path):
        command(
            [cxx, f"-std={std}", "-Wall", "-Wextra", "-I", str(ROOT),
             "-fsyntax-only", "-x", "c++", "-"],
            input=f'#include "{path.as_posix()}"\nint main() {{}}\n',
        )

    parallel_check("headers", sorted(Path("src").rglob("*.hpp")), check, jobs)


def check_unittests(cxx, std, jobs, sanitizers=False):
    targets = (
        [Path("test/unittest") / path for path in SANITIZER_TESTS]
        if sanitizers else sorted(Path("test/unittest").rglob("*.test.cpp"))
    )
    flags = ["-O2"]
    if sanitizers:
        flags = ["-O1", "-g", "-fno-omit-frame-pointer",
                 "-fsanitize=address,undefined", "-fno-sanitize-recover=all"]
    with tempfile.TemporaryDirectory(prefix="shogo-library-check-") as directory:
        def check(path):
            executable = Path(directory) / path.as_posix().replace("/", "_")
            command([cxx, f"-std={std}", "-Wall", "-Wextra", *flags,
                     str(path), "-o", str(executable)])
            output = command([str(executable)])
            if output != "Hello World\n":
                raise RuntimeError(f"expected 'Hello World\\n', got {output!r}")

        parallel_check("sanitizers" if sanitizers else "unittests", targets, check, jobs)


def check_docs():
    errors = []
    documented = {}
    pages = sorted(Path("docs").rglob("*.md"))
    for path in pages:
        text = path.read_text()
        for line_number, line in enumerate(text.splitlines(), 1):
            if "{{" in line or "{%" in line:
                errors.append(f"{path}:{line_number}: Liquid の開始記法が含まれています")
        match = re.search(r"^documentation_of:\s*//(\S+)\s*$", text, re.MULTILINE)
        if not match:
            errors.append(f"{path}: documentation_of がありません")
            continue
        header = Path(match[1])
        if not header.is_file():
            errors.append(f"{path}: 参照先 {header} がありません")
        if header in documented:
            errors.append(f"{path}: {documented[header]} と参照先が重複しています")
        documented[header] = path
    for header in sorted(Path("src").rglob("*.hpp")):
        if "internal" not in header.parts and header not in documented:
            errors.append(f"{header}: 対応する docs がありません")
    if errors:
        raise RuntimeError("\n".join(errors))
    print(f"docs: {len(pages)} pages checked", flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("checks", nargs="+", choices=["headers", "unittests", "sanitizers", "docs"])
    parser.add_argument("--std", choices=["gnu++17", "gnu++20"], default="gnu++17")
    parser.add_argument("--cxx", default="g++")
    parser.add_argument("--jobs", type=int, default=2)
    args = parser.parse_args()
    if args.jobs < 1:
        parser.error("--jobs must be positive")
    # Path の列挙も含め、どのディレクトリから起動しても同じ対象を検証する。
    os.chdir(ROOT)
    try:
        for check in args.checks:
            if check == "headers":
                check_headers(args.cxx, args.std, args.jobs)
            elif check == "unittests":
                check_unittests(args.cxx, args.std, args.jobs)
            elif check == "sanitizers":
                check_unittests(args.cxx, args.std, args.jobs, sanitizers=True)
            else:
                check_docs()
    except RuntimeError as error:
        parser.exit(1, f"{error}\n")


if __name__ == "__main__":
    main()
