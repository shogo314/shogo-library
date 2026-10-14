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
    path: src/data_structures/persistent-lazy-segtree.hpp
    title: "\u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
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
  bundledCode: "#line 1 \"test/unittest/persistent-lazy-segtree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// PersistentLazySegTree \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u7248\u3054\
    \u3068\u306B\u914D\u5217\u3092\u6301\u3064) \u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u53E4\u3044\u7248\u304B\u3089\u66F4\u65B0\u3057\u3066\
    \u3082\u3001\u307B\u304B\u306E\u7248\u304C\u5909\u308F\u3089\u306A\u3044\u3053\
    \u3068\u3092\u78BA\u304B\u3081\u308B\n// \u5408\u6210\u304C\u53EF\u63DB\u3067\u306A\
    \u3044\u4F5C\u7528 (\u30A2\u30D5\u30A3\u30F3\u5909\u63DB) \u3068\u3001\u533A\u9593\
    \u306E\u4F4D\u7F6E\u3092\u4F7F\u3046\u4F5C\u7528 (a_i \u306B f * i \u3092\u8DB3\
    \u3059) \u3092\u4F7F\u3046\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/persistent-lazy-segtree.hpp\"\
    \n\n/**\n * @file persistent-lazy-segtree.hpp\n * @brief \u6C38\u7D9A\u9045\u5EF6\
    \u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <memory>\n#include <ostream>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/algebra/acted-monoid.hpp\"\n\n/**\n * @file\
    \ acted-monoid.hpp\n * @brief \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9\u306E\u5B9A\u7FA9\n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\
    \u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\
    \u3068\u3057\u3066\u8868\u3059\n * - using F: \u4F5C\u7528\u7D20\u306E\u578B\n\
    \ * - S mapping(const F& f, const S& x): \u4F5C\u7528\u7D20\u306E\u9069\u7528\
    \ f(x)\n *   \u533A\u9593\u306E\u60C5\u5831\u304C\u5FC5\u8981\u306A\u5834\u5408\
    \u306F mapping(f, x, sz) (sz \u306F\u533A\u9593\u306E\u9577\u3055) \u3084 mapping(f,\
    \ x, l, r) (\u533A\u9593 [l, r)) \u3067\u3082\u3088\u3044\n *   sz, l, r \u306F\
    \ long long \u3067\u6E21\u3059 (\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3067\u306F int \u306B\u53CE\u307E\u3089\u306A\u3044\u3053\u3068\u304C\u3042\u308B\
    )\n * - F composition(const F& f, const F& g): \u4F5C\u7528\u7D20\u306E\u5408\u6210\
    \ f\u2218g (g\u3092\u9069\u7528\u3057\u305F\u5F8C\u306Bf\u3092\u9069\u7528\u3059\
    \u308B)\n * - F id(): \u6052\u7B49\u5199\u50CF\n * \u4F5C\u7528\u7D20\u304C\u7FA4\
    \u3092\u306A\u3059\u5834\u5408 (imos.hpp \u3067\u4F7F\u3046) \u306F\n * - F inv(const\
    \ F& f): \u9006\u4F5C\u7528\u7D20\n */\n\n#line 19 \"src/algebra/acted-monoid.hpp\"\
    \n#include <array>\n#include <cstddef>\n#include <limits>\n#include <optional>\n\
    #include <type_traits>\n#line 25 \"src/algebra/acted-monoid.hpp\"\n\n#line 2 \"\
    src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\
    \u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\
    \u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using\
    \ S: \u8981\u7D20\u306E\u578B\n * - S op(const S& a, const S& b): \u7A4D (\u7D50\
    \u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\
    \u975E static \u3067\u3082\u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\
    \u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\
    \u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\n#line 17 \"src/algebra/monoid.hpp\"\
    \n#include <istream>\n#line 19 \"src/algebra/monoid.hpp\"\n#include <numeric>\n\
    #line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\u95A2\u6570 f(x)\
    \ = a * x + b\n *\n * monoid::Composite \u306E\u8981\u7D20\u3084 acted_monoid::AffineSum\
    \ \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B: Affine<mint> f{2, 3};\
    \ f(x) \u306F 2x + 3\u3002\u7701\u7565\u3059\u308B\u3068\u6052\u7B49\u5199\u50CF\
    \ {1, 0}\n */\ntemplate <typename T>\nstruct Affine {\n    T a = T(1);  //!< \u50BE\
    \u304D\n    T b = T(0);  //!< \u5207\u7247\n    constexpr T operator()(const T&\
    \ x) const { return a * x + b; }\n    friend constexpr bool operator==(const Affine&\
    \ f, const Affine& g) { return f.a == g.a && f.b == g.b; }\n    friend constexpr\
    \ bool operator!=(const Affine& f, const Affine& g) { return !(f == g); }\n  \
    \  template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Affine& f) {\n  \
    \      return is >> f.a >> f.b;\n    }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
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
    \ b); }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief {0,\
    \ 1, ..., N-1} \u304B\u3089\u81EA\u5206\u81EA\u8EAB\u3078\u306E\u5199\u50CF\u306E\
    \u5408\u6210 (\u5909\u63DB\u30E2\u30CE\u30A4\u30C9)\n *\n * \u8981\u7D20 f \u306F\
    \ f[x] \u304C x \u306E\u884C\u304D\u5148\u3092\u8868\u3059 std::array<int, N>\u3002\
    \u5168\u5358\u5C04\u3067\u306A\u304F\u3066\u3088\u3044\n * op(f, g) = f\u2218\
    g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\u3002\u533A\u9593 [l, r) \u306E\
    \u7A4D\u306F f_l(...f_{r-1}(x)) \u3092\u8868\u3059\n * \u5DE6\u304B\u3089\u9806\
    \u306B\u9069\u7528\u3057\u305F\u3044\u5834\u5408\u306F monoid::Reverse<monoid::Mapping<N>>\
    \ \u3092\u4F7F\u3046\n * \u4F8B: SegTree<monoid::Mapping<3>> seg(n); seg.set(i,\
    \ {0, 2, 1});\n * swap(i, j) \u3067 i \u3068 j \u3092\u5165\u308C\u66FF\u3048\u308B\
    \u5199\u50CF\u3092\u4F5C\u308C\u308B\n *\n * @tparam N \u5199\u50CF\u306E\u5B9A\
    \u7FA9\u57DF\u30FB\u5024\u57DF\u306E\u5927\u304D\u3055\n */\ntemplate <std::size_t\
    \ N>\nstruct Mapping {\n    using S = std::array<int, N>;\n    static constexpr\
    \ S op(const S& f, const S& g) {\n        S h{};\n        for (std::size_t x =\
    \ 0; x < N; x++) h[x] = f[g[x]];\n        return h;\n    }\n    static constexpr\
    \ S e() {\n        S h{};\n        for (std::size_t x = 0; x < N; x++) h[x] =\
    \ static_cast<int>(x);\n        return h;\n    }\n    // i \u3068 j \u3092\u5165\
    \u308C\u66FF\u3048\u3001\u307B\u304B\u306F\u52D5\u304B\u3055\u306A\u3044\u5199\
    \u50CF (\u4E92\u63DB)\n    static constexpr S swap(int i, int j) {\n        S\
    \ h = e();\n        h[i] = j;\n        h[j] = i;\n        return h;\n    }\n};\n\
    \n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\u5408\u6210\n * op(f, g)\
    \ = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n * \u533A\u9593 [l,\
    \ r) \u306E\u7A4D\u306F f_l(...f_{r-1}(x)) \u3092\u8868\u3059\n * \u5DE6\u304B\
    \u3089\u9806\u306B\u9069\u7528\u3057\u305F\u3044 (f_{r-1}(...f_l(x)) \u3092\u6C42\
    \u3081\u305F\u3044) \u5834\u5408\u306F monoid::Reverse<monoid::Composite<T>> \u3092\
    \u4F7F\u3046\n */\ntemplate <typename T>\nstruct Composite {\n    using S = Affine<T>;\n\
    \    static constexpr S op(const S& f, const S& g) { return {f.a * g.a, f.a *\
    \ g.b + f.b}; }\n    static constexpr S e() { return {T(1), T(0)}; }\n};\n\n/**\n\
    \ * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis {\n    struct\
    \ S {\n        long long close;  // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\
    \u306A\u3044 ')' \u306E\u500B\u6570\n        long long open;   // \u5BFE\u5FDC\
    \u306E\u53D6\u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\n        constexpr\
    \ S(char c = 0) : close(c == ')'), open(c == '(') {}\n        constexpr S(long\
    \ long close, long long open) : close(close), open(open) {}\n        /**\n   \
    \      * @brief \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n         */\n    \
    \    constexpr bool is_valid() const { return close == 0 && open == 0; }\n   \
    \ };\n    static constexpr S op(const S& a, const S& b) {\n        if (a.open\
    \ >= b.close) return S(a.close, a.open - b.close + b.open);\n        return S(a.close\
    \ + b.close - a.open, b.open);\n    }\n    static constexpr S e() { return S();\
    \ }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\
    \u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\
    \u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\
    \u5024\u306E\u578B\n */\ntemplate <typename T, typename U = int>\nstruct MinWith\
    \ {\n    using S = std::pair<T, U>;\n    static constexpr S op(const S& a, const\
    \ S& b) { return b.first < a.first ? b : a; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\
    \u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\
    \u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\
    \u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename\
    \ T, typename U = int>\nstruct MaxWith {\n    using S = std::pair<T, U>;\n   \
    \ static constexpr S op(const S& a, const S& b) { return a.first < b.first ? b\
    \ : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MinCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if (a.first < b.first) return a;\n        if (b.first < a.first) return\
    \ b;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::max(), U(0)}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MaxCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if (a.first < b.first) return\
    \ b;\n        if (b.first < a.first) return a;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u7A4D\u306E\u9806\u5E8F\u3092\u9006\u306B\u3057\
    \u305F\u30E2\u30CE\u30A4\u30C9 op(a, b) = M::op(b, a)\n *\n * \u4F8B: SegTree<monoid::Reverse<monoid::Composite<mint>>>\
    \ seg(v); \u306E\u533A\u9593 [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x))\n *\n\
    \ * @tparam M \u3082\u3068\u306E\u30E2\u30CE\u30A4\u30C9\n */\ntemplate <typename\
    \ M>\nstruct Reverse {\n    using S = typename M::S;\n    M m;\n    constexpr\
    \ Reverse() : m() {}\n    constexpr explicit Reverse(M m) : m(std::move(m)) {}\n\
    \    constexpr S op(const S& a, const S& b) const { return m.op(b, a); }\n   \
    \ constexpr S e() const { return m.e(); }\n};\n\n}  // namespace monoid\n\n/**\n\
    \ * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\u5358\u4F4D\u5143\
    \u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u30E2\u30CE\u30A4\u30C9\n * \u30E9\
    \u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * \u4F8B: SegTree seg(v, Monoid([](int\
    \ a, int b) { return std::max(a, b); }, -1));\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u578B\n */\ntemplate <typename T, typename Op>\nstruct Monoid {\n    using\
    \ S = T;\n    Op op_object;\n    S identity;\n    Monoid() = default;\n    constexpr\
    \ Monoid(Op op, const S& e) : op_object(std::move(op)), identity(e) {}\n    constexpr\
    \ S op(const S& a, const S& b) const { return op_object(a, b); }\n    constexpr\
    \ S e() const { return identity; }\n};\ntemplate <typename Op, typename T>\nMonoid(Op,\
    \ T) -> Monoid<T, Op>;\n#line 27 \"src/algebra/acted-monoid.hpp\"\n\nnamespace\
    \ internal_acted_monoid {\ntemplate <typename A, typename = void>\nstruct has_mapping_lr\
    \ : std::false_type {};\ntemplate <typename A>\nstruct has_mapping_lr<A, std::void_t<decltype(std::declval<const\
    \ A&>().mapping(std::declval<const typename A::F&>(), std::declval<const typename\
    \ A::S&>(), 0, 0))>> : std::true_type {};\ntemplate <typename A, typename = void>\n\
    struct has_mapping_sz : std::false_type {};\ntemplate <typename A>\nstruct has_mapping_sz<A,\
    \ std::void_t<decltype(std::declval<const A&>().mapping(std::declval<const typename\
    \ A::F&>(), std::declval<const typename A::S&>(), 0))>> : std::true_type {};\n\
    }  // namespace internal_acted_monoid\n\nnamespace acted_monoid {\n\n/**\n * @brief\
    \ \u533A\u9593 [l, r) \u3092\u8868\u3059\u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\
    \u9069\u7528\u3059\u308B\n * mapping \u306E\u5F15\u6570\u306E\u5F62\u306E\u9055\
    \u3044\u3092\u5438\u53CE\u3059\u308B\n */\ntemplate <typename A>\nconstexpr auto\
    \ apply_mapping(const A& a, const typename A::F& f, const typename A::S& x, long\
    \ long l, long long r) {\n    if constexpr (internal_acted_monoid::has_mapping_lr<A>::value)\
    \ {\n        return a.mapping(f, x, l, r);\n    } else if constexpr (internal_acted_monoid::has_mapping_sz<A>::value)\
    \ {\n        return a.mapping(f, x, r - l);\n    } else {\n        return a.mapping(f,\
    \ x);\n    }\n}\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u548C\
    \n */\ntemplate <typename T>\nstruct AddSum : monoid::Sum<T> {\n    using S =\
    \ T;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x,\
    \ long long sz) { return x + f * S(sz); }\n    static constexpr F composition(const\
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
    \    static constexpr S mapping(const F& f, const S& x, long long sz) { return\
    \ f ? *f * S(sz) : x; }\n    static constexpr F composition(const F& f, const\
    \ F& g) { return f ? f : g; }\n    static constexpr F id() { return std::nullopt;\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\u6700\u5C0F\
    \u5024\n */\ntemplate <typename T>\nstruct UpdateMin : monoid::Min<T> {\n    using\
    \ S = T;\n    using F = std::optional<T>;\n    static constexpr S mapping(const\
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
    \   static constexpr S mapping(const F& f, const S& x, long long sz) { return\
    \ f.a * x + f.b * S(sz); }\n    static constexpr F composition(const F& f, const\
    \ F& g) { return {f.a * g.a, f.a * g.b + f.b}; }\n    static constexpr F id()\
    \ { return {T(1), T(0)}; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\
    1\u6B21\u95A2\u6570\u306E\u5408\u6210 (monoid::Composite)\n */\ntemplate <typename\
    \ T>\nstruct UpdateComposite : monoid::Composite<T> {\n    using S = Affine<T>;\n\
    \    using F = std::optional<S>;\n    static constexpr S mapping(const F& f, const\
    \ S& x, long long sz) {\n        if (!f) return x;\n        // f \u3092 sz \u56DE\
    \u5408\u6210\u3059\u308B\n        S ret = monoid::Composite<T>::e(), p = *f;\n\
    \        for (; sz > 0; sz >>= 1) {\n            if (sz & 1) ret = monoid::Composite<T>::op(ret,\
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
    \ K + 1> val;\n        constexpr S() : val{} {}\n        constexpr S(const T&\
    \ x) : val{} {\n            val[0] = T(1);\n            for (int i = 1; i <= K;\
    \ i++) val[i] = val[i - 1] * x;\n        }\n        constexpr const T& operator[](std::size_t\
    \ i) const { return val[i]; }\n    };\n    using F = T;\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        S ret;\n        for (int i = 0; i <=\
    \ K; i++) ret.val[i] = a.val[i] + b.val[i];\n        return ret;\n    }\n    static\
    \ constexpr S e() { return S(); }\n    static S mapping(const F& f, const S& x)\
    \ {\n        // sum (x+f)^i = sum_j binom(i, j) f^j x^(i-j)\n        static const\
    \ auto binom = [] {\n            std::array<std::array<T, K + 1>, K + 1> c{};\n\
    \            for (int i = 0; i <= K; i++) {\n                c[i][0] = c[i][i]\
    \ = T(1);\n                for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j -\
    \ 1] + c[i - 1][j];\n            }\n            return c;\n        }();\n    \
    \    std::array<T, K + 1> pw{};\n        pw[0] = T(1);\n        for (int i = 1;\
    \ i <= K; i++) pw[i] = pw[i - 1] * f;\n        S ret;\n        for (int i = 0;\
    \ i <= K; i++) {\n            for (int j = 0; j <= i; j++) ret.val[i] += binom[i][j]\
    \ * pw[j] * x.val[i - j];\n        }\n        return ret;\n    }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f + g; }\n    static constexpr\
    \ F id() { return F(0); }\n};\n\n}  // namespace acted_monoid\n\n/**\n * @brief\
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
    \ S& x, long long l, long long r) const {\n        if constexpr (std::is_invocable_v<const\
    \ Mapping&, const F&, const S&, long long, long long>) {\n            return mapping_object(f,\
    \ x, l, r);\n        } else if constexpr (std::is_invocable_v<const Mapping&,\
    \ const F&, const S&, long long>) {\n            return mapping_object(f, x, r\
    \ - l);\n        } else {\n            return mapping_object(f, x);\n        }\n\
    \    }\n    constexpr F composition(const F& f, const F& g) const { return composition_object(f,\
    \ g); }\n    constexpr F id() const { return lazy_identity; }\n};\ntemplate <typename\
    \ Op, typename T, typename Mapping, typename Composition, typename U>\nActedMonoid(Op,\
    \ T, Mapping, Composition, U) -> ActedMonoid<T, Op, U, Mapping, Composition>;\n\
    #line 16 \"src/data_structures/persistent-lazy-segtree.hpp\"\n\n/**\n * @brief\
    \ \u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n\
    \ * \u66F4\u65B0\u3059\u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\
    \u5143\u306E\u7248\u306F\u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u6728\
    \u304B\u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\
    \u3059\u308B\n * \u5225\u306E\u7248\u306E\u533A\u9593\u3092\u305D\u306E\u307E\u307E\
    \u5199\u3057\u305F\u7248\u3082\u4F5C\u308C\u308B\n * \u4F8B:\n * PersistentLazySegTree<acted_monoid::AffineSum<mint>>\
    \ s0(v);\n * auto s1 = s0.apply(l, r, Affine<mint>{b, c});  // s0 \u306F\u305D\
    \u306E\u307E\u307E\n * auto s2 = s1.copy(s0, l, r);                   // [l, r)\
    \ \u3092 s0 \u306E\u5024\u306B\u623B\u3057\u305F\u7248\n *\n * @tparam A \u4F5C\
    \u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\n\
    \ */\ntemplate <typename A>\nclass PersistentLazySegTree {\n   public:\n    using\
    \ S = typename A::S;\n    using F = typename A::F;\n\n   private:\n    // \u3059\
    \u3079\u3066\u306E\u7248\u306E\u30CE\u30FC\u30C9\u3092\u6301\u3064\u3002\u30CE\
    \u30FC\u30C9\u306F\u524A\u9664\u3057\u306A\u3044\n    // val \u306F\u30CE\u30FC\
    \u30C9\u306E\u533A\u9593\u306E\u7A4D\u3067\u3001\u305D\u306E\u30CE\u30FC\u30C9\
    \u306E lazy \u306F\u9069\u7528\u6E08\u307F\u3002lazy \u306F\u5B50\u306B\u307E\u3060\
    \u4F1D\u3048\u3066\u3044\u306A\u3044\u4F5C\u7528\u7D20\n    struct Pool {\n  \
    \      A a;\n        std::vector<S> val;\n        std::vector<F> lazy;\n     \
    \   std::vector<int> left, right;  // \u8449\u3067\u306F -1\n        explicit\
    \ Pool(A a) : a(std::move(a)) {}\n        int make_leaf(const S& x) {\n      \
    \      val.push_back(x);\n            lazy.push_back(a.id());\n            left.push_back(-1);\n\
    \            right.push_back(-1);\n            return int(val.size()) - 1;\n \
    \       }\n        int make_node(int l, int r) {\n            val.push_back(a.op(val[l],\
    \ val[r]));\n            lazy.push_back(a.id());\n            left.push_back(l);\n\
    \            right.push_back(r);\n            return int(val.size()) - 1;\n  \
    \      }\n    };\n\n    std::shared_ptr<Pool> pool;\n    int n, sz, root;\n\n\
    \    S op(const S& x, const S& y) const { return pool->a.op(x, y); }\n    S e()\
    \ const { return pool->a.e(); }\n    // \u672B\u5C3E\u306E\u8981\u7D20\u6570\u3092\
    \ 2 \u3079\u304D\u306B\u305D\u308D\u3048\u308B\u305F\u3081\u306E\u4F59\u308A\u306E\
    \u90E8\u5206\u306F\u533A\u9593\u306B\u542B\u3081\u306A\u3044\n    S mapping(const\
    \ F& f, const S& x, int a, int b) const { return acted_monoid::apply_mapping(pool->a,\
    \ f, x, std::min(a, n), std::min(b, n)); }\n    F composition(const F& f, const\
    \ F& g) const { return pool->a.composition(f, g); }\n    F id() const { return\
    \ pool->a.id(); }\n\n    PersistentLazySegTree(std::shared_ptr<Pool> pool, int\
    \ n, int sz, int root) : pool(std::move(pool)), n(n), sz(sz), root(root) {}\n\n\
    \    void init_size() {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n \
    \   }\n    int build(const std::vector<S>& v, int a, int b) {\n        if (b -\
    \ a == 1) return pool->make_leaf(a < n ? v[a] : e());\n        int mid = (a +\
    \ b) / 2;\n        int l = build(v, a, mid);\n        int r = build(v, mid, b);\n\
    \        return pool->make_node(l, r);\n    }\n    // \u30CE\u30FC\u30C9 t ([a,\
    \ b)) \u306B f \u3092\u4F5C\u7528\u3055\u305B\u305F\u65B0\u3057\u3044\u30CE\u30FC\
    \u30C9\n    int apply_node(int t, int a, int b, const F& f) const {\n        S\
    \ x = mapping(f, pool->val[t], a, b);\n        if (b - a == 1) return pool->make_leaf(x);\n\
    \        F g = composition(f, pool->lazy[t]);\n        int l = pool->left[t],\
    \ r = pool->right[t];\n        pool->val.push_back(x);\n        pool->lazy.push_back(g);\n\
    \        pool->left.push_back(l);\n        pool->right.push_back(r);\n       \
    \ return int(pool->val.size()) - 1;\n    }\n    // \u30CE\u30FC\u30C9 t ([a, b))\
    \ \u306E lazy \u3092\u5B50\u306B\u4F1D\u3048\u305F\u3001\u65B0\u3057\u3044\u5B50\
    \u306E\u7D44\n    std::pair<int, int> push(int t, int a, int b) const {\n    \
    \    int mid = (a + b) / 2;\n        const F f = pool->lazy[t];\n        int l\
    \ = apply_node(pool->left[t], a, mid, f);\n        int r = apply_node(pool->right[t],\
    \ mid, b, f);\n        return {l, r};\n    }\n    int set_rec(int t, int a, int\
    \ b, int k, const S& x) const {\n        if (b - a == 1) return pool->make_leaf(x);\n\
    \        int mid = (a + b) / 2;\n        auto [l, r] = push(t, a, b);\n      \
    \  if (k < mid)\n            l = set_rec(l, a, mid, k, x);\n        else\n   \
    \         r = set_rec(r, mid, b, k, x);\n        return pool->make_node(l, r);\n\
    \    }\n    int apply_rec(int t, int a, int b, int l, int r, const F& f) const\
    \ {\n        if (r <= a || b <= l) return t;\n        if (l <= a && b <= r) return\
    \ apply_node(t, a, b, f);\n        int mid = (a + b) / 2;\n        auto [lc, rc]\
    \ = push(t, a, b);\n        lc = apply_rec(lc, a, mid, l, r, f);\n        rc =\
    \ apply_rec(rc, mid, b, l, r, f);\n        return pool->make_node(lc, rc);\n \
    \   }\n    // t \u306E [l, r) \u3092 u \u306B\u7F6E\u304D\u63DB\u3048\u308B\u3002\
    f \u306F u \u306E\u7956\u5148\u306B\u3042\u3063\u3066\u3001\u307E\u3060 u \u306B\
    \u9069\u7528\u3057\u3066\u3044\u306A\u3044\u4F5C\u7528\u7D20\n    int copy_rec(int\
    \ t, int u, int a, int b, int l, int r, const F& f) const {\n        if (r <=\
    \ a || b <= l) return t;\n        if (l <= a && b <= r) return apply_node(u, a,\
    \ b, f);\n        int mid = (a + b) / 2;\n        auto [lc, rc] = push(t, a, b);\n\
    \        F g = composition(f, pool->lazy[u]);\n        lc = copy_rec(lc, pool->left[u],\
    \ a, mid, l, r, g);\n        rc = copy_rec(rc, pool->right[u], mid, b, l, r, g);\n\
    \        return pool->make_node(lc, rc);\n    }\n    // f \u306F\u30CE\u30FC\u30C9\
    \ t \u306E\u7956\u5148\u306B\u3042\u3063\u3066\u3001\u307E\u3060 t \u306B\u9069\
    \u7528\u3057\u3066\u3044\u306A\u3044\u4F5C\u7528\u7D20\n    S prod_rec(int t,\
    \ int a, int b, int l, int r, const F& f) const {\n        if (r <= a || b <=\
    \ l) return e();\n        if (l <= a && b <= r) return mapping(f, pool->val[t],\
    \ a, b);\n        int mid = (a + b) / 2;\n        F g = composition(f, pool->lazy[t]);\n\
    \        return op(prod_rec(pool->left[t], a, mid, l, r, g), prod_rec(pool->right[t],\
    \ mid, b, l, r, g));\n    }\n    // [a, b) \u306E\u3046\u3061 l \u4EE5\u964D\u3067\
    \u3001sum \u306B\u639B\u3051\u308B\u3068 g \u304C\u507D\u306B\u306A\u308B\u6700\
    \u521D\u306E\u4F4D\u7F6E (\u306A\u3051\u308C\u3070 b)\n    template <typename\
    \ G>\n    int max_right_rec(int t, int a, int b, int l, G& g, S& sum, const F&\
    \ f) const {\n        if (b <= l) return b;\n        if (l <= a) {\n         \
    \   S s = op(sum, mapping(f, pool->val[t], a, b));\n            if (g(s)) {\n\
    \                sum = s;\n                return b;\n            }\n        \
    \    if (b - a == 1) return a;\n        }\n        int mid = (a + b) / 2;\n  \
    \      F h = composition(f, pool->lazy[t]);\n        int x = max_right_rec(pool->left[t],\
    \ a, mid, l, g, sum, h);\n        if (x < mid) return x;\n        return max_right_rec(pool->right[t],\
    \ mid, b, l, g, sum, h);\n    }\n    // [a, b) \u306E\u3046\u3061 r \u3088\u308A\
    \u524D\u3067\u3001sum \u306B\u5DE6\u304B\u3089\u639B\u3051\u308B\u3068 g \u304C\
    \u507D\u306B\u306A\u308B\u6700\u5F8C\u306E\u4F4D\u7F6E + 1 (\u306A\u3051\u308C\
    \u3070 a)\n    template <typename G>\n    int min_left_rec(int t, int a, int b,\
    \ int r, G& g, S& sum, const F& f) const {\n        if (r <= a) return a;\n  \
    \      if (b <= r) {\n            S s = op(mapping(f, pool->val[t], a, b), sum);\n\
    \            if (g(s)) {\n                sum = s;\n                return a;\n\
    \            }\n            if (b - a == 1) return b;\n        }\n        int\
    \ mid = (a + b) / 2;\n        F h = composition(f, pool->lazy[t]);\n        int\
    \ x = min_left_rec(pool->right[t], mid, b, r, g, sum, h);\n        if (x > mid)\
    \ return x;\n        return min_left_rec(pool->left[t], a, mid, r, g, sum, h);\n\
    \    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n     *\n     * \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u5358\u4F4D\u5143\
    \u3067\u521D\u671F\u5316\u3059\u308B\u3002\u5358\u4F4D\u5143\u306E\u90E8\u5206\
    \u6728\u306F\u5171\u6709\u3059\u308B\u306E\u3067\u3001n \u304C\u5927\u304D\u304F\
    \u3066\u3082 O(log n) \u3067\u4F5C\u308C\u308B\n     *\n     * @param n \u8981\
    \u7D20\u6570\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9\n     */\n    explicit PersistentLazySegTree(int n = 0, A a = A()) : pool(std::make_shared<Pool>(std::move(a))),\
    \ n(n) {\n        assert(0 <= n);\n        init_size();\n        root = pool->make_leaf(e());\n\
    \        for (int w = 1; w < sz; w <<= 1) root = pool->make_node(root, root);\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param a \u4F5C\u7528\
    \u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit PersistentLazySegTree(const\
    \ std::vector<S>& v, A a = A()) : pool(std::make_shared<Pool>(std::move(a))),\
    \ n(v.size()) {\n        init_size();\n        root = build(v, 0, sz);\n    }\n\
    \n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    int\
    \ size() const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n    S get(int\
    \ k) const {\n        assert(0 <= k && k < n);\n        int t = root, a = 0, b\
    \ = sz;\n        F f = id();\n        while (b - a > 1) {\n            f = composition(f,\
    \ pool->lazy[t]);\n            int mid = (a + b) / 2;\n            if (k < mid)\
    \ {\n                t = pool->left[t];\n                b = mid;\n          \
    \  } else {\n                t = pool->right[t];\n                a = mid;\n \
    \           }\n        }\n        return mapping(f, pool->val[t], a, b);\n   \
    \ }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\
    \u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @return S \u5024\n     */\n    S operator[](int k) const { return get(k);\
    \ }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n   \
    \  *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\
    \u5B57\u578B\n     * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\n     * @param rhs \u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n     * @return std::basic_ostream<CharT, Traits>&\
    \ \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     */\n    template <class CharT,\
    \ class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const PersistentLazySegTree& rhs) {\n        for (int i = 0; i\
    \ < rhs.n; i++) {\n            if (i != 0) os << CharT(' ');\n            os <<\
    \ rhs[i];\n        }\n        return os;\n    }\n\n    /**\n     * @brief \u6307\
    \u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u3057\u305F\u65B0\
    \u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n     * @param x \u65B0\u3057\u3044\u5024\n     * @return PersistentLazySegTree\
    \ \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n\
    \     */\n    PersistentLazySegTree set(int k, const S& x) const {\n        assert(0\
    \ <= k && k < n);\n        return PersistentLazySegTree(pool, n, sz, set_rec(root,\
    \ 0, sz, k, x));\n    }\n\n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\
    \u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\u958B\u533A\u9593\
    \u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \ 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        return prod_rec(root,\
    \ 0, sz, l, r, id());\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\
    \u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @return S \u7DCF\u7A4D\
    \n     */\n    S all_prod() const { return pool->val[root]; }\n\n    /**\n   \
    \  * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u306Bf\u3092\
    \u4F5C\u7528\u3055\u305B\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n   \
    \  *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param f \u4F5C\
    \u7528\u7D20\n     * @return PersistentLazySegTree \u65B0\u3057\u3044\u7248 (\u81EA\
    \u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentLazySegTree\
    \ apply(int k, const F& f) const {\n        assert(0 <= k && k < n);\n       \
    \ return apply(k, k + 1, f);\n    }\n    /**\n     * @brief [l, r)\u306E\u533A\
    \u9593\u306E\u5024\u306Bf\u3092\u4F5C\u7528\u3055\u305B\u305F\u65B0\u3057\u3044\
    \u7248\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\u958B\u533A\u9593\u306E\
    \u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n\
    \     * @param f \u4F5C\u7528\u7D20\n     * @return PersistentLazySegTree \u65B0\
    \u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n\
    \    PersistentLazySegTree apply(int l, int r, const F& f) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        if (l == r) return *this;\n        return\
    \ PersistentLazySegTree(pool, n, sz, apply_rec(root, 0, sz, l, r, f));\n    }\n\
    \n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u3092\u5225\u306E\u7248\u306E\
    \u5024\u306B\u3057\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n \
    \    * @param other \u5199\u3059\u5143\u306E\u7248 (\u81EA\u8EAB\u3068\u540C\u3058\
    \u6728\u304B\u3089\u4F5C\u3063\u305F\u3082\u306E)\n     * @param l \u534A\u958B\
    \u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\
    \u7D42\u7AEF 0<=l<=r<=n\n     * @return PersistentLazySegTree \u65B0\u3057\u3044\
    \u7248 (\u81EA\u8EAB\u3082 other \u3082\u5909\u308F\u3089\u306A\u3044)\n     */\n\
    \    PersistentLazySegTree copy(const PersistentLazySegTree& other, int l, int\
    \ r) const {\n        assert(pool == other.pool);\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        if (l == r) return *this;\n        return PersistentLazySegTree(pool,\
    \ n, sz, copy_rec(root, other.root, 0, sz, l, r, id()));\n    }\n\n    /**\n \
    \    * @brief (r = l or g(prod([l, r))) = true) and (r = n or g(prod([l, r+1)))\
    \ = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\n     * g\u304C\u5358\u8ABF\u306A\
    \u3089\u3001g(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n    \
    \ *\n     * @tparam G\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \ 0<=l<=n\n     * @param g \u5224\u5B9A\u95A2\u6570 g(e) = true\n     * @return\
    \ int\n     */\n    template <typename G>\n    int max_right(int l, G g) const\
    \ {\n        assert(g(e()));\n        assert(0 <= l && l <= n);\n        if (l\
    \ == n) return n;\n        S sum = e();\n        int r = max_right_rec(root, 0,\
    \ sz, l, g, sum, id());\n        return r < n ? r : n;\n    }\n    /**\n     *\
    \ @brief (l = 0 or g(prod([l, r))) = true) and (l = r or g(prod([l-1, r))) = false)\u3068\
    \u306A\u308Bl\u3092\u8FD4\u3059\n     * g\u304C\u5358\u8ABF\u306A\u3089\u3001\
    g(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5C0F\u306El\n     *\n     * @tparam\
    \ G\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n    \
    \ * @param g \u5224\u5B9A\u95A2\u6570 g(e) = true\n     * @return int\n     */\n\
    \    template <typename G>\n    int min_left(int r, G g) const {\n        assert(g(e()));\n\
    \        assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        S sum\
    \ = e();\n        return min_left_rec(root, 0, sz, r, g, sum, id());\n    }\n\n\
    \    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u4E26\u3079\
    \u305F\u5217\u3092\u8FD4\u3059\n     */\n    std::vector<S> to_vector() const\
    \ {\n        std::vector<S> res(n);\n        for (int i = 0; i < n; i++) res[i]\
    \ = get(i);\n        return res;\n    }\n};\n\ntemplate <typename A>\nPersistentLazySegTree(int,\
    \ A) -> PersistentLazySegTree<A>;\ntemplate <typename A>\nPersistentLazySegTree(std::vector<typename\
    \ A::S>, A) -> PersistentLazySegTree<A>;\n#line 9 \"test/unittest/persistent-lazy-segtree.test.cpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <sstream>\n#line 14 \"test/unittest/persistent-lazy-segtree.test.cpp\"\
    \n\n#line 2 \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n * @brief \u56DB\
    \u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\
    \u30AF\u30E9\u30B9\n */\n\n#line 9 \"src/math/modint.hpp\"\n#include <cstdint>\n\
    #line 14 \"src/math/modint.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n\
    \ * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\
    \n#include <iterator>\n#include <set>\n#line 13 \"src/utility/traits.hpp\"\n\n\
    namespace internal_traits {\nusing std::begin, std::end;\n\ntemplate <class T,\
    \ class = void>\nstruct is_range_impl : std::false_type {};\ntemplate <class T>\n\
    struct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>>\
    \ : std::true_type {};\n}  // namespace internal_traits\n\ntemplate <class T>\n\
    struct is_range : internal_traits::is_range_impl<T>::type {};\ntemplate <class\
    \ T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\n#define HAS_METHOD(func_name)\
    \                                                              \\\n    namespace\
    \ internal_traits {                                                          \
    \  \\\n    template <class T, class = void>                                  \
    \                     \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                    \\\n    template <class T>          \
    \                                                           \\\n    struct has_##func_name##_impl<T,\
    \ std::void_t<decltype(std::declval<T>().func_name())>> \\\n        : std::true_type\
    \ {};                                                               \\\n    }\
    \                                                                            \
    \          \\\n    template <class T>                                        \
    \                             \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T>::type\
    \ {};          \\\n    template <class T>                                    \
    \                                 \\\n    inline constexpr bool has_##func_name##_v\
    \ = has_##func_name<T>::value;\n\n#define HAS_METHOD_ARG(func_name)          \
    \                                                                    \\\n    namespace\
    \ internal_traits {                                                          \
    \                      \\\n    template <class T, typename U, class = void>  \
    \                                                             \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                                      \
    \  \\\n    template <class T, typename U>                                    \
    \                                         \\\n    struct has_##func_name##_impl<T,\
    \ U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>> \\\
    \n        : std::true_type {};                                               \
    \                                    \\\n    }                               \
    \                                                                           \\\
    \n    template <class T, typename U>                                         \
    \                                    \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ internal_traits {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace internal_traits\ntemplate <class T>\n\
    struct is_sorted_container : internal_traits::is_sorted_container_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 16 \"src/math/modint.hpp\"\n\nnamespace internal_modint {\n// clang-format\
    \ off\nstatic constexpr std::uint16_t prime32_bases[] {\n    15591,  2018,  166,\
    \ 7429,  8064, 16045, 10503,  4399,  1949,  1295, 2776,  3620,   560,  3128, \
    \ 5212,  2657,\n     2300,  2021, 4652, 1471,  9336,  4018,  2398, 20462, 10277,\
    \  8028, 2213,  6219,   620,  3763,  4852,  5012,\n     3185,  1333, 6227, 5298,\
    \  1074,  2391,  5113,  7061,   803,  1269, 3875,   422,   751,   580,  4729,\
    \ 10239,\n      746,  2951,  556, 2206,  3778,   481,  1522,  3476,   481,  2487,\
    \ 3266,  5633,   488,  3373,  6441,  3344,\n       17, 15105, 1490, 4154,  2036,\
    \  1882,  1813,   467,  3307, 14042, 6371,   658,  1005,   903,   737,  1887,\n\
    \     7447,  1888, 2848, 1784,  7559,  3400,   951, 13969,  4304,   177,   41,\
    \ 19875,  3110, 13221,  8726,   571,\n     7043,  6943, 1199,  352,  6435,   165,\
    \  1169,  3315,   978,   233, 3003,  2562,  2994, 10587, 10030,  2377,\n     1902,\
    \  5354, 4447, 1555,   263, 27027,  2283,   305,   669,  1912,  601,  6186,  \
    \ 429,  1930, 14873,  1784,\n     1661,   524, 3577,  236,  2360,  6146,  2850,\
    \ 55637,  1753,  4178, 8466,   222,  2579,  2743,  2031,  2226,\n     2276,  \
    \ 374, 2132,  813, 23788,  1610,  4422,  5159,  1725,  3597, 3366, 14336,   579,\
    \   165,  1375, 10018,\n    12616,  9816, 1371,  536,  1867, 10864,   857,  2206,\
    \  5788,   434, 8085, 17618,   727,  3639,  1595,  4944,\n     2129,  2029, 8195,\
    \ 8344,  6232,  9183,  8126,  1870,  3296,  7455, 8947, 25017,   541, 19115, \
    \  368,   566,\n     5674,   411,  522, 1027,  8215,  2050,  6544, 10049,   614,\
    \   774, 2333,  3007, 35201,  4706,  1152,  1785,\n     1028,  1540, 3743,  493,\
    \  4474,  2521, 26845,  8354,   864, 18915, 5465,  2447,    42,  4511,  1660,\
    \   166,\n     1249,  6259, 2553,  304,   272,  7286,    73,  6554,   899,  2816,\
    \ 5197, 13330,  7054,  2818,  3199,   811,\n      922,   350, 7514, 4452,  3449,\
    \  2663,  4708,   418,  1621,  1171, 3471,    88, 11345,   412,  1559,   194,\n\
    };\n// clang-format on\n\nstatic constexpr bool is_SPRP(std::uint32_t n, std::uint32_t\
    \ a) noexcept {\n    std::uint32_t d = n - 1;\n    std::uint32_t s = 0;\n    while\
    \ ((d & 1) == 0) {\n        ++s;\n        d >>= 1;\n    }\n    std::uint64_t cur\
    \ = 1;\n    std::uint64_t pw = d;\n    while (pw) {\n        if (pw & 1) cur =\
    \ (cur * a) % n;\n        a = (static_cast<std::uint64_t>(a) * a) % n;\n     \
    \   pw >>= 1;\n    }\n    if (cur == 1) return true;\n    for (std::uint32_t r\
    \ = 0; r < s; ++r) {\n        if (cur == n - 1) return true;\n        cur = (cur\
    \ * cur) % n;\n    }\n    return false;\n}\n\n// 32\u30D3\u30C3\u30C8\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u306E\u7D20\u6570\u5224\u5B9A\n// \u53C2\u8003: M. Forisek\
    \ and J. Jancina, \u201CFast Primality Testing for Integers That Fit into a Machine\
    \ Word,\u201D presented at the Conference on Current Trends in Theory and Practice\
    \ of Informatics, 2015.\n[[nodiscard]]\nstatic constexpr bool is_prime32(std::uint32_t\
    \ x) noexcept {\n    if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n\
    \    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n\
    \    if (x < 121) return (x > 1);\n    std::uint64_t h = x;\n    h = ((h >> 16)\
    \ ^ h) * 0x45d9f3b;\n    h = ((h >> 16) ^ h) * 0x45d9f3b;\n    h = ((h >> 16)\
    \ ^ h) & 0xff;\n    return is_SPRP(x, prime32_bases[h]);\n}\n}  // namespace internal_modint\n\
    \n/// @brief static_modint \u3068 dynamic_modint \u306E\u5B9F\u88C5\u3092 CRTP\
    \ \u306B\u3088\u3063\u3066\u884C\u3046\u305F\u3081\u306E\u30AF\u30E9\u30B9\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n/// @tparam Modint \u3053\u306E\u30AF\u30E9\u30B9\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u7D99\u627F\u3059\u308B\u30AF\u30E9\
    \u30B9\ntemplate <class Modint>\nclass modint_base {\n   public:\n    /// @brief\
    \ \u4FDD\u6301\u3059\u308B\u5024\u306E\u578B\n    using value_type = std::uint32_t;\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ modint_base() noexcept\n        : m_value{0} {}\n\n    /// @brief @c value \u306E\
    \u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value\
    \ \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral,\
    \ ENABLE_IF_T((std::is_integral_v<SignedIntegral> && std::is_signed_v<SignedIntegral>))>\n\
    \    constexpr modint_base(SignedIntegral value) noexcept\n        : m_value{static_cast<value_type>((static_cast<long\
    \ long>(value) % Modint::mod() + Modint::mod()) % Modint::mod())} {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class UnsignedIntegral, ENABLE_IF_T((std::is_integral_v<UnsignedIntegral> &&\
    \ std::is_unsigned_v<UnsignedIntegral>))>\n    constexpr modint_base(UnsignedIntegral\
    \ value) noexcept\n        : m_value{static_cast<value_type>(value % Modint::mod())}\
    \ {}\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u53D6\u5F97\
    \u3057\u307E\u3059\u3002\n    /// @return \u4FDD\u6301\u3057\u3066\u3044\u308B\
    \u5024\n    [[nodiscard]]\n    constexpr value_type val() const noexcept {\n \
    \       return m_value;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\
    \u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\u3001\
    \u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n \
    \   constexpr Modint& operator++() noexcept {\n        ++m_value;\n        if\
    \ (m_value == Modint::mod()) {\n            m_value = 0;\n        }\n        return\
    \ static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30A4\
    \u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr\
    \ Modint operator++(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        ++*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n\
    \    constexpr Modint& operator--() noexcept {\n        if (m_value == 0) {\n\
    \            m_value = Modint::mod();\n        }\n        --m_value;\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30C7\
    \u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr Modint\
    \ operator--(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        --*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u8DB3\u3057\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3059\u6570\n    /// @return @c *this\n    constexpr Modint& operator+=(const\
    \ Modint& x) noexcept {\n        m_value += x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value -= Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u304B\u3089 @c x \u306E\u6301\u3064\u5024\u3092\u5F15\
    \u3044\u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304F\u6570\n    /// @return @c *this\n    constexpr Modint& operator-=(const\
    \ Modint& x) noexcept {\n        m_value -= x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value += Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u639B\u3051\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u308B\u6570\n    /// @return @c *this\n    constexpr Modint& operator*=(const\
    \ Modint& x) noexcept {\n        m_value = static_cast<value_type>(static_cast<std::uint64_t>(m_value)\
    \ * x.m_value % Modint::mod());\n        return static_cast<Modint&>(*this);\n\
    \    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092 @c x\
    \ \u306E\u6301\u3064\u5024\u3067\u5272\u3063\u3066\u3001\u5270\u4F59\u3092\u53D6\
    \u308A\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A\
    \ @f$O(\\log x)@f$\n    /// @param x \u5272\u308B\u6570\n    /// @return @c *this\n\
    \    constexpr Modint& operator/=(const Modint& x) noexcept {\n        return\
    \ *this *= x.inv();\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u30B3\u30D4\u30FC\
    \u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @return @c *this\n    [[nodiscard]]\n\
    \    constexpr Modint operator+() const noexcept {\n        return static_cast<const\
    \ Modint&>(*this);\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u53CD\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @return \u81EA\u8EAB\u306E\u53CD\u6570\
    \n    [[nodiscard]]\n    constexpr Modint operator-() const noexcept {\n     \
    \   return 0 - static_cast<const Modint&>(*this);\n    }\n\n    /// @brief \u81EA\
    \u8EAB\u306E @c n \u4E57\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @remark\
    \ \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log n)@f$\n    /// @param n \u6307\
    \u6570\n    /// @return \u81EA\u8EAB\u306E @c n \u4E57\n    [[nodiscard]]\n  \
    \  constexpr Modint pow(unsigned long long n) const noexcept {\n        Modint\
    \ x = 1;\n        Modint y = static_cast<const Modint&>(*this);\n        while\
    \ (n) {\n            if (n & 1) {\n                x *= y;\n            }\n  \
    \          y *= y;\n            n >>= 1;\n        }\n        return x;\n    }\n\
    \n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\u3002\
    \n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ Modint inv() const noexcept {\n        long long a = Modint::mod();\n      \
    \  long long b = m_value;\n        long long x = 0;\n        long long y = 1;\n\
    \        while (b) {\n            auto t = a / b;\n            auto u = a - t\
    \ * b;\n            a = b;\n            b = u;\n            u = x - t * y;\n \
    \           x = y;\n            y = u;\n        }\n        assert(a == 1 && \"\
    The inverse element does not exist.\");\n        x %= Modint::mod();\n       \
    \ if (x < 0) {\n            x += Modint::mod();\n        }\n        return x;\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3055\u308C\u308B\u6570\n    /// @param y \u8DB3\u3059\u6570\n    ///\
    \ @return @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator+(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} += y);\n\
    \    }\n\n    /// @brief @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304B\u308C\u308B\u6570\n    /// @param y \u5F15\u304F\u6570\n    ///\
    \ @return @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator-(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} -= y);\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u3089\u308C\u308B\u6570\n    /// @param y \u639B\u3051\u308B\u6570\
    \n    /// @return @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator*(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} *= y);\n\
    \    }\n\n    /// @brief @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u5272\u3089\u308C\u308B\u6570\n    /// @param y \u5272\u308B\u6570\n    ///\
    \ @return @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator/(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} /= y);\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\u307E\u3059\
    \u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\u304C\
    \u7B49\u3057\u3051\u308C\u3070 @c true \u3001\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 @c false\n    [[nodiscard]]\n    friend constexpr bool operator==(const\
    \ Modint& x, const Modint& y) noexcept {\n        return x.m_value == y.m_value;\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u304F\u306A\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\
    \u307E\u3059\u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\
    \u5024\u304C\u7B49\u3057\u3051\u308C\u3070 @c false \u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070 @c true\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Modint& x, const Modint& y) noexcept {\n        return !(x == y);\n    }\n\n\
    \    /// @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\u7B26\u53F7\
    \u4ED8\u304D\u6574\u6570\u3092\u8AAD\u307F\u53D6\u308A\u3001 @c x \u306B\u683C\
    \u7D0D\u3057\u307E\u3059\u3002\n    /// @tparam CharT \u5165\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n    /// @tparam Traits \u5165\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n   \
    \ /// @param is \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n    /// @param x \u5165\
    \u529B\u3092\u53D7\u3051\u53D6\u308B\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n   \
    \ /// @return @c is\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Modint& x) {\n  \
    \      long long tmp;\n        is >> tmp;\n        x = tmp;\n        return is;\n\
    \    }\n\n    /// @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306B @c x\
    \ \u306E\u4FDD\u6301\u3059\u308B\u5024\u3092\u51FA\u529B\u3057\u307E\u3059\u3002\
    \n    /// @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\
    \u5B57\u578B\n    /// @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n    /// @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n    /// @param x \u51FA\u529B\u3059\u308B\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\n    /// @return @c os\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Modint& x) {\n        os << x.val();\n        return os;\n\
    \    }\n\n   protected:\n    value_type m_value;\n};\n\n/// @brief \u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\
    \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\
    \u308B\u30AF\u30E9\u30B9\n/// @tparam Mod \u6CD5\ntemplate <std::uint32_t Mod>\n\
    class static_modint : public modint_base<static_modint<Mod>> {\n    static_assert(Mod\
    \ > 0 && Mod <= std::numeric_limits<std::uint32_t>::max() / 2);\n\n   private:\n\
    \    using base_type = modint_base<static_modint<Mod>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static constexpr\
    \ value_type mod() noexcept {\n        return Mod;\n    }\n\n    /// @brief 0\
    \ \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr static_modint()\
    \ noexcept\n        : base_type{} {}\n\n    /// @brief @c value \u306E\u5270\u4F59\
    \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\u671F\
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n\
    \    constexpr static_modint(SignedIntegral value) noexcept\n        : base_type{value}\
    \ {}\n\n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\
    \u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ static_modint inv() const noexcept {\n        if constexpr (internal_modint::is_prime32(Mod))\
    \ {\n            assert(this->m_value != 0 && \"The inverse element of zero does\
    \ not exist.\");\n            return this->pow(Mod - 2);\n        } else {\n \
    \           return base_type::inv();\n        }\n    }\n};\n\n/// @brief \u5B9F\
    \u884C\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\u56DB\u5247\
    \u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\
    \u30E9\u30B9\n/// @tparam ID \u3053\u306EID\u3054\u3068\u306B\u6CD5\u3092\u8A2D\
    \u5B9A\u3059\u308B\u3053\u3068\u304C\u3067\u304D\u307E\u3059\ntemplate <int ID>\n\
    class dynamic_modint : public modint_base<dynamic_modint<ID>> {\n   private:\n\
    \    using base_type = modint_base<dynamic_modint<ID>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static value_type\
    \ mod() noexcept {\n        return modulus;\n    }\n\n    /// @brief \u6CD5\u3092\
    \u8A2D\u5B9A\u3057\u307E\u3059\u3002\n    /// @param m \u65B0\u3057\u3044\u6CD5\
    \n    static void set_mod(value_type m) noexcept {\n        assert(m > 0 && m\
    \ <= std::numeric_limits<value_type>::max() / 2);\n        modulus = m;\n    }\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ dynamic_modint() noexcept\n        : base_type{} {}\n\n    /// @brief @c value\
    \ \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    ///\
    \ @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class\
    \ SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n    constexpr\
    \ dynamic_modint(SignedIntegral value) noexcept\n        : base_type{value} {}\n\
    \n   private:\n    inline static value_type modulus = 998244353;\n};\n\nusing\
    \ modint998244353 = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n#line 16 \"test/unittest/persistent-lazy-segtree.test.cpp\"\
    \n\nusing mint = modint998244353;\n\n// \u7248\u3092\u5897\u3084\u3057\u306A\u304C\
    \u3089\u3001\u3059\u3079\u3066\u306E\u64CD\u4F5C\u3092\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u6BD4\u3079\u308B\n// make_f \u306F\u4F5C\u7528\u7D20\u3092\u3001\
    apply_f \u306F\u4F5C\u7528\u7D20\u3092 1 \u3064\u306E\u5024\u306B\u9069\u7528\u3057\
    \u305F\u7D50\u679C (\u4F4D\u7F6E i \u3092\u53D7\u3051\u53D6\u308B) \u3092\u4F5C\
    \u308B\ntemplate <typename Seg, typename MakeS, typename MakeF, typename ApplyF>\n\
    bool random_test(std::mt19937& rng, int n, Seg seg0, std::vector<typename Seg::S>\
    \ v0, MakeS make_s, MakeF make_f, ApplyF apply_f) {\n    using S = typename Seg::S;\n\
    \    bool ok = true;\n    std::vector<Seg> seg{seg0};\n    std::vector<std::vector<S>>\
    \ naive{v0};\n    auto naive_prod = [&](const std::vector<S>& v, int l, int r)\
    \ {\n        S res = seg0.prod(0, 0);\n        for (int i = l; i < r; i++) res\
    \ = res + v[i];\n        return res;\n    };\n    for (int t = 0; t < 50; t++)\
    \ {\n        int ver = rng() % seg.size();\n        int op = rng() % 7;\n    \
    \    int l = rng() % (n + 1), r = rng() % (n + 1);\n        if (l > r) std::swap(l,\
    \ r);\n        if (op == 0) {\n            auto f = make_f();\n            seg.push_back(seg[ver].apply(l,\
    \ r, f));\n            naive.push_back(naive[ver]);\n            for (int i =\
    \ l; i < r; i++) naive.back()[i] = apply_f(f, naive.back()[i], i);\n        }\
    \ else if (op == 1) {\n            int k = rng() % n;\n            auto f = make_f();\n\
    \            seg.push_back(seg[ver].apply(k, f));\n            naive.push_back(naive[ver]);\n\
    \            naive.back()[k] = apply_f(f, naive.back()[k], k);\n        } else\
    \ if (op == 2) {\n            int k = rng() % n;\n            S x = make_s();\n\
    \            seg.push_back(seg[ver].set(k, x));\n            naive.push_back(naive[ver]);\n\
    \            naive.back()[k] = x;\n        } else if (op == 3) {\n           \
    \ int src = rng() % seg.size();\n            seg.push_back(seg[ver].copy(seg[src],\
    \ l, r));\n            naive.push_back(naive[ver]);\n            for (int i =\
    \ l; i < r; i++) naive.back()[i] = naive[src][i];\n        } else if (op == 4)\
    \ {\n            if (seg[ver].prod(l, r) != naive_prod(naive[ver], l, r)) ok =\
    \ false;\n        } else {\n            int k = rng() % n;\n            if (seg[ver].get(k)\
    \ != naive[ver][k] || seg[ver][k] != naive[ver][k]) ok = false;\n        }\n \
    \   }\n    // \u3059\u3079\u3066\u306E\u7248\u304C\u3001\u4F5C\u3063\u305F\u3068\
    \u304D\u306E\u5185\u5BB9\u306E\u307E\u307E\u304B\n    for (int i = 0; i < int(seg.size());\
    \ i++) {\n        if (seg[i].size() != n) ok = false;\n        if (seg[i].to_vector()\
    \ != naive[i]) ok = false;\n        if (seg[i].all_prod() != naive_prod(naive[i],\
    \ 0, n)) ok = false;\n    }\n    return ok;\n}\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n\n    // \u30A2\u30D5\u30A3\u30F3\u5909\u63DB\
    \u3068\u533A\u9593\u548C\n    using Seg = PersistentLazySegTree<acted_monoid::AffineSum<mint>>;\n\
    \    for (int rep = 0; rep < 1500 && ok; rep++) {\n        int n = rng() % 12\
    \ + 1;\n        std::vector<mint> v(n);\n        Seg seg;\n        if (rep % 2\
    \ == 0) {\n            seg = Seg(n);\n        } else {\n            for (auto&\
    \ x : v) x = rng() % 10;\n            seg = Seg(v);\n        }\n        ok &=\
    \ random_test(\n            rng, n, seg, v, [&]() { return mint(rng() % 10); },\n\
    \            [&]() { return Affine<mint>{mint(rng() % 5), mint(rng() % 5)}; },\n\
    \            [](const Affine<mint>& f, mint x, int) { return f(x); });\n    }\n\
    \n    // a_i \u306B f * i \u3092\u8DB3\u3059\u4F5C\u7528\u3068\u533A\u9593\u548C\
    \ (mapping \u304C\u533A\u9593\u306E\u4F4D\u7F6E [l, r) \u3092\u4F7F\u3046)\n \
    \   auto am = ActedMonoid(\n        [](long long a, long long b) { return a +\
    \ b; }, 0LL,\n        [](long long f, long long x, int l, int r) { return x +\
    \ f * (long long)(l + r - 1) * (r - l) / 2; },\n        [](long long f, long long\
    \ g) { return f + g; }, 0LL);\n    for (int rep = 0; rep < 1500 && ok; rep++)\
    \ {\n        int n = rng() % 12 + 1;\n        std::vector<long long> v(n);\n \
    \       for (auto& x : v) x = rng() % 10;\n        PersistentLazySegTree seg(v,\
    \ am);\n        ok &= random_test(\n            rng, n, seg, v, [&]() { return\
    \ (long long)(rng() % 10); },\n            [&]() { return (long long)(rng() %\
    \ 5); },\n            [](long long f, long long x, int i) { return x + f * i;\
    \ });\n    }\n\n    // \u533A\u9593\u52A0\u7B97\u30FB\u533A\u9593\u548C\u306E\
    \ max_right / min_left (\u5358\u8ABF\u306A g) \u3068\u51FA\u529B\n    for (int\
    \ rep = 0; rep < 1500 && ok; rep++) {\n        int n = rng() % 12 + 1;\n     \
    \   std::vector<long long> v(n);\n        for (auto& x : v) x = rng() % 5;\n \
    \       PersistentLazySegTree<acted_monoid::AddSum<long long>> seg(v);\n     \
    \   int l0 = rng() % (n + 1), r0 = rng() % (n + 1);\n        if (l0 > r0) std::swap(l0,\
    \ r0);\n        long long f = rng() % 3;\n        auto seg2 = seg.apply(l0, r0,\
    \ f);\n        std::vector<long long> v2 = v;\n        for (int i = l0; i < r0;\
    \ i++) v2[i] += f;\n        for (int l = 0; l <= n; l++) {\n            long long\
    \ lim = rng() % 20;\n            int r = l;\n            long long s = 0;\n  \
    \          while (r < n && s + v2[r] <= lim) s += v2[r++];\n            if (seg2.max_right(l,\
    \ [&](long long t) { return t <= lim; }) != r) ok = false;\n        }\n      \
    \  for (int r = 0; r <= n; r++) {\n            long long lim = rng() % 20;\n \
    \           int l = r;\n            long long s = 0;\n            while (l > 0\
    \ && s + v2[l - 1] <= lim) s += v2[--l];\n            if (seg2.min_left(r, [&](long\
    \ long t) { return t <= lim; }) != l) ok = false;\n        }\n        std::ostringstream\
    \ os, expect;\n        os << seg2;\n        for (int i = 0; i < n; i++) expect\
    \ << (i ? \" \" : \"\") << v2[i];\n        if (os.str() != expect.str()) ok =\
    \ false;\n    }\n\n    // \u8981\u7D20\u6570\u304C\u5927\u304D\u304F\u3066\u3082\
    \u5358\u4F4D\u5143\u306E\u6728\u306F O(log n) \u3067\u4F5C\u308C\u308B\n    {\n\
    \        PersistentLazySegTree<acted_monoid::AddSum<long long>> big(1000000000);\n\
    \        auto b1 = big.apply(0, 1000000000, 1);\n        auto b2 = b1.copy(big,\
    \ 10, 999999990);\n        if (big.all_prod() != 0 || b1.all_prod() != 1000000000\
    \ || b2.all_prod() != 20 || b2.prod(5, 15) != 5) ok = false;\n        if (b2.max_right(0,\
    \ [](long long s) { return s < 10; }) != 9) ok = false;\n    }\n\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// PersistentLazySegTree \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u7248\u3054\
    \u3068\u306B\u914D\u5217\u3092\u6301\u3064) \u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u53E4\u3044\u7248\u304B\u3089\u66F4\u65B0\u3057\u3066\
    \u3082\u3001\u307B\u304B\u306E\u7248\u304C\u5909\u308F\u3089\u306A\u3044\u3053\
    \u3068\u3092\u78BA\u304B\u3081\u308B\n// \u5408\u6210\u304C\u53EF\u63DB\u3067\u306A\
    \u3044\u4F5C\u7528 (\u30A2\u30D5\u30A3\u30F3\u5909\u63DB) \u3068\u3001\u533A\u9593\
    \u306E\u4F4D\u7F6E\u3092\u4F7F\u3046\u4F5C\u7528 (a_i \u306B f * i \u3092\u8DB3\
    \u3059) \u3092\u4F7F\u3046\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/persistent-lazy-segtree.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <sstream>\n#include <vector>\n\
    \n#include \"../../src/math/modint.hpp\"\n\nusing mint = modint998244353;\n\n\
    // \u7248\u3092\u5897\u3084\u3057\u306A\u304C\u3089\u3001\u3059\u3079\u3066\u306E\
    \u64CD\u4F5C\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n// make_f\
    \ \u306F\u4F5C\u7528\u7D20\u3092\u3001apply_f \u306F\u4F5C\u7528\u7D20\u3092 1\
    \ \u3064\u306E\u5024\u306B\u9069\u7528\u3057\u305F\u7D50\u679C (\u4F4D\u7F6E i\
    \ \u3092\u53D7\u3051\u53D6\u308B) \u3092\u4F5C\u308B\ntemplate <typename Seg,\
    \ typename MakeS, typename MakeF, typename ApplyF>\nbool random_test(std::mt19937&\
    \ rng, int n, Seg seg0, std::vector<typename Seg::S> v0, MakeS make_s, MakeF make_f,\
    \ ApplyF apply_f) {\n    using S = typename Seg::S;\n    bool ok = true;\n   \
    \ std::vector<Seg> seg{seg0};\n    std::vector<std::vector<S>> naive{v0};\n  \
    \  auto naive_prod = [&](const std::vector<S>& v, int l, int r) {\n        S res\
    \ = seg0.prod(0, 0);\n        for (int i = l; i < r; i++) res = res + v[i];\n\
    \        return res;\n    };\n    for (int t = 0; t < 50; t++) {\n        int\
    \ ver = rng() % seg.size();\n        int op = rng() % 7;\n        int l = rng()\
    \ % (n + 1), r = rng() % (n + 1);\n        if (l > r) std::swap(l, r);\n     \
    \   if (op == 0) {\n            auto f = make_f();\n            seg.push_back(seg[ver].apply(l,\
    \ r, f));\n            naive.push_back(naive[ver]);\n            for (int i =\
    \ l; i < r; i++) naive.back()[i] = apply_f(f, naive.back()[i], i);\n        }\
    \ else if (op == 1) {\n            int k = rng() % n;\n            auto f = make_f();\n\
    \            seg.push_back(seg[ver].apply(k, f));\n            naive.push_back(naive[ver]);\n\
    \            naive.back()[k] = apply_f(f, naive.back()[k], k);\n        } else\
    \ if (op == 2) {\n            int k = rng() % n;\n            S x = make_s();\n\
    \            seg.push_back(seg[ver].set(k, x));\n            naive.push_back(naive[ver]);\n\
    \            naive.back()[k] = x;\n        } else if (op == 3) {\n           \
    \ int src = rng() % seg.size();\n            seg.push_back(seg[ver].copy(seg[src],\
    \ l, r));\n            naive.push_back(naive[ver]);\n            for (int i =\
    \ l; i < r; i++) naive.back()[i] = naive[src][i];\n        } else if (op == 4)\
    \ {\n            if (seg[ver].prod(l, r) != naive_prod(naive[ver], l, r)) ok =\
    \ false;\n        } else {\n            int k = rng() % n;\n            if (seg[ver].get(k)\
    \ != naive[ver][k] || seg[ver][k] != naive[ver][k]) ok = false;\n        }\n \
    \   }\n    // \u3059\u3079\u3066\u306E\u7248\u304C\u3001\u4F5C\u3063\u305F\u3068\
    \u304D\u306E\u5185\u5BB9\u306E\u307E\u307E\u304B\n    for (int i = 0; i < int(seg.size());\
    \ i++) {\n        if (seg[i].size() != n) ok = false;\n        if (seg[i].to_vector()\
    \ != naive[i]) ok = false;\n        if (seg[i].all_prod() != naive_prod(naive[i],\
    \ 0, n)) ok = false;\n    }\n    return ok;\n}\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n\n    // \u30A2\u30D5\u30A3\u30F3\u5909\u63DB\
    \u3068\u533A\u9593\u548C\n    using Seg = PersistentLazySegTree<acted_monoid::AffineSum<mint>>;\n\
    \    for (int rep = 0; rep < 1500 && ok; rep++) {\n        int n = rng() % 12\
    \ + 1;\n        std::vector<mint> v(n);\n        Seg seg;\n        if (rep % 2\
    \ == 0) {\n            seg = Seg(n);\n        } else {\n            for (auto&\
    \ x : v) x = rng() % 10;\n            seg = Seg(v);\n        }\n        ok &=\
    \ random_test(\n            rng, n, seg, v, [&]() { return mint(rng() % 10); },\n\
    \            [&]() { return Affine<mint>{mint(rng() % 5), mint(rng() % 5)}; },\n\
    \            [](const Affine<mint>& f, mint x, int) { return f(x); });\n    }\n\
    \n    // a_i \u306B f * i \u3092\u8DB3\u3059\u4F5C\u7528\u3068\u533A\u9593\u548C\
    \ (mapping \u304C\u533A\u9593\u306E\u4F4D\u7F6E [l, r) \u3092\u4F7F\u3046)\n \
    \   auto am = ActedMonoid(\n        [](long long a, long long b) { return a +\
    \ b; }, 0LL,\n        [](long long f, long long x, int l, int r) { return x +\
    \ f * (long long)(l + r - 1) * (r - l) / 2; },\n        [](long long f, long long\
    \ g) { return f + g; }, 0LL);\n    for (int rep = 0; rep < 1500 && ok; rep++)\
    \ {\n        int n = rng() % 12 + 1;\n        std::vector<long long> v(n);\n \
    \       for (auto& x : v) x = rng() % 10;\n        PersistentLazySegTree seg(v,\
    \ am);\n        ok &= random_test(\n            rng, n, seg, v, [&]() { return\
    \ (long long)(rng() % 10); },\n            [&]() { return (long long)(rng() %\
    \ 5); },\n            [](long long f, long long x, int i) { return x + f * i;\
    \ });\n    }\n\n    // \u533A\u9593\u52A0\u7B97\u30FB\u533A\u9593\u548C\u306E\
    \ max_right / min_left (\u5358\u8ABF\u306A g) \u3068\u51FA\u529B\n    for (int\
    \ rep = 0; rep < 1500 && ok; rep++) {\n        int n = rng() % 12 + 1;\n     \
    \   std::vector<long long> v(n);\n        for (auto& x : v) x = rng() % 5;\n \
    \       PersistentLazySegTree<acted_monoid::AddSum<long long>> seg(v);\n     \
    \   int l0 = rng() % (n + 1), r0 = rng() % (n + 1);\n        if (l0 > r0) std::swap(l0,\
    \ r0);\n        long long f = rng() % 3;\n        auto seg2 = seg.apply(l0, r0,\
    \ f);\n        std::vector<long long> v2 = v;\n        for (int i = l0; i < r0;\
    \ i++) v2[i] += f;\n        for (int l = 0; l <= n; l++) {\n            long long\
    \ lim = rng() % 20;\n            int r = l;\n            long long s = 0;\n  \
    \          while (r < n && s + v2[r] <= lim) s += v2[r++];\n            if (seg2.max_right(l,\
    \ [&](long long t) { return t <= lim; }) != r) ok = false;\n        }\n      \
    \  for (int r = 0; r <= n; r++) {\n            long long lim = rng() % 20;\n \
    \           int l = r;\n            long long s = 0;\n            while (l > 0\
    \ && s + v2[l - 1] <= lim) s += v2[--l];\n            if (seg2.min_left(r, [&](long\
    \ long t) { return t <= lim; }) != l) ok = false;\n        }\n        std::ostringstream\
    \ os, expect;\n        os << seg2;\n        for (int i = 0; i < n; i++) expect\
    \ << (i ? \" \" : \"\") << v2[i];\n        if (os.str() != expect.str()) ok =\
    \ false;\n    }\n\n    // \u8981\u7D20\u6570\u304C\u5927\u304D\u304F\u3066\u3082\
    \u5358\u4F4D\u5143\u306E\u6728\u306F O(log n) \u3067\u4F5C\u308C\u308B\n    {\n\
    \        PersistentLazySegTree<acted_monoid::AddSum<long long>> big(1000000000);\n\
    \        auto b1 = big.apply(0, 1000000000, 1);\n        auto b2 = b1.copy(big,\
    \ 10, 999999990);\n        if (big.all_prod() != 0 || b1.all_prod() != 1000000000\
    \ || b2.all_prod() != 20 || b2.prod(5, 15) != 5) ok = false;\n        if (b2.max_right(0,\
    \ [](long long s) { return s < 10; }) != 9) ok = false;\n    }\n\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/persistent-lazy-segtree.hpp
  - src/algebra/acted-monoid.hpp
  - src/algebra/monoid.hpp
  - src/math/modint.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/persistent-lazy-segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 02:41:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/persistent-lazy-segtree.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/persistent-lazy-segtree.test.cpp
- /verify/test/unittest/persistent-lazy-segtree.test.cpp.html
title: test/unittest/persistent-lazy-segtree.test.cpp
---
