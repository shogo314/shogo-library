---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1-5-a.test.cpp
    title: test/aoj/alds1-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/subset-sum.test.cpp
    title: test/unittest/subset-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u90E8\u5206\u548C\u554F\u984C (\u4F5C\u308C\u308B\u548C\u306E\
      \u5224\u5B9A\u3068\u5FA9\u5143)"
    links: []
  bundledCode: "#line 2 \"src/others/subset-sum.hpp\"\n\n/**\n * @file subset-sum.hpp\n\
    \ * @brief \u90E8\u5206\u548C\u554F\u984C (\u4F5C\u308C\u308B\u548C\u306E\u5224\
    \u5B9A\u3068\u5FA9\u5143)\n */\n\n#include <cassert>\n#include <optional>\n#include\
    \ <vector>\n\nnamespace internal_subset_sum {\n// bits (S + 1 \u30D3\u30C3\u30C8\
    ) \u306B\u3064\u3044\u3066 bits |= bits << s \u3092\u884C\u3046\u3002\u65B0\u3057\
    \u304F\u7ACB\u3063\u305F\u30D3\u30C3\u30C8\u3054\u3068\u306B f(\u4F4D\u7F6E) \u3092\
    \u547C\u3076\ntemplate <typename F>\nvoid shift_or(std::vector<unsigned long long>&\
    \ bits, long long S, long long s, F f) {\n    int words = bits.size();\n    long\
    \ long q = s / 64;\n    int r = s % 64;\n    for (long long k = words - 1; k >=\
    \ q; k--) {\n        unsigned long long val = bits[k - q] << r;\n        if (r\
    \ && k - q - 1 >= 0) val |= bits[k - q - 1] >> (64 - r);\n        if (k == words\
    \ - 1 && (S + 1) % 64) val &= (1ULL << ((S + 1) % 64)) - 1;  // S \u3092\u8D85\
    \u3048\u308B\u4F4D\u7F6E\u306F\u6368\u3066\u308B\n        unsigned long long added\
    \ = val & ~bits[k];\n        bits[k] |= val;\n        while (added) {\n      \
    \      f(k * 64 + __builtin_ctzll(added));\n            added &= added - 1;\n\
    \        }\n    }\n}\n}  // namespace internal_subset_sum\n\n/**\n * @brief a\
    \ \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\u306F 1 \u56DE\u307E\u3067\
    ) \u306E\u548C\u3068\u3057\u3066\u30010, 1, ..., S \u306E\u305D\u308C\u305E\u308C\
    \u3092\u4F5C\u308C\u308B\u304B O(N S / 64)\n * @param a 0 \u4EE5\u4E0A\u306E\u6574\
    \u6570\u306E\u5217\n * @return \u9577\u3055 S + 1 \u306E\u5217\u3002res[s] \u306F\
    \u548C s \u3092\u4F5C\u308C\u308B\u304B\n */\ninline std::vector<bool> subset_sum(const\
    \ std::vector<long long>& a, long long S) {\n    assert(S >= 0);\n    std::vector<unsigned\
    \ long long> bits(S / 64 + 1);\n    bits[0] = 1;\n    for (long long x : a) {\n\
    \        assert(x >= 0);\n        if (x == 0 || x > S) continue;\n        internal_subset_sum::shift_or(bits,\
    \ S, x, [](long long) {});\n    }\n    std::vector<bool> res(S + 1);\n    for\
    \ (long long s = 0; s <= S; s++) res[s] = bits[s / 64] >> (s % 64) & 1;\n    return\
    \ res;\n}\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\
    \u306F 1 \u56DE\u307E\u3067) \u3067\u548C\u304C\u3061\u3087\u3046\u3069 S \u306B\
    \u306A\u308B\u3082\u306E\u3092 1 \u3064\u6C42\u3081\u3001\u305D\u306E\u6DFB\u5B57\
    \u3092\u6607\u9806\u306B\u8FD4\u3059 O(N S / 64 + S)\n * @param a 0 \u4EE5\u4E0A\
    \u306E\u6574\u6570\u306E\u5217\n * @return \u4F5C\u308C\u306A\u3051\u308C\u3070\
    \ std::nullopt\n */\ninline std::optional<std::vector<int>> subset_sum_restore(const\
    \ std::vector<long long>& a, long long S) {\n    assert(S >= 0);\n    std::vector<unsigned\
    \ long long> bits(S / 64 + 1);\n    bits[0] = 1;\n    // from[s] \u306F\u3001\u548C\
    \ s \u3092\u521D\u3081\u3066\u4F5C\u308C\u308B\u3088\u3046\u306B\u306A\u3063\u305F\
    \u3068\u304D\u306B\u4F7F\u3063\u305F\u8981\u7D20\u306E\u6DFB\u5B57\n    std::vector<int>\
    \ from(S + 1, -1);\n    for (int i = 0; i < (int)a.size(); i++) {\n        assert(a[i]\
    \ >= 0);\n        if (a[i] == 0 || a[i] > S) continue;\n        internal_subset_sum::shift_or(bits,\
    \ S, a[i], [&](long long s) { from[s] = i; });\n    }\n    if (!(bits[S / 64]\
    \ >> (S % 64) & 1)) return std::nullopt;\n    // s - a[from[s]] \u306F from[s]\
    \ \u3088\u308A\u524D\u306E\u8981\u7D20\u3060\u3051\u3067\u4F5C\u308C\u3066\u3044\
    \u305F\u306E\u3067\u3001\u6DFB\u5B57\u306F\u771F\u306B\u6E1B\u3063\u3066\u3044\
    \u304F\n    std::vector<int> res;\n    for (long long s = S; s > 0; s -= a[res.back()])\
    \ res.push_back(from[s]);\n    return std::vector<int>(res.rbegin(), res.rend());\n\
    }\n"
  code: "#pragma once\n\n/**\n * @file subset-sum.hpp\n * @brief \u90E8\u5206\u548C\
    \u554F\u984C (\u4F5C\u308C\u308B\u548C\u306E\u5224\u5B9A\u3068\u5FA9\u5143)\n\
    \ */\n\n#include <cassert>\n#include <optional>\n#include <vector>\n\nnamespace\
    \ internal_subset_sum {\n// bits (S + 1 \u30D3\u30C3\u30C8) \u306B\u3064\u3044\
    \u3066 bits |= bits << s \u3092\u884C\u3046\u3002\u65B0\u3057\u304F\u7ACB\u3063\
    \u305F\u30D3\u30C3\u30C8\u3054\u3068\u306B f(\u4F4D\u7F6E) \u3092\u547C\u3076\n\
    template <typename F>\nvoid shift_or(std::vector<unsigned long long>& bits, long\
    \ long S, long long s, F f) {\n    int words = bits.size();\n    long long q =\
    \ s / 64;\n    int r = s % 64;\n    for (long long k = words - 1; k >= q; k--)\
    \ {\n        unsigned long long val = bits[k - q] << r;\n        if (r && k -\
    \ q - 1 >= 0) val |= bits[k - q - 1] >> (64 - r);\n        if (k == words - 1\
    \ && (S + 1) % 64) val &= (1ULL << ((S + 1) % 64)) - 1;  // S \u3092\u8D85\u3048\
    \u308B\u4F4D\u7F6E\u306F\u6368\u3066\u308B\n        unsigned long long added =\
    \ val & ~bits[k];\n        bits[k] |= val;\n        while (added) {\n        \
    \    f(k * 64 + __builtin_ctzll(added));\n            added &= added - 1;\n  \
    \      }\n    }\n}\n}  // namespace internal_subset_sum\n\n/**\n * @brief a \u306E\
    \u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\u306F 1 \u56DE\u307E\u3067) \u306E\
    \u548C\u3068\u3057\u3066\u30010, 1, ..., S \u306E\u305D\u308C\u305E\u308C\u3092\
    \u4F5C\u308C\u308B\u304B O(N S / 64)\n * @param a 0 \u4EE5\u4E0A\u306E\u6574\u6570\
    \u306E\u5217\n * @return \u9577\u3055 S + 1 \u306E\u5217\u3002res[s] \u306F\u548C\
    \ s \u3092\u4F5C\u308C\u308B\u304B\n */\ninline std::vector<bool> subset_sum(const\
    \ std::vector<long long>& a, long long S) {\n    assert(S >= 0);\n    std::vector<unsigned\
    \ long long> bits(S / 64 + 1);\n    bits[0] = 1;\n    for (long long x : a) {\n\
    \        assert(x >= 0);\n        if (x == 0 || x > S) continue;\n        internal_subset_sum::shift_or(bits,\
    \ S, x, [](long long) {});\n    }\n    std::vector<bool> res(S + 1);\n    for\
    \ (long long s = 0; s <= S; s++) res[s] = bits[s / 64] >> (s % 64) & 1;\n    return\
    \ res;\n}\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\
    \u306F 1 \u56DE\u307E\u3067) \u3067\u548C\u304C\u3061\u3087\u3046\u3069 S \u306B\
    \u306A\u308B\u3082\u306E\u3092 1 \u3064\u6C42\u3081\u3001\u305D\u306E\u6DFB\u5B57\
    \u3092\u6607\u9806\u306B\u8FD4\u3059 O(N S / 64 + S)\n * @param a 0 \u4EE5\u4E0A\
    \u306E\u6574\u6570\u306E\u5217\n * @return \u4F5C\u308C\u306A\u3051\u308C\u3070\
    \ std::nullopt\n */\ninline std::optional<std::vector<int>> subset_sum_restore(const\
    \ std::vector<long long>& a, long long S) {\n    assert(S >= 0);\n    std::vector<unsigned\
    \ long long> bits(S / 64 + 1);\n    bits[0] = 1;\n    // from[s] \u306F\u3001\u548C\
    \ s \u3092\u521D\u3081\u3066\u4F5C\u308C\u308B\u3088\u3046\u306B\u306A\u3063\u305F\
    \u3068\u304D\u306B\u4F7F\u3063\u305F\u8981\u7D20\u306E\u6DFB\u5B57\n    std::vector<int>\
    \ from(S + 1, -1);\n    for (int i = 0; i < (int)a.size(); i++) {\n        assert(a[i]\
    \ >= 0);\n        if (a[i] == 0 || a[i] > S) continue;\n        internal_subset_sum::shift_or(bits,\
    \ S, a[i], [&](long long s) { from[s] = i; });\n    }\n    if (!(bits[S / 64]\
    \ >> (S % 64) & 1)) return std::nullopt;\n    // s - a[from[s]] \u306F from[s]\
    \ \u3088\u308A\u524D\u306E\u8981\u7D20\u3060\u3051\u3067\u4F5C\u308C\u3066\u3044\
    \u305F\u306E\u3067\u3001\u6DFB\u5B57\u306F\u771F\u306B\u6E1B\u3063\u3066\u3044\
    \u304F\n    std::vector<int> res;\n    for (long long s = S; s > 0; s -= a[res.back()])\
    \ res.push_back(from[s]);\n    return std::vector<int>(res.rbegin(), res.rend());\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/others/subset-sum.hpp
  requiredBy: []
  timestamp: '2026-10-14 02:15:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/subset-sum.test.cpp
  - test/aoj/alds1-5-a.test.cpp
documentation_of: src/others/subset-sum.hpp
layout: document
title: "\u90E8\u5206\u548C\u554F\u984C (\u4F5C\u308C\u308B\u548C\u306E\u5224\u5B9A\
  \u3068\u5FA9\u5143)"
---

0 以上の整数の列 `a` から、各要素を 1 回まで選んで作れる和を求めます。bitset で 64 個ずつまとめて計算します。

```cpp
std::vector<long long> a = {3, 5, 9};
std::vector<bool> can = subset_sum(a, 20);   // can[s] は和 s を作れるか。can[14] == true、can[13] == false
auto r = subset_sum_restore(a, 14);          // 和 14 になる添字のリスト {1, 2}
if (!subset_sum_restore(a, 13)) {
    // 作れない
}
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `subset_sum(a, S)` | 長さ `S + 1` の `vector<bool>`。`res[s]` は和 `s` を作れるか | $O(NS / 64)$ |
| `subset_sum_restore(a, S)` | 和がちょうど `S` になる選び方を 1 つ求め、添字を昇順に並べたものを `std::optional` で返す。作れなければ `std::nullopt` | $O(NS / 64 + S)$ |

- `S` を超える要素は使えないので無視します。
- `subset_sum_restore` の結果は、変数に受けてから使います。`for (int i : *subset_sum_restore(a, S))` と書くと、一時オブジェクトの `std::optional` が先に破棄され、壊れた値を読みます。
- 復元では、和 `s` を初めて作れるようになったときに使った要素の添字 `from[s]` を覚えておき、`S` から逆にたどります。メモリは $O(S)$ です。

## 関連

- 和ごとの選び方の個数は [部分和の個数](subset-sum-count.hpp)
- 価値と重さがあるときは [ナップサック問題](knapsack.hpp)
