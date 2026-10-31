---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree.hpp
    title: "\u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/tree/lca.2.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#include <iostream>\n\n#line 2 \"src/data_structures/segtree.hpp\"\n\n/**\n\
    \ * @file segtree.hpp\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n\
    #include <cassert>\n#include <ostream>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\
    \u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\
    \n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S& a, const S& b): \u7A4D\
    \ (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n * op, e \u306F static\
    \ \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\
    \u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\n#include <algorithm>\n\
    #include <array>\n#include <cstddef>\n#include <istream>\n#include <limits>\n\
    #include <numeric>\n#include <optional>\n#line 22 \"src/algebra/monoid.hpp\"\n\
    #include <type_traits>\n#line 24 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief\
    \ 1\u6B21\u95A2\u6570 f(x) = a * x + b\n *\n * monoid::Composite \u306E\u8981\u7D20\
    \u3084 acted_monoid::AffineSum \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n *\
    \ \u4F8B: Affine<mint> f{2, 3}; f(x) \u306F 2x + 3\u3002\u7701\u7565\u3059\u308B\
    \u3068\u6052\u7B49\u5199\u50CF {1, 0}\n */\ntemplate <typename T>\nstruct Affine\
    \ {\n    T a = T(1);  //!< \u50BE\u304D\n    T b = T(0);  //!< \u5207\u7247\n\
    \    constexpr T operator()(const T& x) const { return a * x + b; }\n    friend\
    \ constexpr bool operator==(const Affine& f, const Affine& g) { return f.a ==\
    \ g.a && f.b == g.b; }\n    friend constexpr bool operator!=(const Affine& f,\
    \ const Affine& g) { return !(f == g); }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
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
    \ T) -> Monoid<T, Op>;\n#line 14 \"src/data_structures/segtree.hpp\"\n\n/**\n\
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u4F8B:\n * SegTree<monoid::Max<int>>\
    \ seg(n);\n * SegTree seg(v, Monoid([](int a, int b) { return a + b; }, 0));\n\
    \ *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n */\ntemplate\
    \ <typename M>\nclass SegTree {\n   public:\n    using S = typename M::S;\n\n\
    \   private:\n    M m;\n    S op(const S& a, const S& b) const { return m.op(a,\
    \ b); }\n    S e() const { return m.e(); }\n\n    long long n, sz;\n    int height;\n\
    \    std::vector<S> data;\n    void update(long long k) { data[k] = op(data[2\
    \ * k], data[2 * k + 1]); }\n\n    class SegTreeReference {\n        SegTree&\
    \ segtree;\n        long long k;\n\n       public:\n        SegTreeReference(SegTree&\
    \ segtree, long long k) : segtree(segtree), k(k) {}\n        SegTreeReference&\
    \ operator=(const S& x) {\n            segtree.set(k, x);\n            return\
    \ *this;\n        }\n        operator S() const { return segtree.get(k); }\n \
    \   };\n\n    void construct_data() {\n        sz = 1;\n        height = 0;\n\
    \        while (sz < n) {\n            sz <<= 1;\n            height++;\n    \
    \    }\n        data.assign(sz * 2, e());\n    }\n\n   public:\n    /**\n    \
    \ * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param n\
    \ \u8981\u7D20\u6570\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ SegTree(long long n = 0, M m = M()) : m(std::move(m)), n(n) {\n        construct_data();\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param m \u30E2\u30CE\
    \u30A4\u30C9\n     */\n    explicit SegTree(const std::vector<S>& v, M m = M())\
    \ : SegTree(v.size(), std::move(m)) {\n        for (long long i = 0; i < n; i++)\
    \ data[sz + i] = v[i];\n        for (long long i = sz - 1; i > 0; i--) update(i);\n\
    \    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n\
    \    long long size() const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\
    \u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n \
    \   S get(long long k) const {\n        assert(0 <= k && k < n);\n        return\
    \ data[sz + k];\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\
    \u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n    S operator[](long long\
    \ k) const { return get(k); }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k\n     * @return SegTreeReference \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\
    \u5165\u3055\u308C\u308B\u3068set()\u304C\u547C\u3070\u308C\u308B\n     */\n \
    \   SegTreeReference operator[](long long k) { return SegTreeReference(*this,\
    \ k); }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n\
    \     *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\
    \u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n     * @return std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\
    \u30FC\u30E0\n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const SegTree& rhs)\
    \ {\n        for (long long i = 0; i < rhs.n; i++) {\n            if (i != 0)\
    \ os << CharT(' ');\n            os << rhs[i];\n        }\n        return os;\n\
    \    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n     *\n     * @param k \u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\u3057\u3044\u5024\n     */\n\
    \    void set(long long k, const S& x) {\n        assert(0 <= k && k < n);\n \
    \       k += sz;\n        data[k] = x;\n        for (int i = 1; i <= height; i++)\
    \ update(k >> i);\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\
    \u8981\u7D20\u306E\u5024\u306Bx\u3092\u4F5C\u7528\u3055\u305B\u308B\n     *\n\
    \     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u4F5C\u7528\
    \u7D20\n     */\n    void apply(long long k, const S& x) { set(k, op(get(k), x));\
    \ }\n\n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\u7DCF\u7A4D\u3092\
    \u8FD4\u3059\n     *\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n    \
    \ * @return S \u7DCF\u7A4D\n     */\n    S prod(long long l, long long r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        S left_prod = e(), right_prod\
    \ = e();\n        l += sz;\n        r += sz;\n        while (l < r) {\n      \
    \      if (l & 1) left_prod = op(left_prod, data[l++]);\n            if (r & 1)\
    \ right_prod = op(data[--r], right_prod);\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        return op(left_prod, right_prod);\n    }\n    /**\n\
    \     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\
    \u3059\n     *\n     * @return S \u7DCF\u7A4D\n     */\n    S all_prod() const\
    \ { return data[1]; }\n\n    /**\n     * @brief (r = l or f(prod([l, r))) = true)\
    \ and (r = n or f(prod([l, r+1))) = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\
    \n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001f(prod([l, r))) = true\u3068\u306A\
    \u308B\u6700\u5927\u306Er\n     *\n     * @tparam F\n     * @param l \u534A\u958B\
    \u533A\u9593\u306E\u958B\u59CB 0<=l<=n\n     * @param f \u5224\u5B9A\u95A2\u6570\
    \ f(e) = true\n     * @return long long\n     */\n    template <typename F>\n\
    \    long long max_right(long long l, F f) const {\n        assert(f(e()));\n\
    \        assert(0 <= l && l <= n);\n        if (l == n) return n;\n        l +=\
    \ sz;\n        while (l % 2 == 0) l >>= 1;\n        S sum = e();\n        while\
    \ (f(op(sum, data[l]))) {\n            sum = op(sum, data[l]);\n            l++;\n\
    \            while (l % 2 == 0) l >>= 1;\n            if (l == 1) return n;\n\
    \        }\n        while (l < sz) {\n            if (!f(op(sum, data[l * 2])))\n\
    \                l *= 2;\n            else {\n                sum = op(sum, data[l\
    \ * 2]);\n                l = l * 2 + 1;\n            }\n        }\n        return\
    \ l - sz;\n    }\n    /**\n     * @brief (l = 0 or f(prod([l, r))) = true) and\
    \ (l = r or f(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\u8FD4\u3059\n\
    \     * f\u304C\u5358\u8ABF\u306A\u3089\u3001f(prod([l, r))) = true\u3068\u306A\
    \u308B\u6700\u5C0F\u306El\n     *\n     * @tparam F\n     * @param r \u534A\u958B\
    \u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param f \u5224\u5B9A\u95A2\u6570\
    \ f(e) = true\n     * @return long long\n     */\n    template <typename F>\n\
    \    long long min_left(long long r, F f) const {\n        assert(f(e()));\n \
    \       assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        r +=\
    \ sz;\n        S sum = e();\n        do {\n            r--;\n            while\
    \ (r > 1 && r % 2 == 1) r >>= 1;\n            if (!f(op(data[r], sum))) {\n  \
    \              while (r < sz) {\n                    r = r * 2 + 1;\n        \
    \            if (f(op(data[r], sum))) {\n                        sum = op(data[r],\
    \ sum);\n                        r--;\n                    }\n               \
    \ }\n                return r + 1 - sz;\n            }\n            sum = op(data[r],\
    \ sum);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\ntemplate\
    \ <typename M>\nSegTree(long long, M) -> SegTree<M>;\ntemplate <typename M>\n\
    SegTree(std::vector<typename M::S>, M) -> SegTree<M>;\n\n/**\n * @brief RangeMaxQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RMaxQ = SegTree<monoid::Max<S>>;\n\
    /**\n * @brief RangeMinQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RMinQ = SegTree<monoid::Min<S>>;\n/**\n * @brief RangeSumQuery\n *\n\
    \ * @tparam S \u578B\n */\ntemplate <typename S>\nusing RSumQ = SegTree<monoid::Sum<S>>;\n\
    /**\n * @brief RangeProdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RProdQ = SegTree<monoid::Prod<S>>;\n/**\n * @brief RangeXorQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RXorQ = SegTree<monoid::Xor<S>>;\n\
    /**\n * @brief RangeGcdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RGcdQ = SegTree<monoid::Gcd<S>>;\n#line 2 \"src/graph/tree.hpp\"\n\
    \n/**\n * @file tree.hpp\n * @brief \u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n */\n\n#line 10 \"src/graph/tree.hpp\"\n#include <stack>\n\
    #line 14 \"src/graph/tree.hpp\"\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n *\
    \ @file graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 11 \"src/graph/graph.hpp\"\
    \n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n\
    \ * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B \u7701\u7565\u3057\
    \u305F\u3089 long long (\u91CD\u307F\u306E\u548C\u3084\u672A\u5230\u9054\u3092\
    \u8868\u3059 max / 4 \u304C\u3042\u3075\u308C\u306B\u304F\u3044\u3088\u3046\u306B\
    )\n */\ntemplate <typename Cost = long long>\nclass Graph {\n   public:\n    /**\n\
    \     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\n     *\n     * operator\
    \ long long()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\u306E\u3067\u3001\u6574\
    \u6570\u578B\u306B\u30AD\u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\u306B\
    dst\u306B\u306A\u308B\n     * \u4F8B\u3048\u3070\u3001\n     * for (auto& e :\
    \ g[v]) \u3092\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\u5217\
    \u6319\u3055\u308C\u308B\u304C\u3001\n     * for (long long dst : g[v]) \u3068\
    \u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\
    \u304C\u5217\u6319\u3055\u308C\u308B\n     */\n    struct Edge {\n        long\
    \ long src = -1;  //!< \u59CB\u70B9\n        long long dst = -1;  //!< \u7D42\u70B9\
    \n        Cost cost = {};      //!< \u30B3\u30B9\u30C8\n        long long id =\
    \ -1;   //!< \u8FBA\u306E\u756A\u53F7(\u8FFD\u52A0\u3055\u308C\u305F\u9806\u3001\
    \u7121\u5411\u8FBA\u306E\u5834\u5408\u306Fid\u304C\u540C\u3058\u3067\u65B9\u5411\
    \u304C\u9006\u306E\u3082\u306E\u304C2\u3064\u5B58\u5728\u3059\u308B)\n       \
    \ Edge() = default;\n        Edge(long long src, long long dst, Cost cost = 1,\
    \ long long id = -1) : src(src), dst(dst), cost(cost), id(id) {}\n        operator\
    \ long long() const { return dst; }\n    };\n\n    long long n;              \
    \         //!< \u9802\u70B9\u6570\n    long long m;                       //!<\
    \ \u8FBA\u6570\n    std::vector<std::vector<Edge>> g;  //!< \u30B0\u30E9\u30D5\
    \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\n    /**\n     * @brief \u30C7\
    \u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n\
    \    Graph() : n(0), m(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\u6570\n     */\n    explicit\
    \ Graph(long long n) : n(n), m(0), g(n) {}\n    /**\n     * @brief \u9802\u70B9\
    \u6570\n     */\n    long long size() const { return n; }\n    /**\n     * @brief\
    \ \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\
    \n     * @param v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\
    \u3057\u305F\u30891\n     */\n    void add_edge(long long u, long long v, Cost\
    \ w = 1) {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u,\
    \ v, w, m});\n        g[v].push_back({v, u, w, m++});\n    }\n    /**\n     *\
    \ @brief \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\
    \u70B9\n     * @param v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\
    \u7565\u3057\u305F\u30891\n     */\n    void add_directed_edge(long long u, long\
    \ long v, Cost w = 1) {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n\
    \        g[u].push_back({u, v, w, m++});\n    }\n    /**\n     * @brief \u8FBA\
    \u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\
    \u3063\u3066\u8FFD\u52A0\u3059\u308B\n     * @param m \u8FBA\u306E\u6570\n   \
    \  * @param padding \u9802\u70B9\u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\
    \u304F\u3064\u305A\u3089\u3059\u304B \u7701\u7565\u3057\u305F\u3089-1\n     *\
    \ @param weighted \u8FBA\u306E\u91CD\u307F\u304C\u5165\u529B\u3055\u308C\u308B\
    \u304B \u7701\u7565\u3057\u305F\u3089false\u3068\u306A\u308A\u3001\u91CD\u307F\
    1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\u308C\u308B\n     * @param directed \u6709\
    \u5411\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B \u7701\u7565\u3057\u305F\u3089\
    false\n     */\n    void read(long long m, long long padding = -1, bool weighted\
    \ = false, bool directed = false) {\n        for (long long i = 0; i < m; i++)\
    \ {\n            long long u, v;\n            std::cin >> u >> v;\n          \
    \  u += padding, v += padding;\n            Cost c(1);\n            if (weighted)\n\
    \                std::cin >> c;\n            if (directed)\n                add_directed_edge(u,\
    \ v, c);\n            else\n                add_edge(u, v, c);\n        }\n  \
    \  }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\
    \u3092\u5217\u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n   \
    \  * @return std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\
    \u30C8\n     */\n    std::vector<Edge>& operator[](long long v) {\n        return\
    \ g[v];\n    }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\
    \u308B\u8FBA\u3092\u5217\u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\
    \u53F7\n     * @return const std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\
    \u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<Edge>& operator[](long\
    \ long v) const {\n        return g[v];\n    }\n    /**\n     * @brief \u8FBA\u306E\
    \u30EA\u30B9\u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\u30EA\u30B9\u30C8\
    (id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\u4EE3\u8868\u3057\
    \u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\u3002\u305D\u306E src\
    \ \u3068 dst \u306E\u5411\u304D\u306F\u898F\u5B9A\u3057\u306A\u3044\n     * \u6709\
    \u5411\u8FBA\u306F\u8FFD\u52A0\u3057\u305F\u3068\u304D\u306E\u5411\u304D\u306E\
    \u307E\u307E\u683C\u7D0D\u3055\u308C\u308B\n     */\n    std::vector<Edge> edges()\
    \ const {\n        std::vector<Edge> res(m);\n        for (long long i = 0; i\
    \ < n; i++) {\n            for (auto& e : g[i]) {\n                res[e.id] =\
    \ e;\n            }\n        }\n        return res;\n    }\n};\n#line 16 \"src/graph/tree.hpp\"\
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
    \ Graph<Cost>::Edge;\n    using Graph<Cost>::n;\n    using Graph<Cost>::size;\n\
    \    using Graph<Cost>::m;\n    using Graph<Cost>::g;\n    using Graph<Cost>::Graph;\n\
    \    using Graph<Cost>::add_edge;\n    using Graph<Cost>::operator[];\n    using\
    \ Graph<Cost>::edges;\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     *\n     * @param n \u30CE\u30FC\u30C9\u6570\n     */\n    explicit\
    \ Tree(long long n = 0) : Graph<Cost>(n) {}\n\n    /**\n     * @brief Graph \u3068\
    \u3057\u3066\u898B\u308B\n     *\n     * Graph \u3092\u53D7\u3051\u53D6\u308B\u95A2\
    \u6570 (shortest_path \u306A\u3069) \u306B\u6E21\u3059\u3068\u304D\u306B\u4F7F\
    \u3046\n     * @return const Graph<Cost>& \u3053\u306E\u6728\u3092\u8868\u3059\
    \u30B0\u30E9\u30D5\n     */\n    const Graph<Cost>& graph() const { return *this;\
    \ }\n\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\
    \u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n   \
    \  * @param padding  = -1 \u9802\u70B9\u756A\u53F7\u3092\u5165\u529B\u304B\u3089\
    \u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     * @param weighted = false \u8FBA\
    \u306E\u91CD\u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B\n     */\n    void\
    \ read(long long padding = -1, bool weighted = false) {\n        Graph<Cost>::read(this->n\
    \ - 1, padding, weighted, false);\n    }\n\n    /**\n     * @brief \u6839\u4ED8\
    \u304D\u6728\u306B\u3059\u308B\n     *\n     * @param root \u6839\n     * @return\
    \ RootedTree<Cost> \u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n     */\n    [[nodiscard]]\n    RootedTree<Cost> set_root(long long root)\
    \ const& {\n        return RootedTree<Cost>(*this, root);\n    }\n    /**\n  \
    \   * @brief \u6839\u4ED8\u304D\u6728\u306B\u3057\u3066\u8FD4\u3059\n     *\n\
    \     * @param root \u6839\n     * @return RootedTree<Cost> \u6839\u4ED8\u304D\
    \u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n\
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
    \ Tree<Cost>::Edge;\n    using Tree<Cost>::n;\n    using Tree<Cost>::size;\n \
    \   using Tree<Cost>::m;\n    using Tree<Cost>::g;\n    using Tree<Cost>::operator[];\n\
    \    using Tree<Cost>::edges;\n    using Tree<Cost>::graph;\n\n    long long root;\
    \                                           //!< \u6839\n    std::vector<Edge>\
    \ par;                                    //!< \u89AA\u3078\u5411\u304B\u3046\u8FBA\
    \n    std::vector<std::vector<Edge>> child;                     //!< \u5B50\u3078\
    \u5411\u304B\u3046\u8FBA\u306E\u30EA\u30B9\u30C8\n    std::vector<Cost> depth;\
    \                                  //!< \u6DF1\u3055\u306E\u30EA\u30B9\u30C8\n\
    \    std::vector<Cost> height;                                 //!< \u90E8\u5206\
    \u6728\u306E\u9AD8\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<long long> unweighted_depth;\
    \                  //!< \u91CD\u307F\u306A\u3057\u306E\u6DF1\u3055\u306E\u30EA\
    \u30B9\u30C8\n    std::vector<long long> unweighted_height;                 //!<\
    \ \u91CD\u307F\u306A\u3057\u306E\u90E8\u5206\u6728\u306E\u9AD8\u3055\u306E\u30EA\
    \u30B9\u30C8\n    std::vector<long long> sz;                                //!<\
    \ \u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\u306E\u30EA\u30B9\u30C8\n    std::vector<long\
    \ long> preorder;                          //!< \u5148\u884C\u9806\u5DE1\u56DE\
    \n    std::vector<long long> postorder;                         //!< \u5F8C\u884C\
    \u9806\u5DE1\u56DE\n    std::vector<std::pair<long long, long long>> euler_tour;\
    \  //!< \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC DFS\u4E2D\u306B\u3068\u304A\
    \u3063\u305F\u9802\u70B9\u306E(\u9802\u70B9\u756A\u53F7,\u305D\u306E\u9802\u70B9\
    \u3092\u901A\u3063\u305F\u56DE\u6570)\u306E\u30EA\u30B9\u30C8\n\n    RootedTree()\
    \ = delete;\n\n    /**\n     * @brief \u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\
    \u30C8\u304B\u3089\u6839\u304C0\u306E\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam\
    \ T \u9802\u70B9\u756A\u53F7\u306E\u6574\u6570\u578B (long long \u3084 int)\n\
    \     * @param par_ \u9802\u70B90\u4EE5\u5916\u306E\u89AA\u306E\u9802\u70B9\u306E\
    \u30EA\u30B9\u30C8\n     * @param padding = -1 par\u306E\u9802\u70B9\u756A\u53F7\
    \u3092\u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     */\n    template <typename\
    \ T = long long>\n    explicit RootedTree(const std::vector<T>& par_, long long\
    \ padding = -1) : Tree<Cost>(par_.size() + 1), root(0) {\n        static_assert(std::is_integral_v<T>,\
    \ \"RootedTree: par_ must be a vector of integers\");\n        for (long long\
    \ i = 0; i < static_cast<long long>(par_.size()); i++) {\n            this->add_edge(i\
    \ + 1, par_[i] + padding);\n        }\n        build();\n    }\n    /**\n    \
    \ * @brief Tree\u304B\u3089\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     *\
    \ @param tree Tree \u9802\u70B9\u65701\u4EE5\u4E0A\n     * @param root \u6839\n\
    \     */\n    RootedTree(const Tree<Cost>& tree, long long root) : Tree<Cost>(tree),\
    \ root(root) {\n        build();\n    }\n    /**\n     * @brief Tree\u304B\u3089\
    \u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n     *\n     * @param tree Tree\n    \
    \ * @param root \u6839\n     */\n    RootedTree(Tree<Cost>&& tree, long long root)\
    \ : Tree<Cost>(std::move(tree)), root(root) {\n        build();\n    }\n\n   \
    \ /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\
    \u6839\u4ED8\u304D\u6728\u3092\u5F97\u308B\n     *\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca() const& {\n        return DoublingClimbTree<Cost>(*this);\n    }\n\
    \n    /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\
    \u6839\u4ED8\u304D\u6728\u3092\u5F97\u308B\n     *\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca() && {\n        return DoublingClimbTree<Cost>(std::move(*this));\n\
    \    }\n\n   private:\n    void build() {\n        long long n = this->n;\n  \
    \      assert(n > 0);\n        assert(0 <= root && root < n);\n        par.resize(n);\n\
    \        par[root] = {root, -1, 0, -1};\n        child.resize(n);\n        depth.resize(n);\n\
    \        unweighted_depth.resize(n);\n        height.resize(n);\n        unweighted_height.resize(n);\n\
    \        sz.resize(n);\n        std::vector<int> iter(n);\n        std::stack<std::pair<int,\
    \ int>> stk;\n        stk.emplace(root, 0);\n        while (!stk.empty()) {\n\
    \            auto [u, cnt] = stk.top();\n            stk.pop();\n            euler_tour.emplace_back(u,\
    \ cnt);\n            if (iter[u] == 0) preorder.push_back(u);\n            while\
    \ (iter[u] < static_cast<int>(this->g[u].size()) && this->g[u][iter[u]].dst ==\
    \ par[u]) iter[u]++;\n            if (iter[u] == static_cast<int>(this->g[u].size()))\
    \ {\n                postorder.push_back(u);\n                sz[u] = 1;\n   \
    \             height[u] = 0;\n                unweighted_height[u] = 0;\n    \
    \            for (auto& e : child[u]) {\n                    sz[u] += sz[e.dst];\n\
    \                    if (height[u] < height[e.dst] + e.cost) {\n             \
    \           height[u] = height[e.dst] + e.cost;\n                    }\n     \
    \               if (unweighted_height[u] < unweighted_height[e.dst] + 1) {\n \
    \                       unweighted_height[u] = unweighted_height[e.dst] + 1;\n\
    \                    }\n                }\n            } else {\n            \
    \    auto& e = this->g[u][iter[u]++];\n                par[e.dst] = {e.dst, u,\
    \ e.cost, e.id};\n                child[u].push_back(e);\n                depth[e.dst]\
    \ = depth[u] + e.cost;\n                unweighted_depth[e.dst] = unweighted_depth[u]\
    \ + 1;\n                stk.emplace(u, cnt + 1);\n                stk.emplace(e.dst,\
    \ 0);\n            }\n        }\n    }\n};\n\n/**\n * @brief \u89AA\u9802\u70B9\
    \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\n *\n * @tparam\
    \ Cost = long long \u8FBA\u306E\u91CD\u307F(\u6CE8: hop\u3067\u306F\u6839\u306E\
    \u91CD\u307F\u306F\u8003\u3048\u306A\u3044)\n */\ntemplate <typename Cost = long\
    \ long>\nclass DoublingClimbTree : private RootedTree<Cost> {\n   public:\n  \
    \  using Edge = typename RootedTree<Cost>::Edge;\n    using RootedTree<Cost>::n;\n\
    \    using RootedTree<Cost>::size;\n    using RootedTree<Cost>::m;\n    using\
    \ RootedTree<Cost>::g;\n    using RootedTree<Cost>::operator[];\n    using RootedTree<Cost>::edges;\n\
    \    using RootedTree<Cost>::graph;\n    using RootedTree<Cost>::root;\n    using\
    \ RootedTree<Cost>::par;\n    using RootedTree<Cost>::child;\n    using RootedTree<Cost>::depth;\n\
    \    using RootedTree<Cost>::height;\n    using RootedTree<Cost>::unweighted_depth;\n\
    \    using RootedTree<Cost>::unweighted_height;\n    using RootedTree<Cost>::sz;\n\
    \    using RootedTree<Cost>::preorder;\n    using RootedTree<Cost>::postorder;\n\
    \    using RootedTree<Cost>::euler_tour;\n\n    long long h;                 \
    \                      //!< \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u56DE\u6570\n\
    \    std::vector<std::vector<long long>> doubling_par;  //!< j\u304B\u3089(1<<i)\u9802\
    \u70B9\u767B\u3063\u305F\u9802\u70B9(\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306F-1)\n\n    DoublingClimbTree() = delete;\n\n    /**\n     * @brief RootedTree\u304B\
    \u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\
    \u30FC)\n     *\n     * @param tree RootedTree\n     */\n    explicit DoublingClimbTree(const\
    \ RootedTree<Cost>& tree) : RootedTree<Cost>(tree) {\n        build();\n    }\n\
    \n    /**\n     * @brief RootedTree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\
    \u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n     *\n     * @param tree RootedTree\n\
    \     */\n    DoublingClimbTree(RootedTree<Cost>&& tree) : RootedTree<Cost>(std::move(tree))\
    \ {\n        build();\n    }\n\n    /**\n     * @brief \u89AA\u306E\u9802\u70B9\
    \u306E\u30EA\u30B9\u30C8\u304B\u3089\u6839\u304C0\u306E\u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam T \u9802\u70B9\u756A\
    \u53F7\u306E\u6574\u6570\u578B (long long \u3084 int)\n     * @param par_ \u9802\
    \u70B90\u4EE5\u5916\u306E\u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n  \
    \   * @param padding = -1 par\u306E\u9802\u70B9\u756A\u53F7\u3092\u3044\u304F\u3064\
    \u305A\u3089\u3059\u304B\n     */\n    template <typename T = long long>\n   \
    \ explicit DoublingClimbTree(const std::vector<T>& par_, long long padding = -1)\
    \ : RootedTree<Cost>(par_, padding) {\n        build();\n    }\n    /**\n    \
    \ * @brief Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\
    \u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree Tree\n     * @param root\
    \ \u6839\n     */\n    DoublingClimbTree(const Tree<Cost>& tree, long long root)\
    \ : RootedTree<Cost>(tree, root) {\n        build();\n    }\n    /**\n     * @brief\
    \ Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\
    \u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    (\u30E0\u30FC\u30D6)\n     *\n     * @param tree Tree\n     * @param root \u6839\
    \n     */\n    DoublingClimbTree(Tree<Cost>&& tree, long long root) : RootedTree<Cost>(std::move(tree),\
    \ root) {\n        build();\n    }\n\n    /**\n     * @brief \u9802\u70B9u\u304B\
    \u3089k\u56DE\u3092\u6839\u306E\u65B9\u5411\u306B\u9061\u3063\u305F\u9802\u70B9\
    \n     *\n     * @param u \u5143\u306E\u9802\u70B9\n     * @param k \u767B\u308B\
    \u6BB5\u6570\n     * @return long long k\u56DE\u767B\u3063\u305F\u9802\u70B9 (\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070 -1)\n     */\n    long long hop(long long\
    \ u, long long k) const {\n        assert(0 <= u && u < this->n && k >= 0);\n\
    \        if (k > this->unweighted_depth[u]) return -1;\n        for (long long\
    \ i = 0; i < h; i++) {\n            if (k >> i & 1) u = doubling_par[i][u];\n\
    \            if (u == -1) return -1;\n        }\n        return u;\n    }\n\n\
    \    /**\n     * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148\n     *\n     * @param\
    \ u \u9802\u70B91\n     * @param v \u9802\u70B92\n     * @return long long LCA\u306E\
    \u9802\u70B9\u756A\u53F7\n     */\n    long long lca(long long u, long long v)\
    \ const {\n        assert(0 <= u && u < this->n && 0 <= v && v < this->n);\n \
    \       if (this->unweighted_depth[u] > this->unweighted_depth[v]) std::swap(u,\
    \ v);\n        v = hop(v, this->unweighted_depth[v] - this->unweighted_depth[u]);\n\
    \        if (u == v) return u;\n        for (long long i = h - 1; i >= 0; i--)\
    \ {\n            long long nu = doubling_par[i][u];\n            long long nv\
    \ = doubling_par[i][v];\n            if (nu == -1) continue;\n            if (nu\
    \ != nv) {\n                u = nu;\n                v = nv;\n            }\n\
    \        }\n        return this->par[u];\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9\u9593\u8DDD\u96E2(\u91CD\u307F\u4ED8\u304D)\n     *\n     * @param u \u9802\
    \u70B91\n     * @param v \u9802\u70B92\n     * @return Cost u\u3068v\u9593\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u306E\u8FBA\u306E\u91CD\u307F\u306E\u548C\n     */\n\
    \    Cost dist(long long u, long long v) const {\n        assert(0 <= u && u <\
    \ this->n && 0 <= v && v < this->n);\n        return this->depth[u] + this->depth[v]\
    \ - this->depth[lca(u, v)] * 2;\n    }\n\n   private:\n    void build() {\n  \
    \      long long n = this->n;\n        h = 1;\n        while ((1LL << h) < n)\
    \ h++;\n        doubling_par.assign(h, std::vector<long long>(n, -1));\n     \
    \   for (long long i = 0; i < n; i++) doubling_par[0][i] = this->par[i];\n   \
    \     for (long long i = 0; i < h - 1; i++) {\n            for (long long j =\
    \ 0; j < n; j++) {\n                if (doubling_par[i][j] != -1) {\n        \
    \            doubling_par[i + 1][j] = doubling_par[i][doubling_par[i][j]];\n \
    \               }\n            }\n        }\n    }\n};\n#line 7 \"test/yosupo/tree/lca.2.test.cpp\"\
    \n\nint main(void) {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(0);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<int> par(n - 1);\n  \
    \  for (int i = 0; i < n - 1; i++) std::cin >> par[i];\n    RootedTree tree(par,\
    \ 0);\n    SegTree<monoid::Min<long long>> et_depth(tree.euler_tour.size());\n\
    \    std::vector<int> pre_idx(n);\n    for (int i = 0; i < static_cast<int>(tree.euler_tour.size());\
    \ i++) {\n        auto [u, cnt] = tree.euler_tour[i];\n        et_depth[i] = static_cast<long\
    \ long>(tree.depth[u]) * n + u;\n        if (cnt == 0) pre_idx[u] = i;\n    }\n\
    \    while (q--) {\n        int u, v;\n        std::cin >> u >> v;\n        if\
    \ (pre_idx[u] > pre_idx[v]) std::swap(u, v);\n        std::cout << et_depth.prod(pre_idx[u],\
    \ pre_idx[v] + 1) % n << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <iostream>\n\
    \n#include \"../../../src/data_structures/segtree.hpp\"\n#include \"../../../src/graph/tree.hpp\"\
    \n\nint main(void) {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(0);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<int> par(n - 1);\n  \
    \  for (int i = 0; i < n - 1; i++) std::cin >> par[i];\n    RootedTree tree(par,\
    \ 0);\n    SegTree<monoid::Min<long long>> et_depth(tree.euler_tour.size());\n\
    \    std::vector<int> pre_idx(n);\n    for (int i = 0; i < static_cast<int>(tree.euler_tour.size());\
    \ i++) {\n        auto [u, cnt] = tree.euler_tour[i];\n        et_depth[i] = static_cast<long\
    \ long>(tree.depth[u]) * n + u;\n        if (cnt == 0) pre_idx[u] = i;\n    }\n\
    \    while (q--) {\n        int u, v;\n        std::cin >> u >> v;\n        if\
    \ (pre_idx[u] > pre_idx[v]) std::swap(u, v);\n        std::cout << et_depth.prod(pre_idx[u],\
    \ pre_idx[v] + 1) % n << '\\n';\n    }\n}"
  dependsOn:
  - src/data_structures/segtree.hpp
  - src/algebra/monoid.hpp
  - src/graph/tree.hpp
  - src/graph/graph.hpp
  isVerificationFile: true
  path: test/yosupo/tree/lca.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 18:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree/lca.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree/lca.2.test.cpp
- /verify/test/yosupo/tree/lca.2.test.cpp.html
title: test/yosupo/tree/lca.2.test.cpp
---
