---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  - icon: ':heavy_check_mark:'
    path: src/utility/vector_func.hpp
    title: "vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570"
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
  bundledCode: "#line 1 \"test/unittest/utility/vector_func.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ vector_func.hpp \u306E\u6F14\u7B97\u5B50\u3068\u95A2\u6570\u3092\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #line 2 \"src/utility/vector_func.hpp\"\n\n/**\n * @file vector_func.hpp\n * @brief\
    \ vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570\n */\n\n\
    #include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <cstddef>\n\
    #include <functional>\n#include <numeric>\n#include <type_traits>\n#include <vector>\n\
    \n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\
    \u7279\u6027\n */\n\n#line 10 \"src/utility/traits.hpp\"\n#include <iterator>\n\
    #include <set>\n#line 13 \"src/utility/traits.hpp\"\n#include <utility>\n\nnamespace\
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
    #line 18 \"src/utility/vector_func.hpp\"\n\n/**\n * @brief \u5024\u3092 proj \u3067\
    \u5199\u3057\u3066 comp \u306E\u9806\u306B\u5B89\u5B9A\u30BD\u30FC\u30C8\u3057\
    \u305F\u3068\u304D\u306E\u6DFB\u5B57\u306E\u4E26\u3073 (APL \u306E grade up)\n\
    \ */\ntemplate <typename T, typename F = std::less<>, typename P = internal_traits::identity>\n\
    std::vector<long long> argsort(const std::vector<T>& v, F comp = F(), P proj =\
    \ P()) {\n    std::vector<long long> ret(v.size());\n    std::iota(ret.begin(),\
    \ ret.end(), 0LL);\n    std::stable_sort(ret.begin(), ret.end(), [&](long long\
    \ i, long long j) {\n        return std::invoke(comp, std::invoke(proj, v[i]),\
    \ std::invoke(proj, v[j]));\n    });\n    return ret;\n}\n\n/**\n * @brief \u5404\
    \u8981\u7D20\u306E\u9806\u4F4D (proj \u3067\u5199\u3057\u3066 comp \u306E\u9806\
    \u3067 v[i] \u3088\u308A\u524D\u306B\u6765\u308B\u8981\u7D20\u306E\u500B\u6570\
    )\u3002\u540C\u7387\u306F\u540C\u3058\u9806\u4F4D\u3067\u3001\u6B21\u306E\u9806\
    \u4F4D\u306F\u98DB\u3070\u3059\n */\ntemplate <typename T, typename F = std::less<>,\
    \ typename P = internal_traits::identity>\nstd::vector<long long> rank(const std::vector<T>&\
    \ v, F comp = F(), P proj = P()) {\n    const long long n = v.size();\n    std::vector<long\
    \ long> p = argsort(v, comp, proj), ret(n);\n    for (long long i = 0; i < n;\
    \ i++) {\n        ret[p[i]] = i > 0 && !std::invoke(comp, std::invoke(proj, v[p[i\
    \ - 1]]), std::invoke(proj, v[p[i]])) ? ret[p[i - 1]] : i;\n    }\n    return\
    \ ret;\n}\n\n/**\n * @brief \u9006\u7F6E\u63DB (ret[p[i]] = i)\u3002p \u306F 0,\
    \ ..., n-1 \u306E\u7F6E\u63DB\u3067\u3042\u308B\u3053\u3068\n */\ntemplate <typename\
    \ I, ENABLE_IF_T(std::is_integral_v<I>)>\nstd::vector<long long> inverse_permutation(const\
    \ std::vector<I>& p) {\n    const long long n = p.size();\n    std::vector<long\
    \ long> ret(n, -1);\n    for (long long i = 0; i < n; i++) {\n        const long\
    \ long x = static_cast<long long>(p[i]);\n        assert(0 <= x && x < n && ret[x]\
    \ == -1);\n        ret[x] = i;\n    }\n    return ret;\n}\n\n/**\n * @brief {v[idx[0]],\
    \ v[idx[1]], ...} (Uiua \u306E select)\n */\ntemplate <typename T, typename I,\
    \ ENABLE_IF_T(std::is_integral_v<I>)>\nstd::vector<T> select(const std::vector<T>&\
    \ v, const std::vector<I>& idx) {\n    std::vector<T> ret;\n    ret.reserve(idx.size());\n\
    \    for (I i : idx) {\n        assert(0 <= static_cast<long long>(i) && static_cast<long\
    \ long>(i) < static_cast<long long>(v.size()));\n        ret.push_back(v[i]);\n\
    \    }\n    return ret;\n}\n\ntemplate <typename T>\ninline std::vector<T>& operator++(std::vector<T>&\
    \ v) {\n    for (auto& e : v) e++;\n    return v;\n}\ntemplate <typename T>\n\
    inline std::vector<T> operator++(std::vector<T>& v, int) {\n    auto res = v;\n\
    \    for (auto& e : v) e++;\n    return res;\n}\ntemplate <typename T>\ninline\
    \ std::vector<T>& operator--(std::vector<T>& v) {\n    for (auto& e : v) e--;\n\
    \    return v;\n}\ntemplate <typename T>\ninline std::vector<T> operator--(std::vector<T>&\
    \ v, int) {\n    auto res = v;\n    for (auto& e : v) e--;\n    return res;\n\
    }\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\n\
    inline std::vector<T>& operator+=(std::vector<T>& v1, const std::vector<U>& v2)\
    \ {\n    if (v2.size() > v1.size()) {\n        v1.resize(v2.size());\n    }\n\
    \    for (std::size_t i = 0; i < v2.size(); i++) {\n        v1[i] += v2[i];\n\
    \    }\n    return v1;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator+(const std::vector<T>& v1, const std::vector<U>&\
    \ v2) {\n    std::vector<T> res(v1);\n    return res += v2;\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>&\
    \ operator+=(std::vector<T>& v, const U& u) {\n    for (T& e : v) {\n        e\
    \ += u;\n    }\n    return v;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator+(const std::vector<T>& v, const U& u) {\n\
    \    std::vector<T> res(v);\n    return res += u;\n}\n\ntemplate <typename T,\
    \ typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ operator+(const U& u, const std::vector<T>& v) {\n    std::vector<T> res(v);\n\
    \    return res += u;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T>& operator*=(std::vector<T>& v1, const std::vector<U>&\
    \ v2) {\n    if (v2.size() > v1.size()) {\n        v1.resize(v2.size());\n   \
    \ }\n    for (std::size_t i = 0; i < v2.size(); i++) {\n        v1[i] *= v2[i];\n\
    \    }\n    for (std::size_t i = v2.size(); i < v1.size(); i++) {\n        v1[i]\
    \ *= U(0);\n    }\n    return v1;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator*(const std::vector<T>& v1, const std::vector<U>&\
    \ v2) {\n    std::vector<T> res(v1);\n    return res *= v2;\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>&\
    \ operator*=(std::vector<T>& v, const U& u) {\n    for (T& e : v) {\n        e\
    \ *= u;\n    }\n    return v;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator*(const std::vector<T>& v, const U& u) {\n\
    \    std::vector<T> res(v);\n    return res *= u;\n}\n\ntemplate <typename T,\
    \ typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ operator*(const U& u, const std::vector<T>& v) {\n    std::vector<T> res(v);\n\
    \    return res *= u;\n}\n\ntemplate <typename T, typename U>\ninline std::vector<T>&\
    \ assign(std::vector<T>& v1, const std::vector<U>& v2) {\n    v1.assign(v2.begin(),\
    \ v2.end());\n    return v1;\n}\n\ntemplate <typename T, typename U>\ninline std::vector<T>&\
    \ extend(std::vector<T>& v1, const std::vector<U>& v2) {\n    v1.insert(v1.end(),\
    \ v2.begin(), v2.end());\n    return v1;\n}\n\ntemplate <typename T, typename\
    \ U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>& operator|=(std::vector<T>&\
    \ v1, const std::vector<U>& v2) {\n    return extend(v1, v2);\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\ninline std::vector<T>& operator|=(std::vector<T>&\
    \ v, const U& u) {\n    if constexpr (std::is_signed_v<U>) assert(u >= 0);\n \
    \   std::vector<T> w(v);\n    v.clear();\n    for (long long i = 0; i < static_cast<long\
    \ long>(u); i++) {\n        extend(v, w);\n    }\n    return v;\n}\n\ntemplate\
    \ <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\ninline std::vector<T>\
    \ operator|(const std::vector<T>& v, const U& u) {\n    std::vector<T> res(v);\n\
    \    return res |= u;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\n\
    inline std::vector<T> operator|(const U& u, const std::vector<T>& v) {\n    std::vector<T>\
    \ res(v);\n    return res |= u;\n}\n\ntemplate <typename T>\ninline std::vector<T>\
    \ abs(const std::vector<T>& v) {\n    std::vector<T> ret;\n    ret.reserve(v.size());\n\
    \    for (const T& e : v) ret.push_back(std::abs(e));\n    return ret;\n}\n\n\
    template <typename T>\nstd::vector<T> cumulative_sum(std::vector<T> v) {\n   \
    \ v.insert(v.begin(), T{});\n    std::vector<T> ret(v.size());\n    std::partial_sum(v.begin(),\
    \ v.end(), ret.begin());\n    return ret;\n}\n\ntemplate <typename T, ENABLE_IF_T(std::is_integral_v<T>)>\n\
    std::vector<T> iota(T n) {\n    assert(n >= 0);\n    std::vector<T> ret(n);\n\
    \    std::iota(ret.begin(), ret.end(), 0);\n    return ret;\n}\n\ntemplate <typename\
    \ T, typename U>\nlong long hamming_distance(const std::vector<T>& v1, const std::vector<U>&\
    \ v2) {\n    assert(v1.size() == v2.size());\n    long long res = 0;\n    for\
    \ (std::size_t i = 0; i < v1.size(); i++) {\n        if (!(v1[i] == v2[i])) res++;\n\
    \    }\n    return res;\n}\n\ntemplate <typename T>\nstd::vector<T> unique(const\
    \ std::vector<T>& v) {\n    std::vector<T> res(v);\n    std::sort(res.begin(),\
    \ res.end());\n    res.erase(std::unique(res.begin(), res.end()), res.end());\n\
    \    return res;\n}\n\ninline long long radix_convert(const std::vector<long long>&\
    \ v, int base = 10) {\n    assert(base >= 2);\n    long long res = 0;\n    for\
    \ (long long d : v) {\n        assert(0 <= d && d < base);\n        res = res\
    \ * base + d;\n    }\n    return res;\n}\n\ninline std::vector<long long> radix_convert(long\
    \ long v, int base = 10) {\n    assert(v >= 0 && base >= 2);\n    std::vector<long\
    \ long> res;\n    while (v > 0) {\n        res.push_back(v % base);\n        v\
    \ /= base;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n\
    }\n#line 7 \"test/unittest/utility/vector_func.test.cpp\"\n\n#line 9 \"test/unittest/utility/vector_func.test.cpp\"\
    \n#include <cstdlib>\n#line 11 \"test/unittest/utility/vector_func.test.cpp\"\n\
    #include <iostream>\n#include <random>\n#line 14 \"test/unittest/utility/vector_func.test.cpp\"\
    \n\nbool ok = true;\n\nvoid check(bool cond, const char* what) {\n    if (!cond)\
    \ {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n       \
    \ ok = false;\n    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n    auto\
    \ rand_vec = [&](int n) {\n        std::vector<long long> v(n);\n        for (auto&\
    \ x : v) x = static_cast<long long>(rng() % 21) - 10;\n        return v;\n   \
    \ };\n\n    for (int rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng()\
    \ % 8, m = rng() % 8;\n        std::vector<long long> a = rand_vec(n), b = rand_vec(m);\n\
    \        long long c = static_cast<long long>(rng() % 11) - 5;\n\n        // ++\
    \ / -- (\u524D\u7F6E\u306F\u5909\u66F4\u5F8C\u3001\u5F8C\u7F6E\u306F\u5909\u66F4\
    \u524D\u3092\u8FD4\u3059)\n        {\n            std::vector<long long> x = a,\
    \ inc = a, dec = a;\n            for (auto& e : inc) e++;\n            for (auto&\
    \ e : dec) e--;\n            check(++x == inc && x == inc, \"\u524D\u7F6E ++\"\
    );\n            check(x-- == inc && x == a, \"\u5F8C\u7F6E --\");\n          \
    \  check(--x == dec && x == dec, \"\u524D\u7F6E --\");\n            check(x++\
    \ == dec && x == a, \"\u5F8C\u7F6E ++\");\n        }\n\n        // \u8981\u7D20\
    \u3054\u3068\u306E\u548C (\u77ED\u3044\u65B9\u306F 0 \u3067\u57CB\u3081\u308B\
    )\n        {\n            std::vector<long long> expect(std::max(n, m));\n   \
    \         for (int i = 0; i < static_cast<int>(expect.size()); i++) expect[i]\
    \ = (i < n ? a[i] : 0) + (i < m ? b[i] : 0);\n            check(a + b == expect,\
    \ \"v + w\");\n            std::vector<long long> x = a;\n            x += b;\n\
    \            check(x == expect, \"v += w\");\n        }\n\n        // \u8981\u7D20\
    \u3054\u3068\u306E\u7A4D (\u3069\u3061\u3089\u304B\u306B\u306A\u3044\u4F4D\u7F6E\
    \u306F 0)\n        {\n            std::vector<long long> expect(std::max(n, m));\n\
    \            for (int i = 0; i < static_cast<int>(expect.size()); i++) expect[i]\
    \ = (i < n && i < m) ? a[i] * b[i] : 0;\n            check(a * b == expect, \"\
    v * w\");\n            std::vector<long long> x = a;\n            x *= b;\n  \
    \          check(x == expect, \"v *= w\");\n        }\n\n        // \u30B9\u30AB\
    \u30E9\u30FC\u3068\u306E\u548C\u30FB\u7A4D\n        {\n            std::vector<long\
    \ long> plus = a, times = a;\n            for (auto& e : plus) e += c;\n     \
    \       for (auto& e : times) e *= c;\n            check(a + c == plus && c +\
    \ a == plus, \"v + c, c + v\");\n            check(a * c == times && c * a ==\
    \ times, \"v * c, c * v\");\n            std::vector<long long> x = a;\n     \
    \       x += c;\n            check(x == plus, \"v += c\");\n            x = a;\n\
    \            x *= c;\n            check(x == times, \"v *= c\");\n        }\n\n\
    \        // \u9023\u7D50\u3068\u7E70\u308A\u8FD4\u3057\n        {\n          \
    \  std::vector<long long> cat = a;\n            cat.insert(cat.end(), b.begin(),\
    \ b.end());\n            std::vector<long long> x = a;\n            check(&extend(x,\
    \ b) == &x && x == cat, \"extend\");\n            x = a;\n            x |= b;\n\
    \            check(x == cat, \"v |= w\");\n            int k = rng() % 4;\n  \
    \          std::vector<long long> rep_k;\n            for (int i = 0; i < k; i++)\
    \ rep_k.insert(rep_k.end(), a.begin(), a.end());\n            check((a | k) ==\
    \ rep_k && (k | a) == rep_k, \"v | k, k | v\");\n            x = a;\n        \
    \    x |= k;\n            check(x == rep_k, \"v |= k\");\n        }\n\n      \
    \  // assign (\u578B\u306E\u5909\u63DB\u3064\u304D)\n        {\n            std::vector<int>\
    \ small(b.begin(), b.end());\n            std::vector<long long> x = a;\n    \
    \        check(&assign(x, small) == &x && x == b, \"assign\");\n        }\n\n\
    \        // abs\n        {\n            std::vector<long long> expect = a;\n \
    \           for (auto& e : expect) e = std::llabs(e);\n            check(abs(a)\
    \ == expect, \"abs\");\n        }\n\n        // argsort: \u5024\u306E\u6607\u9806\
    \ (\u964D\u9806) \u306B\u5B89\u5B9A\u30BD\u30FC\u30C8\u3057\u305F\u6DFB\u5B57\u306E\
    \u4E26\u3073\n        {\n            for (bool rev : {false, true}) {\n      \
    \          auto idx = rev ? argsort(a, std::greater<>()) : argsort(a);\n     \
    \           std::vector<long long> perm = idx;\n                std::sort(perm.begin(),\
    \ perm.end());\n                bool is_perm = static_cast<int>(perm.size()) ==\
    \ n;\n                for (int i = 0; i < static_cast<int>(perm.size()) && is_perm;\
    \ i++) is_perm = perm[i] == i;\n                bool is_sorted = true;\n     \
    \           for (int i = 0; i + 1 < static_cast<int>(idx.size()); i++) {\n   \
    \                 long long x = a[idx[i]], y = a[idx[i + 1]];\n              \
    \      if (rev ? x < y : x > y) is_sorted = false;\n                    if (x\
    \ == y && idx[i] > idx[i + 1]) is_sorted = false;  // \u5B89\u5B9A\n         \
    \       }\n                check(is_perm && is_sorted, \"argsort\");\n       \
    \     }\n        }\n\n        // rank: v[i] \u3088\u308A\u5C0F\u3055\u3044 (\u964D\
    \u9806\u306A\u3089\u5927\u304D\u3044) \u8981\u7D20\u306E\u500B\u6570\n       \
    \ {\n            for (bool rev : {false, true}) {\n                auto r = rev\
    \ ? rank(a, std::greater<>()) : rank(a);\n                bool same = static_cast<int>(r.size())\
    \ == n;\n                for (int i = 0; i < n && same; i++) {\n             \
    \       long long cnt = 0;\n                    for (int j = 0; j < n; j++) cnt\
    \ += rev ? a[j] > a[i] : a[j] < a[i];\n                    same = r[i] == cnt;\n\
    \                }\n                check(same, \"rank\");\n            }\n  \
    \      }\n\n        // inverse_permutation: argsort(argsort(v)) \u3068\u4E00\u81F4\
    \u3057\u3001\u5143\u306E\u7F6E\u63DB\u3068\u5408\u6210\u3059\u308B\u3068\u6052\
    \u7B49\u7F6E\u63DB\n        {\n            auto p = argsort(a);\n            auto\
    \ q = inverse_permutation(p);\n            check(q == argsort(p), \"inverse_permutation\
    \ == argsort(argsort(v))\");\n            bool is_inv = static_cast<int>(q.size())\
    \ == n;\n            for (int i = 0; i < n && is_inv; i++) is_inv = p[q[i]] ==\
    \ i && q[p[i]] == i;\n            check(is_inv, \"inverse_permutation\");\n  \
    \          std::vector<int> pi(p.begin(), p.end());\n            check(inverse_permutation(pi)\
    \ == q, \"inverse_permutation (int)\");\n        }\n\n        // argsort / rank\
    \ (\u5C04\u5F71\u3064\u304D): \u5199\u3057\u305F\u5024\u306E\u5217\u306B\u5BFE\
    \u3059\u308B\u7D50\u679C\u3068\u4E00\u81F4\u3059\u308B\n        {\n          \
    \  auto key = [](long long x) { return x * x; };\n            std::vector<long\
    \ long> b(n);\n            for (int i = 0; i < n; i++) b[i] = key(a[i]);\n   \
    \         check(argsort(a, {}, key) == argsort(b), \"argsort(v, {}, proj)\");\n\
    \            check(argsort(a, std::greater<>(), key) == argsort(b, std::greater<>()),\
    \ \"argsort(v, comp, proj)\");\n            check(rank(a, {}, key) == rank(b),\
    \ \"rank(v, {}, proj)\");\n            check(rank(a, std::greater<>(), key) ==\
    \ rank(b, std::greater<>()), \"rank(v, comp, proj)\");\n            std::vector<std::pair<long\
    \ long, long long>> ps(n);\n            for (int i = 0; i < n; i++) ps[i] = {a[i],\
    \ -i};\n            check(argsort(ps, {}, &std::pair<long long, long long>::first)\
    \ == argsort(a), \"argsort(v, {}, &T::member)\");\n        }\n\n        // select:\
    \ \u6DFB\u5B57\u306E\u5217\u3067\u53D6\u308A\u51FA\u3059\n        {\n        \
    \    std::vector<int> idx(n);\n            for (auto& i : idx) i = static_cast<int>(rng()\
    \ % std::max(n, 1));\n            auto s = select(a, idx);\n            bool ok\
    \ = static_cast<int>(s.size()) == n;\n            for (int i = 0; i < n && ok;\
    \ i++) ok = s[i] == a[idx[i]];\n            check(ok, \"select\");\n         \
    \   std::vector<long long> expect = a;\n            std::sort(expect.begin(),\
    \ expect.end());\n            check(select(a, argsort(a)) == expect, \"select(v,\
    \ argsort(v))\");\n        }\n\n        // hamming_distance (\u540C\u3058\u9577\
    \u3055\u3069\u3046\u3057\u3001\u578B\u304C\u7570\u306A\u3063\u3066\u3082\u3088\
    \u3044)\n        {\n            std::vector<long long> d = rand_vec(n);\n    \
    \        std::vector<int> e(d.begin(), d.end());\n            long long hd = 0;\n\
    \            for (int i = 0; i < n; i++) hd += a[i] != d[i];\n            check(hamming_distance(a,\
    \ d) == hd && hamming_distance(a, e) == hd, \"hamming_distance\");\n        }\n\
    \n        // iota\n        {\n            std::vector<int> expect(n);\n      \
    \      for (int i = 0; i < n; i++) expect[i] = i;\n            check(iota(n) ==\
    \ expect, \"iota\");\n        }\n\n        // radix_convert: \u6574\u6570 -> \u6841\
    \ (\u4E0A\u4F4D\u304B\u3089) -> \u6574\u6570\n        {\n            int base\
    \ = rng() % 15 + 2;\n            long long x = rng() % 1000000000000LL;\n    \
    \        std::vector<long long> digits;\n            for (long long y = x; y >\
    \ 0; y /= base) digits.push_back(y % base);\n            std::reverse(digits.begin(),\
    \ digits.end());\n            check(radix_convert(x, base) == digits, \"radix_convert(x,\
    \ base)\");\n            check(radix_convert(digits, base) == x, \"radix_convert(digits,\
    \ base)\");\n        }\n    }\n\n    // \u6C7A\u307E\u3063\u305F\u5024\n    check(radix_convert(123,\
    \ 10) == std::vector<long long>{1, 2, 3}, \"radix_convert(123)\");\n    check(radix_convert(std::vector<long\
    \ long>{1, 0, 1, 1}, 2) == 11, \"radix_convert({1,0,1,1}, 2)\");\n    check(radix_convert(0,\
    \ 10).empty() && radix_convert(std::vector<long long>{}, 10) == 0, \"radix_convert\
    \ 0\");\n    check(iota(0).empty(), \"iota(0)\");\n    check(hamming_distance(std::vector<int>{1,\
    \ 2, 3}, std::vector<int>{1, 0, 0}) == 2, \"hamming_distance \u6C7A\u307E\u3063\
    \u305F\u5024\");\n    check((std::vector<int>{1, 2} | 0).empty(), \"v | 0\");\n\
    \n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// vector_func.hpp \u306E\u6F14\u7B97\u5B50\u3068\u95A2\u6570\u3092\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #include \"../../../src/utility/vector_func.hpp\"\n\n#include <algorithm>\n#include\
    \ <cstdlib>\n#include <functional>\n#include <iostream>\n#include <random>\n#include\
    \ <vector>\n\nbool ok = true;\n\nvoid check(bool cond, const char* what) {\n \
    \   if (!cond) {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n\
    \        ok = false;\n    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    auto rand_vec = [&](int n) {\n        std::vector<long long> v(n);\n    \
    \    for (auto& x : v) x = static_cast<long long>(rng() % 21) - 10;\n        return\
    \ v;\n    };\n\n    for (int rep = 0; rep < 2000 && ok; rep++) {\n        int\
    \ n = rng() % 8, m = rng() % 8;\n        std::vector<long long> a = rand_vec(n),\
    \ b = rand_vec(m);\n        long long c = static_cast<long long>(rng() % 11) -\
    \ 5;\n\n        // ++ / -- (\u524D\u7F6E\u306F\u5909\u66F4\u5F8C\u3001\u5F8C\u7F6E\
    \u306F\u5909\u66F4\u524D\u3092\u8FD4\u3059)\n        {\n            std::vector<long\
    \ long> x = a, inc = a, dec = a;\n            for (auto& e : inc) e++;\n     \
    \       for (auto& e : dec) e--;\n            check(++x == inc && x == inc, \"\
    \u524D\u7F6E ++\");\n            check(x-- == inc && x == a, \"\u5F8C\u7F6E --\"\
    );\n            check(--x == dec && x == dec, \"\u524D\u7F6E --\");\n        \
    \    check(x++ == dec && x == a, \"\u5F8C\u7F6E ++\");\n        }\n\n        //\
    \ \u8981\u7D20\u3054\u3068\u306E\u548C (\u77ED\u3044\u65B9\u306F 0 \u3067\u57CB\
    \u3081\u308B)\n        {\n            std::vector<long long> expect(std::max(n,\
    \ m));\n            for (int i = 0; i < static_cast<int>(expect.size()); i++)\
    \ expect[i] = (i < n ? a[i] : 0) + (i < m ? b[i] : 0);\n            check(a +\
    \ b == expect, \"v + w\");\n            std::vector<long long> x = a;\n      \
    \      x += b;\n            check(x == expect, \"v += w\");\n        }\n\n   \
    \     // \u8981\u7D20\u3054\u3068\u306E\u7A4D (\u3069\u3061\u3089\u304B\u306B\u306A\
    \u3044\u4F4D\u7F6E\u306F 0)\n        {\n            std::vector<long long> expect(std::max(n,\
    \ m));\n            for (int i = 0; i < static_cast<int>(expect.size()); i++)\
    \ expect[i] = (i < n && i < m) ? a[i] * b[i] : 0;\n            check(a * b ==\
    \ expect, \"v * w\");\n            std::vector<long long> x = a;\n           \
    \ x *= b;\n            check(x == expect, \"v *= w\");\n        }\n\n        //\
    \ \u30B9\u30AB\u30E9\u30FC\u3068\u306E\u548C\u30FB\u7A4D\n        {\n        \
    \    std::vector<long long> plus = a, times = a;\n            for (auto& e : plus)\
    \ e += c;\n            for (auto& e : times) e *= c;\n            check(a + c\
    \ == plus && c + a == plus, \"v + c, c + v\");\n            check(a * c == times\
    \ && c * a == times, \"v * c, c * v\");\n            std::vector<long long> x\
    \ = a;\n            x += c;\n            check(x == plus, \"v += c\");\n     \
    \       x = a;\n            x *= c;\n            check(x == times, \"v *= c\"\
    );\n        }\n\n        // \u9023\u7D50\u3068\u7E70\u308A\u8FD4\u3057\n     \
    \   {\n            std::vector<long long> cat = a;\n            cat.insert(cat.end(),\
    \ b.begin(), b.end());\n            std::vector<long long> x = a;\n          \
    \  check(&extend(x, b) == &x && x == cat, \"extend\");\n            x = a;\n \
    \           x |= b;\n            check(x == cat, \"v |= w\");\n            int\
    \ k = rng() % 4;\n            std::vector<long long> rep_k;\n            for (int\
    \ i = 0; i < k; i++) rep_k.insert(rep_k.end(), a.begin(), a.end());\n        \
    \    check((a | k) == rep_k && (k | a) == rep_k, \"v | k, k | v\");\n        \
    \    x = a;\n            x |= k;\n            check(x == rep_k, \"v |= k\");\n\
    \        }\n\n        // assign (\u578B\u306E\u5909\u63DB\u3064\u304D)\n     \
    \   {\n            std::vector<int> small(b.begin(), b.end());\n            std::vector<long\
    \ long> x = a;\n            check(&assign(x, small) == &x && x == b, \"assign\"\
    );\n        }\n\n        // abs\n        {\n            std::vector<long long>\
    \ expect = a;\n            for (auto& e : expect) e = std::llabs(e);\n       \
    \     check(abs(a) == expect, \"abs\");\n        }\n\n        // argsort: \u5024\
    \u306E\u6607\u9806 (\u964D\u9806) \u306B\u5B89\u5B9A\u30BD\u30FC\u30C8\u3057\u305F\
    \u6DFB\u5B57\u306E\u4E26\u3073\n        {\n            for (bool rev : {false,\
    \ true}) {\n                auto idx = rev ? argsort(a, std::greater<>()) : argsort(a);\n\
    \                std::vector<long long> perm = idx;\n                std::sort(perm.begin(),\
    \ perm.end());\n                bool is_perm = static_cast<int>(perm.size()) ==\
    \ n;\n                for (int i = 0; i < static_cast<int>(perm.size()) && is_perm;\
    \ i++) is_perm = perm[i] == i;\n                bool is_sorted = true;\n     \
    \           for (int i = 0; i + 1 < static_cast<int>(idx.size()); i++) {\n   \
    \                 long long x = a[idx[i]], y = a[idx[i + 1]];\n              \
    \      if (rev ? x < y : x > y) is_sorted = false;\n                    if (x\
    \ == y && idx[i] > idx[i + 1]) is_sorted = false;  // \u5B89\u5B9A\n         \
    \       }\n                check(is_perm && is_sorted, \"argsort\");\n       \
    \     }\n        }\n\n        // rank: v[i] \u3088\u308A\u5C0F\u3055\u3044 (\u964D\
    \u9806\u306A\u3089\u5927\u304D\u3044) \u8981\u7D20\u306E\u500B\u6570\n       \
    \ {\n            for (bool rev : {false, true}) {\n                auto r = rev\
    \ ? rank(a, std::greater<>()) : rank(a);\n                bool same = static_cast<int>(r.size())\
    \ == n;\n                for (int i = 0; i < n && same; i++) {\n             \
    \       long long cnt = 0;\n                    for (int j = 0; j < n; j++) cnt\
    \ += rev ? a[j] > a[i] : a[j] < a[i];\n                    same = r[i] == cnt;\n\
    \                }\n                check(same, \"rank\");\n            }\n  \
    \      }\n\n        // inverse_permutation: argsort(argsort(v)) \u3068\u4E00\u81F4\
    \u3057\u3001\u5143\u306E\u7F6E\u63DB\u3068\u5408\u6210\u3059\u308B\u3068\u6052\
    \u7B49\u7F6E\u63DB\n        {\n            auto p = argsort(a);\n            auto\
    \ q = inverse_permutation(p);\n            check(q == argsort(p), \"inverse_permutation\
    \ == argsort(argsort(v))\");\n            bool is_inv = static_cast<int>(q.size())\
    \ == n;\n            for (int i = 0; i < n && is_inv; i++) is_inv = p[q[i]] ==\
    \ i && q[p[i]] == i;\n            check(is_inv, \"inverse_permutation\");\n  \
    \          std::vector<int> pi(p.begin(), p.end());\n            check(inverse_permutation(pi)\
    \ == q, \"inverse_permutation (int)\");\n        }\n\n        // argsort / rank\
    \ (\u5C04\u5F71\u3064\u304D): \u5199\u3057\u305F\u5024\u306E\u5217\u306B\u5BFE\
    \u3059\u308B\u7D50\u679C\u3068\u4E00\u81F4\u3059\u308B\n        {\n          \
    \  auto key = [](long long x) { return x * x; };\n            std::vector<long\
    \ long> b(n);\n            for (int i = 0; i < n; i++) b[i] = key(a[i]);\n   \
    \         check(argsort(a, {}, key) == argsort(b), \"argsort(v, {}, proj)\");\n\
    \            check(argsort(a, std::greater<>(), key) == argsort(b, std::greater<>()),\
    \ \"argsort(v, comp, proj)\");\n            check(rank(a, {}, key) == rank(b),\
    \ \"rank(v, {}, proj)\");\n            check(rank(a, std::greater<>(), key) ==\
    \ rank(b, std::greater<>()), \"rank(v, comp, proj)\");\n            std::vector<std::pair<long\
    \ long, long long>> ps(n);\n            for (int i = 0; i < n; i++) ps[i] = {a[i],\
    \ -i};\n            check(argsort(ps, {}, &std::pair<long long, long long>::first)\
    \ == argsort(a), \"argsort(v, {}, &T::member)\");\n        }\n\n        // select:\
    \ \u6DFB\u5B57\u306E\u5217\u3067\u53D6\u308A\u51FA\u3059\n        {\n        \
    \    std::vector<int> idx(n);\n            for (auto& i : idx) i = static_cast<int>(rng()\
    \ % std::max(n, 1));\n            auto s = select(a, idx);\n            bool ok\
    \ = static_cast<int>(s.size()) == n;\n            for (int i = 0; i < n && ok;\
    \ i++) ok = s[i] == a[idx[i]];\n            check(ok, \"select\");\n         \
    \   std::vector<long long> expect = a;\n            std::sort(expect.begin(),\
    \ expect.end());\n            check(select(a, argsort(a)) == expect, \"select(v,\
    \ argsort(v))\");\n        }\n\n        // hamming_distance (\u540C\u3058\u9577\
    \u3055\u3069\u3046\u3057\u3001\u578B\u304C\u7570\u306A\u3063\u3066\u3082\u3088\
    \u3044)\n        {\n            std::vector<long long> d = rand_vec(n);\n    \
    \        std::vector<int> e(d.begin(), d.end());\n            long long hd = 0;\n\
    \            for (int i = 0; i < n; i++) hd += a[i] != d[i];\n            check(hamming_distance(a,\
    \ d) == hd && hamming_distance(a, e) == hd, \"hamming_distance\");\n        }\n\
    \n        // iota\n        {\n            std::vector<int> expect(n);\n      \
    \      for (int i = 0; i < n; i++) expect[i] = i;\n            check(iota(n) ==\
    \ expect, \"iota\");\n        }\n\n        // radix_convert: \u6574\u6570 -> \u6841\
    \ (\u4E0A\u4F4D\u304B\u3089) -> \u6574\u6570\n        {\n            int base\
    \ = rng() % 15 + 2;\n            long long x = rng() % 1000000000000LL;\n    \
    \        std::vector<long long> digits;\n            for (long long y = x; y >\
    \ 0; y /= base) digits.push_back(y % base);\n            std::reverse(digits.begin(),\
    \ digits.end());\n            check(radix_convert(x, base) == digits, \"radix_convert(x,\
    \ base)\");\n            check(radix_convert(digits, base) == x, \"radix_convert(digits,\
    \ base)\");\n        }\n    }\n\n    // \u6C7A\u307E\u3063\u305F\u5024\n    check(radix_convert(123,\
    \ 10) == std::vector<long long>{1, 2, 3}, \"radix_convert(123)\");\n    check(radix_convert(std::vector<long\
    \ long>{1, 0, 1, 1}, 2) == 11, \"radix_convert({1,0,1,1}, 2)\");\n    check(radix_convert(0,\
    \ 10).empty() && radix_convert(std::vector<long long>{}, 10) == 0, \"radix_convert\
    \ 0\");\n    check(iota(0).empty(), \"iota(0)\");\n    check(hamming_distance(std::vector<int>{1,\
    \ 2, 3}, std::vector<int>{1, 0, 0}) == 2, \"hamming_distance \u6C7A\u307E\u3063\
    \u305F\u5024\");\n    check((std::vector<int>{1, 2} | 0).empty(), \"v | 0\");\n\
    \n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/utility/vector_func.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/utility/vector_func.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 05:46:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/utility/vector_func.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/utility/vector_func.test.cpp
- /verify/test/unittest/utility/vector_func.test.cpp.html
title: test/unittest/utility/vector_func.test.cpp
---
