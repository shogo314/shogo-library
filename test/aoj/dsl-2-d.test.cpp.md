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
    path: src/data_structures/dual-segtree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\u7528\
      \u30011\u70B9\u53D6\u5F97)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/aoj/dsl-2-d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include <iostream>\n\n#line 2 \"src/data_structures/dual-segtree.hpp\"\n\n\
    /**\n * @file dual-segtree.hpp\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728 (\u533A\u9593\u4F5C\u7528\u30011\u70B9\u53D6\u5F97)\n */\n\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/algebra/acted-monoid.hpp\"\
    \n\n/**\n * @file acted-monoid.hpp\n * @brief \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp) \u306E\u30E1\
    \u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using F: \u4F5C\u7528\u7D20\u306E\
    \u578B\n * - S mapping(const F& f, const S& x): \u4F5C\u7528\u7D20\u306E\u9069\
    \u7528 f(x)\n *   \u533A\u9593\u306E\u60C5\u5831\u304C\u5FC5\u8981\u306A\u5834\
    \u5408\u306F mapping(f, x, sz) (sz \u306F\u533A\u9593\u306E\u9577\u3055) \u3084\
    \ mapping(f, x, l, r) (\u533A\u9593 [l, r)) \u3067\u3082\u3088\u3044\n *   sz,\
    \ l, r \u306F long long \u3067\u6E21\u3059 (\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u3067\u306F int \u306B\u53CE\u307E\u3089\u306A\u3044\u3053\u3068\u304C\
    \u3042\u308B)\n * - F composition(const F& f, const F& g): \u4F5C\u7528\u7D20\u306E\
    \u5408\u6210 f\u2218g (g\u3092\u9069\u7528\u3057\u305F\u5F8C\u306Bf\u3092\u9069\
    \u7528\u3059\u308B)\n * - F id(): \u6052\u7B49\u5199\u50CF\n * \u4F5C\u7528\u7D20\
    \u304C\u7FA4\u3092\u306A\u3059\u5834\u5408 (imos.hpp \u3067\u4F7F\u3046) \u306F\
    \n * - F inv(const F& f): \u9006\u4F5C\u7528\u7D20\n */\n\n#include <algorithm>\n\
    #include <array>\n#include <cstddef>\n#include <limits>\n#include <optional>\n\
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
    #line 21 \"src/algebra/monoid.hpp\"\n#include <ostream>\n#line 24 \"src/algebra/monoid.hpp\"\
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
    \    }\n};\n\n/**\n * @brief clamp \u3059\u308B\u95A2\u6570 f(x) = min(max(x,\
    \ lb), ub)\n *\n * monoid::ClampComposite \u306E\u8981\u7D20\u3084 acted_monoid::ClampMin\
    \ \u306A\u3069\u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B: Clamp<int>\
    \ f{0, 10}; f(x) \u306F x \u3092 [0, 10] \u306B\u53CE\u3081\u308B\u3002\u7701\u7565\
    \u3059\u308B\u3068\u6052\u7B49\u5199\u50CF {\u578B\u306E\u6700\u5C0F\u5024, \u578B\
    \u306E\u6700\u5927\u5024}\n * lb, ub \u306B {} (std::nullopt) \u3092\u6E21\u3059\
    \u3068\u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057 (\u578B\u306E\u6700\u5C0F\u5024\
    \u30FB\u6700\u5927\u5024) \u306B\u306A\u308B\u3002\u4F8B: Clamp<int>{0, {}} \u306F\
    \ chmax 0\n * lb <= ub \u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\n\
    \ */\ntemplate <typename T>\nstruct Clamp {\n    T lb;  //!< \u4E0B\u9650\n  \
    \  T ub;  //!< \u4E0A\u9650\n    /// @brief \u6052\u7B49\u5199\u50CF\n    constexpr\
    \ Clamp() : lb(std::numeric_limits<T>::lowest()), ub(std::numeric_limits<T>::max())\
    \ {}\n    /// @brief 1 \u3064\u306E\u5024\u304B\u3089\u306E\u6697\u9ED9\u306E\u5909\
    \u63DB\u3092\u9632\u3050\u305F\u3081\u3001lb \u3068 ub \u306F\u4E21\u65B9\u6E21\
    \u3059\n    constexpr Clamp(std::optional<T> _lb, std::optional<T> _ub)\n    \
    \    : lb(_lb ? *_lb : std::numeric_limits<T>::lowest()), ub(_ub ? *_ub : std::numeric_limits<T>::max())\
    \ {}\n    constexpr T operator()(const T& x) const { return std::min(std::max(x,\
    \ lb), ub); }\n    friend constexpr bool operator==(const Clamp& f, const Clamp&\
    \ g) { return f.lb == g.lb && f.ub == g.ub; }\n    friend constexpr bool operator!=(const\
    \ Clamp& f, const Clamp& g) { return !(f == g); }\n    template <class CharT,\
    \ class Traits>\n    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, Clamp& f) {\n        return is >> f.lb >> f.ub;\n    }\n    template\
    \ <class CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Clamp& f) {\n        return os << f.lb << CharT(' ') << f.ub;\n\
    \    }\n};\n\n/**\n * @brief \u8DB3\u3057\u3066\u304B\u3089 clamp \u3059\u308B\
    \u95A2\u6570 f(x) = min(max(x + add, lb), ub)\n *\n * monoid::ClampAddComposite\
    \ \u306E\u8981\u7D20\u3084 acted_monoid::ClampAddMin\u3001beats_acted_monoid::ChminChmaxAddSum\
    \ \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B: ClampAdd<long long> f{0,\
    \ 10, 3}; f(x) \u306F x + 3 \u3092 [0, 10] \u306B\u53CE\u3081\u308B\u3002\u7701\
    \u7565\u3059\u308B\u3068\u6052\u7B49\u5199\u50CF {\u578B\u306E\u6700\u5C0F\u5024\
    , \u578B\u306E\u6700\u5927\u5024, 0}\n * lb <= ub \u3067\u306A\u3051\u308C\u3070\
    \u306A\u3089\u306A\u3044\u3002lb \u304C\u578B\u306E\u6700\u5C0F\u5024\u3001ub\
    \ \u304C\u578B\u306E\u6700\u5927\u5024\u306E\u3068\u304D\u306F\u3001\u305D\u308C\
    \u305E\u308C\u4E0B\u9650\u30FB\u4E0A\u9650\u304C\u306A\u3044\u3053\u3068\u3092\
    \u8868\u3059\n * lb, ub \u306B {} (std::nullopt) \u3092\u6E21\u3059\u3068\u4E0B\
    \u9650\u30FB\u4E0A\u9650\u306A\u3057\u306B\u306A\u308B\u3002\u4F8B: ClampAdd<long\
    \ long>{{}, {}, 3} \u306F 3 \u3092\u8DB3\u3059\u3001{{}, 5} \u306F chmin 5\n */\n\
    template <typename T>\nstruct ClampAdd {\n    T lb;   //!< \u4E0B\u9650\n    T\
    \ ub;   //!< \u4E0A\u9650\n    T add;  //!< clamp \u306E\u524D\u306B\u8DB3\u3059\
    \u5024\n    /// @brief \u6052\u7B49\u5199\u50CF\n    constexpr ClampAdd() : lb(std::numeric_limits<T>::lowest()),\
    \ ub(std::numeric_limits<T>::max()), add(T(0)) {}\n    /// @brief 1 \u3064\u306E\
    \u5024\u304B\u3089\u306E\u6697\u9ED9\u306E\u5909\u63DB\u3092\u9632\u3050\u305F\
    \u3081\u3001lb \u3068 ub \u306F\u4E21\u65B9\u6E21\u3059\n    constexpr ClampAdd(std::optional<T>\
    \ _lb, std::optional<T> _ub, T _add = T(0))\n        : lb(_lb ? *_lb : std::numeric_limits<T>::lowest()),\
    \ ub(_ub ? *_ub : std::numeric_limits<T>::max()), add(_add) {}\n    constexpr\
    \ T operator()(const T& x) const { return std::min(std::max(x + add, lb), ub);\
    \ }\n    friend constexpr bool operator==(const ClampAdd& f, const ClampAdd& g)\
    \ { return f.lb == g.lb && f.ub == g.ub && f.add == g.add; }\n    friend constexpr\
    \ bool operator!=(const ClampAdd& f, const ClampAdd& g) { return !(f == g); }\n\
    \    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, ClampAdd& f) {\n\
    \        return is >> f.lb >> f.ub >> f.add;\n    }\n    template <class CharT,\
    \ class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const ClampAdd& f) {\n        return os << f.lb << CharT(' ') <<\
    \ f.ub << CharT(' ') << f.add;\n    }\n};\n\nnamespace monoid {\n\n/**\n * @brief\
    \ \u548C\n */\ntemplate <typename T>\nstruct Sum {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return a + b; }\n    static constexpr\
    \ S e() { return S(0); }\n};\n\n/**\n * @brief \u7A4D\n */\ntemplate <typename\
    \ T>\nstruct Prod {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a * b; }\n    static constexpr S e() { return S(1); }\n};\n\n\
    /**\n * @brief \u6700\u5927\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\
    \u5024\n */\ntemplate <typename T>\nstruct Max {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return std::max(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::lowest(); }\n};\n\n/**\n *\
    \ @brief \u6700\u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nstruct Min {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return std::min(a, b); }\n    static constexpr\
    \ S e() { return std::numeric_limits<S>::max(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max}\n */\ntemplate <typename\
    \ T>\nstruct MinMax {\n    using S = std::pair<T, T>;\n    static constexpr S\
    \ op(const S& a, const S& b) { return {std::min(a.first, b.first), std::max(a.second,\
    \ b.second)}; }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::lowest()}; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\
    \u8AD6\u7406\u548C\n */\ntemplate <typename T>\nstruct Xor {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return a ^ b; }\n    static\
    \ constexpr S e() { return S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\u7A4D\n\
    \ */\ntemplate <typename T>\nstruct And {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return a & b; }\n    static constexpr S e() {\
    \ return ~S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\u548C\n */\ntemplate <typename\
    \ T>\nstruct Or {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a | b; }\n    static constexpr S e() { return S(0); }\n};\n\n\
    /**\n * @brief \u6700\u5927\u516C\u7D04\u6570 \u5358\u4F4D\u5143\u306F0\n */\n\
    template <typename T>\nstruct Gcd {\n    static_assert(std::is_integral_v<T>);\n\
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
    \ }\n};\n\n/**\n * @brief clamp \u3059\u308B\u95A2\u6570 (Clamp) \u306E\u5408\u6210\
    \n * op(f, g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n * clamp(clamp(x,\
    \ a, b), c, d) = clamp(x, clamp(a, c, d), clamp(b, c, d)) \u306A\u306E\u3067\u3001\
    \u5408\u6210\u3082 Clamp \u306B\u306A\u308B\n */\ntemplate <typename T>\nstruct\
    \ ClampComposite {\n    using S = Clamp<T>;\n    static constexpr S op(const S&\
    \ f, const S& g) { return {f(g.lb), f(g.ub)}; }\n    static constexpr S e() {\
    \ return {}; }\n};\n\n/**\n * @brief \u8DB3\u3057\u3066\u304B\u3089 clamp \u3059\
    \u308B\u95A2\u6570 (ClampAdd) \u306E\u5408\u6210\n * op(f, g) = f\u2218g (g \u3092\
    \u5148\u306B\u9069\u7528\u3059\u308B)\n * f(g(x)) = clamp(x + g.add + f.add, f(g.lb),\
    \ f(g.ub)) \u306A\u306E\u3067\u3001\u5408\u6210\u3082 ClampAdd \u306B\u306A\u308B\
    \n * \u578B\u306E\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024\u306E lb\u30FBub \u306F\
    \u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057\u3068\u3057\u3066\u6271\u3044\u3001\
    \u8DB3\u3057\u3066\u3082\u3042\u3075\u308C\u306A\u3044\u3088\u3046\u306B\u3059\
    \u308B\n */\ntemplate <typename T>\nstruct ClampAddComposite {\n    using S =\
    \ ClampAdd<T>;\n    static constexpr S op(const S& f, const S& g) {\n        T\
    \ lb = g.lb == std::numeric_limits<T>::lowest() ? f.lb : f(g.lb);\n        T ub\
    \ = g.ub == std::numeric_limits<T>::max() ? f.ub : f(g.ub);\n        return {lb,\
    \ ub, g.add + f.add};\n    }\n    static constexpr S e() { return {}; }\n};\n\n\
    /**\n * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
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
    \u5024\u306E\u578B\n */\ntemplate <typename T, typename U = long long>\nstruct\
    \ MinWith {\n    using S = std::pair<T, U>;\n    static constexpr S op(const S&\
    \ a, const S& b) { return b.first < a.first ? b : a; }\n    static constexpr S\
    \ e() { return {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n * @brief \u6700\
    \u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\
    \u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\
    \u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate\
    \ <typename T, typename U = long long>\nstruct MaxWith {\n    using S = std::pair<T,\
    \ U>;\n    static constexpr S op(const S& a, const S& b) { return a.first < b.first\
    \ ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
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
    \ U(0)}; }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3068\u3001\u7A7A\u3092\
    \u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5927\u5024\n * S(x) \u3067\u5024\
    \ x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\
    \u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate <typename T>\n\
    struct PrefixSumMax {\n    struct S {\n        T sum;  // \u533A\u9593\u306E\u548C\
    \n        T max;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5927\
    \u5024 (0 \u4EE5\u4E0A)\n        constexpr S() : sum(0), max(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), max(x < T(0) ? T(0) : x) {}\n        constexpr S(const\
    \ T& sum, const T& max) : sum(sum), max(max) {}\n        friend constexpr bool\
    \ operator==(const S& a, const S& b) { return a.sum == b.sum && a.max == b.max;\
    \ }\n        friend constexpr bool operator!=(const S& a, const S& b) { return\
    \ !(a == b); }\n    };\n    static constexpr S op(const S& a, const S& b) { return\
    \ S(a.sum + b.sum, std::max(a.max, a.sum + b.max)); }\n    static constexpr S\
    \ e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3068\u3001\
    \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5C0F\u5024\n * S(x)\
    \ \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\
    \u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate\
    \ <typename T>\nstruct PrefixSumMin {\n    struct S {\n        T sum;  // \u533A\
    \u9593\u306E\u548C\n        T min;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\
    \u306E\u6700\u5C0F\u5024 (0 \u4EE5\u4E0B)\n        constexpr S() : sum(0), min(0)\
    \ {}\n        constexpr S(const T& x) : sum(x), min(T(0) < x ? T(0) : x) {}\n\
    \        constexpr S(const T& sum, const T& min) : sum(sum), min(min) {}\n   \
    \     friend constexpr bool operator==(const S& a, const S& b) { return a.sum\
    \ == b.sum && a.min == b.min; }\n        friend constexpr bool operator!=(const\
    \ S& a, const S& b) { return !(a == b); }\n    };\n    static constexpr S op(const\
    \ S& a, const S& b) { return S(a.sum + b.sum, std::min(a.min, a.sum + b.min));\
    \ }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\
    \u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\
    \u5927\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\
    \u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593\
    \ {0, 0}\n */\ntemplate <typename T>\nstruct SuffixSumMax {\n    struct S {\n\
    \        T sum;  // \u533A\u9593\u306E\u548C\n        T max;  // \u7A7A\u3092\u542B\
    \u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        constexpr\
    \ S() : sum(0), max(0) {}\n        constexpr S(const T& x) : sum(x), max(x < T(0)\
    \ ? T(0) : x) {}\n        constexpr S(const T& sum, const T& max) : sum(sum),\
    \ max(max) {}\n        friend constexpr bool operator==(const S& a, const S& b)\
    \ { return a.sum == b.sum && a.max == b.max; }\n        friend constexpr bool\
    \ operator!=(const S& a, const S& b) { return !(a == b); }\n    };\n    static\
    \ constexpr S op(const S& a, const S& b) { return S(a.sum + b.sum, std::max(b.max,\
    \ a.max + b.sum)); }\n    static constexpr S e() { return S(); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 suffix\
    \ \u306E\u548C\u306E\u6700\u5C0F\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\
    \u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\
    \u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate <typename T>\nstruct SuffixSumMin\
    \ {\n    struct S {\n        T sum;  // \u533A\u9593\u306E\u548C\n        T min;\
    \  // \u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\u5C0F\u5024 (0\
    \ \u4EE5\u4E0B)\n        constexpr S() : sum(0), min(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), min(T(0) < x ? T(0) : x) {}\n        constexpr S(const\
    \ T& sum, const T& min) : sum(sum), min(min) {}\n        friend constexpr bool\
    \ operator==(const S& a, const S& b) { return a.sum == b.sum && a.min == b.min;\
    \ }\n        friend constexpr bool operator!=(const S& a, const S& b) { return\
    \ !(a == b); }\n    };\n    static constexpr S op(const S& a, const S& b) { return\
    \ S(a.sum + b.sum, std::min(b.min, a.min + b.sum)); }\n    static constexpr S\
    \ e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3001\u7A7A\
    \u3092\u542B\u3080 prefix\u30FBsuffix \u306E\u548C\u306E\u6700\u5927\u5024\u3001\
    \u7A7A\u3092\u542B\u3080\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\
    \u5927\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\
    \u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593\
    \ {0, 0, 0, 0}\n * \u9759\u7684\u306A\u5217\u306B\u5BFE\u3057\u3066\u4E00\u5EA6\
    \u3060\u3051\u6C42\u3081\u308B\u306A\u3089 dp/maximum-subarray.hpp \u306E maximum_subarray\n\
    \ */\ntemplate <typename T>\nstruct MaxSubarraySum {\n    struct S {\n       \
    \ T sum;     // \u533A\u9593\u306E\u548C\n        T prefix;  // \u7A7A\u3092\u542B\
    \u3080 prefix \u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        T\
    \ suffix;  // \u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024\
    \ (0 \u4EE5\u4E0A)\n        T best;    // \u7A7A\u3092\u542B\u3080\u9023\u7D9A\
    \u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n    \
    \    constexpr S() : sum(0), prefix(0), suffix(0), best(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), prefix(x < T(0) ? T(0) : x), suffix(prefix), best(prefix)\
    \ {}\n        constexpr S(const T& sum, const T& prefix, const T& suffix, const\
    \ T& best)\n            : sum(sum), prefix(prefix), suffix(suffix), best(best)\
    \ {}\n        friend constexpr bool operator==(const S& a, const S& b) {\n   \
    \         return a.sum == b.sum && a.prefix == b.prefix && a.suffix == b.suffix\
    \ && a.best == b.best;\n        }\n        friend constexpr bool operator!=(const\
    \ S& a, const S& b) { return !(a == b); }\n    };\n    static constexpr S op(const\
    \ S& a, const S& b) {\n        return S(a.sum + b.sum, std::max(a.prefix, a.sum\
    \ + b.prefix), std::max(b.suffix, a.suffix + b.sum),\n                 std::max({a.best,\
    \ b.best, a.suffix + b.prefix}));\n    }\n    static constexpr S e() { return\
    \ S(); }\n};\n\n/**\n * @brief \u7A4D\u306E\u9806\u5E8F\u3092\u9006\u306B\u3057\
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
    \ }\n};\n\n/**\n * @brief \u533A\u9593 clamp x <- min(max(x, lb), ub) (Clamp)\u3001\
    \u533A\u9593\u6700\u5C0F\u5024\n * clamp \u306F\u5358\u8ABF\u975E\u6E1B\u5C11\u306A\
    \u306E\u3067\u3001\u6700\u5C0F\u5024\u306B\u9069\u7528\u3059\u308C\u3070\u3088\
    \u3044\n */\ntemplate <typename T>\nstruct ClampMin : monoid::Min<T> {\n    using\
    \ S = T;\n    using F = Clamp<T>;\n    static constexpr S mapping(const F& f,\
    \ const S& x) { return f(x); }\n    static constexpr F composition(const F& f,\
    \ const F& g) { return monoid::ClampComposite<T>::op(f, g); }\n    static constexpr\
    \ F id() { return {}; }\n};\n\n/**\n * @brief \u533A\u9593 clamp x <- min(max(x,\
    \ lb), ub) (Clamp)\u3001\u533A\u9593\u6700\u5927\u5024\n */\ntemplate <typename\
    \ T>\nstruct ClampMax : monoid::Max<T> {\n    using S = T;\n    using F = Clamp<T>;\n\
    \    static constexpr S mapping(const F& f, const S& x) { return f(x); }\n   \
    \ static constexpr F composition(const F& f, const F& g) { return monoid::ClampComposite<T>::op(f,\
    \ g); }\n    static constexpr F id() { return {}; }\n};\n\n/**\n * @brief \u533A\
    \u9593 clamp x <- min(max(x, lb), ub) (Clamp)\u3001\u533A\u9593\u6700\u5C0F\u5024\
    \u3068\u6700\u5927\u5024\u306E\u7D44 {min, max} (monoid::MinMax)\n */\ntemplate\
    \ <typename T>\nstruct ClampMinMax : monoid::MinMax<T> {\n    using S = std::pair<T,\
    \ T>;\n    using F = Clamp<T>;\n    static constexpr S mapping(const F& f, const\
    \ S& x) { return {f(x.first), f(x.second)}; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return monoid::ClampComposite<T>::op(f, g); }\n    static\
    \ constexpr F id() { return {}; }\n};\n\n/**\n * @brief \u533A\u9593 \u52A0\u7B97\
    \u3068 clamp x <- min(max(x + add, lb), ub) (ClampAdd)\u3001\u533A\u9593\u6700\
    \u5C0F\u5024\n * \u533A\u9593\u52A0\u7B97\u30FBchmin\u30FBchmax\u30FB\u4EE3\u5165\
    \u3092\u307E\u3068\u3081\u3066\u6271\u3048\u308B\u3002\u5358\u8ABF\u975E\u6E1B\
    \u5C11\u306A\u306E\u3067\u3001\u6700\u5C0F\u5024\u306B\u9069\u7528\u3059\u308C\
    \u3070\u3088\u3044\n */\ntemplate <typename T>\nstruct ClampAddMin : monoid::Min<T>\
    \ {\n    using S = T;\n    using F = ClampAdd<T>;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return f(x); }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f, g); }\n    static\
    \ constexpr F id() { return {}; }\n};\n\n/**\n * @brief \u533A\u9593 \u52A0\u7B97\
    \u3068 clamp x <- min(max(x + add, lb), ub) (ClampAdd)\u3001\u533A\u9593\u6700\
    \u5927\u5024\n */\ntemplate <typename T>\nstruct ClampAddMax : monoid::Max<T>\
    \ {\n    using S = T;\n    using F = ClampAdd<T>;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return f(x); }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f, g); }\n    static\
    \ constexpr F id() { return {}; }\n};\n\n/**\n * @brief \u533A\u9593 \u52A0\u7B97\
    \u3068 clamp x <- min(max(x + add, lb), ub) (ClampAdd)\u3001\u533A\u9593\u6700\
    \u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max} (monoid::MinMax)\n\
    \ */\ntemplate <typename T>\nstruct ClampAddMinMax : monoid::MinMax<T> {\n   \
    \ using S = std::pair<T, T>;\n    using F = ClampAdd<T>;\n    static constexpr\
    \ S mapping(const F& f, const S& x) { return {f(x.first), f(x.second)}; }\n  \
    \  static constexpr F composition(const F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f,\
    \ g); }\n    static constexpr F id() { return {}; }\n};\n\n/**\n * @brief \u533A\
    \u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB x <- a * x + b (Affine)\u3001\u533A\
    \u9593\u548C\n */\ntemplate <typename T>\nstruct AffineSum : monoid::Sum<T> {\n\
    \    using S = T;\n    using F = Affine<T>;\n    static constexpr S mapping(const\
    \ F& f, const S& x, long long sz) { return f.a * x + f.b * S(sz); }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return {f.a * g.a, f.a * g.b\
    \ + f.b}; }\n    static constexpr F id() { return {T(1), T(0)}; }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u4EE3\u5165\u30011\u6B21\u95A2\u6570\u306E\u5408\u6210\
    \ (monoid::Composite)\n */\ntemplate <typename T>\nstruct UpdateComposite : monoid::Composite<T>\
    \ {\n    using S = Affine<T>;\n    using F = std::optional<S>;\n    static constexpr\
    \ S mapping(const F& f, const S& x, long long sz) {\n        if (!f) return x;\n\
    \        // f \u3092 sz \u56DE\u5408\u6210\u3059\u308B\n        S ret = monoid::Composite<T>::e(),\
    \ p = *f;\n        for (; sz > 0; sz >>= 1) {\n            if (sz & 1) ret = monoid::Composite<T>::op(ret,\
    \ p);\n            p = monoid::Composite<T>::op(p, p);\n        }\n        return\
    \ ret;\n    }\n    static constexpr F composition(const F& f, const F& g) { return\
    \ f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\
    \u306E\u4F4D\u7F6E (monoid::MinWith)\n */\ntemplate <typename T, typename U =\
    \ long long>\nstruct AddMinWith : monoid::MinWith<T, U> {\n    using S = std::pair<T,\
    \ U>;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return {x.first + f, x.second}; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\
    \u5024\u3068\u305D\u306E\u4F4D\u7F6E (monoid::MaxWith)\n */\ntemplate <typename\
    \ T, typename U = long long>\nstruct AddMaxWith : monoid::MaxWith<T, U> {\n  \
    \  using S = std::pair<T, U>;\n    using F = T;\n    static constexpr S mapping(const\
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
    \ i++) val[i] = val[i - 1] * x;\n        }\n        constexpr const T& operator[](long\
    \ long i) const { return val[i]; }\n    };\n    using F = T;\n    static constexpr\
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
    \ F id() { return F(0); }\n};\n\n/**\n * @brief \u6210\u5206\u306E\u4E26\u3079\
    \u66FF\u3048 (monoid::Mapping)\u3001\u30E2\u30CE\u30A4\u30C9 M \u306E N \u500B\
    \u306E\u76F4\u7A4D\n *\n * \u8981\u7D20\u306F M \u306E\u8981\u7D20\u3092 N \u500B\
    \u4E26\u3079\u305F std::array \u3067\u3001\u7A4D\u306F\u6210\u5206\u3054\u3068\
    \u306B M::op \u3092\u3068\u308B\n * \u4F5C\u7528\u7D20 f \u306F monoid::Mapping<N>\
    \ \u306E\u8981\u7D20\u3067\u3001mapping(f, x)[i] = x[f[i]] (\u6210\u5206 i \u306B\
    \ x \u306E\u6210\u5206 f[i] \u3092\u6301\u3063\u3066\u304F\u308B)\n * f \u306F\
    \u5168\u5358\u5C04\u3067\u306A\u304F\u3066\u3088\u3044\u3002\u4F8B\u3048\u3070\
    \ N = 3 \u3067 f = {1, 1, 2} \u306F\u6210\u5206 0 \u3092\u6210\u5206 1 \u3067\u4E0A\
    \u66F8\u304D\u3059\u308B\n * \u7A4D\u304C\u6210\u5206\u3054\u3068\u306A\u306E\u3067\
    \u3001M \u306B\u3088\u3089\u305A\u4F5C\u7528\u306F\u7A4D\u3068\u53EF\u63DB\u306B\
    \u306A\u308B\n *\n * @tparam M static \u306A op, e \u3092\u6301\u3064\u30E2\u30CE\
    \u30A4\u30C9\n * @tparam N \u6210\u5206\u306E\u500B\u6570\n */\ntemplate <typename\
    \ M, std::size_t N>\nstruct Rearrange {\n    using S = std::array<typename M::S,\
    \ N>;\n    using F = typename monoid::Mapping<N>::S;\n    static constexpr S op(const\
    \ S& a, const S& b) {\n        S res{};\n        for (std::size_t i = 0; i < N;\
    \ i++) res[i] = M::op(a[i], b[i]);\n        return res;\n    }\n    static constexpr\
    \ S e() {\n        S res{};\n        for (std::size_t i = 0; i < N; i++) res[i]\
    \ = M::e();\n        return res;\n    }\n    static constexpr S mapping(const\
    \ F& f, const S& x) {\n        S res{};\n        for (std::size_t i = 0; i < N;\
    \ i++) res[i] = x[f[i]];\n        return res;\n    }\n    // mapping(f, mapping(g,\
    \ x))[i] = x[g[f[i]]] \u306A\u306E\u3067\u3001Mapping \u306E\u7A4D\u3068\u3057\
    \u3066\u306F g\u2218f \u306B\u306A\u308B\n    static constexpr F composition(const\
    \ F& f, const F& g) { return monoid::Mapping<N>::op(g, f); }\n    static constexpr\
    \ F id() { return monoid::Mapping<N>::e(); }\n    // \u6210\u5206 i \u3068 j \u3092\
    \u5165\u308C\u66FF\u3048\u308B\u4F5C\u7528\u7D20\n    static constexpr F swap(long\
    \ long i, long long j) { return monoid::Mapping<N>::swap(i, j); }\n};\n\n}  //\
    \ namespace acted_monoid\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u4F5C\u7528\u7D20\
    \u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\
    \u308B\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\
    \u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n * @tparam U \u4F5C\u7528\
    \u7D20\u306E\u578B\n * @tparam Mapping \u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\
    \u308B\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B \u5F15\u6570\
    \u306F (f, x), (f, x, sz), (f, x, l, r) \u306E\u3044\u305A\u308C\u304B\n * @tparam\
    \ Composition \u4F5C\u7528\u7D20\u306E\u5408\u6210\u306E\u95A2\u6570\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename Op,\
    \ typename U, typename Mapping, typename Composition>\nstruct ActedMonoid {\n\
    \    using S = T;\n    using F = U;\n    Op op_object;\n    S identity;\n    Mapping\
    \ mapping_object;\n    Composition composition_object;\n    F lazy_identity;\n\
    \    ActedMonoid() = default;\n    constexpr ActedMonoid(Op op, const S& e, Mapping\
    \ mapping, Composition composition, const F& id)\n        : op_object(std::move(op)),\
    \ identity(e), mapping_object(std::move(mapping)), composition_object(std::move(composition)),\
    \ lazy_identity(id) {}\n    constexpr S op(const S& a, const S& b) const { return\
    \ op_object(a, b); }\n    constexpr S e() const { return identity; }\n    constexpr\
    \ auto mapping(const F& f, const S& x, long long l, long long r) const {\n   \
    \     if constexpr (std::is_invocable_v<const Mapping&, const F&, const S&, long\
    \ long, long long>) {\n            return mapping_object(f, x, l, r);\n      \
    \  } else if constexpr (std::is_invocable_v<const Mapping&, const F&, const S&,\
    \ long long>) {\n            return mapping_object(f, x, r - l);\n        } else\
    \ {\n            return mapping_object(f, x);\n        }\n    }\n    constexpr\
    \ F composition(const F& f, const F& g) const { return composition_object(f, g);\
    \ }\n    constexpr F id() const { return lazy_identity; }\n};\ntemplate <typename\
    \ Op, typename T, typename Mapping, typename Composition, typename U>\nActedMonoid(Op,\
    \ T, Mapping, Composition, U) -> ActedMonoid<T, Op, U, Mapping, Composition>;\n\
    #line 13 \"src/data_structures/dual-segtree.hpp\"\n\n/**\n * @brief \u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\u7528\u30011\u70B9\u53D6\
    \u5F97)\n *\n * \u533A\u9593\u3078\u306E\u4F5C\u7528\u7D20\u306E\u9069\u7528\u3068\
    1\u70B9\u306E\u53D6\u5F97\u3092 O(log n) \u3067\u884C\u3046\u3002\u4F5C\u7528\u7D20\
    \u306F\u53EF\u63DB\u3067\u306A\u304F\u3066\u3082\u3088\u3044\n * \u9045\u5EF6\u4F1D\
    \u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3068\u9055\u3044\u3001\u5024\u306E\
    \u30E2\u30CE\u30A4\u30C9\u306E\u6F14\u7B97 (op\u3001e) \u306F\u4F7F\u308F\u306A\
    \u3044\n * \u4F8B:\n * DualSegTree<acted_monoid::AffineSum<mint>> seg(v);\n *\
    \ seg.apply(l, r, Affine<mint>{b, c});\n * mint x = seg.get(i);\n *\n * @tparam\
    \ A \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\n\
    \ */\ntemplate <typename A>\nclass DualSegTree {\n   public:\n    using S = typename\
    \ A::S;\n    using F = typename A::F;\n\n   private:\n    A a;\n    long long\
    \ n, sz;\n    int height;\n    std::vector<S> data;  // \u8449\u306E\u5024 (\u4F5C\
    \u7528\u7D20\u3092\u307E\u3060\u9069\u7528\u3057\u3066\u3044\u306A\u3044\u3082\
    \u306E)\n    std::vector<F> lazy;  // \u5404\u30CE\u30FC\u30C9\u306E\u533A\u9593\
    \u306B\u3001\u307E\u3060\u4E0B\u3078\u4F1D\u3048\u3066\u3044\u306A\u3044\u4F5C\
    \u7528\u7D20\n\n    S mapping(const F& f, const S& x, long long k) const { return\
    \ acted_monoid::apply_mapping(a, f, x, k, k + 1); }\n    F composition(const F&\
    \ f, const F& g) const { return a.composition(f, g); }\n    F id() const { return\
    \ a.id(); }\n\n    void apply_node(long long k, const F& f) { lazy[k] = composition(f,\
    \ lazy[k]); }\n    void push(long long k) {\n        apply_node(2 * k, lazy[k]);\n\
    \        apply_node(2 * k + 1, lazy[k]);\n        lazy[k] = id();\n    }\n   \
    \ // \u8449 k \u306E\u7956\u5148\u306E\u4F5C\u7528\u7D20\u3092\u3059\u3079\u3066\
    \u4E0B\u3078\u4F1D\u3048\u308B\n    void push_ancestors(long long k) {\n     \
    \   for (int h = height; h > 0; h--) push(k >> h);\n    }\n\n    void construct()\
    \ {\n        sz = 1;\n        height = 0;\n        while (sz < n) {\n        \
    \    sz <<= 1;\n            height++;\n        }\n        lazy.assign(2 * sz,\
    \ id());\n    }\n\n   public:\n    /**\n     * @param n \u8981\u7D20\u6570 \u5404\
    \u8981\u7D20\u306F S() \u3067\u521D\u671F\u5316\u3059\u308B\n     * @param a \u4F5C\
    \u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit DualSegTree(long\
    \ long n = 0, A a = A()) : DualSegTree(n, S(), std::move(a)) {}\n    /**\n   \
    \  * @param n \u8981\u7D20\u6570\n     * @param value \u5404\u8981\u7D20\u306E\
    \u521D\u671F\u5024\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\
    \u30A4\u30C9\n     */\n    DualSegTree(long long n, const S& value, A a = A())\
    \ : a(std::move(a)), n(n), data(n, value) { construct(); }\n    /**\n     * @param\
    \ v \u521D\u671F\u306E\u8981\u7D20\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\
    \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit DualSegTree(const std::vector<S>&\
    \ v, A a = A()) : a(std::move(a)), n(v.size()), data(v) { construct(); }\n\n \
    \   /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long\
    \ long size() const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059 O(log n)\n     */\n   \
    \ S get(long long k) const {\n        assert(0 <= k && k < n);\n        // \u6839\
    \u306B\u8FD1\u3044\u30CE\u30FC\u30C9\u307B\u3069\u5F8C\u306B\u4F5C\u7528\u3057\
    \u305F\u4F5C\u7528\u7D20\u306A\u306E\u3067\u3001\u8449\u304B\u3089\u9806\u306B\
    \u5408\u6210\u3059\u308B\n        F f = id();\n        for (long long i = k +\
    \ sz; i > 0; i >>= 1) f = composition(lazy[i], f);\n        return mapping(f,\
    \ data[k], k);\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u306E\u5024\u3092\u8FD4\u3059 O(n)\n     */\n    std::vector<S> to_vector() {\n\
    \        for (long long k = 1; k < sz; k++) push(k);\n        std::vector<S> res(n);\n\
    \        for (long long k = 0; k < n; k++) res[k] = mapping(lazy[k + sz], data[k],\
    \ k);\n        return res;\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u306E\u5024\u3092 x \u306B\u3059\u308B O(log n)\n     */\n\
    \    void set(long long k, const S& x) {\n        assert(0 <= k && k < n);\n \
    \       push_ancestors(k + sz);\n        data[k] = x;\n        lazy[k + sz] =\
    \ id();\n    }\n\n    /**\n     * @brief 1\u70B9\u4F5C\u7528 O(log n)\n     */\n\
    \    void apply(long long k, const F& f) {\n        assert(0 <= k && k < n);\n\
    \        push_ancestors(k + sz);\n        apply_node(k + sz, f);\n    }\n    /**\n\
    \     * @brief [l, r) \u306E\u533A\u9593\u306E\u5024\u306B f \u3092\u4F5C\u7528\
    \u3055\u305B\u308B O(log n)\n     */\n    void apply(long long l, long long r,\
    \ const F& f) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l ==\
    \ r) return;\n        l += sz;\n        r += sz;\n        // \u4F5C\u7528\u3059\
    \u308B\u533A\u9593\u306E\u5883\u754C\u306E\u7956\u5148\u306B\u6B8B\u3063\u3066\
    \u3044\u308B\u4F5C\u7528\u7D20\u3092\u5148\u306B\u4E0B\u3078\u4F1D\u3048\u308B\
    \ (\u4F5C\u7528\u7D20\u304C\u53EF\u63DB\u3067\u306A\u304F\u3066\u3082\u9806\u5E8F\
    \u3092\u4FDD\u3064\u305F\u3081)\n        for (int h = height; h > 0; h--) {\n\
    \            if (((l >> h) << h) != l) push(l >> h);\n            if (((r >> h)\
    \ << h) != r) push((r - 1) >> h);\n        }\n        for (; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) apply_node(l++, f);\n            if (r & 1)\
    \ apply_node(--r, f);\n        }\n    }\n};\n\ntemplate <typename A>\nDualSegTree(long\
    \ long, A) -> DualSegTree<A>;\ntemplate <typename A>\nDualSegTree(long long, typename\
    \ A::S, A) -> DualSegTree<A>;\ntemplate <typename A>\nDualSegTree(std::vector<typename\
    \ A::S>, A) -> DualSegTree<A>;\n\n// \u5225\u540D \u53CC\u5BFE\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\u306F op, e \u3092\u4F7F\u308F\u306A\u3044\u306E\u3067\u3001\
    \u53D6\u5F97\u306E\u90E8\u5206\u3092\u540D\u524D\u306B\u542B\u3081\u306A\u3044\
    \n// mapping \u304C\u533A\u9593\u306E\u9577\u3055\u3092\u4F7F\u308F\u306A\u3044\
    \ Min \u7CFB\u3092\u5B9F\u4F53\u306B\u3059\u308B (\u5024\u306E\u578B\u306B S(sz)\
    \ \u3084\u639B\u3051\u7B97\u3092\u6C42\u3081\u306A\u3044)\n\n/**\n * @brief \u533A\
    \u9593\u52A0\u7B97\u30011\u70B9\u53D6\u5F97\n *\n * @tparam S \u578B\n */\ntemplate\
    \ <typename S>\nusing RAddQ = DualSegTree<acted_monoid::AddMin<S>>;\n/**\n * @brief\
    \ \u533A\u9593\u4EE3\u5165\u30011\u70B9\u53D6\u5F97\n *\n * @tparam S \u578B\n\
    \ */\ntemplate <typename S>\nusing RUpdateQ = DualSegTree<acted_monoid::UpdateMin<S>>;\n\
    /**\n * @brief \u533A\u9593 chmin\u30011\u70B9\u53D6\u5F97\n *\n * @tparam S \u578B\
    \n */\ntemplate <typename S>\nusing RChminQ = DualSegTree<acted_monoid::ChminMin<S>>;\n\
    /**\n * @brief \u533A\u9593 chmax\u30011\u70B9\u53D6\u5F97\n *\n * @tparam S \u578B\
    \n */\ntemplate <typename S>\nusing RChmaxQ = DualSegTree<acted_monoid::ChmaxMax<S>>;\n\
    /**\n * @brief \u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB x <- a * x + b\
    \ (Affine)\u30011\u70B9\u53D6\u5F97\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RAffineQ = DualSegTree<acted_monoid::AffineSum<S>>;\n#line 6 \"test/aoj/dsl-2-d.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    DualSegTree<acted_monoid::UpdateMin<int>>\
    \ seg(n, 2147483647);\n    while (q--) {\n        int t;\n        std::cin >>\
    \ t;\n        if (t == 0) {\n            int s, u, x;\n            std::cin >>\
    \ s >> u >> x;\n            seg.apply(s, u + 1, x);\n        } else {\n      \
    \      int i;\n            std::cin >> i;\n            std::cout << seg.get(i)\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include <iostream>\n\n#include \"../../src/data_structures/dual-segtree.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    DualSegTree<acted_monoid::UpdateMin<int>>\
    \ seg(n, 2147483647);\n    while (q--) {\n        int t;\n        std::cin >>\
    \ t;\n        if (t == 0) {\n            int s, u, x;\n            std::cin >>\
    \ s >> u >> x;\n            seg.apply(s, u + 1, x);\n        } else {\n      \
    \      int i;\n            std::cin >> i;\n            std::cout << seg.get(i)\
    \ << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - src/data_structures/dual-segtree.hpp
  - src/algebra/acted-monoid.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: true
  path: test/aoj/dsl-2-d.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 12:03:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl-2-d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl-2-d.test.cpp
- /verify/test/aoj/dsl-2-d.test.cpp.html
title: test/aoj/dsl-2-d.test.cpp
---
