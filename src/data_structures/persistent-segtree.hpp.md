---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/persistent-segtree.test.cpp
    title: test/unittest/persistent-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle-sum.4.test.cpp
    title: test/yosupo/rectangle-sum.4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"src/data_structures/persistent-segtree.hpp\"\n\n/**\n *\
    \ @file persistent-segtree.hpp\n * @brief \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\n */\n\n#include <cassert>\n#include <memory>\n#include <ostream>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"src/algebra/monoid.hpp\"\n\n\
    /**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#include <algorithm>\n#include <array>\n#include <cstddef>\n\
    #include <istream>\n#include <limits>\n#include <numeric>\n#line 21 \"src/algebra/monoid.hpp\"\
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
    \ T) -> Monoid<T, Op>;\n#line 15 \"src/data_structures/persistent-segtree.hpp\"\
    \n\n/**\n * @brief \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u66F4\
    \u65B0\u3059\u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\
    \u306E\u7248\u306F\u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u6728\u304B\
    \u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\u3059\
    \u308B\n * \u4F8B:\n * PersistentSegTree<monoid::Sum<long long>> s0(n);\n * auto\
    \ s1 = s0.set(3, 10);  // s0 \u306F\u305D\u306E\u307E\u307E\n * s1.prod(0, 5);\
    \            // 10\n *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n\
    \ */\ntemplate <typename M>\nclass PersistentSegTree {\n   public:\n    using\
    \ S = typename M::S;\n\n   private:\n    // \u3059\u3079\u3066\u306E\u7248\u306E\
    \u30CE\u30FC\u30C9\u3092\u6301\u3064\u3002\u30CE\u30FC\u30C9\u306F\u524A\u9664\
    \u3057\u306A\u3044\n    struct Pool {\n        M m;\n        std::vector<S> val;\n\
    \        std::vector<int> left, right;  // \u8449\u3067\u306F -1\n        explicit\
    \ Pool(M m) : m(std::move(m)) {}\n        int make_leaf(const S& x) {\n      \
    \      val.push_back(x);\n            left.push_back(-1);\n            right.push_back(-1);\n\
    \            return int(val.size()) - 1;\n        }\n        int make_node(int\
    \ l, int r) {\n            val.push_back(m.op(val[l], val[r]));\n            left.push_back(l);\n\
    \            right.push_back(r);\n            return int(val.size()) - 1;\n  \
    \      }\n    };\n\n    std::shared_ptr<Pool> pool;\n    int n, sz, root;\n\n\
    \    S op(const S& a, const S& b) const { return pool->m.op(a, b); }\n    S e()\
    \ const { return pool->m.e(); }\n\n    PersistentSegTree(std::shared_ptr<Pool>\
    \ pool, int n, int sz, int root) : pool(std::move(pool)), n(n), sz(sz), root(root)\
    \ {}\n\n    void init_size() {\n        sz = 1;\n        while (sz < n) sz <<=\
    \ 1;\n    }\n    int build(const std::vector<S>& v, int a, int b) {\n        if\
    \ (b - a == 1) return pool->make_leaf(a < n ? v[a] : e());\n        int mid =\
    \ (a + b) / 2;\n        int l = build(v, a, mid);\n        int r = build(v, mid,\
    \ b);\n        return pool->make_node(l, r);\n    }\n    int set_rec(int t, int\
    \ a, int b, int k, const S& x) const {\n        if (b - a == 1) return pool->make_leaf(x);\n\
    \        int mid = (a + b) / 2;\n        int l = pool->left[t], r = pool->right[t];\n\
    \        if (k < mid)\n            l = set_rec(l, a, mid, k, x);\n        else\n\
    \            r = set_rec(r, mid, b, k, x);\n        return pool->make_node(l,\
    \ r);\n    }\n    // t \u306E [l, r) \u3092 u \u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \n    int copy_rec(int t, int u, int a, int b, int l, int r) const {\n       \
    \ if (r <= a || b <= l) return t;\n        if (l <= a && b <= r) return u;\n \
    \       int mid = (a + b) / 2;\n        int lc = copy_rec(pool->left[t], pool->left[u],\
    \ a, mid, l, r);\n        int rc = copy_rec(pool->right[t], pool->right[u], mid,\
    \ b, l, r);\n        return pool->make_node(lc, rc);\n    }\n    S prod_rec(int\
    \ t, int a, int b, int l, int r) const {\n        if (r <= a || b <= l) return\
    \ e();\n        if (l <= a && b <= r) return pool->val[t];\n        int mid =\
    \ (a + b) / 2;\n        return op(prod_rec(pool->left[t], a, mid, l, r), prod_rec(pool->right[t],\
    \ mid, b, l, r));\n    }\n    // [a, b) \u306E\u3046\u3061 l \u4EE5\u964D\u3067\
    \u3001sum \u306B\u639B\u3051\u308B\u3068 f \u304C\u507D\u306B\u306A\u308B\u6700\
    \u521D\u306E\u4F4D\u7F6E (\u306A\u3051\u308C\u3070 b)\n    template <typename\
    \ F>\n    int max_right_rec(int t, int a, int b, int l, F& f, S& sum) const {\n\
    \        if (b <= l) return b;\n        if (l <= a) {\n            S s = op(sum,\
    \ pool->val[t]);\n            if (f(s)) {\n                sum = s;\n        \
    \        return b;\n            }\n            if (b - a == 1) return a;\n   \
    \     }\n        int mid = (a + b) / 2;\n        int x = max_right_rec(pool->left[t],\
    \ a, mid, l, f, sum);\n        if (x < mid) return x;\n        return max_right_rec(pool->right[t],\
    \ mid, b, l, f, sum);\n    }\n    // [a, b) \u306E\u3046\u3061 r \u3088\u308A\u524D\
    \u3067\u3001sum \u306B\u5DE6\u304B\u3089\u639B\u3051\u308B\u3068 f \u304C\u507D\
    \u306B\u306A\u308B\u6700\u5F8C\u306E\u4F4D\u7F6E + 1 (\u306A\u3051\u308C\u3070\
    \ a)\n    template <typename F>\n    int min_left_rec(int t, int a, int b, int\
    \ r, F& f, S& sum) const {\n        if (r <= a) return a;\n        if (b <= r)\
    \ {\n            S s = op(pool->val[t], sum);\n            if (f(s)) {\n     \
    \           sum = s;\n                return a;\n            }\n            if\
    \ (b - a == 1) return b;\n        }\n        int mid = (a + b) / 2;\n        int\
    \ x = min_left_rec(pool->right[t], mid, b, r, f, sum);\n        if (x > mid) return\
    \ x;\n        return min_left_rec(pool->left[t], a, mid, r, f, sum);\n    }\n\n\
    \   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     *\n     * \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u5358\u4F4D\u5143\u3067\
    \u521D\u671F\u5316\u3059\u308B\u3002\u5358\u4F4D\u5143\u306E\u90E8\u5206\u6728\
    \u306F\u5171\u6709\u3059\u308B\u306E\u3067\u3001n \u304C\u5927\u304D\u304F\u3066\
    \u3082 O(log n) \u3067\u4F5C\u308C\u308B\n     *\n     * @param n \u8981\u7D20\
    \u6570\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit PersistentSegTree(int\
    \ n = 0, M m = M()) : pool(std::make_shared<Pool>(std::move(m))), n(n) {\n   \
    \     assert(0 <= n);\n        init_size();\n        root = pool->make_leaf(e());\n\
    \        for (int w = 1; w < sz; w <<= 1) root = pool->make_node(root, root);\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param m \u30E2\u30CE\
    \u30A4\u30C9\n     */\n    explicit PersistentSegTree(const std::vector<S>& v,\
    \ M m = M()) : pool(std::make_shared<Pool>(std::move(m))), n(v.size()) {\n   \
    \     init_size();\n        root = build(v, 0, sz);\n    }\n\n    /**\n     *\
    \ @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    int size() const {\
    \ return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\
    \u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\n     * @return S \u5024\n     */\n    S get(int k) const {\n   \
    \     assert(0 <= k && k < n);\n        int t = root, a = 0, b = sz;\n       \
    \ while (b - a > 1) {\n            int mid = (a + b) / 2;\n            if (k <\
    \ mid) {\n                t = pool->left[t];\n                b = mid;\n     \
    \       } else {\n                t = pool->right[t];\n                a = mid;\n\
    \            }\n        }\n        return pool->val[t];\n    }\n    /**\n    \
    \ * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\
    \n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ S \u5024\n     */\n    S operator[](int k) const { return get(k); }\n\n    /**\n\
    \     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n     *\n     * @tparam\
    \ CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n \
    \    * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\
    \u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n     * @param rhs \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n     * @return\
    \ std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const PersistentSegTree&\
    \ rhs) {\n        for (int i = 0; i < rhs.n; i++) {\n            if (i != 0) os\
    \ << CharT(' ');\n            os << rhs[i];\n        }\n        return os;\n \
    \   }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u3092x\u306B\u3057\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n  \
    \   *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\
    \u3057\u3044\u5024\n     * @return PersistentSegTree \u65B0\u3057\u3044\u7248\
    \ (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentSegTree\
    \ set(int k, const S& x) const {\n        assert(0 <= k && k < n);\n        return\
    \ PersistentSegTree(pool, n, sz, set_rec(root, 0, sz, k, x));\n    }\n    /**\n\
    \     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u306Bx\u3092\
    \u4F5C\u7528\u3055\u305B\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n   \
    \  *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u4F5C\
    \u7528\u7D20\n     * @return PersistentSegTree \u65B0\u3057\u3044\u7248 (\u81EA\
    \u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentSegTree apply(int\
    \ k, const S& x) const { return set(k, op(get(k), x)); }\n\n    /**\n     * @brief\
    \ [l, r)\u306E\u533A\u9593\u3092\u5225\u306E\u7248\u306E\u5024\u306B\u3057\u305F\
    \u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param other \u5199\
    \u3059\u5143\u306E\u7248 (\u81EA\u8EAB\u3068\u540C\u3058\u6728\u304B\u3089\u4F5C\
    \u3063\u305F\u3082\u306E)\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\
    \u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n\
    \     * @return PersistentSegTree \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u3082\
    \ other \u3082\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentSegTree\
    \ copy(const PersistentSegTree& other, int l, int r) const {\n        assert(pool\
    \ == other.pool);\n        assert(0 <= l && l <= r && r <= n);\n        if (l\
    \ == r) return *this;\n        return PersistentSegTree(pool, n, sz, copy_rec(root,\
    \ other.root, 0, sz, l, r));\n    }\n\n    /**\n     * @brief [l, r)\u306E\u533A\
    \u9593\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\u958B\
    \u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\
    \u7D42\u7AEF 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ prod_rec(root, 0, sz, l, r);\n    }\n    /**\n     * @brief \u3059\u3079\u3066\
    \u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @return\
    \ S \u7DCF\u7A4D\n     */\n    S all_prod() const { return pool->val[root]; }\n\
    \n    /**\n     * @brief (r = l or f(prod([l, r))) = true) and (r = n or f(prod([l,\
    \ r+1))) = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\n     * f\u304C\u5358\u8ABF\
    \u306A\u3089\u3001f(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n\
    \     *\n     * @tparam F\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\
    \u59CB 0<=l<=n\n     * @param f \u5224\u5B9A\u95A2\u6570 f(e) = true\n     * @return\
    \ int\n     */\n    template <typename F>\n    int max_right(int l, F f) const\
    \ {\n        assert(f(e()));\n        assert(0 <= l && l <= n);\n        if (l\
    \ == n) return n;\n        S sum = e();\n        int r = max_right_rec(root, 0,\
    \ sz, l, f, sum);\n        return r < n ? r : n;\n    }\n    /**\n     * @brief\
    \ (l = 0 or f(prod([l, r))) = true) and (l = r or f(prod([l-1, r))) = false)\u3068\
    \u306A\u308Bl\u3092\u8FD4\u3059\n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001\
    f(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5C0F\u306El\n     *\n     * @tparam\
    \ F\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n    \
    \ * @param f \u5224\u5B9A\u95A2\u6570 f(e) = true\n     * @return int\n     */\n\
    \    template <typename F>\n    int min_left(int r, F f) const {\n        assert(f(e()));\n\
    \        assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        S sum\
    \ = e();\n        return min_left_rec(root, 0, sz, r, f, sum);\n    }\n\n    /**\n\
    \     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u4E26\u3079\u305F\u5217\
    \u3092\u8FD4\u3059\n     */\n    std::vector<S> to_vector() const {\n        std::vector<S>\
    \ res(n);\n        for (int i = 0; i < n; i++) res[i] = get(i);\n        return\
    \ res;\n    }\n};\n\ntemplate <typename M>\nPersistentSegTree(int, M) -> PersistentSegTree<M>;\n\
    template <typename M>\nPersistentSegTree(std::vector<typename M::S>, M) -> PersistentSegTree<M>;\n"
  code: "#pragma once\n\n/**\n * @file persistent-segtree.hpp\n * @brief \u6C38\u7D9A\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include <cassert>\n#include <memory>\n\
    #include <ostream>\n#include <utility>\n#include <vector>\n\n#include \"../algebra/monoid.hpp\"\
    \n\n/**\n * @brief \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u66F4\
    \u65B0\u3059\u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\
    \u306E\u7248\u306F\u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u6728\u304B\
    \u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\u3059\
    \u308B\n * \u4F8B:\n * PersistentSegTree<monoid::Sum<long long>> s0(n);\n * auto\
    \ s1 = s0.set(3, 10);  // s0 \u306F\u305D\u306E\u307E\u307E\n * s1.prod(0, 5);\
    \            // 10\n *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n\
    \ */\ntemplate <typename M>\nclass PersistentSegTree {\n   public:\n    using\
    \ S = typename M::S;\n\n   private:\n    // \u3059\u3079\u3066\u306E\u7248\u306E\
    \u30CE\u30FC\u30C9\u3092\u6301\u3064\u3002\u30CE\u30FC\u30C9\u306F\u524A\u9664\
    \u3057\u306A\u3044\n    struct Pool {\n        M m;\n        std::vector<S> val;\n\
    \        std::vector<int> left, right;  // \u8449\u3067\u306F -1\n        explicit\
    \ Pool(M m) : m(std::move(m)) {}\n        int make_leaf(const S& x) {\n      \
    \      val.push_back(x);\n            left.push_back(-1);\n            right.push_back(-1);\n\
    \            return int(val.size()) - 1;\n        }\n        int make_node(int\
    \ l, int r) {\n            val.push_back(m.op(val[l], val[r]));\n            left.push_back(l);\n\
    \            right.push_back(r);\n            return int(val.size()) - 1;\n  \
    \      }\n    };\n\n    std::shared_ptr<Pool> pool;\n    int n, sz, root;\n\n\
    \    S op(const S& a, const S& b) const { return pool->m.op(a, b); }\n    S e()\
    \ const { return pool->m.e(); }\n\n    PersistentSegTree(std::shared_ptr<Pool>\
    \ pool, int n, int sz, int root) : pool(std::move(pool)), n(n), sz(sz), root(root)\
    \ {}\n\n    void init_size() {\n        sz = 1;\n        while (sz < n) sz <<=\
    \ 1;\n    }\n    int build(const std::vector<S>& v, int a, int b) {\n        if\
    \ (b - a == 1) return pool->make_leaf(a < n ? v[a] : e());\n        int mid =\
    \ (a + b) / 2;\n        int l = build(v, a, mid);\n        int r = build(v, mid,\
    \ b);\n        return pool->make_node(l, r);\n    }\n    int set_rec(int t, int\
    \ a, int b, int k, const S& x) const {\n        if (b - a == 1) return pool->make_leaf(x);\n\
    \        int mid = (a + b) / 2;\n        int l = pool->left[t], r = pool->right[t];\n\
    \        if (k < mid)\n            l = set_rec(l, a, mid, k, x);\n        else\n\
    \            r = set_rec(r, mid, b, k, x);\n        return pool->make_node(l,\
    \ r);\n    }\n    // t \u306E [l, r) \u3092 u \u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \n    int copy_rec(int t, int u, int a, int b, int l, int r) const {\n       \
    \ if (r <= a || b <= l) return t;\n        if (l <= a && b <= r) return u;\n \
    \       int mid = (a + b) / 2;\n        int lc = copy_rec(pool->left[t], pool->left[u],\
    \ a, mid, l, r);\n        int rc = copy_rec(pool->right[t], pool->right[u], mid,\
    \ b, l, r);\n        return pool->make_node(lc, rc);\n    }\n    S prod_rec(int\
    \ t, int a, int b, int l, int r) const {\n        if (r <= a || b <= l) return\
    \ e();\n        if (l <= a && b <= r) return pool->val[t];\n        int mid =\
    \ (a + b) / 2;\n        return op(prod_rec(pool->left[t], a, mid, l, r), prod_rec(pool->right[t],\
    \ mid, b, l, r));\n    }\n    // [a, b) \u306E\u3046\u3061 l \u4EE5\u964D\u3067\
    \u3001sum \u306B\u639B\u3051\u308B\u3068 f \u304C\u507D\u306B\u306A\u308B\u6700\
    \u521D\u306E\u4F4D\u7F6E (\u306A\u3051\u308C\u3070 b)\n    template <typename\
    \ F>\n    int max_right_rec(int t, int a, int b, int l, F& f, S& sum) const {\n\
    \        if (b <= l) return b;\n        if (l <= a) {\n            S s = op(sum,\
    \ pool->val[t]);\n            if (f(s)) {\n                sum = s;\n        \
    \        return b;\n            }\n            if (b - a == 1) return a;\n   \
    \     }\n        int mid = (a + b) / 2;\n        int x = max_right_rec(pool->left[t],\
    \ a, mid, l, f, sum);\n        if (x < mid) return x;\n        return max_right_rec(pool->right[t],\
    \ mid, b, l, f, sum);\n    }\n    // [a, b) \u306E\u3046\u3061 r \u3088\u308A\u524D\
    \u3067\u3001sum \u306B\u5DE6\u304B\u3089\u639B\u3051\u308B\u3068 f \u304C\u507D\
    \u306B\u306A\u308B\u6700\u5F8C\u306E\u4F4D\u7F6E + 1 (\u306A\u3051\u308C\u3070\
    \ a)\n    template <typename F>\n    int min_left_rec(int t, int a, int b, int\
    \ r, F& f, S& sum) const {\n        if (r <= a) return a;\n        if (b <= r)\
    \ {\n            S s = op(pool->val[t], sum);\n            if (f(s)) {\n     \
    \           sum = s;\n                return a;\n            }\n            if\
    \ (b - a == 1) return b;\n        }\n        int mid = (a + b) / 2;\n        int\
    \ x = min_left_rec(pool->right[t], mid, b, r, f, sum);\n        if (x > mid) return\
    \ x;\n        return min_left_rec(pool->left[t], a, mid, r, f, sum);\n    }\n\n\
    \   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     *\n     * \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u5358\u4F4D\u5143\u3067\
    \u521D\u671F\u5316\u3059\u308B\u3002\u5358\u4F4D\u5143\u306E\u90E8\u5206\u6728\
    \u306F\u5171\u6709\u3059\u308B\u306E\u3067\u3001n \u304C\u5927\u304D\u304F\u3066\
    \u3082 O(log n) \u3067\u4F5C\u308C\u308B\n     *\n     * @param n \u8981\u7D20\
    \u6570\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit PersistentSegTree(int\
    \ n = 0, M m = M()) : pool(std::make_shared<Pool>(std::move(m))), n(n) {\n   \
    \     assert(0 <= n);\n        init_size();\n        root = pool->make_leaf(e());\n\
    \        for (int w = 1; w < sz; w <<= 1) root = pool->make_node(root, root);\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param m \u30E2\u30CE\
    \u30A4\u30C9\n     */\n    explicit PersistentSegTree(const std::vector<S>& v,\
    \ M m = M()) : pool(std::make_shared<Pool>(std::move(m))), n(v.size()) {\n   \
    \     init_size();\n        root = build(v, 0, sz);\n    }\n\n    /**\n     *\
    \ @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    int size() const {\
    \ return n; }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\
    \u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\n     * @return S \u5024\n     */\n    S get(int k) const {\n   \
    \     assert(0 <= k && k < n);\n        int t = root, a = 0, b = sz;\n       \
    \ while (b - a > 1) {\n            int mid = (a + b) / 2;\n            if (k <\
    \ mid) {\n                t = pool->left[t];\n                b = mid;\n     \
    \       } else {\n                t = pool->right[t];\n                a = mid;\n\
    \            }\n        }\n        return pool->val[t];\n    }\n    /**\n    \
    \ * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\
    \n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ S \u5024\n     */\n    S operator[](int k) const { return get(k); }\n\n    /**\n\
    \     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n     *\n     * @tparam\
    \ CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n \
    \    * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\
    \u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n     * @param rhs \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n     * @return\
    \ std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const PersistentSegTree&\
    \ rhs) {\n        for (int i = 0; i < rhs.n; i++) {\n            if (i != 0) os\
    \ << CharT(' ');\n            os << rhs[i];\n        }\n        return os;\n \
    \   }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u3092x\u306B\u3057\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n  \
    \   *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\
    \u3057\u3044\u5024\n     * @return PersistentSegTree \u65B0\u3057\u3044\u7248\
    \ (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentSegTree\
    \ set(int k, const S& x) const {\n        assert(0 <= k && k < n);\n        return\
    \ PersistentSegTree(pool, n, sz, set_rec(root, 0, sz, k, x));\n    }\n    /**\n\
    \     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u306Bx\u3092\
    \u4F5C\u7528\u3055\u305B\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n   \
    \  *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u4F5C\
    \u7528\u7D20\n     * @return PersistentSegTree \u65B0\u3057\u3044\u7248 (\u81EA\
    \u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentSegTree apply(int\
    \ k, const S& x) const { return set(k, op(get(k), x)); }\n\n    /**\n     * @brief\
    \ [l, r)\u306E\u533A\u9593\u3092\u5225\u306E\u7248\u306E\u5024\u306B\u3057\u305F\
    \u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param other \u5199\
    \u3059\u5143\u306E\u7248 (\u81EA\u8EAB\u3068\u540C\u3058\u6728\u304B\u3089\u4F5C\
    \u3063\u305F\u3082\u306E)\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\
    \u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n\
    \     * @return PersistentSegTree \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u3082\
    \ other \u3082\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentSegTree\
    \ copy(const PersistentSegTree& other, int l, int r) const {\n        assert(pool\
    \ == other.pool);\n        assert(0 <= l && l <= r && r <= n);\n        if (l\
    \ == r) return *this;\n        return PersistentSegTree(pool, n, sz, copy_rec(root,\
    \ other.root, 0, sz, l, r));\n    }\n\n    /**\n     * @brief [l, r)\u306E\u533A\
    \u9593\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @param l \u534A\u958B\
    \u533A\u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\
    \u7D42\u7AEF 0<=l<=r<=n\n     * @return S \u7DCF\u7A4D\n     */\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ prod_rec(root, 0, sz, l, r);\n    }\n    /**\n     * @brief \u3059\u3079\u3066\
    \u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n     * @return\
    \ S \u7DCF\u7A4D\n     */\n    S all_prod() const { return pool->val[root]; }\n\
    \n    /**\n     * @brief (r = l or f(prod([l, r))) = true) and (r = n or f(prod([l,\
    \ r+1))) = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\n     * f\u304C\u5358\u8ABF\
    \u306A\u3089\u3001f(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n\
    \     *\n     * @tparam F\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\
    \u59CB 0<=l<=n\n     * @param f \u5224\u5B9A\u95A2\u6570 f(e) = true\n     * @return\
    \ int\n     */\n    template <typename F>\n    int max_right(int l, F f) const\
    \ {\n        assert(f(e()));\n        assert(0 <= l && l <= n);\n        if (l\
    \ == n) return n;\n        S sum = e();\n        int r = max_right_rec(root, 0,\
    \ sz, l, f, sum);\n        return r < n ? r : n;\n    }\n    /**\n     * @brief\
    \ (l = 0 or f(prod([l, r))) = true) and (l = r or f(prod([l-1, r))) = false)\u3068\
    \u306A\u308Bl\u3092\u8FD4\u3059\n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001\
    f(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5C0F\u306El\n     *\n     * @tparam\
    \ F\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n    \
    \ * @param f \u5224\u5B9A\u95A2\u6570 f(e) = true\n     * @return int\n     */\n\
    \    template <typename F>\n    int min_left(int r, F f) const {\n        assert(f(e()));\n\
    \        assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        S sum\
    \ = e();\n        return min_left_rec(root, 0, sz, r, f, sum);\n    }\n\n    /**\n\
    \     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u4E26\u3079\u305F\u5217\
    \u3092\u8FD4\u3059\n     */\n    std::vector<S> to_vector() const {\n        std::vector<S>\
    \ res(n);\n        for (int i = 0; i < n; i++) res[i] = get(i);\n        return\
    \ res;\n    }\n};\n\ntemplate <typename M>\nPersistentSegTree(int, M) -> PersistentSegTree<M>;\n\
    template <typename M>\nPersistentSegTree(std::vector<typename M::S>, M) -> PersistentSegTree<M>;\n"
  dependsOn:
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/data_structures/persistent-segtree.hpp
  requiredBy: []
  timestamp: '2026-10-15 02:28:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/persistent-segtree.test.cpp
  - test/yosupo/rectangle-sum.4.test.cpp
documentation_of: src/data_structures/persistent-segtree.hpp
layout: document
title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

過去の版を残したまま更新できるセグメント木です。`set` は元の版を変えずに新しい版を返し、新しく作るノードは $O(\log n)$ 個です。版のコピーは $O(1)$ です。

```cpp
PersistentSegTree<monoid::Sum<long long>> s0(n);
auto s1 = s0.set(3, 10);     // s0 はそのまま
auto s2 = s1.apply(5, 2);    // s1 もそのまま
s2.prod(0, n);               // 12
s1.prod(0, n);               // 10
auto s3 = s2.copy(s0, 0, 4); // [0, 4) を s0 の値に戻した版

// 版を配列に並べる (矩形和: x 座標の順に点を足していき、2 つの版の差を取る)
std::vector<PersistentSegTree<monoid::Sum<long long>>> seg(N + 1);
seg[0] = PersistentSegTree<monoid::Sum<long long>>(m);
for (int i = 0; i < N; i++) seg[i + 1] = seg[i].apply(y[i], w[i]);
long long s = seg[r].prod(d, u) - seg[l].prod(d, u);
```

`copy(other, l, r)` の `other` は、自身と同じ木 (同じコンストラクタの呼び出しから更新して作った版) でなければなりません。ノードを共有するので、区間の長さによらず $O(\log n)$ です。

同じ木から作った版はノードを共有します。ノードは削除しないので、メモリは更新の回数に比例して増えます。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentSegTree(n, m = M())` | 要素数 `n`、すべて単位元で初期化 (単位元の部分木を共有する) | $O(\log n)$ |
| `PersistentSegTree(v, m = M())` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` / `seg[k]` | `k` 番目の値 | $O(\log n)$ |
| `set(k, x)` | `k` 番目を `x` にした新しい版を返す | $O(\log n)$ |
| `apply(k, x)` | `k` 番目を `op(seg[k], x)` にした新しい版を返す | $O(\log n)$ |
| `copy(other, l, r)` | 区間 $[l, r)$ を `other` の値にした新しい版を返す | $O(\log n)$ |
| `prod(l, r)` | 区間 $[l, r)$ の積 | $O(\log n)$ |
| `all_prod()` | 全体の積 | $O(1)$ |
| `max_right(l, f)` | `f(prod(l, r))` が真となる最大の `r` (`f` は単調) | $O(\log n)$ |
| `min_left(r, f)` | `f(prod(l, r))` が真となる最小の `l` (`f` は単調) | $O(\log n)$ |
| `to_vector()` | すべての要素を並べた `std::vector<S>` | $O(n \log n)$ |
| `os << seg` | 全要素を空白区切りで出力 | $O(n \log n)$ |

## 関連

- 過去の版が要らないなら [セグメント木](segtree.hpp)
- 区間作用も必要なら [永続遅延伝搬セグメント木](persistent-lazy-segtree.hpp)
- 値を持つだけでよいなら [永続配列](persistent-array.hpp)
- 静的な矩形和だけなら [マージソートツリー](merge-sort-tree.hpp)
