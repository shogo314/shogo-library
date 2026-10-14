---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/io.hpp
    title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\
      \u30D0\u30FC\u30ED\u30FC\u30C9"
  - icon: ':heavy_check_mark:'
    path: src/base/macro.hpp
    title: "\u30DE\u30AF\u30ED (rep \u306A\u3069)"
  - icon: ':heavy_check_mark:'
    path: src/base/type_alias.hpp
    title: "\u578B\u306E\u5225\u540D"
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
  bundledCode: "#line 1 \"test/unittest/macro.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// macro.hpp \u306E\u30DE\u30AF\u30ED\u306E\u52D5\u4F5C\u3092\u691C\u8A3C\u3059\
    \u308B\n// \u5165\u529B\u30DE\u30AF\u30ED\u306F std::cin \u306E\u5165\u529B\u5143\
    \u3092\u3001\u51FA\u529B\u30DE\u30AF\u30ED\u306F std::cout \u306E\u51FA\u529B\u5148\
    \u3092\u4E00\u6642\u7684\u306B\u5DEE\u3057\u66FF\u3048\u3066\u691C\u8A3C\u3059\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#line 2 \"src/base/macro.hpp\"\n\n/**\n * @file macro.hpp\n * @brief \u30DE\
    \u30AF\u30ED (rep \u306A\u3069)\n */\n\n#line 2 \"src/base/io.hpp\"\n/**\n * @file\
    \ io.hpp\n * @brief \u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\
    \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\n */\n\n#include <array>\n#include\
    \ <cstddef>\n#include <iostream>\n#include <set>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\n// \u30CD\u30B9\u30C8\u3057\u305F\u578B (pair<vector<int>,\
    \ int> \u306A\u3069) \u3092\u6271\u3048\u308B\u3088\u3046\u306B\u5148\u306B\u5BA3\
    \u8A00\u3057\u3066\u304A\u304F\ntemplate <typename T1, typename T2, typename CharT,\
    \ typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::pair<T1, T2>& p);\ntemplate <typename... Types, typename CharT,\
    \ typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
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
    \ << x << ' ';\n    err(tail...);\n}\n#line 2 \"src/base/type_alias.hpp\"\n\n\
    /**\n * @file type_alias.hpp\n * @brief \u578B\u306E\u5225\u540D\n */\n\n#line\
    \ 9 \"src/base/type_alias.hpp\"\n#include <deque>\n#include <functional>\n#include\
    \ <list>\n#include <map>\n#include <queue>\n#line 15 \"src/base/type_alias.hpp\"\
    \n#include <string>\n#line 18 \"src/base/type_alias.hpp\"\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\n\ntemplate <typename\
    \ T>\nusing vec = std::vector<T>;\ntemplate <typename T, int N>\nusing ary = std::array<T,\
    \ N>;\nusing str = std::string;\nusing std::deque;\nusing std::list;\nusing std::map;\n\
    using std::multimap;\nusing std::multiset;\nusing std::pair;\nusing std::set;\n\
    \nusing pl = pair<ll, ll>;\nusing pd = pair<ld, ld>;\n\ntemplate <typename T>\n\
    using vv = vec<vec<T>>;\ntemplate <typename T>\nusing vvv = vec<vec<vec<T>>>;\n\
    using vl = vec<ll>;\nusing vvl = vv<ll>;\nusing vvvl = vvv<ll>;\nusing vs = vec<str>;\n\
    using vc = vec<char>;\nusing vi = vec<int>;\nusing vb = vec<bool>;\n\ntemplate\
    \ <typename T1, typename T2>\nusing vp = vec<pair<T1, T2>>;\nusing vpl = vec<pl>;\n\
    using vvpl = vv<pl>;\nusing vd = vec<ld>;\nusing vpd = vec<pd>;\n\ntemplate <int\
    \ N>\nusing al = ary<ll, N>;\ntemplate <int N1, int N2>\nusing aal = ary<ary<ll,\
    \ N2>, N1>;\ntemplate <int N>\nusing val = vec<al<N>>;\ntemplate <int N>\nusing\
    \ avl = ary<vl, N>;\n\ntemplate <typename T>\nusing ml = std::map<ll, T>;\nusing\
    \ mll = std::map<ll, ll>;\nusing sl = std::set<ll>;\nusing spl = set<pl>;\ntemplate\
    \ <int N>\nusing sal = set<al<N>>;\ntemplate <int N>\nusing asl = ary<sl, N>;\n\
    \ntemplate <typename T>\nusing heap_max = std::priority_queue<T, std::vector<T>,\
    \ std::less<T>>;\ntemplate <typename T>\nusing heap_min = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n#line 10 \"src/base/macro.hpp\"\n\n#pragma\
    \ GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n\n#define all(obj) (obj).begin(), (obj).end()\n\n#define CONCAT_IMPL2(x,\
    \ y) x##y\n#define CONCAT_IMPL(x, y) CONCAT_IMPL2(x, y)\n#define UNIQUE_ID(base)\
    \ CONCAT_IMPL(base, __COUNTER__)\n\n#define GET_MACRO(_1, _2, _3, _4, NAME, ...)\
    \ NAME\n\n#define rep4(i, a, n, t) for (long long i = static_cast<long long>(a),\
    \ i##_loop_end = static_cast<long long>(n), i##_loop_step = static_cast<long long>(t);\
    \ i < i##_loop_end; i += i##_loop_step)\n#define rep3(i, a, n) for (long long\
    \ i = static_cast<long long>(a), i##_loop_end = static_cast<long long>(n); i <\
    \ i##_loop_end; ++i)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep1(n) rep2(UNIQUE_ID(loop_counter_),\
    \ n)\n#define rep(...) GET_MACRO(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    \n#define repd4(i, a, n, t) for (long long i = static_cast<long long>(n) - 1,\
    \ i##_loop_end = static_cast<long long>(a), i##_loop_step = static_cast<long long>(t);\
    \ i >= i##_loop_end; i -= i##_loop_step)\n#define repd3(i, a, n) for (long long\
    \ i = static_cast<long long>(n) - 1, i##_loop_end = static_cast<long long>(a);\
    \ i >= i##_loop_end; --i)\n#define repd2(i, n) repd3(i, 0, n)\n#define repd(...)\
    \ GET_MACRO(__VA_ARGS__, repd4, repd3, repd2)(__VA_ARGS__)\n\n#define rrep(i,\
    \ n) rep(i, 1, (n) + 1)\n#define rrepd(i, n) repd(i, 1, (n) + 1)\n\n// \u63D0\u51FA\
    \u30B5\u30A4\u30BA\u3092\u6291\u3048\u308B\u305F\u3081 1 \u884C\u306B\u8A70\u3081\
    \u3066\u66F8\u3044\u3066\u3044\u308B\u306E\u3067\u6574\u5F62\u3057\u306A\u3044\
    \n// clang-format off\ninline void scan(){}\ntemplate<class Head,class... Tail>\n\
    inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}\n#define\
    \ LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n#define STR(...) str __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define IN(a, x) a x; std::cin >> x;\n#define CHAR(x) char x; std::cin >> x;\n\
    #define VL(a,n) vl a(n); std::cin >> a;\n#define AL(a,k) al<k> a; std::cin >>\
    \ a;\n#define AAL(a,n,m) aal<n,m> a; std::cin >> a;\n#define VC(a,n) vc a(n);\
    \ std::cin >> a;\n#define VS(a,n) vs a(n); std::cin >> a;\n#define VPL(a,n) vpl\
    \ a(n); std::cin >> a;\n#define VAL(a,n,k) val<k> a(n); std::cin >> a;\n#define\
    \ VVL(a,n,m) vvl a(n,vl(m)); std::cin >> a;\n#define SL(a,n) sl a;{VL(b,n);a=sl(all(b));}\n\
    \n#define NO std::cout << \"NO\" << std::endl; return;\n#define YES std::cout\
    \ << \"YES\" << std::endl; return;\n#define No std::cout << \"No\" << std::endl;\
    \ return;\n#define Yes std::cout << \"Yes\" << std::endl; return;\n#define Takahashi\
    \ std::cout << \"Takahashi\" << std::endl; return;\n#define Aoki std::cout <<\
    \ \"Aoki\" << std::endl; return;\n// clang-format on\n#line 8 \"test/unittest/macro.test.cpp\"\
    \n\n#include <algorithm>\n#line 11 \"test/unittest/macro.test.cpp\"\n#include\
    \ <sstream>\n#line 14 \"test/unittest/macro.test.cpp\"\n\nbool ok = true;\nvoid\
    \ check(bool cond, const char* what) {\n    if (!cond) {\n        if (ok) std::cerr\
    \ << \"failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\n// for\
    \ \u6587\u3067\u611A\u76F4\u306B\u4F5C\u3063\u305F\u5217\nstd::vector<ll> naive_up(ll\
    \ a, ll n, ll t) {\n    std::vector<ll> v;\n    for (ll i = a; i < n; i += t)\
    \ v.push_back(i);\n    return v;\n}\nstd::vector<ll> naive_down(ll a, ll n, ll\
    \ t) {\n    std::vector<ll> v;\n    for (ll i = n - 1; i >= a; i -= t) v.push_back(i);\n\
    \    return v;\n}\n\n// \u51FA\u529B\u30DE\u30AF\u30ED\u306F return \u3059\u308B\
    \u306E\u3067 void \u95A2\u6570\u306E\u4E2D\u3067\u4F7F\u3046\n// after \u304C\u66F8\
    \u304D\u63DB\u308F\u3089\u306A\u3051\u308C\u3070\u3001\u30DE\u30AF\u30ED\u306E\
    \u5F8C\u308D\u306F\u5B9F\u884C\u3055\u308C\u3066\u3044\u306A\u3044\nint after\
    \ = 0;\nvoid yes_upper() { YES after = 1; }\nvoid no_upper() { NO after = 1; }\n\
    void yes_lower() { Yes after = 1; }\nvoid no_lower() { No after = 1; }\nvoid takahashi()\
    \ { Takahashi after = 1; }\nvoid aoki() { Aoki after = 1; }\n\ntemplate <class\
    \ F>\nstd::string capture_cout(F f) {\n    std::ostringstream buf;\n    std::streambuf*\
    \ old = std::cout.rdbuf(buf.rdbuf());\n    f();\n    std::cout.rdbuf(old);\n \
    \   return buf.str();\n}\n\nint calls = 0;\nll counted(ll x) {\n    calls++;\n\
    \    return x;\n}\n\nint main() {\n    // all\n    {\n        std::vector<int>\
    \ v{3, 1, 2};\n        std::sort(all(v));\n        check(v == std::vector<int>({1,\
    \ 2, 3}), \"all\");\n    }\n\n    // rep (1\u301C4 \u5F15\u6570)\n    for (ll\
    \ a = -3; a <= 6; a++) {\n        for (ll n = -3; n <= 8; n++) {\n           \
    \ {\n                int cnt = 0;\n                rep(n) cnt++;\n           \
    \     check(cnt == std::max<ll>(n, 0), \"rep(n)\");\n            }\n         \
    \   {\n                std::vector<ll> v;\n                rep(i, n) v.push_back(i);\n\
    \                check(v == naive_up(0, n, 1), \"rep(i, n)\");\n            }\n\
    \            {\n                std::vector<ll> v;\n                rep(i, a,\
    \ n) v.push_back(i);\n                check(v == naive_up(a, n, 1), \"rep(i, a,\
    \ n)\");\n            }\n            for (ll t = 1; t <= 4; t++) {\n         \
    \       std::vector<ll> v;\n                rep(i, a, n, t) v.push_back(i);\n\
    \                check(v == naive_up(a, n, t), \"rep(i, a, n, t)\");\n       \
    \     }\n            {\n                std::vector<ll> v;\n                repd(i,\
    \ n) v.push_back(i);\n                check(v == naive_down(0, n, 1), \"repd(i,\
    \ n)\");\n            }\n            {\n                std::vector<ll> v;\n \
    \               repd(i, a, n) v.push_back(i);\n                check(v == naive_down(a,\
    \ n, 1), \"repd(i, a, n)\");\n            }\n            for (ll t = 1; t <= 4;\
    \ t++) {\n                std::vector<ll> v;\n                repd(i, a, n, t)\
    \ v.push_back(i);\n                check(v == naive_down(a, n, t), \"repd(i, a,\
    \ n, t)\");\n            }\n        }\n        {\n            std::vector<ll>\
    \ v;\n            rrep(i, a) v.push_back(i);\n            check(v == naive_up(1,\
    \ a + 1, 1), \"rrep(i, n)\");\n        }\n        {\n            std::vector<ll>\
    \ v;\n            rrepd(i, a) v.push_back(i);\n            check(v == naive_down(1,\
    \ a + 1, 1), \"rrepd(i, n)\");\n        }\n    }\n    {\n        // rep(n) \u3092\
    \u540C\u3058\u30B9\u30B3\u30FC\u30D7\u3067\u5165\u308C\u5B50\u306B\u3067\u304D\
    \u308B (\u30EB\u30FC\u30D7\u5909\u6570\u306E\u540D\u524D\u304C\u91CD\u306A\u3089\
    \u306A\u3044)\n        int cnt = 0;\n        rep(3) rep(4) cnt++;\n        check(cnt\
    \ == 12, \"nested rep(n)\");\n        // \u7D42\u7AEF\u3068\u5897\u5206\u306F\u6700\
    \u521D\u306B 1 \u56DE\u3060\u3051\u8A55\u4FA1\u3055\u308C\u308B\n        calls\
    \ = 0;\n        int iter = 0;\n        rep(i, 0, counted(5), counted(2)) iter++;\n\
    \        check(iter == 3 && calls == 2, \"rep evaluates bounds once\");\n    \
    \    // \u30EB\u30FC\u30D7\u5909\u6570\u306F long long\n        rep(i, 1) static_assert(std::is_same_v<decltype(i),\
    \ long long>);\n    }\n\n    // \u5165\u529B\u30DE\u30AF\u30ED\n    {\n      \
    \  std::istringstream in(\n            \"1 -2 \"         // LL(a, b)\n       \
    \     \"hello world \"  // STR(s, t)\n            \"7 \"            // IN(int,\
    \ x)\n            \"z \"            // CHAR(c)\n            \"3 4 5 \"       \
    \ // VL(v, 3)\n            \"6 7 \"          // AL(arr, 2)\n            \"1 2\
    \ 3 4 5 6 \"  // AAL(aa, 2, 3)\n            \"x y \"          // VC(vc_, 2)\n\
    \            \"ab cd \"        // VS(vs_, 2)\n            \"1 2 3 4 \"      //\
    \ VPL(vp, 2)\n            \"1 2 3 4 5 6 \"  // VAL(va, 2, 3)\n            \"9\
    \ 8 7 6 \"      // VVL(vv_, 2, 2)\n            \"5 3 5 1 \");    // SL(st, 4)\n\
    \        std::streambuf* old = std::cin.rdbuf(in.rdbuf());\n        LL(a, b);\n\
    \        STR(s, t);\n        IN(int, x);\n        CHAR(c);\n        VL(v, 3);\n\
    \        AL(arr, 2);\n        AAL(aa, 2, 3);\n        VC(vc_, 2);\n        VS(vs_,\
    \ 2);\n        VPL(vp, 2);\n        VAL(va, 2, 3);\n        VVL(vv_, 2, 2);\n\
    \        SL(st, 4);\n        std::cin.rdbuf(old);\n        check(a == 1 && b ==\
    \ -2 && std::is_same_v<decltype(a), ll>, \"LL\");\n        check(s == \"hello\"\
    \ && t == \"world\", \"STR\");\n        check(x == 7 && std::is_same_v<decltype(x),\
    \ int>, \"IN\");\n        check(c == 'z', \"CHAR\");\n        check(v == vl({3,\
    \ 4, 5}), \"VL\");\n        check(arr == al<2>{6, 7}, \"AL\");\n        check(aa\
    \ == aal<2, 3>{{{1, 2, 3}, {4, 5, 6}}}, \"AAL\");\n        check(vc_ == vc({'x',\
    \ 'y'}), \"VC\");\n        check(vs_ == vs({\"ab\", \"cd\"}), \"VS\");\n     \
    \   check(vp == vpl({{1, 2}, {3, 4}}), \"VPL\");\n        check(va == val<3>({{1,\
    \ 2, 3}, {4, 5, 6}}), \"VAL\");\n        check(vv_ == vvl({{9, 8}, {7, 6}}), \"\
    VVL\");\n        check(st == sl({1, 3, 5}), \"SL\");\n        check(bool(in),\
    \ \"input stream state\");\n    }\n    {\n        // scan \u3092\u76F4\u63A5\u4F7F\
    \u3046\n        std::istringstream in(\"10 abc 2.5\");\n        std::streambuf*\
    \ old = std::cin.rdbuf(in.rdbuf());\n        int p;\n        std::string q;\n\
    \        double r;\n        scan(p, q, r);\n        scan();\n        std::cin.rdbuf(old);\n\
    \        check(p == 10 && q == \"abc\" && r == 2.5, \"scan\");\n    }\n\n    //\
    \ \u51FA\u529B\u30DE\u30AF\u30ED (\u51FA\u529B\u3057\u3066 return \u3059\u308B\
    )\n    after = 0;\n    check(capture_cout(yes_upper) == \"YES\\n\", \"YES\");\n\
    \    check(capture_cout(no_upper) == \"NO\\n\", \"NO\");\n    check(capture_cout(yes_lower)\
    \ == \"Yes\\n\", \"Yes\");\n    check(capture_cout(no_lower) == \"No\\n\", \"\
    No\");\n    check(capture_cout(takahashi) == \"Takahashi\\n\", \"Takahashi\");\n\
    \    check(capture_cout(aoki) == \"Aoki\\n\", \"Aoki\");\n    check(after == 0,\
    \ \"output macros return\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// macro.hpp \u306E\u30DE\u30AF\u30ED\u306E\u52D5\u4F5C\u3092\u691C\u8A3C\u3059\
    \u308B\n// \u5165\u529B\u30DE\u30AF\u30ED\u306F std::cin \u306E\u5165\u529B\u5143\
    \u3092\u3001\u51FA\u529B\u30DE\u30AF\u30ED\u306F std::cout \u306E\u51FA\u529B\u5148\
    \u3092\u4E00\u6642\u7684\u306B\u5DEE\u3057\u66FF\u3048\u3066\u691C\u8A3C\u3059\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../src/base/macro.hpp\"\n\n#include <algorithm>\n#include <iostream>\n\
    #include <sstream>\n#include <string>\n#include <vector>\n\nbool ok = true;\n\
    void check(bool cond, const char* what) {\n    if (!cond) {\n        if (ok) std::cerr\
    \ << \"failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\n// for\
    \ \u6587\u3067\u611A\u76F4\u306B\u4F5C\u3063\u305F\u5217\nstd::vector<ll> naive_up(ll\
    \ a, ll n, ll t) {\n    std::vector<ll> v;\n    for (ll i = a; i < n; i += t)\
    \ v.push_back(i);\n    return v;\n}\nstd::vector<ll> naive_down(ll a, ll n, ll\
    \ t) {\n    std::vector<ll> v;\n    for (ll i = n - 1; i >= a; i -= t) v.push_back(i);\n\
    \    return v;\n}\n\n// \u51FA\u529B\u30DE\u30AF\u30ED\u306F return \u3059\u308B\
    \u306E\u3067 void \u95A2\u6570\u306E\u4E2D\u3067\u4F7F\u3046\n// after \u304C\u66F8\
    \u304D\u63DB\u308F\u3089\u306A\u3051\u308C\u3070\u3001\u30DE\u30AF\u30ED\u306E\
    \u5F8C\u308D\u306F\u5B9F\u884C\u3055\u308C\u3066\u3044\u306A\u3044\nint after\
    \ = 0;\nvoid yes_upper() { YES after = 1; }\nvoid no_upper() { NO after = 1; }\n\
    void yes_lower() { Yes after = 1; }\nvoid no_lower() { No after = 1; }\nvoid takahashi()\
    \ { Takahashi after = 1; }\nvoid aoki() { Aoki after = 1; }\n\ntemplate <class\
    \ F>\nstd::string capture_cout(F f) {\n    std::ostringstream buf;\n    std::streambuf*\
    \ old = std::cout.rdbuf(buf.rdbuf());\n    f();\n    std::cout.rdbuf(old);\n \
    \   return buf.str();\n}\n\nint calls = 0;\nll counted(ll x) {\n    calls++;\n\
    \    return x;\n}\n\nint main() {\n    // all\n    {\n        std::vector<int>\
    \ v{3, 1, 2};\n        std::sort(all(v));\n        check(v == std::vector<int>({1,\
    \ 2, 3}), \"all\");\n    }\n\n    // rep (1\u301C4 \u5F15\u6570)\n    for (ll\
    \ a = -3; a <= 6; a++) {\n        for (ll n = -3; n <= 8; n++) {\n           \
    \ {\n                int cnt = 0;\n                rep(n) cnt++;\n           \
    \     check(cnt == std::max<ll>(n, 0), \"rep(n)\");\n            }\n         \
    \   {\n                std::vector<ll> v;\n                rep(i, n) v.push_back(i);\n\
    \                check(v == naive_up(0, n, 1), \"rep(i, n)\");\n            }\n\
    \            {\n                std::vector<ll> v;\n                rep(i, a,\
    \ n) v.push_back(i);\n                check(v == naive_up(a, n, 1), \"rep(i, a,\
    \ n)\");\n            }\n            for (ll t = 1; t <= 4; t++) {\n         \
    \       std::vector<ll> v;\n                rep(i, a, n, t) v.push_back(i);\n\
    \                check(v == naive_up(a, n, t), \"rep(i, a, n, t)\");\n       \
    \     }\n            {\n                std::vector<ll> v;\n                repd(i,\
    \ n) v.push_back(i);\n                check(v == naive_down(0, n, 1), \"repd(i,\
    \ n)\");\n            }\n            {\n                std::vector<ll> v;\n \
    \               repd(i, a, n) v.push_back(i);\n                check(v == naive_down(a,\
    \ n, 1), \"repd(i, a, n)\");\n            }\n            for (ll t = 1; t <= 4;\
    \ t++) {\n                std::vector<ll> v;\n                repd(i, a, n, t)\
    \ v.push_back(i);\n                check(v == naive_down(a, n, t), \"repd(i, a,\
    \ n, t)\");\n            }\n        }\n        {\n            std::vector<ll>\
    \ v;\n            rrep(i, a) v.push_back(i);\n            check(v == naive_up(1,\
    \ a + 1, 1), \"rrep(i, n)\");\n        }\n        {\n            std::vector<ll>\
    \ v;\n            rrepd(i, a) v.push_back(i);\n            check(v == naive_down(1,\
    \ a + 1, 1), \"rrepd(i, n)\");\n        }\n    }\n    {\n        // rep(n) \u3092\
    \u540C\u3058\u30B9\u30B3\u30FC\u30D7\u3067\u5165\u308C\u5B50\u306B\u3067\u304D\
    \u308B (\u30EB\u30FC\u30D7\u5909\u6570\u306E\u540D\u524D\u304C\u91CD\u306A\u3089\
    \u306A\u3044)\n        int cnt = 0;\n        rep(3) rep(4) cnt++;\n        check(cnt\
    \ == 12, \"nested rep(n)\");\n        // \u7D42\u7AEF\u3068\u5897\u5206\u306F\u6700\
    \u521D\u306B 1 \u56DE\u3060\u3051\u8A55\u4FA1\u3055\u308C\u308B\n        calls\
    \ = 0;\n        int iter = 0;\n        rep(i, 0, counted(5), counted(2)) iter++;\n\
    \        check(iter == 3 && calls == 2, \"rep evaluates bounds once\");\n    \
    \    // \u30EB\u30FC\u30D7\u5909\u6570\u306F long long\n        rep(i, 1) static_assert(std::is_same_v<decltype(i),\
    \ long long>);\n    }\n\n    // \u5165\u529B\u30DE\u30AF\u30ED\n    {\n      \
    \  std::istringstream in(\n            \"1 -2 \"         // LL(a, b)\n       \
    \     \"hello world \"  // STR(s, t)\n            \"7 \"            // IN(int,\
    \ x)\n            \"z \"            // CHAR(c)\n            \"3 4 5 \"       \
    \ // VL(v, 3)\n            \"6 7 \"          // AL(arr, 2)\n            \"1 2\
    \ 3 4 5 6 \"  // AAL(aa, 2, 3)\n            \"x y \"          // VC(vc_, 2)\n\
    \            \"ab cd \"        // VS(vs_, 2)\n            \"1 2 3 4 \"      //\
    \ VPL(vp, 2)\n            \"1 2 3 4 5 6 \"  // VAL(va, 2, 3)\n            \"9\
    \ 8 7 6 \"      // VVL(vv_, 2, 2)\n            \"5 3 5 1 \");    // SL(st, 4)\n\
    \        std::streambuf* old = std::cin.rdbuf(in.rdbuf());\n        LL(a, b);\n\
    \        STR(s, t);\n        IN(int, x);\n        CHAR(c);\n        VL(v, 3);\n\
    \        AL(arr, 2);\n        AAL(aa, 2, 3);\n        VC(vc_, 2);\n        VS(vs_,\
    \ 2);\n        VPL(vp, 2);\n        VAL(va, 2, 3);\n        VVL(vv_, 2, 2);\n\
    \        SL(st, 4);\n        std::cin.rdbuf(old);\n        check(a == 1 && b ==\
    \ -2 && std::is_same_v<decltype(a), ll>, \"LL\");\n        check(s == \"hello\"\
    \ && t == \"world\", \"STR\");\n        check(x == 7 && std::is_same_v<decltype(x),\
    \ int>, \"IN\");\n        check(c == 'z', \"CHAR\");\n        check(v == vl({3,\
    \ 4, 5}), \"VL\");\n        check(arr == al<2>{6, 7}, \"AL\");\n        check(aa\
    \ == aal<2, 3>{{{1, 2, 3}, {4, 5, 6}}}, \"AAL\");\n        check(vc_ == vc({'x',\
    \ 'y'}), \"VC\");\n        check(vs_ == vs({\"ab\", \"cd\"}), \"VS\");\n     \
    \   check(vp == vpl({{1, 2}, {3, 4}}), \"VPL\");\n        check(va == val<3>({{1,\
    \ 2, 3}, {4, 5, 6}}), \"VAL\");\n        check(vv_ == vvl({{9, 8}, {7, 6}}), \"\
    VVL\");\n        check(st == sl({1, 3, 5}), \"SL\");\n        check(bool(in),\
    \ \"input stream state\");\n    }\n    {\n        // scan \u3092\u76F4\u63A5\u4F7F\
    \u3046\n        std::istringstream in(\"10 abc 2.5\");\n        std::streambuf*\
    \ old = std::cin.rdbuf(in.rdbuf());\n        int p;\n        std::string q;\n\
    \        double r;\n        scan(p, q, r);\n        scan();\n        std::cin.rdbuf(old);\n\
    \        check(p == 10 && q == \"abc\" && r == 2.5, \"scan\");\n    }\n\n    //\
    \ \u51FA\u529B\u30DE\u30AF\u30ED (\u51FA\u529B\u3057\u3066 return \u3059\u308B\
    )\n    after = 0;\n    check(capture_cout(yes_upper) == \"YES\\n\", \"YES\");\n\
    \    check(capture_cout(no_upper) == \"NO\\n\", \"NO\");\n    check(capture_cout(yes_lower)\
    \ == \"Yes\\n\", \"Yes\");\n    check(capture_cout(no_lower) == \"No\\n\", \"\
    No\");\n    check(capture_cout(takahashi) == \"Takahashi\\n\", \"Takahashi\");\n\
    \    check(capture_cout(aoki) == \"Aoki\\n\", \"Aoki\");\n    check(after == 0,\
    \ \"output macros return\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/base/macro.hpp
  - src/base/io.hpp
  - src/base/type_alias.hpp
  isVerificationFile: true
  path: test/unittest/macro.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/macro.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/macro.test.cpp
- /verify/test/unittest/macro.test.cpp.html
title: test/unittest/macro.test.cpp
---
