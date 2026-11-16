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
    path: test/unittest/algebra/beats-acted-monoid-extended.test.cpp
    title: test/unittest/algebra/beats-acted-monoid-extended.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/algebra/beats-acted-monoid.test.cpp
    title: test/unittest/algebra/beats-acted-monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/algebra/monoid.test.cpp
    title: test/unittest/algebra/monoid.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/range-chmin-chmax-add-range-sum.4.test.cpp
    title: test/yosupo/data_structure/range-chmin-chmax-add-range-sum.4.test.cpp
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
    \ <array>\n#include <cassert>\n#include <limits>\n#include <numeric>\n#include\
    \ <optional>\n#include <type_traits>\n#include <utility>\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#line 16 \"src/algebra/monoid.hpp\"\n#include <cstddef>\n\
    #include <istream>\n#line 21 \"src/algebra/monoid.hpp\"\n#include <ostream>\n\
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
    \ return S{}; }\n};\n\n/**\n * @brief \u7A4D\n */\ntemplate <typename T>\nstruct\
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
    \ T = long long>\nstruct MinMax {\n    struct S {\n        T min, max;\n     \
    \   constexpr S() : min(std::numeric_limits<T>::max()), max(std::numeric_limits<T>::lowest())\
    \ {}\n        constexpr S(const T& x) : min(x), max(x) {}\n        constexpr S(const\
    \ T& min, const T& max) : min(min), max(max) {}\n        friend constexpr bool\
    \ operator==(const S& a, const S& b) { return a.min == b.min && a.max == b.max;\
    \ }\n        friend constexpr bool operator!=(const S& a, const S& b) { return\
    \ !(a == b); }\n    };\n    static constexpr S op(const S& a, const S& b) { return\
    \ {std::min(a.min, b.min), std::max(a.max, b.max)}; }\n    static constexpr S\
    \ e() { return S(); }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\
    \n */\ntemplate <typename T>\nstruct Xor {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return a ^ b; }\n    static constexpr S e() {\
    \ return S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\u7A4D\n */\ntemplate <typename\
    \ T>\nstruct And {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a & b; }\n    static constexpr S e() { return ~S(0); }\n};\n\n\
    /**\n * @brief \u8AD6\u7406\u548C\n */\ntemplate <typename T>\nstruct Or {\n \
    \   using S = T;\n    static constexpr S op(const S& a, const S& b) { return a\
    \ | b; }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n * @brief \u6700\
    \u5927\u516C\u7D04\u6570 \u5358\u4F4D\u5143\u306F0\n */\ntemplate <typename T>\n\
    struct Gcd {\n    static_assert(std::is_integral_v<T>);\n    using S = T;\n  \
    \  static constexpr S op(const S& a, const S& b) { return std::gcd(a, b); }\n\
    \    static constexpr S e() { return S(0); }\n};\n\n/**\n * @brief \u6700\u5C0F\
    \u516C\u500D\u6570 \u5358\u4F4D\u5143\u306F1\n */\ntemplate <typename T>\nstruct\
    \ Lcm {\n    static_assert(std::is_integral_v<T>);\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return std::lcm(a, b); }\n    static\
    \ constexpr S e() { return S(1); }\n};\n\n/**\n * @brief {0, 1, ..., N-1} \u304B\
    \u3089\u81EA\u5206\u81EA\u8EAB\u3078\u306E\u5199\u50CF\u306E\u5408\u6210 (\u5909\
    \u63DB\u30E2\u30CE\u30A4\u30C9)\n *\n * \u8981\u7D20 f \u306F f[x] \u304C x \u306E\
    \u884C\u304D\u5148\u3092\u8868\u3059 std::array<int, N>\u3002\u5168\u5358\u5C04\
    \u3067\u306A\u304F\u3066\u3088\u3044\n * op(f, g) = f\u2218g (g \u3092\u5148\u306B\
    \u9069\u7528\u3059\u308B)\u3002\u533A\u9593 [l, r) \u306E\u7A4D\u306F f_l(...f_{r-1}(x))\
    \ \u3092\u8868\u3059\n * \u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3057\u305F\
    \u3044\u5834\u5408\u306F monoid::Reverse<monoid::Mapping<N>> \u3092\u4F7F\u3046\
    \n * \u4F8B: SegTree<monoid::Mapping<3>> seg(n); seg.set(i, {0, 2, 1});\n * swap(i,\
    \ j) \u3067 i \u3068 j \u3092\u5165\u308C\u66FF\u3048\u308B\u5199\u50CF\u3092\u4F5C\
    \u308C\u308B\n *\n * @tparam N \u5199\u50CF\u306E\u5B9A\u7FA9\u57DF\u30FB\u5024\
    \u57DF\u306E\u5927\u304D\u3055\n */\ntemplate <std::size_t N>\nstruct Mapping\
    \ {\n    using S = std::array<int, N>;\n    static constexpr S op(const S& f,\
    \ const S& g) {\n        S h{};\n        for (std::size_t x = 0; x < N; x++) h[x]\
    \ = f[g[x]];\n        return h;\n    }\n    static constexpr S e() {\n       \
    \ S h{};\n        for (std::size_t x = 0; x < N; x++) h[x] = static_cast<int>(x);\n\
    \        return h;\n    }\n    // i \u3068 j \u3092\u5165\u308C\u66FF\u3048\u3001\
    \u307B\u304B\u306F\u52D5\u304B\u3055\u306A\u3044\u5199\u50CF (\u4E92\u63DB)\n\
    \    static constexpr S swap(long long i, long long j) {\n        S h = e();\n\
    \        h[i] = static_cast<int>(j);\n        h[j] = static_cast<int>(i);\n  \
    \      return h;\n    }\n};\n\n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\
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
    suffix \u306E\u548C\u306E\u6700\u5927\u5024\u3001\u7A7A\u3092\u542B\u3080\u90E8\
    \u5206\u914D\u5217\u306E\u548C\u306E\u6700\u5927\u5024\n * S(x) \u3067\u5024 x\
    \ \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\
    \u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0, 0, 0}\n * \u9759\u7684\u306A\
    \u5217\u306B\u5BFE\u3057\u3066\u4E00\u5EA6\u3060\u3051\u6C42\u3081\u308B\u306A\
    \u3089 dp/maximum-subarray.hpp \u306E maximum_subarray\n */\ntemplate <typename\
    \ T>\nstruct MaxSubarraySum {\n    struct S {\n        T sum;     // \u533A\u9593\
    \u306E\u548C\n        T prefix;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\
    \u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        T suffix;  // \u7A7A\u3092\u542B\
    \u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        T\
    \ best;    // \u7A7A\u3092\u542B\u3080\u90E8\u5206\u914D\u5217\u306E\u548C\u306E\
    \u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        constexpr S() : sum(0), prefix(0),\
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
    \ T) -> Monoid<T, Op>;\n#line 22 \"src/algebra/beats-acted-monoid.hpp\"\n\nnamespace\
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
    \n/**\n * @brief \u533A\u9593 chmin\u30FBchmax\u30FB\u52A0\u7B97\u30FB\u4EE3\u5165\
    \u30010 \u4E57\u548C\u304B\u3089 K \u4E57\u548C\n * @tparam T \u6BD4\u8F03\u3059\
    \u308B\u5024\u306E\u578B (\u7B26\u53F7\u4ED8\u304D\u6574\u6570)\n * @tparam K\
    \ \u6700\u5927\u6B21\u6570\n * @tparam U \u4E57\u548C\u306E\u578B (modint \u3082\
    \u53EF)\n */\ntemplate <typename T = long long, long long K = 2, typename U =\
    \ T>\nstruct ChminChmaxAddPowerSum {\n    static_assert(K >= 0);\n    static_assert(std::is_integral_v<T>\
    \ && std::is_signed_v<T>);\n    static constexpr T lowest = std::numeric_limits<T>::lowest();\n\
    \    static constexpr T highest = std::numeric_limits<T>::max();\n    struct S\
    \ {\n        std::array<U, K + 1> val{};\n        T max1 = lowest, max2 = lowest,\
    \ min1 = highest, min2 = highest;\n        long long max_cnt = 0, min_cnt = 0;\n\
    \        constexpr S() = default;\n        constexpr S(const T& x) : max1(x),\
    \ min1(x), max_cnt(1), min_cnt(1) {\n            val[0] = U(1);\n            for\
    \ (long long i = 1; i <= K; ++i) val[i] = val[i - 1] * U(x);\n        }\n    \
    \    constexpr const U& operator[](long long i) const {\n            assert(0\
    \ <= i && i <= K);\n            return val[i];\n        }\n    };\n    using F\
    \ = ClampAdd<T>;\n    static constexpr F chmin(const T& b) { return {lowest, b,\
    \ T(0)}; }\n    static constexpr F chmax(const T& b) { return {b, highest, T(0)};\
    \ }\n    static constexpr F add(const T& b) { return {lowest, highest, b}; }\n\
    \    static constexpr F update(const T& b) { return {b, b, T(0)}; }\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if (a.max_cnt == 0) return\
    \ b;\n        if (b.max_cnt == 0) return a;\n        S res;\n        for (long\
    \ long i = 0; i <= K; ++i) res.val[i] = a.val[i] + b.val[i];\n        res.max1\
    \ = std::max(a.max1, b.max1);\n        res.max_cnt = (a.max1 == res.max1 ? a.max_cnt\
    \ : 0) + (b.max1 == res.max1 ? b.max_cnt : 0);\n        res.max2 = std::max(a.max1\
    \ == res.max1 ? a.max2 : a.max1, b.max1 == res.max1 ? b.max2 : b.max1);\n    \
    \    res.min1 = std::min(a.min1, b.min1);\n        res.min_cnt = (a.min1 == res.min1\
    \ ? a.min_cnt : 0) + (b.min1 == res.min1 ? b.min_cnt : 0);\n        res.min2 =\
    \ std::min(a.min1 == res.min1 ? a.min2 : a.min1, b.min1 == res.min1 ? b.min2 :\
    \ b.min1);\n        return res;\n    }\n    static constexpr S e() { return S();\
    \ }\n    static std::pair<bool, S> mapping(const F& f, const S& x, long long sz)\
    \ {\n        if (x.max_cnt == 0) return {false, x};\n        // \u5168\u8981\u7D20\
    \u304C\u540C\u3058\u5024\u306B\u306A\u308B\u5834\u5408\u306F\u3001\u52A0\u7B97\
    \u3084\u4E8C\u9805\u5C55\u958B\u3088\u308A\u5148\u306B\u51E6\u7406\u3059\u308B\
    \u3002\n        T lo = std::clamp(x.min1 + f.add, f.lb, f.ub);\n        T hi =\
    \ std::clamp(x.max1 + f.add, f.lb, f.ub);\n        if (lo == hi) {\n         \
    \   S res(lo);\n            for (auto& v : res.val) v *= U(sz);\n            res.max_cnt\
    \ = res.min_cnt = sz;\n            return {false, res};\n        }\n        S\
    \ res = x;\n        res.max1 += f.add;\n        res.min1 += f.add;\n        if\
    \ (res.max2 != lowest) res.max2 += f.add;\n        if (res.min2 != highest) res.min2\
    \ += f.add;\n        if (res.max1 != res.min2 && (f.ub <= res.max2 || f.lb >=\
    \ res.min2)) return {true, x};\n        if (f.add != T(0)) {\n            static\
    \ const auto binom = [] {\n                std::array<std::array<U, K + 1>, K\
    \ + 1> c{};\n                for (long long i = 0; i <= K; ++i) {\n          \
    \          c[i][0] = c[i][i] = U(1);\n                    for (long long j = 1;\
    \ j < i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];\n                }\n  \
    \              return c;\n            }();\n            std::array<U, K + 1> pw{};\n\
    \            pw[0] = U(1);\n            for (long long i = 1; i <= K; ++i) pw[i]\
    \ = pw[i - 1] * U(f.add);\n            res.val.fill(U(0));\n            for (long\
    \ long i = 0; i <= K; ++i)\n                for (long long j = 0; j <= i; ++j)\
    \ res.val[i] += binom[i][j] * pw[j] * x.val[i - j];\n        }\n        auto replace\
    \ = [&](T before, T after, long long count) {\n            U p(1), q(1);\n   \
    \         for (long long i = 1; i <= K; ++i) {\n                p *= U(before);\n\
    \                q *= U(after);\n                res.val[i] += (q - p) * U(count);\n\
    \            }\n        };\n        replace(res.max1, hi, res.max_cnt);\n    \
    \    replace(res.min1, lo, res.min_cnt);\n        if (res.max1 == res.min2) {\n\
    \            res.max2 = lo;\n            res.min2 = hi;\n        }\n        res.max1\
    \ = hi;\n        res.min1 = lo;\n        return {false, res};\n    }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f,\
    \ g); }\n    static constexpr F id() { return F(); }\n};\n\n/** @brief \u975E\u8CA0\
    \u6574\u6570\u3078\u306E\u533A\u9593 AND\u30FBOR\u3001\u533A\u9593\u6700\u5C0F\
    \u5024\u30FB\u6700\u5927\u5024 */\ntemplate <typename T = long long>\nstruct BitwiseAndOrMinMax\
    \ {\n    static_assert(std::is_integral_v<T> && !std::is_same_v<T, bool>);\n \
    \   static constexpr T mask = std::numeric_limits<T>::max();\n    struct S {\n\
    \        T min = mask, max = T(0), bit_and = mask, bit_or = T(0);\n        long\
    \ long size = 0;\n        constexpr S() = default;\n        constexpr S(T x) :\
    \ min(x), max(x), bit_and(x), bit_or(x), size(1) { assert(x >= T(0)); }\n    };\n\
    \    struct F {\n        T and_mask = mask, or_mask = T(0);\n    };\n    static\
    \ constexpr F bit_and(T b) {\n        assert(b >= T(0));\n        return {b, T(0)};\n\
    \    }\n    static constexpr F bit_or(T b) {\n        assert(b >= T(0));\n   \
    \     return {mask, b};\n    }\n    static constexpr S e() { return S(); }\n \
    \   static constexpr S op(const S& a, const S& b) {\n        if (a.size == 0)\
    \ return b;\n        if (b.size == 0) return a;\n        S res;\n        res.min\
    \ = std::min(a.min, b.min);\n        res.max = std::max(a.max, b.max);\n     \
    \   res.bit_and = a.bit_and & b.bit_and;\n        res.bit_or = a.bit_or | b.bit_or;\n\
    \        res.size = a.size + b.size;\n        return res;\n    }\n    static constexpr\
    \ std::pair<bool, S> mapping(const F& f, const S& x) {\n        if (x.size ==\
    \ 0) return {false, x};\n        T changed = static_cast<T>((mask ^ f.and_mask)\
    \ | f.or_mask);\n        if ((changed & (x.bit_and ^ x.bit_or)) != T(0)) return\
    \ {true, x};\n        S res = x;\n        res.min = (res.min & f.and_mask) | f.or_mask;\n\
    \        res.max = (res.max & f.and_mask) | f.or_mask;\n        res.bit_and =\
    \ (res.bit_and & f.and_mask) | f.or_mask;\n        res.bit_or = (res.bit_or &\
    \ f.and_mask) | f.or_mask;\n        return {false, res};\n    }\n    static constexpr\
    \ F composition(const F& f, const F& g) {\n        return {static_cast<T>(g.and_mask\
    \ & f.and_mask), static_cast<T>((g.or_mask & f.and_mask) | f.or_mask)};\n    }\n\
    \    static constexpr F id() { return F(); }\n};\n\n/** @brief \u975E\u8CA0\u6574\
    \u6570\u3078\u306E\u533A\u9593\u6574\u6570\u9664\u7B97\u30FB\u4EE3\u5165\u3001\
    \u533A\u9593\u548C\u30FB\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024 */\ntemplate\
    \ <typename T = long long, typename U = T>\nstruct DivUpdateSum {\n    static_assert(std::is_integral_v<T>\
    \ && !std::is_same_v<T, bool>);\n    struct S {\n        U sum = U(0);\n     \
    \   T min = std::numeric_limits<T>::max(), max = T(0);\n        long long size\
    \ = 0;\n        constexpr S() = default;\n        constexpr S(T x) : sum(U(x)),\
    \ min(x), max(x), size(1) { assert(x >= T(0)); }\n    };\n    struct F {\n   \
    \     T divisor = T(1);\n        std::optional<T> value;\n    };\n    static constexpr\
    \ F div(T d) {\n        assert(d >= T(1));\n        return {d, std::nullopt};\n\
    \    }\n    static constexpr F update(T b) {\n        assert(b >= T(0));\n   \
    \     return {T(1), b};\n    }\n    static constexpr S e() { return S(); }\n \
    \   static constexpr S op(const S& a, const S& b) {\n        S res;\n        res.sum\
    \ = a.sum + b.sum;\n        res.size = a.size + b.size;\n        res.min = std::min(a.min,\
    \ b.min);\n        res.max = std::max(a.max, b.max);\n        return res;\n  \
    \  }\n    static constexpr std::pair<bool, S> mapping(const F& f, const S& x)\
    \ {\n        if (x.size == 0 || (!f.value && f.divisor == T(1))) return {false,\
    \ x};\n        T lo = f.value ? *f.value : x.min / f.divisor;\n        T hi =\
    \ f.value ? *f.value : x.max / f.divisor;\n        if (lo != hi) return {true,\
    \ x};\n        S res(lo);\n        res.sum *= U(x.size);\n        res.size = x.size;\n\
    \        return {false, res};\n    }\n    static constexpr F composition(const\
    \ F& f, const F& g) {\n        if (f.value) return f;\n        if (g.value) return\
    \ update(*g.value / f.divisor);\n        // \u9664\u6570\u306E\u7A4D\u304C\u5024\
    \u57DF\u3092\u8D85\u3048\u308B\u306A\u3089\u3001\u3069\u306E\u975E\u8CA0\u5024\
    \u3082 0 \u306B\u306A\u308B\u3002\n        if (g.divisor > std::numeric_limits<T>::max()\
    \ / f.divisor) return update(T(0));\n        return div(g.divisor * f.divisor);\n\
    \    }\n    static constexpr F id() { return F(); }\n};\n\n/** @brief \u975E\u8CA0\
    \u6574\u6570\u3078\u306E\u533A\u9593 gcd\u30FB\u4EE3\u5165\u3001\u533A\u9593\u548C\
    \u30FB\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024 */\ntemplate <typename T = long\
    \ long, typename U = T>\nstruct GcdUpdateSum {\n    static_assert(std::is_integral_v<T>\
    \ && !std::is_same_v<T, bool>);\n    struct S {\n        U sum = U(0);\n     \
    \   T min = std::numeric_limits<T>::max(), max = T(0), lcm = T(1);\n        bool\
    \ lcm_overflow = false;\n        long long size = 0;\n        constexpr S() =\
    \ default;\n        constexpr S(T x) : sum(U(x)), min(x), max(x), lcm(x), size(1)\
    \ { assert(x >= T(0)); }\n    };\n    struct F {\n        T factor = T(0);\n \
    \       std::optional<T> value;\n    };\n    static constexpr F gcd(T b) {\n \
    \       assert(b >= T(0));\n        return {b, std::nullopt};\n    }\n    static\
    \ constexpr F update(T b) {\n        assert(b >= T(0));\n        return {T(0),\
    \ b};\n    }\n    static constexpr S e() { return S(); }\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        if (a.size == 0) return b;\n       \
    \ if (b.size == 0) return a;\n        S res;\n        res.sum = a.sum + b.sum;\n\
    \        res.min = std::min(a.min, b.min);\n        res.max = std::max(a.max,\
    \ b.max);\n        res.size = a.size + b.size;\n        if (res.min == T(0)) {\n\
    \            res.lcm = T(0);\n        } else if (a.lcm_overflow || b.lcm_overflow)\
    \ {\n            res.lcm_overflow = true;\n        } else {\n            T v =\
    \ a.lcm / std::gcd(a.lcm, b.lcm);\n            if (v > std::numeric_limits<T>::max()\
    \ / b.lcm)\n                res.lcm_overflow = true;\n            else\n     \
    \           res.lcm = v * b.lcm;\n        }\n        return res;\n    }\n    static\
    \ constexpr std::pair<bool, S> mapping(const F& f, const S& x) {\n        if (x.size\
    \ == 0) return {false, x};\n        if (!f.value) {\n            if (f.factor\
    \ == T(0)) return {false, x};\n            if (x.min > T(0) && !x.lcm_overflow\
    \ && f.factor % x.lcm == T(0)) return {false, x};\n            if (x.min != x.max)\
    \ return {true, x};\n        }\n        T value = f.value ? *f.value : std::gcd(x.min,\
    \ f.factor);\n        S res(value);\n        res.sum *= U(x.size);\n        res.size\
    \ = x.size;\n        return {false, res};\n    }\n    static constexpr F composition(const\
    \ F& f, const F& g) {\n        if (f.value) return f;\n        if (g.value) return\
    \ update(std::gcd(*g.value, f.factor));\n        return gcd(std::gcd(f.factor,\
    \ g.factor));\n    }\n    static constexpr F id() { return F(); }\n};\n\n}  //\
    \ namespace beats_acted_monoid\n"
  code: "#pragma once\n\n/**\n * @file beats-acted-monoid.hpp\n * @brief Segment Tree\
    \ Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n *\n\
    \ * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\
    \ \u3068\u540C\u3058\u30E1\u30F3\u30D0\u3092\u6301\u3064\u304C\u3001\n * mapping\
    \ \u306F std::pair<bool, S> (\u4F5C\u7528\u306B\u5931\u6557\u3057\u305F\u304B\
    , \u4F5C\u7528\u5F8C\u306E\u5024) \u3092\u8FD4\u3059\n * data_structures/segtree-beats.hpp\
    \ \u306B\u6E21\u3057\u3066\u4F7F\u3046\n */\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <limits>\n#include <numeric>\n#include\
    \ <optional>\n#include <type_traits>\n#include <utility>\n\n#include \"monoid.hpp\"\
    \n\nnamespace beats_acted_monoid {\n\n/**\n * @brief \u533A\u9593 chmin\u3001\u533A\
    \u9593\u548C\u30FB\u6700\u5927\u5024\n *\n * \u4F5C\u7528\u7D20\u306F chmin \u3059\
    \u308B\u5024 (x <- min(x, f))\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u304B\
    \u3089\u4F5C\u308A\u3001sum, max1 \u3067\u533A\u9593\u548C\u30FB\u6700\u5927\u5024\
    \u3092\u53D6\u5F97\u3059\u308B\n * \u7A7A\u306E\u533A\u9593\u3067\u306F max1 =\
    \ numeric_limits<T>::lowest()\n * ChminChmaxAddSum \u3088\u308A\u8EFD\u3044\n\
    \ *\n * @tparam T \u5024\u306E\u578B\n */\ntemplate <typename T>\nstruct ChminSum\
    \ {\n    static constexpr T lowest = std::numeric_limits<T>::lowest();\n\n   \
    \ struct S {\n        T sum;\n        T max1, max2;       // \u6700\u5927\u5024\
    \u30012\u756A\u76EE\u306E\u6700\u5927\u5024 (\u306A\u3051\u308C\u3070 lowest)\n\
    \        long long max_cnt;  // \u6700\u5927\u5024\u306E\u500B\u6570\n       \
    \ constexpr S() : sum(0), max1(lowest), max2(lowest), max_cnt(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), max1(x), max2(lowest), max_cnt(1) {}\n    };\n    using\
    \ F = T;\n\n    static constexpr S op(const S& a, const S& b) {\n        S res;\n\
    \        res.sum = a.sum + b.sum;\n        if (a.max1 == b.max1) {\n         \
    \   res.max1 = a.max1;\n            res.max_cnt = a.max_cnt + b.max_cnt;\n   \
    \         res.max2 = std::max(a.max2, b.max2);\n        } else if (a.max1 > b.max1)\
    \ {\n            res.max1 = a.max1;\n            res.max_cnt = a.max_cnt;\n  \
    \          res.max2 = std::max(a.max2, b.max1);\n        } else {\n          \
    \  res.max1 = b.max1;\n            res.max_cnt = b.max_cnt;\n            res.max2\
    \ = std::max(a.max1, b.max2);\n        }\n        return res;\n    }\n    static\
    \ constexpr S e() { return S(); }\n    static constexpr std::pair<bool, S> mapping(const\
    \ F& f, const S& x) {\n        if (x.max1 <= f) return {false, x};\n        //\
    \ \u6700\u5927\u5024\u3060\u3051\u304C\u5909\u308F\u308B (\u5024\u304C 1 \u7A2E\
    \u985E\u306A\u3089 f = lowest \u3067\u3082\u6210\u529F\u3055\u305B\u308B)\n  \
    \      if (x.max2 < f || x.max2 == lowest) {\n            S res = x;\n       \
    \     res.sum -= (x.max1 - f) * T(x.max_cnt);\n            res.max1 = f;\n   \
    \         return {false, res};\n        }\n        return {true, x};\n    }\n\
    \    static constexpr F composition(const F& f, const F& g) { return std::min(f,\
    \ g); }\n    static constexpr F id() { return std::numeric_limits<T>::max(); }\n\
    };\n\n/**\n * @brief \u533A\u9593 chmax\u3001\u533A\u9593\u548C\u30FB\u6700\u5C0F\
    \u5024\n *\n * \u4F5C\u7528\u7D20\u306F chmax \u3059\u308B\u5024 (x <- max(x,\
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
    \n/**\n * @brief \u533A\u9593 chmin\u30FBchmax\u30FB\u52A0\u7B97\u30FB\u4EE3\u5165\
    \u30010 \u4E57\u548C\u304B\u3089 K \u4E57\u548C\n * @tparam T \u6BD4\u8F03\u3059\
    \u308B\u5024\u306E\u578B (\u7B26\u53F7\u4ED8\u304D\u6574\u6570)\n * @tparam K\
    \ \u6700\u5927\u6B21\u6570\n * @tparam U \u4E57\u548C\u306E\u578B (modint \u3082\
    \u53EF)\n */\ntemplate <typename T = long long, long long K = 2, typename U =\
    \ T>\nstruct ChminChmaxAddPowerSum {\n    static_assert(K >= 0);\n    static_assert(std::is_integral_v<T>\
    \ && std::is_signed_v<T>);\n    static constexpr T lowest = std::numeric_limits<T>::lowest();\n\
    \    static constexpr T highest = std::numeric_limits<T>::max();\n    struct S\
    \ {\n        std::array<U, K + 1> val{};\n        T max1 = lowest, max2 = lowest,\
    \ min1 = highest, min2 = highest;\n        long long max_cnt = 0, min_cnt = 0;\n\
    \        constexpr S() = default;\n        constexpr S(const T& x) : max1(x),\
    \ min1(x), max_cnt(1), min_cnt(1) {\n            val[0] = U(1);\n            for\
    \ (long long i = 1; i <= K; ++i) val[i] = val[i - 1] * U(x);\n        }\n    \
    \    constexpr const U& operator[](long long i) const {\n            assert(0\
    \ <= i && i <= K);\n            return val[i];\n        }\n    };\n    using F\
    \ = ClampAdd<T>;\n    static constexpr F chmin(const T& b) { return {lowest, b,\
    \ T(0)}; }\n    static constexpr F chmax(const T& b) { return {b, highest, T(0)};\
    \ }\n    static constexpr F add(const T& b) { return {lowest, highest, b}; }\n\
    \    static constexpr F update(const T& b) { return {b, b, T(0)}; }\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if (a.max_cnt == 0) return\
    \ b;\n        if (b.max_cnt == 0) return a;\n        S res;\n        for (long\
    \ long i = 0; i <= K; ++i) res.val[i] = a.val[i] + b.val[i];\n        res.max1\
    \ = std::max(a.max1, b.max1);\n        res.max_cnt = (a.max1 == res.max1 ? a.max_cnt\
    \ : 0) + (b.max1 == res.max1 ? b.max_cnt : 0);\n        res.max2 = std::max(a.max1\
    \ == res.max1 ? a.max2 : a.max1, b.max1 == res.max1 ? b.max2 : b.max1);\n    \
    \    res.min1 = std::min(a.min1, b.min1);\n        res.min_cnt = (a.min1 == res.min1\
    \ ? a.min_cnt : 0) + (b.min1 == res.min1 ? b.min_cnt : 0);\n        res.min2 =\
    \ std::min(a.min1 == res.min1 ? a.min2 : a.min1, b.min1 == res.min1 ? b.min2 :\
    \ b.min1);\n        return res;\n    }\n    static constexpr S e() { return S();\
    \ }\n    static std::pair<bool, S> mapping(const F& f, const S& x, long long sz)\
    \ {\n        if (x.max_cnt == 0) return {false, x};\n        // \u5168\u8981\u7D20\
    \u304C\u540C\u3058\u5024\u306B\u306A\u308B\u5834\u5408\u306F\u3001\u52A0\u7B97\
    \u3084\u4E8C\u9805\u5C55\u958B\u3088\u308A\u5148\u306B\u51E6\u7406\u3059\u308B\
    \u3002\n        T lo = std::clamp(x.min1 + f.add, f.lb, f.ub);\n        T hi =\
    \ std::clamp(x.max1 + f.add, f.lb, f.ub);\n        if (lo == hi) {\n         \
    \   S res(lo);\n            for (auto& v : res.val) v *= U(sz);\n            res.max_cnt\
    \ = res.min_cnt = sz;\n            return {false, res};\n        }\n        S\
    \ res = x;\n        res.max1 += f.add;\n        res.min1 += f.add;\n        if\
    \ (res.max2 != lowest) res.max2 += f.add;\n        if (res.min2 != highest) res.min2\
    \ += f.add;\n        if (res.max1 != res.min2 && (f.ub <= res.max2 || f.lb >=\
    \ res.min2)) return {true, x};\n        if (f.add != T(0)) {\n            static\
    \ const auto binom = [] {\n                std::array<std::array<U, K + 1>, K\
    \ + 1> c{};\n                for (long long i = 0; i <= K; ++i) {\n          \
    \          c[i][0] = c[i][i] = U(1);\n                    for (long long j = 1;\
    \ j < i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];\n                }\n  \
    \              return c;\n            }();\n            std::array<U, K + 1> pw{};\n\
    \            pw[0] = U(1);\n            for (long long i = 1; i <= K; ++i) pw[i]\
    \ = pw[i - 1] * U(f.add);\n            res.val.fill(U(0));\n            for (long\
    \ long i = 0; i <= K; ++i)\n                for (long long j = 0; j <= i; ++j)\
    \ res.val[i] += binom[i][j] * pw[j] * x.val[i - j];\n        }\n        auto replace\
    \ = [&](T before, T after, long long count) {\n            U p(1), q(1);\n   \
    \         for (long long i = 1; i <= K; ++i) {\n                p *= U(before);\n\
    \                q *= U(after);\n                res.val[i] += (q - p) * U(count);\n\
    \            }\n        };\n        replace(res.max1, hi, res.max_cnt);\n    \
    \    replace(res.min1, lo, res.min_cnt);\n        if (res.max1 == res.min2) {\n\
    \            res.max2 = lo;\n            res.min2 = hi;\n        }\n        res.max1\
    \ = hi;\n        res.min1 = lo;\n        return {false, res};\n    }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f,\
    \ g); }\n    static constexpr F id() { return F(); }\n};\n\n/** @brief \u975E\u8CA0\
    \u6574\u6570\u3078\u306E\u533A\u9593 AND\u30FBOR\u3001\u533A\u9593\u6700\u5C0F\
    \u5024\u30FB\u6700\u5927\u5024 */\ntemplate <typename T = long long>\nstruct BitwiseAndOrMinMax\
    \ {\n    static_assert(std::is_integral_v<T> && !std::is_same_v<T, bool>);\n \
    \   static constexpr T mask = std::numeric_limits<T>::max();\n    struct S {\n\
    \        T min = mask, max = T(0), bit_and = mask, bit_or = T(0);\n        long\
    \ long size = 0;\n        constexpr S() = default;\n        constexpr S(T x) :\
    \ min(x), max(x), bit_and(x), bit_or(x), size(1) { assert(x >= T(0)); }\n    };\n\
    \    struct F {\n        T and_mask = mask, or_mask = T(0);\n    };\n    static\
    \ constexpr F bit_and(T b) {\n        assert(b >= T(0));\n        return {b, T(0)};\n\
    \    }\n    static constexpr F bit_or(T b) {\n        assert(b >= T(0));\n   \
    \     return {mask, b};\n    }\n    static constexpr S e() { return S(); }\n \
    \   static constexpr S op(const S& a, const S& b) {\n        if (a.size == 0)\
    \ return b;\n        if (b.size == 0) return a;\n        S res;\n        res.min\
    \ = std::min(a.min, b.min);\n        res.max = std::max(a.max, b.max);\n     \
    \   res.bit_and = a.bit_and & b.bit_and;\n        res.bit_or = a.bit_or | b.bit_or;\n\
    \        res.size = a.size + b.size;\n        return res;\n    }\n    static constexpr\
    \ std::pair<bool, S> mapping(const F& f, const S& x) {\n        if (x.size ==\
    \ 0) return {false, x};\n        T changed = static_cast<T>((mask ^ f.and_mask)\
    \ | f.or_mask);\n        if ((changed & (x.bit_and ^ x.bit_or)) != T(0)) return\
    \ {true, x};\n        S res = x;\n        res.min = (res.min & f.and_mask) | f.or_mask;\n\
    \        res.max = (res.max & f.and_mask) | f.or_mask;\n        res.bit_and =\
    \ (res.bit_and & f.and_mask) | f.or_mask;\n        res.bit_or = (res.bit_or &\
    \ f.and_mask) | f.or_mask;\n        return {false, res};\n    }\n    static constexpr\
    \ F composition(const F& f, const F& g) {\n        return {static_cast<T>(g.and_mask\
    \ & f.and_mask), static_cast<T>((g.or_mask & f.and_mask) | f.or_mask)};\n    }\n\
    \    static constexpr F id() { return F(); }\n};\n\n/** @brief \u975E\u8CA0\u6574\
    \u6570\u3078\u306E\u533A\u9593\u6574\u6570\u9664\u7B97\u30FB\u4EE3\u5165\u3001\
    \u533A\u9593\u548C\u30FB\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024 */\ntemplate\
    \ <typename T = long long, typename U = T>\nstruct DivUpdateSum {\n    static_assert(std::is_integral_v<T>\
    \ && !std::is_same_v<T, bool>);\n    struct S {\n        U sum = U(0);\n     \
    \   T min = std::numeric_limits<T>::max(), max = T(0);\n        long long size\
    \ = 0;\n        constexpr S() = default;\n        constexpr S(T x) : sum(U(x)),\
    \ min(x), max(x), size(1) { assert(x >= T(0)); }\n    };\n    struct F {\n   \
    \     T divisor = T(1);\n        std::optional<T> value;\n    };\n    static constexpr\
    \ F div(T d) {\n        assert(d >= T(1));\n        return {d, std::nullopt};\n\
    \    }\n    static constexpr F update(T b) {\n        assert(b >= T(0));\n   \
    \     return {T(1), b};\n    }\n    static constexpr S e() { return S(); }\n \
    \   static constexpr S op(const S& a, const S& b) {\n        S res;\n        res.sum\
    \ = a.sum + b.sum;\n        res.size = a.size + b.size;\n        res.min = std::min(a.min,\
    \ b.min);\n        res.max = std::max(a.max, b.max);\n        return res;\n  \
    \  }\n    static constexpr std::pair<bool, S> mapping(const F& f, const S& x)\
    \ {\n        if (x.size == 0 || (!f.value && f.divisor == T(1))) return {false,\
    \ x};\n        T lo = f.value ? *f.value : x.min / f.divisor;\n        T hi =\
    \ f.value ? *f.value : x.max / f.divisor;\n        if (lo != hi) return {true,\
    \ x};\n        S res(lo);\n        res.sum *= U(x.size);\n        res.size = x.size;\n\
    \        return {false, res};\n    }\n    static constexpr F composition(const\
    \ F& f, const F& g) {\n        if (f.value) return f;\n        if (g.value) return\
    \ update(*g.value / f.divisor);\n        // \u9664\u6570\u306E\u7A4D\u304C\u5024\
    \u57DF\u3092\u8D85\u3048\u308B\u306A\u3089\u3001\u3069\u306E\u975E\u8CA0\u5024\
    \u3082 0 \u306B\u306A\u308B\u3002\n        if (g.divisor > std::numeric_limits<T>::max()\
    \ / f.divisor) return update(T(0));\n        return div(g.divisor * f.divisor);\n\
    \    }\n    static constexpr F id() { return F(); }\n};\n\n/** @brief \u975E\u8CA0\
    \u6574\u6570\u3078\u306E\u533A\u9593 gcd\u30FB\u4EE3\u5165\u3001\u533A\u9593\u548C\
    \u30FB\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024 */\ntemplate <typename T = long\
    \ long, typename U = T>\nstruct GcdUpdateSum {\n    static_assert(std::is_integral_v<T>\
    \ && !std::is_same_v<T, bool>);\n    struct S {\n        U sum = U(0);\n     \
    \   T min = std::numeric_limits<T>::max(), max = T(0), lcm = T(1);\n        bool\
    \ lcm_overflow = false;\n        long long size = 0;\n        constexpr S() =\
    \ default;\n        constexpr S(T x) : sum(U(x)), min(x), max(x), lcm(x), size(1)\
    \ { assert(x >= T(0)); }\n    };\n    struct F {\n        T factor = T(0);\n \
    \       std::optional<T> value;\n    };\n    static constexpr F gcd(T b) {\n \
    \       assert(b >= T(0));\n        return {b, std::nullopt};\n    }\n    static\
    \ constexpr F update(T b) {\n        assert(b >= T(0));\n        return {T(0),\
    \ b};\n    }\n    static constexpr S e() { return S(); }\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        if (a.size == 0) return b;\n       \
    \ if (b.size == 0) return a;\n        S res;\n        res.sum = a.sum + b.sum;\n\
    \        res.min = std::min(a.min, b.min);\n        res.max = std::max(a.max,\
    \ b.max);\n        res.size = a.size + b.size;\n        if (res.min == T(0)) {\n\
    \            res.lcm = T(0);\n        } else if (a.lcm_overflow || b.lcm_overflow)\
    \ {\n            res.lcm_overflow = true;\n        } else {\n            T v =\
    \ a.lcm / std::gcd(a.lcm, b.lcm);\n            if (v > std::numeric_limits<T>::max()\
    \ / b.lcm)\n                res.lcm_overflow = true;\n            else\n     \
    \           res.lcm = v * b.lcm;\n        }\n        return res;\n    }\n    static\
    \ constexpr std::pair<bool, S> mapping(const F& f, const S& x) {\n        if (x.size\
    \ == 0) return {false, x};\n        if (!f.value) {\n            if (f.factor\
    \ == T(0)) return {false, x};\n            if (x.min > T(0) && !x.lcm_overflow\
    \ && f.factor % x.lcm == T(0)) return {false, x};\n            if (x.min != x.max)\
    \ return {true, x};\n        }\n        T value = f.value ? *f.value : std::gcd(x.min,\
    \ f.factor);\n        S res(value);\n        res.sum *= U(x.size);\n        res.size\
    \ = x.size;\n        return {false, res};\n    }\n    static constexpr F composition(const\
    \ F& f, const F& g) {\n        if (f.value) return f;\n        if (g.value) return\
    \ update(std::gcd(*g.value, f.factor));\n        return gcd(std::gcd(f.factor,\
    \ g.factor));\n    }\n    static constexpr F id() { return F(); }\n};\n\n}  //\
    \ namespace beats_acted_monoid\n"
  dependsOn:
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/algebra/beats-acted-monoid.hpp
  requiredBy:
  - src/data_structures/segtree-beats.hpp
  timestamp: '2026-11-16 21:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/dual-segtree.test.cpp
  - test/unittest/data_structures/segtree-beats.test.cpp
  - test/unittest/algebra/beats-acted-monoid.test.cpp
  - test/unittest/algebra/monoid.test.cpp
  - test/unittest/algebra/beats-acted-monoid-extended.test.cpp
  - test/yosupo/data_structure/range-chmin-chmax-add-range-sum.1.test.cpp
  - test/yosupo/data_structure/range-chmin-chmax-add-range-sum.2.test.cpp
  - test/yosupo/data_structure/range-chmin-chmax-add-range-sum.3.test.cpp
  - test/yosupo/data_structure/range-chmin-chmax-add-range-sum.4.test.cpp
documentation_of: src/algebra/beats-acted-monoid.hpp
layout: document
title: "Segment Tree Beats \u7528\u306E\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\
  \u30C9"
---

[Segment Tree Beats](../data_structures/segtree-beats.hpp) に渡す作用素付きモノイドです。メンバは [作用素付きモノイド](acted-monoid.hpp) と同じですが、`mapping` は `std::pair<bool, S>` (作用に失敗したか, 作用後の値) を返すので、遅延伝搬セグメント木には渡せません。

```cpp
using A = beats_acted_monoid::ChminChmaxAddSum<long long>;
SegTreeBeats<A> seg(a);  // a は std::vector<long long>
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
| `ChminChmaxAddPowerSum<T, K, U>` | 区間 chmin・chmax・加算・代入 | 区間の 0 乗和から K 乗和・最大値・最小値 | [`ClampAdd<T>`](monoid.hpp) |
| `BitwiseAndOrMinMax<T>` | 区間 bitwise AND・OR | 区間最小値・最大値・bitwise AND・OR | `F{and_mask, or_mask}` |
| `DivUpdateSum<T, U>` | 区間整数除算・代入 | 区間和・最小値・最大値 | `F` |
| `GcdUpdateSum<T, U>` | 区間 gcd・代入 | 区間和・最小値・最大値 | `F` |

追加の 4 種類は `T = long long` が既定です。乗和の最大次数は `K = 2`、集計の型は `U = T` が既定です。

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

## 区間 chmin・chmax・加算・代入と k 乗和

```cpp
using A = beats_acted_monoid::ChminChmaxAddPowerSum<long long, 2, modint998244353>;
SegTreeBeats<A> seg(a);  // a は std::vector<long long>
seg.apply(l, r, A::chmin(10));
seg.apply(l, r, A::add(3));
auto s = seg.prod(l, r);
auto count = s[0];  // 要素数を U で表した値
auto sum = s[1];
auto square_sum = s[2];
```

`S(x)` で 1 要素を作り、`s[j]` で $\sum a_i^j$ を取得します。`min1`・`max1` は元の値の型 `T`、乗和は `U` です。値を比較するため、`T` には符号付き整数を使います。`U` は `T` から構築でき、加減乗算ができる型で、modint や `__int128_t` も使えます。`K = 0` も許します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `chmin(b)` / `chmax(b)` / `add(b)` / `update(b)` | `ChminChmaxAddSum` と同じ作用素を作る | $O(1)$ |
| `S(x)` | 1 要素を構築 | $O(K+1)$ |
| `s[j]` | `j` 乗和を取得 (`0 <= j <= K`) | $O(1)$ |
| `op(a, b)` | 2 区間を結合 | $O(K+1)$ |
| `mapping(f, s, sz)` | 成功時に乗和と極値を更新、適用できなければ失敗を返す | 加算なし $O(K+1)$、加算あり $O((K+1)^2)$ |

セグ木のクエリは $O((K+1)\log n)$。更新は、chmin・chmax だけなら償却 $O((K+1)\log n)$、加算も含む場合は償却 $O((K+1)^2\log^2 n)$ です。セグ木の領域は $O(n(K+1))$、二項係数表に追加で $O((K+1)^2)$ を使います。

値と加算途中の値は `T` の最小値・最大値に達しない範囲で使ってください。`U` に整数型を使う場合、乗和とその計算途中の値も収まる必要があります。

## 区間 bitwise AND・OR

```cpp
using A = beats_acted_monoid::BitwiseAndOrMinMax<>;
SegTreeBeats<A> seg(a);
seg.apply(l, r, A::bit_and(7));
seg.apply(l, r, A::bit_or(8));
auto s = seg.prod(l, r);
// s.min, s.max, s.bit_and, s.bit_or, s.size
```

`T` は bool 以外の整数型で、値・マスクは非負です。符号なし整数では最上位ビットも扱えます。`F{and_mask, or_mask}` は $(x\mathbin{\&}\mathrm{and\_mask})\mathbin{|}\mathrm{or\_mask}$ を表します。変更するビットが区間内で共通なら、極値の大小関係を保ってノード全体に作用できます。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `bit_and(b)` | $x\leftarrow x\mathbin{\&}b$ の作用素 | $O(1)$ |
| `bit_or(b)` | $x\leftarrow x\mathbin{|}b$ の作用素 | $O(1)$ |
| `S(x)` | 1 要素を構築 | $O(1)$ |
| `op(a, b)` / `mapping(f, s)` / `composition(f, g)` | 結合・作用・合成 | $O(1)$ |

有効ビット数を $B$ とすると、セグ木の更新は償却 $O(B\log n)$、クエリは $O(\log n)$、領域は $O(n)$ です。空区間の `min`・`bit_and` は型の最大値、`max`・`bit_or` は 0 です。

## 区間整数除算・代入

```cpp
using A = beats_acted_monoid::DivUpdateSum<>;
SegTreeBeats<A> seg(a);
seg.apply(l, r, A::div(3));     // a[i] <- floor(a[i] / 3)
seg.apply(l, r, A::update(5));
auto s = seg.prod(l, r);       // s.sum, s.min, s.max, s.size
```

`T` は bool 以外の整数型で、値は非負、除数は 1 以上です。区間の最小値と最大値の商が同じなら区間全体を一様な値にし、異なる場合は子に降ります。除数の合成で積が型の最大値を超える場合は 0 の代入にします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `div(d)` | $x\leftarrow\lfloor x/d\rfloor$ の作用素 (`d >= 1`) | $O(1)$ |
| `update(b)` | 非負値 `b` を代入する作用素 | $O(1)$ |
| `S(x)` | 1 要素を構築 | $O(1)$ |
| `op(a, b)` / `mapping(f, s)` / `composition(f, g)` | 結合・作用・合成 | $O(1)$ |

集計の型 `U` は `T` から構築でき、加算・乗算ができる型です。`sum` と計算途中の値は `U` に収まる必要があります。modint も使えます。空区間では `sum = 0`、`min` は型の最大値、`max = 0`、`size = 0` です。

値の上限を $V$、更新・問い合わせの合計を $q$ とすると、構築を含めて $O((n+q)\log(n+1)\log(V+2))$ 時間、$O(n)$ 領域です。単発の更新は $O(n)$ かかることがあります。クエリは $O(\log n)$ です。

## 区間 gcd・代入

```cpp
using A = beats_acted_monoid::GcdUpdateSum<>;
SegTreeBeats<A> seg(a);
seg.apply(l, r, A::gcd(12));    // a[i] <- gcd(a[i], 12)
seg.apply(l, r, A::update(5));
auto s = seg.prod(l, r);       // s.sum, s.min, s.max, s.size
```

`T` は bool 以外の整数型で、値・gcd の引数は非負です。`gcd(0)` は恒等作用です。集計の型 `U`、空区間の値、計算途中の値に関する条件は `DivUpdateSum` と同じです。

区間が一様なら直接 gcd を計算し、全要素が引数の約数なら変更せずに終了します。それ以外は子に降ります。約数かどうかの判定には LCM を保持し、型に収まらない場合は `lcm_overflow` を立てます。オーバーフロー時の `lcm` は参照しないでください。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `gcd(b)` | $x\leftarrow\gcd(x,b)$ の作用素 | $O(1)$ |
| `update(b)` | 非負値 `b` を代入する作用素 | $O(1)$ |
| `S(x)` | 1 要素を構築 | $O(1)$ |
| `op(a, b)` / `mapping(f, s)` / `composition(f, g)` | 結合・作用・合成 | gcd 計算 $O(1)$ 回 |

整数の gcd を定数時間と数えると、値の上限 $V$、更新・問い合わせの合計 $q$ に対し、構築を含めて $O((n+q)\log(n+1)\log(V+2))$ 時間、$O(n)$ 領域です。単発の更新は $O(n)$ かかることがあります。クエリは gcd 計算 $O(\log n)$ 回です。

## 関連

- これを渡して使うデータ構造は [Segment Tree Beats](../data_structures/segtree-beats.hpp)
- 作用が常に成功する場合は [作用素付きモノイド](acted-monoid.hpp)
