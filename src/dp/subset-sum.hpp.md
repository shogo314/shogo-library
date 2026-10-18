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
  bundledCode: "#line 2 \"src/dp/subset-sum.hpp\"\n\n/**\n * @file subset-sum.hpp\n\
    \ * @brief \u90E8\u5206\u548C\u554F\u984C (\u4F5C\u308C\u308B\u548C\u306E\u5224\
    \u5B9A\u3068\u5FA9\u5143)\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <limits>\n#include <optional>\n#include <utility>\n#include <vector>\n\nnamespace\
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
    \      }\n    }\n}\n\n// bitset \u3067\u4F5C\u308C\u308B\u548C\u3092\u6C42\u3081\
    \u308B\u3002from \u304C\u3042\u308C\u3070\u3001\u548C s \u3092\u521D\u3081\u3066\
    \u4F5C\u308C\u308B\u3088\u3046\u306B\u306A\u3063\u305F\u3068\u304D\u306B\u4F7F\
    \u3063\u305F\u8981\u7D20\u306E\u6DFB\u5B57\u3092\u8A18\u9332\u3059\u308B\ninline\
    \ std::vector<unsigned long long> build(const std::vector<long long>& a, long\
    \ long S, std::vector<int>* from) {\n    assert(S >= 0);\n    std::vector<unsigned\
    \ long long> bits(S / 64 + 1);\n    bits[0] = 1;\n    if (from) from->assign(S\
    \ + 1, -1);\n    for (int i = 0; i < static_cast<int>(a.size()); i++) {\n    \
    \    assert(a[i] >= 0);\n        if (a[i] == 0 || a[i] > S) continue;\n      \
    \  if (from)\n            shift_or(bits, S, a[i], [&](long long s) { (*from)[s]\
    \ = i; });\n        else\n            shift_or(bits, S, a[i], [](long long) {});\n\
    \    }\n    return bits;\n}\ninline bool test(const std::vector<unsigned long\
    \ long>& bits, long long s) { return bits[s / 64] >> (s % 64) & 1; }\n// \u4F5C\
    \u308C\u308B\u548C s \u304B\u3089 from \u3092\u305F\u3069\u3063\u3066\u3001\u6DFB\
    \u5B57\u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\u306B\u3059\u308B (from \u306F\
    \ S + 1 \u500B\u3042\u308B\u306E\u3067 int \u3067\u6301\u3061\u3001\u8FD4\u3059\
    \u3068\u304D\u306B long long \u306B\u3059\u308B)\n// s - a[from[s]] \u306F from[s]\
    \ \u3088\u308A\u524D\u306E\u8981\u7D20\u3060\u3051\u3067\u4F5C\u308C\u3066\u3044\
    \u305F\u306E\u3067\u3001\u6DFB\u5B57\u306F\u771F\u306B\u6E1B\u3063\u3066\u3044\
    \u304F\ninline std::vector<long long> trace(const std::vector<long long>& a, const\
    \ std::vector<int>& from, long long s) {\n    std::vector<long long> res;\n  \
    \  for (; s > 0; s -= a[res.back()]) res.push_back(from[s]);\n    return std::vector<long\
    \ long>(res.rbegin(), res.rend());\n}\n// \u4F5C\u308C\u308B\u548C\u306E\u3046\
    \u3061 S \u4EE5\u4E0B\u306E\u6700\u5927\u5024\ninline long long max_bit(const\
    \ std::vector<unsigned long long>& bits, long long S) {\n    for (long long k\
    \ = S / 64; k >= 0; k--) {\n        unsigned long long x = bits[k];\n        if\
    \ (k == S / 64 && (S + 1) % 64) x &= (1ULL << ((S + 1) % 64)) - 1;\n        if\
    \ (x) return k * 64 + 63 - __builtin_clzll(x);\n    }\n    return 0;\n}\n\n//\
    \ \u8981\u7D20 [l, r) \u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\u548C\u304C\
    \ S \u4EE5\u4E0B\u306E\u3082\u306E\u3092\u3001(\u548C, \u9078\u3093\u3060\u8981\
    \u7D20\u306E\u30D3\u30C3\u30C8\u5217) \u306E\u548C\u306E\u6607\u9806\u3067\u5217\
    \u6319\u3059\u308B\ninline std::vector<std::pair<long long, unsigned long long>>\
    \ enumerate_half(const std::vector<long long>& a, int l, int r, long long S) {\n\
    \    std::vector<std::pair<long long, unsigned long long>> res = {{0, 0}}, add,\
    \ merged;\n    for (int i = l; i < r; i++) {\n        add.clear();\n        for\
    \ (auto [x, mask] : res) {\n            if (a[i] <= S - x) add.emplace_back(x\
    \ + a[i], mask | 1ULL << (i - l));\n        }\n        merged.resize(res.size()\
    \ + add.size());\n        std::merge(res.begin(), res.end(), add.begin(), add.end(),\
    \ merged.begin());\n        std::swap(res, merged);\n    }\n    return res;\n\
    }\n// \u534A\u5206\u5168\u5217\u6319\u3067 S \u4EE5\u4E0B\u306E\u6700\u5927\u306E\
    \u548C\u3092\u6C42\u3081\u3001(\u548C, \u524D\u534A\u306E\u30D3\u30C3\u30C8\u5217\
    , \u5F8C\u534A\u306E\u30D3\u30C3\u30C8\u5217) \u3092\u8FD4\u3059\nstruct MitmResult\
    \ {\n    long long sum;\n    unsigned long long left, right;\n};\ninline MitmResult\
    \ meet_in_the_middle(const std::vector<long long>& a, long long S) {\n    assert(S\
    \ >= 0);\n    int n = a.size();\n    assert(n <= 128 && \"subset_sum_max_meet_in_the_middle:\
    \ too many elements\");\n    for (long long x : a) assert(x >= 0);\n    auto p\
    \ = enumerate_half(a, 0, n / 2, S), q = enumerate_half(a, n / 2, n, S);\n    MitmResult\
    \ res = {0, 0, 0};\n    // p \u3092\u548C\u306E\u6607\u9806\u306B\u898B\u308B\u3068\
    \u3001\u7D44\u3081\u308B q \u306E\u548C\u306E\u4E0A\u9650\u306F\u6E1B\u3063\u3066\
    \u3044\u304F\n    int j = q.size() - 1;\n    for (auto [x, mask] : p) {\n    \
    \    while (q[j].first > S - x) j--;  // q[0] \u306F\u548C 0 \u306A\u306E\u3067\
    \ j >= 0 \u306E\u307E\u307E\n        if (x + q[j].first > res.sum) res = {x +\
    \ q[j].first, mask, q[j].second};\n    }\n    return res;\n}\ninline long double\
    \ cost_bitset(int n, long long S) { return static_cast<long double>(n + 1) * (static_cast<long\
    \ double>(S) / 64 + 1); }\ninline long double cost_meet_in_the_middle(int n) {\n\
    \    if (n > 120) return std::numeric_limits<long double>::infinity();\n    return\
    \ 4 * static_cast<long double>(1ULL << ((n + 1) / 2));\n}\n}  // namespace internal_subset_sum\n\
    \n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\u306F 1\
    \ \u56DE\u307E\u3067) \u306E\u548C\u3068\u3057\u3066\u30010, 1, ..., S \u306E\u305D\
    \u308C\u305E\u308C\u3092\u4F5C\u308C\u308B\u304B O(N S / 64)\n * @param a 0 \u4EE5\
    \u4E0A\u306E\u6574\u6570\u306E\u5217\n * @return \u9577\u3055 S + 1 \u306E\u5217\
    \u3002res[s] \u306F\u548C s \u3092\u4F5C\u308C\u308B\u304B\n */\ninline std::vector<bool>\
    \ subset_sum(const std::vector<long long>& a, long long S) {\n    auto bits =\
    \ internal_subset_sum::build(a, S, nullptr);\n    std::vector<bool> res(S + 1);\n\
    \    for (long long s = 0; s <= S; s++) res[s] = internal_subset_sum::test(bits,\
    \ s);\n    return res;\n}\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\
    \u8981\u7D20\u306F 1 \u56DE\u307E\u3067) \u3067\u548C\u304C\u3061\u3087\u3046\u3069\
    \ S \u306B\u306A\u308B\u3082\u306E\u3092 1 \u3064\u6C42\u3081\u3001\u305D\u306E\
    \u6DFB\u5B57\u3092\u6607\u9806\u306B\u8FD4\u3059 O(N S / 64 + S)\n * @param a\
    \ 0 \u4EE5\u4E0A\u306E\u6574\u6570\u306E\u5217\n * @return \u4F5C\u308C\u306A\u3051\
    \u308C\u3070 std::nullopt\n */\ninline std::optional<std::vector<long long>> subset_sum_restore(const\
    \ std::vector<long long>& a, long long S) {\n    std::vector<int> from;\n    auto\
    \ bits = internal_subset_sum::build(a, S, &from);\n    if (!internal_subset_sum::test(bits,\
    \ S)) return std::nullopt;\n    return internal_subset_sum::trace(a, from, S);\n\
    }\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\u306F\
    \ 1 \u56DE\u307E\u3067) \u306E\u548C\u306E\u3046\u3061\u3001S \u4EE5\u4E0B\u306E\
    \u6700\u5927\u5024 (bitset) O(N S / 64)\n * @param a 0 \u4EE5\u4E0A\u306E\u6574\
    \u6570\u306E\u5217\n */\ninline long long subset_sum_max_bitset(const std::vector<long\
    \ long>& a, long long S) {\n    return internal_subset_sum::max_bit(internal_subset_sum::build(a,\
    \ S, nullptr), S);\n}\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\
    \u8981\u7D20\u306F 1 \u56DE\u307E\u3067) \u306E\u548C\u306E\u3046\u3061\u3001\
    S \u4EE5\u4E0B\u306E\u6700\u5927\u5024 (\u534A\u5206\u5168\u5217\u6319) O(2^(N/2))\n\
    \ * N \u304C 40 \u7A0B\u5EA6\u307E\u3067\u306A\u3089\u3001S \u3084\u8981\u7D20\
    \u304C\u5927\u304D\u304F\u3066\u3082\u3088\u3044\n * @param a 0 \u4EE5\u4E0A\u306E\
    \u6574\u6570\u306E\u5217\n */\ninline long long subset_sum_max_meet_in_the_middle(const\
    \ std::vector<long long>& a, long long S) {\n    return internal_subset_sum::meet_in_the_middle(a,\
    \ S).sum;\n}\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\
    \u306F 1 \u56DE\u307E\u3067) \u306E\u548C\u306E\u3046\u3061\u3001S \u4EE5\u4E0B\
    \u306E\u6700\u5927\u5024\n *\n * \u8A08\u7B97\u91CF\u304C\u5C0F\u3055\u3044\u65B9\
    \u3092\u9078\u3076: subset_sum_max_bitset O(N S / 64) \u304B subset_sum_max_meet_in_the_middle\
    \ O(2^(N/2))\n * @param a 0 \u4EE5\u4E0A\u306E\u6574\u6570\u306E\u5217\n */\n\
    inline long long subset_sum_max(const std::vector<long long>& a, long long S)\
    \ {\n    using namespace internal_subset_sum;\n    if (cost_bitset(a.size(), S)\
    \ <= cost_meet_in_the_middle(a.size())) return subset_sum_max_bitset(a, S);\n\
    \    return subset_sum_max_meet_in_the_middle(a, S);\n}\n\n/**\n * @brief \u548C\
    \u304C S \u4EE5\u4E0B\u3067\u6700\u5927\u306B\u306A\u308B\u90E8\u5206\u96C6\u5408\
    \ (\u5404\u8981\u7D20\u306F 1 \u56DE\u307E\u3067) \u3092 1 \u3064\u6C42\u3081\u3001\
    \u305D\u306E\u6DFB\u5B57\u3092\u6607\u9806\u306B\u8FD4\u3059\n *\n * subset_sum_max\
    \ \u3068\u540C\u3058\u304F\u3001bitset O(N S / 64 + S) \u3068\u534A\u5206\u5168\
    \u5217\u6319 O(2^(N/2)) \u306E\u3046\u3061\u8A08\u7B97\u91CF\u304C\u5C0F\u3055\
    \u3044\u65B9\u3092\u9078\u3076\n * @param a 0 \u4EE5\u4E0A\u306E\u6574\u6570\u306E\
    \u5217\n */\ninline std::vector<long long> subset_sum_max_restore(const std::vector<long\
    \ long>& a, long long S) {\n    using namespace internal_subset_sum;\n    int\
    \ n = a.size();\n    if (cost_bitset(n, S) <= cost_meet_in_the_middle(n)) {\n\
    \        std::vector<int> from;\n        auto bits = build(a, S, &from);\n   \
    \     return trace(a, from, max_bit(bits, S));\n    }\n    MitmResult r = meet_in_the_middle(a,\
    \ S);\n    std::vector<long long> res;\n    for (long long i = 0; i < n / 2; i++)\
    \ {\n        if (r.left >> i & 1) res.push_back(i);\n    }\n    for (long long\
    \ i = n / 2; i < n; i++) {\n        if (r.right >> (i - n / 2) & 1) res.push_back(i);\n\
    \    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file subset-sum.hpp\n * @brief \u90E8\u5206\u548C\
    \u554F\u984C (\u4F5C\u308C\u308B\u548C\u306E\u5224\u5B9A\u3068\u5FA9\u5143)\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <optional>\n#include <utility>\n#include <vector>\n\nnamespace internal_subset_sum\
    \ {\n// bits (S + 1 \u30D3\u30C3\u30C8) \u306B\u3064\u3044\u3066 bits |= bits\
    \ << s \u3092\u884C\u3046\u3002\u65B0\u3057\u304F\u7ACB\u3063\u305F\u30D3\u30C3\
    \u30C8\u3054\u3068\u306B f(\u4F4D\u7F6E) \u3092\u547C\u3076\ntemplate <typename\
    \ F>\nvoid shift_or(std::vector<unsigned long long>& bits, long long S, long long\
    \ s, F f) {\n    int words = bits.size();\n    long long q = s / 64;\n    int\
    \ r = s % 64;\n    for (long long k = words - 1; k >= q; k--) {\n        unsigned\
    \ long long val = bits[k - q] << r;\n        if (r && k - q - 1 >= 0) val |= bits[k\
    \ - q - 1] >> (64 - r);\n        if (k == words - 1 && (S + 1) % 64) val &= (1ULL\
    \ << ((S + 1) % 64)) - 1;  // S \u3092\u8D85\u3048\u308B\u4F4D\u7F6E\u306F\u6368\
    \u3066\u308B\n        unsigned long long added = val & ~bits[k];\n        bits[k]\
    \ |= val;\n        while (added) {\n            f(k * 64 + __builtin_ctzll(added));\n\
    \            added &= added - 1;\n        }\n    }\n}\n\n// bitset \u3067\u4F5C\
    \u308C\u308B\u548C\u3092\u6C42\u3081\u308B\u3002from \u304C\u3042\u308C\u3070\u3001\
    \u548C s \u3092\u521D\u3081\u3066\u4F5C\u308C\u308B\u3088\u3046\u306B\u306A\u3063\
    \u305F\u3068\u304D\u306B\u4F7F\u3063\u305F\u8981\u7D20\u306E\u6DFB\u5B57\u3092\
    \u8A18\u9332\u3059\u308B\ninline std::vector<unsigned long long> build(const std::vector<long\
    \ long>& a, long long S, std::vector<int>* from) {\n    assert(S >= 0);\n    std::vector<unsigned\
    \ long long> bits(S / 64 + 1);\n    bits[0] = 1;\n    if (from) from->assign(S\
    \ + 1, -1);\n    for (int i = 0; i < static_cast<int>(a.size()); i++) {\n    \
    \    assert(a[i] >= 0);\n        if (a[i] == 0 || a[i] > S) continue;\n      \
    \  if (from)\n            shift_or(bits, S, a[i], [&](long long s) { (*from)[s]\
    \ = i; });\n        else\n            shift_or(bits, S, a[i], [](long long) {});\n\
    \    }\n    return bits;\n}\ninline bool test(const std::vector<unsigned long\
    \ long>& bits, long long s) { return bits[s / 64] >> (s % 64) & 1; }\n// \u4F5C\
    \u308C\u308B\u548C s \u304B\u3089 from \u3092\u305F\u3069\u3063\u3066\u3001\u6DFB\
    \u5B57\u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\u306B\u3059\u308B (from \u306F\
    \ S + 1 \u500B\u3042\u308B\u306E\u3067 int \u3067\u6301\u3061\u3001\u8FD4\u3059\
    \u3068\u304D\u306B long long \u306B\u3059\u308B)\n// s - a[from[s]] \u306F from[s]\
    \ \u3088\u308A\u524D\u306E\u8981\u7D20\u3060\u3051\u3067\u4F5C\u308C\u3066\u3044\
    \u305F\u306E\u3067\u3001\u6DFB\u5B57\u306F\u771F\u306B\u6E1B\u3063\u3066\u3044\
    \u304F\ninline std::vector<long long> trace(const std::vector<long long>& a, const\
    \ std::vector<int>& from, long long s) {\n    std::vector<long long> res;\n  \
    \  for (; s > 0; s -= a[res.back()]) res.push_back(from[s]);\n    return std::vector<long\
    \ long>(res.rbegin(), res.rend());\n}\n// \u4F5C\u308C\u308B\u548C\u306E\u3046\
    \u3061 S \u4EE5\u4E0B\u306E\u6700\u5927\u5024\ninline long long max_bit(const\
    \ std::vector<unsigned long long>& bits, long long S) {\n    for (long long k\
    \ = S / 64; k >= 0; k--) {\n        unsigned long long x = bits[k];\n        if\
    \ (k == S / 64 && (S + 1) % 64) x &= (1ULL << ((S + 1) % 64)) - 1;\n        if\
    \ (x) return k * 64 + 63 - __builtin_clzll(x);\n    }\n    return 0;\n}\n\n//\
    \ \u8981\u7D20 [l, r) \u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\u548C\u304C\
    \ S \u4EE5\u4E0B\u306E\u3082\u306E\u3092\u3001(\u548C, \u9078\u3093\u3060\u8981\
    \u7D20\u306E\u30D3\u30C3\u30C8\u5217) \u306E\u548C\u306E\u6607\u9806\u3067\u5217\
    \u6319\u3059\u308B\ninline std::vector<std::pair<long long, unsigned long long>>\
    \ enumerate_half(const std::vector<long long>& a, int l, int r, long long S) {\n\
    \    std::vector<std::pair<long long, unsigned long long>> res = {{0, 0}}, add,\
    \ merged;\n    for (int i = l; i < r; i++) {\n        add.clear();\n        for\
    \ (auto [x, mask] : res) {\n            if (a[i] <= S - x) add.emplace_back(x\
    \ + a[i], mask | 1ULL << (i - l));\n        }\n        merged.resize(res.size()\
    \ + add.size());\n        std::merge(res.begin(), res.end(), add.begin(), add.end(),\
    \ merged.begin());\n        std::swap(res, merged);\n    }\n    return res;\n\
    }\n// \u534A\u5206\u5168\u5217\u6319\u3067 S \u4EE5\u4E0B\u306E\u6700\u5927\u306E\
    \u548C\u3092\u6C42\u3081\u3001(\u548C, \u524D\u534A\u306E\u30D3\u30C3\u30C8\u5217\
    , \u5F8C\u534A\u306E\u30D3\u30C3\u30C8\u5217) \u3092\u8FD4\u3059\nstruct MitmResult\
    \ {\n    long long sum;\n    unsigned long long left, right;\n};\ninline MitmResult\
    \ meet_in_the_middle(const std::vector<long long>& a, long long S) {\n    assert(S\
    \ >= 0);\n    int n = a.size();\n    assert(n <= 128 && \"subset_sum_max_meet_in_the_middle:\
    \ too many elements\");\n    for (long long x : a) assert(x >= 0);\n    auto p\
    \ = enumerate_half(a, 0, n / 2, S), q = enumerate_half(a, n / 2, n, S);\n    MitmResult\
    \ res = {0, 0, 0};\n    // p \u3092\u548C\u306E\u6607\u9806\u306B\u898B\u308B\u3068\
    \u3001\u7D44\u3081\u308B q \u306E\u548C\u306E\u4E0A\u9650\u306F\u6E1B\u3063\u3066\
    \u3044\u304F\n    int j = q.size() - 1;\n    for (auto [x, mask] : p) {\n    \
    \    while (q[j].first > S - x) j--;  // q[0] \u306F\u548C 0 \u306A\u306E\u3067\
    \ j >= 0 \u306E\u307E\u307E\n        if (x + q[j].first > res.sum) res = {x +\
    \ q[j].first, mask, q[j].second};\n    }\n    return res;\n}\ninline long double\
    \ cost_bitset(int n, long long S) { return static_cast<long double>(n + 1) * (static_cast<long\
    \ double>(S) / 64 + 1); }\ninline long double cost_meet_in_the_middle(int n) {\n\
    \    if (n > 120) return std::numeric_limits<long double>::infinity();\n    return\
    \ 4 * static_cast<long double>(1ULL << ((n + 1) / 2));\n}\n}  // namespace internal_subset_sum\n\
    \n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\u306F 1\
    \ \u56DE\u307E\u3067) \u306E\u548C\u3068\u3057\u3066\u30010, 1, ..., S \u306E\u305D\
    \u308C\u305E\u308C\u3092\u4F5C\u308C\u308B\u304B O(N S / 64)\n * @param a 0 \u4EE5\
    \u4E0A\u306E\u6574\u6570\u306E\u5217\n * @return \u9577\u3055 S + 1 \u306E\u5217\
    \u3002res[s] \u306F\u548C s \u3092\u4F5C\u308C\u308B\u304B\n */\ninline std::vector<bool>\
    \ subset_sum(const std::vector<long long>& a, long long S) {\n    auto bits =\
    \ internal_subset_sum::build(a, S, nullptr);\n    std::vector<bool> res(S + 1);\n\
    \    for (long long s = 0; s <= S; s++) res[s] = internal_subset_sum::test(bits,\
    \ s);\n    return res;\n}\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\
    \u8981\u7D20\u306F 1 \u56DE\u307E\u3067) \u3067\u548C\u304C\u3061\u3087\u3046\u3069\
    \ S \u306B\u306A\u308B\u3082\u306E\u3092 1 \u3064\u6C42\u3081\u3001\u305D\u306E\
    \u6DFB\u5B57\u3092\u6607\u9806\u306B\u8FD4\u3059 O(N S / 64 + S)\n * @param a\
    \ 0 \u4EE5\u4E0A\u306E\u6574\u6570\u306E\u5217\n * @return \u4F5C\u308C\u306A\u3051\
    \u308C\u3070 std::nullopt\n */\ninline std::optional<std::vector<long long>> subset_sum_restore(const\
    \ std::vector<long long>& a, long long S) {\n    std::vector<int> from;\n    auto\
    \ bits = internal_subset_sum::build(a, S, &from);\n    if (!internal_subset_sum::test(bits,\
    \ S)) return std::nullopt;\n    return internal_subset_sum::trace(a, from, S);\n\
    }\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\u306F\
    \ 1 \u56DE\u307E\u3067) \u306E\u548C\u306E\u3046\u3061\u3001S \u4EE5\u4E0B\u306E\
    \u6700\u5927\u5024 (bitset) O(N S / 64)\n * @param a 0 \u4EE5\u4E0A\u306E\u6574\
    \u6570\u306E\u5217\n */\ninline long long subset_sum_max_bitset(const std::vector<long\
    \ long>& a, long long S) {\n    return internal_subset_sum::max_bit(internal_subset_sum::build(a,\
    \ S, nullptr), S);\n}\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\
    \u8981\u7D20\u306F 1 \u56DE\u307E\u3067) \u306E\u548C\u306E\u3046\u3061\u3001\
    S \u4EE5\u4E0B\u306E\u6700\u5927\u5024 (\u534A\u5206\u5168\u5217\u6319) O(2^(N/2))\n\
    \ * N \u304C 40 \u7A0B\u5EA6\u307E\u3067\u306A\u3089\u3001S \u3084\u8981\u7D20\
    \u304C\u5927\u304D\u304F\u3066\u3082\u3088\u3044\n * @param a 0 \u4EE5\u4E0A\u306E\
    \u6574\u6570\u306E\u5217\n */\ninline long long subset_sum_max_meet_in_the_middle(const\
    \ std::vector<long long>& a, long long S) {\n    return internal_subset_sum::meet_in_the_middle(a,\
    \ S).sum;\n}\n\n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\
    \u306F 1 \u56DE\u307E\u3067) \u306E\u548C\u306E\u3046\u3061\u3001S \u4EE5\u4E0B\
    \u306E\u6700\u5927\u5024\n *\n * \u8A08\u7B97\u91CF\u304C\u5C0F\u3055\u3044\u65B9\
    \u3092\u9078\u3076: subset_sum_max_bitset O(N S / 64) \u304B subset_sum_max_meet_in_the_middle\
    \ O(2^(N/2))\n * @param a 0 \u4EE5\u4E0A\u306E\u6574\u6570\u306E\u5217\n */\n\
    inline long long subset_sum_max(const std::vector<long long>& a, long long S)\
    \ {\n    using namespace internal_subset_sum;\n    if (cost_bitset(a.size(), S)\
    \ <= cost_meet_in_the_middle(a.size())) return subset_sum_max_bitset(a, S);\n\
    \    return subset_sum_max_meet_in_the_middle(a, S);\n}\n\n/**\n * @brief \u548C\
    \u304C S \u4EE5\u4E0B\u3067\u6700\u5927\u306B\u306A\u308B\u90E8\u5206\u96C6\u5408\
    \ (\u5404\u8981\u7D20\u306F 1 \u56DE\u307E\u3067) \u3092 1 \u3064\u6C42\u3081\u3001\
    \u305D\u306E\u6DFB\u5B57\u3092\u6607\u9806\u306B\u8FD4\u3059\n *\n * subset_sum_max\
    \ \u3068\u540C\u3058\u304F\u3001bitset O(N S / 64 + S) \u3068\u534A\u5206\u5168\
    \u5217\u6319 O(2^(N/2)) \u306E\u3046\u3061\u8A08\u7B97\u91CF\u304C\u5C0F\u3055\
    \u3044\u65B9\u3092\u9078\u3076\n * @param a 0 \u4EE5\u4E0A\u306E\u6574\u6570\u306E\
    \u5217\n */\ninline std::vector<long long> subset_sum_max_restore(const std::vector<long\
    \ long>& a, long long S) {\n    using namespace internal_subset_sum;\n    int\
    \ n = a.size();\n    if (cost_bitset(n, S) <= cost_meet_in_the_middle(n)) {\n\
    \        std::vector<int> from;\n        auto bits = build(a, S, &from);\n   \
    \     return trace(a, from, max_bit(bits, S));\n    }\n    MitmResult r = meet_in_the_middle(a,\
    \ S);\n    std::vector<long long> res;\n    for (long long i = 0; i < n / 2; i++)\
    \ {\n        if (r.left >> i & 1) res.push_back(i);\n    }\n    for (long long\
    \ i = n / 2; i < n; i++) {\n        if (r.right >> (i - n / 2) & 1) res.push_back(i);\n\
    \    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/subset-sum.hpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/subset-sum.test.cpp
  - test/aoj/alds1-5-a.test.cpp
documentation_of: src/dp/subset-sum.hpp
layout: document
title: "\u90E8\u5206\u548C\u554F\u984C (\u4F5C\u308C\u308B\u548C\u306E\u5224\u5B9A\
  \u3001S \u4EE5\u4E0B\u306E\u6700\u5927\u5024\u3068\u5FA9\u5143)"
---

0 以上の整数の列 `a` から、各要素を 1 回まで選んで作れる和を求めます。bitset で 64 個ずつまとめて計算するか、半分全列挙を使います。

```cpp
std::vector<long long> a = {3, 5, 9};
std::vector<bool> can = subset_sum(a, 20);   // can[s] は和 s を作れるか。can[14] == true、can[13] == false
auto r = subset_sum_restore(a, 14);          // 和 14 になる添字のリスト {1, 2}
if (!subset_sum_restore(a, 13)) {
    // 作れない
}
long long m = subset_sum_max(a, 13);         // 12 (S 以下の最大値)
auto idx = subset_sum_max_restore(a, 13);    // {0, 2} (3 + 9)
```

## 注意

- 添字のリストは `std::vector<long long>` で返します。
- `S` を超える要素は使えないので無視します。
- `subset_sum_restore` の結果は、変数に受けてから使います。`for (long long i : *subset_sum_restore(a, S))` と書くと、一時オブジェクトの `std::optional` が先に破棄され、壊れた値を読みます。
- bitset での復元では、和 `s` を初めて作れるようになったときに使った要素の添字 `from[s]` を覚えておき、復元する和から逆にたどります。メモリは $O(S)$ です。

## 作れるかの判定

| 関数 | 説明 | 計算量 |
|---|---|---|
| `subset_sum(a, S)` | 長さ `S + 1` の `vector<bool>`。`res[s]` は和 `s` を作れるか | $O(NS / 64)$ |
| `subset_sum_restore(a, S)` | 和がちょうど `S` になる選び方を 1 つ求め、添字を昇順に並べたものを `std::optional` で返す。作れなければ `std::nullopt` | $O(NS / 64 + S)$ |

## S 以下の最大値

| 関数 | 説明 | 計算量 |
|---|---|---|
| `subset_sum_max(a, S)` | 作れる和のうち `S` 以下の最大値。下の 2 つのうち計算量が小さい方を選ぶ | $O(\min(NS / 64, 2^{N/2}))$ |
| `subset_sum_max_bitset(a, S)` | bitset で作れる和を求め、`S` から下へ探す | $O(NS / 64)$ |
| `subset_sum_max_meet_in_the_middle(a, S)` | 半分全列挙。$N$ が 40 程度までなら、`S` や要素が大きくてもよい。$N \le 128$ (超えると assert で止まる) | $O(2^{N/2})$ |
| `subset_sum_max_restore(a, S)` | 和が `S` 以下で最大になる選び方を 1 つ求め、添字を昇順に並べたものを返す。`subset_sum_max` と同じく計算量が小さい方を選ぶ | $O(\min(NS / 64 + S, 2^{N/2}))$ |

- 何も選ばなければ和は 0 なので、`subset_sum_max` は常に 0 以上の値を返し、`subset_sum_max_restore` は空のリストを返すこともあります。
- 半分全列挙では、前半と後半それぞれの (和, 選んだ要素のビット列) を和の昇順に列挙し、前半の和を小さい順に見ながら後半の添字を後ろから動かします。
- `subset_sum_max` は $(N + 1)(S / 64 + 1)$ と $4 \cdot 2^{\lceil N/2 \rceil}$ を比べて選びます。$N > 120$ のときは半分全列挙を候補から外します。

## 関連

- 和ごとの選び方の個数は [部分和の個数](subset-sum-count.hpp)
- 価値と重さがあるときは [ナップサック問題](knapsack.hpp)
