---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/monoid-unionfind.test.cpp
    title: test/unittest/monoid-unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/674.1.test.cpp
    title: test/yukicoder/674.1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308B\
      UnionFind"
    links: []
  bundledCode: "#line 2 \"src/data_structures/monoid-unionfind.hpp\"\n\n/**\n * @file\
    \ monoid-unionfind.hpp\n * @brief \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\
    \u305B\u308BUnionFind\n */\n\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n\
    \ * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\
    \u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\
    \u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S&\
    \ a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n\
    \ * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\
    \u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\
    \n#include <algorithm>\n#include <array>\n#include <cstddef>\n#include <istream>\n\
    #include <limits>\n#include <numeric>\n#include <ostream>\n#include <type_traits>\n\
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
    \ T) -> Monoid<T, Op>;\n#line 2 \"src/data_structures/unionfind.hpp\"\n\n/**\n\
    \ * @file unionfind.hpp\n * @brief UnionFind\n */\n\n#line 12 \"src/data_structures/unionfind.hpp\"\
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
    \ a) { return leader(a); });\n    }\n};\n#line 14 \"src/data_structures/monoid-unionfind.hpp\"\
    \n\n/**\n * @brief \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308B\
    UnionFind\n *\n * @tparam M \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n\
    \ */\ntemplate <typename M>\nclass MonoidUnionFind : private UnionFind {\n   public:\n\
    \    using S = typename M::S;\n\n   private:\n    M m;\n    std::vector<S> val;\n\
    \    using UnionFind::_n;\n    using UnionFind::parent_or_size;\n\n   public:\n\
    \    /**\n     * @param n \u8981\u7D20\u6570 \u5404\u8981\u7D20\u306E\u5024\u306F\
    \u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\u3059\u308B\n     * @param m \u53EF\
    \u63DB\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit MonoidUnionFind(long long\
    \ n = 0, M m = M()) : UnionFind(n), m(std::move(m)), val(n, this->m.e()) {}\n\
    \    /**\n     * @param v \u5404\u8981\u7D20\u306E\u521D\u671F\u5024\n     * @param\
    \ m \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit MonoidUnionFind(std::vector<S>\
    \ v, M m = M()) : UnionFind(v.size()), m(std::move(m)), val(std::move(v)) {}\n\
    \    using MergeResult = UnionFind::MergeResult;\n    using UnionFind::groups;\n\
    \    using UnionFind::leader;\n    using UnionFind::same;\n    using UnionFind::size;\n\
    \    /**\n     * @brief a \u3068 b \u306E\u9023\u7D50\u6210\u5206\u3092\u7D71\u5408\
    \u3057\u3001\u5024\u306E\u7A4D\u3092\u53D6\u308B\n     * @return \u7D71\u5408\u5F8C\
    \u306E\u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\
    \u304B\n     */\n    MergeResult merge(long long a, long long b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        long long x = leader(a),\
    \ y = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = int(x);\n        val[x] = m.op(val[x], val[y]);\n\
    \        return {x, true};\n    }\n    /**\n     * @brief \u8981\u7D20a\u306E\u5C5E\
    \u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u5024\u306E\u7DCF\u7A4D\n     */\n\
    \    const S& prod(long long a) {\n        return val[leader(a)];\n    }\n};\n\
    \ntemplate <typename M>\nMonoidUnionFind(long long, M) -> MonoidUnionFind<M>;\n\
    template <typename M>\nMonoidUnionFind(std::vector<typename M::S>, M) -> MonoidUnionFind<M>;\n"
  code: "#pragma once\n\n/**\n * @file monoid-unionfind.hpp\n * @brief \u53EF\u63DB\
    \u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308BUnionFind\n */\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\n#include \"../algebra/monoid.hpp\"\n\
    #include \"unionfind.hpp\"\n\n/**\n * @brief \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\
    \u3092\u4E57\u305B\u308BUnionFind\n *\n * @tparam M \u53EF\u63DB\u30E2\u30CE\u30A4\
    \u30C9 (algebra/monoid.hpp)\n */\ntemplate <typename M>\nclass MonoidUnionFind\
    \ : private UnionFind {\n   public:\n    using S = typename M::S;\n\n   private:\n\
    \    M m;\n    std::vector<S> val;\n    using UnionFind::_n;\n    using UnionFind::parent_or_size;\n\
    \n   public:\n    /**\n     * @param n \u8981\u7D20\u6570 \u5404\u8981\u7D20\u306E\
    \u5024\u306F\u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\u3059\u308B\n     * @param\
    \ m \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit MonoidUnionFind(long\
    \ long n = 0, M m = M()) : UnionFind(n), m(std::move(m)), val(n, this->m.e())\
    \ {}\n    /**\n     * @param v \u5404\u8981\u7D20\u306E\u521D\u671F\u5024\n  \
    \   * @param m \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit MonoidUnionFind(std::vector<S>\
    \ v, M m = M()) : UnionFind(v.size()), m(std::move(m)), val(std::move(v)) {}\n\
    \    using MergeResult = UnionFind::MergeResult;\n    using UnionFind::groups;\n\
    \    using UnionFind::leader;\n    using UnionFind::same;\n    using UnionFind::size;\n\
    \    /**\n     * @brief a \u3068 b \u306E\u9023\u7D50\u6210\u5206\u3092\u7D71\u5408\
    \u3057\u3001\u5024\u306E\u7A4D\u3092\u53D6\u308B\n     * @return \u7D71\u5408\u5F8C\
    \u306E\u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\
    \u304B\n     */\n    MergeResult merge(long long a, long long b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        long long x = leader(a),\
    \ y = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = int(x);\n        val[x] = m.op(val[x], val[y]);\n\
    \        return {x, true};\n    }\n    /**\n     * @brief \u8981\u7D20a\u306E\u5C5E\
    \u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u5024\u306E\u7DCF\u7A4D\n     */\n\
    \    const S& prod(long long a) {\n        return val[leader(a)];\n    }\n};\n\
    \ntemplate <typename M>\nMonoidUnionFind(long long, M) -> MonoidUnionFind<M>;\n\
    template <typename M>\nMonoidUnionFind(std::vector<typename M::S>, M) -> MonoidUnionFind<M>;\n"
  dependsOn:
  - src/algebra/monoid.hpp
  - src/data_structures/unionfind.hpp
  isVerificationFile: false
  path: src/data_structures/monoid-unionfind.hpp
  requiredBy: []
  timestamp: '2026-10-15 23:44:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/monoid-unionfind.test.cpp
  - test/yukicoder/674.1.test.cpp
documentation_of: src/data_structures/monoid-unionfind.hpp
layout: document
title: "\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308BUnionFind"
---

各頂点に値を持たせ、連結成分ごとの値の総積を管理する [UnionFind](unionfind.hpp) です。可換モノイド ([algebra/monoid.hpp](../algebra/monoid.hpp)) を渡して使います。

```cpp
std::vector<long long> w = {1, 2, 3, 4, 5};
MonoidUnionFind<monoid::Sum<long long>> uf(w);
uf.merge(0, 1);
uf.merge(3, 4);
long long s = uf.prod(1);   // 1 + 2 = 3

// ラムダ式から作ったモノイドも渡せる
MonoidUnionFind uf2(v, Monoid([](int a, int b) { return std::min(a, b); }, INF));
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `MonoidUnionFind(n, m = M())` | 頂点数 `n`、各頂点の値は単位元 | $O(n)$ |
| `MonoidUnionFind(v, m = M())` | 各頂点の値を `v` で初期化 | $O(n)$ |
| `merge(a, b)` | 辺 $(a, b)$ を追加する。2つの連結成分の値の積が新しい値になる。[UnionFind](unionfind.hpp) と同じ `MergeResult` (代表元と、新しく統合したか) を返す | $O(\alpha(n))$ |
| `prod(a)` | `a` の属する連結成分の値の総積 | $O(\alpha(n))$ |
| `same(a, b)`、`leader(a)`、`size(a)`、`groups()` | [UnionFind](unionfind.hpp) と同じ | $O(\alpha(n))$ (`groups()` は $O(n)$) |

連結後の値は、どちらの成分が親になるかで積の順序が変わります。そのため、モノイドは可換である必要があります。

## 関連

- 値を持たない [UnionFind](unionfind.hpp)
- 頂点間のポテンシャルの差を管理するなら [ポテンシャル付きUnionFind](potentialized-unionfind.hpp)
