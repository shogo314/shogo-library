---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/io.hpp
    title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\
      \u30D0\u30FC\u30ED\u30FC\u30C9"
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
  bundledCode: "#line 1 \"test/unittest/base/io.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// io.hpp \u306E\u5165\u51FA\u529B\u3092 std::istringstream / std::ostringstream\
    \ \u3067\u691C\u8A3C\u3059\u308B\n// print / err \u306F std::cout / std::cerr\
    \ \u306E\u51FA\u529B\u5148\u3092\u4E00\u6642\u7684\u306B\u5DEE\u3057\u66FF\u3048\
    \u3066\u691C\u8A3C\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/base/io.hpp\"\n/**\n * @file io.hpp\n\
    \ * @brief \u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\
    \u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <cstddef>\n#include <iostream>\n#include <set>\n#include <string>\n#include\
    \ <tuple>\n#include <utility>\n#include <vector>\n\nnamespace internal_io {\n\
    // 128 bit \u306E\u5272\u308A\u7B97\u306F\u9045\u3044\u306E\u3067\u300118 \u6841\
    \u305A\u3064 64 bit \u3067\u6271\u3046\nconstexpr unsigned long long POW10_18\
    \ = 1000000000000000000ULL;\n// \u7A7A\u767D\u3067\u533A\u5207\u3089\u308C\u305F\
    \ 1 \u8A9E\u3092 10 \u9032\u306E\u6574\u6570\u3068\u3057\u3066\u8AAD\u3080\u3002\
    \u6570\u3067\u306A\u3044\u3001\u307E\u305F\u306F lim \u3092\u8D85\u3048\u308B\u306A\
    \u3089 false\ntemplate <typename CharT, typename Traits>\nbool read_u128(std::basic_istream<CharT,\
    \ Traits>& is, unsigned __int128& x, bool& neg, unsigned __int128 pos_max, unsigned\
    \ __int128 neg_max) {\n    std::basic_string<CharT, Traits> s;\n    if (!(is >>\
    \ s)) return false;\n    std::size_t i = 0;\n    neg = false;\n    if (s[0] ==\
    \ CharT('-') || s[0] == CharT('+')) neg = s[i++] == CharT('-');\n    if (i ==\
    \ s.size()) return false;\n    for (std::size_t j = i; j < s.size(); j++) {\n\
    \        if (s[j] < CharT('0') || CharT('9') < s[j]) return false;\n    }\n  \
    \  while (i + 1 < s.size() && s[i] == CharT('0')) i++;\n    // 39 \u6841\u306A\
    \u3089 2^128 \u3092\u8D85\u3048\u308B\u3053\u3068\u304C\u3042\u308B\u306E\u3067\
    \u3001\u6700\u5F8C\u306E 1 \u6841\u306E\u524D\u3067\u6BD4\u3079\u308B\u300240\
    \ \u6841\u4EE5\u4E0A\u306F\u5FC5\u305A\u7BC4\u56F2\u5916\n    const std::size_t\
    \ len = s.size() - i;\n    if (len > 39) return false;\n    const unsigned __int128\
    \ lim = neg ? neg_max : pos_max;\n    const std::size_t safe = len == 39 ? s.size()\
    \ - 1 : s.size();\n    x = 0;\n    while (i < safe) {\n        const std::size_t\
    \ k = std::min<std::size_t>(18, safe - i);\n        unsigned long long c = 0,\
    \ p = 1;\n        for (std::size_t j = 0; j < k; j++, i++) c = c * 10 + (s[i]\
    \ - CharT('0')), p *= 10;\n        x = x * p + c;\n    }\n    if (len == 39) {\n\
    \        const unsigned d = s[i] - CharT('0');\n        if (x > lim / 10 || x\
    \ * 10 > lim - d) return false;\n        x = x * 10 + d;\n    }\n    return x\
    \ <= lim;\n}\n// x < 10^18 \u3092\u66F8\u304F\u3002pad \u306A\u3089 18 \u6841\u306B\
    \u306A\u308B\u3088\u3046 0 \u3067\u57CB\u3081\u308B\u3002\u672B\u5C3E\u304B\u3089\
    \u66F8\u3044\u3066\u5148\u982D\u3092\u8FD4\u3059\ninline char* write_u64(char*\
    \ end, unsigned long long x, bool pad) {\n    char* p = end;\n    do {\n     \
    \   *--p = static_cast<char>('0' + x % 10);\n        x /= 10;\n    } while (x\
    \ > 0);\n    if (pad) {\n        while (p > end - 18) *--p = '0';\n    }\n   \
    \ return p;\n}\ntemplate <typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& write_u128(std::basic_ostream<CharT, Traits>& os, unsigned __int128\
    \ x, bool neg) {\n    char buf[41];\n    char* p = buf + 40;\n    *p = '\\0';\n\
    \    if (x < POW10_18) {\n        p = write_u64(p, static_cast<unsigned long long>(x),\
    \ false);\n    } else {\n        const unsigned __int128 q = x / POW10_18;\n \
    \       p = write_u64(p, static_cast<unsigned long long>(x - q * POW10_18), true);\n\
    \        if (q < POW10_18) {\n            p = write_u64(p, static_cast<unsigned\
    \ long long>(q), false);\n        } else {\n            const unsigned long long\
    \ hi = static_cast<unsigned long long>(q / POW10_18);\n            p = write_u64(p,\
    \ static_cast<unsigned long long>(q - static_cast<unsigned __int128>(hi) * POW10_18),\
    \ true);\n            p = write_u64(p, hi, false);\n        }\n    }\n    if (neg)\
    \ *--p = '-';\n    return os << p;\n}\n}  // namespace internal_io\n\n// 128 bit\
    \ \u6574\u6570\u306E\u5165\u51FA\u529B (GNU \u62E1\u5F35)\u3002std::basic_istream\
    \ / std::basic_ostream \u306B\u306F\u7528\u610F\u3055\u308C\u3066\u3044\u306A\u3044\
    \ntemplate <typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>&\
    \ operator>>(std::basic_istream<CharT, Traits>& is, __int128_t& x) {\n    const\
    \ unsigned __int128 pos_max = static_cast<unsigned __int128>(-1) >> 1;\n    unsigned\
    \ __int128 u;\n    bool neg;\n    if (internal_io::read_u128(is, u, neg, pos_max,\
    \ pos_max + 1)) {\n        x = neg ? static_cast<__int128_t>(-u) : static_cast<__int128_t>(u);\n\
    \    } else {\n        x = 0;\n        is.setstate(std::ios_base::failbit);\n\
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
    \ << x << ' ';\n    err(tail...);\n}\n#line 8 \"test/unittest/base/io.test.cpp\"\
    \n\n#line 10 \"test/unittest/base/io.test.cpp\"\n#include <iomanip>\n#line 12\
    \ \"test/unittest/base/io.test.cpp\"\n#include <random>\n#line 14 \"test/unittest/base/io.test.cpp\"\
    \n#include <sstream>\n#line 19 \"test/unittest/base/io.test.cpp\"\n\n// std::cout\
    \ (\u307E\u305F\u306F std::cerr) \u306B\u66F8\u304B\u308C\u305F\u5185\u5BB9\u3092\
    \u6587\u5B57\u5217\u3067\u53D7\u3051\u53D6\u308B\ntemplate <class F>\nstd::string\
    \ capture(std::ostream& stream, F f) {\n    std::ostringstream buf;\n    std::streambuf*\
    \ old = stream.rdbuf(buf.rdbuf());\n    f();\n    stream.rdbuf(old);\n    return\
    \ buf.str();\n}\n\ntemplate <class T>\nstd::string to_str(const T& x) {\n    std::ostringstream\
    \ os;\n    os << x;\n    return os.str();\n}\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n    auto check = [&](bool cond, const char*\
    \ what) {\n        if (!cond) {\n            if (ok) std::cerr << \"failed: \"\
    \ << what << std::endl;\n            ok = false;\n        }\n    };\n\n    //\
    \ \u51FA\u529B: \u7A7A\u767D\u533A\u5207\u308A\n    check(to_str(std::make_pair(1,\
    \ std::string(\"ab\"))) == \"1 ab\", \"<< pair\");\n    check(to_str(std::make_tuple(1,\
    \ 'x', std::string(\"yz\"), 2.5)) == \"1 x yz 2.5\", \"<< tuple\");\n    check(to_str(std::make_tuple(7))\
    \ == \"7\", \"<< tuple (1 \u8981\u7D20)\");\n    check(to_str(std::array<int,\
    \ 3>{4, 5, 6}) == \"4 5 6\", \"<< array\");\n    check(to_str(std::array<int,\
    \ 0>{}) == \"\", \"<< array (\u7A7A)\");\n    check(to_str(std::vector<int>{3,\
    \ 1, 2}) == \"3 1 2\", \"<< vector\");\n    check(to_str(std::vector<int>{}) ==\
    \ \"\", \"<< vector (\u7A7A)\");\n    check(to_str(std::set<int>{3, 1, 2}) ==\
    \ \"1 2 3\", \"<< set\");\n    check(to_str(std::set<int>{}) == \"\", \"<< set\
    \ (\u7A7A)\");\n    // \u30CD\u30B9\u30C8\u3057\u305F\u578B\n    check(to_str(std::vector<std::pair<int,\
    \ int>>{{1, 2}, {3, 4}}) == \"1 2 3 4\", \"<< vector<pair>\");\n    check(to_str(std::make_pair(std::vector<int>{1,\
    \ 2}, std::array<int, 2>{3, 4})) == \"1 2 3 4\", \"<< pair<vector, array>\");\n\
    \n    // \u5165\u529B\n    {\n        std::istringstream is(\"1 ab  x 2 yz 3.5\\\
    n 4 5 6 7 8 9 10\");\n        std::pair<int, std::string> p;\n        std::tuple<char,\
    \ int, std::string, double> t;\n        std::array<int, 3> a;\n        std::vector<int>\
    \ v(4);\n        is >> p >> t >> a >> v;\n        check(p == std::make_pair(1,\
    \ std::string(\"ab\")), \">> pair\");\n        check(t == std::make_tuple('x',\
    \ 2, std::string(\"yz\"), 3.5), \">> tuple\");\n        check(a == std::array<int,\
    \ 3>{4, 5, 6}, \">> array\");\n        check(v == std::vector<int>{7, 8, 9, 10},\
    \ \">> vector\");\n        check(static_cast<bool>(is), \"stream state\");\n \
    \   }\n    {\n        // \u30CD\u30B9\u30C8\u3057\u305F\u578B\n        std::istringstream\
    \ is(\"1 2 3 4 5 6\");\n        std::pair<std::vector<int>, std::array<int, 2>>\
    \ p;\n        p.first.resize(2);\n        std::vector<std::pair<int, int>> vp(1);\n\
    \        is >> p >> vp;\n        check(p.first == std::vector<int>{1, 2} && p.second\
    \ == std::array<int, 2>{3, 4}, \">> pair<vector, array>\");\n        check(vp[0]\
    \ == std::make_pair(5, 6), \">> vector<pair>\");\n    }\n\n    // \u30E9\u30F3\
    \u30C0\u30E0: \u66F8\u3044\u3066\u8AAD\u307F\u623B\u3059\u3068\u4E00\u81F4\u3057\
    \u3001\u51FA\u529B\u306F\u611A\u76F4\u306B\u7A7A\u767D\u3067\u3064\u306A\u3044\
    \u3060\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        int n = rng() % 6;\n        std::vector<int> v(n);\n\
    \        for (int& x : v) x = static_cast<int>(rng() % 2001) - 1000;\n       \
    \ std::string expect;\n        for (int i = 0; i < n; i++) expect += (i ? \" \"\
    \ : \"\") + std::to_string(v[i]);\n        check(to_str(v) == expect, \"<< vector\
    \ (random)\");\n        std::set<int> s(v.begin(), v.end());\n        std::string\
    \ expect_s;\n        for (auto it = s.begin(); it != s.end(); ++it) expect_s +=\
    \ (it == s.begin() ? \"\" : \" \") + std::to_string(*it);\n        check(to_str(s)\
    \ == expect_s, \"<< set (random)\");\n        std::istringstream is(expect);\n\
    \        std::vector<int> w(n);\n        is >> w;\n        check(w == v, \">>\
    \ vector (random)\");\n        std::array<int, 4> a;\n        for (int& x : a)\
    \ x = static_cast<int>(rng() % 2001) - 1000;\n        std::istringstream is2(to_str(a));\n\
    \        std::array<int, 4> b;\n        is2 >> b;\n        check(a == b, \"array\
    \ round trip\");\n        auto t = std::make_tuple(static_cast<int>(rng() % 100),\
    \ static_cast<long long>(rng()), std::string(1 + rng() % 3, 'a' + rng() % 26));\n\
    \        std::istringstream is3(to_str(t));\n        decltype(t) u;\n        is3\
    \ >> u;\n        check(t == u, \"tuple round trip\");\n    }\n\n    // 128 bit\
    \ \u6574\u6570\n    {\n        const __uint128_t umax = ~static_cast<__uint128_t>(0);\n\
    \        const __int128_t imax = static_cast<__int128_t>(umax >> 1), imin = -imax\
    \ - 1;\n        check(to_str(static_cast<__int128_t>(0)) == \"0\", \"<< int128\
    \ (0)\");\n        check(to_str(static_cast<__int128_t>(-42)) == \"-42\", \"<<\
    \ int128 (\u8CA0)\");\n        check(to_str(imax) == \"170141183460469231731687303715884105727\"\
    , \"<< int128 (\u6700\u5927\u5024)\");\n        check(to_str(imin) == \"-170141183460469231731687303715884105728\"\
    , \"<< int128 (\u6700\u5C0F\u5024)\");\n        check(to_str(umax) == \"340282366920938463463374607431768211455\"\
    , \"<< uint128 (\u6700\u5927\u5024)\");\n        check(to_str(std::vector<__int128_t>{1,\
    \ -2}) == \"1 -2\", \"<< vector<int128>\");\n        std::ostringstream w;\n \
    \       w << std::setw(5) << static_cast<__int128_t>(-7);\n        check(w.str()\
    \ == \"   -7\", \"<< int128 (setw)\");\n\n        std::istringstream is(\"170141183460469231731687303715884105727\
    \ -170141183460469231731687303715884105728 +5 340282366920938463463374607431768211455\
    \ 3 -4\");\n        __int128_t a, b, c;\n        __uint128_t d;\n        std::pair<__int128_t,\
    \ __int128_t> p;\n        is >> a >> b >> c >> d >> p;\n        check(a == imax\
    \ && b == imin && c == 5 && d == umax && p == std::make_pair<__int128_t, __int128_t>(3,\
    \ -4), \">> int128\");\n        check(static_cast<bool>(is), \">> int128 (stream\
    \ state)\");\n        // \u7BC4\u56F2\u5916\u3084\u6570\u3067\u306A\u3044\u3082\
    \u306E\u306F failbit\n        for (std::string bad : {\"170141183460469231731687303715884105728\"\
    , \"-170141183460469231731687303715884105729\", \"12a\", \"-\", \"x\"}) {\n  \
    \          std::istringstream bs(bad);\n            __int128_t x;\n          \
    \  bs >> x;\n            check(bs.fail(), \">> int128 (\u4E0D\u6B63)\");\n   \
    \     }\n        for (std::string bad : {\"340282366920938463463374607431768211456\"\
    , \"-1\"}) {\n            std::istringstream bs(bad);\n            __uint128_t\
    \ x;\n            bs >> x;\n            check(bs.fail(), \">> uint128 (\u4E0D\u6B63\
    )\");\n        }\n        std::istringstream zs(\"-0\");\n        __uint128_t\
    \ z = 1;\n        zs >> z;\n        check(!zs.fail() && z == 0, \">> uint128 (-0)\"\
    );\n        // \u30E9\u30F3\u30C0\u30E0: long long \u306E\u7A4D\u3067\u4F5C\u3063\
    \u305F\u5024\u3092\u66F8\u3044\u3066\u8AAD\u307F\u623B\u3059\n        for (int\
    \ rep = 0; rep < 2000; rep++) {\n            __int128_t x = static_cast<__int128_t>(static_cast<long\
    \ long>(rng())) * static_cast<long long>(rng() * 1000003ULL);\n            if\
    \ (rng() % 2) x = -x;\n            std::istringstream rs(to_str(x));\n       \
    \     __int128_t y = 0;\n            rs >> y;\n            check(x == y, \"int128\
    \ round trip\");\n            // long long \u306B\u53CE\u307E\u308B\u306A\u3089\
    \ long long \u3068\u540C\u3058\u8868\u8A18\n            if (-1000000000000000000\
    \ <= x && x <= 1000000000000000000) check(to_str(x) == std::to_string(static_cast<long\
    \ long>(x)), \"<< int128 (long long \u3068\u6BD4\u3079\u308B)\");\n        }\n\
    \        // \u5148\u982D\u306E 0 \u306F\u6841\u6570\u306B\u6570\u3048\u306A\u3044\
    \n        std::istringstream lz(\"000000000000000000000000000000000000000000000123\
    \ -0000 +00340282366920938463463374607431768211455\");\n        __int128_t l1,\
    \ l2;\n        __uint128_t l3;\n        lz >> l1 >> l2 >> l3;\n        check(!lz.fail()\
    \ && l1 == 123 && l2 == 0 && l3 == umax, \">> int128 (\u5148\u982D\u306E 0)\"\
    );\n        // \u30E9\u30F3\u30C0\u30E0: \u5168\u7BC4\u56F2\u306E\u5024\u3092\
    \ 1 \u6841\u305A\u3064\u611A\u76F4\u306B\u5909\u63DB\u3057\u305F\u3082\u306E\u3068\
    \u6BD4\u3079\u308B (18 \u6841\u305A\u3064\u5206\u3051\u308B\u5883\u76EE\u3092\u901A\
    \u308B)\n        for (int rep = 0; rep < 20000; rep++) {\n            __uint128_t\
    \ u = 0;\n            for (int k = 0; k < 4; k++) u = u << 32 | rng();\n     \
    \       u >>= rng() % 128;\n            std::string expect;\n            for (__uint128_t\
    \ y = u; expect.empty() || y > 0; y /= 10) expect.insert(expect.begin(), static_cast<char>('0'\
    \ + static_cast<int>(y % 10)));\n            check(to_str(u) == expect, \"<< uint128\
    \ (random)\");\n            std::istringstream us(expect);\n            __uint128_t\
    \ v = 0;\n            us >> v;\n            check(!us.fail() && u == v, \">> uint128\
    \ (random)\");\n            const __int128_t x = static_cast<__int128_t>(u >>\
    \ 1), nx = -x;\n            check(to_str(nx) == (x == 0 ? \"\" : \"-\") + to_str(static_cast<__uint128_t>(x)),\
    \ \"<< int128 (random \u8CA0)\");\n            std::istringstream ns(to_str(nx));\n\
    \            __int128_t y = 0;\n            ns >> y;\n            check(!ns.fail()\
    \ && y == nx, \">> int128 (random \u8CA0)\");\n            // \u6700\u5927\u5024\
    \u306E\u4ED8\u8FD1: imax - 10 + r \u306F r <= 10 \u306A\u3089\u8AAD\u3081\u3066\
    \u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u7BC4\u56F2\u5916\n         \
    \   const int r = rng() % 21;\n            std::istringstream near(to_str(static_cast<__uint128_t>(imax)\
    \ - 10 + r));\n            __int128_t a = 0;\n            near >> a;\n       \
    \     check(near.fail() == (r > 10) && (r > 10 || a == imax - 10 + r), \">> int128\
    \ (\u6700\u5927\u5024\u306E\u4ED8\u8FD1)\");\n            std::istringstream near_neg(\"\
    -\" + to_str(static_cast<__uint128_t>(imax) - 9 + r));\n            near_neg >>\
    \ a;\n            check(near_neg.fail() == (r > 10) && (r > 10 || a == -imax +\
    \ 9 - r), \">> int128 (\u6700\u5C0F\u5024\u306E\u4ED8\u8FD1)\");\n        }\n\
    \        check(capture(std::cout, [&] { print(imin, umax); }) == \"-170141183460469231731687303715884105728\
    \ 340282366920938463463374607431768211455\\n\", \"print(int128)\");\n    }\n\n\
    \    // print: std::cout \u306B\u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\
    \u3057\u3066\u6539\u884C\n    check(capture(std::cout, [] { print(); }) == \"\\\
    n\", \"print()\");\n    check(capture(std::cout, [] { print(42); }) == \"42\\\
    n\", \"print(x)\");\n    check(capture(std::cout, [] { print(1, \"a\", 2.5, 'c');\
    \ }) == \"1 a 2.5 c\\n\", \"print(x, ...)\");\n    check(capture(std::cout, []\
    \ { print(std::vector<int>{1, 2}, std::make_pair(3, 4)); }) == \"1 2 3 4\\n\"\
    , \"print(vector, pair)\");\n\n    // err: std::cerr \u306B\u7A7A\u767D\u533A\u5207\
    \u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n    check(capture(std::cerr,\
    \ [] { err(); }) == \"\\n\", \"err()\");\n    check(capture(std::cerr, [] { err(42);\
    \ }) == \"42\\n\", \"err(x)\");\n    check(capture(std::cerr, [] { err(1, \"a\"\
    , 2.5, 'c'); }) == \"1 a 2.5 c\\n\", \"err(x, ...)\");\n    check(capture(std::cerr,\
    \ [] { err(std::set<int>{2, 1}); }) == \"1 2\\n\", \"err(set)\");\n\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// io.hpp \u306E\u5165\u51FA\u529B\u3092 std::istringstream / std::ostringstream\
    \ \u3067\u691C\u8A3C\u3059\u308B\n// print / err \u306F std::cout / std::cerr\
    \ \u306E\u51FA\u529B\u5148\u3092\u4E00\u6642\u7684\u306B\u5DEE\u3057\u66FF\u3048\
    \u3066\u691C\u8A3C\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../../src/base/io.hpp\"\n\n#include\
    \ <array>\n#include <iomanip>\n#include <iostream>\n#include <random>\n#include\
    \ <set>\n#include <sstream>\n#include <string>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\n// std::cout (\u307E\u305F\u306F std::cerr) \u306B\u66F8\u304B\
    \u308C\u305F\u5185\u5BB9\u3092\u6587\u5B57\u5217\u3067\u53D7\u3051\u53D6\u308B\
    \ntemplate <class F>\nstd::string capture(std::ostream& stream, F f) {\n    std::ostringstream\
    \ buf;\n    std::streambuf* old = stream.rdbuf(buf.rdbuf());\n    f();\n    stream.rdbuf(old);\n\
    \    return buf.str();\n}\n\ntemplate <class T>\nstd::string to_str(const T& x)\
    \ {\n    std::ostringstream os;\n    os << x;\n    return os.str();\n}\n\nint\
    \ main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    auto check =\
    \ [&](bool cond, const char* what) {\n        if (!cond) {\n            if (ok)\
    \ std::cerr << \"failed: \" << what << std::endl;\n            ok = false;\n \
    \       }\n    };\n\n    // \u51FA\u529B: \u7A7A\u767D\u533A\u5207\u308A\n   \
    \ check(to_str(std::make_pair(1, std::string(\"ab\"))) == \"1 ab\", \"<< pair\"\
    );\n    check(to_str(std::make_tuple(1, 'x', std::string(\"yz\"), 2.5)) == \"\
    1 x yz 2.5\", \"<< tuple\");\n    check(to_str(std::make_tuple(7)) == \"7\", \"\
    << tuple (1 \u8981\u7D20)\");\n    check(to_str(std::array<int, 3>{4, 5, 6}) ==\
    \ \"4 5 6\", \"<< array\");\n    check(to_str(std::array<int, 0>{}) == \"\", \"\
    << array (\u7A7A)\");\n    check(to_str(std::vector<int>{3, 1, 2}) == \"3 1 2\"\
    , \"<< vector\");\n    check(to_str(std::vector<int>{}) == \"\", \"<< vector (\u7A7A\
    )\");\n    check(to_str(std::set<int>{3, 1, 2}) == \"1 2 3\", \"<< set\");\n \
    \   check(to_str(std::set<int>{}) == \"\", \"<< set (\u7A7A)\");\n    // \u30CD\
    \u30B9\u30C8\u3057\u305F\u578B\n    check(to_str(std::vector<std::pair<int, int>>{{1,\
    \ 2}, {3, 4}}) == \"1 2 3 4\", \"<< vector<pair>\");\n    check(to_str(std::make_pair(std::vector<int>{1,\
    \ 2}, std::array<int, 2>{3, 4})) == \"1 2 3 4\", \"<< pair<vector, array>\");\n\
    \n    // \u5165\u529B\n    {\n        std::istringstream is(\"1 ab  x 2 yz 3.5\\\
    n 4 5 6 7 8 9 10\");\n        std::pair<int, std::string> p;\n        std::tuple<char,\
    \ int, std::string, double> t;\n        std::array<int, 3> a;\n        std::vector<int>\
    \ v(4);\n        is >> p >> t >> a >> v;\n        check(p == std::make_pair(1,\
    \ std::string(\"ab\")), \">> pair\");\n        check(t == std::make_tuple('x',\
    \ 2, std::string(\"yz\"), 3.5), \">> tuple\");\n        check(a == std::array<int,\
    \ 3>{4, 5, 6}, \">> array\");\n        check(v == std::vector<int>{7, 8, 9, 10},\
    \ \">> vector\");\n        check(static_cast<bool>(is), \"stream state\");\n \
    \   }\n    {\n        // \u30CD\u30B9\u30C8\u3057\u305F\u578B\n        std::istringstream\
    \ is(\"1 2 3 4 5 6\");\n        std::pair<std::vector<int>, std::array<int, 2>>\
    \ p;\n        p.first.resize(2);\n        std::vector<std::pair<int, int>> vp(1);\n\
    \        is >> p >> vp;\n        check(p.first == std::vector<int>{1, 2} && p.second\
    \ == std::array<int, 2>{3, 4}, \">> pair<vector, array>\");\n        check(vp[0]\
    \ == std::make_pair(5, 6), \">> vector<pair>\");\n    }\n\n    // \u30E9\u30F3\
    \u30C0\u30E0: \u66F8\u3044\u3066\u8AAD\u307F\u623B\u3059\u3068\u4E00\u81F4\u3057\
    \u3001\u51FA\u529B\u306F\u611A\u76F4\u306B\u7A7A\u767D\u3067\u3064\u306A\u3044\
    \u3060\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        int n = rng() % 6;\n        std::vector<int> v(n);\n\
    \        for (int& x : v) x = static_cast<int>(rng() % 2001) - 1000;\n       \
    \ std::string expect;\n        for (int i = 0; i < n; i++) expect += (i ? \" \"\
    \ : \"\") + std::to_string(v[i]);\n        check(to_str(v) == expect, \"<< vector\
    \ (random)\");\n        std::set<int> s(v.begin(), v.end());\n        std::string\
    \ expect_s;\n        for (auto it = s.begin(); it != s.end(); ++it) expect_s +=\
    \ (it == s.begin() ? \"\" : \" \") + std::to_string(*it);\n        check(to_str(s)\
    \ == expect_s, \"<< set (random)\");\n        std::istringstream is(expect);\n\
    \        std::vector<int> w(n);\n        is >> w;\n        check(w == v, \">>\
    \ vector (random)\");\n        std::array<int, 4> a;\n        for (int& x : a)\
    \ x = static_cast<int>(rng() % 2001) - 1000;\n        std::istringstream is2(to_str(a));\n\
    \        std::array<int, 4> b;\n        is2 >> b;\n        check(a == b, \"array\
    \ round trip\");\n        auto t = std::make_tuple(static_cast<int>(rng() % 100),\
    \ static_cast<long long>(rng()), std::string(1 + rng() % 3, 'a' + rng() % 26));\n\
    \        std::istringstream is3(to_str(t));\n        decltype(t) u;\n        is3\
    \ >> u;\n        check(t == u, \"tuple round trip\");\n    }\n\n    // 128 bit\
    \ \u6574\u6570\n    {\n        const __uint128_t umax = ~static_cast<__uint128_t>(0);\n\
    \        const __int128_t imax = static_cast<__int128_t>(umax >> 1), imin = -imax\
    \ - 1;\n        check(to_str(static_cast<__int128_t>(0)) == \"0\", \"<< int128\
    \ (0)\");\n        check(to_str(static_cast<__int128_t>(-42)) == \"-42\", \"<<\
    \ int128 (\u8CA0)\");\n        check(to_str(imax) == \"170141183460469231731687303715884105727\"\
    , \"<< int128 (\u6700\u5927\u5024)\");\n        check(to_str(imin) == \"-170141183460469231731687303715884105728\"\
    , \"<< int128 (\u6700\u5C0F\u5024)\");\n        check(to_str(umax) == \"340282366920938463463374607431768211455\"\
    , \"<< uint128 (\u6700\u5927\u5024)\");\n        check(to_str(std::vector<__int128_t>{1,\
    \ -2}) == \"1 -2\", \"<< vector<int128>\");\n        std::ostringstream w;\n \
    \       w << std::setw(5) << static_cast<__int128_t>(-7);\n        check(w.str()\
    \ == \"   -7\", \"<< int128 (setw)\");\n\n        std::istringstream is(\"170141183460469231731687303715884105727\
    \ -170141183460469231731687303715884105728 +5 340282366920938463463374607431768211455\
    \ 3 -4\");\n        __int128_t a, b, c;\n        __uint128_t d;\n        std::pair<__int128_t,\
    \ __int128_t> p;\n        is >> a >> b >> c >> d >> p;\n        check(a == imax\
    \ && b == imin && c == 5 && d == umax && p == std::make_pair<__int128_t, __int128_t>(3,\
    \ -4), \">> int128\");\n        check(static_cast<bool>(is), \">> int128 (stream\
    \ state)\");\n        // \u7BC4\u56F2\u5916\u3084\u6570\u3067\u306A\u3044\u3082\
    \u306E\u306F failbit\n        for (std::string bad : {\"170141183460469231731687303715884105728\"\
    , \"-170141183460469231731687303715884105729\", \"12a\", \"-\", \"x\"}) {\n  \
    \          std::istringstream bs(bad);\n            __int128_t x;\n          \
    \  bs >> x;\n            check(bs.fail(), \">> int128 (\u4E0D\u6B63)\");\n   \
    \     }\n        for (std::string bad : {\"340282366920938463463374607431768211456\"\
    , \"-1\"}) {\n            std::istringstream bs(bad);\n            __uint128_t\
    \ x;\n            bs >> x;\n            check(bs.fail(), \">> uint128 (\u4E0D\u6B63\
    )\");\n        }\n        std::istringstream zs(\"-0\");\n        __uint128_t\
    \ z = 1;\n        zs >> z;\n        check(!zs.fail() && z == 0, \">> uint128 (-0)\"\
    );\n        // \u30E9\u30F3\u30C0\u30E0: long long \u306E\u7A4D\u3067\u4F5C\u3063\
    \u305F\u5024\u3092\u66F8\u3044\u3066\u8AAD\u307F\u623B\u3059\n        for (int\
    \ rep = 0; rep < 2000; rep++) {\n            __int128_t x = static_cast<__int128_t>(static_cast<long\
    \ long>(rng())) * static_cast<long long>(rng() * 1000003ULL);\n            if\
    \ (rng() % 2) x = -x;\n            std::istringstream rs(to_str(x));\n       \
    \     __int128_t y = 0;\n            rs >> y;\n            check(x == y, \"int128\
    \ round trip\");\n            // long long \u306B\u53CE\u307E\u308B\u306A\u3089\
    \ long long \u3068\u540C\u3058\u8868\u8A18\n            if (-1000000000000000000\
    \ <= x && x <= 1000000000000000000) check(to_str(x) == std::to_string(static_cast<long\
    \ long>(x)), \"<< int128 (long long \u3068\u6BD4\u3079\u308B)\");\n        }\n\
    \        // \u5148\u982D\u306E 0 \u306F\u6841\u6570\u306B\u6570\u3048\u306A\u3044\
    \n        std::istringstream lz(\"000000000000000000000000000000000000000000000123\
    \ -0000 +00340282366920938463463374607431768211455\");\n        __int128_t l1,\
    \ l2;\n        __uint128_t l3;\n        lz >> l1 >> l2 >> l3;\n        check(!lz.fail()\
    \ && l1 == 123 && l2 == 0 && l3 == umax, \">> int128 (\u5148\u982D\u306E 0)\"\
    );\n        // \u30E9\u30F3\u30C0\u30E0: \u5168\u7BC4\u56F2\u306E\u5024\u3092\
    \ 1 \u6841\u305A\u3064\u611A\u76F4\u306B\u5909\u63DB\u3057\u305F\u3082\u306E\u3068\
    \u6BD4\u3079\u308B (18 \u6841\u305A\u3064\u5206\u3051\u308B\u5883\u76EE\u3092\u901A\
    \u308B)\n        for (int rep = 0; rep < 20000; rep++) {\n            __uint128_t\
    \ u = 0;\n            for (int k = 0; k < 4; k++) u = u << 32 | rng();\n     \
    \       u >>= rng() % 128;\n            std::string expect;\n            for (__uint128_t\
    \ y = u; expect.empty() || y > 0; y /= 10) expect.insert(expect.begin(), static_cast<char>('0'\
    \ + static_cast<int>(y % 10)));\n            check(to_str(u) == expect, \"<< uint128\
    \ (random)\");\n            std::istringstream us(expect);\n            __uint128_t\
    \ v = 0;\n            us >> v;\n            check(!us.fail() && u == v, \">> uint128\
    \ (random)\");\n            const __int128_t x = static_cast<__int128_t>(u >>\
    \ 1), nx = -x;\n            check(to_str(nx) == (x == 0 ? \"\" : \"-\") + to_str(static_cast<__uint128_t>(x)),\
    \ \"<< int128 (random \u8CA0)\");\n            std::istringstream ns(to_str(nx));\n\
    \            __int128_t y = 0;\n            ns >> y;\n            check(!ns.fail()\
    \ && y == nx, \">> int128 (random \u8CA0)\");\n            // \u6700\u5927\u5024\
    \u306E\u4ED8\u8FD1: imax - 10 + r \u306F r <= 10 \u306A\u3089\u8AAD\u3081\u3066\
    \u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u7BC4\u56F2\u5916\n         \
    \   const int r = rng() % 21;\n            std::istringstream near(to_str(static_cast<__uint128_t>(imax)\
    \ - 10 + r));\n            __int128_t a = 0;\n            near >> a;\n       \
    \     check(near.fail() == (r > 10) && (r > 10 || a == imax - 10 + r), \">> int128\
    \ (\u6700\u5927\u5024\u306E\u4ED8\u8FD1)\");\n            std::istringstream near_neg(\"\
    -\" + to_str(static_cast<__uint128_t>(imax) - 9 + r));\n            near_neg >>\
    \ a;\n            check(near_neg.fail() == (r > 10) && (r > 10 || a == -imax +\
    \ 9 - r), \">> int128 (\u6700\u5C0F\u5024\u306E\u4ED8\u8FD1)\");\n        }\n\
    \        check(capture(std::cout, [&] { print(imin, umax); }) == \"-170141183460469231731687303715884105728\
    \ 340282366920938463463374607431768211455\\n\", \"print(int128)\");\n    }\n\n\
    \    // print: std::cout \u306B\u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\
    \u3057\u3066\u6539\u884C\n    check(capture(std::cout, [] { print(); }) == \"\\\
    n\", \"print()\");\n    check(capture(std::cout, [] { print(42); }) == \"42\\\
    n\", \"print(x)\");\n    check(capture(std::cout, [] { print(1, \"a\", 2.5, 'c');\
    \ }) == \"1 a 2.5 c\\n\", \"print(x, ...)\");\n    check(capture(std::cout, []\
    \ { print(std::vector<int>{1, 2}, std::make_pair(3, 4)); }) == \"1 2 3 4\\n\"\
    , \"print(vector, pair)\");\n\n    // err: std::cerr \u306B\u7A7A\u767D\u533A\u5207\
    \u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n    check(capture(std::cerr,\
    \ [] { err(); }) == \"\\n\", \"err()\");\n    check(capture(std::cerr, [] { err(42);\
    \ }) == \"42\\n\", \"err(x)\");\n    check(capture(std::cerr, [] { err(1, \"a\"\
    , 2.5, 'c'); }) == \"1 a 2.5 c\\n\", \"err(x, ...)\");\n    check(capture(std::cerr,\
    \ [] { err(std::set<int>{2, 1}); }) == \"1 2\\n\", \"err(set)\");\n\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/base/io.hpp
  isVerificationFile: true
  path: test/unittest/base/io.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 16:27:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/base/io.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/base/io.test.cpp
- /verify/test/unittest/base/io.test.cpp.html
title: test/unittest/base/io.test.cpp
---
