# エージェント向けの注意

ディレクトリ構成と使い方は README.md にある。ここには、コードを見ただけではわからない決まりを書く。

## 置き場所と名前

- ライブラリ本体は必ず `src/` の下に置き、`src/` の外のファイルに依存させない。利用時は `src/` だけを展開して `#include "shogo-library/math/modint.hpp"` の形で使う。
- ファイル名のハイフンとアンダースコアは使い分けている。ハイフンは「ほぼ一単語」とみなせる名前 (`lazy-segtree`, `number-theory`)、アンダースコアは別々の語をつなぐ名前 (`graph_util`, `vector_func`, `type_alias`)。どちらかに統一しない。
- 内部の namespace は `internal_<ファイル名>` にする。
- docs は `docs/<分類>/<名前>.md` に置き、`documentation_of` でヘッダに対応付ける。

## テスト

- 置き場所:
  - `test/unittest/<src の分類>/`: 問題を使わない単体テスト。分類は最初に include する `src/<分類>/` に合わせる。ダミーの ITP1_1_A を PROBLEM にして、通ったら Hello World を出力する。
  - `test/yosupo/<Library Checker のカテゴリ>/`
  - `test/aoj/<コース名>/` (alds1, cgl, dpl, dsl, grl, itp1, itp2, ntl)。コース以外の問題は `test/aoj/volume<問題番号÷100>/<番号>.test.cpp`。
  - `test/atcoder/abc/` と `test/atcoder/other/`: `.cpp` にして `#define IGNORE` を付け、CI では検証しない (わざとそうしている)。
  - `test/yukicoder/`: 分けない。名前は問題番号。
- unittest のファイル名は src のファイル名に合わせる (`container_func.test.cpp`)。観点を足すなら `container_func-member`・`vector-line` のようにする。
- 同じ問題を別の解き方で解いたテストは `.1`・`.2` と番号を付ける (`dpl-5-e.1.test.cpp`)。
- テストを新しく書く前に、`grep -rl 'problem/<問題名>"' test` のように PROBLEM の URL で既存のテストを探す。ファイル名で探すと見落とすことがある。あれば既存のものを `git mv` で `.1` にして、新しいものを `.2` にする。`cat >` は既存のファイルを黙って上書きするので、書いたあとに `git status` で `M` になっていないか確かめる。
- CI は `-std=gnu++17 -Wall -Wextra -O2` で検証する。新しいテストは手元で `-std=gnu++17` と `-std=gnu++20` の両方で通ることを確かめる。

## 書き方

- GNU 拡張 (GCC) を前提にしてよい。`__int128` は GNU モードでは `std::is_integral`・`std::is_scalar` などが真になるので、`Vector<__int128_t, 3>` のように普通の整数型と同じに使える。std の型特性を特殊化したり、独自の型特性で包んだりはしない。
- C++20 で自然な書き方を優先し、`#if __cplusplus >= 202002L` で C++17 版も置く (例: `bit.hpp`・`saturating.hpp`・`functions.hpp`)。制約は C++20 で concept・requires、C++17 で `ENABLE_IF_T` マクロ。
- 公開 API の添字・サイズ・個数・長さ・次数は `long long` にする。外から見えない内部の格納や計算は、問題がなければ `int` でよい。`size_t` は使わない (-1 の番兵や逆順ループが壊れる)。ビット位置や ccw の符号のような「種類を表す値」は `int`。
- 型を省略したときの既定は `long long` にする (`int` だと重み 1e9 の和が黙ってあふれる)。値から型を推論できるよう推論ガイドを付ける。
- 組み込み型へのキャストは `static_cast` にする。`(T)x` や `int(x)` は使わない。`T(1)` や `mint(x)` は構築なのでそのままでよい。
- 区間は半開区間。前提違反は `assert`。解なしは、添字か 0 以上の整数の値 (個数・最小値・離散対数など) なら -1、ほかの値なら `optional`。`Cost` のようなテンプレートの値型は、0 以上でも `optional` にする (double のこともあり -1 は合わない)。列も `std::optional<std::vector<T>>` にする (空の列が正しい答えになることがあり、空で解なしを表すと区別できない)。未到達の距離は `max / 4`。復元が要るときは、値を返す関数と `_restore` の 2 本にする。
- グラフのアルゴリズムは `const Graph<Cost>&` を受け取る自由関数にする。Graph のメンバは表現の操作 (`add_edge`, `read`, `operator[]`, `edges` など) だけにする。木は `Graph` を private 継承しているので、`tree.graph()` を通して渡す。木専用の関数は `const Tree<Cost>&` を受け取り、`tree_util.hpp` に置く。
- グリッドは `Rect` (`src/utility/range.hpp`) の `contains`・`index`・`neighbors4/8` を使う。`DXY` のような方向の配列は足さない。
- 1 引数のコンストラクタには `explicit` を付ける。ただし Matrix・FPS・modint などの値型には付けない。

## 整形

- CI は clang-format 19.1.7 で `--dry-run --Werror` をかける。コミットの前に、同じ版で確かめる。

  ```sh
  find src test \( -name '*.hpp' -o -name '*.cpp' \) -print0 | xargs -0 clang-format --dry-run --Werror
  ```

- ほかの版で整形しない。テストのファイル名を変えると、名前が一致するヘッダが include の先頭に並び直されることがあるので、改名したら整形し直す。

## docs

- docs の Markdown は Jekyll が Liquid として処理する。`{{` や `{%` を書くとサイトのビルドが落ちる (verify は通るので気づきにくい)。`{ {1, 1}, {1, 0} }` のように空白を入れ、書いたら `grep -rn '{{\|{%' docs` で確かめる。
- 書式は `docs/data_structures/segtree.md` に揃える。front matter → 概要 1〜2 文 → 使用例 → 注意など → `## メンバ関数` (自由関数なら `## 関数`) の表 (| 関数 | 説明 | 計算量 |) → `## メンバ変数` (あれば) → 最後に `## 関連`。
- 表のコードの中の `|` はエスケープしない (kramdown では `\|` がそのまま表示される)。

## 意図した仕様 (直さない)

- `src/math/fps.hpp` の `FPS` の `+=`・`-=` は、結果の末尾の 0 を取り除く。
- `modint` などの snake_case の型名と、std と同じ名前のグローバル関数はわざとそうしている。
- そのため `using namespace std;` は使わない方針で、テストにも書かない (`rank` は `std::rank` とぶつかるなど、曖昧になってコンパイルできない)。README とサイトのトップページにも書いてある。

## 計測

- この環境の `timeout` コマンドは時間を 100 ms 刻みに切り上げるので、実行時間を測るのに使わない。

## push の前に

`main` に push すると CI の verify が走り、終わると auto-verifier が `.verify-helper/timestamps.remote.json` を更新するコミット (`[auto-verifier] verify commit ...`) を `origin/main` に積む。手元はたいていその分遅れているので、push の前に毎回確かめる。

```sh
git fetch
git log --oneline main..origin/main
```

auto-verifier のコミットだけなら `git rebase origin/main` してから push する。それ以外のコミットがあれば、rebase する前に中身を確かめる。`timestamps.remote.json` は auto-verifier が管理するので、手で編集しない。
