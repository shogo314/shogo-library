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
  bundledCode: "#line 1 \"test/unittest/container-func-member.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// container_func.hpp \u306E\u95A2\u6570\u304C\u3001\u30B3\u30F3\u30C6\u30CA\
    \u304C\u540C\u540D\u306E\u30E1\u30F3\u30D0\u95A2\u6570\u3092\u6301\u3064\u3068\
    \u304D\u306F\u305D\u3061\u3089\u3092\u547C\u3076\u3053\u3068\u3092\u78BA\u304B\
    \u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\
    \u3079\u3066\u671F\u5F85\u3069\u304A\u308A\u306A\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/utility/container_func.hpp\"\
    \n\n/**\n * @file container_func.hpp\n * @brief \u30B3\u30F3\u30C6\u30CA\u306B\
    \u5BFE\u3059\u308B\u95A2\u6570 (sorted, max, sum \u306A\u3069)\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cstddef>\n#include <functional>\n\
    #include <initializer_list>\n#include <iterator>\n#include <numeric>\n#include\
    \ <type_traits>\n#line 17 \"src/utility/container_func.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 10 \"\
    src/utility/traits.hpp\"\n#include <set>\n#line 12 \"src/utility/traits.hpp\"\n\
    #include <utility>\n\nnamespace internal_traits {\nusing std::begin, std::end;\n\
    \ntemplate <class T, class = void>\nstruct is_range_impl : std::false_type {};\n\
    template <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    \    assert(v.size());\n    // v.size() \u306F\u7B26\u53F7\u306A\u3057\u306A\u306E\
    \u3067\u3001\u305D\u306E\u307E\u307E\u5272\u308B\u3068\u8CA0\u306E\u548C\u304C\
    \u7B26\u53F7\u306A\u3057\u306B\u5909\u63DB\u3055\u308C\u3066\u58CA\u308C\u308B\
    \n    return sum(v) / static_cast<mem_value_type<C>>(v.size());\n}\n\ntemplate\
    \ <class C>\ninline constexpr mem_value_type<C> median(const C& v) {\n    assert(!v.empty());\n\
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
    }\n#line 10 \"test/unittest/container-func-member.test.cpp\"\n\n// \u8981\u7D20\
    \u306F {3, 1, 2} \u3060\u304C\u3001\u30E1\u30F3\u30D0\u95A2\u6570\u306F\u76EE\u5370\
    \u306E\u5024\u3092\u8FD4\u3059\nstruct Base {\n    using value_type = int;\n \
    \   std::vector<int> v{3, 1, 2};\n    auto begin() const { return v.begin(); }\n\
    \    auto end() const { return v.end(); }\n};\nstruct WithMax : Base {\n    int\
    \ max() const { return 100; }\n};\nstruct WithMin : Base {\n    int min() const\
    \ { return -100; }\n};\nstruct WithMaxMin : Base {\n    int max() const { return\
    \ 100; }\n    int min() const { return -100; }\n};\nstruct WithSum : Base {\n\
    \    int sum() const { return 1000; }\n};\nstruct WithProduct : Base {\n    int\
    \ product() const { return 2000; }\n};\nstruct WithProductXor : Base {\n    int\
    \ product_xor() const { return 3000; }\n};\nstruct WithSorted : Base {\n    std::vector<int>\
    \ sorted() const { return {42}; }\n};\nstruct WithReversed : Base {\n    std::vector<int>\
    \ reversed() const { return {43}; }\n};\n\nint main() {\n    bool ok = true;\n\
    \    auto check = [&](bool cond, const char* what) {\n        if (!cond) {\n \
    \           std::cerr << \"failed: \" << what << std::endl;\n            ok =\
    \ false;\n        }\n    };\n\n    check(max(WithMax{}) == 100, \"max \u306F\u30E1\
    \u30F3\u30D0\u95A2\u6570 max \u3092\u547C\u3076\");\n    check(min(WithMax{})\
    \ == 1, \"max \u3060\u3051\u3092\u6301\u3064\u578B\u306E min \u306F\u8981\u7D20\
    \u306E\u6700\u5C0F\u5024\");\n    check(min(WithMin{}) == -100, \"min \u306F\u30E1\
    \u30F3\u30D0\u95A2\u6570 min \u3092\u547C\u3076\");\n    check(max(WithMin{})\
    \ == 3, \"min \u3060\u3051\u3092\u6301\u3064\u578B\u306E max \u306F\u8981\u7D20\
    \u306E\u6700\u5927\u5024\");\n    check(max(WithMaxMin{}) == 100 && min(WithMaxMin{})\
    \ == -100, \"max \u3068 min \u3092\u4E21\u65B9\u6301\u3064\u578B\");\n    check(sum(WithSum{})\
    \ == 1000, \"sum \u306F\u30E1\u30F3\u30D0\u95A2\u6570 sum \u3092\u547C\u3076\"\
    );\n    check(product(WithProduct{}) == 2000, \"product \u306F\u30E1\u30F3\u30D0\
    \u95A2\u6570 product \u3092\u547C\u3076\");\n    check(product_xor(WithProductXor{})\
    \ == 3000, \"product_xor \u306F\u30E1\u30F3\u30D0\u95A2\u6570 product_xor \u3092\
    \u547C\u3076\");\n    check(sorted(WithSorted{}) == std::vector<int>{42}, \"sorted\
    \ \u306F\u30E1\u30F3\u30D0\u95A2\u6570 sorted \u3092\u547C\u3076\");\n    check(reversed(WithReversed{})\
    \ == std::vector<int>{43}, \"reversed \u306F\u30E1\u30F3\u30D0\u95A2\u6570 reversed\
    \ \u3092\u547C\u3076\");\n    check(sum(Base{}) == 6 && product(Base{}) == 6 &&\
    \ product_xor(Base{}) == 0, \"\u30E1\u30F3\u30D0\u95A2\u6570\u3092\u6301\u305F\
    \u306A\u3044\u578B\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// container_func.hpp \u306E\u95A2\u6570\u304C\u3001\u30B3\u30F3\u30C6\u30CA\
    \u304C\u540C\u540D\u306E\u30E1\u30F3\u30D0\u95A2\u6570\u3092\u6301\u3064\u3068\
    \u304D\u306F\u305D\u3061\u3089\u3092\u547C\u3076\u3053\u3068\u3092\u78BA\u304B\
    \u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\
    \u3079\u3066\u671F\u5F85\u3069\u304A\u308A\u306A\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/utility/container_func.hpp\"\
    \n\n// \u8981\u7D20\u306F {3, 1, 2} \u3060\u304C\u3001\u30E1\u30F3\u30D0\u95A2\
    \u6570\u306F\u76EE\u5370\u306E\u5024\u3092\u8FD4\u3059\nstruct Base {\n    using\
    \ value_type = int;\n    std::vector<int> v{3, 1, 2};\n    auto begin() const\
    \ { return v.begin(); }\n    auto end() const { return v.end(); }\n};\nstruct\
    \ WithMax : Base {\n    int max() const { return 100; }\n};\nstruct WithMin :\
    \ Base {\n    int min() const { return -100; }\n};\nstruct WithMaxMin : Base {\n\
    \    int max() const { return 100; }\n    int min() const { return -100; }\n};\n\
    struct WithSum : Base {\n    int sum() const { return 1000; }\n};\nstruct WithProduct\
    \ : Base {\n    int product() const { return 2000; }\n};\nstruct WithProductXor\
    \ : Base {\n    int product_xor() const { return 3000; }\n};\nstruct WithSorted\
    \ : Base {\n    std::vector<int> sorted() const { return {42}; }\n};\nstruct WithReversed\
    \ : Base {\n    std::vector<int> reversed() const { return {43}; }\n};\n\nint\
    \ main() {\n    bool ok = true;\n    auto check = [&](bool cond, const char* what)\
    \ {\n        if (!cond) {\n            std::cerr << \"failed: \" << what << std::endl;\n\
    \            ok = false;\n        }\n    };\n\n    check(max(WithMax{}) == 100,\
    \ \"max \u306F\u30E1\u30F3\u30D0\u95A2\u6570 max \u3092\u547C\u3076\");\n    check(min(WithMax{})\
    \ == 1, \"max \u3060\u3051\u3092\u6301\u3064\u578B\u306E min \u306F\u8981\u7D20\
    \u306E\u6700\u5C0F\u5024\");\n    check(min(WithMin{}) == -100, \"min \u306F\u30E1\
    \u30F3\u30D0\u95A2\u6570 min \u3092\u547C\u3076\");\n    check(max(WithMin{})\
    \ == 3, \"min \u3060\u3051\u3092\u6301\u3064\u578B\u306E max \u306F\u8981\u7D20\
    \u306E\u6700\u5927\u5024\");\n    check(max(WithMaxMin{}) == 100 && min(WithMaxMin{})\
    \ == -100, \"max \u3068 min \u3092\u4E21\u65B9\u6301\u3064\u578B\");\n    check(sum(WithSum{})\
    \ == 1000, \"sum \u306F\u30E1\u30F3\u30D0\u95A2\u6570 sum \u3092\u547C\u3076\"\
    );\n    check(product(WithProduct{}) == 2000, \"product \u306F\u30E1\u30F3\u30D0\
    \u95A2\u6570 product \u3092\u547C\u3076\");\n    check(product_xor(WithProductXor{})\
    \ == 3000, \"product_xor \u306F\u30E1\u30F3\u30D0\u95A2\u6570 product_xor \u3092\
    \u547C\u3076\");\n    check(sorted(WithSorted{}) == std::vector<int>{42}, \"sorted\
    \ \u306F\u30E1\u30F3\u30D0\u95A2\u6570 sorted \u3092\u547C\u3076\");\n    check(reversed(WithReversed{})\
    \ == std::vector<int>{43}, \"reversed \u306F\u30E1\u30F3\u30D0\u95A2\u6570 reversed\
    \ \u3092\u547C\u3076\");\n    check(sum(Base{}) == 6 && product(Base{}) == 6 &&\
    \ product_xor(Base{}) == 0, \"\u30E1\u30F3\u30D0\u95A2\u6570\u3092\u6301\u305F\
    \u306A\u3044\u578B\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/utility/container_func.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/container-func-member.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 03:13:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/container-func-member.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/container-func-member.test.cpp
- /verify/test/unittest/container-func-member.test.cpp.html
title: test/unittest/container-func-member.test.cpp
---
