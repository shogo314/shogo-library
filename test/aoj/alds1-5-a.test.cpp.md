---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/others/subset-sum.hpp
    title: "\u90E8\u5206\u548C\u554F\u984C (\u4F5C\u308C\u308B\u548C\u306E\u5224\u5B9A\
      \u3068\u5FA9\u5143)"
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
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/others/subset-sum.hpp\"\
    \n\n/**\n * @file subset-sum.hpp\n * @brief \u90E8\u5206\u548C\u554F\u984C (\u4F5C\
    \u308C\u308B\u548C\u306E\u5224\u5B9A\u3068\u5FA9\u5143)\n */\n\n#include <cassert>\n\
    #include <optional>\n#line 11 \"src/others/subset-sum.hpp\"\n\nnamespace internal_subset_sum\
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
    \            added &= added - 1;\n        }\n    }\n}\n}  // namespace internal_subset_sum\n\
    \n/**\n * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\u306F 1\
    \ \u56DE\u307E\u3067) \u306E\u548C\u3068\u3057\u3066\u30010, 1, ..., S \u306E\u305D\
    \u308C\u305E\u308C\u3092\u4F5C\u308C\u308B\u304B O(N S / 64)\n * @param a 0 \u4EE5\
    \u4E0A\u306E\u6574\u6570\u306E\u5217\n * @return \u9577\u3055 S + 1 \u306E\u5217\
    \u3002res[s] \u306F\u548C s \u3092\u4F5C\u308C\u308B\u304B\n */\ninline std::vector<bool>\
    \ subset_sum(const std::vector<long long>& a, long long S) {\n    assert(S >=\
    \ 0);\n    std::vector<unsigned long long> bits(S / 64 + 1);\n    bits[0] = 1;\n\
    \    for (long long x : a) {\n        assert(x >= 0);\n        if (x == 0 || x\
    \ > S) continue;\n        internal_subset_sum::shift_or(bits, S, x, [](long long)\
    \ {});\n    }\n    std::vector<bool> res(S + 1);\n    for (long long s = 0; s\
    \ <= S; s++) res[s] = bits[s / 64] >> (s % 64) & 1;\n    return res;\n}\n\n/**\n\
    \ * @brief a \u306E\u90E8\u5206\u96C6\u5408 (\u5404\u8981\u7D20\u306F 1 \u56DE\
    \u307E\u3067) \u3067\u548C\u304C\u3061\u3087\u3046\u3069 S \u306B\u306A\u308B\u3082\
    \u306E\u3092 1 \u3064\u6C42\u3081\u3001\u305D\u306E\u6DFB\u5B57\u3092\u6607\u9806\
    \u306B\u8FD4\u3059 O(N S / 64 + S)\n * @param a 0 \u4EE5\u4E0A\u306E\u6574\u6570\
    \u306E\u5217\n * @return \u4F5C\u308C\u306A\u3051\u308C\u3070 std::nullopt\n */\n\
    inline std::optional<std::vector<int>> subset_sum_restore(const std::vector<long\
    \ long>& a, long long S) {\n    assert(S >= 0);\n    std::vector<unsigned long\
    \ long> bits(S / 64 + 1);\n    bits[0] = 1;\n    // from[s] \u306F\u3001\u548C\
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
    }\n#line 7 \"test/aoj/alds1-5-a.test.cpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<long long> a(n);\n    for (auto& x : a) std::cin >> x;\n\
    \    std::vector<bool> can = subset_sum(a, 2000);\n    int q;\n    std::cin >>\
    \ q;\n    while (q--) {\n        int m;\n        std::cin >> m;\n        std::cout\
    \ << (can[m] ? \"yes\" : \"no\") << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/others/subset-sum.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<long long> a(n);\n\
    \    for (auto& x : a) std::cin >> x;\n    std::vector<bool> can = subset_sum(a,\
    \ 2000);\n    int q;\n    std::cin >> q;\n    while (q--) {\n        int m;\n\
    \        std::cin >> m;\n        std::cout << (can[m] ? \"yes\" : \"no\") << '\\\
    n';\n    }\n}\n"
  dependsOn:
  - src/others/subset-sum.hpp
  isVerificationFile: true
  path: test/aoj/alds1-5-a.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 02:15:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1-5-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1-5-a.test.cpp
- /verify/test/aoj/alds1-5-a.test.cpp.html
title: test/aoj/alds1-5-a.test.cpp
---
