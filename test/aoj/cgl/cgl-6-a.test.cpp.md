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
    path: src/data_structures/fenwick-tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  - icon: ':heavy_check_mark:'
    path: src/geometry/axis-parallel-segments.hpp
    title: "\u8EF8\u306B\u5E73\u884C\u306A\u7DDA\u5206\u306E\u4EA4\u70B9\u306E\u500B\
      \u6570"
  - icon: ':heavy_check_mark:'
    path: src/geometry/vector.hpp
    title: "\u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A
  bundledCode: "#line 1 \"test/aoj/cgl/cgl-6-a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/geometry/axis-parallel-segments.hpp\"\
    \n\n/**\n * @file axis-parallel-segments.hpp\n * @brief \u8EF8\u306B\u5E73\u884C\
    \u306A\u7DDA\u5206\u306E\u4EA4\u70B9\u306E\u500B\u6570\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <tuple>\n#line 12 \"src/geometry/axis-parallel-segments.hpp\"\
    \n\n#line 2 \"src/algebra/group.hpp\"\n\n/**\n * @file group.hpp\n * @brief \u7FA4\
    \u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\
    \ \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\
    \u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - S inv(const S& a):\
    \ \u9006\u5143\n */\n\n#include <array>\n#include <cstddef>\n#line 14 \"src/algebra/group.hpp\"\
    \n\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\
    \u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\
    \u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S& a, const S&\
    \ b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n * op, e \u306F\
    \ static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\u30FC\u30BF\
    \u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\n#line 17\
    \ \"src/algebra/monoid.hpp\"\n#include <istream>\n#include <limits>\n#include\
    \ <numeric>\n#include <optional>\n#include <ostream>\n#include <type_traits>\n\
    #line 24 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\u95A2\u6570 f(x)\
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
    \ typename Inv>\nGroup(Op, T, Inv) -> Group<T, Op, Inv>;\n#line 2 \"src/data_structures/fenwick-tree.hpp\"\
    \n\n/**\n * @file fenwick-tree.hpp\n * @brief Fenwick Tree (Binary Indexed Tree)\n\
    \ */\n\n#line 11 \"src/data_structures/fenwick-tree.hpp\"\n\n#line 13 \"src/data_structures/fenwick-tree.hpp\"\
    \n\n/**\n * @brief Fenwick Tree (Binary Indexed Tree)\n *\n * 1 \u70B9\u3078\u306E\
    \u4F5C\u7528\u3068\u533A\u9593\u7A4D\u3092 O(log n) \u3067\u884C\u3046\n * \u4F8B\
    :\n * FenwickTree<group::Sum<long long>> ft(n);\n * ft.apply(i, x);  // a[i] +=\
    \ x\n * ft.prod(l, r);   // a[l] + ... + a[r-1]\n *\n * @tparam G \u53EF\u63DB\
    \u306A\u7FA4 (algebra/group.hpp)\u3002prefix_prod \u3068 max_right \u3060\u3051\
    \u306A\u3089\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3067\u3082\u3088\u3044\n */\n\
    template <typename G>\nclass FenwickTree {\n   public:\n    using S = typename\
    \ G::S;\n\n   private:\n    G g;\n    long long n;\n    // data[i] \u306F a[i\
    \ - (i & -i)] \u304B\u3089 a[i-1] \u307E\u3067\u306E\u7A4D (1-indexed)\n    std::vector<S>\
    \ data;\n    S op(const S& a, const S& b) const { return g.op(a, b); }\n    S\
    \ e() const { return g.e(); }\n    S inv(const S& a) const { return g.inv(a);\
    \ }\n\n   public:\n    /**\n     * @brief \u8981\u7D20\u6570 n \u3067\u3001\u3059\
    \u3079\u3066\u306E\u8981\u7D20\u304C\u5358\u4F4D\u5143\u306E Fenwick Tree \u3092\
    \u4F5C\u308B\n     */\n    explicit FenwickTree(long long n = 0, G g = G()) :\
    \ g(std::move(g)), n(n), data(n + 1, e()) {}\n    /**\n     * @brief v \u3092\u521D\
    \u671F\u5024\u3068\u3059\u308B Fenwick Tree \u3092\u4F5C\u308B O(n)\n     */\n\
    \    explicit FenwickTree(const std::vector<S>& v, G g = G()) : FenwickTree(v.size(),\
    \ std::move(g)) {\n        for (long long i = 1; i <= n; i++) {\n            data[i]\
    \ = op(data[i], v[i - 1]);\n            long long j = i + (i & -i);\n        \
    \    if (j <= n) data[j] = op(data[j], data[i]);\n        }\n    }\n\n    long\
    \ long size() const { return n; }\n\n    /**\n     * @brief a[k] \u3092 op(a[k],\
    \ x) \u306B\u3059\u308B O(log n)\n     */\n    void apply(long long k, const S&\
    \ x) {\n        assert(0 <= k && k < n);\n        for (k++; k <= n; k += k & -k)\
    \ data[k] = op(data[k], x);\n    }\n    /**\n     * @brief a[0] \u304B\u3089 a[r-1]\
    \ \u307E\u3067\u306E\u7A4D O(log n)\n     */\n    S prefix_prod(long long r) const\
    \ {\n        assert(0 <= r && r <= n);\n        S res = e();\n        for (; r\
    \ > 0; r -= r & -r) res = op(data[r], res);\n        return res;\n    }\n    /**\n\
    \     * @brief a[l] \u304B\u3089 a[r-1] \u307E\u3067\u306E\u7A4D O(log n)\u3002\
    \u9006\u5143\u3092\u4F7F\u3046\n     */\n    S prod(long long l, long long r)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        return op(inv(prefix_prod(l)),\
    \ prefix_prod(r));\n    }\n    S all_prod() const { return prefix_prod(n); }\n\
    \    /**\n     * @brief a[k] O(log n)\u3002\u9006\u5143\u3092\u4F7F\u3046\n  \
    \   */\n    S get(long long k) const {\n        assert(0 <= k && k < n);\n   \
    \     return prod(k, k + 1);\n    }\n    /**\n     * @brief a[k] \u3092 x \u306B\
    \u3059\u308B O(log n)\u3002\u9006\u5143\u3092\u4F7F\u3046\n     */\n    void set(long\
    \ long k, const S& x) { apply(k, op(inv(get(k)), x)); }\n\n    /**\n     * @brief\
    \ f(prefix_prod(r)) = true \u3068\u306A\u308B\u6700\u5927\u306E r \u3092\u8FD4\
    \u3059 O(log n)\n     * f \u306F\u5358\u8ABF (\u3042\u308B r \u307E\u3067\u306F\
    \ true \u3067\u305D\u308C\u4EE5\u964D\u306F false) \u3067\u3042\u308B\u3053\u3068\
    \u3002f(e()) = true\n     */\n    template <typename F>\n    long long max_right(F\
    \ f) const {\n        assert(f(e()));\n        long long r = 0;\n        S sum\
    \ = e();\n        long long step = 1;\n        while (step * 2 <= n) step *= 2;\n\
    \        for (; step > 0; step /= 2) {\n            if (r + step <= n && f(op(sum,\
    \ data[r + step]))) {\n                r += step;\n                sum = op(sum,\
    \ data[r]);\n            }\n        }\n        return r;\n    }\n};\n\ntemplate\
    \ <typename G>\nFenwickTree(long long, G) -> FenwickTree<G>;\ntemplate <typename\
    \ G>\nFenwickTree(std::vector<typename G::S>, G) -> FenwickTree<G>;\n#line 2 \"\
    src/geometry/vector.hpp\"\n\n/**\n * @file vector.hpp\n * @brief \u5E7E\u4F55\u30D9\
    \u30AF\u30C8\u30EB\n */\n\n#line 11 \"src/geometry/vector.hpp\"\n#include <cmath>\n\
    #line 17 \"src/geometry/vector.hpp\"\n#include <stack>\n#line 21 \"src/geometry/vector.hpp\"\
    \n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief\
    \ \u578B\u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include <iterator>\n\
    #include <set>\n#line 13 \"src/utility/traits.hpp\"\n\nnamespace internal_traits\
    \ {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace internal_traits\n\
    \ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\
    \n#define HAS_METHOD(func_name)                                              \
    \                \\\n    namespace internal_traits {                         \
    \                                   \\\n    template <class T, class = void> \
    \                                                      \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : internal_traits::has_##func_name##_impl<T>::type {};          \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace internal_traits {     \
    \                                                                           \\\
    \n    template <class T, typename U, class = void>                           \
    \                                    \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                                        \\\n    template\
    \ <class T, typename U>                                                      \
    \                       \\\n    struct has_##func_name##_impl<T, U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>>\
    \ \\\n        : std::true_type {};                                           \
    \                                        \\\n    }                           \
    \                                                                            \
    \   \\\n    template <class T, typename U>                                   \
    \                                          \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
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
    #line 23 \"src/geometry/vector.hpp\"\n\n/**\n * @brief \u5E7E\u4F55\u5B66\u3068\
    \u3057\u3066\u306E\u30D9\u30AF\u30C8\u30EB\n *\n * @tparam T \u578B \u7701\u7565\
    \u3057\u305F\u3089double\n * @tparam Dim \u6B21\u5143 \u7701\u7565\u3057\u305F\
    \u30892\n */\ntemplate <typename T = double, int Dim = 2, ENABLE_IF_T(std::is_scalar_v<T>\
    \ && (Dim > 0))>\nstruct Vector {\n    std::array<T, Dim> v;  //!< \u30D9\u30AF\
    \u30C8\u30EB\u306E\u6210\u5206\u8868\u793A\n\n    /**\n     * @brief \u30C7\u30D5\
    \u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * \u30BC\u30ED\
    \u30D9\u30AF\u30C8\u30EB\n     */\n    constexpr Vector() noexcept : v() {}\n\
    \    /**\n     * @brief \u53EF\u5909\u9577\u5F15\u6570\u306B\u3088\u308B\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam Args\n     */\n \
    \   template <typename... Args>\n    constexpr Vector(Args... args) noexcept :\
    \ v{args...} {}\n\n    /**\n     * @brief i\u756A\u76EE\u306E\u6210\u5206\u3092\
    \u8FD4\u3059\n     *\n     * @param i\n     * @return T&\n     */\n    constexpr\
    \ T& operator[](long long i) noexcept {\n        return v[i];\n    }\n    /**\n\
    \     * @brief i\u756A\u76EE\u306E\u6210\u5206\u3092\u8FD4\u3059\n     *\n   \
    \  * @param i\n     * @return T&\n     */\n    constexpr const T& operator[](long\
    \ long i) const noexcept {\n        return v[i];\n    }\n\n    /**\n     * @brief\
    \ \u52A0\u7B97\u4EE3\u5165\u6F14\u7B97\u5B50\n     *\n     * @param rhs\n    \
    \ * @return Vector&\n     */\n    constexpr Vector& operator+=(const Vector& rhs)\
    \ noexcept {\n        for (int i = 0; i < Dim; i++) v[i] += rhs[i];\n        return\
    \ *this;\n    }\n    /**\n     * @brief \u6E1B\u7B97\u4EE3\u5165\u6F14\u7B97\u5B50\
    \n     *\n     * @param rhs\n     * @return Vector&\n     */\n    constexpr Vector&\
    \ operator-=(const Vector& rhs) noexcept {\n        for (int i = 0; i < Dim; i++)\
    \ v[i] -= rhs.v[i];\n        return *this;\n    }\n    /**\n     * @brief \u30B9\
    \u30AB\u30E9\u30FC\u500D\u4EE3\u5165\u6F14\u7B97\u5B50\n     *\n     * @param\
    \ coef\n     * @return Vector&\n     */\n    constexpr Vector& operator*=(const\
    \ T& coef) noexcept {\n        for (int i = 0; i < Dim; i++) v[i] *= coef;\n \
    \       return *this;\n    }\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u306E\
    \u9006\u6570\u500D\u4EE3\u5165\u6F14\u7B97\u5B50\n     *\n     * @param coef\n\
    \     * @return Vector&\n     */\n    constexpr Vector& operator/=(const T& coef)\
    \ {\n        for (int i = 0; i < Dim; i++) {\n            if constexpr (std::is_integral_v<T>)\
    \ {\n                assert(v[i] % coef == 0 && \"Vector::operator/= : coef must\
    \ be a divisor of all elements\");\n            }\n            v[i] /= coef;\n\
    \        }\n        return *this;\n    }\n\n    /**\n     * @brief \u5358\u9805\
    \u30D7\u30E9\u30B9\u6F14\u7B97\u5B50\n     *\n     * @return Vector\n     */\n\
    \    [[nodiscard]]\n    constexpr Vector operator+() const noexcept {\n      \
    \  return *this;\n    }\n    /**\n     * @brief \u5358\u9805\u30DE\u30A4\u30CA\
    \u30B9\u6F14\u7B97\u5B50\n     *\n     * @return Vector\n     */\n    [[nodiscard]]\n\
    \    constexpr Vector operator-() const noexcept {\n        return *this * (-1);\n\
    \    }\n\n    /**\n     * @brief \u52A0\u7B97\u6F14\u7B97\u5B50\n     *\n    \
    \ * @param lhs\n     * @param rhs\n     * @return Vector\n     */\n    [[nodiscard]]\n\
    \    friend constexpr Vector operator+(const Vector& lhs, const Vector& rhs) noexcept\
    \ {\n        return std::move(Vector(lhs) += rhs);\n    }\n\n    /**\n     * @brief\
    \ \u6E1B\u7B97\u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n\
    \     * @return Vector\n     */\n    [[nodiscard]]\n    friend constexpr Vector\
    \ operator-(const Vector& lhs, const Vector& rhs) noexcept {\n        return std::move(Vector(lhs)\
    \ -= rhs);\n    }\n\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u500D\u6F14\
    \u7B97\u5B50\n     *\n     * @param lhs\n     * @param coef\n     * @return Vector\n\
    \     */\n    [[nodiscard]]\n    friend constexpr Vector operator*(const Vector&\
    \ lhs, const T& coef) noexcept {\n        return std::move(Vector(lhs) *= coef);\n\
    \    }\n\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u500D\u6F14\u7B97\u5B50\
    \n     *\n     * @param coef\n     * @param rhs\n     * @return Vector\n     */\n\
    \    [[nodiscard]]\n    friend constexpr Vector operator*(const T& coef, const\
    \ Vector& rhs) noexcept {\n        return std::move(Vector(rhs) *= coef);\n  \
    \  }\n\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u306E\u9006\u6570\u500D\
    \u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param coef\n     * @return\
    \ Vector\n     */\n    [[nodiscard]]\n    friend constexpr Vector operator/(const\
    \ Vector& lhs, const T& coef) {\n        return std::move(Vector(lhs) /= coef);\n\
    \    }\n\n    /**\n     * @brief \u7B49\u4FA1\u6F14\u7B97\u5B50\n     *\n    \
    \ * @param lhs\n     * @param rhs\n     * @return bool\n     */\n    [[nodiscard]]\n\
    \    friend constexpr bool operator==(const Vector& lhs, const Vector& rhs) noexcept\
    \ {\n        return lhs.v == rhs.v;\n    }\n\n    /**\n     * @brief \u975E\u7B49\
    \u4FA1\u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n     *\
    \ @return bool\n     */\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Vector& lhs, const Vector& rhs) noexcept {\n        return lhs.v != rhs.v;\n\
    \    }\n\n    /**\n     * @brief \u5C0F\u306A\u308A\u6F14\u7B97\u5B50\n     *\n\
    \     * @param lhs\n     * @param rhs\n     * @return bool\n     */\n    [[nodiscard]]\n\
    \    friend constexpr bool operator<(const Vector& lhs, const Vector& rhs) noexcept\
    \ {\n        return lhs.v < rhs.v;\n    }\n    /**\n     * @brief \u5927\u306A\
    \u308A\u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n     *\
    \ @return bool\n     */\n    [[nodiscard]]\n    friend constexpr bool operator>(const\
    \ Vector& lhs, const Vector& rhs) noexcept {\n        return lhs.v > rhs.v;\n\
    \    }\n    /**\n     * @brief \u5C0F\u306A\u308A\u30A4\u30B3\u30FC\u30EB\u6F14\
    \u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n     * @return bool\n\
    \     */\n    [[nodiscard]]\n    friend constexpr bool operator<=(const Vector&\
    \ lhs, const Vector& rhs) noexcept {\n        return lhs.v <= rhs.v;\n    }\n\
    \    /**\n     * @brief \u5927\u306A\u308A\u30A4\u30B3\u30FC\u30EB\u6F14\u7B97\
    \u5B50\n     *\n     * @param lhs\n     * @param rhs\n     * @return bool\n  \
    \   */\n    [[nodiscard]]\n    friend constexpr bool operator>=(const Vector&\
    \ lhs, const Vector& rhs) noexcept {\n        return lhs.v >= rhs.v;\n    }\n\n\
    \    /**\n     * @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\
    \u306E\u8AAD\u307F\u8FBC\u307F\n     *\n     * @tparam CharT \u5165\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u5165\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n   \
    \  * @param is\n     * @param rhs\n     * @return std::basic_istream<CharT, Traits>&\n\
    \     */\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Vector& rhs) {\n\
    \        for (int i = 0; i < Dim; i++) is >> rhs.v[i];\n        return is;\n \
    \   }\n    /**\n     * @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u3078\
    \u306E\u66F8\u304D\u8FBC\u307F\n     *\n     * @tparam CharT \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u51FA\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n   \
    \  * @param is\n     * @param rhs\n     * @return std::basic_ostream<CharT, Traits>&\n\
    \     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const Vector& rhs)\
    \ {\n        for (int i = 0; i < Dim; i++) {\n            if (i != 0) os << CharT('\
    \ ');\n            os << rhs.v[i];\n        }\n        return os;\n    }\n\n \
    \   /**\n     * @brief \u5185\u7A4D\n     *\n     * @param lhs\n     * @param\
    \ rhs\n     * @return T\n     */\n    friend constexpr T dot(const Vector& lhs,\
    \ const Vector& rhs) noexcept {\n        T ret = 0;\n        for (int i = 0; i\
    \ < Dim; i++) ret += lhs[i] * rhs[i];\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u7D76\u5BFE\u5024\u306E2\u4E57\n     *\n     * @return T\n   \
    \  */\n    constexpr T squared_norm() const noexcept {\n        return dot(*this,\
    \ *this);\n    }\n    /**\n     * @brief \u7D76\u5BFE\u5024\n     *\n     * @return\
    \ double\n     */\n    constexpr double abs() const noexcept {\n        return\
    \ std::sqrt(squared_norm());\n    }\n};\n\n/**\n * @brief \u4E8C\u6B21\u5143\u30D9\
    \u30AF\u30C8\u30EB\u3069\u3046\u3057\u306E\u5916\u7A4D(\u5E73\u884C\u56DB\u8FBA\
    \u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D)\n *\n * @param lhs\n * @param\
    \ rhs\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return T\n */\ntemplate <typename\
    \ T>\nconstexpr T cross(const Vector<T, 2>& lhs, const Vector<T, 2>& rhs) noexcept\
    \ {\n    return lhs[0] * rhs[1] - lhs[1] * rhs[0];\n}\n/**\n * @brief \u4E09\u6B21\
    \u5143\u30D9\u30AF\u30C8\u30EB\u3069\u3046\u3057\u306E\u5916\u7A4D\n *\n * @param\
    \ lhs\n * @param rhs\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return Vector<T,\
    \ 3>\n */\ntemplate <typename T>\nconstexpr Vector<T, 3> cross(const Vector<T,\
    \ 3>& lhs, const Vector<T, 3>& rhs) noexcept {\n    Vector<T, 3> ret;\n    ret[0]\
    \ = lhs[1] * rhs[2] - lhs[2] * rhs[1];\n    ret[1] = lhs[2] * rhs[0] - lhs[0]\
    \ * rhs[2];\n    ret[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];\n    return ret;\n\
    }\n\n/**\n * @brief \u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\n *\n * \u6574\u6570\
    \u578B\u3067\u3082\u4F7F\u3048\u308B\u3002\u5916\u7A4D\u3092\u8A08\u7B97\u3059\
    \u308B\u305F\u3081\u3001\u5EA7\u6A19\u306E\u7D76\u5BFE\u5024\u306E2\u4E57\u306E\
    \u6570\u500D\u304CT\u306B\u53CE\u307E\u308B\u5FC5\u8981\u304C\u3042\u308B\n *\n\
    \ * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param p2\
    \ 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @param q1 2\u672C\u76EE\
    \u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param q2 2\u672C\u76EE\u306E\u7DDA\u5206\
    \u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return bool \u5171\
    \u6709\u70B9\u3092\u6301\u3064\u304B\n */\ntemplate <typename T>\nconstexpr bool\
    \ segments_intersect(const Vector<T, 2>& p1, const Vector<T, 2>& p2, const Vector<T,\
    \ 2>& q1, const Vector<T, 2>& q2) {\n    assert(p1 != p2 && q1 != q2 && \"segments_intersect:\
    \ degenerate segment\");\n    auto sign = [](T x) { return (x > 0) - (x < 0);\
    \ };\n    int q1_section = sign(cross(p2 - p1, q1 - p1));  // \u76F4\u7DDAp1p2\u306B\
    \u5BFE\u3057\u3066q1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n \
    \   int q2_section = sign(cross(p2 - p1, q2 - p1));  // \u76F4\u7DDAp1p2\u306B\
    \u5BFE\u3057\u3066q2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n \
    \   int p1_section = sign(cross(q2 - q1, p1 - q1));  // \u76F4\u7DDAq1q2\u306B\
    \u5BFE\u3057\u3066p1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n \
    \   int p2_section = sign(cross(q2 - q1, p2 - q1));  // \u76F4\u7DDAq1q2\u306B\
    \u5BFE\u3057\u3066p2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n \
    \   if (q1_section == 0 && q2_section == 0) {\n        // 4\u70B9\u304C\u540C\u4E00\
    \u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\n        return dot(q1 - p1,\
    \ q2 - p1) <= 0 || dot(q1 - p2, q2 - p2) <= 0 || dot(p1 - q1, p2 - q1) <= 0;\n\
    \    }\n    return q1_section * q2_section <= 0 && p1_section * p2_section <=\
    \ 0;\n}\n\n/**\n * @brief \u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\u3068\u5171\
    \u6709\u70B9\u306E\u8A08\u7B97\n *\n * \u5171\u6709\u70B9\u306E\u5EA7\u6A19\u306F\
    \u4E00\u822C\u306B\u6574\u6570\u306B\u306A\u3089\u306A\u3044\u305F\u3081\u3001\
    \u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n * \u6574\u6570\u5EA7\u6A19\u3067\
    \u4EA4\u5DEE\u5224\u5B9A\u3060\u3051\u3057\u305F\u3044\u5834\u5408\u306F segments_intersect\
    \ \u3092\u4F7F\u3046\n *\n * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\
    \u70B91\n * @param p2 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @param\
    \ q1 2\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param q2 2\u672C\u76EE\
    \u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\u306E\u578B\n\
    \ * @return std::optional<Vector<T, 2>> \u5171\u6709\u70B9\u306E1\u4F8B (\u5171\
    \u6709\u70B9\u304C\u306A\u3051\u308C\u3070 std::nullopt)\n */\ntemplate <typename\
    \ T>\nconstexpr std::optional<Vector<T, 2>> segment_intersection(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>&\
    \ q2) {\n    static_assert(std::is_floating_point_v<T>, \"segment_intersection:\
    \ T must be a floating point type (use segments_intersect for integers)\");\n\
    \    if (!segments_intersect(p1, p2, q1, q2)) return std::nullopt;\n    if (cross(p2\
    \ - p1, q1 - p1) == 0 && cross(p2 - p1, q2 - p1) == 0) {\n        // 4\u70B9\u304C\
    \u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\n        if (dot(q1\
    \ - p1, q2 - p1) <= 0) return p1;\n        if (dot(q1 - p2, q2 - p2) <= 0) return\
    \ p2;\n        return q1;\n    }\n    T area = cross(p2 - p1, q2 - q1);      \
    \    // 4\u70B9\u3092\u9802\u70B9\u3068\u3059\u308B\u56DB\u89D2\u5F62\u306E\u7B26\
    \u53F7\u4ED8\u304D\u9762\u7A4D\n    T partial_area = cross(q2 - q1, p1 - q1);\
    \  // \u4E09\u89D2\u5F62q1q2p1\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\n   \
    \ return p1 + (p2 - p1) * partial_area / area;\n}\n\n/**\n * @brief 3\u70B9\u306E\
    \u4F4D\u7F6E\u95A2\u4FC2 (counter-clockwise)\n *\n * \u6574\u6570\u578B\u3067\u3082\
    \u4F7F\u3048\u308B\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u3067\u306F\u8AA4\
    \u5DEE\u3092\u8003\u3048\u305A\u306B\u6BD4\u8F03\u3059\u308B\n *\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @return int 1: a\u2192b\u2192c \u304C\u53CD\u6642\
    \u8A08\u56DE\u308A, -1: \u6642\u8A08\u56DE\u308A, 2: c, a, b \u306E\u9806\u306B\
    \u4E00\u76F4\u7DDA\u4E0A, -2: a, b, c \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\
    , 0: c \u304C\u7DDA\u5206 ab \u4E0A\n */\ntemplate <typename T>\nconstexpr int\
    \ ccw(const Vector<T, 2>& a, const Vector<T, 2>& b, const Vector<T, 2>& c) {\n\
    \    Vector<T, 2> u = b - a, v = c - a;\n    T cr = cross(u, v);\n    if (cr >\
    \ 0) return 1;\n    if (cr < 0) return -1;\n    if (dot(u, v) < 0) return 2;\n\
    \    if (u.squared_norm() < v.squared_norm()) return -2;\n    return 0;\n}\n\n\
    /**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u304C\u5E73\u884C\u304B\
    \ (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\nconstexpr bool is_parallel(const Vector<T, 2>& p1, const Vector<T, 2>& p2,\
    \ const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    return cross(p2 - p1,\
    \ q2 - q1) == 0;\n}\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2\
    \ \u304C\u76F4\u4EA4\u3059\u308B\u304B (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\
    \u308B)\n */\ntemplate <typename T>\nconstexpr bool is_orthogonal(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>&\
    \ q2) {\n    return dot(p2 - p1, q2 - q1) == 0;\n}\n\n/**\n * @brief \u70B9 p\
    \ \u304B\u3089\u76F4\u7DDA p1p2 \u306B\u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\
    \u8DB3 (\u5C04\u5F71)\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n\
    \ */\ntemplate <typename T>\nconstexpr Vector<T, 2> projection(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& p) {\n    static_assert(std::is_floating_point_v<T>,\
    \ \"projection: T must be a floating point type\");\n    assert(p1 != p2 && \"\
    projection: degenerate line\");\n    Vector<T, 2> d = p2 - p1;\n    return p1\
    \ + d * (dot(p - p1, d) / d.squared_norm());\n}\n/**\n * @brief \u76F4\u7DDA p1p2\
    \ \u306B\u3064\u3044\u3066\u70B9 p \u3068\u5BFE\u79F0\u306A\u70B9 (\u53CD\u5C04\
    )\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n */\ntemplate <typename\
    \ T>\nconstexpr Vector<T, 2> reflection(const Vector<T, 2>& p1, const Vector<T,\
    \ 2>& p2, const Vector<T, 2>& p) {\n    return projection(p1, p2, p) * T(2) -\
    \ p;\n}\n\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u306E\u4EA4\
    \u70B9\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n * @return std::optional<Vector<T,\
    \ 2>> \u4EA4\u70B9 (\u5E73\u884C\u306A\u3089 std::nullopt)\n */\ntemplate <typename\
    \ T>\nconstexpr std::optional<Vector<T, 2>> line_intersection(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>&\
    \ q2) {\n    static_assert(std::is_floating_point_v<T>, \"line_intersection: T\
    \ must be a floating point type\");\n    Vector<T, 2> d = p2 - p1, e = q2 - q1;\n\
    \    T c = cross(e, d);\n    if (c == 0) return std::nullopt;\n    // p1 + d t\
    \ \u304C\u76F4\u7DDA q1q2 \u4E0A\u306B\u3042\u308B t\n    return p1 + d * (cross(e,\
    \ q1 - p1) / c);\n}\n\n/**\n * @brief \u70B9 p \u3068\u76F4\u7DDA p1p2 \u306E\u8DDD\
    \u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_point_line(const Vector<T, 2>& p1, const Vector<T, 2>& p2,\
    \ const Vector<T, 2>& p) {\n    assert(p1 != p2 && \"distance_point_line: degenerate\
    \ line\");\n    return std::abs(static_cast<double>(cross(p2 - p1, p - p1))) /\
    \ (p2 - p1).abs();\n}\n/**\n * @brief \u70B9 p \u3068\u7DDA\u5206 p1p2 \u306E\u8DDD\
    \u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_point_segment(const Vector<T, 2>& p1, const Vector<T, 2>&\
    \ p2, const Vector<T, 2>& p) {\n    if (p1 == p2) return (p - p1).abs();\n   \
    \ // \u5782\u7DDA\u306E\u8DB3\u304C\u7DDA\u5206\u306E\u5916\u306A\u3089\u3001\u8FD1\
    \u3044\u65B9\u306E\u7AEF\u70B9\u3068\u306E\u8DDD\u96E2\n    if (dot(p2 - p1, p\
    \ - p1) < 0) return (p - p1).abs();\n    if (dot(p1 - p2, p - p2) < 0) return\
    \ (p - p2).abs();\n    return distance_point_line(p1, p2, p);\n}\n/**\n * @brief\
    \ \u7DDA\u5206 p1p2 \u3068\u7DDA\u5206 q1q2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\
    \u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename T>\ndouble distance_segments(const\
    \ Vector<T, 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T,\
    \ 2>& q2) {\n    if (p1 != p2 && q1 != q2 && segments_intersect(p1, p2, q1, q2))\
    \ return 0;\n    return std::min({distance_point_segment(p1, p2, q1), distance_point_segment(p1,\
    \ p2, q2),\n                     distance_point_segment(q1, q2, p1), distance_point_segment(q1,\
    \ q2, p2)});\n}\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\
    \u9762\u7A4D\u306E2\u500D\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param\
    \ polygon \u9802\u70B9\u306E\u5EA7\u6A19\n * @return T \u9762\u7A4D\u306E2\u500D\
    (\u53CD\u6642\u8A08\u56DE\u308A\u306A\u3089\u6B63\u3001\u6642\u8A08\u56DE\u308A\
    \u306A\u3089\u8CA0)\n */\ntemplate <typename T>\nT polygon_area_doubled(const\
    \ std::vector<Vector<T, 2>>& polygon) {\n    T ret = 0;\n    for (int i = 0; i\
    \ < static_cast<int>(polygon.size()); i++) {\n        int j = i + 1;\n       \
    \ if (j == static_cast<int>(polygon.size())) j = 0;\n        ret += cross(polygon[i],\
    \ polygon[j]);\n    }\n    return ret;\n}\n\n/**\n * @brief \u591A\u89D2\u5F62\
    \u306E\u9762\u7A4D\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param polygon\
    \ \u9802\u70B9\u306E\u5EA7\u6A19(\u9806\u756A\u3001\u53CD\u6642\u8A08\u56DE\u308A\
    \u304B\u6642\u8A08\u56DE\u308A\u304B\u306F\u554F\u308F\u306A\u3044)\n * @return\
    \ double \u9762\u7A4D\n */\ntemplate <typename T>\ndouble polygon_area(const std::vector<Vector<T,\
    \ 2>>& polygon) {\n    return std::abs(polygon_area_doubled(polygon)) / 2.;\n\
    }\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u51F8\u6027\u5224\u5B9A\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19\
    (\u53CD\u6642\u8A08\u56DE\u308A)\n * @return true \u51F8\n * @return false \u51F9\
    \n */\ntemplate <typename T>\nbool polygon_is_convex(const std::vector<Vector<T,\
    \ 2>>& polygon) {\n    int n = polygon.size();\n    for (int i = 0; i < n; i++)\
    \ {\n        int j = i + 1;\n        if (j == n) j = 0;\n        int k = j + 1;\n\
    \        if (k == n) k = 0;\n        if (cross(polygon[j] - polygon[i], polygon[k]\
    \ - polygon[j]) < 0) return false;\n    }\n    return true;\n}\n\n/**\n * @brief\
    \ \u70B9\u306E\u591A\u89D2\u5F62\u5185\u5305\u542B\u5224\u5B9A\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19\
    (\u53CD\u6642\u8A08\u56DE\u308A)\n * @param p \u70B9\u306E\u5EA7\u6A19\n * @return\
    \ int 0: \u5916\u90E8, 1: \u8FBA\u4E0A, 2: \u5185\u90E8\n */\ntemplate <typename\
    \ T>\nint polygon_contains(const std::vector<Vector<T, 2>>& polygon, const Vector<T,\
    \ 2>& p) {\n    bool in = false;\n    for (int i = 0; i < static_cast<int>(polygon.size());\
    \ i++) {\n        int j = i + 1;\n        if (j == static_cast<int>(polygon.size()))\
    \ j = 0;\n        Vector<T> v1 = polygon[i] - p, v2 = polygon[j] - p;\n      \
    \  if (v1[1] > v2[1]) std::swap(v1, v2);\n        T c = cross(v1, v2);\n     \
    \   if (v1[1] <= 0 && v2[1] > 0 && c < 0) in = !in;\n        if (c == 0 && dot(v1,\
    \ v2) <= 0) return 1;\n    }\n    return in ? 2 : 0;\n}\n\n/**\n * @brief \u591A\
    \u89D2\u5F62\u306E\u534A\u51F8\u5305\n * \u4E0E\u3048\u3089\u308C\u305F\u9802\u70B9\
    \u30EA\u30B9\u30C8\u306E\u9806\u756A\u3092\u4FDD\u3063\u3066\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B\u51F8\u5305\u3092\u69CB\u6210\u3059\u308B\n * x\u306E\u6607\
    \u9806\u306B\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u308C\u3070\u4E0B\u51F8\
    \u5305\u3001x\u306E\u964D\u9806\u306B\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\
    \u308C\u3070\u4E0A\u51F8\u5305\u304C\u5F97\u3089\u308C\u308B\n *\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\u30B9\u30C8\n\
    \ * @param include_straight \u5185\u89D2\u304C180\u5EA6\u306E\u9802\u70B9\u3092\
    \u542B\u3080\u304B\u3069\u3046\u304B\n * @return std::vector<Vector<T, 2>> \u534A\
    \u51F8\u5305\u306E\u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\u56DE\u308A\
    )\n */\ntemplate <typename T>\nstd::vector<Vector<T, 2>> select_convex(const std::vector<Vector<T,\
    \ 2>>& points, bool include_straight = false) {\n    std::vector<Vector<T, 2>>\
    \ ret;\n    for (auto& p : points) {\n        while (static_cast<int>(ret.size())\
    \ >= 2) {\n            T c = cross(ret.back() - ret[static_cast<int>(ret.size())\
    \ - 2], p - ret.back());\n            if (c > 0 || (c == 0 && include_straight))\
    \ break;\n            ret.pop_back();\n        }\n        ret.push_back(p);\n\
    \    }\n    return ret;\n}\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u51F8\u5305\
    \n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\
    \u30B9\u30C8\n * @param include_straight \u5185\u89D2\u304C180\u5EA6\u306E\u9802\
    \u70B9\u3092\u542B\u3080\u304B\u3069\u3046\u304B\n * @return std::vector<Vector<T,\
    \ 2>> \u51F8\u5305\u306E\u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\u56DE\
    \u308A)\n */\ntemplate <typename T>\nstd::vector<Vector<T, 2>> convex_hull(const\
    \ std::vector<Vector<T, 2>>& _points, bool include_straight = false) {\n    std::vector<Vector<T,\
    \ 2>> points = _points;\n    std::sort(points.begin(), points.end());\n    points.erase(std::unique(points.begin(),\
    \ points.end()), points.end());\n    std::vector<Vector<T, 2>> ret = select_convex(points,\
    \ include_straight);\n    std::reverse(points.begin(), points.end());\n    std::vector<Vector<T,\
    \ 2>> tmp = select_convex(points, include_straight);\n    // \u5168\u70B9\u304C\
    \u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\u4E0B\u5074\u3068\
    \u4E0A\u5074\u304C\u540C\u3058\u70B9\u5217\u306B\u306A\u308B\u306E\u3067\u7247\
    \u65B9\u3060\u3051\u4F7F\u3046\n    if (ret.size() == points.size() && tmp.size()\
    \ == points.size()) return ret;\n    for (int i = 1; i < static_cast<int>(tmp.size())\
    \ - 1; i++) ret.push_back(tmp[i]);\n    return ret;\n}\n\n/**\n * @brief closest_point_pair_squared\
    \ \u306E\u623B\u308A\u5024\n */\ntemplate <typename T>\nstruct ClosestPairSquared\
    \ {\n    T squared_dist;  //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E\
    2\u4E57\n    long long i, j;  //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u6DFB\u5B57\n\
    };\n/**\n * @brief closest_point_pair \u306E\u623B\u308A\u5024\n */\nstruct ClosestPair\
    \ {\n    double dist;     //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\n  \
    \  long long i, j;  //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u6DFB\u5B57\n};\n\n/**\n\
    \ * @brief \u6700\u8FD1\u70B9\u5BFE\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\
    \n * @param points \u9802\u70B9\u30EA\u30B9\u30C8\n * @return ClosestPairSquared<T>\
    \ \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E2\u4E57\u3068\u6DFB\u5B57\n\
    \ */\ntemplate <typename T>\nClosestPairSquared<T> closest_point_pair_squared(const\
    \ std::vector<Vector<T, 2>>& points) {\n    std::vector<int> sorted_idx(points.size());\n\
    \    std::iota(sorted_idx.begin(), sorted_idx.end(), 0);\n    std::sort(sorted_idx.begin(),\
    \ sorted_idx.end(), [&](int i, int j) {\n        return points[i][0] < points[j][0];\n\
    \    });\n    std::vector<int> left(1, 0);                                   \
    \     // \u5DE6\u7AEF\n    std::vector<int> right(1, points.size());         \
    \                  // \u53F3\u7AEF\n    std::vector<int> mid(1, points.size()\
    \ / 2);                         // \u4E2D\u592E\n    std::vector<int> par(1, -1);\
    \                                        // \u89AA\n    std::vector<T> min_dist_squared(1,\
    \ std::numeric_limits<T>::max());  // \u6700\u5C0F\u8DDD\u96E2\u306E2\u4E57\n\
    \    std::vector<std::pair<int, int>> min_dist_pair(1, {-1, -1});        // \u6700\
    \u5C0F\u8DDD\u96E2\u306E\u70B9\u5BFE\n    std::stack<int> stk;\n    stk.push(~0);\n\
    \    stk.push(0);\n    while (!stk.empty()) {\n        int u = stk.top();\n  \
    \      stk.pop();\n        if (u >= 0) {\n            // \u884C\u304D\u304C\u3051\
    \n            if (left[u] + 1 < mid[u]) {\n                int v = left.size();\n\
    \                left.push_back(left[u]);\n                right.push_back(mid[u]);\n\
    \                mid.push_back((left[u] + mid[u]) / 2);\n                par.push_back(u);\n\
    \                min_dist_squared.push_back(std::numeric_limits<T>::max());\n\
    \                min_dist_pair.push_back({-1, -1});\n                stk.push(~v);\n\
    \                stk.push(v);\n            }\n            if (mid[u] + 1 < right[u])\
    \ {\n                int v = left.size();\n                left.push_back(mid[u]);\n\
    \                right.push_back(right[u]);\n                mid.push_back((mid[u]\
    \ + right[u]) / 2);\n                par.push_back(u);\n                min_dist_squared.push_back(std::numeric_limits<T>::max());\n\
    \                min_dist_pair.push_back({-1, -1});\n                stk.push(~v);\n\
    \                stk.push(v);\n            }\n        } else {\n            //\
    \ \u5E30\u308A\u304C\u3051\n            u = ~u;\n            std::vector<int>\
    \ cand;\n            for (int i = left[u]; i < right[u]; i++) {\n            \
    \    T dx = points[sorted_idx[i]][0] - points[sorted_idx[mid[u]]][0];\n      \
    \          if (dx * dx < min_dist_squared[u]) cand.push_back(i);\n           \
    \ }\n            std::sort(cand.begin(), cand.end(), [&](int i, int j) {\n   \
    \             return points[sorted_idx[i]][1] < points[sorted_idx[j]][1];\n  \
    \          });\n            for (int i = 0; i < static_cast<int>(cand.size());\
    \ i++) {\n                for (int j = i + 1; j < static_cast<int>(cand.size());\
    \ j++) {\n                    T dx = points[sorted_idx[cand[j]]][0] - points[sorted_idx[cand[i]]][0];\n\
    \                    T dy = points[sorted_idx[cand[j]]][1] - points[sorted_idx[cand[i]]][1];\n\
    \                    if (dy * dy >= min_dist_squared[u]) break;\n            \
    \        T d = dx * dx + dy * dy;\n                    if (d < min_dist_squared[u])\
    \ {\n                        min_dist_squared[u] = d;\n                      \
    \  min_dist_pair[u] = {sorted_idx[cand[i]], sorted_idx[cand[j]]};\n          \
    \          }\n                }\n            }\n            if (par[u] != -1 &&\
    \ min_dist_squared[u] < min_dist_squared[par[u]]) {\n                min_dist_squared[par[u]]\
    \ = min_dist_squared[u];\n                min_dist_pair[par[u]] = min_dist_pair[u];\n\
    \            }\n        }\n    }\n    return {min_dist_squared[0], min_dist_pair[0].first,\
    \ min_dist_pair[0].second};\n}\n\n/**\n * @brief \u6700\u8FD1\u70B9\u5BFE\n *\n\
    \ * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\u30B9\
    \u30C8\n * @return ClosestPair \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u3068\
    \u6DFB\u5B57\n */\ntemplate <typename T>\nClosestPair closest_point_pair(const\
    \ std::vector<Vector<T, 2>>& points) {\n    auto [d2, i, j] = closest_point_pair_squared(points);\n\
    \    return {std::sqrt(static_cast<double>(d2)), i, j};\n}\n\n/**\n * @brief farthest_point_pair_squared\
    \ \u306E\u623B\u308A\u5024\n */\ntemplate <typename T>\nstruct FarthestPairSquared\
    \ {\n    T squared_dist;  //!< \u6700\u9060\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E\
    2\u4E57\n    long long i, j;  //!< \u6700\u9060\u70B9\u5BFE\u306E\u6DFB\u5B57\n\
    };\n/**\n * @brief farthest_point_pair \u306E\u623B\u308A\u5024\n */\nstruct FarthestPair\
    \ {\n    double dist;     //!< \u6700\u9060\u70B9\u5BFE\u306E\u8DDD\u96E2\n  \
    \  long long i, j;  //!< \u6700\u9060\u70B9\u5BFE\u306E\u6DFB\u5B57\n};\n\n/**\n\
    \ * @brief \u6700\u9060\u70B9\u5BFE (\u51F8\u5305\u3092\u4F5C\u308A\u3001\u56DE\
    \u8EE2\u30AD\u30E3\u30EA\u30D1\u30FC\u6CD5\u3067\u5BFE\u8E60\u70B9\u306E\u7D44\
    \u3092\u8ABF\u3079\u308B) O(n log n)\n *\n * \u6574\u6570\u578B\u3067\u3082\u4F7F\
    \u3048\u308B\u3002\u5EA7\u6A19\u306E\u5DEE\u306E2\u4E57\u306E\u548C\u306E2\u500D\
    \u304C T \u306B\u53CE\u307E\u308B\u5FC5\u8981\u304C\u3042\u308B\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\u30B9\u30C8 (2\u500B\
    \u4EE5\u4E0A)\n * @return FarthestPairSquared<T> \u6700\u9060\u70B9\u5BFE\u306E\
    \u8DDD\u96E2\u306E2\u4E57\u3068\u6DFB\u5B57 (i != j)\n */\ntemplate <typename\
    \ T>\nFarthestPairSquared<T> farthest_point_pair_squared(const std::vector<Vector<T,\
    \ 2>>& points) {\n    const int n = static_cast<int>(points.size());\n    assert(n\
    \ >= 2);\n    // \u51F8\u5305\u306E\u9802\u70B9\u3092\u3001\u3082\u3068\u306E\u6DFB\
    \u5B57\u306B\u623B\u305B\u308B\u3088\u3046\u306B\u3057\u3066\u304A\u304F\n   \
    \ std::vector<std::pair<Vector<T, 2>, int>> sorted(n);\n    for (int i = 0; i\
    \ < n; i++) sorted[i] = {points[i], i};\n    std::sort(sorted.begin(), sorted.end());\n\
    \    auto index_of = [&](const Vector<T, 2>& p) {\n        return std::lower_bound(sorted.begin(),\
    \ sorted.end(), std::make_pair(p, -1))->second;\n    };\n    std::vector<Vector<T,\
    \ 2>> hull = convex_hull(points);\n    const int k = static_cast<int>(hull.size());\n\
    \    if (k == 1) return {T(0), sorted[0].second, sorted[1].second};  // \u3059\
    \u3079\u3066\u540C\u3058\u70B9\n    FarthestPairSquared<T> res{T(0), -1, -1};\n\
    \    auto update = [&](int a, int b) {\n        T d = (hull[a] - hull[b]).squared_norm();\n\
    \        if (res.i == -1 || d > res.squared_dist) res = {d, a, b};\n    };\n \
    \   if (k == 2) {\n        update(0, 1);\n    } else {\n        // \u8FBA i\u2192\
    i+1 \u306B\u5BFE\u3057\u3066\u3001\u6700\u3082\u9060\u3044\u9802\u70B9 j \u3092\
    \u53CD\u6642\u8A08\u56DE\u308A\u306B\u9032\u3081\u3066\u3044\u304F\n        int\
    \ j = 1;\n        for (int i = 0; i < k; i++) {\n            int ni = i + 1 ==\
    \ k ? 0 : i + 1;\n            while (true) {\n                int nj = j + 1 ==\
    \ k ? 0 : j + 1;\n                if (cross(hull[ni] - hull[i], hull[nj] - hull[j])\
    \ > 0)\n                    j = nj;\n                else\n                  \
    \  break;\n            }\n            update(i, j);\n            update(ni, j);\n\
    \        }\n    }\n    return {res.squared_dist, index_of(hull[res.i]), index_of(hull[res.j])};\n\
    }\n\n/**\n * @brief \u6700\u9060\u70B9\u5BFE\n *\n * @tparam T \u5EA7\u6A19\u306E\
    \u578B\n * @param points \u9802\u70B9\u30EA\u30B9\u30C8 (2\u500B\u4EE5\u4E0A)\n\
    \ * @return FarthestPair \u6700\u9060\u70B9\u5BFE\u306E\u8DDD\u96E2\u3068\u6DFB\
    \u5B57\n */\ntemplate <typename T>\nFarthestPair farthest_point_pair(const std::vector<Vector<T,\
    \ 2>>& points) {\n    auto [d2, i, j] = farthest_point_pair_squared(points);\n\
    \    return {std::sqrt(static_cast<double>(d2)), i, j};\n}\n\n/**\n * @brief \u51F8\
    \u591A\u89D2\u5F62\u3092\u76F4\u7DDA p1p2 \u3067\u5207\u308A\u3001\u76F4\u7DDA\
    \u306E\u5DE6\u5074 (p1 \u304B\u3089 p2 \u3092\u898B\u3066\u5DE6) \u306E\u90E8\u5206\
    \u3092\u8FD4\u3059\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n *\n\
    \ * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u51F8\u591A\u89D2\u5F62\
    \u306E\u9802\u70B9\u306E\u5EA7\u6A19 (\u53CD\u6642\u8A08\u56DE\u308A)\n * @return\
    \ std::vector<Vector<T, 2>> \u5DE6\u5074\u306E\u51F8\u591A\u89D2\u5F62\u306E\u9802\
    \u70B9 (\u53CD\u6642\u8A08\u56DE\u308A)\u3002\u76F4\u7DDA\u4E0A\u306E\u9802\u70B9\
    \u3082\u542B\u3080\u3002\u5DE6\u5074\u306B\u4F55\u3082\u306A\u3051\u308C\u3070\
    \u7A7A\n */\ntemplate <typename T>\nstd::vector<Vector<T, 2>> convex_cut(const\
    \ std::vector<Vector<T, 2>>& polygon, const Vector<T, 2>& p1, const Vector<T,\
    \ 2>& p2) {\n    static_assert(std::is_floating_point_v<T>, \"convex_cut: T must\
    \ be a floating point type\");\n    std::vector<Vector<T, 2>> res;\n    const\
    \ int n = static_cast<int>(polygon.size());\n    for (int i = 0; i < n; i++) {\n\
    \        const Vector<T, 2>&a = polygon[i], &b = polygon[i + 1 == n ? 0 : i +\
    \ 1];\n        T ca = cross(p2 - p1, a - p1), cb = cross(p2 - p1, b - p1);\n \
    \       if (ca >= 0) res.push_back(a);\n        // \u8FBA ab \u304C\u76F4\u7DDA\
    \u3092\u307E\u305F\u3050\u306A\u3089\u3001\u4EA4\u70B9\u3092\u5165\u308C\u308B\
    \n        if ((ca > 0 && cb < 0) || (ca < 0 && cb > 0)) res.push_back(a + (b -\
    \ a) * (ca / (ca - cb)));\n    }\n    return res;\n}\n/**\n * @deprecated closest_point_pair_squared\
    \ \u3092\u4F7F\u3046\u3053\u3068(\u7DB4\u308A\u306E\u8AA4\u308A\u3092\u76F4\u3057\
    \u3066\u6539\u540D\u3057\u305F)\n */\ntemplate <typename T>\n[[deprecated(\"use\
    \ closest_point_pair_squared\")]] ClosestPairSquared<T> closest_point_pair_squred(const\
    \ std::vector<Vector<T, 2>>& points) {\n    return closest_point_pair_squared(points);\n\
    }\n#line 16 \"src/geometry/axis-parallel-segments.hpp\"\n\n/**\n * @brief \u6C34\
    \u5E73\u304B\u5782\u76F4\u306A\u7DDA\u5206\u3060\u3051\u304C\u3042\u308B\u3068\
    \u304D\u3001\u6C34\u5E73\u306A\u7DDA\u5206\u3068\u5782\u76F4\u306A\u7DDA\u5206\
    \u304C\u5171\u6709\u70B9\u3092\u6301\u3064\u7D44\u306E\u500B\u6570 (\u8D70\u67FB\
    \u7DDA) O(n log n)\n *\n * y \u306E\u5C0F\u3055\u3044\u9806\u306B\u8D70\u67FB\u3057\
    \u3001y \u65B9\u5411\u306B\u4ECA\u307E\u305F\u3044\u3067\u3044\u308B\u5782\u76F4\
    \u306A\u7DDA\u5206\u306E x \u3092 Fenwick \u6728\u3067\u6570\u3048\u308B\n * \u7AEF\
    \u70B9\u3067\u63A5\u3059\u308B\u3082\u306E\u3082\u6570\u3048\u308B\u3002\u5E73\
    \u884C\u306A\u7DDA\u5206\u3069\u3046\u3057\u306E\u5171\u6709\u70B9\u306F\u6570\
    \u3048\u306A\u3044\u3002\u9577\u3055 0 \u306E\u7DDA\u5206\u306F\u5782\u76F4\u306A\
    \u7DDA\u5206\u3068\u3057\u3066\u6271\u3046\n * @param segments \u7DDA\u5206\u306E\
    \u7AEF\u70B9\u306E\u7D44 (\u5404\u7DDA\u5206\u306F x \u5EA7\u6A19\u304B y \u5EA7\
    \u6A19\u304C\u7B49\u3057\u3044\u3053\u3068)\n * @return long long \u5171\u6709\
    \u70B9\u3092\u6301\u3064 (\u6C34\u5E73\u306A\u7DDA\u5206, \u5782\u76F4\u306A\u7DDA\
    \u5206) \u306E\u7D44\u306E\u500B\u6570\n */\ntemplate <typename T>\nlong long\
    \ count_axis_parallel_intersections(const std::vector<std::pair<Vector<T, 2>,\
    \ Vector<T, 2>>>& segments) {\n    std::vector<T> xs;\n    // (y, \u7A2E\u985E\
    , x1, x2)\u3002\u7A2E\u985E\u306F 0: \u5782\u76F4\u306A\u7DDA\u5206\u306E\u59CB\
    \u307E\u308A\u30011: \u6C34\u5E73\u306A\u7DDA\u5206\u30012: \u5782\u76F4\u306A\
    \u7DDA\u5206\u306E\u7D42\u308F\u308A (\u540C\u3058 y \u3067\u306F\u3053\u306E\u9806\
    \u306B\u51E6\u7406\u3059\u308B)\n    std::vector<std::tuple<T, int, T, T>> events;\n\
    \    for (const auto& [p, q] : segments) {\n        if (p[0] == q[0]) {\n    \
    \        T y1 = std::min(p[1], q[1]), y2 = std::max(p[1], q[1]);\n           \
    \ events.emplace_back(y1, 0, p[0], p[0]);\n            events.emplace_back(y2,\
    \ 2, p[0], p[0]);\n            xs.push_back(p[0]);\n        } else {\n       \
    \     assert(p[1] == q[1] && \"count_axis_parallel_intersections: segment is not\
    \ axis-parallel\");\n            events.emplace_back(p[1], 1, std::min(p[0], q[0]),\
    \ std::max(p[0], q[0]));\n        }\n    }\n    std::sort(xs.begin(), xs.end());\n\
    \    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n    auto index =\
    \ [&](T x) { return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin(); };\n\
    \    std::sort(events.begin(), events.end());\n    FenwickTree<group::Sum<long\
    \ long>> ft(xs.size());\n    long long res = 0;\n    for (const auto& [y, type,\
    \ x1, x2] : events) {\n        if (type == 0) {\n            ft.apply(index(x1),\
    \ 1);\n        } else if (type == 2) {\n            ft.apply(index(x1), -1);\n\
    \        } else {\n            // x1 <= x <= x2 \u306B\u3042\u308B\u5782\u76F4\
    \u306A\u7DDA\u5206\u306E\u500B\u6570\n            res += ft.prod(index(x1), std::upper_bound(xs.begin(),\
    \ xs.end(), x2) - xs.begin());\n        }\n    }\n    return res;\n}\n#line 8\
    \ \"test/aoj/cgl/cgl-6-a.test.cpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n;\n    std::cin >> n;\n    std::vector<std::pair<Vector<long\
    \ long>, Vector<long long>>> segs(n);\n    for (auto& [p, q] : segs) std::cin\
    \ >> p >> q;\n    std::cout << count_axis_parallel_intersections(segs) << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"\
    ../../../src/geometry/axis-parallel-segments.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n;\n    std::cin >> n;\n    std::vector<std::pair<Vector<long\
    \ long>, Vector<long long>>> segs(n);\n    for (auto& [p, q] : segs) std::cin\
    \ >> p >> q;\n    std::cout << count_axis_parallel_intersections(segs) << '\\\
    n';\n}\n"
  dependsOn:
  - src/geometry/axis-parallel-segments.hpp
  - src/algebra/group.hpp
  - src/algebra/monoid.hpp
  - src/data_structures/fenwick-tree.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/aoj/cgl/cgl-6-a.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 05:43:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/cgl/cgl-6-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/cgl/cgl-6-a.test.cpp
- /verify/test/aoj/cgl/cgl-6-a.test.cpp.html
title: test/aoj/cgl/cgl-6-a.test.cpp
---
