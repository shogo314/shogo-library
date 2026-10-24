---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/acted-monoid.hpp
    title: "\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/rbst.test.cpp
    title: test/unittest/data_structures/rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/dynamic-sequence-range-affine-range-sum.test.cpp
    title: test/yosupo/data_structure/dynamic-sequence-range-affine-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/range-reverse-range-sum.test.cpp
    title: test/yosupo/data_structure/range-reverse-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5E73\u8861\u4E8C\u5206\u6728 (RBST) \u306B\u3088\u308B\u5217"
    links: []
  bundledCode: "#line 2 \"src/data_structures/rbst.hpp\"\n\n/**\n * @file rbst.hpp\n\
    \ * @brief \u5E73\u8861\u4E8C\u5206\u6728 (RBST) \u306B\u3088\u308B\u5217\n */\n\
    \n#include <cassert>\n#include <cstddef>\n#include <cstdint>\n#include <ostream>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/algebra/acted-monoid.hpp\"\
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
    #include <array>\n#line 21 \"src/algebra/acted-monoid.hpp\"\n#include <limits>\n\
    #include <optional>\n#line 25 \"src/algebra/acted-monoid.hpp\"\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#line 17 \"src/algebra/monoid.hpp\"\n#include <istream>\n\
    #line 19 \"src/algebra/monoid.hpp\"\n#include <numeric>\n#line 24 \"src/algebra/monoid.hpp\"\
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
    #line 17 \"src/data_structures/rbst.hpp\"\n\nnamespace internal_rbst {\ntemplate\
    \ <typename M, typename = void>\nstruct has_acted : std::false_type {};\ntemplate\
    \ <typename M>\nstruct has_acted<M, std::void_t<typename M::F>> : std::true_type\
    \ {};\n// \u4F5C\u7528\u7D20\u4ED8\u304D\u3067\u306A\u3044\u30E2\u30CE\u30A4\u30C9\
    \u306E\u3068\u304D\u306E\u4F5C\u7528\u7D20\u306E\u578B\nstruct NoAct {\n    using\
    \ F = NoAct;\n};\n}  // namespace internal_rbst\n\n/**\n * @brief \u5E73\u8861\
    \u4E8C\u5206\u6728 (RBST) \u306B\u3088\u308B\u5217\n *\n * \u4F4D\u7F6E\u3067\u6271\
    \u3046\u5217\u3002k \u756A\u76EE\u3078\u306E\u633F\u5165\u30FB\u524A\u9664\u3001\
    \u533A\u9593\u7A4D\u3001\u533A\u9593\u53CD\u8EE2\u3001split\u30FBmerge \u3092\u671F\
    \u5F85 O(log n) \u3067\u884C\u3046\n * \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\
    \ \u304B\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\
    \ \u3092\u4E57\u305B\u308B\u3002\u4F5C\u7528\u7D20\u4ED8\u304D\u306A\u3089\u533A\
    \u9593\u4F5C\u7528\u3082\u3067\u304D\u308B\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\u306E mapping \u306F (f, x) \u304B (f, x, sz) \u306E\u5F62\u306B\
    \u3059\u308B (\u5217\u306E\u4F4D\u7F6E\u306F\u633F\u5165\u30FB\u524A\u9664\u3067\
    \u5909\u308F\u308B\u306E\u3067 (f, x, l, r) \u306F\u4F7F\u3048\u306A\u3044)\n\
    \ * \u9802\u70B9\u306F\u578B\u3054\u3068\u306B\u5171\u6709\u3059\u308B\u914D\u5217\
    \u306B\u7F6E\u304F\u306E\u3067\u3001\u540C\u3058\u578B\u306E\u6728\u3069\u3046\
    \u3057\u3067 split\u30FBmerge \u3067\u304D\u308B\n * \u4F8B:\n * RBST<acted_monoid::AddSum<long\
    \ long>> t(v);\n * t.insert(2, x); t.erase(0); t.reverse(1, 4); t.apply(0, 3,\
    \ 10); t.prod(1, 3);\n * RBST<acted_monoid::AddSum<long long>> u = t.split(2);\
    \  // t \u306F\u5148\u982D 2 \u500B\u3001u \u306F\u6B8B\u308A\n * t.merge(std::move(u));\
    \                                 // \u5143\u306B\u623B\u3059\n *\n * @tparam\
    \ M \u30E2\u30CE\u30A4\u30C9\u304B\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9\n */\ntemplate <typename M>\nclass RBST {\n   public:\n    using S = typename\
    \ M::S;\n    static constexpr bool acted = internal_rbst::has_acted<M>::value;\n\
    \    using F = typename std::conditional_t<acted, M, internal_rbst::NoAct>::F;\n\
    \n   private:\n    static_assert(!acted || !internal_acted_monoid::has_mapping_lr<M>::value,\
    \ \"RBST: mapping(f, x, l, r) \u306F\u4F7F\u3048\u306A\u3044\");\n\n    // \u9802\
    \u70B9 0 \u306F\u7A7A\u306E\u6728\u3092\u8868\u3059\n    struct Node {\n     \
    \   S val, sum, rsum;  // \u5024\u3001\u90E8\u5206\u6728\u306E\u7A4D\u3001\u90E8\
    \u5206\u6728\u306E\u9006\u9806\u306E\u7A4D\n        F lz;              // \u5B50\
    \u306B\u4F1D\u3048\u308B\u4F5C\u7528\u7D20\n        int sz = 0, l = 0, r = 0;\n\
    \        bool has_lz = false, rev = false;  // \u5B50\u306B\u4F5C\u7528\u7D20\u30FB\
    \u53CD\u8EE2\u3092\u4F1D\u3048\u3066\u3044\u306A\u3044\u304B\n    };\n    // \u9802\
    \u70B9\u306E\u914D\u5217\u306F\u6700\u521D\u306B\u9802\u70B9\u3092\u4F5C\u308B\
    \u3068\u304D\u306B\u78BA\u4FDD\u3057\u3001\u89E3\u653E\u3057\u306A\u3044\n   \
    \ // (\u30B0\u30ED\u30FC\u30D0\u30EB\u5909\u6570\u306E\u6728\u306E\u30C7\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u304C\u3001\u5148\u306B\u7834\u68C4\u3055\u308C\u305F\
    \u914D\u5217\u3092\u89E6\u3089\u306A\u3044\u3088\u3046\u306B\u3059\u308B)\n  \
    \  inline static std::vector<Node>* nodes_ = nullptr;\n    inline static std::vector<int>*\
    \ unused_ = nullptr;  // \u6D88\u3057\u305F\u9802\u70B9\n    static Node& node(int\
    \ t) { return (*nodes_)[t]; }\n    static std::uint32_t rand() {\n        static\
    \ std::uint32_t x = 2463534242U;\n        x ^= x << 13;\n        x ^= x >> 17;\n\
    \        x ^= x << 5;\n        return x;\n    }\n\n    M m;\n    int root = 0;\n\
    \n    S op(const S& x, const S& y) const { return m.op(x, y); }\n    S e() const\
    \ { return m.e(); }\n    static int size_of(int t) { return t ? node(t).sz : 0;\
    \ }\n    S sum_of(int t) const { return t ? node(t).sum : e(); }\n    S rsum_of(int\
    \ t) const { return t ? node(t).rsum : e(); }\n\n    // x \u306F\u5024\u3067\u53D7\
    \u3051\u53D6\u308B (\u9802\u70B9\u306E\u914D\u5217\u306E\u8981\u7D20\u3092\u6E21\
    \u3055\u308C\u305F\u3068\u304D\u3001\u914D\u5217\u304C\u4F38\u3073\u3066\u53C2\
    \u7167\u304C\u7121\u52B9\u306B\u306A\u308B\u306E\u3092\u9632\u3050)\n    int new_node(S\
    \ x) {\n        if (!nodes_) nodes_ = new std::vector<Node>(1), unused_ = new\
    \ std::vector<int>();\n        int t;\n        if (!unused_->empty()) {\n    \
    \        t = unused_->back();\n            unused_->pop_back();\n        } else\
    \ {\n            t = nodes_->size();\n            nodes_->emplace_back();\n  \
    \      }\n        Node& v = node(t);\n        v.val = v.sum = v.rsum = x;\n  \
    \      v.has_lz = v.rev = false;\n        v.sz = 1, v.l = v.r = 0;\n        return\
    \ t;\n    }\n    // \u90E8\u5206\u6728\u306E\u9802\u70B9\u3092\u3059\u3079\u3066\
    \u6D88\u3059\n    static void free_tree(int t) {\n        if (!t) return;\n  \
    \      std::vector<int> st = {t};\n        while (!st.empty()) {\n           \
    \ int v = st.back();\n            st.pop_back();\n            if (node(v).l) st.push_back(node(v).l);\n\
    \            if (node(v).r) st.push_back(node(v).r);\n            unused_->push_back(v);\n\
    \        }\n    }\n    int clone_tree(int t) {\n        if (!t) return 0;\n  \
    \      push(t);\n        int lc = clone_tree(node(t).l);\n        int c = new_node(node(t).val);\n\
    \        int rc = clone_tree(node(t).r);\n        node(c).l = lc, node(c).r =\
    \ rc;\n        update(c);\n        return c;\n    }\n\n    void update(int t)\
    \ {\n        Node& v = node(t);\n        v.sz = node(v.l).sz + node(v.r).sz +\
    \ 1;\n        v.sum = op(op(sum_of(v.l), v.val), sum_of(v.r));\n        v.rsum\
    \ = op(op(rsum_of(v.r), v.val), rsum_of(v.l));\n    }\n    void all_apply(int\
    \ t, const F& f) {\n        if (!t) return;\n        if constexpr (acted) {\n\
    \            Node& v = node(t);\n            v.val = acted_monoid::apply_mapping(m,\
    \ f, v.val, 0, 1);\n            v.sum = acted_monoid::apply_mapping(m, f, v.sum,\
    \ 0, v.sz);\n            v.rsum = acted_monoid::apply_mapping(m, f, v.rsum, 0,\
    \ v.sz);\n            v.lz = v.has_lz ? m.composition(f, v.lz) : f;\n        \
    \    v.has_lz = true;\n        }\n    }\n    static void toggle(int t) {\n   \
    \     if (!t) return;\n        Node& v = node(t);\n        std::swap(v.l, v.r);\n\
    \        std::swap(v.sum, v.rsum);\n        v.rev = !v.rev;\n    }\n    void push(int\
    \ t) {\n        Node& v = node(t);\n        if (v.rev) {\n            toggle(v.l),\
    \ toggle(v.r);\n            v.rev = false;\n        }\n        if constexpr (acted)\
    \ {\n            if (v.has_lz) {\n                all_apply(v.l, v.lz), all_apply(v.r,\
    \ v.lz);\n                v.has_lz = false;\n            }\n        }\n    }\n\
    \n    int merge_node(int a, int b) {\n        if (!a || !b) return a ^ b;\n  \
    \      // \u5927\u304D\u3055\u306B\u6BD4\u4F8B\u3059\u308B\u78BA\u7387\u3067\u6839\
    \u3092\u9078\u3076 ([0, \u5927\u304D\u3055\u306E\u548C) \u306E\u4E71\u6570\u3092\
    \u3001\u5272\u308A\u7B97\u306E\u4EE3\u308F\u308A\u306B\u639B\u3051\u7B97\u3068\
    \u30B7\u30D5\u30C8\u3067\u4F5C\u308B)\n        if ((static_cast<std::uint64_t>(rand())\
    \ * (static_cast<std::uint64_t>(node(a).sz) + node(b).sz) >> 32) < static_cast<std::uint64_t>(node(a).sz))\
    \ {\n            push(a);\n            int c = merge_node(node(a).r, b);\n   \
    \         node(a).r = c;\n            update(a);\n            return a;\n    \
    \    }\n        push(b);\n        int c = merge_node(a, node(b).l);\n        node(b).l\
    \ = c;\n        update(b);\n        return b;\n    }\n    // \u5148\u982D k \u500B\
    \u3068\u6B8B\u308A\u306B\u5206\u3051\u308B\n    std::pair<int, int> split_node(int\
    \ t, int k) {\n        if (!t) return {0, 0};\n        push(t);\n        int ls\
    \ = node(node(t).l).sz;\n        if (k <= ls) {\n            auto [a, b] = split_node(node(t).l,\
    \ k);\n            node(t).l = b;\n            update(t);\n            return\
    \ {a, t};\n        }\n        auto [a, b] = split_node(node(t).r, k - ls - 1);\n\
    \        node(t).r = a;\n        update(t);\n        return {t, b};\n    }\n \
    \   int build(const std::vector<S>& v, int lo, int hi) {\n        if (lo >= hi)\
    \ return 0;\n        int mid = (lo + hi) / 2;\n        int lc = build(v, lo, mid);\n\
    \        int t = new_node(v[mid]);\n        int rc = build(v, mid + 1, hi);\n\
    \        node(t).l = lc, node(t).r = rc;\n        update(t);\n        return t;\n\
    \    }\n    // [l, r) \u3092\u53D6\u308A\u51FA\u3057\u3066 f \u3092\u4F5C\u7528\
    \u3055\u305B\u3001\u5143\u306B\u623B\u3059\n    template <typename Fn>\n    auto\
    \ with_range(long long l, long long r, Fn fn) {\n        assert(0 <= l && l <=\
    \ r && r <= size());\n        auto [a, bc] = split_node(root, static_cast<int>(l));\n\
    \        auto [b, c] = split_node(bc, static_cast<int>(r - l));\n        if constexpr\
    \ (std::is_void_v<decltype(fn(b))>) {\n            fn(b);\n            root =\
    \ merge_node(merge_node(a, b), c);\n        } else {\n            auto res = fn(b);\n\
    \            root = merge_node(merge_node(a, b), c);\n            return res;\n\
    \        }\n    }\n    void to_vector(int t, std::vector<S>& res) {\n        if\
    \ (!t) return;\n        push(t);\n        to_vector(node(t).l, res);\n       \
    \ res.push_back(node(t).val);\n        to_vector(node(t).r, res);\n    }\n\n \
    \   class RBSTReference {\n        RBST& t;\n        long long k;\n\n       public:\n\
    \        RBSTReference(RBST& t, long long k) : t(t), k(k) {}\n        RBSTReference&\
    \ operator=(const S& x) {\n            t.set(k, x);\n            return *this;\n\
    \        }\n        operator S() { return t.get(k); }\n    };\n\n    struct FromRoot\
    \ {};\n    RBST(int root, const M& m, FromRoot) : m(m), root(root) {}\n\n   public:\n\
    \    /**\n     * @brief \u7A7A\u306E\u5217\n     */\n    explicit RBST(M m = M())\
    \ : m(std::move(m)) {}\n    /**\n     * @brief \u9577\u3055 n \u3067\u3001\u3059\
    \u3079\u3066\u5358\u4F4D\u5143\u306E\u5217\n     */\n    explicit RBST(long long\
    \ n, M m = M()) : RBST(std::vector<S>(n, m.e()), m) {}\n    /**\n     * @brief\
    \ v \u306E\u5217 O(n)\n     */\n    explicit RBST(const std::vector<S>& v, M m\
    \ = M()) : m(std::move(m)) { root = build(v, 0, static_cast<int>(v.size())); }\n\
    \    /**\n     * @brief \u8907\u88FD\u3059\u308B O(n)\n     */\n    RBST(const\
    \ RBST& o) : m(o.m) { root = const_cast<RBST&>(o).clone_tree(o.root); }\n    RBST(RBST&&\
    \ o) noexcept : m(std::move(o.m)), root(o.root) { o.root = 0; }\n    RBST& operator=(const\
    \ RBST& o) {\n        if (this != &o) {\n            int c = const_cast<RBST&>(o).clone_tree(o.root);\n\
    \            free_tree(root);\n            m = o.m, root = c;\n        }\n   \
    \     return *this;\n    }\n    RBST& operator=(RBST&& o) noexcept {\n       \
    \ if (this != &o) {\n            free_tree(root);\n            m = std::move(o.m),\
    \ root = o.root;\n            o.root = 0;\n        }\n        return *this;\n\
    \    }\n    ~RBST() { free_tree(root); }\n\n    /**\n     * @brief \u5217\u306E\
    \u9577\u3055\n     */\n    long long size() const { return size_of(root); }\n\
    \    /**\n     * @brief \u7A7A\u304B\n     */\n    bool empty() const { return\
    \ root == 0; }\n\n    /**\n     * @brief k \u756A\u76EE\u306E\u5024\n     */\n\
    \    S get(long long k) {\n        assert(0 <= k && k < size());\n        int\
    \ t = root;\n        while (true) {\n            push(t);\n            int ls\
    \ = node(node(t).l).sz;\n            if (k < ls) {\n                t = node(t).l;\n\
    \            } else if (k == ls) {\n                return node(t).val;\n    \
    \        } else {\n                k -= ls + 1;\n                t = node(t).r;\n\
    \            }\n        }\n    }\n    /**\n     * @brief k \u756A\u76EE\u306E\u8981\
    \u7D20\u3078\u306E\u53C2\u7167 (\u4EE3\u5165\u3059\u308B\u3068 set \u304C\u547C\
    \u3070\u308C\u308B)\n     */\n    RBSTReference operator[](long long k) { return\
    \ RBSTReference(*this, k); }\n    /**\n     * @brief k \u756A\u76EE\u306E\u5024\
    \u3092 x \u306B\u3059\u308B\n     */\n    void set(long long k, const S& x) {\n\
    \        assert(0 <= k && k < size());\n        with_range(k, k + 1, [&](int t)\
    \ { node(t).val = node(t).sum = node(t).rsum = x; });\n    }\n    /**\n     *\
    \ @brief k \u756A\u76EE (0 <= k <= size()) \u306B x \u3092\u633F\u5165\u3059\u308B\
    \u3002\u5F8C\u308D\u306E\u8981\u7D20\u306F 1 \u3064\u305A\u3064\u305A\u308C\u308B\
    \n     */\n    void insert(long long k, const S& x) {\n        assert(0 <= k &&\
    \ k <= size());\n        auto [a, b] = split_node(root, static_cast<int>(k));\n\
    \        root = merge_node(merge_node(a, new_node(x)), b);\n    }\n    void push_front(const\
    \ S& x) { insert(0, x); }\n    void push_back(const S& x) { insert(size(), x);\
    \ }\n    /**\n     * @brief k \u756A\u76EE\u3092\u524A\u9664\u3057\u3066\u3001\
    \u305D\u306E\u5024\u3092\u8FD4\u3059\n     */\n    S erase(long long k) {\n  \
    \      assert(0 <= k && k < size());\n        auto [a, bc] = split_node(root,\
    \ static_cast<int>(k));\n        auto [b, c] = split_node(bc, 1);\n        S x\
    \ = node(b).val;\n        free_tree(b);\n        root = merge_node(a, c);\n  \
    \      return x;\n    }\n    S pop_front() { return erase(0); }\n    S pop_back()\
    \ { return erase(size() - 1); }\n\n    /**\n     * @brief [l, r) \u306E\u7A4D\n\
    \     */\n    S prod(long long l, long long r) {\n        return with_range(l,\
    \ r, [&](int t) { return sum_of(t); });\n    }\n    /**\n     * @brief \u5217\u5168\
    \u4F53\u306E\u7A4D O(1)\n     */\n    S all_prod() const { return sum_of(root);\
    \ }\n    /**\n     * @brief [l, r) \u3092\u53CD\u8EE2\u3059\u308B\n     */\n \
    \   void reverse(long long l, long long r) {\n        with_range(l, r, [&](int\
    \ t) { toggle(t); });\n    }\n    /**\n     * @brief [l, r) \u306E\u5404\u5024\
    \u306B f \u3092\u4F5C\u7528\u3055\u305B\u308B (\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\u306E\u3068\u304D)\n     */\n    template <bool B = acted,\
    \ std::enable_if_t<B, std::nullptr_t> = nullptr>\n    void apply(long long l,\
    \ long long r, const F& f) {\n        with_range(l, r, [&](int t) { all_apply(t,\
    \ f); });\n    }\n    /**\n     * @brief k \u756A\u76EE\u306E\u5024\u306B f \u3092\
    \u4F5C\u7528\u3055\u305B\u308B (\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9\u306E\u3068\u304D)\n     */\n    template <bool B = acted, std::enable_if_t<B,\
    \ std::nullptr_t> = nullptr>\n    void apply(long long k, const F& f) {\n    \
    \    assert(0 <= k && k < size());\n        apply(k, k + 1, f);\n    }\n\n   \
    \ /**\n     * @brief \u672B\u5C3E\u306B other \u3092\u3064\u306A\u3052\u308B\u3002\
    other \u306F\u7A7A\u306B\u306A\u308B\n     */\n    void merge(RBST&& other) {\n\
    \        root = merge_node(root, other.root);\n        other.root = 0;\n    }\n\
    \    /**\n     * @brief \u5148\u982D k \u500B\u3092\u6B8B\u3057\u3001\u6B8B\u308A\
    \u3092\u5207\u308A\u53D6\u3063\u3066\u8FD4\u3059\n     */\n    RBST split(long\
    \ long k) {\n        assert(0 <= k && k <= size());\n        auto [a, b] = split_node(root,\
    \ static_cast<int>(k));\n        root = a;\n        return RBST(b, m, FromRoot{});\n\
    \    }\n\n    /**\n     * @brief g(prod(l, r)) \u304C true \u3068\u306A\u308B\u6700\
    \u5927\u306E r (g(e()) \u306F true \u3067\u3042\u308B\u3053\u3068)\n     * g \u304C\
    \u5358\u8ABF\u306A\u3089\u3001g(prod(l, r)) \u304C true \u3068\u306A\u308B r \u306F\
    \ l \u304B\u3089\u59CB\u307E\u308B\u533A\u9593\u3092\u306A\u3059\n     */\n  \
    \  template <typename G>\n    long long max_right(long long l, G g) {\n      \
    \  assert(0 <= l && l <= size());\n        assert(g(e()));\n        auto [a, b]\
    \ = split_node(root, static_cast<int>(l));\n        long long res = l;\n     \
    \   S acc = e();\n        int t = b;\n        while (t) {\n            push(t);\n\
    \            S s = op(acc, sum_of(node(t).l));\n            if (!g(s)) {\n   \
    \             t = node(t).l;\n                continue;\n            }\n     \
    \       S s2 = op(s, node(t).val);\n            if (!g(s2)) {\n              \
    \  res += node(node(t).l).sz;\n                break;\n            }\n       \
    \     acc = s2;\n            res += node(node(t).l).sz + 1;\n            t = node(t).r;\n\
    \        }\n        root = merge_node(a, b);\n        return res;\n    }\n   \
    \ /**\n     * @brief g(prod(l, r)) \u304C true \u3068\u306A\u308B\u6700\u5C0F\u306E\
    \ l (g(e()) \u306F true \u3067\u3042\u308B\u3053\u3068)\n     */\n    template\
    \ <typename G>\n    long long min_left(long long r, G g) {\n        assert(0 <=\
    \ r && r <= size());\n        assert(g(e()));\n        auto [a, b] = split_node(root,\
    \ static_cast<int>(r));\n        long long res = r;\n        S acc = e();\n  \
    \      int t = a;\n        while (t) {\n            push(t);\n            S s\
    \ = op(sum_of(node(t).r), acc);\n            if (!g(s)) {\n                t =\
    \ node(t).r;\n                continue;\n            }\n            S s2 = op(node(t).val,\
    \ s);\n            if (!g(s2)) {\n                res -= node(node(t).r).sz;\n\
    \                break;\n            }\n            acc = s2;\n            res\
    \ -= node(node(t).r).sz + 1;\n            t = node(t).l;\n        }\n        root\
    \ = merge_node(a, b);\n        return res;\n    }\n\n    /**\n     * @brief \u5217\
    \u3092 std::vector \u306B\u3059\u308B O(n)\n     */\n    std::vector<S> to_vector()\
    \ {\n        std::vector<S> res;\n        res.reserve(size());\n        to_vector(root,\
    \ res);\n        return res;\n    }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, RBST& t) {\n        std::vector<S> v = t.to_vector();\n       \
    \ for (int i = 0; i < static_cast<int>(v.size()); i++) {\n            if (i !=\
    \ 0) os << CharT(' ');\n            os << v[i];\n        }\n        return os;\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @file rbst.hpp\n * @brief \u5E73\u8861\u4E8C\u5206\
    \u6728 (RBST) \u306B\u3088\u308B\u5217\n */\n\n#include <cassert>\n#include <cstddef>\n\
    #include <cstdint>\n#include <ostream>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#include \"../algebra/acted-monoid.hpp\"\n\nnamespace internal_rbst\
    \ {\ntemplate <typename M, typename = void>\nstruct has_acted : std::false_type\
    \ {};\ntemplate <typename M>\nstruct has_acted<M, std::void_t<typename M::F>>\
    \ : std::true_type {};\n// \u4F5C\u7528\u7D20\u4ED8\u304D\u3067\u306A\u3044\u30E2\
    \u30CE\u30A4\u30C9\u306E\u3068\u304D\u306E\u4F5C\u7528\u7D20\u306E\u578B\nstruct\
    \ NoAct {\n    using F = NoAct;\n};\n}  // namespace internal_rbst\n\n/**\n *\
    \ @brief \u5E73\u8861\u4E8C\u5206\u6728 (RBST) \u306B\u3088\u308B\u5217\n *\n\
    \ * \u4F4D\u7F6E\u3067\u6271\u3046\u5217\u3002k \u756A\u76EE\u3078\u306E\u633F\
    \u5165\u30FB\u524A\u9664\u3001\u533A\u9593\u7A4D\u3001\u533A\u9593\u53CD\u8EE2\
    \u3001split\u30FBmerge \u3092\u671F\u5F85 O(log n) \u3067\u884C\u3046\n * \u30E2\
    \u30CE\u30A4\u30C9 (algebra/monoid.hpp) \u304B\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp) \u3092\u4E57\u305B\u308B\u3002\u4F5C\
    \u7528\u7D20\u4ED8\u304D\u306A\u3089\u533A\u9593\u4F5C\u7528\u3082\u3067\u304D\
    \u308B\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E mapping\
    \ \u306F (f, x) \u304B (f, x, sz) \u306E\u5F62\u306B\u3059\u308B (\u5217\u306E\
    \u4F4D\u7F6E\u306F\u633F\u5165\u30FB\u524A\u9664\u3067\u5909\u308F\u308B\u306E\
    \u3067 (f, x, l, r) \u306F\u4F7F\u3048\u306A\u3044)\n * \u9802\u70B9\u306F\u578B\
    \u3054\u3068\u306B\u5171\u6709\u3059\u308B\u914D\u5217\u306B\u7F6E\u304F\u306E\
    \u3067\u3001\u540C\u3058\u578B\u306E\u6728\u3069\u3046\u3057\u3067 split\u30FB\
    merge \u3067\u304D\u308B\n * \u4F8B:\n * RBST<acted_monoid::AddSum<long long>>\
    \ t(v);\n * t.insert(2, x); t.erase(0); t.reverse(1, 4); t.apply(0, 3, 10); t.prod(1,\
    \ 3);\n * RBST<acted_monoid::AddSum<long long>> u = t.split(2);  // t \u306F\u5148\
    \u982D 2 \u500B\u3001u \u306F\u6B8B\u308A\n * t.merge(std::move(u));         \
    \                        // \u5143\u306B\u623B\u3059\n *\n * @tparam M \u30E2\u30CE\
    \u30A4\u30C9\u304B\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n */\n\
    template <typename M>\nclass RBST {\n   public:\n    using S = typename M::S;\n\
    \    static constexpr bool acted = internal_rbst::has_acted<M>::value;\n    using\
    \ F = typename std::conditional_t<acted, M, internal_rbst::NoAct>::F;\n\n   private:\n\
    \    static_assert(!acted || !internal_acted_monoid::has_mapping_lr<M>::value,\
    \ \"RBST: mapping(f, x, l, r) \u306F\u4F7F\u3048\u306A\u3044\");\n\n    // \u9802\
    \u70B9 0 \u306F\u7A7A\u306E\u6728\u3092\u8868\u3059\n    struct Node {\n     \
    \   S val, sum, rsum;  // \u5024\u3001\u90E8\u5206\u6728\u306E\u7A4D\u3001\u90E8\
    \u5206\u6728\u306E\u9006\u9806\u306E\u7A4D\n        F lz;              // \u5B50\
    \u306B\u4F1D\u3048\u308B\u4F5C\u7528\u7D20\n        int sz = 0, l = 0, r = 0;\n\
    \        bool has_lz = false, rev = false;  // \u5B50\u306B\u4F5C\u7528\u7D20\u30FB\
    \u53CD\u8EE2\u3092\u4F1D\u3048\u3066\u3044\u306A\u3044\u304B\n    };\n    // \u9802\
    \u70B9\u306E\u914D\u5217\u306F\u6700\u521D\u306B\u9802\u70B9\u3092\u4F5C\u308B\
    \u3068\u304D\u306B\u78BA\u4FDD\u3057\u3001\u89E3\u653E\u3057\u306A\u3044\n   \
    \ // (\u30B0\u30ED\u30FC\u30D0\u30EB\u5909\u6570\u306E\u6728\u306E\u30C7\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u304C\u3001\u5148\u306B\u7834\u68C4\u3055\u308C\u305F\
    \u914D\u5217\u3092\u89E6\u3089\u306A\u3044\u3088\u3046\u306B\u3059\u308B)\n  \
    \  inline static std::vector<Node>* nodes_ = nullptr;\n    inline static std::vector<int>*\
    \ unused_ = nullptr;  // \u6D88\u3057\u305F\u9802\u70B9\n    static Node& node(int\
    \ t) { return (*nodes_)[t]; }\n    static std::uint32_t rand() {\n        static\
    \ std::uint32_t x = 2463534242U;\n        x ^= x << 13;\n        x ^= x >> 17;\n\
    \        x ^= x << 5;\n        return x;\n    }\n\n    M m;\n    int root = 0;\n\
    \n    S op(const S& x, const S& y) const { return m.op(x, y); }\n    S e() const\
    \ { return m.e(); }\n    static int size_of(int t) { return t ? node(t).sz : 0;\
    \ }\n    S sum_of(int t) const { return t ? node(t).sum : e(); }\n    S rsum_of(int\
    \ t) const { return t ? node(t).rsum : e(); }\n\n    // x \u306F\u5024\u3067\u53D7\
    \u3051\u53D6\u308B (\u9802\u70B9\u306E\u914D\u5217\u306E\u8981\u7D20\u3092\u6E21\
    \u3055\u308C\u305F\u3068\u304D\u3001\u914D\u5217\u304C\u4F38\u3073\u3066\u53C2\
    \u7167\u304C\u7121\u52B9\u306B\u306A\u308B\u306E\u3092\u9632\u3050)\n    int new_node(S\
    \ x) {\n        if (!nodes_) nodes_ = new std::vector<Node>(1), unused_ = new\
    \ std::vector<int>();\n        int t;\n        if (!unused_->empty()) {\n    \
    \        t = unused_->back();\n            unused_->pop_back();\n        } else\
    \ {\n            t = nodes_->size();\n            nodes_->emplace_back();\n  \
    \      }\n        Node& v = node(t);\n        v.val = v.sum = v.rsum = x;\n  \
    \      v.has_lz = v.rev = false;\n        v.sz = 1, v.l = v.r = 0;\n        return\
    \ t;\n    }\n    // \u90E8\u5206\u6728\u306E\u9802\u70B9\u3092\u3059\u3079\u3066\
    \u6D88\u3059\n    static void free_tree(int t) {\n        if (!t) return;\n  \
    \      std::vector<int> st = {t};\n        while (!st.empty()) {\n           \
    \ int v = st.back();\n            st.pop_back();\n            if (node(v).l) st.push_back(node(v).l);\n\
    \            if (node(v).r) st.push_back(node(v).r);\n            unused_->push_back(v);\n\
    \        }\n    }\n    int clone_tree(int t) {\n        if (!t) return 0;\n  \
    \      push(t);\n        int lc = clone_tree(node(t).l);\n        int c = new_node(node(t).val);\n\
    \        int rc = clone_tree(node(t).r);\n        node(c).l = lc, node(c).r =\
    \ rc;\n        update(c);\n        return c;\n    }\n\n    void update(int t)\
    \ {\n        Node& v = node(t);\n        v.sz = node(v.l).sz + node(v.r).sz +\
    \ 1;\n        v.sum = op(op(sum_of(v.l), v.val), sum_of(v.r));\n        v.rsum\
    \ = op(op(rsum_of(v.r), v.val), rsum_of(v.l));\n    }\n    void all_apply(int\
    \ t, const F& f) {\n        if (!t) return;\n        if constexpr (acted) {\n\
    \            Node& v = node(t);\n            v.val = acted_monoid::apply_mapping(m,\
    \ f, v.val, 0, 1);\n            v.sum = acted_monoid::apply_mapping(m, f, v.sum,\
    \ 0, v.sz);\n            v.rsum = acted_monoid::apply_mapping(m, f, v.rsum, 0,\
    \ v.sz);\n            v.lz = v.has_lz ? m.composition(f, v.lz) : f;\n        \
    \    v.has_lz = true;\n        }\n    }\n    static void toggle(int t) {\n   \
    \     if (!t) return;\n        Node& v = node(t);\n        std::swap(v.l, v.r);\n\
    \        std::swap(v.sum, v.rsum);\n        v.rev = !v.rev;\n    }\n    void push(int\
    \ t) {\n        Node& v = node(t);\n        if (v.rev) {\n            toggle(v.l),\
    \ toggle(v.r);\n            v.rev = false;\n        }\n        if constexpr (acted)\
    \ {\n            if (v.has_lz) {\n                all_apply(v.l, v.lz), all_apply(v.r,\
    \ v.lz);\n                v.has_lz = false;\n            }\n        }\n    }\n\
    \n    int merge_node(int a, int b) {\n        if (!a || !b) return a ^ b;\n  \
    \      // \u5927\u304D\u3055\u306B\u6BD4\u4F8B\u3059\u308B\u78BA\u7387\u3067\u6839\
    \u3092\u9078\u3076 ([0, \u5927\u304D\u3055\u306E\u548C) \u306E\u4E71\u6570\u3092\
    \u3001\u5272\u308A\u7B97\u306E\u4EE3\u308F\u308A\u306B\u639B\u3051\u7B97\u3068\
    \u30B7\u30D5\u30C8\u3067\u4F5C\u308B)\n        if ((static_cast<std::uint64_t>(rand())\
    \ * (static_cast<std::uint64_t>(node(a).sz) + node(b).sz) >> 32) < static_cast<std::uint64_t>(node(a).sz))\
    \ {\n            push(a);\n            int c = merge_node(node(a).r, b);\n   \
    \         node(a).r = c;\n            update(a);\n            return a;\n    \
    \    }\n        push(b);\n        int c = merge_node(a, node(b).l);\n        node(b).l\
    \ = c;\n        update(b);\n        return b;\n    }\n    // \u5148\u982D k \u500B\
    \u3068\u6B8B\u308A\u306B\u5206\u3051\u308B\n    std::pair<int, int> split_node(int\
    \ t, int k) {\n        if (!t) return {0, 0};\n        push(t);\n        int ls\
    \ = node(node(t).l).sz;\n        if (k <= ls) {\n            auto [a, b] = split_node(node(t).l,\
    \ k);\n            node(t).l = b;\n            update(t);\n            return\
    \ {a, t};\n        }\n        auto [a, b] = split_node(node(t).r, k - ls - 1);\n\
    \        node(t).r = a;\n        update(t);\n        return {t, b};\n    }\n \
    \   int build(const std::vector<S>& v, int lo, int hi) {\n        if (lo >= hi)\
    \ return 0;\n        int mid = (lo + hi) / 2;\n        int lc = build(v, lo, mid);\n\
    \        int t = new_node(v[mid]);\n        int rc = build(v, mid + 1, hi);\n\
    \        node(t).l = lc, node(t).r = rc;\n        update(t);\n        return t;\n\
    \    }\n    // [l, r) \u3092\u53D6\u308A\u51FA\u3057\u3066 f \u3092\u4F5C\u7528\
    \u3055\u305B\u3001\u5143\u306B\u623B\u3059\n    template <typename Fn>\n    auto\
    \ with_range(long long l, long long r, Fn fn) {\n        assert(0 <= l && l <=\
    \ r && r <= size());\n        auto [a, bc] = split_node(root, static_cast<int>(l));\n\
    \        auto [b, c] = split_node(bc, static_cast<int>(r - l));\n        if constexpr\
    \ (std::is_void_v<decltype(fn(b))>) {\n            fn(b);\n            root =\
    \ merge_node(merge_node(a, b), c);\n        } else {\n            auto res = fn(b);\n\
    \            root = merge_node(merge_node(a, b), c);\n            return res;\n\
    \        }\n    }\n    void to_vector(int t, std::vector<S>& res) {\n        if\
    \ (!t) return;\n        push(t);\n        to_vector(node(t).l, res);\n       \
    \ res.push_back(node(t).val);\n        to_vector(node(t).r, res);\n    }\n\n \
    \   class RBSTReference {\n        RBST& t;\n        long long k;\n\n       public:\n\
    \        RBSTReference(RBST& t, long long k) : t(t), k(k) {}\n        RBSTReference&\
    \ operator=(const S& x) {\n            t.set(k, x);\n            return *this;\n\
    \        }\n        operator S() { return t.get(k); }\n    };\n\n    struct FromRoot\
    \ {};\n    RBST(int root, const M& m, FromRoot) : m(m), root(root) {}\n\n   public:\n\
    \    /**\n     * @brief \u7A7A\u306E\u5217\n     */\n    explicit RBST(M m = M())\
    \ : m(std::move(m)) {}\n    /**\n     * @brief \u9577\u3055 n \u3067\u3001\u3059\
    \u3079\u3066\u5358\u4F4D\u5143\u306E\u5217\n     */\n    explicit RBST(long long\
    \ n, M m = M()) : RBST(std::vector<S>(n, m.e()), m) {}\n    /**\n     * @brief\
    \ v \u306E\u5217 O(n)\n     */\n    explicit RBST(const std::vector<S>& v, M m\
    \ = M()) : m(std::move(m)) { root = build(v, 0, static_cast<int>(v.size())); }\n\
    \    /**\n     * @brief \u8907\u88FD\u3059\u308B O(n)\n     */\n    RBST(const\
    \ RBST& o) : m(o.m) { root = const_cast<RBST&>(o).clone_tree(o.root); }\n    RBST(RBST&&\
    \ o) noexcept : m(std::move(o.m)), root(o.root) { o.root = 0; }\n    RBST& operator=(const\
    \ RBST& o) {\n        if (this != &o) {\n            int c = const_cast<RBST&>(o).clone_tree(o.root);\n\
    \            free_tree(root);\n            m = o.m, root = c;\n        }\n   \
    \     return *this;\n    }\n    RBST& operator=(RBST&& o) noexcept {\n       \
    \ if (this != &o) {\n            free_tree(root);\n            m = std::move(o.m),\
    \ root = o.root;\n            o.root = 0;\n        }\n        return *this;\n\
    \    }\n    ~RBST() { free_tree(root); }\n\n    /**\n     * @brief \u5217\u306E\
    \u9577\u3055\n     */\n    long long size() const { return size_of(root); }\n\
    \    /**\n     * @brief \u7A7A\u304B\n     */\n    bool empty() const { return\
    \ root == 0; }\n\n    /**\n     * @brief k \u756A\u76EE\u306E\u5024\n     */\n\
    \    S get(long long k) {\n        assert(0 <= k && k < size());\n        int\
    \ t = root;\n        while (true) {\n            push(t);\n            int ls\
    \ = node(node(t).l).sz;\n            if (k < ls) {\n                t = node(t).l;\n\
    \            } else if (k == ls) {\n                return node(t).val;\n    \
    \        } else {\n                k -= ls + 1;\n                t = node(t).r;\n\
    \            }\n        }\n    }\n    /**\n     * @brief k \u756A\u76EE\u306E\u8981\
    \u7D20\u3078\u306E\u53C2\u7167 (\u4EE3\u5165\u3059\u308B\u3068 set \u304C\u547C\
    \u3070\u308C\u308B)\n     */\n    RBSTReference operator[](long long k) { return\
    \ RBSTReference(*this, k); }\n    /**\n     * @brief k \u756A\u76EE\u306E\u5024\
    \u3092 x \u306B\u3059\u308B\n     */\n    void set(long long k, const S& x) {\n\
    \        assert(0 <= k && k < size());\n        with_range(k, k + 1, [&](int t)\
    \ { node(t).val = node(t).sum = node(t).rsum = x; });\n    }\n    /**\n     *\
    \ @brief k \u756A\u76EE (0 <= k <= size()) \u306B x \u3092\u633F\u5165\u3059\u308B\
    \u3002\u5F8C\u308D\u306E\u8981\u7D20\u306F 1 \u3064\u305A\u3064\u305A\u308C\u308B\
    \n     */\n    void insert(long long k, const S& x) {\n        assert(0 <= k &&\
    \ k <= size());\n        auto [a, b] = split_node(root, static_cast<int>(k));\n\
    \        root = merge_node(merge_node(a, new_node(x)), b);\n    }\n    void push_front(const\
    \ S& x) { insert(0, x); }\n    void push_back(const S& x) { insert(size(), x);\
    \ }\n    /**\n     * @brief k \u756A\u76EE\u3092\u524A\u9664\u3057\u3066\u3001\
    \u305D\u306E\u5024\u3092\u8FD4\u3059\n     */\n    S erase(long long k) {\n  \
    \      assert(0 <= k && k < size());\n        auto [a, bc] = split_node(root,\
    \ static_cast<int>(k));\n        auto [b, c] = split_node(bc, 1);\n        S x\
    \ = node(b).val;\n        free_tree(b);\n        root = merge_node(a, c);\n  \
    \      return x;\n    }\n    S pop_front() { return erase(0); }\n    S pop_back()\
    \ { return erase(size() - 1); }\n\n    /**\n     * @brief [l, r) \u306E\u7A4D\n\
    \     */\n    S prod(long long l, long long r) {\n        return with_range(l,\
    \ r, [&](int t) { return sum_of(t); });\n    }\n    /**\n     * @brief \u5217\u5168\
    \u4F53\u306E\u7A4D O(1)\n     */\n    S all_prod() const { return sum_of(root);\
    \ }\n    /**\n     * @brief [l, r) \u3092\u53CD\u8EE2\u3059\u308B\n     */\n \
    \   void reverse(long long l, long long r) {\n        with_range(l, r, [&](int\
    \ t) { toggle(t); });\n    }\n    /**\n     * @brief [l, r) \u306E\u5404\u5024\
    \u306B f \u3092\u4F5C\u7528\u3055\u305B\u308B (\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\u306E\u3068\u304D)\n     */\n    template <bool B = acted,\
    \ std::enable_if_t<B, std::nullptr_t> = nullptr>\n    void apply(long long l,\
    \ long long r, const F& f) {\n        with_range(l, r, [&](int t) { all_apply(t,\
    \ f); });\n    }\n    /**\n     * @brief k \u756A\u76EE\u306E\u5024\u306B f \u3092\
    \u4F5C\u7528\u3055\u305B\u308B (\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9\u306E\u3068\u304D)\n     */\n    template <bool B = acted, std::enable_if_t<B,\
    \ std::nullptr_t> = nullptr>\n    void apply(long long k, const F& f) {\n    \
    \    assert(0 <= k && k < size());\n        apply(k, k + 1, f);\n    }\n\n   \
    \ /**\n     * @brief \u672B\u5C3E\u306B other \u3092\u3064\u306A\u3052\u308B\u3002\
    other \u306F\u7A7A\u306B\u306A\u308B\n     */\n    void merge(RBST&& other) {\n\
    \        root = merge_node(root, other.root);\n        other.root = 0;\n    }\n\
    \    /**\n     * @brief \u5148\u982D k \u500B\u3092\u6B8B\u3057\u3001\u6B8B\u308A\
    \u3092\u5207\u308A\u53D6\u3063\u3066\u8FD4\u3059\n     */\n    RBST split(long\
    \ long k) {\n        assert(0 <= k && k <= size());\n        auto [a, b] = split_node(root,\
    \ static_cast<int>(k));\n        root = a;\n        return RBST(b, m, FromRoot{});\n\
    \    }\n\n    /**\n     * @brief g(prod(l, r)) \u304C true \u3068\u306A\u308B\u6700\
    \u5927\u306E r (g(e()) \u306F true \u3067\u3042\u308B\u3053\u3068)\n     * g \u304C\
    \u5358\u8ABF\u306A\u3089\u3001g(prod(l, r)) \u304C true \u3068\u306A\u308B r \u306F\
    \ l \u304B\u3089\u59CB\u307E\u308B\u533A\u9593\u3092\u306A\u3059\n     */\n  \
    \  template <typename G>\n    long long max_right(long long l, G g) {\n      \
    \  assert(0 <= l && l <= size());\n        assert(g(e()));\n        auto [a, b]\
    \ = split_node(root, static_cast<int>(l));\n        long long res = l;\n     \
    \   S acc = e();\n        int t = b;\n        while (t) {\n            push(t);\n\
    \            S s = op(acc, sum_of(node(t).l));\n            if (!g(s)) {\n   \
    \             t = node(t).l;\n                continue;\n            }\n     \
    \       S s2 = op(s, node(t).val);\n            if (!g(s2)) {\n              \
    \  res += node(node(t).l).sz;\n                break;\n            }\n       \
    \     acc = s2;\n            res += node(node(t).l).sz + 1;\n            t = node(t).r;\n\
    \        }\n        root = merge_node(a, b);\n        return res;\n    }\n   \
    \ /**\n     * @brief g(prod(l, r)) \u304C true \u3068\u306A\u308B\u6700\u5C0F\u306E\
    \ l (g(e()) \u306F true \u3067\u3042\u308B\u3053\u3068)\n     */\n    template\
    \ <typename G>\n    long long min_left(long long r, G g) {\n        assert(0 <=\
    \ r && r <= size());\n        assert(g(e()));\n        auto [a, b] = split_node(root,\
    \ static_cast<int>(r));\n        long long res = r;\n        S acc = e();\n  \
    \      int t = a;\n        while (t) {\n            push(t);\n            S s\
    \ = op(sum_of(node(t).r), acc);\n            if (!g(s)) {\n                t =\
    \ node(t).r;\n                continue;\n            }\n            S s2 = op(node(t).val,\
    \ s);\n            if (!g(s2)) {\n                res -= node(node(t).r).sz;\n\
    \                break;\n            }\n            acc = s2;\n            res\
    \ -= node(node(t).r).sz + 1;\n            t = node(t).l;\n        }\n        root\
    \ = merge_node(a, b);\n        return res;\n    }\n\n    /**\n     * @brief \u5217\
    \u3092 std::vector \u306B\u3059\u308B O(n)\n     */\n    std::vector<S> to_vector()\
    \ {\n        std::vector<S> res;\n        res.reserve(size());\n        to_vector(root,\
    \ res);\n        return res;\n    }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, RBST& t) {\n        std::vector<S> v = t.to_vector();\n       \
    \ for (int i = 0; i < static_cast<int>(v.size()); i++) {\n            if (i !=\
    \ 0) os << CharT(' ');\n            os << v[i];\n        }\n        return os;\n\
    \    }\n};\n"
  dependsOn:
  - src/algebra/acted-monoid.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/data_structures/rbst.hpp
  requiredBy: []
  timestamp: '2026-10-19 20:07:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/rbst.test.cpp
  - test/yosupo/data_structure/range-reverse-range-sum.test.cpp
  - test/yosupo/data_structure/dynamic-sequence-range-affine-range-sum.test.cpp
documentation_of: src/data_structures/rbst.hpp
layout: document
title: "\u5E73\u8861\u4E8C\u5206\u6728 (RBST)"
---

位置で扱う列を、平衡二分木 (RBST、randomized binary search tree) で持ちます。セグメント木と違って、途中への挿入・削除、区間の反転、列の切り分けとつなぎ合わせ (split・merge) ができます。[モノイド](../algebra/monoid.hpp) か [作用素付きモノイド](../algebra/acted-monoid.hpp) を乗せて、区間積や区間作用も求められます。どの操作も期待 $O(\log n)$ です。

```cpp
RBST<acted_monoid::AffineSum<mint>> t(v);  // 区間アフィン変換・区間和
t.insert(2, x);                            // 2 番目の前に x を挿入
t.erase(0);                                // 0 番目を削除
t.reverse(1, 4);                           // [1, 4) を反転
t.apply(0, 3, Affine<mint>{b, c});         // [0, 3) の各値を b * x + c に
mint s = t.prod(1, 3);                     // [1, 3) の和

RBST<monoid::Max<long long>> u(w);  // 作用なし (区間作用以外は使える)
auto back = u.split(5);             // u は先頭 5 個、back は残り
back.reverse(0, back.size());
u.merge(std::move(back));           // 後ろ側を反転してつなぎ直す
```

- 作用素付きモノイドの `mapping` は `(f, x)` か `(f, x, sz)` の形にします。列の位置は挿入・削除で変わるので、`(f, x, l, r)` の形はコンパイルエラーになります。
- 区間反転のために、各頂点に部分木の逆順の積も持ちます。そのため、可換でないモノイド (1 次関数の合成など) を乗せても、反転した区間の積は正しくなります。
- 頂点は、乗せる型ごとに共有する配列に置きます。そのため、同じ型の木どうしで `split`・`merge` できます。削除した頂点や、破棄した木の頂点は再利用します。
- 木をコピーすると、すべての頂点を複製します ($O(n)$)。`split` で切り取った木や `merge` で渡す木は、コピーせずに頂点をそのまま移します。

## メンバ関数

位置・長さは `long long` です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RBST(m = M())` | 空の列 | $O(1)$ |
| `RBST(n, m = M())` | 長さ `n` で、すべて単位元の列 | $O(n)$ |
| `RBST(v, m = M())` | `std::vector` `v` の列 | $O(n)$ |
| `size()` / `empty()` | 長さ / 空か | $O(1)$ |
| `get(k)` / `t[k]` | `k` 番目の値 (`t[k] = x` で代入もできる) | 期待 $O(\log n)$ |
| `set(k, x)` | `k` 番目の値を `x` にする | 期待 $O(\log n)$ |
| `insert(k, x)` | `k` 番目 ($0 \le k \le$ `size()`) に `x` を挿入する。後ろの要素は 1 つずつずれる | 期待 $O(\log n)$ |
| `erase(k)` | `k` 番目を削除して、その値を返す | 期待 $O(\log n)$ |
| `push_front(x)` / `push_back(x)` | 先頭 / 末尾に追加する | 期待 $O(\log n)$ |
| `pop_front()` / `pop_back()` | 先頭 / 末尾を削除して、その値を返す | 期待 $O(\log n)$ |
| `prod(l, r)` | $[l, r)$ の積 | 期待 $O(\log n)$ |
| `all_prod()` | 列全体の積 | $O(1)$ |
| `reverse(l, r)` | $[l, r)$ を反転する | 期待 $O(\log n)$ |
| `apply(l, r, f)` / `apply(k, f)` | $[l, r)$ / `k` 番目の各値に `f` を作用させる (作用素付きモノイドのときだけ) | 期待 $O(\log n)$ |
| `split(k)` | 先頭 `k` 個を残し、残りを切り取って新しい木として返す | 期待 $O(\log n)$ |
| `merge(std::move(other))` | 末尾に `other` をつなげる。`other` は空になる | 期待 $O(\log n)$ |
| `max_right(l, g)` | `g(prod(l, r))` が `true` となる最大の `r` (`g` は単調で、`g(e())` は `true`) | 期待 $O(\log n)$ |
| `min_left(r, g)` | `g(prod(l, r))` が `true` となる最小の `l` | 期待 $O(\log n)$ |
| `to_vector()` | 列を `std::vector` にする | $O(n)$ |
| `os << t` | 値を空白区切りで出力する | $O(n)$ |

`static constexpr bool acted` は、乗せた型が作用素付きモノイドかどうかです。

## 関連

- 挿入・削除・反転が要らなければ [セグメント木](segtree.hpp) や [遅延伝搬セグメント木](lazy-segtree.hpp) のほうが速い
- 値の順に並べた集合で k 番目を求めるなら、座標圧縮して [Fenwick Tree](fenwick-tree.hpp) の二分探索を使う
