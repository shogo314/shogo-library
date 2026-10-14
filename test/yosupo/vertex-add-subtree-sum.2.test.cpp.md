---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/group.hpp
    title: "\u7FA4\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/fenwick-tree.hpp
    title: Fenwick Tree (Binary Indexed Tree)
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/heavy-light-decomposition.hpp
    title: "HL \u5206\u89E3 (Heavy-Light Decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/vertex-add-subtree-sum.2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n// HL\
    \ \u5206\u89E3\u306E subtree \u3068 Fenwick Tree \u3067\u3001\u70B9\u52A0\u7B97\
    \u3068\u90E8\u5206\u6728\u306E\u548C\u3092\u6C42\u3081\u308B\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"src/algebra/group.hpp\"\n\n/**\n * @file group.hpp\n\
    \ * @brief \u7FA4\u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\
    \u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * -\
    \ S inv(const S& a): \u9006\u5143\n */\n\n#include <array>\n#include <cstddef>\n\
    #include <utility>\n\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n\
    \ * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\
    \u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\
    \u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S&\
    \ a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n\
    \ * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\
    \u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\
    \n#include <algorithm>\n#line 17 \"src/algebra/monoid.hpp\"\n#include <istream>\n\
    #include <limits>\n#include <numeric>\n#include <ostream>\n#include <type_traits>\n\
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
    \ T) -> Monoid<T, Op>;\n#line 16 \"src/algebra/group.hpp\"\n\nnamespace group\
    \ {\n\n/**\n * @brief \u52A0\u6CD5\u7FA4\n */\ntemplate <typename T>\nstruct Sum\
    \ : monoid::Sum<T> {\n    using S = T;\n    static constexpr S inv(const S& a)\
    \ { return -a; }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7FA4 (0\u3092\u542B\u307E\
    \u306A\u3044\u4F53\u306E\u5143\u306A\u3069)\n */\ntemplate <typename T>\nstruct\
    \ Prod : monoid::Prod<T> {\n    using S = T;\n    static constexpr S inv(const\
    \ S& a) { return S(1) / a; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\
    \u548C\n */\ntemplate <typename T>\nstruct Xor : monoid::Xor<T> {\n    using S\
    \ = T;\n    static constexpr S inv(const S& a) { return a; }\n};\n\n/**\n * @brief\
    \ {0, 1, ..., N-1} \u306E\u7F6E\u63DB (\u5168\u5358\u5C04) \u306E\u5408\u6210\n\
    \ *\n * monoid::Mapping<N> \u306B\u9006\u7F6E\u63DB\u3092\u52A0\u3048\u305F\u3082\
    \u306E\u3002\u8981\u7D20\u306F\u7F6E\u63DB\u3067\u3042\u308B\u3053\u3068\n * op(f,\
    \ g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n *\n * @tparam\
    \ N \u7F6E\u63DB\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\n */\ntemplate <std::size_t\
    \ N>\nstruct Permutation : monoid::Mapping<N> {\n    using S = std::array<int,\
    \ N>;\n    static constexpr S inv(const S& f) {\n        S h{};\n        for (std::size_t\
    \ x = 0; x < N; x++) h[f[x]] = static_cast<int>(x);\n        return h;\n    }\n\
    };\n\n}  // namespace group\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\u3068\u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\
    \u308B\u7FA4\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam\
    \ T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306E\u578B\n * @tparam Inv \u9006\u5143\u306E\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename\
    \ Op, typename Inv>\nstruct Group {\n    using S = T;\n    Op op_object;\n   \
    \ S identity;\n    Inv inv_object;\n    Group() = default;\n    constexpr Group(Op\
    \ op, const S& e, Inv inv) : op_object(std::move(op)), identity(e), inv_object(std::move(inv))\
    \ {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a, b);\
    \ }\n    constexpr S e() const { return identity; }\n    constexpr S inv(const\
    \ S& a) const { return inv_object(a); }\n};\ntemplate <typename Op, typename T,\
    \ typename Inv>\nGroup(Op, T, Inv) -> Group<T, Op, Inv>;\n#line 2 \"src/data_structures/fenwick-tree.hpp\"\
    \n\n/**\n * @file fenwick-tree.hpp\n * @brief Fenwick Tree (Binary Indexed Tree)\n\
    \ */\n\n#include <cassert>\n#line 11 \"src/data_structures/fenwick-tree.hpp\"\n\
    \n#line 13 \"src/data_structures/fenwick-tree.hpp\"\n\n/**\n * @brief Fenwick\
    \ Tree (Binary Indexed Tree)\n *\n * 1 \u70B9\u3078\u306E\u4F5C\u7528\u3068\u533A\
    \u9593\u7A4D\u3092 O(log n) \u3067\u884C\u3046\n * \u4F8B:\n * FenwickTree<group::Sum<long\
    \ long>> ft(n);\n * ft.apply(i, x);  // a[i] += x\n * ft.prod(l, r);   // a[l]\
    \ + ... + a[r-1]\n *\n * @tparam G \u53EF\u63DB\u306A\u7FA4 (algebra/group.hpp)\u3002\
    prefix_prod \u3068 max_right \u3060\u3051\u306A\u3089\u53EF\u63DB\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3082\u3088\u3044\n */\ntemplate <typename G>\nclass FenwickTree\
    \ {\n   public:\n    using S = typename G::S;\n\n   private:\n    G g;\n    int\
    \ n;\n    // data[i] \u306F a[i - (i & -i)] \u304B\u3089 a[i-1] \u307E\u3067\u306E\
    \u7A4D (1-indexed)\n    std::vector<S> data;\n    S op(const S& a, const S& b)\
    \ const { return g.op(a, b); }\n    S e() const { return g.e(); }\n    S inv(const\
    \ S& a) const { return g.inv(a); }\n\n   public:\n    /**\n     * @brief \u8981\
    \u7D20\u6570 n \u3067\u3001\u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u5358\u4F4D\
    \u5143\u306E Fenwick Tree \u3092\u4F5C\u308B\n     */\n    explicit FenwickTree(int\
    \ n = 0, G g = G()) : g(std::move(g)), n(n), data(n + 1, e()) {}\n    /**\n  \
    \   * @brief v \u3092\u521D\u671F\u5024\u3068\u3059\u308B Fenwick Tree \u3092\u4F5C\
    \u308B O(n)\n     */\n    explicit FenwickTree(const std::vector<S>& v, G g =\
    \ G()) : FenwickTree(v.size(), std::move(g)) {\n        for (int i = 1; i <= n;\
    \ i++) {\n            data[i] = op(data[i], v[i - 1]);\n            int j = i\
    \ + (i & -i);\n            if (j <= n) data[j] = op(data[j], data[i]);\n     \
    \   }\n    }\n\n    int size() const { return n; }\n\n    /**\n     * @brief a[k]\
    \ \u3092 op(a[k], x) \u306B\u3059\u308B O(log n)\n     */\n    void apply(int\
    \ k, const S& x) {\n        assert(0 <= k && k < n);\n        for (k++; k <= n;\
    \ k += k & -k) data[k] = op(data[k], x);\n    }\n    /**\n     * @brief a[0] \u304B\
    \u3089 a[r-1] \u307E\u3067\u306E\u7A4D O(log n)\n     */\n    S prefix_prod(int\
    \ r) const {\n        assert(0 <= r && r <= n);\n        S res = e();\n      \
    \  for (; r > 0; r -= r & -r) res = op(data[r], res);\n        return res;\n \
    \   }\n    /**\n     * @brief a[l] \u304B\u3089 a[r-1] \u307E\u3067\u306E\u7A4D\
    \ O(log n)\u3002\u9006\u5143\u3092\u4F7F\u3046\n     */\n    S prod(int l, int\
    \ r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return op(inv(prefix_prod(l)),\
    \ prefix_prod(r));\n    }\n    S all_prod() const { return prefix_prod(n); }\n\
    \    /**\n     * @brief a[k] O(log n)\u3002\u9006\u5143\u3092\u4F7F\u3046\n  \
    \   */\n    S get(int k) const {\n        assert(0 <= k && k < n);\n        return\
    \ prod(k, k + 1);\n    }\n    /**\n     * @brief a[k] \u3092 x \u306B\u3059\u308B\
    \ O(log n)\u3002\u9006\u5143\u3092\u4F7F\u3046\n     */\n    void set(int k, const\
    \ S& x) { apply(k, op(inv(get(k)), x)); }\n\n    /**\n     * @brief f(prefix_prod(r))\
    \ = true \u3068\u306A\u308B\u6700\u5927\u306E r \u3092\u8FD4\u3059 O(log n)\n\
    \     * f \u306F\u5358\u8ABF (\u3042\u308B r \u307E\u3067\u306F true \u3067\u305D\
    \u308C\u4EE5\u964D\u306F false) \u3067\u3042\u308B\u3053\u3068\u3002f(e()) = true\n\
    \     */\n    template <typename F>\n    int max_right(F f) const {\n        assert(f(e()));\n\
    \        int r = 0;\n        S sum = e();\n        int step = 1;\n        while\
    \ (step * 2 <= n) step *= 2;\n        for (; step > 0; step /= 2) {\n        \
    \    if (r + step <= n && f(op(sum, data[r + step]))) {\n                r +=\
    \ step;\n                sum = op(sum, data[r]);\n            }\n        }\n \
    \       return r;\n    }\n};\n\ntemplate <typename G>\nFenwickTree(int, G) ->\
    \ FenwickTree<G>;\ntemplate <typename G>\nFenwickTree(std::vector<typename G::S>,\
    \ G) -> FenwickTree<G>;\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file graph.hpp\n\
    \ * @brief \u30B0\u30E9\u30D5\n */\n\n#line 10 \"src/graph/graph.hpp\"\n#include\
    \ <deque>\n#include <functional>\n#line 14 \"src/graph/graph.hpp\"\n#include <queue>\n\
    #line 17 \"src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u6C4E\
    \u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\
    \u578B\n */\ntemplate <typename Cost = int>\nclass Graph {\n   public:\n    /**\n\
    \     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\n     *\n     * operator\
    \ int()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\u306E\u3067\u3001int\u578B\u306B\
    \u30AD\u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\u306Bdst\u306B\u306A\u308B\
    \n     * \u4F8B\u3048\u3070\u3001\n     * for (auto& e : g[v]) \u3092\u3059\u308B\
    \u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\u5217\u6319\u3055\u308C\u308B\
    \u304C\u3001\n     * for (int dst : g[v]) \u3068\u3059\u308B\u3068\u3001v\u304B\
    \u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\u304C\u5217\u6319\u3055\u308C\
    \u308B\n     */\n    struct Edge {\n        int src = -1;    //!< \u59CB\u70B9\
    \n        int dst = -1;    //!< \u7D42\u70B9\n        Cost cost = {};  //!< \u30B3\
    \u30B9\u30C8\n        int id = -1;     //!< \u8FBA\u306E\u756A\u53F7(\u8FFD\u52A0\
    \u3055\u308C\u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\u5834\u5408\u306Fid\u304C\
    \u540C\u3058\u3067\u65B9\u5411\u304C\u9006\u306E\u3082\u306E\u304C2\u3064\u5B58\
    \u5728\u3059\u308B)\n        Edge() = default;\n        Edge(int src, int dst,\
    \ Cost cost = 1, int id = -1) : src(src), dst(dst), cost(cost), id(id) {}\n  \
    \      operator int() const { return dst; }\n    };\n\n    /**\n     * @brief\
    \ \u6700\u77ED\u8DEF\u306E\u7D50\u679C\n     *\n     * auto [dist, prev] = g.shortest_path(s);\
    \ \u306E\u3088\u3046\u306B\u53D7\u3051\u53D6\u308C\u308B\n     */\n    struct\
    \ ShortestPath {\n        std::vector<Cost> dist;  //!< \u5404\u9802\u70B9\u3078\
    \u306E\u6700\u77ED\u8DEF\u9577\n        std::vector<Edge> prev;  //!< \u5404\u9802\
    \u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA (\u59CB\
    \u70B9\u3068\u672A\u5230\u9054\u306E\u9802\u70B9\u3067\u306F src == -1)\n    \
    \    /**\n         * @brief \u59CB\u70B9\u304B\u3089 t \u3078\u306E\u6700\u77ED\
    \u8DEF\u3092\u69CB\u6210\u3059\u308B\u8FBA\u306E\u30EA\u30B9\u30C8 (\u59CB\u70B9\
    \u5074\u304B\u3089\u9806\u306B)\n         * @note t \u304C\u59CB\u70B9\u304B\u672A\
    \u5230\u9054\u306E\u9802\u70B9\u306A\u3089\u7A7A\u3002\u8CA0\u9589\u8DEF\u306E\
    \u5F71\u97FF\u3092\u53D7\u3051\u308B\u9802\u70B9\u3067\u306F\u6700\u77ED\u8DEF\
    \u304C\u5B9A\u307E\u3089\u306A\u3044 (assert \u3067\u843D\u3061\u308B)\n     \
    \    */\n        std::vector<Edge> path(int t) const {\n            std::vector<Edge>\
    \ res;\n            while (prev[t].src != -1) {\n                res.push_back(prev[t]);\n\
    \                assert(res.size() < prev.size() && \"path: negative cycle\");\n\
    \                t = prev[t].src;\n            }\n            std::reverse(res.begin(),\
    \ res.end());\n            return res;\n        }\n    };\n\n    int n;      \
    \                       //!< \u9802\u70B9\u6570\n    int m;                  \
    \           //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>> g;  //!< \u30B0\
    \u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\n    /**\n    \
    \ * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     */\n    Graph() : n(0), m(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\u6570\n     */\n\
    \    explicit Graph(int n) : n(n), m(0), g(n) {}\n    /**\n     * @brief \u7121\
    \u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\n   \
    \  * @param v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\
    \u305F\u30891\n     */\n    void add_edge(int u, int v, Cost w = 1) {\n      \
    \  assert(0 <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u, v,\
    \ w, m});\n        g[v].push_back({v, u, w, m++});\n    }\n    /**\n     * @brief\
    \ \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\
    \n     * @param v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\
    \u3057\u305F\u30891\n     */\n    void add_directed_edge(int u, int v, Cost w\
    \ = 1) {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u,\
    \ v, w, m++});\n    }\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\
    \u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\
    \u308B\n     * @param m \u8FBA\u306E\u6570\n     * @param padding \u9802\u70B9\
    \u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\
    \u304B \u7701\u7565\u3057\u305F\u3089-1\n     * @param weighted \u8FBA\u306E\u91CD\
    \u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B \u7701\u7565\u3057\u305F\u3089\
    false\u3068\u306A\u308A\u3001\u91CD\u307F1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\
    \u308C\u308B\n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\
    \u3046\u304B \u7701\u7565\u3057\u305F\u3089false\n     */\n    void read(int m,\
    \ int padding = -1, bool weighted = false, bool directed = false) {\n        for\
    \ (int i = 0; i < m; i++) {\n            int u, v;\n            std::cin >> u\
    \ >> v;\n            u += padding, v += padding;\n            Cost c(1);\n   \
    \         if (weighted)\n                std::cin >> c;\n            if (directed)\n\
    \                add_directed_edge(u, v, c);\n            else\n             \
    \   add_edge(u, v, c);\n        }\n    }\n    /**\n     * @brief \u3042\u308B\u9802\
    \u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\u6319\u3059\u308B\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return std::vector<Edge>& v\u304B\u3089\u51FA\
    \u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<Edge>& operator[](int\
    \ v) {\n        return g[v];\n    }\n    /**\n     * @brief \u3042\u308B\u9802\
    \u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\u6319\u3059\u308B\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return const std::vector<Edge>& v\u304B\u3089\
    \u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<Edge>&\
    \ operator[](int v) const {\n        return g[v];\n    }\n    /**\n     * @brief\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\
    \u30EA\u30B9\u30C8(id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\
    \u4EE3\u8868\u3057\u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\n  \
    \   */\n    std::vector<Edge> edges() const {\n        std::vector<Edge> res(m);\n\
    \        for (int i = 0; i < n; i++) {\n            for (auto& e : g[i]) {\n \
    \               res[e.id] = e;\n            }\n        }\n        return res;\n\
    \    }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\
    \u70B9\u3078\u306E\u6700\u77ED\u8DEF\n     *\n     * @param s \u59CB\u70B9\n \
    \    * @param weighted 1\u4EE5\u5916\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\
    \u5B58\u5728\u3059\u308B\u304B \u7701\u7565\u3059\u308B\u3068true\n     * @param\
    \ inf \u30B3\u30B9\u30C8\u306Emin\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\
    \u9802\u70B9\u3078\u306E\u8DDD\u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\
    \u308B\u3068 std::numeric_limits<Cost>::max() / 4\n     * @return ShortestPath\
    \ \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA\
    \ (prev)\n     */\n    ShortestPath shortest_path(int s, bool weighted = true,\
    \ Cost inf = std::numeric_limits<Cost>::max() / 4) const {\n        assert(0 <=\
    \ s && s < n);\n        if (weighted)\n            return shortest_path_dijkstra(s,\
    \ inf);\n        return shortest_path_bfs(s, inf);\n    }\n    /**\n     * @brief\
    \ \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\n     *\n     * @param s \u59CB\u70B9\n     * @param inf \u30B3\u30B9\u30C8\
    \u306Emin\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\
    \u8DDD\u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4 \u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u70B9\u306F\
    \ -inf\n     * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u4E0A\u306E\u76F4\u524D\u306E\u8FBA (prev)\n     */\n    ShortestPath bellman_ford(int\
    \ s, Cost inf = std::numeric_limits<Cost>::max() / 4) const {\n        assert(0\
    \ <= s && s < n);\n        std::vector<Cost> dist(n, inf);\n        std::vector<Edge>\
    \ prev(n);\n        dist[s] = Cost{};\n\n        for (int i = 1; i < n; i++) {\n\
    \            bool changed = false;\n            for (int j = 0; j < n; j++)\n\
    \                for (const auto& e : g[j]) {\n                    if (dist[e.src]\
    \ == inf)\n                        continue;\n                    if (dist[e.dst]\
    \ > dist[e.src] + e.cost) {\n                        dist[e.dst] = dist[e.src]\
    \ + e.cost;\n                        if (dist[e.dst] < -inf)\n               \
    \             dist[e.dst] = -inf;\n                        prev[e.dst] = e;\n\
    \                        changed = true;\n                    }\n            \
    \    }\n            if (!changed)\n                break;\n        }\n       \
    \ for (int i = 0; i < n; i++) {\n            bool changed = false;\n         \
    \   for (int j = 0; j < n; j++)\n                for (const auto& e : g[j]) {\n\
    \                    if (dist[e.src] == inf)\n                        continue;\n\
    \                    if (dist[e.dst] > dist[e.src] + e.cost) {\n             \
    \           dist[e.dst] = -inf;\n                        prev[e.dst] = e;\n  \
    \                      changed = true;\n                    }\n              \
    \  }\n            if (!changed)\n                break;\n        }\n        return\
    \ {dist, prev};\n    }\n    /**\n     * @brief \u8FBA\u306E\u30B3\u30B9\u30C8\u304C\
    \ 0 \u304B 1 \u3060\u3051\u306E\u30B0\u30E9\u30D5\u3067\u3001\u3042\u308B\u9802\
    \u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF (01-BFS) O(n\
    \ + m)\n     *\n     * @param s \u59CB\u70B9\n     * @param inf \u672A\u5230\u9054\
    \u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2 \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4\n     * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\
    \u306E\u76F4\u524D\u306E\u8FBA (prev)\n     */\n    ShortestPath shortest_path_01bfs(int\
    \ s, Cost inf = std::numeric_limits<Cost>::max() / 4) const {\n        assert(0\
    \ <= s && s < n);\n        std::vector<Cost> dist(n, inf);\n        std::vector<Edge>\
    \ prev(n);\n        std::deque<int> que;\n        dist[s] = 0;\n        que.push_back(s);\n\
    \        while (!que.empty()) {\n            int u = que.front();\n          \
    \  que.pop_front();\n            for (auto& e : g[u]) {\n                assert(e.cost\
    \ == 0 || e.cost == 1);\n                if (dist[e.dst] == inf || dist[e.dst]\
    \ > dist[u] + e.cost) {\n                    dist[e.dst] = dist[u] + e.cost;\n\
    \                    prev[e.dst] = e;\n                    if (e.cost == 0)\n\
    \                        que.push_front(e.dst);\n                    else\n  \
    \                      que.push_back(e.dst);\n                }\n            }\n\
    \        }\n        return {dist, prev};\n    }\n    /**\n     * @brief \u5168\
    \u70B9\u5BFE\u9593\u306E\u6700\u77ED\u8DEF\u9577 (Floyd-Warshall) O(n^3)\n   \
    \  *\n     * @param inf \u672A\u5230\u9054\u3092\u8868\u3059\u5024 \u7701\u7565\
    \u3059\u308B\u3068 std::numeric_limits<Cost>::max() / 4\n     * @return std::vector<std::vector<Cost>>\
    \ dist[i][j] \u304C i \u304B\u3089 j \u3078\u306E\u6700\u77ED\u8DEF\u9577 (\u5230\
    \u9054\u3067\u304D\u306A\u3051\u308C\u3070 inf)\n     * @note \u8CA0\u306E\u8FBA\
    \u304C\u3042\u3063\u3066\u3082\u3088\u3044\u3002dist[i][i] < 0 \u3068\u306A\u308B\
    \ i \u304C\u3042\u308C\u3070\u8CA0\u9589\u8DEF\u304C\u3042\u308B\n     */\n  \
    \  std::vector<std::vector<Cost>> floyd_warshall(Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) const {\n        std::vector<std::vector<Cost>> dist(n, std::vector<Cost>(n,\
    \ inf));\n        for (int i = 0; i < n; i++) dist[i][i] = Cost{};\n        for\
    \ (int i = 0; i < n; i++) {\n            for (auto& e : g[i]) dist[i][e.dst] =\
    \ std::min(dist[i][e.dst], e.cost);\n        }\n        for (int k = 0; k < n;\
    \ k++) {\n            for (int i = 0; i < n; i++) {\n                if (dist[i][k]\
    \ == inf) continue;\n                for (int j = 0; j < n; j++) {\n         \
    \           if (dist[k][j] == inf) continue;\n                    dist[i][j] =\
    \ std::min(dist[i][j], dist[i][k] + dist[k][j]);\n                }\n        \
    \    }\n        }\n        return dist;\n    }\n\n   private:\n    ShortestPath\
    \ shortest_path_bfs(int s, Cost inf) const {\n        std::vector<Cost> dist(n,\
    \ inf);\n        std::vector<Edge> prev(n);\n        std::queue<int> que;\n  \
    \      dist[s] = 0;\n        que.push(s);\n        while (!que.empty()) {\n  \
    \          int u = que.front();\n            que.pop();\n            for (auto&\
    \ e : g[u]) {\n                if (dist[e.dst] == inf) {\n                   \
    \ dist[e.dst] = dist[e.src] + 1;\n                    prev[e.dst] = e;\n     \
    \               que.push(e.dst);\n                }\n            }\n        }\n\
    \        return {dist, prev};\n    }\n    ShortestPath shortest_path_dijkstra(int\
    \ s, Cost inf) const {\n        std::vector<Cost> dist(n, inf);\n        std::vector<Edge>\
    \ prev(n);\n        using Node = std::pair<Cost, int>;\n        std::priority_queue<Node,\
    \ std::vector<Node>, std::greater<Node>> que;\n        dist[s] = 0;\n        que.push({0,\
    \ s});\n        while (!que.empty()) {\n            auto [d, u] = que.top();\n\
    \            que.pop();\n            if (d > dist[u])\n                continue;\n\
    \            for (auto& e : g[u]) {\n                if (dist[e.dst] == inf ||\
    \ dist[e.dst] > dist[e.src] + e.cost) {\n                    dist[e.dst] = dist[e.src]\
    \ + e.cost;\n                    prev[e.dst] = e;\n                    que.push({dist[e.dst],\
    \ e.dst});\n                }\n            }\n        }\n        return {dist,\
    \ prev};\n    }\n};\n#line 2 \"src/graph/heavy-light-decomposition.hpp\"\n\n/**\n\
    \ * @file heavy-light-decomposition.hpp\n * @brief HL \u5206\u89E3 (Heavy-Light\
    \ Decomposition)\n */\n\n#line 12 \"src/graph/heavy-light-decomposition.hpp\"\n\
    \n/**\n * @brief HL \u5206\u89E3 (Heavy-Light Decomposition)\n *\n * \u6728\u306E\
    \u9802\u70B9\u3092\u3001\u3069\u306E\u30D1\u30B9\u3082 O(log n) \u500B\u306E\u533A\
    \u9593\u306B\u5206\u304B\u308C\u3001\u3069\u306E\u90E8\u5206\u6728\u3082 1 \u3064\
    \u306E\u533A\u9593\u306B\u306A\u308B\u3088\u3046\u306B\u4E26\u3079\u66FF\u3048\
    \u308B\n * \u9802\u70B9 v \u306F\u5217\u306E index(v) \u756A\u76EE\u306B\u5BFE\
    \u5FDC\u3059\u308B\u3002\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u3068\
    \u7D44\u307F\u5408\u308F\u305B\u3066\u3001\u30D1\u30B9\u3084\u90E8\u5206\u6728\
    \u3078\u306E\u30AF\u30A8\u30EA\u3092\u884C\u3046\n * \u524D\u8A08\u7B97 O(n)\u3002\
    DFS \u306F\u518D\u5E30\u3092\u4F7F\u308F\u306A\u3044\n * \u4F8B:\n * HeavyLightDecomposition\
    \ hld(g, root);\n * for (auto [a, b] : hld.path(u, v)) sum += seg.prod(std::min(a,\
    \ b), std::max(a, b) + 1);\n * auto [l, r] = hld.subtree(v);  // \u90E8\u5206\u6728\
    \u306F\u533A\u9593 [l, r)\n */\nclass HeavyLightDecomposition {\n    int n, root;\n\
    \    std::vector<int> par, dep, sz, heavy, head, in, order;\n\n   public:\n  \
    \  /**\n     * @brief \u6728 tree \u3092\u6839 root \u3067 HL \u5206\u89E3\u3059\
    \u308B\n     * @param tree Graph\u3001Tree\u3001RootedTree \u306A\u3069\u3002\
    tree.n \u304C\u9802\u70B9\u6570\u3001for (int u : tree[v]) \u3067 v \u306B\u96A3\
    \u63A5\u3059\u308B\u9802\u70B9\u3092\u5217\u6319\u3067\u304D\u308B\u3053\u3068\
    \n     */\n    template <typename G>\n    explicit HeavyLightDecomposition(const\
    \ G& tree, int root = 0)\n        : n(tree.n), root(root), par(n, -1), dep(n,\
    \ 0), sz(n, 1), heavy(n, -1), head(n), in(n), order(n) {\n        assert(0 <=\
    \ root && root < n);\n        // \u6839\u304B\u3089\u306E BFS \u9806\u3067\u89AA\
    \u3068\u6DF1\u3055\u3092\u6C7A\u3081\u308B\n        std::vector<int> bfs = {root};\n\
    \        bfs.reserve(n);\n        for (int i = 0; i < (int)bfs.size(); i++) {\n\
    \            int v = bfs[i];\n            for (int u : tree[v]) {\n          \
    \      if (u == par[v]) continue;\n                assert(u != root && par[u]\
    \ == -1 && \"HeavyLightDecomposition: not a tree\");\n                par[u] =\
    \ v;\n                dep[u] = dep[v] + 1;\n                bfs.push_back(u);\n\
    \            }\n        }\n        assert((int)bfs.size() == n && \"HeavyLightDecomposition:\
    \ not connected\");\n        // \u8449\u306E\u5074\u304B\u3089\u90E8\u5206\u6728\
    \u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u3001\u6700\u3082\u5927\u304D\u3044\
    \u5B50\u3092 heavy \u306B\u3059\u308B\n        for (int i = n - 1; i > 0; i--)\
    \ {\n            int v = bfs[i], p = par[v];\n            sz[p] += sz[v];\n  \
    \          if (heavy[p] == -1 || sz[v] > sz[heavy[p]]) heavy[p] = v;\n       \
    \ }\n        // heavy \u306A\u5B50\u3092\u6700\u5F8C\u306B\u7A4D\u3080\u3068\u3001\
    \u6B21\u306B\u53D6\u308A\u51FA\u3055\u308C\u3066 index \u304C\u9023\u7D9A\u3059\
    \u308B\n        std::vector<int> st = {root};\n        head[root] = root;\n  \
    \      int k = 0;\n        while (!st.empty()) {\n            int v = st.back();\n\
    \            st.pop_back();\n            in[v] = k;\n            order[k++] =\
    \ v;\n            for (int u : tree[v]) {\n                if (u == par[v] ||\
    \ u == heavy[v]) continue;\n                head[u] = u;\n                st.push_back(u);\n\
    \            }\n            if (heavy[v] != -1) {\n                head[heavy[v]]\
    \ = head[v];\n                st.push_back(heavy[v]);\n            }\n       \
    \ }\n    }\n\n    int size() const { return n; }\n    /**\n     * @brief \u9802\
    \u70B9 v \u306E\u5217\u3067\u306E\u4F4D\u7F6E\n     */\n    int index(int v) const\
    \ { return in[v]; }\n    /**\n     * @brief \u5217\u306E i \u756A\u76EE\u306E\u9802\
    \u70B9 (index \u306E\u9006)\n     */\n    int vertex(int i) const { return order[i];\
    \ }\n    /**\n     * @brief v \u306E\u89AA (\u6839\u306A\u3089 -1)\n     */\n\
    \    int parent(int v) const { return par[v]; }\n    /**\n     * @brief v \u306E\
    \u6DF1\u3055 (\u6839\u306F 0\u3001\u8FBA\u306E\u672C\u6570)\n     */\n    int\
    \ depth(int v) const { return dep[v]; }\n    /**\n     * @brief v \u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306E\u500B\u6570\n   \
    \  */\n    int subtree_size(int v) const { return sz[v]; }\n    /**\n     * @brief\
    \ v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306B\u5BFE\
    \u5FDC\u3059\u308B\u533A\u9593 [l, r)\n     */\n    std::pair<int, int> subtree(int\
    \ v) const { return {in[v], in[v] + sz[v]}; }\n\n    /**\n     * @brief u \u3068\
    \ v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148 O(log n)\n     */\n    int lca(int\
    \ u, int v) const {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n   \
    \     while (head[u] != head[v]) {\n            if (dep[head[u]] < dep[head[v]])\
    \ std::swap(u, v);\n            u = par[head[u]];\n        }\n        return dep[u]\
    \ < dep[v] ? u : v;\n    }\n    /**\n     * @brief u \u3068 v \u306E\u9593\u306E\
    \u8FBA\u306E\u672C\u6570 O(log n)\n     */\n    int dist(int u, int v) const {\
    \ return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }\n    /**\n     * @brief v \u304B\
    \u3089\u6839\u306E\u65B9\u3078 k \u672C\u306E\u8FBA\u3092\u9032\u3093\u3060\u9802\
    \u70B9 (k > depth(v) \u306A\u3089 -1) O(log n)\n     */\n    int hop(int v, int\
    \ k) const {\n        assert(0 <= v && v < n && k >= 0);\n        if (k > dep[v])\
    \ return -1;\n        while (true) {\n            int h = head[v];\n         \
    \   if (in[v] - in[h] >= k) return order[in[v] - k];\n            k -= in[v] -\
    \ in[h] + 1;\n            v = par[h];\n        }\n    }\n    /**\n     * @brief\
    \ u \u304B\u3089 v \u3078\u306E\u30D1\u30B9\u3067\u3001u \u304B\u3089 k \u672C\
    \u306E\u8FBA\u3092\u9032\u3093\u3060\u9802\u70B9 (k > dist(u, v) \u306A\u3089\
    \ -1) O(log n)\n     */\n    int jump(int u, int v, int k) const {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n && k >= 0);\n        int w = lca(u, v);\n \
    \       int du = dep[u] - dep[w], dv = dep[v] - dep[w];\n        if (k <= du)\
    \ return hop(u, k);\n        if (k <= du + dv) return hop(v, du + dv - k);\n \
    \       return -1;\n    }\n\n    /**\n     * @brief u \u304B\u3089 v \u3078\u306E\
    \u30D1\u30B9\u3092\u3001\u5217\u306E\u533A\u9593\u306B\u5206\u3051\u3066 u \u5074\
    \u304B\u3089\u9806\u306B\u4E26\u3079\u308B O(log n)\n     *\n     * \u5404\u8981\
    \u7D20 (a, b) \u306F\u3001\u5217\u306E a \u756A\u76EE\u304B\u3089 b \u756A\u76EE\
    \u307E\u3067 (\u4E21\u7AEF\u3092\u542B\u3080) \u3092\u3001a \u304B\u3089 b \u306E\
    \u5411\u304D\u306B\u305F\u3069\u308B\u3053\u3068\u3092\u8868\u3059\n     * \u5411\
    \u304D\u3092\u8868\u3059\u305F\u3081\u3001\u3053\u306E\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u306E\u4ED6\u306E\u533A\u9593 (\u534A\u958B\u533A\u9593 [l, r)) \u3068\u9055\
    \u3063\u3066\u9589\u533A\u9593\u306B\u306A\u3063\u3066\u3044\u308B\n     * a >\
    \ b \u306A\u3089 index \u304C\u6E1B\u308B\u5411\u304D (\u6839\u306B\u8FD1\u3065\
    \u304F\u5411\u304D) \u306B\u305F\u3069\u308B\n     * \u4EA4\u63DB\u6CD5\u5247\u304C\
    \u6210\u308A\u7ACB\u305F\u306A\u3044\u6F14\u7B97\u3067\u306F\u3001a > b \u306E\
    \u533A\u9593\u306F\u9006\u9806\u306E\u7A4D\u3092\u4F7F\u3046\n     * @param edge\
    \ true \u306A\u3089\u8FBA\u306B\u3064\u3044\u3066\u306E\u30D1\u30B9\u306B\u3059\
    \u308B\u3002\u8FBA (parent(v), v) \u3092 index(v) \u756A\u76EE\u306B\u5BFE\u5FDC\
    \u3055\u305B\u3001lca \u306E\u4F4D\u7F6E\u3092\u542B\u3081\u306A\u3044\n     */\n\
    \    std::vector<std::pair<int, int>> path(int u, int v, bool edge = false) const\
    \ {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n        std::vector<std::pair<int,\
    \ int>> up, down;\n        while (head[u] != head[v]) {\n            if (dep[head[u]]\
    \ >= dep[head[v]]) {\n                up.emplace_back(in[u], in[head[u]]);\n \
    \               u = par[head[u]];\n            } else {\n                down.emplace_back(in[head[v]],\
    \ in[v]);\n                v = par[head[v]];\n            }\n        }\n     \
    \   if (dep[u] >= dep[v]) {\n            // v \u304C lca\n            int l =\
    \ in[v] + edge;\n            if (l <= in[u]) up.emplace_back(in[u], l);\n    \
    \    } else {\n            // u \u304C lca\n            int l = in[u] + edge;\n\
    \            if (l <= in[v]) down.emplace_back(l, in[v]);\n        }\n       \
    \ up.insert(up.end(), down.rbegin(), down.rend());\n        return up;\n    }\n\
    };\n#line 12 \"test/yosupo/vertex-add-subtree-sum.2.test.cpp\"\n\nint main() {\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int n,\
    \ q;\n    std::cin >> n >> q;\n    std::vector<long long> a(n);\n    for (auto&\
    \ x : a) std::cin >> x;\n    Graph<int> g(n);\n    for (int i = 1; i < n; i++)\
    \ {\n        int p;\n        std::cin >> p;\n        g.add_edge(p, i);\n    }\n\
    \    HeavyLightDecomposition hld(g);\n    std::vector<long long> init(n);\n  \
    \  for (int v = 0; v < n; v++) init[hld.index(v)] = a[v];\n    FenwickTree<group::Sum<long\
    \ long>> ft(init);\n    while (q--) {\n        int t;\n        std::cin >> t;\n\
    \        if (t == 0) {\n            int u;\n            long long x;\n       \
    \     std::cin >> u >> x;\n            ft.apply(hld.index(u), x);\n        } else\
    \ {\n            int u;\n            std::cin >> u;\n            auto [l, r] =\
    \ hld.subtree(u);\n            std::cout << ft.prod(l, r) << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n// HL \u5206\u89E3\u306E subtree \u3068 Fenwick Tree \u3067\u3001\u70B9\u52A0\
    \u7B97\u3068\u90E8\u5206\u6728\u306E\u548C\u3092\u6C42\u3081\u308B\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../src/algebra/group.hpp\"\n\
    #include \"../../src/data_structures/fenwick-tree.hpp\"\n#include \"../../src/graph/graph.hpp\"\
    \n#include \"../../src/graph/heavy-light-decomposition.hpp\"\n\nint main() {\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int n,\
    \ q;\n    std::cin >> n >> q;\n    std::vector<long long> a(n);\n    for (auto&\
    \ x : a) std::cin >> x;\n    Graph<int> g(n);\n    for (int i = 1; i < n; i++)\
    \ {\n        int p;\n        std::cin >> p;\n        g.add_edge(p, i);\n    }\n\
    \    HeavyLightDecomposition hld(g);\n    std::vector<long long> init(n);\n  \
    \  for (int v = 0; v < n; v++) init[hld.index(v)] = a[v];\n    FenwickTree<group::Sum<long\
    \ long>> ft(init);\n    while (q--) {\n        int t;\n        std::cin >> t;\n\
    \        if (t == 0) {\n            int u;\n            long long x;\n       \
    \     std::cin >> u >> x;\n            ft.apply(hld.index(u), x);\n        } else\
    \ {\n            int u;\n            std::cin >> u;\n            auto [l, r] =\
    \ hld.subtree(u);\n            std::cout << ft.prod(l, r) << '\\n';\n        }\n\
    \    }\n}\n"
  dependsOn:
  - src/algebra/group.hpp
  - src/algebra/monoid.hpp
  - src/data_structures/fenwick-tree.hpp
  - src/graph/graph.hpp
  - src/graph/heavy-light-decomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex-add-subtree-sum.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex-add-subtree-sum.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex-add-subtree-sum.2.test.cpp
- /verify/test/yosupo/vertex-add-subtree-sum.2.test.cpp.html
title: test/yosupo/vertex-add-subtree-sum.2.test.cpp
---
