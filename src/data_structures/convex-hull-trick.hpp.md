---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/convex-hull-trick.test.cpp
    title: test/unittest/data_structures/convex-hull-trick.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/line-add-get-min.1.test.cpp
    title: test/yosupo/data_structure/line-add-get-min.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/line-add-get-min.2.test.cpp
    title: test/yosupo/data_structure/line-add-get-min.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/segment-add-get-min.test.cpp
    title: test/yosupo/data_structure/segment-add-get-min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Convex Hull Trick
    links: []
  bundledCode: "#line 2 \"src/data_structures/convex-hull-trick.hpp\"\n\n/**\n * @file\
    \ convex-hull-trick.hpp\n * @brief Convex Hull Trick\n *\n * \u4E00\u6B21\u95A2\
    \u6570\u3067\u8868\u3055\u308C\u308B\u76F4\u7DDA\u307E\u305F\u306F\u7DDA\u5206\
    \u306E\u96C6\u5408\u3092\u7BA1\u7406\u3057\u3001\u3042\u308Bx\u306B\u5BFE\u3059\
    \u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n */\n\n#include <cassert>\n\
    #include <cstddef>\n#include <optional>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include\
    \ <functional>\n#include <iterator>\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\
    \n\nnamespace internal_traits {\nusing std::begin, std::end;\n\ntemplate <class\
    \ T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate <class\
    \ T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace internal_traits\n\
    \ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\
    \n#define HAS_METHOD(func_name)                                              \
    \                \\\n    namespace internal_traits {                         \
    \                                   \\\n    template <class T, class = void> \
    \                                                      \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : internal_traits::has_##func_name##_impl<T>::type {};          \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace internal_traits {     \
    \                                                                           \\\
    \n    template <class T, typename U, class = void>                           \
    \                                    \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                                        \\\n    template\
    \ <class T, typename U>                                                      \
    \                       \\\n    struct has_##func_name##_impl<T, U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>>\
    \ \\\n        : std::true_type {};                                           \
    \                                        \\\n    }                           \
    \                                                                            \
    \   \\\n    template <class T, typename U>                                   \
    \                                          \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \nnamespace internal_traits {\n// \u5C04\u5F71 (proj) \u306E\u65E2\u5B9A\u5024\
    \n#if __cplusplus >= 202002L\nusing identity = std::identity;\n#else\nstruct identity\
    \ {\n    using is_transparent = void;\n    template <class T>\n    constexpr T&&\
    \ operator()(T&& x) const noexcept {\n        return std::forward<T>(x);\n   \
    \ }\n};\n#endif\n}  // namespace internal_traits\n\ntemplate <class C>\nusing\
    \ mem_value_type = typename C::value_type;\ntemplate <class C>\nusing mem_difference_type\
    \ = typename C::difference_type;\n\nnamespace internal_traits {\ntemplate <class\
    \ T, class = void>\nstruct is_sorted_container_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_sorted_container_impl<std::set<T>> : std::true_type {};\n\
    template <class T>\nstruct is_sorted_container_impl<std::multiset<T>> : std::true_type\
    \ {};\n}  // namespace internal_traits\ntemplate <class T>\nstruct is_sorted_container\
    \ : internal_traits::is_sorted_container_impl<T>::type {};\ntemplate <class T>\n\
    inline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 18 \"src/data_structures/convex-hull-trick.hpp\"\n\n/**\n * @brief \u8FFD\
    \u52A0\u3055\u308C\u308B\u50BE\u304D\u304C\u5358\u8ABF\u3068\u306F\u9650\u3089\
    \u306A\u3044\u5834\u5408\u306EConvex Hull Trick\n *\n * @tparam T \u5024\u306E\
    \u578B\n */\ntemplate <typename T, ENABLE_IF_T(std::is_scalar_v<T>)>\nclass LiChaoTree\
    \ {\n    long long n, sz;\n    int height;\n    std::vector<T> xs, as, bs;\n \
    \   std::vector<bool> exist;  // \u30CE\u30FC\u30C9\u304C\u76F4\u7DDA\u3092\u6301\
    \u3064\u304B\n\n    void update(T a, T b, long long k, int h) {\n        long\
    \ long l = (k << h) & (sz - 1);\n        long long r = l + (1LL << h);\n\n   \
    \     while (1) {\n            if (!exist[k]) {\n                as[k] = a, bs[k]\
    \ = b, exist[k] = true;\n                return;\n            }\n            long\
    \ long m = (l + r) >> 1;\n            T xl = xs[l], xm = xs[m];\n            bool\
    \ l_update = a * xl + b < as[k] * xl + bs[k];\n            bool m_update = a *\
    \ xm + b < as[k] * xm + bs[k];\n\n            if (m_update) {\n              \
    \  std::swap(as[k], a);\n                std::swap(bs[k], b);\n            }\n\
    \            if (h == 0) break;\n            if (l_update != m_update) {\n   \
    \             k = k * 2;\n                r = m;\n            } else {\n     \
    \           k = k * 2 + 1;\n                l = m;\n            }\n          \
    \  h--;\n        }\n    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n     *\n     * @param xs \u6700\u5C0F\u5024\u30AF\u30A8\
    \u30EA\u306Ex\u5EA7\u6A19\u3084\u7DDA\u5206\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\
    \u4E21\u7AEF\u306Ex\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u3066\u30BD\u30FC\
    \u30C8\u3057\u305F\u914D\u5217\n     */\n    explicit LiChaoTree(const std::vector<T>&\
    \ xs) : n(xs.size()), xs(xs) {\n        assert(!xs.empty());\n        sz = 1,\
    \ height = 0;\n        while (sz < static_cast<long long>(xs.size())) {\n    \
    \        sz <<= 1;\n            height++;\n        }\n        this->xs.resize(sz,\
    \ xs.back());\n        as.assign(sz * 2, 0);\n        bs.assign(sz * 2, 0);\n\
    \        exist.assign(sz * 2, false);\n    }\n\n    /**\n     * @brief \u76F4\u7DDA\
    y=ax+b\u306E\u8FFD\u52A0\n     *\n     * @param a \u50BE\u304D\n     * @param\
    \ b \u5207\u7247\n     */\n    void add_line(T a, T b) {\n        update(a, b,\
    \ 1, height);\n    }\n    /**\n     * @brief \u7DDA\u5206y=ax+b , x\u2208[xs[l],xs[r])\u306E\
    \u8FFD\u52A0\n     *\n     * @param a \u50BE\u304D\n     * @param b \u5207\u7247\
    \n     * @param l \u5DE6\u7AEF(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\n\
    \     * @param r x\u306E\u4E0A\u9650(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    )\n     */\n    void add_segment(T a, T b, long long l, long long r) {\n     \
    \   assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n       \
    \ l += sz, r += sz;\n        int h = 0;\n        while (l < r) {\n           \
    \ if (l & 1) update(a, b, l++, h);\n            if (r & 1) update(a, b, --r, h);\n\
    \            l >>= 1, r >>= 1, h++;\n        }\n    }\n\n    /**\n     * @brief\
    \ x=xs[i]\u306B\u304A\u3051\u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n\
    \     *\n     * @param i x\u5EA7\u6A19(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    )\n     * @return std::optional<T> \u6700\u5C0F\u5024\u3002\u76F4\u7DDA\u304C\u306A\
    \u3051\u308C\u3070 std::nullopt\n     */\n    std::optional<T> get_min(long long\
    \ i) const {\n        assert(0 <= i && i < n);\n        T x = xs[i];\n       \
    \ std::optional<T> res;\n        for (long long k = i + sz; k >= 1; k >>= 1) {\n\
    \            if (!exist[k]) continue;\n            T tmp = as[k] * x + bs[k];\n\
    \            if (!res || tmp < *res) res = tmp;\n        }\n        return res;\n\
    \    }\n};\n\n/**\n * @brief x \u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u306A\
    \u3044 Li Chao Tree (x \u306F [lo, hi) \u306E\u6574\u6570)\n *\n * \u5FC5\u8981\
    \u306B\u306A\u3063\u305F\u9802\u70B9\u3060\u3051\u3092\u4F5C\u308B\u306E\u3067\
    \u3001x \u306E\u7BC4\u56F2\u304C 10^9 \u7A0B\u5EA6\u3067\u3082\u4F7F\u3048\u308B\
    \n * \u9802\u70B9\u306F\u3001\u76F4\u7DDA 1 \u672C\u306B\u3064\u304D 1 \u500B\u4EE5\
    \u4E0B\u3001\u7DDA\u5206 1 \u672C\u306B\u3064\u304D 2 log (hi - lo) \u500B\u7A0B\
    \u5EA6\u5897\u3048\u308B\u3002\u7DDA\u5206\u3092\u4F55\u5341\u4E07\u672C\u3082\
    \u8DB3\u3059\u306A\u3089\u3001x \u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3059\u308B\
    \ LiChaoTree \u306E\u65B9\u304C\u901F\u3044\n * \u4F8B:\n * DynamicLiChaoTree<long\
    \ long> cht(-1000000000, 1000000001);\n * cht.add_line(2, 3); cht.add_segment(-1,\
    \ 0, 0, 10);  // y = -x (x \u2208 [0, 10))\n * cht.get_min(5);  // -5\n *\n *\
    \ @tparam T \u5024\u306E\u578B (a x + b \u304C\u3042\u3075\u308C\u306A\u3044\u3053\
    \u3068)\n */\ntemplate <typename T>\nclass DynamicLiChaoTree {\n    struct Node\
    \ {\n        T a, b;\n        bool exist = false;\n        int left = -1, right\
    \ = -1;\n    };\n    long long lo, hi;\n    std::vector<Node> nodes;\n\n    static\
    \ T eval(T a, T b, long long x) { return a * static_cast<T>(x) + b; }\n    int\
    \ child(int k, bool right) {\n        int& c = right ? nodes[k].right : nodes[k].left;\n\
    \        if (c == -1) {\n            // push_back \u3067 nodes \u304C\u4F38\u3073\
    \u308B\u3068\u53C2\u7167 c \u304C\u7121\u52B9\u306B\u306A\u308B\u306E\u3067\u3001\
    \u5148\u306B\u756A\u53F7\u3092\u6C7A\u3081\u3066\u304A\u304F\n            int\
    \ id = nodes.size();\n            c = id;\n            nodes.emplace_back();\n\
    \            return id;\n        }\n        return c;\n    }\n    // \u9802\u70B9\
    \ k (\u533A\u9593 [l, r)) \u306B\u76F4\u7DDA\u3092\u5165\u308C\u308B\u3002\u4ECA\
    \u306E\u76F4\u7DDA\u3068\u6BD4\u3079\u3066\u3001\u533A\u9593\u306E\u4E2D\u70B9\
    \u3067\u826F\u3044\u65B9\u3092\u6B8B\u3057\u3001\u60AA\u3044\u65B9\u3092\u7247\
    \u5074\u306E\u5B50\u3078\u9001\u308B\n    void update(int k, long long l, long\
    \ long r, T a, T b) {\n        while (true) {\n            Node& nd = nodes[k];\n\
    \            if (!nd.exist) {\n                nd.a = a, nd.b = b, nd.exist =\
    \ true;\n                return;\n            }\n            const long long m\
    \ = l + (r - l) / 2;\n            bool l_better = eval(a, b, l) < eval(nd.a, nd.b,\
    \ l);\n            bool m_better = eval(a, b, m) < eval(nd.a, nd.b, m);\n    \
    \        if (m_better) std::swap(nd.a, a), std::swap(nd.b, b);\n            if\
    \ (r - l == 1) return;\n            // \u60AA\u3044\u65B9\u306E\u76F4\u7DDA\u304C\
    \u826F\u304F\u306A\u308A\u3046\u308B\u306E\u306F\u3001\u5DE6\u7AEF\u3067\u826F\
    \u304B\u3063\u305F\u306A\u3089 [l, m)\u3001\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 [m, r)\n            if (l_better != m_better) {\n                k = child(k,\
    \ false), r = m;\n            } else {\n                k = child(k, true), l\
    \ = m;\n            }\n        }\n    }\n    // \u9802\u70B9 k (\u533A\u9593 [l,\
    \ r)\u3001[sl, sr) \u3068\u91CD\u306A\u308B) \u306B\u7DDA\u5206\u3092\u5165\u308C\
    \u308B\u3002\u91CD\u306A\u3089\u306A\u3044\u5074\u306E\u5B50\u306F\u4F5C\u3089\
    \u306A\u3044\n    void update_segment(int k, long long l, long long r, T a, T\
    \ b, long long sl, long long sr) {\n        if (sl <= l && r <= sr) {\n      \
    \      update(k, l, r, a, b);\n            return;\n        }\n        const long\
    \ long m = l + (r - l) / 2;\n        if (sl < m) update_segment(child(k, false),\
    \ l, m, a, b, sl, sr);\n        if (m < sr) update_segment(child(k, true), m,\
    \ r, a, b, sl, sr);\n    }\n\n   public:\n    /**\n     * @brief x \u304C [lo,\
    \ hi) \u306E\u6574\u6570\u3092\u3068\u308B\u3001\u76F4\u7DDA\u306E\u306A\u3044\
    \u6728\u3092\u4F5C\u308B\n     */\n    DynamicLiChaoTree(long long lo, long long\
    \ hi) : lo(lo), hi(hi), nodes(1) { assert(lo < hi); }\n\n    /**\n     * @brief\
    \ \u76F4\u7DDA y = a x + b \u3092\u8FFD\u52A0\u3059\u308B O(log (hi - lo))\n \
    \    */\n    void add_line(T a, T b) { update(0, lo, hi, a, b); }\n    /**\n \
    \    * @brief \u7DDA\u5206 y = a x + b (x \u2208 [l, r)) \u3092\u8FFD\u52A0\u3059\
    \u308B O(log^2 (hi - lo))\n     */\n    void add_segment(T a, T b, long long l,\
    \ long long r) {\n        assert(lo <= l && l <= r && r <= hi);\n        if (l\
    \ < r) update_segment(0, lo, hi, a, b, l, r);\n    }\n    /**\n     * @brief x\
    \ \u3067\u306E\u6700\u5C0F\u5024\u3002x \u3092\u542B\u3080\u76F4\u7DDA\u30FB\u7DDA\
    \u5206\u304C\u306A\u3051\u308C\u3070 std::nullopt O(log (hi - lo))\n     */\n\
    \    std::optional<T> get_min(long long x) const {\n        assert(lo <= x &&\
    \ x < hi);\n        std::optional<T> res;\n        long long l = lo, r = hi;\n\
    \        for (int k = 0; k != -1;) {\n            const Node& nd = nodes[k];\n\
    \            if (nd.exist) {\n                T v = eval(nd.a, nd.b, x);\n   \
    \             if (!res || v < *res) res = v;\n            }\n            const\
    \ long long m = l + (r - l) / 2;\n            if (x < m) {\n                k\
    \ = nd.left, r = m;\n            } else {\n                k = nd.right, l = m;\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file convex-hull-trick.hpp\n * @brief Convex Hull\
    \ Trick\n *\n * \u4E00\u6B21\u95A2\u6570\u3067\u8868\u3055\u308C\u308B\u76F4\u7DDA\
    \u307E\u305F\u306F\u7DDA\u5206\u306E\u96C6\u5408\u3092\u7BA1\u7406\u3057\u3001\
    \u3042\u308Bx\u306B\u5BFE\u3059\u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\
    \n */\n\n#include <cassert>\n#include <cstddef>\n#include <optional>\n#include\
    \ <type_traits>\n#include <utility>\n#include <vector>\n\n#include \"../utility/traits.hpp\"\
    \n\n/**\n * @brief \u8FFD\u52A0\u3055\u308C\u308B\u50BE\u304D\u304C\u5358\u8ABF\
    \u3068\u306F\u9650\u3089\u306A\u3044\u5834\u5408\u306EConvex Hull Trick\n *\n\
    \ * @tparam T \u5024\u306E\u578B\n */\ntemplate <typename T, ENABLE_IF_T(std::is_scalar_v<T>)>\n\
    class LiChaoTree {\n    long long n, sz;\n    int height;\n    std::vector<T>\
    \ xs, as, bs;\n    std::vector<bool> exist;  // \u30CE\u30FC\u30C9\u304C\u76F4\
    \u7DDA\u3092\u6301\u3064\u304B\n\n    void update(T a, T b, long long k, int h)\
    \ {\n        long long l = (k << h) & (sz - 1);\n        long long r = l + (1LL\
    \ << h);\n\n        while (1) {\n            if (!exist[k]) {\n              \
    \  as[k] = a, bs[k] = b, exist[k] = true;\n                return;\n         \
    \   }\n            long long m = (l + r) >> 1;\n            T xl = xs[l], xm =\
    \ xs[m];\n            bool l_update = a * xl + b < as[k] * xl + bs[k];\n     \
    \       bool m_update = a * xm + b < as[k] * xm + bs[k];\n\n            if (m_update)\
    \ {\n                std::swap(as[k], a);\n                std::swap(bs[k], b);\n\
    \            }\n            if (h == 0) break;\n            if (l_update != m_update)\
    \ {\n                k = k * 2;\n                r = m;\n            } else {\n\
    \                k = k * 2 + 1;\n                l = m;\n            }\n     \
    \       h--;\n        }\n    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param xs \u6700\u5C0F\u5024\u30AF\
    \u30A8\u30EA\u306Ex\u5EA7\u6A19\u3084\u7DDA\u5206\u8FFD\u52A0\u30AF\u30A8\u30EA\
    \u306E\u4E21\u7AEF\u306Ex\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u3066\u30BD\
    \u30FC\u30C8\u3057\u305F\u914D\u5217\n     */\n    explicit LiChaoTree(const std::vector<T>&\
    \ xs) : n(xs.size()), xs(xs) {\n        assert(!xs.empty());\n        sz = 1,\
    \ height = 0;\n        while (sz < static_cast<long long>(xs.size())) {\n    \
    \        sz <<= 1;\n            height++;\n        }\n        this->xs.resize(sz,\
    \ xs.back());\n        as.assign(sz * 2, 0);\n        bs.assign(sz * 2, 0);\n\
    \        exist.assign(sz * 2, false);\n    }\n\n    /**\n     * @brief \u76F4\u7DDA\
    y=ax+b\u306E\u8FFD\u52A0\n     *\n     * @param a \u50BE\u304D\n     * @param\
    \ b \u5207\u7247\n     */\n    void add_line(T a, T b) {\n        update(a, b,\
    \ 1, height);\n    }\n    /**\n     * @brief \u7DDA\u5206y=ax+b , x\u2208[xs[l],xs[r])\u306E\
    \u8FFD\u52A0\n     *\n     * @param a \u50BE\u304D\n     * @param b \u5207\u7247\
    \n     * @param l \u5DE6\u7AEF(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\n\
    \     * @param r x\u306E\u4E0A\u9650(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    )\n     */\n    void add_segment(T a, T b, long long l, long long r) {\n     \
    \   assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n       \
    \ l += sz, r += sz;\n        int h = 0;\n        while (l < r) {\n           \
    \ if (l & 1) update(a, b, l++, h);\n            if (r & 1) update(a, b, --r, h);\n\
    \            l >>= 1, r >>= 1, h++;\n        }\n    }\n\n    /**\n     * @brief\
    \ x=xs[i]\u306B\u304A\u3051\u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n\
    \     *\n     * @param i x\u5EA7\u6A19(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    )\n     * @return std::optional<T> \u6700\u5C0F\u5024\u3002\u76F4\u7DDA\u304C\u306A\
    \u3051\u308C\u3070 std::nullopt\n     */\n    std::optional<T> get_min(long long\
    \ i) const {\n        assert(0 <= i && i < n);\n        T x = xs[i];\n       \
    \ std::optional<T> res;\n        for (long long k = i + sz; k >= 1; k >>= 1) {\n\
    \            if (!exist[k]) continue;\n            T tmp = as[k] * x + bs[k];\n\
    \            if (!res || tmp < *res) res = tmp;\n        }\n        return res;\n\
    \    }\n};\n\n/**\n * @brief x \u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u306A\
    \u3044 Li Chao Tree (x \u306F [lo, hi) \u306E\u6574\u6570)\n *\n * \u5FC5\u8981\
    \u306B\u306A\u3063\u305F\u9802\u70B9\u3060\u3051\u3092\u4F5C\u308B\u306E\u3067\
    \u3001x \u306E\u7BC4\u56F2\u304C 10^9 \u7A0B\u5EA6\u3067\u3082\u4F7F\u3048\u308B\
    \n * \u9802\u70B9\u306F\u3001\u76F4\u7DDA 1 \u672C\u306B\u3064\u304D 1 \u500B\u4EE5\
    \u4E0B\u3001\u7DDA\u5206 1 \u672C\u306B\u3064\u304D 2 log (hi - lo) \u500B\u7A0B\
    \u5EA6\u5897\u3048\u308B\u3002\u7DDA\u5206\u3092\u4F55\u5341\u4E07\u672C\u3082\
    \u8DB3\u3059\u306A\u3089\u3001x \u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3059\u308B\
    \ LiChaoTree \u306E\u65B9\u304C\u901F\u3044\n * \u4F8B:\n * DynamicLiChaoTree<long\
    \ long> cht(-1000000000, 1000000001);\n * cht.add_line(2, 3); cht.add_segment(-1,\
    \ 0, 0, 10);  // y = -x (x \u2208 [0, 10))\n * cht.get_min(5);  // -5\n *\n *\
    \ @tparam T \u5024\u306E\u578B (a x + b \u304C\u3042\u3075\u308C\u306A\u3044\u3053\
    \u3068)\n */\ntemplate <typename T>\nclass DynamicLiChaoTree {\n    struct Node\
    \ {\n        T a, b;\n        bool exist = false;\n        int left = -1, right\
    \ = -1;\n    };\n    long long lo, hi;\n    std::vector<Node> nodes;\n\n    static\
    \ T eval(T a, T b, long long x) { return a * static_cast<T>(x) + b; }\n    int\
    \ child(int k, bool right) {\n        int& c = right ? nodes[k].right : nodes[k].left;\n\
    \        if (c == -1) {\n            // push_back \u3067 nodes \u304C\u4F38\u3073\
    \u308B\u3068\u53C2\u7167 c \u304C\u7121\u52B9\u306B\u306A\u308B\u306E\u3067\u3001\
    \u5148\u306B\u756A\u53F7\u3092\u6C7A\u3081\u3066\u304A\u304F\n            int\
    \ id = nodes.size();\n            c = id;\n            nodes.emplace_back();\n\
    \            return id;\n        }\n        return c;\n    }\n    // \u9802\u70B9\
    \ k (\u533A\u9593 [l, r)) \u306B\u76F4\u7DDA\u3092\u5165\u308C\u308B\u3002\u4ECA\
    \u306E\u76F4\u7DDA\u3068\u6BD4\u3079\u3066\u3001\u533A\u9593\u306E\u4E2D\u70B9\
    \u3067\u826F\u3044\u65B9\u3092\u6B8B\u3057\u3001\u60AA\u3044\u65B9\u3092\u7247\
    \u5074\u306E\u5B50\u3078\u9001\u308B\n    void update(int k, long long l, long\
    \ long r, T a, T b) {\n        while (true) {\n            Node& nd = nodes[k];\n\
    \            if (!nd.exist) {\n                nd.a = a, nd.b = b, nd.exist =\
    \ true;\n                return;\n            }\n            const long long m\
    \ = l + (r - l) / 2;\n            bool l_better = eval(a, b, l) < eval(nd.a, nd.b,\
    \ l);\n            bool m_better = eval(a, b, m) < eval(nd.a, nd.b, m);\n    \
    \        if (m_better) std::swap(nd.a, a), std::swap(nd.b, b);\n            if\
    \ (r - l == 1) return;\n            // \u60AA\u3044\u65B9\u306E\u76F4\u7DDA\u304C\
    \u826F\u304F\u306A\u308A\u3046\u308B\u306E\u306F\u3001\u5DE6\u7AEF\u3067\u826F\
    \u304B\u3063\u305F\u306A\u3089 [l, m)\u3001\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 [m, r)\n            if (l_better != m_better) {\n                k = child(k,\
    \ false), r = m;\n            } else {\n                k = child(k, true), l\
    \ = m;\n            }\n        }\n    }\n    // \u9802\u70B9 k (\u533A\u9593 [l,\
    \ r)\u3001[sl, sr) \u3068\u91CD\u306A\u308B) \u306B\u7DDA\u5206\u3092\u5165\u308C\
    \u308B\u3002\u91CD\u306A\u3089\u306A\u3044\u5074\u306E\u5B50\u306F\u4F5C\u3089\
    \u306A\u3044\n    void update_segment(int k, long long l, long long r, T a, T\
    \ b, long long sl, long long sr) {\n        if (sl <= l && r <= sr) {\n      \
    \      update(k, l, r, a, b);\n            return;\n        }\n        const long\
    \ long m = l + (r - l) / 2;\n        if (sl < m) update_segment(child(k, false),\
    \ l, m, a, b, sl, sr);\n        if (m < sr) update_segment(child(k, true), m,\
    \ r, a, b, sl, sr);\n    }\n\n   public:\n    /**\n     * @brief x \u304C [lo,\
    \ hi) \u306E\u6574\u6570\u3092\u3068\u308B\u3001\u76F4\u7DDA\u306E\u306A\u3044\
    \u6728\u3092\u4F5C\u308B\n     */\n    DynamicLiChaoTree(long long lo, long long\
    \ hi) : lo(lo), hi(hi), nodes(1) { assert(lo < hi); }\n\n    /**\n     * @brief\
    \ \u76F4\u7DDA y = a x + b \u3092\u8FFD\u52A0\u3059\u308B O(log (hi - lo))\n \
    \    */\n    void add_line(T a, T b) { update(0, lo, hi, a, b); }\n    /**\n \
    \    * @brief \u7DDA\u5206 y = a x + b (x \u2208 [l, r)) \u3092\u8FFD\u52A0\u3059\
    \u308B O(log^2 (hi - lo))\n     */\n    void add_segment(T a, T b, long long l,\
    \ long long r) {\n        assert(lo <= l && l <= r && r <= hi);\n        if (l\
    \ < r) update_segment(0, lo, hi, a, b, l, r);\n    }\n    /**\n     * @brief x\
    \ \u3067\u306E\u6700\u5C0F\u5024\u3002x \u3092\u542B\u3080\u76F4\u7DDA\u30FB\u7DDA\
    \u5206\u304C\u306A\u3051\u308C\u3070 std::nullopt O(log (hi - lo))\n     */\n\
    \    std::optional<T> get_min(long long x) const {\n        assert(lo <= x &&\
    \ x < hi);\n        std::optional<T> res;\n        long long l = lo, r = hi;\n\
    \        for (int k = 0; k != -1;) {\n            const Node& nd = nodes[k];\n\
    \            if (nd.exist) {\n                T v = eval(nd.a, nd.b, x);\n   \
    \             if (!res || v < *res) res = v;\n            }\n            const\
    \ long long m = l + (r - l) / 2;\n            if (x < m) {\n                k\
    \ = nd.left, r = m;\n            } else {\n                k = nd.right, l = m;\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  dependsOn:
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/data_structures/convex-hull-trick.hpp
  requiredBy: []
  timestamp: '2026-10-31 05:46:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/convex-hull-trick.test.cpp
  - test/yosupo/data_structure/segment-add-get-min.test.cpp
  - test/yosupo/data_structure/line-add-get-min.1.test.cpp
  - test/yosupo/data_structure/line-add-get-min.2.test.cpp
documentation_of: src/data_structures/convex-hull-trick.hpp
layout: document
title: Convex Hull Trick
---

直線・線分を追加し、ある $x$ での最小値を求める Li Chao Tree `LiChaoTree<T>` です。追加する傾きは単調でなくてもかまいません。

使う $x$ 座標 (最小値を求める $x$ と、線分の両端) を先読みしてソートした配列を渡し、以降は $x$ をその配列の添字で指定します。

```cpp
std::vector<long long> xs = {-2, 0, 1, 5};
LiChaoTree<long long> cht(xs);
cht.add_line(1, 0);             // y = x
cht.add_segment(-1, 3, 1, 3);   // y = -x + 3 (x ∈ [xs[1], xs[3]) = [0, 5))
*cht.get_min(2);                // x = xs[2] = 1 での最小値: 1
```

最大値を求めたい場合は、傾きと切片の符号を反転して追加し、結果の符号を戻します。

## メンバ関数

$n$ を `xs` の長さとします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `LiChaoTree(xs)` | ソート済みの $x$ 座標の配列から作る | $O(n)$ |
| `add_line(a, b)` | 直線 $y = ax + b$ を追加 | $O(\log n)$ |
| `add_segment(a, b, l, r)` | 線分 $y = ax + b$ ($x \in [\mathrm{xs}_l, \mathrm{xs}_r)$) を追加 | $O(\log^2 n)$ |
| `get_min(i)` | $x = \mathrm{xs}_i$ での最小値 (`std::optional<T>`)。$x = \mathrm{xs}_i$ を含む直線・線分がなければ `std::nullopt` | $O(\log n)$ |

## x 座標を先読みしない `DynamicLiChaoTree<T>`

$x$ を $[lo, hi)$ の整数に限る代わりに、座標を先読みしなくてよい版です。必要になった頂点だけを作るので、範囲が $10^9$ 程度でも使えます。クエリを先に読めない (オンラインの) ときに使います。

```cpp
DynamicLiChaoTree<long long> cht(-1000000000, 1000000001);  // x ∈ [-10^9, 10^9]
cht.add_line(2, 3);             // y = 2x + 3
cht.add_segment(-1, 0, 0, 10);  // y = -x (x ∈ [0, 10))
*cht.get_min(5);                // -5
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `DynamicLiChaoTree(lo, hi)` | $x$ が $[lo, hi)$ の整数をとる、直線のない木 | $O(1)$ |
| `add_line(a, b)` | 直線 $y = ax + b$ を追加 | $O(\log W)$ |
| `add_segment(a, b, l, r)` | 線分 $y = ax + b$ ($x \in [l, r)$、$l$、$r$ は $x$ 座標そのもの) を追加 | $O(\log^2 W)$ |
| `get_min(x)` | $x$ での最小値 (`std::optional<T>`)。$x$ を含む直線・線分がなければ `std::nullopt` | $O(\log W)$ |

$W = hi - lo$ です。頂点は、直線 1 本につき 1 個以下、線分 1 本につき $2 \log W$ 個程度増えます。線分を何十万本も足すとメモリと時間が重くなる (範囲 $2 \times 10^9$、線分 $4 \times 10^5$ 本で頂点 1300 万個、5 秒ほど) ので、そのときは座標を先読みする `LiChaoTree` を使います。

## 関連

- 直線ではなく値の区間最小値なら [セグメント木](segtree.hpp)
- 遷移の最適な位置が単調な DP や Alien DP は [Monge 性を使う DP の高速化](../dp/monge.hpp)
