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
    path: src/data_structures/dual-segtree-2d.hpp
    title: "2\u6B21\u5143\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u9577\u65B9\
      \u5F62\u4F5C\u7528\u30011\u70B9\u53D6\u5F97)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/rectangle.hpp
    title: "\u8EF8\u306B\u5E73\u884C\u306A\u9577\u65B9\u5F62"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/data_structures/dual-segtree-2d.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// DualSegTree2D \u306E apply\u30FBget \u3092\u3001\u8CA0\u306E\u5EA7\u6A19\
    \u30FB\u91CD\u8907\u3057\u305F\u70B9\u30FB\u52A0\u7B97\u3068 chmin \u3068\u521D\
    \u671F\u5024\u3067\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u8F03\u3059\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #line 2 \"src/data_structures/dual-segtree-2d.hpp\"\n\n/**\n * @file dual-segtree-2d.hpp\n\
    \ * @brief 2\u6B21\u5143\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u9577\
    \u65B9\u5F62\u4F5C\u7528\u30011\u70B9\u53D6\u5F97)\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iterator>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"src/algebra/acted-monoid.hpp\"\n\n/**\n * @file acted-monoid.hpp\n\
    \ * @brief \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306F\u30E2\u30CE\
    \u30A4\u30C9 (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\
    \u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\
    \u3059\n * - using F: \u4F5C\u7528\u7D20\u306E\u578B\n * - S mapping(const F&\
    \ f, const S& x): \u4F5C\u7528\u7D20\u306E\u9069\u7528 f(x)\n *   \u533A\u9593\
    \u306E\u60C5\u5831\u304C\u5FC5\u8981\u306A\u5834\u5408\u306F mapping(f, x, sz)\
    \ (sz \u306F\u533A\u9593\u306E\u9577\u3055) \u3084 mapping(f, x, l, r) (\u533A\
    \u9593 [l, r)) \u3067\u3082\u3088\u3044\n *   sz, l, r \u306F long long \u3067\
    \u6E21\u3059 (\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u306F int\
    \ \u306B\u53CE\u307E\u3089\u306A\u3044\u3053\u3068\u304C\u3042\u308B)\n * - F\
    \ composition(const F& f, const F& g): \u4F5C\u7528\u7D20\u306E\u5408\u6210 f\u2218\
    g (g\u3092\u9069\u7528\u3057\u305F\u5F8C\u306Bf\u3092\u9069\u7528\u3059\u308B\
    )\n * - F id(): \u6052\u7B49\u5199\u50CF\n * \u4F5C\u7528\u7D20\u304C\u7FA4\u3092\
    \u306A\u3059\u5834\u5408 (imos.hpp \u3067\u4F7F\u3046) \u306F\n * - F inv(const\
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
    \ U>;\n    using F = T;\n    // \u5358\u4F4D\u5143 (\u4F4D\u7F6E\u304C -1) \u306F\
    \u5358\u4F4D\u5143\u306E\u307E\u307E (\u578B\u306E\u6700\u5927\u5024\u30FB\u6700\
    \u5C0F\u5024\u306B\u8DB3\u3057\u3066\u3042\u3075\u308C\u306A\u3044\u3088\u3046\
    \u306B)\n    static constexpr S mapping(const F& f, const S& x) {\n        if\
    \ (internal_monoid::with_is_e(x.second)) return x;\n        return {x.first +\
    \ f, x.second};\n    }\n    static constexpr F composition(const F& f, const F&\
    \ g) { return f + g; }\n    static constexpr F id() { return F(0); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\u5024\u3068\u305D\
    \u306E\u4F4D\u7F6E (monoid::MaxWith)\n */\ntemplate <typename T, typename U =\
    \ long long>\nstruct AddMaxWith : monoid::MaxWith<T, U> {\n    using S = std::pair<T,\
    \ U>;\n    using F = T;\n    // \u5358\u4F4D\u5143 (\u4F4D\u7F6E\u304C -1) \u306F\
    \u5358\u4F4D\u5143\u306E\u307E\u307E (\u578B\u306E\u6700\u5927\u5024\u30FB\u6700\
    \u5C0F\u5024\u306B\u8DB3\u3057\u3066\u3042\u3075\u308C\u306A\u3044\u3088\u3046\
    \u306B)\n    static constexpr S mapping(const F& f, const S& x) {\n        if\
    \ (internal_monoid::with_is_e(x.second)) return x;\n        return {x.first +\
    \ f, x.second};\n    }\n    static constexpr F composition(const F& f, const F&\
    \ g) { return f + g; }\n    static constexpr F id() { return F(0); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\
    \u306E\u500B\u6570 (monoid::MinCount)\n */\ntemplate <typename T, typename U =\
    \ long long>\nstruct AddMinCount : monoid::MinCount<T, U> {\n    using S = std::pair<T,\
    \ U>;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return {x.first + f, x.second}; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\
    \u5024\u3068\u305D\u306E\u500B\u6570 (monoid::MaxCount)\n */\ntemplate <typename\
    \ T, typename U = long long>\nstruct AddMaxCount : monoid::MaxCount<T, U> {\n\
    \    using S = std::pair<T, U>;\n    using F = T;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return {x.first + f, x.second}; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f + g; }\n    static constexpr\
    \ F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\
    \u533A\u9593\u306E0\u4E57\u548C\u304B\u3089K\u4E57\u548C\n *\n * S(x) \u3067\u5024\
    \ x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\
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
    #line 2 \"src/geometry/rectangle.hpp\"\n\n/**\n * @file rectangle.hpp\n * @brief\
    \ \u8EF8\u306B\u5E73\u884C\u306A\u9577\u65B9\u5F62\n */\n\n#line 11 \"src/geometry/rectangle.hpp\"\
    \n\n#line 2 \"src/geometry/vector.hpp\"\n\n/**\n * @file vector.hpp\n * @brief\
    \ \u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB\n */\n\n#line 10 \"src/geometry/vector.hpp\"\
    \n#include <cmath>\n#line 15 \"src/geometry/vector.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"\
    src/utility/traits.hpp\"\n#include <functional>\n#line 11 \"src/utility/traits.hpp\"\
    \n#include <set>\n#line 14 \"src/utility/traits.hpp\"\n\nnamespace internal_traits\
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
    #line 17 \"src/geometry/vector.hpp\"\n\n/**\n * @brief \u5E7E\u4F55\u5B66\u3068\
    \u3057\u3066\u306E\u30D9\u30AF\u30C8\u30EB\n *\n * @tparam T \u578B \u7701\u7565\
    \u3057\u305F\u3089double\n * @tparam Dim \u6B21\u5143 \u7701\u7565\u3057\u305F\
    \u30892\n */\ntemplate <typename T = double, int Dim = 2, ENABLE_IF_T(std::is_scalar_v<T>\
    \ && (Dim > 0))>\nstruct Vector {\n    std::array<T, Dim> v;  //!< \u30D9\u30AF\
    \u30C8\u30EB\u306E\u6210\u5206\u8868\u793A\n\n    /**\n     * @brief \u30C7\u30D5\
    \u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * \u30BC\u30ED\
    \u30D9\u30AF\u30C8\u30EB\n     */\n    constexpr Vector() noexcept : v() {}\n\
    \    /**\n     * @brief \u53EF\u5909\u9577\u5F15\u6570\u306B\u3088\u308B\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * \u5404\u6210\u5206\u3092\
    \ T \u306B\u5909\u63DB\u3057\u3066\u5165\u308C\u308B (Vector(1, 2.5) \u306E\u3088\
    \u3046\u306B\u578B\u304C\u6DF7\u3056\u3063\u3066\u3082\u7E2E\u5C0F\u5909\u63DB\
    \u306E\u8B66\u544A\u3092\u51FA\u3055\u306A\u3044)\n     * @tparam Args\n     */\n\
    \    template <typename... Args>\n    constexpr Vector(Args... args) noexcept\
    \ : v{static_cast<T>(args)...} {}\n\n    /**\n     * @brief i\u756A\u76EE\u306E\
    \u6210\u5206\u3092\u8FD4\u3059\n     *\n     * @param i\n     * @return T&\n \
    \    */\n    constexpr T& operator[](long long i) noexcept {\n        return v[i];\n\
    \    }\n    /**\n     * @brief i\u756A\u76EE\u306E\u6210\u5206\u3092\u8FD4\u3059\
    \n     *\n     * @param i\n     * @return T&\n     */\n    constexpr const T&\
    \ operator[](long long i) const noexcept {\n        return v[i];\n    }\n\n  \
    \  /**\n     * @brief \u52A0\u7B97\u4EE3\u5165\u6F14\u7B97\u5B50\n     *\n   \
    \  * @param rhs\n     * @return Vector&\n     */\n    constexpr Vector& operator+=(const\
    \ Vector& rhs) noexcept {\n        for (int i = 0; i < Dim; i++) v[i] += rhs[i];\n\
    \        return *this;\n    }\n    /**\n     * @brief \u6E1B\u7B97\u4EE3\u5165\
    \u6F14\u7B97\u5B50\n     *\n     * @param rhs\n     * @return Vector&\n     */\n\
    \    constexpr Vector& operator-=(const Vector& rhs) noexcept {\n        for (int\
    \ i = 0; i < Dim; i++) v[i] -= rhs.v[i];\n        return *this;\n    }\n    /**\n\
    \     * @brief \u30B9\u30AB\u30E9\u30FC\u500D\u4EE3\u5165\u6F14\u7B97\u5B50\n\
    \     *\n     * @param coef\n     * @return Vector&\n     */\n    constexpr Vector&\
    \ operator*=(const T& coef) noexcept {\n        for (int i = 0; i < Dim; i++)\
    \ v[i] *= coef;\n        return *this;\n    }\n    /**\n     * @brief \u30B9\u30AB\
    \u30E9\u30FC\u306E\u9006\u6570\u500D\u4EE3\u5165\u6F14\u7B97\u5B50\n     *\n \
    \    * @param coef\n     * @return Vector&\n     */\n    constexpr Vector& operator/=(const\
    \ T& coef) {\n        for (int i = 0; i < Dim; i++) {\n            if constexpr\
    \ (std::is_integral_v<T>) {\n                assert(v[i] % coef == 0 && \"Vector::operator/=\
    \ : coef must be a divisor of all elements\");\n            }\n            v[i]\
    \ /= coef;\n        }\n        return *this;\n    }\n\n    /**\n     * @brief\
    \ \u5358\u9805\u30D7\u30E9\u30B9\u6F14\u7B97\u5B50\n     *\n     * @return Vector\n\
    \     */\n    [[nodiscard]]\n    constexpr Vector operator+() const noexcept {\n\
    \        return *this;\n    }\n    /**\n     * @brief \u5358\u9805\u30DE\u30A4\
    \u30CA\u30B9\u6F14\u7B97\u5B50\n     *\n     * @return Vector\n     */\n    [[nodiscard]]\n\
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
    \ std::sqrt(squared_norm());\n    }\n};\n\n/**\n * @brief \u6210\u5206\u304B\u3089\
    \u4F5C\u308B\u3068\u304D\u306E\u63A8\u8AD6\u30AC\u30A4\u30C9\u3002\u578B\u306F\
    \u6210\u5206\u306E\u5171\u901A\u306E\u578B\u3001\u6B21\u5143\u306F\u6210\u5206\
    \u306E\u500B\u6570\u306B\u3059\u308B\n *\n * Vector(2LL, 3LL) \u306F Vector<long\
    \ long, 2>\u3001Vector(1, 2, 3) \u306F Vector<int, 3>\u3001Vector(0.0, 0.0) \u306F\
    \ Vector<double, 2>\n * (\u3053\u308C\u304C\u306A\u3044\u3068\u3001\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u306E\u7701\u7565\u6642\u306E\u5024\u304B\
    \u3089 Vector<double, 2> \u306B\u306A\u3063\u3066\u3057\u307E\u3046)\n */\ntemplate\
    \ <typename T, typename... U, ENABLE_IF_T(std::is_scalar_v<T> && (std::is_scalar_v<U>\
    \ && ...))>\nVector(T, U...) -> Vector<std::common_type_t<T, U...>, 1 + sizeof...(U)>;\n\
    \n/**\n * @brief \u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u3069\u3046\u3057\u306E\
    \u5916\u7A4D(\u5E73\u884C\u56DB\u8FBA\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\
    \u7A4D)\n *\n * @param lhs\n * @param rhs\n * @tparam T \u5EA7\u6A19\u306E\u578B\
    \n * @return T\n */\ntemplate <typename T>\nconstexpr T cross(const Vector<T,\
    \ 2>& lhs, const Vector<T, 2>& rhs) noexcept {\n    return lhs[0] * rhs[1] - lhs[1]\
    \ * rhs[0];\n}\n/**\n * @brief \u4E09\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u3069\
    \u3046\u3057\u306E\u5916\u7A4D\n *\n * @param lhs\n * @param rhs\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @return Vector<T, 3>\n */\ntemplate <typename T>\n\
    constexpr Vector<T, 3> cross(const Vector<T, 3>& lhs, const Vector<T, 3>& rhs)\
    \ noexcept {\n    Vector<T, 3> ret;\n    ret[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];\n\
    \    ret[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];\n    ret[2] = lhs[0] * rhs[1]\
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n\n/**\n * @brief 3\u70B9\u306E\u4F4D\
    \u7F6E\u95A2\u4FC2 (counter-clockwise)\n *\n * \u6574\u6570\u578B\u3067\u3082\u4F7F\
    \u3048\u308B\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u3067\u306F\u8AA4\u5DEE\
    \u3092\u8003\u3048\u305A\u306B\u6BD4\u8F03\u3059\u308B\n *\n * @tparam T \u5EA7\
    \u6A19\u306E\u578B\n * @return int 1: a\u2192b\u2192c \u304C\u53CD\u6642\u8A08\
    \u56DE\u308A, -1: \u6642\u8A08\u56DE\u308A, 2: c, a, b \u306E\u9806\u306B\u4E00\
    \u76F4\u7DDA\u4E0A, -2: a, b, c \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A, 0:\
    \ c \u304C\u7DDA\u5206 ab \u4E0A\n */\ntemplate <typename T>\nconstexpr int ccw(const\
    \ Vector<T, 2>& a, const Vector<T, 2>& b, const Vector<T, 2>& c) {\n    Vector<T,\
    \ 2> u = b - a, v = c - a;\n    T cr = cross(u, v);\n    if (cr > 0) return 1;\n\
    \    if (cr < 0) return -1;\n    if (dot(u, v) < 0) return 2;\n    if (u.squared_norm()\
    \ < v.squared_norm()) return -2;\n    return 0;\n}\n#line 13 \"src/geometry/rectangle.hpp\"\
    \n\n/**\n * @brief \u534A\u958B\u9818\u57DF [left, right) \xD7 [bottom, top)\u3002\
    \u5E45\u30FB\u9AD8\u3055 0 \u3082\u8A31\u3059\n * @tparam T \u5EA7\u6A19\u306E\
    \u578B\u3002\u7701\u7565\u3057\u305F\u3089 long long\n */\ntemplate <typename\
    \ T = long long>\nstruct Rectangle {\n    T left{}, bottom{}, right{}, top{};\n\
    \n    constexpr Rectangle() = default;\n    constexpr Rectangle(T left, T bottom,\
    \ T right, T top) : left(left), bottom(bottom), right(right), top(top) {\n   \
    \     assert(left <= right && bottom <= top);\n    }\n    constexpr T width()\
    \ const { return right - left; }\n    constexpr T height() const { return top\
    \ - bottom; }\n    constexpr T area() const { return width() * height(); }\n \
    \   constexpr bool empty() const { return left == right || bottom == top; }\n\
    \    /** @brief \u5DE6\u8FBA\u30FB\u4E0B\u8FBA\u3092\u542B\u307F\u3001\u53F3\u8FBA\
    \u30FB\u4E0A\u8FBA\u3092\u542B\u307E\u306A\u3044\u5305\u542B\u5224\u5B9A */\n\
    \    constexpr bool contains(T x, T y) const {\n        return left <= x && x\
    \ < right && bottom <= y && y < top;\n    }\n    constexpr bool contains(const\
    \ Vector<T, 2>& p) const { return contains(p[0], p[1]); }\n    /** @brief 4 \u8FBA\
    \u306E\u5EA7\u6A19\u304C\u3059\u3079\u3066\u7B49\u3057\u3044\u304B (\u7A7A\u306E\
    \u9577\u65B9\u5F62\u3067\u3082\u5EA7\u6A19\u3092\u6BD4\u8F03\u3059\u308B) */\n\
    \    constexpr bool operator==(const Rectangle& other) const {\n        return\
    \ left == other.left && bottom == other.bottom && right == other.right && top\
    \ == other.top;\n    }\n    constexpr bool operator!=(const Rectangle& other)\
    \ const { return !(*this == other); }\n\n    /** @brief left bottom right top\
    \ \u306E\u9806\u306B\u8AAD\u307F\u8FBC\u3080 */\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, Rectangle& rhs) {\n        if (is >> rhs.left >> rhs.bottom >>\
    \ rhs.right >> rhs.top) {\n            assert(rhs.left <= rhs.right && rhs.bottom\
    \ <= rhs.top);\n        }\n        return is;\n    }\n};\n\ntemplate <typename\
    \ A, typename B, typename C, typename D>\nRectangle(A, B, C, D) -> Rectangle<std::common_type_t<A,\
    \ B, C, D>>;\n#line 16 \"src/data_structures/dual-segtree-2d.hpp\"\n\n/**\n *\
    \ @brief 2\u6B21\u5143\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u53D6\
    \u5F97\u3059\u308B\u70B9\u3092\u5148\u8AAD\u307F\u3059\u308B)\n *\n * x \u5EA7\
    \u6A19\u306E\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u5404\u30CE\u30FC\u30C9\
    \u306B\u3001\u305D\u306E\u90E8\u5206\u6728\u306B\u3042\u308B\u70B9\u306E y \u5EA7\
    \u6A19\u306E\u5217\u3068\u3001\u305D\u306E\u4E0A\u306E\u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3092\u6301\u305F\u305B\u308B\u3002\n * \u4F5C\u7528\u7D20\
    \u3092\u4E0B\u3078\u4F1D\u3048\u306A\u3044\u306E\u3067\u3001\u4F5C\u7528\u7D20\
    \u306E\u5408\u6210\u306F\u53EF\u63DB\u3067\u306A\u3051\u308C\u3070\u306A\u3089\
    \u306A\u3044\n *\n * @tparam A \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9 (algebra/acted-monoid.hpp)\u3002composition \u306F\u53EF\u63DB\n */\ntemplate\
    \ <typename A>\nclass DualSegTree2D {\n   public:\n    using S = typename A::S;\n\
    \    using F = typename A::F;\n\n   private:\n    A a;\n    F composition(const\
    \ F& f, const F& g) const { return a.composition(f, g); }\n    F id() const {\
    \ return a.id(); }\n\n    int n;                                  // x \u5EA7\u6A19\
    \u306E\u7A2E\u985E\u6570\n    S init;                                 // \u5404\
    \u70B9\u306E\u521D\u671F\u5024\n    std::vector<long long> xs, ys;          //\
    \ \u5727\u7E2E\u3057\u305F\u5EA7\u6A19\n    std::vector<std::vector<int>> node_ys;\
    \  // \u5404\u30CE\u30FC\u30C9\u306B\u3042\u308B\u70B9\u306E y \u306E\u756A\u53F7\
    \ (\u6607\u9806)\n    std::vector<std::vector<F>> lazy;       // \u5404\u30CE\u30FC\
    \u30C9\u306E y \u306E\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5927\u304D\
    \u3055\u306F 2 * node_ys[k].size())\n\n    int lower(int k, int yi) const { return\
    \ static_cast<int>(std::lower_bound(node_ys[k].begin(), node_ys[k].end(), yi)\
    \ - node_ys[k].begin()); }\n\n    void construct(const std::vector<std::pair<long\
    \ long, long long>>& points) {\n        for (auto [x, y] : points) {\n       \
    \     xs.push_back(x);\n            ys.push_back(y);\n        }\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \        std::sort(ys.begin(), ys.end());\n        ys.erase(std::unique(ys.begin(),\
    \ ys.end()), ys.end());\n        n = static_cast<int>(xs.size());\n        node_ys.resize(2\
    \ * n);\n        for (auto [x, y] : points) {\n            int xi = static_cast<int>(std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin());\n            node_ys[n + xi].push_back(static_cast<int>(std::lower_bound(ys.begin(),\
    \ ys.end(), y) - ys.begin()));\n        }\n        for (int k = n; k < 2 * n;\
    \ k++) {\n            std::sort(node_ys[k].begin(), node_ys[k].end());\n     \
    \       node_ys[k].erase(std::unique(node_ys[k].begin(), node_ys[k].end()), node_ys[k].end());\n\
    \        }\n        for (int k = n - 1; k >= 1; k--) {\n            const auto\
    \ &l = node_ys[2 * k], &r = node_ys[2 * k + 1];\n            std::set_union(l.begin(),\
    \ l.end(), r.begin(), r.end(), std::back_inserter(node_ys[k]));\n        }\n \
    \       lazy.resize(2 * n);\n        for (int k = 1; k < 2 * n; k++) lazy[k].assign(2\
    \ * node_ys[k].size(), id());\n    }\n\n   public:\n    /**\n     * @param points\
    \ get \u3059\u308B\u70B9 (x, y) \u306E\u5217 (\u91CD\u8907\u3057\u3066\u3088\u3044\
    )\u3002\u5404\u70B9\u306F S() \u3067\u521D\u671F\u5316\u3059\u308B\n     * @param\
    \ a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ DualSegTree2D(const std::vector<std::pair<long long, long long>>& points = {},\
    \ A a = A()) : DualSegTree2D(points, S(), std::move(a)) {}\n    /**\n     * @param\
    \ points get \u3059\u308B\u70B9 (x, y) \u306E\u5217 (\u91CD\u8907\u3057\u3066\u3088\
    \u3044)\n     * @param value \u5404\u70B9\u306E\u521D\u671F\u5024\n     * @param\
    \ a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    DualSegTree2D(const\
    \ std::vector<std::pair<long long, long long>>& points, const S& value, A a =\
    \ A()) : a(std::move(a)), init(value) { construct(points); }\n\n    /**\n    \
    \ * @brief [lx, rx) x [ly, ry) \u306B\u3042\u308B\u70B9\u306E\u5024\u306B f \u3092\
    \u4F5C\u7528\u3055\u305B\u308B O(log^2 P)\n     */\n    void apply(const Rectangle<long\
    \ long>& rect, const F& f) {\n        const auto& [lx, ly, rx, ry] = rect;\n \
    \       assert(lx <= rx && ly <= ry);\n        int l = static_cast<int>(std::lower_bound(xs.begin(),\
    \ xs.end(), lx) - xs.begin()) + n;\n        int r = static_cast<int>(std::lower_bound(xs.begin(),\
    \ xs.end(), rx) - xs.begin()) + n;\n        int lyi = static_cast<int>(std::lower_bound(ys.begin(),\
    \ ys.end(), ly) - ys.begin());\n        int ryi = static_cast<int>(std::lower_bound(ys.begin(),\
    \ ys.end(), ry) - ys.begin());\n        auto apply_node = [&](int k) {\n     \
    \       int len = static_cast<int>(node_ys[k].size());\n            for (int i\
    \ = lower(k, lyi) + len, j = lower(k, ryi) + len; i < j; i >>= 1, j >>= 1) {\n\
    \                if (i & 1) lazy[k][i] = composition(f, lazy[k][i]), i++;\n  \
    \              if (j & 1) --j, lazy[k][j] = composition(f, lazy[k][j]);\n    \
    \        }\n        };\n        for (; l < r; l >>= 1, r >>= 1) {\n          \
    \  if (l & 1) apply_node(l++);\n            if (r & 1) apply_node(--r);\n    \
    \    }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u70B9\u306E\
    \u5024\u3092\u8FD4\u3059 (\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u6E21\
    \u3057\u305F\u70B9\u306E\u307F) O(log^2 P)\n     */\n    S get(long long x, long\
    \ long y) const {\n        auto ix = std::lower_bound(xs.begin(), xs.end(), x);\n\
    \        auto iy = std::lower_bound(ys.begin(), ys.end(), y);\n        assert(ix\
    \ != xs.end() && *ix == x && iy != ys.end() && *iy == y);\n        int yi = static_cast<int>(iy\
    \ - ys.begin());\n        F f = id();\n        for (int k = n + static_cast<int>(ix\
    \ - xs.begin()); k >= 1; k >>= 1) {\n            int p = lower(k, yi);\n     \
    \       assert(p < static_cast<int>(node_ys[k].size()) && node_ys[k][p] == yi);\
    \  // \u6E21\u3057\u305F\u70B9\u304B\n            for (p += static_cast<int>(node_ys[k].size());\
    \ p >= 1; p >>= 1) f = composition(lazy[k][p], f);\n        }\n        return\
    \ acted_monoid::apply_mapping(a, f, init, 0, 1);\n    }\n};\n\ntemplate <typename\
    \ A>\nDualSegTree2D(std::vector<std::pair<long long, long long>>, A) -> DualSegTree2D<A>;\n\
    template <typename A>\nDualSegTree2D(std::vector<std::pair<long long, long long>>,\
    \ typename A::S, A) -> DualSegTree2D<A>;\n\n// \u5225\u540D (\u4F5C\u7528\u7D20\
    \u306E\u5408\u6210\u304C\u53EF\u63DB\u306A\u3082\u306E\u3060\u3051\u3002DualSegTree\
    \ \u306E\u5225\u540D\u3068\u540C\u3058\u304F Min \u7CFB\u3092\u5B9F\u4F53\u306B\
    \u3059\u308B)\n\n/**\n * @brief \u9577\u65B9\u5F62\u52A0\u7B97\u30011\u70B9\u53D6\
    \u5F97\n *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RAddQ2D = DualSegTree2D<acted_monoid::AddMin<S>>;\n\
    /**\n * @brief \u9577\u65B9\u5F62 chmin\u30011\u70B9\u53D6\u5F97\n *\n * @tparam\
    \ S \u578B\n */\ntemplate <typename S>\nusing RChminQ2D = DualSegTree2D<acted_monoid::ChminMin<S>>;\n\
    /**\n * @brief \u9577\u65B9\u5F62 chmax\u30011\u70B9\u53D6\u5F97\n *\n * @tparam\
    \ S \u578B\n */\ntemplate <typename S>\nusing RChmaxQ2D = DualSegTree2D<acted_monoid::ChmaxMax<S>>;\n\
    #line 7 \"test/unittest/data_structures/dual-segtree-2d.test.cpp\"\n\n#line 9\
    \ \"test/unittest/data_structures/dual-segtree-2d.test.cpp\"\n#include <iostream>\n\
    #include <map>\n#include <random>\n#line 14 \"test/unittest/data_structures/dual-segtree-2d.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 500 && ok; rep++) {\n        int c = rng() % 12 + 1;\n      \
    \  std::vector<std::pair<long long, long long>> points;\n        for (int i =\
    \ 0; i < c; i++) points.emplace_back(static_cast<long long>(rng() % 9) - 4, static_cast<long\
    \ long>(rng() % 9) - 4);\n        RAddQ2D<long long> add(points, 3);\n       \
    \ RChminQ2D<long long> mn(points, 100);\n        std::map<std::pair<long long,\
    \ long long>, long long> va, vm;\n        for (auto p : points) va[p] = 3, vm[p]\
    \ = 100;\n        for (int t = 0; t < 50; t++) {\n            if (rng() % 2) {\n\
    \                long long lx = static_cast<long long>(rng() % 13) - 6, rx = static_cast<long\
    \ long>(rng() % 13) - 6;\n                long long ly = static_cast<long long>(rng()\
    \ % 13) - 6, ry = static_cast<long long>(rng() % 13) - 6;\n                if\
    \ (lx > rx) std::swap(lx, rx);\n                if (ly > ry) std::swap(ly, ry);\n\
    \                long long v = static_cast<long long>(rng() % 41) - 20;\n    \
    \            add.apply(Rectangle(lx, ly, rx, ry), v);\n                mn.apply(Rectangle(lx,\
    \ ly, rx, ry), v);\n                for (auto& [p, x] : va)\n                \
    \    if (lx <= p.first && p.first < rx && ly <= p.second && p.second < ry) x +=\
    \ v;\n                for (auto& [p, x] : vm)\n                    if (lx <= p.first\
    \ && p.first < rx && ly <= p.second && p.second < ry) x = std::min(x, v);\n  \
    \          } else {\n                auto p = points[rng() % c];\n           \
    \     if (add.get(p.first, p.second) != va[p] || mn.get(p.first, p.second) !=\
    \ vm[p]) ok = false;\n            }\n        }\n    }\n    if (ok) std::cout <<\
    \ \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// DualSegTree2D \u306E apply\u30FBget \u3092\u3001\u8CA0\u306E\u5EA7\u6A19\
    \u30FB\u91CD\u8907\u3057\u305F\u70B9\u30FB\u52A0\u7B97\u3068 chmin \u3068\u521D\
    \u671F\u5024\u3067\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u8F03\u3059\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #include \"../../../src/data_structures/dual-segtree-2d.hpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <map>\n#include <random>\n#include <utility>\n#include\
    \ <vector>\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n\
    \    for (int rep = 0; rep < 500 && ok; rep++) {\n        int c = rng() % 12 +\
    \ 1;\n        std::vector<std::pair<long long, long long>> points;\n        for\
    \ (int i = 0; i < c; i++) points.emplace_back(static_cast<long long>(rng() % 9)\
    \ - 4, static_cast<long long>(rng() % 9) - 4);\n        RAddQ2D<long long> add(points,\
    \ 3);\n        RChminQ2D<long long> mn(points, 100);\n        std::map<std::pair<long\
    \ long, long long>, long long> va, vm;\n        for (auto p : points) va[p] =\
    \ 3, vm[p] = 100;\n        for (int t = 0; t < 50; t++) {\n            if (rng()\
    \ % 2) {\n                long long lx = static_cast<long long>(rng() % 13) -\
    \ 6, rx = static_cast<long long>(rng() % 13) - 6;\n                long long ly\
    \ = static_cast<long long>(rng() % 13) - 6, ry = static_cast<long long>(rng()\
    \ % 13) - 6;\n                if (lx > rx) std::swap(lx, rx);\n              \
    \  if (ly > ry) std::swap(ly, ry);\n                long long v = static_cast<long\
    \ long>(rng() % 41) - 20;\n                add.apply(Rectangle(lx, ly, rx, ry),\
    \ v);\n                mn.apply(Rectangle(lx, ly, rx, ry), v);\n             \
    \   for (auto& [p, x] : va)\n                    if (lx <= p.first && p.first\
    \ < rx && ly <= p.second && p.second < ry) x += v;\n                for (auto&\
    \ [p, x] : vm)\n                    if (lx <= p.first && p.first < rx && ly <=\
    \ p.second && p.second < ry) x = std::min(x, v);\n            } else {\n     \
    \           auto p = points[rng() % c];\n                if (add.get(p.first,\
    \ p.second) != va[p] || mn.get(p.first, p.second) != vm[p]) ok = false;\n    \
    \        }\n        }\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/data_structures/dual-segtree-2d.hpp
  - src/algebra/acted-monoid.hpp
  - src/algebra/monoid.hpp
  - src/geometry/rectangle.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/dual-segtree-2d.test.cpp
  requiredBy: []
  timestamp: '2026-11-08 19:03:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/dual-segtree-2d.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/dual-segtree-2d.test.cpp
- /verify/test/unittest/data_structures/dual-segtree-2d.test.cpp.html
title: test/unittest/data_structures/dual-segtree-2d.test.cpp
---
