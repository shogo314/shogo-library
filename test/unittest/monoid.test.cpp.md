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
    path: src/data_structures/potentialized-unionfind.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
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
  bundledCode: "#line 1 \"test/unittest/monoid.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// monoid.hpp / group.hpp \u306E\u30E2\u30CE\u30A4\u30C9\u30FB\u7FA4\u3068\
    \ SegTree \u306E\u7D30\u304B\u3044\u6A5F\u80FD\u3092\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#include <algorithm>\n#include <array>\n#include <cstddef>\n\
    #include <istream>\n#include <limits>\n#include <numeric>\n#include <ostream>\n\
    #include <type_traits>\n#include <utility>\n\n/**\n * @brief 1\u6B21\u95A2\u6570\
    \ f(x) = a * x + b\n *\n * monoid::Composite \u306E\u8981\u7D20\u3084 acted_monoid::AffineSum\
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
    \ T) -> Monoid<T, Op>;\n#line 7 \"test/unittest/monoid.test.cpp\"\n\n#include\
    \ <iostream>\n#include <random>\n#include <sstream>\n#include <string>\n#include\
    \ <vector>\n\n#line 2 \"src/algebra/group.hpp\"\n\n/**\n * @file group.hpp\n *\
    \ @brief \u7FA4\u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\
    \u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * -\
    \ S inv(const S& a): \u9006\u5143\n */\n\n#line 14 \"src/algebra/group.hpp\"\n\
    \n#line 16 \"src/algebra/group.hpp\"\n\nnamespace group {\n\n/**\n * @brief \u52A0\
    \u6CD5\u7FA4\n */\ntemplate <typename T>\nstruct Sum : monoid::Sum<T> {\n    using\
    \ S = T;\n    static constexpr S inv(const S& a) { return -a; }\n};\n\n/**\n *\
    \ @brief \u4E57\u6CD5\u7FA4 (0\u3092\u542B\u307E\u306A\u3044\u4F53\u306E\u5143\
    \u306A\u3069)\n */\ntemplate <typename T>\nstruct Prod : monoid::Prod<T> {\n \
    \   using S = T;\n    static constexpr S inv(const S& a) { return S(1) / a; }\n\
    };\n\n/**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate <typename\
    \ T>\nstruct Xor : monoid::Xor<T> {\n    using S = T;\n    static constexpr S\
    \ inv(const S& a) { return a; }\n};\n\n/**\n * @brief {0, 1, ..., N-1} \u306E\u7F6E\
    \u63DB (\u5168\u5358\u5C04) \u306E\u5408\u6210\n *\n * monoid::Mapping<N> \u306B\
    \u9006\u7F6E\u63DB\u3092\u52A0\u3048\u305F\u3082\u306E\u3002\u8981\u7D20\u306F\
    \u7F6E\u63DB\u3067\u3042\u308B\u3053\u3068\n * op(f, g) = f\u2218g (g \u3092\u5148\
    \u306B\u9069\u7528\u3059\u308B)\n *\n * @tparam N \u7F6E\u63DB\u3059\u308B\u8981\
    \u7D20\u306E\u500B\u6570\n */\ntemplate <std::size_t N>\nstruct Permutation :\
    \ monoid::Mapping<N> {\n    using S = std::array<int, N>;\n    static constexpr\
    \ S inv(const S& f) {\n        S h{};\n        for (std::size_t x = 0; x < N;\
    \ x++) h[f[x]] = static_cast<int>(x);\n        return h;\n    }\n};\n\n}  // namespace\
    \ group\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\
    \u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u7FA4\n * \u30E9\
    \u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u578B\n * @tparam Inv \u9006\u5143\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename Op, typename Inv>\n\
    struct Group {\n    using S = T;\n    Op op_object;\n    S identity;\n    Inv\
    \ inv_object;\n    Group() = default;\n    constexpr Group(Op op, const S& e,\
    \ Inv inv) : op_object(std::move(op)), identity(e), inv_object(std::move(inv))\
    \ {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a, b);\
    \ }\n    constexpr S e() const { return identity; }\n    constexpr S inv(const\
    \ S& a) const { return inv_object(a); }\n};\ntemplate <typename Op, typename T,\
    \ typename Inv>\nGroup(Op, T, Inv) -> Group<T, Op, Inv>;\n#line 2 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n\n/**\n * @file potentialized-unionfind.hpp\n * @brief \u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\u4ED8\u304DUnionFind\n */\n#include <cassert>\n#include <stack>\n\
    #line 11 \"src/data_structures/potentialized-unionfind.hpp\"\n\n#line 2 \"src/data_structures/unionfind.hpp\"\
    \n\n/**\n * @file unionfind.hpp\n * @brief UnionFind\n */\n\n#line 12 \"src/data_structures/unionfind.hpp\"\
    \n\nnamespace internal_unionfind {\n/**\n * @brief \u5404\u8981\u7D20\u306E\u4EE3\
    \u8868\u5143\u304B\u3089\u3001\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8981\
    \u7D20\u306E\u30EA\u30B9\u30C8\u3092\u4F5C\u308B\n * @param leader \u8981\u7D20\
    \ a \u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\u95A2\u6570\n */\ntemplate <typename\
    \ F>\nstd::vector<std::vector<int>> groups(int n, F leader) {\n    std::vector<int>\
    \ leader_buf(n), group_size(n);\n    for (int i = 0; i < n; i++) {\n        leader_buf[i]\
    \ = leader(i);\n        group_size[leader_buf[i]]++;\n    }\n    std::vector<std::vector<int>>\
    \ result(n);\n    for (int i = 0; i < n; i++) {\n        result[i].reserve(group_size[i]);\n\
    \    }\n    for (int i = 0; i < n; i++) {\n        result[leader_buf[i]].push_back(i);\n\
    \    }\n    result.erase(std::remove_if(result.begin(), result.end(), [&](const\
    \ std::vector<int>& v) { return v.empty(); }), result.end());\n    return result;\n\
    }\n}  // namespace internal_unionfind\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\
    \u30D5\u306B\u5BFE\u3057\u3066\u300C\u8FBA\u306E\u8FFD\u52A0\u300D\u3001\u300C\
    2\u9802\u70B9\u304C\u9023\u7D50\u304B\u306E\u5224\u5B9A\u300D\u3092\u3059\u308B\
    \n */\nclass UnionFind {\n   protected:\n    int _n;\n    // \u8CA0\u306A\u3089\
    \u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\u3089\u89AA\n    std::vector<int> parent_or_size;\n\
    \n   public:\n    /**\n     * @brief merge \u306E\u623B\u308A\u5024\n     *\n\
    \     * if (uf.merge(a, b)) \u3067\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B\
    \u3092\u5224\u5B9A\u3067\u304D\u3001\n     * auto [r, merged] = uf.merge(a, b);\
    \ \u3067\u4EE3\u8868\u5143\u3082\u53D7\u3051\u53D6\u308C\u308B\n     */\n    struct\
    \ MergeResult {\n        int leader;   //!< \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\
    \u5143\n        bool merged;  //!< \u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B\
    \ (\u3082\u3068\u3082\u3068\u540C\u3058\u9023\u7D50\u6210\u5206\u306A\u3089 false)\n\
    \        explicit operator bool() const { return merged; }\n    };\n\n    UnionFind()\
    \ : _n(0) {}\n    explicit UnionFind(int n) : _n(n), parent_or_size(n, -1) {}\n\
    \n    /**\n     * @brief \u8FBA(a,b)\u3092\u8DB3\u3059\n     * @return \u7D71\u5408\
    \u5F8C\u306E\u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\
    \u305F\u304B\n     */\n    MergeResult merge(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        int x = leader(a),\
    \ y = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        return {x, true};\n    }\n    /**\n \
    \    * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\u304B\n    \
    \ */\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n     \
    \   assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n    }\n\
    \    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u4EE3\u8868\u5143\n     */\n    int leader(int a) {\n        assert(0\
    \ <= a && a < _n);\n        if (parent_or_size[a] < 0) return a;\n        int\
    \ x = a;\n        while (parent_or_size[x] >= 0) {\n            x = parent_or_size[x];\n\
    \        }\n        while (parent_or_size[a] >= 0) {\n            int t = parent_or_size[a];\n\
    \            parent_or_size[a] = x;\n            a = t;\n        }\n        return\
    \ x;\n    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\
    \u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\n     */\n    int size(int a) {\n \
    \       assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\
    \u306B\u5206\u3051\u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return\
    \ \u300C\u4E00\u3064\u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\
    \u306E\u30EA\u30B9\u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<int>>\
    \ groups() {\n        return internal_unionfind::groups(_n, [&](int a) { return\
    \ leader(a); });\n    }\n};\n#line 14 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n\n/**\n * @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind\n\
    \ * @tparam G \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u7FA4 (algebra/group.hpp)\
    \ \u975E\u53EF\u63DB\u3067\u3082\u3088\u3044\n */\ntemplate <typename G>\nclass\
    \ PotentializedUnionFind {\n   public:\n    using S = typename G::S;\n    using\
    \ MergeResult = UnionFind::MergeResult;\n\n   private:\n    G g;\n    int _n;\n\
    \    // \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\u3089\u89AA\
    \n    std::vector<int> parent_or_size;\n    // \u91CD\u307F\n    std::vector<S>\
    \ diff_weight;\n\n    S op(const S& a, const S& b) const { return g.op(a, b);\
    \ }\n    S e() const { return g.e(); }\n    S inv(const S& a) const { return g.inv(a);\
    \ }\n\n   public:\n    /**\n     * @param n \u8981\u7D20\u6570\n     * @param\
    \ g \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u7FA4\n     */\n    explicit PotentializedUnionFind(int\
    \ n = 0, G g = G()) : g(std::move(g)), _n(n), parent_or_size(n, -1), diff_weight(n,\
    \ e()) {}\n\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\
    \u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    int leader(int a) {\n\
    \        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0) return\
    \ a;\n        std::stack<int> stk;\n        stk.push(a);\n        while (parent_or_size[stk.top()]\
    \ >= 0) {\n            stk.push(parent_or_size[stk.top()]);\n        }\n     \
    \   const int root = stk.top();\n        stk.pop();\n        stk.pop();\n    \
    \    while (!stk.empty()) {\n            diff_weight[stk.top()] = op(diff_weight[parent_or_size[stk.top()]],\
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
    \   MergeResult merge(int a, int b, S w) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        w = op(weight(a), w);\n        w =\
    \ op(w, inv(weight(b)));\n        int x = leader(a), y = leader(b);\n        if\
    \ (x == y) return {x, false};\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ {\n            std::swap(x, y);\n            w = inv(w);\n        }\n      \
    \  parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] = x;\n \
    \       diff_weight[y] = w;\n        return {x, true};\n    }\n\n    /**\n   \
    \  * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\u304B\n     */\n\
    \    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        return leader(a) == leader(b);\n    }\n\n    /**\n\
    \     * @brief (b \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB) - (a \u306E\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB)\n     */\n    S diff(int a, int b) {\n       \
    \ assert(same(a, b));\n        return op(inv(weight(a)), weight(b));\n    }\n\n\
    \    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30BA\n     */\n    int size(int a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\u5206\u3051\
    \u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\u4E00\u3064\
    \u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\
    \u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<int>>\
    \ groups() {\n        return internal_unionfind::groups(_n, [&](int a) { return\
    \ leader(a); });\n    }\n\n   private:\n    S weight(int a) {\n        leader(a);\n\
    \        return diff_weight[a];\n    }\n};\n\ntemplate <typename G>\nPotentializedUnionFind(int,\
    \ G) -> PotentializedUnionFind<G>;\n#line 2 \"src/data_structures/segtree.hpp\"\
    \n\n/**\n * @file segtree.hpp\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\
    \ */\n\n#line 12 \"src/data_structures/segtree.hpp\"\n\n#line 14 \"src/data_structures/segtree.hpp\"\
    \n\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u4F8B:\n * SegTree<monoid::Max<int>>\
    \ seg(n);\n * SegTree seg(v, Monoid([](int a, int b) { return a + b; }, 0));\n\
    \ *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n */\ntemplate\
    \ <typename M>\nclass SegTree {\n   public:\n    using S = typename M::S;\n\n\
    \   private:\n    M m;\n    S op(const S& a, const S& b) const { return m.op(a,\
    \ b); }\n    S e() const { return m.e(); }\n\n    int n, sz, height;\n    std::vector<S>\
    \ data;\n    void update(int k) { data[k] = op(data[2 * k], data[2 * k + 1]);\
    \ }\n\n    class SegTreeReference {\n        SegTree& segtree;\n        int k;\n\
    \n       public:\n        SegTreeReference(SegTree& segtree, int k) : segtree(segtree),\
    \ k(k) {}\n        SegTreeReference& operator=(const S& x) {\n            segtree.set(k,\
    \ x);\n            return *this;\n        }\n        operator S() const { return\
    \ segtree.get(k); }\n    };\n\n    void construct_data() {\n        sz = 1;\n\
    \        height = 0;\n        while (sz < n) {\n            sz <<= 1;\n      \
    \      height++;\n        }\n        data.assign(sz * 2, e());\n    }\n\n   public:\n\
    \    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n \
    \    * @param n \u8981\u7D20\u6570\n     * @param m \u30E2\u30CE\u30A4\u30C9\n\
    \     */\n    explicit SegTree(int n = 0, M m = M()) : m(std::move(m)), n(n) {\n\
    \        construct_data();\n    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n \
    \    * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit SegTree(const\
    \ std::vector<S>& v, M m = M()) : SegTree(v.size(), std::move(m)) {\n        for\
    \ (int i = 0; i < n; i++) data[sz + i] = v[i];\n        for (int i = sz - 1; i\
    \ > 0; i--) update(i);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\
    \u8FD4\u3059\n     */\n    int size() const { return n; }\n\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n \
    \    *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S\
    \ \u5024\n     */\n    S get(int k) const {\n        assert(0 <= k && k < n);\n\
    \        return data[sz + k];\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n \
    \   S operator[](int k) const { return get(k); }\n    /**\n     * @brief \u6307\
    \u5B9A\u3055\u308C\u305F\u8981\u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\
    \n     *\n     * @param k\n     * @return SegTreeReference \u8981\u7D20\u3078\u306E\
    \u53C2\u7167 \u4EE3\u5165\u3055\u308C\u308B\u3068set()\u304C\u547C\u3070\u308C\
    \u308B\n     */\n    SegTreeReference operator[](int k) { return SegTreeReference(*this,\
    \ k); }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n\
    \     *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\
    \u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n     * @return std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\
    \u30FC\u30E0\n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const SegTree& rhs)\
    \ {\n        for (int i = 0; i < rhs.n; i++) {\n            if (i != 0) os <<\
    \ CharT(' ');\n            os << rhs[i];\n        }\n        return os;\n    }\n\
    \n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\
    \u3092x\u306B\u66F4\u65B0\u3059\u308B\n     *\n     * @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n     * @param x \u65B0\u3057\u3044\u5024\n     */\n    void\
    \ set(int k, const S& x) {\n        assert(0 <= k && k < n);\n        k += sz;\n\
    \        data[k] = x;\n        for (int i = 1; i <= height; i++) update(k >> i);\n\
    \    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u306Bx\u3092\u4F5C\u7528\u3055\u305B\u308B\n     *\n     * @param k \u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u4F5C\u7528\u7D20\n     */\n\
    \    void apply(int k, const S& x) { set(k, op(get(k), x)); }\n\n    /**\n   \
    \  * @brief [l, r)\u306E\u533A\u9593\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n   \
    \  *\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param\
    \ r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @return S \u7DCF\
    \u7A4D\n     */\n    S prod(int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        S left_prod = e(), right_prod = e();\n        l +=\
    \ sz;\n        r += sz;\n        while (l < r) {\n            if (l & 1) left_prod\
    \ = op(left_prod, data[l++]);\n            if (r & 1) right_prod = op(data[--r],\
    \ right_prod);\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return op(left_prod, right_prod);\n    }\n    /**\n     * @brief \u3059\u3079\
    \u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @return\
    \ S \u7DCF\u7A4D\n     */\n    S all_prod() const { return data[1]; }\n\n    /**\n\
    \     * @brief (r = l or f(prod([l, r))) = true) and (r = n or f(prod([l, r+1)))\
    \ = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\n     * f\u304C\u5358\u8ABF\u306A\
    \u3089\u3001f(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n    \
    \ *\n     * @tparam F\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \ 0<=l<=n\n     * @param f \u5224\u5B9A\u95A2\u6570 f(e) = true\n     * @return\
    \ int\n     */\n    template <typename F>\n    int max_right(int l, F f) const\
    \ {\n        assert(f(e()));\n        assert(0 <= l && l <= n);\n        if (l\
    \ == n) return n;\n        l += sz;\n        while (l % 2 == 0) l >>= 1;\n   \
    \     S sum = e();\n        while (f(op(sum, data[l]))) {\n            sum = op(sum,\
    \ data[l]);\n            l++;\n            while (l % 2 == 0) l >>= 1;\n     \
    \       if (l == 1) return n;\n        }\n        while (l < sz) {\n         \
    \   if (!f(op(sum, data[l * 2])))\n                l *= 2;\n            else {\n\
    \                sum = op(sum, data[l * 2]);\n                l = l * 2 + 1;\n\
    \            }\n        }\n        return l - sz;\n    }\n    /**\n     * @brief\
    \ (l = 0 or f(prod([l, r))) = true) and (l = r or f(prod([l-1, r))) = false)\u3068\
    \u306A\u308Bl\u3092\u8FD4\u3059\n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001\
    f(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5C0F\u306El\n     *\n     * @tparam\
    \ F\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n    \
    \ * @param f \u5224\u5B9A\u95A2\u6570 f(e) = true\n     * @return int\n     */\n\
    \    template <typename F>\n    int min_left(int r, F f) const {\n        assert(f(e()));\n\
    \        assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        r +=\
    \ sz;\n        S sum = e();\n        do {\n            r--;\n            while\
    \ (r > 1 && r % 2 == 1) r >>= 1;\n            if (!f(op(data[r], sum))) {\n  \
    \              while (r < sz) {\n                    r = r * 2 + 1;\n        \
    \            if (f(op(data[r], sum))) {\n                        sum = op(data[r],\
    \ sum);\n                        r--;\n                    }\n               \
    \ }\n                return r + 1 - sz;\n            }\n            sum = op(data[r],\
    \ sum);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\ntemplate\
    \ <typename M>\nSegTree(int, M) -> SegTree<M>;\ntemplate <typename M>\nSegTree(std::vector<typename\
    \ M::S>, M) -> SegTree<M>;\n\n/**\n * @brief RangeMaxQuery\n *\n * @tparam S \u578B\
    \n */\ntemplate <typename S>\nusing RMaxQ = SegTree<monoid::Max<S>>;\n/**\n *\
    \ @brief RangeMinQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename S>\n\
    using RMinQ = SegTree<monoid::Min<S>>;\n/**\n * @brief RangeSumQuery\n *\n * @tparam\
    \ S \u578B\n */\ntemplate <typename S>\nusing RSumQ = SegTree<monoid::Sum<S>>;\n\
    /**\n * @brief RangeProdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RProdQ = SegTree<monoid::Prod<S>>;\n/**\n * @brief RangeXorQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RXorQ = SegTree<monoid::Xor<S>>;\n\
    /**\n * @brief RangeGcdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RGcdQ = SegTree<monoid::Gcd<S>>;\n#line 17 \"test/unittest/monoid.test.cpp\"\
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
    \   check(os.str() == expect.str(), name);\n    }\n}\n\nint main() {\n    std::mt19937_64\
    \ rng(314);\n\n    // And / Or: \u5358\u4F4D\u5143\u306F\u305D\u308C\u305E\u308C\
    \u5168\u30D3\u30C3\u30C8 1 \u3068 0\n    check(monoid::And<unsigned>::e() == ~0u,\
    \ \"And::e\");\n    check(monoid::Or<unsigned>::e() == 0u, \"Or::e\");\n    auto\
    \ gen_bits = [&] { return (unsigned)(rng() % 64); };\n    test_segtree<monoid::And<unsigned>>([](unsigned\
    \ a, unsigned b) { return a & b; }, ~0u, gen_bits, rng, \"And\");\n    test_segtree<monoid::Or<unsigned>>([](unsigned\
    \ a, unsigned b) { return a | b; }, 0u, gen_bits, rng, \"Or\");\n\n    // Parenthesis:\
    \ \u533A\u9593\u304C\u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\u3092 is_valid\
    \ \u3067\u5224\u5B9A\u3059\u308B\n    for (int rep = 0; rep < 300 && ok; rep++)\
    \ {\n        int n = rng() % 16 + 1;\n        std::string s(n, '(');\n       \
    \ for (char& c : s) c = rng() % 2 ? '(' : ')';\n        std::vector<monoid::Parenthesis::S>\
    \ v(s.begin(), s.end());\n        SegTree<monoid::Parenthesis> seg(v);\n     \
    \   for (int l = 0; l <= n; l++) {\n            for (int r = l; r <= n; r++) {\n\
    \                int depth = 0, min_depth = 0;\n                for (int i = l;\
    \ i < r; i++) {\n                    depth += s[i] == '(' ? 1 : -1;\n        \
    \            min_depth = std::min(min_depth, depth);\n                }\n    \
    \            auto p = seg.prod(l, r);\n                check(p.is_valid() == (depth\
    \ == 0 && min_depth == 0), \"Parenthesis::is_valid\");\n                check(p.close\
    \ == -min_depth && p.open == depth - min_depth, \"Parenthesis::op\");\n      \
    \      }\n        }\n    }\n\n    // Affine: ==, !=, \u51FA\u529B\n    {\n   \
    \     Affine<long long> f{2, 3}, g{2, 3}, h{2, 4}, id;\n        check(f == g &&\
    \ !(f != g), \"Affine ==\");\n        check(f != h && !(f == h), \"Affine !=\"\
    );\n        check(id == Affine<long long>{1, 0}, \"Affine default\");\n      \
    \  std::ostringstream os;\n        os << f;\n        check(os.str() == \"2 3\"\
    , \"Affine <<\");\n        // Composite \u3067\u5408\u6210\u3057\u305F\u7D50\u679C\
    \u304C\u95A2\u6570\u306E\u5408\u6210 a\u2218b \u3068\u4E00\u81F4\u3059\u308B\u3002\
    Reverse \u306F b\u2218a\n        for (int rep = 0; rep < 1000 && ok; rep++) {\n\
    \            Affine<long long> a{(long long)(rng() % 7) - 3, (long long)(rng()\
    \ % 7) - 3};\n            Affine<long long> b{(long long)(rng() % 7) - 3, (long\
    \ long)(rng() % 7) - 3};\n            long long x = (long long)(rng() % 7) - 3;\n\
    \            auto c = monoid::Composite<long long>::op(a, b);\n            check(c(x)\
    \ == a(b(x)), \"Composite op\");\n            check(c == Affine<long long>{a.a\
    \ * b.a, a.a * b.b + a.b}, \"Affine == after op\");\n            auto d = monoid::Reverse<monoid::Composite<long\
    \ long>>().op(a, b);\n            check(d(x) == b(a(x)), \"Reverse<Composite>\
    \ op\");\n        }\n    }\n\n    // group::Xor: inv \u306F\u81EA\u5206\u81EA\u8EAB\
    \u3002PotentializedUnionFind \u306B\u4E57\u305B\u3066 xor \u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 300 &&\
    \ ok; rep++) {\n        int n = rng() % 12 + 1;\n        std::vector<int> pot(n);\n\
    \        for (int& p : pot) p = rng() % 1024;\n        std::vector<int> comp(n);\n\
    \        for (int i = 0; i < n; i++) comp[i] = i;\n        PotentializedUnionFind<group::Xor<int>>\
    \ uf(n);\n        for (int q = 0; q < 30 && ok; q++) {\n            int a = rng()\
    \ % n, b = rng() % n;\n            if (rng() % 2) {\n                uf.merge(a,\
    \ b, pot[a] ^ pot[b]);\n                int ca = comp[a], cb = comp[b];\n    \
    \            for (int& c : comp)\n                    if (c == cb) c = ca;\n \
    \           } else {\n                check(uf.same(a, b) == (comp[a] == comp[b]),\
    \ \"group::Xor same\");\n                if (comp[a] == comp[b]) check(uf.diff(a,\
    \ b) == (pot[a] ^ pot[b]), \"group::Xor diff\");\n            }\n        }\n \
    \       int x = rng() % 1024;\n        check(group::Xor<int>::inv(x) == x, \"\
    group::Xor::inv\");\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// monoid.hpp / group.hpp \u306E\u30E2\u30CE\u30A4\u30C9\u30FB\u7FA4\u3068\
    \ SegTree \u306E\u7D30\u304B\u3044\u6A5F\u80FD\u3092\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/algebra/monoid.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <sstream>\n#include <string>\n\
    #include <vector>\n\n#include \"../../src/algebra/group.hpp\"\n#include \"../../src/data_structures/potentialized-unionfind.hpp\"\
    \n#include \"../../src/data_structures/segtree.hpp\"\n\nbool ok = true;\nvoid\
    \ check(bool cond, const char* what) {\n    if (!cond && ok) std::cerr << \"failed:\
    \ \" << what << std::endl;\n    if (!cond) ok = false;\n}\n\n// SegTree<M> \u3092\
    \u3001\u914D\u5217\u3068\u6F14\u7B97 op \u3067\u611A\u76F4\u306B\u8A08\u7B97\u3057\
    \u305F\u7D50\u679C\u3068\u30E9\u30F3\u30C0\u30E0\u306A\u64CD\u4F5C\u5217\u3067\
    \u6BD4\u3079\u308B\n// size\u30FBconst \u306A operator[]\u30FBall_prod\u30FBos\
    \ << seg \u3082\u78BA\u304B\u3081\u308B\ntemplate <typename M, typename Op, typename\
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
    \ name);\n    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\n    // And\
    \ / Or: \u5358\u4F4D\u5143\u306F\u305D\u308C\u305E\u308C\u5168\u30D3\u30C3\u30C8\
    \ 1 \u3068 0\n    check(monoid::And<unsigned>::e() == ~0u, \"And::e\");\n    check(monoid::Or<unsigned>::e()\
    \ == 0u, \"Or::e\");\n    auto gen_bits = [&] { return (unsigned)(rng() % 64);\
    \ };\n    test_segtree<monoid::And<unsigned>>([](unsigned a, unsigned b) { return\
    \ a & b; }, ~0u, gen_bits, rng, \"And\");\n    test_segtree<monoid::Or<unsigned>>([](unsigned\
    \ a, unsigned b) { return a | b; }, 0u, gen_bits, rng, \"Or\");\n\n    // Parenthesis:\
    \ \u533A\u9593\u304C\u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\u3092 is_valid\
    \ \u3067\u5224\u5B9A\u3059\u308B\n    for (int rep = 0; rep < 300 && ok; rep++)\
    \ {\n        int n = rng() % 16 + 1;\n        std::string s(n, '(');\n       \
    \ for (char& c : s) c = rng() % 2 ? '(' : ')';\n        std::vector<monoid::Parenthesis::S>\
    \ v(s.begin(), s.end());\n        SegTree<monoid::Parenthesis> seg(v);\n     \
    \   for (int l = 0; l <= n; l++) {\n            for (int r = l; r <= n; r++) {\n\
    \                int depth = 0, min_depth = 0;\n                for (int i = l;\
    \ i < r; i++) {\n                    depth += s[i] == '(' ? 1 : -1;\n        \
    \            min_depth = std::min(min_depth, depth);\n                }\n    \
    \            auto p = seg.prod(l, r);\n                check(p.is_valid() == (depth\
    \ == 0 && min_depth == 0), \"Parenthesis::is_valid\");\n                check(p.close\
    \ == -min_depth && p.open == depth - min_depth, \"Parenthesis::op\");\n      \
    \      }\n        }\n    }\n\n    // Affine: ==, !=, \u51FA\u529B\n    {\n   \
    \     Affine<long long> f{2, 3}, g{2, 3}, h{2, 4}, id;\n        check(f == g &&\
    \ !(f != g), \"Affine ==\");\n        check(f != h && !(f == h), \"Affine !=\"\
    );\n        check(id == Affine<long long>{1, 0}, \"Affine default\");\n      \
    \  std::ostringstream os;\n        os << f;\n        check(os.str() == \"2 3\"\
    , \"Affine <<\");\n        // Composite \u3067\u5408\u6210\u3057\u305F\u7D50\u679C\
    \u304C\u95A2\u6570\u306E\u5408\u6210 a\u2218b \u3068\u4E00\u81F4\u3059\u308B\u3002\
    Reverse \u306F b\u2218a\n        for (int rep = 0; rep < 1000 && ok; rep++) {\n\
    \            Affine<long long> a{(long long)(rng() % 7) - 3, (long long)(rng()\
    \ % 7) - 3};\n            Affine<long long> b{(long long)(rng() % 7) - 3, (long\
    \ long)(rng() % 7) - 3};\n            long long x = (long long)(rng() % 7) - 3;\n\
    \            auto c = monoid::Composite<long long>::op(a, b);\n            check(c(x)\
    \ == a(b(x)), \"Composite op\");\n            check(c == Affine<long long>{a.a\
    \ * b.a, a.a * b.b + a.b}, \"Affine == after op\");\n            auto d = monoid::Reverse<monoid::Composite<long\
    \ long>>().op(a, b);\n            check(d(x) == b(a(x)), \"Reverse<Composite>\
    \ op\");\n        }\n    }\n\n    // group::Xor: inv \u306F\u81EA\u5206\u81EA\u8EAB\
    \u3002PotentializedUnionFind \u306B\u4E57\u305B\u3066 xor \u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 300 &&\
    \ ok; rep++) {\n        int n = rng() % 12 + 1;\n        std::vector<int> pot(n);\n\
    \        for (int& p : pot) p = rng() % 1024;\n        std::vector<int> comp(n);\n\
    \        for (int i = 0; i < n; i++) comp[i] = i;\n        PotentializedUnionFind<group::Xor<int>>\
    \ uf(n);\n        for (int q = 0; q < 30 && ok; q++) {\n            int a = rng()\
    \ % n, b = rng() % n;\n            if (rng() % 2) {\n                uf.merge(a,\
    \ b, pot[a] ^ pot[b]);\n                int ca = comp[a], cb = comp[b];\n    \
    \            for (int& c : comp)\n                    if (c == cb) c = ca;\n \
    \           } else {\n                check(uf.same(a, b) == (comp[a] == comp[b]),\
    \ \"group::Xor same\");\n                if (comp[a] == comp[b]) check(uf.diff(a,\
    \ b) == (pot[a] ^ pot[b]), \"group::Xor diff\");\n            }\n        }\n \
    \       int x = rng() % 1024;\n        check(group::Xor<int>::inv(x) == x, \"\
    group::Xor::inv\");\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/algebra/monoid.hpp
  - src/algebra/group.hpp
  - src/data_structures/potentialized-unionfind.hpp
  - src/data_structures/unionfind.hpp
  - src/data_structures/segtree.hpp
  isVerificationFile: true
  path: test/unittest/monoid.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 21:19:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/monoid.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/monoid.test.cpp
- /verify/test/unittest/monoid.test.cpp.html
title: test/unittest/monoid.test.cpp
---
