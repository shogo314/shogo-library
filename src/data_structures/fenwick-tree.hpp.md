---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/group.hpp
    title: "\u7FA4\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-2-b.2.test.cpp
    title: test/aoj/dsl-2-b.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-5-d.test.cpp
    title: test/aoj/grl-5-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/fenwick-tree.test.cpp
    title: test/unittest/fenwick-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point-add-range-sum.3.test.cpp
    title: test/yosupo/point-add-range-sum.3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex-add-path-sum.test.cpp
    title: test/yosupo/vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex-add-subtree-sum.2.test.cpp
    title: test/yosupo/vertex-add-subtree-sum.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Fenwick Tree (Binary Indexed Tree)
    links: []
  bundledCode: "#line 2 \"src/data_structures/fenwick-tree.hpp\"\n\n/**\n * @file\
    \ fenwick-tree.hpp\n * @brief Fenwick Tree (Binary Indexed Tree)\n */\n\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n#line 2 \"src/algebra/group.hpp\"\
    \n\n/**\n * @file group.hpp\n * @brief \u7FA4\u306E\u5B9A\u7FA9\n *\n * \u7FA4\
    \u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\
    \u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\
    \u3057\u3066\u8868\u3059\n * - S inv(const S& a): \u9006\u5143\n */\n\n#include\
    \ <array>\n#include <cstddef>\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file\
    \ monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\
    \u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\
    \u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S\
    \ op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\
    \u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044\
    \ (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059\
    )\n */\n\n#include <algorithm>\n#line 17 \"src/algebra/monoid.hpp\"\n#include\
    \ <istream>\n#include <limits>\n#include <numeric>\n#include <ostream>\n#include\
    \ <type_traits>\n#line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\
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
    \u5168\u5358\u5C04\u3067\u306A\u304F\u3066\u3088\u3044\n * op(f, g) = g\u2218\
    f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3059\u308B)\u3002\u533A\u9593 [l,\
    \ r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\n * \u4F8B: SegTree<monoid::Mapping<3>>\
    \ seg(n); seg.set(i, {0, 2, 1});\n * swap(i, j) \u3067 i \u3068 j \u3092\u5165\
    \u308C\u66FF\u3048\u308B\u5199\u50CF\u3092\u4F5C\u308C\u308B\n *\n * @tparam N\
    \ \u5199\u50CF\u306E\u5B9A\u7FA9\u57DF\u30FB\u5024\u57DF\u306E\u5927\u304D\u3055\
    \n */\ntemplate <std::size_t N>\nstruct Mapping {\n    using S = std::array<int,\
    \ N>;\n    static constexpr S op(const S& f, const S& g) {\n        S h{};\n \
    \       for (std::size_t x = 0; x < N; x++) h[x] = g[f[x]];\n        return h;\n\
    \    }\n    static constexpr S e() {\n        S h{};\n        for (std::size_t\
    \ x = 0; x < N; x++) h[x] = static_cast<int>(x);\n        return h;\n    }\n \
    \   // i \u3068 j \u3092\u5165\u308C\u66FF\u3048\u3001\u307B\u304B\u306F\u52D5\
    \u304B\u3055\u306A\u3044\u5199\u50CF (\u4E92\u63DB)\n    static constexpr S swap(int\
    \ i, int j) {\n        S h = e();\n        h[i] = j;\n        h[j] = i;\n    \
    \    return h;\n    }\n};\n\n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\
    \u5408\u6210\n * op(f, g) = g\u2218f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\
    \u3059\u308B)\n * \u533A\u9593 [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\
    \u8868\u3059\n */\ntemplate <typename T>\nstruct Composite {\n    using S = Affine<T>;\n\
    \    static constexpr S op(const S& f, const S& g) { return {g.a * f.a, g.a *\
    \ f.b + g.b}; }\n    static constexpr S e() { return {T(1), T(0)}; }\n};\n\n/**\n\
    \ * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis {\n    struct\
    \ S {\n        long long close; // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u306E\u500B\u6570\n        long long open;  // \u5BFE\u5FDC\u306E\u53D6\
    \u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\n        constexpr S(char\
    \ c = 0) : close(c == ')'), open(c == '(') {}\n        constexpr S(long long close,\
    \ long long open) : close(close), open(open) {}\n        /**\n         * @brief\
    \ \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n         */\n        constexpr bool\
    \ is_valid() const { return close == 0 && open == 0; }\n    };\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        if(a.open >= b.close) return S(a.close,\
    \ a.open - b.close + b.open);\n        return S(a.close + b.close - a.open, b.open);\n\
    \    }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\
    \u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\
    \u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate\
    \ <typename T, typename U = int>\nstruct MinWith {\n    using S = std::pair<T,\
    \ U>;\n    static constexpr S op(const S& a, const S& b) { return b.first < a.first\
    \ ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E\
    \ \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam\
    \ T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\
    \u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename T, typename U = int>\n\
    struct MaxWith {\n    using S = std::pair<T, U>;\n    static constexpr S op(const\
    \ S& a, const S& b) { return a.first < b.first ? b : a; }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U{}}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MinCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if(a.first < b.first) return\
    \ a;\n        if(b.first < a.first) return b;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MaxCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if(a.first < b.first) return b;\n        if(b.first < a.first) return\
    \ a;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U(0)}; }\n};\n\n} // namespace\
    \ monoid\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\
    \u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u30E2\u30CE\
    \u30A4\u30C9\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * \u4F8B\
    : SegTree seg(v, Monoid([](int a, int b) { return std::max(a, b); }, -1));\n *\n\
    \ * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename\
    \ Op>\nstruct Monoid {\n    using S = T;\n    Op op_object;\n    S identity;\n\
    \    Monoid() = default;\n    constexpr Monoid(Op op, const S& e) : op_object(std::move(op)),\
    \ identity(e) {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a,\
    \ b); }\n    constexpr S e() const { return identity; }\n};\ntemplate <typename\
    \ Op, typename T>\nMonoid(Op, T) -> Monoid<T, Op>;\n#line 15 \"src/algebra/group.hpp\"\
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
    \u3068\n * op(f, g) = g\u2218f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3059\
    \u308B)\n *\n * @tparam N \u7F6E\u63DB\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\
    \n */\ntemplate <std::size_t N>\nstruct Permutation : monoid::Mapping<N> {\n \
    \   using S = std::array<int, N>;\n    static constexpr S inv(const S& f) {\n\
    \        S h{};\n        for (std::size_t x = 0; x < N; x++) h[f[x]] = static_cast<int>(x);\n\
    \        return h;\n    }\n};\n\n} // namespace group\n\n/**\n * @brief \u95A2\
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
    \ Op, Inv>;\n#line 12 \"src/data_structures/fenwick-tree.hpp\"\n\n/**\n * @brief\
    \ Fenwick Tree (Binary Indexed Tree)\n *\n * 1 \u70B9\u3078\u306E\u4F5C\u7528\u3068\
    \u533A\u9593\u7A4D\u3092 O(log n) \u3067\u884C\u3046\n * \u4F8B:\n * FenwickTree<group::Sum<long\
    \ long>> ft(n);\n * ft.apply(i, x);  // a[i] += x\n * ft.prod(l, r);   // a[l]\
    \ + ... + a[r-1]\n *\n * @tparam G \u53EF\u63DB\u306A\u7FA4 (algebra/group.hpp)\u3002\
    prefix_prod \u3068 max_right \u3060\u3051\u306A\u3089\u53EF\u63DB\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3082\u3088\u3044\n */\ntemplate <typename G>\nclass FenwickTree\
    \ {\npublic:\n    using S = typename G::S;\n\nprivate:\n    G g;\n    int n;\n\
    \    // data[i] \u306F a[i - (i & -i)] \u304B\u3089 a[i-1] \u307E\u3067\u306E\u7A4D\
    \ (1-indexed)\n    std::vector<S> data;\n    S op(const S& a, const S& b) const\
    \ { return g.op(a, b); }\n    S e() const { return g.e(); }\n    S inv(const S&\
    \ a) const { return g.inv(a); }\n\npublic:\n    /**\n     * @brief \u8981\u7D20\
    \u6570 n \u3067\u3001\u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u5358\u4F4D\u5143\
    \u306E Fenwick Tree \u3092\u4F5C\u308B\n     */\n    explicit FenwickTree(int\
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
    \ G) -> FenwickTree<G>;\n"
  code: "#pragma once\n\n/**\n * @file fenwick-tree.hpp\n * @brief Fenwick Tree (Binary\
    \ Indexed Tree)\n */\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../algebra/group.hpp\"\n\n/**\n * @brief Fenwick Tree (Binary Indexed\
    \ Tree)\n *\n * 1 \u70B9\u3078\u306E\u4F5C\u7528\u3068\u533A\u9593\u7A4D\u3092\
    \ O(log n) \u3067\u884C\u3046\n * \u4F8B:\n * FenwickTree<group::Sum<long long>>\
    \ ft(n);\n * ft.apply(i, x);  // a[i] += x\n * ft.prod(l, r);   // a[l] + ...\
    \ + a[r-1]\n *\n * @tparam G \u53EF\u63DB\u306A\u7FA4 (algebra/group.hpp)\u3002\
    prefix_prod \u3068 max_right \u3060\u3051\u306A\u3089\u53EF\u63DB\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3082\u3088\u3044\n */\ntemplate <typename G>\nclass FenwickTree\
    \ {\npublic:\n    using S = typename G::S;\n\nprivate:\n    G g;\n    int n;\n\
    \    // data[i] \u306F a[i - (i & -i)] \u304B\u3089 a[i-1] \u307E\u3067\u306E\u7A4D\
    \ (1-indexed)\n    std::vector<S> data;\n    S op(const S& a, const S& b) const\
    \ { return g.op(a, b); }\n    S e() const { return g.e(); }\n    S inv(const S&\
    \ a) const { return g.inv(a); }\n\npublic:\n    /**\n     * @brief \u8981\u7D20\
    \u6570 n \u3067\u3001\u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u5358\u4F4D\u5143\
    \u306E Fenwick Tree \u3092\u4F5C\u308B\n     */\n    explicit FenwickTree(int\
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
    \ G) -> FenwickTree<G>;\n"
  dependsOn:
  - src/algebra/group.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/data_structures/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2026-10-13 20:17:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/fenwick-tree.test.cpp
  - test/aoj/grl-5-d.test.cpp
  - test/aoj/dsl-2-b.2.test.cpp
  - test/yosupo/point-add-range-sum.3.test.cpp
  - test/yosupo/vertex-add-path-sum.test.cpp
  - test/yosupo/vertex-add-subtree-sum.2.test.cpp
documentation_of: src/data_structures/fenwick-tree.hpp
layout: document
title: Fenwick Tree (Binary Indexed Tree)
---

1 点への作用と区間積を $O(\log n)$ で行うデータ構造です。[セグメント木](segtree.hpp) よりできることは少ないですが、コードが短く定数倍が軽いです。可換な [群](../algebra/group.hpp) を渡して使います。

```cpp
FenwickTree<group::Sum<long long>> ft(n);   // すべて 0
FenwickTree<group::Sum<long long>> ft2(a);  // a で初期化する (O(n))
ft.apply(i, x);                             // a[i] += x
long long s = ft.prod(l, r);                // a[l] + ... + a[r-1]
int k = ft.max_right([&](long long v) { return v <= w; });  // 先頭からの和が w 以下になる最大の長さ
```

## メンバ

| メンバ | 説明 |
|---|---|
| `FenwickTree(n)` | 要素数 `n` で、すべての要素が単位元 |
| `FenwickTree(v)` | `v` を初期値にする。$O(n)$ |
| `size()` | 要素数 |
| `apply(k, x)` | `a[k]` を `op(a[k], x)` にする。$O(\log n)$ |
| `prefix_prod(r)` | `a[0]` から `a[r-1]` までの積。$O(\log n)$ |
| `prod(l, r)` | `a[l]` から `a[r-1]` までの積。逆元を使う。$O(\log n)$ |
| `all_prod()` | すべての要素の積 |
| `get(k)` | `a[k]`。逆元を使う。$O(\log n)$ |
| `set(k, x)` | `a[k]` を `x` にする。逆元を使う。$O(\log n)$ |
| `max_right(f)` | `f(prefix_prod(r))` が真になる最大の `r`。`f` は単調で `f(e())` が真であること。$O(\log n)$ |

逆元を使わない `apply`・`prefix_prod`・`all_prod`・`max_right` だけなら、可換なモノイド (`monoid::Max<T>` など) でも使えます。

`max_right` は、要素が非負のときの「先頭から和が `w` 以下になる最大の長さ」や、個数を数える BIT での「`k` 番目に小さい値」に使えます。

ラムダ式から作った群も渡せます。

```cpp
FenwickTree ft(v, Group([](int a, int b) { return a ^ b; }, 0, [](int a) { return a; }));
```

## 関連

- 区間への作用や非可換な演算が必要なら [セグメント木](segtree.hpp)、[遅延伝搬セグメント木](lazy-segtree.hpp)
