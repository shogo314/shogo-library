---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree-beats.hpp
    title: Segment Tree Beats
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/algebra/beats-acted-monoid.test.cpp
    title: test/unittest/algebra/beats-acted-monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/dual-segtree.test.cpp
    title: test/unittest/data_structures/dual-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/segtree-beats.test.cpp
    title: test/unittest/data_structures/segtree-beats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/range-chmin-chmax-add-range-sum.1.test.cpp
    title: test/yosupo/data_structure/range-chmin-chmax-add-range-sum.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/range-chmin-chmax-add-range-sum.2.test.cpp
    title: test/yosupo/data_structure/range-chmin-chmax-add-range-sum.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/range-chmin-chmax-add-range-sum.3.test.cpp
    title: test/yosupo/data_structure/range-chmin-chmax-add-range-sum.3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment Tree Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\
      \u30E2\u30CE\u30A4\u30C9"
    links: []
  bundledCode: "#line 2 \"src/algebra/beats-acted-monoid.hpp\"\n\n/**\n * @file beats-acted-monoid.hpp\n\
    \ * @brief Segment Tree Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/acted-monoid.hpp) \u3068\u540C\u3058\u30E1\u30F3\u30D0\u3092\u6301\u3064\
    \u304C\u3001\n * mapping \u306F std::pair<bool, S> (\u4F5C\u7528\u306B\u5931\u6557\
    \u3057\u305F\u304B, \u4F5C\u7528\u5F8C\u306E\u5024) \u3092\u8FD4\u3059\n * data_structures/segtree-beats.hpp\
    \ \u306B\u6E21\u3057\u3066\u4F7F\u3046\n */\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <utility>\n\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n\
    \ * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n\
    \ * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\
    \u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n\
    \ * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\
    \u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\
    \u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\
    \u3059)\n */\n\n#line 15 \"src/algebra/monoid.hpp\"\n#include <array>\n#include\
    \ <cstddef>\n#include <istream>\n#line 19 \"src/algebra/monoid.hpp\"\n#include\
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
    \ T) -> Monoid<T, Op>;\n#line 17 \"src/algebra/beats-acted-monoid.hpp\"\n\nnamespace\
    \ beats_acted_monoid {\n\n/**\n * @brief \u533A\u9593 chmin\u3001\u533A\u9593\u548C\
    \u30FB\u6700\u5927\u5024\n *\n * \u4F5C\u7528\u7D20\u306F chmin \u3059\u308B\u5024\
    \ (x <- min(x, f))\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u304B\u3089\u4F5C\
    \u308A\u3001sum, max1 \u3067\u533A\u9593\u548C\u30FB\u6700\u5927\u5024\u3092\u53D6\
    \u5F97\u3059\u308B\n * \u7A7A\u306E\u533A\u9593\u3067\u306F max1 = numeric_limits<T>::lowest()\n\
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
    \n}  // namespace beats_acted_monoid\n"
  code: "#pragma once\n\n/**\n * @file beats-acted-monoid.hpp\n * @brief Segment Tree\
    \ Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n *\n\
    \ * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\
    \ \u3068\u540C\u3058\u30E1\u30F3\u30D0\u3092\u6301\u3064\u304C\u3001\n * mapping\
    \ \u306F std::pair<bool, S> (\u4F5C\u7528\u306B\u5931\u6557\u3057\u305F\u304B\
    , \u4F5C\u7528\u5F8C\u306E\u5024) \u3092\u8FD4\u3059\n * data_structures/segtree-beats.hpp\
    \ \u306B\u6E21\u3057\u3066\u4F7F\u3046\n */\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <utility>\n\n#include \"monoid.hpp\"\n\nnamespace beats_acted_monoid\
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
    \n}  // namespace beats_acted_monoid\n"
  dependsOn:
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/algebra/beats-acted-monoid.hpp
  requiredBy:
  - src/data_structures/segtree-beats.hpp
  timestamp: '2026-10-19 12:29:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/segtree-beats.test.cpp
  - test/unittest/data_structures/dual-segtree.test.cpp
  - test/unittest/algebra/beats-acted-monoid.test.cpp
  - test/yosupo/data_structure/range-chmin-chmax-add-range-sum.2.test.cpp
  - test/yosupo/data_structure/range-chmin-chmax-add-range-sum.3.test.cpp
  - test/yosupo/data_structure/range-chmin-chmax-add-range-sum.1.test.cpp
documentation_of: src/algebra/beats-acted-monoid.hpp
layout: document
title: "Segment Tree Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
  \u30C9"
---

[Segment Tree Beats](../data_structures/segtree-beats.hpp) に渡す作用素付きモノイドです。メンバは [作用素付きモノイド](acted-monoid.hpp) と同じですが、`mapping` は `std::pair<bool, S>` (作用に失敗したか, 作用後の値) を返すので、遅延伝搬セグメント木には渡せません。

```cpp
using A = beats_acted_monoid::ChminChmaxAddSum<long long>;
SegTreeBeats<A> seg(std::vector<A::S>(a.begin(), a.end()));  // a は std::vector<long long>
seg.apply(l, r, A::chmin(x));   // [l, r) を min(a[i], x) に
seg.apply(l, r, A::add(x));     // [l, r) に x を足す
A::S s = seg.prod(l, r);
s.sum; s.max1; s.min1;          // [l, r) の和、最大値、最小値
```

## 一覧 (`namespace beats_acted_monoid`)

| 作用素付きモノイド | 作用 | 取得 | 作用素の型 `F` |
|---|---|---|---|
| `ChminSum<T>` | 区間 chmin | 区間和・最大値 | `T` |
| `ChmaxSum<T>` | 区間 chmax | 区間和・最小値 | `T` |
| `ChminChmaxAddSum<T>` | 区間 chmin・chmax・加算・代入 | 区間和・最大値・最小値 | [`ClampAdd<T>`](monoid.hpp) |

## 区間 chmin `ChminSum<T>`・区間 chmax `ChmaxSum<T>`

作用素は chmin (chmax) する値そのものです。`seg.apply(l, r, x)` で $[l, r)$ の各値を $\min(a_i, x)$ ($\max(a_i, x)$) にします。

要素 `S` は `S(x)` で値 `x` の 1 要素から作ります。`ChminSum` のメンバ `sum`、`max1` が区間和・最大値です。ほかに 2 番目の最大値 `max2`、最大値の個数 `max_cnt` を持ちます。`ChmaxSum` は同様に `sum`、`min1`、`min2`、`min_cnt` を持ちます。空の区間では `max1` が `numeric_limits<T>::lowest()`、`min1` が `numeric_limits<T>::max()` です。

作用が chmin だけ (chmax だけ) なら、`ChminChmaxAddSum` より 3〜4 倍ほど速く動きます。計算量は償却 $O(\log n)$ です。

## 区間 chmin・chmax・加算・代入 `ChminChmaxAddSum<T>`

作用素 `F` は [`ClampAdd<T>`](monoid.hpp) で、`F{lb, ub, add}` は $x \leftarrow \mathrm{clamp}(x + \mathit{add}, \mathit{lb}, \mathit{ub})$ を表します ($\mathit{lb} \le \mathit{ub}$)。次の static 関数で作ります。

| 関数 | 作用 |
|---|---|
| `chmin(b)` | $x \leftarrow \min(x, b)$ |
| `chmax(b)` | $x \leftarrow \max(x, b)$ |
| `add(b)` | $x \leftarrow x + b$ |
| `update(b)` | $x \leftarrow b$ |

要素 `S` は `S(x)` で値 `x` の 1 要素から作ります。メンバ `sum`、`max1`、`min1` が区間和・最大値・最小値です。ほかに 2 番目の最大値 `max2`、2 番目の最小値 `min2`、最大値・最小値の個数 `max_cnt`、`min_cnt` を持ちます。空の区間では `max1` が `numeric_limits<T>::lowest()`、`min1` が `numeric_limits<T>::max()` です。

- `T` は符号付き整数を想定しています。値に足し続けて `numeric_limits<T>` の端に届くとオーバーフローします。
- 計算量は、作用が chmin・chmax だけなら償却 $O(\log n)$、加算もあると償却 $O(\log^2 n)$ です。

## 関連

- これを渡して使うデータ構造は [Segment Tree Beats](../data_structures/segtree-beats.hpp)
- 作用が常に成功する場合は [作用素付きモノイド](acted-monoid.hpp)
