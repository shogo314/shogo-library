---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/io.hpp
    title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\
      \u30D0\u30FC\u30ED\u30FC\u30C9"
  - icon: ':heavy_check_mark:'
    path: src/math/convolution.hpp
    title: "\u7573\u307F\u8FBC\u307F (NTT)"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
      \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)"
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_2_64
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_2_64
  bundledCode: "#line 1 \"test/yosupo/convolution-mod-2-64.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod_2_64\"\n\n#line 2 \"src/base/io.hpp\"\
    \n/**\n * @file io.hpp\n * @brief \u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001\
    iostream\u306E\u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\n */\n\n#include <array>\n\
    #include <cstddef>\n#include <iostream>\n#include <set>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n// \u30CD\u30B9\u30C8\u3057\u305F\u578B (pair<vector<int>,\
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
    \ << x << ' ';\n    err(tail...);\n}\n#line 2 \"src/math/convolution.hpp\"\n\n\
    /**\n * @file convolution.hpp\n * @brief \u7573\u307F\u8FBC\u307F (NTT)\n */\n\
    \n#include <algorithm>\n#line 11 \"src/math/convolution.hpp\"\n\n#line 2 \"src/math/modint.hpp\"\
    \n\n/**\n * @file modint.hpp\n * @brief \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\
    \u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n */\n\n#include\
    \ <cassert>\n#include <cstdint>\n#line 11 \"src/math/modint.hpp\"\n#include <limits>\n\
    #include <type_traits>\n#line 14 \"src/math/modint.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"\
    src/utility/traits.hpp\"\n#include <iterator>\n#line 13 \"src/utility/traits.hpp\"\
    \n\nnamespace internal_traits {\nusing std::begin, std::end;\n\ntemplate <class\
    \ T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate <class\
    \ T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    using modint = dynamic_modint<-1>;\n#line 2 \"src/math/modular-arithmetic.hpp\"\
    \n\n/**\n * @file modular-arithmetic.hpp\n * @brief mod \u6F14\u7B97 (\u7A4D\u3001\
    \u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\u6563\u5BFE\u6570\u3001\u5E73\u65B9\
    \u6839)\n */\n\n#line 10 \"src/math/modular-arithmetic.hpp\"\n#include <cmath>\n\
    #include <numeric>\n#include <unordered_map>\n\n/**\n * @brief a * b mod m \u3092\
    \u8FD4\u3059 (\u9014\u4E2D\u3067 __int128 \u3092\u4F7F\u3046\u306E\u3067 m < 2^63\
    \ \u306A\u3089\u3042\u3075\u308C\u306A\u3044)\n */\nconstexpr long long modmul(long\
    \ long a, long long b, long long m) {\n    long long res = static_cast<long long>(static_cast<__int128>(a)\
    \ * b % m);\n    if (res < 0) res += m;\n    return res;\n}\n\n/**\n * @brief\
    \ a^(-1) mod m \u3092\u8FD4\u3059\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\
    \u7D20\u3067\u3042\u308B\u3053\u3068\u3002O(log m)\n */\nconstexpr long long modinv(long\
    \ long a, long long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a +=\
    \ m;\n    long long b = m, u = 1, v = 0;\n    while (b) {\n        // std::swap\
    \ \u306F C++17 \u3067\u306F constexpr \u3067\u306A\u3044\u306E\u3067\u3001\u4F7F\
    \u308F\u305A\u306B\u66F8\u304F\n        long long t = a / b;\n        long long\
    \ c = a - t * b;\n        a = b, b = c;\n        long long w = u - t * v;\n  \
    \      u = v, v = w;\n    }\n    assert(a == 1 && \"a and m must be coprime\"\
    );\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n}\n\n/**\n * @brief a^n\
    \ mod m \u3092\u8FD4\u3059\n * @note n \u304C\u8CA0\u306A\u3089 a^(-1) \u306E\
    \ -n \u4E57 (a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\
    \u3068)\u3002O(log |n|)\n */\nconstexpr long long modpow(long long a, long long\
    \ n, long long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n\
    \    if (n < 0) {\n        n = -n;\n        a = modinv(a, m);\n    }\n    long\
    \ long res = 1 % m;\n    while (n > 0) {\n        if (n & 1) res = modmul(res,\
    \ a, m);\n        a = modmul(a, a, m);\n        n >>= 1;\n    }\n    return res;\n\
    }\n\n/**\n * @brief a^x \u2261 b (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E\
    \ x >= 0 (\u306A\u3051\u308C\u3070 -1)\n * @note a \u3068 m \u306F\u4E92\u3044\
    \u306B\u7D20\u3067\u306A\u304F\u3066\u3082\u3088\u3044\u3002Baby-step Giant-step\
    \ \u3067 O(\u221Am) \u306E\u6642\u9593\u3068\u30E1\u30E2\u30EA\n */\ninline long\
    \ long discrete_log(long long a, long long b, long long m) {\n    assert(m >=\
    \ 1);\n    a %= m, b %= m;\n    if (a < 0) a += m;\n    if (b < 0) b += m;\n \
    \   if (m == 1) return 0;\n    // a \u3068 m \u304C\u4E92\u3044\u306B\u7D20\u306B\
    \u306A\u308B\u307E\u3067\u4E21\u8FBA\u3092 gcd \u3067\u5272\u308B\u3002k = a^add\
    \ / (\u5272\u3063\u305F gcd \u306E\u7A4D) mod m\n    long long k = 1, add = 0,\
    \ g;\n    while ((g = std::gcd(a, m)) > 1) {\n        if (b == k) return add;\n\
    \        if (b % g != 0) return -1;\n        b /= g, m /= g, add++;\n        k\
    \ = modmul(k, a / g, m);\n    }\n    // k a^x \u2261 b \u3092 x = n p - q (1 <=\
    \ p <= n\u30010 <= q <= n) \u3068\u66F8\u3044\u3066\u89E3\u304F\n    const long\
    \ long n = static_cast<long long>(std::sqrt(static_cast<long double>(m))) + 1;\n\
    \    std::unordered_map<long long, long long> baby;\n    baby.reserve(2 * n +\
    \ 2);\n    // b a^q \u3092 q \u306E\u5C0F\u3055\u3044\u9806\u306B\u5165\u308C\u3001\
    \u540C\u3058\u5024\u306A\u3089\u5927\u304D\u3044 q \u3067\u4E0A\u66F8\u304D\u3059\
    \u308B (x \u3092\u5C0F\u3055\u304F\u3059\u308B\u305F\u3081)\n    for (long long\
    \ q = 0, cur = b; q <= n; q++, cur = modmul(cur, a, m)) baby[cur] = q;\n    const\
    \ long long an = modpow(a, n, m);\n    for (long long p = 1, cur = k; p <= n;\
    \ p++) {\n        cur = modmul(cur, an, m);\n        auto it = baby.find(cur);\n\
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
    \    }\n    return std::min(r, p - r);\n}\n#line 14 \"src/math/convolution.hpp\"\
    \n\n/**\n * @brief \u7573\u307F\u8FBC\u307F\n */\nnamespace internal_convolution\
    \ {\n/**\n * @brief \u539F\u5B50\u6839\n * @param MOD int\n * @return int\n */\n\
    inline int calc_primitive_root(int MOD) {\n    if (MOD == 2) return 1;\n    if\
    \ (MOD == 167772161) return 3;\n    if (MOD == 469762049) return 3;\n    if (MOD\
    \ == 754974721) return 11;\n    if (MOD == 998244353) return 3;\n    int divs[20]\
    \ = {};\n    divs[0] = 2;\n    int cnt = 1;\n    long long x = (MOD - 1) >> 1;\n\
    \    while (x % 2 == 0) x >>= 1;\n    for (long long i = 3; i * i <= x; i += 2)\
    \ {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n            while\
    \ (x % i == 0) x /= i;\n        }\n    }\n    if (x > 1) divs[cnt++] = x;\n  \
    \  for (int g = 2;; ++g) {\n        bool ok = true;\n        for (int i = 0; i\
    \ < cnt; i++) {\n            if (modpow(g, (MOD - 1) / divs[i], MOD) == 1) {\n\
    \                ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) return g;\n    }\n}\n\n/**\n * @brief \u7573\u307F\u8FBC\u307F\
    \u306E\u30B5\u30A4\u30BA\u30922\u306E\u3079\u304D\u4E57\u306B\u3059\u308B\n */\n\
    inline int get_fft_size(int N, int M) {\n    int size = 1;\n    while (size <\
    \ N + M - 1) size <<= 1;\n    return size;\n}\n\n/**\n * @brief NTT\n */\ntemplate\
    \ <class mint>\nvoid trans(std::vector<mint>& v, bool inv = false) {\n    if (v.empty())\
    \ return;\n    int N = static_cast<int>(v.size());\n    int MOD = v[0].mod();\n\
    \    int PR = calc_primitive_root(MOD);\n    static bool first = true;\n    static\
    \ std::vector<long long> vbw(30), vibw(30);\n    if (first) {\n        first =\
    \ false;\n        for (int k = 0; k < 30; ++k) {\n            vbw[k] = modpow(PR,\
    \ (MOD - 1) >> (k + 1), MOD);\n            vibw[k] = modinv(vbw[k], MOD);\n  \
    \      }\n    }\n    for (int i = 0, j = 1; j < N - 1; ++j) {\n        for (int\
    \ k = N >> 1; k > (i ^= k); k >>= 1);\n        if (i > j) std::swap(v[i], v[j]);\n\
    \    }\n    for (int k = 0, t = 2; t <= N; ++k, t <<= 1) {\n        long long\
    \ bw = vbw[k];\n        if (inv) bw = vibw[k];\n        for (int i = 0; i < N;\
    \ i += t) {\n            mint w = 1;\n            for (int j = 0; j < (t >> 1);\
    \ ++j) {\n                int j1 = i + j, j2 = i + j + (t >> 1);\n           \
    \     mint c1 = v[j1], c2 = v[j2] * w;\n                v[j1] = c1 + c2;\n   \
    \             v[j2] = c1 - c2;\n                w *= bw;\n            }\n    \
    \    }\n    }\n    if (inv) {\n        long long invN = modinv(N, MOD);\n    \
    \    for (int i = 0; i < N; ++i) v[i] = v[i] * invN;\n    }\n}\n\nstatic constexpr\
    \ int MOD0 = 754974721;\nstatic constexpr int MOD1 = 167772161;\nstatic constexpr\
    \ int MOD2 = 469762049;\nusing mint0 = static_modint<MOD0>;\nusing mint1 = static_modint<MOD1>;\n\
    using mint2 = static_modint<MOD2>;\nstatic const mint1 imod0 = 95869806;    //\
    \ modinv(MOD0, MOD1);\nstatic const mint2 imod1 = 104391568;   // modinv(MOD1,\
    \ MOD2);\nstatic const mint2 imod01 = 187290749;  // imod1 / MOD0;\n\n/**\n *\
    \ @brief \u914D\u5217\u306E\u30B5\u30A4\u30BA\u304C\u5C0F\u3055\u3044\u3068\u304D\
    \u306E\u7573\u307F\u8FBC\u307F\n * @param T mint, long long\n * @param A vector<T>\n\
    \ * @param B vector<T>\n * @return vector<T>\n */\ntemplate <class T>\nstd::vector<T>\
    \ naive(const std::vector<T>& A, const std::vector<T>& B) {\n    if (A.empty()\
    \ || B.empty()) return {};\n    int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    std::vector<T> res(N + M - 1);\n    for (int i = 0; i < N; ++i)\n       \
    \ for (int j = 0; j < M; ++j)\n            res[i + j] += A[i] * B[j];\n    return\
    \ res;\n}\n};  // namespace internal_convolution\n\n/**\n * @brief modint\u306E\
    \u7573\u307F\u8FBC\u307F\n * @param A vector<mint>\n * @param B vector<mint>\n\
    \ * @return vector<mint>\n */\ntemplate <class mint>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& A, const std::vector<mint>& B) {\n    if (A.empty() || B.empty())\
    \ return {};\n    int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    if (std::min(N, M) < 30) return internal_convolution::naive(A, B);\n    int\
    \ MOD = A[0].mod();\n    int size_fft = internal_convolution::get_fft_size(N,\
    \ M);\n    if (MOD == 998244353) {\n        std::vector<mint> a(size_fft), b(size_fft),\
    \ c(size_fft);\n        for (int i = 0; i < N; ++i) a[i] = A[i];\n        for\
    \ (int i = 0; i < M; ++i) b[i] = B[i];\n        internal_convolution::trans(a),\
    \ internal_convolution::trans(b);\n        std::vector<mint> res(size_fft);\n\
    \        for (int i = 0; i < size_fft; ++i) res[i] = a[i] * b[i];\n        internal_convolution::trans(res,\
    \ true);\n        res.resize(N + M - 1);\n        return res;\n    }\n    std::vector<internal_convolution::mint0>\
    \ a0(size_fft, 0), b0(size_fft, 0), c0(size_fft, 0);\n    std::vector<internal_convolution::mint1>\
    \ a1(size_fft, 0), b1(size_fft, 0), c1(size_fft, 0);\n    std::vector<internal_convolution::mint2>\
    \ a2(size_fft, 0), b2(size_fft, 0), c2(size_fft, 0);\n    for (int i = 0; i <\
    \ N; ++i) {\n        a0[i] = A[i].val();\n        a1[i] = A[i].val();\n      \
    \  a2[i] = A[i].val();\n    }\n    for (int i = 0; i < M; ++i) {\n        b0[i]\
    \ = B[i].val();\n        b1[i] = B[i].val();\n        b2[i] = B[i].val();\n  \
    \  }\n    internal_convolution::trans(a0), internal_convolution::trans(a1), internal_convolution::trans(a2),\n\
    \        internal_convolution::trans(b0), internal_convolution::trans(b1), internal_convolution::trans(b2);\n\
    \    for (int i = 0; i < size_fft; ++i) {\n        c0[i] = a0[i] * b0[i];\n  \
    \      c1[i] = a1[i] * b1[i];\n        c2[i] = a2[i] * b2[i];\n    }\n    internal_convolution::trans(c0,\
    \ true), internal_convolution::trans(c1, true), internal_convolution::trans(c2,\
    \ true);\n    const mint mod0 = internal_convolution::MOD0, mod01 = mod0 * internal_convolution::MOD1;\n\
    \    std::vector<mint> res(N + M - 1);\n    for (int i = 0; i < N + M - 1; ++i)\
    \ {\n        int y0 = c0[i].val();\n        int y1 = (internal_convolution::imod0\
    \ * (c1[i] - y0)).val();\n        int y2 = (internal_convolution::imod01 * (c2[i]\
    \ - y0) - internal_convolution::imod1 * y1).val();\n        res[i] = mod01 * y2\
    \ + mod0 * y1 + y0;\n    }\n    return res;\n}\n\n/**\n * @brief long long\u306E\
    \u7573\u307F\u8FBC\u307F\n * @param A vector<long long>\n * @param B vector<long\
    \ long>\n * @return vector<long long>\n */\ninline std::vector<long long> convolution_ll(const\
    \ std::vector<long long>& A, const std::vector<long long>& B) {\n    if (A.empty()\
    \ || B.empty()) return {};\n    int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    if (std::min(N, M) < 30) return internal_convolution::naive(A, B);\n    int\
    \ size_fft = internal_convolution::get_fft_size(N, M);\n    std::vector<internal_convolution::mint0>\
    \ a0(size_fft, 0), b0(size_fft, 0), c0(size_fft, 0);\n    std::vector<internal_convolution::mint1>\
    \ a1(size_fft, 0), b1(size_fft, 0), c1(size_fft, 0);\n    std::vector<internal_convolution::mint2>\
    \ a2(size_fft, 0), b2(size_fft, 0), c2(size_fft, 0);\n    for (int i = 0; i <\
    \ N; ++i) {\n        a0[i] = A[i];\n        a1[i] = A[i];\n        a2[i] = A[i];\n\
    \    }\n    for (int i = 0; i < M; ++i) {\n        b0[i] = B[i];\n        b1[i]\
    \ = B[i];\n        b2[i] = B[i];\n    }\n    internal_convolution::trans(a0),\
    \ internal_convolution::trans(a1), internal_convolution::trans(a2),\n        internal_convolution::trans(b0),\
    \ internal_convolution::trans(b1), internal_convolution::trans(b2);\n    for (int\
    \ i = 0; i < size_fft; ++i) {\n        c0[i] = a0[i] * b0[i];\n        c1[i] =\
    \ a1[i] * b1[i];\n        c2[i] = a2[i] * b2[i];\n    }\n    internal_convolution::trans(c0,\
    \ true), internal_convolution::trans(c1, true), internal_convolution::trans(c2,\
    \ true);\n    static const long long mod0 = internal_convolution::MOD0, mod01\
    \ = mod0 * internal_convolution::MOD1;\n    static const __int128_t mod012 = static_cast<__int128_t>(mod01)\
    \ * internal_convolution::MOD2;\n    std::vector<long long> res(N + M - 1);\n\
    \    for (int i = 0; i < N + M - 1; ++i) {\n        int y0 = c0[i].val();\n  \
    \      int y1 = (internal_convolution::imod0 * (c1[i] - y0)).val();\n        int\
    \ y2 = (internal_convolution::imod01 * (c2[i] - y0) - internal_convolution::imod1\
    \ * y1).val();\n        __int128_t tmp = static_cast<__int128_t>(mod01) * y2 +\
    \ static_cast<__int128_t>(mod0) * y1 + y0;\n        if (tmp < (mod012 >> 1))\n\
    \            res[i] = tmp;\n        else\n            res[i] = tmp - mod012;\n\
    \    }\n    return res;\n}\n#line 5 \"test/yosupo/convolution-mod-2-64.test.cpp\"\
    \n\nint main(void) {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<long\
    \ long> a0(n), a1(n), a2(n), b0(m), b1(m), b2(m);\n    for (int i = 0; i < n;\
    \ i++) {\n        unsigned long long a;\n        std::cin >> a;\n        a0[i]\
    \ = a & ((1ULL << 31) - 1);\n        a1[i] = a >> 31 & ((1ULL << 31) - 1);\n \
    \       a2[i] = a >> 62;\n    }\n    for (int i = 0; i < m; i++) {\n        unsigned\
    \ long long b;\n        std::cin >> b;\n        b0[i] = b & ((1ULL << 31) - 1);\n\
    \        b1[i] = b >> 31 & ((1ULL << 31) - 1);\n        b2[i] = b >> 62;\n   \
    \ }\n    std::vector<unsigned long long> c(n + m - 1);\n    std::vector<long long>\
    \ c00 = convolution_ll(a0, b0);\n    for (int i = 0; i < n + m - 1; i++) {\n \
    \       c[i] += static_cast<unsigned long long>(c00[i]);\n    }\n    std::vector<long\
    \ long> c01 = convolution_ll(a0, b1);\n    for (int i = 0; i < n + m - 1; i++)\
    \ {\n        c[i] += static_cast<unsigned long long>(c01[i]) << 31;\n    }\n \
    \   std::vector<long long> c02 = convolution_ll(a0, b2);\n    for (int i = 0;\
    \ i < n + m - 1; i++) {\n        c[i] += static_cast<unsigned long long>(c02[i])\
    \ << 62;\n    }\n    std::vector<long long> c10 = convolution_ll(a1, b0);\n  \
    \  for (int i = 0; i < n + m - 1; i++) {\n        c[i] += static_cast<unsigned\
    \ long long>(c10[i]) << 31;\n    }\n    std::vector<long long> c11 = convolution_ll(a1,\
    \ b1);\n    for (int i = 0; i < n + m - 1; i++) {\n        c[i] += static_cast<unsigned\
    \ long long>(c11[i]) << 62;\n    }\n    std::vector<long long> c20 = convolution_ll(a2,\
    \ b0);\n    for (int i = 0; i < n + m - 1; i++) {\n        c[i] += static_cast<unsigned\
    \ long long>(c20[i]) << 62;\n    }\n    std::cout << c << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_2_64\"\n\
    \n#include \"../../src/base/io.hpp\"\n#include \"../../src/math/convolution.hpp\"\
    \n\nint main(void) {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<long\
    \ long> a0(n), a1(n), a2(n), b0(m), b1(m), b2(m);\n    for (int i = 0; i < n;\
    \ i++) {\n        unsigned long long a;\n        std::cin >> a;\n        a0[i]\
    \ = a & ((1ULL << 31) - 1);\n        a1[i] = a >> 31 & ((1ULL << 31) - 1);\n \
    \       a2[i] = a >> 62;\n    }\n    for (int i = 0; i < m; i++) {\n        unsigned\
    \ long long b;\n        std::cin >> b;\n        b0[i] = b & ((1ULL << 31) - 1);\n\
    \        b1[i] = b >> 31 & ((1ULL << 31) - 1);\n        b2[i] = b >> 62;\n   \
    \ }\n    std::vector<unsigned long long> c(n + m - 1);\n    std::vector<long long>\
    \ c00 = convolution_ll(a0, b0);\n    for (int i = 0; i < n + m - 1; i++) {\n \
    \       c[i] += static_cast<unsigned long long>(c00[i]);\n    }\n    std::vector<long\
    \ long> c01 = convolution_ll(a0, b1);\n    for (int i = 0; i < n + m - 1; i++)\
    \ {\n        c[i] += static_cast<unsigned long long>(c01[i]) << 31;\n    }\n \
    \   std::vector<long long> c02 = convolution_ll(a0, b2);\n    for (int i = 0;\
    \ i < n + m - 1; i++) {\n        c[i] += static_cast<unsigned long long>(c02[i])\
    \ << 62;\n    }\n    std::vector<long long> c10 = convolution_ll(a1, b0);\n  \
    \  for (int i = 0; i < n + m - 1; i++) {\n        c[i] += static_cast<unsigned\
    \ long long>(c10[i]) << 31;\n    }\n    std::vector<long long> c11 = convolution_ll(a1,\
    \ b1);\n    for (int i = 0; i < n + m - 1; i++) {\n        c[i] += static_cast<unsigned\
    \ long long>(c11[i]) << 62;\n    }\n    std::vector<long long> c20 = convolution_ll(a2,\
    \ b0);\n    for (int i = 0; i < n + m - 1; i++) {\n        c[i] += static_cast<unsigned\
    \ long long>(c20[i]) << 62;\n    }\n    std::cout << c << std::endl;\n}\n"
  dependsOn:
  - src/base/io.hpp
  - src/math/convolution.hpp
  - src/math/modint.hpp
  - src/utility/traits.hpp
  - src/math/modular-arithmetic.hpp
  isVerificationFile: true
  path: test/yosupo/convolution-mod-2-64.test.cpp
  requiredBy: []
  timestamp: '2026-10-20 17:15:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution-mod-2-64.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution-mod-2-64.test.cpp
- /verify/test/yosupo/convolution-mod-2-64.test.cpp.html
title: test/yosupo/convolution-mod-2-64.test.cpp
---
