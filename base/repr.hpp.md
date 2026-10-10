---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/traits.hpp
    title: base/traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base/repr.hpp\"\n#include <array>\n#include <iostream>\n\
    #include <map>\n#include <set>\n#include <sstream>\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"base/traits.hpp\"\n\n#include <cstddef>\n\
    #include <iterator>\n#line 6 \"base/traits.hpp\"\n#include <type_traits>\n#line\
    \ 8 \"base/traits.hpp\"\n\nnamespace detail {\nusing std::begin, std::end;\n\n\
    template <class T, class = void>\nstruct is_range_impl : std::false_type {};\n\
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
    \ 11 \"base/repr.hpp\"\n\nnamespace detail {\n\n///////////////////////////////////////////////////////////////////\n\
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
    \ char& t) {\n    std::vector<std::string> v(128, \"\");\n    v['\\0'] = \"\\\\\
    0\";\n    v['\\a'] = \"\\\\a\";\n    v['\\b'] = \"\\\\b\";\n    v['\\f'] = \"\\\
    \\f\";\n    v['\\r'] = \"\\\\r\";\n    v['\\n'] = \"\\\\n\";\n    v['\\v'] = \"\
    \\\\v\";\n    v['\\''] = \"\\\\'\";\n    v['\\\\'] = \"\\\\\\\\\";\n    if (!v[t].empty())\n\
    \        return \"'\" + v[t] + \"'\";\n    if (32 <= t and t <= 126)\n       \
    \ return \"'\" + std::string{t} + \"'\";\n    return \"'\\\\\" + std::to_string(t\
    \ / 64) + std::to_string(t / 8 % 8) + std::to_string(t % 8) + \"'\";\n}\ninline\
    \ std::string repr(const char& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const int&) {\n    return \"int\";\n}\ninline\
    \ std::string initializer_str(const int& t) {\n    return std::to_string(t);\n\
    }\ninline std::string repr(const int& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const long&) {\n    return \"long\";\n}\ninline\
    \ std::string initializer_str(const long& t) {\n    return std::to_string(t) +\
    \ \"l\";\n}\ninline std::string repr(const long& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const long long&) {\n    return \"long long\"\
    ;\n}\ninline std::string initializer_str(const long long& t) {\n    return std::to_string(t)\
    \ + \"ll\";\n}\ninline std::string repr(const long long& t) {\n    return detail::initializer_str(t);\n\
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
    \ detail::type_str(t) + detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ float&) {\n    return \"float\";\n}\ninline std::string initializer_str(const\
    \ float& t) {\n    return std::to_string(t) + \"f\";\n}\ninline std::string repr(const\
    \ float& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string\
    \ type_str(const double&) {\n    return \"double\";\n}\ninline std::string initializer_str(const\
    \ double& t) {\n    return std::to_string(t);\n}\ninline std::string repr(const\
    \ double& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string\
    \ type_str(const long double&) {\n    return \"long double\";\n}\ninline std::string\
    \ initializer_str(const long double& t) {\n    return std::to_string(t) + \"l\"\
    ;\n}\ninline std::string repr(const long double& t) {\n    return detail::initializer_str(t);\n\
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
    \ \"{\" + detail::repr(t.first) + \", \" + detail::repr(t.second) + \"}\";\n}\n\
    template <typename T1, typename T2>\ninline std::string repr(const std::pair<T1,\
    \ T2>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n}\n\
    \ntemplate <typename T1, typename T2>\ninline std::string type_str(const std::map<T1,\
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
  code: "#pragma once\n#include <array>\n#include <iostream>\n#include <map>\n#include\
    \ <set>\n#include <sstream>\n#include <string>\n#include <utility>\n#include <vector>\n\
    #include \"traits.hpp\"\n\nnamespace detail {\n\n///////////////////////////////////////////////////////////////////\n\
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
    \ char& t) {\n    std::vector<std::string> v(128, \"\");\n    v['\\0'] = \"\\\\\
    0\";\n    v['\\a'] = \"\\\\a\";\n    v['\\b'] = \"\\\\b\";\n    v['\\f'] = \"\\\
    \\f\";\n    v['\\r'] = \"\\\\r\";\n    v['\\n'] = \"\\\\n\";\n    v['\\v'] = \"\
    \\\\v\";\n    v['\\''] = \"\\\\'\";\n    v['\\\\'] = \"\\\\\\\\\";\n    if (!v[t].empty())\n\
    \        return \"'\" + v[t] + \"'\";\n    if (32 <= t and t <= 126)\n       \
    \ return \"'\" + std::string{t} + \"'\";\n    return \"'\\\\\" + std::to_string(t\
    \ / 64) + std::to_string(t / 8 % 8) + std::to_string(t % 8) + \"'\";\n}\ninline\
    \ std::string repr(const char& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const int&) {\n    return \"int\";\n}\ninline\
    \ std::string initializer_str(const int& t) {\n    return std::to_string(t);\n\
    }\ninline std::string repr(const int& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const long&) {\n    return \"long\";\n}\ninline\
    \ std::string initializer_str(const long& t) {\n    return std::to_string(t) +\
    \ \"l\";\n}\ninline std::string repr(const long& t) {\n    return detail::initializer_str(t);\n\
    }\n\ninline std::string type_str(const long long&) {\n    return \"long long\"\
    ;\n}\ninline std::string initializer_str(const long long& t) {\n    return std::to_string(t)\
    \ + \"ll\";\n}\ninline std::string repr(const long long& t) {\n    return detail::initializer_str(t);\n\
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
    \ detail::type_str(t) + detail::initializer_str(t);\n}\n\ninline std::string type_str(const\
    \ float&) {\n    return \"float\";\n}\ninline std::string initializer_str(const\
    \ float& t) {\n    return std::to_string(t) + \"f\";\n}\ninline std::string repr(const\
    \ float& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string\
    \ type_str(const double&) {\n    return \"double\";\n}\ninline std::string initializer_str(const\
    \ double& t) {\n    return std::to_string(t);\n}\ninline std::string repr(const\
    \ double& t) {\n    return detail::initializer_str(t);\n}\n\ninline std::string\
    \ type_str(const long double&) {\n    return \"long double\";\n}\ninline std::string\
    \ initializer_str(const long double& t) {\n    return std::to_string(t) + \"l\"\
    ;\n}\ninline std::string repr(const long double& t) {\n    return detail::initializer_str(t);\n\
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
    \ \"{\" + detail::repr(t.first) + \", \" + detail::repr(t.second) + \"}\";\n}\n\
    template <typename T1, typename T2>\ninline std::string repr(const std::pair<T1,\
    \ T2>& t) {\n    return detail::type_str(t) + detail::initializer_str(t);\n}\n\
    \ntemplate <typename T1, typename T2>\ninline std::string type_str(const std::map<T1,\
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
  - base/traits.hpp
  isVerificationFile: false
  path: base/repr.hpp
  requiredBy: []
  timestamp: '2026-10-10 20:42:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/repr.hpp
layout: document
redirect_from:
- /library/base/repr.hpp
- /library/base/repr.hpp.html
title: base/repr.hpp
---
