---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/xor-basis.hpp
    title: "XOR \u57FA\u5E95 (F2 \u4E0A\u306E\u7DDA\u5F62\u57FA\u5E95)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/xor-basis.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// XorBasis \u3092\u3001\u4F5C\u308C\u308B\u5024\u3092\u3059\u3079\u3066\u5217\
    \u6319\u3059\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n#include <iostream>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\n#line 2 \"src/math/xor-basis.hpp\"\
    \n\n/**\n * @file xor-basis.hpp\n * @brief XOR \u57FA\u5E95 (F2 \u4E0A\u306E\u7DDA\
    \u5F62\u57FA\u5E95)\n */\n\n#include <cassert>\n#include <limits>\n#include <type_traits>\n\
    #line 12 \"src/math/xor-basis.hpp\"\n\n/**\n * @brief XOR \u57FA\u5E95 (F2 \u4E0A\
    \u306E\u7DDA\u5F62\u57FA\u5E95)\n *\n * \u8FFD\u52A0\u3057\u305F\u5024\u306E XOR\
    \ \u3067\u4F5C\u308C\u308B\u5024\u306E\u96C6\u5408 (\u7DDA\u5F62\u7A7A\u9593)\
    \ \u3092\u7BA1\u7406\u3059\u308B\u3002\u5404\u64CD\u4F5C O(B) (B \u306F T \u306E\
    \u30D3\u30C3\u30C8\u6570)\n * \u57FA\u5E95\u306F\u3001\u6700\u4E0A\u4F4D\u30D3\
    \u30C3\u30C8\u304C\u3059\u3079\u3066\u7570\u306A\u308A\u3001\u5404\u57FA\u5E95\
    \u306E\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304C\u307B\u304B\u306E\u57FA\u5E95\
    \u3067 0 \u306B\u306A\u308B\u5F62 (\u7C21\u7D04\u3055\u308C\u305F\u5F62) \u306B\
    \u4FDD\u3064\n * \u4F8B:\n * XorBasis<> xb;\n * xb.add(5); xb.add(3);\n * xb.contains(6);\
    \  // true\n * xb.max();        // 6\n *\n * @tparam T 64 \u30D3\u30C3\u30C8\u4EE5\
    \u4E0B\u306E\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\n */\ntemplate <typename\
    \ T = unsigned long long>\nclass XorBasis {\n    static_assert(std::is_unsigned_v<T>,\
    \ \"XorBasis: T must be unsigned\");\n    static constexpr int B = std::numeric_limits<T>::digits;\n\
    \    static_assert(B <= 64, \"XorBasis: T must be at most 64 bits\");\n    T b[B]\
    \ = {};  // b[i] \u306F\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304C i \u306E\u57FA\
    \u5E95 (\u306A\u3051\u308C\u3070 0)\n    int r = 0;\n\npublic:\n    XorBasis()\
    \ = default;\n\n    /**\n     * @brief x \u3092\u8FFD\u52A0\u3059\u308B\u3002\
    x \u304C\u4ECA\u306E\u7A7A\u9593\u306B\u542B\u307E\u308C\u3066\u3044\u306A\u3051\
    \u308C\u3070 (\u57FA\u5E95\u304C\u5897\u3048\u308C\u3070) true\n     */\n    bool\
    \ add(T x) {\n        for (int i = B - 1; i >= 0; i--) {\n            if ((x >>\
    \ i & 1) && b[i]) x ^= b[i];\n        }\n        if (x == 0) return false;\n \
    \       int t = B - 1;\n        while (!(x >> t & 1)) t--;\n        // \u307B\u304B\
    \u306E\u57FA\u5E95\u304B\u3089\u3001\u30D3\u30C3\u30C8 t \u3092\u6D88\u3059\n\
    \        for (int i = t + 1; i < B; i++) {\n            if (b[i] >> t & 1) b[i]\
    \ ^= x;\n        }\n        b[t] = x;\n        r++;\n        return true;\n  \
    \  }\n\n    /**\n     * @brief \u57FA\u5E95\u306E\u500B\u6570 (\u7A7A\u9593\u306E\
    \u6B21\u5143)\u3002\u4F5C\u308C\u308B\u5024\u306F 2^rank() \u500B\n     */\n \
    \   int rank() const { return r; }\n\n    /**\n     * @brief x \u3092\u4F5C\u308C\
    \u308B\u304B\n     */\n    bool contains(T x) const { return min(x) == 0; }\n\n\
    \    /**\n     * @brief \u4F5C\u308C\u308B\u5024 y \u306B\u3064\u3044\u3066 x\
    \ ^ y \u306E\u6700\u5927\u5024 (x = 0 \u306A\u3089\u4F5C\u308C\u308B\u5024\u306E\
    \u6700\u5927\u5024)\n     */\n    T max(T x = 0) const {\n        for (int i =\
    \ B - 1; i >= 0; i--) {\n            if (b[i] && !(x >> i & 1)) x ^= b[i];\n \
    \       }\n        return x;\n    }\n\n    /**\n     * @brief \u4F5C\u308C\u308B\
    \u5024 y \u306B\u3064\u3044\u3066 x ^ y \u306E\u6700\u5C0F\u5024 (x = 0 \u306A\
    \u3089 0)\n     */\n    T min(T x) const {\n        for (int i = B - 1; i >= 0;\
    \ i--) {\n            if (x >> i & 1) x ^= b[i];\n        }\n        return x;\n\
    \    }\n\n    /**\n     * @brief \u4F5C\u308C\u308B\u5024\u306E\u3046\u3061\u3001\
    \u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u5024\u3002\
    k < 2^rank() \u3067\u3042\u308B\u3053\u3068\n     */\n    T kth(unsigned long\
    \ long k) const {\n        assert(r >= 64 || k < (1ULL << r));\n        T res\
    \ = 0;\n        for (int i = 0; i < B && k; i++) {\n            if (!b[i]) continue;\n\
    \            if (k & 1) res ^= b[i];\n            k >>= 1;\n        }\n      \
    \  return res;\n    }\n\n    /**\n     * @brief \u4F5C\u308C\u308B\u5024\u306E\
    \u3046\u3061\u3001x \u3088\u308A\u5C0F\u3055\u3044\u3082\u306E\u306E\u500B\u6570\
    \ (kth \u306E\u9006)\n     */\n    unsigned long long count_less(T x) const {\n\
    \        // \u4F5C\u308C\u308B\u5024 y \u3092\u4E0A\u306E\u30D3\u30C3\u30C8\u304B\
    \u3089 x \u3068\u6BD4\u3079\u308B\u3002j \u306F\u307E\u3060\u9078\u3093\u3067\u3044\
    \u306A\u3044\u57FA\u5E95 (\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304C i \u672A\u6E80\
    ) \u306E\u500B\u6570\n        unsigned long long res = 0;\n        int j = r;\n\
    \        T y = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            if\
    \ (b[i]) {\n                // \u7C21\u7D04\u3055\u308C\u305F\u5F62\u306A\u306E\
    \u3067\u3001y \u306E\u30D3\u30C3\u30C8 i \u306F b[i] \u3092\u4F7F\u3046\u304B\u3069\
    \u3046\u304B\u3060\u3051\u3067\u6C7A\u307E\u308B\n                j--;\n     \
    \           if ((y >> i & 1) != (x >> i & 1)) y ^= b[i];\n                // \u30D3\
    \u30C3\u30C8 i \u3092 0 \u306B\u3057\u305F\u5074\u306E 2^j \u500B\u306F\u3001\u3059\
    \u3079\u3066 x \u3088\u308A\u5C0F\u3055\u3044\n                if (x >> i & 1)\
    \ res += 1ULL << j;\n            } else if ((y >> i & 1) != (x >> i & 1)) {\n\
    \                // \u30D3\u30C3\u30C8 i \u306F\u4E0A\u306E\u30D3\u30C3\u30C8\u306E\
    \u9078\u3073\u65B9\u3067\u6C7A\u307E\u3063\u3066\u3044\u3066\u3001\u3053\u3053\
    \u3067\u5927\u5C0F\u304C\u6C7A\u307E\u308B\n                if (x >> i & 1) res\
    \ += 1ULL << j;\n                return res;\n            }\n        }\n     \
    \   return res;\n    }\n\n    /**\n     * @brief \u57FA\u5E95 (\u6700\u4E0A\u4F4D\
    \u30D3\u30C3\u30C8\u306E\u964D\u9806)\n     */\n    std::vector<T> basis() const\
    \ {\n        std::vector<T> res;\n        for (int i = B - 1; i >= 0; i--) {\n\
    \            if (b[i]) res.push_back(b[i]);\n        }\n        return res;\n\
    \    }\n};\n#line 13 \"test/unittest/xor-basis.test.cpp\"\n\nint main() {\n  \
    \  std::mt19937 rng(314);\n    bool ok = true;\n    // 8 \u30D3\u30C3\u30C8\u3067\
    \u3001\u4F5C\u308C\u308B\u5024\u3092\u5168\u90E8\u8ABF\u3079\u308B\n    for (int\
    \ rep = 0; rep < 2000 && ok; rep++) {\n        XorBasis<unsigned char> xb;\n \
    \       std::set<int> span = {0};\n        int k = rng() % 8;\n        int mask\
    \ = rng() % 256;\n        for (int it = 0; it < k && ok; it++) {\n           \
    \ int x = rng() % 256 & mask;  // \u5F93\u5C5E\u306A\u3082\u306E\u304C\u51FA\u3084\
    \u3059\u3044\u3088\u3046\u306B\u30D3\u30C3\u30C8\u3092\u7D5E\u308B\n         \
    \   bool expected = !span.count(x);\n            ok = ok && xb.add(x) == expected;\n\
    \            std::set<int> next = span;\n            for (int y : span) next.insert(y\
    \ ^ x);\n            span = next;\n\n            std::vector<int> vals(span.begin(),\
    \ span.end());\n            ok = ok && (1 << xb.rank()) == (int)vals.size() &&\
    \ (int)xb.basis().size() == xb.rank();\n            for (int i = 0; i < (int)vals.size();\
    \ i++) ok = ok && xb.kth(i) == vals[i];\n            for (int y = 0; y < 256;\
    \ y++) {\n                int mx = 0, mn = 255;\n                for (int v :\
    \ vals) mx = std::max(mx, y ^ v), mn = std::min(mn, y ^ v);\n                int\
    \ less = std::lower_bound(vals.begin(), vals.end(), y) - vals.begin();\n     \
    \           ok = ok && xb.contains(y) == (span.count(y) > 0) && xb.max(y) == mx\
    \ && xb.min(y) == mn &&\n                     xb.count_less(y) == (unsigned long\
    \ long)less;\n            }\n            // \u57FA\u5E95\u306E\u6700\u4E0A\u4F4D\
    \u30D3\u30C3\u30C8\u306F\u964D\u9806\u3067\u7570\u306A\u308A\u3001\u307B\u304B\
    \u306E\u57FA\u5E95\u306E\u305D\u306E\u30D3\u30C3\u30C8\u306F 0\n            auto\
    \ bs = xb.basis();\n            for (int i = 0; i < (int)bs.size(); i++) {\n \
    \               int t = 31 - __builtin_clz(bs[i]);\n                for (int j\
    \ = 0; j < (int)bs.size(); j++) {\n                    if (i != j && (bs[j] >>\
    \ t & 1)) ok = false;\n                }\n                if (i > 0 && bs[i -\
    \ 1] <= bs[i]) ok = false;\n            }\n        }\n    }\n    // 64 \u30D3\u30C3\
    \u30C8: \u57FA\u5E95\u304C 64 \u500B\u306B\u306A\u308B\u5834\u5408\n    {\n  \
    \      XorBasis<> xb;\n        for (int i = 0; i < 64; i++) ok = ok && xb.add((1ULL\
    \ << i) | (i ? 1ULL << (i - 1) : 0));\n        ok = ok && xb.rank() == 64 && !xb.add(12345)\
    \ && xb.max() == ~0ULL && xb.kth(~0ULL) == ~0ULL;\n        ok = ok && xb.count_less(~0ULL)\
    \ == ~0ULL && xb.kth(5) == 5;\n    }\n    // \u4F8B\n    {\n        XorBasis<>\
    \ xb;\n        ok = ok && xb.add(5) && xb.add(3) && !xb.add(6);\n        ok =\
    \ ok && xb.contains(6) && !xb.contains(1) && xb.max() == 6 && xb.max(1) == 7 &&\
    \ xb.min(1) == 1;\n        ok = ok && xb.kth(0) == 0 && xb.kth(1) == 3 && xb.kth(2)\
    \ == 5 && xb.kth(3) == 6;\n    }\n\n    if (ok) std::cout << \"Hello World\" <<\
    \ std::endl;\n    else std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// XorBasis \u3092\u3001\u4F5C\u308C\u308B\u5024\u3092\u3059\u3079\u3066\u5217\
    \u6319\u3059\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n#include <iostream>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\n#include \"../../src/math/xor-basis.hpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    // 8 \u30D3\
    \u30C3\u30C8\u3067\u3001\u4F5C\u308C\u308B\u5024\u3092\u5168\u90E8\u8ABF\u3079\
    \u308B\n    for (int rep = 0; rep < 2000 && ok; rep++) {\n        XorBasis<unsigned\
    \ char> xb;\n        std::set<int> span = {0};\n        int k = rng() % 8;\n \
    \       int mask = rng() % 256;\n        for (int it = 0; it < k && ok; it++)\
    \ {\n            int x = rng() % 256 & mask;  // \u5F93\u5C5E\u306A\u3082\u306E\
    \u304C\u51FA\u3084\u3059\u3044\u3088\u3046\u306B\u30D3\u30C3\u30C8\u3092\u7D5E\
    \u308B\n            bool expected = !span.count(x);\n            ok = ok && xb.add(x)\
    \ == expected;\n            std::set<int> next = span;\n            for (int y\
    \ : span) next.insert(y ^ x);\n            span = next;\n\n            std::vector<int>\
    \ vals(span.begin(), span.end());\n            ok = ok && (1 << xb.rank()) ==\
    \ (int)vals.size() && (int)xb.basis().size() == xb.rank();\n            for (int\
    \ i = 0; i < (int)vals.size(); i++) ok = ok && xb.kth(i) == vals[i];\n       \
    \     for (int y = 0; y < 256; y++) {\n                int mx = 0, mn = 255;\n\
    \                for (int v : vals) mx = std::max(mx, y ^ v), mn = std::min(mn,\
    \ y ^ v);\n                int less = std::lower_bound(vals.begin(), vals.end(),\
    \ y) - vals.begin();\n                ok = ok && xb.contains(y) == (span.count(y)\
    \ > 0) && xb.max(y) == mx && xb.min(y) == mn &&\n                     xb.count_less(y)\
    \ == (unsigned long long)less;\n            }\n            // \u57FA\u5E95\u306E\
    \u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u306F\u964D\u9806\u3067\u7570\u306A\u308A\
    \u3001\u307B\u304B\u306E\u57FA\u5E95\u306E\u305D\u306E\u30D3\u30C3\u30C8\u306F\
    \ 0\n            auto bs = xb.basis();\n            for (int i = 0; i < (int)bs.size();\
    \ i++) {\n                int t = 31 - __builtin_clz(bs[i]);\n               \
    \ for (int j = 0; j < (int)bs.size(); j++) {\n                    if (i != j &&\
    \ (bs[j] >> t & 1)) ok = false;\n                }\n                if (i > 0\
    \ && bs[i - 1] <= bs[i]) ok = false;\n            }\n        }\n    }\n    //\
    \ 64 \u30D3\u30C3\u30C8: \u57FA\u5E95\u304C 64 \u500B\u306B\u306A\u308B\u5834\u5408\
    \n    {\n        XorBasis<> xb;\n        for (int i = 0; i < 64; i++) ok = ok\
    \ && xb.add((1ULL << i) | (i ? 1ULL << (i - 1) : 0));\n        ok = ok && xb.rank()\
    \ == 64 && !xb.add(12345) && xb.max() == ~0ULL && xb.kth(~0ULL) == ~0ULL;\n  \
    \      ok = ok && xb.count_less(~0ULL) == ~0ULL && xb.kth(5) == 5;\n    }\n  \
    \  // \u4F8B\n    {\n        XorBasis<> xb;\n        ok = ok && xb.add(5) && xb.add(3)\
    \ && !xb.add(6);\n        ok = ok && xb.contains(6) && !xb.contains(1) && xb.max()\
    \ == 6 && xb.max(1) == 7 && xb.min(1) == 1;\n        ok = ok && xb.kth(0) == 0\
    \ && xb.kth(1) == 3 && xb.kth(2) == 5 && xb.kth(3) == 6;\n    }\n\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n    else std::cerr << \"failed\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/math/xor-basis.hpp
  isVerificationFile: true
  path: test/unittest/xor-basis.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 01:43:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/xor-basis.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/xor-basis.test.cpp
- /verify/test/unittest/xor-basis.test.cpp.html
title: test/unittest/xor-basis.test.cpp
---
