---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/disjoint-sparse-table.hpp
    title: Disjoint Sparse Table
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit.hpp
    title: "\u30D3\u30C3\u30C8\u6F14\u7B97"
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
  bundledCode: "#line 1 \"test/unittest/data_structures/disjoint-sparse-table.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#line 2 \"src/data_structures/disjoint-sparse-table.hpp\"\n\n/**\n * @file\
    \ disjoint-sparse-table.hpp\n * @brief \u51AA\u7B49\u6027\u3092\u4EEE\u5B9A\u3057\
    \u306A\u3044\u9759\u7684\u306A\u533A\u9593\u7A4D\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <initializer_list>\n#include <utility>\n#include\
    \ <vector>\n\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n\
    \ * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\
    \u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\
    \u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S&\
    \ a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n\
    \ * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\
    \u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\
    \n#line 15 \"src/algebra/monoid.hpp\"\n#include <array>\n#include <cstddef>\n\
    #include <istream>\n#include <limits>\n#include <numeric>\n#include <optional>\n\
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
    \ T) -> Monoid<T, Op>;\n#line 2 \"src/utility/bit.hpp\"\n\n/**\n * @file bit.hpp\n\
    \ * @brief \u30D3\u30C3\u30C8\u6F14\u7B97\n */\n\n#line 10 \"src/utility/bit.hpp\"\
    \n#include <iterator>\n#include <string>\n#line 13 \"src/utility/bit.hpp\"\n\n\
    /**\n * @brief 2\u9032\u6570\u306E\u6587\u5B57\u5217\u3092long long\u306B\u3059\
    \u308B\n */\ninline long long btoll(std::string s, char one = '1') {\n    long\
    \ long res = 0;\n    for (char c : s) {\n        res <<= 1;\n        if (c ==\
    \ one) ++res;\n    }\n    return res;\n}\n\n#if __cplusplus < 202000L\n\n// C++20\
    \ \u306E <bit> \u3068\u540C\u3058\u5024\u3092\u8FD4\u3059 (0 \u306E\u3068\u304D\
    \u3082\u540C\u3058)\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\
    \u30C8\u3092\u6570\u3048\u308B\n * __builtin_popcountll\n */\ninline constexpr\
    \ long long popcount(long long a) {\n    assert(a >= 0);\n    return __builtin_popcountll(static_cast<unsigned\
    \ long long>(a));\n}\n/**\n * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F\
    0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_clzll\n */\ninline\
    \ constexpr long long countl_zero(long long a) {\n    assert(a >= 0);\n    return\
    \ a == 0 ? 64 : __builtin_clzll(static_cast<unsigned long long>(a));\n}\n/**\n\
    \ * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n */\ninline constexpr long long countl_one(long long\
    \ a) {\n    assert(a >= 0);\n    unsigned long long x = ~static_cast<unsigned\
    \ long long>(a);\n    return x == 0 ? 64 : __builtin_clzll(x);\n}\n/**\n * @brief\
    \ \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\
    \u3048\u308B\n * __builtin_ctzll\n */\ninline constexpr long long countr_zero(long\
    \ long a) {\n    assert(a >= 0);\n    return a == 0 ? 64 : __builtin_ctzll(static_cast<unsigned\
    \ long long>(a));\n}\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F\
    1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\ninline constexpr long\
    \ long countr_one(long long a) {\n    assert(a >= 0);\n    unsigned long long\
    \ x = ~static_cast<unsigned long long>(a);\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n/**\n * @brief \u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\
    \u8981\u306A\u30D3\u30C3\u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\ninline constexpr\
    \ long long bit_width(long long a) {\n    assert(a >= 0);\n    return 64 - countl_zero(a);\n\
    }\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\
    \u308A\u4E0A\u3052\u308B\n */\ninline constexpr long long bit_ceil(long long a)\
    \ {\n    assert(0 <= a && a <= (1LL << 62));\n    return a <= 1 ? 1 : 1LL << bit_width(a\
    \ - 1);\n}\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\
    \u5207\u308A\u4E0B\u3052\u308B\n */\ninline constexpr long long bit_floor(long\
    \ long a) {\n    assert(a >= 0);\n    return a == 0 ? 0 : 1LL << (bit_width(a)\
    \ - 1);\n}\n/**\n * @brief 2 \u306E\u7D2F\u4E57\u304B (\u3061\u3087\u3046\u3069\
    \ 1 \u3064\u306E\u30D3\u30C3\u30C8\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B)\n\
    \ */\ninline constexpr bool has_single_bit(long long a) {\n    assert(a >= 0);\n\
    \    return a != 0 && (a & (a - 1)) == 0;\n}\n\n#else\n\n#include <bit>\n#define\
    \ BIT_FUNC_EXPAND(func)                                 \\\n    inline constexpr\
    \ long long func(long long a) {            \\\n        assert(a >= 0);       \
    \                                \\\n        return std::func(static_cast<unsigned\
    \ long long>(a)); \\\n    }\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\
    \u30C3\u30C8\u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(popcount)\n/**\n *\
    \ @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\
    \u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countl_zero)\n/**\n * @brief \u5DE6\u304B\
    \u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\
    \n */\nBIT_FUNC_EXPAND(countl_one)\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\
    \u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countr_zero)\n\
    /**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countr_one)\n/**\n * @brief \u6574\
    \u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0A\u3052\u308B\
    \n */\ninline constexpr long long bit_ceil(long long a) {\n    // \u7D50\u679C\
    \u304C long long \u306B\u53CE\u307E\u308B\u7BC4\u56F2\u306B\u9650\u308B\n    assert(0\
    \ <= a && a <= (1LL << 62));\n    return std::bit_ceil(static_cast<unsigned long\
    \ long>(a));\n}\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\
    \u306B\u5207\u308A\u4E0B\u3052\u308B\n */\nBIT_FUNC_EXPAND(bit_floor)\n/**\n *\
    \ @brief \u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\
    \u30D3\u30C3\u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\nBIT_FUNC_EXPAND(bit_width)\n\
    /**\n * @brief 2 \u306E\u7D2F\u4E57\u304B (\u3061\u3087\u3046\u3069 1 \u3064\u306E\
    \u30D3\u30C3\u30C8\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B)\n */\ninline constexpr\
    \ bool has_single_bit(long long a) {\n    assert(a >= 0);\n    return std::has_single_bit(static_cast<unsigned\
    \ long long>(a));\n}\n\n#endif\n\n/**\n * @brief 2 \u3064\u306E\u6574\u6570\u306E\
    \u30CF\u30DF\u30F3\u30B0\u8DDD\u96E2 (\u30D3\u30C3\u30C8\u304C\u7570\u306A\u308B\
    \u4F4D\u7F6E\u306E\u6570)\n */\ninline constexpr long long hamming_distance(long\
    \ long a, long long b) {\n    assert(a >= 0 && b >= 0);\n    return popcount(a\
    \ ^ b);\n}\n\n/**\n * @brief \u6700\u4E0A\u4F4D\u306E\u7ACB\u3063\u3066\u3044\u308B\
    \u30D3\u30C3\u30C8\u306E\u4F4D\u7F6E (0 \u306A\u3089 -1)\n */\ninline constexpr\
    \ long long msb(long long a) { return bit_width(a) - 1; }\n/**\n * @brief \u6700\
    \u4E0B\u4F4D\u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u306E\u4F4D\
    \u7F6E (0 \u306A\u3089 -1)\n */\ninline constexpr long long lsb(long long a) {\n\
    \    assert(a >= 0);\n    return a == 0 ? -1 : countr_zero(a);\n}\n/**\n * @brief\
    \ \u6700\u4E0B\u4F4D\u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3060\
    \u3051\u3092\u6B8B\u3057\u305F\u5024 a & -a (0 \u306A\u3089 0)\n */\ninline constexpr\
    \ long long lowbit(long long a) {\n    assert(a >= 0);\n    return a & -a;\n}\n\
    /**\n * @brief a \u306E i \u30D3\u30C3\u30C8\u76EE\u304C\u7ACB\u3063\u3066\u3044\
    \u308B\u304B\n */\ninline constexpr bool test_bit(long long a, long long i) {\n\
    \    assert(a >= 0 && 0 <= i && i < 63);\n    return a >> i & 1;\n}\n/**\n * @brief\
    \ a \u306E i \u30D3\u30C3\u30C8\u76EE\u3092 1 \u306B\u3057\u305F\u5024\n */\n\
    inline constexpr long long set_bit(long long a, long long i) {\n    assert(a >=\
    \ 0 && 0 <= i && i < 63);\n    return a | 1LL << i;\n}\n/**\n * @brief a \u306E\
    \ i \u30D3\u30C3\u30C8\u76EE\u3092 0 \u306B\u3057\u305F\u5024\n */\ninline constexpr\
    \ long long reset_bit(long long a, long long i) {\n    assert(a >= 0 && 0 <= i\
    \ && i < 63);\n    return a & ~(1LL << i);\n}\n/**\n * @brief a \u306E i \u30D3\
    \u30C3\u30C8\u76EE\u3092\u53CD\u8EE2\u3057\u305F\u5024\n */\ninline constexpr\
    \ long long flip_bit(long long a, long long i) {\n    assert(a >= 0 && 0 <= i\
    \ && i < 63);\n    return a ^ 1LL << i;\n}\n/**\n * @brief \u7ACB\u3063\u3066\u3044\
    \u308B\u30D3\u30C3\u30C8\u306E\u6570\u306E\u5076\u5947 (popcount(a) % 2)\n */\n\
    inline constexpr long long parity(long long a) { return popcount(a) & 1; }\n/**\n\
    \ * @brief long long \u3092 n \u6841\u306E 2 \u9032\u6570\u306E\u6587\u5B57\u5217\
    \u306B\u3059\u308B (btoll \u306E\u9006)\n * n \u3092\u7701\u7565\u3059\u308B\u3068\
    \ bit_width(a) \u6841 (0 \u306A\u3089 \"0\")\n */\ninline std::string lltob(long\
    \ long a, long long n = -1, char one = '1', char zero = '0') {\n    assert(a >=\
    \ 0);\n    if (n < 0) n = a == 0 ? 1 : bit_width(a);\n    assert(n >= bit_width(a));\n\
    \    std::string res(n, zero);\n    for (long long i = 0; i < n && i < 63; i++)\
    \ {\n        if (a >> i & 1) res[n - 1 - i] = one;\n    }\n    return res;\n}\n\
    /**\n * @brief \u4E0B\u4F4D n \u30D3\u30C3\u30C8\u306E\u4E26\u3073\u3092\u9006\
    \u306B\u3059\u308B (a < 2^n)\n */\ninline constexpr long long reverse_bits(long\
    \ long a, long long n) {\n    assert(0 <= n && n <= 63 && 0 <= a && bit_width(a)\
    \ <= n);\n    long long res = 0;\n    for (long long i = 0; i < n; i++) {\n  \
    \      if (a >> i & 1) res |= 1LL << (n - 1 - i);\n    }\n    return res;\n}\n\
    /**\n * @brief \u4E0B\u4F4D n \u30D3\u30C3\u30C8\u3092\u5DE6\u306B k \u30D3\u30C3\
    \u30C8\u5DE1\u56DE\u30B7\u30D5\u30C8\u3059\u308B (a < 2^n\u3001k \u306F\u8CA0\u3067\
    \u3082\u3088\u3044)\n */\ninline constexpr long long rotate_left(long long a,\
    \ long long k, long long n) {\n    assert(1 <= n && n <= 63 && 0 <= a && bit_width(a)\
    \ <= n);\n    k %= n;\n    if (k < 0) k += n;\n    if (k == 0) return a;\n   \
    \ unsigned long long full = (1ULL << n) - 1;\n    return static_cast<long long>((static_cast<unsigned\
    \ long long>(a) << k & full) | static_cast<unsigned long long>(a) >> (n - k));\n\
    }\n/**\n * @brief \u4E0B\u4F4D n \u30D3\u30C3\u30C8\u3092\u53F3\u306B k \u30D3\
    \u30C3\u30C8\u5DE1\u56DE\u30B7\u30D5\u30C8\u3059\u308B (a < 2^n\u3001k \u306F\u8CA0\
    \u3067\u3082\u3088\u3044)\n */\ninline constexpr long long rotate_right(long long\
    \ a, long long k, long long n) {\n    assert(1 <= n && n <= 63);\n    return rotate_left(a,\
    \ -(k % n), n);\n}\n/**\n * @brief \u30B0\u30EC\u30A4\u30B3\u30FC\u30C9 (\u96A3\
    \u308A\u5408\u3046\u5024\u3067 1 \u30D3\u30C3\u30C8\u3060\u3051\u5909\u308F\u308B\
    ) a ^ (a >> 1)\n */\ninline constexpr long long gray_code(long long a) {\n   \
    \ assert(a >= 0);\n    return a ^ a >> 1;\n}\n/**\n * @brief \u30B0\u30EC\u30A4\
    \u30B3\u30FC\u30C9\u304B\u3089\u5143\u306E\u5024\u306B\u623B\u3059 (gray_code\
    \ \u306E\u9006)\n */\ninline constexpr long long inverse_gray_code(long long g)\
    \ {\n    assert(g >= 0);\n    for (long long s = 1; s < 64; s <<= 1) g ^= g >>\
    \ s;\n    return g;\n}\n/**\n * @brief mask \u306E\u7ACB\u3063\u3066\u3044\u308B\
    \u30D3\u30C3\u30C8\u306E\u3046\u3061\u3001\u4E0B\u304B\u3089 k \u756A\u76EE (0-indexed)\
    \ \u306E\u4F4D\u7F6E O(log 64)\n */\ninline constexpr long long kth_set_bit(long\
    \ long mask, long long k) {\n    assert(mask >= 0 && 0 <= k && k < popcount(mask));\n\
    \    long long res = 0;\n    for (long long w = 32; w > 0; w >>= 1) {\n      \
    \  // \u4E0B\u4F4D w \u30D3\u30C3\u30C8\u306B\u7ACB\u3063\u3066\u3044\u308B\u30D3\
    \u30C3\u30C8\u306E\u6570\u3067\u3001\u7B54\u3048\u304C\u4E0A\u4E0B\u3069\u3061\
    \u3089\u306B\u3042\u308B\u304B\u3092\u6C7A\u3081\u308B\n        long long c =\
    \ popcount(mask & ((1LL << w) - 1));\n        if (k >= c) {\n            k -=\
    \ c;\n            mask >>= w;\n            res += w;\n        }\n    }\n    return\
    \ res;\n}\n/**\n * @brief 0 ^ 1 ^ ... ^ n\n */\ninline constexpr long long xor_upto(long\
    \ long n) {\n    assert(n >= 0);\n    // 4 \u3064\u3054\u3068\u306B\u5468\u671F\
    \u7684\u306B\u306A\u308B\n    long long r = n & 3;\n    // r \u3054\u3068\u306E\
    \u5024\u306E\u8868\u3068\u3057\u3066\u8AAD\u3081\u308B\u3088\u3046\u306B 1 \u884C\
    \u3067\u66F8\u3044\u3066\u3044\u308B\u306E\u3067\u6574\u5F62\u3057\u306A\u3044\
    \n    // clang-format off\n    return r == 0 ? n : r == 1 ? 1 : r == 2 ? n + 1\
    \ : 0;\n    // clang-format on\n}\n/**\n * @brief 0 \u4EE5\u4E0A n \u4EE5\u4E0B\
    \u306E\u6574\u6570\u306E\u3046\u3061\u3001i \u30D3\u30C3\u30C8\u76EE\u304C\u7ACB\
    \u3063\u3066\u3044\u308B\u3082\u306E\u306E\u6570\n */\ninline constexpr long long\
    \ bit_count_upto(long long n, long long i) {\n    assert(0 <= n && n < 0x7fffffffffffffffLL\
    \ && 0 <= i && i < 63);\n    // 2^(i + 1) \u3054\u3068\u306B\u3001\u5F8C\u534A\
    \u306E 2^i \u500B\u3067\u7ACB\u3064\n    unsigned long long m = static_cast<unsigned\
    \ long long>(n) + 1, half = 1ULL << i, cycle = half << 1;\n    unsigned long long\
    \ r = m % cycle;\n    return static_cast<long long>(m / cycle * half + (r > half\
    \ ? r - half : 0));\n}\n\nnamespace internal_bit {\n// \u7BC4\u56F2 for \u3067\
    \u4F7F\u3046\u5217\u6319\u3002next \u3067\u6B21\u306E\u5024\u306B\u9032\u307F\u3001\
    done \u306B\u306A\u3063\u305F\u3089\u7D42\u308F\u308B\ntemplate <class Next>\n\
    struct BitEnumeration {\n    long long first;\n    bool empty;\n    Next next;\
    \  // next(s) \u306F\u6B21\u306E\u5024\u3001\u7D42\u308F\u308A\u306A\u3089 -1\n\
    \    struct iterator {\n        using value_type = long long;\n        using difference_type\
    \ = std::ptrdiff_t;\n        using pointer = void;\n        using reference =\
    \ value_type;\n        using iterator_category = std::input_iterator_tag;\n  \
    \      using iterator_concept = std::forward_iterator_tag;\n\n        long long\
    \ s = -1;\n        const Next* next = nullptr;\n        constexpr long long operator*()\
    \ const { return s; }\n        constexpr iterator& operator++() {\n          \
    \  s = (*next)(s);\n            return *this;\n        }\n        constexpr iterator\
    \ operator++(int) {\n            auto previous = *this;\n            ++*this;\n\
    \            return previous;\n        }\n        constexpr bool operator!=(const\
    \ iterator& other) const { return s != other.s; }\n        constexpr bool operator==(const\
    \ iterator& other) const { return s == other.s; }\n    };\n    constexpr iterator\
    \ begin() const { return {empty ? -1 : first, &next}; }\n    constexpr iterator\
    \ end() const { return {-1, &next}; }\n};\nstruct Bits {\n    long long mask;\n\
    \    struct iterator {\n        using value_type = long long;\n        using difference_type\
    \ = std::ptrdiff_t;\n        using pointer = void;\n        using reference =\
    \ value_type;\n        using iterator_category = std::input_iterator_tag;\n  \
    \      using iterator_concept = std::forward_iterator_tag;\n\n        long long\
    \ s = 0;\n        constexpr long long operator*() const { return countr_zero(s);\
    \ }\n        constexpr iterator& operator++() {\n            s &= s - 1;\n   \
    \         return *this;\n        }\n        constexpr iterator operator++(int)\
    \ {\n            auto previous = *this;\n            ++*this;\n            return\
    \ previous;\n        }\n        constexpr bool operator!=(const iterator& other)\
    \ const { return s != other.s; }\n        constexpr bool operator==(const iterator&\
    \ other) const { return s == other.s; }\n    };\n    constexpr iterator begin()\
    \ const { return {mask}; }\n    constexpr iterator end() const { return {0}; }\n\
    };\n\nstruct SubsetPairs {\n    long long n;\n    struct iterator {\n        using\
    \ value_type = std::pair<long long, long long>;\n        using difference_type\
    \ = std::ptrdiff_t;\n        using pointer = void;\n        using reference =\
    \ value_type;\n        using iterator_category = std::input_iterator_tag;\n  \
    \      using iterator_concept = std::forward_iterator_tag;\n\n        long long\
    \ s = 0, t = 0;\n        constexpr std::pair<long long, long long> operator*()\
    \ const { return {s, t}; }\n        constexpr iterator& operator++() {\n     \
    \       if (t == 0) {\n                t = ++s;\n            } else {\n      \
    \          t = (t - 1) & s;\n            }\n            return *this;\n      \
    \  }\n        constexpr iterator operator++(int) {\n            auto previous\
    \ = *this;\n            ++*this;\n            return previous;\n        }\n  \
    \      constexpr bool operator!=(const iterator& other) const { return s != other.s\
    \ || t != other.t; }\n        constexpr bool operator==(const iterator& other)\
    \ const { return s == other.s && t == other.t; }\n    };\n    constexpr iterator\
    \ begin() const { return {0, 0}; }\n    constexpr iterator end() const { return\
    \ {1LL << n, 1LL << n}; }\n};\n\nstruct SubsetsNext {\n    long long mask;\n \
    \   constexpr long long operator()(long long s) const { return s == 0 ? -1 : (s\
    \ - 1) & mask; }\n};\nstruct SupersetsNext {\n    long long mask, full;\n    constexpr\
    \ long long operator()(long long s) const { return s == full ? -1 : (s + 1) |\
    \ mask; }\n};\nstruct CombinationsNext {\n    long long limit;\n    constexpr\
    \ long long operator()(long long s) const;\n};\nstruct FixedSubsetsNext {\n  \
    \  long long mask, k;\n    constexpr long long lowest(long long count) const {\n\
    \        long long res = 0, rest = mask;\n        for (long long j = 0; j < count;\
    \ j++) {\n            res |= rest & -rest;\n            rest &= rest - 1;\n  \
    \      }\n        return res;\n    }\n    constexpr long long operator()(long\
    \ long s) const {\n        if (s == 0) return -1;\n        // mask \u306E\u5916\
    \u306E\u30D3\u30C3\u30C8\u3092 1 \u3068\u307F\u306A\u3057\u3066\u6700\u4E0B\u4F4D\
    \u30D3\u30C3\u30C8\u3092\u8DB3\u3059\u3068\u3001\u7E70\u308A\u4E0A\u304C\u308A\
    \u304C mask \u306E\u4E2D\u3060\u3051\u3092\u9032\u3080\u3002\n        unsigned\
    \ long long c = s & -s, r = ((static_cast<unsigned long long>(s) | ~static_cast<unsigned\
    \ long long>(mask)) + c) & static_cast<unsigned long long>(mask);\n        if\
    \ (r == 0) return -1;\n        return static_cast<long long>(r) | lowest(k - popcount(static_cast<long\
    \ long>(r)));\n    }\n};\n\ntemplate <class Next>\nconstexpr BitEnumeration<Next>\
    \ make_bit_enumeration(long long first, bool empty, Next next) {\n    return {first,\
    \ empty, next};\n}\n}  // namespace internal_bit\n\n/**\n * @brief mask \u306E\
    \u90E8\u5206\u96C6\u5408\u3092 mask \u304B\u3089 0 \u307E\u3067\u964D\u9806\u306B\
    \u5217\u6319\u3059\u308B (0 \u3068 mask \u3092\u542B\u3080) \u5168\u4F53\u3067\
    \ O(2^popcount(mask))\n */\ninline constexpr auto subsets(long long mask) {\n\
    \    assert(mask >= 0);\n    return internal_bit::make_bit_enumeration(mask, false,\
    \ internal_bit::SubsetsNext{mask});\n}\n/**\n * @brief n \u30D3\u30C3\u30C8\u306E\
    \u96C6\u5408\u306E\u3046\u3061 mask \u3092\u542B\u3080\u3082\u306E\u3092 mask\
    \ \u304B\u3089\u6607\u9806\u306B\u5217\u6319\u3059\u308B (mask \u3068 2^n - 1\
    \ \u3092\u542B\u3080) \u5168\u4F53\u3067 O(2^(n - popcount(mask)))\n */\ninline\
    \ constexpr auto supersets(long long mask, long long n) {\n    assert(0 <= n &&\
    \ n <= 62 && 0 <= mask && mask < (1LL << n));\n    long long full = (1LL << n)\
    \ - 1;\n    return internal_bit::make_bit_enumeration(mask, false, internal_bit::SupersetsNext{mask,\
    \ full});\n}\n/**\n * @brief mask \u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\
    \u30C8\u306E\u4F4D\u7F6E\u3092\u6607\u9806\u306B\u5217\u6319\u3059\u308B \u5168\
    \u4F53\u3067 O(popcount(mask))\n */\ninline constexpr auto bits(long long mask)\
    \ {\n    assert(mask >= 0);\n    // \u5185\u90E8\u3067\u306F\u6B8B\u308A\u306E\
    \u30D3\u30C3\u30C8\u3092\u6301\u3061\u3001* \u3067\u6700\u4E0B\u4F4D\u30D3\u30C3\
    \u30C8\u306E\u4F4D\u7F6E\u3092\u8FD4\u3059\n    return internal_bit::Bits{mask};\n\
    }\n/**\n * @brief s \u3068\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u306E\
    \u6570\u304C\u540C\u3058\u3067\u3001s \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\
    \u306E\u5024 (Gosper's hack)\n * long long \u306B\u53CE\u307E\u3089\u306A\u3051\
    \u308C\u3070 -1\n */\ninline constexpr long long next_combination_mask(long long\
    \ s) {\n    assert(s > 0);\n    unsigned long long u = s, c = u & -u, r = u +\
    \ c;\n    unsigned long long t = (((r ^ u) >> 2) / c) | r;\n    return t > 0x7fffffffffffffffULL\
    \ ? -1 : static_cast<long long>(t);\n}\nconstexpr long long internal_bit::CombinationsNext::operator()(long\
    \ long s) const {\n    if (s == 0) return -1;\n    long long t = next_combination_mask(s);\n\
    \    return t >= limit ? -1 : t;\n}\n\n/**\n * @brief n \u30D3\u30C3\u30C8\u306E\
    \u96C6\u5408\u306E\u3046\u3061\u3001\u3061\u3087\u3046\u3069 k \u500B\u306E\u30D3\
    \u30C3\u30C8\u304C\u7ACB\u3064\u3082\u306E\u3092\u6607\u9806\u306B\u5217\u6319\
    \u3059\u308B (Gosper's hack) \u5168\u4F53\u3067 O(C(n, k))\n * k > n \u306A\u3089\
    \u4F55\u3082\u5217\u6319\u3057\u306A\u3044\n */\ninline constexpr auto combinations_mask(long\
    \ long n, long long k) {\n    assert(0 <= n && n <= 62 && 0 <= k);\n    long long\
    \ limit = 1LL << n;\n    return internal_bit::make_bit_enumeration(k > n ? -1\
    \ : (1LL << k) - 1, k > n, internal_bit::CombinationsNext{limit});\n}\n/**\n *\
    \ @brief mask \u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\u3001\u3061\u3087\
    \u3046\u3069 k \u500B\u306E\u30D3\u30C3\u30C8\u304C\u7ACB\u3064\u3082\u306E\u3092\
    \u6607\u9806\u306B\u5217\u6319\u3059\u308B 1 \u3064\u3042\u305F\u308A O(k)\n *\
    \ k > popcount(mask) \u306A\u3089\u4F55\u3082\u5217\u6319\u3057\u306A\u3044\n\
    \ */\ninline constexpr auto subsets_of_size(long long mask, long long k) {\n \
    \   assert(mask >= 0 && 0 <= k);\n    const internal_bit::FixedSubsetsNext next{mask,\
    \ k};\n    bool empty = k > popcount(mask);\n    return internal_bit::make_bit_enumeration(empty\
    \ ? -1 : next.lowest(k), empty, next);\n}\n\nnamespace internal_bit {\n// rest\
    \ \u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8 i \u3092\u6607\u9806\u306B\
    \u3001(i, mask ^ (1 << i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B\nstruct\
    \ ToggleOneBit {\n    long long mask, rest;\n    struct iterator {\n        using\
    \ value_type = std::pair<long long, long long>;\n        using difference_type\
    \ = std::ptrdiff_t;\n        using pointer = void;\n        using reference =\
    \ value_type;\n        using iterator_category = std::input_iterator_tag;\n  \
    \      using iterator_concept = std::forward_iterator_tag;\n\n        long long\
    \ mask = 0, s = 0;\n        constexpr std::pair<long long, long long> operator*()\
    \ const {\n            long long i = countr_zero(s);\n            return {i, mask\
    \ ^ (1LL << i)};\n        }\n        constexpr iterator& operator++() {\n    \
    \        s &= s - 1;\n            return *this;\n        }\n        constexpr\
    \ iterator operator++(int) {\n            auto previous = *this;\n           \
    \ ++*this;\n            return previous;\n        }\n        constexpr bool operator!=(const\
    \ iterator& other) const { return s != other.s; }\n        constexpr bool operator==(const\
    \ iterator& other) const { return s == other.s; }\n    };\n    constexpr iterator\
    \ begin() const { return {mask, rest}; }\n    constexpr iterator end() const {\
    \ return {mask, 0}; }\n};\n}  // namespace internal_bit\n\n/**\n * @brief n \u30D3\
    \u30C3\u30C8\u306E\u3046\u3061 mask \u306B\u542B\u307E\u308C\u306A\u3044\u4F4D\
    \u7F6E i \u3092\u6607\u9806\u306B\u3001(i, mask | (1 << i)) \u306E\u7D44\u3067\
    \u5217\u6319\u3059\u308B \u5168\u4F53\u3067 O(n - popcount(mask))\n * bit DP \u3067\
    \ 1 \u3064\u8981\u7D20\u3092\u8DB3\u3059\u9077\u79FB\u306B\u4F7F\u3046\n */\n\
    inline constexpr internal_bit::ToggleOneBit add_one(long long mask, long long\
    \ n) {\n    assert(0 <= n && n <= 62 && 0 <= mask && mask < (1LL << n));\n   \
    \ return {mask, ((1LL << n) - 1) ^ mask};\n}\n/**\n * @brief mask \u306B\u542B\
    \u307E\u308C\u308B\u4F4D\u7F6E i \u3092\u6607\u9806\u306B\u3001(i, mask ^ (1 <<\
    \ i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B \u5168\u4F53\u3067 O(popcount(mask))\n\
    \ * bit DP \u3067 1 \u3064\u8981\u7D20\u3092\u9664\u3044\u305F\u96C6\u5408\u304B\
    \u3089\u9077\u79FB\u3059\u308B\u3068\u304D\u306B\u4F7F\u3046\n */\ninline constexpr\
    \ internal_bit::ToggleOneBit remove_one(long long mask) {\n    assert(mask >=\
    \ 0);\n    return {mask, mask};\n}\n\n/**\n * @brief n \u30D3\u30C3\u30C8\u306E\
    \u3059\u3079\u3066\u306E\u96C6\u5408 S \u3068\u3001\u305D\u306E\u90E8\u5206\u96C6\
    \u5408 T \u306E\u7D44 (S, T) \u3092\u5217\u6319\u3059\u308B \u5168\u4F53\u3067\
    \ O(3^n)\n * S \u306F 0 \u304B\u3089\u6607\u9806\u3001\u5404 S \u306E\u4E2D\u3067\
    \ T \u306F S \u304B\u3089 0 \u307E\u3067\u964D\u9806\n */\ninline constexpr auto\
    \ subset_pairs(long long n) {\n    assert(0 <= n && n <= 62);\n    return internal_bit::SubsetPairs{n};\n\
    }\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\
    \u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include <functional>\n\
    #line 11 \"src/utility/traits.hpp\"\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\
    \n\n#if __cplusplus >= 202002L\n#include <concepts>\n#include <ranges>\n#endif\n\
    \nnamespace internal_traits {\nusing std::begin, std::end;\n\n#if __cplusplus\
    \ >= 202002L\ntemplate <class T>\n    struct is_range_impl : std::bool_constant\
    \ < requires(T& t) {\n    begin(t);\n    end(t);\n}>{};\n#else\ntemplate <class\
    \ T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate <class\
    \ T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n#endif\n\n// \u30B5\u30A4\u30BA\
    \u4ED8\u304D\u7BC4\u56F2\u304B\u3089\u8981\u7D20\u3092\u76F4\u63A5\u69CB\u7BC9\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u5171\u6709\u3059\
    \u308B\u3002\n#if __cplusplus >= 202002L\ntemplate <class R, class S>\nconcept\
    \ sized_constructible_range = std::ranges::input_range<R> && std::ranges::sized_range<R>\
    \ &&\n                                    std::is_constructible_v<S, std::ranges::range_reference_t<R>>;\n\
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
    \n#if __cplusplus >= 202002L\n#define HAS_METHOD(func_name)                  \
    \                                                 \\\n    namespace internal_traits\
    \ {                                                                 \\\n    template\
    \ <class T>                                                                  \
    \        \\\n    concept has_##func_name##_impl = requires { std::declval<T>().func_name();\
    \ };               \\\n    }                                                 \
    \                                          \\\n    template <class T>        \
    \                                                                  \\\n    struct\
    \ has_##func_name : std::bool_constant<internal_traits::has_##func_name##_impl<T>>\
    \ {}; \\\n    template <class T>                                             \
    \                             \\\n    inline constexpr bool has_##func_name##_v\
    \ = has_##func_name<T>::value;\n\n#define HAS_METHOD_ARG(func_name)          \
    \                                                        \\\n    namespace internal_traits\
    \ {                                                                    \\\n  \
    \  template <class T, class U>                                               \
    \                     \\\n    concept has_##func_name##_impl = requires { std::declval<T>().func_name(std::declval<U>());\
    \ }; \\\n    }                                                               \
    \                               \\\n    template <class T, class U>          \
    \                                                          \\\n    struct has_##func_name\
    \ : std::bool_constant<internal_traits::has_##func_name##_impl<T, U>> {}; \\\n\
    \    template <class T, class U>                                             \
    \                       \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T,\
    \ U>::value;\n#else\n#define HAS_METHOD(func_name)                           \
    \                                   \\\n    namespace internal_traits {      \
    \                                                      \\\n    template <class\
    \ T, class = void>                                                       \\\n\
    \    struct has_##func_name##_impl : std::false_type {};                     \
    \               \\\n    template <class T>                                   \
    \                                  \\\n    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
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
    #endif\n\nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\n\
    HAS_METHOD(max)\nHAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\n\
    HAS_METHOD(product)\nHAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\n\
    HAS_METHOD_ARG(lower_bound)\nHAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr)\
    \ std::enable_if_t<expr, std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
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
    #line 17 \"src/data_structures/disjoint-sparse-table.hpp\"\n\ntemplate <typename\
    \ M>\nclass DisjointSparseTable {\n   public:\n    using S = typename M::S;\n\n\
    \   private:\n    M m;\n    long long n;\n    std::vector<S> values;\n    std::vector<std::vector<S>>\
    \ table;\n\n   public:\n#if __cplusplus >= 202002L\n    template <class R = std::initializer_list<S>>\n\
    \        requires internal_traits::sized_constructible_range<R, S>\n#else\n  \
    \  template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit DisjointSparseTable(R&& v = {}, M m = M())\
    \ : m(std::move(m)), n(internal_traits::range_size(v)) {\n        values.reserve(n);\n\
    \        for (auto&& x : v) values.emplace_back(std::forward<decltype(x)>(x));\n\
    \        const int height = n <= 1 ? 0 : static_cast<int>(bit_width(n - 1));\n\
    \        table.reserve(height);\n        for (int k = 0; k < height; ++k) {\n\
    \            const long long half = 1LL << k;\n            std::vector<S> row(n,\
    \ this->m.e());\n            for (long long l = 0; l < n; l += 2 * half) {\n \
    \               const long long mid = std::min(n, l + half), r = std::min(n, l\
    \ + 2 * half);\n                row[mid - 1] = values[mid - 1];\n            \
    \    for (long long i = mid - 1; i > l; --i) row[i - 1] = this->m.op(values[i\
    \ - 1], row[i]);\n                if (mid < r) {\n                    row[mid]\
    \ = values[mid];\n                    for (long long i = mid + 1; i < r; ++i)\
    \ row[i] = this->m.op(row[i - 1], values[i]);\n                }\n           \
    \ }\n            table.push_back(std::move(row));\n        }\n    }\n\n    long\
    \ long size() const { return n; }\n    S get(long long k) const {\n        assert(0\
    \ <= k && k < n);\n        return values[k];\n    }\n    S prod(long long l, long\
    \ long r) const {\n        assert(0 <= l && l <= r && r <= n);\n        if (l\
    \ == r) return m.e();\n        if (r - l == 1) return values[l];\n        const\
    \ int k = static_cast<int>(bit_width(l ^ (r - 1))) - 1;\n        return m.op(table[k][l],\
    \ table[k][r - 1]);\n    }\n    S all_prod() const { return prod(0, n); }\n};\n\
    \ntemplate <class R, typename M>\nDisjointSparseTable(R&&, M) -> DisjointSparseTable<M>;\n\
    template <typename M>\nDisjointSparseTable(std::initializer_list<typename M::S>,\
    \ M) -> DisjointSparseTable<M>;\n#line 4 \"test/unittest/data_structures/disjoint-sparse-table.test.cpp\"\
    \n\n#line 6 \"test/unittest/data_structures/disjoint-sparse-table.test.cpp\"\n\
    #include <iostream>\n#line 8 \"test/unittest/data_structures/disjoint-sparse-table.test.cpp\"\
    \n#include <list>\n#include <random>\n#include <sstream>\n#line 14 \"test/unittest/data_structures/disjoint-sparse-table.test.cpp\"\
    \n\n#line 2 \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n * @brief \u56DB\
    \u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\
    \u30AF\u30E9\u30B9\n */\n\n#line 9 \"src/math/modint.hpp\"\n#include <cstdint>\n\
    #line 14 \"src/math/modint.hpp\"\n\n#line 16 \"src/math/modint.hpp\"\n\nnamespace\
    \ internal_modint {\n// clang-format off\nstatic constexpr std::uint16_t prime32_bases[]\
    \ {\n    15591,  2018,  166, 7429,  8064, 16045, 10503,  4399,  1949,  1295, 2776,\
    \  3620,   560,  3128,  5212,  2657,\n     2300,  2021, 4652, 1471,  9336,  4018,\
    \  2398, 20462, 10277,  8028, 2213,  6219,   620,  3763,  4852,  5012,\n     3185,\
    \  1333, 6227, 5298,  1074,  2391,  5113,  7061,   803,  1269, 3875,   422,  \
    \ 751,   580,  4729, 10239,\n      746,  2951,  556, 2206,  3778,   481,  1522,\
    \  3476,   481,  2487, 3266,  5633,   488,  3373,  6441,  3344,\n       17, 15105,\
    \ 1490, 4154,  2036,  1882,  1813,   467,  3307, 14042, 6371,   658,  1005,  \
    \ 903,   737,  1887,\n     7447,  1888, 2848, 1784,  7559,  3400,   951, 13969,\
    \  4304,   177,   41, 19875,  3110, 13221,  8726,   571,\n     7043,  6943, 1199,\
    \  352,  6435,   165,  1169,  3315,   978,   233, 3003,  2562,  2994, 10587, 10030,\
    \  2377,\n     1902,  5354, 4447, 1555,   263, 27027,  2283,   305,   669,  1912,\
    \  601,  6186,   429,  1930, 14873,  1784,\n     1661,   524, 3577,  236,  2360,\
    \  6146,  2850, 55637,  1753,  4178, 8466,   222,  2579,  2743,  2031,  2226,\n\
    \     2276,   374, 2132,  813, 23788,  1610,  4422,  5159,  1725,  3597, 3366,\
    \ 14336,   579,   165,  1375, 10018,\n    12616,  9816, 1371,  536,  1867, 10864,\
    \   857,  2206,  5788,   434, 8085, 17618,   727,  3639,  1595,  4944,\n     2129,\
    \  2029, 8195, 8344,  6232,  9183,  8126,  1870,  3296,  7455, 8947, 25017,  \
    \ 541, 19115,   368,   566,\n     5674,   411,  522, 1027,  8215,  2050,  6544,\
    \ 10049,   614,   774, 2333,  3007, 35201,  4706,  1152,  1785,\n     1028,  1540,\
    \ 3743,  493,  4474,  2521, 26845,  8354,   864, 18915, 5465,  2447,    42,  4511,\
    \  1660,   166,\n     1249,  6259, 2553,  304,   272,  7286,    73,  6554,   899,\
    \  2816, 5197, 13330,  7054,  2818,  3199,   811,\n      922,   350, 7514, 4452,\
    \  3449,  2663,  4708,   418,  1621,  1171, 3471,    88, 11345,   412,  1559,\
    \   194,\n};\n// clang-format on\n\nstatic constexpr bool is_SPRP(std::uint32_t\
    \ n, std::uint32_t a) noexcept {\n    std::uint32_t d = n - 1;\n    std::uint32_t\
    \ s = 0;\n    while ((d & 1) == 0) {\n        ++s;\n        d >>= 1;\n    }\n\
    \    std::uint64_t cur = 1;\n    std::uint64_t pw = d;\n    while (pw) {\n   \
    \     if (pw & 1) cur = (cur * a) % n;\n        a = (static_cast<std::uint64_t>(a)\
    \ * a) % n;\n        pw >>= 1;\n    }\n    if (cur == 1) return true;\n    for\
    \ (std::uint32_t r = 0; r < s; ++r) {\n        if (cur == n - 1) return true;\n\
    \        cur = (cur * cur) % n;\n    }\n    return false;\n}\n\n// 32\u30D3\u30C3\
    \u30C8\u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u7D20\u6570\u5224\u5B9A\n// \u53C2\
    \u8003: M. Forisek and J. Jancina, \u201CFast Primality Testing for Integers That\
    \ Fit into a Machine Word,\u201D presented at the Conference on Current Trends\
    \ in Theory and Practice of Informatics, 2015.\n[[nodiscard]]\nstatic constexpr\
    \ bool is_prime32(std::uint32_t x) noexcept {\n    if (x == 2 || x == 3 || x ==\
    \ 5 || x == 7) return true;\n    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 ||\
    \ x % 7 == 0) return false;\n    if (x < 121) return (x > 1);\n    std::uint64_t\
    \ h = x;\n    h = ((h >> 16) ^ h) * 0x45d9f3b;\n    h = ((h >> 16) ^ h) * 0x45d9f3b;\n\
    \    h = ((h >> 16) ^ h) & 0xff;\n    return is_SPRP(x, prime32_bases[h]);\n}\n\
    }  // namespace internal_modint\n\n/// @brief static_modint \u3068 dynamic_modint\
    \ \u306E\u5B9F\u88C5\u3092 CRTP \u306B\u3088\u3063\u3066\u884C\u3046\u305F\u3081\
    \u306E\u30AF\u30E9\u30B9\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n/// @tparam Modint\
    \ \u3053\u306E\u30AF\u30E9\u30B9\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u7D99\
    \u627F\u3059\u308B\u30AF\u30E9\u30B9\ntemplate <class Modint>\nclass modint_base\
    \ {\n   public:\n    /// @brief \u4FDD\u6301\u3059\u308B\u5024\u306E\u578B\n \
    \   using value_type = std::uint32_t;\n\n    /// @brief 0 \u3067\u521D\u671F\u5316\
    \u3057\u307E\u3059\u3002\n    constexpr modint_base() noexcept\n        : m_value{0}\
    \ {}\n\n    /// @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\
    \u307E\u3059\u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\
    \n    template <class SignedIntegral, ENABLE_IF_T((std::is_integral_v<SignedIntegral>\
    \ && std::is_signed_v<SignedIntegral>))>\n    constexpr modint_base(SignedIntegral\
    \ value) noexcept\n        : m_value{static_cast<value_type>((static_cast<long\
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
    using modint = dynamic_modint<-1>;\n#line 16 \"test/unittest/data_structures/disjoint-sparse-table.test.cpp\"\
    \n\nstruct ExplicitSum {\n    struct S {\n        long long value;\n        explicit\
    \ S(long long x) : value(x) {}\n    };\n    static S e() { return S(0); }\n  \
    \  static S op(const S& a, const S& b) { return S(a.value + b.value); }\n};\n\n\
    struct InputRange {\n    std::istringstream input{\"1 2 3\"};\n    auto begin()\
    \ { return std::istream_iterator<int>(input); }\n    auto end() { return std::istream_iterator<int>();\
    \ }\n    long long size() const { return 3; }\n};\n\nint main() {\n    using mint\
    \ = modint998244353;\n    std::mt19937 rng(314);\n    for (int n = 0; n <= 130;\
    \ ++n) {\n        std::vector<Affine<mint>> a(n);\n        for (auto& f : a) f\
    \ = {rng() % 10, rng() % 10};\n        DisjointSparseTable<monoid::Composite<mint>>\
    \ table(a);\n        for (int l = 0; l <= n; ++l) {\n            Affine<mint>\
    \ expected;\n            for (int r = l; r <= n; ++r) {\n                if (table.prod(l,\
    \ r) != expected) return 1;\n                if (r < n) expected = monoid::Composite<mint>::op(expected,\
    \ a[r]);\n            }\n        }\n        if (table.size() != n || table.all_prod()\
    \ != table.prod(0, n)) return 1;\n        for (int i = 0; i < n; ++i)\n      \
    \      if (table.get(i) != a[i]) return 1;\n    }\n    auto check = [](auto&&\
    \ range) {\n        DisjointSparseTable st(std::forward<decltype(range)>(range),\
    \ ExplicitSum{});\n        return st.size() == 3 && st.all_prod().value == 6 &&\
    \ st.prod(1, 3).value == 5;\n    };\n    int raw[] = {1, 2, 3};\n    const std::array<int,\
    \ 3> arr = {1, 2, 3};\n    if (!check(raw) || !check(arr) || !check(std::list<int>{1,\
    \ 2, 3}) || !check(InputRange{})) return 1;\n#if __cplusplus >= 202002L\n    if\
    \ (!check(std::views::iota(1, 4))) return 1;\n#endif\n    DisjointSparseTable<ExplicitSum>\
    \ empty;\n    if (empty.size() != 0 || empty.all_prod().value != 0) return 1;\n\
    \    DisjointSparseTable<monoid::Sum<long long>> singleton({7});\n    if (singleton.prod(0,\
    \ 1) != 7 || singleton.prod(1, 1) != 0) return 1;\n    DisjointSparseTable braces({1LL,\
    \ 2LL, 3LL}, monoid::Sum<long long>{});\n    if (braces.all_prod() != 6) return\
    \ 1;\n    DisjointSparseTable stateful(std::array<std::string, 3>{\"a\", \"b\"\
    , \"c\"},\n                                 Monoid([reverse = true](const std::string&\
    \ a, const std::string& b) { return reverse ? b + a : a + b; }, std::string{}));\n\
    \    if (stateful.prod(0, 3) != \"cba\" || stateful.prod(1, 3) != \"cb\") return\
    \ 1;\n    static_assert(!std::is_constructible_v<DisjointSparseTable<ExplicitSum>,\
    \ std::vector<std::string>&>);\n    std::cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../../src/data_structures/disjoint-sparse-table.hpp\"\n\n#include\
    \ <array>\n#include <iostream>\n#include <iterator>\n#include <list>\n#include\
    \ <random>\n#include <sstream>\n#include <string>\n#include <type_traits>\n#include\
    \ <vector>\n\n#include \"../../../src/math/modint.hpp\"\n\nstruct ExplicitSum\
    \ {\n    struct S {\n        long long value;\n        explicit S(long long x)\
    \ : value(x) {}\n    };\n    static S e() { return S(0); }\n    static S op(const\
    \ S& a, const S& b) { return S(a.value + b.value); }\n};\n\nstruct InputRange\
    \ {\n    std::istringstream input{\"1 2 3\"};\n    auto begin() { return std::istream_iterator<int>(input);\
    \ }\n    auto end() { return std::istream_iterator<int>(); }\n    long long size()\
    \ const { return 3; }\n};\n\nint main() {\n    using mint = modint998244353;\n\
    \    std::mt19937 rng(314);\n    for (int n = 0; n <= 130; ++n) {\n        std::vector<Affine<mint>>\
    \ a(n);\n        for (auto& f : a) f = {rng() % 10, rng() % 10};\n        DisjointSparseTable<monoid::Composite<mint>>\
    \ table(a);\n        for (int l = 0; l <= n; ++l) {\n            Affine<mint>\
    \ expected;\n            for (int r = l; r <= n; ++r) {\n                if (table.prod(l,\
    \ r) != expected) return 1;\n                if (r < n) expected = monoid::Composite<mint>::op(expected,\
    \ a[r]);\n            }\n        }\n        if (table.size() != n || table.all_prod()\
    \ != table.prod(0, n)) return 1;\n        for (int i = 0; i < n; ++i)\n      \
    \      if (table.get(i) != a[i]) return 1;\n    }\n    auto check = [](auto&&\
    \ range) {\n        DisjointSparseTable st(std::forward<decltype(range)>(range),\
    \ ExplicitSum{});\n        return st.size() == 3 && st.all_prod().value == 6 &&\
    \ st.prod(1, 3).value == 5;\n    };\n    int raw[] = {1, 2, 3};\n    const std::array<int,\
    \ 3> arr = {1, 2, 3};\n    if (!check(raw) || !check(arr) || !check(std::list<int>{1,\
    \ 2, 3}) || !check(InputRange{})) return 1;\n#if __cplusplus >= 202002L\n    if\
    \ (!check(std::views::iota(1, 4))) return 1;\n#endif\n    DisjointSparseTable<ExplicitSum>\
    \ empty;\n    if (empty.size() != 0 || empty.all_prod().value != 0) return 1;\n\
    \    DisjointSparseTable<monoid::Sum<long long>> singleton({7});\n    if (singleton.prod(0,\
    \ 1) != 7 || singleton.prod(1, 1) != 0) return 1;\n    DisjointSparseTable braces({1LL,\
    \ 2LL, 3LL}, monoid::Sum<long long>{});\n    if (braces.all_prod() != 6) return\
    \ 1;\n    DisjointSparseTable stateful(std::array<std::string, 3>{\"a\", \"b\"\
    , \"c\"},\n                                 Monoid([reverse = true](const std::string&\
    \ a, const std::string& b) { return reverse ? b + a : a + b; }, std::string{}));\n\
    \    if (stateful.prod(0, 3) != \"cba\" || stateful.prod(1, 3) != \"cb\") return\
    \ 1;\n    static_assert(!std::is_constructible_v<DisjointSparseTable<ExplicitSum>,\
    \ std::vector<std::string>&>);\n    std::cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - src/data_structures/disjoint-sparse-table.hpp
  - src/algebra/monoid.hpp
  - src/utility/bit.hpp
  - src/utility/traits.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/disjoint-sparse-table.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 04:55:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/disjoint-sparse-table.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/disjoint-sparse-table.test.cpp
- /verify/test/unittest/data_structures/disjoint-sparse-table.test.cpp.html
title: test/unittest/data_structures/disjoint-sparse-table.test.cpp
---
