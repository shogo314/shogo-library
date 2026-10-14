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
    path: src/data_structures/segtree-beats.hpp
    title: Segment Tree Beats
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
  bundledCode: "#line 1 \"test/unittest/segtree-beats.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ SegTreeBeats \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u533A\u9593 chmin / chmax / \u52A0\u7B97\u3001\
    1 \u70B9\u306E apply / set / get / seg[k]\u3001prod\u3001all_prod\u3001max_right\u3001\
    min_left\u3001size\u3001os << seg\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/segtree-beats.hpp\"\
    \n\n/**\n * @file segtree-beats.hpp\n * @brief Segment Tree Beats\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <ostream>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"src/algebra/acted-monoid.hpp\"\n\n\
    /**\n * @file acted-monoid.hpp\n * @brief \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
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
    \n#include <array>\n#include <limits>\n#include <optional>\n#include <type_traits>\n\
    #line 24 \"src/algebra/acted-monoid.hpp\"\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#line 16 \"src/algebra/monoid.hpp\"\n#include <cstddef>\n\
    #include <istream>\n#line 19 \"src/algebra/monoid.hpp\"\n#include <numeric>\n\
    #line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\u95A2\u6570 f(x)\
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
    \ }\n};\n\n/**\n * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\
    \u3044\u306A\u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis\
    \ {\n    struct S {\n        long long close;  // \u5BFE\u5FDC\u306E\u53D6\u308C\
    \u3066\u3044\u306A\u3044 ')' \u306E\u500B\u6570\n        long long open;   //\
    \ \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\
    \n        constexpr S(char c = 0) : close(c == ')'), open(c == '(') {}\n     \
    \   constexpr S(long long close, long long open) : close(close), open(open) {}\n\
    \        /**\n         * @brief \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n \
    \        */\n        constexpr bool is_valid() const { return close == 0 && open\
    \ == 0; }\n    };\n    static constexpr S op(const S& a, const S& b) {\n     \
    \   if (a.open >= b.close) return S(a.close, a.open - b.close + b.open);\n   \
    \     return S(a.close + b.close - a.open, b.open);\n    }\n    static constexpr\
    \ S e() { return S(); }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\
    \u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n\
    \ * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\
    \u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename T, typename U =\
    \ long long>\nstruct MinWith {\n    using S = std::pair<T, U>;\n    static constexpr\
    \ S op(const S& a, const S& b) { return b.first < a.first ? b : a; }\n    static\
    \ constexpr S e() { return {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n\
    \ * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\
    \u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\
    \n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\
    \u578B\n */\ntemplate <typename T, typename U = long long>\nstruct MaxWith {\n\
    \    using S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S&\
    \ b) { return a.first < b.first ? b : a; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::lowest(), U{}}; }\n};\n\n/**\n * @brief \u6700\u5C0F\
    \u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\u578B\n *\
    \ @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename U =\
    \ long long>\nstruct MinCount {\n    using S = std::pair<T, U>;\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        if (a.first < b.first) return a;\n \
    \       if (b.first < a.first) return b;\n        return {a.first, a.second +\
    \ b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MaxCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if (a.first < b.first) return b;\n        if (b.first < a.first) return\
    \ a;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U(0)}; }\n};\n\n/**\n * @brief\
    \ \u7A4D\u306E\u9806\u5E8F\u3092\u9006\u306B\u3057\u305F\u30E2\u30CE\u30A4\u30C9\
    \ op(a, b) = M::op(b, a)\n *\n * \u4F8B: SegTree<monoid::Reverse<monoid::Composite<mint>>>\
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
    \ T) -> Monoid<T, Op>;\n#line 26 \"src/algebra/acted-monoid.hpp\"\n\nnamespace\
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
    #line 16 \"src/data_structures/segtree-beats.hpp\"\n\n/**\n * @brief Segment Tree\
    \ Beats\n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\
    \ \u3068\u540C\u3058\u5F62\u306E\u578B\u3092\u53D7\u3051\u53D6\u308B\u304C\u3001\
    \n * mapping \u306F std::pair<bool, S> (\u4F5C\u7528\u306B\u5931\u6557\u3057\u305F\
    \u304B, \u4F5C\u7528\u5F8C\u306E\u5024) \u3092\u8FD4\u3059\n * \u5931\u6557\u3057\
    \u305F\u5834\u5408\u306F\u5B50\u306B\u4F1D\u642C\u3057\u3066\u304B\u3089\u8A08\
    \u7B97\u3057\u76F4\u3059\n *\n * @tparam A \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\
    \u30CE\u30A4\u30C9\n */\ntemplate <typename A>\nclass SegTreeBeats {\n   public:\n\
    \    using S = typename A::S;\n    using F = typename A::F;\n\n   private:\n \
    \   A a;\n    S op(const S& x, const S& y) const { return a.op(x, y); }\n    S\
    \ e() const { return a.e(); }\n    std::pair<bool, S> mapping(const F& f, const\
    \ S& x, long long l, long long r) const { return acted_monoid::apply_mapping(a,\
    \ f, x, l, r); }\n    F composition(const F& f, const F& g) const { return a.composition(f,\
    \ g); }\n    F id() const { return a.id(); }\n\n    long long n, sz;\n    int\
    \ height;\n    std::vector<S> data;\n    std::vector<int> fail;\n    std::vector<F>\
    \ lazy;\n\n    void update(long long k) {\n        data[k] = op(data[2 * k], data[2\
    \ * k + 1]);\n        fail[k] = false;\n    }\n    void apply_node(long long k,\
    \ int h, const F& f) {\n        // \u672B\u5C3E\u306E\u8981\u7D20\u6570\u3092\
    \ 2 \u3079\u304D\u306B\u305D\u308D\u3048\u308B\u305F\u3081\u306E\u4F59\u308A\u306E\
    \u90E8\u5206\u306F\u533A\u9593\u306B\u542B\u3081\u306A\u3044\n        long long\
    \ l = std::min((k << h) & (sz - 1), n);\n        long long r = std::min(((k <<\
    \ h) & (sz - 1)) + (1LL << h), n);\n        std::tie(fail[k], data[k]) = mapping(f,\
    \ data[k], l, r);\n        if (k < sz) {\n            lazy[k] = composition(f,\
    \ lazy[k]);\n            if (fail[k]) {\n                push(k, h);\n       \
    \         update(k);\n            }\n        }\n    }\n    void push(long long\
    \ k, int h) {\n        apply_node(2 * k, h - 1, lazy[k]);\n        apply_node(2\
    \ * k + 1, h - 1, lazy[k]);\n        lazy[k] = id();\n    }\n\n    class SegTreeBeatsReference\
    \ {\n        SegTreeBeats& segtree;\n        long long k;\n\n       public:\n\
    \        SegTreeBeatsReference(SegTreeBeats& segtree, long long k) : segtree(segtree),\
    \ k(k) {}\n        SegTreeBeatsReference& operator=(const S& x) {\n          \
    \  segtree.set(k, x);\n            return *this;\n        }\n        operator\
    \ S() { return segtree.get(k); }\n    };\n\n    void construct_data() {\n    \
    \    sz = 1;\n        height = 0;\n        while (sz < n) {\n            sz <<=\
    \ 1;\n            height++;\n        }\n        data.assign(sz * 2, e());\n  \
    \      fail.assign(sz * 2, false);\n        lazy.assign(sz * 2, id());\n    }\n\
    \n   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     *\n     * @param n \u8981\u7D20\u6570\n     * @param a \u4F5C\u7528\u7D20\
    \u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit SegTreeBeats(long\
    \ long n = 0, A a = A()) : a(std::move(a)), n(n) {\n        construct_data();\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param a \u4F5C\u7528\
    \u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit SegTreeBeats(const\
    \ std::vector<S>& v, A a = A()) : SegTreeBeats(v.size(), std::move(a)) {\n   \
    \     for (long long i = 0; i < n; i++) data[sz + i] = v[i];\n        for (long\
    \ long i = sz - 1; i > 0; i--) update(i);\n    }\n\n    /**\n     * @brief \u8981\
    \u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long long size() const { return n;\
    \ }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\n     * @return S \u5024\n     */\n    S get(long long k) {\n        assert(0\
    \ <= k && k < n);\n        k += sz;\n        for (int h = height; h > 0; h--)\
    \ {\n            push(k >> h, h);\n        }\n        return data[k];\n    }\n\
    \    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u3078\u306E\
    \u53C2\u7167\u3092\u8FD4\u3059\n     *\n     * @param k\n     * @return SegTreeReference\
    \ \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\u5165\u3055\u308C\u308B\u3068set()\u304C\
    \u547C\u3070\u308C\u308B\n     */\n    SegTreeBeatsReference operator[](long long\
    \ k) { return SegTreeBeatsReference(*this, k); }\n\n    /**\n     * @brief \u5185\
    \u5BB9\u3092\u51FA\u529B\u3059\u308B\n     *\n     * @tparam CharT \u51FA\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits\
    \ \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\
    \n     * @param os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     * @param rhs\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n     * @return std::basic_ostream<CharT,\
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
    \ A::S>, A) -> SegTreeBeats<A>;\n#line 8 \"test/unittest/segtree-beats.test.cpp\"\
    \n\n#line 10 \"test/unittest/segtree-beats.test.cpp\"\n#include <iostream>\n#include\
    \ <random>\n#include <sstream>\n#line 14 \"test/unittest/segtree-beats.test.cpp\"\
    \n\nconstexpr long long inf = 2e18;\n\n// test/yosupo/range-chmin-chmax-add-range-sum.1.test.cpp\
    \ \u3068\u540C\u3058\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\nstruct\
    \ Node {\n    // 1\u756A\u76EE\u30011\u756A\u76EE\u306E\u8981\u7D20\u6570\u3001\
    2\u756A\u76EE\u3001\u5408\u8A08\n    long long max1, max1_num, max2, min1, min1_num,\
    \ min2, sum;\n    Node(long long x = 0) : max1(x), max1_num(1), max2(-inf), min1(x),\
    \ min1_num(1), min2(inf), sum(x) {}\n};\nstd::ostream& operator<<(std::ostream&\
    \ os, const Node& x) { return os << x.sum; }\nstruct Clamp {\n    // clamp(x +\
    \ add, lb, ub)\n    long long lb, ub, add;\n};\nstruct ChminChmaxAddSum {\n  \
    \  using S = Node;\n    using F = Clamp;\n    S op(const S& l, const S& r) const\
    \ {\n        S res;\n        res.max1 = std::max(l.max1, r.max1);\n        if\
    \ (l.max1 == r.max1) {\n            res.max1_num = l.max1_num + r.max1_num;\n\
    \            res.max2 = std::max(l.max2, r.max2);\n        } else if (l.max1 >\
    \ r.max1) {\n            res.max1_num = l.max1_num;\n            res.max2 = std::max(l.max2,\
    \ r.max1);\n        } else {\n            res.max1_num = r.max1_num;\n       \
    \     res.max2 = std::max(l.max1, r.max2);\n        }\n        res.min1 = std::min(l.min1,\
    \ r.min1);\n        if (l.min1 == r.min1) {\n            res.min1_num = l.min1_num\
    \ + r.min1_num;\n            res.min2 = std::min(l.min2, r.min2);\n        } else\
    \ if (l.min1 < r.min1) {\n            res.min1_num = l.min1_num;\n           \
    \ res.min2 = std::min(l.min2, r.min1);\n        } else {\n            res.min1_num\
    \ = r.min1_num;\n            res.min2 = std::min(l.min1, r.min2);\n        }\n\
    \        res.sum = l.sum + r.sum;\n        return res;\n    }\n    S e() const\
    \ {\n        S res;\n        res.max1 = -inf;\n        res.max1_num = 0;\n   \
    \     res.max2 = -inf;\n        res.min1 = inf;\n        res.min1_num = 0;\n \
    \       res.min2 = inf;\n        res.sum = 0;\n        return res;\n    }\n  \
    \  std::pair<bool, S> mapping(const F& f, const S& x, int sz) const {\n      \
    \  S res = x;\n        res.max1 += f.add;\n        res.max2 += f.add;\n      \
    \  res.min1 += f.add;\n        res.min2 += f.add;\n        res.sum += f.add *\
    \ sz;\n        if (res.max1 == res.min1) {\n            long long x = std::clamp(res.max1,\
    \ f.lb, f.ub);\n            res.max1 = x;\n            res.max2 = -inf;\n    \
    \        res.min1 = x;\n            res.min2 = inf;\n            res.sum = x *\
    \ sz;\n            return {false, res};\n        }\n        if (res.max1 == res.min2)\
    \ {\n            long long xr = std::clamp(res.max1, f.lb, f.ub);\n          \
    \  long long xl = std::clamp(res.min1, f.lb, f.ub);\n            if (xr == xl)\
    \ {\n                res.max1 = xr;\n                res.max1_num = sz;\n    \
    \            res.max2 = -inf;\n                res.min1 = xr;\n              \
    \  res.min1_num = sz;\n                res.min2 = inf;\n                res.sum\
    \ = xr * sz;\n                return {false, res};\n            }\n          \
    \  res.max1 = xr;\n            res.max2 = xl;\n            res.min1 = xl;\n  \
    \          res.min2 = xr;\n            res.sum = xr * res.max1_num + xl * res.min1_num;\n\
    \            return {false, res};\n        }\n        if (f.ub <= res.max2) return\
    \ {true, res};\n        if (f.lb >= res.min2) return {true, res};\n        if\
    \ (f.ub < res.max1) {\n            res.sum -= (res.max1 - f.ub) * res.max1_num;\n\
    \            res.max1 = f.ub;\n        }\n        if (f.lb > res.min1) {\n   \
    \         res.sum += (f.lb - res.min1) * res.min1_num;\n            res.min1 =\
    \ f.lb;\n        }\n        return {false, res};\n    }\n    F composition(const\
    \ F& f, const F& g) const {\n        F res;\n        res.lb = std::clamp(g.lb\
    \ + f.add, f.lb, f.ub);\n        res.ub = std::clamp(g.ub + f.add, f.lb, f.ub);\n\
    \        res.add = f.add + g.add;\n        return res;\n    }\n    F id() const\
    \ {\n        F res;\n        res.lb = -inf;\n        res.ub = inf;\n        res.add\
    \ = 0;\n        return res;\n    }\n};\n\nbool ok = true;\nvoid check(bool cond,\
    \ const char* what) {\n    if (!cond && ok) std::cerr << \"failed: \" << what\
    \ << std::endl;\n    if (!cond) ok = false;\n}\n\nlong long clamp_apply(const\
    \ Clamp& f, long long x) { return std::clamp(x + f.add, f.lb, f.ub); }\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n    auto small = [&] { return (long\
    \ long)(rng() % 41) - 20; };\n    auto gen_f = [&]() -> Clamp {\n        long\
    \ long b = small();\n        switch (rng() % 3) {\n            case 0:\n     \
    \           return Clamp{-inf, b, 0};  // chmin\n            case 1:\n       \
    \         return Clamp{b, inf, 0};  // chmax\n            default:\n         \
    \       return Clamp{-inf, inf, b};  // add\n        }\n    };\n    for (int rep\
    \ = 0; rep < 300 && ok; rep++) {\n        int n = rng() % 24 + 1;\n        std::vector<long\
    \ long> a(n);\n        for (auto& x : a) x = small();\n        std::vector<Node>\
    \ init(a.begin(), a.end());\n        SegTreeBeats<ChminChmaxAddSum> seg(init);\n\
    \        check(seg.size() == n, \"size\");\n        for (int q = 0; q < 80 &&\
    \ ok; q++) {\n            int t = rng() % 8;\n            int l = rng() % (n +\
    \ 1), r = rng() % (n + 1);\n            if (l > r) std::swap(l, r);\n        \
    \    int k = rng() % n;\n            if (t == 0) {\n                Clamp f =\
    \ gen_f();\n                seg.apply(l, r, f);\n                for (int i =\
    \ l; i < r; i++) a[i] = clamp_apply(f, a[i]);\n            } else if (t == 1)\
    \ {\n                Clamp f = gen_f();\n                seg.apply(k, f);\n  \
    \              a[k] = clamp_apply(f, a[k]);\n            } else if (t == 2) {\n\
    \                long long x = small();\n                if (rng() % 2)\n    \
    \                seg.set(k, Node(x));\n                else\n                \
    \    seg[k] = Node(x);\n                a[k] = x;\n            } else if (t ==\
    \ 3) {\n                check(seg.get(k).sum == a[k], \"get\");\n            \
    \    Node x = seg[k];\n                check(x.sum == a[k] && x.max1 == a[k] &&\
    \ x.min1 == a[k], \"seg[k]\");\n            } else if (t == 4) {\n           \
    \     Node p = seg.prod(l, r);\n                long long sum = 0, mx = -inf,\
    \ mn = inf;\n                for (int i = l; i < r; i++) sum += a[i], mx = std::max(mx,\
    \ a[i]), mn = std::min(mn, a[i]);\n                check(p.sum == sum && p.max1\
    \ == mx && p.min1 == mn, \"prod\");\n            } else if (t == 5) {\n      \
    \          // \u6700\u5927\u5024\u304C x \u4EE5\u4E0B\u3067\u3042\u308B\u6700\u9577\
    \u306E\u533A\u9593 [l, r)\n                long long x = small();\n          \
    \      int expect = l;\n                while (expect < n && a[expect] <= x) expect++;\n\
    \                check(seg.max_right(l, [&](const Node& s) { return s.max1 <=\
    \ x; }) == expect, \"max_right\");\n            } else if (t == 6) {\n       \
    \         // \u6700\u5C0F\u5024\u304C x \u4EE5\u4E0A\u3067\u3042\u308B\u6700\u9577\
    \u306E\u533A\u9593 [l, r)\n                long long x = small();\n          \
    \      int expect = r;\n                while (expect > 0 && a[expect - 1] >=\
    \ x) expect--;\n                check(seg.min_left(r, [&](const Node& s) { return\
    \ s.min1 >= x; }) == expect, \"min_left\");\n            } else {\n          \
    \      long long sum = 0;\n                for (long long x : a) sum += x;\n \
    \               check(seg.all_prod().sum == sum, \"all_prod\");\n            }\n\
    \        }\n        std::ostringstream os, expect;\n        os << seg;\n     \
    \   for (int i = 0; i < n; i++) {\n            if (i != 0) expect << ' ';\n  \
    \          expect << a[i];\n        }\n        check(os.str() == expect.str(),\
    \ \"os << seg\");\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// SegTreeBeats \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u533A\u9593 chmin / chmax / \u52A0\u7B97\
    \u30011 \u70B9\u306E apply / set / get / seg[k]\u3001prod\u3001all_prod\u3001\
    max_right\u3001min_left\u3001size\u3001os << seg\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/segtree-beats.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <random>\n#include <sstream>\n\
    #include <vector>\n\nconstexpr long long inf = 2e18;\n\n// test/yosupo/range-chmin-chmax-add-range-sum.1.test.cpp\
    \ \u3068\u540C\u3058\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\nstruct\
    \ Node {\n    // 1\u756A\u76EE\u30011\u756A\u76EE\u306E\u8981\u7D20\u6570\u3001\
    2\u756A\u76EE\u3001\u5408\u8A08\n    long long max1, max1_num, max2, min1, min1_num,\
    \ min2, sum;\n    Node(long long x = 0) : max1(x), max1_num(1), max2(-inf), min1(x),\
    \ min1_num(1), min2(inf), sum(x) {}\n};\nstd::ostream& operator<<(std::ostream&\
    \ os, const Node& x) { return os << x.sum; }\nstruct Clamp {\n    // clamp(x +\
    \ add, lb, ub)\n    long long lb, ub, add;\n};\nstruct ChminChmaxAddSum {\n  \
    \  using S = Node;\n    using F = Clamp;\n    S op(const S& l, const S& r) const\
    \ {\n        S res;\n        res.max1 = std::max(l.max1, r.max1);\n        if\
    \ (l.max1 == r.max1) {\n            res.max1_num = l.max1_num + r.max1_num;\n\
    \            res.max2 = std::max(l.max2, r.max2);\n        } else if (l.max1 >\
    \ r.max1) {\n            res.max1_num = l.max1_num;\n            res.max2 = std::max(l.max2,\
    \ r.max1);\n        } else {\n            res.max1_num = r.max1_num;\n       \
    \     res.max2 = std::max(l.max1, r.max2);\n        }\n        res.min1 = std::min(l.min1,\
    \ r.min1);\n        if (l.min1 == r.min1) {\n            res.min1_num = l.min1_num\
    \ + r.min1_num;\n            res.min2 = std::min(l.min2, r.min2);\n        } else\
    \ if (l.min1 < r.min1) {\n            res.min1_num = l.min1_num;\n           \
    \ res.min2 = std::min(l.min2, r.min1);\n        } else {\n            res.min1_num\
    \ = r.min1_num;\n            res.min2 = std::min(l.min1, r.min2);\n        }\n\
    \        res.sum = l.sum + r.sum;\n        return res;\n    }\n    S e() const\
    \ {\n        S res;\n        res.max1 = -inf;\n        res.max1_num = 0;\n   \
    \     res.max2 = -inf;\n        res.min1 = inf;\n        res.min1_num = 0;\n \
    \       res.min2 = inf;\n        res.sum = 0;\n        return res;\n    }\n  \
    \  std::pair<bool, S> mapping(const F& f, const S& x, int sz) const {\n      \
    \  S res = x;\n        res.max1 += f.add;\n        res.max2 += f.add;\n      \
    \  res.min1 += f.add;\n        res.min2 += f.add;\n        res.sum += f.add *\
    \ sz;\n        if (res.max1 == res.min1) {\n            long long x = std::clamp(res.max1,\
    \ f.lb, f.ub);\n            res.max1 = x;\n            res.max2 = -inf;\n    \
    \        res.min1 = x;\n            res.min2 = inf;\n            res.sum = x *\
    \ sz;\n            return {false, res};\n        }\n        if (res.max1 == res.min2)\
    \ {\n            long long xr = std::clamp(res.max1, f.lb, f.ub);\n          \
    \  long long xl = std::clamp(res.min1, f.lb, f.ub);\n            if (xr == xl)\
    \ {\n                res.max1 = xr;\n                res.max1_num = sz;\n    \
    \            res.max2 = -inf;\n                res.min1 = xr;\n              \
    \  res.min1_num = sz;\n                res.min2 = inf;\n                res.sum\
    \ = xr * sz;\n                return {false, res};\n            }\n          \
    \  res.max1 = xr;\n            res.max2 = xl;\n            res.min1 = xl;\n  \
    \          res.min2 = xr;\n            res.sum = xr * res.max1_num + xl * res.min1_num;\n\
    \            return {false, res};\n        }\n        if (f.ub <= res.max2) return\
    \ {true, res};\n        if (f.lb >= res.min2) return {true, res};\n        if\
    \ (f.ub < res.max1) {\n            res.sum -= (res.max1 - f.ub) * res.max1_num;\n\
    \            res.max1 = f.ub;\n        }\n        if (f.lb > res.min1) {\n   \
    \         res.sum += (f.lb - res.min1) * res.min1_num;\n            res.min1 =\
    \ f.lb;\n        }\n        return {false, res};\n    }\n    F composition(const\
    \ F& f, const F& g) const {\n        F res;\n        res.lb = std::clamp(g.lb\
    \ + f.add, f.lb, f.ub);\n        res.ub = std::clamp(g.ub + f.add, f.lb, f.ub);\n\
    \        res.add = f.add + g.add;\n        return res;\n    }\n    F id() const\
    \ {\n        F res;\n        res.lb = -inf;\n        res.ub = inf;\n        res.add\
    \ = 0;\n        return res;\n    }\n};\n\nbool ok = true;\nvoid check(bool cond,\
    \ const char* what) {\n    if (!cond && ok) std::cerr << \"failed: \" << what\
    \ << std::endl;\n    if (!cond) ok = false;\n}\n\nlong long clamp_apply(const\
    \ Clamp& f, long long x) { return std::clamp(x + f.add, f.lb, f.ub); }\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n    auto small = [&] { return (long\
    \ long)(rng() % 41) - 20; };\n    auto gen_f = [&]() -> Clamp {\n        long\
    \ long b = small();\n        switch (rng() % 3) {\n            case 0:\n     \
    \           return Clamp{-inf, b, 0};  // chmin\n            case 1:\n       \
    \         return Clamp{b, inf, 0};  // chmax\n            default:\n         \
    \       return Clamp{-inf, inf, b};  // add\n        }\n    };\n    for (int rep\
    \ = 0; rep < 300 && ok; rep++) {\n        int n = rng() % 24 + 1;\n        std::vector<long\
    \ long> a(n);\n        for (auto& x : a) x = small();\n        std::vector<Node>\
    \ init(a.begin(), a.end());\n        SegTreeBeats<ChminChmaxAddSum> seg(init);\n\
    \        check(seg.size() == n, \"size\");\n        for (int q = 0; q < 80 &&\
    \ ok; q++) {\n            int t = rng() % 8;\n            int l = rng() % (n +\
    \ 1), r = rng() % (n + 1);\n            if (l > r) std::swap(l, r);\n        \
    \    int k = rng() % n;\n            if (t == 0) {\n                Clamp f =\
    \ gen_f();\n                seg.apply(l, r, f);\n                for (int i =\
    \ l; i < r; i++) a[i] = clamp_apply(f, a[i]);\n            } else if (t == 1)\
    \ {\n                Clamp f = gen_f();\n                seg.apply(k, f);\n  \
    \              a[k] = clamp_apply(f, a[k]);\n            } else if (t == 2) {\n\
    \                long long x = small();\n                if (rng() % 2)\n    \
    \                seg.set(k, Node(x));\n                else\n                \
    \    seg[k] = Node(x);\n                a[k] = x;\n            } else if (t ==\
    \ 3) {\n                check(seg.get(k).sum == a[k], \"get\");\n            \
    \    Node x = seg[k];\n                check(x.sum == a[k] && x.max1 == a[k] &&\
    \ x.min1 == a[k], \"seg[k]\");\n            } else if (t == 4) {\n           \
    \     Node p = seg.prod(l, r);\n                long long sum = 0, mx = -inf,\
    \ mn = inf;\n                for (int i = l; i < r; i++) sum += a[i], mx = std::max(mx,\
    \ a[i]), mn = std::min(mn, a[i]);\n                check(p.sum == sum && p.max1\
    \ == mx && p.min1 == mn, \"prod\");\n            } else if (t == 5) {\n      \
    \          // \u6700\u5927\u5024\u304C x \u4EE5\u4E0B\u3067\u3042\u308B\u6700\u9577\
    \u306E\u533A\u9593 [l, r)\n                long long x = small();\n          \
    \      int expect = l;\n                while (expect < n && a[expect] <= x) expect++;\n\
    \                check(seg.max_right(l, [&](const Node& s) { return s.max1 <=\
    \ x; }) == expect, \"max_right\");\n            } else if (t == 6) {\n       \
    \         // \u6700\u5C0F\u5024\u304C x \u4EE5\u4E0A\u3067\u3042\u308B\u6700\u9577\
    \u306E\u533A\u9593 [l, r)\n                long long x = small();\n          \
    \      int expect = r;\n                while (expect > 0 && a[expect - 1] >=\
    \ x) expect--;\n                check(seg.min_left(r, [&](const Node& s) { return\
    \ s.min1 >= x; }) == expect, \"min_left\");\n            } else {\n          \
    \      long long sum = 0;\n                for (long long x : a) sum += x;\n \
    \               check(seg.all_prod().sum == sum, \"all_prod\");\n            }\n\
    \        }\n        std::ostringstream os, expect;\n        os << seg;\n     \
    \   for (int i = 0; i < n; i++) {\n            if (i != 0) expect << ' ';\n  \
    \          expect << a[i];\n        }\n        check(os.str() == expect.str(),\
    \ \"os << seg\");\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/data_structures/segtree-beats.hpp
  - src/algebra/acted-monoid.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: true
  path: test/unittest/segtree-beats.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 07:27:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/segtree-beats.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/segtree-beats.test.cpp
- /verify/test/unittest/segtree-beats.test.cpp.html
title: test/unittest/segtree-beats.test.cpp
---
