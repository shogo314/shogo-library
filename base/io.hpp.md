---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-cgl-3-a.test.cpp
    title: test/aoj-cgl-3-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-cgl-3-b.test.cpp
    title: test/aoj-cgl-3-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-cgl-3-c.test.cpp
    title: test/aoj-cgl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-convolution-mod-2-64.test.cpp
    title: test/yosupo-convolution-mod-2-64.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\
      \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9"
    links: []
  bundledCode: "#line 2 \"base/io.hpp\"\n/**\n * @file io.hpp\n * @brief \u7A7A\u767D\
    \u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\u30D0\u30FC\u30ED\
    \u30FC\u30C9\n */\n\n#include <array>\n#include <iostream>\n#include <set>\n#include\
    \ <utility>\n#include <tuple>\n#include <vector>\n\n// \u30CD\u30B9\u30C8\u3057\
    \u305F\u578B (pair<vector<int>, int> \u306A\u3069) \u3092\u6271\u3048\u308B\u3088\
    \u3046\u306B\u5148\u306B\u5BA3\u8A00\u3057\u3066\u304A\u304F\ntemplate <typename\
    \ T1, typename T2, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::pair<T1, T2>&\
    \ p);\ntemplate <typename... Types, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::tuple<Types...>&\
    \ p);\ntemplate <typename T, size_t N, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::array<T, N>&\
    \ a);\ntemplate <typename T, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::vector<T>& v);\n\
    template <typename T1, typename T2, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::pair<T1,\
    \ T2>& p);\ntemplate <typename... Types, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::tuple<Types...>&\
    \ p);\ntemplate <typename T, size_t N, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::array<T,\
    \ N>& a);\ntemplate <typename T, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::vector<T>&\
    \ v);\ntemplate <typename T, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::set<T>&\
    \ s);\n\nnamespace tuple_io {\n    template <typename Tuple, size_t I, typename\
    \ CharT, typename Traits>\n    std::basic_istream<CharT, Traits>& read_tuple(std::basic_istream<CharT,\
    \ Traits>& is, Tuple& t) {\n        is >> std::get<I>(t);\n        if constexpr\
    \ (I + 1 < std::tuple_size_v<Tuple>) {\n            return read_tuple<Tuple, I\
    \ + 1>(is, t);\n        }\n        return is;\n    }\n    template <typename Tuple,\
    \ size_t I, typename CharT, typename Traits>\n    std::basic_ostream<CharT, Traits>&\
    \ write_tuple(std::basic_ostream<CharT, Traits>& os, const Tuple& t) {\n     \
    \   os << std::get<I>(t);\n        if constexpr (I + 1 < std::tuple_size_v<Tuple>)\
    \ {\n            os << CharT(' ');\n            return write_tuple<Tuple, I +\
    \ 1>(os, t);\n        }\n        return os;\n    }\n};\n\ntemplate <typename T1,\
    \ typename T2, typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>&\
    \ operator>>(std::basic_istream<CharT, Traits>& is, std::pair<T1, T2>& p) {\n\
    \    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename... Types,\
    \ typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::tuple<Types...>& p) {\n    return tuple_io::read_tuple<std::tuple<Types...>,\
    \ 0>(is, p);\n}\ntemplate <typename T, size_t N, typename CharT, typename Traits>\n\
    std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>&\
    \ is, std::array<T, N>& a) {\n    for(auto& e : a) is >> e;\n    return is;\n\
    }\ntemplate <typename T, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::vector<T>& v)\
    \ {\n    for(auto& e : v) is >> e;\n    return is;\n}\n\ntemplate <typename T1,\
    \ typename T2, typename CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>&\
    \ operator<<(std::basic_ostream<CharT, Traits>& os, const std::pair<T1, T2>& p)\
    \ {\n    os << p.first << CharT(' ') << p.second;\n    return os;\n}\ntemplate\
    \ <typename... Types, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::tuple<Types...>&\
    \ p) {\n    return tuple_io::write_tuple<std::tuple<Types...>, 0>(os, p);\n}\n\
    template <typename T, size_t N, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::array<T,\
    \ N>& a) {\n    for(size_t i = 0; i < N; ++i) {\n        if(i) os << CharT(' ');\n\
    \        os << a[i];\n    }\n    return os;\n}\ntemplate <typename T, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::vector<T>& v) {\n    for(size_t i = 0; i < v.size();\
    \ ++i) {\n        if(i) os << CharT(' ');\n        os << v[i];\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::set<T>&\
    \ s) {\n    for(auto itr = s.begin(); itr != s.end(); ++itr) {\n        if(itr\
    \ != s.begin()) os << CharT(' ');\n        os << *itr;\n    }\n    return os;\n\
    }\n\n/**\n * @brief \u7A7A\u884C\u51FA\u529B\n */\ninline void print() { std::cout\
    \ << '\\n'; }\n/**\n * @brief \u51FA\u529B\u3057\u3066\u6539\u884C\n * \n * @tparam\
    \ T \u578B\n * @param x \u51FA\u529B\u3059\u308B\u5024\n */\ntemplate <typename\
    \ T>\nvoid print(const T& x) { std::cout << x << '\\n'; }\n/**\n * @brief \u7A7A\
    \u767D\u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n * \n * @tparam\
    \ T 1\u3064\u76EE\u306E\u8981\u7D20\u306E\u578B\n * @tparam Tail 2\u3064\u76EE\
    \u4EE5\u964D\u306E\u8981\u7D20\u306E\u578B\n * @param x 1\u3064\u76EE\u306E\u8981\
    \u7D20\n * @param tail 2\u3064\u76EE\u4EE5\u964D\u306E\u8981\u7D20\n */\ntemplate\
    \ <typename T, typename... Tail>\nvoid print(const T& x, const Tail&... tail)\
    \ {\n    std::cout << x << ' ';\n    print(tail...);\n}\n\n/**\n * @brief \u6A19\
    \u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u7A7A\u884C\u51FA\u529B\n */\ninline\
    \ void err() { std::cerr << std::endl; }\n/**\n * @brief \u6A19\u6E96\u30A8\u30E9\
    \u30FC\u51FA\u529B\u306B\u51FA\u529B\u3057\u3066\u6539\u884C\n *\n * @tparam T\
    \ \u578B\n * @param x \u51FA\u529B\u3059\u308B\u5024\n */\ntemplate <typename\
    \ T>\nvoid err(const T& x) { std::cerr << x << std::endl; }\n/**\n * @brief \u6A19\
    \u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u7A7A\u767D\u533A\u5207\u308A\u3067\
    \u51FA\u529B\u3057\u3066\u6539\u884C\n *\n * @tparam T 1\u3064\u76EE\u306E\u8981\
    \u7D20\u306E\u578B\n * @tparam Tail 2\u3064\u76EE\u4EE5\u964D\u306E\u8981\u7D20\
    \u306E\u578B\n * @param x 1\u3064\u76EE\u306E\u8981\u7D20\n * @param tail 2\u3064\
    \u76EE\u4EE5\u964D\u306E\u8981\u7D20\n */\ntemplate <typename T, typename... Tail>\n\
    void err(const T& x, const Tail&... tail) {\n    std::cerr << x << ' ';\n    err(tail...);\n\
    }\n"
  code: "#pragma once\n/**\n * @file io.hpp\n * @brief \u7A7A\u767D\u533A\u5207\u308A\
    \u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\n */\n\
    \n#include <array>\n#include <iostream>\n#include <set>\n#include <utility>\n\
    #include <tuple>\n#include <vector>\n\n// \u30CD\u30B9\u30C8\u3057\u305F\u578B\
    \ (pair<vector<int>, int> \u306A\u3069) \u3092\u6271\u3048\u308B\u3088\u3046\u306B\
    \u5148\u306B\u5BA3\u8A00\u3057\u3066\u304A\u304F\ntemplate <typename T1, typename\
    \ T2, typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::pair<T1, T2>& p);\ntemplate <typename... Types, typename CharT,\
    \ typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::tuple<Types...>& p);\ntemplate <typename T, size_t N, typename\
    \ CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::array<T, N>& a);\ntemplate <typename T, typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v);\ntemplate <typename T1, typename T2, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::pair<T1, T2>& p);\ntemplate <typename... Types, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::tuple<Types...>& p);\ntemplate <typename T, size_t N,\
    \ typename CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::array<T, N>& a);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::vector<T>& v);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s);\n\nnamespace tuple_io {\n    template <typename\
    \ Tuple, size_t I, typename CharT, typename Traits>\n    std::basic_istream<CharT,\
    \ Traits>& read_tuple(std::basic_istream<CharT, Traits>& is, Tuple& t) {\n   \
    \     is >> std::get<I>(t);\n        if constexpr (I + 1 < std::tuple_size_v<Tuple>)\
    \ {\n            return read_tuple<Tuple, I + 1>(is, t);\n        }\n        return\
    \ is;\n    }\n    template <typename Tuple, size_t I, typename CharT, typename\
    \ Traits>\n    std::basic_ostream<CharT, Traits>& write_tuple(std::basic_ostream<CharT,\
    \ Traits>& os, const Tuple& t) {\n        os << std::get<I>(t);\n        if constexpr\
    \ (I + 1 < std::tuple_size_v<Tuple>) {\n            os << CharT(' ');\n      \
    \      return write_tuple<Tuple, I + 1>(os, t);\n        }\n        return os;\n\
    \    }\n};\n\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>&\
    \ is, std::pair<T1, T2>& p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename... Types, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::tuple<Types...>&\
    \ p) {\n    return tuple_io::read_tuple<std::tuple<Types...>, 0>(is, p);\n}\n\
    template <typename T, size_t N, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::array<T, N>&\
    \ a) {\n    for(auto& e : a) is >> e;\n    return is;\n}\ntemplate <typename T,\
    \ typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v) {\n    for(auto& e : v) is >> e;\n    return\
    \ is;\n}\n\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::pair<T1, T2>& p) {\n    os << p.first << CharT(' ') << p.second;\n\
    \    return os;\n}\ntemplate <typename... Types, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::tuple<Types...>& p) {\n    return tuple_io::write_tuple<std::tuple<Types...>,\
    \ 0>(os, p);\n}\ntemplate <typename T, size_t N, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::array<T, N>& a) {\n    for(size_t i = 0; i < N; ++i) {\n    \
    \    if(i) os << CharT(' ');\n        os << a[i];\n    }\n    return os;\n}\n\
    template <typename T, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::vector<T>&\
    \ v) {\n    for(size_t i = 0; i < v.size(); ++i) {\n        if(i) os << CharT('\
    \ ');\n        os << v[i];\n    }\n    return os;\n}\ntemplate <typename T, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s) {\n    for(auto itr = s.begin(); itr != s.end();\
    \ ++itr) {\n        if(itr != s.begin()) os << CharT(' ');\n        os << *itr;\n\
    \    }\n    return os;\n}\n\n/**\n * @brief \u7A7A\u884C\u51FA\u529B\n */\ninline\
    \ void print() { std::cout << '\\n'; }\n/**\n * @brief \u51FA\u529B\u3057\u3066\
    \u6539\u884C\n * \n * @tparam T \u578B\n * @param x \u51FA\u529B\u3059\u308B\u5024\
    \n */\ntemplate <typename T>\nvoid print(const T& x) { std::cout << x << '\\n';\
    \ }\n/**\n * @brief \u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3066\
    \u6539\u884C\n * \n * @tparam T 1\u3064\u76EE\u306E\u8981\u7D20\u306E\u578B\n\
    \ * @tparam Tail 2\u3064\u76EE\u4EE5\u964D\u306E\u8981\u7D20\u306E\u578B\n * @param\
    \ x 1\u3064\u76EE\u306E\u8981\u7D20\n * @param tail 2\u3064\u76EE\u4EE5\u964D\u306E\
    \u8981\u7D20\n */\ntemplate <typename T, typename... Tail>\nvoid print(const T&\
    \ x, const Tail&... tail) {\n    std::cout << x << ' ';\n    print(tail...);\n\
    }\n\n/**\n * @brief \u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u7A7A\u884C\
    \u51FA\u529B\n */\ninline void err() { std::cerr << std::endl; }\n/**\n * @brief\
    \ \u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u51FA\u529B\u3057\u3066\u6539\
    \u884C\n *\n * @tparam T \u578B\n * @param x \u51FA\u529B\u3059\u308B\u5024\n\
    \ */\ntemplate <typename T>\nvoid err(const T& x) { std::cerr << x << std::endl;\
    \ }\n/**\n * @brief \u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u7A7A\u767D\
    \u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n *\n * @tparam T\
    \ 1\u3064\u76EE\u306E\u8981\u7D20\u306E\u578B\n * @tparam Tail 2\u3064\u76EE\u4EE5\
    \u964D\u306E\u8981\u7D20\u306E\u578B\n * @param x 1\u3064\u76EE\u306E\u8981\u7D20\
    \n * @param tail 2\u3064\u76EE\u4EE5\u964D\u306E\u8981\u7D20\n */\ntemplate <typename\
    \ T, typename... Tail>\nvoid err(const T& x, const Tail&... tail) {\n    std::cerr\
    \ << x << ' ';\n    err(tail...);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: base/io.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-cgl-3-a.test.cpp
  - test/aoj-cgl-3-b.test.cpp
  - test/yosupo-convolution-mod-2-64.test.cpp
  - test/aoj-cgl-3-c.test.cpp
documentation_of: base/io.hpp
layout: document
redirect_from:
- /library/base/io.hpp
- /library/base/io.hpp.html
title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\
  \u30D0\u30FC\u30ED\u30FC\u30C9"
---
