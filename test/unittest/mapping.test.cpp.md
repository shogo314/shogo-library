---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/group.hpp
    title: "\u7FA4\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/potentialized-unionfind.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
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
  bundledCode: "#line 1 \"test/unittest/mapping.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// monoid::Mapping (\u5199\u50CF\u306E\u5408\u6210) \u3068 group::Permutation\
    \ (\u7F6E\u63DB\u306E\u5408\u6210) \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\
    \u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n#include\
    \ <array>\n#include <iostream>\n#include <numeric>\n#include <random>\n#include\
    \ <vector>\n\n#line 2 \"src/algebra/group.hpp\"\n\n/**\n * @file group.hpp\n *\
    \ @brief \u7FA4\u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\
    \u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * -\
    \ S inv(const S& a): \u9006\u5143\n */\n\n#line 12 \"src/algebra/group.hpp\"\n\
    #include <cstddef>\n#include <utility>\n\n#line 2 \"src/algebra/monoid.hpp\"\n\
    \n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#line 17 \"src/algebra/monoid.hpp\"\n#include <istream>\n\
    #include <limits>\n#line 20 \"src/algebra/monoid.hpp\"\n#include <ostream>\n#include\
    \ <type_traits>\n#line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\
    \u95A2\u6570 f(x) = a * x + b\n *\n * monoid::Composite \u306E\u8981\u7D20\u3084\
    \ acted_monoid::AffineSum \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B\
    : Affine<mint> f{2, 3}; f(x) \u306F 2x + 3\u3002\u7701\u7565\u3059\u308B\u3068\
    \u6052\u7B49\u5199\u50CF {1, 0}\n */\ntemplate <typename T>\nstruct Affine {\n\
    \    T a = T(1);  //!< \u50BE\u304D\n    T b = T(0);  //!< \u5207\u7247\n    constexpr\
    \ T operator()(const T& x) const { return a * x + b; }\n    friend constexpr bool\
    \ operator==(const Affine& f, const Affine& g) { return f.a == g.a && f.b == g.b;\
    \ }\n    friend constexpr bool operator!=(const Affine& f, const Affine& g) {\
    \ return !(f == g); }\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
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
    \u50CF (\u4E92\u63DB)\n    static constexpr S swap(long long i, long long j) {\n\
    \        S h = e();\n        h[i] = static_cast<int>(j);\n        h[j] = static_cast<int>(i);\n\
    \        return h;\n    }\n};\n\n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\
    \u5408\u6210\n * op(f, g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B\
    )\n * \u533A\u9593 [l, r) \u306E\u7A4D\u306F f_l(...f_{r-1}(x)) \u3092\u8868\u3059\
    \n * \u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3057\u305F\u3044 (f_{r-1}(...f_l(x))\
    \ \u3092\u6C42\u3081\u305F\u3044) \u5834\u5408\u306F monoid::Reverse<monoid::Composite<T>>\
    \ \u3092\u4F7F\u3046\n */\ntemplate <typename T>\nstruct Composite {\n    using\
    \ S = Affine<T>;\n    static constexpr S op(const S& f, const S& g) { return {f.a\
    \ * g.a, f.a * g.b + f.b}; }\n    static constexpr S e() { return {T(1), T(0)};\
    \ }\n};\n\n/**\n * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\
    \u3044\u306A\u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis\
    \ {\n    struct S {\n        long long close;  // \u5BFE\u5FDC\u306E\u53D6\u308C\
    \u3066\u3044\u306A\u3044 ')' \u306E\u500B\u6570\n        long long open;   //\
    \ \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\
    \n        constexpr S(char c = 0) : close(c == ')'), open(c == '(') {}\n     \
    \   constexpr S(long long close, long long open) : close(close), open(open) {}\n\
    \        /**\n         * @brief \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n \
    \        */\n        constexpr bool is_valid() const { return close == 0 && open\
    \ == 0; }\n    };\n    static constexpr S op(const S& a, const S& b) {\n     \
    \   if (a.open >= b.close) return S(a.close, a.open - b.close + b.open);\n   \
    \     return S(a.close + b.close - a.open, b.open);\n    }\n    static constexpr\
    \ S e() { return S(); }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\
    \u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n\
    \ * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\
    \u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename T, typename U =\
    \ long long>\nstruct MinWith {\n    using S = std::pair<T, U>;\n    static constexpr\
    \ S op(const S& a, const S& b) { return b.first < a.first ? b : a; }\n    static\
    \ constexpr S e() { return {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n\
    \ * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\
    \u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\
    \n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\
    \u578B\n */\ntemplate <typename T, typename U = long long>\nstruct MaxWith {\n\
    \    using S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S&\
    \ b) { return a.first < b.first ? b : a; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::lowest(), U{}}; }\n};\n\n/**\n * @brief \u6700\u5C0F\
    \u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\u578B\n *\
    \ @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename U =\
    \ long long>\nstruct MinCount {\n    using S = std::pair<T, U>;\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        if (a.first < b.first) return a;\n \
    \       if (b.first < a.first) return b;\n        return {a.first, a.second +\
    \ b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MaxCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if (a.first < b.first) return b;\n        if (b.first < a.first) return\
    \ a;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U(0)}; }\n};\n\n/**\n * @brief\
    \ \u533A\u9593\u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\
    \u306E\u6700\u5927\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\
    \u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\
    \u533A\u9593 {0, 0}\n */\ntemplate <typename T>\nstruct PrefixSumMax {\n    struct\
    \ S {\n        T sum;  // \u533A\u9593\u306E\u548C\n        T max;  // \u7A7A\u3092\
    \u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n  \
    \      constexpr S() : sum(0), max(0) {}\n        constexpr S(const T& x) : sum(x),\
    \ max(x < T(0) ? T(0) : x) {}\n        constexpr S(const T& sum, const T& max)\
    \ : sum(sum), max(max) {}\n        friend constexpr bool operator==(const S& a,\
    \ const S& b) { return a.sum == b.sum && a.max == b.max; }\n        friend constexpr\
    \ bool operator!=(const S& a, const S& b) { return !(a == b); }\n    };\n    static\
    \ constexpr S op(const S& a, const S& b) { return S(a.sum + b.sum, std::max(a.max,\
    \ a.sum + b.max)); }\n    static constexpr S e() { return S(); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 prefix\
    \ \u306E\u548C\u306E\u6700\u5C0F\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\
    \u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\
    \u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate <typename T>\nstruct PrefixSumMin\
    \ {\n    struct S {\n        T sum;  // \u533A\u9593\u306E\u548C\n        T min;\
    \  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5C0F\u5024 (0\
    \ \u4EE5\u4E0B)\n        constexpr S() : sum(0), min(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), min(T(0) < x ? T(0) : x) {}\n        constexpr S(const\
    \ T& sum, const T& min) : sum(sum), min(min) {}\n        friend constexpr bool\
    \ operator==(const S& a, const S& b) { return a.sum == b.sum && a.min == b.min;\
    \ }\n        friend constexpr bool operator!=(const S& a, const S& b) { return\
    \ !(a == b); }\n    };\n    static constexpr S op(const S& a, const S& b) { return\
    \ S(a.sum + b.sum, std::min(a.min, a.sum + b.min)); }\n    static constexpr S\
    \ e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3068\u3001\
    \u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024\n * S(x)\
    \ \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\
    \u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate\
    \ <typename T>\nstruct SuffixSumMax {\n    struct S {\n        T sum;  // \u533A\
    \u9593\u306E\u548C\n        T max;  // \u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\
    \u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        constexpr S() : sum(0), max(0)\
    \ {}\n        constexpr S(const T& x) : sum(x), max(x < T(0) ? T(0) : x) {}\n\
    \        constexpr S(const T& sum, const T& max) : sum(sum), max(max) {}\n   \
    \     friend constexpr bool operator==(const S& a, const S& b) { return a.sum\
    \ == b.sum && a.max == b.max; }\n        friend constexpr bool operator!=(const\
    \ S& a, const S& b) { return !(a == b); }\n    };\n    static constexpr S op(const\
    \ S& a, const S& b) { return S(a.sum + b.sum, std::max(b.max, a.max + b.sum));\
    \ }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\
    \u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\
    \u5C0F\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\
    \u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593\
    \ {0, 0}\n */\ntemplate <typename T>\nstruct SuffixSumMin {\n    struct S {\n\
    \        T sum;  // \u533A\u9593\u306E\u548C\n        T min;  // \u7A7A\u3092\u542B\
    \u3080 suffix \u306E\u548C\u306E\u6700\u5C0F\u5024 (0 \u4EE5\u4E0B)\n        constexpr\
    \ S() : sum(0), min(0) {}\n        constexpr S(const T& x) : sum(x), min(T(0)\
    \ < x ? T(0) : x) {}\n        constexpr S(const T& sum, const T& min) : sum(sum),\
    \ min(min) {}\n        friend constexpr bool operator==(const S& a, const S& b)\
    \ { return a.sum == b.sum && a.min == b.min; }\n        friend constexpr bool\
    \ operator!=(const S& a, const S& b) { return !(a == b); }\n    };\n    static\
    \ constexpr S op(const S& a, const S& b) { return S(a.sum + b.sum, std::min(b.min,\
    \ a.min + b.sum)); }\n    static constexpr S e() { return S(); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u306E\u548C\u3001\u7A7A\u3092\u542B\u3080 prefix\u30FB\
    suffix \u306E\u548C\u306E\u6700\u5927\u5024\u3001\u7A7A\u3092\u542B\u3080\u9023\
    \u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024\n * S(x) \u3067\u5024\
    \ x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\
    \u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0, 0, 0}\n * \u9759\u7684\u306A\
    \u5217\u306B\u5BFE\u3057\u3066\u4E00\u5EA6\u3060\u3051\u6C42\u3081\u308B\u306A\
    \u3089 dp/maximum-subarray.hpp \u306E maximum_subarray\n */\ntemplate <typename\
    \ T>\nstruct MaxSubarraySum {\n    struct S {\n        T sum;     // \u533A\u9593\
    \u306E\u548C\n        T prefix;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\
    \u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        T suffix;  // \u7A7A\u3092\u542B\
    \u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        T\
    \ best;    // \u7A7A\u3092\u542B\u3080\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\
    \u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        constexpr S() : sum(0), prefix(0),\
    \ suffix(0), best(0) {}\n        constexpr S(const T& x) : sum(x), prefix(x <\
    \ T(0) ? T(0) : x), suffix(prefix), best(prefix) {}\n        constexpr S(const\
    \ T& sum, const T& prefix, const T& suffix, const T& best)\n            : sum(sum),\
    \ prefix(prefix), suffix(suffix), best(best) {}\n        friend constexpr bool\
    \ operator==(const S& a, const S& b) {\n            return a.sum == b.sum && a.prefix\
    \ == b.prefix && a.suffix == b.suffix && a.best == b.best;\n        }\n      \
    \  friend constexpr bool operator!=(const S& a, const S& b) { return !(a == b);\
    \ }\n    };\n    static constexpr S op(const S& a, const S& b) {\n        return\
    \ S(a.sum + b.sum, std::max(a.prefix, a.sum + b.prefix), std::max(b.suffix, a.suffix\
    \ + b.sum),\n                 std::max({a.best, b.best, a.suffix + b.prefix}));\n\
    \    }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u7A4D\
    \u306E\u9806\u5E8F\u3092\u9006\u306B\u3057\u305F\u30E2\u30CE\u30A4\u30C9 op(a,\
    \ b) = M::op(b, a)\n *\n * \u4F8B: SegTree<monoid::Reverse<monoid::Composite<mint>>>\
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
    \ T) -> Monoid<T, Op>;\n#line 16 \"src/algebra/group.hpp\"\n\nnamespace group\
    \ {\n\n/**\n * @brief \u52A0\u6CD5\u7FA4\n */\ntemplate <typename T>\nstruct Sum\
    \ : monoid::Sum<T> {\n    using S = T;\n    static constexpr S inv(const S& a)\
    \ { return -a; }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7FA4 (0\u3092\u542B\u307E\
    \u306A\u3044\u4F53\u306E\u5143\u306A\u3069)\n */\ntemplate <typename T>\nstruct\
    \ Prod : monoid::Prod<T> {\n    using S = T;\n    static constexpr S inv(const\
    \ S& a) { return S(1) / a; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\
    \u548C\n */\ntemplate <typename T>\nstruct Xor : monoid::Xor<T> {\n    using S\
    \ = T;\n    static constexpr S inv(const S& a) { return a; }\n};\n\n/**\n * @brief\
    \ {0, 1, ..., N-1} \u306E\u7F6E\u63DB (\u5168\u5358\u5C04) \u306E\u5408\u6210\n\
    \ *\n * monoid::Mapping<N> \u306B\u9006\u7F6E\u63DB\u3092\u52A0\u3048\u305F\u3082\
    \u306E\u3002\u8981\u7D20\u306F\u7F6E\u63DB\u3067\u3042\u308B\u3053\u3068\n * op(f,\
    \ g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n *\n * @tparam\
    \ N \u7F6E\u63DB\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\n */\ntemplate <std::size_t\
    \ N>\nstruct Permutation : monoid::Mapping<N> {\n    using S = std::array<int,\
    \ N>;\n    static constexpr S inv(const S& f) {\n        S h{};\n        for (std::size_t\
    \ x = 0; x < N; x++) h[f[x]] = static_cast<int>(x);\n        return h;\n    }\n\
    };\n\n}  // namespace group\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\u3068\u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\
    \u308B\u7FA4\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam\
    \ T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306E\u578B\n * @tparam Inv \u9006\u5143\u306E\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename\
    \ Op, typename Inv>\nstruct Group {\n    using S = T;\n    Op op_object;\n   \
    \ S identity;\n    Inv inv_object;\n    Group() = default;\n    constexpr Group(Op\
    \ op, const S& e, Inv inv) : op_object(std::move(op)), identity(e), inv_object(std::move(inv))\
    \ {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a, b);\
    \ }\n    constexpr S e() const { return identity; }\n    constexpr S inv(const\
    \ S& a) const { return inv_object(a); }\n};\ntemplate <typename Op, typename T,\
    \ typename Inv>\nGroup(Op, T, Inv) -> Group<T, Op, Inv>;\n#line 2 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n\n/**\n * @file potentialized-unionfind.hpp\n * @brief \u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\u4ED8\u304DUnionFind\n */\n#include <cassert>\n#include <stack>\n\
    #line 11 \"src/data_structures/potentialized-unionfind.hpp\"\n\n#line 2 \"src/data_structures/unionfind.hpp\"\
    \n\n/**\n * @file unionfind.hpp\n * @brief UnionFind\n */\n\n#line 12 \"src/data_structures/unionfind.hpp\"\
    \n\nnamespace internal_unionfind {\n/**\n * @brief \u5404\u8981\u7D20\u306E\u4EE3\
    \u8868\u5143\u304B\u3089\u3001\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8981\
    \u7D20\u306E\u30EA\u30B9\u30C8\u3092\u4F5C\u308B\n * @param leader \u8981\u7D20\
    \ a \u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\u95A2\u6570\n */\ntemplate <typename\
    \ F>\nstd::vector<std::vector<long long>> groups(long long n, F leader) {\n  \
    \  std::vector<long long> leader_buf(n), group_size(n);\n    for (long long i\
    \ = 0; i < n; i++) {\n        leader_buf[i] = leader(i);\n        group_size[leader_buf[i]]++;\n\
    \    }\n    std::vector<std::vector<long long>> result(n);\n    for (long long\
    \ i = 0; i < n; i++) {\n        result[i].reserve(group_size[i]);\n    }\n   \
    \ for (long long i = 0; i < n; i++) {\n        result[leader_buf[i]].push_back(i);\n\
    \    }\n    result.erase(std::remove_if(result.begin(), result.end(), [&](const\
    \ std::vector<long long>& v) { return v.empty(); }), result.end());\n    return\
    \ result;\n}\n}  // namespace internal_unionfind\n\n/**\n * @brief \u7121\u5411\
    \u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u300C\u8FBA\u306E\u8FFD\u52A0\u300D\
    \u3001\u300C2\u9802\u70B9\u304C\u9023\u7D50\u304B\u306E\u5224\u5B9A\u300D\u3092\
    \u3059\u308B\n */\nclass UnionFind {\n   protected:\n    long long _n;\n    //\
    \ \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\u3089\u89AA (\u30E1\
    \u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081 int \u3067\u6301\u3064)\n   \
    \ std::vector<int> parent_or_size;\n\n   public:\n    /**\n     * @brief merge\
    \ \u306E\u623B\u308A\u5024\n     *\n     * if (uf.merge(a, b)) \u3067\u65B0\u3057\
    \u304F\u7D71\u5408\u3057\u305F\u304B\u3092\u5224\u5B9A\u3067\u304D\u3001\n   \
    \  * auto [r, merged] = uf.merge(a, b); \u3067\u4EE3\u8868\u5143\u3082\u53D7\u3051\
    \u53D6\u308C\u308B\n     */\n    struct MergeResult {\n        long long leader;\
    \  //!< \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\n        bool merged;     \
    \  //!< \u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B (\u3082\u3068\u3082\u3068\
    \u540C\u3058\u9023\u7D50\u6210\u5206\u306A\u3089 false)\n        explicit operator\
    \ bool() const { return merged; }\n    };\n\n    UnionFind() : _n(0) {}\n    explicit\
    \ UnionFind(long long n) : _n(n), parent_or_size(n, -1) {}\n\n    /**\n     *\
    \ @brief \u8FBA(a,b)\u3092\u8DB3\u3059\n     * @return \u7D71\u5408\u5F8C\u306E\
    \u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B\
    \n     */\n    MergeResult merge(long long a, long long b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        long long x = leader(a),\
    \ y = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = int(x);\n        return {x, true};\n    }\n    /**\n\
    \     * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\u304B\n   \
    \  */\n    bool same(long long a, long long b) {\n        assert(0 <= a && a <\
    \ _n);\n        assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n\
    \    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\
    \u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    long long leader(long long\
    \ a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0)\
    \ return a;\n        int x = int(a);\n        while (parent_or_size[x] >= 0) {\n\
    \            x = parent_or_size[x];\n        }\n        while (parent_or_size[a]\
    \ >= 0) {\n            int t = parent_or_size[a];\n            parent_or_size[a]\
    \ = x;\n            a = t;\n        }\n        return x;\n    }\n    /**\n   \
    \  * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\
    \u30B5\u30A4\u30BA\n     */\n    long long size(long long a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\u5206\u3051\
    \u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\u4E00\u3064\
    \u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\
    \u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<long\
    \ long>> groups() {\n        return internal_unionfind::groups(_n, [&](long long\
    \ a) { return leader(a); });\n    }\n};\n#line 14 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n\n/**\n * @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind\n\
    \ * @tparam G \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u7FA4 (algebra/group.hpp)\
    \ \u975E\u53EF\u63DB\u3067\u3082\u3088\u3044\n */\ntemplate <typename G>\nclass\
    \ PotentializedUnionFind {\n   public:\n    using S = typename G::S;\n    using\
    \ MergeResult = UnionFind::MergeResult;\n\n   private:\n    G g;\n    long long\
    \ _n;\n    // \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\u3089\
    \u89AA (\u30E1\u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081 int \u3067\u6301\
    \u3064)\n    std::vector<int> parent_or_size;\n    // \u91CD\u307F\n    std::vector<S>\
    \ diff_weight;\n\n    S op(const S& a, const S& b) const { return g.op(a, b);\
    \ }\n    S e() const { return g.e(); }\n    S inv(const S& a) const { return g.inv(a);\
    \ }\n\n   public:\n    /**\n     * @param n \u8981\u7D20\u6570\n     * @param\
    \ g \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u7FA4\n     */\n    explicit PotentializedUnionFind(long\
    \ long n = 0, G g = G()) : g(std::move(g)), _n(n), parent_or_size(n, -1), diff_weight(n,\
    \ e()) {}\n\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\
    \u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    long long leader(long\
    \ long a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a]\
    \ < 0) return a;\n        std::stack<int> stk;\n        stk.push(int(a));\n  \
    \      while (parent_or_size[stk.top()] >= 0) {\n            stk.push(parent_or_size[stk.top()]);\n\
    \        }\n        const int root = stk.top();\n        stk.pop();\n        stk.pop();\n\
    \        while (!stk.empty()) {\n            diff_weight[stk.top()] = op(diff_weight[parent_or_size[stk.top()]],\
    \ diff_weight[stk.top()]);\n            parent_or_size[stk.top()] = root;\n  \
    \          stk.pop();\n        }\n        return root;\n    }\n\n    /**\n   \
    \  * @brief a \u306E\u30B0\u30EB\u30FC\u30D7\u3068 b \u306E\u30B0\u30EB\u30FC\u30D7\
    \u3092\u7D71\u5408\u3059\u308B\n     * @param w (b \u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB) - (a \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)\n     * @return\
    \ \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\
    \u5408\u3057\u305F\u304B\n     * @note \u3059\u3067\u306B\u540C\u3058\u9023\u7D50\
    \u6210\u5206\u306A\u3089\u4F55\u3082\u3057\u306A\u3044 (w \u304C\u77DB\u76FE\u3057\
    \u3066\u3044\u3066\u3082\u691C\u51FA\u3057\u306A\u3044)\u3002\n     *       \u77DB\
    \u76FE\u3092\u8ABF\u3079\u308B\u306B\u306F\u3001merged \u304C false \u306E\u3068\
    \u304D\u306B diff(a, b) == w \u304B\u3092\u78BA\u304B\u3081\u308B\n     */\n \
    \   MergeResult merge(long long a, long long b, S w) {\n        assert(0 <= a\
    \ && a < _n);\n        assert(0 <= b && b < _n);\n        w = op(weight(a), w);\n\
    \        w = op(w, inv(weight(b)));\n        long long x = leader(a), y = leader(b);\n\
    \        if (x == y) return {x, false};\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ {\n            std::swap(x, y);\n            w = inv(w);\n        }\n      \
    \  parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] = int(x);\n\
    \        diff_weight[y] = w;\n        return {x, true};\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\u304B\n     */\n\
    \    bool same(long long a, long long b) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n \
    \   }\n\n    /**\n     * @brief (b \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    ) - (a \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)\n     */\n    S diff(long long\
    \ a, long long b) {\n        assert(same(a, b));\n        return op(inv(weight(a)),\
    \ weight(b));\n    }\n\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\
    \u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\n     */\n    long long\
    \ size(long long a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\
    \u306B\u5206\u3051\u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return\
    \ \u300C\u4E00\u3064\u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\
    \u306E\u30EA\u30B9\u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<long\
    \ long>> groups() {\n        return internal_unionfind::groups(_n, [&](long long\
    \ a) { return leader(a); });\n    }\n\n   private:\n    S weight(long long a)\
    \ {\n        leader(a);\n        return diff_weight[a];\n    }\n};\n\ntemplate\
    \ <typename G>\nPotentializedUnionFind(long long, G) -> PotentializedUnionFind<G>;\n\
    #line 2 \"src/data_structures/segtree.hpp\"\n\n/**\n * @file segtree.hpp\n * @brief\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#line 12 \"src/data_structures/segtree.hpp\"\
    \n\n#line 14 \"src/data_structures/segtree.hpp\"\n\n/**\n * @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n *\n * \u4F8B:\n * SegTree<monoid::Max<int>> seg(n);\n\
    \ * SegTree seg(v, Monoid([](int a, int b) { return a + b; }, 0));\n *\n * @tparam\
    \ M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n */\ntemplate <typename M>\n\
    class SegTree {\n   public:\n    using S = typename M::S;\n\n   private:\n   \
    \ M m;\n    S op(const S& a, const S& b) const { return m.op(a, b); }\n    S e()\
    \ const { return m.e(); }\n\n    long long n, sz;\n    int height;\n    std::vector<S>\
    \ data;\n    void update(long long k) { data[k] = op(data[2 * k], data[2 * k +\
    \ 1]); }\n\n    class SegTreeReference {\n        SegTree& segtree;\n        long\
    \ long k;\n\n       public:\n        SegTreeReference(SegTree& segtree, long long\
    \ k) : segtree(segtree), k(k) {}\n        SegTreeReference& operator=(const S&\
    \ x) {\n            segtree.set(k, x);\n            return *this;\n        }\n\
    \        operator S() const { return segtree.get(k); }\n    };\n\n    void construct_data()\
    \ {\n        sz = 1;\n        height = 0;\n        while (sz < n) {\n        \
    \    sz <<= 1;\n            height++;\n        }\n        data.assign(sz * 2,\
    \ e());\n    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     *\n     * @param n \u8981\u7D20\u6570\n     * @param m \u30E2\
    \u30CE\u30A4\u30C9\n     */\n    explicit SegTree(long long n = 0, M m = M())\
    \ : m(std::move(m)), n(n) {\n        construct_data();\n    }\n    /**\n     *\
    \ @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param v \u521D\
    \u671F\u306E\u8981\u7D20\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n\
    \    explicit SegTree(const std::vector<S>& v, M m = M()) : SegTree(v.size(),\
    \ std::move(m)) {\n        for (long long i = 0; i < n; i++) data[sz + i] = v[i];\n\
    \        for (long long i = sz - 1; i > 0; i--) update(i);\n    }\n\n    /**\n\
    \     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long long size()\
    \ const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\
    \u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n    S get(long long\
    \ k) const {\n        assert(0 <= k && k < n);\n        return data[sz + k];\n\
    \    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\n     * @return S \u5024\n     */\n    S operator[](long long k) const\
    \ { return get(k); }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\
    \u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\n     *\n     * @param k\n  \
    \   * @return SegTreeReference \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\u5165\
    \u3055\u308C\u308B\u3068set()\u304C\u547C\u3070\u308C\u308B\n     */\n    SegTreeReference\
    \ operator[](long long k) { return SegTreeReference(*this, k); }\n\n    /**\n\
    \     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n     *\n     * @tparam\
    \ CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n \
    \    * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\
    \u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n     * @param rhs \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n     * @return std::basic_ostream<CharT,\
    \ Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     */\n    template <class\
    \ CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const SegTree& rhs) {\n        for (long long i = 0; i < rhs.n;\
    \ i++) {\n            if (i != 0) os << CharT(' ');\n            os << rhs[i];\n\
    \        }\n        return os;\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n  \
    \   *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\
    \u3057\u3044\u5024\n     */\n    void set(long long k, const S& x) {\n       \
    \ assert(0 <= k && k < n);\n        k += sz;\n        data[k] = x;\n        for\
    \ (int i = 1; i <= height; i++) update(k >> i);\n    }\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u306Bx\u3092\u4F5C\u7528\
    \u3055\u305B\u308B\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @param x \u4F5C\u7528\u7D20\n     */\n    void apply(long long k, const\
    \ S& x) { set(k, op(get(k), x)); }\n\n    /**\n     * @brief [l, r)\u306E\u533A\
    \u9593\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\u958B\
    \u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\
    \u7D42\u7AEF 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(long\
    \ long l, long long r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        S left_prod = e(), right_prod = e();\n        l += sz;\n        r +=\
    \ sz;\n        while (l < r) {\n            if (l & 1) left_prod = op(left_prod,\
    \ data[l++]);\n            if (r & 1) right_prod = op(data[--r], right_prod);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(left_prod,\
    \ right_prod);\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @return S \u7DCF\u7A4D\n\
    \     */\n    S all_prod() const { return data[1]; }\n\n    /**\n     * @brief\
    \ (r = l or f(prod([l, r))) = true) and (r = n or f(prod([l, r+1))) = false)\u3068\
    \u306A\u308Br\u3092\u8FD4\u3059\n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001\
    f(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n     *\n     * @tparam\
    \ F\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB 0<=l<=n\n    \
    \ * @param f \u5224\u5B9A\u95A2\u6570 f(e) = true\n     * @return long long\n\
    \     */\n    template <typename F>\n    long long max_right(long long l, F f)\
    \ const {\n        assert(f(e()));\n        assert(0 <= l && l <= n);\n      \
    \  if (l == n) return n;\n        l += sz;\n        while (l % 2 == 0) l >>= 1;\n\
    \        S sum = e();\n        while (f(op(sum, data[l]))) {\n            sum\
    \ = op(sum, data[l]);\n            l++;\n            while (l % 2 == 0) l >>=\
    \ 1;\n            if (l == 1) return n;\n        }\n        while (l < sz) {\n\
    \            if (!f(op(sum, data[l * 2])))\n                l *= 2;\n        \
    \    else {\n                sum = op(sum, data[l * 2]);\n                l =\
    \ l * 2 + 1;\n            }\n        }\n        return l - sz;\n    }\n    /**\n\
    \     * @brief (l = 0 or f(prod([l, r))) = true) and (l = r or f(prod([l-1, r)))\
    \ = false)\u3068\u306A\u308Bl\u3092\u8FD4\u3059\n     * f\u304C\u5358\u8ABF\u306A\
    \u3089\u3001f(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5C0F\u306El\n    \
    \ *\n     * @tparam F\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \ 0<=r<=n\n     * @param f \u5224\u5B9A\u95A2\u6570 f(e) = true\n     * @return\
    \ long long\n     */\n    template <typename F>\n    long long min_left(long long\
    \ r, F f) const {\n        assert(f(e()));\n        assert(0 <= r && r <= n);\n\
    \        if (r == 0) return 0;\n        r += sz;\n        S sum = e();\n     \
    \   do {\n            r--;\n            while (r > 1 && r % 2 == 1) r >>= 1;\n\
    \            if (!f(op(data[r], sum))) {\n                while (r < sz) {\n \
    \                   r = r * 2 + 1;\n                    if (f(op(data[r], sum)))\
    \ {\n                        sum = op(data[r], sum);\n                       \
    \ r--;\n                    }\n                }\n                return r + 1\
    \ - sz;\n            }\n            sum = op(data[r], sum);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n};\n\ntemplate <typename M>\nSegTree(long\
    \ long, M) -> SegTree<M>;\ntemplate <typename M>\nSegTree(std::vector<typename\
    \ M::S>, M) -> SegTree<M>;\n\n/**\n * @brief RangeMaxQuery\n *\n * @tparam S \u578B\
    \n */\ntemplate <typename S>\nusing RMaxQ = SegTree<monoid::Max<S>>;\n/**\n *\
    \ @brief RangeMinQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename S>\n\
    using RMinQ = SegTree<monoid::Min<S>>;\n/**\n * @brief RangeSumQuery\n *\n * @tparam\
    \ S \u578B\n */\ntemplate <typename S>\nusing RSumQ = SegTree<monoid::Sum<S>>;\n\
    /**\n * @brief RangeProdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RProdQ = SegTree<monoid::Prod<S>>;\n/**\n * @brief RangeXorQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RXorQ = SegTree<monoid::Xor<S>>;\n\
    /**\n * @brief RangeGcdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RGcdQ = SegTree<monoid::Gcd<S>>;\n#line 16 \"test/unittest/mapping.test.cpp\"\
    \n\n// std::array \u306E == \u306F C++17 \u3067\u306F constexpr \u3067\u306A\u3044\
    \u306E\u3067\u3001\u8981\u7D20\u3054\u3068\u306B\u6BD4\u3079\u308B\ntemplate <std::size_t\
    \ N>\nconstexpr bool equal(const std::array<int, N>& a, const std::array<int,\
    \ N>& b) {\n    for (std::size_t i = 0; i < N; i++) {\n        if (a[i] != b[i])\
    \ return false;\n    }\n    return true;\n}\n// constexpr \u3067\u4F7F\u3048\u308B\
    \u3053\u3068: op(f, g) = f\u2218g\u3002(1, 1, 0) \u3092\u9069\u7528\u3057\u3066\
    \u304B\u3089 (0, 2, 1) \u3092\u9069\u7528\u3059\u308B\u3068 (2, 2, 0)\nstatic_assert(equal(monoid::Mapping<3>::op({0,\
    \ 2, 1}, {1, 1, 0}), {2, 2, 0}));\nstatic_assert(equal(monoid::Reverse<monoid::Mapping<3>>().op({1,\
    \ 1, 0}, {0, 2, 1}), {2, 2, 0}));\nstatic_assert(equal(monoid::Mapping<3>::e(),\
    \ {0, 1, 2}));\nstatic_assert(equal(group::Permutation<3>::inv({1, 2, 0}), {2,\
    \ 0, 1}));\nstatic_assert(equal(monoid::Mapping<3>::swap(1, 2), {0, 2, 1}));\n\
    static_assert(equal(monoid::Mapping<4>::swap(3, 0), {3, 1, 2, 0}));\nstatic_assert(equal(monoid::Mapping<3>::swap(1,\
    \ 1), {0, 1, 2}));\nstatic_assert(equal(group::Permutation<3>::swap(0, 1), {1,\
    \ 0, 2}));\n\ntemplate <std::size_t N>\nstd::array<int, N> random_mapping(std::mt19937&\
    \ rng, bool bijective) {\n    std::array<int, N> f;\n    if (bijective) {\n  \
    \      std::iota(f.begin(), f.end(), 0);\n        std::shuffle(f.begin(), f.end(),\
    \ rng);\n    } else {\n        for (auto& v : f) v = rng() % N;\n    }\n    return\
    \ f;\n}\n\n// SegTree<monoid::Mapping<N>> \u306E\u533A\u9593\u7A4D\u304C\u3001\
    \u533A\u9593\u306E\u5199\u50CF\u3092\u53F3\u304B\u3089\u9806\u306B\u9069\u7528\
    \u3057\u305F\u7D50\u679C\u3068\u4E00\u81F4\u3059\u308B\u304B\ntemplate <std::size_t\
    \ N>\nbool check_segtree(std::mt19937& rng) {\n    using S = std::array<int, N>;\n\
    \    for (int rep = 0; rep < 200; rep++) {\n        int n = rng() % 20 + 1;\n\
    \        std::vector<S> a(n);\n        for (auto& f : a) f = random_mapping<N>(rng,\
    \ rng() % 2);\n        SegTree<monoid::Mapping<N>> seg(a);\n        for (int q\
    \ = 0; q < 50; q++) {\n            if (rng() % 2) {\n                int i = rng()\
    \ % n;\n                a[i] = random_mapping<N>(rng, rng() % 2);\n          \
    \      seg.set(i, a[i]);\n            } else {\n                int l = rng()\
    \ % (n + 1), r = rng() % (n + 1);\n                if (l > r) std::swap(l, r);\n\
    \                S got = seg.prod(l, r);\n                for (int x = 0; x <\
    \ (int)N; x++) {\n                    int y = x;\n                    for (int\
    \ i = r - 1; i >= l; i--) y = a[i][y];\n                    if (got[x] != y) return\
    \ false;\n                }\n            }\n        }\n    }\n    return true;\n\
    }\n\n// group::Permutation \u306E\u9006\u7F6E\u63DB\u3068\u3001\u975E\u53EF\u63DB\
    \u306A\u7FA4\u3068\u3057\u3066 PotentializedUnionFind \u306B\u4E57\u305B\u305F\
    \u3068\u304D\u306E diff\ntemplate <std::size_t N>\nbool check_permutation(std::mt19937&\
    \ rng) {\n    using G = group::Permutation<N>;\n    using S = std::array<int,\
    \ N>;\n    for (int rep = 0; rep < 1000; rep++) {\n        S f = random_mapping<N>(rng,\
    \ true);\n        if (G::op(f, G::inv(f)) != G::e() || G::op(G::inv(f), f) !=\
    \ G::e()) return false;\n    }\n    for (int rep = 0; rep < 200; rep++) {\n  \
    \      int n = rng() % 10 + 1;\n        // \u5404\u9802\u70B9\u306B\u7F6E\u63DB\
    \ p[v] \u3092\u6C7A\u3081\u3001\u305D\u308C\u3068\u77DB\u76FE\u3057\u306A\u3044\
    \u60C5\u5831\u3060\u3051\u3092 merge \u3059\u308B\n        std::vector<S> p(n);\n\
    \        for (auto& f : p) f = random_mapping<N>(rng, true);\n        PotentializedUnionFind<G>\
    \ uf(n);\n        std::vector<int> root(n);\n        std::iota(root.begin(), root.end(),\
    \ 0);\n        for (int q = 0; q < 30; q++) {\n            int a = rng() % n,\
    \ b = rng() % n;\n            // diff(a, b) \u306F p[a]^{-1}\u30FBp[b] (op \u306E\
    \u9806\u3067 p[a] \u306E\u9006\u5143\u306E\u5F8C\u306B p[b])\n            S w\
    \ = G::op(G::inv(p[a]), p[b]);\n            uf.merge(a, b, w);\n            int\
    \ ra = root[a], rb = root[b];\n            for (int& r : root)\n             \
    \   if (r == rb) r = ra;\n            for (int u = 0; u < n; u++) {\n        \
    \        for (int v = 0; v < n; v++) {\n                    bool same = root[u]\
    \ == root[v];\n                    if (uf.same(u, v) != same) return false;\n\
    \                    if (same && uf.diff(u, v) != G::op(G::inv(p[u]), p[v])) return\
    \ false;\n                }\n            }\n        }\n    }\n    return true;\n\
    }\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    ok = ok\
    \ && check_segtree<1>(rng);\n    ok = ok && check_segtree<3>(rng);\n    ok = ok\
    \ && check_segtree<5>(rng);\n    ok = ok && check_permutation<3>(rng);\n    ok\
    \ = ok && check_permutation<5>(rng);\n\n    // \u4F8B: (0, 2, 1) \u3092\u533A\u9593\
    \u306B\u4E26\u3079\u308B\u3002\u5076\u6570\u500B\u306A\u3089\u6052\u7B49\u5199\
    \u50CF\u3001\u5947\u6570\u500B\u306A\u3089 (0, 2, 1)\n    SegTree<monoid::Mapping<3>>\
    \ seg(4);\n    for (int i = 0; i < 4; i++) seg.set(i, monoid::Mapping<3>::swap(1,\
    \ 2));\n    ok = ok && seg.prod(0, 4) == std::array<int, 3>{0, 1, 2};\n    ok\
    \ = ok && seg.prod(1, 4) == std::array<int, 3>{0, 2, 1};\n\n    if (ok)\n    \
    \    std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr <<\
    \ \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// monoid::Mapping (\u5199\u50CF\u306E\u5408\u6210) \u3068 group::Permutation\
    \ (\u7F6E\u63DB\u306E\u5408\u6210) \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\
    \u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n#include\
    \ <array>\n#include <iostream>\n#include <numeric>\n#include <random>\n#include\
    \ <vector>\n\n#include \"../../src/algebra/group.hpp\"\n#include \"../../src/data_structures/potentialized-unionfind.hpp\"\
    \n#include \"../../src/data_structures/segtree.hpp\"\n\n// std::array \u306E ==\
    \ \u306F C++17 \u3067\u306F constexpr \u3067\u306A\u3044\u306E\u3067\u3001\u8981\
    \u7D20\u3054\u3068\u306B\u6BD4\u3079\u308B\ntemplate <std::size_t N>\nconstexpr\
    \ bool equal(const std::array<int, N>& a, const std::array<int, N>& b) {\n   \
    \ for (std::size_t i = 0; i < N; i++) {\n        if (a[i] != b[i]) return false;\n\
    \    }\n    return true;\n}\n// constexpr \u3067\u4F7F\u3048\u308B\u3053\u3068\
    : op(f, g) = f\u2218g\u3002(1, 1, 0) \u3092\u9069\u7528\u3057\u3066\u304B\u3089\
    \ (0, 2, 1) \u3092\u9069\u7528\u3059\u308B\u3068 (2, 2, 0)\nstatic_assert(equal(monoid::Mapping<3>::op({0,\
    \ 2, 1}, {1, 1, 0}), {2, 2, 0}));\nstatic_assert(equal(monoid::Reverse<monoid::Mapping<3>>().op({1,\
    \ 1, 0}, {0, 2, 1}), {2, 2, 0}));\nstatic_assert(equal(monoid::Mapping<3>::e(),\
    \ {0, 1, 2}));\nstatic_assert(equal(group::Permutation<3>::inv({1, 2, 0}), {2,\
    \ 0, 1}));\nstatic_assert(equal(monoid::Mapping<3>::swap(1, 2), {0, 2, 1}));\n\
    static_assert(equal(monoid::Mapping<4>::swap(3, 0), {3, 1, 2, 0}));\nstatic_assert(equal(monoid::Mapping<3>::swap(1,\
    \ 1), {0, 1, 2}));\nstatic_assert(equal(group::Permutation<3>::swap(0, 1), {1,\
    \ 0, 2}));\n\ntemplate <std::size_t N>\nstd::array<int, N> random_mapping(std::mt19937&\
    \ rng, bool bijective) {\n    std::array<int, N> f;\n    if (bijective) {\n  \
    \      std::iota(f.begin(), f.end(), 0);\n        std::shuffle(f.begin(), f.end(),\
    \ rng);\n    } else {\n        for (auto& v : f) v = rng() % N;\n    }\n    return\
    \ f;\n}\n\n// SegTree<monoid::Mapping<N>> \u306E\u533A\u9593\u7A4D\u304C\u3001\
    \u533A\u9593\u306E\u5199\u50CF\u3092\u53F3\u304B\u3089\u9806\u306B\u9069\u7528\
    \u3057\u305F\u7D50\u679C\u3068\u4E00\u81F4\u3059\u308B\u304B\ntemplate <std::size_t\
    \ N>\nbool check_segtree(std::mt19937& rng) {\n    using S = std::array<int, N>;\n\
    \    for (int rep = 0; rep < 200; rep++) {\n        int n = rng() % 20 + 1;\n\
    \        std::vector<S> a(n);\n        for (auto& f : a) f = random_mapping<N>(rng,\
    \ rng() % 2);\n        SegTree<monoid::Mapping<N>> seg(a);\n        for (int q\
    \ = 0; q < 50; q++) {\n            if (rng() % 2) {\n                int i = rng()\
    \ % n;\n                a[i] = random_mapping<N>(rng, rng() % 2);\n          \
    \      seg.set(i, a[i]);\n            } else {\n                int l = rng()\
    \ % (n + 1), r = rng() % (n + 1);\n                if (l > r) std::swap(l, r);\n\
    \                S got = seg.prod(l, r);\n                for (int x = 0; x <\
    \ (int)N; x++) {\n                    int y = x;\n                    for (int\
    \ i = r - 1; i >= l; i--) y = a[i][y];\n                    if (got[x] != y) return\
    \ false;\n                }\n            }\n        }\n    }\n    return true;\n\
    }\n\n// group::Permutation \u306E\u9006\u7F6E\u63DB\u3068\u3001\u975E\u53EF\u63DB\
    \u306A\u7FA4\u3068\u3057\u3066 PotentializedUnionFind \u306B\u4E57\u305B\u305F\
    \u3068\u304D\u306E diff\ntemplate <std::size_t N>\nbool check_permutation(std::mt19937&\
    \ rng) {\n    using G = group::Permutation<N>;\n    using S = std::array<int,\
    \ N>;\n    for (int rep = 0; rep < 1000; rep++) {\n        S f = random_mapping<N>(rng,\
    \ true);\n        if (G::op(f, G::inv(f)) != G::e() || G::op(G::inv(f), f) !=\
    \ G::e()) return false;\n    }\n    for (int rep = 0; rep < 200; rep++) {\n  \
    \      int n = rng() % 10 + 1;\n        // \u5404\u9802\u70B9\u306B\u7F6E\u63DB\
    \ p[v] \u3092\u6C7A\u3081\u3001\u305D\u308C\u3068\u77DB\u76FE\u3057\u306A\u3044\
    \u60C5\u5831\u3060\u3051\u3092 merge \u3059\u308B\n        std::vector<S> p(n);\n\
    \        for (auto& f : p) f = random_mapping<N>(rng, true);\n        PotentializedUnionFind<G>\
    \ uf(n);\n        std::vector<int> root(n);\n        std::iota(root.begin(), root.end(),\
    \ 0);\n        for (int q = 0; q < 30; q++) {\n            int a = rng() % n,\
    \ b = rng() % n;\n            // diff(a, b) \u306F p[a]^{-1}\u30FBp[b] (op \u306E\
    \u9806\u3067 p[a] \u306E\u9006\u5143\u306E\u5F8C\u306B p[b])\n            S w\
    \ = G::op(G::inv(p[a]), p[b]);\n            uf.merge(a, b, w);\n            int\
    \ ra = root[a], rb = root[b];\n            for (int& r : root)\n             \
    \   if (r == rb) r = ra;\n            for (int u = 0; u < n; u++) {\n        \
    \        for (int v = 0; v < n; v++) {\n                    bool same = root[u]\
    \ == root[v];\n                    if (uf.same(u, v) != same) return false;\n\
    \                    if (same && uf.diff(u, v) != G::op(G::inv(p[u]), p[v])) return\
    \ false;\n                }\n            }\n        }\n    }\n    return true;\n\
    }\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    ok = ok\
    \ && check_segtree<1>(rng);\n    ok = ok && check_segtree<3>(rng);\n    ok = ok\
    \ && check_segtree<5>(rng);\n    ok = ok && check_permutation<3>(rng);\n    ok\
    \ = ok && check_permutation<5>(rng);\n\n    // \u4F8B: (0, 2, 1) \u3092\u533A\u9593\
    \u306B\u4E26\u3079\u308B\u3002\u5076\u6570\u500B\u306A\u3089\u6052\u7B49\u5199\
    \u50CF\u3001\u5947\u6570\u500B\u306A\u3089 (0, 2, 1)\n    SegTree<monoid::Mapping<3>>\
    \ seg(4);\n    for (int i = 0; i < 4; i++) seg.set(i, monoid::Mapping<3>::swap(1,\
    \ 2));\n    ok = ok && seg.prod(0, 4) == std::array<int, 3>{0, 1, 2};\n    ok\
    \ = ok && seg.prod(1, 4) == std::array<int, 3>{0, 2, 1};\n\n    if (ok)\n    \
    \    std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr <<\
    \ \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/algebra/group.hpp
  - src/algebra/monoid.hpp
  - src/data_structures/potentialized-unionfind.hpp
  - src/data_structures/unionfind.hpp
  - src/data_structures/segtree.hpp
  isVerificationFile: true
  path: test/unittest/mapping.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 23:44:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/mapping.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/mapping.test.cpp
- /verify/test/unittest/mapping.test.cpp.html
title: test/unittest/mapping.test.cpp
---
