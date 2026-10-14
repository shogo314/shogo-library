---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-3-d.test.cpp
    title: test/aoj/dsl-3-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/sliding-window-aggregation.test.cpp
    title: test/unittest/sliding-window-aggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue-operate-all-composite.test.cpp
    title: test/yosupo/queue-operate-all-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Sliding Window Aggregation (\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\
      \u305B\u305F\u30AD\u30E5\u30FC) \u3068\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
    links: []
  bundledCode: "#line 2 \"src/data_structures/sliding-window-aggregation.hpp\"\n\n\
    /**\n * @file sliding-window-aggregation.hpp\n * @brief Sliding Window Aggregation\
    \ (\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u305F\u30AD\u30E5\u30FC) \u3068\u30B9\
    \u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n */\n\n#include <cassert>\n#include <deque>\n\
    #include <functional>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#include <algorithm>\n#include <array>\n#include <cstddef>\n\
    #include <istream>\n#include <limits>\n#include <numeric>\n#include <ostream>\n\
    #include <type_traits>\n#line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief\
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
    \ T) -> Monoid<T, Op>;\n#line 15 \"src/data_structures/sliding-window-aggregation.hpp\"\
    \n\n/**\n * @brief Sliding Window Aggregation (\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\
    \u305B\u305F\u30AD\u30E5\u30FC)\n *\n * \u672B\u5C3E\u3078\u306E\u8FFD\u52A0\u3001\
    \u5148\u982D\u306E\u524A\u9664\u3001\u5168\u4F53\u306E\u7A4D\u3092\u511F\u5374\
    \ O(1) \u3067\u884C\u3046\u3002\u30E2\u30CE\u30A4\u30C9\u306F\u53EF\u63DB\u3067\
    \u306A\u304F\u3066\u3082\u3088\u3044\n * \u4F8B:\n * SlidingWindowAggregation<monoid::Reverse<monoid::Composite<mint>>>\
    \ swag;  // \u5148\u982D\u304B\u3089\u9806\u306B\u9069\u7528\n * swag.push(f);\
    \ swag.pop(); swag.prod();\n *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n\
    \ */\ntemplate <typename M>\nclass SlidingWindowAggregation {\n   public:\n  \
    \  using S = typename M::S;\n\n   private:\n    M m;\n    // \u30AD\u30E5\u30FC\
    \u306E\u524D\u534A\u3092\u30B9\u30BF\u30C3\u30AF front_vals (\u672B\u5C3E\u304C\
    \u30AD\u30E5\u30FC\u306E\u5148\u982D) \u3067\u3001\u5F8C\u534A\u3092 back_vals\
    \ (\u672B\u5C3E\u304C\u30AD\u30E5\u30FC\u306E\u672B\u5C3E) \u3067\u6301\u3064\n\
    \    std::vector<S> front_vals, front_prod;  // front_prod[i] \u306F front_vals[i],\
    \ front_vals[i - 1], ..., front_vals[0] \u306E\u7A4D\n    std::vector<S> back_vals;\n\
    \    S back_prod;  // back_vals \u306E\u5148\u982D\u304B\u3089\u306E\u7A4D\n\n\
    \    S op(const S& x, const S& y) const { return m.op(x, y); }\n    S e() const\
    \ { return m.e(); }\n\n   public:\n    explicit SlidingWindowAggregation(M m =\
    \ M()) : m(std::move(m)), back_prod(this->m.e()) {}\n\n    /**\n     * @brief\
    \ \u8981\u7D20\u6570\n     */\n    int size() const { return front_vals.size()\
    \ + back_vals.size(); }\n    bool empty() const { return size() == 0; }\n\n  \
    \  /**\n     * @brief \u672B\u5C3E\u306B x \u3092\u8FFD\u52A0\u3059\u308B O(1)\n\
    \     */\n    void push(const S& x) {\n        back_vals.push_back(x);\n     \
    \   back_prod = op(back_prod, x);\n    }\n    /**\n     * @brief \u5148\u982D\u306E\
    \u8981\u7D20\u3092\u524A\u9664\u3059\u308B \u511F\u5374 O(1)\n     */\n    void\
    \ pop() {\n        assert(!empty());\n        if (front_vals.empty()) {\n    \
    \        // \u5F8C\u534A\u3092\u3059\u3079\u3066\u524D\u534A\u3078\u79FB\u3059\
    \n            while (!back_vals.empty()) {\n                S x = std::move(back_vals.back());\n\
    \                back_vals.pop_back();\n                front_prod.push_back(front_vals.empty()\
    \ ? x : op(x, front_prod.back()));\n                front_vals.push_back(std::move(x));\n\
    \            }\n            back_prod = e();\n        }\n        front_vals.pop_back();\n\
    \        front_prod.pop_back();\n    }\n    /**\n     * @brief \u5148\u982D\u306E\
    \u8981\u7D20 O(1)\n     */\n    const S& front() const {\n        assert(!empty());\n\
    \        return front_vals.empty() ? back_vals.front() : front_vals.back();\n\
    \    }\n    /**\n     * @brief \u5148\u982D\u304B\u3089\u672B\u5C3E\u307E\u3067\
    \u306E\u7A4D (\u7A7A\u306A\u3089\u5358\u4F4D\u5143) O(1)\n     */\n    S prod()\
    \ const {\n        if (front_vals.empty()) return back_prod;\n        return op(front_prod.back(),\
    \ back_prod);\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u3092\u524A\u9664\u3059\u308B\n     */\n    void clear() {\n        front_vals.clear();\n\
    \        front_prod.clear();\n        back_vals.clear();\n        back_prod =\
    \ e();\n    }\n};\n\ntemplate <typename M>\nSlidingWindowAggregation(M) -> SlidingWindowAggregation<M>;\n\
    \n/**\n * @brief \u9577\u3055 k \u306E\u5404\u533A\u9593 [i, i + k) \u306E\u6700\
    \u5C0F\u5024\u3092\u4E26\u3079\u305F\u3082\u306E (\u9577\u3055 n - k + 1) O(n)\n\
    \ *\n * \u5358\u8ABF\u306A deque \u3092\u4F7F\u3046\n * @param comp \u5927\u5C0F\
    \u306E\u6BD4\u8F03\u3002std::greater<T>() \u3092\u6E21\u3059\u3068\u6700\u5927\
    \u5024\u306B\u306A\u308B\n */\ntemplate <typename T, typename Compare = std::less<T>>\n\
    std::vector<T> sliding_window_min(const std::vector<T>& a, int k, Compare comp\
    \ = Compare()) {\n    int n = a.size();\n    assert(1 <= k && k <= n);\n    std::vector<T>\
    \ res;\n    res.reserve(n - k + 1);\n    // \u7A93\u306E\u4E2D\u3067\u3001\u5F8C\
    \u308D\u306B\u305D\u308C\u4EE5\u4E0B\u306E\u5024\u304C\u306A\u3044\u6DFB\u5B57\
    \u3092\u3001\u5024\u306E\u6607\u9806\u306B\u6301\u3064\n    std::deque<int> dq;\n\
    \    for (int i = 0; i < n; i++) {\n        while (!dq.empty() && !comp(a[dq.back()],\
    \ a[i])) dq.pop_back();\n        dq.push_back(i);\n        if (dq.front() <= i\
    \ - k) dq.pop_front();\n        if (i >= k - 1) res.push_back(a[dq.front()]);\n\
    \    }\n    return res;\n}\n\n/**\n * @brief \u9577\u3055 k \u306E\u5404\u533A\
    \u9593 [i, i + k) \u306E\u6700\u5927\u5024\u3092\u4E26\u3079\u305F\u3082\u306E\
    \ (\u9577\u3055 n - k + 1) O(n)\n */\ntemplate <typename T>\nstd::vector<T> sliding_window_max(const\
    \ std::vector<T>& a, int k) {\n    return sliding_window_min(a, k, std::greater<T>());\n\
    }\n"
  code: "#pragma once\n\n/**\n * @file sliding-window-aggregation.hpp\n * @brief Sliding\
    \ Window Aggregation (\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u305F\u30AD\u30E5\
    \u30FC) \u3068\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n */\n\n#include <cassert>\n\
    #include <deque>\n#include <functional>\n#include <utility>\n#include <vector>\n\
    \n#include \"../algebra/monoid.hpp\"\n\n/**\n * @brief Sliding Window Aggregation\
    \ (\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u305F\u30AD\u30E5\u30FC)\n *\n *\
    \ \u672B\u5C3E\u3078\u306E\u8FFD\u52A0\u3001\u5148\u982D\u306E\u524A\u9664\u3001\
    \u5168\u4F53\u306E\u7A4D\u3092\u511F\u5374 O(1) \u3067\u884C\u3046\u3002\u30E2\
    \u30CE\u30A4\u30C9\u306F\u53EF\u63DB\u3067\u306A\u304F\u3066\u3082\u3088\u3044\
    \n * \u4F8B:\n * SlidingWindowAggregation<monoid::Reverse<monoid::Composite<mint>>>\
    \ swag;  // \u5148\u982D\u304B\u3089\u9806\u306B\u9069\u7528\n * swag.push(f);\
    \ swag.pop(); swag.prod();\n *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n\
    \ */\ntemplate <typename M>\nclass SlidingWindowAggregation {\n   public:\n  \
    \  using S = typename M::S;\n\n   private:\n    M m;\n    // \u30AD\u30E5\u30FC\
    \u306E\u524D\u534A\u3092\u30B9\u30BF\u30C3\u30AF front_vals (\u672B\u5C3E\u304C\
    \u30AD\u30E5\u30FC\u306E\u5148\u982D) \u3067\u3001\u5F8C\u534A\u3092 back_vals\
    \ (\u672B\u5C3E\u304C\u30AD\u30E5\u30FC\u306E\u672B\u5C3E) \u3067\u6301\u3064\n\
    \    std::vector<S> front_vals, front_prod;  // front_prod[i] \u306F front_vals[i],\
    \ front_vals[i - 1], ..., front_vals[0] \u306E\u7A4D\n    std::vector<S> back_vals;\n\
    \    S back_prod;  // back_vals \u306E\u5148\u982D\u304B\u3089\u306E\u7A4D\n\n\
    \    S op(const S& x, const S& y) const { return m.op(x, y); }\n    S e() const\
    \ { return m.e(); }\n\n   public:\n    explicit SlidingWindowAggregation(M m =\
    \ M()) : m(std::move(m)), back_prod(this->m.e()) {}\n\n    /**\n     * @brief\
    \ \u8981\u7D20\u6570\n     */\n    int size() const { return front_vals.size()\
    \ + back_vals.size(); }\n    bool empty() const { return size() == 0; }\n\n  \
    \  /**\n     * @brief \u672B\u5C3E\u306B x \u3092\u8FFD\u52A0\u3059\u308B O(1)\n\
    \     */\n    void push(const S& x) {\n        back_vals.push_back(x);\n     \
    \   back_prod = op(back_prod, x);\n    }\n    /**\n     * @brief \u5148\u982D\u306E\
    \u8981\u7D20\u3092\u524A\u9664\u3059\u308B \u511F\u5374 O(1)\n     */\n    void\
    \ pop() {\n        assert(!empty());\n        if (front_vals.empty()) {\n    \
    \        // \u5F8C\u534A\u3092\u3059\u3079\u3066\u524D\u534A\u3078\u79FB\u3059\
    \n            while (!back_vals.empty()) {\n                S x = std::move(back_vals.back());\n\
    \                back_vals.pop_back();\n                front_prod.push_back(front_vals.empty()\
    \ ? x : op(x, front_prod.back()));\n                front_vals.push_back(std::move(x));\n\
    \            }\n            back_prod = e();\n        }\n        front_vals.pop_back();\n\
    \        front_prod.pop_back();\n    }\n    /**\n     * @brief \u5148\u982D\u306E\
    \u8981\u7D20 O(1)\n     */\n    const S& front() const {\n        assert(!empty());\n\
    \        return front_vals.empty() ? back_vals.front() : front_vals.back();\n\
    \    }\n    /**\n     * @brief \u5148\u982D\u304B\u3089\u672B\u5C3E\u307E\u3067\
    \u306E\u7A4D (\u7A7A\u306A\u3089\u5358\u4F4D\u5143) O(1)\n     */\n    S prod()\
    \ const {\n        if (front_vals.empty()) return back_prod;\n        return op(front_prod.back(),\
    \ back_prod);\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u3092\u524A\u9664\u3059\u308B\n     */\n    void clear() {\n        front_vals.clear();\n\
    \        front_prod.clear();\n        back_vals.clear();\n        back_prod =\
    \ e();\n    }\n};\n\ntemplate <typename M>\nSlidingWindowAggregation(M) -> SlidingWindowAggregation<M>;\n\
    \n/**\n * @brief \u9577\u3055 k \u306E\u5404\u533A\u9593 [i, i + k) \u306E\u6700\
    \u5C0F\u5024\u3092\u4E26\u3079\u305F\u3082\u306E (\u9577\u3055 n - k + 1) O(n)\n\
    \ *\n * \u5358\u8ABF\u306A deque \u3092\u4F7F\u3046\n * @param comp \u5927\u5C0F\
    \u306E\u6BD4\u8F03\u3002std::greater<T>() \u3092\u6E21\u3059\u3068\u6700\u5927\
    \u5024\u306B\u306A\u308B\n */\ntemplate <typename T, typename Compare = std::less<T>>\n\
    std::vector<T> sliding_window_min(const std::vector<T>& a, int k, Compare comp\
    \ = Compare()) {\n    int n = a.size();\n    assert(1 <= k && k <= n);\n    std::vector<T>\
    \ res;\n    res.reserve(n - k + 1);\n    // \u7A93\u306E\u4E2D\u3067\u3001\u5F8C\
    \u308D\u306B\u305D\u308C\u4EE5\u4E0B\u306E\u5024\u304C\u306A\u3044\u6DFB\u5B57\
    \u3092\u3001\u5024\u306E\u6607\u9806\u306B\u6301\u3064\n    std::deque<int> dq;\n\
    \    for (int i = 0; i < n; i++) {\n        while (!dq.empty() && !comp(a[dq.back()],\
    \ a[i])) dq.pop_back();\n        dq.push_back(i);\n        if (dq.front() <= i\
    \ - k) dq.pop_front();\n        if (i >= k - 1) res.push_back(a[dq.front()]);\n\
    \    }\n    return res;\n}\n\n/**\n * @brief \u9577\u3055 k \u306E\u5404\u533A\
    \u9593 [i, i + k) \u306E\u6700\u5927\u5024\u3092\u4E26\u3079\u305F\u3082\u306E\
    \ (\u9577\u3055 n - k + 1) O(n)\n */\ntemplate <typename T>\nstd::vector<T> sliding_window_max(const\
    \ std::vector<T>& a, int k) {\n    return sliding_window_min(a, k, std::greater<T>());\n\
    }\n"
  dependsOn:
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/data_structures/sliding-window-aggregation.hpp
  requiredBy: []
  timestamp: '2026-10-14 16:37:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/sliding-window-aggregation.test.cpp
  - test/aoj/dsl-3-d.test.cpp
  - test/yosupo/queue-operate-all-composite.test.cpp
documentation_of: src/data_structures/sliding-window-aggregation.hpp
layout: document
title: "Sliding Window Aggregation \u3068\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---

## Sliding Window Aggregation

モノイド ([algebra/monoid.hpp](../algebra/monoid.hpp)) を乗せたキューです。末尾への追加、先頭の削除、全体の積の取得を償却 $O(1)$ で行います。モノイドは可換でなくてもよく、逆元もいりません。

```cpp
// Composite の積は f∘g なので、先頭から順に適用するには Reverse で積の順序を逆にする
SlidingWindowAggregation<monoid::Reverse<monoid::Composite<mint>>> swag;
swag.push(Affine<mint>{2, 3});
swag.push(Affine<mint>{1, 5});
mint y = swag.prod()(x);  // 先頭から順に適用した結果 (2x + 3) + 5
swag.pop();               // 先頭を削除
SlidingWindowAggregation swag2(Monoid([](int a, int b) { return std::min(a, b); }, INF));  // ラムダ式から作る
```

キューを 2 つのスタックで表し、前半のスタックには先頭側からの積を持たせます。前半が空のときに `pop` すると、後半をまとめて前半へ移します。

### メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SlidingWindowAggregation<M>()` | 空のキュー | $O(1)$ |
| `push(x)` | 末尾に `x` を追加 | $O(1)$ |
| `pop()` | 先頭を削除 | 償却 $O(1)$ |
| `front()` | 先頭の要素 | $O(1)$ |
| `prod()` | 先頭から末尾までの積 (空なら単位元) | $O(1)$ |
| `size()`、`empty()` | 要素数、空か | $O(1)$ |
| `clear()` | すべて削除 | $O(n)$ |

## スライド最小値

配列 `a` の長さ `k` の各区間 $[i, i + k)$ の最小値・最大値を、単調な deque で求めます。返り値の長さは $n - k + 1$ です ($1 \le k \le n$)。

```cpp
std::vector<int> a = {1, 7, 7, 4, 8, 1, 6};
auto mn = sliding_window_min(a, 3);  // {1, 4, 4, 1, 1}
auto mx = sliding_window_max(a, 3);  // {7, 7, 8, 8, 8}
```

### 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sliding_window_min(a, k, comp = std::less<T>())` | 各区間の最小値。`comp` を渡すとその順序での最小値 | $O(n)$ |
| `sliding_window_max(a, k)` | 各区間の最大値 | $O(n)$ |

## 関連

- 区間が自由に動くなら [Sparse Table](sparse-table.hpp) や [セグメント木](segtree.hpp)
