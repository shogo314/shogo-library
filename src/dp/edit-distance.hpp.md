---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl/dpl-1-e.test.cpp
    title: test/aoj/dpl/dpl-1-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/dp/edit-distance.test.cpp
    title: test/unittest/dp/edit-distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\
      \u30BF\u30A4\u30F3\u8DDD\u96E2)"
    links: []
  bundledCode: "#line 2 \"src/dp/edit-distance.hpp\"\n\n/**\n * @file edit-distance.hpp\n\
    \ * @brief \u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\
    \u30A4\u30F3\u8DDD\u96E2)\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <iterator>\n#include <vector>\n\n/**\n * @brief s \u3092 t \u306B\u5909\u3048\
    \u308B\u306E\u306B\u5FC5\u8981\u306A\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\
    \u63DB\u306E\u6700\u5C0F\u56DE\u6570 O(nm)\n * \u8981\u7D20\u306F == \u3067\u6BD4\
    \u3079\u308B\u3002\u30E1\u30E2\u30EA\u306F O(m)\n */\ntemplate <typename R1, typename\
    \ R2>\nlong long edit_distance(const R1& s, const R2& t) {\n    auto a = std::begin(s);\n\
    \    auto b = std::begin(t);\n    long long n = std::end(s) - a, m = std::end(t)\
    \ - b;\n    // dp[j] \u306F s[0, i) \u3068 t[0, j) \u306E\u7DE8\u96C6\u8DDD\u96E2\
    \n    std::vector<long long> dp(m + 1);\n    for (long long j = 0; j <= m; j++)\
    \ dp[j] = j;\n    for (long long i = 1; i <= n; i++) {\n        long long diag\
    \ = dp[0];  // s[0, i - 1) \u3068 t[0, j - 1) \u306E\u7DE8\u96C6\u8DDD\u96E2\n\
    \        dp[0] = i;\n        for (long long j = 1; j <= m; j++) {\n          \
    \  long long up = dp[j];\n            dp[j] = std::min({dp[j] + 1, dp[j - 1] +\
    \ 1, diag + (a[i - 1] == b[j - 1] ? 0 : 1)});\n            diag = up;\n      \
    \  }\n    }\n    return dp[m];\n}\n\n/**\n * @brief \u7DE8\u96C6\u8DDD\u96E2\u3068\
    \u3001s \u3092 t \u306B\u5909\u3048\u308B\u64CD\u4F5C\u5217\n */\nstruct EditDistance\
    \ {\n    enum class Type { Insert,\n                      Erase,\n           \
    \           Replace };\n    struct Operation {\n        Type type;\n        long\
    \ long source_index;  //!< \u5143\u306E s \u306E\u6DFB\u5B57\u3002\u633F\u5165\
    \u3067\u306F\u9699\u9593\u306E\u4F4D\u7F6E [0, |s|]\n        long long target_index;\
    \  //!< t \u306E\u6DFB\u5B57\u3002\u524A\u9664\u3067\u306F\u9699\u9593\u306E\u4F4D\
    \u7F6E [0, |t|]\n    };\n    long long distance;\n    std::vector<Operation> operations;\n\
    };\n\n/**\n * @brief \u7DE8\u96C6\u8DDD\u96E2\u3068\u3001\u305D\u306E\u6700\u5C0F\
    \u56DE\u6570\u306E\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\u63DB\u3092\u6C42\
    \u3081\u308B\n * \u6642\u9593\u30FB\u30E1\u30E2\u30EA O(nm)\u3002\u4E00\u81F4\u3059\
    \u308B\u8981\u7D20\u3092\u901A\u904E\u3059\u308B\u64CD\u4F5C\u306F\u542B\u3081\
    \u306A\u3044\u3002\n * \u64CD\u4F5C\u9806\u306B\u3001\u5909\u66F4\u4E2D\u306E\u5217\
    \u306E target_index \u306E\u4F4D\u7F6E\u3078\u633F\u5165\u30FB\u524A\u9664\u30FB\
    \u7F6E\u63DB\u3059\u308B\u3002\n * \u633F\u5165\u30FB\u7F6E\u63DB\u3059\u308B\u5024\
    \u306F t[target_index]\u3002\n */\ntemplate <typename R1, typename R2>\nEditDistance\
    \ edit_distance_restore(const R1& s, const R2& t) {\n    auto a = std::begin(s);\n\
    \    auto b = std::begin(t);\n    const long long n = std::end(s) - a, m = std::end(t)\
    \ - b;\n    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m\
    \ + 1));\n    for (long long i = 0; i <= n; ++i) dp[i][0] = i;\n    for (long\
    \ long j = 0; j <= m; ++j) dp[0][j] = j;\n    for (long long i = 1; i <= n; ++i)\
    \ {\n        for (long long j = 1; j <= m; ++j) {\n            dp[i][j] = std::min({dp[i\
    \ - 1][j] + 1, dp[i][j - 1] + 1,\n                                 dp[i - 1][j\
    \ - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)});\n        }\n    }\n    EditDistance\
    \ result{dp[n][m], {}};\n    result.operations.reserve(result.distance);\n   \
    \ long long i = n, j = m;\n    while (i > 0 || j > 0) {\n        if (i > 0 &&\
    \ j > 0 && dp[i][j] == dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)) {\n\
    \            if (!(a[i - 1] == b[j - 1])) result.operations.push_back({EditDistance::Type::Replace,\
    \ i - 1, j - 1});\n            --i, --j;\n        } else if (i > 0 && dp[i][j]\
    \ == dp[i - 1][j] + 1) {\n            result.operations.push_back({EditDistance::Type::Erase,\
    \ i - 1, j});\n            --i;\n        } else {\n            assert(j > 0);\n\
    \            result.operations.push_back({EditDistance::Type::Insert, i, j - 1});\n\
    \            --j;\n        }\n    }\n    std::reverse(result.operations.begin(),\
    \ result.operations.end());\n    return result;\n}\n"
  code: "#pragma once\n\n/**\n * @file edit-distance.hpp\n * @brief \u7DE8\u96C6\u8DDD\
    \u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2)\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include\
    \ <vector>\n\n/**\n * @brief s \u3092 t \u306B\u5909\u3048\u308B\u306E\u306B\u5FC5\
    \u8981\u306A\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\u63DB\u306E\u6700\u5C0F\
    \u56DE\u6570 O(nm)\n * \u8981\u7D20\u306F == \u3067\u6BD4\u3079\u308B\u3002\u30E1\
    \u30E2\u30EA\u306F O(m)\n */\ntemplate <typename R1, typename R2>\nlong long edit_distance(const\
    \ R1& s, const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n\
    \    long long n = std::end(s) - a, m = std::end(t) - b;\n    // dp[j] \u306F\
    \ s[0, i) \u3068 t[0, j) \u306E\u7DE8\u96C6\u8DDD\u96E2\n    std::vector<long\
    \ long> dp(m + 1);\n    for (long long j = 0; j <= m; j++) dp[j] = j;\n    for\
    \ (long long i = 1; i <= n; i++) {\n        long long diag = dp[0];  // s[0, i\
    \ - 1) \u3068 t[0, j - 1) \u306E\u7DE8\u96C6\u8DDD\u96E2\n        dp[0] = i;\n\
    \        for (long long j = 1; j <= m; j++) {\n            long long up = dp[j];\n\
    \            dp[j] = std::min({dp[j] + 1, dp[j - 1] + 1, diag + (a[i - 1] == b[j\
    \ - 1] ? 0 : 1)});\n            diag = up;\n        }\n    }\n    return dp[m];\n\
    }\n\n/**\n * @brief \u7DE8\u96C6\u8DDD\u96E2\u3068\u3001s \u3092 t \u306B\u5909\
    \u3048\u308B\u64CD\u4F5C\u5217\n */\nstruct EditDistance {\n    enum class Type\
    \ { Insert,\n                      Erase,\n                      Replace };\n\
    \    struct Operation {\n        Type type;\n        long long source_index; \
    \ //!< \u5143\u306E s \u306E\u6DFB\u5B57\u3002\u633F\u5165\u3067\u306F\u9699\u9593\
    \u306E\u4F4D\u7F6E [0, |s|]\n        long long target_index;  //!< t \u306E\u6DFB\
    \u5B57\u3002\u524A\u9664\u3067\u306F\u9699\u9593\u306E\u4F4D\u7F6E [0, |t|]\n\
    \    };\n    long long distance;\n    std::vector<Operation> operations;\n};\n\
    \n/**\n * @brief \u7DE8\u96C6\u8DDD\u96E2\u3068\u3001\u305D\u306E\u6700\u5C0F\u56DE\
    \u6570\u306E\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\u63DB\u3092\u6C42\u3081\
    \u308B\n * \u6642\u9593\u30FB\u30E1\u30E2\u30EA O(nm)\u3002\u4E00\u81F4\u3059\u308B\
    \u8981\u7D20\u3092\u901A\u904E\u3059\u308B\u64CD\u4F5C\u306F\u542B\u3081\u306A\
    \u3044\u3002\n * \u64CD\u4F5C\u9806\u306B\u3001\u5909\u66F4\u4E2D\u306E\u5217\u306E\
    \ target_index \u306E\u4F4D\u7F6E\u3078\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\
    \u63DB\u3059\u308B\u3002\n * \u633F\u5165\u30FB\u7F6E\u63DB\u3059\u308B\u5024\u306F\
    \ t[target_index]\u3002\n */\ntemplate <typename R1, typename R2>\nEditDistance\
    \ edit_distance_restore(const R1& s, const R2& t) {\n    auto a = std::begin(s);\n\
    \    auto b = std::begin(t);\n    const long long n = std::end(s) - a, m = std::end(t)\
    \ - b;\n    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m\
    \ + 1));\n    for (long long i = 0; i <= n; ++i) dp[i][0] = i;\n    for (long\
    \ long j = 0; j <= m; ++j) dp[0][j] = j;\n    for (long long i = 1; i <= n; ++i)\
    \ {\n        for (long long j = 1; j <= m; ++j) {\n            dp[i][j] = std::min({dp[i\
    \ - 1][j] + 1, dp[i][j - 1] + 1,\n                                 dp[i - 1][j\
    \ - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)});\n        }\n    }\n    EditDistance\
    \ result{dp[n][m], {}};\n    result.operations.reserve(result.distance);\n   \
    \ long long i = n, j = m;\n    while (i > 0 || j > 0) {\n        if (i > 0 &&\
    \ j > 0 && dp[i][j] == dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)) {\n\
    \            if (!(a[i - 1] == b[j - 1])) result.operations.push_back({EditDistance::Type::Replace,\
    \ i - 1, j - 1});\n            --i, --j;\n        } else if (i > 0 && dp[i][j]\
    \ == dp[i - 1][j] + 1) {\n            result.operations.push_back({EditDistance::Type::Erase,\
    \ i - 1, j});\n            --i;\n        } else {\n            assert(j > 0);\n\
    \            result.operations.push_back({EditDistance::Type::Insert, i, j - 1});\n\
    \            --j;\n        }\n    }\n    std::reverse(result.operations.begin(),\
    \ result.operations.end());\n    return result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/edit-distance.hpp
  requiredBy: []
  timestamp: '2026-11-08 23:25:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dp/edit-distance.test.cpp
  - test/aoj/dpl/dpl-1-e.test.cpp
documentation_of: src/dp/edit-distance.hpp
layout: document
title: "\u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\
  \u30F3\u8DDD\u96E2)"
---

列 `s` を列 `t` に変えるのに必要な、1 要素の挿入・削除・置換の最小回数を $O(nm)$ で求めます。$n$、$m$ は `s`、`t` の長さです。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
long long d = edit_distance(std::string("kitten"), std::string("sitting"));  // 3
edit_distance(std::vector<int>{1, 2, 3}, std::vector<int>{2, 3, 4});        // 2
```

`edit_distance_restore` は距離と、最小回数の挿入・削除・置換を行う操作列を返します。入力はランダムアクセス可能な列にしてください。最適な操作列が複数ある場合は、そのうち 1 つを返します。

```cpp
std::string s = "kitten", t = "sitting";
auto [distance, operations] = edit_distance_restore(s, t);  // distance == 3
for (const auto& op : operations) {
    if (op.type == EditDistance::Type::Insert) s.insert(s.begin() + op.target_index, t[op.target_index]);
    if (op.type == EditDistance::Type::Erase) s.erase(s.begin() + op.target_index);
    if (op.type == EditDistance::Type::Replace) s[op.target_index] = t[op.target_index];
}
// s == t
```

`source_index` は変更前の元の列の添字で、挿入のときは隙間の位置 `[0, |s|]` です。`target_index` は目標の列の添字で、削除のときは隙間の位置 `[0, |t|]` です。返された順に操作を適用する場合、変更中の列で操作する位置も `target_index` になります。挿入・置換する値は元の目標列の `t[target_index]` から取得してください。値を操作列にコピーしないため、文字列以外の列でも同じ型で結果を受け取れます。

一致した要素を通過する操作は含みません。操作数は距離と等しく、同じ列どうしでは空の操作列になります。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `edit_distance(s, t)` | 編集距離 (`long long`) | 時間 $O(nm)$、メモリ $O(m)$ |
| `edit_distance_restore(s, t)` | 距離と操作列を持つ `EditDistance` を返す | 時間・メモリ $O(nm)$ |

## メンバ変数

| メンバ | 説明 |
|---|---|
| `EditDistance::distance` | 編集距離 (`long long`) |
| `EditDistance::operations` | 順に適用する `Operation` の列 |
| `Operation::type` | `EditDistance::Type::Insert`・`Erase`・`Replace` |
| `Operation::source_index` | 元の列の添字 (挿入では隙間) |
| `Operation::target_index` | 目標の列の添字 (削除では隙間) |

## 関連

- 置換だけを許す場合 (同じ長さの列で異なる位置の数) は [コンテナに対する関数](../utility/container_func.hpp) の `hamming_distance`
- 挿入と削除だけを許す場合の最小回数は、[最長共通部分列 (LCS)](longest-common-subsequence.hpp) の長さ $L$ を使って $n + m - 2L$
