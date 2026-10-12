---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/io.hpp
    title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\
      \u30D0\u30FC\u30ED\u30FC\u30C9"
  - icon: ':heavy_check_mark:'
    path: src/base/type_alias.hpp
    title: "\u578B\u306E\u5225\u540D"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1160.test.cpp
    title: test/aoj/1160.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/macro.test.cpp
    title: test/unittest/macro.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30DE\u30AF\u30ED (rep \u306A\u3069)"
    links: []
  bundledCode: "#line 2 \"src/base/macro.hpp\"\n\n/**\n * @file macro.hpp\n * @brief\
    \ \u30DE\u30AF\u30ED (rep \u306A\u3069)\n */\n\n#line 2 \"src/base/io.hpp\"\n\
    /**\n * @file io.hpp\n * @brief \u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001\
    iostream\u306E\u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\n */\n\n#include <array>\n\
    #include <iostream>\n#include <set>\n#include <utility>\n#include <tuple>\n#include\
    \ <vector>\n\n// \u30CD\u30B9\u30C8\u3057\u305F\u578B (pair<vector<int>, int>\
    \ \u306A\u3069) \u3092\u6271\u3048\u308B\u3088\u3046\u306B\u5148\u306B\u5BA3\u8A00\
    \u3057\u3066\u304A\u304F\ntemplate <typename T1, typename T2, typename CharT,\
    \ typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
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
    \ << x << ' ';\n    err(tail...);\n}\n#line 2 \"src/base/type_alias.hpp\"\n\n\
    /**\n * @file type_alias.hpp\n * @brief \u578B\u306E\u5225\u540D\n */\n\n#include\
    \ <bits/stdc++.h>\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\n\ntemplate <typename T>\nusing vec = std::vector<T>;\n\
    template <typename T, int N>\nusing ary = std::array<T, N>;\nusing str = std::string;\n\
    using std::deque;\nusing std::list;\nusing std::map;\nusing std::multimap;\nusing\
    \ std::multiset;\nusing std::pair;\nusing std::set;\n\nusing pl = pair<ll, ll>;\n\
    using pd = pair<ld, ld>;\n\ntemplate <typename T>\nusing vv = vec<vec<T>>;\ntemplate\
    \ <typename T>\nusing vvv = vec<vec<vec<T>>>;\nusing vl = vec<ll>;\nusing vvl\
    \ = vv<ll>;\nusing vvvl = vvv<ll>;\nusing vs = vec<str>;\nusing vc = vec<char>;\n\
    using vi = vec<int>;\nusing vb = vec<bool>;\n\ntemplate <typename T1, typename\
    \ T2>\nusing vp = vec<pair<T1, T2>>;\nusing vpl = vec<pl>;\nusing vvpl = vv<pl>;\n\
    using vd = vec<ld>;\nusing vpd = vec<pd>;\n\ntemplate <int N>\nusing al = ary<ll,\
    \ N>;\ntemplate <int N1, int N2>\nusing aal = ary<ary<ll, N2>, N1>;\ntemplate\
    \ <int N>\nusing val = vec<al<N>>;\ntemplate <int N>\nusing avl = ary<vl,N>;\n\
    \ntemplate <typename T>\nusing ml = std::map<ll, T>;\nusing mll = std::map<ll,\
    \ ll>;\nusing sl = std::set<ll>;\nusing spl = set<pl>;\ntemplate <int N>\nusing\
    \ sal = set<al<N>>;\ntemplate <int N>\nusing asl = ary<sl,N>;\n\ntemplate <typename\
    \ T>\nusing heap_max = std::priority_queue<T, std::vector<T>, std::less<T>>;\n\
    template <typename T>\nusing heap_min = std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>>;\n#line 10 \"src/base/macro.hpp\"\n\n#pragma GCC target(\"\
    avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n\
    \n#define all(obj) (obj).begin(), (obj).end()\n\n#define CONCAT_IMPL2(x, y) x##y\n\
    #define CONCAT_IMPL(x, y) CONCAT_IMPL2(x, y)\n#define UNIQUE_ID(base) CONCAT_IMPL(base,\
    \ __COUNTER__)\n\n#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME\n\n#define\
    \ rep4(i, a, n, t) for (long long i = static_cast<long long>(a), i##_loop_end\
    \ = static_cast<long long>(n), i##_loop_step = static_cast<long long>(t); i <\
    \ i##_loop_end; i += i##_loop_step)\n#define rep3(i, a, n) for (long long i =\
    \ static_cast<long long>(a), i##_loop_end = static_cast<long long>(n); i < i##_loop_end;\
    \ ++i)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep1(n) rep2(UNIQUE_ID(loop_counter_),\
    \ n)\n#define rep(...) GET_MACRO(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    \n#define repd4(i, a, n, t) for (long long i = static_cast<long long>(n) - 1,\
    \ i##_loop_end = static_cast<long long>(a), i##_loop_step = static_cast<long long>(t);\
    \ i >= i##_loop_end; i -= i##_loop_step)\n#define repd3(i, a, n) for (long long\
    \ i = static_cast<long long>(n) - 1, i##_loop_end = static_cast<long long>(a);\
    \ i >= i##_loop_end; --i)\n#define repd2(i, n) repd3(i, 0, n)\n#define repd(...)\
    \ GET_MACRO(__VA_ARGS__, repd4, repd3, repd2)(__VA_ARGS__)\n\n#define rrep(i,\
    \ n) rep(i, 1, (n) + 1)\n#define rrepd(i, n) repd(i, 1, (n) + 1)\n\ninline void\
    \ scan(){}\ntemplate<class Head,class... Tail>\ninline void scan(Head&head,Tail&...\
    \ tail){std::cin>>head;scan(tail...);}\n#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define STR(...) str __VA_ARGS__;scan(__VA_ARGS__)\n#define IN(a, x) a x; std::cin\
    \ >> x;\n#define CHAR(x) char x; std::cin >> x;\n#define VL(a,n) vl a(n); std::cin\
    \ >> a;\n#define AL(a,k) al<k> a; std::cin >> a;\n#define AAL(a,n,m) aal<n,m>\
    \ a; std::cin >> a;\n#define VC(a,n) vc a(n); std::cin >> a;\n#define VS(a,n)\
    \ vs a(n); std::cin >> a;\n#define VPL(a,n) vpl a(n); std::cin >> a;\n#define\
    \ VAL(a,n,k) val<k> a(n); std::cin >> a;\n#define VVL(a,n,m) vvl a(n,vl(m)); std::cin\
    \ >> a;\n#define SL(a,n) sl a;{VL(b,n);a=sl(all(b));}\n\n#define NO std::cout\
    \ << \"NO\" << std::endl; return;\n#define YES std::cout << \"YES\" << std::endl;\
    \ return;\n#define No std::cout << \"No\" << std::endl; return;\n#define Yes std::cout\
    \ << \"Yes\" << std::endl; return;\n#define Takahashi std::cout << \"Takahashi\"\
    \ << std::endl; return;\n#define Aoki std::cout << \"Aoki\" << std::endl; return;\n"
  code: "#pragma once\n\n/**\n * @file macro.hpp\n * @brief \u30DE\u30AF\u30ED (rep\
    \ \u306A\u3069)\n */\n\n#include \"io.hpp\"\n#include \"type_alias.hpp\"\n\n#pragma\
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
    \ n) rep(i, 1, (n) + 1)\n#define rrepd(i, n) repd(i, 1, (n) + 1)\n\ninline void\
    \ scan(){}\ntemplate<class Head,class... Tail>\ninline void scan(Head&head,Tail&...\
    \ tail){std::cin>>head;scan(tail...);}\n#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define STR(...) str __VA_ARGS__;scan(__VA_ARGS__)\n#define IN(a, x) a x; std::cin\
    \ >> x;\n#define CHAR(x) char x; std::cin >> x;\n#define VL(a,n) vl a(n); std::cin\
    \ >> a;\n#define AL(a,k) al<k> a; std::cin >> a;\n#define AAL(a,n,m) aal<n,m>\
    \ a; std::cin >> a;\n#define VC(a,n) vc a(n); std::cin >> a;\n#define VS(a,n)\
    \ vs a(n); std::cin >> a;\n#define VPL(a,n) vpl a(n); std::cin >> a;\n#define\
    \ VAL(a,n,k) val<k> a(n); std::cin >> a;\n#define VVL(a,n,m) vvl a(n,vl(m)); std::cin\
    \ >> a;\n#define SL(a,n) sl a;{VL(b,n);a=sl(all(b));}\n\n#define NO std::cout\
    \ << \"NO\" << std::endl; return;\n#define YES std::cout << \"YES\" << std::endl;\
    \ return;\n#define No std::cout << \"No\" << std::endl; return;\n#define Yes std::cout\
    \ << \"Yes\" << std::endl; return;\n#define Takahashi std::cout << \"Takahashi\"\
    \ << std::endl; return;\n#define Aoki std::cout << \"Aoki\" << std::endl; return;\n"
  dependsOn:
  - src/base/io.hpp
  - src/base/type_alias.hpp
  isVerificationFile: false
  path: src/base/macro.hpp
  requiredBy: []
  timestamp: '2026-10-12 20:22:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/macro.test.cpp
  - test/aoj/1160.test.cpp
documentation_of: src/base/macro.hpp
layout: document
title: "\u30DE\u30AF\u30ED (rep \u306A\u3069)"
---

コンテスト用のマクロです。[型の別名](type_alias.hpp) と、入力用のマクロが使う [入出力](io.hpp) を include し、最適化の `#pragma` (`avx2`、`O3`、`unroll-loops`) も設定します。

```cpp
void solve() {
    LL(n, m);                  // long long n, m; を読む
    VL(a, n);                  // vector<long long> a(n); を読む
    rep(i, n) a[i] += m;
    std::sort(all(a));
    if (a[0] > 0) { Yes }      // "Yes" を出力して return
    No
}
```

## ループ

ループ変数はすべて `long long` です。

| マクロ | 意味 |
|---|---|
| `rep(n)` | `n` 回繰り返す |
| `rep(i, n)` | `i = 0, 1, ..., n-1` |
| `rep(i, a, n)` | `i = a, a+1, ..., n-1` |
| `rep(i, a, n, t)` | `i = a, a+t, ...` (`n` 未満) |
| `repd(i, n)` | `i = n-1, n-2, ..., 0` |
| `repd(i, a, n)` | `i = n-1, n-2, ..., a` |
| `repd(i, a, n, t)` | `i = n-1, n-1-t, ...` (`a` 以上) |
| `rrep(i, n)` | `i = 1, 2, ..., n` |
| `rrepd(i, n)` | `i = n, n-1, ..., 1` |
| `all(v)` | `v.begin(), v.end()` |

## 入力

宣言と読み込みを同時に行います。

| マクロ | 宣言される変数 |
|---|---|
| `LL(a, b, ...)` | `ll a, b, ...;` |
| `STR(s, t, ...)` | `str s, t, ...;` |
| `IN(T, x)` | `T x;` |
| `CHAR(c)` | `char c;` |
| `VL(a, n)` / `VC(a, n)` / `VS(a, n)` / `VPL(a, n)` | 長さ `n` の `vl` / `vc` / `vs` / `vpl` |
| `VVL(a, n, m)` | `n` × `m` の `vvl` |
| `AL(a, k)` / `AAL(a, n, m)` | `al<k>` / `aal<n, m>` |
| `VAL(a, n, k)` | 長さ `n` の `val<k>` |
| `SL(a, n)` | `n` 個読んだ `sl` (`set<ll>`) |

`scan(a, b, ...)` で、宣言済みの変数を読むこともできます。

## 出力して終了

文字列を出力して改行し、`return;` します。戻り値が `void` の関数 (`solve` など) の中で使います。

| マクロ | 出力 |
|---|---|
| `Yes` / `No` | `Yes` / `No` |
| `YES` / `NO` | `YES` / `NO` |
| `Takahashi` / `Aoki` | `Takahashi` / `Aoki` |
