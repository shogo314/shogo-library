---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/functions.hpp
    title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax, \u4E8C\u5206\u63A2\u7D22\u306A\
      \u3069)"
  - icon: ':heavy_check_mark:'
    path: src/base/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/yosupo/sort-points-by-argument.2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <iostream>\n#include <vector>\n\n#line\
    \ 2 \"src/base/functions.hpp\"\n\n/**\n * @file functions.hpp\n * @brief \u6C4E\
    \u7528\u95A2\u6570 (chmin, chmax, \u4E8C\u5206\u63A2\u7D22\u306A\u3069)\n */\n\
    \n#line 10 \"src/base/functions.hpp\"\n#include <cmath>\n#include <numeric>\n\
    #line 2 \"src/base/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\
    \u6027\n */\n\n#include <cstddef>\n#include <iterator>\n#include <set>\n#include\
    \ <type_traits>\n#include <utility>\n\nnamespace detail {\nusing std::begin, std::end;\n\
    \ntemplate <class T, class = void>\nstruct is_range_impl : std::false_type {};\n\
    template <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace detail\n\n\
    template <class T>\nstruct is_range : detail::is_range_impl<T>::type {};\ntemplate\
    \ <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\n#define\
    \ HAS_METHOD(func_name)                                                      \
    \        \\\n    namespace detail {                                          \
    \                           \\\n    template <class T, class = void>         \
    \                                              \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : detail::has_##func_name##_impl<T>::type {};                   \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace detail {              \
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
    \                                          \\\n    struct has_##func_name : detail::has_##func_name##_impl<T,\
    \ U>::type {};                                    \\\n    template <class T, typename\
    \ U>                                                                         \
    \    \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ detail {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace detail\ntemplate <class T>\nstruct is_sorted_container\
    \ : detail::is_sorted_container_impl<T>::type {};\ntemplate <class T>\ninline\
    \ constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n#line\
    \ 13 \"src/base/functions.hpp\"\n\ntemplate <typename T1, typename T2>\ninline\
    \ constexpr bool chmin(T1 &a, T2 b) {\n    if (a > b) {\n        a = b;\n    \
    \    return true;\n    }\n    return false;\n}\n\ntemplate <typename T1, typename\
    \ T2>\ninline constexpr bool chmax(T1 &a, T2 b) {\n    if (a < b) {\n        a\
    \ = b;\n        return true;\n    }\n    return false;\n}\n\ninline constexpr\
    \ long long max(const long long &t1, const long long &t2) {\n    return std::max<long\
    \ long>(t1, t2);\n}\n\ninline constexpr long long min(const long long &t1, const\
    \ long long &t2) {\n    return std::min<long long>(t1, t2);\n}\n\nusing std::abs;\n\
    using std::gcd;\nusing std::lcm;\nusing std::size;\n\ntemplate <typename T>\n\
    constexpr T extgcd(const T &a, const T &b, T &x, T &y) {\n    T d = a;\n    if\
    \ (b != 0) {\n        d = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n\
    \    } else {\n        x = 1;\n        y = 0;\n    }\n    return d;\n}\n\n/**\n\
    \ * \u504F\u89D2\u30BD\u30FC\u30C8\n * \u53CD\u6642\u8A08\u56DE\u308A\n * x \u8EF8\
    \u6B63\u65B9\u5411\u3092\u59CB\u70B9\u3068\u3057\u3001\u96F6\u30D9\u30AF\u30C8\
    \u30EB\u306F x \u8EF8\u6B63\u65B9\u5411\u3068\u540C\u3058\u504F\u89D2\u3068\u3057\
    \u3066\u6271\u3046\n */\ntemplate <typename T, ENABLE_IF_T(std::is_integral_v<T>)>\n\
    bool argcmp(std::array<T, 2> a, std::array<T, 2> b) {\n    // \u96F6\u30D9\u30AF\
    \u30C8\u30EB\u306F\u5916\u7A4D\u3067\u6BD4\u3079\u3089\u308C\u306A\u3044\u306E\
    \u3067\u3001\u504F\u89D2 0 (x \u8EF8\u6B63\u65B9\u5411) \u3068\u3057\u3066\u5148\
    \u306B\u5224\u5B9A\u3059\u308B\n    const bool a_zero = a[0] == 0 && a[1] == 0;\n\
    \    const bool b_zero = b[0] == 0 && b[1] == 0;\n    if (b_zero) return false;\
    \  // \u504F\u89D2 0 \u3088\u308A\u5C0F\u3055\u3044\u3082\u306E\u306F\u306A\u3044\
    \n    if (a_zero) return !(b[1] == 0 && b[0] > 0);  // b \u306E\u504F\u89D2\u304C\
    \ 0 \u3088\u308A\u5927\u304D\u3044\u304B\n    T a0 = std::array<T, 2>{a[1], a[0]}\
    \ < std::array<T, 2>{0, 0};\n    T b0 = std::array<T, 2>{b[1], b[0]} < std::array<T,\
    \ 2>{0, 0};\n    if (a0 < b0) {\n        return true;\n    } else if (b0 < a0)\
    \ {\n        return false;\n    } else {\n        return b[0] * a[1] < a[0] *\
    \ b[1];\n    }\n}\n\ntemplate <typename M, typename N, class F, ENABLE_IF_T(std::is_integral_v<std::common_type_t<M,\
    \ N>> and std::is_invocable_r_v<bool, F, std::common_type_t<M, N>>)>\ninline constexpr\
    \ std::common_type_t<M, N> binary_search(const M &ok, const N &ng, F f) {\n  \
    \  std::common_type_t<M, N> _ok = ok, _ng = ng;\n    while (std::abs(_ok - _ng)\
    \ > 1) {\n        std::common_type_t<M, N> mid = (_ok + _ng) / 2;\n        if\
    \ (f(mid)) {\n            _ok = mid;\n        } else {\n            _ng = mid;\n\
    \        }\n    }\n    return _ok;\n}\n\ntemplate <typename M, typename N, class\
    \ F, ENABLE_IF_T(not std::is_integral_v<std::common_type_t<M, N>> and std::is_invocable_r_v<bool,\
    \ F, std::common_type_t<M, N>>)>\ninline constexpr std::common_type_t<M, N> binary_search(const\
    \ M &ok, const N &ng, F f) {\n    std::common_type_t<M, N> _ok = ok, _ng = ng;\n\
    \    for (int i = 0; i < 100; i++) {\n        std::common_type_t<M, N> mid = (_ok\
    \ + _ng) / 2;\n        if (f(mid)) {\n            _ok = mid;\n        } else {\n\
    \            _ng = mid;\n        }\n    }\n    return _ok;\n}\n\n/**\n * 0 <=\
    \ x < a\n */\ninline constexpr bool inrange(long long x, long long a) {\n    return\
    \ 0 <= x and x < a;\n}\n/**\n * a <= x < b\n */\ninline constexpr bool inrange(long\
    \ long x, long long a, long long b) {\n    return a <= x and x < b;\n}\n/**\n\
    \ * 0 <= x < a and 0 <= y < b\n */\ninline constexpr bool inrect(long long x,\
    \ long long y, long long a, long long b) {\n    return 0 <= x and x < a and 0\
    \ <= y and y < b;\n}\n#line 9 \"test/yosupo/sort-points-by-argument.2.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n; std::cin >> n;\n    std::vector<std::array<long long, 2>> ps(n);\n\
    \    for (auto& [x, y] : ps) std::cin >> x >> y;\n    // argcmp \u306F x \u8EF8\
    \u6B63\u65B9\u5411\u304B\u3089\u53CD\u6642\u8A08\u56DE\u308A ([0, 2\u03C0)) \u306B\
    \u4E26\u3079\u308B\n    std::sort(ps.begin(), ps.end(), [](const auto& a, const\
    \ auto& b) { return argcmp(a, b); });\n    // \u554F\u984C\u306F x <= 0, y = 0\
    \ \u306E\u534A\u76F4\u7DDA\u306E\u76F4\u5F8C\u304B\u3089 ((-\u03C0, \u03C0]) \u306A\
    \u306E\u3067\u3001y < 0 \u306E\u70B9\u3092\u5148\u982D\u306B\u79FB\u3059\n   \
    \ std::stable_partition(ps.begin(), ps.end(), [](const auto& p) { return p[1]\
    \ < 0; });\n    for (const auto& [x, y] : ps) std::cout << x << ' ' << y << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include <algorithm>\n#include <array>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../src/base/functions.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n; std::cin >> n;\n    std::vector<std::array<long\
    \ long, 2>> ps(n);\n    for (auto& [x, y] : ps) std::cin >> x >> y;\n    // argcmp\
    \ \u306F x \u8EF8\u6B63\u65B9\u5411\u304B\u3089\u53CD\u6642\u8A08\u56DE\u308A\
    \ ([0, 2\u03C0)) \u306B\u4E26\u3079\u308B\n    std::sort(ps.begin(), ps.end(),\
    \ [](const auto& a, const auto& b) { return argcmp(a, b); });\n    // \u554F\u984C\
    \u306F x <= 0, y = 0 \u306E\u534A\u76F4\u7DDA\u306E\u76F4\u5F8C\u304B\u3089 ((-\u03C0\
    , \u03C0]) \u306A\u306E\u3067\u3001y < 0 \u306E\u70B9\u3092\u5148\u982D\u306B\u79FB\
    \u3059\n    std::stable_partition(ps.begin(), ps.end(), [](const auto& p) { return\
    \ p[1] < 0; });\n    for (const auto& [x, y] : ps) std::cout << x << ' ' << y\
    \ << '\\n';\n}\n"
  dependsOn:
  - src/base/functions.hpp
  - src/base/traits.hpp
  isVerificationFile: true
  path: test/yosupo/sort-points-by-argument.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 01:36:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sort-points-by-argument.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sort-points-by-argument.2.test.cpp
- /verify/test/yosupo/sort-points-by-argument.2.test.cpp.html
title: test/yosupo/sort-points-by-argument.2.test.cpp
---
