---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/acted-monoid.hpp
    title: "\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/lazy-segtree.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/dsl-2-f.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <iostream>\n\n#line 2 \"src/data_structures/lazy-segtree.hpp\"\n\n\
    /**\n * @file lazy-segtree.hpp\n * @brief \u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <functional>\n#include <ostream>\n#include <utility>\n#include <vector>\n#line\
    \ 2 \"src/algebra/acted-monoid.hpp\"\n\n/**\n * @file acted-monoid.hpp\n * @brief\
    \ \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n\
    \ * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306F\u30E2\u30CE\u30A4\
    \u30C9 (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\
    \u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\
    \n * - using F: \u4F5C\u7528\u7D20\u306E\u578B\n * - S mapping(const F& f, const\
    \ S& x): \u4F5C\u7528\u7D20\u306E\u9069\u7528 f(x)\n *   \u533A\u9593\u306E\u60C5\
    \u5831\u304C\u5FC5\u8981\u306A\u5834\u5408\u306F mapping(f, x, sz) (sz \u306F\u533A\
    \u9593\u306E\u9577\u3055) \u3084 mapping(f, x, l, r) (\u533A\u9593 [l, r)) \u3067\
    \u3082\u3088\u3044\n * - F composition(const F& f, const F& g): \u4F5C\u7528\u7D20\
    \u306E\u5408\u6210 f\u2218g (g\u3092\u9069\u7528\u3057\u305F\u5F8C\u306Bf\u3092\
    \u9069\u7528\u3059\u308B)\n * - F id(): \u6052\u7B49\u5199\u50CF\n * \u4F5C\u7528\
    \u7D20\u304C\u7FA4\u3092\u306A\u3059\u5834\u5408 (imos.hpp \u3067\u4F7F\u3046\
    ) \u306F\n * - F inv(const F& f): \u9006\u4F5C\u7528\u7D20\n */\n\n#include <array>\n\
    #include <limits>\n#include <optional>\n#include <type_traits>\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#line 15 \"src/algebra/monoid.hpp\"\n#include <istream>\n\
    #line 17 \"src/algebra/monoid.hpp\"\n#include <numeric>\n#line 21 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @brief 1\u6B21\u95A2\u6570 f(x) = a * x + b\n *\n * monoid::Composite\
    \ \u306E\u8981\u7D20\u3084 acted_monoid::AffineSum \u306E\u4F5C\u7528\u7D20\u306B\
    \u4F7F\u3046\n * \u4F8B: Affine<mint> f{2, 3}; f(x) \u306F 2x + 3\u3002\u7701\u7565\
    \u3059\u308B\u3068\u6052\u7B49\u5199\u50CF {1, 0}\n */\ntemplate <typename T>\n\
    struct Affine {\n    T a = T(1);  //!< \u50BE\u304D\n    T b = T(0);  //!< \u5207\
    \u7247\n    constexpr T operator()(const T& x) const { return a * x + b; }\n \
    \   friend constexpr bool operator==(const Affine& f, const Affine& g) { return\
    \ f.a == g.a && f.b == g.b; }\n    friend constexpr bool operator!=(const Affine&\
    \ f, const Affine& g) { return !(f == g); }\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, Affine& f) {\n        return is >> f.a >> f.b;\n    }\n    template\
    \ <class CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Affine& f) {\n        return os << f.a << CharT(' ') << f.b;\n\
    \    }\n};\n\nnamespace monoid {\n\n/**\n * @brief \u548C\n */\ntemplate <typename\
    \ T>\nstruct Sum {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a + b; }\n    static constexpr S e() { return S(0); }\n};\n\n\
    /**\n * @brief \u7A4D\n */\ntemplate <typename T>\nstruct Prod {\n    using S\
    \ = T;\n    static constexpr S op(const S& a, const S& b) { return a * b; }\n\
    \    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief \u6700\u5927\
    \u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\u5024\n */\ntemplate <typename\
    \ T>\nstruct Max {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::lowest();\
    \ }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\
    \u6700\u5927\u5024\n */\ntemplate <typename T>\nstruct Min {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return std::min(a, b); }\n\
    \    static constexpr S e() { return std::numeric_limits<S>::max(); }\n};\n\n\
    /**\n * @brief \u6700\u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max}\n\
    \ */\ntemplate <typename T>\nstruct MinMax {\n    using S = std::pair<T, T>;\n\
    \    static constexpr S op(const S& a, const S& b) { return {std::min(a.first,\
    \ b.first), std::max(a.second, b.second)}; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::max(), std::numeric_limits<T>::lowest()}; }\n};\n\n\
    /**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate <typename T>\n\
    struct Xor {\n    using S = T;\n    static constexpr S op(const S& a, const S&\
    \ b) { return a ^ b; }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u8AD6\u7406\u7A4D\n */\ntemplate <typename T>\nstruct And {\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return a & b; }\n\
    \    static constexpr S e() { return ~S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\
    \u548C\n */\ntemplate <typename T>\nstruct Or {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return a | b; }\n    static constexpr\
    \ S e() { return S(0); }\n};\n\n/**\n * @brief \u6700\u5927\u516C\u7D04\u6570\
    \ \u5358\u4F4D\u5143\u306F0\n */\ntemplate <typename T>\nstruct Gcd {\n    static_assert(std::is_integral_v<T>);\n\
    \    using S = T;\n    static constexpr S op(const S& a, const S& b) { return\
    \ std::gcd(a, b); }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u6700\u5C0F\u516C\u500D\u6570 \u5358\u4F4D\u5143\u306F1\n */\ntemplate\
    \ <typename T>\nstruct Lcm {\n    static_assert(std::is_integral_v<T>);\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return std::lcm(a,\
    \ b); }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief 1\u6B21\
    \u95A2\u6570 (Affine) \u306E\u5408\u6210\n * op(f, g) = g\u2218f (\u5DE6\u304B\
    \u3089\u9806\u306B\u9069\u7528\u3059\u308B)\n * \u533A\u9593 [l, r) \u306E\u7A4D\
    \u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\n */\ntemplate <typename T>\nstruct\
    \ Composite {\n    using S = Affine<T>;\n    static constexpr S op(const S& f,\
    \ const S& g) { return {g.a * f.a, g.a * f.b + g.b}; }\n    static constexpr S\
    \ e() { return {T(1), T(0)}; }\n};\n\n/**\n * @brief \u62EC\u5F27\u5217 \u5BFE\
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
    \ Op>;\n#line 23 \"src/algebra/acted-monoid.hpp\"\n\nnamespace acted_monoid {\n\
    \nnamespace detail {\ntemplate <typename A, typename = void>\nstruct has_mapping_lr\
    \ : std::false_type {};\ntemplate <typename A>\nstruct has_mapping_lr<A, std::void_t<decltype(std::declval<const\
    \ A&>().mapping(std::declval<const typename A::F&>(), std::declval<const typename\
    \ A::S&>(), 0, 0))>> : std::true_type {};\ntemplate <typename A, typename = void>\n\
    struct has_mapping_sz : std::false_type {};\ntemplate <typename A>\nstruct has_mapping_sz<A,\
    \ std::void_t<decltype(std::declval<const A&>().mapping(std::declval<const typename\
    \ A::F&>(), std::declval<const typename A::S&>(), 0))>> : std::true_type {};\n\
    } // namespace detail\n\n/**\n * @brief \u533A\u9593 [l, r) \u3092\u8868\u3059\
    \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\u308B\n * mapping\
    \ \u306E\u5F15\u6570\u306E\u5F62\u306E\u9055\u3044\u3092\u5438\u53CE\u3059\u308B\
    \n */\ntemplate <typename A>\nconstexpr auto apply_mapping(const A& a, const typename\
    \ A::F& f, const typename A::S& x, int l, int r) {\n    if constexpr(detail::has_mapping_lr<A>::value)\
    \ {\n        return a.mapping(f, x, l, r);\n    } else if constexpr(detail::has_mapping_sz<A>::value)\
    \ {\n        return a.mapping(f, x, r - l);\n    } else {\n        return a.mapping(f,\
    \ x);\n    }\n}\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u548C\
    \n */\ntemplate <typename T>\nstruct AddSum : monoid::Sum<T> {\n    using S =\
    \ T;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x,\
    \ int sz) { return x + f * S(sz); }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n    static constexpr F inv(const F& f) { return -f; }\n};\n\n/**\n * @brief\
    \ \u533A\u9593\u4E57\u7B97\u3001\u533A\u9593\u548C\n */\ntemplate <typename T>\n\
    struct MulSum : monoid::Sum<T> {\n    using S = T;\n    using F = T;\n    static\
    \ constexpr S mapping(const F& f, const S& x) { return f * x; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f * g; }\n    static constexpr\
    \ F id() { return F(1); }\n    static constexpr F inv(const F& f) { return F(1)\
    \ / f; }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\
    \u5C0F\u5024\n */\ntemplate <typename T>\nstruct AddMin : monoid::Min<T> {\n \
    \   using S = T;\n    using F = T;\n    static constexpr S mapping(const F& f,\
    \ const S& x) { return x + f; }\n    static constexpr F composition(const F& f,\
    \ const F& g) { return f + g; }\n    static constexpr F id() { return F(0); }\n\
    };\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nstruct AddMax : monoid::Max<T> {\n    using S =\
    \ T;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return x + f; }\n    static constexpr F composition(const F& f, const F& g)\
    \ { return f + g; }\n    static constexpr F id() { return F(0); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\u548C\n */\ntemplate <typename\
    \ T>\nstruct UpdateSum : monoid::Sum<T> {\n    using S = T;\n    using F = std::optional<T>;\n\
    \    static constexpr S mapping(const F& f, const S& x, int sz) { return f ? *f\
    \ * S(sz) : x; }\n    static constexpr F composition(const F& f, const F& g) {\
    \ return f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n\
    };\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\u6700\u5C0F\u5024\
    \n */\ntemplate <typename T>\nstruct UpdateMin : monoid::Min<T> {\n    using S\
    \ = T;\n    using F = std::optional<T>;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return f ? *f : x; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f ? f : g; }\n    static constexpr F id() { return\
    \ std::nullopt; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\
    \u6700\u5927\u5024\n */\ntemplate <typename T>\nstruct UpdateMax : monoid::Max<T>\
    \ {\n    using S = T;\n    using F = std::optional<T>;\n    static constexpr S\
    \ mapping(const F& f, const S& x) { return f ? *f : x; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f ? f : g; }\n    static constexpr\
    \ F id() { return std::nullopt; }\n};\n\n/**\n * @brief \u533A\u9593chmin\u3001\
    \u533A\u9593\u6700\u5C0F\u5024\n */\ntemplate <typename T>\nstruct ChminMin :\
    \ monoid::Min<T> {\n    using S = T;\n    using F = T;\n    static constexpr S\
    \ mapping(const F& f, const S& x) { return std::min(f, x); }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return std::min(f, g); }\n    static\
    \ constexpr F id() { return std::numeric_limits<F>::max(); }\n};\n\n/**\n * @brief\
    \ \u533A\u9593chmax\u3001\u533A\u9593\u6700\u5927\u5024\n */\ntemplate <typename\
    \ T>\nstruct ChmaxMax : monoid::Max<T> {\n    using S = T;\n    using F = T;\n\
    \    static constexpr S mapping(const F& f, const S& x) { return std::max(f, x);\
    \ }\n    static constexpr F composition(const F& f, const F& g) { return std::max(f,\
    \ g); }\n    static constexpr F id() { return std::numeric_limits<F>::lowest();\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB x <-\
    \ a * x + b (Affine)\u3001\u533A\u9593\u548C\n */\ntemplate <typename T>\nstruct\
    \ AffineSum : monoid::Sum<T> {\n    using S = T;\n    using F = Affine<T>;\n \
    \   static constexpr S mapping(const F& f, const S& x, int sz) { return f.a *\
    \ x + f.b * S(sz); }\n    static constexpr F composition(const F& f, const F&\
    \ g) { return {f.a * g.a, f.a * g.b + f.b}; }\n    static constexpr F id() { return\
    \ {T(1), T(0)}; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u30011\u6B21\u95A2\
    \u6570\u306E\u5408\u6210 (monoid::Composite)\n */\ntemplate <typename T>\nstruct\
    \ UpdateComposite : monoid::Composite<T> {\n    using S = Affine<T>;\n    using\
    \ F = std::optional<S>;\n    static constexpr S mapping(const F& f, const S& x,\
    \ int sz) {\n        if(!f) return x;\n        // f \u3092 sz \u56DE\u5408\u6210\
    \u3059\u308B\n        S ret = monoid::Composite<T>::e(), p = *f;\n        for(;\
    \ sz > 0; sz >>= 1) {\n            if(sz & 1) ret = monoid::Composite<T>::op(ret,\
    \ p);\n            p = monoid::Composite<T>::op(p, p);\n        }\n        return\
    \ ret;\n    }\n    static constexpr F composition(const F& f, const F& g) { return\
    \ f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\
    \u306E\u4F4D\u7F6E (monoid::MinWith)\n */\ntemplate <typename T, typename U =\
    \ int>\nstruct AddMinWith : monoid::MinWith<T, U> {\n    using S = std::pair<T,\
    \ U>;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return {x.first + f, x.second}; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\
    \u5024\u3068\u305D\u306E\u4F4D\u7F6E (monoid::MaxWith)\n */\ntemplate <typename\
    \ T, typename U = int>\nstruct AddMaxWith : monoid::MaxWith<T, U> {\n    using\
    \ S = std::pair<T, U>;\n    using F = T;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return {x.first + f, x.second}; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f + g; }\n    static constexpr\
    \ F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\
    \u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570 (monoid::MinCount)\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct AddMinCount : monoid::MinCount<T,\
    \ U> {\n    using S = std::pair<T, U>;\n    using F = T;\n    static constexpr\
    \ S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ constexpr F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\
    \u3001\u533A\u9593\u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570 (monoid::MaxCount)\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct AddMaxCount : monoid::MaxCount<T,\
    \ U> {\n    using S = std::pair<T, U>;\n    using F = T;\n    static constexpr\
    \ S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ constexpr F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\
    \u3001\u533A\u9593\u306E0\u4E57\u548C\u304B\u3089K\u4E57\u548C\n *\n * S(x) \u3067\
    \u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\
    S::operator[](i) \u3067 i \u4E57\u548C\u3092\u53D6\u5F97\u3059\u308B\n */\ntemplate\
    \ <typename T, int K>\nstruct AddPowerSum {\n    struct S {\n        std::array<T,\
    \ K + 1> val;\n        S() : val{} {}\n        S(const T& x) {\n            val[0]\
    \ = T(1);\n            for(int i = 1; i <= K; i++) val[i] = val[i - 1] * x;\n\
    \        }\n        const T& operator[](std::size_t i) const { return val[i];\
    \ }\n    };\n    using F = T;\n    static S op(const S& a, const S& b) {\n   \
    \     S ret;\n        for(int i = 0; i <= K; i++) ret.val[i] = a.val[i] + b.val[i];\n\
    \        return ret;\n    }\n    static S e() { return S(); }\n    static S mapping(const\
    \ F& f, const S& x) {\n        // sum (x+f)^i = sum_j binom(i, j) f^j x^(i-j)\n\
    \        static const auto binom = [] {\n            std::array<std::array<T,\
    \ K + 1>, K + 1> c{};\n            for(int i = 0; i <= K; i++) {\n           \
    \     c[i][0] = c[i][i] = T(1);\n                for(int j = 1; j < i; j++) c[i][j]\
    \ = c[i - 1][j - 1] + c[i - 1][j];\n            }\n            return c;\n   \
    \     }();\n        std::array<T, K + 1> pw{};\n        pw[0] = T(1);\n      \
    \  for(int i = 1; i <= K; i++) pw[i] = pw[i - 1] * f;\n        S ret;\n      \
    \  for(int i = 0; i <= K; i++) {\n            for(int j = 0; j <= i; j++) ret.val[i]\
    \ += binom[i][j] * pw[j] * x.val[i - j];\n        }\n        return ret;\n   \
    \ }\n    static F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ F id() { return F(0); }\n};\n\n} // namespace acted_monoid\n\n/**\n * @brief\
    \ \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u304B\u3089\u5B9F\u884C\u6642\
    \u306B\u4F5C\u308B\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n * \u30E9\
    \u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u578B\n * @tparam U \u4F5C\u7528\u7D20\u306E\u578B\n * @tparam Mapping\
    \ \u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\u308B\u95A2\u6570\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306E\u578B \u5F15\u6570\u306F (f, x), (f, x, sz), (f, x, l,\
    \ r) \u306E\u3044\u305A\u308C\u304B\n * @tparam Composition \u4F5C\u7528\u7D20\
    \u306E\u5408\u6210\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\
    \u578B\n */\ntemplate <typename T, typename Op, typename U, typename Mapping,\
    \ typename Composition>\nstruct ActedMonoid {\n    using S = T;\n    using F =\
    \ U;\n    Op op_object;\n    S identity;\n    Mapping mapping_object;\n    Composition\
    \ composition_object;\n    F lazy_identity;\n    ActedMonoid() = default;\n  \
    \  constexpr ActedMonoid(Op op, const S& e, Mapping mapping, Composition composition,\
    \ const F& id)\n        : op_object(std::move(op)), identity(e), mapping_object(std::move(mapping)),\
    \ composition_object(std::move(composition)), lazy_identity(id) {}\n    constexpr\
    \ S op(const S& a, const S& b) const { return op_object(a, b); }\n    constexpr\
    \ S e() const { return identity; }\n    constexpr auto mapping(const F& f, const\
    \ S& x, int l, int r) const {\n        if constexpr(std::is_invocable_v<const\
    \ Mapping&, const F&, const S&, int, int>) {\n            return mapping_object(f,\
    \ x, l, r);\n        } else if constexpr(std::is_invocable_v<const Mapping&, const\
    \ F&, const S&, int>) {\n            return mapping_object(f, x, r - l);\n   \
    \     } else {\n            return mapping_object(f, x);\n        }\n    }\n \
    \   constexpr F composition(const F& f, const F& g) const { return composition_object(f,\
    \ g); }\n    constexpr F id() const { return lazy_identity; }\n};\ntemplate <typename\
    \ Op, typename T, typename Mapping, typename Composition, typename U>\nActedMonoid(Op,\
    \ T, Mapping, Composition, U) -> ActedMonoid<T, Op, U, Mapping, Composition>;\n\
    #line 15 \"src/data_structures/lazy-segtree.hpp\"\n\n/**\n * @brief \u9045\u5EF6\
    \u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u4F8B:\n * LazySegTree<acted_monoid::AffineSum<mint>>\
    \ seg(v);\n *\n * @tparam A \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/acted-monoid.hpp)\n */\ntemplate <typename A>\nclass LazySegTree {\n\
    public:\n    using S = typename A::S;\n    using F = typename A::F;\n\nprivate:\n\
    \    A a;\n    S op(const S& x, const S& y) const { return a.op(x, y); }\n   \
    \ S e() const { return a.e(); }\n    S mapping(const F& f, const S& x, int l,\
    \ int r) const { return acted_monoid::apply_mapping(a, f, x, l, r); }\n    F composition(const\
    \ F& f, const F& g) const { return a.composition(f, g); }\n    F id() const {\
    \ return a.id(); }\n\n    int n, sz, height;\n    std::vector<S> data;\n    std::vector<F>\
    \ lazy;\n\n    void update(int k) { data[k] = op(data[2 * k], data[2 * k + 1]);\
    \ }\n    void apply_node(int k, int h, const F& f) {\n        // \u672B\u5C3E\u306E\
    \u8981\u7D20\u6570\u3092 2 \u3079\u304D\u306B\u305D\u308D\u3048\u308B\u305F\u3081\
    \u306E\u4F59\u308A\u306E\u90E8\u5206\u306F\u533A\u9593\u306B\u542B\u3081\u306A\
    \u3044\n        int l = std::min((k << h) & (sz - 1), n);\n        int r = std::min(((k\
    \ << h) & (sz - 1)) + (1 << h), n);\n        data[k] = mapping(f, data[k], l,\
    \ r);\n        if(k < sz) lazy[k] = composition(f, lazy[k]);\n    }\n    void\
    \ push(int k, int h) {\n        apply_node(2 * k, h-1, lazy[k]);\n        apply_node(2\
    \ * k + 1, h-1, lazy[k]);\n        lazy[k] = id();\n    }\n\n    class LazySegTreeReference\
    \ {\n        LazySegTree& segtree;\n        int k;\n    public:\n        LazySegTreeReference(LazySegTree&\
    \ segtree, int k) : segtree(segtree), k(k) {}\n        LazySegTreeReference& operator=(const\
    \ S& x) {\n            segtree.set(k, x);\n            return *this;\n       \
    \ }\n        operator S() { return segtree.get(k); }\n    };\n\n    void construct_data()\
    \ {\n        sz = 1;\n        height = 0;\n        while (sz < n) {\n        \
    \    sz <<= 1;\n            height++;\n        }\n        data.assign(sz * 2,\
    \ e());\n        lazy.assign(sz * 2, id());\n    }\n\npublic:\n    /**\n     *\
    \ @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param n \u8981\
    \u7D20\u6570\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9\n     */\n    explicit LazySegTree(int n = 0, A a = A()) : a(std::move(a)),\
    \ n(n) {\n        construct_data();\n    }\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param v \u521D\u671F\u306E\u8981\
    \u7D20\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\
    \n     */\n    explicit LazySegTree(const std::vector<S>& v, A a = A()) : LazySegTree(v.size(),\
    \ std::move(a)) {\n        for (int i = 0; i < n; i++) data[sz + i] = v[i];\n\
    \        for (int i = sz - 1; i > 0; i--) update(i);\n    }\n\n    /**\n     *\
    \ @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    int size() const {\
    \ return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\
    \u306E\u5024\u3092\u8FD4\u3059\n     * \n     * @param k \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\n     * @return S \u5024\n     */\n    S get(int k) {\n        assert(0\
    \ <= k && k < n);\n        k += sz;\n        for(int h = height; h > 0; h--) {\n\
    \            push(k >> h, h);\n        }\n        return data[k];\n    }\n   \
    \ /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u3078\u306E\u53C2\
    \u7167\u3092\u8FD4\u3059\n     * \n     * @param k \n     * @return SegTreeReference\
    \ \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\u5165\u3055\u308C\u308B\u3068set()\u304C\
    \u547C\u3070\u308C\u308B\n     */\n    LazySegTreeReference operator[] (int k)\
    \ { return LazySegTreeReference(*this, k); }\n\n    /**\n     * @brief \u5185\u5BB9\
    \u3092\u51FA\u529B\u3059\u308B\n     * \n     * @tparam CharT \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u51FA\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n   \
    \  * @param os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n     * @return std::basic_ostream<CharT, Traits>&\
    \ \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0 \n     */\n    template <class CharT,\
    \ class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, LazySegTree& rhs) {\n        for(int i = 0; i < rhs.n; i++) {\n\
    \            if(i != 0) os << CharT(' ');\n            os << rhs[i];\n       \
    \ }\n        return os;\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n     * \n\
    \     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\u3057\
    \u3044\u5024\n     */\n    void set(int k, const S& x) {\n        assert(0 <=\
    \ k && k < n);\n        k += sz;\n        for(int h = height; h > 0; h--) {\n\
    \            push(k >> h, h);\n        }\n        data[k] = x;\n        while(k\
    \ >>= 1) update(k);\n    }\n\n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\
    \u7DCF\u7A4D\u3092\u8FD4\u3059\n     * \n     * @param l \u534A\u958B\u533A\u9593\
    \u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \ 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        l += sz; r += sz;\n\
    \        for(int h = height; h > 0; h--) {\n            if(((l >> h) << h) !=\
    \ l) push(l >> h, h);\n            if(((r >> h) << h) != r) push(r >> h, h);\n\
    \        }\n        S left_prod = e(), right_prod = e();\n        while(l < r)\
    \ {\n            if(l & 1) left_prod = op(left_prod, data[l++]);\n           \
    \ if(r & 1) right_prod = op(data[--r], right_prod);\n            l >>= 1; r >>=\
    \ 1;\n        }\n        return op(left_prod, right_prod);\n    }\n    /**\n \
    \    * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\
    \u3059\n     * \n     * @return S \u7DCF\u7A4D\n     */\n    S all_prod() const\
    \ { return data[1]; }\n    \n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\
    \u8981\u7D20\u306E\u5024\u306Bf\u3092\u4F5C\u7528\u3055\u305B\u308B\n     * \n\
    \     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param f \u4F5C\u7528\
    \u7D20\n     */\n    void apply(int k, const F& f) {\n        assert(0 <= k &&\
    \ k < n);\n        k += sz;\n        for(int h = height; h > 0; h--) {\n     \
    \       push(k >> h, h);\n        }\n        data[k] = mapping(f, data[k], k -\
    \ sz, k - sz + 1);\n        while(k >>= 1) update(k);\n    }\n    /**\n     *\
    \ @brief [l, r)\u306E\u533A\u9593\u306E\u5024\u306Bx\u3092\u4F5C\u7528\u3055\u305B\
    \u308B\n     * \n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\n\
    \     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n     *\
    \ @param f \u4F5C\u7528\u7D20\n     */\n    void apply(int l, int r, const F&\
    \ f) {\n        assert(0 <= l && l <= r && r <= n);\n        if(l == r) return;\n\
    \        l += sz; r += sz;\n        for(int h = height; h > 0; h--) {\n      \
    \      if(((l >> h) << h) != l) push(l >> h, h);\n            if(((r >> h) <<\
    \ h) != r) push(r >> h, h);\n        }\n        {\n            int l2 = l, r2\
    \ = r;\n            int h = 0;\n            while(l < r) {\n                if(l\
    \ & 1) apply_node(l++, h, f);\n                if(r & 1) apply_node(--r, h, f);\n\
    \                l >>= 1; r >>= 1;\n                h++;\n            }\n    \
    \        l = l2; r = r2;\n        }\n        for(int h = 1; h <= height; h++)\
    \ {\n            if(((l >> h) << h) != l) update(l >> h);\n            if(((r\
    \ >> h) << h) != r) update((r - 1) >> h);\n        }\n    }\n\n    /**\n     *\
    \ @brief (r = l or g(prod([l, r))) = true) and (r = n or g(prod([l, r+1))) = false)\u3068\
    \u306A\u308Br\u3092\u8FD4\u3059\n     * g\u304C\u5358\u8ABF\u306A\u3089\u3001\
    g(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n     * \n     * @tparam\
    \ G\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB 0<=l<=n\n    \
    \ * @param g \u5224\u5B9A\u95A2\u6570 g(e) = true\n     * @return int\n     */\n\
    \    template <typename G>\n    int max_right(int l, G g) {\n        assert(g(e()));\n\
    \        assert(0 <= l && l <= n);\n        if(l == n) return n;\n        l +=\
    \ sz;\n        for(int h = height; h > 0; h--) {\n            push(l >> h, h);\n\
    \        }\n        int h = 0;\n        while(l % 2 == 0) {\n            l >>=\
    \ 1;\n            h++;\n        }\n        S sum = e();\n        while(g(op(sum,\
    \ data[l]))) {\n            sum = op(sum, data[l]);\n            l++;\n      \
    \      while(l % 2 == 0) {\n                l >>= 1;\n                h++;\n \
    \           }\n            if(l == 1) return n;\n        }\n        while(l <\
    \ sz) {\n            push(l, h);\n            if(!g(op(sum, data[l*2]))) {\n \
    \               l = l*2;\n            } else {\n                sum = op(sum,\
    \ data[l*2]);\n                l = l*2+1;\n            }\n            h--;\n \
    \       }\n        return l - sz;\n    }\n    /**\n     * @brief (l = 0 or g(prod([l,\
    \ r))) = true) and (l = r or g(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\
    \u8FD4\u3059\n     * g\u304C\u5358\u8ABF\u306A\u3089\u3001g(prod([l, r))) = true\u3068\
    \u306A\u308B\u6700\u5C0F\u306El\n     * \n     * @tparam G\n     * @param r \u534A\
    \u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param g \u5224\u5B9A\u95A2\
    \u6570 g(e) = true\n     * @return int\n     */\n    template <typename G>\n \
    \   int min_left(int r, G g) {\n        assert(g(e()));\n        assert(0 <= r\
    \ && r <= n);\n        if (r == 0) return 0;\n        r += sz;\n        for(int\
    \ h = height; h > 0; h--) {\n            push((r - 1) >> h, h);\n        }\n \
    \       int h = 0;\n        S sum = e();\n        do {\n            r--;\n   \
    \         while(r > 1 && r % 2 == 1) {\n                r >>= 1;\n           \
    \     h++;\n            }\n            if(!g(op(data[r], sum))) {\n          \
    \      while(r < sz) {\n                    push(r, h);\n                    r\
    \ = r*2 + 1;\n                    h--;\n                    if(g(op(data[r], sum)))\
    \ {\n                        sum = op(data[r], sum);\n                       \
    \ r--;\n                    }\n                }\n                return r + 1\
    \ - sz;\n            }\n            sum = op(data[r], sum);\n        } while((r\
    \ & -r) != r);\n        return 0;\n    }\n};\n\ntemplate <typename A>\nLazySegTree(int,\
    \ A) -> LazySegTree<A>;\ntemplate <typename A>\nLazySegTree(std::vector<typename\
    \ A::S>, A) -> LazySegTree<A>;\n\n/**\n * @brief \u533A\u9593\u6700\u5C0F\u5024\
    \u66F4\u65B0\u3001\u533A\u9593\u6700\u5C0F\u5024\n *\n * @tparam S \u578B\n */\n\
    template <typename S>\nusing RChminMinQ = LazySegTree<acted_monoid::ChminMin<S>>;\n\
    /**\n * @brief \u533A\u9593\u6700\u5927\u5024\u66F4\u65B0\u3001\u533A\u9593\u6700\
    \u5927\u5024\n *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RChmaxMaxQ\
    \ = LazySegTree<acted_monoid::ChmaxMax<S>>;\n/**\n * @brief \u533A\u9593\u52A0\
    \u7B97\u3001\u533A\u9593\u6700\u5C0F\u5024\n *\n * @tparam S \u578B\n */\ntemplate\
    \ <typename S>\nusing RAddMinQ = LazySegTree<acted_monoid::AddMin<S>>;\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\u5024\n *\n\
    \ * @tparam S \u578B\n */\ntemplate <typename S>\nusing RAddMaxQ = LazySegTree<acted_monoid::AddMax<S>>;\n\
    /**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u548C\n *\n * @tparam\
    \ S \u578B\n */\ntemplate <typename S>\nusing RAddSumQ = LazySegTree<acted_monoid::AddSum<S>>;\n\
    /**\n * @brief \u533A\u9593\u5909\u66F4\u3001\u533A\u9593\u6700\u5C0F\u5024\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RUpdateMinQ = LazySegTree<acted_monoid::UpdateMin<S>>;\n\
    /**\n * @brief \u533A\u9593\u5909\u66F4\u3001\u533A\u9593\u6700\u5927\u5024\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RUpdateMaxQ = LazySegTree<acted_monoid::UpdateMax<S>>;\n\
    /**\n * @brief \u533A\u9593\u5909\u66F4\u3001\u533A\u9593\u548C\n *\n * @tparam\
    \ S \u578B\n */\ntemplate <typename S>\nusing RUpdateSumQ = LazySegTree<acted_monoid::UpdateSum<S>>;\n\
    #line 6 \"test/aoj/dsl-2-f.test.cpp\"\n\nint main(void) {\n    int n, q; std::cin\
    \ >> n >> q;\n    LazySegTree<acted_monoid::UpdateMin<int>> seg(n);\n    while(q--)\
    \ {\n        int op; std::cin >> op;\n        if(op == 0) {\n            int s,\
    \ t, x; std::cin >> s >> t >> x; t++;\n            seg.apply(s, t, x);\n     \
    \   } else {\n            int s, t; std::cin >> s >> t; t++;\n            std::cout\
    \ << seg.prod(s, t) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <iostream>\n\n#include \"../../src/data_structures/lazy-segtree.hpp\"\
    \n\nint main(void) {\n    int n, q; std::cin >> n >> q;\n    LazySegTree<acted_monoid::UpdateMin<int>>\
    \ seg(n);\n    while(q--) {\n        int op; std::cin >> op;\n        if(op ==\
    \ 0) {\n            int s, t, x; std::cin >> s >> t >> x; t++;\n            seg.apply(s,\
    \ t, x);\n        } else {\n            int s, t; std::cin >> s >> t; t++;\n \
    \           std::cout << seg.prod(s, t) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/data_structures/lazy-segtree.hpp
  - src/algebra/acted-monoid.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: true
  path: test/aoj/dsl-2-f.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 06:02:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl-2-f.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl-2-f.test.cpp
- /verify/test/aoj/dsl-2-f.test.cpp.html
title: test/aoj/dsl-2-f.test.cpp
---
