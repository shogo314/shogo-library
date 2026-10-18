---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/subset-sum.hpp
    title: "\u90E8\u5206\u548C\u554F\u984C (\u4F5C\u308C\u308B\u548C\u306E\u5224\u5B9A\
      \u3001S \u4EE5\u4E0B\u306E\u6700\u5927\u5024\u3068\u5FA9\u5143)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A
  bundledCode: "#line 1 \"test/aoj/alds1-5-a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/dp/subset-sum.hpp\"\
    \n\n/**\n * @file subset-sum.hpp\n * @brief \u90E8\u5206\u548C\u554F\u984C (\u4F5C\
    \u308C\u308B\u548C\u306E\u5224\u5B9A\u3068\u5FA9\u5143)\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <optional>\n#include <utility>\n\
    #line 14 \"src/dp/subset-sum.hpp\"\n\nnamespace internal_subset_sum {\n// bits\
    \ (S + 1 \u30D3\u30C3\u30C8) \u306B\u3064\u3044\u3066 bits |= bits << s \u3092\
    \u884C\u3046\u3002\u65B0\u3057\u304F\u7ACB\u3063\u305F\u30D3\u30C3\u30C8\u3054\
    \u3068\u306B f(\u4F4D\u7F6E) \u3092\u547C\u3076\ntemplate <typename F>\nvoid shift_or(std::vector<unsigned\
    \ long long>& bits, long long S, long long s, F f) {\n    int words = bits.size();\n\
    \    long long q = s / 64;\n    int r = s % 64;\n    for (long long k = words\
    \ - 1; k >= q; k--) {\n        unsigned long long val = bits[k - q] << r;\n  \
    \      if (r && k - q - 1 >= 0) val |= bits[k - q - 1] >> (64 - r);\n        if\
    \ (k == words - 1 && (S + 1) % 64) val &= (1ULL << ((S + 1) % 64)) - 1;  // S\
    \ \u3092\u8D85\u3048\u308B\u4F4D\u7F6E\u306F\u6368\u3066\u308B\n        unsigned\
    \ long long added = val & ~bits[k];\n        bits[k] |= val;\n        while (added)\
    \ {\n            f(k * 64 + __builtin_ctzll(added));\n            added &= added\
    \ - 1;\n        }\n    }\n}\n\n// bitset \u3067\u4F5C\u308C\u308B\u548C\u3092\u6C42\
    \u3081\u308B\u3002from \u304C\u3042\u308C\u3070\u3001\u548C s \u3092\u521D\u3081\
    \u3066\u4F5C\u308C\u308B\u3088\u3046\u306B\u306A\u3063\u305F\u3068\u304D\u306B\
    \u4F7F\u3063\u305F\u8981\u7D20\u306E\u6DFB\u5B57\u3092\u8A18\u9332\u3059\u308B\
    \ninline std::vector<unsigned long long> build(const std::vector<long long>& a,\
    \ long long S, std::vector<int>* from) {\n    assert(S >= 0);\n    std::vector<unsigned\
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
    \    }\n    return res;\n}\n#line 7 \"test/aoj/alds1-5-a.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    std::vector<long long> a(n);\n    for\
    \ (auto& x : a) std::cin >> x;\n    std::vector<bool> can = subset_sum(a, 2000);\n\
    \    int q;\n    std::cin >> q;\n    while (q--) {\n        int m;\n        std::cin\
    \ >> m;\n        std::cout << (can[m] ? \"yes\" : \"no\") << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/dp/subset-sum.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<long long> a(n);\n\
    \    for (auto& x : a) std::cin >> x;\n    std::vector<bool> can = subset_sum(a,\
    \ 2000);\n    int q;\n    std::cin >> q;\n    while (q--) {\n        int m;\n\
    \        std::cin >> m;\n        std::cout << (can[m] ? \"yes\" : \"no\") << '\\\
    n';\n    }\n}\n"
  dependsOn:
  - src/dp/subset-sum.hpp
  isVerificationFile: true
  path: test/aoj/alds1-5-a.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1-5-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1-5-a.test.cpp
- /verify/test/aoj/alds1-5-a.test.cpp.html
title: test/aoj/alds1-5-a.test.cpp
---
