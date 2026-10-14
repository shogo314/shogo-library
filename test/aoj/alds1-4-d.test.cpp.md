---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/binary-search.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D
  bundledCode: "#line 1 \"test/aoj/alds1-4-d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/utility/binary-search.hpp\"\
    \n\n/**\n * @file binary-search.hpp\n * @brief \u4E8C\u5206\u63A2\u7D22\n */\n\
    \n#include <cmath>\n#include <type_traits>\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n\
    #include <iterator>\n#include <set>\n#line 12 \"src/utility/traits.hpp\"\n#include\
    \ <utility>\n\nnamespace internal_traits {\nusing std::begin, std::end;\n\ntemplate\
    \ <class T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    #line 12 \"src/utility/binary-search.hpp\"\n\n/**\n * f(ok) \u304C\u771F\u3001\
    f(ng) \u304C\u507D\u3068\u3057\u3066\u3001\u5883\u754C\u3067 f \u304C\u771F\u306B\
    \u306A\u308B\u5074\u306E\u5024\u3092\u8FD4\u3059\n * \u6574\u6570\u306A\u3089\
    \ ok \u3068 ng \u306E\u5DEE\u304C 1 \u306B\u306A\u308B\u307E\u3067\u3001\u6D6E\
    \u52D5\u5C0F\u6570\u70B9\u6570\u306A\u3089 100 \u56DE\u4E8C\u5206\u3059\u308B\n\
    \ */\ntemplate <typename M, typename N, class F, ENABLE_IF_T(std::is_integral_v<std::common_type_t<M,\
    \ N>>and std::is_invocable_r_v<bool, F, std::common_type_t<M, N>>)>\ninline constexpr\
    \ std::common_type_t<M, N> binary_search(const M& ok, const N& ng, F f) {\n  \
    \  std::common_type_t<M, N> _ok = ok, _ng = ng;\n    while (std::abs(_ok - _ng)\
    \ > 1) {\n        std::common_type_t<M, N> mid = (_ok + _ng) / 2;\n        if\
    \ (f(mid)) {\n            _ok = mid;\n        } else {\n            _ng = mid;\n\
    \        }\n    }\n    return _ok;\n}\n\ntemplate <typename M, typename N, class\
    \ F, ENABLE_IF_T(!std::is_integral_v<std::common_type_t<M, N>> && std::is_invocable_r_v<bool,\
    \ F, std::common_type_t<M, N>>)>\ninline constexpr std::common_type_t<M, N> binary_search(const\
    \ M& ok, const N& ng, F f) {\n    std::common_type_t<M, N> _ok = ok, _ng = ng;\n\
    \    for (int i = 0; i < 100; i++) {\n        std::common_type_t<M, N> mid = (_ok\
    \ + _ng) / 2;\n        if (f(mid)) {\n            _ok = mid;\n        } else {\n\
    \            _ng = mid;\n        }\n    }\n    return _ok;\n}\n#line 7 \"test/aoj/alds1-4-d.test.cpp\"\
    \n\nint main() {\n    int n, k;\n    std::cin >> n >> k;\n    std::vector<long\
    \ long> w(n);\n    for (auto& x : w) std::cin >> x;\n    // \u6700\u5927\u7A4D\
    \u8F09\u91CF P \u3067 k \u53F0\u306B\u7A4D\u3081\u308B\u304B\n    auto can = [&](long\
    \ long p) {\n        int cnt = 1;\n        long long cur = 0;\n        for (long\
    \ long x : w) {\n            if (x > p) return false;\n            if (cur + x\
    \ > p) {\n                cnt++;\n                cur = 0;\n            }\n  \
    \          cur += x;\n        }\n        return cnt <= k;\n    };\n    // \u7A4D\
    \u3081\u306A\u3044 P (ng) \u3068\u7A4D\u3081\u308B P (ok) \u306E\u5883\u754C\u3092\
    \u4E8C\u5206\u63A2\u7D22\u3059\u308B\n    long long ng = 0, ok = 100000LL * 10000LL;\n\
    \    std::cout << binary_search(ok, ng, can) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/utility/binary-search.hpp\"\
    \n\nint main() {\n    int n, k;\n    std::cin >> n >> k;\n    std::vector<long\
    \ long> w(n);\n    for (auto& x : w) std::cin >> x;\n    // \u6700\u5927\u7A4D\
    \u8F09\u91CF P \u3067 k \u53F0\u306B\u7A4D\u3081\u308B\u304B\n    auto can = [&](long\
    \ long p) {\n        int cnt = 1;\n        long long cur = 0;\n        for (long\
    \ long x : w) {\n            if (x > p) return false;\n            if (cur + x\
    \ > p) {\n                cnt++;\n                cur = 0;\n            }\n  \
    \          cur += x;\n        }\n        return cnt <= k;\n    };\n    // \u7A4D\
    \u3081\u306A\u3044 P (ng) \u3068\u7A4D\u3081\u308B P (ok) \u306E\u5883\u754C\u3092\
    \u4E8C\u5206\u63A2\u7D22\u3059\u308B\n    long long ng = 0, ok = 100000LL * 10000LL;\n\
    \    std::cout << binary_search(ok, ng, can) << '\\n';\n}\n"
  dependsOn:
  - src/utility/binary-search.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/aoj/alds1-4-d.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1-4-d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1-4-d.test.cpp
- /verify/test/aoj/alds1-4-d.test.cpp.html
title: test/aoj/alds1-4-d.test.cpp
---
