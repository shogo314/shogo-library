---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_B
  bundledCode: "#line 1 \"test/aoj/itp2-3-b.1.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/data_structures/segtree.hpp\"\
    \n\n/**\n * @file segtree.hpp\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\
    \ */\n\n#include <cassert>\n#include <ostream>\n#include <utility>\n#line 12 \"\
    src/data_structures/segtree.hpp\"\n\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n\
    \ * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n\
    \ * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\
    \u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n\
    \ * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\
    \u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\
    \u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\
    \u3059)\n */\n\n#include <algorithm>\n#include <array>\n#include <cstddef>\n#include\
    \ <istream>\n#include <limits>\n#include <numeric>\n#line 21 \"src/algebra/monoid.hpp\"\
    \n#include <type_traits>\n#line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief\
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
    \ T) -> Monoid<T, Op>;\n#line 14 \"src/data_structures/segtree.hpp\"\n\n/**\n\
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u4F8B:\n * SegTree<monoid::Max<int>>\
    \ seg(n);\n * SegTree seg(v, Monoid([](int a, int b) { return a + b; }, 0));\n\
    \ *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n */\ntemplate\
    \ <typename M>\nclass SegTree {\n   public:\n    using S = typename M::S;\n\n\
    \   private:\n    M m;\n    S op(const S& a, const S& b) const { return m.op(a,\
    \ b); }\n    S e() const { return m.e(); }\n\n    long long n, sz;\n    int height;\n\
    \    std::vector<S> data;\n    void update(long long k) { data[k] = op(data[2\
    \ * k], data[2 * k + 1]); }\n\n    class SegTreeReference {\n        SegTree&\
    \ segtree;\n        long long k;\n\n       public:\n        SegTreeReference(SegTree&\
    \ segtree, long long k) : segtree(segtree), k(k) {}\n        SegTreeReference&\
    \ operator=(const S& x) {\n            segtree.set(k, x);\n            return\
    \ *this;\n        }\n        operator S() const { return segtree.get(k); }\n \
    \   };\n\n    void construct_data() {\n        sz = 1;\n        height = 0;\n\
    \        while (sz < n) {\n            sz <<= 1;\n            height++;\n    \
    \    }\n        data.assign(sz * 2, e());\n    }\n\n   public:\n    /**\n    \
    \ * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param n\
    \ \u8981\u7D20\u6570\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ SegTree(long long n = 0, M m = M()) : m(std::move(m)), n(n) {\n        construct_data();\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param m \u30E2\u30CE\
    \u30A4\u30C9\n     */\n    explicit SegTree(const std::vector<S>& v, M m = M())\
    \ : SegTree(v.size(), std::move(m)) {\n        for (long long i = 0; i < n; i++)\
    \ data[sz + i] = v[i];\n        for (long long i = sz - 1; i > 0; i--) update(i);\n\
    \    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n\
    \    long long size() const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\
    \u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n \
    \   S get(long long k) const {\n        assert(0 <= k && k < n);\n        return\
    \ data[sz + k];\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\
    \u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n    S operator[](long long\
    \ k) const { return get(k); }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k\n     * @return SegTreeReference \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\
    \u5165\u3055\u308C\u308B\u3068set()\u304C\u547C\u3070\u308C\u308B\n     */\n \
    \   SegTreeReference operator[](long long k) { return SegTreeReference(*this,\
    \ k); }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n\
    \     *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\
    \u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n     * @return std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\
    \u30FC\u30E0\n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const SegTree& rhs)\
    \ {\n        for (long long i = 0; i < rhs.n; i++) {\n            if (i != 0)\
    \ os << CharT(' ');\n            os << rhs[i];\n        }\n        return os;\n\
    \    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n     *\n     * @param k \u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\u3057\u3044\u5024\n     */\n\
    \    void set(long long k, const S& x) {\n        assert(0 <= k && k < n);\n \
    \       k += sz;\n        data[k] = x;\n        for (int i = 1; i <= height; i++)\
    \ update(k >> i);\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\
    \u8981\u7D20\u306E\u5024\u306Bx\u3092\u4F5C\u7528\u3055\u305B\u308B\n     *\n\
    \     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u4F5C\u7528\
    \u7D20\n     */\n    void apply(long long k, const S& x) { set(k, op(get(k), x));\
    \ }\n\n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\u7DCF\u7A4D\u3092\
    \u8FD4\u3059\n     *\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n    \
    \ * @return S \u7DCF\u7A4D\n     */\n    S prod(long long l, long long r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        S left_prod = e(), right_prod\
    \ = e();\n        l += sz;\n        r += sz;\n        while (l < r) {\n      \
    \      if (l & 1) left_prod = op(left_prod, data[l++]);\n            if (r & 1)\
    \ right_prod = op(data[--r], right_prod);\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        return op(left_prod, right_prod);\n    }\n    /**\n\
    \     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\
    \u3059\n     *\n     * @return S \u7DCF\u7A4D\n     */\n    S all_prod() const\
    \ { return data[1]; }\n\n    /**\n     * @brief (r = l or f(prod([l, r))) = true)\
    \ and (r = n or f(prod([l, r+1))) = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\
    \n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001f(prod([l, r))) = true\u3068\u306A\
    \u308B\u6700\u5927\u306Er\n     *\n     * @tparam F\n     * @param l \u534A\u958B\
    \u533A\u9593\u306E\u958B\u59CB 0<=l<=n\n     * @param f \u5224\u5B9A\u95A2\u6570\
    \ f(e) = true\n     * @return long long\n     */\n    template <typename F>\n\
    \    long long max_right(long long l, F f) const {\n        assert(f(e()));\n\
    \        assert(0 <= l && l <= n);\n        if (l == n) return n;\n        l +=\
    \ sz;\n        while (l % 2 == 0) l >>= 1;\n        S sum = e();\n        while\
    \ (f(op(sum, data[l]))) {\n            sum = op(sum, data[l]);\n            l++;\n\
    \            while (l % 2 == 0) l >>= 1;\n            if (l == 1) return n;\n\
    \        }\n        while (l < sz) {\n            if (!f(op(sum, data[l * 2])))\n\
    \                l *= 2;\n            else {\n                sum = op(sum, data[l\
    \ * 2]);\n                l = l * 2 + 1;\n            }\n        }\n        return\
    \ l - sz;\n    }\n    /**\n     * @brief (l = 0 or f(prod([l, r))) = true) and\
    \ (l = r or f(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\u8FD4\u3059\n\
    \     * f\u304C\u5358\u8ABF\u306A\u3089\u3001f(prod([l, r))) = true\u3068\u306A\
    \u308B\u6700\u5C0F\u306El\n     *\n     * @tparam F\n     * @param r \u534A\u958B\
    \u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param f \u5224\u5B9A\u95A2\u6570\
    \ f(e) = true\n     * @return long long\n     */\n    template <typename F>\n\
    \    long long min_left(long long r, F f) const {\n        assert(f(e()));\n \
    \       assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        r +=\
    \ sz;\n        S sum = e();\n        do {\n            r--;\n            while\
    \ (r > 1 && r % 2 == 1) r >>= 1;\n            if (!f(op(data[r], sum))) {\n  \
    \              while (r < sz) {\n                    r = r * 2 + 1;\n        \
    \            if (f(op(data[r], sum))) {\n                        sum = op(data[r],\
    \ sum);\n                        r--;\n                    }\n               \
    \ }\n                return r + 1 - sz;\n            }\n            sum = op(data[r],\
    \ sum);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\ntemplate\
    \ <typename M>\nSegTree(long long, M) -> SegTree<M>;\ntemplate <typename M>\n\
    SegTree(std::vector<typename M::S>, M) -> SegTree<M>;\n\n/**\n * @brief RangeMaxQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RMaxQ = SegTree<monoid::Max<S>>;\n\
    /**\n * @brief RangeMinQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RMinQ = SegTree<monoid::Min<S>>;\n/**\n * @brief RangeSumQuery\n *\n\
    \ * @tparam S \u578B\n */\ntemplate <typename S>\nusing RSumQ = SegTree<monoid::Sum<S>>;\n\
    /**\n * @brief RangeProdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RProdQ = SegTree<monoid::Prod<S>>;\n/**\n * @brief RangeXorQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RXorQ = SegTree<monoid::Xor<S>>;\n\
    /**\n * @brief RangeGcdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RGcdQ = SegTree<monoid::Gcd<S>>;\n#line 7 \"test/aoj/itp2-3-b.1.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<long long> a(n);\n\
    \    for (auto& x : a) std::cin >> x;\n    RMinQ<long long> seg_min(a);\n    RMaxQ<long\
    \ long> seg_max(a);\n    int q;\n    std::cin >> q;\n    while (q--) {\n     \
    \   int com, b, e;\n        std::cin >> com >> b >> e;\n        if (com == 0)\
    \ {\n            std::cout << seg_min.prod(b, e) << '\\n';\n        } else {\n\
    \            std::cout << seg_max.prod(b, e) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/data_structures/segtree.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<long long> a(n);\n\
    \    for (auto& x : a) std::cin >> x;\n    RMinQ<long long> seg_min(a);\n    RMaxQ<long\
    \ long> seg_max(a);\n    int q;\n    std::cin >> q;\n    while (q--) {\n     \
    \   int com, b, e;\n        std::cin >> com >> b >> e;\n        if (com == 0)\
    \ {\n            std::cout << seg_min.prod(b, e) << '\\n';\n        } else {\n\
    \            std::cout << seg_max.prod(b, e) << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - src/data_structures/segtree.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: true
  path: test/aoj/itp2-3-b.1.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 07:27:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/itp2-3-b.1.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/itp2-3-b.1.test.cpp
- /verify/test/aoj/itp2-3-b.1.test.cpp.html
title: test/aoj/itp2-3-b.1.test.cpp
---
