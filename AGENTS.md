# エージェント向けの注意

ディレクトリ構成と使い方は README.md にある。ここには、コードを見ただけではわからない決まりを書く。

## 置き場所と名前

- ライブラリ本体は必ず `src/` の下に置き、`src/` の外のファイルに依存させない。利用時は `src/` だけを展開して `#include "shogo-library/math/modint.hpp"` の形で使う。
- `src/base/` (`functions.hpp` の `midpoint` など) にはどのファイルから依存してもよい。同じ処理を手で書き直さず、base のものを使う。
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
- 区間は半開区間。前提違反は `assert`。解なしは、添字か 0 以上の整数の値 (個数・最小値・離散対数など) なら -1、ほかの値なら `optional`。`Cost` のようなテンプレートの値型は、0 以上でも `optional` にする (double のこともあり -1 は合わない)。列も `std::optional<std::vector<T>>` にする (空の列が正しい答えになることがあり、空で解なしを表すと区別できない)。未到達の距離は `max / 4`。
- 復元が要るときは、値を返す関数と `_restore` の 2 本にする。
  - `_restore` は値も含めた構造体を返す (`{length, indices}`・`{cost, edges}` など)。
  - 辺は番号でなく `Edge` で返す。
  - グラフの経路 (路・閉路) は `graph.hpp` の `Path<Cost> {cost, vertices, edges}` で返す (`shortest_path`・`tree_diameter_restore`・`eulerian_trail_*`・`find_cycle_*`・`chinese_postman_restore`)。`vertices` は `edges` より 1 つ多く、辺がなくても始点を入れる。
  - 値と復元が手間をかけずに一緒に求まるなら、2 本に分けず 1 つの構造体で返してよい (`shortest_path_dijkstra`・`minimum_spanning_tree`・`hungarian`)。
  - 値を返す版がない関数 (`general_matching` など) には `_restore` を付けない。
- `.first`・`.second`・`std::get` では中身が読み取りにくい組は、名前付きのメンバを持つ型で返す。メンバは構造化束縛で受け取る順に並べる。
  - 型名は関数名をキャメルケースにしたもの (`MinimumSpanningTree`・`ShortestPath`)。複数の関数で共有するもの、関数名が動詞やアルゴリズム名のものは中身を表す名詞にする (`SubsetSum`・`LongestSubstring`・`Match`・`Assignment`)。
  - メンバ関数の結果の型はクラスの中に置く (`RangeMode::Mode`・`Matrix::ReducedRowEchelon`)。
  - 意味が決まっている組は `pair` のままでよい: `divmod` の (商, 余り)、`factorize` の (素数, 指数)、区間 `[l, r)`、map と同じ (キー, 値)、ACL と同じ API (`MinCostFlow::flow`・`slope`、二部マッチング)。
- `inf` を受け取る関数は、最後の引数にして既定を `max / 4` にする。
- グラフのアルゴリズムは `const Graph<Cost>&` を受け取る自由関数にする。Graph のメンバは表現の操作 (`add_edge`, `read`, `operator[]`, `edges` など) だけにする。木は `Graph` を private 継承しているので、`tree.graph()` を通して渡す。木専用の関数は `const Tree<Cost>&` を受け取り、`tree_util.hpp` に置く。
- グリッドは `Grid` (`src/utility/range.hpp`) の `contains`・`index`・`neighbors4/8` を使う。`DXY` のような方向の配列は足さない。
- 1 引数のコンストラクタには `explicit` を付ける。ただし Matrix・FPS・modint などの値型には付けない。

## 関数と型の名前

- 同じ意味の操作は同じ名前にする: 値の取得は `val()`、祖先への移動は `hop`、成分 (連結成分・UnionFind のグループなど) は `groups`。
- 二分探索は、イテレータを返すなら `lower_bound`・`upper_bound`、添字を返すなら `bisect_left`・`bisect_right`。
- 同じ系統の関数は対象を先に書き、エディタの補完で並ぶようにする (`subset_sum`・`subset_sum_max`・`subset_sum_count`、`knapsack`・`knapsack_bounded`・`knapsack_unbounded`)。`convex_hull`・`edit_distance` のように言葉として決まっている名前はそのまま。
- 個数を返す自由関数は `<対象>_count` (`prime_count`・`subset_sum_count`・`subarray_sum_count`)。メンバ関数で、引数を渡して数える操作は `std::count`・`count_if` と同じく `count`・`count_<対象>` (`count_prefix`・`count_less`)、持っている数を返すだけのものは `size()` と同じく名詞 (`pattern_count`)。
- mod を法とする演算は `_mod` を後ろに付ける (`pow_mod`・`inv_mod`・`mul_mod`・`sqrt_mod`・`det_mod`。ACL・Library Checker と同じ)。
- 列を返すものは `enumerate_`、関数を受け取って呼ぶものは `for_each_` (`enumerate_quotients`・`for_each_quotient`)。
- 同じ問題を解くアルゴリズムが複数あるなら `<問題>_<アルゴリズム>` にする (`shortest_path_dijkstra`・`shortest_path_bellman_ford`・`subset_sum_max_bitset`)。問題そのものの名前 (`shortest_path(g, s, t)`) は、いちばん普通に使う形に付ける。
- 変種は接尾辞で表す: `_directed`・`_undirected`、`_by_weight`・`_by_value`、`_meet_in_the_middle`、`_bitset`、`_geometric`、`_2d`、`_mod`。整数のまま正確に返す版は `_squared`・`_doubled` (`closest_point_pair_squared`・`polygon_area_doubled`)。
- 最小化・最大化する問題の名前は、省略せず `minimum_`・`maximum_` にする (`minimum_spanning_tree`・`minimum_set_cover`・`maximum_independent_set`。Library Checker の問題名とも揃う)。演算の名前や ACL・std 由来のものは `min`・`max` のまま (`min_plus_convolution_*`・`min_cut`・`min_left`・`max_right`・`subset_sum_max`)。
- 誤字は直す。改名したら古い名前は残さない (`[[deprecated]]` の別名も置かない)。

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

push の前に、前回の push に対する CI がすべて完了していることを確認する。実行中や待機中なら、完了を待ってから push する。

`main` に push すると CI の verify が走り、終わると auto-verifier が `.verify-helper/timestamps.remote.json` を更新するコミット (`[auto-verifier] verify commit ...`) を `origin/main` に積む。手元はたいていその分遅れているので、push の前に毎回確かめる。

```sh
git fetch
git log --oneline main..origin/main
```

auto-verifier のコミットだけなら `git rebase origin/main` してから push する。それ以外のコミットがあれば、rebase する前に中身を確かめる。`timestamps.remote.json` は auto-verifier が管理するので、手で編集しない。
