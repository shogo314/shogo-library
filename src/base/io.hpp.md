---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/base/macro.hpp
    title: "\u30DE\u30AF\u30ED (rep \u306A\u3069)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/cgl-3-a.test.cpp
    title: test/aoj/cgl/cgl-3-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/cgl-3-b.test.cpp
    title: test/aoj/cgl/cgl-3-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/cgl-3-c.test.cpp
    title: test/aoj/cgl/cgl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/cgl-4-b.test.cpp
    title: test/aoj/cgl/cgl-4-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/cgl-4-c.test.cpp
    title: test/aoj/cgl/cgl-4-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/cgl-7-h.test.cpp
    title: test/aoj/cgl/cgl-7-h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1/itp1-2-c.test.cpp
    title: test/aoj/itp1/itp1-2-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1/itp1-6-a.test.cpp
    title: test/aoj/itp1/itp1-6-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2/itp2-5-a.1.test.cpp
    title: test/aoj/itp2/itp2-5-a.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2/itp2-5-b.test.cpp
    title: test/aoj/itp2/itp2-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/volume11/1160.test.cpp
    title: test/aoj/volume11/1160.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/base/io.test.cpp
    title: test/unittest/base/io.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/base/macro.test.cpp
    title: test/unittest/base/macro.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution/convolution-mod-2-64.1.test.cpp
    title: test/yosupo/convolution/convolution-mod-2-64.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sample/many-aplusb-128bit.test.cpp
    title: test/yosupo/sample/many-aplusb-128bit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\
      \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9"
    links: []
  bundledCode: "#line 2 \"src/base/io.hpp\"\n/**\n * @file io.hpp\n * @brief \u7A7A\
    \u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\u30D0\u30FC\
    \u30ED\u30FC\u30C9\n */\n\n#include <algorithm>\n#include <array>\n#include <cstddef>\n\
    #include <iostream>\n#include <set>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace internal_io {\n// 128 bit \u306E\u5272\
    \u308A\u7B97\u306F\u9045\u3044\u306E\u3067\u300118 \u6841\u305A\u3064 64 bit \u3067\
    \u6271\u3046\nconstexpr unsigned long long POW10_18 = 1000000000000000000ULL;\n\
    // \u7A7A\u767D\u3067\u533A\u5207\u3089\u308C\u305F 1 \u8A9E\u3092 10 \u9032\u306E\
    \u6574\u6570\u3068\u3057\u3066\u8AAD\u3080\u3002\u6570\u3067\u306A\u3044\u3001\
    \u307E\u305F\u306F lim \u3092\u8D85\u3048\u308B\u306A\u3089 false\ntemplate <typename\
    \ CharT, typename Traits>\nbool read_u128(std::basic_istream<CharT, Traits>& is,\
    \ unsigned __int128& x, bool& neg, unsigned __int128 pos_max, unsigned __int128\
    \ neg_max) {\n    std::basic_string<CharT, Traits> s;\n    if (!(is >> s)) return\
    \ false;\n    std::size_t i = 0;\n    neg = false;\n    if (s[0] == CharT('-')\
    \ || s[0] == CharT('+')) neg = s[i++] == CharT('-');\n    if (i == s.size()) return\
    \ false;\n    for (std::size_t j = i; j < s.size(); j++) {\n        if (s[j] <\
    \ CharT('0') || CharT('9') < s[j]) return false;\n    }\n    while (i + 1 < s.size()\
    \ && s[i] == CharT('0')) i++;\n    // 39 \u6841\u306A\u3089 2^128 \u3092\u8D85\
    \u3048\u308B\u3053\u3068\u304C\u3042\u308B\u306E\u3067\u3001\u6700\u5F8C\u306E\
    \ 1 \u6841\u306E\u524D\u3067\u6BD4\u3079\u308B\u300240 \u6841\u4EE5\u4E0A\u306F\
    \u5FC5\u305A\u7BC4\u56F2\u5916\n    const std::size_t len = s.size() - i;\n  \
    \  if (len > 39) return false;\n    const unsigned __int128 lim = neg ? neg_max\
    \ : pos_max;\n    const std::size_t safe = len == 39 ? s.size() - 1 : s.size();\n\
    \    x = 0;\n    while (i < safe) {\n        const std::size_t k = std::min<std::size_t>(18,\
    \ safe - i);\n        unsigned long long c = 0, p = 1;\n        for (std::size_t\
    \ j = 0; j < k; j++, i++) c = c * 10 + (s[i] - CharT('0')), p *= 10;\n       \
    \ x = x * p + c;\n    }\n    if (len == 39) {\n        const unsigned d = s[i]\
    \ - CharT('0');\n        if (x > lim / 10 || x * 10 > lim - d) return false;\n\
    \        x = x * 10 + d;\n    }\n    return x <= lim;\n}\n// x < 10^18 \u3092\u66F8\
    \u304F\u3002pad \u306A\u3089 18 \u6841\u306B\u306A\u308B\u3088\u3046 0 \u3067\u57CB\
    \u3081\u308B\u3002\u672B\u5C3E\u304B\u3089\u66F8\u3044\u3066\u5148\u982D\u3092\
    \u8FD4\u3059\ninline char* write_u64(char* end, unsigned long long x, bool pad)\
    \ {\n    char* p = end;\n    do {\n        *--p = static_cast<char>('0' + x %\
    \ 10);\n        x /= 10;\n    } while (x > 0);\n    if (pad) {\n        while\
    \ (p > end - 18) *--p = '0';\n    }\n    return p;\n}\ntemplate <typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& write_u128(std::basic_ostream<CharT,\
    \ Traits>& os, unsigned __int128 x, bool neg) {\n    char buf[41];\n    char*\
    \ p = buf + 40;\n    *p = '\\0';\n    if (x < POW10_18) {\n        p = write_u64(p,\
    \ static_cast<unsigned long long>(x), false);\n    } else {\n        const unsigned\
    \ __int128 q = x / POW10_18;\n        p = write_u64(p, static_cast<unsigned long\
    \ long>(x - q * POW10_18), true);\n        if (q < POW10_18) {\n            p\
    \ = write_u64(p, static_cast<unsigned long long>(q), false);\n        } else {\n\
    \            const unsigned long long hi = static_cast<unsigned long long>(q /\
    \ POW10_18);\n            p = write_u64(p, static_cast<unsigned long long>(q -\
    \ static_cast<unsigned __int128>(hi) * POW10_18), true);\n            p = write_u64(p,\
    \ hi, false);\n        }\n    }\n    if (neg) *--p = '-';\n    return os << p;\n\
    }\n}  // namespace internal_io\n\n// 128 bit \u6574\u6570\u306E\u5165\u51FA\u529B\
    \ (GNU \u62E1\u5F35)\u3002std::basic_istream / std::basic_ostream \u306B\u306F\
    \u7528\u610F\u3055\u308C\u3066\u3044\u306A\u3044\ntemplate <typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, __int128_t& x) {\n    const unsigned __int128 pos_max = static_cast<unsigned\
    \ __int128>(-1) >> 1;\n    unsigned __int128 u;\n    bool neg;\n    if (internal_io::read_u128(is,\
    \ u, neg, pos_max, pos_max + 1)) {\n        x = neg ? static_cast<__int128_t>(-u)\
    \ : static_cast<__int128_t>(u);\n    } else {\n        x = 0;\n        is.setstate(std::ios_base::failbit);\n\
    \    }\n    return is;\n}\ntemplate <typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, __uint128_t& x) {\n\
    \    unsigned __int128 u;\n    bool neg;\n    if (internal_io::read_u128(is, u,\
    \ neg, static_cast<unsigned __int128>(-1), 0)) {\n        x = u;\n    } else {\n\
    \        x = 0;\n        is.setstate(std::ios_base::failbit);\n    }\n    return\
    \ is;\n}\ntemplate <typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, __int128_t x) {\n\
    \    // -x \u306F\u6700\u5C0F\u5024\u3067\u3042\u3075\u308C\u308B\u306E\u3067\u3001\
    \u7B26\u53F7\u306A\u3057\u3067\u7B26\u53F7\u3092\u53CD\u8EE2\u3059\u308B\n   \
    \ return internal_io::write_u128(os, x < 0 ? -static_cast<unsigned __int128>(x)\
    \ : static_cast<unsigned __int128>(x), x < 0);\n}\ntemplate <typename CharT, typename\
    \ Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, __uint128_t x) {\n    return internal_io::write_u128(os, x, false);\n\
    }\n\n// \u30CD\u30B9\u30C8\u3057\u305F\u578B (pair<vector<int>, int> \u306A\u3069\
    ) \u3092\u6271\u3048\u308B\u3088\u3046\u306B\u5148\u306B\u5BA3\u8A00\u3057\u3066\
    \u304A\u304F\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>&\
    \ is, std::pair<T1, T2>& p);\ntemplate <typename... Types, typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::tuple<Types...>& p);\ntemplate <typename T, std::size_t N,\
    \ typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::array<T, N>& a);\ntemplate <typename T, typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v);\ntemplate <typename T1, typename T2, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::pair<T1, T2>& p);\ntemplate <typename... Types, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::tuple<Types...>& p);\ntemplate <typename T, std::size_t\
    \ N, typename CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::array<T, N>& a);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::vector<T>& v);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s);\n\nnamespace internal_io {\ntemplate <typename\
    \ Tuple, std::size_t I, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& read_tuple(std::basic_istream<CharT, Traits>& is, Tuple& t) {\n   \
    \ is >> std::get<I>(t);\n    if constexpr (I + 1 < std::tuple_size_v<Tuple>) {\n\
    \        return read_tuple<Tuple, I + 1>(is, t);\n    }\n    return is;\n}\ntemplate\
    \ <typename Tuple, std::size_t I, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& write_tuple(std::basic_ostream<CharT, Traits>& os, const Tuple& t)\
    \ {\n    os << std::get<I>(t);\n    if constexpr (I + 1 < std::tuple_size_v<Tuple>)\
    \ {\n        os << CharT(' ');\n        return write_tuple<Tuple, I + 1>(os, t);\n\
    \    }\n    return os;\n}\n};  // namespace internal_io\n\ntemplate <typename\
    \ T1, typename T2, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::pair<T1, T2>&\
    \ p) {\n    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename...\
    \ Types, typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>&\
    \ operator>>(std::basic_istream<CharT, Traits>& is, std::tuple<Types...>& p) {\n\
    \    return internal_io::read_tuple<std::tuple<Types...>, 0>(is, p);\n}\ntemplate\
    \ <typename T, std::size_t N, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::array<T, N>&\
    \ a) {\n    for (auto& e : a) is >> e;\n    return is;\n}\ntemplate <typename\
    \ T, typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v) {\n    for (auto& e : v) is >> e;\n    return\
    \ is;\n}\n\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::pair<T1, T2>& p) {\n    os << p.first << CharT(' ') << p.second;\n\
    \    return os;\n}\ntemplate <typename... Types, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::tuple<Types...>& p) {\n    return internal_io::write_tuple<std::tuple<Types...>,\
    \ 0>(os, p);\n}\ntemplate <typename T, std::size_t N, typename CharT, typename\
    \ Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::array<T, N>& a) {\n    for (std::size_t i = 0; i < N;\
    \ ++i) {\n        if (i) os << CharT(' ');\n        os << a[i];\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::vector<T>&\
    \ v) {\n    for (std::size_t i = 0; i < v.size(); ++i) {\n        if (i) os <<\
    \ CharT(' ');\n        os << v[i];\n    }\n    return os;\n}\ntemplate <typename\
    \ T, typename CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s) {\n    for (auto itr = s.begin(); itr !=\
    \ s.end(); ++itr) {\n        if (itr != s.begin()) os << CharT(' ');\n       \
    \ os << *itr;\n    }\n    return os;\n}\n\n/**\n * @brief \u7A7A\u884C\u51FA\u529B\
    \n */\ninline void print() { std::cout << '\\n'; }\n/**\n * @brief \u51FA\u529B\
    \u3057\u3066\u6539\u884C\n *\n * @tparam T \u578B\n * @param x \u51FA\u529B\u3059\
    \u308B\u5024\n */\ntemplate <typename T>\nvoid print(const T& x) { std::cout <<\
    \ x << '\\n'; }\n/**\n * @brief \u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\
    \u3057\u3066\u6539\u884C\n *\n * @tparam T 1\u3064\u76EE\u306E\u8981\u7D20\u306E\
    \u578B\n * @tparam Tail 2\u3064\u76EE\u4EE5\u964D\u306E\u8981\u7D20\u306E\u578B\
    \n * @param x 1\u3064\u76EE\u306E\u8981\u7D20\n * @param tail 2\u3064\u76EE\u4EE5\
    \u964D\u306E\u8981\u7D20\n */\ntemplate <typename T, typename... Tail>\nvoid print(const\
    \ T& x, const Tail&... tail) {\n    std::cout << x << ' ';\n    print(tail...);\n\
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
  code: "#pragma once\n/**\n * @file io.hpp\n * @brief \u7A7A\u767D\u533A\u5207\u308A\
    \u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\n */\n\
    \n#include <algorithm>\n#include <array>\n#include <cstddef>\n#include <iostream>\n\
    #include <set>\n#include <string>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace internal_io {\n// 128 bit \u306E\u5272\u308A\u7B97\u306F\
    \u9045\u3044\u306E\u3067\u300118 \u6841\u305A\u3064 64 bit \u3067\u6271\u3046\n\
    constexpr unsigned long long POW10_18 = 1000000000000000000ULL;\n// \u7A7A\u767D\
    \u3067\u533A\u5207\u3089\u308C\u305F 1 \u8A9E\u3092 10 \u9032\u306E\u6574\u6570\
    \u3068\u3057\u3066\u8AAD\u3080\u3002\u6570\u3067\u306A\u3044\u3001\u307E\u305F\
    \u306F lim \u3092\u8D85\u3048\u308B\u306A\u3089 false\ntemplate <typename CharT,\
    \ typename Traits>\nbool read_u128(std::basic_istream<CharT, Traits>& is, unsigned\
    \ __int128& x, bool& neg, unsigned __int128 pos_max, unsigned __int128 neg_max)\
    \ {\n    std::basic_string<CharT, Traits> s;\n    if (!(is >> s)) return false;\n\
    \    std::size_t i = 0;\n    neg = false;\n    if (s[0] == CharT('-') || s[0]\
    \ == CharT('+')) neg = s[i++] == CharT('-');\n    if (i == s.size()) return false;\n\
    \    for (std::size_t j = i; j < s.size(); j++) {\n        if (s[j] < CharT('0')\
    \ || CharT('9') < s[j]) return false;\n    }\n    while (i + 1 < s.size() && s[i]\
    \ == CharT('0')) i++;\n    // 39 \u6841\u306A\u3089 2^128 \u3092\u8D85\u3048\u308B\
    \u3053\u3068\u304C\u3042\u308B\u306E\u3067\u3001\u6700\u5F8C\u306E 1 \u6841\u306E\
    \u524D\u3067\u6BD4\u3079\u308B\u300240 \u6841\u4EE5\u4E0A\u306F\u5FC5\u305A\u7BC4\
    \u56F2\u5916\n    const std::size_t len = s.size() - i;\n    if (len > 39) return\
    \ false;\n    const unsigned __int128 lim = neg ? neg_max : pos_max;\n    const\
    \ std::size_t safe = len == 39 ? s.size() - 1 : s.size();\n    x = 0;\n    while\
    \ (i < safe) {\n        const std::size_t k = std::min<std::size_t>(18, safe -\
    \ i);\n        unsigned long long c = 0, p = 1;\n        for (std::size_t j =\
    \ 0; j < k; j++, i++) c = c * 10 + (s[i] - CharT('0')), p *= 10;\n        x =\
    \ x * p + c;\n    }\n    if (len == 39) {\n        const unsigned d = s[i] - CharT('0');\n\
    \        if (x > lim / 10 || x * 10 > lim - d) return false;\n        x = x *\
    \ 10 + d;\n    }\n    return x <= lim;\n}\n// x < 10^18 \u3092\u66F8\u304F\u3002\
    pad \u306A\u3089 18 \u6841\u306B\u306A\u308B\u3088\u3046 0 \u3067\u57CB\u3081\u308B\
    \u3002\u672B\u5C3E\u304B\u3089\u66F8\u3044\u3066\u5148\u982D\u3092\u8FD4\u3059\
    \ninline char* write_u64(char* end, unsigned long long x, bool pad) {\n    char*\
    \ p = end;\n    do {\n        *--p = static_cast<char>('0' + x % 10);\n      \
    \  x /= 10;\n    } while (x > 0);\n    if (pad) {\n        while (p > end - 18)\
    \ *--p = '0';\n    }\n    return p;\n}\ntemplate <typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& write_u128(std::basic_ostream<CharT, Traits>&\
    \ os, unsigned __int128 x, bool neg) {\n    char buf[41];\n    char* p = buf +\
    \ 40;\n    *p = '\\0';\n    if (x < POW10_18) {\n        p = write_u64(p, static_cast<unsigned\
    \ long long>(x), false);\n    } else {\n        const unsigned __int128 q = x\
    \ / POW10_18;\n        p = write_u64(p, static_cast<unsigned long long>(x - q\
    \ * POW10_18), true);\n        if (q < POW10_18) {\n            p = write_u64(p,\
    \ static_cast<unsigned long long>(q), false);\n        } else {\n            const\
    \ unsigned long long hi = static_cast<unsigned long long>(q / POW10_18);\n   \
    \         p = write_u64(p, static_cast<unsigned long long>(q - static_cast<unsigned\
    \ __int128>(hi) * POW10_18), true);\n            p = write_u64(p, hi, false);\n\
    \        }\n    }\n    if (neg) *--p = '-';\n    return os << p;\n}\n}  // namespace\
    \ internal_io\n\n// 128 bit \u6574\u6570\u306E\u5165\u51FA\u529B (GNU \u62E1\u5F35\
    )\u3002std::basic_istream / std::basic_ostream \u306B\u306F\u7528\u610F\u3055\u308C\
    \u3066\u3044\u306A\u3044\ntemplate <typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, __int128_t& x) {\n\
    \    const unsigned __int128 pos_max = static_cast<unsigned __int128>(-1) >> 1;\n\
    \    unsigned __int128 u;\n    bool neg;\n    if (internal_io::read_u128(is, u,\
    \ neg, pos_max, pos_max + 1)) {\n        x = neg ? static_cast<__int128_t>(-u)\
    \ : static_cast<__int128_t>(u);\n    } else {\n        x = 0;\n        is.setstate(std::ios_base::failbit);\n\
    \    }\n    return is;\n}\ntemplate <typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, __uint128_t& x) {\n\
    \    unsigned __int128 u;\n    bool neg;\n    if (internal_io::read_u128(is, u,\
    \ neg, static_cast<unsigned __int128>(-1), 0)) {\n        x = u;\n    } else {\n\
    \        x = 0;\n        is.setstate(std::ios_base::failbit);\n    }\n    return\
    \ is;\n}\ntemplate <typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, __int128_t x) {\n\
    \    // -x \u306F\u6700\u5C0F\u5024\u3067\u3042\u3075\u308C\u308B\u306E\u3067\u3001\
    \u7B26\u53F7\u306A\u3057\u3067\u7B26\u53F7\u3092\u53CD\u8EE2\u3059\u308B\n   \
    \ return internal_io::write_u128(os, x < 0 ? -static_cast<unsigned __int128>(x)\
    \ : static_cast<unsigned __int128>(x), x < 0);\n}\ntemplate <typename CharT, typename\
    \ Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, __uint128_t x) {\n    return internal_io::write_u128(os, x, false);\n\
    }\n\n// \u30CD\u30B9\u30C8\u3057\u305F\u578B (pair<vector<int>, int> \u306A\u3069\
    ) \u3092\u6271\u3048\u308B\u3088\u3046\u306B\u5148\u306B\u5BA3\u8A00\u3057\u3066\
    \u304A\u304F\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>&\
    \ is, std::pair<T1, T2>& p);\ntemplate <typename... Types, typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::tuple<Types...>& p);\ntemplate <typename T, std::size_t N,\
    \ typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::array<T, N>& a);\ntemplate <typename T, typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v);\ntemplate <typename T1, typename T2, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::pair<T1, T2>& p);\ntemplate <typename... Types, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::tuple<Types...>& p);\ntemplate <typename T, std::size_t\
    \ N, typename CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::array<T, N>& a);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::vector<T>& v);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s);\n\nnamespace internal_io {\ntemplate <typename\
    \ Tuple, std::size_t I, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& read_tuple(std::basic_istream<CharT, Traits>& is, Tuple& t) {\n   \
    \ is >> std::get<I>(t);\n    if constexpr (I + 1 < std::tuple_size_v<Tuple>) {\n\
    \        return read_tuple<Tuple, I + 1>(is, t);\n    }\n    return is;\n}\ntemplate\
    \ <typename Tuple, std::size_t I, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& write_tuple(std::basic_ostream<CharT, Traits>& os, const Tuple& t)\
    \ {\n    os << std::get<I>(t);\n    if constexpr (I + 1 < std::tuple_size_v<Tuple>)\
    \ {\n        os << CharT(' ');\n        return write_tuple<Tuple, I + 1>(os, t);\n\
    \    }\n    return os;\n}\n};  // namespace internal_io\n\ntemplate <typename\
    \ T1, typename T2, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::pair<T1, T2>&\
    \ p) {\n    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename...\
    \ Types, typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>&\
    \ operator>>(std::basic_istream<CharT, Traits>& is, std::tuple<Types...>& p) {\n\
    \    return internal_io::read_tuple<std::tuple<Types...>, 0>(is, p);\n}\ntemplate\
    \ <typename T, std::size_t N, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::array<T, N>&\
    \ a) {\n    for (auto& e : a) is >> e;\n    return is;\n}\ntemplate <typename\
    \ T, typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v) {\n    for (auto& e : v) is >> e;\n    return\
    \ is;\n}\n\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::pair<T1, T2>& p) {\n    os << p.first << CharT(' ') << p.second;\n\
    \    return os;\n}\ntemplate <typename... Types, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::tuple<Types...>& p) {\n    return internal_io::write_tuple<std::tuple<Types...>,\
    \ 0>(os, p);\n}\ntemplate <typename T, std::size_t N, typename CharT, typename\
    \ Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::array<T, N>& a) {\n    for (std::size_t i = 0; i < N;\
    \ ++i) {\n        if (i) os << CharT(' ');\n        os << a[i];\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::vector<T>&\
    \ v) {\n    for (std::size_t i = 0; i < v.size(); ++i) {\n        if (i) os <<\
    \ CharT(' ');\n        os << v[i];\n    }\n    return os;\n}\ntemplate <typename\
    \ T, typename CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s) {\n    for (auto itr = s.begin(); itr !=\
    \ s.end(); ++itr) {\n        if (itr != s.begin()) os << CharT(' ');\n       \
    \ os << *itr;\n    }\n    return os;\n}\n\n/**\n * @brief \u7A7A\u884C\u51FA\u529B\
    \n */\ninline void print() { std::cout << '\\n'; }\n/**\n * @brief \u51FA\u529B\
    \u3057\u3066\u6539\u884C\n *\n * @tparam T \u578B\n * @param x \u51FA\u529B\u3059\
    \u308B\u5024\n */\ntemplate <typename T>\nvoid print(const T& x) { std::cout <<\
    \ x << '\\n'; }\n/**\n * @brief \u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\
    \u3057\u3066\u6539\u884C\n *\n * @tparam T 1\u3064\u76EE\u306E\u8981\u7D20\u306E\
    \u578B\n * @tparam Tail 2\u3064\u76EE\u4EE5\u964D\u306E\u8981\u7D20\u306E\u578B\
    \n * @param x 1\u3064\u76EE\u306E\u8981\u7D20\n * @param tail 2\u3064\u76EE\u4EE5\
    \u964D\u306E\u8981\u7D20\n */\ntemplate <typename T, typename... Tail>\nvoid print(const\
    \ T& x, const Tail&... tail) {\n    std::cout << x << ' ';\n    print(tail...);\n\
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
  path: src/base/io.hpp
  requiredBy:
  - src/base/macro.hpp
  timestamp: '2026-10-31 16:27:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/base/io.test.cpp
  - test/unittest/base/macro.test.cpp
  - test/aoj/cgl/cgl-3-b.test.cpp
  - test/aoj/cgl/cgl-3-a.test.cpp
  - test/aoj/cgl/cgl-4-c.test.cpp
  - test/aoj/cgl/cgl-7-h.test.cpp
  - test/aoj/cgl/cgl-3-c.test.cpp
  - test/aoj/cgl/cgl-4-b.test.cpp
  - test/aoj/itp1/itp1-6-a.test.cpp
  - test/aoj/itp1/itp1-2-c.test.cpp
  - test/aoj/volume11/1160.test.cpp
  - test/aoj/itp2/itp2-5-a.1.test.cpp
  - test/aoj/itp2/itp2-5-b.test.cpp
  - test/yosupo/convolution/convolution-mod-2-64.1.test.cpp
  - test/yosupo/sample/many-aplusb-128bit.test.cpp
documentation_of: src/base/io.hpp
layout: document
title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\
  \u30D0\u30FC\u30ED\u30FC\u30C9"
---

STL のコンテナを `>>` / `<<` で入出力できるようにし、空白区切りで出力する `print` を追加します。

```cpp
std::vector<std::pair<int, int>> v(n);
std::cin >> v;                  // 2n 個の整数を読む
print(v);                       // "1 2 3 4" のように空白区切りで出力して改行
print(1, "a", 2.5);             // "1 a 2.5"
err(x, y);                      // 標準エラー出力に出す
```

## 入出力演算子

ネストした型 (`vector<pair<int, int>>` など) もそのまま入出力できます。

| 型 | `>>` | `<<` |
|---|:-:|:-:|
| `std::pair` | ✓ | ✓ |
| `std::tuple` | ✓ | ✓ |
| `std::array` | ✓ | ✓ |
| `std::vector` | ✓ (あらかじめ要素数を決めておく) | ✓ |
| `std::set` | | ✓ |
| `__int128_t` / `__uint128_t` | ✓ | ✓ |

出力は要素を空白 1 つで区切ります。

## 128 bit 整数

std のストリームには 128 bit 整数 (GNU 拡張) の入出力がないので、10 進で読み書きできるようにします。`int128_t` / `uint128_t` ([型の別名](type_alias.hpp)) でも同じです。

```cpp
int128_t x;
std::cin >> x;                  // "-170141183460469231731687303715884105728" まで読める
print(x);                       // 10 進で出力
std::vector<int128_t> v(n);
std::cin >> v;                  // コンテナの中身でもよい
```

- 入力は空白で区切られた 1 語を読み、先頭の `+` / `-` を受け付けます。数でない文字を含むときや範囲外のときは、値を 0 にして failbit を立てます (組み込みの整数と違い、`12a` の `12` だけを読むことはしません)。
- 出力は `std::setw` の幅に合わせて埋めます。`std::hex` などの基数の指定は使いません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `print(x, ...)` | 引数を空白区切りで標準出力に出して改行。引数なしなら改行だけ | 出力の長さに比例 |
| `err(x, ...)` | 引数を空白区切りで標準エラー出力に出して改行 (`std::endl` でフラッシュする) | 出力の長さに比例 |

## 関連

- デバッグ用に型ごと出力するなら [repr](../utility/repr.hpp) の `DEBUG(x)`
- 入力を宣言と同時に読むマクロ (`LL`、`VL` など) は [マクロ](macro.hpp)
