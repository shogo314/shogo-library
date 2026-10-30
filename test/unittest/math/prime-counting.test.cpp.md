---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
      \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)"
  - icon: ':heavy_check_mark:'
    path: src/math/prime-counting.hpp
    title: "\u7D20\u6570\u306E\u500B\u6570\u30FB\u7D20\u6570\u306E\u548C (Lucy DP)\u30FB\
      \u4E57\u6CD5\u7684\u95A2\u6570\u306E\u548C"
  - icon: ':heavy_check_mark:'
    path: src/math/prime.hpp
    title: "\u7D20\u6570 (\u7D20\u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\u89E3\
      \u3001\u7D04\u6570\u5217\u6319\u3001\u7BE9\u3001\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: src/math/quotients.hpp
    title: "\u5546\u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: src/math/sqrt.hpp
    title: "\u6574\u6570\u306E\u5E73\u65B9\u6839\u30FBk \u4E57\u6839"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/math/prime-counting.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ prime_count\u30FBprime_count_table\u30FBPrimeSumTable \u3092\u3001\u7BE9\u3067\
    \u6570\u3048\u305F\u5024\u3068\u6BD4\u3079\u308B\n// multiplicative_sum \u3092\
    \u3001\u7BE9\u3067\u6C42\u3081\u305F\u4E57\u6CD5\u7684\u95A2\u6570 (\u03C6\u30FB\
    \u03BC\u30FB\u03C3) \u306E\u548C\u3068\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/math/prime-counting.hpp\"\
    \n\n/**\n * @file prime-counting.hpp\n * @brief \u7D20\u6570\u306E\u500B\u6570\
    \u30FB\u7D20\u6570\u306E\u548C (Lucy DP)\n */\n\n#include <cassert>\n#include\
    \ <type_traits>\n#include <vector>\n\n#line 2 \"src/math/sqrt.hpp\"\n\n/**\n *\
    \ @file sqrt.hpp\n * @brief \u6574\u6570\u306E\u5E73\u65B9\u6839\u30FBk \u4E57\
    \u6839\n */\n\n#line 9 \"src/math/sqrt.hpp\"\n#include <cmath>\n\n/**\n * @brief\
    \ floor(sqrt(n))\n * @param n \u5E73\u65B9\u6839\u3092\u6C42\u3081\u305F\u3044\
    \u6574\u6570 long long \u578B\u3067 0 <= n < 2^63 \u3092\u6E80\u305F\u3059\n *\
    \ @return long long\n */\ninline long long sqrtll(long long n) {\n    assert(n\
    \ >= 0);\n    // 3037000500 = ceil(sqrt(2^63))\n    long long le = 0, ri = 3037000500;\n\
    \    while (ri - le > 1) {\n        long long mid = (le + ri) / 2;\n        if\
    \ (mid * mid <= n)\n            le = mid;\n        else\n            ri = mid;\n\
    \    }\n    return le;\n}\n\n/**\n * @brief floor(a^(1/k))\n *\n * \u6D6E\u52D5\
    \u5C0F\u6570\u70B9\u3067\u8FD1\u3044\u5024\u3092\u6C42\u3081\u3001\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\u639B\u3051\
    \u7B97\u3067\u78BA\u304B\u3081\u3066\u5408\u308F\u305B\u308B\n * @param a 0 <=\
    \ a < 2^64\n * @param k 1 \u4EE5\u4E0A\n * @return unsigned long long\n */\ninline\
    \ unsigned long long kth_root(unsigned long long a, long long k) {\n    assert(k\
    \ >= 1);\n    if (k == 1 || a <= 1) return a;\n    if (k >= 64) return 1;  //\
    \ a < 2^64 \u306A\u306E\u3067\n    // x^k <= a \u304B\n    auto fits = [&](unsigned\
    \ long long x) {\n        unsigned long long p = 1;\n        for (long long i\
    \ = 0; i < k; i++) {\n            if (p > a / x) return false;\n            p\
    \ *= x;\n        }\n        return true;\n    };\n    unsigned long long x = static_cast<unsigned\
    \ long long>(std::pow(static_cast<long double>(a), 1.0L / k));\n    if (x == 0)\
    \ x = 1;\n    while (!fits(x)) x--;\n    while (fits(x + 1)) x++;\n    return\
    \ x;\n}\n#line 13 \"src/math/prime-counting.hpp\"\n\n/**\n * @brief \u3059\u3079\
    \u3066\u306E v = floor(n / k) \u306B\u3064\u3044\u3066\u3001v \u4EE5\u4E0B\u306E\
    \u7D20\u6570 p \u306E g(p) \u306E\u548C\u3092\u6C42\u3081\u305F\u8868 (Lucy DP)\n\
    \ *\n * g \u306F\u5B8C\u5168\u4E57\u6CD5\u7684 (g(ab) = g(a) g(b)) \u3067\u3042\
    \u308B\u3053\u3068\u3002prefix(v) \u306F g(2) + g(3) + ... + g(v) (2 \u4EE5\u4E0A\
    \ v \u4EE5\u4E0B\u306E\u6574\u6570\u3059\u3079\u3066\u306E\u548C)\n * \u4F8B:\
    \ \u7D20\u6570\u306E\u500B\u6570\u306A\u3089 g(p) = 1\u3001prefix(v) = v - 1\u3002\
    \u7D20\u6570\u306E\u548C\u306A\u3089 g(p) = p\u3001prefix(v) = v (v + 1) / 2 -\
    \ 1\n * O(n^(3/4) / log n)\u3001\u30E1\u30E2\u30EA O(sqrt(n))\n * \u4F8B:\n *\
    \ PrimeSumTable<__int128> t(n, [](long long v) { return (__int128)v * (v + 1)\
    \ / 2 - 1; }, [](long long p) { return (__int128)p; });\n * t(n);      // n \u4EE5\
    \u4E0B\u306E\u7D20\u6570\u306E\u548C\n * t(n / 3);  // floor(n / 3) \u4EE5\u4E0B\
    \u306E\u7D20\u6570\u306E\u548C\n *\n * @tparam T \u548C\u306E\u578B (long long\u3001\
    __int128\u3001modint \u306A\u3069)\n */\ntemplate <typename T>\nclass PrimeSumTable\
    \ {\n    long long n, sq;\n    std::vector<long long> vals;  // floor(n / k) \u306E\
    \u3068\u308B\u5024\u306E\u6607\u9806 (1, 2, ..., sq \u3068\u3001sq \u3088\u308A\
    \u5927\u304D\u3044 n / k)\n    std::vector<T> sum;           // sum[i] \u306F\
    \ vals[i] \u4EE5\u4E0B\u306E\u7D20\u6570 p \u306E g(p) \u306E\u548C\n\n    long\
    \ long index(long long v) const { return v <= sq ? v - 1 : static_cast<long long>(vals.size())\
    \ - n / v; }\n\n   public:\n    /**\n     * @brief \u8868\u3092\u4F5C\u308B\n\
    \     * @pre n >= 1\n     */\n    template <typename Prefix, typename G>\n   \
    \ PrimeSumTable(long long n, Prefix prefix, G g) : n(n), sq(sqrtll(n)) {\n   \
    \     assert(n >= 1);\n        for (long long v = 1; v <= sq; v++) vals.push_back(v);\n\
    \        for (long long k = n / (sq + 1); k >= 1; k--) vals.push_back(n / k);\n\
    \        sum.resize(vals.size());\n        // \u306F\u3058\u3081\u306F 2 \u4EE5\
    \u4E0A v \u4EE5\u4E0B\u306E\u6574\u6570\u3059\u3079\u3066\u306E\u548C\u3002\u5C0F\
    \u3055\u3044\u7D20\u6570 p \u304B\u3089\u9806\u306B\u3001\u6700\u5C0F\u7D20\u56E0\
    \u6570\u304C p \u306E\u5408\u6210\u6570\u306E\u5206\u3092\u5F15\u304F\n      \
    \  for (size_t i = 0; i < vals.size(); i++) sum[i] = prefix(vals[i]);\n      \
    \  std::vector<bool> composite(sq + 1, false);\n        for (long long p = 2;\
    \ p <= sq; p++) {\n            if (composite[p]) continue;\n            for (long\
    \ long q = p * p; q <= sq; q += p) composite[q] = true;\n            const T gp\
    \ = g(p), below = sum[p - 2];  // below \u306F p - 1 \u4EE5\u4E0B\u306E\u7D20\u6570\
    \u306E\u548C\n            const long long p2 = p * p;\n            // v >= p^2\
    \ \u306E\u5024\u3092\u3001\u5927\u304D\u3044\u65B9\u304B\u3089 (floor(v / p) \u304C\
    \u307E\u3060\u66F4\u65B0\u3055\u308C\u3066\u3044\u306A\u3044\u3046\u3061\u306B\
    ) \u66F4\u65B0\u3059\u308B\n            for (long long i = static_cast<long long>(vals.size())\
    \ - 1; i >= 0 && vals[i] >= p2; i--) {\n                sum[i] -= gp * (sum[index(vals[i]\
    \ / p)] - below);\n            }\n        }\n    }\n\n    /**\n     * @brief v\
    \ \u4EE5\u4E0B\u306E\u7D20\u6570 p \u306E g(p) \u306E\u548C O(1)\n     * @pre\
    \ v = floor(n / k) \u3068\u306A\u308B k >= 1 \u304C\u3042\u308B\u3053\u3068 (v\
    \ = 0 \u3082\u53EF)\n     */\n    T operator()(long long v) const {\n        assert(0\
    \ <= v && v <= n);\n        if (v == 0) return T(0);\n        long long i = index(v);\n\
    \        assert(vals[i] == v && \"PrimeSumTable: v \u306F floor(n / k) \u306E\u5F62\
    \u3067\u3042\u308B\u3053\u3068\");\n        return sum[i];\n    }\n    /**\n \
    \    * @brief floor(n / k) \u306E\u3068\u308B\u5024\u306E\u6607\u9806\n     */\n\
    \    const std::vector<long long>& values() const { return vals; }\n};\n\n/**\n\
    \ * @brief \u3059\u3079\u3066\u306E v = floor(n / k) \u306B\u3064\u3044\u3066\u3001\
    v \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u305F\u8868\
    \ O(n^(3/4) / log n)\n * \u4F8B: auto t = prime_count_table(n); t(n / 2);\n */\n\
    inline PrimeSumTable<long long> prime_count_table(long long n) {\n    return PrimeSumTable<long\
    \ long>(n, [](long long v) { return v - 1; }, [](long long) { return 1LL; });\n\
    }\n\n/**\n * @brief n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u500B\u6570 \u03C0\
    (n) O(n^(3/4) / log n)\n */\ninline long long prime_count(long long n) {\n   \
    \ assert(n >= 0);\n    if (n < 2) return 0;\n    return prime_count_table(n)(n);\n\
    }\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570 f \u306E\u548C f(1) + f(2)\
    \ + ... + f(n) (min_25 \u7BE9\u306E\u5F8C\u534A) O(n^(3/4) / log n) \u7A0B\u5EA6\
    \n *\n * prime_sum(v) \u306F v \u4EE5\u4E0B\u306E\u7D20\u6570 p \u306E f(p) \u306E\
    \u548C\u3002floor(n / k) \u306E\u3068\u308B\u5024 v \u3054\u3068\u306B 1 \u56DE\
    \u305A\u3064\u547C\u3093\u3067\u8868\u306B\u3059\u308B\u3002PrimeSumTable \u3092\
    \u7D44\u307F\u5408\u308F\u305B\u3066\u4F5C\u308B\n * f_pe(p, e) \u306F f(p^e)\
    \ (p \u306F sqrt(n) \u4EE5\u4E0B\u306E\u7D20\u6570\u3001e >= 1)\u3002f(1) = 1\
    \ \u3068\u3059\u308B\n * \u4F8B: \u30AA\u30A4\u30E9\u30FC\u306E \u03C6 \u306A\u3089\
    \ \u03C6(p) = p - 1 \u306A\u306E\u3067\u3001\u7D20\u6570\u306E\u548C\u306E\u8868\
    \ s \u3068\u500B\u6570\u306E\u8868 c \u304B\u3089 prime_sum(v) = s(v) - c(v)\u3001\
    f_pe(p, e) = p^e - p^(e-1)\n * @pre n >= 0\n */\ntemplate <typename PrimeSum,\
    \ typename F>\nauto multiplicative_sum(long long n, PrimeSum prime_sum, F f_pe)\
    \ {\n    using T = std::decay_t<decltype(prime_sum(n))>;\n    assert(n >= 0);\n\
    \    if (n == 0) return T(0);\n    const long long sq = sqrtll(n);\n    std::vector<long\
    \ long> primes;\n    std::vector<bool> composite(sq + 1, false);\n    for (long\
    \ long p = 2; p <= sq; p++) {\n        if (composite[p]) continue;\n        primes.push_back(p);\n\
    \        for (long long q = p * p; q <= sq; q += p) composite[q] = true;\n   \
    \ }\n    // below[j]: primes \u306E\u5148\u982D j \u500B\u306E f(p) \u306E\u548C\
    \n    std::vector<T> below(primes.size() + 1, T(0));\n    for (size_t j = 0; j\
    \ < primes.size(); j++) below[j + 1] = below[j] + f_pe(primes[j], 1);\n    //\
    \ prime_sum \u3092 floor(n / k) \u306E\u3068\u308B\u5024\u3054\u3068\u306B 1 \u56DE\
    \u3060\u3051\u547C\u3093\u3067\u8868\u306B\u3059\u308B (v <= sq \u306F v - 1 \u756A\
    \u76EE\u3001\u305D\u308C\u3088\u308A\u5927\u304D\u3044 n / k \u306F sq + k - 1\
    \ \u756A\u76EE)\n    std::vector<T> table(2 * sq + 1);\n    for (long long v =\
    \ 1; v <= sq; v++) table[v - 1] = prime_sum(v);\n    for (long long k = 1; n /\
    \ k > sq; k++) table[sq + k - 1] = prime_sum(n / k);\n    auto at = [&](long long\
    \ x) -> const T& { return x <= sq ? table[x - 1] : table[sq + n / x - 1]; };\n\
    \    // 2 \u4EE5\u4E0A x \u4EE5\u4E0B\u3067\u3001\u6700\u5C0F\u7D20\u56E0\u6570\
    \u304C primes[j] \u4EE5\u4E0A\u306E i \u306E f(i) \u306E\u548C\n    auto rec =\
    \ [&](auto self, long long x, size_t j) -> T {\n        // primes[j] \u4EE5\u4E0A\
    \ (primes \u3092\u4F7F\u3044\u5207\u3063\u305F\u306A\u3089\u3001primes \u306E\u3069\
    \u308C\u3088\u308A\u3082\u5927\u304D\u3044) \u306E\u7D20\u6570\u304C x \u4EE5\u4E0B\
    \u306B\u306A\u3044\n        if (j < primes.size() ? primes[j] > x : !primes.empty()\
    \ && primes.back() >= x) return T(0);\n        // \u7D20\u6570\u306E\u5206\n \
    \       T res = at(x) - below[j];\n        // \u5408\u6210\u6570\u306E\u5206:\
    \ \u6700\u5C0F\u7D20\u56E0\u6570 p \u3067 p^e \u3067\u5272\u308A\u5207\u308C\u3066\
    \ p^(e+1) \u3067\u5272\u308A\u5207\u308C\u306A\u3044\u3082\u306E\u3092\u3001p^e\
    \ \u3068\u6B8B\u308A\u306E\u7A4D\u3068\u3057\u3066\u6570\u3048\u308B\n       \
    \ for (size_t k = j; k < primes.size() && primes[k] * primes[k] <= x; k++) {\n\
    \            const long long p = primes[k];\n            if (p > x / (p * p))\
    \ {\n                // p^3 > x \u306A\u3089 e = 1 \u3060\u3051\u3067\u3001\u6B8B\
    \u308A x / p (< p^2) \u306F p \u3088\u308A\u5927\u304D\u3044\u7D20\u6570\u304B\
    \ 1 \u306A\u306E\u3067\u3001\u518D\u5E30\u305B\u305A\u306B\u6C42\u3081\u308B\n\
    \                res += f_pe(p, 1) * (at(x / p) - below[k + 1]) + f_pe(p, 2);\n\
    \                continue;\n            }\n            long long pe = p;\n   \
    \         for (long long e = 1; pe <= x / p; e++, pe *= p) {\n               \
    \ res += f_pe(p, e) * self(self, x / pe, k + 1) + f_pe(p, e + 1);\n          \
    \  }\n        }\n        return res;\n    };\n    return rec(rec, n, 0) + T(1);\n\
    }\n#line 8 \"test/unittest/math/prime-counting.test.cpp\"\n\n#include <iostream>\n\
    #include <random>\n#line 12 \"test/unittest/math/prime-counting.test.cpp\"\n\n\
    #line 2 \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n * @brief \u56DB\u5247\
    \u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\
    \u30E9\u30B9\n */\n\n#line 9 \"src/math/modint.hpp\"\n#include <cstdint>\n#line\
    \ 11 \"src/math/modint.hpp\"\n#include <limits>\n#line 13 \"src/math/modint.hpp\"\
    \n#include <utility>\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n#include <functional>\n\
    #include <iterator>\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\n\nnamespace\
    \ internal_traits {\nusing std::begin, std::end;\n\ntemplate <class T, class =\
    \ void>\nstruct is_range_impl : std::false_type {};\ntemplate <class T>\nstruct\
    \ is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>>\
    \ : std::true_type {};\n}  // namespace internal_traits\n\ntemplate <class T>\n\
    struct is_range : internal_traits::is_range_impl<T>::type {};\ntemplate <class\
    \ T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\n#define HAS_METHOD(func_name)\
    \                                                              \\\n    namespace\
    \ internal_traits {                                                          \
    \  \\\n    template <class T, class = void>                                  \
    \                     \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                    \\\n    template <class T>          \
    \                                                           \\\n    struct has_##func_name##_impl<T,\
    \ std::void_t<decltype(std::declval<T>().func_name())>> \\\n        : std::true_type\
    \ {};                                                               \\\n    }\
    \                                                                            \
    \          \\\n    template <class T>                                        \
    \                             \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T>::type\
    \ {};          \\\n    template <class T>                                    \
    \                                 \\\n    inline constexpr bool has_##func_name##_v\
    \ = has_##func_name<T>::value;\n\n#define HAS_METHOD_ARG(func_name)          \
    \                                                                    \\\n    namespace\
    \ internal_traits {                                                          \
    \                      \\\n    template <class T, typename U, class = void>  \
    \                                                             \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                                      \
    \  \\\n    template <class T, typename U>                                    \
    \                                         \\\n    struct has_##func_name##_impl<T,\
    \ U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>> \\\
    \n        : std::true_type {};                                               \
    \                                    \\\n    }                               \
    \                                                                           \\\
    \n    template <class T, typename U>                                         \
    \                                    \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \nnamespace internal_traits {\n// \u5C04\u5F71 (proj) \u306E\u65E2\u5B9A\u5024\
    \n#if __cplusplus >= 202002L\nusing identity = std::identity;\n#else\nstruct identity\
    \ {\n    using is_transparent = void;\n    template <class T>\n    constexpr T&&\
    \ operator()(T&& x) const noexcept {\n        return std::forward<T>(x);\n   \
    \ }\n};\n#endif\n}  // namespace internal_traits\n\ntemplate <class C>\nusing\
    \ mem_value_type = typename C::value_type;\ntemplate <class C>\nusing mem_difference_type\
    \ = typename C::difference_type;\n\nnamespace internal_traits {\ntemplate <class\
    \ T, class = void>\nstruct is_sorted_container_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_sorted_container_impl<std::set<T>> : std::true_type {};\n\
    template <class T>\nstruct is_sorted_container_impl<std::multiset<T>> : std::true_type\
    \ {};\n}  // namespace internal_traits\ntemplate <class T>\nstruct is_sorted_container\
    \ : internal_traits::is_sorted_container_impl<T>::type {};\ntemplate <class T>\n\
    inline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 16 \"src/math/modint.hpp\"\n\nnamespace internal_modint {\n// clang-format\
    \ off\nstatic constexpr std::uint16_t prime32_bases[] {\n    15591,  2018,  166,\
    \ 7429,  8064, 16045, 10503,  4399,  1949,  1295, 2776,  3620,   560,  3128, \
    \ 5212,  2657,\n     2300,  2021, 4652, 1471,  9336,  4018,  2398, 20462, 10277,\
    \  8028, 2213,  6219,   620,  3763,  4852,  5012,\n     3185,  1333, 6227, 5298,\
    \  1074,  2391,  5113,  7061,   803,  1269, 3875,   422,   751,   580,  4729,\
    \ 10239,\n      746,  2951,  556, 2206,  3778,   481,  1522,  3476,   481,  2487,\
    \ 3266,  5633,   488,  3373,  6441,  3344,\n       17, 15105, 1490, 4154,  2036,\
    \  1882,  1813,   467,  3307, 14042, 6371,   658,  1005,   903,   737,  1887,\n\
    \     7447,  1888, 2848, 1784,  7559,  3400,   951, 13969,  4304,   177,   41,\
    \ 19875,  3110, 13221,  8726,   571,\n     7043,  6943, 1199,  352,  6435,   165,\
    \  1169,  3315,   978,   233, 3003,  2562,  2994, 10587, 10030,  2377,\n     1902,\
    \  5354, 4447, 1555,   263, 27027,  2283,   305,   669,  1912,  601,  6186,  \
    \ 429,  1930, 14873,  1784,\n     1661,   524, 3577,  236,  2360,  6146,  2850,\
    \ 55637,  1753,  4178, 8466,   222,  2579,  2743,  2031,  2226,\n     2276,  \
    \ 374, 2132,  813, 23788,  1610,  4422,  5159,  1725,  3597, 3366, 14336,   579,\
    \   165,  1375, 10018,\n    12616,  9816, 1371,  536,  1867, 10864,   857,  2206,\
    \  5788,   434, 8085, 17618,   727,  3639,  1595,  4944,\n     2129,  2029, 8195,\
    \ 8344,  6232,  9183,  8126,  1870,  3296,  7455, 8947, 25017,   541, 19115, \
    \  368,   566,\n     5674,   411,  522, 1027,  8215,  2050,  6544, 10049,   614,\
    \   774, 2333,  3007, 35201,  4706,  1152,  1785,\n     1028,  1540, 3743,  493,\
    \  4474,  2521, 26845,  8354,   864, 18915, 5465,  2447,    42,  4511,  1660,\
    \   166,\n     1249,  6259, 2553,  304,   272,  7286,    73,  6554,   899,  2816,\
    \ 5197, 13330,  7054,  2818,  3199,   811,\n      922,   350, 7514, 4452,  3449,\
    \  2663,  4708,   418,  1621,  1171, 3471,    88, 11345,   412,  1559,   194,\n\
    };\n// clang-format on\n\nstatic constexpr bool is_SPRP(std::uint32_t n, std::uint32_t\
    \ a) noexcept {\n    std::uint32_t d = n - 1;\n    std::uint32_t s = 0;\n    while\
    \ ((d & 1) == 0) {\n        ++s;\n        d >>= 1;\n    }\n    std::uint64_t cur\
    \ = 1;\n    std::uint64_t pw = d;\n    while (pw) {\n        if (pw & 1) cur =\
    \ (cur * a) % n;\n        a = (static_cast<std::uint64_t>(a) * a) % n;\n     \
    \   pw >>= 1;\n    }\n    if (cur == 1) return true;\n    for (std::uint32_t r\
    \ = 0; r < s; ++r) {\n        if (cur == n - 1) return true;\n        cur = (cur\
    \ * cur) % n;\n    }\n    return false;\n}\n\n// 32\u30D3\u30C3\u30C8\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u306E\u7D20\u6570\u5224\u5B9A\n// \u53C2\u8003: M. Forisek\
    \ and J. Jancina, \u201CFast Primality Testing for Integers That Fit into a Machine\
    \ Word,\u201D presented at the Conference on Current Trends in Theory and Practice\
    \ of Informatics, 2015.\n[[nodiscard]]\nstatic constexpr bool is_prime32(std::uint32_t\
    \ x) noexcept {\n    if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n\
    \    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n\
    \    if (x < 121) return (x > 1);\n    std::uint64_t h = x;\n    h = ((h >> 16)\
    \ ^ h) * 0x45d9f3b;\n    h = ((h >> 16) ^ h) * 0x45d9f3b;\n    h = ((h >> 16)\
    \ ^ h) & 0xff;\n    return is_SPRP(x, prime32_bases[h]);\n}\n}  // namespace internal_modint\n\
    \n/// @brief static_modint \u3068 dynamic_modint \u306E\u5B9F\u88C5\u3092 CRTP\
    \ \u306B\u3088\u3063\u3066\u884C\u3046\u305F\u3081\u306E\u30AF\u30E9\u30B9\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n/// @tparam Modint \u3053\u306E\u30AF\u30E9\u30B9\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u7D99\u627F\u3059\u308B\u30AF\u30E9\
    \u30B9\ntemplate <class Modint>\nclass modint_base {\n   public:\n    /// @brief\
    \ \u4FDD\u6301\u3059\u308B\u5024\u306E\u578B\n    using value_type = std::uint32_t;\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ modint_base() noexcept\n        : m_value{0} {}\n\n    /// @brief @c value \u306E\
    \u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value\
    \ \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral,\
    \ ENABLE_IF_T((std::is_integral_v<SignedIntegral> && std::is_signed_v<SignedIntegral>))>\n\
    \    constexpr modint_base(SignedIntegral value) noexcept\n        : m_value{static_cast<value_type>((static_cast<long\
    \ long>(value) % Modint::mod() + Modint::mod()) % Modint::mod())} {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class UnsignedIntegral, ENABLE_IF_T((std::is_integral_v<UnsignedIntegral> &&\
    \ std::is_unsigned_v<UnsignedIntegral>))>\n    constexpr modint_base(UnsignedIntegral\
    \ value) noexcept\n        : m_value{static_cast<value_type>(value % Modint::mod())}\
    \ {}\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u53D6\u5F97\
    \u3057\u307E\u3059\u3002\n    /// @return \u4FDD\u6301\u3057\u3066\u3044\u308B\
    \u5024\n    [[nodiscard]]\n    constexpr value_type val() const noexcept {\n \
    \       return m_value;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\
    \u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\u3001\
    \u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n \
    \   constexpr Modint& operator++() noexcept {\n        ++m_value;\n        if\
    \ (m_value == Modint::mod()) {\n            m_value = 0;\n        }\n        return\
    \ static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30A4\
    \u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr\
    \ Modint operator++(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        ++*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n\
    \    constexpr Modint& operator--() noexcept {\n        if (m_value == 0) {\n\
    \            m_value = Modint::mod();\n        }\n        --m_value;\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30C7\
    \u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr Modint\
    \ operator--(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        --*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u8DB3\u3057\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3059\u6570\n    /// @return @c *this\n    constexpr Modint& operator+=(const\
    \ Modint& x) noexcept {\n        m_value += x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value -= Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u304B\u3089 @c x \u306E\u6301\u3064\u5024\u3092\u5F15\
    \u3044\u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304F\u6570\n    /// @return @c *this\n    constexpr Modint& operator-=(const\
    \ Modint& x) noexcept {\n        m_value -= x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value += Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u639B\u3051\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u308B\u6570\n    /// @return @c *this\n    constexpr Modint& operator*=(const\
    \ Modint& x) noexcept {\n        m_value = static_cast<value_type>(static_cast<std::uint64_t>(m_value)\
    \ * x.m_value % Modint::mod());\n        return static_cast<Modint&>(*this);\n\
    \    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092 @c x\
    \ \u306E\u6301\u3064\u5024\u3067\u5272\u3063\u3066\u3001\u5270\u4F59\u3092\u53D6\
    \u308A\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A\
    \ @f$O(\\log x)@f$\n    /// @param x \u5272\u308B\u6570\n    /// @return @c *this\n\
    \    constexpr Modint& operator/=(const Modint& x) noexcept {\n        return\
    \ *this *= x.inv();\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u30B3\u30D4\u30FC\
    \u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @return @c *this\n    [[nodiscard]]\n\
    \    constexpr Modint operator+() const noexcept {\n        return static_cast<const\
    \ Modint&>(*this);\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u53CD\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @return \u81EA\u8EAB\u306E\u53CD\u6570\
    \n    [[nodiscard]]\n    constexpr Modint operator-() const noexcept {\n     \
    \   return 0 - static_cast<const Modint&>(*this);\n    }\n\n    /// @brief \u81EA\
    \u8EAB\u306E @c n \u4E57\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @remark\
    \ \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log n)@f$\n    /// @param n \u6307\
    \u6570\n    /// @return \u81EA\u8EAB\u306E @c n \u4E57\n    [[nodiscard]]\n  \
    \  constexpr Modint pow(unsigned long long n) const noexcept {\n        Modint\
    \ x = 1;\n        Modint y = static_cast<const Modint&>(*this);\n        while\
    \ (n) {\n            if (n & 1) {\n                x *= y;\n            }\n  \
    \          y *= y;\n            n >>= 1;\n        }\n        return x;\n    }\n\
    \n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\u3002\
    \n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ Modint inv() const noexcept {\n        long long a = Modint::mod();\n      \
    \  long long b = m_value;\n        long long x = 0;\n        long long y = 1;\n\
    \        while (b) {\n            auto t = a / b;\n            auto u = a - t\
    \ * b;\n            a = b;\n            b = u;\n            u = x - t * y;\n \
    \           x = y;\n            y = u;\n        }\n        assert(a == 1 && \"\
    The inverse element does not exist.\");\n        x %= Modint::mod();\n       \
    \ if (x < 0) {\n            x += Modint::mod();\n        }\n        return x;\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3055\u308C\u308B\u6570\n    /// @param y \u8DB3\u3059\u6570\n    ///\
    \ @return @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator+(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} += y);\n\
    \    }\n\n    /// @brief @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304B\u308C\u308B\u6570\n    /// @param y \u5F15\u304F\u6570\n    ///\
    \ @return @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator-(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} -= y);\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u3089\u308C\u308B\u6570\n    /// @param y \u639B\u3051\u308B\u6570\
    \n    /// @return @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator*(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} *= y);\n\
    \    }\n\n    /// @brief @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u5272\u3089\u308C\u308B\u6570\n    /// @param y \u5272\u308B\u6570\n    ///\
    \ @return @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator/(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} /= y);\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\u307E\u3059\
    \u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\u304C\
    \u7B49\u3057\u3051\u308C\u3070 @c true \u3001\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 @c false\n    [[nodiscard]]\n    friend constexpr bool operator==(const\
    \ Modint& x, const Modint& y) noexcept {\n        return x.m_value == y.m_value;\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u304F\u306A\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\
    \u307E\u3059\u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\
    \u5024\u304C\u7B49\u3057\u3051\u308C\u3070 @c false \u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070 @c true\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Modint& x, const Modint& y) noexcept {\n        return !(x == y);\n    }\n\n\
    \    /// @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\u7B26\u53F7\
    \u4ED8\u304D\u6574\u6570\u3092\u8AAD\u307F\u53D6\u308A\u3001 @c x \u306B\u683C\
    \u7D0D\u3057\u307E\u3059\u3002\n    /// @tparam CharT \u5165\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n    /// @tparam Traits \u5165\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n   \
    \ /// @param is \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n    /// @param x \u5165\
    \u529B\u3092\u53D7\u3051\u53D6\u308B\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n   \
    \ /// @return @c is\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Modint& x) {\n  \
    \      long long tmp;\n        is >> tmp;\n        x = tmp;\n        return is;\n\
    \    }\n\n    /// @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306B @c x\
    \ \u306E\u4FDD\u6301\u3059\u308B\u5024\u3092\u51FA\u529B\u3057\u307E\u3059\u3002\
    \n    /// @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\
    \u5B57\u578B\n    /// @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n    /// @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n    /// @param x \u51FA\u529B\u3059\u308B\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\n    /// @return @c os\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Modint& x) {\n        os << x.val();\n        return os;\n\
    \    }\n\n   protected:\n    value_type m_value;\n};\n\n/// @brief \u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\
    \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\
    \u308B\u30AF\u30E9\u30B9\n/// @tparam Mod \u6CD5\ntemplate <std::uint32_t Mod>\n\
    class static_modint : public modint_base<static_modint<Mod>> {\n    static_assert(Mod\
    \ > 0 && Mod <= std::numeric_limits<std::uint32_t>::max() / 2);\n\n   private:\n\
    \    using base_type = modint_base<static_modint<Mod>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static constexpr\
    \ value_type mod() noexcept {\n        return Mod;\n    }\n\n    /// @brief 0\
    \ \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr static_modint()\
    \ noexcept\n        : base_type{} {}\n\n    /// @brief @c value \u306E\u5270\u4F59\
    \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\u671F\
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n\
    \    constexpr static_modint(SignedIntegral value) noexcept\n        : base_type{value}\
    \ {}\n\n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\
    \u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ static_modint inv() const noexcept {\n        if constexpr (internal_modint::is_prime32(Mod))\
    \ {\n            assert(this->m_value != 0 && \"The inverse element of zero does\
    \ not exist.\");\n            return this->pow(Mod - 2);\n        } else {\n \
    \           return base_type::inv();\n        }\n    }\n};\n\n/// @brief \u5B9F\
    \u884C\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\u56DB\u5247\
    \u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\
    \u30E9\u30B9\n/// @tparam ID \u3053\u306EID\u3054\u3068\u306B\u6CD5\u3092\u8A2D\
    \u5B9A\u3059\u308B\u3053\u3068\u304C\u3067\u304D\u307E\u3059\ntemplate <int ID>\n\
    class dynamic_modint : public modint_base<dynamic_modint<ID>> {\n   private:\n\
    \    using base_type = modint_base<dynamic_modint<ID>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static value_type\
    \ mod() noexcept {\n        return modulus;\n    }\n\n    /// @brief \u6CD5\u3092\
    \u8A2D\u5B9A\u3057\u307E\u3059\u3002\n    /// @param m \u65B0\u3057\u3044\u6CD5\
    \n    static void set_mod(value_type m) noexcept {\n        assert(m > 0 && m\
    \ <= std::numeric_limits<value_type>::max() / 2);\n        modulus = m;\n    }\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ dynamic_modint() noexcept\n        : base_type{} {}\n\n    /// @brief @c value\
    \ \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    ///\
    \ @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class\
    \ SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n    constexpr\
    \ dynamic_modint(SignedIntegral value) noexcept\n        : base_type{value} {}\n\
    \n   private:\n    inline static value_type modulus = 998244353;\n};\n\nusing\
    \ modint998244353 = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n#line 2 \"src/math/prime.hpp\"\n\n/**\n *\
    \ @file prime.hpp\n * @brief \u7D20\u6570 (\u7D20\u6570\u5224\u5B9A\u3001\u7D20\
    \u56E0\u6570\u5206\u89E3\u3001\u7D04\u6570\u5217\u6319\u3001\u7BE9\u3001\u539F\
    \u59CB\u6839)\n */\n\n#include <algorithm>\n#line 11 \"src/math/prime.hpp\"\n\
    #include <initializer_list>\n#include <numeric>\n#include <unordered_map>\n#line\
    \ 16 \"src/math/prime.hpp\"\n\n#line 2 \"src/math/modular-arithmetic.hpp\"\n\n\
    /**\n * @file modular-arithmetic.hpp\n * @brief mod \u6F14\u7B97 (\u7A4D\u3001\
    \u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\u6563\u5BFE\u6570\u3001\u5E73\u65B9\
    \u6839)\n */\n\n#line 13 \"src/math/modular-arithmetic.hpp\"\n\n/**\n * @brief\
    \ a * b mod m \u3092\u8FD4\u3059 (\u9014\u4E2D\u3067 __int128 \u3092\u4F7F\u3046\
    \u306E\u3067 m < 2^63 \u306A\u3089\u3042\u3075\u308C\u306A\u3044)\n */\nconstexpr\
    \ long long modmul(long long a, long long b, long long m) {\n    long long res\
    \ = static_cast<long long>(static_cast<__int128>(a) * b % m);\n    if (res < 0)\
    \ res += m;\n    return res;\n}\n\n/**\n * @brief a^(-1) mod m \u3092\u8FD4\u3059\
    \n * @note a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\
    \u3002O(log m)\n */\nconstexpr long long modinv(long long a, long long m) {\n\
    \    assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n    long long b = m,\
    \ u = 1, v = 0;\n    while (b) {\n        // std::swap \u306F C++17 \u3067\u306F\
    \ constexpr \u3067\u306A\u3044\u306E\u3067\u3001\u4F7F\u308F\u305A\u306B\u66F8\
    \u304F\n        long long t = a / b;\n        long long c = a - t * b;\n     \
    \   a = b, b = c;\n        long long w = u - t * v;\n        u = v, v = w;\n \
    \   }\n    assert(a == 1 && \"a and m must be coprime\");\n    u %= m;\n    if\
    \ (u < 0) u += m;\n    return u;\n}\n\n/**\n * @brief a^n mod m \u3092\u8FD4\u3059\
    \n * @note n \u304C\u8CA0\u306A\u3089 a^(-1) \u306E -n \u4E57 (a \u3068 m \u306F\
    \u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068)\u3002O(log |n|)\n */\n\
    constexpr long long modpow(long long a, long long n, long long m) {\n    assert(m\
    \ >= 1);\n    a %= m;\n    if (a < 0) a += m;\n    if (n < 0) {\n        n = -n;\n\
    \        a = modinv(a, m);\n    }\n    long long res = 1 % m;\n    while (n >\
    \ 0) {\n        if (n & 1) res = modmul(res, a, m);\n        a = modmul(a, a,\
    \ m);\n        n >>= 1;\n    }\n    return res;\n}\n\n/**\n * @brief a^x \u2261\
    \ b (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E x >= 0 (\u306A\u3051\u308C\u3070\
    \ -1)\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u306A\u304F\u3066\
    \u3082\u3088\u3044\u3002Baby-step Giant-step \u3067 O(\u221Am) \u306E\u6642\u9593\
    \u3068\u30E1\u30E2\u30EA\n */\ninline long long discrete_log(long long a, long\
    \ long b, long long m) {\n    assert(m >= 1);\n    a %= m, b %= m;\n    if (a\
    \ < 0) a += m;\n    if (b < 0) b += m;\n    if (m == 1) return 0;\n    // a \u3068\
    \ m \u304C\u4E92\u3044\u306B\u7D20\u306B\u306A\u308B\u307E\u3067\u4E21\u8FBA\u3092\
    \ gcd \u3067\u5272\u308B\u3002k = a^add / (\u5272\u3063\u305F gcd \u306E\u7A4D\
    ) mod m\n    long long k = 1, add = 0, g;\n    while ((g = std::gcd(a, m)) > 1)\
    \ {\n        if (b == k) return add;\n        if (b % g != 0) return -1;\n   \
    \     b /= g, m /= g, add++;\n        k = modmul(k, a / g, m);\n    }\n    //\
    \ k a^x \u2261 b \u3092 x = n p - q (1 <= p <= n\u30010 <= q <= n) \u3068\u66F8\
    \u3044\u3066\u89E3\u304F\n    const long long n = static_cast<long long>(std::sqrt(static_cast<long\
    \ double>(m))) + 1;\n    std::unordered_map<long long, long long> baby;\n    baby.reserve(2\
    \ * n + 2);\n    // b a^q \u3092 q \u306E\u5C0F\u3055\u3044\u9806\u306B\u5165\u308C\
    \u3001\u540C\u3058\u5024\u306A\u3089\u5927\u304D\u3044 q \u3067\u4E0A\u66F8\u304D\
    \u3059\u308B (x \u3092\u5C0F\u3055\u304F\u3059\u308B\u305F\u3081)\n    for (long\
    \ long q = 0, cur = b; q <= n; q++, cur = modmul(cur, a, m)) baby[cur] = q;\n\
    \    const long long an = modpow(a, n, m);\n    for (long long p = 1, cur = k;\
    \ p <= n; p++) {\n        cur = modmul(cur, an, m);\n        auto it = baby.find(cur);\n\
    \        if (it != baby.end()) return n * p - it->second + add;\n    }\n    return\
    \ -1;\n}\n\n/**\n * @brief \u7D20\u6570 p \u306B\u3064\u3044\u3066 x^2 \u2261\
    \ a (mod p) \u3068\u306A\u308B x \u306E\u3046\u3061\u5C0F\u3055\u3044\u65B9 (\u306A\
    \u3051\u308C\u3070 -1)\n * @note \u3082\u3046\u4E00\u65B9\u306E\u89E3\u306F p\
    \ - x\u3002Tonelli-Shanks \u3067 O(log^2 p)\n */\ninline long long sqrt_mod(long\
    \ long a, long long p) {\n    assert(p >= 2);\n    a %= p;\n    if (a < 0) a +=\
    \ p;\n    if (a == 0 || p == 2) return a;\n    // \u30AA\u30A4\u30E9\u30FC\u306E\
    \u898F\u6E96: a^((p-1)/2) \u304C 1 \u3067\u306A\u3051\u308C\u3070\u5E73\u65B9\u975E\
    \u5270\u4F59\n    if (modpow(a, (p - 1) / 2, p) != 1) return -1;\n    long long\
    \ q = p - 1, s = 0;\n    while (q % 2 == 0) q /= 2, s++;\n    // \u5E73\u65B9\u975E\
    \u5270\u4F59 z \u3092\u63A2\u3059\n    long long z = 2;\n    while (modpow(z,\
    \ (p - 1) / 2, p) != p - 1) z++;\n    long long c = modpow(z, q, p), t = modpow(a,\
    \ q, p), r = modpow(a, (q + 1) / 2, p);\n    // r^2 = a t \u3092\u4FDD\u3061\u306A\
    \u304C\u3089\u3001t \u306E\u4F4D\u6570\u3092\u4E0B\u3052\u3066\u3044\u304F\n \
    \   while (t != 1) {\n        long long i = 0, tt = t;\n        while (tt != 1)\
    \ tt = modmul(tt, tt, p), i++;\n        long long b = c;\n        for (long long\
    \ j = 0; j < s - i - 1; j++) b = modmul(b, b, p);\n        s = i;\n        c =\
    \ modmul(b, b, p);\n        t = modmul(t, c, p);\n        r = modmul(r, b, p);\n\
    \    }\n    return std::min(r, p - r);\n}\n#line 18 \"src/math/prime.hpp\"\n\n\
    namespace internal_prime {\n\nusing u64 = unsigned long long;\n\n/**\n * @brief\
    \ Pollard \u306E \u03C1 \u6CD5 (Brent \u306E\u6539\u826F) \u3067\u5408\u6210\u6570\
    \ n \u306E 1 \u3067\u3082 n \u3067\u3082\u306A\u3044\u7D04\u6570\u3092 1 \u3064\
    \u898B\u3064\u3051\u308B\n */\ninline u64 find_factor(u64 n) {\n    if (n % 2\
    \ == 0) return 2;\n    constexpr u64 m = 128;\n    for (u64 c = 1;; c++) {\n \
    \       auto f = [&](u64 x) { return (modmul(x, x, n) + c) % n; };\n        auto\
    \ diff = [](u64 x, u64 y) { return x > y ? x - y : y - x; };\n        u64 x =\
    \ 0, y = 2, ys = 2, q = 1, g = 1;\n        for (u64 r = 1; g == 1; r <<= 1) {\n\
    \            x = y;\n            for (u64 i = 0; i < r; i++) y = f(y);\n     \
    \       for (u64 k = 0; k < r && g == 1; k += m) {\n                ys = y;\n\
    \                for (u64 i = 0; i < m && i < r - k; i++) {\n                \
    \    y = f(y);\n                    q = modmul(q, diff(x, y), n);\n          \
    \      }\n                g = std::gcd(q, n);\n            }\n        }\n    \
    \    if (g == n) {\n            // \u307E\u3068\u3081\u3066\u639B\u3051\u305F\u305B\
    \u3044\u3067 n \u306B\u306A\u3063\u305F\u306E\u3067\u30011 \u3064\u305A\u3064\u623B\
    \u3063\u3066\u78BA\u304B\u3081\u308B\n            do {\n                ys = f(ys);\n\
    \                g = std::gcd(diff(x, ys), n);\n            } while (g == 1);\n\
    \        }\n        if (g != n) return g;\n    }\n}\n\n}  // namespace internal_prime\n\
    \n/**\n * @brief n \u304C\u7D20\u6570\u304B (Miller-Rabin\u300164 bit \u3067\u6C7A\
    \u5B9A\u7684) O(log n)\n */\nconstexpr bool is_prime(long long n) {\n    using\
    \ namespace internal_prime;\n    if (n < 2) return false;\n    for (u64 p : {2,\
    \ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n        if (static_cast<u64>(n)\
    \ % p == 0) return static_cast<u64>(n) == p;\n    }\n    const u64 m = n;\n  \
    \  u64 d = m - 1;\n    int s = 0;\n    while (d % 2 == 0) d /= 2, s++;\n    for\
    \ (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL})\
    \ {\n        a %= m;\n        if (a == 0) continue;\n        u64 x = modpow(a,\
    \ d, m);\n        if (x == 1 || x == m - 1) continue;\n        bool composite\
    \ = true;\n        for (int i = 1; i < s; i++) {\n            x = modmul(x, x,\
    \ m);\n            if (x == m - 1) {\n                composite = false;\n   \
    \             break;\n            }\n        }\n        if (composite) return\
    \ false;\n    }\n    return true;\n}\n\n/**\n * @brief n (>= 1) \u3092\u7D20\u56E0\
    \u6570\u5206\u89E3\u3057\u3001(\u7D20\u56E0\u6570, \u6307\u6570) \u3092\u7D20\u56E0\
    \u6570\u306E\u6607\u9806\u306B\u4E26\u3079\u3066\u8FD4\u3059\n * Pollard \u306E\
    \ \u03C1 \u6CD5\u3092\u4F7F\u3046\u3002\u671F\u5F85 O(n^(1/4)) \u7A0B\u5EA6\n\
    \ */\ninline std::vector<std::pair<long long, long long>> factorize(long long\
    \ n) {\n    assert(n >= 1);\n    std::vector<long long> ps;\n    // \u5C0F\u3055\
    \u3044\u7D20\u56E0\u6570\u306F\u5272\u308A\u7B97\u3067\u53D6\u308A\u9664\u304F\
    \n    for (long long p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n   \
    \     while (n % p == 0) {\n            ps.push_back(p);\n            n /= p;\n\
    \        }\n    }\n    std::vector<long long> st;\n    if (n > 1) st.push_back(n);\n\
    \    while (!st.empty()) {\n        long long x = st.back();\n        st.pop_back();\n\
    \        if (is_prime(x)) {\n            ps.push_back(x);\n            continue;\n\
    \        }\n        long long d = internal_prime::find_factor(x);\n        st.push_back(d);\n\
    \        st.push_back(x / d);\n    }\n    std::sort(ps.begin(), ps.end());\n \
    \   std::vector<std::pair<long long, long long>> res;\n    for (long long p :\
    \ ps) {\n        if (!res.empty() && res.back().first == p)\n            res.back().second++;\n\
    \        else\n            res.emplace_back(p, 1);\n    }\n    return res;\n}\n\
    \n/**\n * @brief n (>= 1) \u306E\u6B63\u306E\u7D04\u6570\u3092\u6607\u9806\u306B\
    \u4E26\u3079\u3066\u8FD4\u3059\n */\ninline std::vector<long long> divisors(long\
    \ long n) {\n    std::vector<long long> res = {1};\n    for (auto [p, e] : factorize(n))\
    \ {\n        const long long sz = res.size();\n        long long pw = 1;\n   \
    \     for (long long i = 0; i < e; i++) {\n            pw *= p;\n            for\
    \ (long long j = 0; j < sz; j++) res.push_back(res[j] * pw);\n        }\n    }\n\
    \    std::sort(res.begin(), res.end());\n    return res;\n}\n\n/**\n * @brief\
    \ \u30AA\u30A4\u30E9\u30FC\u306E \u03C6 \u95A2\u6570 (1 \u4EE5\u4E0A n \u4EE5\u4E0B\
    \u3067 n \u3068\u4E92\u3044\u306B\u7D20\u306A\u6574\u6570\u306E\u500B\u6570)\n\
    \ */\ninline long long totient(long long n) {\n    long long res = n;\n    for\
    \ (auto [p, e] : factorize(n)) res = res / p * (p - 1);\n    return res;\n}\n\n\
    /**\n * @brief m (>= 1) \u3092\u6CD5\u3068\u3059\u308B\u6700\u5C0F\u306E\u539F\
    \u59CB\u6839 (\u306A\u3051\u308C\u3070 -1)\n * \u539F\u59CB\u6839\u304C\u3042\u308B\
    \u306E\u306F m = 1, 2, 4, p^k, 2p^k (p \u306F\u5947\u7D20\u6570) \u306E\u3068\u304D\
    \u3002m = 1 \u306A\u3089 0 \u3092\u8FD4\u3059\n * \u7D20\u56E0\u6570\u5206\u89E3\
    \u3092\u4F7F\u3046\u306E\u3067\u3001m \u304C 10^18 \u7A0B\u5EA6\u3067\u3082\u901F\
    \u3044\n */\ninline long long primitive_root(long long m) {\n    assert(m >= 1);\n\
    \    if (m == 1) return 0;\n    if (m == 2) return 1;\n    if (m == 4) return\
    \ 3;\n    auto fm = factorize(m);\n    // m = p^k \u304B 2 p^k (p \u306F\u5947\
    \u7D20\u6570) \u304B\n    if (fm.size() > 2 || (fm.size() == 2 && !(fm[0].first\
    \ == 2 && fm[0].second == 1)) || (fm.size() == 1 && fm[0].first == 2)) return\
    \ -1;\n    long long phi = m;\n    for (auto [p, e] : fm) phi = phi / p * (p -\
    \ 1);\n    auto fphi = factorize(phi);\n    // g \u306E\u4F4D\u6570\u304C \u03C6\
    (m) \u3067\u3042\u308B\u3053\u3068: \u03C6(m) \u306E\u3069\u306E\u7D20\u56E0\u6570\
    \ q \u306B\u3064\u3044\u3066\u3082 g^(\u03C6(m)/q) \u304C 1 \u3067\u306A\u3044\
    \n    for (long long g = 2;; g++) {\n        if (std::gcd(g, m) != 1) continue;\n\
    \        bool ok = true;\n        for (auto [q, e] : fphi) {\n            if (modpow(g,\
    \ phi / q, m) == 1) {\n                ok = false;\n                break;\n \
    \           }\n        }\n        if (ok) return g;\n    }\n}\n\n/**\n * @brief\
    \ \u7D20\u6570 p \u306B\u3064\u3044\u3066 x^k \u2261 a (mod p) \u3068\u306A\u308B\
    \ x \u3092 1 \u3064\u8FD4\u3059 (\u306A\u3051\u308C\u3070 -1)\u30020^0 = 1 \u3068\
    \u3059\u308B\n *\n * g = gcd(k, p - 1) \u3068\u3057\u3066 g \u4E57\u6839 z \u3092\
    \u6C42\u3081\u3001x = z^(k/g \u306E\u9006\u6570 mod (p-1)/g) \u3068\u3059\u308B\
    \n * g \u4E57\u6839\u306F\u3001g \u306E\u7D20\u56E0\u6570 q \u3054\u3068\u306B\
    \u3001\u4F4D\u6570 q^s \u306E\u90E8\u5206\u7FA4\u306E\u4E2D\u3067 Pohlig-Hellman\
    \ \u6CD5 (q \u306E\u90E8\u5206\u306F baby-step giant-step) \u3092\u4F7F\u3063\u3066\
    \u76F4\u3059\n * O(\u03A3_q (s sqrt(q) + log^2 p)) \u306B p - 1 \u306E\u7D20\u56E0\
    \u6570\u5206\u89E3\u3092\u8DB3\u3057\u305F\u3082\u306E\n */\ninline long long\
    \ kth_root_mod(long long k, long long a, long long p) {\n    assert(k >= 0 &&\
    \ p >= 2);\n    a %= p;\n    if (a < 0) a += p;\n    if (k == 0) return a == 1\
    \ % p ? 1 : -1;\n    if (a == 0) return 0;\n    const long long m = p - 1, g =\
    \ std::gcd(k, m);\n    if (modpow(a, m / g, p) != 1) return -1;\n    long long\
    \ z = a;  // \u7D20\u56E0\u6570\u3092 1 \u3064\u305A\u3064\u51E6\u7406\u3057\u3001\
    \u6700\u5F8C\u306B z^g = a \u3068\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \    for (auto [q, e] : factorize(g)) {\n        long long s = 0, t = m, qe =\
    \ 1;\n        while (t % q == 0) t /= q, s++;\n        for (long long i = 0; i\
    \ < e; i++) qe *= q;\n        // x1 = z^r (r q^e \u2261 1 mod t) \u3068\u3059\u308B\
    \u3068 x1^(q^e) = z h (h \u306F\u4F4D\u6570 q^s \u306E\u90E8\u5206\u7FA4 H \u306E\
    \u5143)\n        const long long r = t == 1 ? 0 : modinv(qe % t, t);\n       \
    \ const long long x1 = modpow(z, r, p);\n        const long long target = modmul(z,\
    \ modinv(modpow(x1, qe, p), p), p);  // h^(-1)\u3001H \u306E\u5143\u3067 q^e \u4E57\
    \u306B\u306A\u3063\u3066\u3044\u308B\n        // H \u306E\u751F\u6210\u5143 c\
    \ = w^t (w \u306F q \u4E57\u975E\u5270\u4F59)\n        long long w = 2;\n    \
    \    while (modpow(w, m / q, p) == 1) w++;\n        const long long c = modpow(w,\
    \ t, p);\n        // target = c^d \u3068\u306A\u308B d \u3092 q \u9032\u3067 1\
    \ \u6841\u305A\u3064\u6C42\u3081\u308B (Pohlig-Hellman)\n        long long zeta\
    \ = c;  // \u4F4D\u6570 q \u306E\u5143 c^(q^(s-1))\n        for (long long i =\
    \ 0; i + 1 < s; i++) zeta = modpow(zeta, q, p);\n        const long long B = std::sqrt(static_cast<double>(q))\
    \ + 1;\n        std::unordered_map<long long, long long> baby;  // zeta^j -> j\
    \ (j < B)\n        for (long long j = 0, x = 1; j < B; j++, x = modmul(x, zeta,\
    \ p)) baby.emplace(x, j);\n        const long long giant = modinv(modpow(zeta,\
    \ B, p), p);\n        auto log_zeta = [&](long long y) {\n            for (long\
    \ long i = 0; i <= q / B + 1; i++, y = modmul(y, giant, p)) {\n              \
    \  auto it = baby.find(y);\n                if (it != baby.end()) return i * B\
    \ + it->second;\n            }\n            assert(false);\n            return\
    \ -1LL;\n        };\n        long long d = 0, qi = 1;\n        const long long\
    \ cinv = modinv(c, p);\n        for (long long i = 0; i < s; i++, qi *= q) {\n\
    \            // (target c^(-d))^(q^(s-1-i)) = zeta^(d \u306E i \u6841\u76EE)\n\
    \            long long y = modmul(target, modpow(cinv, d, p), p);\n          \
    \  for (long long j = 0; j + 1 + i < s; j++) y = modpow(y, q, p);\n          \
    \  d += log_zeta(y) * qi;\n        }\n        // d \u306F q^e \u306E\u500D\u6570\
    \u306B\u306A\u3063\u3066\u3044\u308B\n        z = modmul(x1, modpow(c, d / qe,\
    \ p), p);\n    }\n    const long long mg = m / g;\n    const long long inv = mg\
    \ == 1 ? 0 : modinv((k / g) % mg, mg);\n    return modpow(z, inv, p);\n}\n\n/**\n\
    \ * @brief \u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3 a\u2191\u2191b (a \u3092\
    \ b \u500B\u91CD\u306D\u305F\u3079\u304D\u4E57 a^a^...^a\u3001a\u2191\u21910 =\
    \ 1) \u3092 m \u3067\u5272\u3063\u305F\u4F59\u308A\u30020^0 = 1 \u3068\u3059\u308B\
    \n *\n * x >= log2(m) \u306A\u3089 a^x \u2261 a^(x mod \u03C6(m) + \u03C6(m))\
    \ (mod m) \u3092\u4F7F\u3044\u3001m \u3092 \u03C6(m) \u306B\u7F6E\u304D\u63DB\u3048\
    \u3066\u518D\u5E30\u3059\u308B\u3002m \u306F O(log m) \u56DE\u3067 1 \u306B\u306A\
    \u308B\n * \u9014\u4E2D\u306E\u5024\u306F\u300C\u672C\u5F53\u306E\u5024\u304C\
    \ m \u672A\u6E80\u306A\u3089\u305D\u306E\u307E\u307E\u3001m \u4EE5\u4E0A\u306A\
    \u3089 (\u5024 mod m) + m\u300D\u3067\u6301\u3061\u3001\u672C\u5F53\u306E\u5024\
    \u304C m \u4EE5\u4E0A\u304B\u3092\u5931\u308F\u306A\u3044\u3088\u3046\u306B\u3059\
    \u308B\n * O(log m \xD7 (factorize(m) + log m))\n * @pre m <= 2 \xD7 10^9\n */\n\
    inline long long tetration_mod(long long a, long long b, long long m) {\n    //\
    \ \u9014\u4E2D\u306E\u5024\u306F 2m \u672A\u6E80\u306A\u306E\u3067\u3001\u305D\
    \u306E\u7A4D\u304C\u3042\u3075\u308C\u306A\u3044\u3088\u3046\u306B m \u3092\u5236\
    \u9650\u3059\u308B\n    assert(a >= 0 && b >= 0 && 1 <= m && m <= 2000000000);\n\
    \    // x \u3092\u4E0A\u306E\u5F62\u306B\u76F4\u3059\n    auto clamp = [](long\
    \ long x, long long mod) { return x < mod ? x : x % mod + mod; };\n    // a\u2191\
    \u2191b \u3092\u4E0A\u306E\u5F62\u3067\u8FD4\u3059\n    auto rec = [&](auto self,\
    \ long long b, long long mod) -> long long {\n        if (b == 0) return clamp(1,\
    \ mod);\n        // 0\u2191\u2191b \u306F b \u304C\u5076\u6570\u306A\u3089 1\u3001\
    \u5947\u6570\u306A\u3089 0\n        if (a == 0) return clamp(b % 2 == 0 ? 1 :\
    \ 0, mod);\n        // a >= 1 \u306A\u3089 a\u2191\u2191b >= 1\n        if (a\
    \ == 1 || mod == 1) return clamp(1, mod);\n        const long long e = self(self,\
    \ b - 1, totient(mod));\n        // a^e \u3092\u4E0A\u306E\u5F62\u3067\u6C42\u3081\
    \u308B (a >= 1\u3001e >= 1)\n        long long res = 1, base = clamp(a, mod);\n\
    \        for (long long k = e; k > 0; k >>= 1) {\n            if (k & 1) res =\
    \ clamp(res * base, mod);\n            if (k > 1) base = clamp(base * base, mod);\n\
    \        }\n        return res;\n    };\n    return rec(rec, b, m) % m;\n}\n\n\
    /**\n * @brief n \u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\
    \u3066\u8FD4\u3059\n * \u5947\u6570\u3060\u3051\u3092\u533A\u9593\u3054\u3068\u306B\
    \u7BE9\u3046\u3002O(n log log n)\u3001\u30E1\u30E2\u30EA\u306F O(\u221An + \u7D20\
    \u6570\u306E\u500B\u6570)\n */\ninline std::vector<long long> enumerate_primes(long\
    \ long n) {\n    std::vector<long long> res;\n    if (n < 2) return res;\n   \
    \ res.push_back(2);\n    long long r = 1;\n    while ((r + 1) * (r + 1) <= n)\
    \ r++;\n    // \u221An \u4EE5\u4E0B\u306E\u5947\u7D20\u6570 p \u3068\u3001\u6B21\
    \u306B\u7BE9\u3046 p \u306E\u500D\u6570 (\u5947\u6570)\n    std::vector<char>\
    \ small(r + 1, 1);\n    std::vector<std::pair<long long, long long>> sp;\n   \
    \ for (long long i = 3; i <= r; i += 2) {\n        if (!small[i]) continue;\n\
    \        for (long long j = i * i; j <= r; j += 2 * i) small[j] = 0;\n       \
    \ sp.emplace_back(i, i * i);\n    }\n    // \u5947\u6570 2k+1 (1 <= k <= kmax)\
    \ \u3092\u3001k \u306E\u9577\u3055 B \u306E\u533A\u9593\u3054\u3068\u306B\u7BE9\
    \u3046\n    constexpr int B = 1 << 16;\n    std::vector<char> block(B);\n    const\
    \ long long kmax = (n - 1) / 2;\n    for (long long lo = 1; lo <= kmax; lo +=\
    \ B) {\n        const long long hi = std::min(lo + B, kmax + 1);\n        std::fill(block.begin(),\
    \ block.begin() + (hi - lo), 1);\n        for (auto& [p, m] : sp) {\n        \
    \    long long k = (m - 1) / 2;\n            for (; k < hi; k += p) block[k -\
    \ lo] = 0;\n            m = 2 * k + 1;\n        }\n        for (long long k =\
    \ lo; k < hi; k++) {\n            if (block[k - lo]) res.push_back(2 * k + 1);\n\
    \        }\n    }\n    return res;\n}\n\n/**\n * @brief n \u4EE5\u4E0B\u306E\u6574\
    \u6570\u306E\u6700\u5C0F\u7D20\u56E0\u6570\u3092\u524D\u8A08\u7B97\u3059\u308B\
    \u7BE9 (\u7DDA\u5F62\u7BE9)\n *\n * \u524D\u8A08\u7B97 O(n)\u3001\u7D20\u6570\u5224\
    \u5B9A O(1)\u3001\u7D20\u56E0\u6570\u5206\u89E3 O(log x)\n * \u4F8B:\n * Sieve\
    \ sv(1000000);\n * sv.is_prime(x); sv.factorize(x);\n */\nclass Sieve {\n    long\
    \ long n;\n    std::vector<int> lpf;  // \u6700\u5C0F\u7D20\u56E0\u6570 (\u30E1\
    \u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081 int \u3067\u6301\u3064)\n   \
    \ std::vector<long long> ps;\n\n   public:\n    explicit Sieve(long long n) :\
    \ n(n), lpf(n + 1, 0) {\n        assert(n >= 0);\n        for (int i = 2; i <=\
    \ n; i++) {\n            if (lpf[i] == 0) {\n                lpf[i] = i;\n   \
    \             ps.push_back(i);\n            }\n            for (long long p :\
    \ ps) {\n                if (p > lpf[i] || p * i > n) break;\n               \
    \ lpf[p * i] = p;\n            }\n        }\n    }\n\n    /**\n     * @brief \u524D\
    \u8A08\u7B97\u3057\u305F\u7BC4\u56F2\u306E\u4E0A\u9650 n\n     */\n    long long\
    \ limit() const { return n; }\n    /**\n     * @brief x (0 <= x <= n) \u304C\u7D20\
    \u6570\u304B O(1)\n     */\n    bool is_prime(long long x) const {\n        assert(0\
    \ <= x && x <= n);\n        return x >= 2 && lpf[x] == x;\n    }\n    /**\n  \
    \   * @brief x (2 <= x <= n) \u306E\u6700\u5C0F\u7D20\u56E0\u6570 O(1)\n     */\n\
    \    long long min_factor(long long x) const {\n        assert(2 <= x && x <=\
    \ n);\n        return lpf[x];\n    }\n    /**\n     * @brief n \u4EE5\u4E0B\u306E\
    \u7D20\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\n     */\n\
    \    const std::vector<long long>& primes() const { return ps; }\n    /**\n  \
    \   * @brief x (1 <= x <= n) \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\
    (\u7D20\u56E0\u6570, \u6307\u6570) \u3092\u7D20\u56E0\u6570\u306E\u6607\u9806\u306B\
    \u4E26\u3079\u3066\u8FD4\u3059 O(log x)\n     */\n    std::vector<std::pair<long\
    \ long, long long>> factorize(long long x) const {\n        assert(1 <= x && x\
    \ <= n);\n        std::vector<std::pair<long long, long long>> res;\n        while\
    \ (x > 1) {\n            long long p = lpf[x], e = 0;\n            while (x %\
    \ p == 0) x /= p, e++;\n            res.emplace_back(p, e);\n        }\n     \
    \   return res;\n    }\n    /**\n     * @brief x (1 <= x <= n) \u306E\u6B63\u306E\
    \u7D04\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\u8FD4\u3059\n     */\n\
    \    std::vector<long long> divisors(long long x) const {\n        std::vector<long\
    \ long> res = {1};\n        for (auto [p, e] : factorize(x)) {\n            const\
    \ long long sz = res.size();\n            long long pw = 1;\n            for (long\
    \ long i = 0; i < e; i++) {\n                pw *= p;\n                for (long\
    \ long j = 0; j < sz; j++) res.push_back(res[j] * pw);\n            }\n      \
    \  }\n        std::sort(res.begin(), res.end());\n        return res;\n    }\n\
    };\n#line 2 \"src/math/quotients.hpp\"\n\n/**\n * @file quotients.hpp\n * @brief\
    \ \u5546\u306E\u5217\u6319 (floor(n / i) \u304C\u540C\u3058\u5024\u306B\u306A\u308B\
    \ i \u306E\u533A\u9593)\n */\n\n#line 10 \"src/math/quotients.hpp\"\n\n/**\n *\
    \ @brief \u5546 q = floor(n / i) \u3068\u3001\u305D\u308C\u3092\u3068\u308B i\
    \ \u306E\u533A\u9593 [l, r]\n */\nstruct QuotientRange {\n    long long q;  //!<\
    \ \u5546\n    long long l;  //!< \u533A\u9593\u306E\u5DE6\u7AEF (\u542B\u3080\
    )\n    long long r;  //!< \u533A\u9593\u306E\u53F3\u7AEF (\u542B\u3080)\n};\n\n\
    /**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\u9593\
    \u306B\u5206\u3051\u3001i \u306E\u6607\u9806 (\u5546\u306E\u964D\u9806) \u306B\
    \ f(q, l, r) \u3092\u547C\u3076 O(sqrt(n))\n * l <= i <= r \u306A\u3089 floor(n\
    \ / i) == q\n */\ntemplate <typename F>\nvoid for_each_quotient(long long n, F\
    \ f) {\n    assert(n >= 0);\n    for (long long l = 1; l <= n;) {\n        long\
    \ long q = n / l, r = n / q;\n        f(q, l, r);\n        l = r + 1;\n    }\n\
    }\n\n/**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\
    \u9593\u306B\u5206\u3051\u305F\u3082\u306E (i \u306E\u6607\u9806\u3001\u3064\u307E\
    \u308A\u5546\u306E\u964D\u9806) O(sqrt(n))\n * \u533A\u9593\u306E\u500B\u6570\u306F\
    \ 2 sqrt(n) \u4EE5\u4E0B\n */\ninline std::vector<QuotientRange> enumerate_quotients(long\
    \ long n) {\n    std::vector<QuotientRange> res;\n    for_each_quotient(n, [&](long\
    \ long q, long long l, long long r) { res.push_back({q, l, r}); });\n    return\
    \ res;\n}\n#line 16 \"test/unittest/math/prime-counting.test.cpp\"\n\nusing mint\
    \ = static_modint<998244353>;\n\nbool ok = true;\nvoid check(bool cond, const\
    \ char* what) {\n    if (!cond && ok) std::cerr << \"failed: \" << what << std::endl;\n\
    \    if (!cond) ok = false;\n}\n\nint main() {\n    const long long N = 10000000;\n\
    \    Sieve sv(N);\n    // cnt[v]: v \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u500B\
    \u6570\u3001sum[v]: v \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u548C\u3001sq[v]: v\
    \ \u4EE5\u4E0B\u306E\u7D20\u6570\u306E 2 \u4E57\u306E\u548C (mod)\n    std::vector<long\
    \ long> cnt(N + 1, 0);\n    std::vector<__int128> sum(N + 1, 0);\n    std::vector<mint>\
    \ sq(N + 1, 0);\n    for (long long v = 1; v <= N; v++) {\n        bool p = sv.is_prime(v);\n\
    \        cnt[v] = cnt[v - 1] + p;\n        sum[v] = sum[v - 1] + (p ? v : 0);\n\
    \        sq[v] = sq[v - 1] + (p ? mint(v) * v : mint(0));\n    }\n\n    // \u5C0F\
    \u3055\u3044 n \u306F\u3059\u3079\u3066\u3001\u8868\u306E\u3059\u3079\u3066\u306E\
    \u5024\u307E\u3067\u6BD4\u3079\u308B\n    for (long long n = 1; n <= 3000 && ok;\
    \ n++) {\n        check(prime_count(n) == cnt[n], \"prime_count \u5C0F\u3055\u3044\
    \ n\");\n        auto t = prime_count_table(n);\n        for (auto [q, l, r] :\
    \ enumerate_quotients(n)) check(t(q) == cnt[q], \"prime_count_table\");\n    \
    \    // values() \u306F floor(n / k) \u306E\u3068\u308B\u5024\u306E\u6607\u9806\
    \n        std::vector<long long> qs;\n        for (auto [q, l, r] : enumerate_quotients(n))\
    \ qs.insert(qs.begin(), q);\n        check(t.values() == qs, \"values\");\n  \
    \  }\n    check(prime_count(0) == 0 && prime_count(1) == 0 && prime_count(2) ==\
    \ 1, \"prime_count 0, 1, 2\");\n\n    // \u30E9\u30F3\u30C0\u30E0\u306A n (10^7\
    \ \u307E\u3067)\u3002\u7D20\u6570\u306E\u548C (__int128) \u3068 2 \u4E57\u306E\
    \u548C (mod) \u3082\u6BD4\u3079\u308B\n    std::mt19937_64 rng(314);\n    for\
    \ (int rep = 0; rep < 30 && ok; rep++) {\n        long long n = rep < 3 ? N -\
    \ rep : static_cast<long long>(rng() % N) + 1;\n        check(prime_count(n) ==\
    \ cnt[n], \"prime_count\");\n        PrimeSumTable<__int128> s(n, [](long long\
    \ v) { return static_cast<__int128>(v) * (v + 1) / 2 - 1; }, [](long long p) {\
    \ return static_cast<__int128>(p); });\n        PrimeSumTable<mint> s2(\n    \
    \        n, [](long long v) { mint x = v; return x * (x + 1) * (2 * x + 1) / 6\
    \ - 1; }, [](long long p) { return mint(p) * p; });\n        for (auto [q, l,\
    \ r] : enumerate_quotients(n)) {\n            check(s(q) == sum[q], \"PrimeSumTable\
    \ \u7D20\u6570\u306E\u548C\");\n            check(s2(q) == sq[q], \"PrimeSumTable\
    \ \u7D20\u6570\u306E 2 \u4E57\u306E\u548C\");\n        }\n    }\n\n    // \u5927\
    \u304D\u3044 n: \u65E2\u77E5\u306E\u5024 \u03C0(10^k)\n    check(prime_count(1000000000LL)\
    \ == 50847534, \"\u03C0(10^9)\");\n    check(prime_count(10000000000LL) == 455052511,\
    \ \"\u03C0(10^10)\");\n\n    // multiplicative_sum: \u03C6\u30FB\u30E1\u30D3\u30A6\
    \u30B9\u95A2\u6570 \u03BC\u30FB\u7D04\u6570\u306E\u548C \u03C3 \u3092\u3001\u7BE9\
    \u3067\u6C42\u3081\u305F\u5024\u3092\u8DB3\u3057\u305F\u3082\u306E\u3068\u6BD4\
    \u3079\u308B\n    {\n        const int N = 3000;\n        // \u6700\u5C0F\u7D20\
    \u56E0\u6570\u3067\u5272\u3063\u3066\u3044\u304D\u3001\u4E57\u6CD5\u7684\u95A2\
    \u6570\u3092\u7D20\u56E0\u6570\u5206\u89E3\u304B\u3089\u6C42\u3081\u308B\n   \
    \     std::vector<int> lpf(N + 1, 0);\n        for (int i = 2; i <= N; i++)\n\
    \            if (lpf[i] == 0)\n                for (int j = i; j <= N; j += i)\n\
    \                    if (lpf[j] == 0) lpf[j] = i;\n        auto eval = [&](int\
    \ i, auto f_pe) {\n            long long r = 1;\n            while (i > 1) {\n\
    \                int p = lpf[i], e = 0;\n                while (i % p == 0) i\
    \ /= p, e++;\n                r *= f_pe(p, e);\n            }\n            return\
    \ r;\n        };\n        auto power = [](long long p, long long e) {\n      \
    \      long long r = 1;\n            while (e--) r *= p;\n            return r;\n\
    \        };\n        auto phi = [&](long long p, long long e) { return power(p,\
    \ e) - power(p, e - 1); };\n        auto mu = [](long long, long long e) { return\
    \ e == 1 ? -1LL : 0LL; };\n        auto sigma = [&](long long p, long long e)\
    \ { return (power(p, e + 1) - 1) / (p - 1); };\n        for (int n = 0; n <= N\
    \ && ok; n += (n < 100 ? 1 : 37)) {\n            long long e_phi = 0, e_mu = 0,\
    \ e_sigma = 0;\n            for (int i = 1; i <= n; i++) e_phi += eval(i, phi),\
    \ e_mu += eval(i, mu), e_sigma += eval(i, sigma);\n            if (n == 0) {\n\
    \                check(multiplicative_sum(0, [](long long) { return 0LL; }, phi)\
    \ == 0, \"multiplicative_sum n = 0\");\n                continue;\n          \
    \  }\n            PrimeSumTable<long long> cnt(n, [](long long v) { return v -\
    \ 1; }, [](long long) { return 1LL; });\n            PrimeSumTable<long long>\
    \ sum(n, [](long long v) { return v * (v + 1) / 2 - 1; }, [](long long p) { return\
    \ p; });\n            check(multiplicative_sum(n, [&](long long v) { return sum(v)\
    \ - cnt(v); }, phi) == e_phi, \"multiplicative_sum \u03C6\");\n            check(multiplicative_sum(n,\
    \ [&](long long v) { return -cnt(v); }, mu) == e_mu, \"multiplicative_sum \u03BC\
    \");\n            check(multiplicative_sum(n, [&](long long v) { return sum(v)\
    \ + cnt(v); }, sigma) == e_sigma, \"multiplicative_sum \u03C3\");\n        }\n\
    \    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// prime_count\u30FBprime_count_table\u30FBPrimeSumTable \u3092\u3001\u7BE9\
    \u3067\u6570\u3048\u305F\u5024\u3068\u6BD4\u3079\u308B\n// multiplicative_sum\
    \ \u3092\u3001\u7BE9\u3067\u6C42\u3081\u305F\u4E57\u6CD5\u7684\u95A2\u6570 (\u03C6\
    \u30FB\u03BC\u30FB\u03C3) \u306E\u548C\u3068\u6BD4\u3079\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/math/prime-counting.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <vector>\n\n#include \"../../../src/math/modint.hpp\"\
    \n#include \"../../../src/math/prime.hpp\"\n#include \"../../../src/math/quotients.hpp\"\
    \n\nusing mint = static_modint<998244353>;\n\nbool ok = true;\nvoid check(bool\
    \ cond, const char* what) {\n    if (!cond && ok) std::cerr << \"failed: \" <<\
    \ what << std::endl;\n    if (!cond) ok = false;\n}\n\nint main() {\n    const\
    \ long long N = 10000000;\n    Sieve sv(N);\n    // cnt[v]: v \u4EE5\u4E0B\u306E\
    \u7D20\u6570\u306E\u500B\u6570\u3001sum[v]: v \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\
    \u548C\u3001sq[v]: v \u4EE5\u4E0B\u306E\u7D20\u6570\u306E 2 \u4E57\u306E\u548C\
    \ (mod)\n    std::vector<long long> cnt(N + 1, 0);\n    std::vector<__int128>\
    \ sum(N + 1, 0);\n    std::vector<mint> sq(N + 1, 0);\n    for (long long v =\
    \ 1; v <= N; v++) {\n        bool p = sv.is_prime(v);\n        cnt[v] = cnt[v\
    \ - 1] + p;\n        sum[v] = sum[v - 1] + (p ? v : 0);\n        sq[v] = sq[v\
    \ - 1] + (p ? mint(v) * v : mint(0));\n    }\n\n    // \u5C0F\u3055\u3044 n \u306F\
    \u3059\u3079\u3066\u3001\u8868\u306E\u3059\u3079\u3066\u306E\u5024\u307E\u3067\
    \u6BD4\u3079\u308B\n    for (long long n = 1; n <= 3000 && ok; n++) {\n      \
    \  check(prime_count(n) == cnt[n], \"prime_count \u5C0F\u3055\u3044 n\");\n  \
    \      auto t = prime_count_table(n);\n        for (auto [q, l, r] : enumerate_quotients(n))\
    \ check(t(q) == cnt[q], \"prime_count_table\");\n        // values() \u306F floor(n\
    \ / k) \u306E\u3068\u308B\u5024\u306E\u6607\u9806\n        std::vector<long long>\
    \ qs;\n        for (auto [q, l, r] : enumerate_quotients(n)) qs.insert(qs.begin(),\
    \ q);\n        check(t.values() == qs, \"values\");\n    }\n    check(prime_count(0)\
    \ == 0 && prime_count(1) == 0 && prime_count(2) == 1, \"prime_count 0, 1, 2\"\
    );\n\n    // \u30E9\u30F3\u30C0\u30E0\u306A n (10^7 \u307E\u3067)\u3002\u7D20\u6570\
    \u306E\u548C (__int128) \u3068 2 \u4E57\u306E\u548C (mod) \u3082\u6BD4\u3079\u308B\
    \n    std::mt19937_64 rng(314);\n    for (int rep = 0; rep < 30 && ok; rep++)\
    \ {\n        long long n = rep < 3 ? N - rep : static_cast<long long>(rng() %\
    \ N) + 1;\n        check(prime_count(n) == cnt[n], \"prime_count\");\n       \
    \ PrimeSumTable<__int128> s(n, [](long long v) { return static_cast<__int128>(v)\
    \ * (v + 1) / 2 - 1; }, [](long long p) { return static_cast<__int128>(p); });\n\
    \        PrimeSumTable<mint> s2(\n            n, [](long long v) { mint x = v;\
    \ return x * (x + 1) * (2 * x + 1) / 6 - 1; }, [](long long p) { return mint(p)\
    \ * p; });\n        for (auto [q, l, r] : enumerate_quotients(n)) {\n        \
    \    check(s(q) == sum[q], \"PrimeSumTable \u7D20\u6570\u306E\u548C\");\n    \
    \        check(s2(q) == sq[q], \"PrimeSumTable \u7D20\u6570\u306E 2 \u4E57\u306E\
    \u548C\");\n        }\n    }\n\n    // \u5927\u304D\u3044 n: \u65E2\u77E5\u306E\
    \u5024 \u03C0(10^k)\n    check(prime_count(1000000000LL) == 50847534, \"\u03C0\
    (10^9)\");\n    check(prime_count(10000000000LL) == 455052511, \"\u03C0(10^10)\"\
    );\n\n    // multiplicative_sum: \u03C6\u30FB\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\
    \ \u03BC\u30FB\u7D04\u6570\u306E\u548C \u03C3 \u3092\u3001\u7BE9\u3067\u6C42\u3081\
    \u305F\u5024\u3092\u8DB3\u3057\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B\n   \
    \ {\n        const int N = 3000;\n        // \u6700\u5C0F\u7D20\u56E0\u6570\u3067\
    \u5272\u3063\u3066\u3044\u304D\u3001\u4E57\u6CD5\u7684\u95A2\u6570\u3092\u7D20\
    \u56E0\u6570\u5206\u89E3\u304B\u3089\u6C42\u3081\u308B\n        std::vector<int>\
    \ lpf(N + 1, 0);\n        for (int i = 2; i <= N; i++)\n            if (lpf[i]\
    \ == 0)\n                for (int j = i; j <= N; j += i)\n                   \
    \ if (lpf[j] == 0) lpf[j] = i;\n        auto eval = [&](int i, auto f_pe) {\n\
    \            long long r = 1;\n            while (i > 1) {\n                int\
    \ p = lpf[i], e = 0;\n                while (i % p == 0) i /= p, e++;\n      \
    \          r *= f_pe(p, e);\n            }\n            return r;\n        };\n\
    \        auto power = [](long long p, long long e) {\n            long long r\
    \ = 1;\n            while (e--) r *= p;\n            return r;\n        };\n \
    \       auto phi = [&](long long p, long long e) { return power(p, e) - power(p,\
    \ e - 1); };\n        auto mu = [](long long, long long e) { return e == 1 ? -1LL\
    \ : 0LL; };\n        auto sigma = [&](long long p, long long e) { return (power(p,\
    \ e + 1) - 1) / (p - 1); };\n        for (int n = 0; n <= N && ok; n += (n < 100\
    \ ? 1 : 37)) {\n            long long e_phi = 0, e_mu = 0, e_sigma = 0;\n    \
    \        for (int i = 1; i <= n; i++) e_phi += eval(i, phi), e_mu += eval(i, mu),\
    \ e_sigma += eval(i, sigma);\n            if (n == 0) {\n                check(multiplicative_sum(0,\
    \ [](long long) { return 0LL; }, phi) == 0, \"multiplicative_sum n = 0\");\n \
    \               continue;\n            }\n            PrimeSumTable<long long>\
    \ cnt(n, [](long long v) { return v - 1; }, [](long long) { return 1LL; });\n\
    \            PrimeSumTable<long long> sum(n, [](long long v) { return v * (v +\
    \ 1) / 2 - 1; }, [](long long p) { return p; });\n            check(multiplicative_sum(n,\
    \ [&](long long v) { return sum(v) - cnt(v); }, phi) == e_phi, \"multiplicative_sum\
    \ \u03C6\");\n            check(multiplicative_sum(n, [&](long long v) { return\
    \ -cnt(v); }, mu) == e_mu, \"multiplicative_sum \u03BC\");\n            check(multiplicative_sum(n,\
    \ [&](long long v) { return sum(v) + cnt(v); }, sigma) == e_sigma, \"multiplicative_sum\
    \ \u03C3\");\n        }\n    }\n\n    if (ok) std::cout << \"Hello World\" <<\
    \ std::endl;\n}\n"
  dependsOn:
  - src/math/prime-counting.hpp
  - src/math/sqrt.hpp
  - src/math/modint.hpp
  - src/utility/traits.hpp
  - src/math/prime.hpp
  - src/math/modular-arithmetic.hpp
  - src/math/quotients.hpp
  isVerificationFile: true
  path: test/unittest/math/prime-counting.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 05:46:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/math/prime-counting.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/math/prime-counting.test.cpp
- /verify/test/unittest/math/prime-counting.test.cpp.html
title: test/unittest/math/prime-counting.test.cpp
---
