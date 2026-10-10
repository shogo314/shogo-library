---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structures/merge-sort-tree.hpp
    title: "\u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u30C4\u30EA\u30FC"
  - icon: ':heavy_check_mark:'
    path: data_structures/potentialized-unionfind.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-dsl-1-b.test.cpp
    title: test/aoj-dsl-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-jag-summer-2971.test.cpp
    title: test/aoj-jag-summer-2971.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-rectangle-sum.test.cpp
    title: test/yosupo-rectangle-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp
    title: test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7FA4\u306E\u5B9A\u7FA9"
    links: []
  bundledCode: "#line 2 \"algebra/group.hpp\"\n\n/**\n * @file group.hpp\n * @brief\
    \ \u7FA4\u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\
    \ \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\
    \u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - S inv(const S& a):\
    \ \u9006\u5143\n */\n\n#line 2 \"algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n\
    \ * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\
    \u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\
    \u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S&\
    \ a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n\
    \ * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\
    \u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\
    \n#include <algorithm>\n#include <limits>\n#include <numeric>\n#include <type_traits>\n\
    #include <utility>\n\nnamespace monoid {\n\n/**\n * @brief \u548C\n */\ntemplate\
    \ <typename T>\nstruct Sum {\n    using S = T;\n    static constexpr S op(const\
    \ S& a, const S& b) { return a + b; }\n    static constexpr S e() { return S(0);\
    \ }\n};\n\n/**\n * @brief \u7A4D\n */\ntemplate <typename T>\nstruct Prod {\n\
    \    using S = T;\n    static constexpr S op(const S& a, const S& b) { return\
    \ a * b; }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief\
    \ \u6700\u5927\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\u5024\n\
    \ */\ntemplate <typename T>\nstruct Max {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return std::max(a, b); }\n    static constexpr\
    \ S e() { return std::numeric_limits<S>::lowest(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5927\u5024\n */\ntemplate\
    \ <typename T>\nstruct Min {\n    using S = T;\n    static constexpr S op(const\
    \ S& a, const S& b) { return std::min(a, b); }\n    static constexpr S e() { return\
    \ std::numeric_limits<S>::max(); }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\
    \u6700\u5927\u5024\u306E\u7D44 {min, max}\n */\ntemplate <typename T>\nstruct\
    \ MinMax {\n    using S = std::pair<T, T>;\n    static constexpr S op(const S&\
    \ a, const S& b) { return {std::min(a.first, b.first), std::max(a.second, b.second)};\
    \ }\n    static constexpr S e() { return {std::numeric_limits<T>::max(), std::numeric_limits<T>::lowest()};\
    \ }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate\
    \ <typename T>\nstruct Xor {\n    using S = T;\n    static constexpr S op(const\
    \ S& a, const S& b) { return a ^ b; }\n    static constexpr S e() { return S(0);\
    \ }\n};\n\n/**\n * @brief \u8AD6\u7406\u7A4D\n */\ntemplate <typename T>\nstruct\
    \ And {\n    using S = T;\n    static constexpr S op(const S& a, const S& b) {\
    \ return a & b; }\n    static constexpr S e() { return ~S(0); }\n};\n\n/**\n *\
    \ @brief \u8AD6\u7406\u548C\n */\ntemplate <typename T>\nstruct Or {\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return a | b; }\n\
    \    static constexpr S e() { return S(0); }\n};\n\n/**\n * @brief \u6700\u5927\
    \u516C\u7D04\u6570 \u5358\u4F4D\u5143\u306F0\n */\ntemplate <typename T>\nstruct\
    \ Gcd {\n    static_assert(std::is_integral_v<T>);\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return std::gcd(a, b); }\n    static\
    \ constexpr S e() { return S(0); }\n};\n\n/**\n * @brief \u6700\u5C0F\u516C\u500D\
    \u6570 \u5358\u4F4D\u5143\u306F1\n */\ntemplate <typename T>\nstruct Lcm {\n \
    \   static_assert(std::is_integral_v<T>);\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return std::lcm(a, b); }\n    static constexpr\
    \ S e() { return S(1); }\n};\n\n/**\n * @brief 1\u6B21\u95A2\u6570 f(x) = first\
    \ * x + second \u306E\u5408\u6210\n * op(f, g) = g\u2218f (\u5DE6\u304B\u3089\u9806\
    \u306B\u9069\u7528\u3059\u308B)\n * \u533A\u9593 [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x))\
    \ \u3092\u8868\u3059\n */\ntemplate <typename T>\nstruct Composite {\n    using\
    \ S = std::pair<T, T>;\n    static constexpr S op(const S& f, const S& g) { return\
    \ {g.first * f.first, g.first * f.second + g.second}; }\n    static constexpr\
    \ S e() { return {T(1), T(0)}; }\n};\n\n/**\n * @brief \u62EC\u5F27\u5217 \u5BFE\
    \u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\u3044 ')' \u3068 '(' \u306E\u500B\u6570\
    \n */\nstruct Parenthesis {\n    struct S {\n        long long close; // \u5BFE\
    \u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\u3044 ')' \u306E\u500B\u6570\n    \
    \    long long open;  // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\u3044\
    \ '(' \u306E\u500B\u6570\n        constexpr S(char c = 0) : close(c == ')'), open(c\
    \ == '(') {}\n        constexpr S(long long close, long long open) : close(close),\
    \ open(open) {}\n        /**\n         * @brief \u6B63\u3057\u3044\u62EC\u5F27\
    \u5217\u304B\n         */\n        constexpr bool is_valid() const { return close\
    \ == 0 && open == 0; }\n    };\n    static constexpr S op(const S& a, const S&\
    \ b) {\n        if(a.open >= b.close) return S(a.close, a.open - b.close + b.open);\n\
    \        return S(a.close + b.close - a.open, b.open);\n    }\n    static constexpr\
    \ S e() { return S(); }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\
    \u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n\
    \ * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\
    \u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename T, typename U =\
    \ int>\nstruct MinWith {\n    using S = std::pair<T, U>;\n    static constexpr\
    \ S op(const S& a, const S& b) { return b.first < a.first ? b : a; }\n    static\
    \ constexpr S e() { return {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n\
    \ * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\
    \u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\
    \n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\
    \u578B\n */\ntemplate <typename T, typename U = int>\nstruct MaxWith {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) { return\
    \ a.first < b.first ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MinCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if(a.first < b.first) return a;\n        if(b.first < a.first) return\
    \ b;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::max(), U(0)}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MaxCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if(a.first < b.first) return\
    \ b;\n        if(b.first < a.first) return a;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U(0)}; }\n};\n\n} // namespace monoid\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3068\u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\
    \u306B\u4F5C\u308B\u30E2\u30CE\u30A4\u30C9\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\
    \u3048\u308B\n *\n * \u4F8B: SegTree seg(v, Monoid([](int a, int b) { return std::max(a,\
    \ b); }, -1));\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\
    \u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate\
    \ <typename T, typename Op>\nstruct Monoid {\n    using S = T;\n    Op op_object;\n\
    \    S identity;\n    Monoid() = default;\n    constexpr Monoid(Op op, const S&\
    \ e) : op_object(std::move(op)), identity(e) {}\n    constexpr S op(const S& a,\
    \ const S& b) const { return op_object(a, b); }\n    constexpr S e() const { return\
    \ identity; }\n};\ntemplate <typename Op, typename T>\nMonoid(Op, T) -> Monoid<T,\
    \ Op>;\n#line 12 \"algebra/group.hpp\"\n\nnamespace group {\n\n/**\n * @brief\
    \ \u52A0\u6CD5\u7FA4\n */\ntemplate <typename T>\nstruct Sum : monoid::Sum<T>\
    \ {\n    using S = T;\n    static constexpr S inv(const S& a) { return -a; }\n\
    };\n\n/**\n * @brief \u4E57\u6CD5\u7FA4 (0\u3092\u542B\u307E\u306A\u3044\u4F53\
    \u306E\u5143\u306A\u3069)\n */\ntemplate <typename T>\nstruct Prod : monoid::Prod<T>\
    \ {\n    using S = T;\n    static constexpr S inv(const S& a) { return S(1) /\
    \ a; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate\
    \ <typename T>\nstruct Xor : monoid::Xor<T> {\n    using S = T;\n    static constexpr\
    \ S inv(const S& a) { return a; }\n};\n\n} // namespace group\n\n/**\n * @brief\
    \ \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\u5358\u4F4D\u5143\u304B\
    \u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u7FA4\n * \u30E9\u30E0\u30C0\u5F0F\u3092\
    \u4F7F\u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\
    \u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n * @tparam\
    \ Inv \u9006\u5143\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\
    \u578B\n */\ntemplate <typename T, typename Op, typename Inv>\nstruct Group {\n\
    \    using S = T;\n    Op op_object;\n    S identity;\n    Inv inv_object;\n \
    \   Group() = default;\n    constexpr Group(Op op, const S& e, Inv inv) : op_object(std::move(op)),\
    \ identity(e), inv_object(std::move(inv)) {}\n    constexpr S op(const S& a, const\
    \ S& b) const { return op_object(a, b); }\n    constexpr S e() const { return\
    \ identity; }\n    constexpr S inv(const S& a) const { return inv_object(a); }\n\
    };\ntemplate <typename Op, typename T, typename Inv>\nGroup(Op, T, Inv) -> Group<T,\
    \ Op, Inv>;\n"
  code: "#pragma once\n\n/**\n * @file group.hpp\n * @brief \u7FA4\u306E\u5B9A\u7FA9\
    \n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp) \u306E\u30E1\
    \u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - S inv(const S& a): \u9006\u5143\
    \n */\n\n#include \"monoid.hpp\"\n\nnamespace group {\n\n/**\n * @brief \u52A0\
    \u6CD5\u7FA4\n */\ntemplate <typename T>\nstruct Sum : monoid::Sum<T> {\n    using\
    \ S = T;\n    static constexpr S inv(const S& a) { return -a; }\n};\n\n/**\n *\
    \ @brief \u4E57\u6CD5\u7FA4 (0\u3092\u542B\u307E\u306A\u3044\u4F53\u306E\u5143\
    \u306A\u3069)\n */\ntemplate <typename T>\nstruct Prod : monoid::Prod<T> {\n \
    \   using S = T;\n    static constexpr S inv(const S& a) { return S(1) / a; }\n\
    };\n\n/**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate <typename\
    \ T>\nstruct Xor : monoid::Xor<T> {\n    using S = T;\n    static constexpr S\
    \ inv(const S& a) { return a; }\n};\n\n} // namespace group\n\n/**\n * @brief\
    \ \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\u5358\u4F4D\u5143\u304B\
    \u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u7FA4\n * \u30E9\u30E0\u30C0\u5F0F\u3092\
    \u4F7F\u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\
    \u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n * @tparam\
    \ Inv \u9006\u5143\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\
    \u578B\n */\ntemplate <typename T, typename Op, typename Inv>\nstruct Group {\n\
    \    using S = T;\n    Op op_object;\n    S identity;\n    Inv inv_object;\n \
    \   Group() = default;\n    constexpr Group(Op op, const S& e, Inv inv) : op_object(std::move(op)),\
    \ identity(e), inv_object(std::move(inv)) {}\n    constexpr S op(const S& a, const\
    \ S& b) const { return op_object(a, b); }\n    constexpr S e() const { return\
    \ identity; }\n    constexpr S inv(const S& a) const { return inv_object(a); }\n\
    };\ntemplate <typename Op, typename T, typename Inv>\nGroup(Op, T, Inv) -> Group<T,\
    \ Op, Inv>;\n"
  dependsOn:
  - algebra/monoid.hpp
  isVerificationFile: false
  path: algebra/group.hpp
  requiredBy:
  - data_structures/potentialized-unionfind.hpp
  - data_structures/merge-sort-tree.hpp
  timestamp: '2026-10-10 20:42:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-jag-summer-2971.test.cpp
  - test/aoj-dsl-1-b.test.cpp
  - test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp
  - test/yosupo-rectangle-sum.test.cpp
documentation_of: algebra/group.hpp
layout: document
redirect_from:
- /library/algebra/group.hpp
- /library/algebra/group.hpp.html
title: "\u7FA4\u306E\u5B9A\u7FA9"
---
