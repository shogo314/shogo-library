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
  bundledCode: "#line 1 \"test/unittest/vector-func.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// vector_func.hpp\
    \ \u306E\u6F14\u7B97\u5B50\u3068\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n\
    #include <cstdlib>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#line 2 \"src/utility/vector_func.hpp\"\n\n/**\n * @file vector_func.hpp\n *\
    \ @brief vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570\n\
    \ */\n\n#line 9 \"src/utility/vector_func.hpp\"\n#include <cassert>\n#include\
    \ <cmath>\n#include <cstddef>\n#include <numeric>\n#include <type_traits>\n#line\
    \ 15 \"src/utility/vector_func.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\n\n\
    /**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\
    \n#include <iterator>\n#include <set>\n#line 12 \"src/utility/traits.hpp\"\n#include\
    \ <utility>\n\nnamespace internal_traits {\nusing std::begin, std::end;\n\ntemplate\
    \ <class T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace internal_traits\n\
    \ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\
    \n#define HAS_METHOD(func_name)                                              \
    \                \\\n    namespace internal_traits {                         \
    \                                   \\\n    template <class T, class = void> \
    \                                                      \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : internal_traits::has_##func_name##_impl<T>::type {};          \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace internal_traits {     \
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
    \                                          \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ internal_traits {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace internal_traits\ntemplate <class T>\n\
    struct is_sorted_container : internal_traits::is_sorted_container_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 17 \"src/utility/vector_func.hpp\"\n\ntemplate <typename T>\nstd::vector<long\
    \ long> sorted_idx(const std::vector<T>& v, bool reverse = false) {\n    std::vector<long\
    \ long> ret(v.size());\n    std::iota(ret.begin(), ret.end(), 0LL);\n    std::sort(ret.begin(),\
    \ ret.end(), [&](long long i, long long j) {\n        return v[i] < v[j];\n  \
    \  });\n    if (reverse) std::reverse(ret.begin(), ret.end());\n    return ret;\n\
    }\n\ntemplate <typename T>\ninline std::vector<T>& operator++(std::vector<T>&\
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
    \ v, const U& u) {\n    std::vector<T> w(v);\n    v.clear();\n    for (int i =\
    \ 0; i < u; i++) {\n        extend(v, w);\n    }\n    return v;\n}\n\ntemplate\
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
    \ v, int base = 10) {\n    long long res = 0;\n    for (long long d : v) {\n \
    \       res = res * base + d;\n    }\n    return res;\n}\n\ninline std::vector<long\
    \ long> radix_convert(long long v, int base = 10) {\n    std::vector<long long>\
    \ res;\n    while (v > 0) {\n        res.push_back(v % base);\n        v /= base;\n\
    \    }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n#line 13\
    \ \"test/unittest/vector-func.test.cpp\"\n\nbool ok = true;\n\nvoid check(bool\
    \ cond, const char* what) {\n    if (!cond) {\n        if (ok) std::cerr << \"\
    failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\nint main()\
    \ {\n    std::mt19937_64 rng(314);\n    auto rand_vec = [&](int n) {\n       \
    \ std::vector<long long> v(n);\n        for (auto& x : v) x = (long long)(rng()\
    \ % 21) - 10;\n        return v;\n    };\n\n    for (int rep = 0; rep < 2000 &&\
    \ ok; rep++) {\n        int n = rng() % 8, m = rng() % 8;\n        std::vector<long\
    \ long> a = rand_vec(n), b = rand_vec(m);\n        long long c = (long long)(rng()\
    \ % 11) - 5;\n\n        // ++ / -- (\u524D\u7F6E\u306F\u5909\u66F4\u5F8C\u3001\
    \u5F8C\u7F6E\u306F\u5909\u66F4\u524D\u3092\u8FD4\u3059)\n        {\n         \
    \   std::vector<long long> x = a, inc = a, dec = a;\n            for (auto& e\
    \ : inc) e++;\n            for (auto& e : dec) e--;\n            check(++x ==\
    \ inc && x == inc, \"\u524D\u7F6E ++\");\n            check(x-- == inc && x ==\
    \ a, \"\u5F8C\u7F6E --\");\n            check(--x == dec && x == dec, \"\u524D\
    \u7F6E --\");\n            check(x++ == dec && x == a, \"\u5F8C\u7F6E ++\");\n\
    \        }\n\n        // \u8981\u7D20\u3054\u3068\u306E\u548C (\u77ED\u3044\u65B9\
    \u306F 0 \u3067\u57CB\u3081\u308B)\n        {\n            std::vector<long long>\
    \ expect(std::max(n, m));\n            for (int i = 0; i < (int)expect.size();\
    \ i++) expect[i] = (i < n ? a[i] : 0) + (i < m ? b[i] : 0);\n            check(a\
    \ + b == expect, \"v + w\");\n            std::vector<long long> x = a;\n    \
    \        x += b;\n            check(x == expect, \"v += w\");\n        }\n\n \
    \       // \u8981\u7D20\u3054\u3068\u306E\u7A4D (\u3069\u3061\u3089\u304B\u306B\
    \u306A\u3044\u4F4D\u7F6E\u306F 0)\n        {\n            std::vector<long long>\
    \ expect(std::max(n, m));\n            for (int i = 0; i < (int)expect.size();\
    \ i++) expect[i] = (i < n && i < m) ? a[i] * b[i] : 0;\n            check(a *\
    \ b == expect, \"v * w\");\n            std::vector<long long> x = a;\n      \
    \      x *= b;\n            check(x == expect, \"v *= w\");\n        }\n\n   \
    \     // \u30B9\u30AB\u30E9\u30FC\u3068\u306E\u548C\u30FB\u7A4D\n        {\n \
    \           std::vector<long long> plus = a, times = a;\n            for (auto&\
    \ e : plus) e += c;\n            for (auto& e : times) e *= c;\n            check(a\
    \ + c == plus && c + a == plus, \"v + c, c + v\");\n            check(a * c ==\
    \ times && c * a == times, \"v * c, c * v\");\n            std::vector<long long>\
    \ x = a;\n            x += c;\n            check(x == plus, \"v += c\");\n   \
    \         x = a;\n            x *= c;\n            check(x == times, \"v *= c\"\
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
    \     check(abs(a) == expect, \"abs\");\n        }\n\n        // sorted_idx: \u5024\
    \u306E\u6607\u9806 (\u964D\u9806) \u306B\u4E26\u3079\u305F\u6DFB\u5B57\u306E\u4E26\
    \u3073\u66FF\u3048\n        {\n            for (bool rev : {false, true}) {\n\
    \                auto idx = sorted_idx(a, rev);\n                std::vector<long\
    \ long> perm = idx;\n                std::sort(perm.begin(), perm.end());\n  \
    \              bool is_perm = (int)perm.size() == n;\n                for (int\
    \ i = 0; i < (int)perm.size() && is_perm; i++) is_perm = perm[i] == i;\n     \
    \           bool is_sorted = true;\n                for (int i = 0; i + 1 < (int)idx.size();\
    \ i++) {\n                    if (rev ? a[idx[i]] < a[idx[i + 1]] : a[idx[i]]\
    \ > a[idx[i + 1]]) is_sorted = false;\n                }\n                check(is_perm\
    \ && is_sorted, \"sorted_idx\");\n            }\n        }\n\n        // hamming_distance\
    \ (\u540C\u3058\u9577\u3055\u3069\u3046\u3057\u3001\u578B\u304C\u7570\u306A\u3063\
    \u3066\u3082\u3088\u3044)\n        {\n            std::vector<long long> d = rand_vec(n);\n\
    \            std::vector<int> e(d.begin(), d.end());\n            long long hd\
    \ = 0;\n            for (int i = 0; i < n; i++) hd += a[i] != d[i];\n        \
    \    check(hamming_distance(a, d) == hd && hamming_distance(a, e) == hd, \"hamming_distance\"\
    );\n        }\n\n        // iota\n        {\n            std::vector<int> expect(n);\n\
    \            for (int i = 0; i < n; i++) expect[i] = i;\n            check(iota(n)\
    \ == expect, \"iota\");\n        }\n\n        // radix_convert: \u6574\u6570 ->\
    \ \u6841 (\u4E0A\u4F4D\u304B\u3089) -> \u6574\u6570\n        {\n            int\
    \ base = rng() % 15 + 2;\n            long long x = rng() % 1000000000000LL;\n\
    \            std::vector<long long> digits;\n            for (long long y = x;\
    \ y > 0; y /= base) digits.push_back(y % base);\n            std::reverse(digits.begin(),\
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
    #include <algorithm>\n#include <cstdlib>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#include \"../../src/utility/vector_func.hpp\"\n\nbool ok\
    \ = true;\n\nvoid check(bool cond, const char* what) {\n    if (!cond) {\n   \
    \     if (ok) std::cerr << \"failed: \" << what << std::endl;\n        ok = false;\n\
    \    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n    auto rand_vec =\
    \ [&](int n) {\n        std::vector<long long> v(n);\n        for (auto& x : v)\
    \ x = (long long)(rng() % 21) - 10;\n        return v;\n    };\n\n    for (int\
    \ rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 8, m = rng() %\
    \ 8;\n        std::vector<long long> a = rand_vec(n), b = rand_vec(m);\n     \
    \   long long c = (long long)(rng() % 11) - 5;\n\n        // ++ / -- (\u524D\u7F6E\
    \u306F\u5909\u66F4\u5F8C\u3001\u5F8C\u7F6E\u306F\u5909\u66F4\u524D\u3092\u8FD4\
    \u3059)\n        {\n            std::vector<long long> x = a, inc = a, dec = a;\n\
    \            for (auto& e : inc) e++;\n            for (auto& e : dec) e--;\n\
    \            check(++x == inc && x == inc, \"\u524D\u7F6E ++\");\n           \
    \ check(x-- == inc && x == a, \"\u5F8C\u7F6E --\");\n            check(--x ==\
    \ dec && x == dec, \"\u524D\u7F6E --\");\n            check(x++ == dec && x ==\
    \ a, \"\u5F8C\u7F6E ++\");\n        }\n\n        // \u8981\u7D20\u3054\u3068\u306E\
    \u548C (\u77ED\u3044\u65B9\u306F 0 \u3067\u57CB\u3081\u308B)\n        {\n    \
    \        std::vector<long long> expect(std::max(n, m));\n            for (int\
    \ i = 0; i < (int)expect.size(); i++) expect[i] = (i < n ? a[i] : 0) + (i < m\
    \ ? b[i] : 0);\n            check(a + b == expect, \"v + w\");\n            std::vector<long\
    \ long> x = a;\n            x += b;\n            check(x == expect, \"v += w\"\
    );\n        }\n\n        // \u8981\u7D20\u3054\u3068\u306E\u7A4D (\u3069\u3061\
    \u3089\u304B\u306B\u306A\u3044\u4F4D\u7F6E\u306F 0)\n        {\n            std::vector<long\
    \ long> expect(std::max(n, m));\n            for (int i = 0; i < (int)expect.size();\
    \ i++) expect[i] = (i < n && i < m) ? a[i] * b[i] : 0;\n            check(a *\
    \ b == expect, \"v * w\");\n            std::vector<long long> x = a;\n      \
    \      x *= b;\n            check(x == expect, \"v *= w\");\n        }\n\n   \
    \     // \u30B9\u30AB\u30E9\u30FC\u3068\u306E\u548C\u30FB\u7A4D\n        {\n \
    \           std::vector<long long> plus = a, times = a;\n            for (auto&\
    \ e : plus) e += c;\n            for (auto& e : times) e *= c;\n            check(a\
    \ + c == plus && c + a == plus, \"v + c, c + v\");\n            check(a * c ==\
    \ times && c * a == times, \"v * c, c * v\");\n            std::vector<long long>\
    \ x = a;\n            x += c;\n            check(x == plus, \"v += c\");\n   \
    \         x = a;\n            x *= c;\n            check(x == times, \"v *= c\"\
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
    \     check(abs(a) == expect, \"abs\");\n        }\n\n        // sorted_idx: \u5024\
    \u306E\u6607\u9806 (\u964D\u9806) \u306B\u4E26\u3079\u305F\u6DFB\u5B57\u306E\u4E26\
    \u3073\u66FF\u3048\n        {\n            for (bool rev : {false, true}) {\n\
    \                auto idx = sorted_idx(a, rev);\n                std::vector<long\
    \ long> perm = idx;\n                std::sort(perm.begin(), perm.end());\n  \
    \              bool is_perm = (int)perm.size() == n;\n                for (int\
    \ i = 0; i < (int)perm.size() && is_perm; i++) is_perm = perm[i] == i;\n     \
    \           bool is_sorted = true;\n                for (int i = 0; i + 1 < (int)idx.size();\
    \ i++) {\n                    if (rev ? a[idx[i]] < a[idx[i + 1]] : a[idx[i]]\
    \ > a[idx[i + 1]]) is_sorted = false;\n                }\n                check(is_perm\
    \ && is_sorted, \"sorted_idx\");\n            }\n        }\n\n        // hamming_distance\
    \ (\u540C\u3058\u9577\u3055\u3069\u3046\u3057\u3001\u578B\u304C\u7570\u306A\u3063\
    \u3066\u3082\u3088\u3044)\n        {\n            std::vector<long long> d = rand_vec(n);\n\
    \            std::vector<int> e(d.begin(), d.end());\n            long long hd\
    \ = 0;\n            for (int i = 0; i < n; i++) hd += a[i] != d[i];\n        \
    \    check(hamming_distance(a, d) == hd && hamming_distance(a, e) == hd, \"hamming_distance\"\
    );\n        }\n\n        // iota\n        {\n            std::vector<int> expect(n);\n\
    \            for (int i = 0; i < n; i++) expect[i] = i;\n            check(iota(n)\
    \ == expect, \"iota\");\n        }\n\n        // radix_convert: \u6574\u6570 ->\
    \ \u6841 (\u4E0A\u4F4D\u304B\u3089) -> \u6574\u6570\n        {\n            int\
    \ base = rng() % 15 + 2;\n            long long x = rng() % 1000000000000LL;\n\
    \            std::vector<long long> digits;\n            for (long long y = x;\
    \ y > 0; y /= base) digits.push_back(y % base);\n            std::reverse(digits.begin(),\
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
  path: test/unittest/vector-func.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 23:17:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/vector-func.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/vector-func.test.cpp
- /verify/test/unittest/vector-func.test.cpp.html
title: test/unittest/vector-func.test.cpp
---
