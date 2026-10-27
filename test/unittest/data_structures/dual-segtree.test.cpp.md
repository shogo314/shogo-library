---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/acted-monoid.hpp
    title: "\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/beats-acted-monoid.hpp
    title: "Segment Tree Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\
      \u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/dual-segtree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\u7528\
      \u30011\u70B9\u53D6\u5F97)"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/lazy-segtree.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree-beats.hpp
    title: Segment Tree Beats
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/geometry/vector.hpp
    title: "\u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
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
  bundledCode: "#line 1 \"test/unittest/data_structures/dual-segtree.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// DualSegTree \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u53EF\u63DB\u3067\u306A\u3044\u4F5C\u7528\
    \ (\u30A2\u30D5\u30A3\u30F3\u5909\u63DB) \u3068\u3001\u533A\u9593\u306E\u9577\u3055\
    \u3092\u4F7F\u3046\u4F5C\u7528 (\u533A\u9593\u52A0\u7B97\u30FB\u533A\u9593\u548C\
    ) \u3067\u78BA\u304B\u3081\u308B\n// \u5225\u540D RAddQ / RUpdateQ / RChminQ /\
    \ RChmaxQ / RAffineQ \u3082\u78BA\u304B\u3081\u308B (\u9806\u5E8F\u3084 S(sz)\
    \ \u3092\u6301\u305F\u306A\u3044\u578B\u3067\u3082\u4F7F\u3048\u308B\u3053\u3068\
    )\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#line 2 \"src/data_structures/dual-segtree.hpp\"\n\n/**\n * @file dual-segtree.hpp\n\
    \ * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\
    \u7528\u30011\u70B9\u53D6\u5F97)\n */\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/algebra/acted-monoid.hpp\"\n\n/**\n * @file\
    \ acted-monoid.hpp\n * @brief \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9\u306E\u5B9A\u7FA9\n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
    \u30C9\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\
    \u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\
    \u3068\u3057\u3066\u8868\u3059\n * - using F: \u4F5C\u7528\u7D20\u306E\u578B\n\
    \ * - S mapping(const F& f, const S& x): \u4F5C\u7528\u7D20\u306E\u9069\u7528\
    \ f(x)\n *   \u533A\u9593\u306E\u60C5\u5831\u304C\u5FC5\u8981\u306A\u5834\u5408\
    \u306F mapping(f, x, sz) (sz \u306F\u533A\u9593\u306E\u9577\u3055) \u3084 mapping(f,\
    \ x, l, r) (\u533A\u9593 [l, r)) \u3067\u3082\u3088\u3044\n *   sz, l, r \u306F\
    \ long long \u3067\u6E21\u3059 (\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3067\u306F int \u306B\u53CE\u307E\u3089\u306A\u3044\u3053\u3068\u304C\u3042\u308B\
    )\n * - F composition(const F& f, const F& g): \u4F5C\u7528\u7D20\u306E\u5408\u6210\
    \ f\u2218g (g\u3092\u9069\u7528\u3057\u305F\u5F8C\u306Bf\u3092\u9069\u7528\u3059\
    \u308B)\n * - F id(): \u6052\u7B49\u5199\u50CF\n * \u4F5C\u7528\u7D20\u304C\u7FA4\
    \u3092\u306A\u3059\u5834\u5408 (imos.hpp \u3067\u4F7F\u3046) \u306F\n * - F inv(const\
    \ F& f): \u9006\u4F5C\u7528\u7D20\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <cstddef>\n#include <limits>\n#include <optional>\n#include <type_traits>\n\
    #line 25 \"src/algebra/acted-monoid.hpp\"\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#line 17 \"src/algebra/monoid.hpp\"\n#include <istream>\n\
    #line 19 \"src/algebra/monoid.hpp\"\n#include <numeric>\n#line 21 \"src/algebra/monoid.hpp\"\
    \n#include <ostream>\n#line 24 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\
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
    \ S>\nusing RAffineQ = DualSegTree<acted_monoid::AffineSum<S>>;\n#line 9 \"test/unittest/data_structures/dual-segtree.test.cpp\"\
    \n\n#line 11 \"test/unittest/data_structures/dual-segtree.test.cpp\"\n#include\
    \ <iostream>\n#include <random>\n#include <string>\n#line 16 \"test/unittest/data_structures/dual-segtree.test.cpp\"\
    \n\n#line 2 \"src/data_structures/lazy-segtree.hpp\"\n\n/**\n * @file lazy-segtree.hpp\n\
    \ * @brief \u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\
    \n#line 13 \"src/data_structures/lazy-segtree.hpp\"\n\n#line 15 \"src/data_structures/lazy-segtree.hpp\"\
    \n\n/**\n * @brief \u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n *\n * \u4F8B:\n * LazySegTree<acted_monoid::AffineSum<mint>> seg(v);\n *\n\
    \ * @tparam A \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\n\
    \ */\ntemplate <typename A>\nclass LazySegTree {\n   public:\n    using S = typename\
    \ A::S;\n    using F = typename A::F;\n\n   private:\n    A a;\n    S op(const\
    \ S& x, const S& y) const { return a.op(x, y); }\n    S e() const { return a.e();\
    \ }\n    S mapping(const F& f, const S& x, long long l, long long r) const { return\
    \ acted_monoid::apply_mapping(a, f, x, l, r); }\n    F composition(const F& f,\
    \ const F& g) const { return a.composition(f, g); }\n    F id() const { return\
    \ a.id(); }\n\n    long long n, sz;\n    int height;\n    std::vector<S> data;\n\
    \    std::vector<F> lazy;\n\n    void update(long long k) { data[k] = op(data[2\
    \ * k], data[2 * k + 1]); }\n    void apply_node(long long k, int h, const F&\
    \ f) {\n        // \u672B\u5C3E\u306E\u8981\u7D20\u6570\u3092 2 \u3079\u304D\u306B\
    \u305D\u308D\u3048\u308B\u305F\u3081\u306E\u4F59\u308A\u306E\u90E8\u5206\u306F\
    \u533A\u9593\u306B\u542B\u3081\u306A\u3044\n        long long l = std::min((k\
    \ << h) & (sz - 1), n);\n        long long r = std::min(((k << h) & (sz - 1))\
    \ + (1LL << h), n);\n        data[k] = mapping(f, data[k], l, r);\n        if\
    \ (k < sz) lazy[k] = composition(f, lazy[k]);\n    }\n    void push(long long\
    \ k, int h) {\n        apply_node(2 * k, h - 1, lazy[k]);\n        apply_node(2\
    \ * k + 1, h - 1, lazy[k]);\n        lazy[k] = id();\n    }\n\n    class LazySegTreeReference\
    \ {\n        LazySegTree& segtree;\n        long long k;\n\n       public:\n \
    \       LazySegTreeReference(LazySegTree& segtree, long long k) : segtree(segtree),\
    \ k(k) {}\n        LazySegTreeReference& operator=(const S& x) {\n           \
    \ segtree.set(k, x);\n            return *this;\n        }\n        operator S()\
    \ { return segtree.get(k); }\n    };\n\n    void construct_data() {\n        sz\
    \ = 1;\n        height = 0;\n        while (sz < n) {\n            sz <<= 1;\n\
    \            height++;\n        }\n        data.assign(sz * 2, e());\n       \
    \ lazy.assign(sz * 2, id());\n    }\n\n   public:\n    /**\n     * @brief \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param n \u8981\u7D20\u6570\
    \n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n   \
    \  */\n    explicit LazySegTree(long long n = 0, A a = A()) : a(std::move(a)),\
    \ n(n) {\n        construct_data();\n    }\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param v \u521D\u671F\u306E\u8981\
    \u7D20\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\
    \n     */\n    explicit LazySegTree(const std::vector<S>& v, A a = A()) : LazySegTree(v.size(),\
    \ std::move(a)) {\n        for (long long i = 0; i < n; i++) data[sz + i] = v[i];\n\
    \        for (long long i = sz - 1; i > 0; i--) update(i);\n    }\n\n    /**\n\
    \     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long long size()\
    \ const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\
    \u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n    S get(long long\
    \ k) {\n        assert(0 <= k && k < n);\n        k += sz;\n        for (int h\
    \ = height; h > 0; h--) {\n            push(k >> h, h);\n        }\n        return\
    \ data[k];\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\
    \u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\n     *\n     * @param k\n  \
    \   * @return SegTreeReference \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\u5165\
    \u3055\u308C\u308B\u3068set()\u304C\u547C\u3070\u308C\u308B\n     */\n    LazySegTreeReference\
    \ operator[](long long k) { return LazySegTreeReference(*this, k); }\n\n    /**\n\
    \     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n     *\n     * @tparam\
    \ CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n \
    \    * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\
    \u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n     * @param rhs \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n     * @return std::basic_ostream<CharT,\
    \ Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     */\n    template <class\
    \ CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, LazySegTree& rhs) {\n        for (long long i = 0; i < rhs.n; i++)\
    \ {\n            if (i != 0) os << CharT(' ');\n            os << rhs[i];\n  \
    \      }\n        return os;\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n  \
    \   *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\
    \u3057\u3044\u5024\n     */\n    void set(long long k, const S& x) {\n       \
    \ assert(0 <= k && k < n);\n        k += sz;\n        for (int h = height; h >\
    \ 0; h--) {\n            push(k >> h, h);\n        }\n        data[k] = x;\n \
    \       while (k >>= 1) update(k);\n    }\n\n    /**\n     * @brief [l, r)\u306E\
    \u533A\u9593\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\
    \u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\
    \u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(long\
    \ long l, long long r) {\n        assert(0 <= l && l <= r && r <= n);\n      \
    \  l += sz;\n        r += sz;\n        for (int h = height; h > 0; h--) {\n  \
    \          if (((l >> h) << h) != l) push(l >> h, h);\n            if (((r >>\
    \ h) << h) != r) push(r >> h, h);\n        }\n        S left_prod = e(), right_prod\
    \ = e();\n        while (l < r) {\n            if (l & 1) left_prod = op(left_prod,\
    \ data[l++]);\n            if (r & 1) right_prod = op(data[--r], right_prod);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(left_prod,\
    \ right_prod);\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @return S \u7DCF\u7A4D\n\
    \     */\n    S all_prod() const { return data[1]; }\n\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u306Bf\u3092\u4F5C\u7528\
    \u3055\u305B\u308B\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @param f \u4F5C\u7528\u7D20\n     */\n    void apply(long long k, const\
    \ F& f) {\n        assert(0 <= k && k < n);\n        k += sz;\n        for (int\
    \ h = height; h > 0; h--) {\n            push(k >> h, h);\n        }\n       \
    \ data[k] = mapping(f, data[k], k - sz, k - sz + 1);\n        while (k >>= 1)\
    \ update(k);\n    }\n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\u5024\
    \u306Bx\u3092\u4F5C\u7528\u3055\u305B\u308B\n     *\n     * @param l \u534A\u958B\
    \u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\
    \u7D42\u7AEF 0<=l<=r<=n\n     * @param f \u4F5C\u7528\u7D20\n     */\n    void\
    \ apply(long long l, long long r, const F& f) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        if (l == r) return;\n        l += sz;\n        r += sz;\n\
    \        for (int h = height; h > 0; h--) {\n            if (((l >> h) << h) !=\
    \ l) push(l >> h, h);\n            if (((r >> h) << h) != r) push(r >> h, h);\n\
    \        }\n        {\n            long long l2 = l, r2 = r;\n            int\
    \ h = 0;\n            while (l < r) {\n                if (l & 1) apply_node(l++,\
    \ h, f);\n                if (r & 1) apply_node(--r, h, f);\n                l\
    \ >>= 1;\n                r >>= 1;\n                h++;\n            }\n    \
    \        l = l2;\n            r = r2;\n        }\n        for (int h = 1; h <=\
    \ height; h++) {\n            if (((l >> h) << h) != l) update(l >> h);\n    \
    \        if (((r >> h) << h) != r) update((r - 1) >> h);\n        }\n    }\n\n\
    \    /**\n     * @brief (r = l or g(prod([l, r))) = true) and (r = n or g(prod([l,\
    \ r+1))) = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\n     * g\u304C\u5358\u8ABF\
    \u306A\u3089\u3001g(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n\
    \     *\n     * @tparam G\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\
    \u59CB 0<=l<=n\n     * @param g \u5224\u5B9A\u95A2\u6570 g(e) = true\n     * @return\
    \ long long\n     */\n    template <typename G>\n    long long max_right(long\
    \ long l, G g) {\n        assert(g(e()));\n        assert(0 <= l && l <= n);\n\
    \        if (l == n) return n;\n        l += sz;\n        for (int h = height;\
    \ h > 0; h--) {\n            push(l >> h, h);\n        }\n        int h = 0;\n\
    \        while (l % 2 == 0) {\n            l >>= 1;\n            h++;\n      \
    \  }\n        S sum = e();\n        while (g(op(sum, data[l]))) {\n          \
    \  sum = op(sum, data[l]);\n            l++;\n            while (l % 2 == 0) {\n\
    \                l >>= 1;\n                h++;\n            }\n            if\
    \ (l == 1) return n;\n        }\n        while (l < sz) {\n            push(l,\
    \ h);\n            if (!g(op(sum, data[l * 2]))) {\n                l = l * 2;\n\
    \            } else {\n                sum = op(sum, data[l * 2]);\n         \
    \       l = l * 2 + 1;\n            }\n            h--;\n        }\n        return\
    \ l - sz;\n    }\n    /**\n     * @brief (l = 0 or g(prod([l, r))) = true) and\
    \ (l = r or g(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\u8FD4\u3059\n\
    \     * g\u304C\u5358\u8ABF\u306A\u3089\u3001g(prod([l, r))) = true\u3068\u306A\
    \u308B\u6700\u5C0F\u306El\n     *\n     * @tparam G\n     * @param r \u534A\u958B\
    \u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param g \u5224\u5B9A\u95A2\u6570\
    \ g(e) = true\n     * @return long long\n     */\n    template <typename G>\n\
    \    long long min_left(long long r, G g) {\n        assert(g(e()));\n       \
    \ assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        r += sz;\n\
    \        for (int h = height; h > 0; h--) {\n            push((r - 1) >> h, h);\n\
    \        }\n        int h = 0;\n        S sum = e();\n        do {\n         \
    \   r--;\n            while (r > 1 && r % 2 == 1) {\n                r >>= 1;\n\
    \                h++;\n            }\n            if (!g(op(data[r], sum))) {\n\
    \                while (r < sz) {\n                    push(r, h);\n         \
    \           r = r * 2 + 1;\n                    h--;\n                    if (g(op(data[r],\
    \ sum))) {\n                        sum = op(data[r], sum);\n                \
    \        r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            sum = op(data[r], sum);\n        } while\
    \ ((r & -r) != r);\n        return 0;\n    }\n};\n\ntemplate <typename A>\nLazySegTree(long\
    \ long, A) -> LazySegTree<A>;\ntemplate <typename A>\nLazySegTree(std::vector<typename\
    \ A::S>, A) -> LazySegTree<A>;\n\n/**\n * @brief \u533A\u9593\u6700\u5C0F\u5024\
    \u66F4\u65B0\u3001\u533A\u9593\u6700\u5C0F\u5024\n *\n * @tparam S \u578B\n */\n\
    template <typename S>\nusing RChminMinQ = LazySegTree<acted_monoid::ChminMin<S>>;\n\
    /**\n * @brief \u533A\u9593\u6700\u5927\u5024\u66F4\u65B0\u3001\u533A\u9593\u6700\
    \u5927\u5024\n *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RChmaxMaxQ\
    \ = LazySegTree<acted_monoid::ChmaxMax<S>>;\n/**\n * @brief \u533A\u9593\u52A0\
    \u7B97\u3001\u533A\u9593\u6700\u5C0F\u5024\n *\n * @tparam S \u578B\n */\ntemplate\
    \ <typename S>\nusing RAddMinQ = LazySegTree<acted_monoid::AddMin<S>>;\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\u5024\n *\n\
    \ * @tparam S \u578B\n */\ntemplate <typename S>\nusing RAddMaxQ = LazySegTree<acted_monoid::AddMax<S>>;\n\
    /**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u548C\n *\n * @tparam\
    \ S \u578B\n */\ntemplate <typename S>\nusing RAddSumQ = LazySegTree<acted_monoid::AddSum<S>>;\n\
    /**\n * @brief \u533A\u9593\u5909\u66F4\u3001\u533A\u9593\u6700\u5C0F\u5024\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RUpdateMinQ = LazySegTree<acted_monoid::UpdateMin<S>>;\n\
    /**\n * @brief \u533A\u9593\u5909\u66F4\u3001\u533A\u9593\u6700\u5927\u5024\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RUpdateMaxQ = LazySegTree<acted_monoid::UpdateMax<S>>;\n\
    /**\n * @brief \u533A\u9593\u5909\u66F4\u3001\u533A\u9593\u548C\n *\n * @tparam\
    \ S \u578B\n */\ntemplate <typename S>\nusing RUpdateSumQ = LazySegTree<acted_monoid::UpdateSum<S>>;\n\
    #line 2 \"src/data_structures/segtree-beats.hpp\"\n\n/**\n * @file segtree-beats.hpp\n\
    \ * @brief Segment Tree Beats\n */\n\n#line 11 \"src/data_structures/segtree-beats.hpp\"\
    \n#include <tuple>\n#line 14 \"src/data_structures/segtree-beats.hpp\"\n\n#line\
    \ 2 \"src/algebra/beats-acted-monoid.hpp\"\n\n/**\n * @file beats-acted-monoid.hpp\n\
    \ * @brief Segment Tree Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/acted-monoid.hpp) \u3068\u540C\u3058\u30E1\u30F3\u30D0\u3092\u6301\u3064\
    \u304C\u3001\n * mapping \u306F std::pair<bool, S> (\u4F5C\u7528\u306B\u5931\u6557\
    \u3057\u305F\u304B, \u4F5C\u7528\u5F8C\u306E\u5024) \u3092\u8FD4\u3059\n * data_structures/segtree-beats.hpp\
    \ \u306B\u6E21\u3057\u3066\u4F7F\u3046\n */\n\n#line 15 \"src/algebra/beats-acted-monoid.hpp\"\
    \n\n#line 17 \"src/algebra/beats-acted-monoid.hpp\"\n\nnamespace beats_acted_monoid\
    \ {\n\n/**\n * @brief \u533A\u9593 chmin\u3001\u533A\u9593\u548C\u30FB\u6700\u5927\
    \u5024\n *\n * \u4F5C\u7528\u7D20\u306F chmin \u3059\u308B\u5024 (x <- min(x,\
    \ f))\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u304B\u3089\u4F5C\u308A\u3001\
    sum, max1 \u3067\u533A\u9593\u548C\u30FB\u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\
    \u308B\n * \u7A7A\u306E\u533A\u9593\u3067\u306F max1 = numeric_limits<T>::lowest()\n\
    \ * ChminChmaxAddSum \u3088\u308A\u8EFD\u3044\n *\n * @tparam T \u5024\u306E\u578B\
    \n */\ntemplate <typename T>\nstruct ChminSum {\n    static constexpr T lowest\
    \ = std::numeric_limits<T>::lowest();\n\n    struct S {\n        T sum;\n    \
    \    T max1, max2;       // \u6700\u5927\u5024\u30012\u756A\u76EE\u306E\u6700\u5927\
    \u5024 (\u306A\u3051\u308C\u3070 lowest)\n        long long max_cnt;  // \u6700\
    \u5927\u5024\u306E\u500B\u6570\n        constexpr S() : sum(0), max1(lowest),\
    \ max2(lowest), max_cnt(0) {}\n        constexpr S(const T& x) : sum(x), max1(x),\
    \ max2(lowest), max_cnt(1) {}\n    };\n    using F = T;\n\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        S res;\n        res.sum = a.sum + b.sum;\n\
    \        if (a.max1 == b.max1) {\n            res.max1 = a.max1;\n           \
    \ res.max_cnt = a.max_cnt + b.max_cnt;\n            res.max2 = std::max(a.max2,\
    \ b.max2);\n        } else if (a.max1 > b.max1) {\n            res.max1 = a.max1;\n\
    \            res.max_cnt = a.max_cnt;\n            res.max2 = std::max(a.max2,\
    \ b.max1);\n        } else {\n            res.max1 = b.max1;\n            res.max_cnt\
    \ = b.max_cnt;\n            res.max2 = std::max(a.max1, b.max2);\n        }\n\
    \        return res;\n    }\n    static constexpr S e() { return S(); }\n    static\
    \ constexpr std::pair<bool, S> mapping(const F& f, const S& x) {\n        if (x.max1\
    \ <= f) return {false, x};\n        // \u6700\u5927\u5024\u3060\u3051\u304C\u5909\
    \u308F\u308B (\u5024\u304C 1 \u7A2E\u985E\u306A\u3089 f = lowest \u3067\u3082\u6210\
    \u529F\u3055\u305B\u308B)\n        if (x.max2 < f || x.max2 == lowest) {\n   \
    \         S res = x;\n            res.sum -= (x.max1 - f) * T(x.max_cnt);\n  \
    \          res.max1 = f;\n            return {false, res};\n        }\n      \
    \  return {true, x};\n    }\n    static constexpr F composition(const F& f, const\
    \ F& g) { return std::min(f, g); }\n    static constexpr F id() { return std::numeric_limits<T>::max();\
    \ }\n};\n\n/**\n * @brief \u533A\u9593 chmax\u3001\u533A\u9593\u548C\u30FB\u6700\
    \u5C0F\u5024\n *\n * \u4F5C\u7528\u7D20\u306F chmax \u3059\u308B\u5024 (x <- max(x,\
    \ f))\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u304B\u3089\u4F5C\u308A\u3001\
    sum, min1 \u3067\u533A\u9593\u548C\u30FB\u6700\u5C0F\u5024\u3092\u53D6\u5F97\u3059\
    \u308B\n * \u7A7A\u306E\u533A\u9593\u3067\u306F min1 = numeric_limits<T>::max()\n\
    \ * ChminChmaxAddSum \u3088\u308A\u8EFD\u3044\n *\n * @tparam T \u5024\u306E\u578B\
    \n */\ntemplate <typename T>\nstruct ChmaxSum {\n    static constexpr T highest\
    \ = std::numeric_limits<T>::max();\n\n    struct S {\n        T sum;\n       \
    \ T min1, min2;       // \u6700\u5C0F\u5024\u30012\u756A\u76EE\u306E\u6700\u5C0F\
    \u5024 (\u306A\u3051\u308C\u3070 highest)\n        long long min_cnt;  // \u6700\
    \u5C0F\u5024\u306E\u500B\u6570\n        constexpr S() : sum(0), min1(highest),\
    \ min2(highest), min_cnt(0) {}\n        constexpr S(const T& x) : sum(x), min1(x),\
    \ min2(highest), min_cnt(1) {}\n    };\n    using F = T;\n\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        S res;\n        res.sum = a.sum + b.sum;\n\
    \        if (a.min1 == b.min1) {\n            res.min1 = a.min1;\n           \
    \ res.min_cnt = a.min_cnt + b.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min2);\n        } else if (a.min1 < b.min1) {\n            res.min1 = a.min1;\n\
    \            res.min_cnt = a.min_cnt;\n            res.min2 = std::min(a.min2,\
    \ b.min1);\n        } else {\n            res.min1 = b.min1;\n            res.min_cnt\
    \ = b.min_cnt;\n            res.min2 = std::min(a.min1, b.min2);\n        }\n\
    \        return res;\n    }\n    static constexpr S e() { return S(); }\n    static\
    \ constexpr std::pair<bool, S> mapping(const F& f, const S& x) {\n        if (x.min1\
    \ >= f) return {false, x};\n        // \u6700\u5C0F\u5024\u3060\u3051\u304C\u5909\
    \u308F\u308B (\u5024\u304C 1 \u7A2E\u985E\u306A\u3089 f = highest \u3067\u3082\
    \u6210\u529F\u3055\u305B\u308B)\n        if (x.min2 > f || x.min2 == highest)\
    \ {\n            S res = x;\n            res.sum += (f - x.min1) * T(x.min_cnt);\n\
    \            res.min1 = f;\n            return {false, res};\n        }\n    \
    \    return {true, x};\n    }\n    static constexpr F composition(const F& f,\
    \ const F& g) { return std::max(f, g); }\n    static constexpr F id() { return\
    \ std::numeric_limits<T>::lowest(); }\n};\n\n/**\n * @brief \u533A\u9593 chmin\u30FB\
    chmax\u30FB\u52A0\u7B97\u30FB\u4EE3\u5165\u3001\u533A\u9593\u548C\u30FB\u6700\u5927\
    \u5024\u30FB\u6700\u5C0F\u5024\n *\n * \u4F5C\u7528\u7D20 F = ClampAdd<T>{lb,\
    \ ub, add} \u306F x <- clamp(x + add, lb, ub) \u3092\u8868\u3059 (lb <= ub)\n\
    \ * chmin(b), chmax(b), add(b), update(b) \u3067\u4F5C\u308B\n * S(x) \u3067\u5024\
    \ x \u306E1\u8981\u7D20\u304B\u3089\u4F5C\u308A\u3001sum, max1, min1 \u3067\u533A\
    \u9593\u548C\u30FB\u6700\u5927\u5024\u30FB\u6700\u5C0F\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\n * \u7A7A\u306E\u533A\u9593\u3067\u306F max1 = numeric_limits<T>::lowest(),\
    \ min1 = numeric_limits<T>::max()\n *\n * @tparam T \u5024\u306E\u578B (\u7B26\
    \u53F7\u4ED8\u304D\u6574\u6570\u3092\u60F3\u5B9A\u3059\u308B)\n */\ntemplate <typename\
    \ T>\nstruct ChminChmaxAddSum {\n    static constexpr T lowest = std::numeric_limits<T>::lowest();\n\
    \    static constexpr T highest = std::numeric_limits<T>::max();\n\n    struct\
    \ S {\n        T sum;\n        T max1, max2;                // \u6700\u5927\u5024\
    \u30012\u756A\u76EE\u306E\u6700\u5927\u5024 (\u306A\u3051\u308C\u3070 lowest)\n\
    \        T min1, min2;                // \u6700\u5C0F\u5024\u30012\u756A\u76EE\
    \u306E\u6700\u5C0F\u5024 (\u306A\u3051\u308C\u3070 highest)\n        long long\
    \ max_cnt, min_cnt;  // \u6700\u5927\u5024\u30FB\u6700\u5C0F\u5024\u306E\u500B\
    \u6570\n        constexpr S() : sum(0), max1(lowest), max2(lowest), min1(highest),\
    \ min2(highest), max_cnt(0), min_cnt(0) {}\n        constexpr S(const T& x) :\
    \ sum(x), max1(x), max2(lowest), min1(x), min2(highest), max_cnt(1), min_cnt(1)\
    \ {}\n    };\n    using F = ClampAdd<T>;\n\n    static constexpr F chmin(const\
    \ T& b) { return {lowest, b, T(0)}; }\n    static constexpr F chmax(const T& b)\
    \ { return {b, highest, T(0)}; }\n    static constexpr F add(const T& b) { return\
    \ {lowest, highest, b}; }\n    static constexpr F update(const T& b) { return\
    \ {b, b, T(0)}; }\n\n    static constexpr S op(const S& a, const S& b) {\n   \
    \     S res;\n        res.sum = a.sum + b.sum;\n        if (a.max1 == b.max1)\
    \ {\n            res.max1 = a.max1;\n            res.max_cnt = a.max_cnt + b.max_cnt;\n\
    \            res.max2 = std::max(a.max2, b.max2);\n        } else if (a.max1 >\
    \ b.max1) {\n            res.max1 = a.max1;\n            res.max_cnt = a.max_cnt;\n\
    \            res.max2 = std::max(a.max2, b.max1);\n        } else {\n        \
    \    res.max1 = b.max1;\n            res.max_cnt = b.max_cnt;\n            res.max2\
    \ = std::max(a.max1, b.max2);\n        }\n        if (a.min1 == b.min1) {\n  \
    \          res.min1 = a.min1;\n            res.min_cnt = a.min_cnt + b.min_cnt;\n\
    \            res.min2 = std::min(a.min2, b.min2);\n        } else if (a.min1 <\
    \ b.min1) {\n            res.min1 = a.min1;\n            res.min_cnt = a.min_cnt;\n\
    \            res.min2 = std::min(a.min2, b.min1);\n        } else {\n        \
    \    res.min1 = b.min1;\n            res.min_cnt = b.min_cnt;\n            res.min2\
    \ = std::min(a.min1, b.min2);\n        }\n        return res;\n    }\n    static\
    \ constexpr S e() { return S(); }\n    static constexpr std::pair<bool, S> mapping(const\
    \ F& f, const S& x, long long sz) {\n        if (x.max_cnt == 0) return {false,\
    \ x};\n        S res = x;\n        // \u52A0\u7B97 (\u756A\u5175\u306B\u306F\u8DB3\
    \u3055\u306A\u3044)\n        res.sum += f.add * T(sz);\n        res.max1 += f.add;\n\
    \        res.min1 += f.add;\n        if (res.max2 != lowest) res.max2 += f.add;\n\
    \        if (res.min2 != highest) res.min2 += f.add;\n        // \u5024\u304C\
    \ 1 \u7A2E\u985E\n        if (res.max1 == res.min1) {\n            T v = std::clamp(res.max1,\
    \ f.lb, f.ub);\n            res.max1 = res.min1 = v;\n            res.sum = v\
    \ * T(sz);\n            return {false, res};\n        }\n        // \u5024\u304C\
    \ 2 \u7A2E\u985E\n        if (res.max1 == res.min2) {\n            T hi = std::clamp(res.max1,\
    \ f.lb, f.ub), lo = std::clamp(res.min1, f.lb, f.ub);\n            if (hi == lo)\
    \ {\n                res.max1 = res.min1 = hi;\n                res.max2 = lowest;\n\
    \                res.min2 = highest;\n                res.max_cnt = res.min_cnt\
    \ = sz;\n                res.sum = hi * T(sz);\n            } else {\n       \
    \         res.max1 = res.min2 = hi;\n                res.min1 = res.max2 = lo;\n\
    \                res.sum = hi * T(res.max_cnt) + lo * T(res.min_cnt);\n      \
    \      }\n            return {false, res};\n        }\n        // \u5024\u304C\
    \ 3 \u7A2E\u985E\u4EE5\u4E0A: \u6700\u5927\u5024\u3068\u6700\u5C0F\u5024\u3060\
    \u3051\u304C\u5909\u308F\u308B\u5834\u5408\u4EE5\u5916\u306F\u5931\u6557\n   \
    \     if (f.ub <= res.max2 || f.lb >= res.min2) return {true, res};\n        if\
    \ (f.ub < res.max1) {\n            res.sum -= (res.max1 - f.ub) * T(res.max_cnt);\n\
    \            res.max1 = f.ub;\n        }\n        if (f.lb > res.min1) {\n   \
    \         res.sum += (f.lb - res.min1) * T(res.min_cnt);\n            res.min1\
    \ = f.lb;\n        }\n        return {false, res};\n    }\n    // g \u3092\u9069\
    \u7528\u3057\u305F\u5F8C\u306B f \u3092\u9069\u7528\u3059\u308B\n    static constexpr\
    \ F composition(const F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f,\
    \ g); }\n    static constexpr F id() { return {lowest, highest, T(0)}; }\n};\n\
    \n}  // namespace beats_acted_monoid\n#line 17 \"src/data_structures/segtree-beats.hpp\"\
    \n\n/**\n * @brief Segment Tree Beats\n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp) \u3068\u540C\u3058\u5F62\u306E\u578B\
    \u3092\u53D7\u3051\u53D6\u308B\u304C\u3001\n * mapping \u306F std::pair<bool,\
    \ S> (\u4F5C\u7528\u306B\u5931\u6557\u3057\u305F\u304B, \u4F5C\u7528\u5F8C\u306E\
    \u5024) \u3092\u8FD4\u3059\n * \u5931\u6557\u3057\u305F\u5834\u5408\u306F\u5B50\
    \u306B\u4F1D\u642C\u3057\u3066\u304B\u3089\u8A08\u7B97\u3057\u76F4\u3059\n *\n\
    \ * @tparam A \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n */\ntemplate\
    \ <typename A>\nclass SegTreeBeats {\n   public:\n    using S = typename A::S;\n\
    \    using F = typename A::F;\n\n   private:\n    A a;\n    S op(const S& x, const\
    \ S& y) const { return a.op(x, y); }\n    S e() const { return a.e(); }\n    std::pair<bool,\
    \ S> mapping(const F& f, const S& x, long long l, long long r) const { return\
    \ acted_monoid::apply_mapping(a, f, x, l, r); }\n    F composition(const F& f,\
    \ const F& g) const { return a.composition(f, g); }\n    F id() const { return\
    \ a.id(); }\n\n    long long n, sz;\n    int height;\n    std::vector<S> data;\n\
    \    std::vector<int> fail;\n    std::vector<F> lazy;\n\n    void update(long\
    \ long k) {\n        data[k] = op(data[2 * k], data[2 * k + 1]);\n        fail[k]\
    \ = false;\n    }\n    void apply_node(long long k, int h, const F& f) {\n   \
    \     // \u672B\u5C3E\u306E\u8981\u7D20\u6570\u3092 2 \u3079\u304D\u306B\u305D\
    \u308D\u3048\u308B\u305F\u3081\u306E\u4F59\u308A\u306E\u90E8\u5206\u306F\u533A\
    \u9593\u306B\u542B\u3081\u306A\u3044\n        long long l = std::min((k << h)\
    \ & (sz - 1), n);\n        long long r = std::min(((k << h) & (sz - 1)) + (1LL\
    \ << h), n);\n        std::tie(fail[k], data[k]) = mapping(f, data[k], l, r);\n\
    \        if (k < sz) {\n            lazy[k] = composition(f, lazy[k]);\n     \
    \       if (fail[k]) {\n                push(k, h);\n                update(k);\n\
    \            }\n        }\n    }\n    void push(long long k, int h) {\n      \
    \  apply_node(2 * k, h - 1, lazy[k]);\n        apply_node(2 * k + 1, h - 1, lazy[k]);\n\
    \        lazy[k] = id();\n    }\n\n    class SegTreeBeatsReference {\n       \
    \ SegTreeBeats& segtree;\n        long long k;\n\n       public:\n        SegTreeBeatsReference(SegTreeBeats&\
    \ segtree, long long k) : segtree(segtree), k(k) {}\n        SegTreeBeatsReference&\
    \ operator=(const S& x) {\n            segtree.set(k, x);\n            return\
    \ *this;\n        }\n        operator S() { return segtree.get(k); }\n    };\n\
    \n    void construct_data() {\n        sz = 1;\n        height = 0;\n        while\
    \ (sz < n) {\n            sz <<= 1;\n            height++;\n        }\n      \
    \  data.assign(sz * 2, e());\n        fail.assign(sz * 2, false);\n        lazy.assign(sz\
    \ * 2, id());\n    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     *\n     * @param n \u8981\u7D20\u6570\n     * @param\
    \ a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ SegTreeBeats(long long n = 0, A a = A()) : a(std::move(a)), n(n) {\n       \
    \ construct_data();\n    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param\
    \ a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ SegTreeBeats(const std::vector<S>& v, A a = A()) : SegTreeBeats(v.size(), std::move(a))\
    \ {\n        for (long long i = 0; i < n; i++) data[sz + i] = v[i];\n        for\
    \ (long long i = sz - 1; i > 0; i--) update(i);\n    }\n\n    /**\n     * @brief\
    \ \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long long size() const {\
    \ return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\
    \u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\n     * @return S \u5024\n     */\n    S get(long long k) {\n   \
    \     assert(0 <= k && k < n);\n        k += sz;\n        for (int h = height;\
    \ h > 0; h--) {\n            push(k >> h, h);\n        }\n        return data[k];\n\
    \    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u3078\
    \u306E\u53C2\u7167\u3092\u8FD4\u3059\n     *\n     * @param k\n     * @return\
    \ SegTreeReference \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\u5165\u3055\u308C\
    \u308B\u3068set()\u304C\u547C\u3070\u308C\u308B\n     */\n    SegTreeBeatsReference\
    \ operator[](long long k) { return SegTreeBeatsReference(*this, k); }\n\n    /**\n\
    \     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n     *\n     * @tparam\
    \ CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n \
    \    * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\
    \u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n     * @param rhs \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n     * @return std::basic_ostream<CharT,\
    \ Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     */\n    template <class\
    \ CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, SegTreeBeats& rhs) {\n        for (long long i = 0; i < rhs.n;\
    \ i++) {\n            if (i != 0) os << CharT(' ');\n            os << rhs[i];\n\
    \        }\n        return os;\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n  \
    \   *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\
    \u3057\u3044\u5024\n     */\n    void set(long long k, const S& x) {\n       \
    \ assert(0 <= k && k < n);\n        k += sz;\n        for (int h = height; h >\
    \ 0; h--) {\n            push(k >> h, h);\n        }\n        data[k] = x;\n \
    \       while (k >>= 1) update(k);\n    }\n\n    /**\n     * @brief [l, r)\u306E\
    \u533A\u9593\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\
    \u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\
    \u306E\u7D42\u7AEF\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(long long\
    \ l, long long r) {\n        assert(0 <= l && l <= r && r <= n);\n        l +=\
    \ sz;\n        r += sz;\n        for (int h = height; h > 0; h--) {\n        \
    \    if (((l >> h) << h) != l) push(l >> h, h);\n            if (((r >> h) <<\
    \ h) != r) push(r >> h, h);\n        }\n        S left_prod = e(), right_prod\
    \ = e();\n        while (l < r) {\n            if (l & 1) left_prod = op(left_prod,\
    \ data[l++]);\n            if (r & 1) right_prod = op(data[--r], right_prod);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(left_prod,\
    \ right_prod);\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @return S \u7DCF\u7A4D\n\
    \     */\n    S all_prod() const { return data[1]; }\n\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u306Bx\u3092\u4F5C\u7528\
    \u3055\u305B\u308B\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @param x \u4F5C\u7528\u7D20\n     */\n    void apply(long long k, const\
    \ F& f) {\n        assert(0 <= k && k < n);\n        k += sz;\n        for (int\
    \ h = height; h > 0; h--) {\n            push(k >> h, h);\n        }\n       \
    \ data[k] = mapping(f, data[k], k - sz, k - sz + 1).second;\n        while (k\
    \ >>= 1) update(k);\n    }\n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\
    \u5024\u306Bx\u3092\u4F5C\u7528\u3055\u305B\u308B\n     *\n     * @param l \u534A\
    \u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\
    \u306E\u7D42\u7AEF\n     * @param f \u4F5C\u7528\u7D20\n     */\n    void apply(long\
    \ long l, long long r, const F& f) {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        if (l == r) return;\n        l += sz;\n        r += sz;\n     \
    \   for (int h = height; h > 0; h--) {\n            if (((l >> h) << h) != l)\
    \ push(l >> h, h);\n            if (((r >> h) << h) != r) push(r >> h, h);\n \
    \       }\n        {\n            long long l2 = l, r2 = r;\n            int h\
    \ = 0;\n            while (l < r) {\n                if (l & 1) apply_node(l++,\
    \ h, f);\n                if (r & 1) apply_node(--r, h, f);\n                l\
    \ >>= 1;\n                r >>= 1;\n                h++;\n            }\n    \
    \        l = l2;\n            r = r2;\n        }\n        for (int h = 1; h <=\
    \ height; h++) {\n            if (((l >> h) << h) != l) update(l >> h);\n    \
    \        if (((r >> h) << h) != r) update((r - 1) >> h);\n        }\n    }\n\n\
    \    /**\n     * @brief (r = l or g(prod([l, r))) = true) and (r = n or g(prod([l,\
    \ r+1))) = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\n     * g\u304C\u5358\u8ABF\
    \u306A\u3089\u3001g(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n\
    \     *\n     * @tparam G\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\
    \u59CB\n     * @param g \u5224\u5B9A\u95A2\u6570 g(e) = true\n     * @return long\
    \ long\n     */\n    template <typename G>\n    long long max_right(long long\
    \ l, G g) {\n        assert(g(e()));\n        assert(0 <= l && l <= n);\n    \
    \    if (l == n) return n;\n        l += sz;\n        for (int h = height; h >\
    \ 0; h--) {\n            push(l >> h, h);\n        }\n        int h = 0;\n   \
    \     while (l % 2 == 0) {\n            l >>= 1;\n            h++;\n        }\n\
    \        S sum = e();\n        while (g(op(sum, data[l]))) {\n            sum\
    \ = op(sum, data[l]);\n            l++;\n            while (l % 2 == 0) {\n  \
    \              l >>= 1;\n                h++;\n            }\n            if (l\
    \ == 1) return n;\n        }\n        while (l < sz) {\n            push(l, h);\n\
    \            if (!g(op(sum, data[l * 2]))) {\n                l = l * 2;\n   \
    \         } else {\n                sum = op(sum, data[l * 2]);\n            \
    \    l = l * 2 + 1;\n            }\n            h--;\n        }\n        return\
    \ l - sz;\n    }\n    /**\n     * @brief (l = 0 or g(prod([l, r))) = true) and\
    \ (l = r or g(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\u8FD4\u3059\n\
    \     * g\u304C\u5358\u8ABF\u306A\u3089\u3001g(prod([l, r))) = true\u3068\u306A\
    \u308B\u6700\u5C0F\u306El\n     *\n     * @tparam G\n     * @param r \u534A\u958B\
    \u533A\u9593\u306E\u7D42\u7AEF\n     * @param g \u5224\u5B9A\u95A2\u6570 g(e)\
    \ = true\n     * @return long long\n     */\n    template <typename G>\n    long\
    \ long min_left(long long r, G g) {\n        assert(g(e()));\n        assert(0\
    \ <= r && r <= n);\n        if (r == 0) return 0;\n        r += sz;\n        for\
    \ (int h = height; h > 0; h--) {\n            push((r - 1) >> h, h);\n       \
    \ }\n        int h = 0;\n        S sum = e();\n        do {\n            r--;\n\
    \            while (r > 1 && r % 2 == 1) {\n                r >>= 1;\n       \
    \         h++;\n            }\n            if (!g(op(data[r], sum))) {\n     \
    \           while (r < sz) {\n                    push(r, h);\n              \
    \      r = r * 2 + 1;\n                    h--;\n                    if (g(op(data[r],\
    \ sum))) {\n                        sum = op(data[r], sum);\n                \
    \        r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            sum = op(data[r], sum);\n        } while\
    \ ((r & -r) != r);\n        return 0;\n    }\n};\n\ntemplate <typename A>\nSegTreeBeats(long\
    \ long, A) -> SegTreeBeats<A>;\ntemplate <typename A>\nSegTreeBeats(std::vector<typename\
    \ A::S>, A) -> SegTreeBeats<A>;\n\n/**\n * @brief \u533A\u9593 chmin\u3001\u533A\
    \u9593\u548C\u30FB\u6700\u5927\u5024\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RChminSumQ = SegTreeBeats<beats_acted_monoid::ChminSum<S>>;\n/**\n\
    \ * @brief \u533A\u9593 chmax\u3001\u533A\u9593\u548C\u30FB\u6700\u5C0F\u5024\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RChmaxSumQ = SegTreeBeats<beats_acted_monoid::ChmaxSum<S>>;\n\
    /**\n * @brief \u533A\u9593 chmin\u30FBchmax\u30FB\u52A0\u7B97\u30FB\u4EE3\u5165\
    \u3001\u533A\u9593\u548C\u30FB\u6700\u5927\u5024\u30FB\u6700\u5C0F\u5024\n *\n\
    \ * @tparam S \u578B\n */\ntemplate <typename S>\nusing RChminChmaxAddSumQ = SegTreeBeats<beats_acted_monoid::ChminChmaxAddSum<S>>;\n\
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
    \ S>\nusing RGcdQ = SegTree<monoid::Gcd<S>>;\n#line 2 \"src/geometry/vector.hpp\"\
    \n\n/**\n * @file vector.hpp\n * @brief \u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB\n\
    \ */\n\n#line 11 \"src/geometry/vector.hpp\"\n#include <cmath>\n#line 17 \"src/geometry/vector.hpp\"\
    \n#include <stack>\n#line 21 \"src/geometry/vector.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"\
    src/utility/traits.hpp\"\n#include <iterator>\n#include <set>\n#line 13 \"src/utility/traits.hpp\"\
    \n\nnamespace internal_traits {\nusing std::begin, std::end;\n\ntemplate <class\
    \ T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate <class\
    \ T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n\n/**\n * @brief \u7DDA\u5206\u306E\u4EA4\
    \u5DEE\u5224\u5B9A\n *\n * \u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B\u3002\
    \u5916\u7A4D\u3092\u8A08\u7B97\u3059\u308B\u305F\u3081\u3001\u5EA7\u6A19\u306E\
    \u7D76\u5BFE\u5024\u306E2\u4E57\u306E\u6570\u500D\u304CT\u306B\u53CE\u307E\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n *\n * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\
    \u306E\u7AEF\u70B91\n * @param p2 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B9\
    2\n * @param q1 2\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param\
    \ q2 2\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\
    \u306E\u578B\n * @return bool \u5171\u6709\u70B9\u3092\u6301\u3064\u304B\n */\n\
    template <typename T>\nconstexpr bool segments_intersect(const Vector<T, 2>& p1,\
    \ const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n\
    \    assert(p1 != p2 && q1 != q2 && \"segments_intersect: degenerate segment\"\
    );\n    auto sign = [](T x) { return (x > 0) - (x < 0); };\n    int q1_section\
    \ = sign(cross(p2 - p1, q1 - p1));  // \u76F4\u7DDAp1p2\u306B\u5BFE\u3057\u3066\
    q1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    int q2_section =\
    \ sign(cross(p2 - p1, q2 - p1));  // \u76F4\u7DDAp1p2\u306B\u5BFE\u3057\u3066\
    q2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    int p1_section =\
    \ sign(cross(q2 - q1, p1 - q1));  // \u76F4\u7DDAq1q2\u306B\u5BFE\u3057\u3066\
    p1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    int p2_section =\
    \ sign(cross(q2 - q1, p2 - q1));  // \u76F4\u7DDAq1q2\u306B\u5BFE\u3057\u3066\
    p2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    if (q1_section ==\
    \ 0 && q2_section == 0) {\n        // 4\u70B9\u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \u306B\u3042\u308B\u5834\u5408\n        return dot(q1 - p1, q2 - p1) <= 0 || dot(q1\
    \ - p2, q2 - p2) <= 0 || dot(p1 - q1, p2 - q1) <= 0;\n    }\n    return q1_section\
    \ * q2_section <= 0 && p1_section * p2_section <= 0;\n}\n\n/**\n * @brief \u7DDA\
    \u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\u3068\u5171\u6709\u70B9\u306E\u8A08\u7B97\
    \n *\n * \u5171\u6709\u70B9\u306E\u5EA7\u6A19\u306F\u4E00\u822C\u306B\u6574\u6570\
    \u306B\u306A\u3089\u306A\u3044\u305F\u3081\u3001\u6D6E\u52D5\u5C0F\u6570\u70B9\
    \u578B\u9650\u5B9A\n * \u6574\u6570\u5EA7\u6A19\u3067\u4EA4\u5DEE\u5224\u5B9A\u3060\
    \u3051\u3057\u305F\u3044\u5834\u5408\u306F segments_intersect \u3092\u4F7F\u3046\
    \n *\n * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param\
    \ p2 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @param q1 2\u672C\u76EE\
    \u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param q2 2\u672C\u76EE\u306E\u7DDA\u5206\
    \u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return std::optional<Vector<T,\
    \ 2>> \u5171\u6709\u70B9\u306E1\u4F8B (\u5171\u6709\u70B9\u304C\u306A\u3051\u308C\
    \u3070 std::nullopt)\n */\ntemplate <typename T>\nconstexpr std::optional<Vector<T,\
    \ 2>> segment_intersection(const Vector<T, 2>& p1, const Vector<T, 2>& p2, const\
    \ Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    static_assert(std::is_floating_point_v<T>,\
    \ \"segment_intersection: T must be a floating point type (use segments_intersect\
    \ for integers)\");\n    if (!segments_intersect(p1, p2, q1, q2)) return std::nullopt;\n\
    \    if (cross(p2 - p1, q1 - p1) == 0 && cross(p2 - p1, q2 - p1) == 0) {\n   \
    \     // 4\u70B9\u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\
    \n        if (dot(q1 - p1, q2 - p1) <= 0) return p1;\n        if (dot(q1 - p2,\
    \ q2 - p2) <= 0) return p2;\n        return q1;\n    }\n    T area = cross(p2\
    \ - p1, q2 - q1);          // 4\u70B9\u3092\u9802\u70B9\u3068\u3059\u308B\u56DB\
    \u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\n    T partial_area = cross(q2\
    \ - q1, p1 - q1);  // \u4E09\u89D2\u5F62q1q2p1\u306E\u7B26\u53F7\u4ED8\u304D\u9762\
    \u7A4D\n    return p1 + (p2 - p1) * partial_area / area;\n}\n\n/**\n * @brief\
    \ 3\u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2 (counter-clockwise)\n *\n * \u6574\u6570\
    \u578B\u3067\u3082\u4F7F\u3048\u308B\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\
    \u3067\u306F\u8AA4\u5DEE\u3092\u8003\u3048\u305A\u306B\u6BD4\u8F03\u3059\u308B\
    \n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return int 1: a\u2192b\u2192\
    c \u304C\u53CD\u6642\u8A08\u56DE\u308A, -1: \u6642\u8A08\u56DE\u308A, 2: c, a,\
    \ b \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A, -2: a, b, c \u306E\u9806\u306B\
    \u4E00\u76F4\u7DDA\u4E0A, 0: c \u304C\u7DDA\u5206 ab \u4E0A\n */\ntemplate <typename\
    \ T>\nconstexpr int ccw(const Vector<T, 2>& a, const Vector<T, 2>& b, const Vector<T,\
    \ 2>& c) {\n    Vector<T, 2> u = b - a, v = c - a;\n    T cr = cross(u, v);\n\
    \    if (cr > 0) return 1;\n    if (cr < 0) return -1;\n    if (dot(u, v) < 0)\
    \ return 2;\n    if (u.squared_norm() < v.squared_norm()) return -2;\n    return\
    \ 0;\n}\n\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u304C\u5E73\
    \u884C\u304B (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate\
    \ <typename T>\nconstexpr bool is_parallel(const Vector<T, 2>& p1, const Vector<T,\
    \ 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    return cross(p2\
    \ - p1, q2 - q1) == 0;\n}\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA\
    \ q1q2 \u304C\u76F4\u4EA4\u3059\u308B\u304B (\u6574\u6570\u578B\u3067\u3082\u4F7F\
    \u3048\u308B)\n */\ntemplate <typename T>\nconstexpr bool is_orthogonal(const\
    \ Vector<T, 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T,\
    \ 2>& q2) {\n    return dot(p2 - p1, q2 - q1) == 0;\n}\n\n/**\n * @brief \u70B9\
    \ p \u304B\u3089\u76F4\u7DDA p1p2 \u306B\u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\
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
    \u70B9\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\u3002p1 != p2 \u304B\
    \u3064 q1 != q2 \u3067\u3042\u308B\u3053\u3068\n * @return std::optional<Vector<T,\
    \ 2>> \u4EA4\u70B9 (\u5E73\u884C (\u91CD\u306A\u308B\u76F4\u7DDA\u3082\u542B\u3080\
    ) \u306A\u3089 std::nullopt)\n */\ntemplate <typename T>\nconstexpr std::optional<Vector<T,\
    \ 2>> line_intersection(const Vector<T, 2>& p1, const Vector<T, 2>& p2, const\
    \ Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    static_assert(std::is_floating_point_v<T>,\
    \ \"line_intersection: T must be a floating point type\");\n    assert(p1 != p2\
    \ && q1 != q2 && \"line_intersection: degenerate line\");\n    Vector<T, 2> d\
    \ = p2 - p1, e = q2 - q1;\n    T c = cross(e, d);\n    if (c == 0) return std::nullopt;\n\
    \    // p1 + d t \u304C\u76F4\u7DDA q1q2 \u4E0A\u306B\u3042\u308B t\n    return\
    \ p1 + d * (cross(e, q1 - p1) / c);\n}\n\n/**\n * @brief \u70B9 p \u3068\u76F4\
    \u7DDA p1p2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B\
    )\n */\ntemplate <typename T>\ndouble distance_point_line(const Vector<T, 2>&\
    \ p1, const Vector<T, 2>& p2, const Vector<T, 2>& p) {\n    assert(p1 != p2 &&\
    \ \"distance_point_line: degenerate line\");\n    return std::abs(static_cast<double>(cross(p2\
    \ - p1, p - p1))) / (p2 - p1).abs();\n}\n/**\n * @brief \u70B9 p \u3068\u7DDA\u5206\
    \ p1p2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n\
    \ */\ntemplate <typename T>\ndouble distance_point_segment(const Vector<T, 2>&\
    \ p1, const Vector<T, 2>& p2, const Vector<T, 2>& p) {\n    if (p1 == p2) return\
    \ (p - p1).abs();\n    // \u5782\u7DDA\u306E\u8DB3\u304C\u7DDA\u5206\u306E\u5916\
    \u306A\u3089\u3001\u8FD1\u3044\u65B9\u306E\u7AEF\u70B9\u3068\u306E\u8DDD\u96E2\
    \n    if (dot(p2 - p1, p - p1) < 0) return (p - p1).abs();\n    if (dot(p1 - p2,\
    \ p - p2) < 0) return (p - p2).abs();\n    return distance_point_line(p1, p2,\
    \ p);\n}\n/**\n * @brief \u7DDA\u5206 p1p2 \u3068\u7DDA\u5206 q1q2 \u306E\u8DDD\
    \u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_segments(const Vector<T, 2>& p1, const Vector<T, 2>& p2,\
    \ const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    if (p1 != p2 && q1 !=\
    \ q2 && segments_intersect(p1, p2, q1, q2)) return 0;\n    return std::min({distance_point_segment(p1,\
    \ p2, q1), distance_point_segment(p1, p2, q2),\n                     distance_point_segment(q1,\
    \ q2, p1), distance_point_segment(q1, q2, p2)});\n}\n\n/**\n * @brief \u591A\u89D2\
    \u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\u306E2\u500D\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19\
    \n * @return T \u9762\u7A4D\u306E2\u500D(\u53CD\u6642\u8A08\u56DE\u308A\u306A\u3089\
    \u6B63\u3001\u6642\u8A08\u56DE\u308A\u306A\u3089\u8CA0)\n */\ntemplate <typename\
    \ T>\nT polygon_area_doubled(const std::vector<Vector<T, 2>>& polygon) {\n   \
    \ T ret = 0;\n    for (int i = 0; i < static_cast<int>(polygon.size()); i++) {\n\
    \        int j = i + 1;\n        if (j == static_cast<int>(polygon.size())) j\
    \ = 0;\n        ret += cross(polygon[i], polygon[j]);\n    }\n    return ret;\n\
    }\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u9762\u7A4D\n *\n * @tparam T \u5EA7\
    \u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19(\u9806\u756A\
    \u3001\u53CD\u6642\u8A08\u56DE\u308A\u304B\u6642\u8A08\u56DE\u308A\u304B\u306F\
    \u554F\u308F\u306A\u3044)\n * @return double \u9762\u7A4D\n */\ntemplate <typename\
    \ T>\ndouble polygon_area(const std::vector<Vector<T, 2>>& polygon) {\n    return\
    \ std::abs(polygon_area_doubled(polygon)) / 2.;\n}\n\n/**\n * @brief \u591A\u89D2\
    \u5F62\u306E\u51F8\u6027\u5224\u5B9A\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\
    \n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\u56DE\u308A\
    )\n * @return true \u51F8\n * @return false \u51F9\n */\ntemplate <typename T>\n\
    bool polygon_is_convex(const std::vector<Vector<T, 2>>& polygon) {\n    int n\
    \ = polygon.size();\n    for (int i = 0; i < n; i++) {\n        int j = i + 1;\n\
    \        if (j == n) j = 0;\n        int k = j + 1;\n        if (k == n) k = 0;\n\
    \        if (cross(polygon[j] - polygon[i], polygon[k] - polygon[j]) < 0) return\
    \ false;\n    }\n    return true;\n}\n\n/**\n * @brief \u70B9\u306E\u591A\u89D2\
    \u5F62\u5185\u5305\u542B\u5224\u5B9A\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\
    \n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\u56DE\u308A\
    )\n * @param p \u70B9\u306E\u5EA7\u6A19\n * @return int 0: \u5916\u90E8, 1: \u8FBA\
    \u4E0A, 2: \u5185\u90E8\n */\ntemplate <typename T>\nint polygon_contains(const\
    \ std::vector<Vector<T, 2>>& polygon, const Vector<T, 2>& p) {\n    bool in =\
    \ false;\n    for (int i = 0; i < static_cast<int>(polygon.size()); i++) {\n \
    \       int j = i + 1;\n        if (j == static_cast<int>(polygon.size())) j =\
    \ 0;\n        Vector<T> v1 = polygon[i] - p, v2 = polygon[j] - p;\n        if\
    \ (v1[1] > v2[1]) std::swap(v1, v2);\n        T c = cross(v1, v2);\n        if\
    \ (v1[1] <= 0 && v2[1] > 0 && c < 0) in = !in;\n        if (c == 0 && dot(v1,\
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
    \n * @param points \u9802\u70B9\u30EA\u30B9\u30C8 (2\u500B\u4EE5\u4E0A)\n * @return\
    \ ClosestPairSquared<T> \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E2\u4E57\
    \u3068\u6DFB\u5B57\n */\ntemplate <typename T>\nClosestPairSquared<T> closest_point_pair_squared(const\
    \ std::vector<Vector<T, 2>>& points) {\n    assert(points.size() >= 2 && \"closest_point_pair_squared:\
    \ fewer than 2 points\");\n    std::vector<int> sorted_idx(points.size());\n \
    \   std::iota(sorted_idx.begin(), sorted_idx.end(), 0);\n    std::sort(sorted_idx.begin(),\
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
    \u30C8 (2\u500B\u4EE5\u4E0A)\n * @return ClosestPair \u6700\u8FD1\u70B9\u5BFE\u306E\
    \u8DDD\u96E2\u3068\u6DFB\u5B57\n */\ntemplate <typename T>\nClosestPair closest_point_pair(const\
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
    }\n#line 2 \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n * @brief \u56DB\
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
    using modint = dynamic_modint<-1>;\n#line 22 \"test/unittest/data_structures/dual-segtree.test.cpp\"\
    \n\nusing mint = modint998244353;\n\nstatic_assert(std::is_same_v<RAddQ<long long>,\
    \ DualSegTree<acted_monoid::AddMin<long long>>>);\nstatic_assert(std::is_same_v<RUpdateQ<long\
    \ long>, DualSegTree<acted_monoid::UpdateMin<long long>>>);\nstatic_assert(std::is_same_v<RChminQ<long\
    \ long>, DualSegTree<acted_monoid::ChminMin<long long>>>);\nstatic_assert(std::is_same_v<RChmaxQ<long\
    \ long>, DualSegTree<acted_monoid::ChmaxMax<long long>>>);\nstatic_assert(std::is_same_v<RAffineQ<mint>,\
    \ DualSegTree<acted_monoid::AffineSum<mint>>>);\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n    for (int rep = 0; rep < 2000 && ok; rep++)\
    \ {\n        int n = rng() % 12 + 1;\n        std::vector<mint> v(n);\n      \
    \  DualSegTree<acted_monoid::AffineSum<mint>> seg;\n        switch (rep % 3) {\n\
    \            case 0:\n                seg = DualSegTree<acted_monoid::AffineSum<mint>>(n);\n\
    \                break;\n            case 1: {\n                mint x = rng()\
    \ % 10;\n                seg = DualSegTree<acted_monoid::AffineSum<mint>>(n, x);\n\
    \                v.assign(n, x);\n                break;\n            }\n    \
    \        default:\n                for (auto& x : v) x = rng() % 10;\n       \
    \         seg = DualSegTree<acted_monoid::AffineSum<mint>>(v);\n             \
    \   break;\n        }\n        if (seg.size() != n) ok = false;\n        for (int\
    \ t = 0; t < 40; t++) {\n            int op = rng() % 5;\n            Affine<mint>\
    \ f{mint(rng() % 5), mint(rng() % 5)};\n            if (op == 0) {\n         \
    \       int l = rng() % (n + 1), r = rng() % (n + 1);\n                if (l >\
    \ r) std::swap(l, r);\n                seg.apply(l, r, f);\n                for\
    \ (int i = l; i < r; i++) v[i] = f(v[i]);\n            } else if (op == 1) {\n\
    \                int k = rng() % n;\n                seg.apply(k, f);\n      \
    \          v[k] = f(v[k]);\n            } else if (op == 2) {\n              \
    \  int k = rng() % n;\n                mint x = rng() % 10;\n                seg.set(k,\
    \ x);\n                v[k] = x;\n            } else if (op == 3) {\n        \
    \        int k = rng() % n;\n                if (seg.get(k) != v[k]) ok = false;\n\
    \            } else {\n                if (seg.to_vector() != v) ok = false;\n\
    \            }\n        }\n        for (int k = 0; k < n; k++) {\n           \
    \ if (seg.get(k) != v[k]) ok = false;\n        }\n    }\n    // \u533A\u9593\u306E\
    \u9577\u3055\u3092\u4F7F\u3046 mapping (\u8981\u7D20\u3054\u3068\u306B\u9577\u3055\
    \ 1 \u3068\u3057\u3066\u4F5C\u7528\u3059\u308B)\n    for (int rep = 0; rep < 500\
    \ && ok; rep++) {\n        int n = rng() % 12 + 1;\n        std::vector<long long>\
    \ v(n);\n        DualSegTree<acted_monoid::AddSum<long long>> seg(n);\n      \
    \  for (int t = 0; t < 40; t++) {\n            int l = rng() % (n + 1), r = rng()\
    \ % (n + 1);\n            if (l > r) std::swap(l, r);\n            long long x\
    \ = static_cast<long long>(rng() % 21) - 10;\n            seg.apply(l, r, x);\n\
    \            for (int i = l; i < r; i++) v[i] += x;\n            int k = rng()\
    \ % n;\n            if (seg.get(k) != v[k]) ok = false;\n        }\n    }\n  \
    \  // \u5225\u540D (\u533A\u9593\u52A0\u7B97\u30FB\u4EE3\u5165\u30FBchmin\u30FB\
    chmax)\n    for (int rep = 0; rep < 500 && ok; rep++) {\n        int n = rng()\
    \ % 12 + 1;\n        std::vector<long long> v(n);\n        for (auto& x : v) x\
    \ = static_cast<long long>(rng() % 21) - 10;\n        RAddQ<long long> add(v);\n\
    \        RUpdateQ<long long> upd(v);\n        RChminQ<long long> chmin(v);\n \
    \       RChmaxQ<long long> chmax(v);\n        std::vector<long long> va = v, vu\
    \ = v, vmin = v, vmax = v;\n        for (int t = 0; t < 40; t++) {\n         \
    \   int l = rng() % (n + 1), r = rng() % (n + 1);\n            if (l > r) std::swap(l,\
    \ r);\n            long long x = static_cast<long long>(rng() % 21) - 10;\n  \
    \          add.apply(l, r, x);\n            upd.apply(l, r, x);\n            chmin.apply(l,\
    \ r, x);\n            chmax.apply(l, r, x);\n            for (int i = l; i < r;\
    \ i++) va[i] += x, vu[i] = x, vmin[i] = std::min(vmin[i], x), vmax[i] = std::max(vmax[i],\
    \ x);\n            int k = rng() % n;\n            if (add.get(k) != va[k] ||\
    \ upd.get(k) != vu[k] || chmin.get(k) != vmin[k] || chmax.get(k) != vmax[k]) ok\
    \ = false;\n        }\n    }\n    // \u9806\u5E8F\u3084 S(sz) \u3092\u6301\u305F\
    \u306A\u3044\u578B (std::string\u3001Vector)\n    {\n        RUpdateQ<std::string>\
    \ seg(5, \"\");\n        seg.apply(1, 4, \"abc\");\n        seg.apply(2, 3, \"\
    x\");\n        if (seg.to_vector() != std::vector<std::string>{\"\", \"abc\",\
    \ \"x\", \"abc\", \"\"}) ok = false;\n        using V = Vector<long long>;\n \
    \       RAddQ<V> seg2(3);\n        seg2.apply(0, 2, V(1, 2));\n        seg2.apply(1,\
    \ 3, V(10, 20));\n        if (!(seg2.get(0) == V(1, 2) && seg2.get(1) == V(11,\
    \ 22) && seg2.get(2) == V(10, 20))) ok = false;\n    }\n\n    if (ok)\n      \
    \  std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr <<\
    \ \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// DualSegTree \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u53EF\u63DB\u3067\u306A\u3044\u4F5C\u7528\
    \ (\u30A2\u30D5\u30A3\u30F3\u5909\u63DB) \u3068\u3001\u533A\u9593\u306E\u9577\u3055\
    \u3092\u4F7F\u3046\u4F5C\u7528 (\u533A\u9593\u52A0\u7B97\u30FB\u533A\u9593\u548C\
    ) \u3067\u78BA\u304B\u3081\u308B\n// \u5225\u540D RAddQ / RUpdateQ / RChminQ /\
    \ RChmaxQ / RAffineQ \u3082\u78BA\u304B\u3081\u308B (\u9806\u5E8F\u3084 S(sz)\
    \ \u3092\u6301\u305F\u306A\u3044\u578B\u3067\u3082\u4F7F\u3048\u308B\u3053\u3068\
    )\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../../src/data_structures/dual-segtree.hpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <random>\n#include <string>\n#include <type_traits>\n\
    #include <vector>\n\n#include \"../../../src/data_structures/lazy-segtree.hpp\"\
    \  // \u5225\u540D\u304C\u304B\u3076\u3089\u306A\u3044\u3053\u3068\n#include \"\
    ../../../src/data_structures/segtree-beats.hpp\"\n#include \"../../../src/data_structures/segtree.hpp\"\
    \n#include \"../../../src/geometry/vector.hpp\"\n#include \"../../../src/math/modint.hpp\"\
    \n\nusing mint = modint998244353;\n\nstatic_assert(std::is_same_v<RAddQ<long long>,\
    \ DualSegTree<acted_monoid::AddMin<long long>>>);\nstatic_assert(std::is_same_v<RUpdateQ<long\
    \ long>, DualSegTree<acted_monoid::UpdateMin<long long>>>);\nstatic_assert(std::is_same_v<RChminQ<long\
    \ long>, DualSegTree<acted_monoid::ChminMin<long long>>>);\nstatic_assert(std::is_same_v<RChmaxQ<long\
    \ long>, DualSegTree<acted_monoid::ChmaxMax<long long>>>);\nstatic_assert(std::is_same_v<RAffineQ<mint>,\
    \ DualSegTree<acted_monoid::AffineSum<mint>>>);\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n    for (int rep = 0; rep < 2000 && ok; rep++)\
    \ {\n        int n = rng() % 12 + 1;\n        std::vector<mint> v(n);\n      \
    \  DualSegTree<acted_monoid::AffineSum<mint>> seg;\n        switch (rep % 3) {\n\
    \            case 0:\n                seg = DualSegTree<acted_monoid::AffineSum<mint>>(n);\n\
    \                break;\n            case 1: {\n                mint x = rng()\
    \ % 10;\n                seg = DualSegTree<acted_monoid::AffineSum<mint>>(n, x);\n\
    \                v.assign(n, x);\n                break;\n            }\n    \
    \        default:\n                for (auto& x : v) x = rng() % 10;\n       \
    \         seg = DualSegTree<acted_monoid::AffineSum<mint>>(v);\n             \
    \   break;\n        }\n        if (seg.size() != n) ok = false;\n        for (int\
    \ t = 0; t < 40; t++) {\n            int op = rng() % 5;\n            Affine<mint>\
    \ f{mint(rng() % 5), mint(rng() % 5)};\n            if (op == 0) {\n         \
    \       int l = rng() % (n + 1), r = rng() % (n + 1);\n                if (l >\
    \ r) std::swap(l, r);\n                seg.apply(l, r, f);\n                for\
    \ (int i = l; i < r; i++) v[i] = f(v[i]);\n            } else if (op == 1) {\n\
    \                int k = rng() % n;\n                seg.apply(k, f);\n      \
    \          v[k] = f(v[k]);\n            } else if (op == 2) {\n              \
    \  int k = rng() % n;\n                mint x = rng() % 10;\n                seg.set(k,\
    \ x);\n                v[k] = x;\n            } else if (op == 3) {\n        \
    \        int k = rng() % n;\n                if (seg.get(k) != v[k]) ok = false;\n\
    \            } else {\n                if (seg.to_vector() != v) ok = false;\n\
    \            }\n        }\n        for (int k = 0; k < n; k++) {\n           \
    \ if (seg.get(k) != v[k]) ok = false;\n        }\n    }\n    // \u533A\u9593\u306E\
    \u9577\u3055\u3092\u4F7F\u3046 mapping (\u8981\u7D20\u3054\u3068\u306B\u9577\u3055\
    \ 1 \u3068\u3057\u3066\u4F5C\u7528\u3059\u308B)\n    for (int rep = 0; rep < 500\
    \ && ok; rep++) {\n        int n = rng() % 12 + 1;\n        std::vector<long long>\
    \ v(n);\n        DualSegTree<acted_monoid::AddSum<long long>> seg(n);\n      \
    \  for (int t = 0; t < 40; t++) {\n            int l = rng() % (n + 1), r = rng()\
    \ % (n + 1);\n            if (l > r) std::swap(l, r);\n            long long x\
    \ = static_cast<long long>(rng() % 21) - 10;\n            seg.apply(l, r, x);\n\
    \            for (int i = l; i < r; i++) v[i] += x;\n            int k = rng()\
    \ % n;\n            if (seg.get(k) != v[k]) ok = false;\n        }\n    }\n  \
    \  // \u5225\u540D (\u533A\u9593\u52A0\u7B97\u30FB\u4EE3\u5165\u30FBchmin\u30FB\
    chmax)\n    for (int rep = 0; rep < 500 && ok; rep++) {\n        int n = rng()\
    \ % 12 + 1;\n        std::vector<long long> v(n);\n        for (auto& x : v) x\
    \ = static_cast<long long>(rng() % 21) - 10;\n        RAddQ<long long> add(v);\n\
    \        RUpdateQ<long long> upd(v);\n        RChminQ<long long> chmin(v);\n \
    \       RChmaxQ<long long> chmax(v);\n        std::vector<long long> va = v, vu\
    \ = v, vmin = v, vmax = v;\n        for (int t = 0; t < 40; t++) {\n         \
    \   int l = rng() % (n + 1), r = rng() % (n + 1);\n            if (l > r) std::swap(l,\
    \ r);\n            long long x = static_cast<long long>(rng() % 21) - 10;\n  \
    \          add.apply(l, r, x);\n            upd.apply(l, r, x);\n            chmin.apply(l,\
    \ r, x);\n            chmax.apply(l, r, x);\n            for (int i = l; i < r;\
    \ i++) va[i] += x, vu[i] = x, vmin[i] = std::min(vmin[i], x), vmax[i] = std::max(vmax[i],\
    \ x);\n            int k = rng() % n;\n            if (add.get(k) != va[k] ||\
    \ upd.get(k) != vu[k] || chmin.get(k) != vmin[k] || chmax.get(k) != vmax[k]) ok\
    \ = false;\n        }\n    }\n    // \u9806\u5E8F\u3084 S(sz) \u3092\u6301\u305F\
    \u306A\u3044\u578B (std::string\u3001Vector)\n    {\n        RUpdateQ<std::string>\
    \ seg(5, \"\");\n        seg.apply(1, 4, \"abc\");\n        seg.apply(2, 3, \"\
    x\");\n        if (seg.to_vector() != std::vector<std::string>{\"\", \"abc\",\
    \ \"x\", \"abc\", \"\"}) ok = false;\n        using V = Vector<long long>;\n \
    \       RAddQ<V> seg2(3);\n        seg2.apply(0, 2, V(1, 2));\n        seg2.apply(1,\
    \ 3, V(10, 20));\n        if (!(seg2.get(0) == V(1, 2) && seg2.get(1) == V(11,\
    \ 22) && seg2.get(2) == V(10, 20))) ok = false;\n    }\n\n    if (ok)\n      \
    \  std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr <<\
    \ \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/dual-segtree.hpp
  - src/algebra/acted-monoid.hpp
  - src/algebra/monoid.hpp
  - src/data_structures/lazy-segtree.hpp
  - src/data_structures/segtree-beats.hpp
  - src/algebra/beats-acted-monoid.hpp
  - src/data_structures/segtree.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/dual-segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/dual-segtree.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/dual-segtree.test.cpp
- /verify/test/unittest/data_structures/dual-segtree.test.cpp.html
title: test/unittest/data_structures/dual-segtree.test.cpp
---
