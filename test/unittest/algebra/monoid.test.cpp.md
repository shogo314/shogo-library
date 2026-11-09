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
    path: src/algebra/group.hpp
    title: "\u7FA4\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/dual-segtree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u4F5C\u7528\
      \u30011\u70B9\u53D6\u5F97)"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/fast-set.hpp
    title: "64 \u5206\u6728 (FastSet)"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/fenwick-tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  - icon: ':heavy_check_mark:'
    path: src/data_structures/imos.hpp
    title: "imos\u6CD5\u3067\u533A\u9593\u4F5C\u7528\u30011\u70B9\u53D6\u5F97"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/lazy-segtree.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/link-cut-tree.hpp
    title: Link-Cut Tree
  - icon: ':heavy_check_mark:'
    path: src/data_structures/monoid-unionfind.hpp
    title: "\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308BUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/persistent-lazy-segtree.hpp
    title: "\u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/persistent-segtree.hpp
    title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/potentialized-unionfind.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/rbst.hpp
    title: "\u5E73\u8861\u4E8C\u5206\u6728 (RBST)"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree-beats.hpp
    title: Segment Tree Beats
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/sortable-segtree.hpp
    title: "\u533A\u9593\u30BD\u30FC\u30C8\u306E\u3067\u304D\u308B\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/sparse-table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
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
  bundledCode: "#line 1 \"test/unittest/algebra/monoid.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ monoid.hpp / group.hpp \u306E\u30E2\u30CE\u30A4\u30C9\u30FB\u7FA4\u3068 SegTree\
    \ \u306E\u7D30\u304B\u3044\u6A5F\u80FD\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\
    \u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#include <algorithm>\n#include <array>\n#include <cstddef>\n\
    #include <istream>\n#include <limits>\n#include <numeric>\n#include <optional>\n\
    #include <ostream>\n#include <type_traits>\n#include <utility>\n\n/**\n * @brief\
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
    \ T) -> Monoid<T, Op>;\n#line 7 \"test/unittest/algebra/monoid.test.cpp\"\n\n\
    #line 9 \"test/unittest/algebra/monoid.test.cpp\"\n#include <deque>\n#include\
    \ <forward_list>\n#include <iostream>\n#line 13 \"test/unittest/algebra/monoid.test.cpp\"\
    \n#include <list>\n#include <random>\n#include <sstream>\n#include <string>\n\
    #line 19 \"test/unittest/algebra/monoid.test.cpp\"\n#include <vector>\n\n#line\
    \ 2 \"src/algebra/group.hpp\"\n\n/**\n * @file group.hpp\n * @brief \u7FA4\u306E\
    \u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\
    \ \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\
    \u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - S inv(const S& a):\
    \ \u9006\u5143\n */\n\n#line 14 \"src/algebra/group.hpp\"\n\n#line 16 \"src/algebra/group.hpp\"\
    \n\nnamespace group {\n\n/**\n * @brief \u52A0\u6CD5\u7FA4\n */\ntemplate <typename\
    \ T>\nstruct Sum : monoid::Sum<T> {\n    using S = T;\n    static constexpr S\
    \ inv(const S& a) { return -a; }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7FA4 (0\u3092\
    \u542B\u307E\u306A\u3044\u4F53\u306E\u5143\u306A\u3069)\n */\ntemplate <typename\
    \ T>\nstruct Prod : monoid::Prod<T> {\n    using S = T;\n    static constexpr\
    \ S inv(const S& a) { return S(1) / a; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\
    \u8AD6\u7406\u548C\n */\ntemplate <typename T>\nstruct Xor : monoid::Xor<T> {\n\
    \    using S = T;\n    static constexpr S inv(const S& a) { return a; }\n};\n\n\
    /**\n * @brief {0, 1, ..., N-1} \u306E\u7F6E\u63DB (\u5168\u5358\u5C04) \u306E\
    \u5408\u6210\n *\n * monoid::Mapping<N> \u306B\u9006\u7F6E\u63DB\u3092\u52A0\u3048\
    \u305F\u3082\u306E\u3002\u8981\u7D20\u306F\u7F6E\u63DB\u3067\u3042\u308B\u3053\
    \u3068\n * op(f, g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n\
    \ *\n * @tparam N \u7F6E\u63DB\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\n */\n\
    template <std::size_t N>\nstruct Permutation : monoid::Mapping<N> {\n    using\
    \ S = std::array<int, N>;\n    static constexpr S inv(const S& f) {\n        S\
    \ h{};\n        for (std::size_t x = 0; x < N; x++) h[f[x]] = static_cast<int>(x);\n\
    \        return h;\n    }\n};\n\n}  // namespace group\n\n/**\n * @brief \u95A2\
    \u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\u5358\u4F4D\u5143\u304B\u3089\
    \u5B9F\u884C\u6642\u306B\u4F5C\u308B\u7FA4\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\
    \u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\
    \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n * @tparam Inv \u9006\
    \u5143\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\n\
    template <typename T, typename Op, typename Inv>\nstruct Group {\n    using S\
    \ = T;\n    Op op_object;\n    S identity;\n    Inv inv_object;\n    Group() =\
    \ default;\n    constexpr Group(Op op, const S& e, Inv inv) : op_object(std::move(op)),\
    \ identity(e), inv_object(std::move(inv)) {}\n    constexpr S op(const S& a, const\
    \ S& b) const { return op_object(a, b); }\n    constexpr S e() const { return\
    \ identity; }\n    constexpr S inv(const S& a) const { return inv_object(a); }\n\
    };\ntemplate <typename Op, typename T, typename Inv>\nGroup(Op, T, Inv) -> Group<T,\
    \ Op, Inv>;\n#line 2 \"src/data_structures/dual-segtree.hpp\"\n\n/**\n * @file\
    \ dual-segtree.hpp\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \ (\u533A\u9593\u4F5C\u7528\u30011\u70B9\u53D6\u5F97)\n */\n\n#include <cassert>\n\
    #include <initializer_list>\n#line 13 \"src/data_structures/dual-segtree.hpp\"\
    \n\n#line 2 \"src/algebra/acted-monoid.hpp\"\n\n/**\n * @file acted-monoid.hpp\n\
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
    \ F& f): \u9006\u4F5C\u7528\u7D20\n */\n\n#line 25 \"src/algebra/acted-monoid.hpp\"\
    \n\n#line 27 \"src/algebra/acted-monoid.hpp\"\n\n#if __cplusplus < 202002L\nnamespace\
    \ internal_acted_monoid {\ntemplate <typename A, typename = void>\nstruct has_mapping_lr\
    \ : std::false_type {};\ntemplate <typename A>\nstruct has_mapping_lr<A, std::void_t<decltype(std::declval<const\
    \ A&>().mapping(std::declval<const typename A::F&>(), std::declval<const typename\
    \ A::S&>(), 0, 0))>> : std::true_type {};\ntemplate <typename A, typename = void>\n\
    struct has_mapping_sz : std::false_type {};\ntemplate <typename A>\nstruct has_mapping_sz<A,\
    \ std::void_t<decltype(std::declval<const A&>().mapping(std::declval<const typename\
    \ A::F&>(), std::declval<const typename A::S&>(), 0))>> : std::true_type {};\n\
    }  // namespace internal_acted_monoid\n#endif\n\nnamespace acted_monoid {\n\n\
    /**\n * @brief \u533A\u9593 [l, r) \u3092\u8868\u3059\u8981\u7D20\u306B\u4F5C\u7528\
    \u7D20\u3092\u9069\u7528\u3059\u308B\n * mapping \u306E\u5F15\u6570\u306E\u5F62\
    \u306E\u9055\u3044\u3092\u5438\u53CE\u3059\u308B\n */\ntemplate <typename A>\n\
    constexpr auto apply_mapping(const A& a, const typename A::F& f, const typename\
    \ A::S& x, long long l, long long r) {\n#if __cplusplus >= 202002L\n    if constexpr\
    \ (requires { a.mapping(f, x, l, r); }) {\n#else\n    if constexpr (internal_acted_monoid::has_mapping_lr<A>::value)\
    \ {\n#endif\n        return a.mapping(f, x, l, r);\n#if __cplusplus >= 202002L\n\
    \    } else if constexpr (requires { a.mapping(f, x, r - l); }) {\n#else\n   \
    \ } else if constexpr (internal_acted_monoid::has_mapping_sz<A>::value) {\n#endif\n\
    \        return a.mapping(f, x, r - l);\n    } else {\n        return a.mapping(f,\
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
    #line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\
    \u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include <functional>\n\
    #include <iterator>\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\n\n#if\
    \ __cplusplus >= 202002L\n#include <concepts>\n#include <ranges>\n#endif\n\nnamespace\
    \ internal_traits {\nusing std::begin, std::end;\n\n#if __cplusplus >= 202002L\n\
    template <class T>\n    struct is_range_impl : std::bool_constant < requires(T&\
    \ t) {\n    begin(t);\n    end(t);\n}>{};\n#else\ntemplate <class T, class = void>\n\
    struct is_range_impl : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T,\
    \ std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>> :\
    \ std::true_type {};\n#endif\n\n// \u30B5\u30A4\u30BA\u4ED8\u304D\u7BC4\u56F2\u304B\
    \u3089\u8981\u7D20\u3092\u76F4\u63A5\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3067\u5171\u6709\u3059\u308B\u3002\n#if __cplusplus\
    \ >= 202002L\ntemplate <class R, class S>\nconcept sized_constructible_range =\
    \ std::ranges::input_range<R> && std::ranges::sized_range<R> &&\n            \
    \                        std::is_constructible_v<S, std::ranges::range_reference_t<R>>;\n\
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
    #line 16 \"src/data_structures/dual-segtree.hpp\"\n\n/**\n * @brief \u53CC\u5BFE\
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
    \u30E2\u30CE\u30A4\u30C9\n     */\n#if __cplusplus >= 202002L\n    template <class\
    \ R = std::initializer_list<S>>\n        requires internal_traits::sized_constructible_range<R,\
    \ S>\n#else\n    template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit DualSegTree(R&& v, A a = A()) : a(std::move(a)),\
    \ n(internal_traits::range_size(v)) {\n        data.reserve(n);\n        for (auto&&\
    \ x : v) data.emplace_back(std::forward<decltype(x)>(x));\n        construct();\n\
    \    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n\
    \    long long size() const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\
    \u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059 O(log n)\n     */\n\
    \    S get(long long k) const {\n        assert(0 <= k && k < n);\n        //\
    \ \u6839\u306B\u8FD1\u3044\u30CE\u30FC\u30C9\u307B\u3069\u5F8C\u306B\u4F5C\u7528\
    \u3057\u305F\u4F5C\u7528\u7D20\u306A\u306E\u3067\u3001\u8449\u304B\u3089\u9806\
    \u306B\u5408\u6210\u3059\u308B\n        F f = id();\n        for (long long i\
    \ = k + sz; i > 0; i >>= 1) f = composition(lazy[i], f);\n        return mapping(f,\
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
    \ A::S, A) -> DualSegTree<A>;\ntemplate <class R, typename A>\nDualSegTree(R&&,\
    \ A) -> DualSegTree<A>;\ntemplate <typename A>\nDualSegTree(std::initializer_list<typename\
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
    \ S>\nusing RAffineQ = DualSegTree<acted_monoid::AffineSum<S>>;\n#line 2 \"src/data_structures/fenwick-tree.hpp\"\
    \n\n/**\n * @file fenwick-tree.hpp\n * @brief Fenwick Tree (Binary Indexed Tree)\n\
    \ */\n\n#line 13 \"src/data_structures/fenwick-tree.hpp\"\n\n#line 16 \"src/data_structures/fenwick-tree.hpp\"\
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
    #if __cplusplus >= 202002L\n    template <class R = std::initializer_list<S>>\n\
    \        requires internal_traits::sized_constructible_range<R, S>\n#else\n  \
    \  template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
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
    \ 2 \"src/data_structures/imos.hpp\"\n\n/**\n * @file imos.hpp\n * @brief imos\u6CD5\
    \u3067\u533A\u9593\u4F5C\u7528\u30011\u70B9\u53D6\u5F97\n */\n\n#line 13 \"src/data_structures/imos.hpp\"\
    \n\n#line 16 \"src/data_structures/imos.hpp\"\n\n/**\n * @brief imos\u6CD5\u3067\
    \u533A\u9593\u4F5C\u7528\u30011\u70B9\u53D6\u5F97\u3059\u308B\u3002\n *\n * \u4F8B\
    : Imos<acted_monoid::AddSum<long long>> imos(n);\n *\n * @tparam A \u4F5C\u7528\
    \u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\n *    \
    \       \u4F5C\u7528\u7D20\u306F\u30A2\u30FC\u30D9\u30EB\u7FA4(\u53EF\u63DB\u7FA4\
    )\u3092\u306A\u3057\u3001inv \u3092\u6301\u3064\u5FC5\u8981\u304C\u3042\u308B\
    \ \u5024\u306E\u30E2\u30CE\u30A4\u30C9\u306E\u6F14\u7B97\u306F\u4F7F\u308F\u306A\
    \u3044\n */\ntemplate <typename A>\nclass Imos {\n   public:\n    using S = typename\
    \ A::S;\n    using F = typename A::F;\n\n   private:\n    A a;\n    long long\
    \ _n, t;\n    std::vector<S> data;\n    std::vector<F> lazy;\n\n    S mapping(const\
    \ F& f, const S& x, long long k) const { return acted_monoid::apply_mapping(a,\
    \ f, x, k, k + 1); }\n    F composition(const F& f, const F& g) const { return\
    \ a.composition(f, g); }\n    F id() const { return a.id(); }\n    F inv(const\
    \ F& f) const { return a.inv(f); }\n\n   public:\n    /**\n     * @param n \u8981\
    \u7D20\u6570 \u5404\u8981\u7D20\u306F S() \u3067\u521D\u671F\u5316\u3059\u308B\
    \n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n   \
    \  */\n    explicit Imos(long long n = 0, A a = A()) : Imos(n, S(), std::move(a))\
    \ {}\n    /**\n     * @param n \u8981\u7D20\u6570\n     * @param value \u5404\u8981\
    \u7D20\u306E\u521D\u671F\u5024\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\
    \u30E2\u30CE\u30A4\u30C9\n     */\n    Imos(long long n, const S& value, A a =\
    \ A()) : a(std::move(a)), _n(n), t(n), data(n, value), lazy(n, this->a.id()) {}\n\
    \    /**\n     * @param value \u5404\u8981\u7D20\u306E\u521D\u671F\u5024\n   \
    \  * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n\
    #if __cplusplus >= 202002L\n    template <class R = std::initializer_list<S>>\n\
    \        requires internal_traits::sized_constructible_range<R, S>\n#else\n  \
    \  template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit Imos(R&& value, A a = A()) : a(std::move(a)),\
    \ _n(internal_traits::range_size(value)), t(_n), lazy(_n, this->a.id()) {\n  \
    \      data.reserve(_n);\n        for (auto&& x : value) data.emplace_back(std::forward<decltype(x)>(x));\n\
    \    }\n\n    /**\n     * @brief 1\u70B9\u4F5C\u7528\n     * @param k \u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n     * @param f \u4F5C\u7528\u7D20\n     */\n    void\
    \ apply(long long k, const F& f) {\n        assert(0 <= k && k < _n);\n      \
    \  data[k] = mapping(f, data[k], k);\n    }\n    /**\n     * @brief [l, r)\u306E\
    \u533A\u9593\u306E\u5024\u306Bf\u3092\u4F5C\u7528\u3055\u305B\u308B\n     * @param\
    \ l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\
    \u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @param f \u4F5C\u7528\u7D20\n    \
    \ */\n    void apply(long long l, long long r, const F& f) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l < _n) lazy[l] = composition(lazy[l],\
    \ f);\n        if (r < _n) lazy[r] = composition(lazy[r], inv(f));\n        if\
    \ (t > l) t = l;\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\
    \u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     * @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n     * @return const S& \u5024\n     */\n    const S& get(long\
    \ long k) {\n        assert(0 <= k && k < _n);\n        while (t <= k) {\n   \
    \         data[t] = mapping(lazy[t], data[t], t);\n            if (t + 1 < _n)\
    \ {\n                lazy[t + 1] = composition(lazy[t], lazy[t + 1]);\n      \
    \      }\n            lazy[t] = id();\n            t++;\n        }\n        return\
    \ data[k];\n    }\n};\n\ntemplate <typename A>\nImos(long long, A) -> Imos<A>;\n\
    template <typename A>\nImos(long long, typename A::S, A) -> Imos<A>;\ntemplate\
    \ <class R, typename A>\nImos(R&&, A) -> Imos<A>;\ntemplate <typename A>\nImos(std::initializer_list<typename\
    \ A::S>, A) -> Imos<A>;\n#line 2 \"src/data_structures/lazy-segtree.hpp\"\n\n\
    /**\n * @file lazy-segtree.hpp\n * @brief \u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n */\n\n#line 15 \"src/data_structures/lazy-segtree.hpp\"\
    \n\n#line 18 \"src/data_structures/lazy-segtree.hpp\"\n\n/**\n * @brief \u9045\
    \u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u4F8B:\n * LazySegTree<acted_monoid::AffineSum<mint>>\
    \ seg(v);\n *\n * @tparam A \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/acted-monoid.hpp)\n */\ntemplate <typename A>\nclass LazySegTree {\n\
    \   public:\n    using S = typename A::S;\n    using F = typename A::F;\n\n  \
    \ private:\n    A a;\n    S op(const S& x, const S& y) const { return a.op(x,\
    \ y); }\n    S e() const { return a.e(); }\n    S mapping(const F& f, const S&\
    \ x, long long l, long long r) const { return acted_monoid::apply_mapping(a, f,\
    \ x, l, r); }\n    F composition(const F& f, const F& g) const { return a.composition(f,\
    \ g); }\n    F id() const { return a.id(); }\n\n    long long n, sz;\n    int\
    \ height;\n    std::vector<S> data;\n    std::vector<F> lazy;\n\n    void update(long\
    \ long k) { data[k] = op(data[2 * k], data[2 * k + 1]); }\n    void apply_node(long\
    \ long k, int h, const F& f) {\n        // \u672B\u5C3E\u306E\u8981\u7D20\u6570\
    \u3092 2 \u3079\u304D\u306B\u305D\u308D\u3048\u308B\u305F\u3081\u306E\u4F59\u308A\
    \u306E\u90E8\u5206\u306F\u533A\u9593\u306B\u542B\u3081\u306A\u3044\n        long\
    \ long l = std::min((k << h) & (sz - 1), n);\n        long long r = std::min(((k\
    \ << h) & (sz - 1)) + (1LL << h), n);\n        data[k] = mapping(f, data[k], l,\
    \ r);\n        if (k < sz) lazy[k] = composition(f, lazy[k]);\n    }\n    void\
    \ push(long long k, int h) {\n        apply_node(2 * k, h - 1, lazy[k]);\n   \
    \     apply_node(2 * k + 1, h - 1, lazy[k]);\n        lazy[k] = id();\n    }\n\
    \n    class LazySegTreeReference {\n        LazySegTree& segtree;\n        long\
    \ long k;\n\n       public:\n        LazySegTreeReference(LazySegTree& segtree,\
    \ long long k) : segtree(segtree), k(k) {}\n        LazySegTreeReference& operator=(const\
    \ S& x) {\n            segtree.set(k, x);\n            return *this;\n       \
    \ }\n        operator S() { return segtree.get(k); }\n    };\n\n    void construct_data()\
    \ {\n        sz = 1;\n        height = 0;\n        while (sz < n) {\n        \
    \    sz <<= 1;\n            height++;\n        }\n        data.assign(sz * 2,\
    \ e());\n        lazy.assign(sz * 2, id());\n    }\n\n   public:\n    /**\n  \
    \   * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param\
    \ n \u8981\u7D20\u6570\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\
    \u30A4\u30C9\n     */\n    explicit LazySegTree(long long n = 0, A a = A()) :\
    \ a(std::move(a)), n(n) {\n        construct_data();\n    }\n    /**\n     * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param v \u521D\u671F\
    \u306E\u8981\u7D20\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\
    \u30A4\u30C9\n     */\n#if __cplusplus >= 202002L\n    template <class R = std::initializer_list<S>>\n\
    \        requires internal_traits::sized_constructible_range<R, S>\n#else\n  \
    \  template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit LazySegTree(R&& v, A a = A()) : LazySegTree(internal_traits::range_size(v),\
    \ std::move(a)) {\n        long long k = sz;\n        for (auto&& x : v) data[k++]\
    \ = S(std::forward<decltype(x)>(x));\n        for (long long i = sz - 1; i > 0;\
    \ i--) update(i);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\n     */\n    long long size() const { return n; }\n\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n \
    \    *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S\
    \ \u5024\n     */\n    S get(long long k) {\n        assert(0 <= k && k < n);\n\
    \        k += sz;\n        for (int h = height; h > 0; h--) {\n            push(k\
    \ >> h, h);\n        }\n        return data[k];\n    }\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\
    \u3059\n     *\n     * @param k\n     * @return SegTreeReference \u8981\u7D20\u3078\
    \u306E\u53C2\u7167 \u4EE3\u5165\u3055\u308C\u308B\u3068set()\u304C\u547C\u3070\
    \u308C\u308B\n     */\n    LazySegTreeReference operator[](long long k) { return\
    \ LazySegTreeReference(*this, k); }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\
    \u51FA\u529B\u3059\u308B\n     *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param\
    \ os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n     * @return std::basic_ostream<CharT, Traits>& \u51FA\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     */\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
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
    \ long, A) -> LazySegTree<A>;\ntemplate <class R, typename A>\nLazySegTree(R&&,\
    \ A) -> LazySegTree<A>;\ntemplate <typename A>\nLazySegTree(std::initializer_list<typename\
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
    #line 2 \"src/data_structures/link-cut-tree.hpp\"\n\n/**\n * @file link-cut-tree.hpp\n\
    \ * @brief Link-Cut Tree\n */\n\n#line 13 \"src/data_structures/link-cut-tree.hpp\"\
    \n\n#line 15 \"src/data_structures/link-cut-tree.hpp\"\n\n/**\n * @brief Link-Cut\
    \ Tree (\u68EE\u3067\u3001\u8FBA\u306E\u8FFD\u52A0\u30FB\u524A\u9664\u3068\u30D1\
    \u30B9\u4E0A\u306E\u5024\u306E\u96C6\u7D04\u304C\u3067\u304D\u308B)\n *\n * \u5404\
    \u64CD\u4F5C\u306F\u306A\u3089\u3057 O(log n)\u3002\u5185\u90E8\u306E\u914D\u5217\
    \u306F int \u3067\u6301\u3064\n * \u4F8B:\n * LinkCutTree<monoid::Sum<long long>>\
    \ lct(a);\n * lct.link(0, 1);\n * long long s = lct.prod(0, 1);\n *\n * @tparam\
    \ M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\u3002\u53EF\u63DB\u3067\u306A\
    \u304F\u3066\u3082\u3088\u3044 (prod \u306F u \u304B\u3089 v \u306E\u5411\u304D\
    \u306B\u305F\u305F\u3080)\n */\ntemplate <typename M>\nclass LinkCutTree {\n \
    \   using S = typename M::S;\n    struct Node {\n        int l = -1, r = -1, p\
    \ = -1;\n        bool rev = false;\n        S val, sum, rsum;  // sum \u306F\u5DE6\
    \u304B\u3089\u53F3\u3001rsum \u306F\u53F3\u304B\u3089\u5DE6\u306B\u305F\u305F\u3093\
    \u3060\u3082\u306E\n    };\n    M m;\n    S op(const S& a, const S& b) const {\
    \ return m.op(a, b); }\n    S e() const { return m.e(); }\n    std::vector<Node>\
    \ t;\n    std::vector<int> stk;\n\n    bool is_root(int x) const {\n        int\
    \ p = t[x].p;\n        return p == -1 || (t[p].l != x && t[p].r != x);\n    }\n\
    \    S sum(int x) const { return x == -1 ? e() : t[x].sum; }\n    S rsum(int x)\
    \ const { return x == -1 ? e() : t[x].rsum; }\n    void update(int x) {\n    \
    \    t[x].sum = op(op(sum(t[x].l), t[x].val), sum(t[x].r));\n        t[x].rsum\
    \ = op(op(rsum(t[x].r), t[x].val), rsum(t[x].l));\n    }\n    void toggle(int\
    \ x) {\n        if (x == -1) return;\n        std::swap(t[x].l, t[x].r);\n   \
    \     std::swap(t[x].sum, t[x].rsum);\n        t[x].rev = !t[x].rev;\n    }\n\
    \    void push(int x) {\n        if (!t[x].rev) return;\n        toggle(t[x].l);\n\
    \        toggle(t[x].r);\n        t[x].rev = false;\n    }\n    void rotate(int\
    \ x) {\n        int p = t[x].p, g = t[p].p;\n        if (t[p].l == x) {\n    \
    \        t[p].l = t[x].r;\n            if (t[x].r != -1) t[t[x].r].p = p;\n  \
    \          t[x].r = p;\n        } else {\n            t[p].r = t[x].l;\n     \
    \       if (t[x].l != -1) t[t[x].l].p = p;\n            t[x].l = p;\n        }\n\
    \        t[p].p = x, t[x].p = g;\n        if (g != -1) {\n            if (t[g].l\
    \ == p) t[g].l = x;\n            if (t[g].r == p) t[g].r = x;\n        }\n   \
    \     update(p), update(x);\n    }\n    void splay(int x) {\n        for (int\
    \ y = x;; y = t[y].p) {\n            stk.push_back(y);\n            if (is_root(y))\
    \ break;\n        }\n        while (!stk.empty()) push(stk.back()), stk.pop_back();\n\
    \        while (!is_root(x)) {\n            int p = t[x].p;\n            if (!is_root(p))\
    \ rotate((t[t[p].p].l == p) == (t[p].l == x) ? p : x);\n            rotate(x);\n\
    \        }\n    }\n    // x \u304B\u3089\u6839\u307E\u3067\u306E\u30D1\u30B9\u3092\
    \ 1 \u672C\u306E splay \u6728\u306B\u3057\u3001x \u3092\u305D\u306E\u6839\u306B\
    \u3059\u308B\u3002\u6700\u5F8C\u306B splay \u3057\u305F\u9802\u70B9\u3092\u8FD4\
    \u3059\n    int access(int x) {\n        int last = -1;\n        for (int y =\
    \ x; y != -1; y = t[y].p) {\n            splay(y);\n            t[y].r = last;\n\
    \            update(y);\n            last = y;\n        }\n        splay(x);\n\
    \        return last;\n    }\n\n   public:\n    /**\n     * @brief \u9802\u70B9\
    \u6570 n\u3001\u8FBA\u306A\u3057\u3001\u5024\u306F\u3059\u3079\u3066\u5358\u4F4D\
    \u5143\n     *\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ LinkCutTree(long long n = 0, M m = M()) : m(std::move(m)) {\n        Node x;\n\
    \        x.val = x.sum = x.rsum = e();\n        t.assign(n, x);\n    }\n    /**\n\
    \     * @brief \u9802\u70B9 i \u306E\u5024\u304C a[i]\u3001\u8FBA\u306A\u3057\n\
    \     */\n#if __cplusplus >= 202002L\n    template <class R = std::initializer_list<S>>\n\
    \        requires internal_traits::sized_constructible_range<R, S>\n#else\n  \
    \  template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit LinkCutTree(R&& a, M m = M()) : LinkCutTree(internal_traits::range_size(a),\
    \ std::move(m)) {\n        long long i = 0;\n        for (auto&& x : a) {\n  \
    \          t[i].val = t[i].sum = t[i].rsum = S(std::forward<decltype(x)>(x));\n\
    \            ++i;\n        }\n    }\n\n    /**\n     * @brief \u9802\u70B9\u6570\
    \n     */\n    long long size() const { return static_cast<long long>(t.size());\
    \ }\n    /**\n     * @brief v \u3092\u6839\u306B\u3059\u308B\n     */\n    void\
    \ evert(long long v) {\n        access(v);\n        toggle(v);\n        push(v);\n\
    \    }\n    /**\n     * @brief \u8FBA (u, v) \u3092\u8FFD\u52A0\u3059\u308B\u3002\
    u \u3068 v \u306F\u5225\u306E\u6728\u306B\u3042\u308B\u3053\u3068\n     */\n \
    \   void link(long long u, long long v) {\n        assert(!connected(u, v));\n\
    \        evert(u);\n        t[u].p = static_cast<int>(v);\n    }\n    /**\n  \
    \   * @brief \u8FBA (u, v) \u3092\u524A\u9664\u3059\u308B\u3002\u8FBA (u, v) \u304C\
    \u3042\u308B\u3053\u3068\n     */\n    void cut(long long u, long long v) {\n\
    \        evert(u);\n        access(v);\n        assert(t[v].l == u && t[u].r ==\
    \ -1);\n        t[v].l = t[u].p = -1;\n        update(v);\n    }\n    /**\n  \
    \   * @brief v \u3092\u542B\u3080\u6728\u306E\u6839\n     */\n    long long root(long\
    \ long v) {\n        access(v);\n        int x = static_cast<int>(v);\n      \
    \  while (push(x), t[x].l != -1) x = t[x].l;\n        splay(x);\n        return\
    \ x;\n    }\n    /**\n     * @brief u \u3068 v \u304C\u540C\u3058\u6728\u306B\u3042\
    \u308B\u304B\n     */\n    bool connected(long long u, long long v) { return u\
    \ == v || root(u) == root(v); }\n    /**\n     * @brief u \u3068 v \u306E\u6700\
    \u5C0F\u5171\u901A\u7956\u5148 (\u6839\u306F\u6700\u5F8C\u306B evert \u3057\u305F\
    \u9802\u70B9\u306A\u3069\u3001\u4ECA\u306E\u6839)\u3002u \u3068 v \u306F\u540C\
    \u3058\u6728\u306B\u3042\u308B\u3053\u3068\n     */\n    long long lca(long long\
    \ u, long long v) {\n        assert(connected(u, v));\n        access(u);\n  \
    \      return access(v);\n    }\n    /**\n     * @brief \u9802\u70B9 v \u306E\u5024\
    \u3092 x \u306B\u3059\u308B\n     */\n    void set(long long v, const S& x) {\n\
    \        access(v);\n        t[v].val = x;\n        update(v);\n    }\n    /**\n\
    \     * @brief \u9802\u70B9 v \u306E\u5024\n     */\n    S get(long long v) const\
    \ { return t[v].val; }\n    /**\n     * @brief \u9802\u70B9 v \u306E\u5024\u3092\
    \ op(get(v), x) \u306B\u3059\u308B\n     */\n    void apply(long long v, const\
    \ S& x) { set(v, op(t[v].val, x)); }\n    /**\n     * @brief u \u304B\u3089 v\
    \ \u3078\u306E\u30D1\u30B9\u4E0A\u306E\u9802\u70B9 (\u7AEF\u70B9\u3092\u542B\u3080\
    ) \u306E\u5024\u3092\u3001u \u306E\u5074\u304B\u3089\u9806\u306B\u305F\u305F\u3093\
    \u3060\u3082\u306E\u3002u \u3068 v \u306F\u540C\u3058\u6728\u306B\u3042\u308B\u3053\
    \u3068\n     *\n     * u \u304C\u6839\u306B\u306A\u308B\n     */\n    S prod(long\
    \ long u, long long v) {\n        assert(connected(u, v));\n        evert(u);\n\
    \        access(v);\n        return t[v].sum;\n    }\n};\n\n/**\n * @brief \u90E8\
    \u5206\u6728\u306E\u5024\u306E\u96C6\u7D04\u3082\u3067\u304D\u308B Link-Cut Tree\n\
    \ *\n * \u30D1\u30B9\u306B\u542B\u307E\u308C\u306A\u3044\u5B50\u306E\u90E8\u5206\
    \u6728\u306E\u5024 (virtual) \u3092\u6301\u3064\u3002\u5404\u64CD\u4F5C\u306F\u306A\
    \u3089\u3057 O(log n)\n * \u4F8B:\n * SubtreeLinkCutTree<group::Sum<long long>>\
    \ lct(a);\n * lct.link(0, 1);\n * long long s = lct.subtree_prod(1, 0);  // 0\
    \ \u3092\u89AA\u3068\u3057\u305F\u3068\u304D\u306E 1 \u306E\u90E8\u5206\u6728\u306E\
    \u548C\n *\n * @tparam G \u53EF\u63DB\u306A\u7FA4 (algebra/group.hpp)\n */\n\n\
    template <typename M>\nLinkCutTree(long long, M) -> LinkCutTree<M>;\ntemplate\
    \ <class R, typename M>\nLinkCutTree(R&&, M) -> LinkCutTree<M>;\ntemplate <typename\
    \ M>\nLinkCutTree(std::initializer_list<typename M::S>, M) -> LinkCutTree<M>;\n\
    \ntemplate <typename G>\nclass SubtreeLinkCutTree {\n    using S = typename G::S;\n\
    \    struct Node {\n        int l = -1, r = -1, p = -1;\n        bool rev = false;\n\
    \        S val, path, virt, sum;  // path \u306F\u30D1\u30B9\u4E0A\u3001sum \u306F\
    \ virtual \u3082\u542B\u3081\u305F\u548C\n    };\n    G g;\n    S op(const S&\
    \ a, const S& b) const { return g.op(a, b); }\n    S e() const { return g.e();\
    \ }\n    S inv(const S& a) const { return g.inv(a); }\n    std::vector<Node> t;\n\
    \    std::vector<int> stk;\n\n    bool is_root(int x) const {\n        int p =\
    \ t[x].p;\n        return p == -1 || (t[p].l != x && t[p].r != x);\n    }\n  \
    \  S path(int x) const { return x == -1 ? e() : t[x].path; }\n    S sum(int x)\
    \ const { return x == -1 ? e() : t[x].sum; }\n    void update(int x) {\n     \
    \   t[x].path = op(op(path(t[x].l), t[x].val), path(t[x].r));\n        t[x].sum\
    \ = op(op(sum(t[x].l), op(t[x].val, t[x].virt)), sum(t[x].r));\n    }\n    void\
    \ toggle(int x) {\n        if (x == -1) return;\n        std::swap(t[x].l, t[x].r);\n\
    \        t[x].rev = !t[x].rev;\n    }\n    void push(int x) {\n        if (!t[x].rev)\
    \ return;\n        toggle(t[x].l);\n        toggle(t[x].r);\n        t[x].rev\
    \ = false;\n    }\n    void rotate(int x) {\n        int p = t[x].p, g = t[p].p;\n\
    \        if (t[p].l == x) {\n            t[p].l = t[x].r;\n            if (t[x].r\
    \ != -1) t[t[x].r].p = p;\n            t[x].r = p;\n        } else {\n       \
    \     t[p].r = t[x].l;\n            if (t[x].l != -1) t[t[x].l].p = p;\n     \
    \       t[x].l = p;\n        }\n        t[p].p = x, t[x].p = g;\n        if (g\
    \ != -1) {\n            if (t[g].l == p) t[g].l = x;\n            if (t[g].r ==\
    \ p) t[g].r = x;\n        }\n        update(p), update(x);\n    }\n    void splay(int\
    \ x) {\n        for (int y = x;; y = t[y].p) {\n            stk.push_back(y);\n\
    \            if (is_root(y)) break;\n        }\n        while (!stk.empty()) push(stk.back()),\
    \ stk.pop_back();\n        while (!is_root(x)) {\n            int p = t[x].p;\n\
    \            if (!is_root(p)) rotate((t[t[p].p].l == p) == (t[p].l == x) ? p :\
    \ x);\n            rotate(x);\n        }\n    }\n    int access(int x) {\n   \
    \     int last = -1;\n        for (int y = x; y != -1; y = t[y].p) {\n       \
    \     splay(y);\n            // \u4ECA\u306E\u53F3\u306E\u5B50\u306F virtual \u306B\
    \u306A\u308A\u3001last \u306F virtual \u3067\u306A\u304F\u306A\u308B\n       \
    \     t[y].virt = op(op(t[y].virt, sum(t[y].r)), inv(sum(last)));\n          \
    \  t[y].r = last;\n            update(y);\n            last = y;\n        }\n\
    \        splay(x);\n        return last;\n    }\n\n   public:\n    explicit SubtreeLinkCutTree(long\
    \ long n = 0, G g = G()) : g(std::move(g)) {\n        Node x;\n        x.val =\
    \ x.path = x.virt = x.sum = e();\n        t.assign(n, x);\n    }\n#if __cplusplus\
    \ >= 202002L\n    template <class R = std::initializer_list<S>>\n        requires\
    \ internal_traits::sized_constructible_range<R, S>\n#else\n    template <class\
    \ R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit SubtreeLinkCutTree(R&& a, G g = G()) : SubtreeLinkCutTree(internal_traits::range_size(a),\
    \ std::move(g)) {\n        long long i = 0;\n        for (auto&& x : a) {\n  \
    \          t[i].val = t[i].path = t[i].sum = S(std::forward<decltype(x)>(x));\n\
    \            ++i;\n        }\n    }\n\n    long long size() const { return static_cast<long\
    \ long>(t.size()); }\n    void evert(long long v) {\n        access(v);\n    \
    \    toggle(v);\n        push(v);\n    }\n    void link(long long u, long long\
    \ v) {\n        assert(!connected(u, v));\n        evert(u);\n        access(v);\n\
    \        t[u].p = static_cast<int>(v);\n        t[v].virt = op(t[v].virt, t[u].sum);\n\
    \        update(v);\n    }\n    void cut(long long u, long long v) {\n       \
    \ evert(u);\n        access(v);\n        assert(t[v].l == u && t[u].r == -1);\n\
    \        t[v].l = t[u].p = -1;\n        update(v);\n    }\n    long long root(long\
    \ long v) {\n        access(v);\n        int x = static_cast<int>(v);\n      \
    \  while (push(x), t[x].l != -1) x = t[x].l;\n        splay(x);\n        return\
    \ x;\n    }\n    bool connected(long long u, long long v) { return u == v || root(u)\
    \ == root(v); }\n    long long lca(long long u, long long v) {\n        assert(connected(u,\
    \ v));\n        access(u);\n        return access(v);\n    }\n    void set(long\
    \ long v, const S& x) {\n        access(v);\n        t[v].val = x;\n        update(v);\n\
    \    }\n    S get(long long v) const { return t[v].val; }\n    void apply(long\
    \ long v, const S& x) { set(v, op(t[v].val, x)); }\n    /**\n     * @brief u \u304B\
    \u3089 v \u3078\u306E\u30D1\u30B9\u4E0A\u306E\u9802\u70B9 (\u7AEF\u70B9\u3092\u542B\
    \u3080) \u306E\u5024\u306E\u548C\u3002u \u3068 v \u306F\u540C\u3058\u6728\u306B\
    \u3042\u308B\u3053\u3068\n     */\n    S prod(long long u, long long v) {\n  \
    \      assert(connected(u, v));\n        evert(u);\n        access(v);\n     \
    \   return t[v].path;\n    }\n    /**\n     * @brief p \u3092\u6839\u3068\u3057\
    \u305F\u3068\u304D\u306E v \u306E\u90E8\u5206\u6728\u306E\u5024\u306E\u548C (p\
    \ == v \u306A\u3089\u6728\u5168\u4F53)\u3002v \u3068 p \u306F\u540C\u3058\u6728\
    \u306B\u3042\u308B\u3053\u3068\n     *\n     * p \u304C\u6839\u306B\u306A\u308B\
    \n     */\n    S subtree_prod(long long v, long long p) {\n        assert(connected(v,\
    \ p));\n        evert(p);\n        access(v);\n        return op(t[v].val, t[v].virt);\n\
    \    }\n};\n\ntemplate <typename G>\nSubtreeLinkCutTree(long long, G) -> SubtreeLinkCutTree<G>;\n\
    template <class R, typename G>\nSubtreeLinkCutTree(R&&, G) -> SubtreeLinkCutTree<G>;\n\
    template <typename G>\nSubtreeLinkCutTree(std::initializer_list<typename G::S>,\
    \ G) -> SubtreeLinkCutTree<G>;\n#line 2 \"src/data_structures/monoid-unionfind.hpp\"\
    \n\n/**\n * @file monoid-unionfind.hpp\n * @brief \u53EF\u63DB\u30E2\u30CE\u30A4\
    \u30C9\u3092\u4E57\u305B\u308BUnionFind\n */\n\n#line 13 \"src/data_structures/monoid-unionfind.hpp\"\
    \n\n#line 2 \"src/data_structures/unionfind.hpp\"\n\n/**\n * @file unionfind.hpp\n\
    \ * @brief UnionFind\n */\n\n#line 12 \"src/data_structures/unionfind.hpp\"\n\n\
    namespace internal_unionfind {\n/**\n * @brief \u5404\u8981\u7D20\u306E\u4EE3\u8868\
    \u5143\u304B\u3089\u3001\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8981\u7D20\
    \u306E\u30EA\u30B9\u30C8\u3092\u4F5C\u308B\n * @param leader \u8981\u7D20 a \u306E\
    \u4EE3\u8868\u5143\u3092\u8FD4\u3059\u95A2\u6570\n */\ntemplate <typename F>\n\
    std::vector<std::vector<long long>> groups(long long n, F leader) {\n    std::vector<long\
    \ long> leader_buf(n), group_size(n);\n    for (long long i = 0; i < n; i++) {\n\
    \        leader_buf[i] = leader(i);\n        group_size[leader_buf[i]]++;\n  \
    \  }\n    std::vector<std::vector<long long>> result(n);\n    for (long long i\
    \ = 0; i < n; i++) {\n        result[i].reserve(group_size[i]);\n    }\n    for\
    \ (long long i = 0; i < n; i++) {\n        result[leader_buf[i]].push_back(i);\n\
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
    \        parent_or_size[y] = static_cast<int>(x);\n        return {x, true};\n\
    \    }\n    /**\n     * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\
    \u304B\n     */\n    bool same(long long a, long long b) {\n        assert(0 <=\
    \ a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a) ==\
    \ leader(b);\n    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    long long leader(long\
    \ long a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a]\
    \ < 0) return a;\n        int x = static_cast<int>(a);\n        while (parent_or_size[x]\
    \ >= 0) {\n            x = parent_or_size[x];\n        }\n        while (parent_or_size[a]\
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
    \ a) { return leader(a); });\n    }\n};\n#line 17 \"src/data_structures/monoid-unionfind.hpp\"\
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
    \n    /**\n     * @brief \u5404\u8981\u7D20\u3092 S(x) \u3067\u69CB\u7BC9\u3057\
    \u3066\u521D\u671F\u5316\u3059\u308B\n     */\n#if __cplusplus >= 202002L\n  \
    \  template <class R = std::initializer_list<S>>\n        requires internal_traits::sized_constructible_range<R,\
    \ S>\n#else\n    template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit MonoidUnionFind(R&& v, M m = M())\n      \
    \  : UnionFind(internal_traits::range_size(v)), m(std::move(m)) {\n        val.reserve(internal_traits::range_size(v));\n\
    \        for (auto&& x : v) val.emplace_back(std::forward<decltype(x)>(x));\n\
    \    }\n\n    using MergeResult = UnionFind::MergeResult;\n    using UnionFind::groups;\n\
    \    using UnionFind::leader;\n    using UnionFind::same;\n    using UnionFind::size;\n\
    \    /**\n     * @brief a \u3068 b \u306E\u9023\u7D50\u6210\u5206\u3092\u7D71\u5408\
    \u3057\u3001\u5024\u306E\u7A4D\u3092\u53D6\u308B\n     * @return \u7D71\u5408\u5F8C\
    \u306E\u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\
    \u304B\n     */\n    MergeResult merge(long long a, long long b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        long long x = leader(a),\
    \ y = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = static_cast<int>(x);\n        val[x] = m.op(val[x],\
    \ val[y]);\n        return {x, true};\n    }\n    /**\n     * @brief \u8981\u7D20\
    a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u5024\u306E\u7DCF\u7A4D\
    \n     */\n    const S& prod(long long a) {\n        return val[leader(a)];\n\
    \    }\n};\n\ntemplate <typename M>\nMonoidUnionFind(long long, M) -> MonoidUnionFind<M>;\n\
    template <class R, typename M>\nMonoidUnionFind(R&&, M) -> MonoidUnionFind<M>;\n\
    template <typename M>\nMonoidUnionFind(std::initializer_list<typename M::S>, M)\
    \ -> MonoidUnionFind<M>;\n#line 2 \"src/data_structures/persistent-lazy-segtree.hpp\"\
    \n\n/**\n * @file persistent-lazy-segtree.hpp\n * @brief \u6C38\u7D9A\u9045\u5EF6\
    \u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#line 11 \"src/data_structures/persistent-lazy-segtree.hpp\"\
    \n#include <memory>\n#line 16 \"src/data_structures/persistent-lazy-segtree.hpp\"\
    \n\n#line 19 \"src/data_structures/persistent-lazy-segtree.hpp\"\n\n/**\n * @brief\
    \ \u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n\
    \ * \u66F4\u65B0\u3059\u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\
    \u5143\u306E\u7248\u306F\u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u6728\
    \u304B\u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\
    \u3059\u308B\n * \u5225\u306E\u7248\u306E\u533A\u9593\u3092\u305D\u306E\u307E\u307E\
    \u5199\u3057\u305F\u7248\u3082\u4F5C\u308C\u308B\n * \u4F8B:\n * PersistentLazySegTree<acted_monoid::AffineSum<mint>>\
    \ s0(v);\n * auto s1 = s0.apply(l, r, Affine<mint>{b, c});  // s0 \u306F\u305D\
    \u306E\u307E\u307E\n * auto s2 = s1.copy(s0, l, r);                   // [l, r)\
    \ \u3092 s0 \u306E\u5024\u306B\u623B\u3057\u305F\u7248\n *\n * @tparam A \u4F5C\
    \u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\n\
    \ */\ntemplate <typename A>\nclass PersistentLazySegTree {\n   public:\n    using\
    \ S = typename A::S;\n    using F = typename A::F;\n\n   private:\n    // \u3059\
    \u3079\u3066\u306E\u7248\u306E\u30CE\u30FC\u30C9\u3092\u6301\u3064\u3002\u30CE\
    \u30FC\u30C9\u306F\u524A\u9664\u3057\u306A\u3044\n    // val \u306F\u30CE\u30FC\
    \u30C9\u306E\u533A\u9593\u306E\u7A4D\u3067\u3001\u305D\u306E\u30CE\u30FC\u30C9\
    \u306E lazy \u306F\u9069\u7528\u6E08\u307F\u3002lazy \u306F\u5B50\u306B\u307E\u3060\
    \u4F1D\u3048\u3066\u3044\u306A\u3044\u4F5C\u7528\u7D20\n    struct Pool {\n  \
    \      A a;\n        std::vector<S> val;\n        std::vector<F> lazy;\n     \
    \   std::vector<int> left, right;  // \u8449\u3067\u306F -1\n        explicit\
    \ Pool(A a) : a(std::move(a)) {}\n        int make_leaf(const S& x) {\n      \
    \      val.push_back(x);\n            lazy.push_back(a.id());\n            left.push_back(-1);\n\
    \            right.push_back(-1);\n            return static_cast<int>(val.size())\
    \ - 1;\n        }\n        int make_node(int l, int r) {\n            val.push_back(a.op(val[l],\
    \ val[r]));\n            lazy.push_back(a.id());\n            left.push_back(l);\n\
    \            right.push_back(r);\n            return static_cast<int>(val.size())\
    \ - 1;\n        }\n    };\n\n    std::shared_ptr<Pool> pool;\n    long long n,\
    \ sz;\n    int root;\n\n    S op(const S& x, const S& y) const { return pool->a.op(x,\
    \ y); }\n    S e() const { return pool->a.e(); }\n    // \u672B\u5C3E\u306E\u8981\
    \u7D20\u6570\u3092 2 \u3079\u304D\u306B\u305D\u308D\u3048\u308B\u305F\u3081\u306E\
    \u4F59\u308A\u306E\u90E8\u5206\u306F\u533A\u9593\u306B\u542B\u3081\u306A\u3044\
    \n    S mapping(const F& f, const S& x, long long a, long long b) const { return\
    \ acted_monoid::apply_mapping(pool->a, f, x, std::min(a, n), std::min(b, n));\
    \ }\n    F composition(const F& f, const F& g) const { return pool->a.composition(f,\
    \ g); }\n    F id() const { return pool->a.id(); }\n\n    PersistentLazySegTree(std::shared_ptr<Pool>\
    \ pool, long long n, long long sz, int root) : pool(std::move(pool)), n(n), sz(sz),\
    \ root(root) {}\n\n    void init_size() {\n        sz = 1;\n        while (sz\
    \ < n) sz <<= 1;\n    }\n    template <class It>\n    int build(It& it, long long\
    \ a, long long b) {\n        if (b - a == 1) {\n            if (a >= n) return\
    \ pool->make_leaf(e());\n            S x(*it);\n            ++it;\n          \
    \  return pool->make_leaf(x);\n        }\n        long long mid = (a + b) / 2;\n\
    \        int l = build(it, a, mid);\n        int r = build(it, mid, b);\n    \
    \    return pool->make_node(l, r);\n    }\n    // \u30CE\u30FC\u30C9 t ([a, b))\
    \ \u306B f \u3092\u4F5C\u7528\u3055\u305B\u305F\u65B0\u3057\u3044\u30CE\u30FC\u30C9\
    \n    int apply_node(int t, long long a, long long b, const F& f) const {\n  \
    \      S x = mapping(f, pool->val[t], a, b);\n        if (b - a == 1) return pool->make_leaf(x);\n\
    \        F g = composition(f, pool->lazy[t]);\n        int l = pool->left[t],\
    \ r = pool->right[t];\n        pool->val.push_back(x);\n        pool->lazy.push_back(g);\n\
    \        pool->left.push_back(l);\n        pool->right.push_back(r);\n       \
    \ return static_cast<int>(pool->val.size()) - 1;\n    }\n    // \u30CE\u30FC\u30C9\
    \ t ([a, b)) \u306E lazy \u3092\u5B50\u306B\u4F1D\u3048\u305F\u3001\u65B0\u3057\
    \u3044\u5B50\u306E\u7D44\n    std::pair<int, int> push(int t, long long a, long\
    \ long b) const {\n        long long mid = (a + b) / 2;\n        const F f = pool->lazy[t];\n\
    \        int l = apply_node(pool->left[t], a, mid, f);\n        int r = apply_node(pool->right[t],\
    \ mid, b, f);\n        return {l, r};\n    }\n    int set_rec(int t, long long\
    \ a, long long b, long long k, const S& x) const {\n        if (b - a == 1) return\
    \ pool->make_leaf(x);\n        long long mid = (a + b) / 2;\n        auto [l,\
    \ r] = push(t, a, b);\n        if (k < mid)\n            l = set_rec(l, a, mid,\
    \ k, x);\n        else\n            r = set_rec(r, mid, b, k, x);\n        return\
    \ pool->make_node(l, r);\n    }\n    int apply_rec(int t, long long a, long long\
    \ b, long long l, long long r, const F& f) const {\n        if (r <= a || b <=\
    \ l) return t;\n        if (l <= a && b <= r) return apply_node(t, a, b, f);\n\
    \        long long mid = (a + b) / 2;\n        auto [lc, rc] = push(t, a, b);\n\
    \        lc = apply_rec(lc, a, mid, l, r, f);\n        rc = apply_rec(rc, mid,\
    \ b, l, r, f);\n        return pool->make_node(lc, rc);\n    }\n    // t \u306E\
    \ [l, r) \u3092 u \u306B\u7F6E\u304D\u63DB\u3048\u308B\u3002f \u306F u \u306E\u7956\
    \u5148\u306B\u3042\u3063\u3066\u3001\u307E\u3060 u \u306B\u9069\u7528\u3057\u3066\
    \u3044\u306A\u3044\u4F5C\u7528\u7D20\n    int copy_rec(int t, int u, long long\
    \ a, long long b, long long l, long long r, const F& f) const {\n        if (r\
    \ <= a || b <= l) return t;\n        if (l <= a && b <= r) return apply_node(u,\
    \ a, b, f);\n        long long mid = (a + b) / 2;\n        auto [lc, rc] = push(t,\
    \ a, b);\n        F g = composition(f, pool->lazy[u]);\n        lc = copy_rec(lc,\
    \ pool->left[u], a, mid, l, r, g);\n        rc = copy_rec(rc, pool->right[u],\
    \ mid, b, l, r, g);\n        return pool->make_node(lc, rc);\n    }\n    // f\
    \ \u306F\u30CE\u30FC\u30C9 t \u306E\u7956\u5148\u306B\u3042\u3063\u3066\u3001\u307E\
    \u3060 t \u306B\u9069\u7528\u3057\u3066\u3044\u306A\u3044\u4F5C\u7528\u7D20\n\
    \    S prod_rec(int t, long long a, long long b, long long l, long long r, const\
    \ F& f) const {\n        if (r <= a || b <= l) return e();\n        if (l <= a\
    \ && b <= r) return mapping(f, pool->val[t], a, b);\n        long long mid = (a\
    \ + b) / 2;\n        F g = composition(f, pool->lazy[t]);\n        return op(prod_rec(pool->left[t],\
    \ a, mid, l, r, g), prod_rec(pool->right[t], mid, b, l, r, g));\n    }\n    //\
    \ [a, b) \u306E\u3046\u3061 l \u4EE5\u964D\u3067\u3001sum \u306B\u639B\u3051\u308B\
    \u3068 g \u304C\u507D\u306B\u306A\u308B\u6700\u521D\u306E\u4F4D\u7F6E (\u306A\u3051\
    \u308C\u3070 b)\n    template <typename G>\n    long long max_right_rec(int t,\
    \ long long a, long long b, long long l, G& g, S& sum, const F& f) const {\n \
    \       if (b <= l) return b;\n        if (l <= a) {\n            S s = op(sum,\
    \ mapping(f, pool->val[t], a, b));\n            if (g(s)) {\n                sum\
    \ = s;\n                return b;\n            }\n            if (b - a == 1)\
    \ return a;\n        }\n        long long mid = (a + b) / 2;\n        F h = composition(f,\
    \ pool->lazy[t]);\n        long long x = max_right_rec(pool->left[t], a, mid,\
    \ l, g, sum, h);\n        if (x < mid) return x;\n        return max_right_rec(pool->right[t],\
    \ mid, b, l, g, sum, h);\n    }\n    // [a, b) \u306E\u3046\u3061 r \u3088\u308A\
    \u524D\u3067\u3001sum \u306B\u5DE6\u304B\u3089\u639B\u3051\u308B\u3068 g \u304C\
    \u507D\u306B\u306A\u308B\u6700\u5F8C\u306E\u4F4D\u7F6E + 1 (\u306A\u3051\u308C\
    \u3070 a)\n    template <typename G>\n    long long min_left_rec(int t, long long\
    \ a, long long b, long long r, G& g, S& sum, const F& f) const {\n        if (r\
    \ <= a) return a;\n        if (b <= r) {\n            S s = op(mapping(f, pool->val[t],\
    \ a, b), sum);\n            if (g(s)) {\n                sum = s;\n          \
    \      return a;\n            }\n            if (b - a == 1) return b;\n     \
    \   }\n        long long mid = (a + b) / 2;\n        F h = composition(f, pool->lazy[t]);\n\
    \        long long x = min_left_rec(pool->right[t], mid, b, r, g, sum, h);\n \
    \       if (x > mid) return x;\n        return min_left_rec(pool->left[t], a,\
    \ mid, r, g, sum, h);\n    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u3092\u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\u3059\u308B\u3002\u5358\u4F4D\
    \u5143\u306E\u90E8\u5206\u6728\u306F\u5171\u6709\u3059\u308B\u306E\u3067\u3001\
    n \u304C\u5927\u304D\u304F\u3066\u3082 O(log n) \u3067\u4F5C\u308C\u308B\n   \
    \  *\n     * @param n \u8981\u7D20\u6570\n     * @param a \u4F5C\u7528\u7D20\u4ED8\
    \u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit PersistentLazySegTree(long\
    \ long n = 0, A a = A()) : pool(std::make_shared<Pool>(std::move(a))), n(n) {\n\
    \        assert(0 <= n);\n        init_size();\n        root = pool->make_leaf(e());\n\
    \        for (long long w = 1; w < sz; w <<= 1) root = pool->make_node(root, root);\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param a \u4F5C\u7528\
    \u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n#if __cplusplus >= 202002L\n\
    \    template <class R = std::initializer_list<S>>\n        requires internal_traits::sized_constructible_range<R,\
    \ S>\n#else\n    template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit PersistentLazySegTree(R&& v, A a = A()) :\
    \ pool(std::make_shared<Pool>(std::move(a))), n(internal_traits::range_size(v))\
    \ {\n        init_size();\n        auto it = internal_traits::range_begin(v);\n\
    \        root = build(it, 0, sz);\n    }\n\n    /**\n     * @brief \u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\n     */\n    long long size() const { return n; }\n\n\
    \    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\
    \u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @return S \u5024\n     */\n    S get(long long k) const {\n        assert(0\
    \ <= k && k < n);\n        int t = root;\n        long long a = 0, b = sz;\n \
    \       F f = id();\n        while (b - a > 1) {\n            f = composition(f,\
    \ pool->lazy[t]);\n            long long mid = (a + b) / 2;\n            if (k\
    \ < mid) {\n                t = pool->left[t];\n                b = mid;\n   \
    \         } else {\n                t = pool->right[t];\n                a = mid;\n\
    \            }\n        }\n        return mapping(f, pool->val[t], a, b);\n  \
    \  }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\
    \u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @return S \u5024\n     */\n    S operator[](long long k) const { return\
    \ get(k); }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\
    \n     *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\
    \u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n     * @return std::basic_ostream<CharT,\
    \ Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     */\n    template <class\
    \ CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const PersistentLazySegTree& rhs) {\n        for (long long i =\
    \ 0; i < rhs.n; i++) {\n            if (i != 0) os << CharT(' ');\n          \
    \  os << rhs[i];\n        }\n        return os;\n    }\n\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u3057\u305F\
    \u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\u3057\u3044\u5024\n     * @return\
    \ PersistentLazySegTree \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\
    \u3089\u306A\u3044)\n     */\n    PersistentLazySegTree set(long long k, const\
    \ S& x) const {\n        assert(0 <= k && k < n);\n        return PersistentLazySegTree(pool,\
    \ n, sz, set_rec(root, 0, sz, k, x));\n    }\n\n    /**\n     * @brief [l, r)\u306E\
    \u533A\u9593\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\
    \u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\
    \u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(long\
    \ long l, long long r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        return prod_rec(root, 0, sz, l, r, id());\n    }\n    /**\n     * @brief\
    \ \u3059\u3079\u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n \
    \    *\n     * @return S \u7DCF\u7A4D\n     */\n    S all_prod() const { return\
    \ pool->val[root]; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\
    \u7D20\u306E\u5024\u306Bf\u3092\u4F5C\u7528\u3055\u305B\u305F\u65B0\u3057\u3044\
    \u7248\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\n     * @param f \u4F5C\u7528\u7D20\n     * @return PersistentLazySegTree\
    \ \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n\
    \     */\n    PersistentLazySegTree apply(long long k, const F& f) const {\n \
    \       assert(0 <= k && k < n);\n        return apply(k, k + 1, f);\n    }\n\
    \    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\u5024\u306Bf\u3092\u4F5C\
    \u7528\u3055\u305B\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n \
    \    * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\
    \u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @param f \u4F5C\u7528\u7D20\
    \n     * @return PersistentLazySegTree \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\
    \u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentLazySegTree apply(long\
    \ long l, long long r, const F& f) const {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        if (l == r) return *this;\n        return PersistentLazySegTree(pool,\
    \ n, sz, apply_rec(root, 0, sz, l, r, f));\n    }\n\n    /**\n     * @brief [l,\
    \ r)\u306E\u533A\u9593\u3092\u5225\u306E\u7248\u306E\u5024\u306B\u3057\u305F\u65B0\
    \u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param other \u5199\u3059\
    \u5143\u306E\u7248 (\u81EA\u8EAB\u3068\u540C\u3058\u6728\u304B\u3089\u4F5C\u3063\
    \u305F\u3082\u306E)\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n    \
    \ * @return PersistentLazySegTree \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u3082\
    \ other \u3082\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentLazySegTree\
    \ copy(const PersistentLazySegTree& other, long long l, long long r) const {\n\
    \        assert(pool == other.pool);\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        if (l == r) return *this;\n        return PersistentLazySegTree(pool,\
    \ n, sz, copy_rec(root, other.root, 0, sz, l, r, id()));\n    }\n\n    /**\n \
    \    * @brief (r = l or g(prod([l, r))) = true) and (r = n or g(prod([l, r+1)))\
    \ = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\n     * g\u304C\u5358\u8ABF\u306A\
    \u3089\u3001g(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n    \
    \ *\n     * @tparam G\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \ 0<=l<=n\n     * @param g \u5224\u5B9A\u95A2\u6570 g(e) = true\n     * @return\
    \ long long\n     */\n    template <typename G>\n    long long max_right(long\
    \ long l, G g) const {\n        assert(g(e()));\n        assert(0 <= l && l <=\
    \ n);\n        if (l == n) return n;\n        S sum = e();\n        long long\
    \ r = max_right_rec(root, 0, sz, l, g, sum, id());\n        return r < n ? r :\
    \ n;\n    }\n    /**\n     * @brief (l = 0 or g(prod([l, r))) = true) and (l =\
    \ r or g(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\u8FD4\u3059\n     *\
    \ g\u304C\u5358\u8ABF\u306A\u3089\u3001g(prod([l, r))) = true\u3068\u306A\u308B\
    \u6700\u5C0F\u306El\n     *\n     * @tparam G\n     * @param r \u534A\u958B\u533A\
    \u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param g \u5224\u5B9A\u95A2\u6570 g(e)\
    \ = true\n     * @return long long\n     */\n    template <typename G>\n    long\
    \ long min_left(long long r, G g) const {\n        assert(g(e()));\n        assert(0\
    \ <= r && r <= n);\n        if (r == 0) return 0;\n        S sum = e();\n    \
    \    return min_left_rec(root, 0, sz, r, g, sum, id());\n    }\n\n    /**\n  \
    \   * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u4E26\u3079\u305F\u5217\
    \u3092\u8FD4\u3059\n     */\n    std::vector<S> to_vector() const {\n        std::vector<S>\
    \ res(n);\n        for (long long i = 0; i < n; i++) res[i] = get(i);\n      \
    \  return res;\n    }\n};\n\ntemplate <typename A>\nPersistentLazySegTree(long\
    \ long, A) -> PersistentLazySegTree<A>;\ntemplate <class R, typename A>\nPersistentLazySegTree(R&&,\
    \ A) -> PersistentLazySegTree<A>;\ntemplate <typename A>\nPersistentLazySegTree(std::initializer_list<typename\
    \ A::S>, A) -> PersistentLazySegTree<A>;\n#line 2 \"src/data_structures/persistent-segtree.hpp\"\
    \n\n/**\n * @file persistent-segtree.hpp\n * @brief \u6C38\u7D9A\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n */\n\n#line 15 \"src/data_structures/persistent-segtree.hpp\"\
    \n\n#line 18 \"src/data_structures/persistent-segtree.hpp\"\n\n/**\n * @brief\
    \ \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u66F4\u65B0\u3059\u308B\
    \u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\u306E\u7248\u306F\
    \u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u6728\u304B\u3089\u4F5C\u3063\
    \u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\u3059\u308B\n * \u4F8B\
    :\n * PersistentSegTree<monoid::Sum<long long>> s0(n);\n * auto s1 = s0.set(3,\
    \ 10);  // s0 \u306F\u305D\u306E\u307E\u307E\n * s1.prod(0, 5);            //\
    \ 10\n *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n */\ntemplate\
    \ <typename M>\nclass PersistentSegTree {\n   public:\n    using S = typename\
    \ M::S;\n\n   private:\n    // \u3059\u3079\u3066\u306E\u7248\u306E\u30CE\u30FC\
    \u30C9\u3092\u6301\u3064\u3002\u30CE\u30FC\u30C9\u306F\u524A\u9664\u3057\u306A\
    \u3044\n    struct Pool {\n        M m;\n        std::vector<S> val;\n       \
    \ std::vector<int> left, right;  // \u8449\u3067\u306F -1\n        explicit Pool(M\
    \ m) : m(std::move(m)) {}\n        int make_leaf(const S& x) {\n            val.push_back(x);\n\
    \            left.push_back(-1);\n            right.push_back(-1);\n         \
    \   return static_cast<int>(val.size()) - 1;\n        }\n        int make_node(int\
    \ l, int r) {\n            val.push_back(m.op(val[l], val[r]));\n            left.push_back(l);\n\
    \            right.push_back(r);\n            return static_cast<int>(val.size())\
    \ - 1;\n        }\n    };\n\n    std::shared_ptr<Pool> pool;\n    long long n,\
    \ sz;\n    int root;\n\n    S op(const S& a, const S& b) const { return pool->m.op(a,\
    \ b); }\n    S e() const { return pool->m.e(); }\n\n    PersistentSegTree(std::shared_ptr<Pool>\
    \ pool, long long n, long long sz, int root) : pool(std::move(pool)), n(n), sz(sz),\
    \ root(root) {}\n\n    void init_size() {\n        sz = 1;\n        while (sz\
    \ < n) sz <<= 1;\n    }\n    template <class It>\n    int build(It& it, long long\
    \ a, long long b) {\n        if (b - a == 1) {\n            if (a >= n) return\
    \ pool->make_leaf(e());\n            S x(*it);\n            ++it;\n          \
    \  return pool->make_leaf(x);\n        }\n        long long mid = (a + b) / 2;\n\
    \        int l = build(it, a, mid);\n        int r = build(it, mid, b);\n    \
    \    return pool->make_node(l, r);\n    }\n    int set_rec(int t, long long a,\
    \ long long b, long long k, const S& x) const {\n        if (b - a == 1) return\
    \ pool->make_leaf(x);\n        long long mid = (a + b) / 2;\n        int l = pool->left[t],\
    \ r = pool->right[t];\n        if (k < mid)\n            l = set_rec(l, a, mid,\
    \ k, x);\n        else\n            r = set_rec(r, mid, b, k, x);\n        return\
    \ pool->make_node(l, r);\n    }\n    // t \u306E [l, r) \u3092 u \u306B\u7F6E\u304D\
    \u63DB\u3048\u308B\n    int copy_rec(int t, int u, long long a, long long b, long\
    \ long l, long long r) const {\n        if (r <= a || b <= l) return t;\n    \
    \    if (l <= a && b <= r) return u;\n        long long mid = (a + b) / 2;\n \
    \       int lc = copy_rec(pool->left[t], pool->left[u], a, mid, l, r);\n     \
    \   int rc = copy_rec(pool->right[t], pool->right[u], mid, b, l, r);\n       \
    \ return pool->make_node(lc, rc);\n    }\n    S prod_rec(int t, long long a, long\
    \ long b, long long l, long long r) const {\n        if (r <= a || b <= l) return\
    \ e();\n        if (l <= a && b <= r) return pool->val[t];\n        long long\
    \ mid = (a + b) / 2;\n        return op(prod_rec(pool->left[t], a, mid, l, r),\
    \ prod_rec(pool->right[t], mid, b, l, r));\n    }\n    // [a, b) \u306E\u3046\u3061\
    \ l \u4EE5\u964D\u3067\u3001sum \u306B\u639B\u3051\u308B\u3068 f \u304C\u507D\u306B\
    \u306A\u308B\u6700\u521D\u306E\u4F4D\u7F6E (\u306A\u3051\u308C\u3070 b)\n    template\
    \ <typename F>\n    long long max_right_rec(int t, long long a, long long b, long\
    \ long l, F& f, S& sum) const {\n        if (b <= l) return b;\n        if (l\
    \ <= a) {\n            S s = op(sum, pool->val[t]);\n            if (f(s)) {\n\
    \                sum = s;\n                return b;\n            }\n        \
    \    if (b - a == 1) return a;\n        }\n        long long mid = (a + b) / 2;\n\
    \        long long x = max_right_rec(pool->left[t], a, mid, l, f, sum);\n    \
    \    if (x < mid) return x;\n        return max_right_rec(pool->right[t], mid,\
    \ b, l, f, sum);\n    }\n    // [a, b) \u306E\u3046\u3061 r \u3088\u308A\u524D\
    \u3067\u3001sum \u306B\u5DE6\u304B\u3089\u639B\u3051\u308B\u3068 f \u304C\u507D\
    \u306B\u306A\u308B\u6700\u5F8C\u306E\u4F4D\u7F6E + 1 (\u306A\u3051\u308C\u3070\
    \ a)\n    template <typename F>\n    long long min_left_rec(int t, long long a,\
    \ long long b, long long r, F& f, S& sum) const {\n        if (r <= a) return\
    \ a;\n        if (b <= r) {\n            S s = op(pool->val[t], sum);\n      \
    \      if (f(s)) {\n                sum = s;\n                return a;\n    \
    \        }\n            if (b - a == 1) return b;\n        }\n        long long\
    \ mid = (a + b) / 2;\n        long long x = min_left_rec(pool->right[t], mid,\
    \ b, r, f, sum);\n        if (x > mid) return x;\n        return min_left_rec(pool->left[t],\
    \ a, mid, r, f, sum);\n    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u3092\u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\u3059\u308B\u3002\u5358\u4F4D\
    \u5143\u306E\u90E8\u5206\u6728\u306F\u5171\u6709\u3059\u308B\u306E\u3067\u3001\
    n \u304C\u5927\u304D\u304F\u3066\u3082 O(log n) \u3067\u4F5C\u308C\u308B\n   \
    \  *\n     * @param n \u8981\u7D20\u6570\n     * @param m \u30E2\u30CE\u30A4\u30C9\
    \n     */\n    explicit PersistentSegTree(long long n = 0, M m = M()) : pool(std::make_shared<Pool>(std::move(m))),\
    \ n(n) {\n        assert(0 <= n);\n        init_size();\n        root = pool->make_leaf(e());\n\
    \        for (long long w = 1; w < sz; w <<= 1) root = pool->make_node(root, root);\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param m \u30E2\u30CE\
    \u30A4\u30C9\n     */\n#if __cplusplus >= 202002L\n    template <class R = std::initializer_list<S>>\n\
    \        requires internal_traits::sized_constructible_range<R, S>\n#else\n  \
    \  template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit PersistentSegTree(R&& v, M m = M()) : pool(std::make_shared<Pool>(std::move(m))),\
    \ n(internal_traits::range_size(v)) {\n        init_size();\n        auto it =\
    \ internal_traits::range_begin(v);\n        root = build(it, 0, sz);\n    }\n\n\
    \    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long\
    \ long size() const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n \
    \   S get(long long k) const {\n        assert(0 <= k && k < n);\n        int\
    \ t = root;\n        long long a = 0, b = sz;\n        while (b - a > 1) {\n \
    \           long long mid = (a + b) / 2;\n            if (k < mid) {\n       \
    \         t = pool->left[t];\n                b = mid;\n            } else {\n\
    \                t = pool->right[t];\n                a = mid;\n            }\n\
    \        }\n        return pool->val[t];\n    }\n    /**\n     * @brief \u6307\
    \u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n \
    \    * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n\
    \     */\n    S operator[](long long k) const { return get(k); }\n\n    /**\n\
    \     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n     *\n     * @tparam\
    \ CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n \
    \    * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\
    \u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n     * @param rhs \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n     * @return\
    \ std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const PersistentSegTree&\
    \ rhs) {\n        for (long long i = 0; i < rhs.n; i++) {\n            if (i !=\
    \ 0) os << CharT(' ');\n            os << rhs[i];\n        }\n        return os;\n\
    \    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u3092x\u306B\u3057\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n  \
    \   *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\
    \u3057\u3044\u5024\n     * @return PersistentSegTree \u65B0\u3057\u3044\u7248\
    \ (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentSegTree\
    \ set(long long k, const S& x) const {\n        assert(0 <= k && k < n);\n   \
    \     return PersistentSegTree(pool, n, sz, set_rec(root, 0, sz, k, x));\n   \
    \ }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\
    \u306Bx\u3092\u4F5C\u7528\u3055\u305B\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\
    \u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param\
    \ x \u4F5C\u7528\u7D20\n     * @return PersistentSegTree \u65B0\u3057\u3044\u7248\
    \ (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentSegTree\
    \ apply(long long k, const S& x) const { return set(k, op(get(k), x)); }\n\n \
    \   /**\n     * @brief [l, r)\u306E\u533A\u9593\u3092\u5225\u306E\u7248\u306E\u5024\
    \u306B\u3057\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param\
    \ other \u5199\u3059\u5143\u306E\u7248 (\u81EA\u8EAB\u3068\u540C\u3058\u6728\u304B\
    \u3089\u4F5C\u3063\u305F\u3082\u306E)\n     * @param l \u534A\u958B\u533A\u9593\
    \u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \ 0<=l<=r<=n\n     * @return PersistentSegTree \u65B0\u3057\u3044\u7248 (\u81EA\
    \u8EAB\u3082 other \u3082\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentSegTree\
    \ copy(const PersistentSegTree& other, long long l, long long r) const {\n   \
    \     assert(pool == other.pool);\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r) return *this;\n        return PersistentSegTree(pool, n,\
    \ sz, copy_rec(root, other.root, 0, sz, l, r));\n    }\n\n    /**\n     * @brief\
    \ [l, r)\u306E\u533A\u9593\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     *\
    \ @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\
    \u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n   \
    \  */\n    S prod(long long l, long long r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        return prod_rec(root, 0, sz, l, r);\n    }\n   \
    \ /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\
    \u8FD4\u3059\n     *\n     * @return S \u7DCF\u7A4D\n     */\n    S all_prod()\
    \ const { return pool->val[root]; }\n\n    /**\n     * @brief (r = l or f(prod([l,\
    \ r))) = true) and (r = n or f(prod([l, r+1))) = false)\u3068\u306A\u308Br\u3092\
    \u8FD4\u3059\n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001f(prod([l, r))) = true\u3068\
    \u306A\u308B\u6700\u5927\u306Er\n     *\n     * @tparam F\n     * @param l \u534A\
    \u958B\u533A\u9593\u306E\u958B\u59CB 0<=l<=n\n     * @param f \u5224\u5B9A\u95A2\
    \u6570 f(e) = true\n     * @return long long\n     */\n    template <typename\
    \ F>\n    long long max_right(long long l, F f) const {\n        assert(f(e()));\n\
    \        assert(0 <= l && l <= n);\n        if (l == n) return n;\n        S sum\
    \ = e();\n        long long r = max_right_rec(root, 0, sz, l, f, sum);\n     \
    \   return r < n ? r : n;\n    }\n    /**\n     * @brief (l = 0 or f(prod([l,\
    \ r))) = true) and (l = r or f(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\
    \u8FD4\u3059\n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001f(prod([l, r))) = true\u3068\
    \u306A\u308B\u6700\u5C0F\u306El\n     *\n     * @tparam F\n     * @param r \u534A\
    \u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param f \u5224\u5B9A\u95A2\
    \u6570 f(e) = true\n     * @return long long\n     */\n    template <typename\
    \ F>\n    long long min_left(long long r, F f) const {\n        assert(f(e()));\n\
    \        assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        S sum\
    \ = e();\n        return min_left_rec(root, 0, sz, r, f, sum);\n    }\n\n    /**\n\
    \     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u4E26\u3079\u305F\u5217\
    \u3092\u8FD4\u3059\n     */\n    std::vector<S> to_vector() const {\n        std::vector<S>\
    \ res(n);\n        for (long long i = 0; i < n; i++) res[i] = get(i);\n      \
    \  return res;\n    }\n};\n\ntemplate <typename M>\nPersistentSegTree(long long,\
    \ M) -> PersistentSegTree<M>;\ntemplate <class R, typename M>\nPersistentSegTree(R&&,\
    \ M) -> PersistentSegTree<M>;\ntemplate <typename M>\nPersistentSegTree(std::initializer_list<typename\
    \ M::S>, M) -> PersistentSegTree<M>;\n#line 2 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n\n/**\n * @file potentialized-unionfind.hpp\n * @brief \u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\u4ED8\u304DUnionFind\n */\n#line 8 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n#include <stack>\n#line 11 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n\n#line 14 \"src/data_structures/potentialized-unionfind.hpp\"\n\n/**\n * @brief\
    \ \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind\n * @tparam G \u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u7FA4 (algebra/group.hpp) \u975E\u53EF\u63DB\
    \u3067\u3082\u3088\u3044\n */\ntemplate <typename G>\nclass PotentializedUnionFind\
    \ {\n   public:\n    using S = typename G::S;\n    using MergeResult = UnionFind::MergeResult;\n\
    \n   private:\n    G g;\n    long long _n;\n    // \u8CA0\u306A\u3089\u30B5\u30A4\
    \u30BA\u3001\u975E\u8CA0\u306A\u3089\u89AA (\u30E1\u30E2\u30EA\u3092\u6291\u3048\
    \u308B\u305F\u3081 int \u3067\u6301\u3064)\n    std::vector<int> parent_or_size;\n\
    \    // \u91CD\u307F\n    std::vector<S> diff_weight;\n\n    S op(const S& a,\
    \ const S& b) const { return g.op(a, b); }\n    S e() const { return g.e(); }\n\
    \    S inv(const S& a) const { return g.inv(a); }\n\n   public:\n    /**\n   \
    \  * @param n \u8981\u7D20\u6570\n     * @param g \u30DD\u30C6\u30F3\u30B7\u30E3\
    \u30EB\u306E\u7FA4\n     */\n    explicit PotentializedUnionFind(long long n =\
    \ 0, G g = G()) : g(std::move(g)), _n(n), parent_or_size(n, -1), diff_weight(n,\
    \ e()) {}\n\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\
    \u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    long long leader(long\
    \ long a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a]\
    \ < 0) return a;\n        std::stack<int> stk;\n        stk.push(static_cast<int>(a));\n\
    \        while (parent_or_size[stk.top()] >= 0) {\n            stk.push(parent_or_size[stk.top()]);\n\
    \        }\n        const int root = stk.top();\n        stk.pop();\n        stk.pop();\n\
    \        while (!stk.empty()) {\n            diff_weight[stk.top()] = op(diff_weight[parent_or_size[stk.top()]],\
    \ diff_weight[stk.top()]);\n            parent_or_size[stk.top()] = root;\n  \
    \          stk.pop();\n        }\n        return root;\n    }\n\n    /**\n   \
    \  * @brief a \u306E\u30B0\u30EB\u30FC\u30D7\u3068 b \u306E\u30B0\u30EB\u30FC\u30D7\
    \u3092\u7D71\u5408\u3059\u308B\n     * @param w (b \u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB) - (a \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)\n     * @return\
    \ \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\
    \u5408\u3057\u305F\u304B\n     * @note \u3059\u3067\u306B\u540C\u3058\u9023\u7D50\
    \u6210\u5206\u306A\u3089\u4F55\u3082\u3057\u306A\u3044 (w \u304C\u77DB\u76FE\u3057\
    \u3066\u3044\u3066\u3082\u691C\u51FA\u3057\u306A\u3044)\u3002\n     *       \u77DB\
    \u76FE\u3092\u8ABF\u3079\u308B\u306B\u306F\u3001merged \u304C false \u306E\u3068\
    \u304D\u306B diff(a, b) == w \u304B\u3092\u78BA\u304B\u3081\u308B\n     */\n \
    \   MergeResult merge(long long a, long long b, S w) {\n        assert(0 <= a\
    \ && a < _n);\n        assert(0 <= b && b < _n);\n        w = op(weight(a), w);\n\
    \        w = op(w, inv(weight(b)));\n        long long x = leader(a), y = leader(b);\n\
    \        if (x == y) return {x, false};\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ {\n            std::swap(x, y);\n            w = inv(w);\n        }\n      \
    \  parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] = static_cast<int>(x);\n\
    \        diff_weight[y] = w;\n        return {x, true};\n    }\n\n    /**\n  \
    \   * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\u304B\n     */\n\
    \    bool same(long long a, long long b) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n \
    \   }\n\n    /**\n     * @brief (b \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    ) - (a \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)\n     */\n    S diff(long long\
    \ a, long long b) {\n        assert(same(a, b));\n        return op(inv(weight(a)),\
    \ weight(b));\n    }\n\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\
    \u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\n     */\n    long long\
    \ size(long long a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\
    \u306B\u5206\u3051\u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return\
    \ \u300C\u4E00\u3064\u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\
    \u306E\u30EA\u30B9\u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<long\
    \ long>> groups() {\n        return internal_unionfind::groups(_n, [&](long long\
    \ a) { return leader(a); });\n    }\n\n   private:\n    S weight(long long a)\
    \ {\n        leader(a);\n        return diff_weight[a];\n    }\n};\n\ntemplate\
    \ <typename G>\nPotentializedUnionFind(long long, G) -> PotentializedUnionFind<G>;\n\
    #line 2 \"src/data_structures/rbst.hpp\"\n\n/**\n * @file rbst.hpp\n * @brief\
    \ \u5E73\u8861\u4E8C\u5206\u6728 (RBST) \u306B\u3088\u308B\u5217\n */\n\n#line\
    \ 10 \"src/data_structures/rbst.hpp\"\n#include <cstdint>\n#line 16 \"src/data_structures/rbst.hpp\"\
    \n\n#line 19 \"src/data_structures/rbst.hpp\"\n\nnamespace internal_rbst {\n#if\
    \ __cplusplus < 202002L\ntemplate <typename M, typename = void>\nstruct has_acted\
    \ : std::false_type {};\ntemplate <typename M>\nstruct has_acted<M, std::void_t<typename\
    \ M::F>> : std::true_type {};\n#endif\n// \u4F5C\u7528\u7D20\u4ED8\u304D\u3067\
    \u306A\u3044\u30E2\u30CE\u30A4\u30C9\u306E\u3068\u304D\u306E\u4F5C\u7528\u7D20\
    \u306E\u578B\nstruct NoAct {\n    using F = NoAct;\n};\n}  // namespace internal_rbst\n\
    \n/**\n * @brief \u5E73\u8861\u4E8C\u5206\u6728 (RBST) \u306B\u3088\u308B\u5217\
    \n *\n * \u4F4D\u7F6E\u3067\u6271\u3046\u5217\u3002k \u756A\u76EE\u3078\u306E\u633F\
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
    #if __cplusplus >= 202002L\n    static constexpr bool acted = requires { typename\
    \ M::F; };\n#else\n    static constexpr bool acted = internal_rbst::has_acted<M>::value;\n\
    #endif\n    using F = typename std::conditional_t<acted, M, internal_rbst::NoAct>::F;\n\
    \n   private:\n#if __cplusplus >= 202002L\n    static_assert(!acted || !requires(const\
    \ M& m, const F& f, const S& x) { m.mapping(f, x, 0LL, 0LL); }, \"RBST: mapping(f,\
    \ x, l, r) \u306F\u4F7F\u3048\u306A\u3044\");\n#else\n    static_assert(!acted\
    \ || !internal_acted_monoid::has_mapping_lr<M>::value, \"RBST: mapping(f, x, l,\
    \ r) \u306F\u4F7F\u3048\u306A\u3044\");\n#endif\n\n    // \u9802\u70B9 0 \u306F\
    \u7A7A\u306E\u6728\u3092\u8868\u3059\n    struct Node {\n        S val, sum, rsum;\
    \  // \u5024\u3001\u90E8\u5206\u6728\u306E\u7A4D\u3001\u90E8\u5206\u6728\u306E\
    \u9006\u9806\u306E\u7A4D\n        F lz;              // \u5B50\u306B\u4F1D\u3048\
    \u308B\u4F5C\u7528\u7D20\n        int sz = 0, l = 0, r = 0;\n        bool has_lz\
    \ = false, rev = false;  // \u5B50\u306B\u4F5C\u7528\u7D20\u30FB\u53CD\u8EE2\u3092\
    \u4F1D\u3048\u3066\u3044\u306A\u3044\u304B\n    };\n    // \u9802\u70B9\u306E\u914D\
    \u5217\u306F\u6700\u521D\u306B\u9802\u70B9\u3092\u4F5C\u308B\u3068\u304D\u306B\
    \u78BA\u4FDD\u3057\u3001\u89E3\u653E\u3057\u306A\u3044\n    // (\u30B0\u30ED\u30FC\
    \u30D0\u30EB\u5909\u6570\u306E\u6728\u306E\u30C7\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u304C\u3001\u5148\u306B\u7834\u68C4\u3055\u308C\u305F\u914D\u5217\u3092\u89E6\
    \u3089\u306A\u3044\u3088\u3046\u306B\u3059\u308B)\n    inline static std::vector<Node>*\
    \ nodes_ = nullptr;\n    inline static std::vector<int>* unused_ = nullptr;  //\
    \ \u6D88\u3057\u305F\u9802\u70B9\n    static Node& node(int t) { return (*nodes_)[t];\
    \ }\n    static std::uint32_t rand() {\n        static std::uint32_t x = 2463534242U;\n\
    \        x ^= x << 13;\n        x ^= x >> 17;\n        x ^= x << 5;\n        return\
    \ x;\n    }\n\n    M m;\n    int root = 0;\n\n    S op(const S& x, const S& y)\
    \ const { return m.op(x, y); }\n    S e() const { return m.e(); }\n    static\
    \ int size_of(int t) { return t ? node(t).sz : 0; }\n    S sum_of(int t) const\
    \ { return t ? node(t).sum : e(); }\n    S rsum_of(int t) const { return t ? node(t).rsum\
    \ : e(); }\n\n    // x \u306F\u5024\u3067\u53D7\u3051\u53D6\u308B (\u9802\u70B9\
    \u306E\u914D\u5217\u306E\u8981\u7D20\u3092\u6E21\u3055\u308C\u305F\u3068\u304D\
    \u3001\u914D\u5217\u304C\u4F38\u3073\u3066\u53C2\u7167\u304C\u7121\u52B9\u306B\
    \u306A\u308B\u306E\u3092\u9632\u3050)\n    int new_node(S x) {\n        if (!nodes_)\
    \ nodes_ = new std::vector<Node>(1), unused_ = new std::vector<int>();\n     \
    \   int t;\n        if (!unused_->empty()) {\n            t = unused_->back();\n\
    \            unused_->pop_back();\n        } else {\n            t = nodes_->size();\n\
    \            nodes_->emplace_back();\n        }\n        Node& v = node(t);\n\
    \        v.val = v.sum = v.rsum = x;\n        v.has_lz = v.rev = false;\n    \
    \    v.sz = 1, v.l = v.r = 0;\n        return t;\n    }\n    // \u90E8\u5206\u6728\
    \u306E\u9802\u70B9\u3092\u3059\u3079\u3066\u6D88\u3059\n    static void free_tree(int\
    \ t) {\n        if (!t) return;\n        std::vector<int> st = {t};\n        while\
    \ (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \            if (node(v).l) st.push_back(node(v).l);\n            if (node(v).r)\
    \ st.push_back(node(v).r);\n            unused_->push_back(v);\n        }\n  \
    \  }\n    int clone_tree(int t) {\n        if (!t) return 0;\n        push(t);\n\
    \        int lc = clone_tree(node(t).l);\n        int c = new_node(node(t).val);\n\
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
    \   template <class It>\n    int build(It& it, int lo, int hi) {\n        if (lo\
    \ >= hi) return 0;\n        int mid = (lo + hi) / 2;\n        int lc = build(it,\
    \ lo, mid);\n        int t = new_node(S(*it));\n        ++it;\n        int rc\
    \ = build(it, mid + 1, hi);\n        node(t).l = lc, node(t).r = rc;\n       \
    \ update(t);\n        return t;\n    }\n    // [l, r) \u3092\u53D6\u308A\u51FA\
    \u3057\u3066 f \u3092\u4F5C\u7528\u3055\u305B\u3001\u5143\u306B\u623B\u3059\n\
    \    template <typename Fn>\n    auto with_range(long long l, long long r, Fn\
    \ fn) {\n        assert(0 <= l && l <= r && r <= size());\n        auto [a, bc]\
    \ = split_node(root, static_cast<int>(l));\n        auto [b, c] = split_node(bc,\
    \ static_cast<int>(r - l));\n        if constexpr (std::is_void_v<decltype(fn(b))>)\
    \ {\n            fn(b);\n            root = merge_node(merge_node(a, b), c);\n\
    \        } else {\n            auto res = fn(b);\n            root = merge_node(merge_node(a,\
    \ b), c);\n            return res;\n        }\n    }\n    void to_vector(int t,\
    \ std::vector<S>& res) {\n        if (!t) return;\n        push(t);\n        to_vector(node(t).l,\
    \ res);\n        res.push_back(node(t).val);\n        to_vector(node(t).r, res);\n\
    \    }\n\n    class RBSTReference {\n        RBST& t;\n        long long k;\n\n\
    \       public:\n        RBSTReference(RBST& t, long long k) : t(t), k(k) {}\n\
    \        RBSTReference& operator=(const S& x) {\n            t.set(k, x);\n  \
    \          return *this;\n        }\n        operator S() { return t.get(k); }\n\
    \    };\n\n    struct FromRoot {};\n    RBST(int root, const M& m, FromRoot) :\
    \ m(m), root(root) {}\n\n   public:\n    /**\n     * @brief \u7A7A\u306E\u5217\
    \n     */\n    explicit RBST(M m = M()) : m(std::move(m)) {}\n    /**\n     *\
    \ @brief \u9577\u3055 n \u3067\u3001\u3059\u3079\u3066\u5358\u4F4D\u5143\u306E\
    \u5217\n     */\n    explicit RBST(long long n, M m = M()) : RBST(std::vector<S>(n,\
    \ m.e()), m) {}\n    /**\n     * @brief v \u306E\u5217 O(n)\n     */\n#if __cplusplus\
    \ >= 202002L\n    template <class R = std::initializer_list<S>>\n        requires\
    \ internal_traits::sized_constructible_range<R, S>\n#else\n    template <class\
    \ R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit RBST(R&& v, M m = M()) : m(std::move(m)) {\n\
    \        auto it = internal_traits::range_begin(v);\n        root = build(it,\
    \ 0, static_cast<int>(internal_traits::range_size(v)));\n    }\n\n    /**\n  \
    \   * @brief \u8907\u88FD\u3059\u308B O(n)\n     */\n    RBST(const RBST& o) :\
    \ m(o.m) { root = const_cast<RBST&>(o).clone_tree(o.root); }\n    RBST(RBST&&\
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
    \    }\n};\n\ntemplate <class R, typename M>\nRBST(R&&, M) -> RBST<M>;\ntemplate\
    \ <typename M>\nRBST(std::initializer_list<typename M::S>, M) -> RBST<M>;\n#line\
    \ 2 \"src/data_structures/segtree-beats.hpp\"\n\n/**\n * @file segtree-beats.hpp\n\
    \ * @brief Segment Tree Beats\n */\n\n#line 12 \"src/data_structures/segtree-beats.hpp\"\
    \n#include <tuple>\n#line 16 \"src/data_structures/segtree-beats.hpp\"\n\n#line\
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
    \n}  // namespace beats_acted_monoid\n#line 20 \"src/data_structures/segtree-beats.hpp\"\
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
    \ a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n#if __cplusplus\
    \ >= 202002L\n    template <class R = std::initializer_list<S>>\n        requires\
    \ internal_traits::sized_constructible_range<R, S>\n#else\n    template <class\
    \ R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit SegTreeBeats(R&& v, A a = A()) : SegTreeBeats(internal_traits::range_size(v),\
    \ std::move(a)) {\n        long long k = sz;\n        for (auto&& x : v) data[k++]\
    \ = S(std::forward<decltype(x)>(x));\n        for (long long i = sz - 1; i > 0;\
    \ i--) update(i);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\n     */\n    long long size() const { return n; }\n\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n \
    \    *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S\
    \ \u5024\n     */\n    S get(long long k) {\n        assert(0 <= k && k < n);\n\
    \        k += sz;\n        for (int h = height; h > 0; h--) {\n            push(k\
    \ >> h, h);\n        }\n        return data[k];\n    }\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\
    \u3059\n     *\n     * @param k\n     * @return SegTreeReference \u8981\u7D20\u3078\
    \u306E\u53C2\u7167 \u4EE3\u5165\u3055\u308C\u308B\u3068set()\u304C\u547C\u3070\
    \u308C\u308B\n     */\n    SegTreeBeatsReference operator[](long long k) { return\
    \ SegTreeBeatsReference(*this, k); }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\
    \u51FA\u529B\u3059\u308B\n     *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param\
    \ os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n     * @return std::basic_ostream<CharT, Traits>& \u51FA\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     */\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
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
    \ long, A) -> SegTreeBeats<A>;\ntemplate <class R, typename A>\nSegTreeBeats(R&&,\
    \ A) -> SegTreeBeats<A>;\ntemplate <typename A>\nSegTreeBeats(std::initializer_list<typename\
    \ A::S>, A) -> SegTreeBeats<A>;\n\n/**\n * @brief \u533A\u9593 chmin\u3001\u533A\
    \u9593\u548C\u30FB\u6700\u5927\u5024\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RChminSumQ = SegTreeBeats<beats_acted_monoid::ChminSum<S>>;\n/**\n\
    \ * @brief \u533A\u9593 chmax\u3001\u533A\u9593\u548C\u30FB\u6700\u5C0F\u5024\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RChmaxSumQ = SegTreeBeats<beats_acted_monoid::ChmaxSum<S>>;\n\
    /**\n * @brief \u533A\u9593 chmin\u30FBchmax\u30FB\u52A0\u7B97\u30FB\u4EE3\u5165\
    \u3001\u533A\u9593\u548C\u30FB\u6700\u5927\u5024\u30FB\u6700\u5C0F\u5024\n *\n\
    \ * @tparam S \u578B\n */\ntemplate <typename S>\nusing RChminChmaxAddSumQ = SegTreeBeats<beats_acted_monoid::ChminChmaxAddSum<S>>;\n\
    #line 2 \"src/data_structures/segtree.hpp\"\n\n/**\n * @file segtree.hpp\n * @brief\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#line 15 \"src/data_structures/segtree.hpp\"\
    \n\n#line 18 \"src/data_structures/segtree.hpp\"\n\n/**\n * @brief \u30BB\u30B0\
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
    #if __cplusplus >= 202002L\n    template <class R = std::initializer_list<S>>\n\
    \        requires internal_traits::sized_constructible_range<R, S>\n#else\n  \
    \  template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit SegTree(R&& v, M m = M()) : SegTree(static_cast<long\
    \ long>(internal_traits::range_size(v)), std::move(m)) {\n        long long k\
    \ = sz;\n        for (auto&& x : v) data[k++] = S(std::forward<decltype(x)>(x));\n\
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
    \ long, M) -> SegTree<M>;\ntemplate <class R, typename M>\nSegTree(R&&, M) ->\
    \ SegTree<M>;\ntemplate <typename M>\nSegTree(std::initializer_list<typename M::S>,\
    \ M) -> SegTree<M>;\n\n/**\n * @brief RangeMaxQuery\n *\n * @tparam S \u578B\n\
    \ */\ntemplate <typename S>\nusing RMaxQ = SegTree<monoid::Max<S>>;\n/**\n * @brief\
    \ RangeMinQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RMinQ\
    \ = SegTree<monoid::Min<S>>;\n/**\n * @brief RangeSumQuery\n *\n * @tparam S \u578B\
    \n */\ntemplate <typename S>\nusing RSumQ = SegTree<monoid::Sum<S>>;\n/**\n *\
    \ @brief RangeProdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename S>\n\
    using RProdQ = SegTree<monoid::Prod<S>>;\n/**\n * @brief RangeXorQuery\n *\n *\
    \ @tparam S \u578B\n */\ntemplate <typename S>\nusing RXorQ = SegTree<monoid::Xor<S>>;\n\
    /**\n * @brief RangeGcdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RGcdQ = SegTree<monoid::Gcd<S>>;\n#line 2 \"src/data_structures/sortable-segtree.hpp\"\
    \n\n/**\n * @file sortable-segtree.hpp\n * @brief \u533A\u9593\u30BD\u30FC\u30C8\
    \u306E\u3067\u304D\u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#line 13\
    \ \"src/data_structures/sortable-segtree.hpp\"\n\n#line 2 \"src/data_structures/fast-set.hpp\"\
    \n\n/**\n * @file fast-set.hpp\n * @brief 64 \u5206\u6728\u306B\u3088\u308B\u6574\
    \u6570\u306E\u96C6\u5408 (FastSet)\n */\n\n#line 11 \"src/data_structures/fast-set.hpp\"\
    \n\n/**\n * @brief [0, n) \u306E\u6574\u6570\u306E\u96C6\u5408\u3092 64 \u5206\
    \u6728\u3067\u6301\u3064\n *\n * \u5404\u6BB5\u306F 64 bit \u306E\u914D\u5217\u3067\
    \u3001\u4E0A\u306E\u6BB5\u306E bit \u306F\u4E0B\u306E\u6BB5\u306E 64 bit \u304C\
    \ 0 \u3067\u306A\u3044\u304B\u3092\u8868\u3059\n * \u633F\u5165\u30FB\u524A\u9664\
    \u30FBx \u4EE5\u4E0A\u306E\u6700\u5C0F\u30FBx \u4EE5\u4E0B\u306E\u6700\u5927\u3092\
    \ O(log_64 n) \u3067\u884C\u3046 (n = 10^9 \u3067\u3082 5 \u6BB5\u7A0B\u5EA6)\n\
    \ * \u4F8B:\n * FastSet s(n);\n * s.insert(3); s.insert(10);\n * s.next(4);  //\
    \ 10\n * s.prev(4);  // 3\n */\nclass FastSet {\n    long long n, cnt = 0;\n \
    \   std::vector<std::vector<std::uint64_t>> seg;  // seg[0] \u304C\u8981\u7D20\
    \u306E bit\u3001seg[h + 1] \u306F seg[h] \u306E\u5404 64 bit \u304C 0 \u3067\u306A\
    \u3044\u304B\n\n    void build_levels() {\n        // 1 \u3064\u306E 64 bit \u306B\
    \u53CE\u307E\u308B\u307E\u3067\u6BB5\u3092\u91CD\u306D\u308B\n        do {\n \
    \           long long m = seg.empty() ? n : static_cast<long long>(seg.back().size());\n\
    \            seg.emplace_back((m + 63) / 64, 0);\n        } while (seg.back().size()\
    \ > 1);\n    }\n\n   public:\n    /**\n     * @brief [0, n) \u306E\u7A7A\u306E\
    \u96C6\u5408\n     */\n    explicit FastSet(long long n = 0) : n(n) {\n      \
    \  assert(n >= 0);\n        build_levels();\n    }\n    /**\n     * @brief v[i]\
    \ \u304C true \u306E i \u304B\u3089\u306A\u308B\u96C6\u5408 O(n)\n     */\n  \
    \  explicit FastSet(const std::vector<bool>& v) : FastSet(static_cast<long long>(v.size()))\
    \ {\n        for (long long i = 0; i < n; i++) {\n            if (v[i]) seg[0][i\
    \ >> 6] |= std::uint64_t(1) << (i & 63), cnt++;\n        }\n        for (int h\
    \ = 0; h + 1 < static_cast<int>(seg.size()); h++) {\n            for (long long\
    \ i = 0; i < static_cast<long long>(seg[h].size()); i++) {\n                if\
    \ (seg[h][i]) seg[h + 1][i >> 6] |= std::uint64_t(1) << (i & 63);\n          \
    \  }\n        }\n    }\n\n    /**\n     * @brief \u6271\u3048\u308B\u6574\u6570\
    \u306E\u7BC4\u56F2 [0, n) \u306E n\n     */\n    long long limit() const { return\
    \ n; }\n    /**\n     * @brief \u8981\u7D20\u6570\n     */\n    long long size()\
    \ const { return cnt; }\n    /**\n     * @brief \u7A7A\u304B\n     */\n    bool\
    \ empty() const { return cnt == 0; }\n\n    /**\n     * @brief x \u304C\u542B\u307E\
    \u308C\u308B\u304B O(1)\n     */\n    bool contains(long long x) const {\n   \
    \     assert(0 <= x && x < n);\n        return seg[0][x >> 6] >> (x & 63) & 1;\n\
    \    }\n    /**\n     * @brief x \u306E\u500B\u6570 (0 \u304B 1) O(1)\n     */\n\
    \    long long count(long long x) const { return contains(x); }\n    /**\n   \
    \  * @brief x \u3092\u633F\u5165\u3059\u308B\u3002\u65B0\u3057\u304F\u5165\u3063\
    \u305F\u3089 true O(log_64 n)\n     */\n    bool insert(long long x) {\n     \
    \   assert(0 <= x && x < n);\n        if (contains(x)) return false;\n       \
    \ cnt++;\n        for (auto& level : seg) {\n            level[x >> 6] |= std::uint64_t(1)\
    \ << (x & 63);\n            x >>= 6;\n        }\n        return true;\n    }\n\
    \    /**\n     * @brief x \u3092\u524A\u9664\u3059\u308B\u3002\u5165\u3063\u3066\
    \u3044\u305F\u3089 true O(log_64 n)\n     */\n    bool erase(long long x) {\n\
    \        assert(0 <= x && x < n);\n        if (!contains(x)) return false;\n \
    \       cnt--;\n        for (auto& level : seg) {\n            level[x >> 6] &=\
    \ ~(std::uint64_t(1) << (x & 63));\n            // \u540C\u3058 64 bit \u306B\u4ED6\
    \u306E\u8981\u7D20\u304C\u6B8B\u3063\u3066\u3044\u308C\u3070\u3001\u4E0A\u306E\
    \u6BB5\u306F\u5909\u308F\u3089\u306A\u3044\n            if (level[x >> 6]) break;\n\
    \            x >>= 6;\n        }\n        return true;\n    }\n\n    /**\n   \
    \  * @brief x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20 (\u306A\u3051\u308C\
    \u3070 -1) O(log_64 n)\n     */\n    long long next(long long x) const {\n   \
    \     if (x < 0) x = 0;\n        if (x >= n) return -1;\n        for (int h =\
    \ 0; h < static_cast<int>(seg.size()); h++) {\n            if ((x >> 6) == static_cast<long\
    \ long>(seg[h].size())) break;\n            std::uint64_t d = seg[h][x >> 6] >>\
    \ (x & 63);\n            if (!d) {\n                x = (x >> 6) + 1;\n      \
    \          continue;\n            }\n            // \u3053\u306E\u6BB5\u3067\u898B\
    \u3064\u304B\u3063\u305F\u306E\u3067\u3001\u4E0B\u306E\u6BB5\u3067\u306F\u6700\
    \u3082\u5C0F\u3055\u3044 bit \u3092\u305F\u3069\u308B\n            x += __builtin_ctzll(d);\n\
    \            for (int g = h - 1; g >= 0; g--) {\n                x <<= 6;\n  \
    \              x += __builtin_ctzll(seg[g][x >> 6]);\n            }\n        \
    \    return x;\n        }\n        return -1;\n    }\n    /**\n     * @brief x\
    \ \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 -1)\
    \ O(log_64 n)\n     */\n    long long prev(long long x) const {\n        if (x\
    \ >= n) x = n - 1;\n        if (x < 0) return -1;\n        for (int h = 0; h <\
    \ static_cast<int>(seg.size()); h++) {\n            if (x == -1) break;\n    \
    \        std::uint64_t d = seg[h][x >> 6] << (63 - (x & 63));\n            if\
    \ (!d) {\n                x = (x >> 6) - 1;\n                continue;\n     \
    \       }\n            // \u3053\u306E\u6BB5\u3067\u898B\u3064\u304B\u3063\u305F\
    \u306E\u3067\u3001\u4E0B\u306E\u6BB5\u3067\u306F\u6700\u3082\u5927\u304D\u3044\
    \ bit \u3092\u305F\u3069\u308B\n            x -= __builtin_clzll(d);\n       \
    \     for (int g = h - 1; g >= 0; g--) {\n                x <<= 6;\n         \
    \       x += 63 - __builtin_clzll(seg[g][x >> 6]);\n            }\n          \
    \  return x;\n        }\n        return -1;\n    }\n    /**\n     * @brief \u6700\
    \u5C0F\u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n    long\
    \ long min() const { return next(0); }\n    /**\n     * @brief \u6700\u5927\u306E\
    \u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n    long long max()\
    \ const { return prev(n - 1); }\n\n    /**\n     * @brief \u8981\u7D20\u3092\u6607\
    \u9806\u306B\u4E26\u3079\u305F\u3082\u306E O(size() log_64 n)\n     */\n    std::vector<long\
    \ long> to_vector() const {\n        std::vector<long long> res;\n        res.reserve(cnt);\n\
    \        for (long long x = next(0); x != -1; x = next(x + 1)) res.push_back(x);\n\
    \        return res;\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u524A\u9664\
    \u3059\u308B O(n / 64)\n     */\n    void clear() {\n        for (auto& level\
    \ : seg) level.assign(level.size(), 0);\n        cnt = 0;\n    }\n};\n#line 17\
    \ \"src/data_structures/sortable-segtree.hpp\"\n\n/**\n * @brief \u5404\u4F4D\u7F6E\
    \u306B\u30AD\u30FC\u3068\u5024\u3092\u6301\u3064\u5217\u3067\u30011 \u70B9\u306E\
    \u5909\u66F4\u30FB\u533A\u9593\u306E\u7A4D\u30FB\u533A\u9593\u3092\u30AD\u30FC\
    \u3067\u4E26\u3079\u66FF\u3048\u308B\u64CD\u4F5C\u3092\u884C\u3046\n *\n * \u4E26\
    \u3079\u66FF\u3048\u305F\u533A\u9593\u3054\u3068\u306B\u3001\u305D\u306E\u8981\
    \u7D20\u3092\u30AD\u30FC\u306E\u4E8C\u5206\u30C8\u30E9\u30A4 (\u52D5\u7684\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728) \u3067\u6301\u3061\u3001\u6607\u9806\u3068\u964D\
    \u9806\u306E\u7A4D\u3092\u4FDD\u3064\u3002\n * \u533A\u9593\u306E\u5148\u982D\u306E\
    \u4F4D\u7F6E\u306B\u300C\u533A\u9593\u306E\u5411\u304D\u306B\u5408\u308F\u305B\
    \u305F\u7A4D\u300D\u3092\u7F6E\u3044\u305F\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3067\u533A\u9593\u306E\u7A4D\u3092\u6C42\u3081\u308B\u3002\n * \u4E26\u3079\u66FF\
    \u3048\u306F\u30C8\u30E9\u30A4\u306E\u4F75\u5408\u3001\u533A\u9593\u306E\u5883\
    \u76EE\u306F\u30C8\u30E9\u30A4\u3092\u500B\u6570\u3067\u5206\u3051\u308B\u3053\
    \u3068\u3067\u4F5C\u308B\n * \u8A08\u7B97\u91CF\u306F\u306A\u3089\u3057 O((N +\
    \ Q) log K) (K \u306F\u30AD\u30FC\u306E\u4E0A\u9650)\u3002\u30E1\u30E2\u30EA\u306F\
    \ O((N + Q) log K)\n * \u4F8B:\n * SortableSegTree<monoid::Sum<long long>> st(keys,\
    \ values, 1LL << 30);\n * st.sort(l, r);         // [l, r) \u3092\u30AD\u30FC\u306E\
    \u6607\u9806\u306B\u4E26\u3079\u66FF\u3048\u308B\n * st.sort(l, r, true);   //\
    \ \u964D\u9806\n * st.prod(l, r);\n *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (\u7A4D\
    \u306E\u9806\u756A\u306F\u5217\u306E\u9806\u756A)\n */\ntemplate <typename M>\n\
    class SortableSegTree {\n    using S = typename M::S;\n    struct Node {\n   \
    \     int child[2] = {0, 0};\n        int cnt = 0;\n        S asc, desc;  // \u30AD\
    \u30FC\u306E\u6607\u9806\u30FB\u964D\u9806\u306B\u4E26\u3079\u305F\u3068\u304D\
    \u306E\u7A4D\n    };\n    M m;\n    long long n;\n    int bits;\n    std::vector<Node>\
    \ nodes;  // nodes[0] \u306F\u7A7A\u306E\u30C8\u30E9\u30A4\n    std::vector<int>\
    \ root;    // root[s]: s \u304B\u3089\u59CB\u307E\u308B\u533A\u9593\u306E\u30C8\
    \u30E9\u30A4\n    std::vector<bool> rev;    // rev[s]: s \u304B\u3089\u59CB\u307E\
    \u308B\u533A\u9593\u304C\u964D\u9806\u304B\n    FastSet starts;           // \u533A\
    \u9593\u306E\u5148\u982D\n    SegTree<M> seg;\n\n    int new_node() {\n      \
    \  nodes.push_back(Node{{0, 0}, 0, m.e(), m.e()});\n        return static_cast<int>(nodes.size())\
    \ - 1;\n    }\n    void pull(int t) {\n        const Node &a = nodes[nodes[t].child[0]],\
    \ &b = nodes[nodes[t].child[1]];\n        nodes[t].cnt = a.cnt + b.cnt;\n    \
    \    nodes[t].asc = m.op(a.asc, b.asc);\n        nodes[t].desc = m.op(b.desc,\
    \ a.desc);\n    }\n    // \u30AD\u30FC k\u3001\u5024 x \u3060\u3051\u3092\u6301\
    \u3064\u30C8\u30E9\u30A4\n    int make(long long k, const S& x) {\n        assert(0\
    \ <= k && k < (1LL << bits));\n        std::vector<int> path = {new_node()};\n\
    \        for (int d = bits - 1; d >= 0; d--) {\n            const int c = new_node();\n\
    \            nodes[path.back()].child[k >> d & 1] = c;\n            path.push_back(c);\n\
    \        }\n        nodes[path.back()].cnt = 1, nodes[path.back()].asc = nodes[path.back()].desc\
    \ = x;\n        for (int i = static_cast<int>(path.size()) - 2; i >= 0; i--) pull(path[i]);\n\
    \        return path[0];\n    }\n    // 2 \u3064\u306E\u30C8\u30E9\u30A4\u3092\
    \u4F75\u5408\u3059\u308B (\u30AD\u30FC\u306F\u91CD\u306A\u3089\u306A\u3044\u3053\
    \u3068)\n    int merge(int a, int b, int d) {\n        if (a == 0) return b;\n\
    \        if (b == 0) return a;\n        assert(d >= 0 && \"SortableSegTree: \u30AD\
    \u30FC\u304C\u91CD\u306A\u3063\u3066\u3044\u308B\");\n        for (int c = 0;\
    \ c < 2; c++) {\n            int x = merge(nodes[a].child[c], nodes[b].child[c],\
    \ d - 1);\n            nodes[a].child[c] = x;\n        }\n        pull(a);\n \
    \       return a;\n    }\n    // \u30AD\u30FC\u306E\u5C0F\u3055\u3044\u65B9\u304B\
    \u3089 k \u500B\u3068\u6B8B\u308A\u306B\u5206\u3051\u308B\n    std::pair<int,\
    \ int> split(int t, int k, int d) {\n        if (t == 0 || k == 0) return {0,\
    \ t};\n        if (k >= nodes[t].cnt) return {t, 0};\n        // \u3053\u3053\u306B\
    \u6765\u308B\u306A\u3089 cnt >= 2 \u306A\u306E\u3067\u8449\u3067\u306F\u306A\u3044\
    \n        int s = new_node();\n        const int lc = nodes[t].child[0], left_cnt\
    \ = nodes[lc].cnt;\n        if (k <= left_cnt) {\n            auto [a, b] = split(lc,\
    \ k, d - 1);\n            nodes[t].child[0] = a;\n            nodes[s].child[0]\
    \ = b, nodes[s].child[1] = nodes[t].child[1];\n            nodes[t].child[1] =\
    \ 0;\n        } else {\n            auto [a, b] = split(nodes[t].child[1], k -\
    \ left_cnt, d - 1);\n            nodes[t].child[1] = a;\n            nodes[s].child[1]\
    \ = b;\n        }\n        pull(t), pull(s);\n        return {t, s};\n    }\n\
    \    // \u533A\u9593\u306E\u7A4D\u3092\u5411\u304D\u306B\u5408\u308F\u305B\u3066\
    \u8FD4\u3059\n    S value(int s) const { return rev[s] ? nodes[root[s]].desc :\
    \ nodes[root[s]].asc; }\n    // x \u304C\u533A\u9593\u306E\u5148\u982D\u306B\u306A\
    \u308B\u3088\u3046\u306B\u5206\u3051\u308B\n    void cut(long long x) {\n    \
    \    if (x >= n || starts.contains(x)) return;\n        const long long s = starts.prev(x);\n\
    \        const int len = nodes[root[s]].cnt, k = x - s;\n        int a, b;\n \
    \       if (!rev[s]) {\n            std::tie(a, b) = split(root[s], k, bits -\
    \ 1);\n        } else {\n            // \u964D\u9806\u306A\u306E\u3067\u3001\u5148\
    \u982D\u306E k \u500B\u306F\u30AD\u30FC\u306E\u5927\u304D\u3044\u65B9\u306E k\
    \ \u500B\n            std::tie(b, a) = split(root[s], len - k, bits - 1);\n  \
    \      }\n        root[s] = a, root[x] = b, rev[x] = rev[s];\n        starts.insert(x);\n\
    \        seg.set(s, value(s)), seg.set(x, value(x));\n    }\n\n   public:\n  \
    \  /**\n     * @brief \u30AD\u30FC\u3068\u5024\u306E\u5217\u304B\u3089\u4F5C\u308B\
    \n     * @param keys \u30AD\u30FC (0 <= \u30AD\u30FC < key_limit\u3001\u3059\u3079\
    \u3066\u7570\u306A\u308B\u3053\u3068)\n     * @param key_limit \u30AD\u30FC\u306E\
    \u4E0A\u9650 (1 \u70B9\u306E\u5909\u66F4\u3067\u4F7F\u3046\u30AD\u30FC\u3082\u3053\
    \u308C\u672A\u6E80\u3067\u3042\u308B\u3053\u3068)\n     */\n#if __cplusplus >=\
    \ 202002L\n    template <class K = std::initializer_list<long long>, class R =\
    \ std::initializer_list<S>>\n        requires(internal_traits::sized_constructible_range<K,\
    \ long long> && internal_traits::sized_constructible_range<R, S>)\n#else\n   \
    \ template <class K = std::initializer_list<long long>, class R = std::initializer_list<S>,\n\
    \              ENABLE_IF_T(internal_traits::is_sized_constructible_range<K, long\
    \ long>::value&& internal_traits::is_sized_constructible_range<R, S>::value)>\n\
    #endif\n    SortableSegTree(K&& keys, R&& values, long long key_limit, M m = M())\n\
    \        : m(m), n(internal_traits::range_size(keys)), bits(1), root(n), rev(n,\
    \ false), starts(n), seg(values, m) {\n        assert(n == static_cast<long long>(internal_traits::range_size(values)));\n\
    \        while ((1LL << bits) < key_limit) bits++;\n        nodes.reserve(n *\
    \ (bits + 2) + 1);\n        nodes.push_back(Node{{0, 0}, 0, this->m.e(), this->m.e()});\n\
    \        long long i = 0;\n        for (auto&& key : keys) {\n            root[i]\
    \ = make(static_cast<long long>(std::forward<decltype(key)>(key)), seg.get(i));\n\
    \            starts.insert(i++);\n        }\n    }\n\n    /**\n     * @brief \u8981\
    \u7D20\u6570\n     */\n    long long size() const { return n; }\n    /**\n   \
    \  * @brief \u4F4D\u7F6E i \u306E\u30AD\u30FC\u3068\u5024\u3092\u5909\u3048\u308B\
    \ \u306A\u3089\u3057 O(log K)\n     */\n    void set(long long i, long long k,\
    \ const S& x) {\n        assert(0 <= i && i < n);\n        cut(i), cut(i + 1);\n\
    \        root[i] = make(k, x), rev[i] = false;\n        seg.set(i, x);\n    }\n\
    \    /**\n     * @brief a[l] a[l+1] ... a[r-1] \u306E\u7A4D \u306A\u3089\u3057\
    \ O(log K + log N)\n     */\n    S prod(long long l, long long r) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        if (l == r) return m.e();\n        cut(l),\
    \ cut(r);\n        return seg.prod(l, r);\n    }\n    /**\n     * @brief [l, r)\
    \ \u3092\u30AD\u30FC\u306E\u6607\u9806 (reverse \u306A\u3089\u964D\u9806) \u306B\
    \u4E26\u3079\u66FF\u3048\u308B \u306A\u3089\u3057 O(log K + \u533A\u9593\u306E\
    \u500B\u6570)\n     */\n    void sort(long long l, long long r, bool reverse =\
    \ false) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n\
    \        cut(l), cut(r);\n        int t = 0;\n        for (long long s = l; s\
    \ != -1 && s < r; s = starts.next(s + 1)) {\n            t = merge(t, root[s],\
    \ bits - 1);\n            if (s != l) starts.erase(s), seg.set(s, m.e()), root[s]\
    \ = 0;\n        }\n        root[l] = t, rev[l] = reverse;\n        seg.set(l,\
    \ value(l));\n    }\n};\n\ntemplate <class K, class R, typename M>\nSortableSegTree(K&&,\
    \ R&&, long long, M) -> SortableSegTree<M>;\ntemplate <typename M>\nSortableSegTree(std::initializer_list<long\
    \ long>, std::initializer_list<typename M::S>, long long, M) -> SortableSegTree<M>;\n\
    #line 2 \"src/data_structures/sparse-table.hpp\"\n\n/**\n * @file sparse-table.hpp\n\
    \ * @brief Sparse Table\n */\n\n#line 13 \"src/data_structures/sparse-table.hpp\"\
    \n\n#line 16 \"src/data_structures/sparse-table.hpp\"\n\n/**\n * @brief Sparse\
    \ Table\n *\n * \u9759\u7684\u306A\u5217\u306E\u533A\u9593\u7A4D\u3092\u3001\u524D\
    \u8A08\u7B97 O(n log n)\u3001\u30AF\u30A8\u30EA O(1) \u3067\u6C42\u3081\u308B\n\
    \ * \u4F8B:\n * SparseTable<monoid::Min<int>> st(v);\n * st.prod(l, r);  // min(v[l],\
    \ ..., v[r-1])\n *\n * @tparam M \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9 (op(x,\
    \ x) = x \u3068\u306A\u308B\u3082\u306E\u3002monoid::Min\u3001Max\u3001Gcd\u3001\
    And\u3001Or \u306A\u3069)\n */\ntemplate <typename M>\nclass SparseTable {\n \
    \  public:\n    using S = typename M::S;\n\n   private:\n    M m;\n    long long\
    \ n;\n    // table[k][i] \u306F v[i] \u304B\u3089 v[i + 2^k - 1] \u307E\u3067\u306E\
    \u7A4D\n    std::vector<std::vector<S>> table;\n    std::vector<int> lg;  // lg[x]\
    \ = floor(log2(x))\n    S op(const S& a, const S& b) const { return m.op(a, b);\
    \ }\n    S e() const { return m.e(); }\n\n   public:\n#if __cplusplus >= 202002L\n\
    \    template <class R = std::initializer_list<S>>\n        requires internal_traits::sized_constructible_range<R,\
    \ S>\n#else\n    template <class R = std::initializer_list<S>, ENABLE_IF_T(internal_traits::is_sized_constructible_range<R,\
    \ S>::value)>\n#endif\n    explicit SparseTable(R&& v = {}, M m = M()) : m(std::move(m)),\
    \ n(internal_traits::range_size(v)), lg(n + 1, 0) {\n        table.emplace_back();\n\
    \        table[0].reserve(n);\n        for (auto&& x : v) table[0].emplace_back(std::forward<decltype(x)>(x));\n\
    \        for (long long x = 2; x <= n; x++) lg[x] = lg[x / 2] + 1;\n        for\
    \ (int k = 1; (1LL << k) <= n; k++) {\n            const auto& prev = table[k\
    \ - 1];\n            std::vector<S> cur(n - (1LL << k) + 1);\n            for\
    \ (long long i = 0; i + (1LL << k) <= n; i++) cur[i] = op(prev[i], prev[i + (1LL\
    \ << (k - 1))]);\n            table.push_back(std::move(cur));\n        }\n  \
    \  }\n\n    long long size() const { return n; }\n\n    /**\n     * @brief v[k]\n\
    \     */\n    S get(long long k) const {\n        assert(0 <= k && k < n);\n \
    \       return table[0][k];\n    }\n    /**\n     * @brief v[l] \u304B\u3089 v[r-1]\
    \ \u307E\u3067\u306E\u7A4D O(1)\u3002l = r \u306A\u3089\u5358\u4F4D\u5143\n  \
    \   */\n    S prod(long long l, long long r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        if (l == r) return e();\n        int k = lg[r -\
    \ l];\n        return op(table[k][l], table[k][r - (1LL << k)]);\n    }\n    S\
    \ all_prod() const { return prod(0, n); }\n};\n\ntemplate <class R, typename M>\n\
    SparseTable(R&&, M) -> SparseTable<M>;\ntemplate <typename M>\nSparseTable(std::initializer_list<typename\
    \ M::S>, M) -> SparseTable<M>;\n#line 36 \"test/unittest/algebra/monoid.test.cpp\"\
    \n\nbool ok = true;\nvoid check(bool cond, const char* what) {\n    if (!cond\
    \ && ok) std::cerr << \"failed: \" << what << std::endl;\n    if (!cond) ok =\
    \ false;\n}\n\n// SegTree<M> \u3092\u3001\u914D\u5217\u3068\u6F14\u7B97 op \u3067\
    \u611A\u76F4\u306B\u8A08\u7B97\u3057\u305F\u7D50\u679C\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306A\u64CD\u4F5C\u5217\u3067\u6BD4\u3079\u308B\n// size\u30FBconst \u306A\
    \ operator[]\u30FBall_prod\u30FBos << seg \u3082\u78BA\u304B\u3081\u308B\ntemplate\
    \ <typename M, typename Op, typename Gen>\nvoid test_segtree(Op op, typename M::S\
    \ e, Gen gen, std::mt19937_64& rng, const char* name) {\n    using S = typename\
    \ M::S;\n    for (int rep = 0; rep < 200 && ok; rep++) {\n        int n = rng()\
    \ % 20 + 1;\n        std::vector<S> a(n);\n        for (auto& x : a) x = gen();\n\
    \        SegTree<M> seg(a);\n        check(seg.size() == n, name);\n        for\
    \ (int q = 0; q < 50 && ok; q++) {\n            int t = rng() % 3;\n         \
    \   if (t == 0) {\n                int k = rng() % n;\n                S x = gen();\n\
    \                seg.set(k, x);\n                a[k] = x;\n            } else\
    \ if (t == 1) {\n                int k = rng() % n;\n                S x = gen();\n\
    \                seg.apply(k, x);\n                a[k] = op(a[k], x);\n     \
    \       } else {\n                int l = rng() % (n + 1), r = rng() % (n + 1);\n\
    \                if (l > r) std::swap(l, r);\n                S expect = e;\n\
    \                for (int i = l; i < r; i++) expect = op(expect, a[i]);\n    \
    \            check(seg.prod(l, r) == expect, name);\n            }\n        }\n\
    \        S all = e;\n        for (int i = 0; i < n; i++) all = op(all, a[i]);\n\
    \        check(seg.all_prod() == all, name);\n        const SegTree<M>& cseg =\
    \ seg;\n        std::ostringstream os, expect;\n        for (int i = 0; i < n;\
    \ i++) {\n            check(cseg[i] == a[i], name);\n            if (i != 0) expect\
    \ << ' ';\n            expect << a[i];\n        }\n        os << cseg;\n     \
    \   check(os.str() == expect.str(), name);\n    }\n}\n\nstruct ExplicitSum {\n\
    \    struct S {\n        long long value;\n        S() : value(0) {}\n       \
    \ explicit S(long long x) : value(x) {}\n    };\n    static S op(const S& a, const\
    \ S& b) { return S(a.value + b.value); }\n    static S e() { return S(0); }\n\
    };\n\nstruct ExplicitAddSum : ExplicitSum {\n    using F = long long;\n    static\
    \ S mapping(F f, const S& x, long long len) { return S(x.value + f * len); }\n\
    \    static F composition(F f, F g) { return f + g; }\n    static F id() { return\
    \ 0; }\n    static F inv(F f) { return -f; }\n};\n\nstruct ExplicitGroup : ExplicitSum\
    \ {\n    static S inv(const S& x) { return S(-x.value); }\n};\n\nstruct ExplicitMin\
    \ : ExplicitSum {\n    static S op(const S& a, const S& b) { return S(std::min(a.value,\
    \ b.value)); }\n    static S e() { return S(std::numeric_limits<long long>::max());\
    \ }\n};\n\nstruct ExplicitBeats : ExplicitAddSum {\n    static std::pair<bool,\
    \ S> mapping(F f, const S& x, long long len) { return {false, ExplicitAddSum::mapping(f,\
    \ x, len)}; }\n};\n\n// begin \u306F\u4E00\u5EA6\u3060\u3051\u3002\u30A4\u30C6\
    \u30EC\u30FC\u30BF\u306E\u5F8C\u7F6E ++ \u306F\u5024\u3092\u8FD4\u3055\u305A\u3001\
    \u7D42\u7AEF\u306E\u578B\u3082\u7570\u306A\u308B\u3002\nstruct SizedInputRange\
    \ {\n    int values[3] = {2, -5, 4};\n    int pos = 0;\n    bool begun = false;\n\
    \    struct Sentinel {};\n    struct Iterator {\n        using value_type = int;\n\
    \        using difference_type = long long;\n        using iterator_category =\
    \ std::input_iterator_tag;\n        SizedInputRange* range;\n        int operator*()\
    \ const { return range->values[range->pos]; }\n        Iterator& operator++()\
    \ {\n            ++range->pos;\n            return *this;\n        }\n       \
    \ void operator++(int) { ++*this; }\n        friend bool operator==(Iterator it,\
    \ Sentinel) { return it.range->pos == 3; }\n        friend bool operator!=(Iterator\
    \ it, Sentinel s) { return !(it == s); }\n        friend bool operator==(Sentinel\
    \ s, Iterator it) { return it == s; }\n        friend bool operator!=(Sentinel\
    \ s, Iterator it) { return !(it == s); }\n    };\n    Iterator begin() {\n   \
    \     check(!begun, \"sized input range is traversed once\");\n        begun =\
    \ true;\n        return {this};\n    }\n    Sentinel end() const { return {};\
    \ }\n    long long size() const { return 3; }\n};\n\ntemplate <template <typename>\
    \ class Tree, typename M>\nvoid test_converting_tree(M m) {\n    auto verify_range\
    \ = [&](auto&& r) {\n        Tree tree(std::forward<decltype(r)>(r), m);\n   \
    \     check(tree.size() == 3 && tree.get(0).value == 2 && tree.get(1).value ==\
    \ -5 && tree.get(2).value == 4,\n              \"tree family sized range / CTAD\"\
    );\n    };\n    int raw[] = {2, -5, 4};\n    const std::array<int, 3> arr = {2,\
    \ -5, 4};\n    verify_range(raw);\n    verify_range(arr);\n    verify_range(std::list<int>{2,\
    \ -5, 4});\n    verify_range(std::deque<int>{2, -5, 4});\n    verify_range(SizedInputRange{});\n\
    \    Tree<M> empty_array(std::array<int, 0>{});\n    check(empty_array.size()\
    \ == 0, \"tree family empty array\");\n    static_assert(!std::is_constructible_v<Tree<M>,\
    \ std::forward_list<int>&>);\n    static_assert(!std::is_constructible_v<Tree<M>,\
    \ std::array<std::string, 3>&>);\n#if __cplusplus >= 202002L\n    verify_range(std::views::iota(0,\
    \ 3) | std::views::transform([&](int i) { return raw[i]; }));\n#endif\n    static_assert(std::is_constructible_v<Tree<M>,\
    \ const std::vector<int>&, M>);\n    static_assert(!std::is_constructible_v<Tree<M>,\
    \ const std::vector<std::string>&, M>);\n    Tree seg(std::vector<int>{2, -5,\
    \ 4}, m);\n    check(seg.size() == 3 && seg.get(0).value == 2 && seg.get(1).value\
    \ == -5 && seg.get(2).value == 4,\n          \"segtree family explicit conversion\
    \ / CTAD\");\n    Tree<M> empty(std::vector<int>{});\n    check(empty.size() ==\
    \ 0, \"segtree family conversion empty\");\n    Tree<M> same(std::vector<typename\
    \ M::S>{typename M::S(7)});\n    check(same.get(0).value == 7, \"segtree family\
    \ vector<S>\");\n    Tree<M> list({typename M::S(8), typename M::S(9)});\n   \
    \ check(list.get(1).value == 9, \"segtree family initializer list\");\n}\n\ntemplate\
    \ <class R>\nvoid test_segtree_range(R&& r) {\n    SegTree seg(std::forward<R>(r),\
    \ ExplicitSum{});\n    check(seg.size() == 3 && seg.prod(0, 3).value == 1 && seg.prod(1,\
    \ 3).value == -1, \"SegTree sized range / CTAD\");\n    seg.set(1, ExplicitSum::S(3));\n\
    \    check(seg.all_prod().value == 9, \"SegTree sized range update\");\n}\n\n\
    int main() {\n    {\n        int a[] = {2, -5, 4};\n        const std::array<int,\
    \ 3> b = {2, -5, 4};\n        test_segtree_range(a);\n        test_segtree_range(b);\n\
    \        test_segtree_range(std::list<int>{2, -5, 4});\n        test_segtree_range(std::deque<int>{2,\
    \ -5, 4});\n        SegTree<ExplicitSum> empty(std::array<int, 0>{});\n      \
    \  check(empty.size() == 0 && empty.all_prod().value == 0, \"SegTree empty range\"\
    );\n        SegTree braces({ExplicitSum::S(2), ExplicitSum::S(-5), ExplicitSum::S(4)},\
    \ ExplicitSum{});\n        check(braces.all_prod().value == 1, \"SegTree initializer\
    \ list / CTAD\");\n        SegTree<ExplicitSum> original(a);\n        auto copied\
    \ = original;\n        auto moved = std::move(copied);\n        check(moved.all_prod().value\
    \ == 1 && original.all_prod().value == 1, \"SegTree copy / move\");\n        SegTree\
    \ sized(3LL, ExplicitSum{});\n        check(sized.size() == 3 && sized.all_prod().value\
    \ == 0, \"SegTree size / CTAD\");\n        static_assert(!std::is_constructible_v<SegTree<ExplicitSum>,\
    \ std::forward_list<int>&>);\n        static_assert(!std::is_constructible_v<SegTree<ExplicitSum>,\
    \ std::array<std::string, 3>&>);\n#if __cplusplus >= 202002L\n        test_segtree_range(std::views::all(a));\n\
    \        test_segtree_range(std::views::iota(0, 3) | std::views::transform([&](int\
    \ i) { return a[i]; }));\n        SegTree view(a | std::views::take(2), ExplicitSum{});\n\
    \        check(view.size() == 2 && view.all_prod().value == -3, \"SegTree partial\
    \ view\");\n#endif\n    }\n\n    test_converting_tree<SegTree>(ExplicitSum{});\n\
    \    test_converting_tree<RBST>(ExplicitSum{});\n    test_converting_tree<RBST>(ExplicitAddSum{});\n\
    \    test_converting_tree<FenwickTree>(ExplicitGroup{});\n    test_converting_tree<SparseTable>(ExplicitMin{});\n\
    \    test_converting_tree<LinkCutTree>(ExplicitSum{});\n    test_converting_tree<SubtreeLinkCutTree>(ExplicitGroup{});\n\
    \    {\n        auto verify = [](auto&& r) {\n            MonoidUnionFind uf(std::forward<decltype(r)>(r),\
    \ ExplicitSum{});\n            uf.merge(0, 1);\n            check(uf.prod(0).value\
    \ == -3 && uf.prod(2).value == 4, \"MonoidUnionFind sized range / CTAD\");\n \
    \       };\n        int raw[] = {2, -5, 4};\n        verify(raw);\n        verify(std::list<int>{2,\
    \ -5, 4});\n        verify(SizedInputRange{});\n        std::vector<ExplicitSum::S>\
    \ owned{ExplicitSum::S(7)};\n        const auto* ptr = owned.data();\n       \
    \ MonoidUnionFind moved(std::move(owned), ExplicitSum{});\n        check(&moved.prod(0)\
    \ == ptr, \"MonoidUnionFind moves vector storage\");\n        Imos from_range(SizedInputRange{},\
    \ ExplicitAddSum{});\n        from_range.apply(0, 2, 3);\n        check(from_range.get(0).value\
    \ == 5 && from_range.get(1).value == -2 && from_range.get(2).value == 4,\n   \
    \           \"Imos sized input range / CTAD\");\n        Imos from_list(std::list<int>{2,\
    \ -5, 4}, ExplicitAddSum{});\n        check(from_list.get(1).value == -5, \"Imos\
    \ list\");\n        Imos<ExplicitAddSum> empty_range(std::array<int, 0>{});\n\
    \        static_assert(!std::is_constructible_v<Imos<ExplicitAddSum>, std::forward_list<int>&>);\n\
    \        static_assert(!std::is_constructible_v<MonoidUnionFind<ExplicitSum>,\
    \ const std::vector<std::string>&>);\n        MonoidUnionFind uf(std::vector<int>{2,\
    \ -5, 4}, ExplicitSum{});\n        uf.merge(0, 1);\n        check(uf.prod(0).value\
    \ == -3 && uf.prod(2).value == 4, \"MonoidUnionFind conversion / CTAD\");\n  \
    \      MonoidUnionFind<ExplicitSum> empty(std::vector<int>{});\n        check(empty.groups().empty(),\
    \ \"MonoidUnionFind conversion empty\");\n        Imos imos(std::vector<int>{2,\
    \ -5, 4}, ExplicitAddSum{});\n        imos.apply(0, 2, 3);\n        check(imos.get(0).value\
    \ == 5 && imos.get(1).value == -2 && imos.get(2).value == 4, \"Imos conversion\
    \ / CTAD\");\n        Imos<ExplicitAddSum> empty_imos(std::vector<int>{});\n \
    \       static_assert(!std::is_constructible_v<Imos<ExplicitAddSum>, const std::vector<std::string>&>);\n\
    \    }\n\n    test_converting_tree<LazySegTree>(ExplicitAddSum{});\n    test_converting_tree<DualSegTree>(ExplicitAddSum{});\n\
    \    test_converting_tree<PersistentSegTree>(ExplicitSum{});\n    test_converting_tree<PersistentLazySegTree>(ExplicitAddSum{});\n\
    \    test_converting_tree<SegTreeBeats>(ExplicitBeats{});\n    {\n        auto\
    \ verify = [](auto&& keys, auto&& values) {\n            SortableSegTree tree(std::forward<decltype(keys)>(keys),\
    \ std::forward<decltype(values)>(values), 3, ExplicitSum{});\n            tree.sort(0,\
    \ 3);\n            check(tree.prod(0, 1).value == -5 && tree.prod(0, 3).value\
    \ == 1, \"SortableSegTree sized ranges / sort / CTAD\");\n        };\n       \
    \ int keys[] = {2, 0, 1};\n        verify(keys, std::list<int>{2, -5, 4});\n \
    \       verify(std::list<int>{2, 0, 1}, SizedInputRange{});\n        SortableSegTree\
    \ braces({2, 0, 1}, {ExplicitSum::S(2), ExplicitSum::S(-5), ExplicitSum::S(4)},\
    \ 3, ExplicitSum{});\n        check(braces.prod(0, 3).value == 1, \"SortableSegTree\
    \ initializer lists / CTAD\");\n        SortableSegTree sorted(std::vector<long\
    \ long>{2, 0, 1}, std::vector<int>{2, -5, 4}, 3, ExplicitSum{});\n        sorted.sort(0,\
    \ 3);\n        check(sorted.prod(0, 1).value == -5 && sorted.prod(0, 3).value\
    \ == 1, \"SortableSegTree conversion / CTAD / sort\");\n        SortableSegTree<ExplicitSum>\
    \ empty(std::vector<long long>{}, std::vector<int>{}, 1);\n        check(empty.size()\
    \ == 0, \"SortableSegTree conversion empty\");\n    }\n\n    {\n        static_assert(std::is_constructible_v<SegTree<ExplicitSum>,\
    \ const std::vector<int>&>);\n        static_assert(!std::is_constructible_v<SegTree<ExplicitSum>,\
    \ const std::vector<std::string>&>);\n        SegTree seg(std::vector<int>{2,\
    \ -5, 4}, ExplicitSum{});\n        check(seg.prod(0, 3).value == 1 && seg.prod(1,\
    \ 3).value == -1, \"SegTree explicit conversion / CTAD\");\n        SegTree<ExplicitSum>\
    \ empty(std::vector<int>{});\n        check(empty.size() == 0 && empty.all_prod().value\
    \ == 0, \"SegTree conversion empty\");\n        SegTree<monoid::Sum<long long>>\
    \ ordinary({1, 2, 3});\n        check(ordinary.all_prod() == 6, \"SegTree initializer\
    \ list\");\n        SegTree<monoid::Sum<long long>> widened(std::vector<int>{1,\
    \ 2, 3});\n        check(widened.all_prod() == 6, \"SegTree arithmetic conversion\"\
    );\n    }\n\n    std::mt19937_64 rng(314);\n\n    // And / Or: \u5358\u4F4D\u5143\
    \u306F\u305D\u308C\u305E\u308C\u5168\u30D3\u30C3\u30C8 1 \u3068 0\n    check(monoid::And<unsigned>::e()\
    \ == ~0u, \"And::e\");\n    check(monoid::Or<unsigned>::e() == 0u, \"Or::e\");\n\
    \    auto gen_bits = [&] { return static_cast<unsigned>(rng() % 64); };\n    test_segtree<monoid::And<unsigned>>([](unsigned\
    \ a, unsigned b) { return a & b; }, ~0u, gen_bits, rng, \"And\");\n    test_segtree<monoid::Or<unsigned>>([](unsigned\
    \ a, unsigned b) { return a | b; }, 0u, gen_bits, rng, \"Or\");\n\n    // Parenthesis:\
    \ \u533A\u9593\u304C\u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\u3092 is_valid\
    \ \u3067\u5224\u5B9A\u3059\u308B\n    for (int rep = 0; rep < 300 && ok; rep++)\
    \ {\n        int n = rng() % 16 + 1;\n        std::string s(n, '(');\n       \
    \ for (char& c : s) c = rng() % 2 ? '(' : ')';\n        SegTree<monoid::Parenthesis>\
    \ seg(s);\n        for (int l = 0; l <= n; l++) {\n            for (int r = l;\
    \ r <= n; r++) {\n                int depth = 0, min_depth = 0;\n            \
    \    for (int i = l; i < r; i++) {\n                    depth += s[i] == '(' ?\
    \ 1 : -1;\n                    min_depth = std::min(min_depth, depth);\n     \
    \           }\n                auto p = seg.prod(l, r);\n                check(p.is_valid()\
    \ == (depth == 0 && min_depth == 0), \"Parenthesis::is_valid\");\n           \
    \     check(p.close == -min_depth && p.open == depth - min_depth, \"Parenthesis::op\"\
    );\n            }\n        }\n    }\n\n    // Affine: ==, !=, \u51FA\u529B\n \
    \   {\n        Affine<long long> f{2, 3}, g{2, 3}, h{2, 4}, id;\n        check(f\
    \ == g && !(f != g), \"Affine ==\");\n        check(f != h && !(f == h), \"Affine\
    \ !=\");\n        check(id == Affine<long long>{1, 0}, \"Affine default\");\n\
    \        std::ostringstream os;\n        os << f;\n        check(os.str() == \"\
    2 3\", \"Affine <<\");\n        // Composite \u3067\u5408\u6210\u3057\u305F\u7D50\
    \u679C\u304C\u95A2\u6570\u306E\u5408\u6210 a\u2218b \u3068\u4E00\u81F4\u3059\u308B\
    \u3002Reverse \u306F b\u2218a\n        for (int rep = 0; rep < 1000 && ok; rep++)\
    \ {\n            Affine<long long> a{static_cast<long long>(rng() % 7) - 3, static_cast<long\
    \ long>(rng() % 7) - 3};\n            Affine<long long> b{static_cast<long long>(rng()\
    \ % 7) - 3, static_cast<long long>(rng() % 7) - 3};\n            long long x =\
    \ static_cast<long long>(rng() % 7) - 3;\n            auto c = monoid::Composite<long\
    \ long>::op(a, b);\n            check(c(x) == a(b(x)), \"Composite op\");\n  \
    \          check(c == Affine<long long>{a.a * b.a, a.a * b.b + a.b}, \"Affine\
    \ == after op\");\n            auto d = monoid::Reverse<monoid::Composite<long\
    \ long>>().op(a, b);\n            check(d(x) == b(a(x)), \"Reverse<Composite>\
    \ op\");\n        }\n    }\n\n    // Clamp: ==, !=, \u5165\u51FA\u529B, \u65E2\
    \u5B9A\u5024\u306F\u6052\u7B49\u5199\u50CF\n    {\n        Clamp<long long> f{2,\
    \ 5}, g{2, 5}, h{2, 6}, id;\n        check(f == g && !(f != g), \"Clamp ==\");\n\
    \        check(f != h && !(f == h), \"Clamp !=\");\n        check(id(std::numeric_limits<long\
    \ long>::lowest()) == std::numeric_limits<long long>::lowest() && id(std::numeric_limits<long\
    \ long>::max()) == std::numeric_limits<long long>::max(), \"Clamp default\");\n\
    \        check(f(1) == 2 && f(3) == 3 && f(9) == 5, \"Clamp ()\");\n        //\
    \ {} \u3092\u6E21\u3059\u3068\u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057\u3002\
    1 \u3064\u306E\u5024\u304B\u3089\u306F\u6697\u9ED9\u306B\u5909\u63DB\u3057\u306A\
    \u3044\n        check((Clamp<long long>{0, {}} == Clamp<long long>{0, std::numeric_limits<long\
    \ long>::max()}), \"Clamp {lb, {}}\");\n        check((Clamp<long long>{{}, 0}\
    \ == Clamp<long long>{std::numeric_limits<long long>::lowest(), 0}), \"Clamp {{},\
    \ ub}\");\n        check((Clamp<long long>{{}, {}} == Clamp<long long>{}), \"\
    Clamp {{}, {}}\");\n        static_assert(!std::is_convertible_v<long long, Clamp<long\
    \ long>>);\n        static_assert(std::is_trivially_copyable_v<Clamp<long long>>);\n\
    \        static_assert(Clamp<int>{0, {}}(-5) == 0);\n        std::ostringstream\
    \ os;\n        os << f;\n        check(os.str() == \"2 5\", \"Clamp <<\");\n \
    \       std::istringstream is(\"-3 4\");\n        is >> f;\n        check(f ==\
    \ Clamp<long long>{-3, 4}, \"Clamp >>\");\n        // ClampComposite \u3067\u5408\
    \u6210\u3057\u305F\u7D50\u679C\u304C\u95A2\u6570\u306E\u5408\u6210 a\u2218b \u3068\
    \u4E00\u81F4\u3059\u308B\u3002Reverse \u306F b\u2218a\n        auto gen_clamp\
    \ = [&] {\n            long long lb = static_cast<long long>(rng() % 11) - 5,\
    \ ub = static_cast<long long>(rng() % 11) - 5;\n            if (lb > ub) std::swap(lb,\
    \ ub);\n            if (rng() % 4 == 0) lb = std::numeric_limits<long long>::lowest();\n\
    \            if (rng() % 4 == 0) ub = std::numeric_limits<long long>::max();\n\
    \            return Clamp<long long>{lb, ub};\n        };\n        for (int rep\
    \ = 0; rep < 1000 && ok; rep++) {\n            auto a = gen_clamp(), b = gen_clamp();\n\
    \            auto c = monoid::ClampComposite<long long>::op(a, b);\n         \
    \   auto d = monoid::Reverse<monoid::ClampComposite<long long>>().op(a, b);\n\
    \            check(c.lb <= c.ub, \"ClampComposite lb <= ub\");\n            check(monoid::ClampComposite<long\
    \ long>::op(a, monoid::ClampComposite<long long>::e()) == a, \"ClampComposite\
    \ e\");\n            check(monoid::ClampComposite<long long>::op(monoid::ClampComposite<long\
    \ long>::e(), a) == a, \"ClampComposite e\");\n            for (long long x =\
    \ -7; x <= 7; x++) {\n                check(c(x) == a(b(x)), \"ClampComposite\
    \ op\");\n                check(d(x) == b(a(x)), \"Reverse<ClampComposite> op\"\
    );\n            }\n        }\n        // SegTree \u306B\u4E57\u305B\u3066\u3001\
    \u533A\u9593\u306E\u95A2\u6570\u3092\u53F3\u304B\u3089\u9806\u306B\u9069\u7528\
    \u3057\u305F\u7D50\u679C\u3068\u6BD4\u3079\u308B\n        test_segtree<monoid::ClampComposite<long\
    \ long>>(\n            [](const Clamp<long long>& a, const Clamp<long long>& b)\
    \ { return monoid::ClampComposite<long long>::op(a, b); },\n            Clamp<long\
    \ long>{}, gen_clamp, rng, \"ClampComposite\");\n    }\n\n    // ClampAdd: ==,\
    \ !=, \u5165\u51FA\u529B, \u65E2\u5B9A\u5024\u306F\u6052\u7B49\u5199\u50CF\n \
    \   {\n        constexpr long long lowest = std::numeric_limits<long long>::lowest(),\
    \ highest = std::numeric_limits<long long>::max();\n        ClampAdd<long long>\
    \ f{2, 5, 1}, g{2, 5, 1}, h{2, 5, 0}, id;\n        check(f == g && !(f != g),\
    \ \"ClampAdd ==\");\n        check(f != h && !(f == h), \"ClampAdd !=\");\n  \
    \      check(id == ClampAdd<long long>{lowest, highest, 0} && id(lowest) == lowest\
    \ && id(highest) == highest, \"ClampAdd default\");\n        check(f(0) == 2 &&\
    \ f(2) == 3 && f(9) == 5, \"ClampAdd ()\");\n        // {} \u3092\u6E21\u3059\u3068\
    \u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057\u3002add \u306F\u7701\u7565\u3059\u308B\
    \u3068 0\u30021 \u3064\u306E\u5024\u304B\u3089\u306F\u6697\u9ED9\u306B\u5909\u63DB\
    \u3057\u306A\u3044\n        check((ClampAdd<long long>{{}, {}, 3} == ClampAdd<long\
    \ long>{lowest, highest, 3}), \"ClampAdd {{}, {}, add}\");\n        check((ClampAdd<long\
    \ long>{{}, 5} == ClampAdd<long long>{lowest, 5, 0}), \"ClampAdd {{}, ub}\");\n\
    \        check((ClampAdd<long long>{5, {}} == ClampAdd<long long>{5, highest,\
    \ 0}), \"ClampAdd {lb, {}}\");\n        static_assert(!std::is_convertible_v<long\
    \ long, ClampAdd<long long>>);\n        static_assert(std::is_trivially_copyable_v<ClampAdd<long\
    \ long>>);\n        static_assert(ClampAdd<int>{{}, 10, 3}(9) == 10);\n      \
    \  std::ostringstream os;\n        os << f;\n        check(os.str() == \"2 5 1\"\
    , \"ClampAdd <<\");\n        std::istringstream is(\"-3 4 -1\");\n        is >>\
    \ f;\n        check(f == ClampAdd<long long>{-3, 4, -1}, \"ClampAdd >>\");\n \
    \       // ClampAddComposite \u3067\u5408\u6210\u3057\u305F\u7D50\u679C\u304C\u95A2\
    \u6570\u306E\u5408\u6210 a\u2218b \u3068\u4E00\u81F4\u3059\u308B\u3002Reverse\
    \ \u306F b\u2218a\n        // \u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057 (\u578B\
    \u306E\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024) \u306B\u8DB3\u3057\u3066\u3082\
    \u3042\u3075\u308C\u306A\u3044 (UBSan \u3067\u78BA\u304B\u3081\u308B)\n      \
    \  auto gen_clamp_add = [&] {\n            long long lb = static_cast<long long>(rng()\
    \ % 11) - 5, ub = static_cast<long long>(rng() % 11) - 5;\n            if (lb\
    \ > ub) std::swap(lb, ub);\n            if (rng() % 3 == 0) lb = lowest;\n   \
    \         if (rng() % 3 == 0) ub = highest;\n            return ClampAdd<long\
    \ long>{lb, ub, static_cast<long long>(rng() % 7) - 3};\n        };\n        for\
    \ (int rep = 0; rep < 1000 && ok; rep++) {\n            auto a = gen_clamp_add(),\
    \ b = gen_clamp_add();\n            auto c = monoid::ClampAddComposite<long long>::op(a,\
    \ b);\n            auto d = monoid::Reverse<monoid::ClampAddComposite<long long>>().op(a,\
    \ b);\n            check(c.lb <= c.ub, \"ClampAddComposite lb <= ub\");\n    \
    \        check(monoid::ClampAddComposite<long long>::op(a, monoid::ClampAddComposite<long\
    \ long>::e()) == a, \"ClampAddComposite e\");\n            check(monoid::ClampAddComposite<long\
    \ long>::op(monoid::ClampAddComposite<long long>::e(), a) == a, \"ClampAddComposite\
    \ e\");\n            for (long long x = -9; x <= 9; x++) {\n                check(c(x)\
    \ == a(b(x)), \"ClampAddComposite op\");\n                check(d(x) == b(a(x)),\
    \ \"Reverse<ClampAddComposite> op\");\n            }\n        }\n        // SegTree\
    \ \u306B\u4E57\u305B\u308B (\u52A0\u7B97\u304C\u7A4D\u307F\u91CD\u306A\u3063\u3066\
    \u3082\u3042\u3075\u308C\u306A\u3044\u7BC4\u56F2\u3067)\n        test_segtree<monoid::ClampAddComposite<long\
    \ long>>(\n            [](const ClampAdd<long long>& a, const ClampAdd<long long>&\
    \ b) { return monoid::ClampAddComposite<long long>::op(a, b); },\n           \
    \ ClampAdd<long long>{}, gen_clamp_add, rng, \"ClampAddComposite\");\n    }\n\n\
    \    // group::Xor: inv \u306F\u81EA\u5206\u81EA\u8EAB\u3002PotentializedUnionFind\
    \ \u306B\u4E57\u305B\u3066 xor \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3068\
    \u6BD4\u3079\u308B\n    for (int rep = 0; rep < 300 && ok; rep++) {\n        int\
    \ n = rng() % 12 + 1;\n        std::vector<int> pot(n);\n        for (int& p :\
    \ pot) p = rng() % 1024;\n        std::vector<int> comp(n);\n        for (int\
    \ i = 0; i < n; i++) comp[i] = i;\n        PotentializedUnionFind<group::Xor<int>>\
    \ uf(n);\n        for (int q = 0; q < 30 && ok; q++) {\n            int a = rng()\
    \ % n, b = rng() % n;\n            if (rng() % 2) {\n                uf.merge(a,\
    \ b, pot[a] ^ pot[b]);\n                int ca = comp[a], cb = comp[b];\n    \
    \            for (int& c : comp)\n                    if (c == cb) c = ca;\n \
    \           } else {\n                check(uf.same(a, b) == (comp[a] == comp[b]),\
    \ \"group::Xor same\");\n                if (comp[a] == comp[b]) check(uf.diff(a,\
    \ b) == (pot[a] ^ pot[b]), \"group::Xor diff\");\n            }\n        }\n \
    \       int x = rng() % 1024;\n        check(group::Xor<int>::inv(x) == x, \"\
    group::Xor::inv\");\n    }\n\n    // PrefixSumMax / PrefixSumMin / PrefixSumMinMax\
    \ / SuffixSumMax / SuffixSumMin / MaxSubarraySum: \u7A7A\u3092\u542B\u3080 prefix\u30FB\
    suffix\u30FB\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\n    for (int rep = 0;\
    \ rep < 300 && ok; rep++) {\n        int n = rng() % 12 + 1;\n        std::vector<long\
    \ long> a(n);\n        for (auto& x : a) x = static_cast<long long>(rng() % 21)\
    \ - 10;\n        SegTree<monoid::PrefixSumMax<long long>> pmax(a);\n        SegTree<monoid::PrefixSumMin<long\
    \ long>> pmin(a);\n        using PM = monoid::PrefixSumMinMax<>;\n        SegTree<PM>\
    \ pminmax(a);\n        SegTree<monoid::SuffixSumMax<long long>> smax(a);\n   \
    \     SegTree<monoid::SuffixSumMin<long long>> smin(a);\n        SegTree<monoid::MaxSubarraySum<long\
    \ long>> msub(a);\n        for (int q = 0; q < 10 && ok; q++) {\n            int\
    \ k = rng() % n;\n            a[k] = static_cast<long long>(rng() % 21) - 10;\n\
    \            pminmax.set(k, a[k]);\n            pmax.set(k, a[k]), pmin.set(k,\
    \ a[k]), smax.set(k, a[k]), smin.set(k, a[k]), msub.set(k, a[k]);\n          \
    \  for (int l = 0; l <= n; l++) {\n                for (int r = l; r <= n; r++)\
    \ {\n                    long long sum = 0, pre_max = 0, pre_min = 0, suf_max\
    \ = 0, suf_min = 0, best = 0;\n                    for (int i = l; i < r; i++)\
    \ {\n                        sum += a[i];\n                        pre_max = std::max(pre_max,\
    \ sum), pre_min = std::min(pre_min, sum);\n                        long long s\
    \ = 0;\n                        for (int j = i; j < r; j++) {\n              \
    \              s += a[j];\n                            best = std::max(best, s);\n\
    \                        }\n                    }\n                    long long\
    \ s = 0;\n                    for (int i = r - 1; i >= l; i--) {\n           \
    \             s += a[i];\n                        suf_max = std::max(suf_max,\
    \ s), suf_min = std::min(suf_min, s);\n                    }\n               \
    \     check(pmax.prod(l, r) == monoid::PrefixSumMax<long long>::S(sum, pre_max),\
    \ \"PrefixSumMax\");\n                    check(pmin.prod(l, r) == monoid::PrefixSumMin<long\
    \ long>::S(sum, pre_min), \"PrefixSumMin\");\n                    check(pminmax.prod(l,\
    \ r) == PM::S(sum, pre_min, pre_max), \"PrefixSumMinMax\");\n                \
    \    check(PM::op(PM::e(), pminmax.prod(l, r)) == pminmax.prod(l, r) &&\n    \
    \                          PM::op(pminmax.prod(l, r), PM::e()) == pminmax.prod(l,\
    \ r),\n                          \"PrefixSumMinMax identity\");\n            \
    \        int m = (l + r) / 2;\n                    check(PM::op(pminmax.prod(l,\
    \ m), pminmax.prod(m, r)) == pminmax.prod(l, r), \"PrefixSumMinMax concatenate\"\
    );\n                    check(smax.prod(l, r) == monoid::SuffixSumMax<long long>::S(sum,\
    \ suf_max), \"SuffixSumMax\");\n                    check(smin.prod(l, r) == monoid::SuffixSumMin<long\
    \ long>::S(sum, suf_min), \"SuffixSumMin\");\n                    check(msub.prod(l,\
    \ r) == monoid::MaxSubarraySum<long long>::S(sum, pre_max, suf_max, best), \"\
    MaxSubarraySum\");\n                }\n            }\n            // max_right:\
    \ l \u304B\u3089\u59CB\u3081\u3066\u548C\u304C\u521D\u3081\u3066\u6B63\u306B\u306A\
    \u308B\u4F4D\u7F6E\n            int l = rng() % (n + 1);\n            long long\
    \ sum = 0;\n            int expect = n;\n            for (int i = l; i < n; i++)\
    \ {\n                sum += a[i];\n                if (sum > 0) {\n          \
    \          expect = i;\n                    break;\n                }\n      \
    \      }\n            check(pmax.max_right(l, [](const auto& s) { return s.max\
    \ <= 0; }) == expect, \"PrefixSumMax max_right\");\n        }\n    }\n\n    //\
    \ MinWith / MaxWith: \u7A7A\u533A\u9593\u306F\u4F4D\u7F6E -1\u3002\u5024\u304C\
    \u578B\u306E\u6700\u5927\u5024 (\u6700\u5C0F\u5024) \u306E\u8981\u7D20\u304C\u3042\
    \u3063\u3066\u3082\u5358\u4F4D\u5143\u3068\u3057\u3066\u50CD\u304D\u3001\u540C\
    \u3058\u5024\u306A\u3089\u5DE6\u5074\n    {\n        using Mn = monoid::MinWith<long\
    \ long>;\n        using Mx = monoid::MaxWith<long long>;\n        constexpr long\
    \ long INF = std::numeric_limits<long long>::max(), NINF = std::numeric_limits<long\
    \ long>::lowest();\n        check(Mn::e() == std::pair<long long, long long>(INF,\
    \ -1) && Mx::e() == std::pair<long long, long long>(NINF, -1), \"MinWith/MaxWith::e\"\
    );\n        check(Mn::op(Mn::e(), {INF, 3}) == std::pair<long long, long long>(INF,\
    \ 3) && Mn::op({INF, 3}, Mn::e()) == std::pair<long long, long long>(INF, 3),\
    \ \"MinWith e \u306F\u5358\u4F4D\u5143\");\n        check(Mx::op(Mx::e(), {NINF,\
    \ 3}) == std::pair<long long, long long>(NINF, 3) && Mx::op({NINF, 3}, Mx::e())\
    \ == std::pair<long long, long long>(NINF, 3), \"MaxWith e \u306F\u5358\u4F4D\u5143\
    \");\n        for (int rep = 0; rep < 200 && ok; rep++) {\n            int n =\
    \ rng() % 20 + 1;\n            std::vector<long long> a(n);\n            for (auto&\
    \ x : a) x = rng() % 3 == 0 ? (rng() % 2 ? INF : NINF) : static_cast<long long>(rng()\
    \ % 5);\n            std::vector<std::pair<long long, long long>> init(n);\n \
    \           for (int i = 0; i < n; i++) init[i] = {a[i], i};\n            SegTree<Mn>\
    \ mn(init);\n            SegTree<Mx> mx(init);\n            for (int q = 0; q\
    \ < 30; q++) {\n                int l = rng() % (n + 1), r = rng() % (n + 1);\n\
    \                if (l > r) std::swap(l, r);\n                std::pair<long long,\
    \ long long> emn(INF, -1), emx(NINF, -1);\n                for (int i = l; i <\
    \ r; i++) {\n                    if (emn.second == -1 || a[i] < emn.first) emn\
    \ = {a[i], i};\n                    if (emx.second == -1 || a[i] > emx.first)\
    \ emx = {a[i], i};\n                }\n                check(mn.prod(l, r) ==\
    \ emn, \"MinWith prod\");\n                check(mx.prod(l, r) == emx, \"MaxWith\
    \ prod\");\n            }\n        }\n    }\n\n    if (ok) std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// monoid.hpp / group.hpp \u306E\u30E2\u30CE\u30A4\u30C9\u30FB\u7FA4\u3068\
    \ SegTree \u306E\u7D30\u304B\u3044\u6A5F\u80FD\u3092\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/algebra/monoid.hpp\"\
    \n\n#include <array>\n#include <deque>\n#include <forward_list>\n#include <iostream>\n\
    #include <limits>\n#include <list>\n#include <random>\n#include <sstream>\n#include\
    \ <string>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\n\
    #include \"../../../src/algebra/group.hpp\"\n#include \"../../../src/data_structures/dual-segtree.hpp\"\
    \n#include \"../../../src/data_structures/fenwick-tree.hpp\"\n#include \"../../../src/data_structures/imos.hpp\"\
    \n#include \"../../../src/data_structures/lazy-segtree.hpp\"\n#include \"../../../src/data_structures/link-cut-tree.hpp\"\
    \n#include \"../../../src/data_structures/monoid-unionfind.hpp\"\n#include \"\
    ../../../src/data_structures/persistent-lazy-segtree.hpp\"\n#include \"../../../src/data_structures/persistent-segtree.hpp\"\
    \n#include \"../../../src/data_structures/potentialized-unionfind.hpp\"\n#include\
    \ \"../../../src/data_structures/rbst.hpp\"\n#include \"../../../src/data_structures/segtree-beats.hpp\"\
    \n#include \"../../../src/data_structures/segtree.hpp\"\n#include \"../../../src/data_structures/sortable-segtree.hpp\"\
    \n#include \"../../../src/data_structures/sparse-table.hpp\"\n\nbool ok = true;\n\
    void check(bool cond, const char* what) {\n    if (!cond && ok) std::cerr << \"\
    failed: \" << what << std::endl;\n    if (!cond) ok = false;\n}\n\n// SegTree<M>\
    \ \u3092\u3001\u914D\u5217\u3068\u6F14\u7B97 op \u3067\u611A\u76F4\u306B\u8A08\
    \u7B97\u3057\u305F\u7D50\u679C\u3068\u30E9\u30F3\u30C0\u30E0\u306A\u64CD\u4F5C\
    \u5217\u3067\u6BD4\u3079\u308B\n// size\u30FBconst \u306A operator[]\u30FBall_prod\u30FB\
    os << seg \u3082\u78BA\u304B\u3081\u308B\ntemplate <typename M, typename Op, typename\
    \ Gen>\nvoid test_segtree(Op op, typename M::S e, Gen gen, std::mt19937_64& rng,\
    \ const char* name) {\n    using S = typename M::S;\n    for (int rep = 0; rep\
    \ < 200 && ok; rep++) {\n        int n = rng() % 20 + 1;\n        std::vector<S>\
    \ a(n);\n        for (auto& x : a) x = gen();\n        SegTree<M> seg(a);\n  \
    \      check(seg.size() == n, name);\n        for (int q = 0; q < 50 && ok; q++)\
    \ {\n            int t = rng() % 3;\n            if (t == 0) {\n             \
    \   int k = rng() % n;\n                S x = gen();\n                seg.set(k,\
    \ x);\n                a[k] = x;\n            } else if (t == 1) {\n         \
    \       int k = rng() % n;\n                S x = gen();\n                seg.apply(k,\
    \ x);\n                a[k] = op(a[k], x);\n            } else {\n           \
    \     int l = rng() % (n + 1), r = rng() % (n + 1);\n                if (l > r)\
    \ std::swap(l, r);\n                S expect = e;\n                for (int i\
    \ = l; i < r; i++) expect = op(expect, a[i]);\n                check(seg.prod(l,\
    \ r) == expect, name);\n            }\n        }\n        S all = e;\n       \
    \ for (int i = 0; i < n; i++) all = op(all, a[i]);\n        check(seg.all_prod()\
    \ == all, name);\n        const SegTree<M>& cseg = seg;\n        std::ostringstream\
    \ os, expect;\n        for (int i = 0; i < n; i++) {\n            check(cseg[i]\
    \ == a[i], name);\n            if (i != 0) expect << ' ';\n            expect\
    \ << a[i];\n        }\n        os << cseg;\n        check(os.str() == expect.str(),\
    \ name);\n    }\n}\n\nstruct ExplicitSum {\n    struct S {\n        long long\
    \ value;\n        S() : value(0) {}\n        explicit S(long long x) : value(x)\
    \ {}\n    };\n    static S op(const S& a, const S& b) { return S(a.value + b.value);\
    \ }\n    static S e() { return S(0); }\n};\n\nstruct ExplicitAddSum : ExplicitSum\
    \ {\n    using F = long long;\n    static S mapping(F f, const S& x, long long\
    \ len) { return S(x.value + f * len); }\n    static F composition(F f, F g) {\
    \ return f + g; }\n    static F id() { return 0; }\n    static F inv(F f) { return\
    \ -f; }\n};\n\nstruct ExplicitGroup : ExplicitSum {\n    static S inv(const S&\
    \ x) { return S(-x.value); }\n};\n\nstruct ExplicitMin : ExplicitSum {\n    static\
    \ S op(const S& a, const S& b) { return S(std::min(a.value, b.value)); }\n   \
    \ static S e() { return S(std::numeric_limits<long long>::max()); }\n};\n\nstruct\
    \ ExplicitBeats : ExplicitAddSum {\n    static std::pair<bool, S> mapping(F f,\
    \ const S& x, long long len) { return {false, ExplicitAddSum::mapping(f, x, len)};\
    \ }\n};\n\n// begin \u306F\u4E00\u5EA6\u3060\u3051\u3002\u30A4\u30C6\u30EC\u30FC\
    \u30BF\u306E\u5F8C\u7F6E ++ \u306F\u5024\u3092\u8FD4\u3055\u305A\u3001\u7D42\u7AEF\
    \u306E\u578B\u3082\u7570\u306A\u308B\u3002\nstruct SizedInputRange {\n    int\
    \ values[3] = {2, -5, 4};\n    int pos = 0;\n    bool begun = false;\n    struct\
    \ Sentinel {};\n    struct Iterator {\n        using value_type = int;\n     \
    \   using difference_type = long long;\n        using iterator_category = std::input_iterator_tag;\n\
    \        SizedInputRange* range;\n        int operator*() const { return range->values[range->pos];\
    \ }\n        Iterator& operator++() {\n            ++range->pos;\n           \
    \ return *this;\n        }\n        void operator++(int) { ++*this; }\n      \
    \  friend bool operator==(Iterator it, Sentinel) { return it.range->pos == 3;\
    \ }\n        friend bool operator!=(Iterator it, Sentinel s) { return !(it ==\
    \ s); }\n        friend bool operator==(Sentinel s, Iterator it) { return it ==\
    \ s; }\n        friend bool operator!=(Sentinel s, Iterator it) { return !(it\
    \ == s); }\n    };\n    Iterator begin() {\n        check(!begun, \"sized input\
    \ range is traversed once\");\n        begun = true;\n        return {this};\n\
    \    }\n    Sentinel end() const { return {}; }\n    long long size() const {\
    \ return 3; }\n};\n\ntemplate <template <typename> class Tree, typename M>\nvoid\
    \ test_converting_tree(M m) {\n    auto verify_range = [&](auto&& r) {\n     \
    \   Tree tree(std::forward<decltype(r)>(r), m);\n        check(tree.size() ==\
    \ 3 && tree.get(0).value == 2 && tree.get(1).value == -5 && tree.get(2).value\
    \ == 4,\n              \"tree family sized range / CTAD\");\n    };\n    int raw[]\
    \ = {2, -5, 4};\n    const std::array<int, 3> arr = {2, -5, 4};\n    verify_range(raw);\n\
    \    verify_range(arr);\n    verify_range(std::list<int>{2, -5, 4});\n    verify_range(std::deque<int>{2,\
    \ -5, 4});\n    verify_range(SizedInputRange{});\n    Tree<M> empty_array(std::array<int,\
    \ 0>{});\n    check(empty_array.size() == 0, \"tree family empty array\");\n \
    \   static_assert(!std::is_constructible_v<Tree<M>, std::forward_list<int>&>);\n\
    \    static_assert(!std::is_constructible_v<Tree<M>, std::array<std::string, 3>&>);\n\
    #if __cplusplus >= 202002L\n    verify_range(std::views::iota(0, 3) | std::views::transform([&](int\
    \ i) { return raw[i]; }));\n#endif\n    static_assert(std::is_constructible_v<Tree<M>,\
    \ const std::vector<int>&, M>);\n    static_assert(!std::is_constructible_v<Tree<M>,\
    \ const std::vector<std::string>&, M>);\n    Tree seg(std::vector<int>{2, -5,\
    \ 4}, m);\n    check(seg.size() == 3 && seg.get(0).value == 2 && seg.get(1).value\
    \ == -5 && seg.get(2).value == 4,\n          \"segtree family explicit conversion\
    \ / CTAD\");\n    Tree<M> empty(std::vector<int>{});\n    check(empty.size() ==\
    \ 0, \"segtree family conversion empty\");\n    Tree<M> same(std::vector<typename\
    \ M::S>{typename M::S(7)});\n    check(same.get(0).value == 7, \"segtree family\
    \ vector<S>\");\n    Tree<M> list({typename M::S(8), typename M::S(9)});\n   \
    \ check(list.get(1).value == 9, \"segtree family initializer list\");\n}\n\ntemplate\
    \ <class R>\nvoid test_segtree_range(R&& r) {\n    SegTree seg(std::forward<R>(r),\
    \ ExplicitSum{});\n    check(seg.size() == 3 && seg.prod(0, 3).value == 1 && seg.prod(1,\
    \ 3).value == -1, \"SegTree sized range / CTAD\");\n    seg.set(1, ExplicitSum::S(3));\n\
    \    check(seg.all_prod().value == 9, \"SegTree sized range update\");\n}\n\n\
    int main() {\n    {\n        int a[] = {2, -5, 4};\n        const std::array<int,\
    \ 3> b = {2, -5, 4};\n        test_segtree_range(a);\n        test_segtree_range(b);\n\
    \        test_segtree_range(std::list<int>{2, -5, 4});\n        test_segtree_range(std::deque<int>{2,\
    \ -5, 4});\n        SegTree<ExplicitSum> empty(std::array<int, 0>{});\n      \
    \  check(empty.size() == 0 && empty.all_prod().value == 0, \"SegTree empty range\"\
    );\n        SegTree braces({ExplicitSum::S(2), ExplicitSum::S(-5), ExplicitSum::S(4)},\
    \ ExplicitSum{});\n        check(braces.all_prod().value == 1, \"SegTree initializer\
    \ list / CTAD\");\n        SegTree<ExplicitSum> original(a);\n        auto copied\
    \ = original;\n        auto moved = std::move(copied);\n        check(moved.all_prod().value\
    \ == 1 && original.all_prod().value == 1, \"SegTree copy / move\");\n        SegTree\
    \ sized(3LL, ExplicitSum{});\n        check(sized.size() == 3 && sized.all_prod().value\
    \ == 0, \"SegTree size / CTAD\");\n        static_assert(!std::is_constructible_v<SegTree<ExplicitSum>,\
    \ std::forward_list<int>&>);\n        static_assert(!std::is_constructible_v<SegTree<ExplicitSum>,\
    \ std::array<std::string, 3>&>);\n#if __cplusplus >= 202002L\n        test_segtree_range(std::views::all(a));\n\
    \        test_segtree_range(std::views::iota(0, 3) | std::views::transform([&](int\
    \ i) { return a[i]; }));\n        SegTree view(a | std::views::take(2), ExplicitSum{});\n\
    \        check(view.size() == 2 && view.all_prod().value == -3, \"SegTree partial\
    \ view\");\n#endif\n    }\n\n    test_converting_tree<SegTree>(ExplicitSum{});\n\
    \    test_converting_tree<RBST>(ExplicitSum{});\n    test_converting_tree<RBST>(ExplicitAddSum{});\n\
    \    test_converting_tree<FenwickTree>(ExplicitGroup{});\n    test_converting_tree<SparseTable>(ExplicitMin{});\n\
    \    test_converting_tree<LinkCutTree>(ExplicitSum{});\n    test_converting_tree<SubtreeLinkCutTree>(ExplicitGroup{});\n\
    \    {\n        auto verify = [](auto&& r) {\n            MonoidUnionFind uf(std::forward<decltype(r)>(r),\
    \ ExplicitSum{});\n            uf.merge(0, 1);\n            check(uf.prod(0).value\
    \ == -3 && uf.prod(2).value == 4, \"MonoidUnionFind sized range / CTAD\");\n \
    \       };\n        int raw[] = {2, -5, 4};\n        verify(raw);\n        verify(std::list<int>{2,\
    \ -5, 4});\n        verify(SizedInputRange{});\n        std::vector<ExplicitSum::S>\
    \ owned{ExplicitSum::S(7)};\n        const auto* ptr = owned.data();\n       \
    \ MonoidUnionFind moved(std::move(owned), ExplicitSum{});\n        check(&moved.prod(0)\
    \ == ptr, \"MonoidUnionFind moves vector storage\");\n        Imos from_range(SizedInputRange{},\
    \ ExplicitAddSum{});\n        from_range.apply(0, 2, 3);\n        check(from_range.get(0).value\
    \ == 5 && from_range.get(1).value == -2 && from_range.get(2).value == 4,\n   \
    \           \"Imos sized input range / CTAD\");\n        Imos from_list(std::list<int>{2,\
    \ -5, 4}, ExplicitAddSum{});\n        check(from_list.get(1).value == -5, \"Imos\
    \ list\");\n        Imos<ExplicitAddSum> empty_range(std::array<int, 0>{});\n\
    \        static_assert(!std::is_constructible_v<Imos<ExplicitAddSum>, std::forward_list<int>&>);\n\
    \        static_assert(!std::is_constructible_v<MonoidUnionFind<ExplicitSum>,\
    \ const std::vector<std::string>&>);\n        MonoidUnionFind uf(std::vector<int>{2,\
    \ -5, 4}, ExplicitSum{});\n        uf.merge(0, 1);\n        check(uf.prod(0).value\
    \ == -3 && uf.prod(2).value == 4, \"MonoidUnionFind conversion / CTAD\");\n  \
    \      MonoidUnionFind<ExplicitSum> empty(std::vector<int>{});\n        check(empty.groups().empty(),\
    \ \"MonoidUnionFind conversion empty\");\n        Imos imos(std::vector<int>{2,\
    \ -5, 4}, ExplicitAddSum{});\n        imos.apply(0, 2, 3);\n        check(imos.get(0).value\
    \ == 5 && imos.get(1).value == -2 && imos.get(2).value == 4, \"Imos conversion\
    \ / CTAD\");\n        Imos<ExplicitAddSum> empty_imos(std::vector<int>{});\n \
    \       static_assert(!std::is_constructible_v<Imos<ExplicitAddSum>, const std::vector<std::string>&>);\n\
    \    }\n\n    test_converting_tree<LazySegTree>(ExplicitAddSum{});\n    test_converting_tree<DualSegTree>(ExplicitAddSum{});\n\
    \    test_converting_tree<PersistentSegTree>(ExplicitSum{});\n    test_converting_tree<PersistentLazySegTree>(ExplicitAddSum{});\n\
    \    test_converting_tree<SegTreeBeats>(ExplicitBeats{});\n    {\n        auto\
    \ verify = [](auto&& keys, auto&& values) {\n            SortableSegTree tree(std::forward<decltype(keys)>(keys),\
    \ std::forward<decltype(values)>(values), 3, ExplicitSum{});\n            tree.sort(0,\
    \ 3);\n            check(tree.prod(0, 1).value == -5 && tree.prod(0, 3).value\
    \ == 1, \"SortableSegTree sized ranges / sort / CTAD\");\n        };\n       \
    \ int keys[] = {2, 0, 1};\n        verify(keys, std::list<int>{2, -5, 4});\n \
    \       verify(std::list<int>{2, 0, 1}, SizedInputRange{});\n        SortableSegTree\
    \ braces({2, 0, 1}, {ExplicitSum::S(2), ExplicitSum::S(-5), ExplicitSum::S(4)},\
    \ 3, ExplicitSum{});\n        check(braces.prod(0, 3).value == 1, \"SortableSegTree\
    \ initializer lists / CTAD\");\n        SortableSegTree sorted(std::vector<long\
    \ long>{2, 0, 1}, std::vector<int>{2, -5, 4}, 3, ExplicitSum{});\n        sorted.sort(0,\
    \ 3);\n        check(sorted.prod(0, 1).value == -5 && sorted.prod(0, 3).value\
    \ == 1, \"SortableSegTree conversion / CTAD / sort\");\n        SortableSegTree<ExplicitSum>\
    \ empty(std::vector<long long>{}, std::vector<int>{}, 1);\n        check(empty.size()\
    \ == 0, \"SortableSegTree conversion empty\");\n    }\n\n    {\n        static_assert(std::is_constructible_v<SegTree<ExplicitSum>,\
    \ const std::vector<int>&>);\n        static_assert(!std::is_constructible_v<SegTree<ExplicitSum>,\
    \ const std::vector<std::string>&>);\n        SegTree seg(std::vector<int>{2,\
    \ -5, 4}, ExplicitSum{});\n        check(seg.prod(0, 3).value == 1 && seg.prod(1,\
    \ 3).value == -1, \"SegTree explicit conversion / CTAD\");\n        SegTree<ExplicitSum>\
    \ empty(std::vector<int>{});\n        check(empty.size() == 0 && empty.all_prod().value\
    \ == 0, \"SegTree conversion empty\");\n        SegTree<monoid::Sum<long long>>\
    \ ordinary({1, 2, 3});\n        check(ordinary.all_prod() == 6, \"SegTree initializer\
    \ list\");\n        SegTree<monoid::Sum<long long>> widened(std::vector<int>{1,\
    \ 2, 3});\n        check(widened.all_prod() == 6, \"SegTree arithmetic conversion\"\
    );\n    }\n\n    std::mt19937_64 rng(314);\n\n    // And / Or: \u5358\u4F4D\u5143\
    \u306F\u305D\u308C\u305E\u308C\u5168\u30D3\u30C3\u30C8 1 \u3068 0\n    check(monoid::And<unsigned>::e()\
    \ == ~0u, \"And::e\");\n    check(monoid::Or<unsigned>::e() == 0u, \"Or::e\");\n\
    \    auto gen_bits = [&] { return static_cast<unsigned>(rng() % 64); };\n    test_segtree<monoid::And<unsigned>>([](unsigned\
    \ a, unsigned b) { return a & b; }, ~0u, gen_bits, rng, \"And\");\n    test_segtree<monoid::Or<unsigned>>([](unsigned\
    \ a, unsigned b) { return a | b; }, 0u, gen_bits, rng, \"Or\");\n\n    // Parenthesis:\
    \ \u533A\u9593\u304C\u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\u3092 is_valid\
    \ \u3067\u5224\u5B9A\u3059\u308B\n    for (int rep = 0; rep < 300 && ok; rep++)\
    \ {\n        int n = rng() % 16 + 1;\n        std::string s(n, '(');\n       \
    \ for (char& c : s) c = rng() % 2 ? '(' : ')';\n        SegTree<monoid::Parenthesis>\
    \ seg(s);\n        for (int l = 0; l <= n; l++) {\n            for (int r = l;\
    \ r <= n; r++) {\n                int depth = 0, min_depth = 0;\n            \
    \    for (int i = l; i < r; i++) {\n                    depth += s[i] == '(' ?\
    \ 1 : -1;\n                    min_depth = std::min(min_depth, depth);\n     \
    \           }\n                auto p = seg.prod(l, r);\n                check(p.is_valid()\
    \ == (depth == 0 && min_depth == 0), \"Parenthesis::is_valid\");\n           \
    \     check(p.close == -min_depth && p.open == depth - min_depth, \"Parenthesis::op\"\
    );\n            }\n        }\n    }\n\n    // Affine: ==, !=, \u51FA\u529B\n \
    \   {\n        Affine<long long> f{2, 3}, g{2, 3}, h{2, 4}, id;\n        check(f\
    \ == g && !(f != g), \"Affine ==\");\n        check(f != h && !(f == h), \"Affine\
    \ !=\");\n        check(id == Affine<long long>{1, 0}, \"Affine default\");\n\
    \        std::ostringstream os;\n        os << f;\n        check(os.str() == \"\
    2 3\", \"Affine <<\");\n        // Composite \u3067\u5408\u6210\u3057\u305F\u7D50\
    \u679C\u304C\u95A2\u6570\u306E\u5408\u6210 a\u2218b \u3068\u4E00\u81F4\u3059\u308B\
    \u3002Reverse \u306F b\u2218a\n        for (int rep = 0; rep < 1000 && ok; rep++)\
    \ {\n            Affine<long long> a{static_cast<long long>(rng() % 7) - 3, static_cast<long\
    \ long>(rng() % 7) - 3};\n            Affine<long long> b{static_cast<long long>(rng()\
    \ % 7) - 3, static_cast<long long>(rng() % 7) - 3};\n            long long x =\
    \ static_cast<long long>(rng() % 7) - 3;\n            auto c = monoid::Composite<long\
    \ long>::op(a, b);\n            check(c(x) == a(b(x)), \"Composite op\");\n  \
    \          check(c == Affine<long long>{a.a * b.a, a.a * b.b + a.b}, \"Affine\
    \ == after op\");\n            auto d = monoid::Reverse<monoid::Composite<long\
    \ long>>().op(a, b);\n            check(d(x) == b(a(x)), \"Reverse<Composite>\
    \ op\");\n        }\n    }\n\n    // Clamp: ==, !=, \u5165\u51FA\u529B, \u65E2\
    \u5B9A\u5024\u306F\u6052\u7B49\u5199\u50CF\n    {\n        Clamp<long long> f{2,\
    \ 5}, g{2, 5}, h{2, 6}, id;\n        check(f == g && !(f != g), \"Clamp ==\");\n\
    \        check(f != h && !(f == h), \"Clamp !=\");\n        check(id(std::numeric_limits<long\
    \ long>::lowest()) == std::numeric_limits<long long>::lowest() && id(std::numeric_limits<long\
    \ long>::max()) == std::numeric_limits<long long>::max(), \"Clamp default\");\n\
    \        check(f(1) == 2 && f(3) == 3 && f(9) == 5, \"Clamp ()\");\n        //\
    \ {} \u3092\u6E21\u3059\u3068\u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057\u3002\
    1 \u3064\u306E\u5024\u304B\u3089\u306F\u6697\u9ED9\u306B\u5909\u63DB\u3057\u306A\
    \u3044\n        check((Clamp<long long>{0, {}} == Clamp<long long>{0, std::numeric_limits<long\
    \ long>::max()}), \"Clamp {lb, {}}\");\n        check((Clamp<long long>{{}, 0}\
    \ == Clamp<long long>{std::numeric_limits<long long>::lowest(), 0}), \"Clamp {{},\
    \ ub}\");\n        check((Clamp<long long>{{}, {}} == Clamp<long long>{}), \"\
    Clamp {{}, {}}\");\n        static_assert(!std::is_convertible_v<long long, Clamp<long\
    \ long>>);\n        static_assert(std::is_trivially_copyable_v<Clamp<long long>>);\n\
    \        static_assert(Clamp<int>{0, {}}(-5) == 0);\n        std::ostringstream\
    \ os;\n        os << f;\n        check(os.str() == \"2 5\", \"Clamp <<\");\n \
    \       std::istringstream is(\"-3 4\");\n        is >> f;\n        check(f ==\
    \ Clamp<long long>{-3, 4}, \"Clamp >>\");\n        // ClampComposite \u3067\u5408\
    \u6210\u3057\u305F\u7D50\u679C\u304C\u95A2\u6570\u306E\u5408\u6210 a\u2218b \u3068\
    \u4E00\u81F4\u3059\u308B\u3002Reverse \u306F b\u2218a\n        auto gen_clamp\
    \ = [&] {\n            long long lb = static_cast<long long>(rng() % 11) - 5,\
    \ ub = static_cast<long long>(rng() % 11) - 5;\n            if (lb > ub) std::swap(lb,\
    \ ub);\n            if (rng() % 4 == 0) lb = std::numeric_limits<long long>::lowest();\n\
    \            if (rng() % 4 == 0) ub = std::numeric_limits<long long>::max();\n\
    \            return Clamp<long long>{lb, ub};\n        };\n        for (int rep\
    \ = 0; rep < 1000 && ok; rep++) {\n            auto a = gen_clamp(), b = gen_clamp();\n\
    \            auto c = monoid::ClampComposite<long long>::op(a, b);\n         \
    \   auto d = monoid::Reverse<monoid::ClampComposite<long long>>().op(a, b);\n\
    \            check(c.lb <= c.ub, \"ClampComposite lb <= ub\");\n            check(monoid::ClampComposite<long\
    \ long>::op(a, monoid::ClampComposite<long long>::e()) == a, \"ClampComposite\
    \ e\");\n            check(monoid::ClampComposite<long long>::op(monoid::ClampComposite<long\
    \ long>::e(), a) == a, \"ClampComposite e\");\n            for (long long x =\
    \ -7; x <= 7; x++) {\n                check(c(x) == a(b(x)), \"ClampComposite\
    \ op\");\n                check(d(x) == b(a(x)), \"Reverse<ClampComposite> op\"\
    );\n            }\n        }\n        // SegTree \u306B\u4E57\u305B\u3066\u3001\
    \u533A\u9593\u306E\u95A2\u6570\u3092\u53F3\u304B\u3089\u9806\u306B\u9069\u7528\
    \u3057\u305F\u7D50\u679C\u3068\u6BD4\u3079\u308B\n        test_segtree<monoid::ClampComposite<long\
    \ long>>(\n            [](const Clamp<long long>& a, const Clamp<long long>& b)\
    \ { return monoid::ClampComposite<long long>::op(a, b); },\n            Clamp<long\
    \ long>{}, gen_clamp, rng, \"ClampComposite\");\n    }\n\n    // ClampAdd: ==,\
    \ !=, \u5165\u51FA\u529B, \u65E2\u5B9A\u5024\u306F\u6052\u7B49\u5199\u50CF\n \
    \   {\n        constexpr long long lowest = std::numeric_limits<long long>::lowest(),\
    \ highest = std::numeric_limits<long long>::max();\n        ClampAdd<long long>\
    \ f{2, 5, 1}, g{2, 5, 1}, h{2, 5, 0}, id;\n        check(f == g && !(f != g),\
    \ \"ClampAdd ==\");\n        check(f != h && !(f == h), \"ClampAdd !=\");\n  \
    \      check(id == ClampAdd<long long>{lowest, highest, 0} && id(lowest) == lowest\
    \ && id(highest) == highest, \"ClampAdd default\");\n        check(f(0) == 2 &&\
    \ f(2) == 3 && f(9) == 5, \"ClampAdd ()\");\n        // {} \u3092\u6E21\u3059\u3068\
    \u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057\u3002add \u306F\u7701\u7565\u3059\u308B\
    \u3068 0\u30021 \u3064\u306E\u5024\u304B\u3089\u306F\u6697\u9ED9\u306B\u5909\u63DB\
    \u3057\u306A\u3044\n        check((ClampAdd<long long>{{}, {}, 3} == ClampAdd<long\
    \ long>{lowest, highest, 3}), \"ClampAdd {{}, {}, add}\");\n        check((ClampAdd<long\
    \ long>{{}, 5} == ClampAdd<long long>{lowest, 5, 0}), \"ClampAdd {{}, ub}\");\n\
    \        check((ClampAdd<long long>{5, {}} == ClampAdd<long long>{5, highest,\
    \ 0}), \"ClampAdd {lb, {}}\");\n        static_assert(!std::is_convertible_v<long\
    \ long, ClampAdd<long long>>);\n        static_assert(std::is_trivially_copyable_v<ClampAdd<long\
    \ long>>);\n        static_assert(ClampAdd<int>{{}, 10, 3}(9) == 10);\n      \
    \  std::ostringstream os;\n        os << f;\n        check(os.str() == \"2 5 1\"\
    , \"ClampAdd <<\");\n        std::istringstream is(\"-3 4 -1\");\n        is >>\
    \ f;\n        check(f == ClampAdd<long long>{-3, 4, -1}, \"ClampAdd >>\");\n \
    \       // ClampAddComposite \u3067\u5408\u6210\u3057\u305F\u7D50\u679C\u304C\u95A2\
    \u6570\u306E\u5408\u6210 a\u2218b \u3068\u4E00\u81F4\u3059\u308B\u3002Reverse\
    \ \u306F b\u2218a\n        // \u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057 (\u578B\
    \u306E\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024) \u306B\u8DB3\u3057\u3066\u3082\
    \u3042\u3075\u308C\u306A\u3044 (UBSan \u3067\u78BA\u304B\u3081\u308B)\n      \
    \  auto gen_clamp_add = [&] {\n            long long lb = static_cast<long long>(rng()\
    \ % 11) - 5, ub = static_cast<long long>(rng() % 11) - 5;\n            if (lb\
    \ > ub) std::swap(lb, ub);\n            if (rng() % 3 == 0) lb = lowest;\n   \
    \         if (rng() % 3 == 0) ub = highest;\n            return ClampAdd<long\
    \ long>{lb, ub, static_cast<long long>(rng() % 7) - 3};\n        };\n        for\
    \ (int rep = 0; rep < 1000 && ok; rep++) {\n            auto a = gen_clamp_add(),\
    \ b = gen_clamp_add();\n            auto c = monoid::ClampAddComposite<long long>::op(a,\
    \ b);\n            auto d = monoid::Reverse<monoid::ClampAddComposite<long long>>().op(a,\
    \ b);\n            check(c.lb <= c.ub, \"ClampAddComposite lb <= ub\");\n    \
    \        check(monoid::ClampAddComposite<long long>::op(a, monoid::ClampAddComposite<long\
    \ long>::e()) == a, \"ClampAddComposite e\");\n            check(monoid::ClampAddComposite<long\
    \ long>::op(monoid::ClampAddComposite<long long>::e(), a) == a, \"ClampAddComposite\
    \ e\");\n            for (long long x = -9; x <= 9; x++) {\n                check(c(x)\
    \ == a(b(x)), \"ClampAddComposite op\");\n                check(d(x) == b(a(x)),\
    \ \"Reverse<ClampAddComposite> op\");\n            }\n        }\n        // SegTree\
    \ \u306B\u4E57\u305B\u308B (\u52A0\u7B97\u304C\u7A4D\u307F\u91CD\u306A\u3063\u3066\
    \u3082\u3042\u3075\u308C\u306A\u3044\u7BC4\u56F2\u3067)\n        test_segtree<monoid::ClampAddComposite<long\
    \ long>>(\n            [](const ClampAdd<long long>& a, const ClampAdd<long long>&\
    \ b) { return monoid::ClampAddComposite<long long>::op(a, b); },\n           \
    \ ClampAdd<long long>{}, gen_clamp_add, rng, \"ClampAddComposite\");\n    }\n\n\
    \    // group::Xor: inv \u306F\u81EA\u5206\u81EA\u8EAB\u3002PotentializedUnionFind\
    \ \u306B\u4E57\u305B\u3066 xor \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3068\
    \u6BD4\u3079\u308B\n    for (int rep = 0; rep < 300 && ok; rep++) {\n        int\
    \ n = rng() % 12 + 1;\n        std::vector<int> pot(n);\n        for (int& p :\
    \ pot) p = rng() % 1024;\n        std::vector<int> comp(n);\n        for (int\
    \ i = 0; i < n; i++) comp[i] = i;\n        PotentializedUnionFind<group::Xor<int>>\
    \ uf(n);\n        for (int q = 0; q < 30 && ok; q++) {\n            int a = rng()\
    \ % n, b = rng() % n;\n            if (rng() % 2) {\n                uf.merge(a,\
    \ b, pot[a] ^ pot[b]);\n                int ca = comp[a], cb = comp[b];\n    \
    \            for (int& c : comp)\n                    if (c == cb) c = ca;\n \
    \           } else {\n                check(uf.same(a, b) == (comp[a] == comp[b]),\
    \ \"group::Xor same\");\n                if (comp[a] == comp[b]) check(uf.diff(a,\
    \ b) == (pot[a] ^ pot[b]), \"group::Xor diff\");\n            }\n        }\n \
    \       int x = rng() % 1024;\n        check(group::Xor<int>::inv(x) == x, \"\
    group::Xor::inv\");\n    }\n\n    // PrefixSumMax / PrefixSumMin / PrefixSumMinMax\
    \ / SuffixSumMax / SuffixSumMin / MaxSubarraySum: \u7A7A\u3092\u542B\u3080 prefix\u30FB\
    suffix\u30FB\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\n    for (int rep = 0;\
    \ rep < 300 && ok; rep++) {\n        int n = rng() % 12 + 1;\n        std::vector<long\
    \ long> a(n);\n        for (auto& x : a) x = static_cast<long long>(rng() % 21)\
    \ - 10;\n        SegTree<monoid::PrefixSumMax<long long>> pmax(a);\n        SegTree<monoid::PrefixSumMin<long\
    \ long>> pmin(a);\n        using PM = monoid::PrefixSumMinMax<>;\n        SegTree<PM>\
    \ pminmax(a);\n        SegTree<monoid::SuffixSumMax<long long>> smax(a);\n   \
    \     SegTree<monoid::SuffixSumMin<long long>> smin(a);\n        SegTree<monoid::MaxSubarraySum<long\
    \ long>> msub(a);\n        for (int q = 0; q < 10 && ok; q++) {\n            int\
    \ k = rng() % n;\n            a[k] = static_cast<long long>(rng() % 21) - 10;\n\
    \            pminmax.set(k, a[k]);\n            pmax.set(k, a[k]), pmin.set(k,\
    \ a[k]), smax.set(k, a[k]), smin.set(k, a[k]), msub.set(k, a[k]);\n          \
    \  for (int l = 0; l <= n; l++) {\n                for (int r = l; r <= n; r++)\
    \ {\n                    long long sum = 0, pre_max = 0, pre_min = 0, suf_max\
    \ = 0, suf_min = 0, best = 0;\n                    for (int i = l; i < r; i++)\
    \ {\n                        sum += a[i];\n                        pre_max = std::max(pre_max,\
    \ sum), pre_min = std::min(pre_min, sum);\n                        long long s\
    \ = 0;\n                        for (int j = i; j < r; j++) {\n              \
    \              s += a[j];\n                            best = std::max(best, s);\n\
    \                        }\n                    }\n                    long long\
    \ s = 0;\n                    for (int i = r - 1; i >= l; i--) {\n           \
    \             s += a[i];\n                        suf_max = std::max(suf_max,\
    \ s), suf_min = std::min(suf_min, s);\n                    }\n               \
    \     check(pmax.prod(l, r) == monoid::PrefixSumMax<long long>::S(sum, pre_max),\
    \ \"PrefixSumMax\");\n                    check(pmin.prod(l, r) == monoid::PrefixSumMin<long\
    \ long>::S(sum, pre_min), \"PrefixSumMin\");\n                    check(pminmax.prod(l,\
    \ r) == PM::S(sum, pre_min, pre_max), \"PrefixSumMinMax\");\n                \
    \    check(PM::op(PM::e(), pminmax.prod(l, r)) == pminmax.prod(l, r) &&\n    \
    \                          PM::op(pminmax.prod(l, r), PM::e()) == pminmax.prod(l,\
    \ r),\n                          \"PrefixSumMinMax identity\");\n            \
    \        int m = (l + r) / 2;\n                    check(PM::op(pminmax.prod(l,\
    \ m), pminmax.prod(m, r)) == pminmax.prod(l, r), \"PrefixSumMinMax concatenate\"\
    );\n                    check(smax.prod(l, r) == monoid::SuffixSumMax<long long>::S(sum,\
    \ suf_max), \"SuffixSumMax\");\n                    check(smin.prod(l, r) == monoid::SuffixSumMin<long\
    \ long>::S(sum, suf_min), \"SuffixSumMin\");\n                    check(msub.prod(l,\
    \ r) == monoid::MaxSubarraySum<long long>::S(sum, pre_max, suf_max, best), \"\
    MaxSubarraySum\");\n                }\n            }\n            // max_right:\
    \ l \u304B\u3089\u59CB\u3081\u3066\u548C\u304C\u521D\u3081\u3066\u6B63\u306B\u306A\
    \u308B\u4F4D\u7F6E\n            int l = rng() % (n + 1);\n            long long\
    \ sum = 0;\n            int expect = n;\n            for (int i = l; i < n; i++)\
    \ {\n                sum += a[i];\n                if (sum > 0) {\n          \
    \          expect = i;\n                    break;\n                }\n      \
    \      }\n            check(pmax.max_right(l, [](const auto& s) { return s.max\
    \ <= 0; }) == expect, \"PrefixSumMax max_right\");\n        }\n    }\n\n    //\
    \ MinWith / MaxWith: \u7A7A\u533A\u9593\u306F\u4F4D\u7F6E -1\u3002\u5024\u304C\
    \u578B\u306E\u6700\u5927\u5024 (\u6700\u5C0F\u5024) \u306E\u8981\u7D20\u304C\u3042\
    \u3063\u3066\u3082\u5358\u4F4D\u5143\u3068\u3057\u3066\u50CD\u304D\u3001\u540C\
    \u3058\u5024\u306A\u3089\u5DE6\u5074\n    {\n        using Mn = monoid::MinWith<long\
    \ long>;\n        using Mx = monoid::MaxWith<long long>;\n        constexpr long\
    \ long INF = std::numeric_limits<long long>::max(), NINF = std::numeric_limits<long\
    \ long>::lowest();\n        check(Mn::e() == std::pair<long long, long long>(INF,\
    \ -1) && Mx::e() == std::pair<long long, long long>(NINF, -1), \"MinWith/MaxWith::e\"\
    );\n        check(Mn::op(Mn::e(), {INF, 3}) == std::pair<long long, long long>(INF,\
    \ 3) && Mn::op({INF, 3}, Mn::e()) == std::pair<long long, long long>(INF, 3),\
    \ \"MinWith e \u306F\u5358\u4F4D\u5143\");\n        check(Mx::op(Mx::e(), {NINF,\
    \ 3}) == std::pair<long long, long long>(NINF, 3) && Mx::op({NINF, 3}, Mx::e())\
    \ == std::pair<long long, long long>(NINF, 3), \"MaxWith e \u306F\u5358\u4F4D\u5143\
    \");\n        for (int rep = 0; rep < 200 && ok; rep++) {\n            int n =\
    \ rng() % 20 + 1;\n            std::vector<long long> a(n);\n            for (auto&\
    \ x : a) x = rng() % 3 == 0 ? (rng() % 2 ? INF : NINF) : static_cast<long long>(rng()\
    \ % 5);\n            std::vector<std::pair<long long, long long>> init(n);\n \
    \           for (int i = 0; i < n; i++) init[i] = {a[i], i};\n            SegTree<Mn>\
    \ mn(init);\n            SegTree<Mx> mx(init);\n            for (int q = 0; q\
    \ < 30; q++) {\n                int l = rng() % (n + 1), r = rng() % (n + 1);\n\
    \                if (l > r) std::swap(l, r);\n                std::pair<long long,\
    \ long long> emn(INF, -1), emx(NINF, -1);\n                for (int i = l; i <\
    \ r; i++) {\n                    if (emn.second == -1 || a[i] < emn.first) emn\
    \ = {a[i], i};\n                    if (emx.second == -1 || a[i] > emx.first)\
    \ emx = {a[i], i};\n                }\n                check(mn.prod(l, r) ==\
    \ emn, \"MinWith prod\");\n                check(mx.prod(l, r) == emx, \"MaxWith\
    \ prod\");\n            }\n        }\n    }\n\n    if (ok) std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  dependsOn:
  - src/algebra/monoid.hpp
  - src/algebra/group.hpp
  - src/data_structures/dual-segtree.hpp
  - src/algebra/acted-monoid.hpp
  - src/utility/traits.hpp
  - src/data_structures/fenwick-tree.hpp
  - src/data_structures/imos.hpp
  - src/data_structures/lazy-segtree.hpp
  - src/data_structures/link-cut-tree.hpp
  - src/data_structures/monoid-unionfind.hpp
  - src/data_structures/unionfind.hpp
  - src/data_structures/persistent-lazy-segtree.hpp
  - src/data_structures/persistent-segtree.hpp
  - src/data_structures/potentialized-unionfind.hpp
  - src/data_structures/rbst.hpp
  - src/data_structures/segtree-beats.hpp
  - src/algebra/beats-acted-monoid.hpp
  - src/data_structures/segtree.hpp
  - src/data_structures/sortable-segtree.hpp
  - src/data_structures/fast-set.hpp
  - src/data_structures/sparse-table.hpp
  isVerificationFile: true
  path: test/unittest/algebra/monoid.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 04:55:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/algebra/monoid.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/algebra/monoid.test.cpp
- /verify/test/unittest/algebra/monoid.test.cpp.html
title: test/unittest/algebra/monoid.test.cpp
---
