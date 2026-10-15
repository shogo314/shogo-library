---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree-beats.hpp
    title: Segment Tree Beats
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/beats-acted-monoid.test.cpp
    title: test/unittest/beats-acted-monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/dual-segtree.test.cpp
    title: test/unittest/dual-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/segtree-beats.test.cpp
    title: test/unittest/segtree-beats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-chmin-chmax-add-range-sum.1.test.cpp
    title: test/yosupo/range-chmin-chmax-add-range-sum.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-chmin-chmax-add-range-sum.2.test.cpp
    title: test/yosupo/range-chmin-chmax-add-range-sum.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-chmin-chmax-add-range-sum.3.test.cpp
    title: test/yosupo/range-chmin-chmax-add-range-sum.3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment Tree Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\
      \u30E2\u30CE\u30A4\u30C9"
    links: []
  bundledCode: "#line 2 \"src/algebra/beats-acted-monoid.hpp\"\n\n/**\n * @file beats-acted-monoid.hpp\n\
    \ * @brief Segment Tree Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/acted-monoid.hpp) \u3068\u540C\u3058\u30E1\u30F3\u30D0\u3092\u6301\u3064\
    \u304C\u3001\n * mapping \u306F std::pair<bool, S> (\u4F5C\u7528\u306B\u5931\u6557\
    \u3057\u305F\u304B, \u4F5C\u7528\u5F8C\u306E\u5024) \u3092\u8FD4\u3059\n * data_structures/segtree-beats.hpp\
    \ \u306B\u6E21\u3057\u3066\u4F7F\u3046\n */\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <utility>\n\nnamespace beats_acted_monoid {\n\n/**\n * @brief\
    \ \u533A\u9593 chmin\u3001\u533A\u9593\u548C\u30FB\u6700\u5927\u5024\n *\n * \u4F5C\
    \u7528\u7D20\u306F chmin \u3059\u308B\u5024 (x <- min(x, f))\n * S(x) \u3067\u5024\
    \ x \u306E1\u8981\u7D20\u304B\u3089\u4F5C\u308A\u3001sum, max1 \u3067\u533A\u9593\
    \u548C\u30FB\u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\u308B\n * \u7A7A\u306E\u533A\
    \u9593\u3067\u306F max1 = numeric_limits<T>::lowest()\n * ChminChmaxAddSum \u3088\
    \u308A\u8EFD\u3044\n *\n * @tparam T \u5024\u306E\u578B\n */\ntemplate <typename\
    \ T>\nstruct ChminSum {\n    static constexpr T lowest = std::numeric_limits<T>::lowest();\n\
    \n    struct S {\n        T sum;\n        T max1, max2;      // \u6700\u5927\u5024\
    \u30012\u756A\u76EE\u306E\u6700\u5927\u5024 (\u306A\u3051\u308C\u3070 lowest)\n\
    \        long long max_cnt;  // \u6700\u5927\u5024\u306E\u500B\u6570\n       \
    \ constexpr S() : sum(0), max1(lowest), max2(lowest), max_cnt(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), max1(x), max2(lowest), max_cnt(1) {}\n    };\n    using\
    \ F = T;\n\n    static constexpr S op(const S& a, const S& b) {\n        S res;\n\
    \        res.sum = a.sum + b.sum;\n        if (a.max1 == b.max1) {\n         \
    \   res.max1 = a.max1;\n            res.max_cnt = a.max_cnt + b.max_cnt;\n   \
    \         res.max2 = std::max(a.max2, b.max2);\n        } else if (a.max1 > b.max1)\
    \ {\n            res.max1 = a.max1;\n            res.max_cnt = a.max_cnt;\n  \
    \          res.max2 = std::max(a.max2, b.max1);\n        } else {\n          \
    \  res.max1 = b.max1;\n            res.max_cnt = b.max_cnt;\n            res.max2\
    \ = std::max(a.max1, b.max2);\n        }\n        return res;\n    }\n    static\
    \ constexpr S e() { return S(); }\n    static constexpr std::pair<bool, S> mapping(const\
    \ F& f, const S& x) {\n        if (x.max1 <= f) return {false, x};\n        //\
    \ \u6700\u5927\u5024\u3060\u3051\u304C\u5909\u308F\u308B (\u5024\u304C 1 \u7A2E\
    \u985E\u306A\u3089 f = lowest \u3067\u3082\u6210\u529F\u3055\u305B\u308B)\n  \
    \      if (x.max2 < f || x.max2 == lowest) {\n            S res = x;\n       \
    \     res.sum -= (x.max1 - f) * T(x.max_cnt);\n            res.max1 = f;\n   \
    \         return {false, res};\n        }\n        return {true, x};\n    }\n\
    \    static constexpr F composition(const F& f, const F& g) { return std::min(f,\
    \ g); }\n    static constexpr F id() { return std::numeric_limits<T>::max(); }\n\
    };\n\n/**\n * @brief \u533A\u9593 chmax\u3001\u533A\u9593\u548C\u30FB\u6700\u5C0F\
    \u5024\n *\n * \u4F5C\u7528\u7D20\u306F chmax \u3059\u308B\u5024 (x <- max(x,\
    \ f))\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u304B\u3089\u4F5C\u308A\u3001\
    sum, min1 \u3067\u533A\u9593\u548C\u30FB\u6700\u5C0F\u5024\u3092\u53D6\u5F97\u3059\
    \u308B\n * \u7A7A\u306E\u533A\u9593\u3067\u306F min1 = numeric_limits<T>::max()\n\
    \ * ChminChmaxAddSum \u3088\u308A\u8EFD\u3044\n *\n * @tparam T \u5024\u306E\u578B\
    \n */\ntemplate <typename T>\nstruct ChmaxSum {\n    static constexpr T highest\
    \ = std::numeric_limits<T>::max();\n\n    struct S {\n        T sum;\n       \
    \ T min1, min2;      // \u6700\u5C0F\u5024\u30012\u756A\u76EE\u306E\u6700\u5C0F\
    \u5024 (\u306A\u3051\u308C\u3070 highest)\n        long long min_cnt;  // \u6700\
    \u5C0F\u5024\u306E\u500B\u6570\n        constexpr S() : sum(0), min1(highest),\
    \ min2(highest), min_cnt(0) {}\n        constexpr S(const T& x) : sum(x), min1(x),\
    \ min2(highest), min_cnt(1) {}\n    };\n    using F = T;\n\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        S res;\n        res.sum = a.sum + b.sum;\n\
    \        if (a.min1 == b.min1) {\n            res.min1 = a.min1;\n           \
    \ res.min_cnt = a.min_cnt + b.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min2);\n        } else if (a.min1 < b.min1) {\n            res.min1 = a.min1;\n\
    \            res.min_cnt = a.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min1);\n        } else {\n            res.min1 = b.min1;\n            res.min_cnt\
    \ = b.min_cnt;\n            res.min2 = std::min(a.min1, b.min2);\n        }\n\
    \        return res;\n    }\n    static constexpr S e() { return S(); }\n    static\
    \ constexpr std::pair<bool, S> mapping(const F& f, const S& x) {\n        if (x.min1\
    \ >= f) return {false, x};\n        // \u6700\u5C0F\u5024\u3060\u3051\u304C\u5909\
    \u308F\u308B (\u5024\u304C 1 \u7A2E\u985E\u306A\u3089 f = highest \u3067\u3082\
    \u6210\u529F\u3055\u305B\u308B)\n        if (x.min2 > f || x.min2 == highest)\
    \ {\n            S res = x;\n            res.sum += (f - x.min1) * T(x.min_cnt);\n\
    \            res.min1 = f;\n            return {false, res};\n        }\n    \
    \    return {true, x};\n    }\n    static constexpr F composition(const F& f,\
    \ const F& g) { return std::max(f, g); }\n    static constexpr F id() { return\
    \ std::numeric_limits<T>::lowest(); }\n};\n\n/**\n * @brief \u533A\u9593 chmin\u30FB\
    chmax\u30FB\u52A0\u7B97\u30FB\u4EE3\u5165\u3001\u533A\u9593\u548C\u30FB\u6700\u5927\
    \u5024\u30FB\u6700\u5C0F\u5024\n *\n * \u4F5C\u7528\u7D20 F{lb, ub, add} \u306F\
    \ x <- clamp(x + add, lb, ub) \u3092\u8868\u3059 (lb <= ub)\n * chmin(b), chmax(b),\
    \ add(b), update(b) \u3067\u4F5C\u308B\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\
    \u304B\u3089\u4F5C\u308A\u3001sum, max1, min1 \u3067\u533A\u9593\u548C\u30FB\u6700\
    \u5927\u5024\u30FB\u6700\u5C0F\u5024\u3092\u53D6\u5F97\u3059\u308B\n * \u7A7A\u306E\
    \u533A\u9593\u3067\u306F max1 = numeric_limits<T>::lowest(), min1 = numeric_limits<T>::max()\n\
    \ *\n * @tparam T \u5024\u306E\u578B (\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3092\
    \u60F3\u5B9A\u3059\u308B)\n */\ntemplate <typename T>\nstruct ChminChmaxAddSum\
    \ {\n    static constexpr T lowest = std::numeric_limits<T>::lowest();\n    static\
    \ constexpr T highest = std::numeric_limits<T>::max();\n\n    struct S {\n   \
    \     T sum;\n        T max1, max2;  // \u6700\u5927\u5024\u30012\u756A\u76EE\u306E\
    \u6700\u5927\u5024 (\u306A\u3051\u308C\u3070 lowest)\n        T min1, min2;  //\
    \ \u6700\u5C0F\u5024\u30012\u756A\u76EE\u306E\u6700\u5C0F\u5024 (\u306A\u3051\u308C\
    \u3070 highest)\n        long long max_cnt, min_cnt;  // \u6700\u5927\u5024\u30FB\
    \u6700\u5C0F\u5024\u306E\u500B\u6570\n        constexpr S() : sum(0), max1(lowest),\
    \ max2(lowest), min1(highest), min2(highest), max_cnt(0), min_cnt(0) {}\n    \
    \    constexpr S(const T& x) : sum(x), max1(x), max2(lowest), min1(x), min2(highest),\
    \ max_cnt(1), min_cnt(1) {}\n    };\n    struct F {\n        T lb, ub, add;\n\
    \    };\n\n    static constexpr F chmin(const T& b) { return {lowest, b, T(0)};\
    \ }\n    static constexpr F chmax(const T& b) { return {b, highest, T(0)}; }\n\
    \    static constexpr F add(const T& b) { return {lowest, highest, b}; }\n   \
    \ static constexpr F update(const T& b) { return {b, b, T(0)}; }\n\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        S res;\n        res.sum =\
    \ a.sum + b.sum;\n        if (a.max1 == b.max1) {\n            res.max1 = a.max1;\n\
    \            res.max_cnt = a.max_cnt + b.max_cnt;\n            res.max2 = std::max(a.max2,\
    \ b.max2);\n        } else if (a.max1 > b.max1) {\n            res.max1 = a.max1;\n\
    \            res.max_cnt = a.max_cnt;\n            res.max2 = std::max(a.max2,\
    \ b.max1);\n        } else {\n            res.max1 = b.max1;\n            res.max_cnt\
    \ = b.max_cnt;\n            res.max2 = std::max(a.max1, b.max2);\n        }\n\
    \        if (a.min1 == b.min1) {\n            res.min1 = a.min1;\n           \
    \ res.min_cnt = a.min_cnt + b.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min2);\n        } else if (a.min1 < b.min1) {\n            res.min1 = a.min1;\n\
    \            res.min_cnt = a.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min1);\n        } else {\n            res.min1 = b.min1;\n            res.min_cnt\
    \ = b.min_cnt;\n            res.min2 = std::min(a.min1, b.min2);\n        }\n\
    \        return res;\n    }\n    static constexpr S e() { return S(); }\n    static\
    \ constexpr std::pair<bool, S> mapping(const F& f, const S& x, long long sz) {\n\
    \        if (x.max_cnt == 0) return {false, x};\n        S res = x;\n        //\
    \ \u52A0\u7B97 (\u756A\u5175\u306B\u306F\u8DB3\u3055\u306A\u3044)\n        res.sum\
    \ += f.add * T(sz);\n        res.max1 += f.add;\n        res.min1 += f.add;\n\
    \        if (res.max2 != lowest) res.max2 += f.add;\n        if (res.min2 != highest)\
    \ res.min2 += f.add;\n        // \u5024\u304C 1 \u7A2E\u985E\n        if (res.max1\
    \ == res.min1) {\n            T v = std::clamp(res.max1, f.lb, f.ub);\n      \
    \      res.max1 = res.min1 = v;\n            res.sum = v * T(sz);\n          \
    \  return {false, res};\n        }\n        // \u5024\u304C 2 \u7A2E\u985E\n \
    \       if (res.max1 == res.min2) {\n            T hi = std::clamp(res.max1, f.lb,\
    \ f.ub), lo = std::clamp(res.min1, f.lb, f.ub);\n            if (hi == lo) {\n\
    \                res.max1 = res.min1 = hi;\n                res.max2 = lowest;\n\
    \                res.min2 = highest;\n                res.max_cnt = res.min_cnt\
    \ = sz;\n                res.sum = hi * T(sz);\n            } else {\n       \
    \         res.max1 = res.min2 = hi;\n                res.min1 = res.max2 = lo;\n\
    \                res.sum = hi * T(res.max_cnt) + lo * T(res.min_cnt);\n      \
    \      }\n            return {false, res};\n        }\n        // \u5024\u304C\
    \ 3 \u7A2E\u985E\u4EE5\u4E0A: \u6700\u5927\u5024\u3068\u6700\u5C0F\u5024\u3060\
    \u3051\u304C\u5909\u308F\u308B\u5834\u5408\u4EE5\u5916\u306F\u5931\u6557\n   \
    \     if (f.ub <= res.max2 || f.lb >= res.min2) return {true, res};\n        if\
    \ (f.ub < res.max1) {\n            res.sum -= (res.max1 - f.ub) * T(res.max_cnt);\n\
    \            res.max1 = f.ub;\n        }\n        if (f.lb > res.min1) {\n   \
    \         res.sum += (f.lb - res.min1) * T(res.min_cnt);\n            res.min1\
    \ = f.lb;\n        }\n        return {false, res};\n    }\n    // g \u3092\u9069\
    \u7528\u3057\u305F\u5F8C\u306B f \u3092\u9069\u7528\u3059\u308B\n    static constexpr\
    \ F composition(const F& f, const F& g) {\n        T lb = g.lb == lowest ? f.lb\
    \ : std::clamp(g.lb + f.add, f.lb, f.ub);\n        T ub = g.ub == highest ? f.ub\
    \ : std::clamp(g.ub + f.add, f.lb, f.ub);\n        return {lb, ub, g.add + f.add};\n\
    \    }\n    static constexpr F id() { return {lowest, highest, T(0)}; }\n};\n\n\
    }  // namespace beats_acted_monoid\n"
  code: "#pragma once\n\n/**\n * @file beats-acted-monoid.hpp\n * @brief Segment Tree\
    \ Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n *\n\
    \ * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\
    \ \u3068\u540C\u3058\u30E1\u30F3\u30D0\u3092\u6301\u3064\u304C\u3001\n * mapping\
    \ \u306F std::pair<bool, S> (\u4F5C\u7528\u306B\u5931\u6557\u3057\u305F\u304B\
    , \u4F5C\u7528\u5F8C\u306E\u5024) \u3092\u8FD4\u3059\n * data_structures/segtree-beats.hpp\
    \ \u306B\u6E21\u3057\u3066\u4F7F\u3046\n */\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <utility>\n\nnamespace beats_acted_monoid {\n\n/**\n * @brief\
    \ \u533A\u9593 chmin\u3001\u533A\u9593\u548C\u30FB\u6700\u5927\u5024\n *\n * \u4F5C\
    \u7528\u7D20\u306F chmin \u3059\u308B\u5024 (x <- min(x, f))\n * S(x) \u3067\u5024\
    \ x \u306E1\u8981\u7D20\u304B\u3089\u4F5C\u308A\u3001sum, max1 \u3067\u533A\u9593\
    \u548C\u30FB\u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\u308B\n * \u7A7A\u306E\u533A\
    \u9593\u3067\u306F max1 = numeric_limits<T>::lowest()\n * ChminChmaxAddSum \u3088\
    \u308A\u8EFD\u3044\n *\n * @tparam T \u5024\u306E\u578B\n */\ntemplate <typename\
    \ T>\nstruct ChminSum {\n    static constexpr T lowest = std::numeric_limits<T>::lowest();\n\
    \n    struct S {\n        T sum;\n        T max1, max2;      // \u6700\u5927\u5024\
    \u30012\u756A\u76EE\u306E\u6700\u5927\u5024 (\u306A\u3051\u308C\u3070 lowest)\n\
    \        long long max_cnt;  // \u6700\u5927\u5024\u306E\u500B\u6570\n       \
    \ constexpr S() : sum(0), max1(lowest), max2(lowest), max_cnt(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), max1(x), max2(lowest), max_cnt(1) {}\n    };\n    using\
    \ F = T;\n\n    static constexpr S op(const S& a, const S& b) {\n        S res;\n\
    \        res.sum = a.sum + b.sum;\n        if (a.max1 == b.max1) {\n         \
    \   res.max1 = a.max1;\n            res.max_cnt = a.max_cnt + b.max_cnt;\n   \
    \         res.max2 = std::max(a.max2, b.max2);\n        } else if (a.max1 > b.max1)\
    \ {\n            res.max1 = a.max1;\n            res.max_cnt = a.max_cnt;\n  \
    \          res.max2 = std::max(a.max2, b.max1);\n        } else {\n          \
    \  res.max1 = b.max1;\n            res.max_cnt = b.max_cnt;\n            res.max2\
    \ = std::max(a.max1, b.max2);\n        }\n        return res;\n    }\n    static\
    \ constexpr S e() { return S(); }\n    static constexpr std::pair<bool, S> mapping(const\
    \ F& f, const S& x) {\n        if (x.max1 <= f) return {false, x};\n        //\
    \ \u6700\u5927\u5024\u3060\u3051\u304C\u5909\u308F\u308B (\u5024\u304C 1 \u7A2E\
    \u985E\u306A\u3089 f = lowest \u3067\u3082\u6210\u529F\u3055\u305B\u308B)\n  \
    \      if (x.max2 < f || x.max2 == lowest) {\n            S res = x;\n       \
    \     res.sum -= (x.max1 - f) * T(x.max_cnt);\n            res.max1 = f;\n   \
    \         return {false, res};\n        }\n        return {true, x};\n    }\n\
    \    static constexpr F composition(const F& f, const F& g) { return std::min(f,\
    \ g); }\n    static constexpr F id() { return std::numeric_limits<T>::max(); }\n\
    };\n\n/**\n * @brief \u533A\u9593 chmax\u3001\u533A\u9593\u548C\u30FB\u6700\u5C0F\
    \u5024\n *\n * \u4F5C\u7528\u7D20\u306F chmax \u3059\u308B\u5024 (x <- max(x,\
    \ f))\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u304B\u3089\u4F5C\u308A\u3001\
    sum, min1 \u3067\u533A\u9593\u548C\u30FB\u6700\u5C0F\u5024\u3092\u53D6\u5F97\u3059\
    \u308B\n * \u7A7A\u306E\u533A\u9593\u3067\u306F min1 = numeric_limits<T>::max()\n\
    \ * ChminChmaxAddSum \u3088\u308A\u8EFD\u3044\n *\n * @tparam T \u5024\u306E\u578B\
    \n */\ntemplate <typename T>\nstruct ChmaxSum {\n    static constexpr T highest\
    \ = std::numeric_limits<T>::max();\n\n    struct S {\n        T sum;\n       \
    \ T min1, min2;      // \u6700\u5C0F\u5024\u30012\u756A\u76EE\u306E\u6700\u5C0F\
    \u5024 (\u306A\u3051\u308C\u3070 highest)\n        long long min_cnt;  // \u6700\
    \u5C0F\u5024\u306E\u500B\u6570\n        constexpr S() : sum(0), min1(highest),\
    \ min2(highest), min_cnt(0) {}\n        constexpr S(const T& x) : sum(x), min1(x),\
    \ min2(highest), min_cnt(1) {}\n    };\n    using F = T;\n\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        S res;\n        res.sum = a.sum + b.sum;\n\
    \        if (a.min1 == b.min1) {\n            res.min1 = a.min1;\n           \
    \ res.min_cnt = a.min_cnt + b.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min2);\n        } else if (a.min1 < b.min1) {\n            res.min1 = a.min1;\n\
    \            res.min_cnt = a.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min1);\n        } else {\n            res.min1 = b.min1;\n            res.min_cnt\
    \ = b.min_cnt;\n            res.min2 = std::min(a.min1, b.min2);\n        }\n\
    \        return res;\n    }\n    static constexpr S e() { return S(); }\n    static\
    \ constexpr std::pair<bool, S> mapping(const F& f, const S& x) {\n        if (x.min1\
    \ >= f) return {false, x};\n        // \u6700\u5C0F\u5024\u3060\u3051\u304C\u5909\
    \u308F\u308B (\u5024\u304C 1 \u7A2E\u985E\u306A\u3089 f = highest \u3067\u3082\
    \u6210\u529F\u3055\u305B\u308B)\n        if (x.min2 > f || x.min2 == highest)\
    \ {\n            S res = x;\n            res.sum += (f - x.min1) * T(x.min_cnt);\n\
    \            res.min1 = f;\n            return {false, res};\n        }\n    \
    \    return {true, x};\n    }\n    static constexpr F composition(const F& f,\
    \ const F& g) { return std::max(f, g); }\n    static constexpr F id() { return\
    \ std::numeric_limits<T>::lowest(); }\n};\n\n/**\n * @brief \u533A\u9593 chmin\u30FB\
    chmax\u30FB\u52A0\u7B97\u30FB\u4EE3\u5165\u3001\u533A\u9593\u548C\u30FB\u6700\u5927\
    \u5024\u30FB\u6700\u5C0F\u5024\n *\n * \u4F5C\u7528\u7D20 F{lb, ub, add} \u306F\
    \ x <- clamp(x + add, lb, ub) \u3092\u8868\u3059 (lb <= ub)\n * chmin(b), chmax(b),\
    \ add(b), update(b) \u3067\u4F5C\u308B\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\
    \u304B\u3089\u4F5C\u308A\u3001sum, max1, min1 \u3067\u533A\u9593\u548C\u30FB\u6700\
    \u5927\u5024\u30FB\u6700\u5C0F\u5024\u3092\u53D6\u5F97\u3059\u308B\n * \u7A7A\u306E\
    \u533A\u9593\u3067\u306F max1 = numeric_limits<T>::lowest(), min1 = numeric_limits<T>::max()\n\
    \ *\n * @tparam T \u5024\u306E\u578B (\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3092\
    \u60F3\u5B9A\u3059\u308B)\n */\ntemplate <typename T>\nstruct ChminChmaxAddSum\
    \ {\n    static constexpr T lowest = std::numeric_limits<T>::lowest();\n    static\
    \ constexpr T highest = std::numeric_limits<T>::max();\n\n    struct S {\n   \
    \     T sum;\n        T max1, max2;  // \u6700\u5927\u5024\u30012\u756A\u76EE\u306E\
    \u6700\u5927\u5024 (\u306A\u3051\u308C\u3070 lowest)\n        T min1, min2;  //\
    \ \u6700\u5C0F\u5024\u30012\u756A\u76EE\u306E\u6700\u5C0F\u5024 (\u306A\u3051\u308C\
    \u3070 highest)\n        long long max_cnt, min_cnt;  // \u6700\u5927\u5024\u30FB\
    \u6700\u5C0F\u5024\u306E\u500B\u6570\n        constexpr S() : sum(0), max1(lowest),\
    \ max2(lowest), min1(highest), min2(highest), max_cnt(0), min_cnt(0) {}\n    \
    \    constexpr S(const T& x) : sum(x), max1(x), max2(lowest), min1(x), min2(highest),\
    \ max_cnt(1), min_cnt(1) {}\n    };\n    struct F {\n        T lb, ub, add;\n\
    \    };\n\n    static constexpr F chmin(const T& b) { return {lowest, b, T(0)};\
    \ }\n    static constexpr F chmax(const T& b) { return {b, highest, T(0)}; }\n\
    \    static constexpr F add(const T& b) { return {lowest, highest, b}; }\n   \
    \ static constexpr F update(const T& b) { return {b, b, T(0)}; }\n\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        S res;\n        res.sum =\
    \ a.sum + b.sum;\n        if (a.max1 == b.max1) {\n            res.max1 = a.max1;\n\
    \            res.max_cnt = a.max_cnt + b.max_cnt;\n            res.max2 = std::max(a.max2,\
    \ b.max2);\n        } else if (a.max1 > b.max1) {\n            res.max1 = a.max1;\n\
    \            res.max_cnt = a.max_cnt;\n            res.max2 = std::max(a.max2,\
    \ b.max1);\n        } else {\n            res.max1 = b.max1;\n            res.max_cnt\
    \ = b.max_cnt;\n            res.max2 = std::max(a.max1, b.max2);\n        }\n\
    \        if (a.min1 == b.min1) {\n            res.min1 = a.min1;\n           \
    \ res.min_cnt = a.min_cnt + b.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min2);\n        } else if (a.min1 < b.min1) {\n            res.min1 = a.min1;\n\
    \            res.min_cnt = a.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min1);\n        } else {\n            res.min1 = b.min1;\n            res.min_cnt\
    \ = b.min_cnt;\n            res.min2 = std::min(a.min1, b.min2);\n        }\n\
    \        return res;\n    }\n    static constexpr S e() { return S(); }\n    static\
    \ constexpr std::pair<bool, S> mapping(const F& f, const S& x, long long sz) {\n\
    \        if (x.max_cnt == 0) return {false, x};\n        S res = x;\n        //\
    \ \u52A0\u7B97 (\u756A\u5175\u306B\u306F\u8DB3\u3055\u306A\u3044)\n        res.sum\
    \ += f.add * T(sz);\n        res.max1 += f.add;\n        res.min1 += f.add;\n\
    \        if (res.max2 != lowest) res.max2 += f.add;\n        if (res.min2 != highest)\
    \ res.min2 += f.add;\n        // \u5024\u304C 1 \u7A2E\u985E\n        if (res.max1\
    \ == res.min1) {\n            T v = std::clamp(res.max1, f.lb, f.ub);\n      \
    \      res.max1 = res.min1 = v;\n            res.sum = v * T(sz);\n          \
    \  return {false, res};\n        }\n        // \u5024\u304C 2 \u7A2E\u985E\n \
    \       if (res.max1 == res.min2) {\n            T hi = std::clamp(res.max1, f.lb,\
    \ f.ub), lo = std::clamp(res.min1, f.lb, f.ub);\n            if (hi == lo) {\n\
    \                res.max1 = res.min1 = hi;\n                res.max2 = lowest;\n\
    \                res.min2 = highest;\n                res.max_cnt = res.min_cnt\
    \ = sz;\n                res.sum = hi * T(sz);\n            } else {\n       \
    \         res.max1 = res.min2 = hi;\n                res.min1 = res.max2 = lo;\n\
    \                res.sum = hi * T(res.max_cnt) + lo * T(res.min_cnt);\n      \
    \      }\n            return {false, res};\n        }\n        // \u5024\u304C\
    \ 3 \u7A2E\u985E\u4EE5\u4E0A: \u6700\u5927\u5024\u3068\u6700\u5C0F\u5024\u3060\
    \u3051\u304C\u5909\u308F\u308B\u5834\u5408\u4EE5\u5916\u306F\u5931\u6557\n   \
    \     if (f.ub <= res.max2 || f.lb >= res.min2) return {true, res};\n        if\
    \ (f.ub < res.max1) {\n            res.sum -= (res.max1 - f.ub) * T(res.max_cnt);\n\
    \            res.max1 = f.ub;\n        }\n        if (f.lb > res.min1) {\n   \
    \         res.sum += (f.lb - res.min1) * T(res.min_cnt);\n            res.min1\
    \ = f.lb;\n        }\n        return {false, res};\n    }\n    // g \u3092\u9069\
    \u7528\u3057\u305F\u5F8C\u306B f \u3092\u9069\u7528\u3059\u308B\n    static constexpr\
    \ F composition(const F& f, const F& g) {\n        T lb = g.lb == lowest ? f.lb\
    \ : std::clamp(g.lb + f.add, f.lb, f.ub);\n        T ub = g.ub == highest ? f.ub\
    \ : std::clamp(g.ub + f.add, f.lb, f.ub);\n        return {lb, ub, g.add + f.add};\n\
    \    }\n    static constexpr F id() { return {lowest, highest, T(0)}; }\n};\n\n\
    }  // namespace beats_acted_monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/beats-acted-monoid.hpp
  requiredBy:
  - src/data_structures/segtree-beats.hpp
  timestamp: '2026-10-16 03:54:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/segtree-beats.test.cpp
  - test/unittest/dual-segtree.test.cpp
  - test/unittest/beats-acted-monoid.test.cpp
  - test/yosupo/range-chmin-chmax-add-range-sum.2.test.cpp
  - test/yosupo/range-chmin-chmax-add-range-sum.3.test.cpp
  - test/yosupo/range-chmin-chmax-add-range-sum.1.test.cpp
documentation_of: src/algebra/beats-acted-monoid.hpp
layout: document
title: "Segment Tree Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
  \u30C9"
---

[Segment Tree Beats](../data_structures/segtree-beats.hpp) に渡す作用素付きモノイドです。メンバは [作用素付きモノイド](acted-monoid.hpp) と同じですが、`mapping` は `std::pair<bool, S>` (作用に失敗したか, 作用後の値) を返すので、遅延伝搬セグメント木には渡せません。

```cpp
using A = beats_acted_monoid::ChminChmaxAddSum<long long>;
SegTreeBeats<A> seg(std::vector<A::S>(a.begin(), a.end()));  // a は std::vector<long long>
seg.apply(l, r, A::chmin(x));   // [l, r) を min(a[i], x) に
seg.apply(l, r, A::add(x));     // [l, r) に x を足す
A::S s = seg.prod(l, r);
s.sum; s.max1; s.min1;          // [l, r) の和、最大値、最小値
```

## 一覧 (`namespace beats_acted_monoid`)

| 作用素付きモノイド | 作用 | 取得 | 作用素の型 `F` |
|---|---|---|---|
| `ChminSum<T>` | 区間 chmin | 区間和・最大値 | `T` |
| `ChmaxSum<T>` | 区間 chmax | 区間和・最小値 | `T` |
| `ChminChmaxAddSum<T>` | 区間 chmin・chmax・加算・代入 | 区間和・最大値・最小値 | `F{lb, ub, add}` |

## 区間 chmin `ChminSum<T>`・区間 chmax `ChmaxSum<T>`

作用素は chmin (chmax) する値そのものです。`seg.apply(l, r, x)` で $[l, r)$ の各値を $\min(a_i, x)$ ($\max(a_i, x)$) にします。

要素 `S` は `S(x)` で値 `x` の 1 要素から作ります。`ChminSum` のメンバ `sum`、`max1` が区間和・最大値です。ほかに 2 番目の最大値 `max2`、最大値の個数 `max_cnt` を持ちます。`ChmaxSum` は同様に `sum`、`min1`、`min2`、`min_cnt` を持ちます。空の区間では `max1` が `numeric_limits<T>::lowest()`、`min1` が `numeric_limits<T>::max()` です。

作用が chmin だけ (chmax だけ) なら、`ChminChmaxAddSum` より 3〜4 倍ほど速く動きます。計算量は償却 $O(\log n)$ です。

## 区間 chmin・chmax・加算・代入 `ChminChmaxAddSum<T>`

作用素 `F{lb, ub, add}` は $x \leftarrow \mathrm{clamp}(x + \mathit{add}, \mathit{lb}, \mathit{ub})$ を表します ($\mathit{lb} \le \mathit{ub}$)。次の static 関数で作ります。

| 関数 | 作用 |
|---|---|
| `chmin(b)` | $x \leftarrow \min(x, b)$ |
| `chmax(b)` | $x \leftarrow \max(x, b)$ |
| `add(b)` | $x \leftarrow x + b$ |
| `update(b)` | $x \leftarrow b$ |

要素 `S` は `S(x)` で値 `x` の 1 要素から作ります。メンバ `sum`、`max1`、`min1` が区間和・最大値・最小値です。ほかに 2 番目の最大値 `max2`、2 番目の最小値 `min2`、最大値・最小値の個数 `max_cnt`、`min_cnt` を持ちます。空の区間では `max1` が `numeric_limits<T>::lowest()`、`min1` が `numeric_limits<T>::max()` です。

- `T` は符号付き整数を想定しています。値に足し続けて `numeric_limits<T>` の端に届くとオーバーフローします。
- 計算量は、作用が chmin・chmax だけなら償却 $O(\log n)$、加算もあると償却 $O(\log^2 n)$ です。

## 関連

- これを渡して使うデータ構造は [Segment Tree Beats](../data_structures/segtree-beats.hpp)
- 作用が常に成功する場合は [作用素付きモノイド](acted-monoid.hpp)
