---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\"\"\"\u5916\u90E8\u30B8\u30E3\u30C3\u30B8\u3092\u4F7F\
    \u308F\u305A\u3001\u30D8\u30C3\u30C0\u30FB\u5358\u4F53\u30C6\u30B9\u30C8\u30FB\
    docs \u3092\u691C\u8A3C\u3059\u308B\u3002\"\"\"\n\nimport argparse\nfrom concurrent.futures\
    \ import ThreadPoolExecutor, as_completed\nfrom pathlib import Path\nimport os\n\
    import re\nimport subprocess\nimport tempfile\n\n\nROOT = Path(__file__).resolve().parents[1]\n\
    SANITIZER_TESTS = (\n    \"algebra/monoid.test.cpp\",\n    \"data_structures/binary-trie.1.test.cpp\"\
    ,\n    \"data_structures/binary-trie.2.test.cpp\",\n    \"data_structures/disjoint-sparse-table.test.cpp\"\
    ,\n    \"data_structures/rollback-unionfind.test.cpp\",\n    \"dp/edit-distance.test.cpp\"\
    ,\n    \"graph/max-flow.test.cpp\",\n    \"math/modular-arithmetic.test.cpp\"\
    ,\n    \"math/number-theory.test.cpp\",\n    \"math/fps.test.cpp\",\n)\n\n\ndef\
    \ command(args, *, input=None, timeout=180):\n    try:\n        result = subprocess.run(\n\
    \            args, input=input, cwd=ROOT, text=True, capture_output=True, timeout=timeout\n\
    \        )\n    except subprocess.TimeoutExpired as error:\n        raise RuntimeError(f\"\
    timeout: {' '.join(map(str, args))}\") from error\n    if result.returncode:\n\
    \        raise RuntimeError(\n            f\"exit {result.returncode}: {' '.join(map(str,\
    \ args))}\\n\"\n            f\"{result.stdout}{result.stderr}\"\n        )\n \
    \   if result.stderr:\n        print(result.stderr, end=\"\", flush=True)\n  \
    \  return result.stdout\n\n\ndef parallel_check(name, targets, check, jobs):\n\
    \    failures = []\n    with ThreadPoolExecutor(max_workers=jobs) as executor:\n\
    \        futures = {executor.submit(check, path): path for path in targets}\n\
    \        for done, future in enumerate(as_completed(futures), 1):\n          \
    \  try:\n                future.result()\n            except Exception as error:\n\
    \                failures.append(f\"{futures[future]}: {error}\")\n          \
    \  if done % 20 == 0 or done == len(targets):\n                print(f\"{name}:\
    \ {done}/{len(targets)}\", flush=True)\n    if failures:\n        raise RuntimeError(\"\
    \\n\".join(failures))\n\n\ndef check_headers(cxx, std, jobs):\n    def check(path):\n\
    \        command(\n            [cxx, f\"-std={std}\", \"-Wall\", \"-Wextra\",\
    \ \"-I\", str(ROOT),\n             \"-fsyntax-only\", \"-x\", \"c++\", \"-\"],\n\
    \            input=f'#include \"{path.as_posix()}\"\\nint main() {{}}\\n',\n \
    \       )\n\n    parallel_check(\"headers\", sorted(Path(\"src\").rglob(\"*.hpp\"\
    )), check, jobs)\n\n\ndef check_unittests(cxx, std, jobs, sanitizers=False):\n\
    \    targets = (\n        [Path(\"test/unittest\") / path for path in SANITIZER_TESTS]\n\
    \        if sanitizers else sorted(Path(\"test/unittest\").rglob(\"*.test.cpp\"\
    ))\n    )\n    flags = [\"-O2\"]\n    if sanitizers:\n        flags = [\"-O1\"\
    , \"-g\", \"-fno-omit-frame-pointer\",\n                 \"-fsanitize=address,undefined\"\
    , \"-fno-sanitize-recover=all\"]\n    with tempfile.TemporaryDirectory(prefix=\"\
    shogo-library-check-\") as directory:\n        def check(path):\n            executable\
    \ = Path(directory) / path.as_posix().replace(\"/\", \"_\")\n            command([cxx,\
    \ f\"-std={std}\", \"-Wall\", \"-Wextra\", *flags,\n                     str(path),\
    \ \"-o\", str(executable)])\n            output = command([str(executable)])\n\
    \            if output != \"Hello World\\n\":\n                raise RuntimeError(f\"\
    expected 'Hello World\\\\n', got {output!r}\")\n\n        parallel_check(\"sanitizers\"\
    \ if sanitizers else \"unittests\", targets, check, jobs)\n\n\ndef check_docs():\n\
    \    errors = []\n    documented = {}\n    pages = sorted(Path(\"docs\").rglob(\"\
    *.md\"))\n    for path in pages:\n        text = path.read_text()\n        for\
    \ line_number, line in enumerate(text.splitlines(), 1):\n            if \"{{\"\
    \ in line or \"{%\" in line:\n                errors.append(f\"{path}:{line_number}:\
    \ Liquid \u306E\u958B\u59CB\u8A18\u6CD5\u304C\u542B\u307E\u308C\u3066\u3044\u307E\
    \u3059\")\n        match = re.search(r\"^documentation_of:\\s*//(\\S+)\\s*$\"\
    , text, re.MULTILINE)\n        if not match:\n            errors.append(f\"{path}:\
    \ documentation_of \u304C\u3042\u308A\u307E\u305B\u3093\")\n            continue\n\
    \        header = Path(match[1])\n        if not header.is_file():\n         \
    \   errors.append(f\"{path}: \u53C2\u7167\u5148 {header} \u304C\u3042\u308A\u307E\
    \u305B\u3093\")\n        if header in documented:\n            errors.append(f\"\
    {path}: {documented[header]} \u3068\u53C2\u7167\u5148\u304C\u91CD\u8907\u3057\u3066\
    \u3044\u307E\u3059\")\n        documented[header] = path\n    for header in sorted(Path(\"\
    src\").rglob(\"*.hpp\")):\n        if \"internal\" not in header.parts and header\
    \ not in documented:\n            errors.append(f\"{header}: \u5BFE\u5FDC\u3059\
    \u308B docs \u304C\u3042\u308A\u307E\u305B\u3093\")\n    if errors:\n        raise\
    \ RuntimeError(\"\\n\".join(errors))\n    print(f\"docs: {len(pages)} pages checked\"\
    , flush=True)\n\n\ndef main():\n    parser = argparse.ArgumentParser(description=__doc__)\n\
    \    parser.add_argument(\"checks\", nargs=\"+\", choices=[\"headers\", \"unittests\"\
    , \"sanitizers\", \"docs\"])\n    parser.add_argument(\"--std\", choices=[\"gnu++17\"\
    , \"gnu++20\", \"gnu++23\"], default=\"gnu++17\")\n    parser.add_argument(\"\
    --cxx\", default=\"g++\")\n    parser.add_argument(\"--jobs\", type=int, default=2)\n\
    \    args = parser.parse_args()\n    if args.jobs < 1:\n        parser.error(\"\
    --jobs must be positive\")\n    # Path \u306E\u5217\u6319\u3082\u542B\u3081\u3001\
    \u3069\u306E\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u304B\u3089\u8D77\u52D5\u3057\
    \u3066\u3082\u540C\u3058\u5BFE\u8C61\u3092\u691C\u8A3C\u3059\u308B\u3002\n   \
    \ os.chdir(ROOT)\n    try:\n        for check in args.checks:\n            if\
    \ check == \"headers\":\n                check_headers(args.cxx, args.std, args.jobs)\n\
    \            elif check == \"unittests\":\n                check_unittests(args.cxx,\
    \ args.std, args.jobs)\n            elif check == \"sanitizers\":\n          \
    \      check_unittests(args.cxx, args.std, args.jobs, sanitizers=True)\n     \
    \       else:\n                check_docs()\n    except RuntimeError as error:\n\
    \        parser.exit(1, f\"{error}\\n\")\n\n\nif __name__ == \"__main__\":\n \
    \   main()\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/check_library.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/check_library.py
layout: document
redirect_from:
- /library/tools/check_library.py
- /library/tools/check_library.py.html
title: tools/check_library.py
---
