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
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/heavy-light-decomposition.hpp
    title: "HL \u5206\u89E3 (Heavy-Light Decomposition)"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree.hpp
    title: "\u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
  bundledCode: "#line 1 \"test/aoj/grl/grl-5-d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n// HL \u5206\u89E3\u306E\u8FBA\u306E\u30D1\u30B9\u3068 Fenwick Tree \u3067\
    \u3001\u8FBA\u3078\u306E\u52A0\u7B97\u3068\u6839\u304B\u3089\u306E\u30D1\u30B9\
    \u306E\u548C\u3092\u6C42\u3081\u308B\n// \u8FBA (parent(v), v) \u306E\u5024\u3092\
    \ index(v) \u756A\u76EE\u306B\u7F6E\u304F\n\n#include <algorithm>\n#include <iostream>\n\
    \n#line 2 \"src/algebra/group.hpp\"\n\n/**\n * @file group.hpp\n * @brief \u7FA4\
    \u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\
    \ \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\
    \u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - S inv(const S& a):\
    \ \u9006\u5143\n */\n\n#include <array>\n#include <cstddef>\n#include <utility>\n\
    \n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\
    \u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\
    \n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S& a, const S& b): \u7A4D\
    \ (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n * op, e \u306F static\
    \ \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\
    \u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\n#line 17 \"src/algebra/monoid.hpp\"\
    \n#include <istream>\n#include <limits>\n#include <numeric>\n#include <optional>\n\
    #include <ostream>\n#include <type_traits>\n#line 24 \"src/algebra/monoid.hpp\"\
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
    \ f.ub << CharT(' ') << f.add;\n    }\n};\n\nnamespace internal_monoid {\n// MinWith\u30FB\
    MaxWith \u306E\u5358\u4F4D\u5143\u306E\u4F4D\u7F6E\u3002U \u304C bool \u4EE5\u5916\
    \u306E\u6574\u6570\u578B\u306A\u3089 -1 (\u5B9F\u5728\u306E\u4F4D\u7F6E\u3068\u533A\
    \u5225\u3067\u304D\u308B)\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 U{}\n\
    template <typename U>\nconstexpr bool with_has_e_position = std::is_integral_v<U>\
    \ && !std::is_same_v<U, bool>;\ntemplate <typename U>\nconstexpr U with_e_position()\
    \ {\n    if constexpr (with_has_e_position<U>)\n        return static_cast<U>(-1);\n\
    \    else\n        return U{};\n}\n// U \u304C bool \u4EE5\u5916\u306E\u6574\u6570\
    \u578B\u3067\u3001\u4F4D\u7F6E\u304C -1 \u306A\u3089\u5358\u4F4D\u5143\ntemplate\
    \ <typename U>\nconstexpr bool with_is_e(const U& u) {\n    if constexpr (with_has_e_position<U>)\n\
    \        return u == static_cast<U>(-1);\n    else\n        return false;\n}\n\
    }  // namespace internal_monoid\n\nnamespace monoid {\n\n/**\n * @brief \u548C\
    \n */\ntemplate <typename T>\nstruct Sum {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return a + b; }\n    static constexpr S e() {\
    \ return S(0); }\n};\n\n/**\n * @brief \u7A4D\n */\ntemplate <typename T>\nstruct\
    \ Prod {\n    using S = T;\n    static constexpr S op(const S& a, const S& b)\
    \ { return a * b; }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n\
    \ * @brief \u6700\u5927\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\
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
    \u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n * U \u304C\u6574\u6570\
    \u578B\u306A\u3089\u5358\u4F4D\u5143 (\u7A7A\u533A\u9593) \u306E\u4F4D\u7F6E\u306F\
    \ -1 \u3067\u3001\u5024\u304C\u578B\u306E\u6700\u5927\u5024\u306E\u8981\u7D20\u304C\
    \u3042\u3063\u3066\u3082\u5358\u4F4D\u5143\u3068\u3057\u3066\u50CD\u304F\n * U\
    \ \u304C\u6574\u6570\u578B\u3067\u306A\u3051\u308C\u3070\u5358\u4F4D\u5143\u306F\
    \ {\u578B\u306E\u6700\u5927\u5024, U{}} \u3067\u3001\u5024\u304C\u578B\u306E\u6700\
    \u5927\u5024\u306E\u8981\u7D20\u306F\u306A\u3044\u3053\u3068\n *\n * @tparam T\
    \ \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\
    \u308B\u5024\u306E\u578B (\u6574\u6570\u578B\u306A\u3089 -1 \u306F\u4F7F\u308F\
    \u306A\u3044\u3053\u3068)\n */\ntemplate <typename T, typename U = long long>\n\
    struct MinWith {\n    using S = std::pair<T, U>;\n    static constexpr S op(const\
    \ S& a, const S& b) {\n        if (internal_monoid::with_is_e(a.second)) return\
    \ b;\n        if (internal_monoid::with_is_e(b.second)) return a;\n        return\
    \ b.first < a.first ? b : a;\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ internal_monoid::with_e_position<U>()}; }\n};\n\n/**\n * @brief \u6700\u5927\
    \u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\
    \u3092\u512A\u5148\n * U \u304C\u6574\u6570\u578B\u306A\u3089\u5358\u4F4D\u5143\
    \ (\u7A7A\u533A\u9593) \u306E\u4F4D\u7F6E\u306F -1 \u3067\u3001\u5024\u304C\u578B\
    \u306E\u6700\u5C0F\u5024\u306E\u8981\u7D20\u304C\u3042\u3063\u3066\u3082\u5358\
    \u4F4D\u5143\u3068\u3057\u3066\u50CD\u304F\n * U \u304C\u6574\u6570\u578B\u3067\
    \u306A\u3051\u308C\u3070\u5358\u4F4D\u5143\u306F {\u578B\u306E\u6700\u5C0F\u5024\
    , U{}} \u3067\u3001\u5024\u304C\u578B\u306E\u6700\u5C0F\u5024\u306E\u8981\u7D20\
    \u306F\u306A\u3044\u3053\u3068\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam\
    \ U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B (\u6574\
    \u6570\u578B\u306A\u3089 -1 \u306F\u4F7F\u308F\u306A\u3044\u3053\u3068)\n */\n\
    template <typename T, typename U = long long>\nstruct MaxWith {\n    using S =\
    \ std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n    \
    \    if (internal_monoid::with_is_e(a.second)) return b;\n        if (internal_monoid::with_is_e(b.second))\
    \ return a;\n        return a.first < b.first ? b : a;\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), internal_monoid::with_e_position<U>()};\
    \ }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\n *\n\
    \ * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\n\
    template <typename T, typename U = long long>\nstruct MinCount {\n    using S\
    \ = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n  \
    \      if (a.first < b.first) return a;\n        if (b.first < a.first) return\
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
    \u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\u306E\u6700\
    \u5C0F\u5024\u30FB\u6700\u5927\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\
    \u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\
    \u7A7A\u306E\u533A\u9593 {0, 0, 0}\n */\ntemplate <typename T = long long>\nstruct\
    \ PrefixSumMinMax {\n    struct S {\n        T sum;  // \u533A\u9593\u306E\u548C\
    \n        T min;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5C0F\
    \u5024 (0 \u4EE5\u4E0B)\n        T max;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\
    \u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        constexpr S() : sum(0),\
    \ min(0), max(0) {}\n        constexpr S(const T& x) : sum(x), min(T(0) < x ?\
    \ T(0) : x), max(x < T(0) ? T(0) : x) {}\n        constexpr S(const T& sum, const\
    \ T& min, const T& max) : sum(sum), min(min), max(max) {}\n        friend constexpr\
    \ bool operator==(const S& a, const S& b) { return a.sum == b.sum && a.min ==\
    \ b.min && a.max == b.max; }\n        friend constexpr bool operator!=(const S&\
    \ a, const S& b) { return !(a == b); }\n    };\n    static constexpr S op(const\
    \ S& a, const S& b) {\n        return S(a.sum + b.sum, std::min(a.min, a.sum +\
    \ b.min), std::max(a.max, a.sum + b.max));\n    }\n    static constexpr S e()\
    \ { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3068\u3001\u7A7A\
    \u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024\n * S(x) \u3067\
    \u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\
    \u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate <typename\
    \ T>\nstruct SuffixSumMax {\n    struct S {\n        T sum;  // \u533A\u9593\u306E\
    \u548C\n        T max;  // \u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\
    \u5927\u5024 (0 \u4EE5\u4E0A)\n        constexpr S() : sum(0), max(0) {}\n   \
    \     constexpr S(const T& x) : sum(x), max(x < T(0) ? T(0) : x) {}\n        constexpr\
    \ S(const T& sum, const T& max) : sum(sum), max(max) {}\n        friend constexpr\
    \ bool operator==(const S& a, const S& b) { return a.sum == b.sum && a.max ==\
    \ b.max; }\n        friend constexpr bool operator!=(const S& a, const S& b) {\
    \ return !(a == b); }\n    };\n    static constexpr S op(const S& a, const S&\
    \ b) { return S(a.sum + b.sum, std::max(b.max, a.max + b.sum)); }\n    static\
    \ constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\
    \u3068\u3001\u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\u5C0F\u5024\
    \n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\
    \u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0}\n */\n\
    template <typename T>\nstruct SuffixSumMin {\n    struct S {\n        T sum; \
    \ // \u533A\u9593\u306E\u548C\n        T min;  // \u7A7A\u3092\u542B\u3080 suffix\
    \ \u306E\u548C\u306E\u6700\u5C0F\u5024 (0 \u4EE5\u4E0B)\n        constexpr S()\
    \ : sum(0), min(0) {}\n        constexpr S(const T& x) : sum(x), min(T(0) < x\
    \ ? T(0) : x) {}\n        constexpr S(const T& sum, const T& min) : sum(sum),\
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
    \ typename Inv>\nGroup(Op, T, Inv) -> Group<T, Op, Inv>;\n#line 2 \"src/data_structures/fenwick-tree.hpp\"\
    \n\n/**\n * @file fenwick-tree.hpp\n * @brief Fenwick Tree (Binary Indexed Tree)\n\
    \ */\n\n#include <cassert>\n#include <initializer_list>\n#line 12 \"src/data_structures/fenwick-tree.hpp\"\
    \n#include <vector>\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include\
    \ <functional>\n#include <iterator>\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\
    \n\n#if __cplusplus >= 202002L\n#include <ranges>\n#endif\n\nnamespace internal_traits\
    \ {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n\n// \u30B5\u30A4\u30BA\u4ED8\
    \u304D\u7BC4\u56F2\u304B\u3089\u8981\u7D20\u3092\u76F4\u63A5\u69CB\u7BC9\u3059\
    \u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u5171\u6709\u3059\u308B\
    \u3002\n#if __cplusplus >= 202002L\ntemplate <class R, class S>\nconcept sized_constructible_range\
    \ = std::ranges::input_range<R> && std::ranges::sized_range<R> &&\n          \
    \                          std::is_constructible_v<S, std::ranges::range_reference_t<R>>;\n\
    \ntemplate <class R>\nauto range_size(R& r) {\n    return std::ranges::size(r);\n\
    }\ntemplate <class R>\nauto range_begin(R& r) {\n    return std::ranges::begin(r);\n\
    }\ntemplate <class R>\nusing range_value_t = std::ranges::range_value_t<R>;\n\
    #else\nusing std::size;\ntemplate <class R>\nauto range_size(R& r) -> decltype(size(r))\
    \ {\n    return size(r);\n}\ntemplate <class R>\nauto range_begin(R& r) -> decltype(begin(r))\
    \ {\n    return begin(r);\n}\ntemplate <class R>\nusing range_value_t = typename\
    \ std::iterator_traits<decltype(range_begin(std::declval<R&>()))>::value_type;\n\
    \ntemplate <class R, class S, class = void>\nstruct is_sized_constructible_range\
    \ : std::false_type {};\ntemplate <class R, class S>\nstruct is_sized_constructible_range<R,\
    \ S, std::void_t<decltype(range_size(std::declval<R&>())), decltype(++std::declval<decltype(begin(std::declval<R&>()))&>()),\
    \ decltype(begin(std::declval<R&>()) != end(std::declval<R&>())), decltype(*begin(std::declval<R&>()))>>\n\
    \    : std::is_constructible<S, decltype(*begin(std::declval<R&>()))> {};\n#endif\n\
    }  // namespace internal_traits\n\ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
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
    \nnamespace internal_traits {\n// \u5C04\u5F71 (proj) \u306E\u65E2\u5B9A\u5024\
    \n#if __cplusplus >= 202002L\nusing identity = std::identity;\n#else\nstruct identity\
    \ {\n    using is_transparent = void;\n    template <class T>\n    constexpr T&&\
    \ operator()(T&& x) const noexcept {\n        return std::forward<T>(x);\n   \
    \ }\n};\n#endif\n}  // namespace internal_traits\n\ntemplate <class C>\nusing\
    \ mem_value_type = typename C::value_type;\ntemplate <class C>\nusing mem_difference_type\
    \ = typename C::difference_type;\n\nnamespace internal_traits {\ntemplate <class\
    \ T, class = void>\nstruct is_sorted_container_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_sorted_container_impl<std::set<T>> : std::true_type {};\n\
    template <class T>\nstruct is_sorted_container_impl<std::multiset<T>> : std::true_type\
    \ {};\n}  // namespace internal_traits\ntemplate <class T>\nstruct is_sorted_container\
    \ : internal_traits::is_sorted_container_impl<T>::type {};\ntemplate <class T>\n\
    inline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 16 \"src/data_structures/fenwick-tree.hpp\"\n\n/**\n * @brief Fenwick Tree\
    \ (Binary Indexed Tree)\n *\n * 1 \u70B9\u3078\u306E\u4F5C\u7528\u3068\u533A\u9593\
    \u7A4D\u3092 O(log n) \u3067\u884C\u3046\n * \u4F8B:\n * FenwickTree<group::Sum<long\
    \ long>> ft(n);\n * ft.apply(i, x);  // a[i] += x\n * ft.prod(l, r);   // a[l]\
    \ + ... + a[r-1]\n *\n * @tparam G \u53EF\u63DB\u306A\u7FA4 (algebra/group.hpp)\u3002\
    prefix_prod \u3068 max_right \u3060\u3051\u306A\u3089\u53EF\u63DB\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3082\u3088\u3044\n */\ntemplate <typename G>\nclass FenwickTree\
    \ {\n   public:\n    using S = typename G::S;\n\n   private:\n    G g;\n    long\
    \ long n;\n    // data[i] \u306F a[i - (i & -i)] \u304B\u3089 a[i-1] \u307E\u3067\
    \u306E\u7A4D (1-indexed)\n    std::vector<S> data;\n    S op(const S& a, const\
    \ S& b) const { return g.op(a, b); }\n    S e() const { return g.e(); }\n    S\
    \ inv(const S& a) const { return g.inv(a); }\n\n   public:\n    /**\n     * @brief\
    \ \u8981\u7D20\u6570 n \u3067\u3001\u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u5358\
    \u4F4D\u5143\u306E Fenwick Tree \u3092\u4F5C\u308B\n     */\n    explicit FenwickTree(long\
    \ long n = 0, G g = G()) : g(std::move(g)), n(n), data(n + 1, e()) {}\n    /**\n\
    \     * @brief v \u3092\u521D\u671F\u5024\u3068\u3059\u308B Fenwick Tree \u3092\
    \u4F5C\u308B O(n)\n     */\n#if __cplusplus >= 202002L\n    template <class R\
    \ = std::initializer_list<S>>\n        requires internal_traits::sized_constructible_range<R,\
    \ S>\n#else\n    template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit FenwickTree(R&& v, G g = G()) : FenwickTree(internal_traits::range_size(v),\
    \ std::move(g)) {\n        auto it = internal_traits::range_begin(v);\n      \
    \  for (long long i = 1; i <= n; i++) {\n            data[i] = op(data[i], S(*it));\n\
    \            ++it;\n            long long j = i + (i & -i);\n            if (j\
    \ <= n) data[j] = op(data[j], data[i]);\n        }\n    }\n\n    long long size()\
    \ const { return n; }\n\n    /**\n     * @brief a[k] \u3092 op(a[k], x) \u306B\
    \u3059\u308B O(log n)\n     */\n    void apply(long long k, const S& x) {\n  \
    \      assert(0 <= k && k < n);\n        for (k++; k <= n; k += k & -k) data[k]\
    \ = op(data[k], x);\n    }\n    /**\n     * @brief a[0] \u304B\u3089 a[r-1] \u307E\
    \u3067\u306E\u7A4D O(log n)\n     */\n    S prefix_prod(long long r) const {\n\
    \        assert(0 <= r && r <= n);\n        S res = e();\n        for (; r > 0;\
    \ r -= r & -r) res = op(data[r], res);\n        return res;\n    }\n    /**\n\
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
    \ <typename G>\nFenwickTree(long long, G) -> FenwickTree<G>;\ntemplate <class\
    \ R, typename G>\nFenwickTree(R&&, G) -> FenwickTree<G>;\ntemplate <typename G>\n\
    FenwickTree(std::initializer_list<typename G::S>, G) -> FenwickTree<G>;\n#line\
    \ 2 \"src/graph/heavy-light-decomposition.hpp\"\n\n/**\n * @file heavy-light-decomposition.hpp\n\
    \ * @brief HL \u5206\u89E3 (Heavy-Light Decomposition)\n */\n\n#line 16 \"src/graph/heavy-light-decomposition.hpp\"\
    \n\n#line 2 \"src/graph/tree.hpp\"\n\n/**\n * @file tree.hpp\n * @brief \u6728\
    \u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n#line 10 \"src/graph/tree.hpp\"\
    \n#include <stack>\n#line 14 \"src/graph/tree.hpp\"\n\n#line 2 \"src/graph/graph.hpp\"\
    \n\n/**\n * @file graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 12 \"\
    src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u6C4E\u7528\u30AF\
    \u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B \u7701\
    \u7565\u3057\u305F\u3089 long long (\u91CD\u307F\u306E\u548C\u3084\u672A\u5230\
    \u9054\u3092\u8868\u3059 max / 4 \u304C\u3042\u3075\u308C\u306B\u304F\u3044\u3088\
    \u3046\u306B)\n */\ntemplate <typename Cost = long long>\nclass Graph {\n   public:\n\
    \    /**\n     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\n     *\n \
    \    * operator long long()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\u306E\u3067\
    \u3001\u6574\u6570\u578B\u306B\u30AD\u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\
    \u624B\u306Bdst\u306B\u306A\u308B\n     * \u4F8B\u3048\u3070\u3001\n     * for\
    \ (auto& e : g[v]) \u3092\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\
    \u304C\u5217\u6319\u3055\u308C\u308B\u304C\u3001\n     * for (long long dst :\
    \ g[v]) \u3068\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u884C\
    \u304D\u5148\u304C\u5217\u6319\u3055\u308C\u308B\n     */\n    struct Edge {\n\
    \        long long src = -1;  //!< \u59CB\u70B9\n        long long dst = -1; \
    \ //!< \u7D42\u70B9\n        Cost cost = {};      //!< \u30B3\u30B9\u30C8\n  \
    \      long long id = -1;   //!< \u8FBA\u306E\u756A\u53F7(\u8FFD\u52A0\u3055\u308C\
    \u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\u5834\u5408\u306Fid\u304C\u540C\u3058\
    \u3067\u65B9\u5411\u304C\u9006\u306E\u3082\u306E\u304C2\u3064\u5B58\u5728\u3059\
    \u308B)\n        Edge() = default;\n        Edge(long long src, long long dst,\
    \ Cost cost = 1, long long id = -1) : src(src), dst(dst), cost(cost), id(id) {}\n\
    \        operator long long() const { return dst; }\n    };\n\n   private:\n \
    \   long long n;                       //!< \u9802\u70B9\u6570\n    long long\
    \ m;                       //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>>\
    \ g;  //!< \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\
    \n   public:\n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n    Graph() : n(0), m(0), g(0) {}\n \
    \   /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ n \u9802\u70B9\u6570\n     */\n    explicit Graph(long long n) : n(n), m(0),\
    \ g(n) {}\n    /**\n     * @brief \u9802\u70B9\u6570\n     */\n    long long size()\
    \ const { return n; }\n    /**\n     * @brief \u8FBA\u6570 (\u7121\u5411\u8FBA\
    \u306F 1 \u672C\u3068\u6570\u3048\u308B)\n     */\n    long long edge_count()\
    \ const { return m; }\n    /**\n     * @brief \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n   \
    \  * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n  \
    \  void add_edge(long long u, long long v, Cost w = 1) {\n        assert(0 <=\
    \ u && u < n && 0 <= v && v < n);\n        g[u].push_back({u, v, w, m});\n   \
    \     g[v].push_back({v, u, w, m++});\n    }\n    /**\n     * @brief \u6709\u5411\
    \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param\
    \ v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u3089\
    1\n     */\n    void add_directed_edge(long long u, long long v, Cost w = 1) {\n\
    \        assert(0 <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u,\
    \ v, w, m++});\n    }\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\
    \u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\
    \u308B\n     * @param m \u8FBA\u306E\u6570\n     * @param padding \u9802\u70B9\
    \u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\
    \u304B \u7701\u7565\u3057\u305F\u3089-1\n     * @param weighted \u8FBA\u306E\u91CD\
    \u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B \u7701\u7565\u3057\u305F\u3089\
    false\u3068\u306A\u308A\u3001\u91CD\u307F1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\
    \u308C\u308B\n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\
    \u3046\u304B \u7701\u7565\u3057\u305F\u3089false\n     */\n    void read(long\
    \ long m, long long padding = -1, bool weighted = false, bool directed = false)\
    \ {\n        for (long long i = 0; i < m; i++) {\n            long long u, v;\n\
    \            std::cin >> u >> v;\n            u += padding, v += padding;\n  \
    \          Cost c(1);\n            if (weighted)\n                std::cin >>\
    \ c;\n            if (directed)\n                add_directed_edge(u, v, c);\n\
    \            else\n                add_edge(u, v, c);\n        }\n    }\n    /**\n\
    \     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\
    \u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return const\
    \ std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n\
    \     */\n    const std::vector<Edge>& operator[](long long v) const {\n     \
    \   assert(0 <= v && v < n);\n        return g[v];\n    }\n    /**\n     * @brief\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\
    \u30EA\u30B9\u30C8(id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\
    \u4EE3\u8868\u3057\u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\u3002\
    \u305D\u306E src \u3068 dst \u306E\u5411\u304D\u306F\u898F\u5B9A\u3057\u306A\u3044\
    \n     * \u6709\u5411\u8FBA\u306F\u8FFD\u52A0\u3057\u305F\u3068\u304D\u306E\u5411\
    \u304D\u306E\u307E\u307E\u683C\u7D0D\u3055\u308C\u308B\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res(m);\n        for (long long i\
    \ = 0; i < n; i++) {\n            for (auto& e : g[i]) {\n                res[e.id]\
    \ = e;\n            }\n        }\n        return res;\n    }\n};\n\n/**\n * @brief\
    \ \u7D4C\u8DEF (\u8DEF\u30FB\u9589\u8DEF)\u3002\u9577\u3055 cost\u3001\u305F\u3069\
    \u308B\u9802\u70B9\u306E\u5217 vertices\u3001\u305F\u3069\u308B\u8FBA\u306E\u5217\
    \ edges\n *\n * edges[k] \u306F vertices[k] \u304B\u3089 vertices[k + 1] \u3078\
    \u5411\u304B\u3046 (edges[k].src == vertices[k]\u3001edges[k].dst == vertices[k\
    \ + 1])\n * vertices \u306F edges \u3088\u308A 1 \u3064\u591A\u3044\u3002\u8FBA\
    \u304C\u306A\u304F\u3066\u3082\u59CB\u70B9 1 \u3064\u304C\u5165\u308B\u3002\u9589\
    \u8DEF\u306A\u3089 vertices.front() == vertices.back()\n * auto [cost, vertices,\
    \ edges] = *shortest_path(g, s, t); \u306E\u3088\u3046\u306B\u53D7\u3051\u53D6\
    \u308C\u308B\n */\ntemplate <typename Cost>\nstruct Path {\n    Cost cost;   \
    \                                   //!< \u9577\u3055 (\u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306E\u548C)\n    std::vector<long long> vertices;                //!<\
    \ \u305F\u3069\u308B\u9802\u70B9 (\u59CB\u70B9\u304B\u3089\u9806\u306B)\n    std::vector<typename\
    \ Graph<Cost>::Edge> edges;  //!< \u305F\u3069\u308B\u8FBA (\u59CB\u70B9\u5074\
    \u304B\u3089\u9806\u306B)\n};\n\nnamespace internal_graph {\n/**\n * @brief \u59CB\
    \u70B9 s \u3068\u3001s \u304B\u3089\u305F\u3069\u308B\u9806\u306B\u4E26\u3079\u305F\
    \u8FBA edges \u304B\u3089 Path \u3092\u4F5C\u308B\u3002cost \u306F\u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306E\u548C\n */\ntemplate <typename Cost>\nPath<Cost> make_path(long\
    \ long s, std::vector<typename Graph<Cost>::Edge> edges) {\n    Path<Cost> res{Cost{},\
    \ {s}, std::move(edges)};\n    for (const auto& e : res.edges) {\n        assert(e.src\
    \ == res.vertices.back());\n        res.cost += e.cost;\n        res.vertices.push_back(e.dst);\n\
    \    }\n    return res;\n}\n}  // namespace internal_graph\n#line 16 \"src/graph/tree.hpp\"\
    \n\ntemplate <typename>\nclass RootedTree;\ntemplate <typename>\nclass DoublingClimbTree;\n\
    \n/**\n * @brief \u6839\u306A\u3057\u6728\n *\n * @tparam Cost = long long \u8FBA\
    \u306E\u91CD\u307F\n *\n * Graph<Cost>\u3092\u7D99\u627F\u3057\u3001\u3059\u3079\
    \u3066\u7121\u5411\u8FBA\u3067\u8868\u3059\n */\ntemplate <typename Cost = long\
    \ long>\nstruct Tree : private Graph<Cost> {\n    // Graph<Cost>* g = new Tree<Cost>();\
    \ \u304C\u3067\u304D\u3066\u3057\u307E\u3046\u3068\u3001delete\u6642\u306B\u30E1\
    \u30E2\u30EA\u30EA\u30FC\u30AF\u304C\u767A\u751F\n    // \u56DE\u907F\u3059\u308B\
    \u305F\u3081private\u7D99\u627F\u306B\u3057\u3066\u3001\u516C\u958B\u3059\u308B\
    \u30E1\u30F3\u30D0\u3092using\u5BA3\u8A00\u3059\u308B\n    // add_directed_edge\
    \ \u306F\u6728\u3067\u306A\u304F\u306A\u308B\u306E\u3067\u516C\u958B\u3057\u306A\
    \u3044 (read \u306F Tree::read \u3067\u96A0\u3059)\n    using Edge = typename\
    \ Graph<Cost>::Edge;\n    using Graph<Cost>::size;\n    using Graph<Cost>::edge_count;\n\
    \    using Graph<Cost>::Graph;\n    using Graph<Cost>::add_edge;\n    using Graph<Cost>::operator[];\n\
    \    using Graph<Cost>::edges;\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     *\n     * @param n \u30CE\u30FC\u30C9\u6570\n     */\n\
    \    explicit Tree(long long n = 0) : Graph<Cost>(n) {}\n\n    /**\n     * @brief\
    \ Graph \u3068\u3057\u3066\u898B\u308B\n     *\n     * Graph \u3092\u53D7\u3051\
    \u53D6\u308B\u95A2\u6570 (shortest_path_dijkstra \u306A\u3069) \u306B\u6E21\u3059\
    \u3068\u304D\u306B\u4F7F\u3046\n     * @return const Graph<Cost>& \u3053\u306E\
    \u6728\u3092\u8868\u3059\u30B0\u30E9\u30D5\n     */\n    const Graph<Cost>& graph()\
    \ const { return *this; }\n\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\
    \u6A19\u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\
    \u3059\u308B\n     * @param padding  = -1 \u9802\u70B9\u756A\u53F7\u3092\u5165\
    \u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     * @param weighted\
    \ = false \u8FBA\u306E\u91CD\u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B\n\
    \     */\n    void read(long long padding = -1, bool weighted = false) {\n   \
    \     Graph<Cost>::read(this->size() - 1, padding, weighted, false);\n    }\n\n\
    \    /**\n     * @brief \u6839\u4ED8\u304D\u6728\u306B\u3059\u308B\n     *\n \
    \    * @param root \u6839\n     * @return RootedTree<Cost> \u6839\u4ED8\u304D\u6728\
    \u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    RootedTree<Cost>\
    \ set_root(long long root) const& {\n        return RootedTree<Cost>(*this, root);\n\
    \    }\n    /**\n     * @brief \u6839\u4ED8\u304D\u6728\u306B\u3057\u3066\u8FD4\
    \u3059\n     *\n     * @param root \u6839\n     * @return RootedTree<Cost> \u6839\
    \u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n\
    \    RootedTree<Cost> set_root(long long root) && {\n        return RootedTree<Cost>(std::move(*this),\
    \ root);\n    }\n\n    /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\
    \u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\u3092\u8FD4\u3059\n     *\n     * @param\
    \ root \u6839\n     * @return DoublingClimbTree<Cost> \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost> build_lca(long\
    \ long root) const& {\n        RootedTree rooted_tree(*this, root);\n        return\
    \ DoublingClimbTree<Cost>(std::move(rooted_tree));\n    }\n    /**\n     * @brief\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\
    \u3092\u8FD4\u3059\n     *\n     * @param root \u6839\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca(long long root) && {\n        RootedTree rooted_tree(std::move(*this),\
    \ root);\n        return DoublingClimbTree<Cost>(std::move(rooted_tree));\n  \
    \  }\n};\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\n *\n * @tparam Cost = long\
    \ long \u8FBA\u306E\u30B3\u30B9\u30C8\n */\ntemplate <typename Cost = long long>\n\
    class RootedTree : private Tree<Cost> {\n   public:\n    using Edge = typename\
    \ Tree<Cost>::Edge;\n    using Tree<Cost>::size;\n    using Tree<Cost>::edge_count;\n\
    \    using Tree<Cost>::edges;\n    using Tree<Cost>::graph;\n\n   private:\n \
    \   long long _root;                                           //!< \u6839\n \
    \   std::vector<Edge> _par;                                    //!< \u89AA\u3078\
    \u5411\u304B\u3046\u8FBA\n    std::vector<std::vector<Edge>> _child;         \
    \            //!< \u5B50\u3078\u5411\u304B\u3046\u8FBA\u306E\u30EA\u30B9\u30C8\
    \n    std::vector<Cost> _depth;                                  //!< \u6DF1\u3055\
    \u306E\u30EA\u30B9\u30C8\n    std::vector<Cost> _height;                     \
    \            //!< \u90E8\u5206\u6728\u306E\u9AD8\u3055\u306E\u30EA\u30B9\u30C8\
    \n    std::vector<long long> _unweighted_depth;                  //!< \u91CD\u307F\
    \u306A\u3057\u306E\u6DF1\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<long long>\
    \ _unweighted_height;                 //!< \u91CD\u307F\u306A\u3057\u306E\u90E8\
    \u5206\u6728\u306E\u9AD8\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<long long>\
    \ _sz;                                //!< \u90E8\u5206\u6728\u306E\u9802\u70B9\
    \u6570\u306E\u30EA\u30B9\u30C8\n    std::vector<long long> _preorder;        \
    \                  //!< \u5148\u884C\u9806\u5DE1\u56DE\n    std::vector<long long>\
    \ _postorder;                         //!< \u5F8C\u884C\u9806\u5DE1\u56DE\n  \
    \  std::vector<std::pair<long long, long long>> _euler_tour;  //!< \u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC DFS\u4E2D\u306B\u3068\u304A\u3063\u305F\u9802\u70B9\
    \u306E(\u9802\u70B9\u756A\u53F7,\u305D\u306E\u9802\u70B9\u3092\u901A\u3063\u305F\
    \u56DE\u6570)\u306E\u30EA\u30B9\u30C8\n\n   public:\n    /**\n     * @brief \u9802\
    \u70B9 v \u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\u6319\u3059\u308B\n     */\n\
    \    const std::vector<Edge>& operator[](long long v) const { return Tree<Cost>::operator[](v);\
    \ }\n\n    /** @brief \u6839 */\n    long long root() const { return _root; }\n\
    \    /** @brief \u9802\u70B9 v \u306E\u89AA\u3078\u5411\u304B\u3046\u8FBA (\u6839\
    \u3067\u306F dst == -1) */\n    const Edge& parent_edge(long long v) const {\n\
    \        assert(0 <= v && v < size());\n        return _par[v];\n    }\n    /**\
    \ @brief \u9802\u70B9 v \u306E\u5B50\u3078\u5411\u304B\u3046\u8FBA */\n    const\
    \ std::vector<Edge>& children(long long v) const {\n        assert(0 <= v && v\
    \ < size());\n        return _child[v];\n    }\n    /** @brief \u9802\u70B9 v\
    \ \u306E\u6839\u304B\u3089\u306E\u8DDD\u96E2 */\n    Cost depth(long long v) const\
    \ {\n        assert(0 <= v && v < size());\n        return _depth[v];\n    }\n\
    \    /** @brief \u9802\u70B9 v \u306E\u90E8\u5206\u6728\u306E\u9AD8\u3055 */\n\
    \    Cost height(long long v) const {\n        assert(0 <= v && v < size());\n\
    \        return _height[v];\n    }\n    /** @brief \u9802\u70B9 v \u306E\u6839\
    \u304B\u3089\u306E\u8FBA\u6570 */\n    long long unweighted_depth(long long v)\
    \ const {\n        assert(0 <= v && v < size());\n        return _unweighted_depth[v];\n\
    \    }\n    /** @brief \u9802\u70B9 v \u306E\u90E8\u5206\u6728\u306E\u9AD8\u3055\
    \ (\u8FBA\u6570) */\n    long long unweighted_height(long long v) const {\n  \
    \      assert(0 <= v && v < size());\n        return _unweighted_height[v];\n\
    \    }\n    /** @brief \u9802\u70B9 v \u306E\u90E8\u5206\u6728\u306E\u9802\u70B9\
    \u6570 */\n    long long subtree_size(long long v) const {\n        assert(0 <=\
    \ v && v < size());\n        return _sz[v];\n    }\n    /** @brief \u884C\u304D\
    \u304C\u3051\u9806 */\n    const std::vector<long long>& preorder() const { return\
    \ _preorder; }\n    /** @brief \u5E30\u308A\u304C\u3051\u9806 */\n    const std::vector<long\
    \ long>& postorder() const { return _postorder; }\n    /** @brief \u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC (\u9802\u70B9\u3068\u8A2A\u554F\u56DE\u6570\u306E\
    \u7D44) */\n    const std::vector<std::pair<long long, long long>>& euler_tour()\
    \ const { return _euler_tour; }\n\n    RootedTree() = delete;\n\n    /**\n   \
    \  * @brief \u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u304B\u3089\u6839\
    \u304C0\u306E\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam T \u9802\u70B9\u756A\u53F7\
    \u306E\u6574\u6570\u578B (long long \u3084 int)\n     * @param par_ \u9802\u70B9\
    0\u4EE5\u5916\u306E\u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     * @param\
    \ padding = -1 par\u306E\u9802\u70B9\u756A\u53F7\u3092\u3044\u304F\u3064\u305A\
    \u3089\u3059\u304B\n     */\n    template <typename T = long long>\n    explicit\
    \ RootedTree(const std::vector<T>& par_, long long padding = -1) : Tree<Cost>(par_.size()\
    \ + 1), _root(0) {\n        static_assert(std::is_integral_v<T>, \"RootedTree:\
    \ par_ must be a vector of integers\");\n        for (long long i = 0; i < static_cast<long\
    \ long>(par_.size()); i++) {\n            this->add_edge(i + 1, par_[i] + padding);\n\
    \        }\n        build();\n    }\n    /**\n     * @brief Tree\u304B\u3089\u6839\
    \u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree Tree \u9802\u70B9\
    \u65701\u4EE5\u4E0A\n     * @param root \u6839\n     */\n    RootedTree(const\
    \ Tree<Cost>& tree, long long root) : Tree<Cost>(tree), _root(root) {\n      \
    \  build();\n    }\n    /**\n     * @brief Tree\u304B\u3089\u6839\u4ED8\u304D\u6728\
    \u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30E0\
    \u30FC\u30D6)\n     *\n     * @param tree Tree\n     * @param root \u6839\n  \
    \   */\n    RootedTree(Tree<Cost>&& tree, long long root) : Tree<Cost>(std::move(tree)),\
    \ _root(root) {\n        build();\n    }\n\n    /**\n     * @brief \u30C0\u30D6\
    \u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\u3092\u5F97\
    \u308B\n     *\n     * @return DoublingClimbTree<Cost> \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost> build_lca() const&\
    \ {\n        return DoublingClimbTree<Cost>(*this);\n    }\n\n    /**\n     *\
    \ @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\
    \u304D\u6728\u3092\u5F97\u308B\n     *\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca() && {\n        return DoublingClimbTree<Cost>(std::move(*this));\n\
    \    }\n\n   private:\n    void build() {\n        long long n = this->size();\n\
    \        assert(n > 0);\n        assert(0 <= _root && _root < n);\n        _par.resize(n);\n\
    \        _par[_root] = {_root, -1, 0, -1};\n        _child.resize(n);\n      \
    \  _depth.resize(n);\n        _unweighted_depth.resize(n);\n        _height.resize(n);\n\
    \        _unweighted_height.resize(n);\n        _sz.resize(n);\n        std::vector<int>\
    \ iter(n);\n        std::stack<std::pair<int, int>> stk;\n        stk.emplace(_root,\
    \ 0);\n        while (!stk.empty()) {\n            auto [u, cnt] = stk.top();\n\
    \            stk.pop();\n            _euler_tour.emplace_back(u, cnt);\n     \
    \       if (iter[u] == 0) _preorder.push_back(u);\n            while (iter[u]\
    \ < static_cast<int>((*this)[u].size()) && (*this)[u][iter[u]].dst == _par[u])\
    \ iter[u]++;\n            if (iter[u] == static_cast<int>((*this)[u].size()))\
    \ {\n                _postorder.push_back(u);\n                _sz[u] = 1;\n \
    \               _height[u] = 0;\n                _unweighted_height[u] = 0;\n\
    \                for (auto& e : _child[u]) {\n                    _sz[u] += _sz[e.dst];\n\
    \                    if (_height[u] < _height[e.dst] + e.cost) {\n           \
    \             _height[u] = _height[e.dst] + e.cost;\n                    }\n \
    \                   if (_unweighted_height[u] < _unweighted_height[e.dst] + 1)\
    \ {\n                        _unweighted_height[u] = _unweighted_height[e.dst]\
    \ + 1;\n                    }\n                }\n            } else {\n     \
    \           auto& e = (*this)[u][iter[u]++];\n                _par[e.dst] = {e.dst,\
    \ u, e.cost, e.id};\n                _child[u].push_back(e);\n               \
    \ _depth[e.dst] = _depth[u] + e.cost;\n                _unweighted_depth[e.dst]\
    \ = _unweighted_depth[u] + 1;\n                stk.emplace(u, cnt + 1);\n    \
    \            stk.emplace(e.dst, 0);\n            }\n        }\n    }\n};\n\n/**\n\
    \ * @brief \u89AA\u9802\u70B9\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\
    \u304D\u6728\n *\n * @tparam Cost = long long \u8FBA\u306E\u91CD\u307F(\u6CE8\
    : hop\u3067\u306F\u6839\u306E\u91CD\u307F\u306F\u8003\u3048\u306A\u3044)\n */\n\
    template <typename Cost = long long>\nclass DoublingClimbTree : private RootedTree<Cost>\
    \ {\n   public:\n    using Edge = typename RootedTree<Cost>::Edge;\n    using\
    \ RootedTree<Cost>::size;\n    using RootedTree<Cost>::edge_count;\n    using\
    \ RootedTree<Cost>::operator[];\n    using RootedTree<Cost>::edges;\n    using\
    \ RootedTree<Cost>::graph;\n    using RootedTree<Cost>::root;\n    using RootedTree<Cost>::parent_edge;\n\
    \    using RootedTree<Cost>::children;\n    using RootedTree<Cost>::depth;\n \
    \   using RootedTree<Cost>::height;\n    using RootedTree<Cost>::unweighted_depth;\n\
    \    using RootedTree<Cost>::unweighted_height;\n    using RootedTree<Cost>::subtree_size;\n\
    \    using RootedTree<Cost>::preorder;\n    using RootedTree<Cost>::postorder;\n\
    \    using RootedTree<Cost>::euler_tour;\n\n   private:\n    long long h;    \
    \                                   //!< \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u56DE\
    \u6570\n    std::vector<std::vector<long long>> doubling_par;  //!< j\u304B\u3089\
    (1<<i)\u9802\u70B9\u767B\u3063\u305F\u9802\u70B9(\u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F-1)\n\n   public:\n    DoublingClimbTree() = delete;\n\n   \
    \ /**\n     * @brief RootedTree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\
    \u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree RootedTree\n\
    \     */\n    explicit DoublingClimbTree(const RootedTree<Cost>& tree) : RootedTree<Cost>(tree)\
    \ {\n        build();\n    }\n\n    /**\n     * @brief RootedTree\u304B\u3089\u30C0\
    \u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n \
    \    *\n     * @param tree RootedTree\n     */\n    DoublingClimbTree(RootedTree<Cost>&&\
    \ tree) : RootedTree<Cost>(std::move(tree)) {\n        build();\n    }\n\n   \
    \ /**\n     * @brief \u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u304B\u3089\
    \u6839\u304C0\u306E\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\
    \u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     *\n     * @tparam T \u9802\u70B9\u756A\u53F7\u306E\u6574\u6570\u578B (long\
    \ long \u3084 int)\n     * @param par_ \u9802\u70B90\u4EE5\u5916\u306E\u89AA\u306E\
    \u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     * @param padding = -1 par\u306E\u9802\
    \u70B9\u756A\u53F7\u3092\u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     */\n\
    \    template <typename T = long long>\n    explicit DoublingClimbTree(const std::vector<T>&\
    \ par_, long long padding = -1) : RootedTree<Cost>(par_, padding) {\n        build();\n\
    \    }\n    /**\n     * @brief Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\
    \u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree Tree\n\
    \     * @param root \u6839\n     */\n    DoublingClimbTree(const Tree<Cost>& tree,\
    \ long long root) : RootedTree<Cost>(tree, root) {\n        build();\n    }\n\
    \    /**\n     * @brief Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\
    \u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n     *\n     * @param tree Tree\n    \
    \ * @param root \u6839\n     */\n    DoublingClimbTree(Tree<Cost>&& tree, long\
    \ long root) : RootedTree<Cost>(std::move(tree), root) {\n        build();\n \
    \   }\n\n    /**\n     * @brief \u9802\u70B9u\u304B\u3089k\u56DE\u3092\u6839\u306E\
    \u65B9\u5411\u306B\u9061\u3063\u305F\u9802\u70B9\n     *\n     * @param u \u5143\
    \u306E\u9802\u70B9\n     * @param k \u767B\u308B\u6BB5\u6570\n     * @return long\
    \ long k\u56DE\u767B\u3063\u305F\u9802\u70B9 (\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u3070 -1)\n     */\n    long long hop(long long u, long long k) const {\n   \
    \     assert(0 <= u && u < this->size() && k >= 0);\n        if (k > this->unweighted_depth(u))\
    \ return -1;\n        for (long long i = 0; i < h; i++) {\n            if (k >>\
    \ i & 1) u = doubling_par[i][u];\n            if (u == -1) return -1;\n      \
    \  }\n        return u;\n    }\n\n    /**\n     * @brief \u6700\u5C0F\u5171\u901A\
    \u7956\u5148\n     *\n     * @param u \u9802\u70B91\n     * @param v \u9802\u70B9\
    2\n     * @return long long LCA\u306E\u9802\u70B9\u756A\u53F7\n     */\n    long\
    \ long lca(long long u, long long v) const {\n        assert(0 <= u && u < this->size()\
    \ && 0 <= v && v < this->size());\n        if (this->unweighted_depth(u) > this->unweighted_depth(v))\
    \ std::swap(u, v);\n        v = hop(v, this->unweighted_depth(v) - this->unweighted_depth(u));\n\
    \        if (u == v) return u;\n        for (long long i = h - 1; i >= 0; i--)\
    \ {\n            long long nu = doubling_par[i][u];\n            long long nv\
    \ = doubling_par[i][v];\n            if (nu == -1) continue;\n            if (nu\
    \ != nv) {\n                u = nu;\n                v = nv;\n            }\n\
    \        }\n        return this->parent_edge(u);\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9\u9593\u8DDD\u96E2(\u91CD\u307F\u4ED8\u304D)\n     *\n     * @param\
    \ u \u9802\u70B91\n     * @param v \u9802\u70B92\n     * @return Cost u\u3068\
    v\u9593\u306E\u6700\u77ED\u7D4C\u8DEF\u306E\u8FBA\u306E\u91CD\u307F\u306E\u548C\
    \n     */\n    Cost dist(long long u, long long v) const {\n        assert(0 <=\
    \ u && u < this->size() && 0 <= v && v < this->size());\n        return this->depth(u)\
    \ + this->depth(v) - this->depth(lca(u, v)) * 2;\n    }\n\n   private:\n    void\
    \ build() {\n        long long n = this->size();\n        h = 1;\n        while\
    \ ((1LL << h) < n) h++;\n        doubling_par.assign(h, std::vector<long long>(n,\
    \ -1));\n        for (long long i = 0; i < n; i++) doubling_par[0][i] = this->parent_edge(i);\n\
    \        for (long long i = 0; i < h - 1; i++) {\n            for (long long j\
    \ = 0; j < n; j++) {\n                if (doubling_par[i][j] != -1) {\n      \
    \              doubling_par[i + 1][j] = doubling_par[i][doubling_par[i][j]];\n\
    \                }\n            }\n        }\n    }\n};\n#line 18 \"src/graph/heavy-light-decomposition.hpp\"\
    \n\n/**\n * @brief HL \u5206\u89E3 (Heavy-Light Decomposition)\n *\n * \u6728\u306E\
    \u9802\u70B9\u3092\u3001\u3069\u306E\u30D1\u30B9\u3082 O(log n) \u500B\u306E\u533A\
    \u9593\u306B\u5206\u304B\u308C\u3001\u3069\u306E\u90E8\u5206\u6728\u3082 1 \u3064\
    \u306E\u533A\u9593\u306B\u306A\u308B\u3088\u3046\u306B\u4E26\u3079\u66FF\u3048\
    \u308B\n * \u9802\u70B9 v \u306F\u5217\u306E index(v) \u756A\u76EE\u306B\u5BFE\
    \u5FDC\u3059\u308B\u3002\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u3068\
    \u7D44\u307F\u5408\u308F\u305B\u3066\u3001\u30D1\u30B9\u3084\u90E8\u5206\u6728\
    \u3078\u306E\u30AF\u30A8\u30EA\u3092\u884C\u3046\n * \u524D\u8A08\u7B97 O(n)\u3002\
    DFS \u306F\u518D\u5E30\u3092\u4F7F\u308F\u306A\u3044\n * \u4F8B:\n * HeavyLightDecomposition\
    \ hld(tree, root);  // tree \u306F Tree<Cost>\n * for (auto [l, r, reverse] :\
    \ hld.path(u, v)) sum += seg.prod(l, r);\n * auto [l, r] = hld.subtree(v);  //\
    \ \u90E8\u5206\u6728\u306F\u533A\u9593 [l, r)\n */\nclass HeavyLightDecomposition\
    \ {\n    long long n, root;\n    // \u5185\u90E8\u306E\u914D\u5217\u306F int \u3067\
    \u6301\u3061\u3001\u516C\u958B\u3059\u308B\u95A2\u6570\u3067 long long \u306B\u3059\
    \u308B\n    std::vector<int> par, dep, sz, heavy, head, in, order;\n\n   public:\n\
    \    /**\n     * @brief \u30D1\u30B9\u306E\u4E00\u90E8\u306B\u5BFE\u5FDC\u3059\
    \u308B\u534A\u958B\u533A\u9593 [l, r) \u3068\u3001\u305F\u3069\u308B\u5411\u304D\
    \n     */\n    struct PathSegment {\n        long long l;   //!< \u533A\u9593\u306E\
    \u5DE6\u7AEF (\u542B\u3080)\n        long long r;   //!< \u533A\u9593\u306E\u53F3\
    \u7AEF (\u542B\u307E\u306A\u3044)\n        bool reverse;  //!< true \u306A\u3089\
    \ r - 1 \u304B\u3089 l \u3078\u3001false \u306A\u3089 l \u304B\u3089 r - 1 \u3078\
    \u305F\u3069\u308B\n    };\n\n    /**\n     * @brief \u6728 tree \u3092\u6839\
    \ root \u3067 HL \u5206\u89E3\u3059\u308B\n     */\n    template <typename Cost>\n\
    \    explicit HeavyLightDecomposition(const Tree<Cost>& tree, long long root =\
    \ 0)\n        : n(tree.size()), root(root), par(n, -1), dep(n, 0), sz(n, 1), heavy(n,\
    \ -1), head(n), in(n), order(n) {\n        assert(0 <= root && root < n);\n  \
    \      // \u6839\u304B\u3089\u306E BFS \u9806\u3067\u89AA\u3068\u6DF1\u3055\u3092\
    \u6C7A\u3081\u308B\n        std::vector<int> bfs = {static_cast<int>(root)};\n\
    \        bfs.reserve(n);\n        for (int i = 0; i < static_cast<int>(bfs.size());\
    \ i++) {\n            int v = bfs[i];\n            for (long long u : tree[v])\
    \ {\n                if (u == par[v]) continue;\n                assert(u != root\
    \ && par[u] == -1 && \"HeavyLightDecomposition: not a tree\");\n             \
    \   par[u] = v;\n                dep[u] = dep[v] + 1;\n                bfs.push_back(u);\n\
    \            }\n        }\n        assert(static_cast<long long>(bfs.size()) ==\
    \ n && \"HeavyLightDecomposition: not connected\");\n        // \u8449\u306E\u5074\
    \u304B\u3089\u90E8\u5206\u6728\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u3001\
    \u6700\u3082\u5927\u304D\u3044\u5B50\u3092 heavy \u306B\u3059\u308B\n        for\
    \ (int i = n - 1; i > 0; i--) {\n            int v = bfs[i], p = par[v];\n   \
    \         sz[p] += sz[v];\n            if (heavy[p] == -1 || sz[v] > sz[heavy[p]])\
    \ heavy[p] = v;\n        }\n        // heavy \u306A\u5B50\u3092\u6700\u5F8C\u306B\
    \u7A4D\u3080\u3068\u3001\u6B21\u306B\u53D6\u308A\u51FA\u3055\u308C\u3066 index\
    \ \u304C\u9023\u7D9A\u3059\u308B\n        std::vector<int> st = {static_cast<int>(root)};\n\
    \        head[root] = root;\n        int k = 0;\n        while (!st.empty()) {\n\
    \            int v = st.back();\n            st.pop_back();\n            in[v]\
    \ = k;\n            order[k++] = v;\n            for (long long u : tree[v]) {\n\
    \                if (u == par[v] || u == heavy[v]) continue;\n               \
    \ head[u] = u;\n                st.push_back(u);\n            }\n            if\
    \ (heavy[v] != -1) {\n                head[heavy[v]] = head[v];\n            \
    \    st.push_back(heavy[v]);\n            }\n        }\n    }\n\n    long long\
    \ size() const { return n; }\n    /**\n     * @brief \u9802\u70B9 v \u306E\u5217\
    \u3067\u306E\u4F4D\u7F6E\n     */\n    long long index(long long v) const {\n\
    \        assert(0 <= v && v < n);\n        return in[v];\n    }\n    /**\n   \
    \  * @brief \u5217\u306E i \u756A\u76EE\u306E\u9802\u70B9 (index \u306E\u9006\
    )\n     */\n    long long vertex(long long i) const {\n        assert(0 <= i &&\
    \ i < n);\n        return order[i];\n    }\n    /**\n     * @brief v \u306E\u89AA\
    \ (\u6839\u306A\u3089 -1)\n     */\n    long long parent(long long v) const {\n\
    \        assert(0 <= v && v < n);\n        return par[v];\n    }\n    /**\n  \
    \   * @brief v \u306E\u6DF1\u3055 (\u6839\u306F 0\u3001\u8FBA\u306E\u672C\u6570\
    )\n     */\n    long long depth(long long v) const {\n        assert(0 <= v &&\
    \ v < n);\n        return dep[v];\n    }\n    /**\n     * @brief v \u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306E\u500B\u6570\n   \
    \  */\n    long long subtree_size(long long v) const {\n        assert(0 <= v\
    \ && v < n);\n        return sz[v];\n    }\n    /**\n     * @brief v \u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\
    \u308B\u533A\u9593 [l, r)\n     */\n    std::pair<long long, long long> subtree(long\
    \ long v) const { return {in[v], in[v] + sz[v]}; }\n\n    /**\n     * @brief u\
    \ \u3068 v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148 O(log n)\n     */\n    long\
    \ long lca(long long u, long long v) const {\n        assert(0 <= u && u < n &&\
    \ 0 <= v && v < n);\n        while (head[u] != head[v]) {\n            if (dep[head[u]]\
    \ < dep[head[v]]) std::swap(u, v);\n            u = par[head[u]];\n        }\n\
    \        return dep[u] < dep[v] ? u : v;\n    }\n    /**\n     * @brief u \u3068\
    \ v \u306E\u9593\u306E\u8FBA\u306E\u672C\u6570 O(log n)\n     */\n    long long\
    \ dist(long long u, long long v) const { return dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)]; }\n    /**\n     * @brief v \u304B\u3089\u6839\u306E\u65B9\u3078 k \u672C\
    \u306E\u8FBA\u3092\u9032\u3093\u3060\u9802\u70B9 (k > depth(v) \u306A\u3089 -1)\
    \ O(log n)\n     */\n    long long hop(long long v, long long k) const {\n   \
    \     assert(0 <= v && v < n && k >= 0);\n        if (k > dep[v]) return -1;\n\
    \        while (true) {\n            long long h = head[v];\n            if (in[v]\
    \ - in[h] >= k) return order[in[v] - k];\n            k -= in[v] - in[h] + 1;\n\
    \            v = par[h];\n        }\n    }\n    /**\n     * @brief u \u304B\u3089\
    \ v \u3078\u306E\u30D1\u30B9\u3067\u3001u \u304B\u3089 k \u672C\u306E\u8FBA\u3092\
    \u9032\u3093\u3060\u9802\u70B9 (k > dist(u, v) \u306A\u3089 -1) O(log n)\n   \
    \  */\n    long long jump(long long u, long long v, long long k) const {\n   \
    \     assert(0 <= u && u < n && 0 <= v && v < n && k >= 0);\n        long long\
    \ w = lca(u, v);\n        long long du = dep[u] - dep[w], dv = dep[v] - dep[w];\n\
    \        if (k <= du) return hop(u, k);\n        if (k <= du + dv) return hop(v,\
    \ du + dv - k);\n        return -1;\n    }\n\n   private:\n    class PathEnumeration\
    \ {\n        const HeavyLightDecomposition* hld;\n        int u, v;\n        bool\
    \ edge;\n\n       public:\n        PathEnumeration(const HeavyLightDecomposition*\
    \ hld, long long u, long long v, bool edge)\n            : hld(hld), u(static_cast<int>(u)),\
    \ v(static_cast<int>(v)), edge(edge) {}\n\n        class iterator {\n        \
    \    struct Interval {\n                int l, r;\n            };\n          \
    \  const HeavyLightDecomposition* hld = nullptr;\n            int u = 0, v = 0,\
    \ top = 0;\n            bool edge = false, ascending = true, done = true;\n  \
    \          // v \u5074\u304B\u3089\u96C6\u3081\u305F\u533A\u9593\u3092\u9006\u9806\
    \u306B\u8FD4\u3059\u3002light edge \u3092\u8D8A\u3048\u308B\u305F\u3073\u306B\u90E8\
    \u5206\u6728\u306E\u5927\u304D\u3055\u306F\u500D\u4EE5\u4E0A\u306B\u306A\u308B\
    \u3002\n            // \u672A\u4F7F\u7528\u306E\u8981\u7D20\u306F\u521D\u671F\u5316\
    \u305B\u305A\u3001iterator \u306E\u30B3\u30D4\u30FC\u3067\u3082 [0, top) \u3060\
    \u3051\u3092\u30B3\u30D4\u30FC\u3059\u308B\u3002\n            std::array<Interval,\
    \ std::numeric_limits<long long>::digits> pending;\n            PathSegment current{0,\
    \ 0, false};\n\n           public:\n            using value_type = PathSegment;\n\
    \            using difference_type = std::ptrdiff_t;\n            using reference\
    \ = value_type;\n            using pointer = void;\n            using iterator_category\
    \ = std::input_iterator_tag;\n\n            iterator() = default;\n          \
    \  iterator(const HeavyLightDecomposition* hld, long long u, long long v, bool\
    \ edge)\n                : hld(hld), u(static_cast<int>(u)), v(static_cast<int>(v)),\
    \ edge(edge), done(false) { ++*this; }\n            iterator(const iterator& other)\n\
    \                : hld(other.hld), u(other.u), v(other.v), top(other.top), edge(other.edge),\
    \ ascending(other.ascending), done(other.done), current(other.current) {\n   \
    \             std::copy_n(other.pending.begin(), top, pending.begin());\n    \
    \        }\n            iterator& operator=(const iterator& other) {\n       \
    \         if (this != &other) {\n                    hld = other.hld;\n      \
    \              u = other.u;\n                    v = other.v;\n              \
    \      top = other.top;\n                    edge = other.edge;\n            \
    \        ascending = other.ascending;\n                    done = other.done;\n\
    \                    current = other.current;\n                    std::copy_n(other.pending.begin(),\
    \ top, pending.begin());\n                }\n                return *this;\n \
    \           }\n            value_type operator*() const { return current; }\n\
    \            iterator& operator++() {\n                if (ascending) {\n    \
    \                while (hld->head[u] != hld->head[v]) {\n                    \
    \    if (hld->dep[hld->head[u]] >= hld->dep[hld->head[v]]) {\n               \
    \             current = {hld->in[hld->head[u]], hld->in[u] + 1, true};\n     \
    \                       u = hld->par[hld->head[u]];\n                        \
    \    return *this;\n                        }\n                        pending[top++]\
    \ = {hld->in[hld->head[v]], hld->in[v] + 1};\n                        v = hld->par[hld->head[v]];\n\
    \                    }\n                    ascending = false;\n             \
    \       if (hld->dep[u] >= hld->dep[v]) {\n                        const long\
    \ long l = hld->in[v] + edge;\n                        if (l <= hld->in[u]) {\n\
    \                            current = {l, hld->in[u] + 1, true};\n          \
    \                  return *this;\n                        }\n                \
    \    } else {\n                        const long long l = hld->in[u] + edge;\n\
    \                        if (l <= hld->in[v]) {\n                            current\
    \ = {l, hld->in[v] + 1, false};\n                            return *this;\n \
    \                       }\n                    }\n                }\n        \
    \        if (top > 0) {\n                    const auto [l, r] = pending[--top];\n\
    \                    current = {l, r, false};\n                } else {\n    \
    \                done = true;\n                }\n                return *this;\n\
    \            }\n            // \u5F8C\u7F6E increment \u3067\u306F\u3001\u9000\
    \u907F\u3057\u305F\u533A\u9593\u3092\u30B3\u30D4\u30FC\u305B\u305A\u3001\u5909\
    \u66F4\u524D\u306E\u5024\u3060\u3051\u3092\u8FD4\u3059\u3002\n            struct\
    \ Postfix {\n                value_type value;\n                value_type operator*()\
    \ const { return value; }\n            };\n            Postfix operator++(int)\
    \ {\n                const Postfix previous{current};\n                ++*this;\n\
    \                return previous;\n            }\n            bool operator==(const\
    \ iterator& other) const {\n                if (done || other.done) return done\
    \ == other.done;\n                return hld == other.hld && current.l == other.current.l\
    \ && current.r == other.current.r && current.reverse == other.current.reverse;\n\
    \            }\n            bool operator!=(const iterator& other) const { return\
    \ !(*this == other); }\n        };\n\n        iterator begin() const { return\
    \ iterator(hld, u, v, edge); }\n        iterator end() const { return iterator();\
    \ }\n    };\n\n   public:\n    /**\n     * @brief u \u304B\u3089 v \u3078\u306E\
    \u30D1\u30B9\u306E\u533A\u9593\u3092 u \u5074\u304B\u3089\u9806\u306B\u9045\u5EF6\
    \u5217\u6319\u3059\u308B\u3002\u69CB\u7BC9 O(1)\u3001\u5168\u8D70\u67FB O(log\
    \ n)\n     *\n     * \u5404\u8981\u7D20\u306F\u534A\u958B\u533A\u9593 [l, r) \u3068\
    \u5411\u304D reverse \u3092\u6301\u3064 PathSegment\n     * reverse \u304C false\
    \ \u306A\u3089 index \u306E\u6607\u9806\u3001true \u306A\u3089\u964D\u9806 (\u6839\
    \u306B\u8FD1\u3065\u304F\u5411\u304D) \u306B\u305F\u3069\u308B\n     * \u4EA4\u63DB\
    \u6CD5\u5247\u304C\u6210\u308A\u7ACB\u305F\u306A\u3044\u6F14\u7B97\u3067\u306F\
    \u3001reverse \u304C true \u306E\u533A\u9593\u306F\u9006\u9806\u306E\u7A4D\u3092\
    \u4F7F\u3046\n     * @pre \u8D70\u67FB\u4E2D\u306F\u3001\u3053\u306E HeavyLightDecomposition\
    \ \u3092\u6709\u52B9\u306A\u307E\u307E\u4FDD\u6301\u3057\u3001\u5909\u66F4\u3057\
    \u306A\u3044\u3053\u3068\n     * @param edge true \u306A\u3089\u8FBA\u306B\u3064\
    \u3044\u3066\u306E\u30D1\u30B9\u306B\u3059\u308B\u3002\u8FBA (parent(v), v) \u3092\
    \ index(v) \u756A\u76EE\u306B\u5BFE\u5FDC\u3055\u305B\u3001lca \u306E\u4F4D\u7F6E\
    \u3092\u542B\u3081\u306A\u3044\n     */\n    auto path(long long u, long long\
    \ v, bool edge = false) const {\n        assert(0 <= u && u < n && 0 <= v && v\
    \ < n);\n        return PathEnumeration(this, u, v, edge);\n    }\n};\n#line 13\
    \ \"test/aoj/grl/grl-5-d.test.cpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n;\n    std::cin >> n;\n    Tree<int>\
    \ g(n);\n    for (int v = 0; v < n; v++) {\n        int k;\n        std::cin >>\
    \ k;\n        for (int i = 0; i < k; i++) {\n            int c;\n            std::cin\
    \ >> c;\n            g.add_edge(v, c);\n        }\n    }\n    HeavyLightDecomposition\
    \ hld(g, 0);\n    FenwickTree<group::Sum<long long>> ft(n);\n    int q;\n    std::cin\
    \ >> q;\n    while (q--) {\n        int t;\n        std::cin >> t;\n        if\
    \ (t == 0) {\n            int v;\n            long long w;\n            std::cin\
    \ >> v >> w;\n            ft.apply(hld.index(v), w);\n        } else {\n     \
    \       int u;\n            std::cin >> u;\n            long long sum = 0;\n \
    \           for (auto [l, r, reverse] : hld.path(0, u, true)) sum += ft.prod(l,\
    \ r);\n            std::cout << sum << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n// HL \u5206\u89E3\u306E\u8FBA\u306E\u30D1\u30B9\u3068 Fenwick Tree \u3067\
    \u3001\u8FBA\u3078\u306E\u52A0\u7B97\u3068\u6839\u304B\u3089\u306E\u30D1\u30B9\
    \u306E\u548C\u3092\u6C42\u3081\u308B\n// \u8FBA (parent(v), v) \u306E\u5024\u3092\
    \ index(v) \u756A\u76EE\u306B\u7F6E\u304F\n\n#include <algorithm>\n#include <iostream>\n\
    \n#include \"../../../src/algebra/group.hpp\"\n#include \"../../../src/data_structures/fenwick-tree.hpp\"\
    \n#include \"../../../src/graph/heavy-light-decomposition.hpp\"\n#include \"../../../src/graph/tree.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n;\n    std::cin >> n;\n    Tree<int> g(n);\n    for (int v = 0; v <\
    \ n; v++) {\n        int k;\n        std::cin >> k;\n        for (int i = 0; i\
    \ < k; i++) {\n            int c;\n            std::cin >> c;\n            g.add_edge(v,\
    \ c);\n        }\n    }\n    HeavyLightDecomposition hld(g, 0);\n    FenwickTree<group::Sum<long\
    \ long>> ft(n);\n    int q;\n    std::cin >> q;\n    while (q--) {\n        int\
    \ t;\n        std::cin >> t;\n        if (t == 0) {\n            int v;\n    \
    \        long long w;\n            std::cin >> v >> w;\n            ft.apply(hld.index(v),\
    \ w);\n        } else {\n            int u;\n            std::cin >> u;\n    \
    \        long long sum = 0;\n            for (auto [l, r, reverse] : hld.path(0,\
    \ u, true)) sum += ft.prod(l, r);\n            std::cout << sum << '\\n';\n  \
    \      }\n    }\n}\n"
  dependsOn:
  - src/algebra/group.hpp
  - src/algebra/monoid.hpp
  - src/data_structures/fenwick-tree.hpp
  - src/utility/traits.hpp
  - src/graph/heavy-light-decomposition.hpp
  - src/graph/tree.hpp
  - src/graph/graph.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl-5-d.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 03:47:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/grl-5-d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl-5-d.test.cpp
- /verify/test/aoj/grl/grl-5-d.test.cpp.html
title: test/aoj/grl/grl-5-d.test.cpp
---
