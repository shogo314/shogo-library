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
  bundledCode: "#line 1 \"test/unittest/io.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// io.hpp \u306E\u5165\u51FA\u529B\u3092 std::istringstream / std::ostringstream\
    \ \u3067\u691C\u8A3C\u3059\u308B\n// print / err \u306F std::cout / std::cerr\
    \ \u306E\u51FA\u529B\u5148\u3092\u4E00\u6642\u7684\u306B\u5DEE\u3057\u66FF\u3048\
    \u3066\u691C\u8A3C\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include <array>\n#include <iostream>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"src/base/io.hpp\"\n/**\n * @file io.hpp\n\
    \ * @brief \u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\
    \u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\n */\n\n#line 13 \"src/base/io.hpp\"\n\n\
    // \u30CD\u30B9\u30C8\u3057\u305F\u578B (pair<vector<int>, int> \u306A\u3069)\
    \ \u3092\u6271\u3048\u308B\u3088\u3046\u306B\u5148\u306B\u5BA3\u8A00\u3057\u3066\
    \u304A\u304F\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>&\
    \ is, std::pair<T1, T2>& p);\ntemplate <typename... Types, typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
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
    \ << x << ' ';\n    err(tail...);\n}\n#line 18 \"test/unittest/io.test.cpp\"\n\
    \n// std::cout (\u307E\u305F\u306F std::cerr) \u306B\u66F8\u304B\u308C\u305F\u5185\
    \u5BB9\u3092\u6587\u5B57\u5217\u3067\u53D7\u3051\u53D6\u308B\ntemplate <class\
    \ F>\nstd::string capture(std::ostream& stream, F f) {\n    std::ostringstream\
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
    \ \">> vector\");\n        check(bool(is), \"stream state\");\n    }\n    {\n\
    \        // \u30CD\u30B9\u30C8\u3057\u305F\u578B\n        std::istringstream is(\"\
    1 2 3 4 5 6\");\n        std::pair<std::vector<int>, std::array<int, 2>> p;\n\
    \        p.first.resize(2);\n        std::vector<std::pair<int, int>> vp(1);\n\
    \        is >> p >> vp;\n        check(p.first == std::vector<int>{1, 2} && p.second\
    \ == std::array<int, 2>{3, 4}, \">> pair<vector, array>\");\n        check(vp[0]\
    \ == std::make_pair(5, 6), \">> vector<pair>\");\n    }\n\n    // \u30E9\u30F3\
    \u30C0\u30E0: \u66F8\u3044\u3066\u8AAD\u307F\u623B\u3059\u3068\u4E00\u81F4\u3057\
    \u3001\u51FA\u529B\u306F\u611A\u76F4\u306B\u7A7A\u767D\u3067\u3064\u306A\u3044\
    \u3060\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        int n = rng() % 6;\n        std::vector<int> v(n);\n\
    \        for (int& x : v) x = (int)(rng() % 2001) - 1000;\n        std::string\
    \ expect;\n        for (int i = 0; i < n; i++) expect += (i ? \" \" : \"\") +\
    \ std::to_string(v[i]);\n        check(to_str(v) == expect, \"<< vector (random)\"\
    );\n        std::set<int> s(v.begin(), v.end());\n        std::string expect_s;\n\
    \        for (auto it = s.begin(); it != s.end(); ++it) expect_s += (it == s.begin()\
    \ ? \"\" : \" \") + std::to_string(*it);\n        check(to_str(s) == expect_s,\
    \ \"<< set (random)\");\n        std::istringstream is(expect);\n        std::vector<int>\
    \ w(n);\n        is >> w;\n        check(w == v, \">> vector (random)\");\n  \
    \      std::array<int, 4> a;\n        for (int& x : a) x = (int)(rng() % 2001)\
    \ - 1000;\n        std::istringstream is2(to_str(a));\n        std::array<int,\
    \ 4> b;\n        is2 >> b;\n        check(a == b, \"array round trip\");\n   \
    \     auto t = std::make_tuple((int)(rng() % 100), (long long)rng(), std::string(1\
    \ + rng() % 3, 'a' + rng() % 26));\n        std::istringstream is3(to_str(t));\n\
    \        decltype(t) u;\n        is3 >> u;\n        check(t == u, \"tuple round\
    \ trip\");\n    }\n\n    // print: std::cout \u306B\u7A7A\u767D\u533A\u5207\u308A\
    \u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n    check(capture(std::cout, [] {\
    \ print(); }) == \"\\n\", \"print()\");\n    check(capture(std::cout, [] { print(42);\
    \ }) == \"42\\n\", \"print(x)\");\n    check(capture(std::cout, [] { print(1,\
    \ \"a\", 2.5, 'c'); }) == \"1 a 2.5 c\\n\", \"print(x, ...)\");\n    check(capture(std::cout,\
    \ [] { print(std::vector<int>{1, 2}, std::make_pair(3, 4)); }) == \"1 2 3 4\\\
    n\", \"print(vector, pair)\");\n\n    // err: std::cerr \u306B\u7A7A\u767D\u533A\
    \u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n    check(capture(std::cerr,\
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
    \u51FA\u529B\u3059\u308B\n\n#include <array>\n#include <iostream>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"../../src/base/io.hpp\"\n\n// std::cout\
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
    \ \">> vector\");\n        check(bool(is), \"stream state\");\n    }\n    {\n\
    \        // \u30CD\u30B9\u30C8\u3057\u305F\u578B\n        std::istringstream is(\"\
    1 2 3 4 5 6\");\n        std::pair<std::vector<int>, std::array<int, 2>> p;\n\
    \        p.first.resize(2);\n        std::vector<std::pair<int, int>> vp(1);\n\
    \        is >> p >> vp;\n        check(p.first == std::vector<int>{1, 2} && p.second\
    \ == std::array<int, 2>{3, 4}, \">> pair<vector, array>\");\n        check(vp[0]\
    \ == std::make_pair(5, 6), \">> vector<pair>\");\n    }\n\n    // \u30E9\u30F3\
    \u30C0\u30E0: \u66F8\u3044\u3066\u8AAD\u307F\u623B\u3059\u3068\u4E00\u81F4\u3057\
    \u3001\u51FA\u529B\u306F\u611A\u76F4\u306B\u7A7A\u767D\u3067\u3064\u306A\u3044\
    \u3060\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        int n = rng() % 6;\n        std::vector<int> v(n);\n\
    \        for (int& x : v) x = (int)(rng() % 2001) - 1000;\n        std::string\
    \ expect;\n        for (int i = 0; i < n; i++) expect += (i ? \" \" : \"\") +\
    \ std::to_string(v[i]);\n        check(to_str(v) == expect, \"<< vector (random)\"\
    );\n        std::set<int> s(v.begin(), v.end());\n        std::string expect_s;\n\
    \        for (auto it = s.begin(); it != s.end(); ++it) expect_s += (it == s.begin()\
    \ ? \"\" : \" \") + std::to_string(*it);\n        check(to_str(s) == expect_s,\
    \ \"<< set (random)\");\n        std::istringstream is(expect);\n        std::vector<int>\
    \ w(n);\n        is >> w;\n        check(w == v, \">> vector (random)\");\n  \
    \      std::array<int, 4> a;\n        for (int& x : a) x = (int)(rng() % 2001)\
    \ - 1000;\n        std::istringstream is2(to_str(a));\n        std::array<int,\
    \ 4> b;\n        is2 >> b;\n        check(a == b, \"array round trip\");\n   \
    \     auto t = std::make_tuple((int)(rng() % 100), (long long)rng(), std::string(1\
    \ + rng() % 3, 'a' + rng() % 26));\n        std::istringstream is3(to_str(t));\n\
    \        decltype(t) u;\n        is3 >> u;\n        check(t == u, \"tuple round\
    \ trip\");\n    }\n\n    // print: std::cout \u306B\u7A7A\u767D\u533A\u5207\u308A\
    \u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n    check(capture(std::cout, [] {\
    \ print(); }) == \"\\n\", \"print()\");\n    check(capture(std::cout, [] { print(42);\
    \ }) == \"42\\n\", \"print(x)\");\n    check(capture(std::cout, [] { print(1,\
    \ \"a\", 2.5, 'c'); }) == \"1 a 2.5 c\\n\", \"print(x, ...)\");\n    check(capture(std::cout,\
    \ [] { print(std::vector<int>{1, 2}, std::make_pair(3, 4)); }) == \"1 2 3 4\\\
    n\", \"print(vector, pair)\");\n\n    // err: std::cerr \u306B\u7A7A\u767D\u533A\
    \u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n    check(capture(std::cerr,\
    \ [] { err(); }) == \"\\n\", \"err()\");\n    check(capture(std::cerr, [] { err(42);\
    \ }) == \"42\\n\", \"err(x)\");\n    check(capture(std::cerr, [] { err(1, \"a\"\
    , 2.5, 'c'); }) == \"1 a 2.5 c\\n\", \"err(x, ...)\");\n    check(capture(std::cerr,\
    \ [] { err(std::set<int>{2, 1}); }) == \"1 2\\n\", \"err(set)\");\n\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/base/io.hpp
  isVerificationFile: true
  path: test/unittest/io.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 06:02:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/io.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/io.test.cpp
- /verify/test/unittest/io.test.cpp.html
title: test/unittest/io.test.cpp
---
