---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base/type_alias.hpp
    title: base/type_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "base/type_alias.hpp"

    #include <bits/stdc++.h>


    using ll = long long;

    using ull = unsigned long long;

    using ld = long double;


    template <typename T>

    using vec = std::vector<T>;

    template <typename T, int N>

    using ary = std::array<T, N>;

    using str = std::string;

    using std::deque;

    using std::list;

    using std::map;

    using std::multimap;

    using std::multiset;

    using std::pair;

    using std::set;


    using pl = pair<ll, ll>;

    using pd = pair<ld, ld>;


    template <typename T>

    using vv = vec<vec<T>>;

    template <typename T>

    using vvv = vec<vec<vec<T>>>;

    using vl = vec<ll>;

    using vvl = vv<ll>;

    using vvvl = vvv<ll>;

    using vs = vec<str>;

    using vc = vec<char>;

    using vi = vec<int>;

    using vb = vec<bool>;


    template <typename T1, typename T2>

    using vp = vec<pair<T1, T2>>;

    using vpl = vec<pl>;

    using vvpl = vv<pl>;

    using vd = vec<ld>;

    using vpd = vec<pd>;


    template <int N>

    using al = ary<ll, N>;

    template <int N1, int N2>

    using aal = ary<ary<ll, N2>, N1>;

    template <int N>

    using val = vec<al<N>>;

    template <int N>

    using avl = ary<vl,N>;


    template <typename T>

    using ml = std::map<ll, T>;

    using mll = std::map<ll, ll>;

    using sl = std::set<ll>;

    using spl = set<pl>;

    template <int N>

    using sal = set<al<N>>;

    template <int N>

    using asl = ary<sl,N>;


    template <typename T>

    using heap_max = std::priority_queue<T, std::vector<T>, std::less<T>>;

    template <typename T>

    using heap_min = std::priority_queue<T, std::vector<T>, std::greater<T>>;

    #line 3 "base/macro.hpp"


    #pragma GCC target("avx2")

    #pragma GCC optimize("O3")

    #pragma GCC optimize("unroll-loops")


    #define all(obj) (obj).begin(), (obj).end()


    #define CONCAT_IMPL2(x, y) x##y

    #define CONCAT_IMPL(x, y) CONCAT_IMPL2(x, y)

    #define UNIQUE_ID(base) CONCAT_IMPL(base, __COUNTER__)


    #define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME


    #define rep4(i, a, n, t) for (long long i = static_cast<long long>(a), i##_loop_end
    = static_cast<long long>(n), i##_loop_step = static_cast<long long>(t); i < i##_loop_end;
    i += i##_loop_step)

    #define rep3(i, a, n) for (long long i = static_cast<long long>(a), i##_loop_end
    = static_cast<long long>(n); i < i##_loop_end; ++i)

    #define rep2(i, n) rep3(i, 0, n)

    #define rep1(n) rep2(UNIQUE_ID(loop_counter_), n)

    #define rep(...) GET_MACRO(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)


    #define repd4(i, a, n, t) for (long long i = static_cast<long long>(n) - 1, i##_loop_end
    = static_cast<long long>(a), i##_loop_step = static_cast<long long>(t); i >= i##_loop_end;
    i -= i##_loop_step)

    #define repd3(i, a, n) for (long long i = static_cast<long long>(n) - 1, i##_loop_end
    = static_cast<long long>(a); i >= i##_loop_end; --i)

    #define repd2(i, n) repd3(i, 0, n)

    #define repd(...) GET_MACRO(__VA_ARGS__, repd4, repd3, repd2)(__VA_ARGS__)


    #define rrep(i, n) rep(i, 1, (n) + 1)

    #define rrepd(i, n) repd(i, 1, (n) + 1)


    inline void scan(){}

    template<class Head,class... Tail>

    inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}

    #define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)

    #define STR(...) str __VA_ARGS__;scan(__VA_ARGS__)

    #define IN(a, x) a x; std::cin >> x;

    #define CHAR(x) char x; std::cin >> x;

    #define VL(a,n) vl a(n); std::cin >> a;

    #define AL(a,k) al<k> a; std::cin >> a;

    #define AAL(a,n,m) aal<n,m> a; std::cin >> a;

    #define VC(a,n) vc a(n); std::cin >> a;

    #define VS(a,n) vs a(n); std::cin >> a;

    #define VPL(a,n) vpl a(n); std::cin >> a;

    #define VAL(a,n,k) val<k> a(n); std::cin >> a;

    #define VVL(a,n,m) vvl a(n,vl(m)); std::cin >> a;

    #define SL(a,n) sl a;{VL(b,n);a=sl(all(b));}


    #define NO std::cout << "NO" << std::endl; return;

    #define YES std::cout << "YES" << std::endl; return;

    #define No std::cout << "No" << std::endl; return;

    #define Yes std::cout << "Yes" << std::endl; return;

    #define Takahashi std::cout << "Takahashi" << std::endl; return;

    #define Aoki std::cout << "Aoki" << std::endl; return;

    '
  code: '#pragma once

    #include "type_alias.hpp"


    #pragma GCC target("avx2")

    #pragma GCC optimize("O3")

    #pragma GCC optimize("unroll-loops")


    #define all(obj) (obj).begin(), (obj).end()


    #define CONCAT_IMPL2(x, y) x##y

    #define CONCAT_IMPL(x, y) CONCAT_IMPL2(x, y)

    #define UNIQUE_ID(base) CONCAT_IMPL(base, __COUNTER__)


    #define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME


    #define rep4(i, a, n, t) for (long long i = static_cast<long long>(a), i##_loop_end
    = static_cast<long long>(n), i##_loop_step = static_cast<long long>(t); i < i##_loop_end;
    i += i##_loop_step)

    #define rep3(i, a, n) for (long long i = static_cast<long long>(a), i##_loop_end
    = static_cast<long long>(n); i < i##_loop_end; ++i)

    #define rep2(i, n) rep3(i, 0, n)

    #define rep1(n) rep2(UNIQUE_ID(loop_counter_), n)

    #define rep(...) GET_MACRO(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)


    #define repd4(i, a, n, t) for (long long i = static_cast<long long>(n) - 1, i##_loop_end
    = static_cast<long long>(a), i##_loop_step = static_cast<long long>(t); i >= i##_loop_end;
    i -= i##_loop_step)

    #define repd3(i, a, n) for (long long i = static_cast<long long>(n) - 1, i##_loop_end
    = static_cast<long long>(a); i >= i##_loop_end; --i)

    #define repd2(i, n) repd3(i, 0, n)

    #define repd(...) GET_MACRO(__VA_ARGS__, repd4, repd3, repd2)(__VA_ARGS__)


    #define rrep(i, n) rep(i, 1, (n) + 1)

    #define rrepd(i, n) repd(i, 1, (n) + 1)


    inline void scan(){}

    template<class Head,class... Tail>

    inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}

    #define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)

    #define STR(...) str __VA_ARGS__;scan(__VA_ARGS__)

    #define IN(a, x) a x; std::cin >> x;

    #define CHAR(x) char x; std::cin >> x;

    #define VL(a,n) vl a(n); std::cin >> a;

    #define AL(a,k) al<k> a; std::cin >> a;

    #define AAL(a,n,m) aal<n,m> a; std::cin >> a;

    #define VC(a,n) vc a(n); std::cin >> a;

    #define VS(a,n) vs a(n); std::cin >> a;

    #define VPL(a,n) vpl a(n); std::cin >> a;

    #define VAL(a,n,k) val<k> a(n); std::cin >> a;

    #define VVL(a,n,m) vvl a(n,vl(m)); std::cin >> a;

    #define SL(a,n) sl a;{VL(b,n);a=sl(all(b));}


    #define NO std::cout << "NO" << std::endl; return;

    #define YES std::cout << "YES" << std::endl; return;

    #define No std::cout << "No" << std::endl; return;

    #define Yes std::cout << "Yes" << std::endl; return;

    #define Takahashi std::cout << "Takahashi" << std::endl; return;

    #define Aoki std::cout << "Aoki" << std::endl; return;

    '
  dependsOn:
  - base/type_alias.hpp
  isVerificationFile: false
  path: base/macro.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/macro.hpp
layout: document
redirect_from:
- /library/base/macro.hpp
- /library/base/macro.hpp.html
title: base/macro.hpp
---
