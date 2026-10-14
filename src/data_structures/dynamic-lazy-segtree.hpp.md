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
    path: test/unittest/dynamic-lazy-segtree.test.cpp
    title: test/unittest/dynamic-lazy-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range-affine-range-sum-large-array.test.cpp
    title: test/yosupo/range-affine-range-sum-large-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u52D5\u7684\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728"
    links: []
  bundledCode: "#line 2 \"src/data_structures/dynamic-lazy-segtree.hpp\"\n\n/**\n\
    \ * @file dynamic-lazy-segtree.hpp\n * @brief \u52D5\u7684\u9045\u5EF6\u4F1D\u642C\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"src/algebra/acted-monoid.hpp\"\
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
    \n * - F inv(const F& f): \u9006\u4F5C\u7528\u7D20\n */\n\n#line 19 \"src/algebra/acted-monoid.hpp\"\
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
    #include <ostream>\n#line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\
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
    \    }\n};\n\nnamespace monoid {\n\n/**\n * @brief \u548C\n */\ntemplate <typename\
    \ T>\nstruct Sum {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a + b; }\n    static constexpr S e() { return S(0); }\n};\n\n\
    /**\n * @brief \u7A4D\n */\ntemplate <typename T>\nstruct Prod {\n    using S\
    \ = T;\n    static constexpr S op(const S& a, const S& b) { return a * b; }\n\
    \    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief \u6700\u5927\
    \u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\u5024\n */\ntemplate <typename\
    \ T>\nstruct Max {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::lowest();\
    \ }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\
    \u6700\u5927\u5024\n */\ntemplate <typename T>\nstruct Min {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return std::min(a, b); }\n\
    \    static constexpr S e() { return std::numeric_limits<S>::max(); }\n};\n\n\
    /**\n * @brief \u6700\u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max}\n\
    \ */\ntemplate <typename T>\nstruct MinMax {\n    using S = std::pair<T, T>;\n\
    \    static constexpr S op(const S& a, const S& b) { return {std::min(a.first,\
    \ b.first), std::max(a.second, b.second)}; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::max(), std::numeric_limits<T>::lowest()}; }\n};\n\n\
    /**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate <typename T>\n\
    struct Xor {\n    using S = T;\n    static constexpr S op(const S& a, const S&\
    \ b) { return a ^ b; }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u8AD6\u7406\u7A4D\n */\ntemplate <typename T>\nstruct And {\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return a & b; }\n\
    \    static constexpr S e() { return ~S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\
    \u548C\n */\ntemplate <typename T>\nstruct Or {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return a | b; }\n    static constexpr\
    \ S e() { return S(0); }\n};\n\n/**\n * @brief \u6700\u5927\u516C\u7D04\u6570\
    \ \u5358\u4F4D\u5143\u306F0\n */\ntemplate <typename T>\nstruct Gcd {\n    static_assert(std::is_integral_v<T>);\n\
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
    \u50CF (\u4E92\u63DB)\n    static constexpr S swap(int i, int j) {\n        S\
    \ h = e();\n        h[i] = j;\n        h[j] = i;\n        return h;\n    }\n};\n\
    \n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\u5408\u6210\n * op(f, g)\
    \ = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n * \u533A\u9593 [l,\
    \ r) \u306E\u7A4D\u306F f_l(...f_{r-1}(x)) \u3092\u8868\u3059\n * \u5DE6\u304B\
    \u3089\u9806\u306B\u9069\u7528\u3057\u305F\u3044 (f_{r-1}(...f_l(x)) \u3092\u6C42\
    \u3081\u305F\u3044) \u5834\u5408\u306F monoid::Reverse<monoid::Composite<T>> \u3092\
    \u4F7F\u3046\n */\ntemplate <typename T>\nstruct Composite {\n    using S = Affine<T>;\n\
    \    static constexpr S op(const S& f, const S& g) { return {f.a * g.a, f.a *\
    \ g.b + f.b}; }\n    static constexpr S e() { return {T(1), T(0)}; }\n};\n\n/**\n\
    \ * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
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
    \u5024\u306E\u578B\n */\ntemplate <typename T, typename U = int>\nstruct MinWith\
    \ {\n    using S = std::pair<T, U>;\n    static constexpr S op(const S& a, const\
    \ S& b) { return b.first < a.first ? b : a; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\
    \u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\
    \u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\
    \u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename\
    \ T, typename U = int>\nstruct MaxWith {\n    using S = std::pair<T, U>;\n   \
    \ static constexpr S op(const S& a, const S& b) { return a.first < b.first ? b\
    \ : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
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
    \ U(0)}; }\n};\n\n/**\n * @brief \u7A4D\u306E\u9806\u5E8F\u3092\u9006\u306B\u3057\
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
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB x <-\
    \ a * x + b (Affine)\u3001\u533A\u9593\u548C\n */\ntemplate <typename T>\nstruct\
    \ AffineSum : monoid::Sum<T> {\n    using S = T;\n    using F = Affine<T>;\n \
    \   static constexpr S mapping(const F& f, const S& x, long long sz) { return\
    \ f.a * x + f.b * S(sz); }\n    static constexpr F composition(const F& f, const\
    \ F& g) { return {f.a * g.a, f.a * g.b + f.b}; }\n    static constexpr F id()\
    \ { return {T(1), T(0)}; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\
    1\u6B21\u95A2\u6570\u306E\u5408\u6210 (monoid::Composite)\n */\ntemplate <typename\
    \ T>\nstruct UpdateComposite : monoid::Composite<T> {\n    using S = Affine<T>;\n\
    \    using F = std::optional<S>;\n    static constexpr S mapping(const F& f, const\
    \ S& x, long long sz) {\n        if (!f) return x;\n        // f \u3092 sz \u56DE\
    \u5408\u6210\u3059\u308B\n        S ret = monoid::Composite<T>::e(), p = *f;\n\
    \        for (; sz > 0; sz >>= 1) {\n            if (sz & 1) ret = monoid::Composite<T>::op(ret,\
    \ p);\n            p = monoid::Composite<T>::op(p, p);\n        }\n        return\
    \ ret;\n    }\n    static constexpr F composition(const F& f, const F& g) { return\
    \ f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\
    \u306E\u4F4D\u7F6E (monoid::MinWith)\n */\ntemplate <typename T, typename U =\
    \ int>\nstruct AddMinWith : monoid::MinWith<T, U> {\n    using S = std::pair<T,\
    \ U>;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return {x.first + f, x.second}; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\
    \u5024\u3068\u305D\u306E\u4F4D\u7F6E (monoid::MaxWith)\n */\ntemplate <typename\
    \ T, typename U = int>\nstruct AddMaxWith : monoid::MaxWith<T, U> {\n    using\
    \ S = std::pair<T, U>;\n    using F = T;\n    static constexpr S mapping(const\
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
    \ i++) val[i] = val[i - 1] * x;\n        }\n        constexpr const T& operator[](std::size_t\
    \ i) const { return val[i]; }\n    };\n    using F = T;\n    static constexpr\
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
    \ F id() { return F(0); }\n};\n\n}  // namespace acted_monoid\n\n/**\n * @brief\
    \ \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u304B\u3089\u5B9F\u884C\u6642\
    \u306B\u4F5C\u308B\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n * \u30E9\
    \u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u578B\n * @tparam U \u4F5C\u7528\u7D20\u306E\u578B\n * @tparam Mapping\
    \ \u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\u308B\u95A2\u6570\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306E\u578B \u5F15\u6570\u306F (f, x), (f, x, sz), (f, x, l,\
    \ r) \u306E\u3044\u305A\u308C\u304B\n * @tparam Composition \u4F5C\u7528\u7D20\
    \u306E\u5408\u6210\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\
    \u578B\n */\ntemplate <typename T, typename Op, typename U, typename Mapping,\
    \ typename Composition>\nstruct ActedMonoid {\n    using S = T;\n    using F =\
    \ U;\n    Op op_object;\n    S identity;\n    Mapping mapping_object;\n    Composition\
    \ composition_object;\n    F lazy_identity;\n    ActedMonoid() = default;\n  \
    \  constexpr ActedMonoid(Op op, const S& e, Mapping mapping, Composition composition,\
    \ const F& id)\n        : op_object(std::move(op)), identity(e), mapping_object(std::move(mapping)),\
    \ composition_object(std::move(composition)), lazy_identity(id) {}\n    constexpr\
    \ S op(const S& a, const S& b) const { return op_object(a, b); }\n    constexpr\
    \ S e() const { return identity; }\n    constexpr auto mapping(const F& f, const\
    \ S& x, long long l, long long r) const {\n        if constexpr (std::is_invocable_v<const\
    \ Mapping&, const F&, const S&, long long, long long>) {\n            return mapping_object(f,\
    \ x, l, r);\n        } else if constexpr (std::is_invocable_v<const Mapping&,\
    \ const F&, const S&, long long>) {\n            return mapping_object(f, x, r\
    \ - l);\n        } else {\n            return mapping_object(f, x);\n        }\n\
    \    }\n    constexpr F composition(const F& f, const F& g) const { return composition_object(f,\
    \ g); }\n    constexpr F id() const { return lazy_identity; }\n};\ntemplate <typename\
    \ Op, typename T, typename Mapping, typename Composition, typename U>\nActedMonoid(Op,\
    \ T, Mapping, Composition, U) -> ActedMonoid<T, Op, U, Mapping, Composition>;\n\
    #line 14 \"src/data_structures/dynamic-lazy-segtree.hpp\"\n\n/**\n * @brief \u52D5\
    \u7684\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u8981\
    \u7D20\u6570\u304C\u5927\u304D\u304F\u3066\u3082\u4F7F\u3048\u308B\u9045\u5EF6\
    \u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3002\u6700\u521D\u306F\u3059\
    \u3079\u3066\u5358\u4F4D\u5143\u3067\u3001\u66F4\u65B0\u3057\u305F\u3068\u3053\
    \u308D\u306E\u30CE\u30FC\u30C9\u3060\u3051\u3092\u4F5C\u308B\n * \u4F8B:\n * DynamicLazySegTree<acted_monoid::AddSum<long\
    \ long>> seg(1000000000000000000);\n * seg.apply(0, 1000000000000000000, 1);\n\
    \ * seg.prod(10, 20);  // 10\n *\n * @tparam A \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\n */\ntemplate <typename A>\nclass\
    \ DynamicLazySegTree {\n   public:\n    using S = typename A::S;\n    using F\
    \ = typename A::F;\n\n   private:\n    A a;\n    S op(const S& x, const S& y)\
    \ const { return a.op(x, y); }\n    S e() const { return a.e(); }\n    S mapping(const\
    \ F& f, const S& x, long long l, long long r) const { return acted_monoid::apply_mapping(a,\
    \ f, x, l, r); }\n    F composition(const F& f, const F& g) const { return a.composition(f,\
    \ g); }\n    F id() const { return a.id(); }\n\n    long long n;\n    int root;\
    \  // \u307E\u3060\u4F5C\u3063\u3066\u3044\u306A\u3044\u30CE\u30FC\u30C9\u306F\
    \ -1 \u3067\u3001\u533A\u9593\u306E\u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u5358\
    \u4F4D\u5143\u3067\u3042\u308B\u3053\u3068\u3092\u8868\u3059\n    // val \u306F\
    \u30CE\u30FC\u30C9\u306E\u533A\u9593\u306E\u7A4D\u3067\u3001\u305D\u306E\u30CE\
    \u30FC\u30C9\u306E lazy \u306F\u9069\u7528\u6E08\u307F\u3002lazy \u306F\u5B50\u306B\
    \u307E\u3060\u4F1D\u3048\u3066\u3044\u306A\u3044\u4F5C\u7528\u7D20\n    std::vector<S>\
    \ val;\n    std::vector<F> lazy;\n    std::vector<int> left, right;\n\n    class\
    \ DynamicLazySegTreeReference {\n        DynamicLazySegTree& segtree;\n      \
    \  long long k;\n\n       public:\n        DynamicLazySegTreeReference(DynamicLazySegTree&\
    \ segtree, long long k) : segtree(segtree), k(k) {}\n        DynamicLazySegTreeReference&\
    \ operator=(const S& x) {\n            segtree.set(k, x);\n            return\
    \ *this;\n        }\n        operator S() const { return segtree.get(k); }\n \
    \   };\n\n    int make_node(const S& x, const F& f) {\n        val.push_back(x);\n\
    \        lazy.push_back(f);\n        left.push_back(-1);\n        right.push_back(-1);\n\
    \        return int(val.size()) - 1;\n    }\n    // \u30CE\u30FC\u30C9 t ([a,\
    \ b)) \u306B f \u3092\u4F5C\u7528\u3055\u305B\u308B\u3002t \u304C -1 \u306A\u3089\
    \u30CE\u30FC\u30C9\u3092\u4F5C\u308B\n    int apply_node(int t, long long a, long\
    \ long b, const F& f) {\n        if (t == -1) return make_node(mapping(f, e(),\
    \ a, b), f);\n        val[t] = mapping(f, val[t], a, b);\n        lazy[t] = composition(f,\
    \ lazy[t]);\n        return t;\n    }\n    // \u30CE\u30FC\u30C9 t ([a, b)) \u306E\
    \ lazy \u3092\u5B50\u306B\u4F1D\u3048\u308B\n    void push(int t, long long a,\
    \ long long b) {\n        long long mid = (a + b) / 2;\n        const F f = lazy[t];\n\
    \        int l = apply_node(left[t], a, mid, f);\n        left[t] = l;\n     \
    \   int r = apply_node(right[t], mid, b, f);\n        right[t] = r;\n        lazy[t]\
    \ = id();\n    }\n    S value(int t) const { return t == -1 ? e() : val[t]; }\n\
    \    void update(int t) { val[t] = op(value(left[t]), value(right[t])); }\n\n\
    \    int set_rec(int t, long long a, long long b, long long k, const S& x) {\n\
    \        if (b - a == 1) {\n            if (t == -1) return make_node(x, id());\n\
    \            val[t] = x;\n            return t;\n        }\n        long long\
    \ mid = (a + b) / 2;\n        // \u4F5C\u3063\u305F\u3070\u304B\u308A\u306E\u30CE\
    \u30FC\u30C9\u306F\u5B50\u304C\u306A\u304F lazy \u3082\u6052\u7B49\u5199\u50CF\
    \u306A\u306E\u3067\u3001\u4F1D\u3048\u306A\u304F\u3066\u3088\u3044\n        if\
    \ (t == -1)\n            t = make_node(e(), id());\n        else\n           \
    \ push(t, a, b);\n        if (k < mid) {\n            int c = set_rec(left[t],\
    \ a, mid, k, x);\n            left[t] = c;\n        } else {\n            int\
    \ c = set_rec(right[t], mid, b, k, x);\n            right[t] = c;\n        }\n\
    \        update(t);\n        return t;\n    }\n    int apply_rec(int t, long long\
    \ a, long long b, long long l, long long r, const F& f) {\n        if (r <= a\
    \ || b <= l) return t;\n        if (l <= a && b <= r) return apply_node(t, a,\
    \ b, f);\n        long long mid = (a + b) / 2;\n        if (t == -1)\n       \
    \     t = make_node(e(), id());\n        else\n            push(t, a, b);\n  \
    \      int lc = apply_rec(left[t], a, mid, l, r, f);\n        left[t] = lc;\n\
    \        int rc = apply_rec(right[t], mid, b, l, r, f);\n        right[t] = rc;\n\
    \        update(t);\n        return t;\n    }\n    // f \u306F\u30CE\u30FC\u30C9\
    \ t \u306E\u7956\u5148\u306B\u3042\u3063\u3066\u3001\u307E\u3060 t \u306B\u9069\
    \u7528\u3057\u3066\u3044\u306A\u3044\u4F5C\u7528\u7D20\n    S prod_rec(int t,\
    \ long long a, long long b, long long l, long long r, const F& f) const {\n  \
    \      if (r <= a || b <= l) return e();\n        // \u4F5C\u3063\u3066\u3044\u306A\
    \u3044\u30CE\u30FC\u30C9\u306E\u533A\u9593\u306F\u5358\u4F4D\u5143\u3060\u3051\
    \u306A\u306E\u3067\u3001f \u3092\u4F5C\u7528\u3055\u305B\u305F\u5024\u306F\u533A\
    \u9593\u306E\u4F4D\u7F6E\u3060\u3051\u3067\u6C7A\u307E\u308B\n        if (t ==\
    \ -1) return mapping(f, e(), std::max(a, l), std::min(b, r));\n        if (l <=\
    \ a && b <= r) return mapping(f, val[t], a, b);\n        long long mid = (a +\
    \ b) / 2;\n        F g = composition(f, lazy[t]);\n        return op(prod_rec(left[t],\
    \ a, mid, l, r, g), prod_rec(right[t], mid, b, l, r, g));\n    }\n    // [a, b)\
    \ \u306E\u3046\u3061 l \u4EE5\u964D\u3067\u3001sum \u306B\u639B\u3051\u308B\u3068\
    \ g \u304C\u507D\u306B\u306A\u308B\u6700\u521D\u306E\u4F4D\u7F6E (\u306A\u3051\
    \u308C\u3070 b)\n    template <typename G>\n    long long max_right_rec(int t,\
    \ long long a, long long b, long long l, G& g, S& sum, const F& f) const {\n \
    \       if (b <= l) return b;\n        if (l <= a) {\n            S s = op(sum,\
    \ t == -1 ? mapping(f, e(), a, b) : mapping(f, val[t], a, b));\n            if\
    \ (g(s)) {\n                sum = s;\n                return b;\n            }\n\
    \            if (b - a == 1) return a;\n        }\n        long long mid = (a\
    \ + b) / 2;\n        F h = t == -1 ? f : composition(f, lazy[t]);\n        long\
    \ long x = max_right_rec(t == -1 ? -1 : left[t], a, mid, l, g, sum, h);\n    \
    \    if (x < mid) return x;\n        return max_right_rec(t == -1 ? -1 : right[t],\
    \ mid, b, l, g, sum, h);\n    }\n    // [a, b) \u306E\u3046\u3061 r \u3088\u308A\
    \u524D\u3067\u3001sum \u306B\u5DE6\u304B\u3089\u639B\u3051\u308B\u3068 g \u304C\
    \u507D\u306B\u306A\u308B\u6700\u5F8C\u306E\u4F4D\u7F6E + 1 (\u306A\u3051\u308C\
    \u3070 a)\n    template <typename G>\n    long long min_left_rec(int t, long long\
    \ a, long long b, long long r, G& g, S& sum, const F& f) const {\n        if (r\
    \ <= a) return a;\n        if (b <= r) {\n            S s = op(t == -1 ? mapping(f,\
    \ e(), a, b) : mapping(f, val[t], a, b), sum);\n            if (g(s)) {\n    \
    \            sum = s;\n                return a;\n            }\n            if\
    \ (b - a == 1) return b;\n        }\n        long long mid = (a + b) / 2;\n  \
    \      F h = t == -1 ? f : composition(f, lazy[t]);\n        long long x = min_left_rec(t\
    \ == -1 ? -1 : right[t], mid, b, r, g, sum, h);\n        if (x > mid) return x;\n\
    \        return min_left_rec(t == -1 ? -1 : left[t], a, mid, r, g, sum, h);\n\
    \    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n     *\n     * \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u5358\u4F4D\u5143\
    \u3067\u521D\u671F\u5316\u3059\u308B\u3002\u30CE\u30FC\u30C9\u306F\u66F4\u65B0\
    \u3057\u305F\u3068\u304D\u306B\u4F5C\u308B\u306E\u3067 O(1)\n     *\n     * @param\
    \ n \u8981\u7D20\u6570\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\
    \u30A4\u30C9\n     */\n    explicit DynamicLazySegTree(long long n = 0, A a =\
    \ A()) : a(std::move(a)), n(n), root(-1) {\n        assert(0 <= n);\n    }\n\n\
    \    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long\
    \ long size() const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n \
    \   S get(long long k) const {\n        assert(0 <= k && k < n);\n        int\
    \ t = root;\n        long long a = 0, b = n;\n        F f = id();\n        while\
    \ (t != -1 && b - a > 1) {\n            f = composition(f, lazy[t]);\n       \
    \     long long mid = (a + b) / 2;\n            if (k < mid) {\n             \
    \   t = left[t];\n                b = mid;\n            } else {\n           \
    \     t = right[t];\n                a = mid;\n            }\n        }\n    \
    \    return mapping(f, t == -1 ? e() : val[t], k, k + 1);\n    }\n    /**\n  \
    \   * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\
    \u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ S \u5024\n     */\n    S operator[](long long k) const { return get(k); }\n\
    \    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u3078\u306E\
    \u53C2\u7167\u3092\u8FD4\u3059\n     *\n     * @param k\n     * @return DynamicLazySegTreeReference\
    \ \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\u5165\u3055\u308C\u308B\u3068set()\u304C\
    \u547C\u3070\u308C\u308B\n     */\n    DynamicLazySegTreeReference operator[](long\
    \ long k) { return DynamicLazySegTreeReference(*this, k); }\n\n    /**\n     *\
    \ @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u66F4\
    \u65B0\u3059\u308B\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @param x \u65B0\u3057\u3044\u5024\n     */\n    void set(long long k,\
    \ const S& x) {\n        assert(0 <= k && k < n);\n        root = set_rec(root,\
    \ 0, n, k, x);\n    }\n\n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\
    \u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\u958B\u533A\u9593\
    \u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \ 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(long long l,\
    \ long long r) const {\n        assert(0 <= l && l <= r && r <= n);\n        if\
    \ (l == r) return e();\n        return prod_rec(root, 0, n, l, r, id());\n   \
    \ }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\
    \u3092\u8FD4\u3059\n     *\n     * @return S \u7DCF\u7A4D\n     */\n    S all_prod()\
    \ const { return value(root); }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u306E\u5024\u306Bf\u3092\u4F5C\u7528\u3055\u305B\u308B\n  \
    \   *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param f \u4F5C\
    \u7528\u7D20\n     */\n    void apply(long long k, const F& f) {\n        assert(0\
    \ <= k && k < n);\n        apply(k, k + 1, f);\n    }\n    /**\n     * @brief\
    \ [l, r)\u306E\u533A\u9593\u306E\u5024\u306Bf\u3092\u4F5C\u7528\u3055\u305B\u308B\
    \n     *\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param\
    \ r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @param f \u4F5C\
    \u7528\u7D20\n     */\n    void apply(long long l, long long r, const F& f) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n  \
    \      root = apply_rec(root, 0, n, l, r, f);\n    }\n\n    /**\n     * @brief\
    \ (r = l or g(prod([l, r))) = true) and (r = n or g(prod([l, r+1))) = false)\u3068\
    \u306A\u308Br\u3092\u8FD4\u3059\n     * g\u304C\u5358\u8ABF\u306A\u3089\u3001\
    g(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n     *\n     * @tparam\
    \ G\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB 0<=l<=n\n    \
    \ * @param g \u5224\u5B9A\u95A2\u6570 g(e) = true\n     * @return long long\n\
    \     */\n    template <typename G>\n    long long max_right(long long l, G g)\
    \ const {\n        assert(g(e()));\n        assert(0 <= l && l <= n);\n      \
    \  if (l == n) return n;\n        S sum = e();\n        return max_right_rec(root,\
    \ 0, n, l, g, sum, id());\n    }\n    /**\n     * @brief (l = 0 or g(prod([l,\
    \ r))) = true) and (l = r or g(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\
    \u8FD4\u3059\n     * g\u304C\u5358\u8ABF\u306A\u3089\u3001g(prod([l, r))) = true\u3068\
    \u306A\u308B\u6700\u5C0F\u306El\n     *\n     * @tparam G\n     * @param r \u534A\
    \u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param g \u5224\u5B9A\u95A2\
    \u6570 g(e) = true\n     * @return long long\n     */\n    template <typename\
    \ G>\n    long long min_left(long long r, G g) const {\n        assert(g(e()));\n\
    \        assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        S sum\
    \ = e();\n        return min_left_rec(root, 0, n, r, g, sum, id());\n    }\n};\n\
    \ntemplate <typename A>\nDynamicLazySegTree(long long, A) -> DynamicLazySegTree<A>;\n"
  code: "#pragma once\n\n/**\n * @file dynamic-lazy-segtree.hpp\n * @brief \u52D5\u7684\
    \u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\n#include\
    \ \"../algebra/acted-monoid.hpp\"\n\n/**\n * @brief \u52D5\u7684\u9045\u5EF6\u4F1D\
    \u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u8981\u7D20\u6570\u304C\u5927\
    \u304D\u304F\u3066\u3082\u4F7F\u3048\u308B\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3002\u6700\u521D\u306F\u3059\u3079\u3066\u5358\u4F4D\
    \u5143\u3067\u3001\u66F4\u65B0\u3057\u305F\u3068\u3053\u308D\u306E\u30CE\u30FC\
    \u30C9\u3060\u3051\u3092\u4F5C\u308B\n * \u4F8B:\n * DynamicLazySegTree<acted_monoid::AddSum<long\
    \ long>> seg(1000000000000000000);\n * seg.apply(0, 1000000000000000000, 1);\n\
    \ * seg.prod(10, 20);  // 10\n *\n * @tparam A \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\n */\ntemplate <typename A>\nclass\
    \ DynamicLazySegTree {\n   public:\n    using S = typename A::S;\n    using F\
    \ = typename A::F;\n\n   private:\n    A a;\n    S op(const S& x, const S& y)\
    \ const { return a.op(x, y); }\n    S e() const { return a.e(); }\n    S mapping(const\
    \ F& f, const S& x, long long l, long long r) const { return acted_monoid::apply_mapping(a,\
    \ f, x, l, r); }\n    F composition(const F& f, const F& g) const { return a.composition(f,\
    \ g); }\n    F id() const { return a.id(); }\n\n    long long n;\n    int root;\
    \  // \u307E\u3060\u4F5C\u3063\u3066\u3044\u306A\u3044\u30CE\u30FC\u30C9\u306F\
    \ -1 \u3067\u3001\u533A\u9593\u306E\u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u5358\
    \u4F4D\u5143\u3067\u3042\u308B\u3053\u3068\u3092\u8868\u3059\n    // val \u306F\
    \u30CE\u30FC\u30C9\u306E\u533A\u9593\u306E\u7A4D\u3067\u3001\u305D\u306E\u30CE\
    \u30FC\u30C9\u306E lazy \u306F\u9069\u7528\u6E08\u307F\u3002lazy \u306F\u5B50\u306B\
    \u307E\u3060\u4F1D\u3048\u3066\u3044\u306A\u3044\u4F5C\u7528\u7D20\n    std::vector<S>\
    \ val;\n    std::vector<F> lazy;\n    std::vector<int> left, right;\n\n    class\
    \ DynamicLazySegTreeReference {\n        DynamicLazySegTree& segtree;\n      \
    \  long long k;\n\n       public:\n        DynamicLazySegTreeReference(DynamicLazySegTree&\
    \ segtree, long long k) : segtree(segtree), k(k) {}\n        DynamicLazySegTreeReference&\
    \ operator=(const S& x) {\n            segtree.set(k, x);\n            return\
    \ *this;\n        }\n        operator S() const { return segtree.get(k); }\n \
    \   };\n\n    int make_node(const S& x, const F& f) {\n        val.push_back(x);\n\
    \        lazy.push_back(f);\n        left.push_back(-1);\n        right.push_back(-1);\n\
    \        return int(val.size()) - 1;\n    }\n    // \u30CE\u30FC\u30C9 t ([a,\
    \ b)) \u306B f \u3092\u4F5C\u7528\u3055\u305B\u308B\u3002t \u304C -1 \u306A\u3089\
    \u30CE\u30FC\u30C9\u3092\u4F5C\u308B\n    int apply_node(int t, long long a, long\
    \ long b, const F& f) {\n        if (t == -1) return make_node(mapping(f, e(),\
    \ a, b), f);\n        val[t] = mapping(f, val[t], a, b);\n        lazy[t] = composition(f,\
    \ lazy[t]);\n        return t;\n    }\n    // \u30CE\u30FC\u30C9 t ([a, b)) \u306E\
    \ lazy \u3092\u5B50\u306B\u4F1D\u3048\u308B\n    void push(int t, long long a,\
    \ long long b) {\n        long long mid = (a + b) / 2;\n        const F f = lazy[t];\n\
    \        int l = apply_node(left[t], a, mid, f);\n        left[t] = l;\n     \
    \   int r = apply_node(right[t], mid, b, f);\n        right[t] = r;\n        lazy[t]\
    \ = id();\n    }\n    S value(int t) const { return t == -1 ? e() : val[t]; }\n\
    \    void update(int t) { val[t] = op(value(left[t]), value(right[t])); }\n\n\
    \    int set_rec(int t, long long a, long long b, long long k, const S& x) {\n\
    \        if (b - a == 1) {\n            if (t == -1) return make_node(x, id());\n\
    \            val[t] = x;\n            return t;\n        }\n        long long\
    \ mid = (a + b) / 2;\n        // \u4F5C\u3063\u305F\u3070\u304B\u308A\u306E\u30CE\
    \u30FC\u30C9\u306F\u5B50\u304C\u306A\u304F lazy \u3082\u6052\u7B49\u5199\u50CF\
    \u306A\u306E\u3067\u3001\u4F1D\u3048\u306A\u304F\u3066\u3088\u3044\n        if\
    \ (t == -1)\n            t = make_node(e(), id());\n        else\n           \
    \ push(t, a, b);\n        if (k < mid) {\n            int c = set_rec(left[t],\
    \ a, mid, k, x);\n            left[t] = c;\n        } else {\n            int\
    \ c = set_rec(right[t], mid, b, k, x);\n            right[t] = c;\n        }\n\
    \        update(t);\n        return t;\n    }\n    int apply_rec(int t, long long\
    \ a, long long b, long long l, long long r, const F& f) {\n        if (r <= a\
    \ || b <= l) return t;\n        if (l <= a && b <= r) return apply_node(t, a,\
    \ b, f);\n        long long mid = (a + b) / 2;\n        if (t == -1)\n       \
    \     t = make_node(e(), id());\n        else\n            push(t, a, b);\n  \
    \      int lc = apply_rec(left[t], a, mid, l, r, f);\n        left[t] = lc;\n\
    \        int rc = apply_rec(right[t], mid, b, l, r, f);\n        right[t] = rc;\n\
    \        update(t);\n        return t;\n    }\n    // f \u306F\u30CE\u30FC\u30C9\
    \ t \u306E\u7956\u5148\u306B\u3042\u3063\u3066\u3001\u307E\u3060 t \u306B\u9069\
    \u7528\u3057\u3066\u3044\u306A\u3044\u4F5C\u7528\u7D20\n    S prod_rec(int t,\
    \ long long a, long long b, long long l, long long r, const F& f) const {\n  \
    \      if (r <= a || b <= l) return e();\n        // \u4F5C\u3063\u3066\u3044\u306A\
    \u3044\u30CE\u30FC\u30C9\u306E\u533A\u9593\u306F\u5358\u4F4D\u5143\u3060\u3051\
    \u306A\u306E\u3067\u3001f \u3092\u4F5C\u7528\u3055\u305B\u305F\u5024\u306F\u533A\
    \u9593\u306E\u4F4D\u7F6E\u3060\u3051\u3067\u6C7A\u307E\u308B\n        if (t ==\
    \ -1) return mapping(f, e(), std::max(a, l), std::min(b, r));\n        if (l <=\
    \ a && b <= r) return mapping(f, val[t], a, b);\n        long long mid = (a +\
    \ b) / 2;\n        F g = composition(f, lazy[t]);\n        return op(prod_rec(left[t],\
    \ a, mid, l, r, g), prod_rec(right[t], mid, b, l, r, g));\n    }\n    // [a, b)\
    \ \u306E\u3046\u3061 l \u4EE5\u964D\u3067\u3001sum \u306B\u639B\u3051\u308B\u3068\
    \ g \u304C\u507D\u306B\u306A\u308B\u6700\u521D\u306E\u4F4D\u7F6E (\u306A\u3051\
    \u308C\u3070 b)\n    template <typename G>\n    long long max_right_rec(int t,\
    \ long long a, long long b, long long l, G& g, S& sum, const F& f) const {\n \
    \       if (b <= l) return b;\n        if (l <= a) {\n            S s = op(sum,\
    \ t == -1 ? mapping(f, e(), a, b) : mapping(f, val[t], a, b));\n            if\
    \ (g(s)) {\n                sum = s;\n                return b;\n            }\n\
    \            if (b - a == 1) return a;\n        }\n        long long mid = (a\
    \ + b) / 2;\n        F h = t == -1 ? f : composition(f, lazy[t]);\n        long\
    \ long x = max_right_rec(t == -1 ? -1 : left[t], a, mid, l, g, sum, h);\n    \
    \    if (x < mid) return x;\n        return max_right_rec(t == -1 ? -1 : right[t],\
    \ mid, b, l, g, sum, h);\n    }\n    // [a, b) \u306E\u3046\u3061 r \u3088\u308A\
    \u524D\u3067\u3001sum \u306B\u5DE6\u304B\u3089\u639B\u3051\u308B\u3068 g \u304C\
    \u507D\u306B\u306A\u308B\u6700\u5F8C\u306E\u4F4D\u7F6E + 1 (\u306A\u3051\u308C\
    \u3070 a)\n    template <typename G>\n    long long min_left_rec(int t, long long\
    \ a, long long b, long long r, G& g, S& sum, const F& f) const {\n        if (r\
    \ <= a) return a;\n        if (b <= r) {\n            S s = op(t == -1 ? mapping(f,\
    \ e(), a, b) : mapping(f, val[t], a, b), sum);\n            if (g(s)) {\n    \
    \            sum = s;\n                return a;\n            }\n            if\
    \ (b - a == 1) return b;\n        }\n        long long mid = (a + b) / 2;\n  \
    \      F h = t == -1 ? f : composition(f, lazy[t]);\n        long long x = min_left_rec(t\
    \ == -1 ? -1 : right[t], mid, b, r, g, sum, h);\n        if (x > mid) return x;\n\
    \        return min_left_rec(t == -1 ? -1 : left[t], a, mid, r, g, sum, h);\n\
    \    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n     *\n     * \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u5358\u4F4D\u5143\
    \u3067\u521D\u671F\u5316\u3059\u308B\u3002\u30CE\u30FC\u30C9\u306F\u66F4\u65B0\
    \u3057\u305F\u3068\u304D\u306B\u4F5C\u308B\u306E\u3067 O(1)\n     *\n     * @param\
    \ n \u8981\u7D20\u6570\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\
    \u30A4\u30C9\n     */\n    explicit DynamicLazySegTree(long long n = 0, A a =\
    \ A()) : a(std::move(a)), n(n), root(-1) {\n        assert(0 <= n);\n    }\n\n\
    \    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long\
    \ long size() const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n \
    \   S get(long long k) const {\n        assert(0 <= k && k < n);\n        int\
    \ t = root;\n        long long a = 0, b = n;\n        F f = id();\n        while\
    \ (t != -1 && b - a > 1) {\n            f = composition(f, lazy[t]);\n       \
    \     long long mid = (a + b) / 2;\n            if (k < mid) {\n             \
    \   t = left[t];\n                b = mid;\n            } else {\n           \
    \     t = right[t];\n                a = mid;\n            }\n        }\n    \
    \    return mapping(f, t == -1 ? e() : val[t], k, k + 1);\n    }\n    /**\n  \
    \   * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\
    \u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ S \u5024\n     */\n    S operator[](long long k) const { return get(k); }\n\
    \    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u3078\u306E\
    \u53C2\u7167\u3092\u8FD4\u3059\n     *\n     * @param k\n     * @return DynamicLazySegTreeReference\
    \ \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\u5165\u3055\u308C\u308B\u3068set()\u304C\
    \u547C\u3070\u308C\u308B\n     */\n    DynamicLazySegTreeReference operator[](long\
    \ long k) { return DynamicLazySegTreeReference(*this, k); }\n\n    /**\n     *\
    \ @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u66F4\
    \u65B0\u3059\u308B\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @param x \u65B0\u3057\u3044\u5024\n     */\n    void set(long long k,\
    \ const S& x) {\n        assert(0 <= k && k < n);\n        root = set_rec(root,\
    \ 0, n, k, x);\n    }\n\n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\
    \u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\u958B\u533A\u9593\
    \u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \ 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(long long l,\
    \ long long r) const {\n        assert(0 <= l && l <= r && r <= n);\n        if\
    \ (l == r) return e();\n        return prod_rec(root, 0, n, l, r, id());\n   \
    \ }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\
    \u3092\u8FD4\u3059\n     *\n     * @return S \u7DCF\u7A4D\n     */\n    S all_prod()\
    \ const { return value(root); }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u306E\u5024\u306Bf\u3092\u4F5C\u7528\u3055\u305B\u308B\n  \
    \   *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param f \u4F5C\
    \u7528\u7D20\n     */\n    void apply(long long k, const F& f) {\n        assert(0\
    \ <= k && k < n);\n        apply(k, k + 1, f);\n    }\n    /**\n     * @brief\
    \ [l, r)\u306E\u533A\u9593\u306E\u5024\u306Bf\u3092\u4F5C\u7528\u3055\u305B\u308B\
    \n     *\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param\
    \ r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @param f \u4F5C\
    \u7528\u7D20\n     */\n    void apply(long long l, long long r, const F& f) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n  \
    \      root = apply_rec(root, 0, n, l, r, f);\n    }\n\n    /**\n     * @brief\
    \ (r = l or g(prod([l, r))) = true) and (r = n or g(prod([l, r+1))) = false)\u3068\
    \u306A\u308Br\u3092\u8FD4\u3059\n     * g\u304C\u5358\u8ABF\u306A\u3089\u3001\
    g(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n     *\n     * @tparam\
    \ G\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB 0<=l<=n\n    \
    \ * @param g \u5224\u5B9A\u95A2\u6570 g(e) = true\n     * @return long long\n\
    \     */\n    template <typename G>\n    long long max_right(long long l, G g)\
    \ const {\n        assert(g(e()));\n        assert(0 <= l && l <= n);\n      \
    \  if (l == n) return n;\n        S sum = e();\n        return max_right_rec(root,\
    \ 0, n, l, g, sum, id());\n    }\n    /**\n     * @brief (l = 0 or g(prod([l,\
    \ r))) = true) and (l = r or g(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\
    \u8FD4\u3059\n     * g\u304C\u5358\u8ABF\u306A\u3089\u3001g(prod([l, r))) = true\u3068\
    \u306A\u308B\u6700\u5C0F\u306El\n     *\n     * @tparam G\n     * @param r \u534A\
    \u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param g \u5224\u5B9A\u95A2\
    \u6570 g(e) = true\n     * @return long long\n     */\n    template <typename\
    \ G>\n    long long min_left(long long r, G g) const {\n        assert(g(e()));\n\
    \        assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        S sum\
    \ = e();\n        return min_left_rec(root, 0, n, r, g, sum, id());\n    }\n};\n\
    \ntemplate <typename A>\nDynamicLazySegTree(long long, A) -> DynamicLazySegTree<A>;\n"
  dependsOn:
  - src/algebra/acted-monoid.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/data_structures/dynamic-lazy-segtree.hpp
  requiredBy: []
  timestamp: '2026-10-15 02:41:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dynamic-lazy-segtree.test.cpp
  - test/yosupo/range-affine-range-sum-large-array.test.cpp
documentation_of: src/data_structures/dynamic-lazy-segtree.hpp
layout: document
title: "\u52D5\u7684\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

要素数が大きくても使える遅延伝搬セグメント木です。作用素付きモノイド ([algebra/acted-monoid.hpp](../algebra/acted-monoid.hpp)) を渡して使います。最初はすべて単位元で、更新したところのノードだけを作ります。添字は `long long` で、要素数が $10^{18}$ でも使えます。

```cpp
DynamicLazySegTree<acted_monoid::AddSum<long long>> seg(1000000000000000000);
seg.apply(0, 1000000000000000000, 1);   // すべてに 1 を足す
seg.prod(10, 20);                       // 10
seg.set(15, 100);
seg.prod(10, 20);                       // 109
```

負の添字を使いたいときは、その分ずらして使います。

`mapping` に渡す区間の長さや位置も `long long` になります。

`apply`・`set` は、たどるノードの作用素を子に伝えます。このとき、まだ作っていない子も作ります。`get`・`prod`・`max_right`・`min_left` はノードを作らず、上の作用素を合成しながら下ります。まだ作っていない部分木は、すべて単位元として扱います。

$N$ を要素数とします。メモリは更新の回数 × $O(\log N)$ です。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `DynamicLazySegTree(n, a = A())` | 要素数 `n` (`long long`)、すべて単位元で初期化 | $O(1)$ |
| `size()` | 要素数 (`long long`) | $O(1)$ |
| `get(k)` / `seg[k]` | `k` 番目の値 | $O(\log N)$ |
| `set(k, x)` / `seg[k] = x` | `k` 番目を `x` に更新 | $O(\log N)$ |
| `prod(l, r)` | 区間 $[l, r)$ の積 | $O(\log N)$ |
| `all_prod()` | 全体の積 | $O(1)$ |
| `apply(k, f)` | `k` 番目に `f` を作用 | $O(\log N)$ |
| `apply(l, r, f)` | 区間 $[l, r)$ に `f` を作用 | $O(\log N)$ |
| `max_right(l, g)` | `g(prod(l, r))` が真となる最大の `r` (`g` は単調) | $O(\log N)$ |
| `min_left(r, g)` | `g(prod(l, r))` が真となる最小の `l` (`g` は単調) | $O(\log N)$ |

## 関連

- 要素数が小さいなら [遅延伝搬セグメント木](lazy-segtree.hpp) の方が速い
- 1点更新だけなら [動的セグメント木](dynamic-segtree.hpp)
- 過去の版も使うなら [永続遅延伝搬セグメント木](persistent-lazy-segtree.hpp) (添字は `int`)
