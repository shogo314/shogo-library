---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree-2d.hpp
    title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_add_point_get
    links:
    - https://judge.yosupo.jp/problem/rectangle_add_point_get
  bundledCode: "#line 1 \"test/yosupo/data_structure/rectangle-add-point-get.1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\n\
    \n#include <iostream>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/data_structures/segtree-2d.hpp\"\
    \n\n/**\n * @file segtree-2d.hpp\n * @brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\n */\n\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n\
    #line 13 \"src/data_structures/segtree-2d.hpp\"\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#line 15 \"src/algebra/monoid.hpp\"\n#include <array>\n\
    #include <cstddef>\n#include <istream>\n#include <limits>\n#include <numeric>\n\
    #include <optional>\n#include <ostream>\n#include <type_traits>\n#line 24 \"src/algebra/monoid.hpp\"\
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
    \ T) -> Monoid<T, Op>;\n#line 15 \"src/data_structures/segtree-2d.hpp\"\n\n/**\n\
    \ * @brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u66F4\u65B0\u3059\
    \u308B\u70B9\u3092\u5148\u8AAD\u307F\u3059\u308B\u9818\u57DF\u6728)\n *\n * x\
    \ \u5EA7\u6A19\u306E\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u5404\u30CE\u30FC\
    \u30C9\u306B\u3001\u305D\u306E\u90E8\u5206\u6728\u306B\u3042\u308B\u70B9\u306E\
    \ y \u5EA7\u6A19\u306E\u5217\u3068\u3001\u305D\u306E\u4E0A\u306E\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\u3092\u6301\u305F\u305B\u308B\u3002\n *\n * @tparam M \u53EF\
    \u63DB\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n */\ntemplate <typename M>\n\
    class SegTree2D {\n   public:\n    using S = typename M::S;\n\n   private:\n \
    \   M m;\n    S op(const S& a, const S& b) const { return m.op(a, b); }\n    S\
    \ e() const { return m.e(); }\n\n    int n;                                  //\
    \ x \u5EA7\u6A19\u306E\u7A2E\u985E\u6570\n    std::vector<long long> xs, ys; \
    \         // \u5727\u7E2E\u3057\u305F\u5EA7\u6A19\n    std::vector<std::vector<int>>\
    \ node_ys;  // \u5404\u30CE\u30FC\u30C9\u306B\u3042\u308B\u70B9\u306E y \u306E\
    \u756A\u53F7 (\u6607\u9806)\n    std::vector<std::vector<S>> data;       // \u5404\
    \u30CE\u30FC\u30C9\u306E y \u306E\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5927\u304D\
    \u3055\u306F 2 * node_ys[k].size())\n\n    // \u30CE\u30FC\u30C9 k \u306E y \u306E\
    \u756A\u53F7 yi \u306E\u4F4D\u7F6E\u3002\u306A\u3051\u308C\u3070 -1\n    int find_y(int\
    \ k, int yi) const {\n        auto it = std::lower_bound(node_ys[k].begin(), node_ys[k].end(),\
    \ yi);\n        if (it == node_ys[k].end() || *it != yi) return -1;\n        return\
    \ static_cast<int>(it - node_ys[k].begin());\n    }\n    S get_node(int k, int\
    \ yi) const {\n        int p = find_y(k, yi);\n        if (p == -1) return e();\n\
    \        return data[k][node_ys[k].size() + p];\n    }\n    int x_index(long long\
    \ x) const {\n        auto it = std::lower_bound(xs.begin(), xs.end(), x);\n \
    \       assert(it != xs.end() && *it == x);\n        return static_cast<int>(it\
    \ - xs.begin());\n    }\n    int y_index(long long y) const {\n        auto it\
    \ = std::lower_bound(ys.begin(), ys.end(), y);\n        assert(it != ys.end()\
    \ && *it == y);\n        return static_cast<int>(it - ys.begin());\n    }\n  \
    \  S prod_node(int k, int ly, int ry) const {\n        const auto& v = node_ys[k];\n\
    \        int len = static_cast<int>(v.size());\n        int l = static_cast<int>(std::lower_bound(v.begin(),\
    \ v.end(), ly) - v.begin()) + len;\n        int r = static_cast<int>(std::lower_bound(v.begin(),\
    \ v.end(), ry) - v.begin()) + len;\n        S sml = e(), smr = e();\n        while\
    \ (l < r) {\n            if (l & 1) sml = op(sml, data[k][l++]);\n           \
    \ if (r & 1) smr = op(data[k][--r], smr);\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n   public:\n    SegTree2D()\
    \ : SegTree2D(std::vector<std::pair<long long, long long>>()) {}\n    /**\n  \
    \   * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param\
    \ points set/apply \u3059\u308B\u70B9 (x, y) \u306E\u5217 (\u91CD\u8907\u3057\u3066\
    \u3088\u3044)\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ SegTree2D(const std::vector<std::pair<long long, long long>>& points, M m =\
    \ M()) : m(std::move(m)) {\n        for (auto [x, y] : points) {\n           \
    \ xs.push_back(x);\n            ys.push_back(y);\n        }\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \        std::sort(ys.begin(), ys.end());\n        ys.erase(std::unique(ys.begin(),\
    \ ys.end()), ys.end());\n        n = static_cast<int>(xs.size());\n        node_ys.resize(2\
    \ * n);\n        for (auto [x, y] : points) node_ys[n + x_index(x)].push_back(y_index(y));\n\
    \        for (int k = n; k < 2 * n; k++) {\n            std::sort(node_ys[k].begin(),\
    \ node_ys[k].end());\n            node_ys[k].erase(std::unique(node_ys[k].begin(),\
    \ node_ys[k].end()), node_ys[k].end());\n        }\n        for (int k = n - 1;\
    \ k >= 1; k--) {\n            const auto &a = node_ys[2 * k], &b = node_ys[2 *\
    \ k + 1];\n            std::set_union(a.begin(), a.end(), b.begin(), b.end(),\
    \ std::back_inserter(node_ys[k]));\n        }\n        data.resize(2 * n);\n \
    \       for (int k = 1; k < 2 * n; k++) data[k].assign(2 * node_ys[k].size(),\
    \ e());\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u70B9\u306E\
    \u5024\u3092\u8FD4\u3059 (\u6E21\u3057\u3066\u3044\u306A\u3044\u70B9\u306A\u3089\
    \u5358\u4F4D\u5143)\n     */\n    S get(long long x, long long y) const {\n  \
    \      auto ix = std::lower_bound(xs.begin(), xs.end(), x);\n        auto iy =\
    \ std::lower_bound(ys.begin(), ys.end(), y);\n        if (ix == xs.end() || *ix\
    \ != x || iy == ys.end() || *iy != y) return e();\n        return get_node(n +\
    \ static_cast<int>(ix - xs.begin()), static_cast<int>(iy - ys.begin()));\n   \
    \ }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u70B9\u306E\u5024\
    \u3092 v \u306B\u66F4\u65B0\u3059\u308B (\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u3067\u6E21\u3057\u305F\u70B9\u306E\u307F\u3002\u9055\u3048\u3070 assert \u3067\
    \u843D\u3061\u308B)\n     */\n    void set(long long x, long long y, const S&\
    \ v) {\n        int yi = y_index(y);\n        int leaf = n + x_index(x);\n   \
    \     assert(find_y(leaf, yi) != -1);  // \u6E21\u3057\u305F\u70B9\u304B (\u8449\
    \u306B\u3042\u308C\u3070\u7956\u5148\u306B\u3082\u3042\u308B)\n        for (int\
    \ k = leaf; k >= 1; k >>= 1) {\n            int len = static_cast<int>(node_ys[k].size());\n\
    \            int p = find_y(k, yi) + len;\n            data[k][p] = k >= n ? v\
    \ : op(get_node(2 * k, yi), get_node(2 * k + 1, yi));\n            for (p >>=\
    \ 1; p >= 1; p >>= 1) data[k][p] = op(data[k][2 * p], data[k][2 * p + 1]);\n \
    \       }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u70B9\
    \u306E\u5024\u306B v \u3092\u4F5C\u7528\u3055\u305B\u308B (\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u3067\u6E21\u3057\u305F\u70B9\u306E\u307F\u3002\u9055\u3048\
    \u3070 assert \u3067\u843D\u3061\u308B)\n     */\n    void apply(long long x,\
    \ long long y, const S& v) {\n        int yi = y_index(y);\n        // \u53EF\u63DB\
    \u306A\u306E\u3067\u3001\u7956\u5148\u306E\u5024\u306B\u305D\u306E\u307E\u307E\
    \ v \u3092\u639B\u3051\u308C\u3070\u3088\u3044\n        int leaf = n + x_index(x);\n\
    \        assert(find_y(leaf, yi) != -1);  // \u6E21\u3057\u305F\u70B9\u304B (\u8449\
    \u306B\u3042\u308C\u3070\u7956\u5148\u306B\u3082\u3042\u308B)\n        for (int\
    \ k = leaf; k >= 1; k >>= 1) {\n            for (int p = find_y(k, yi) + static_cast<int>(node_ys[k].size());\
    \ p >= 1; p >>= 1) data[k][p] = op(data[k][p], v);\n        }\n    }\n\n    /**\n\
    \     * @brief [lx, rx) x [ly, ry) \u306B\u3042\u308B\u70B9\u306E\u5024\u306E\u7DCF\
    \u7A4D\u3092\u8FD4\u3059\n     */\n    S prod(long long lx, long long rx, long\
    \ long ly, long long ry) const {\n        assert(lx <= rx && ly <= ry);\n    \
    \    int l = static_cast<int>(std::lower_bound(xs.begin(), xs.end(), lx) - xs.begin())\
    \ + n;\n        int r = static_cast<int>(std::lower_bound(xs.begin(), xs.end(),\
    \ rx) - xs.begin()) + n;\n        int lyi = static_cast<int>(std::lower_bound(ys.begin(),\
    \ ys.end(), ly) - ys.begin());\n        int ryi = static_cast<int>(std::lower_bound(ys.begin(),\
    \ ys.end(), ry) - ys.begin());\n        S res = e();\n        while (l < r) {\n\
    \            if (l & 1) res = op(res, prod_node(l++, lyi, ryi));\n           \
    \ if (r & 1) res = op(res, prod_node(--r, lyi, ryi));\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return res;\n    }\n};\n\ntemplate <typename\
    \ M>\nSegTree2D(std::vector<std::pair<long long, long long>>, M) -> SegTree2D<M>;\n\
    \n/**\n * @brief RangeMaxQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RMaxQ2D = SegTree2D<monoid::Max<S>>;\n/**\n * @brief RangeMinQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RMinQ2D = SegTree2D<monoid::Min<S>>;\n\
    /**\n * @brief RangeSumQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RSumQ2D = SegTree2D<monoid::Sum<S>>;\n#line 8 \"test/yosupo/data_structure/rectangle-add-point-get.1.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    // \u9577\u65B9\u5F62 [l, r) x [d,\
    \ u) \u3078\u306E\u52A0\u7B97\u3092 4 \u9685\u3078\u306E\u52A0\u7B97 (\u5DEE\u5206\
    ) \u306B\u3057\u3001\u70B9 (x, y) \u306E\u5024\u306F x \u4EE5\u4E0B\u30FBy \u4EE5\
    \u4E0B\u306E\u9685\u306E\u548C\u3068\u3057\u3066\u6C42\u3081\u308B\n    struct\
    \ Query {\n        int type;\n        long long l, d, r, u, w;\n    };\n    std::vector<Query>\
    \ qs;\n    for (int i = 0; i < n; i++) {\n        long long l, d, r, u, w;\n \
    \       std::cin >> l >> d >> r >> u >> w;\n        qs.push_back({0, l, d, r,\
    \ u, w});\n    }\n    for (int i = 0; i < q; i++) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t == 0) {\n            long long l, d, r, u, w;\n       \
    \     std::cin >> l >> d >> r >> u >> w;\n            qs.push_back({0, l, d, r,\
    \ u, w});\n        } else {\n            long long x, y;\n            std::cin\
    \ >> x >> y;\n            qs.push_back({1, x, y, 0, 0, 0});\n        }\n    }\n\
    \    std::vector<std::pair<long long, long long>> points;\n    for (const auto&\
    \ c : qs) {\n        if (c.type == 0) {\n            for (long long x : {c.l,\
    \ c.r})\n                for (long long y : {c.d, c.u}) points.emplace_back(x,\
    \ y);\n        }\n    }\n    RSumQ2D<long long> seg(points);\n    for (const auto&\
    \ c : qs) {\n        if (c.type == 0) {\n            seg.apply(c.l, c.d, c.w);\n\
    \            seg.apply(c.r, c.d, -c.w);\n            seg.apply(c.l, c.u, -c.w);\n\
    \            seg.apply(c.r, c.u, c.w);\n        } else {\n            std::cout\
    \ << seg.prod(0, c.l + 1, 0, c.d + 1) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"\
    ../../../src/data_structures/segtree-2d.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, q;\n    std::cin >> n >> q;\n\
    \    // \u9577\u65B9\u5F62 [l, r) x [d, u) \u3078\u306E\u52A0\u7B97\u3092 4 \u9685\
    \u3078\u306E\u52A0\u7B97 (\u5DEE\u5206) \u306B\u3057\u3001\u70B9 (x, y) \u306E\
    \u5024\u306F x \u4EE5\u4E0B\u30FBy \u4EE5\u4E0B\u306E\u9685\u306E\u548C\u3068\u3057\
    \u3066\u6C42\u3081\u308B\n    struct Query {\n        int type;\n        long\
    \ long l, d, r, u, w;\n    };\n    std::vector<Query> qs;\n    for (int i = 0;\
    \ i < n; i++) {\n        long long l, d, r, u, w;\n        std::cin >> l >> d\
    \ >> r >> u >> w;\n        qs.push_back({0, l, d, r, u, w});\n    }\n    for (int\
    \ i = 0; i < q; i++) {\n        int t;\n        std::cin >> t;\n        if (t\
    \ == 0) {\n            long long l, d, r, u, w;\n            std::cin >> l >>\
    \ d >> r >> u >> w;\n            qs.push_back({0, l, d, r, u, w});\n        }\
    \ else {\n            long long x, y;\n            std::cin >> x >> y;\n     \
    \       qs.push_back({1, x, y, 0, 0, 0});\n        }\n    }\n    std::vector<std::pair<long\
    \ long, long long>> points;\n    for (const auto& c : qs) {\n        if (c.type\
    \ == 0) {\n            for (long long x : {c.l, c.r})\n                for (long\
    \ long y : {c.d, c.u}) points.emplace_back(x, y);\n        }\n    }\n    RSumQ2D<long\
    \ long> seg(points);\n    for (const auto& c : qs) {\n        if (c.type == 0)\
    \ {\n            seg.apply(c.l, c.d, c.w);\n            seg.apply(c.r, c.d, -c.w);\n\
    \            seg.apply(c.l, c.u, -c.w);\n            seg.apply(c.r, c.u, c.w);\n\
    \        } else {\n            std::cout << seg.prod(0, c.l + 1, 0, c.d + 1) <<\
    \ '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - src/data_structures/segtree-2d.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: true
  path: test/yosupo/data_structure/rectangle-add-point-get.1.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/data_structure/rectangle-add-point-get.1.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/rectangle-add-point-get.1.test.cpp
- /verify/test/yosupo/data_structure/rectangle-add-point-get.1.test.cpp.html
title: test/yosupo/data_structure/rectangle-add-point-get.1.test.cpp
---
