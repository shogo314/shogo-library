---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/repr.test.cpp
    title: test/unittest/repr.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u51FA\u529B\u3092\u305D\u306E\u307E\u307E\u30B3\u30F3\u30B9\u30C8\
      \u30E9\u30AF\u30BF\u306B\u4F7F\u3048\u308B\u6587\u5B57\u5217\u5316 (repr)"
    links: []
  bundledCode: "#line 2 \"src/base/repr.hpp\"\n\n/**\n * @file repr.hpp\n * @brief\
    \ \u51FA\u529B\u3092\u305D\u306E\u307E\u307E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u306B\u4F7F\u3048\u308B\u6587\u5B57\u5217\u5316 (repr)\n */\n\n#include\
    \ <array>\n#include <iostream>\n#include <map>\n#include <set>\n#include <sstream>\n\
    #include <string>\n#include <utility>\n#include <vector>\n#line 2 \"src/base/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n\
    #include <iterator>\n#line 11 \"src/base/traits.hpp\"\n#include <type_traits>\n\
    #line 13 \"src/base/traits.hpp\"\n\nnamespace detail {\nusing std::begin, std::end;\n\
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
    \ 17 \"src/base/repr.hpp\"\n\nnamespace detail {\n\n///////////////////////////////////////////////////////////////////\n\
    /////////////////////////// declaration ///////////////////////////\n///////////////////////////////////////////////////////////////////\n\
    \ninline std::string type_str(const char*);\ninline std::string initializer_str(const\
    \ char*);\ninline std::string repr(const char*);\n\ninline std::string type_str(const\
    \ char&);\ninline std::string initializer_str(const char&);\ninline std::string\
    \ repr(const char&);\n\ninline std::string type_str(const int&);\ninline std::string\
    \ initializer_str(const int&);\ninline std::string repr(const int&);\n\ninline\
    \ std::string type_str(const long&);\ninline std::string initializer_str(const\
    \ long&);\ninline std::string repr(const long&);\n\ninline std::string type_str(const\
    \ long long&);\ninline std::string initializer_str(const long long&);\ninline\
    \ std::string repr(const long long&);\n\ninline std::string type_str(const unsigned\
    \ int&);\ninline std::string initializer_str(const unsigned int&);\ninline std::string\
    \ repr(const unsigned int&);\n\ninline std::string type_str(const unsigned long&);\n\
    inline std::string initializer_str(const unsigned long&);\ninline std::string\
    \ repr(const unsigned long&);\n\ninline std::string type_str(const unsigned long\
    \ long&);\ninline std::string initializer_str(const unsigned long long&);\ninline\
    \ std::string repr(const unsigned long long&);\n\ninline std::string type_str(const\
    \ std::string&);\ninline std::string initializer_str(const std::string&);\ninline\
    \ std::string repr(const std::string&);\n\ninline std::string type_str(const float&);\n\
    inline std::string initializer_str(const float&);\ninline std::string repr(const\
    \ float&);\n\ninline std::string type_str(const double&);\ninline std::string\
    \ initializer_str(const double&);\ninline std::string repr(const double&);\n\n\
    inline std::string type_str(const long double&);\ninline std::string initializer_str(const\
    \ long double&);\ninline std::string repr(const long double&);\n\ntemplate <typename\
    \ T>\ninline std::string type_str(const std::vector<T>&);\ntemplate <typename\
    \ T>\ninline std::string initializer_str(const std::vector<T>&);\ntemplate <typename\
    \ T>\ninline std::string repr(const std::vector<T>&);\n\ntemplate <typename T>\n\
    inline std::string type_str(const std::set<T>&);\ntemplate <typename T>\ninline\
    \ std::string initializer_str(const std::set<T>&);\ntemplate <typename T>\ninline\
    \ std::string repr(const std::set<T>&);\n\ntemplate <typename T1, typename T2>\n\
    inline std::string type_str(const std::pair<T1, T2>&);\ntemplate <typename T1,\
    \ typename T2>\ninline std::string initializer_str(const std::pair<T1, T2>&);\n\
    template <typename T1, typename T2>\ninline std::string repr(const std::pair<T1,\
    \ T2>&);\n\ntemplate <typename T1, typename T2>\ninline std::string type_str(const\
    \ std::map<T1, T2>&);\ntemplate <typename T1, typename T2>\ninline std::string\
    \ initializer_str(const std::map<T1, T2>&);\ntemplate <typename T1, typename T2>\n\
    inline std::string repr(const std::map<T1, T2>&);\n\ntemplate <typename T, size_t\
    \ N>\ninline std::string type_str(const std::array<T, N>&);\ntemplate <typename\
    \ T, size_t N>\ninline std::string initializer_str(const std::array<T, N>&);\n\
    template <typename T, size_t N>\ninline std::string repr(const std::array<T, N>&);\n\
    \n///////////////////////////////////////////////////////////////////\n///////////////////////////\
    \ definition ////////////////////////////\n///////////////////////////////////////////////////////////////////\n\
    \ntemplate <typename T, std::enable_if_t<not has_type_str_v<T>, std::nullptr_t>\
    \ = nullptr>\ninline std::string type_str(const T& t) {\n    return \"T\";\n}\n\
    template <typename T, std::enable_if_t<has_type_str_v<T>, std::nullptr_t> = nullptr>\n\
    inline std::string type_str(const T& t) {\n    return t.type_str();\n}\ntemplate\
    \ <typename T, std::enable_if_t<not has_initializer_str_v<T>, std::nullptr_t>\
    \ = nullptr>\ninline std::string initializer_str(const T& t) {\n    return \"\
    {}\";\n}\ntemplate <typename T, std::enable_if_t<has_initializer_str_v<T>, std::nullptr_t>\
    \ = nullptr>\ninline std::string initializer_str(const T& t) {\n    return t.initializer_str();\n\
    }\ntemplate <typename T, std::enable_if_t<not has_repr_v<T>, std::nullptr_t> =\
    \ nullptr>\ninline std::string repr(const T& t) {\n    return detail::type_str(t)\
    \ + detail::initializer_str(t);\n}\ntemplate <typename T, std::enable_if_t<has_repr_v<T>,\
    \ std::nullptr_t> = nullptr>\ninline std::string repr(const T& t) {\n    return\
    \ t.repr();\n}\n\ninline std::string type_str(const char*) {\n    return \"char*\"\
    ;\n}\ninline std::string initializer_str(const char* t) {\n    return \"\\\"\"\
    \ + std::string(t) + \"\\\"\";\n}\ninline std::string repr(const char* t) {\n\
    \    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ char&) {\n    return \"char\";\n}\ninline std::string initializer_str(const\
    \ char& t) {\n    // char \u304C\u7B26\u53F7\u4ED8\u304D\u3067\u3082\u6DFB\u5B57\
    \u304C\u8CA0\u306B\u306A\u3089\u306A\u3044\u3088\u3046\u306B unsigned char \u3067\
    \u6271\u3046 (UTF-8 \u306E\u30D0\u30A4\u30C8\u306A\u3069)\n    const unsigned\
    \ char u = static_cast<unsigned char>(t);\n    std::vector<std::string> v(128,\
    \ \"\");\n    v['\\0'] = \"\\\\0\";\n    v['\\a'] = \"\\\\a\";\n    v['\\b'] =\
    \ \"\\\\b\";\n    v['\\f'] = \"\\\\f\";\n    v['\\r'] = \"\\\\r\";\n    v['\\\
    n'] = \"\\\\n\";\n    v['\\v'] = \"\\\\v\";\n    v['\\''] = \"\\\\'\";\n    v['\\\
    \\'] = \"\\\\\\\\\";\n    if (u < 128 and !v[u].empty())\n        return \"'\"\
    \ + v[u] + \"'\";\n    if (32 <= u and u <= 126)\n        return \"'\" + std::string{t}\
    \ + \"'\";\n    return \"'\\\\\" + std::to_string(u / 64) + std::to_string(u /\
    \ 8 % 8) + std::to_string(u % 8) + \"'\";\n}\ninline std::string repr(const char&\
    \ t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ int&) {\n    return \"int\";\n}\ninline std::string initializer_str(const int&\
    \ t) {\n    return std::to_string(t);\n}\ninline std::string repr(const int& t)\
    \ {\n    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ long&) {\n    return \"long\";\n}\ninline std::string initializer_str(const\
    \ long& t) {\n    return std::to_string(t) + \"l\";\n}\ninline std::string repr(const\
    \ long& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string\
    \ type_str(const long long&) {\n    return \"long long\";\n}\ninline std::string\
    \ initializer_str(const long long& t) {\n    return std::to_string(t) + \"ll\"\
    ;\n}\ninline std::string repr(const long long& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const unsigned int&) {\n    return \"unsigned\
    \ int\";\n}\ninline std::string initializer_str(const unsigned int& t) {\n   \
    \ return std::to_string(t) + \"u\";\n}\ninline std::string repr(const unsigned\
    \ int& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ unsigned long&) {\n    return \"unsigned long\";\n}\ninline std::string initializer_str(const\
    \ unsigned long& t) {\n    return std::to_string(t) + \"ul\";\n}\ninline std::string\
    \ repr(const unsigned long& t) {\n    return detail::initializer_str(t);\n}\n\n\
    inline std::string type_str(const unsigned long long&) {\n    return \"unsigned\
    \ long long\";\n}\ninline std::string initializer_str(const unsigned long long&\
    \ t) {\n    return std::to_string(t) + \"ull\";\n}\ninline std::string repr(const\
    \ unsigned long long& t) {\n    return detail::initializer_str(t);\n}\n\ninline\
    \ std::string type_str(const std::string&) {\n    return \"std::string\";\n}\n\
    inline std::string initializer_str(const std::string& t) {\n    return \"\\\"\"\
    \ + t + \"\\\"\";\n}\ninline std::string repr(const std::string& t) {\n    return\
    \ detail::type_str(t) + \"{\" + detail::initializer_str(t) + \"}\";\n}\n\ninline\
    \ std::string type_str(const float&) {\n    return \"float\";\n}\ninline std::string\
    \ initializer_str(const float& t) {\n    return std::to_string(t) + \"f\";\n}\n\
    inline std::string repr(const float& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const double&) {\n    return \"double\";\n}\n\
    inline std::string initializer_str(const double& t) {\n    return std::to_string(t);\n\
    }\ninline std::string repr(const double& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const long double&) {\n    return \"long double\"\
    ;\n}\ninline std::string initializer_str(const long double& t) {\n    return std::to_string(t)\
    \ + \"l\";\n}\ninline std::string repr(const long double& t) {\n    return detail::initializer_str(t);\n\
    }\n\ntemplate <typename T>\ninline std::string type_str(const std::vector<T>&)\
    \ {\n    T t;\n    return \"std::vector<\" + detail::type_str(t) + \">\";\n}\n\
    template <typename T>\ninline std::string initializer_str(const std::vector<T>&\
    \ t) {\n    std::string ret;\n    ret += \"{\";\n    for (auto itr = t.begin();\
    \ itr != t.end(); itr++) {\n        if (itr != t.begin()) ret += \", \";\n   \
    \     ret += detail::initializer_str(*itr);\n    }\n    ret += \"}\";\n    return\
    \ ret;\n}\ntemplate <typename T>\ninline std::string repr(const std::vector<T>&\
    \ t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n}\n\ntemplate\
    \ <typename T>\ninline std::string type_str(const std::set<T>&) {\n    T t;\n\
    \    return \"std::set<\" + detail::type_str(t) + \">\";\n}\ntemplate <typename\
    \ T>\ninline std::string initializer_str(const std::set<T>& t) {\n    std::string\
    \ ret;\n    ret += \"{\";\n    for (auto itr = t.begin(); itr != t.end(); itr++)\
    \ {\n        if (itr != t.begin()) ret += \", \";\n        ret += detail::initializer_str(*itr);\n\
    \    }\n    ret += \"}\";\n    return ret;\n}\ntemplate <typename T>\ninline std::string\
    \ repr(const std::set<T>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n\
    }\n\ntemplate <typename T1, typename T2>\ninline std::string type_str(const std::pair<T1,\
    \ T2>&) {\n    T1 t1;\n    T2 t2;\n    return \"std::pair<\" + detail::type_str(t1)\
    \ + \", \" + detail::type_str(t2) + \">\";\n}\ntemplate <typename T1, typename\
    \ T2>\ninline std::string initializer_str(const std::pair<T1, T2>& t) {\n    return\
    \ \"{\" + detail::initializer_str(t.first) + \", \" + detail::initializer_str(t.second)\
    \ + \"}\";\n}\ntemplate <typename T1, typename T2>\ninline std::string repr(const\
    \ std::pair<T1, T2>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n\
    }\n\ntemplate <typename T1, typename T2>\ninline std::string type_str(const std::map<T1,\
    \ T2>&) {\n    T1 t1;\n    T2 t2;\n    return \"std::map<\" + detail::type_str(t1)\
    \ + \", \" + detail::type_str(t2) + \">\";\n}\ntemplate <typename T1, typename\
    \ T2>\ninline std::string initializer_str(const std::map<T1, T2>& t) {\n    std::string\
    \ ret;\n    ret += \"{\";\n    for (auto itr = t.begin(); itr != t.end(); itr++)\
    \ {\n        if (itr != t.begin()) ret += \", \";\n        ret += \"{\";\n   \
    \     ret += detail::initializer_str(itr->first);\n        ret += \", \";\n  \
    \      ret += detail::initializer_str(itr->second);\n        ret += \"}\";\n \
    \   }\n    ret += \"}\";\n    return ret;\n}\ntemplate <typename T1, typename\
    \ T2>\ninline std::string repr(const std::map<T1, T2>& t) {\n    return detail::type_str(t)\
    \ + detail::initializer_str(t);\n}\n\ntemplate <typename T, size_t N>\ninline\
    \ std::string type_str(const std::array<T, N>&) {\n    T t;\n    return \"std::array<\"\
    \ + detail::type_str(t) + \", \" + std::to_string(N) + \">\";\n}\ntemplate <typename\
    \ T, size_t N>\ninline std::string initializer_str(const std::array<T, N>& t)\
    \ {\n    std::string ret;\n    ret += \"{\";\n    for (auto itr = t.begin(); itr\
    \ != t.end(); itr++) {\n        if (itr != t.begin()) ret += \", \";\n       \
    \ ret += detail::initializer_str(*itr);\n    }\n    ret += \"}\";\n    return\
    \ ret;\n}\ntemplate <typename T, size_t N>\ninline std::string repr(const std::array<T,\
    \ N>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n}\n\n\
    }  // namespace detail\n\ntemplate <typename T>\ninline std::string type_str(const\
    \ T& t) {\n    return detail::type_str(t);\n}\ntemplate <typename T>\ninline std::string\
    \ initializer_str(const T& t) {\n    return detail::initializer_str(t);\n}\ntemplate\
    \ <typename T>\ninline std::string repr(const T& t) {\n    return detail::repr(t);\n\
    }\n\n#define DEBUG(x) { std::cerr << #x << \" = \" << repr(x) << std::endl; }\n"
  code: "#pragma once\n\n/**\n * @file repr.hpp\n * @brief \u51FA\u529B\u3092\u305D\
    \u306E\u307E\u307E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u4F7F\u3048\
    \u308B\u6587\u5B57\u5217\u5316 (repr)\n */\n\n#include <array>\n#include <iostream>\n\
    #include <map>\n#include <set>\n#include <sstream>\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n#include \"traits.hpp\"\n\nnamespace detail {\n\
    \n///////////////////////////////////////////////////////////////////\n///////////////////////////\
    \ declaration ///////////////////////////\n///////////////////////////////////////////////////////////////////\n\
    \ninline std::string type_str(const char*);\ninline std::string initializer_str(const\
    \ char*);\ninline std::string repr(const char*);\n\ninline std::string type_str(const\
    \ char&);\ninline std::string initializer_str(const char&);\ninline std::string\
    \ repr(const char&);\n\ninline std::string type_str(const int&);\ninline std::string\
    \ initializer_str(const int&);\ninline std::string repr(const int&);\n\ninline\
    \ std::string type_str(const long&);\ninline std::string initializer_str(const\
    \ long&);\ninline std::string repr(const long&);\n\ninline std::string type_str(const\
    \ long long&);\ninline std::string initializer_str(const long long&);\ninline\
    \ std::string repr(const long long&);\n\ninline std::string type_str(const unsigned\
    \ int&);\ninline std::string initializer_str(const unsigned int&);\ninline std::string\
    \ repr(const unsigned int&);\n\ninline std::string type_str(const unsigned long&);\n\
    inline std::string initializer_str(const unsigned long&);\ninline std::string\
    \ repr(const unsigned long&);\n\ninline std::string type_str(const unsigned long\
    \ long&);\ninline std::string initializer_str(const unsigned long long&);\ninline\
    \ std::string repr(const unsigned long long&);\n\ninline std::string type_str(const\
    \ std::string&);\ninline std::string initializer_str(const std::string&);\ninline\
    \ std::string repr(const std::string&);\n\ninline std::string type_str(const float&);\n\
    inline std::string initializer_str(const float&);\ninline std::string repr(const\
    \ float&);\n\ninline std::string type_str(const double&);\ninline std::string\
    \ initializer_str(const double&);\ninline std::string repr(const double&);\n\n\
    inline std::string type_str(const long double&);\ninline std::string initializer_str(const\
    \ long double&);\ninline std::string repr(const long double&);\n\ntemplate <typename\
    \ T>\ninline std::string type_str(const std::vector<T>&);\ntemplate <typename\
    \ T>\ninline std::string initializer_str(const std::vector<T>&);\ntemplate <typename\
    \ T>\ninline std::string repr(const std::vector<T>&);\n\ntemplate <typename T>\n\
    inline std::string type_str(const std::set<T>&);\ntemplate <typename T>\ninline\
    \ std::string initializer_str(const std::set<T>&);\ntemplate <typename T>\ninline\
    \ std::string repr(const std::set<T>&);\n\ntemplate <typename T1, typename T2>\n\
    inline std::string type_str(const std::pair<T1, T2>&);\ntemplate <typename T1,\
    \ typename T2>\ninline std::string initializer_str(const std::pair<T1, T2>&);\n\
    template <typename T1, typename T2>\ninline std::string repr(const std::pair<T1,\
    \ T2>&);\n\ntemplate <typename T1, typename T2>\ninline std::string type_str(const\
    \ std::map<T1, T2>&);\ntemplate <typename T1, typename T2>\ninline std::string\
    \ initializer_str(const std::map<T1, T2>&);\ntemplate <typename T1, typename T2>\n\
    inline std::string repr(const std::map<T1, T2>&);\n\ntemplate <typename T, size_t\
    \ N>\ninline std::string type_str(const std::array<T, N>&);\ntemplate <typename\
    \ T, size_t N>\ninline std::string initializer_str(const std::array<T, N>&);\n\
    template <typename T, size_t N>\ninline std::string repr(const std::array<T, N>&);\n\
    \n///////////////////////////////////////////////////////////////////\n///////////////////////////\
    \ definition ////////////////////////////\n///////////////////////////////////////////////////////////////////\n\
    \ntemplate <typename T, std::enable_if_t<not has_type_str_v<T>, std::nullptr_t>\
    \ = nullptr>\ninline std::string type_str(const T& t) {\n    return \"T\";\n}\n\
    template <typename T, std::enable_if_t<has_type_str_v<T>, std::nullptr_t> = nullptr>\n\
    inline std::string type_str(const T& t) {\n    return t.type_str();\n}\ntemplate\
    \ <typename T, std::enable_if_t<not has_initializer_str_v<T>, std::nullptr_t>\
    \ = nullptr>\ninline std::string initializer_str(const T& t) {\n    return \"\
    {}\";\n}\ntemplate <typename T, std::enable_if_t<has_initializer_str_v<T>, std::nullptr_t>\
    \ = nullptr>\ninline std::string initializer_str(const T& t) {\n    return t.initializer_str();\n\
    }\ntemplate <typename T, std::enable_if_t<not has_repr_v<T>, std::nullptr_t> =\
    \ nullptr>\ninline std::string repr(const T& t) {\n    return detail::type_str(t)\
    \ + detail::initializer_str(t);\n}\ntemplate <typename T, std::enable_if_t<has_repr_v<T>,\
    \ std::nullptr_t> = nullptr>\ninline std::string repr(const T& t) {\n    return\
    \ t.repr();\n}\n\ninline std::string type_str(const char*) {\n    return \"char*\"\
    ;\n}\ninline std::string initializer_str(const char* t) {\n    return \"\\\"\"\
    \ + std::string(t) + \"\\\"\";\n}\ninline std::string repr(const char* t) {\n\
    \    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ char&) {\n    return \"char\";\n}\ninline std::string initializer_str(const\
    \ char& t) {\n    // char \u304C\u7B26\u53F7\u4ED8\u304D\u3067\u3082\u6DFB\u5B57\
    \u304C\u8CA0\u306B\u306A\u3089\u306A\u3044\u3088\u3046\u306B unsigned char \u3067\
    \u6271\u3046 (UTF-8 \u306E\u30D0\u30A4\u30C8\u306A\u3069)\n    const unsigned\
    \ char u = static_cast<unsigned char>(t);\n    std::vector<std::string> v(128,\
    \ \"\");\n    v['\\0'] = \"\\\\0\";\n    v['\\a'] = \"\\\\a\";\n    v['\\b'] =\
    \ \"\\\\b\";\n    v['\\f'] = \"\\\\f\";\n    v['\\r'] = \"\\\\r\";\n    v['\\\
    n'] = \"\\\\n\";\n    v['\\v'] = \"\\\\v\";\n    v['\\''] = \"\\\\'\";\n    v['\\\
    \\'] = \"\\\\\\\\\";\n    if (u < 128 and !v[u].empty())\n        return \"'\"\
    \ + v[u] + \"'\";\n    if (32 <= u and u <= 126)\n        return \"'\" + std::string{t}\
    \ + \"'\";\n    return \"'\\\\\" + std::to_string(u / 64) + std::to_string(u /\
    \ 8 % 8) + std::to_string(u % 8) + \"'\";\n}\ninline std::string repr(const char&\
    \ t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ int&) {\n    return \"int\";\n}\ninline std::string initializer_str(const int&\
    \ t) {\n    return std::to_string(t);\n}\ninline std::string repr(const int& t)\
    \ {\n    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ long&) {\n    return \"long\";\n}\ninline std::string initializer_str(const\
    \ long& t) {\n    return std::to_string(t) + \"l\";\n}\ninline std::string repr(const\
    \ long& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string\
    \ type_str(const long long&) {\n    return \"long long\";\n}\ninline std::string\
    \ initializer_str(const long long& t) {\n    return std::to_string(t) + \"ll\"\
    ;\n}\ninline std::string repr(const long long& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const unsigned int&) {\n    return \"unsigned\
    \ int\";\n}\ninline std::string initializer_str(const unsigned int& t) {\n   \
    \ return std::to_string(t) + \"u\";\n}\ninline std::string repr(const unsigned\
    \ int& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ unsigned long&) {\n    return \"unsigned long\";\n}\ninline std::string initializer_str(const\
    \ unsigned long& t) {\n    return std::to_string(t) + \"ul\";\n}\ninline std::string\
    \ repr(const unsigned long& t) {\n    return detail::initializer_str(t);\n}\n\n\
    inline std::string type_str(const unsigned long long&) {\n    return \"unsigned\
    \ long long\";\n}\ninline std::string initializer_str(const unsigned long long&\
    \ t) {\n    return std::to_string(t) + \"ull\";\n}\ninline std::string repr(const\
    \ unsigned long long& t) {\n    return detail::initializer_str(t);\n}\n\ninline\
    \ std::string type_str(const std::string&) {\n    return \"std::string\";\n}\n\
    inline std::string initializer_str(const std::string& t) {\n    return \"\\\"\"\
    \ + t + \"\\\"\";\n}\ninline std::string repr(const std::string& t) {\n    return\
    \ detail::type_str(t) + \"{\" + detail::initializer_str(t) + \"}\";\n}\n\ninline\
    \ std::string type_str(const float&) {\n    return \"float\";\n}\ninline std::string\
    \ initializer_str(const float& t) {\n    return std::to_string(t) + \"f\";\n}\n\
    inline std::string repr(const float& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const double&) {\n    return \"double\";\n}\n\
    inline std::string initializer_str(const double& t) {\n    return std::to_string(t);\n\
    }\ninline std::string repr(const double& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const long double&) {\n    return \"long double\"\
    ;\n}\ninline std::string initializer_str(const long double& t) {\n    return std::to_string(t)\
    \ + \"l\";\n}\ninline std::string repr(const long double& t) {\n    return detail::initializer_str(t);\n\
    }\n\ntemplate <typename T>\ninline std::string type_str(const std::vector<T>&)\
    \ {\n    T t;\n    return \"std::vector<\" + detail::type_str(t) + \">\";\n}\n\
    template <typename T>\ninline std::string initializer_str(const std::vector<T>&\
    \ t) {\n    std::string ret;\n    ret += \"{\";\n    for (auto itr = t.begin();\
    \ itr != t.end(); itr++) {\n        if (itr != t.begin()) ret += \", \";\n   \
    \     ret += detail::initializer_str(*itr);\n    }\n    ret += \"}\";\n    return\
    \ ret;\n}\ntemplate <typename T>\ninline std::string repr(const std::vector<T>&\
    \ t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n}\n\ntemplate\
    \ <typename T>\ninline std::string type_str(const std::set<T>&) {\n    T t;\n\
    \    return \"std::set<\" + detail::type_str(t) + \">\";\n}\ntemplate <typename\
    \ T>\ninline std::string initializer_str(const std::set<T>& t) {\n    std::string\
    \ ret;\n    ret += \"{\";\n    for (auto itr = t.begin(); itr != t.end(); itr++)\
    \ {\n        if (itr != t.begin()) ret += \", \";\n        ret += detail::initializer_str(*itr);\n\
    \    }\n    ret += \"}\";\n    return ret;\n}\ntemplate <typename T>\ninline std::string\
    \ repr(const std::set<T>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n\
    }\n\ntemplate <typename T1, typename T2>\ninline std::string type_str(const std::pair<T1,\
    \ T2>&) {\n    T1 t1;\n    T2 t2;\n    return \"std::pair<\" + detail::type_str(t1)\
    \ + \", \" + detail::type_str(t2) + \">\";\n}\ntemplate <typename T1, typename\
    \ T2>\ninline std::string initializer_str(const std::pair<T1, T2>& t) {\n    return\
    \ \"{\" + detail::initializer_str(t.first) + \", \" + detail::initializer_str(t.second)\
    \ + \"}\";\n}\ntemplate <typename T1, typename T2>\ninline std::string repr(const\
    \ std::pair<T1, T2>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n\
    }\n\ntemplate <typename T1, typename T2>\ninline std::string type_str(const std::map<T1,\
    \ T2>&) {\n    T1 t1;\n    T2 t2;\n    return \"std::map<\" + detail::type_str(t1)\
    \ + \", \" + detail::type_str(t2) + \">\";\n}\ntemplate <typename T1, typename\
    \ T2>\ninline std::string initializer_str(const std::map<T1, T2>& t) {\n    std::string\
    \ ret;\n    ret += \"{\";\n    for (auto itr = t.begin(); itr != t.end(); itr++)\
    \ {\n        if (itr != t.begin()) ret += \", \";\n        ret += \"{\";\n   \
    \     ret += detail::initializer_str(itr->first);\n        ret += \", \";\n  \
    \      ret += detail::initializer_str(itr->second);\n        ret += \"}\";\n \
    \   }\n    ret += \"}\";\n    return ret;\n}\ntemplate <typename T1, typename\
    \ T2>\ninline std::string repr(const std::map<T1, T2>& t) {\n    return detail::type_str(t)\
    \ + detail::initializer_str(t);\n}\n\ntemplate <typename T, size_t N>\ninline\
    \ std::string type_str(const std::array<T, N>&) {\n    T t;\n    return \"std::array<\"\
    \ + detail::type_str(t) + \", \" + std::to_string(N) + \">\";\n}\ntemplate <typename\
    \ T, size_t N>\ninline std::string initializer_str(const std::array<T, N>& t)\
    \ {\n    std::string ret;\n    ret += \"{\";\n    for (auto itr = t.begin(); itr\
    \ != t.end(); itr++) {\n        if (itr != t.begin()) ret += \", \";\n       \
    \ ret += detail::initializer_str(*itr);\n    }\n    ret += \"}\";\n    return\
    \ ret;\n}\ntemplate <typename T, size_t N>\ninline std::string repr(const std::array<T,\
    \ N>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n}\n\n\
    }  // namespace detail\n\ntemplate <typename T>\ninline std::string type_str(const\
    \ T& t) {\n    return detail::type_str(t);\n}\ntemplate <typename T>\ninline std::string\
    \ initializer_str(const T& t) {\n    return detail::initializer_str(t);\n}\ntemplate\
    \ <typename T>\ninline std::string repr(const T& t) {\n    return detail::repr(t);\n\
    }\n\n#define DEBUG(x) { std::cerr << #x << \" = \" << repr(x) << std::endl; }\n"
  dependsOn:
  - src/base/traits.hpp
  isVerificationFile: false
  path: src/base/repr.hpp
  requiredBy: []
  timestamp: '2026-10-12 20:20:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/repr.test.cpp
documentation_of: src/base/repr.hpp
layout: document
title: "\u51FA\u529B\u3092\u305D\u306E\u307E\u307E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
  \u30BF\u306B\u4F7F\u3048\u308B\u6587\u5B57\u5217\u5316 (repr)"
---

値を、型名つきの C++ の初期化式のような文字列にします。デバッグ出力で、値の中身と型をまとめて確認できます。

```cpp
repr(std::vector<int>{1, 2});           // "std::vector<int>{1, 2}"
repr(std::make_pair(1, 'x'));           // "std::pair<int, char>{1, 'x'}"
repr(3LL);                              // "3ll"
int n = 3;
DEBUG(n);                               // 標準エラー出力に "n = 3"
```

## 関数・マクロ

| 名前 | 説明 |
|---|---|
| `repr(x)` | 型名と初期化子を合わせた文字列 |
| `type_str(x)` | 型名の文字列 (`"std::vector<int>"` など) |
| `initializer_str(x)` | 初期化子の部分の文字列 (`"{1, 2}"` など) |
| `DEBUG(x)` | 標準エラー出力に `x = repr(x)` を出す |

## 対応している型

| 型 | `repr` の例 |
|---|---|
| `int` / `long` / `long long` | `3` / `3l` / `3ll` |
| `unsigned int` / `unsigned long` / `unsigned long long` | `3u` / `3ul` / `3ull` |
| `float` / `double` / `long double` | `1.500000f` / `1.500000` / `1.500000l` (`std::to_string` を使うので小数点以下 6 桁) |
| `char` | `'a'`、`'\n'` などのエスケープ、表示できない文字は 8 進数 |
| `const char*` / `std::string` | `"abc"` / `std::string{"abc"}` |
| `std::vector` / `std::set` / `std::array` / `std::map` / `std::pair` | `std::vector<int>{1, 2}` など、要素も再帰的に文字列化 |
| `repr()` などのメンバ関数を持つ型 | そのメンバ関数の結果 ([Range](range.hpp) など) |
| それ以外 | `T{}` |

自作の型でも、メンバ関数 `repr()`、または `type_str()` と `initializer_str()` を定義すれば対応できます。
