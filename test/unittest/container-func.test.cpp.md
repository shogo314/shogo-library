---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/container_func.hpp
    title: "\u30B3\u30F3\u30C6\u30CA\u306B\u5BFE\u3059\u308B\u95A2\u6570 (sorted,\
      \ max, sum \u306A\u3069)"
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
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
  bundledCode: "#line 1 \"test/unittest/container-func.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ container_func.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\
    \u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n#include\
    \ <functional>\n#include <iostream>\n#include <numeric>\n#include <random>\n#include\
    \ <set>\n#include <string>\n#include <vector>\n\n#line 2 \"src/utility/container_func.hpp\"\
    \n\n/**\n * @file container_func.hpp\n * @brief \u30B3\u30F3\u30C6\u30CA\u306B\
    \u5BFE\u3059\u308B\u95A2\u6570 (sorted, max, sum \u306A\u3069)\n */\n\n#line 9\
    \ \"src/utility/container_func.hpp\"\n#include <cassert>\n#include <cstddef>\n\
    #line 12 \"src/utility/container_func.hpp\"\n#include <initializer_list>\n#include\
    \ <iterator>\n#line 15 \"src/utility/container_func.hpp\"\n#include <type_traits>\n\
    #line 17 \"src/utility/container_func.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 12 \"\
    src/utility/traits.hpp\"\n#include <utility>\n\nnamespace internal_traits {\n\
    using std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ internal_traits {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace internal_traits\ntemplate <class T>\n\
    struct is_sorted_container : internal_traits::is_sorted_container_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 19 \"src/utility/container_func.hpp\"\n\n#define METHOD_EXPAND(func)   \
    \                                     \\\n    template <typename T, ENABLE_IF_T(has_##func##_v<T>)>\
    \          \\\n    inline constexpr auto func(const T& t) -> decltype(t.func())\
    \ { \\\n        return t.func();                                           \\\n\
    \    }\n\n#define METHOD_AND_FUNC_ARG_EXPAND(func)                           \
    \       \\\n    template <typename T, typename U, ENABLE_IF_T(has_##func##_v<T,\
    \ U>)>  \\\n    inline constexpr auto func(const T& t, const U& u)           \
    \         \\\n        -> decltype(t.func(u)) {                               \
    \           \\\n        return t.func(u);                                    \
    \             \\\n    }                                                      \
    \               \\\n    template <typename T, typename U, ENABLE_IF_T(!has_##func##_v<T,\
    \ U>)> \\\n    inline constexpr auto func(const T& t, const U& u)            \
    \        \\\n        -> decltype(std::func(t.begin(), t.end(), u)) {         \
    \          \\\n        return std::func(t.begin(), t.end(), u);              \
    \            \\\n    }\n\nMETHOD_EXPAND(reversed)\ntemplate <class C, ENABLE_IF_T(!has_reversed_v<C>)>\n\
    inline constexpr C reversed(C t) {\n    std::reverse(t.begin(), t.end());\n  \
    \  return t;\n}\n\nMETHOD_EXPAND(sorted)\ntemplate <class C, ENABLE_IF_T(!has_sorted_v<C>)>\n\
    inline constexpr C sorted(C t, bool reverse = false) {\n    std::sort(t.begin(),\
    \ t.end());\n    if (reverse) std::reverse(t.begin(), t.end());\n    return t;\n\
    }\ntemplate <class C, class F, ENABLE_IF_T(!has_sorted_v<C> && std::is_invocable_r_v<bool,\
    \ F, mem_value_type<C>, mem_value_type<C>>)>\ninline constexpr C sorted(C t, F\
    \ f) {\n    std::sort(t.begin(), t.end(), f);\n    return t;\n}\n\ntemplate <class\
    \ C>\ninline constexpr void sort(C& t, bool reverse = false) {\n    std::sort(t.begin(),\
    \ t.end());\n    if (reverse) std::reverse(t.begin(), t.end());\n}\ntemplate <class\
    \ C, class F, ENABLE_IF_T(std::is_invocable_r_v<bool, F, mem_value_type<C>, mem_value_type<C>>)>\n\
    inline constexpr void sort(C& t, F f) {\n    std::sort(t.begin(), t.end(), f);\n\
    }\ntemplate <class C, class F, ENABLE_IF_T(std::is_invocable_v<F, mem_value_type<C>>)>\n\
    inline constexpr void sort_by_key(C& t, F f) {\n    std::sort(t.begin(), t.end(),\
    \ [&](const mem_value_type<C>& left, const mem_value_type<C>& right) {\n     \
    \   return f(left) < f(right);\n    });\n}\n\ntemplate <class C>\ninline constexpr\
    \ void reverse(C& t) {\n    std::reverse(t.begin(), t.end());\n}\n\nMETHOD_EXPAND(max)\n\
    template <class C, ENABLE_IF_T(!has_max_v<C> && is_sorted_container_v<C>)>\ninline\
    \ constexpr mem_value_type<C> max(const C& v) {\n    assert(v.begin() != v.end());\n\
    \    return *v.rbegin();\n}\ntemplate <class C, ENABLE_IF_T(!has_max_v<C> && !is_sorted_container_v<C>)>\n\
    inline constexpr mem_value_type<C> max(const C& v) {\n    assert(v.begin() !=\
    \ v.end());\n    return *std::max_element(v.begin(), v.end());\n}\ntemplate <typename\
    \ T>\ninline constexpr T max(const std::initializer_list<T>& v) {\n    return\
    \ std::max(v);\n}\n\nMETHOD_EXPAND(min)\ntemplate <class C, ENABLE_IF_T(!has_min_v<C>\
    \ && is_sorted_container_v<C>)>\ninline constexpr mem_value_type<C> min(const\
    \ C& v) {\n    assert(v.begin() != v.end());\n    return *v.begin();\n}\ntemplate\
    \ <class C, ENABLE_IF_T(!has_min_v<C> && !is_sorted_container_v<C>)>\ninline constexpr\
    \ mem_value_type<C> min(const C& v) {\n    assert(v.begin() != v.end());\n   \
    \ return *std::min_element(v.begin(), v.end());\n}\ntemplate <typename T>\ninline\
    \ constexpr T min(const std::initializer_list<T>& v) {\n    return std::min(v);\n\
    }\n\nMETHOD_EXPAND(sum)\ntemplate <class C, ENABLE_IF_T(!has_sum_v<C>)>\ninline\
    \ constexpr mem_value_type<C> sum(const C& v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), mem_value_type<C>{});\n}\ntemplate <typename T>\ninline constexpr T\
    \ sum(const std::initializer_list<T>& v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), T{});\n}\n\nMETHOD_EXPAND(product)\ntemplate <class C, ENABLE_IF_T(!has_product_v<C>)>\n\
    inline constexpr mem_value_type<C> product(const C& v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), mem_value_type<C>{1}, std::multiplies<mem_value_type<C>>());\n}\ntemplate\
    \ <typename T>\ninline constexpr T product(const std::initializer_list<T>& v)\
    \ {\n    return std::accumulate(v.begin(), v.end(), T{1}, std::multiplies<T>());\n\
    }\n\nMETHOD_EXPAND(product_xor)\ntemplate <class C, ENABLE_IF_T(!has_product_xor_v<C>)>\n\
    inline constexpr mem_value_type<C> product_xor(const C& v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), mem_value_type<C>{0}, std::bit_xor<mem_value_type<C>>());\n}\ntemplate\
    \ <typename T>\ninline constexpr T product_xor(const std::initializer_list<T>&\
    \ v) {\n    return std::accumulate(v.begin(), v.end(), T{0}, std::bit_xor<T>());\n\
    }\n\ntemplate <class C>\ninline constexpr mem_value_type<C> maximum_subarray(const\
    \ C& v) {\n    assert(!v.empty());\n    auto itr = v.begin();\n    mem_value_type<C>\
    \ tmp = *itr++;\n    mem_value_type<C> res = tmp;\n    while (itr != v.end())\
    \ {\n        tmp += *itr;\n        if (tmp < *itr) tmp = *itr;\n        if (res\
    \ < tmp) res = tmp;\n        ++itr;\n    }\n    return res;\n}\ntemplate <class\
    \ C>\ninline constexpr mem_value_type<C> maximum_subarray(const C& v, mem_value_type<C>\
    \ init) {\n    mem_value_type<C> res = init, tmp = init;\n    for (const auto&\
    \ a : v) {\n        tmp += a;\n        if (tmp < init) tmp = init;\n        if\
    \ (res < tmp) res = tmp;\n    }\n    return res;\n}\n\nMETHOD_AND_FUNC_ARG_EXPAND(count)\n\
    METHOD_AND_FUNC_ARG_EXPAND(find)\nMETHOD_AND_FUNC_ARG_EXPAND(lower_bound)\nMETHOD_AND_FUNC_ARG_EXPAND(upper_bound)\n\
    \ntemplate <class C, typename T>\ninline constexpr bool contains(const C& c, const\
    \ T& t) {\n    return find(c, t) != c.end();\n}\n\ntemplate <class C>\ninline\
    \ constexpr mem_value_type<C> gcd(const C& v) {\n    mem_value_type<C> init(0);\n\
    \    for (const auto& e : v) init = std::gcd(init, e);\n    return init;\n}\n\n\
    template <class C>\ninline constexpr mem_value_type<C> average(const C& v) {\n\
    \    assert(v.size());\n    return sum(v) / v.size();\n}\n\ntemplate <class C>\n\
    inline constexpr mem_value_type<C> median(const C& v) {\n    assert(!v.empty());\n\
    \    std::vector<std::size_t> u(v.size());\n    std::iota(u.begin(), u.end(),\
    \ 0);\n    std::sort(u.begin(), u.end(), [&](std::size_t a, std::size_t b) {\n\
    \        return v[a] < v[b];\n    });\n    if (v.size() & 1) {\n        return\
    \ v[u[v.size() / 2]];\n    }\n    // C++20\n    // return std::midpoint(v[u[v.size()\
    \ / 2]], v[u[v.size() / 2 - 1]]);\n    return (v[u[v.size() / 2]] + v[u[v.size()\
    \ / 2 - 1]]) / 2;\n}\n\n// x \u304C\u6700\u521D\u306B\u73FE\u308C\u308B\u4F4D\u7F6E\
    \u3002\u306A\u3051\u308C\u3070 -1\ntemplate <class C, typename U>\ninline constexpr\
    \ int index(const C& v, const U& x) {\n    auto it = find(v, x);\n    if (it ==\
    \ v.end()) return -1;\n    return static_cast<int>(std::distance(v.begin(), it));\n\
    }\n\ntemplate <class C, ENABLE_IF_T(std::is_integral_v<mem_value_type<C>>)>\n\
    inline constexpr mem_value_type<C> mex(const C& v) {\n    std::vector<bool> b(v.size()\
    \ + 1);\n    for (const auto& a : v) {\n        if (0 <= a && static_cast<std::size_t>(a)\
    \ < b.size()) {\n            b[a] = true;\n        }\n    }\n    mem_value_type<C>\
    \ ret = 0;  // b \u306E\u8981\u7D20\u6570\u306F v \u3088\u308A 1 \u591A\u3044\u306E\
    \u3067\u3001\u4E0B\u306E\u30EB\u30FC\u30D7\u3067\u5FC5\u305A\u898B\u3064\u304B\
    \u308B\n    for (std::size_t i = 0; i < b.size(); i++) {\n        if (!b[i]) {\n\
    \            ret = i;\n            break;\n        }\n    }\n    return ret;\n\
    }\n\ntemplate <class C>\ninline constexpr int bisect_left(const C& v, const mem_value_type<C>&\
    \ x) {\n    return static_cast<int>(std::distance(v.begin(), lower_bound(v, x)));\n\
    }\ntemplate <class C>\ninline constexpr int bisect_right(const C& v, const mem_value_type<C>&\
    \ x) {\n    return static_cast<int>(std::distance(v.begin(), upper_bound(v, x)));\n\
    }\n#line 16 \"test/unittest/container-func.test.cpp\"\n\nbool ok = true;\n\nvoid\
    \ check(bool cond, const char* what) {\n    if (!cond) {\n        if (ok) std::cerr\
    \ << \"failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n    auto rand_vec = [&](int n, long\
    \ long lo, long long hi) {\n        std::vector<long long> v(n);\n        for\
    \ (auto& x : v) x = lo + (long long)(rng() % (unsigned long long)(hi - lo + 1));\n\
    \        return v;\n    };\n\n    for (int rep = 0; rep < 2000 && ok; rep++) {\n\
    \        int n = rng() % 10 + 1;\n        std::vector<long long> v = rand_vec(n,\
    \ -5, 5);\n\n        // sorted / sort (\u6BD4\u8F03\u95A2\u6570\u3064\u304D)\n\
    \        {\n            std::vector<long long> expect = v;\n            std::sort(expect.begin(),\
    \ expect.end(), std::greater<long long>());\n            check(sorted(v, std::greater<long\
    \ long>()) == expect, \"sorted(c, f)\");\n            std::vector<long long> w\
    \ = v;\n            sort(w, std::greater<long long>());\n            check(w ==\
    \ expect, \"sort(c, f)\");\n        }\n\n        // set / multiset \u306B\u5BFE\
    \u3059\u308B max / min (\u30BD\u30FC\u30C8\u6E08\u307F\u306E\u30B3\u30F3\u30C6\
    \u30CA\u306F\u5148\u982D\u3068\u672B\u5C3E)\n        {\n            std::set<long\
    \ long> s(v.begin(), v.end());\n            std::multiset<long long> ms(v.begin(),\
    \ v.end());\n            long long mx = *std::max_element(v.begin(), v.end());\n\
    \            long long mn = *std::min_element(v.begin(), v.end());\n         \
    \   check(max(s) == mx && min(s) == mn, \"max/min(set)\");\n            check(max(ms)\
    \ == mx && min(ms) == mn, \"max/min(multiset)\");\n            check(max(v) ==\
    \ mx && min(v) == mn, \"max/min(vector)\");\n        }\n\n        // product /\
    \ product_xor\n        {\n            std::vector<long long> small = rand_vec(n,\
    \ -3, 3);\n            long long p = 1, x = 0;\n            for (long long a :\
    \ small) p *= a, x ^= a;\n            check(product(small) == p, \"product(c)\"\
    );\n            check(product_xor(small) == x, \"product_xor(c)\");\n        \
    \    std::vector<long long> nonneg = rand_vec(n, 0, 1000000);\n            long\
    \ long y = 0;\n            for (long long a : nonneg) y ^= a;\n            check(product_xor(nonneg)\
    \ == y, \"product_xor(c) large\");\n        }\n\n        // maximum_subarray (\u7A7A\
    \u306E\u90E8\u5206\u5217\u3092\u8A31\u3059\u7248): \u5168\u533A\u9593\u306E\u548C\
    \u306E\u6700\u5927\u5024\u3068 init \u306E\u5927\u304D\u3044\u65B9\n        {\n\
    \            long long init = (long long)(rng() % 7) - 3;\n            long long\
    \ best = init;\n            for (int l = 0; l < n; l++) {\n                long\
    \ long s = init;\n                for (int r = l; r < n; r++) {\n            \
    \        s += v[r];\n                    best = std::max(best, s);\n         \
    \       }\n            }\n            check(maximum_subarray(v, init) == best,\
    \ \"maximum_subarray(c, init)\");\n            // \u7A7A\u3067\u306A\u3044\u7248\
    \u3082\u5408\u308F\u305B\u3066\u78BA\u304B\u3081\u308B\n            long long\
    \ best_nonempty = v[0];\n            for (int l = 0; l < n; l++) {\n         \
    \       long long s = 0;\n                for (int r = l; r < n; r++) {\n    \
    \                s += v[r];\n                    best_nonempty = std::max(best_nonempty,\
    \ s);\n                }\n            }\n            check(maximum_subarray(v)\
    \ == best_nonempty, \"maximum_subarray(c)\");\n        }\n\n        // median:\
    \ \u5076\u6570\u500B\u306A\u3089\u4E2D\u592E 2 \u3064\u306E\u5E73\u5747 (\u6574\
    \u6570\u578B\u306F 0 \u65B9\u5411\u306B\u5207\u308A\u6368\u3066)\n        {\n\
    \            std::vector<long long> w = v;\n            std::sort(w.begin(), w.end());\n\
    \            long long expect = n % 2 ? w[n / 2] : (w[n / 2 - 1] + w[n / 2]) /\
    \ 2;\n            check(median(v) == expect, \"median(vector<long long>)\");\n\
    \            std::vector<double> d(v.begin(), v.end());\n            std::vector<double>\
    \ dw = d;\n            std::sort(dw.begin(), dw.end());\n            double dexp\
    \ = n % 2 ? dw[n / 2] : (dw[n / 2 - 1] + dw[n / 2]) / 2;\n            check(median(d)\
    \ == dexp, \"median(vector<double>)\");\n        }\n\n        // index: \u6700\
    \u521D\u306B\u73FE\u308C\u308B\u4F4D\u7F6E\u3001\u306A\u3051\u308C\u3070 -1\n\
    \        {\n            long long x = (long long)(rng() % 13) - 6;\n         \
    \   long long expect = std::find(v.begin(), v.end(), x) - v.begin();\n       \
    \     if (expect == (long long)v.size()) expect = -1;\n            check(index(v,\
    \ x) == expect, \"index(c, x)\");\n        }\n\n        // mex: \u542B\u307E\u308C\
    \u306A\u3044\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\n        {\n          \
    \  std::vector<int> w(n);\n            for (auto& a : w) a = (int)(rng() % 8)\
    \ - 2;\n            int expect = 0;\n            while (std::find(w.begin(), w.end(),\
    \ expect) != w.end()) expect++;\n            check(mex(w) == expect, \"mex(c)\"\
    );\n        }\n\n        // count / find / lower_bound / upper_bound (set \u306F\
    \u30E1\u30F3\u30D0\u95A2\u6570\u3001vector \u306F std:: \u306E\u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0)\n        {\n            long long x = (long long)(rng() %\
    \ 13) - 6;\n            std::multiset<long long> ms(v.begin(), v.end());\n   \
    \         std::vector<long long> w = v;\n            std::sort(w.begin(), w.end());\n\
    \            check(count(ms, x) == (std::size_t)std::count(v.begin(), v.end(),\
    \ x), \"count(multiset, x)\");\n            check(count(v, x) == std::count(v.begin(),\
    \ v.end(), x), \"count(vector, x)\");\n            check((find(ms, x) != ms.end())\
    \ == (std::find(v.begin(), v.end(), x) != v.end()), \"find(multiset, x)\");\n\
    \            check(find(v, x) == std::find(v.begin(), v.end(), x), \"find(vector,\
    \ x)\");\n            check(lower_bound(ms, x) == ms.lower_bound(x) && upper_bound(ms,\
    \ x) == ms.upper_bound(x), \"lower/upper_bound(multiset, x)\");\n            check(lower_bound(w,\
    \ x) == std::lower_bound(w.begin(), w.end(), x), \"lower_bound(vector, x)\");\n\
    \            check(upper_bound(w, x) == std::upper_bound(w.begin(), w.end(), x),\
    \ \"upper_bound(vector, x)\");\n            check(contains(v, x) == (std::find(v.begin(),\
    \ v.end(), x) != v.end()), \"contains(vector, x)\");\n        }\n    }\n\n   \
    \ // \u521D\u671F\u5316\u5B50\u30EA\u30B9\u30C8\u7248\n    check(max({3, -1, 7,\
    \ 2}) == 7, \"max(initializer_list)\");\n    check(min({3, -1, 7, 2}) == -1, \"\
    min(initializer_list)\");\n    check(sum({3, -1, 7, 2}) == 11, \"sum(initializer_list)\"\
    );\n    check(product({3, -1, 7, 2}) == -42, \"product(initializer_list)\");\n\
    \    check(product_xor({3, 5, 6}) == 0, \"product_xor(initializer_list)\");\n\
    \    check(max({5}) == 5 && min({5}) == 5, \"max/min(initializer_list) 1 \u8981\
    \u7D20\");\n\n    // \u5883\u754C: 1 \u8981\u7D20\u3001\u7A7A\n    check(median(std::vector<int>{4})\
    \ == 4, \"median 1 \u8981\u7D20\");\n    check(median(std::vector<int>{1, 4})\
    \ == 2, \"median 2 \u8981\u7D20\");\n    check(mex(std::vector<int>{}) == 0, \"\
    mex \u7A7A\");\n    check(mex(std::vector<int>{0, 1, 2}) == 3, \"mex 0..n-1 \u3092\
    \u3059\u3079\u3066\u542B\u3080\");\n    check(maximum_subarray(std::vector<int>{},\
    \ 0) == 0, \"maximum_subarray \u7A7A\");\n    check(maximum_subarray(std::vector<int>{-5,\
    \ -2, -9}) == -2, \"maximum_subarray \u3059\u3079\u3066\u8CA0\");\n    check(maximum_subarray(std::vector<int>{-5,\
    \ -2, -9}, 0) == 0, \"maximum_subarray \u3059\u3079\u3066\u8CA0\u3001\u7A7A\u3092\
    \u8A31\u3059\");\n    check(product(std::vector<int>{}) == 1 && product_xor(std::vector<int>{})\
    \ == 0, \"product \u7A7A\");\n    check(index(std::vector<int>{}, 3) == -1, \"\
    index \u7A7A\");\n    check(sorted(std::string(\"bca\"), std::greater<char>())\
    \ == \"cba\", \"sorted(string, f)\");\n\n    if (ok) std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// container_func.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n\
    #include <functional>\n#include <iostream>\n#include <numeric>\n#include <random>\n\
    #include <set>\n#include <string>\n#include <vector>\n\n#include \"../../src/utility/container_func.hpp\"\
    \n\nbool ok = true;\n\nvoid check(bool cond, const char* what) {\n    if (!cond)\
    \ {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n       \
    \ ok = false;\n    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n    auto\
    \ rand_vec = [&](int n, long long lo, long long hi) {\n        std::vector<long\
    \ long> v(n);\n        for (auto& x : v) x = lo + (long long)(rng() % (unsigned\
    \ long long)(hi - lo + 1));\n        return v;\n    };\n\n    for (int rep = 0;\
    \ rep < 2000 && ok; rep++) {\n        int n = rng() % 10 + 1;\n        std::vector<long\
    \ long> v = rand_vec(n, -5, 5);\n\n        // sorted / sort (\u6BD4\u8F03\u95A2\
    \u6570\u3064\u304D)\n        {\n            std::vector<long long> expect = v;\n\
    \            std::sort(expect.begin(), expect.end(), std::greater<long long>());\n\
    \            check(sorted(v, std::greater<long long>()) == expect, \"sorted(c,\
    \ f)\");\n            std::vector<long long> w = v;\n            sort(w, std::greater<long\
    \ long>());\n            check(w == expect, \"sort(c, f)\");\n        }\n\n  \
    \      // set / multiset \u306B\u5BFE\u3059\u308B max / min (\u30BD\u30FC\u30C8\
    \u6E08\u307F\u306E\u30B3\u30F3\u30C6\u30CA\u306F\u5148\u982D\u3068\u672B\u5C3E\
    )\n        {\n            std::set<long long> s(v.begin(), v.end());\n       \
    \     std::multiset<long long> ms(v.begin(), v.end());\n            long long\
    \ mx = *std::max_element(v.begin(), v.end());\n            long long mn = *std::min_element(v.begin(),\
    \ v.end());\n            check(max(s) == mx && min(s) == mn, \"max/min(set)\"\
    );\n            check(max(ms) == mx && min(ms) == mn, \"max/min(multiset)\");\n\
    \            check(max(v) == mx && min(v) == mn, \"max/min(vector)\");\n     \
    \   }\n\n        // product / product_xor\n        {\n            std::vector<long\
    \ long> small = rand_vec(n, -3, 3);\n            long long p = 1, x = 0;\n   \
    \         for (long long a : small) p *= a, x ^= a;\n            check(product(small)\
    \ == p, \"product(c)\");\n            check(product_xor(small) == x, \"product_xor(c)\"\
    );\n            std::vector<long long> nonneg = rand_vec(n, 0, 1000000);\n   \
    \         long long y = 0;\n            for (long long a : nonneg) y ^= a;\n \
    \           check(product_xor(nonneg) == y, \"product_xor(c) large\");\n     \
    \   }\n\n        // maximum_subarray (\u7A7A\u306E\u90E8\u5206\u5217\u3092\u8A31\
    \u3059\u7248): \u5168\u533A\u9593\u306E\u548C\u306E\u6700\u5927\u5024\u3068 init\
    \ \u306E\u5927\u304D\u3044\u65B9\n        {\n            long long init = (long\
    \ long)(rng() % 7) - 3;\n            long long best = init;\n            for (int\
    \ l = 0; l < n; l++) {\n                long long s = init;\n                for\
    \ (int r = l; r < n; r++) {\n                    s += v[r];\n                \
    \    best = std::max(best, s);\n                }\n            }\n           \
    \ check(maximum_subarray(v, init) == best, \"maximum_subarray(c, init)\");\n \
    \           // \u7A7A\u3067\u306A\u3044\u7248\u3082\u5408\u308F\u305B\u3066\u78BA\
    \u304B\u3081\u308B\n            long long best_nonempty = v[0];\n            for\
    \ (int l = 0; l < n; l++) {\n                long long s = 0;\n              \
    \  for (int r = l; r < n; r++) {\n                    s += v[r];\n           \
    \         best_nonempty = std::max(best_nonempty, s);\n                }\n   \
    \         }\n            check(maximum_subarray(v) == best_nonempty, \"maximum_subarray(c)\"\
    );\n        }\n\n        // median: \u5076\u6570\u500B\u306A\u3089\u4E2D\u592E\
    \ 2 \u3064\u306E\u5E73\u5747 (\u6574\u6570\u578B\u306F 0 \u65B9\u5411\u306B\u5207\
    \u308A\u6368\u3066)\n        {\n            std::vector<long long> w = v;\n  \
    \          std::sort(w.begin(), w.end());\n            long long expect = n %\
    \ 2 ? w[n / 2] : (w[n / 2 - 1] + w[n / 2]) / 2;\n            check(median(v) ==\
    \ expect, \"median(vector<long long>)\");\n            std::vector<double> d(v.begin(),\
    \ v.end());\n            std::vector<double> dw = d;\n            std::sort(dw.begin(),\
    \ dw.end());\n            double dexp = n % 2 ? dw[n / 2] : (dw[n / 2 - 1] + dw[n\
    \ / 2]) / 2;\n            check(median(d) == dexp, \"median(vector<double>)\"\
    );\n        }\n\n        // index: \u6700\u521D\u306B\u73FE\u308C\u308B\u4F4D\u7F6E\
    \u3001\u306A\u3051\u308C\u3070 -1\n        {\n            long long x = (long\
    \ long)(rng() % 13) - 6;\n            long long expect = std::find(v.begin(),\
    \ v.end(), x) - v.begin();\n            if (expect == (long long)v.size()) expect\
    \ = -1;\n            check(index(v, x) == expect, \"index(c, x)\");\n        }\n\
    \n        // mex: \u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u975E\u8CA0\
    \u6574\u6570\n        {\n            std::vector<int> w(n);\n            for (auto&\
    \ a : w) a = (int)(rng() % 8) - 2;\n            int expect = 0;\n            while\
    \ (std::find(w.begin(), w.end(), expect) != w.end()) expect++;\n            check(mex(w)\
    \ == expect, \"mex(c)\");\n        }\n\n        // count / find / lower_bound\
    \ / upper_bound (set \u306F\u30E1\u30F3\u30D0\u95A2\u6570\u3001vector \u306F std::\
    \ \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)\n        {\n            long long\
    \ x = (long long)(rng() % 13) - 6;\n            std::multiset<long long> ms(v.begin(),\
    \ v.end());\n            std::vector<long long> w = v;\n            std::sort(w.begin(),\
    \ w.end());\n            check(count(ms, x) == (std::size_t)std::count(v.begin(),\
    \ v.end(), x), \"count(multiset, x)\");\n            check(count(v, x) == std::count(v.begin(),\
    \ v.end(), x), \"count(vector, x)\");\n            check((find(ms, x) != ms.end())\
    \ == (std::find(v.begin(), v.end(), x) != v.end()), \"find(multiset, x)\");\n\
    \            check(find(v, x) == std::find(v.begin(), v.end(), x), \"find(vector,\
    \ x)\");\n            check(lower_bound(ms, x) == ms.lower_bound(x) && upper_bound(ms,\
    \ x) == ms.upper_bound(x), \"lower/upper_bound(multiset, x)\");\n            check(lower_bound(w,\
    \ x) == std::lower_bound(w.begin(), w.end(), x), \"lower_bound(vector, x)\");\n\
    \            check(upper_bound(w, x) == std::upper_bound(w.begin(), w.end(), x),\
    \ \"upper_bound(vector, x)\");\n            check(contains(v, x) == (std::find(v.begin(),\
    \ v.end(), x) != v.end()), \"contains(vector, x)\");\n        }\n    }\n\n   \
    \ // \u521D\u671F\u5316\u5B50\u30EA\u30B9\u30C8\u7248\n    check(max({3, -1, 7,\
    \ 2}) == 7, \"max(initializer_list)\");\n    check(min({3, -1, 7, 2}) == -1, \"\
    min(initializer_list)\");\n    check(sum({3, -1, 7, 2}) == 11, \"sum(initializer_list)\"\
    );\n    check(product({3, -1, 7, 2}) == -42, \"product(initializer_list)\");\n\
    \    check(product_xor({3, 5, 6}) == 0, \"product_xor(initializer_list)\");\n\
    \    check(max({5}) == 5 && min({5}) == 5, \"max/min(initializer_list) 1 \u8981\
    \u7D20\");\n\n    // \u5883\u754C: 1 \u8981\u7D20\u3001\u7A7A\n    check(median(std::vector<int>{4})\
    \ == 4, \"median 1 \u8981\u7D20\");\n    check(median(std::vector<int>{1, 4})\
    \ == 2, \"median 2 \u8981\u7D20\");\n    check(mex(std::vector<int>{}) == 0, \"\
    mex \u7A7A\");\n    check(mex(std::vector<int>{0, 1, 2}) == 3, \"mex 0..n-1 \u3092\
    \u3059\u3079\u3066\u542B\u3080\");\n    check(maximum_subarray(std::vector<int>{},\
    \ 0) == 0, \"maximum_subarray \u7A7A\");\n    check(maximum_subarray(std::vector<int>{-5,\
    \ -2, -9}) == -2, \"maximum_subarray \u3059\u3079\u3066\u8CA0\");\n    check(maximum_subarray(std::vector<int>{-5,\
    \ -2, -9}, 0) == 0, \"maximum_subarray \u3059\u3079\u3066\u8CA0\u3001\u7A7A\u3092\
    \u8A31\u3059\");\n    check(product(std::vector<int>{}) == 1 && product_xor(std::vector<int>{})\
    \ == 0, \"product \u7A7A\");\n    check(index(std::vector<int>{}, 3) == -1, \"\
    index \u7A7A\");\n    check(sorted(std::string(\"bca\"), std::greater<char>())\
    \ == \"cba\", \"sorted(string, f)\");\n\n    if (ok) std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/utility/container_func.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/container-func.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/container-func.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/container-func.test.cpp
- /verify/test/unittest/container-func.test.cpp.html
title: test/unittest/container-func.test.cpp
---
