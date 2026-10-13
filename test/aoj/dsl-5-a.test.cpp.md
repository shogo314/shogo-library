---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/acted-monoid.hpp
    title: "\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/base/functions.hpp
    title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax, \u4E8C\u5206\u63A2\u7D22\u306A\
      \u3069)"
  - icon: ':heavy_check_mark:'
    path: src/base/traits.hpp
    title: "\u578B\u7279\u6027"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/imos.hpp
    title: "imos\u6CD5\u3067\u533A\u9593\u4F5C\u7528\u30011\u70B9\u53D6\u5F97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
  bundledCode: "#line 1 \"test/aoj/dsl-5-a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n\n#include <iostream>\n\n#line 2 \"src/base/functions.hpp\"\n\n/**\n * @file\
    \ functions.hpp\n * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax, \u4E8C\u5206\
    \u63A2\u7D22\u306A\u3069)\n */\n\n#include <algorithm>\n#include <array>\n#include\
    \ <cmath>\n#include <numeric>\n#line 2 \"src/base/traits.hpp\"\n\n/**\n * @file\
    \ traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n#include\
    \ <iterator>\n#include <set>\n#include <type_traits>\n#include <utility>\n\nnamespace\
    \ detail {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\n\
    struct is_range_impl : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T,\
    \ std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>> :\
    \ std::true_type {};\n}  // namespace detail\n\ntemplate <class T>\nstruct is_range\
    \ : detail::is_range_impl<T>::type {};\ntemplate <class T>\ninline constexpr bool\
    \ is_range_v = is_range<T>::value;\n\n#define HAS_METHOD(func_name)          \
    \                                                    \\\n    namespace detail\
    \ {                                                                     \\\n \
    \   template <class T, class = void>                                         \
    \              \\\n    struct has_##func_name##_impl : std::false_type {};   \
    \                                 \\\n    template <class T>                 \
    \                                                    \\\n    struct has_##func_name##_impl<T,\
    \ std::void_t<decltype(std::declval<T>().func_name())>> \\\n        : std::true_type\
    \ {};                                                               \\\n    }\
    \                                                                            \
    \          \\\n    template <class T>                                        \
    \                             \\\n    struct has_##func_name : detail::has_##func_name##_impl<T>::type\
    \ {};                   \\\n    template <class T>                           \
    \                                          \\\n    inline constexpr bool has_##func_name##_v\
    \ = has_##func_name<T>::value;\n\n#define HAS_METHOD_ARG(func_name)          \
    \                                                                    \\\n    namespace\
    \ detail {                                                                   \
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
    \                                    \\\n    struct has_##func_name : detail::has_##func_name##_impl<T,\
    \ U>::type {};                                    \\\n    template <class T, typename\
    \ U>                                                                         \
    \    \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ detail {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace detail\ntemplate <class T>\nstruct is_sorted_container\
    \ : detail::is_sorted_container_impl<T>::type {};\ntemplate <class T>\ninline\
    \ constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n#line\
    \ 13 \"src/base/functions.hpp\"\n\ntemplate <typename T1, typename T2>\ninline\
    \ constexpr bool chmin(T1 &a, T2 b) {\n    if (a > b) {\n        a = b;\n    \
    \    return true;\n    }\n    return false;\n}\n\ntemplate <typename T1, typename\
    \ T2>\ninline constexpr bool chmax(T1 &a, T2 b) {\n    if (a < b) {\n        a\
    \ = b;\n        return true;\n    }\n    return false;\n}\n\ninline constexpr\
    \ long long max(const long long &t1, const long long &t2) {\n    return std::max<long\
    \ long>(t1, t2);\n}\n\ninline constexpr long long min(const long long &t1, const\
    \ long long &t2) {\n    return std::min<long long>(t1, t2);\n}\n\nusing std::abs;\n\
    using std::gcd;\nusing std::lcm;\nusing std::size;\n\ntemplate <typename T>\n\
    constexpr T extgcd(const T &a, const T &b, T &x, T &y) {\n    T d = a;\n    if\
    \ (b != 0) {\n        d = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n\
    \    } else {\n        x = 1;\n        y = 0;\n    }\n    return d;\n}\n\n/**\n\
    \ * \u504F\u89D2\u30BD\u30FC\u30C8\n * \u53CD\u6642\u8A08\u56DE\u308A\n * x \u8EF8\
    \u6B63\u65B9\u5411\u3092\u59CB\u70B9\u3068\u3057\u3001\u96F6\u30D9\u30AF\u30C8\
    \u30EB\u306F x \u8EF8\u6B63\u65B9\u5411\u3068\u540C\u3058\u504F\u89D2\u3068\u3057\
    \u3066\u6271\u3046\n */\ntemplate <typename T, ENABLE_IF_T(std::is_integral_v<T>)>\n\
    bool argcmp(std::array<T, 2> a, std::array<T, 2> b) {\n    // \u96F6\u30D9\u30AF\
    \u30C8\u30EB\u306F\u5916\u7A4D\u3067\u6BD4\u3079\u3089\u308C\u306A\u3044\u306E\
    \u3067\u3001\u504F\u89D2 0 (x \u8EF8\u6B63\u65B9\u5411) \u3068\u3057\u3066\u5148\
    \u306B\u5224\u5B9A\u3059\u308B\n    const bool a_zero = a[0] == 0 && a[1] == 0;\n\
    \    const bool b_zero = b[0] == 0 && b[1] == 0;\n    if (b_zero) return false;\
    \  // \u504F\u89D2 0 \u3088\u308A\u5C0F\u3055\u3044\u3082\u306E\u306F\u306A\u3044\
    \n    if (a_zero) return !(b[1] == 0 && b[0] > 0);  // b \u306E\u504F\u89D2\u304C\
    \ 0 \u3088\u308A\u5927\u304D\u3044\u304B\n    T a0 = std::array<T, 2>{a[1], a[0]}\
    \ < std::array<T, 2>{0, 0};\n    T b0 = std::array<T, 2>{b[1], b[0]} < std::array<T,\
    \ 2>{0, 0};\n    if (a0 < b0) {\n        return true;\n    } else if (b0 < a0)\
    \ {\n        return false;\n    } else {\n        return b[0] * a[1] < a[0] *\
    \ b[1];\n    }\n}\n\ntemplate <typename M, typename N, class F, ENABLE_IF_T(std::is_integral_v<std::common_type_t<M,\
    \ N>> and std::is_invocable_r_v<bool, F, std::common_type_t<M, N>>)>\ninline constexpr\
    \ std::common_type_t<M, N> binary_search(const M &ok, const N &ng, F f) {\n  \
    \  std::common_type_t<M, N> _ok = ok, _ng = ng;\n    while (std::abs(_ok - _ng)\
    \ > 1) {\n        std::common_type_t<M, N> mid = (_ok + _ng) / 2;\n        if\
    \ (f(mid)) {\n            _ok = mid;\n        } else {\n            _ng = mid;\n\
    \        }\n    }\n    return _ok;\n}\n\ntemplate <typename M, typename N, class\
    \ F, ENABLE_IF_T(not std::is_integral_v<std::common_type_t<M, N>> and std::is_invocable_r_v<bool,\
    \ F, std::common_type_t<M, N>>)>\ninline constexpr std::common_type_t<M, N> binary_search(const\
    \ M &ok, const N &ng, F f) {\n    std::common_type_t<M, N> _ok = ok, _ng = ng;\n\
    \    for (int i = 0; i < 100; i++) {\n        std::common_type_t<M, N> mid = (_ok\
    \ + _ng) / 2;\n        if (f(mid)) {\n            _ok = mid;\n        } else {\n\
    \            _ng = mid;\n        }\n    }\n    return _ok;\n}\n\n/**\n * 0 <=\
    \ x < a\n */\ninline constexpr bool inrange(long long x, long long a) {\n    return\
    \ 0 <= x and x < a;\n}\n/**\n * a <= x < b\n */\ninline constexpr bool inrange(long\
    \ long x, long long a, long long b) {\n    return a <= x and x < b;\n}\n/**\n\
    \ * 0 <= x < a and 0 <= y < b\n */\ninline constexpr bool inrect(long long x,\
    \ long long y, long long a, long long b) {\n    return 0 <= x and x < a and 0\
    \ <= y and y < b;\n}\n#line 2 \"src/data_structures/imos.hpp\"\n\n/**\n * @file\
    \ imos.hpp\n * @brief imos\u6CD5\u3067\u533A\u9593\u4F5C\u7528\u30011\u70B9\u53D6\
    \u5F97\n */\n\n#include <cassert>\n#include <functional>\n#include <vector>\n\
    #line 2 \"src/algebra/acted-monoid.hpp\"\n\n/**\n * @file acted-monoid.hpp\n *\
    \ @brief \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\u306F\u30E2\u30CE\
    \u30A4\u30C9 (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\
    \u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\
    \u3059\n * - using F: \u4F5C\u7528\u7D20\u306E\u578B\n * - S mapping(const F&\
    \ f, const S& x): \u4F5C\u7528\u7D20\u306E\u9069\u7528 f(x)\n *   \u533A\u9593\
    \u306E\u60C5\u5831\u304C\u5FC5\u8981\u306A\u5834\u5408\u306F mapping(f, x, sz)\
    \ (sz \u306F\u533A\u9593\u306E\u9577\u3055) \u3084 mapping(f, x, l, r) (\u533A\
    \u9593 [l, r)) \u3067\u3082\u3088\u3044\n * - F composition(const F& f, const\
    \ F& g): \u4F5C\u7528\u7D20\u306E\u5408\u6210 f\u2218g (g\u3092\u9069\u7528\u3057\
    \u305F\u5F8C\u306Bf\u3092\u9069\u7528\u3059\u308B)\n * - F id(): \u6052\u7B49\u5199\
    \u50CF\n * \u4F5C\u7528\u7D20\u304C\u7FA4\u3092\u306A\u3059\u5834\u5408 (imos.hpp\
    \ \u3067\u4F7F\u3046) \u306F\n * - F inv(const F& f): \u9006\u4F5C\u7528\u7D20\
    \n */\n\n#line 18 \"src/algebra/acted-monoid.hpp\"\n#include <limits>\n#include\
    \ <optional>\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n\
    \ * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\
    \u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\
    \u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S&\
    \ a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n\
    \ * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\
    \u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\
    \n#line 17 \"src/algebra/monoid.hpp\"\n#include <istream>\n#line 20 \"src/algebra/monoid.hpp\"\
    \n#include <ostream>\n#line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\
    \u95A2\u6570 f(x) = a * x + b\n *\n * monoid::Composite \u306E\u8981\u7D20\u3084\
    \ acted_monoid::AffineSum \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B\
    : Affine<mint> f{2, 3}; f(x) \u306F 2x + 3\u3002\u7701\u7565\u3059\u308B\u3068\
    \u6052\u7B49\u5199\u50CF {1, 0}\n */\ntemplate <typename T>\nstruct Affine {\n\
    \    T a = T(1);  //!< \u50BE\u304D\n    T b = T(0);  //!< \u5207\u7247\n    constexpr\
    \ T operator()(const T& x) const { return a * x + b; }\n    friend constexpr bool\
    \ operator==(const Affine& f, const Affine& g) { return f.a == g.a && f.b == g.b;\
    \ }\n    friend constexpr bool operator!=(const Affine& f, const Affine& g) {\
    \ return !(f == g); }\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Affine& f) {\n  \
    \      return is >> f.a >> f.b;\n    }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Affine& f) {\n        return os << f.a << CharT(' ') << f.b;\n\
    \    }\n};\n\nnamespace monoid {\n\n/**\n * @brief \u548C\n */\ntemplate <typename\
    \ T>\nstruct Sum {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a + b; }\n    static constexpr S e() { return S(0); }\n};\n\n\
    /**\n * @brief \u7A4D\n */\ntemplate <typename T>\nstruct Prod {\n    using S\
    \ = T;\n    static constexpr S op(const S& a, const S& b) { return a * b; }\n\
    \    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief \u6700\u5927\
    \u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\u5024\n */\ntemplate <typename\
    \ T>\nstruct Max {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::lowest();\
    \ }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\
    \u6700\u5927\u5024\n */\ntemplate <typename T>\nstruct Min {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return std::min(a, b); }\n\
    \    static constexpr S e() { return std::numeric_limits<S>::max(); }\n};\n\n\
    /**\n * @brief \u6700\u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max}\n\
    \ */\ntemplate <typename T>\nstruct MinMax {\n    using S = std::pair<T, T>;\n\
    \    static constexpr S op(const S& a, const S& b) { return {std::min(a.first,\
    \ b.first), std::max(a.second, b.second)}; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::max(), std::numeric_limits<T>::lowest()}; }\n};\n\n\
    /**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate <typename T>\n\
    struct Xor {\n    using S = T;\n    static constexpr S op(const S& a, const S&\
    \ b) { return a ^ b; }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u8AD6\u7406\u7A4D\n */\ntemplate <typename T>\nstruct And {\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return a & b; }\n\
    \    static constexpr S e() { return ~S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\
    \u548C\n */\ntemplate <typename T>\nstruct Or {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return a | b; }\n    static constexpr\
    \ S e() { return S(0); }\n};\n\n/**\n * @brief \u6700\u5927\u516C\u7D04\u6570\
    \ \u5358\u4F4D\u5143\u306F0\n */\ntemplate <typename T>\nstruct Gcd {\n    static_assert(std::is_integral_v<T>);\n\
    \    using S = T;\n    static constexpr S op(const S& a, const S& b) { return\
    \ std::gcd(a, b); }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u6700\u5C0F\u516C\u500D\u6570 \u5358\u4F4D\u5143\u306F1\n */\ntemplate\
    \ <typename T>\nstruct Lcm {\n    static_assert(std::is_integral_v<T>);\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return std::lcm(a,\
    \ b); }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief {0,\
    \ 1, ..., N-1} \u304B\u3089\u81EA\u5206\u81EA\u8EAB\u3078\u306E\u5199\u50CF\u306E\
    \u5408\u6210 (\u5909\u63DB\u30E2\u30CE\u30A4\u30C9)\n *\n * \u8981\u7D20 f \u306F\
    \ f[x] \u304C x \u306E\u884C\u304D\u5148\u3092\u8868\u3059 std::array<int, N>\u3002\
    \u5168\u5358\u5C04\u3067\u306A\u304F\u3066\u3088\u3044\n * op(f, g) = g\u2218\
    f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3059\u308B)\u3002\u533A\u9593 [l,\
    \ r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\n * \u4F8B: SegTree<monoid::Mapping<3>>\
    \ seg(n); seg.set(i, {0, 2, 1});\n *\n * @tparam N \u5199\u50CF\u306E\u5B9A\u7FA9\
    \u57DF\u30FB\u5024\u57DF\u306E\u5927\u304D\u3055\n */\ntemplate <std::size_t N>\n\
    struct Mapping {\n    using S = std::array<int, N>;\n    static constexpr S op(const\
    \ S& f, const S& g) {\n        S h{};\n        for (std::size_t x = 0; x < N;\
    \ x++) h[x] = g[f[x]];\n        return h;\n    }\n    static constexpr S e() {\n\
    \        S h{};\n        for (std::size_t x = 0; x < N; x++) h[x] = static_cast<int>(x);\n\
    \        return h;\n    }\n};\n\n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\
    \u5408\u6210\n * op(f, g) = g\u2218f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\
    \u3059\u308B)\n * \u533A\u9593 [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\
    \u8868\u3059\n */\ntemplate <typename T>\nstruct Composite {\n    using S = Affine<T>;\n\
    \    static constexpr S op(const S& f, const S& g) { return {g.a * f.a, g.a *\
    \ f.b + g.b}; }\n    static constexpr S e() { return {T(1), T(0)}; }\n};\n\n/**\n\
    \ * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis {\n    struct\
    \ S {\n        long long close; // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u306E\u500B\u6570\n        long long open;  // \u5BFE\u5FDC\u306E\u53D6\
    \u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\n        constexpr S(char\
    \ c = 0) : close(c == ')'), open(c == '(') {}\n        constexpr S(long long close,\
    \ long long open) : close(close), open(open) {}\n        /**\n         * @brief\
    \ \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n         */\n        constexpr bool\
    \ is_valid() const { return close == 0 && open == 0; }\n    };\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        if(a.open >= b.close) return S(a.close,\
    \ a.open - b.close + b.open);\n        return S(a.close + b.close - a.open, b.open);\n\
    \    }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\
    \u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\
    \u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate\
    \ <typename T, typename U = int>\nstruct MinWith {\n    using S = std::pair<T,\
    \ U>;\n    static constexpr S op(const S& a, const S& b) { return b.first < a.first\
    \ ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E\
    \ \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam\
    \ T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\
    \u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename T, typename U = int>\n\
    struct MaxWith {\n    using S = std::pair<T, U>;\n    static constexpr S op(const\
    \ S& a, const S& b) { return a.first < b.first ? b : a; }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U{}}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MinCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if(a.first < b.first) return\
    \ a;\n        if(b.first < a.first) return b;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MaxCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if(a.first < b.first) return b;\n        if(b.first < a.first) return\
    \ a;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U(0)}; }\n};\n\n} // namespace\
    \ monoid\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\
    \u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u30E2\u30CE\
    \u30A4\u30C9\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * \u4F8B\
    : SegTree seg(v, Monoid([](int a, int b) { return std::max(a, b); }, -1));\n *\n\
    \ * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename\
    \ Op>\nstruct Monoid {\n    using S = T;\n    Op op_object;\n    S identity;\n\
    \    Monoid() = default;\n    constexpr Monoid(Op op, const S& e) : op_object(std::move(op)),\
    \ identity(e) {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a,\
    \ b); }\n    constexpr S e() const { return identity; }\n};\ntemplate <typename\
    \ Op, typename T>\nMonoid(Op, T) -> Monoid<T, Op>;\n#line 23 \"src/algebra/acted-monoid.hpp\"\
    \n\nnamespace acted_monoid {\n\nnamespace detail {\ntemplate <typename A, typename\
    \ = void>\nstruct has_mapping_lr : std::false_type {};\ntemplate <typename A>\n\
    struct has_mapping_lr<A, std::void_t<decltype(std::declval<const A&>().mapping(std::declval<const\
    \ typename A::F&>(), std::declval<const typename A::S&>(), 0, 0))>> : std::true_type\
    \ {};\ntemplate <typename A, typename = void>\nstruct has_mapping_sz : std::false_type\
    \ {};\ntemplate <typename A>\nstruct has_mapping_sz<A, std::void_t<decltype(std::declval<const\
    \ A&>().mapping(std::declval<const typename A::F&>(), std::declval<const typename\
    \ A::S&>(), 0))>> : std::true_type {};\n} // namespace detail\n\n/**\n * @brief\
    \ \u533A\u9593 [l, r) \u3092\u8868\u3059\u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\
    \u9069\u7528\u3059\u308B\n * mapping \u306E\u5F15\u6570\u306E\u5F62\u306E\u9055\
    \u3044\u3092\u5438\u53CE\u3059\u308B\n */\ntemplate <typename A>\nconstexpr auto\
    \ apply_mapping(const A& a, const typename A::F& f, const typename A::S& x, int\
    \ l, int r) {\n    if constexpr(detail::has_mapping_lr<A>::value) {\n        return\
    \ a.mapping(f, x, l, r);\n    } else if constexpr(detail::has_mapping_sz<A>::value)\
    \ {\n        return a.mapping(f, x, r - l);\n    } else {\n        return a.mapping(f,\
    \ x);\n    }\n}\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u548C\
    \n */\ntemplate <typename T>\nstruct AddSum : monoid::Sum<T> {\n    using S =\
    \ T;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x,\
    \ int sz) { return x + f * S(sz); }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n    static constexpr F inv(const F& f) { return -f; }\n};\n\n/**\n * @brief\
    \ \u533A\u9593\u4E57\u7B97\u3001\u533A\u9593\u548C\n */\ntemplate <typename T>\n\
    struct MulSum : monoid::Sum<T> {\n    using S = T;\n    using F = T;\n    static\
    \ constexpr S mapping(const F& f, const S& x) { return f * x; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f * g; }\n    static constexpr\
    \ F id() { return F(1); }\n    static constexpr F inv(const F& f) { return F(1)\
    \ / f; }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\
    \u5C0F\u5024\n */\ntemplate <typename T>\nstruct AddMin : monoid::Min<T> {\n \
    \   using S = T;\n    using F = T;\n    static constexpr S mapping(const F& f,\
    \ const S& x) { return x + f; }\n    static constexpr F composition(const F& f,\
    \ const F& g) { return f + g; }\n    static constexpr F id() { return F(0); }\n\
    };\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nstruct AddMax : monoid::Max<T> {\n    using S =\
    \ T;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return x + f; }\n    static constexpr F composition(const F& f, const F& g)\
    \ { return f + g; }\n    static constexpr F id() { return F(0); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\u548C\n */\ntemplate <typename\
    \ T>\nstruct UpdateSum : monoid::Sum<T> {\n    using S = T;\n    using F = std::optional<T>;\n\
    \    static constexpr S mapping(const F& f, const S& x, int sz) { return f ? *f\
    \ * S(sz) : x; }\n    static constexpr F composition(const F& f, const F& g) {\
    \ return f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n\
    };\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\u6700\u5C0F\u5024\
    \n */\ntemplate <typename T>\nstruct UpdateMin : monoid::Min<T> {\n    using S\
    \ = T;\n    using F = std::optional<T>;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return f ? *f : x; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f ? f : g; }\n    static constexpr F id() { return\
    \ std::nullopt; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u3001\u533A\u9593\
    \u6700\u5927\u5024\n */\ntemplate <typename T>\nstruct UpdateMax : monoid::Max<T>\
    \ {\n    using S = T;\n    using F = std::optional<T>;\n    static constexpr S\
    \ mapping(const F& f, const S& x) { return f ? *f : x; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f ? f : g; }\n    static constexpr\
    \ F id() { return std::nullopt; }\n};\n\n/**\n * @brief \u533A\u9593chmin\u3001\
    \u533A\u9593\u6700\u5C0F\u5024\n */\ntemplate <typename T>\nstruct ChminMin :\
    \ monoid::Min<T> {\n    using S = T;\n    using F = T;\n    static constexpr S\
    \ mapping(const F& f, const S& x) { return std::min(f, x); }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return std::min(f, g); }\n    static\
    \ constexpr F id() { return std::numeric_limits<F>::max(); }\n};\n\n/**\n * @brief\
    \ \u533A\u9593chmax\u3001\u533A\u9593\u6700\u5927\u5024\n */\ntemplate <typename\
    \ T>\nstruct ChmaxMax : monoid::Max<T> {\n    using S = T;\n    using F = T;\n\
    \    static constexpr S mapping(const F& f, const S& x) { return std::max(f, x);\
    \ }\n    static constexpr F composition(const F& f, const F& g) { return std::max(f,\
    \ g); }\n    static constexpr F id() { return std::numeric_limits<F>::lowest();\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB x <-\
    \ a * x + b (Affine)\u3001\u533A\u9593\u548C\n */\ntemplate <typename T>\nstruct\
    \ AffineSum : monoid::Sum<T> {\n    using S = T;\n    using F = Affine<T>;\n \
    \   static constexpr S mapping(const F& f, const S& x, int sz) { return f.a *\
    \ x + f.b * S(sz); }\n    static constexpr F composition(const F& f, const F&\
    \ g) { return {f.a * g.a, f.a * g.b + f.b}; }\n    static constexpr F id() { return\
    \ {T(1), T(0)}; }\n};\n\n/**\n * @brief \u533A\u9593\u4EE3\u5165\u30011\u6B21\u95A2\
    \u6570\u306E\u5408\u6210 (monoid::Composite)\n */\ntemplate <typename T>\nstruct\
    \ UpdateComposite : monoid::Composite<T> {\n    using S = Affine<T>;\n    using\
    \ F = std::optional<S>;\n    static constexpr S mapping(const F& f, const S& x,\
    \ int sz) {\n        if(!f) return x;\n        // f \u3092 sz \u56DE\u5408\u6210\
    \u3059\u308B\n        S ret = monoid::Composite<T>::e(), p = *f;\n        for(;\
    \ sz > 0; sz >>= 1) {\n            if(sz & 1) ret = monoid::Composite<T>::op(ret,\
    \ p);\n            p = monoid::Composite<T>::op(p, p);\n        }\n        return\
    \ ret;\n    }\n    static constexpr F composition(const F& f, const F& g) { return\
    \ f ? f : g; }\n    static constexpr F id() { return std::nullopt; }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\
    \u306E\u4F4D\u7F6E (monoid::MinWith)\n */\ntemplate <typename T, typename U =\
    \ int>\nstruct AddMinWith : monoid::MinWith<T, U> {\n    using S = std::pair<T,\
    \ U>;\n    using F = T;\n    static constexpr S mapping(const F& f, const S& x)\
    \ { return {x.first + f, x.second}; }\n    static constexpr F composition(const\
    \ F& f, const F& g) { return f + g; }\n    static constexpr F id() { return F(0);\
    \ }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u6700\u5927\
    \u5024\u3068\u305D\u306E\u4F4D\u7F6E (monoid::MaxWith)\n */\ntemplate <typename\
    \ T, typename U = int>\nstruct AddMaxWith : monoid::MaxWith<T, U> {\n    using\
    \ S = std::pair<T, U>;\n    using F = T;\n    static constexpr S mapping(const\
    \ F& f, const S& x) { return {x.first + f, x.second}; }\n    static constexpr\
    \ F composition(const F& f, const F& g) { return f + g; }\n    static constexpr\
    \ F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\u3001\
    \u533A\u9593\u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570 (monoid::MinCount)\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct AddMinCount : monoid::MinCount<T,\
    \ U> {\n    using S = std::pair<T, U>;\n    using F = T;\n    static constexpr\
    \ S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ constexpr F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\
    \u3001\u533A\u9593\u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570 (monoid::MaxCount)\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct AddMaxCount : monoid::MaxCount<T,\
    \ U> {\n    using S = std::pair<T, U>;\n    using F = T;\n    static constexpr\
    \ S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }\n    static\
    \ constexpr F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ constexpr F id() { return F(0); }\n};\n\n/**\n * @brief \u533A\u9593\u52A0\u7B97\
    \u3001\u533A\u9593\u306E0\u4E57\u548C\u304B\u3089K\u4E57\u548C\n *\n * S(x) \u3067\
    \u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\
    S::operator[](i) \u3067 i \u4E57\u548C\u3092\u53D6\u5F97\u3059\u308B\n */\ntemplate\
    \ <typename T, int K>\nstruct AddPowerSum {\n    struct S {\n        std::array<T,\
    \ K + 1> val;\n        S() : val{} {}\n        S(const T& x) {\n            val[0]\
    \ = T(1);\n            for(int i = 1; i <= K; i++) val[i] = val[i - 1] * x;\n\
    \        }\n        const T& operator[](std::size_t i) const { return val[i];\
    \ }\n    };\n    using F = T;\n    static S op(const S& a, const S& b) {\n   \
    \     S ret;\n        for(int i = 0; i <= K; i++) ret.val[i] = a.val[i] + b.val[i];\n\
    \        return ret;\n    }\n    static S e() { return S(); }\n    static S mapping(const\
    \ F& f, const S& x) {\n        // sum (x+f)^i = sum_j binom(i, j) f^j x^(i-j)\n\
    \        static const auto binom = [] {\n            std::array<std::array<T,\
    \ K + 1>, K + 1> c{};\n            for(int i = 0; i <= K; i++) {\n           \
    \     c[i][0] = c[i][i] = T(1);\n                for(int j = 1; j < i; j++) c[i][j]\
    \ = c[i - 1][j - 1] + c[i - 1][j];\n            }\n            return c;\n   \
    \     }();\n        std::array<T, K + 1> pw{};\n        pw[0] = T(1);\n      \
    \  for(int i = 1; i <= K; i++) pw[i] = pw[i - 1] * f;\n        S ret;\n      \
    \  for(int i = 0; i <= K; i++) {\n            for(int j = 0; j <= i; j++) ret.val[i]\
    \ += binom[i][j] * pw[j] * x.val[i - j];\n        }\n        return ret;\n   \
    \ }\n    static F composition(const F& f, const F& g) { return f + g; }\n    static\
    \ F id() { return F(0); }\n};\n\n} // namespace acted_monoid\n\n/**\n * @brief\
    \ \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u304B\u3089\u5B9F\u884C\u6642\
    \u306B\u4F5C\u308B\u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n * \u30E9\
    \u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u578B\n * @tparam U \u4F5C\u7528\u7D20\u306E\u578B\n * @tparam Mapping\
    \ \u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\u308B\u95A2\u6570\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306E\u578B \u5F15\u6570\u306F (f, x), (f, x, sz), (f, x, l,\
    \ r) \u306E\u3044\u305A\u308C\u304B\n * @tparam Composition \u4F5C\u7528\u7D20\
    \u306E\u5408\u6210\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\
    \u578B\n */\ntemplate <typename T, typename Op, typename U, typename Mapping,\
    \ typename Composition>\nstruct ActedMonoid {\n    using S = T;\n    using F =\
    \ U;\n    Op op_object;\n    S identity;\n    Mapping mapping_object;\n    Composition\
    \ composition_object;\n    F lazy_identity;\n    ActedMonoid() = default;\n  \
    \  constexpr ActedMonoid(Op op, const S& e, Mapping mapping, Composition composition,\
    \ const F& id)\n        : op_object(std::move(op)), identity(e), mapping_object(std::move(mapping)),\
    \ composition_object(std::move(composition)), lazy_identity(id) {}\n    constexpr\
    \ S op(const S& a, const S& b) const { return op_object(a, b); }\n    constexpr\
    \ S e() const { return identity; }\n    constexpr auto mapping(const F& f, const\
    \ S& x, int l, int r) const {\n        if constexpr(std::is_invocable_v<const\
    \ Mapping&, const F&, const S&, int, int>) {\n            return mapping_object(f,\
    \ x, l, r);\n        } else if constexpr(std::is_invocable_v<const Mapping&, const\
    \ F&, const S&, int>) {\n            return mapping_object(f, x, r - l);\n   \
    \     } else {\n            return mapping_object(f, x);\n        }\n    }\n \
    \   constexpr F composition(const F& f, const F& g) const { return composition_object(f,\
    \ g); }\n    constexpr F id() const { return lazy_identity; }\n};\ntemplate <typename\
    \ Op, typename T, typename Mapping, typename Composition, typename U>\nActedMonoid(Op,\
    \ T, Mapping, Composition, U) -> ActedMonoid<T, Op, U, Mapping, Composition>;\n\
    #line 13 \"src/data_structures/imos.hpp\"\n\n/**\n * @brief imos\u6CD5\u3067\u533A\
    \u9593\u4F5C\u7528\u30011\u70B9\u53D6\u5F97\u3059\u308B\u3002\n *\n * \u4F8B:\
    \ Imos<acted_monoid::AddSum<long long>> imos(n);\n *\n * @tparam A \u4F5C\u7528\
    \u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9 (algebra/acted-monoid.hpp)\n *    \
    \       \u4F5C\u7528\u7D20\u306F\u30A2\u30FC\u30D9\u30EB\u7FA4(\u53EF\u63DB\u7FA4\
    )\u3092\u306A\u3057\u3001inv \u3092\u6301\u3064\u5FC5\u8981\u304C\u3042\u308B\
    \ \u5024\u306E\u30E2\u30CE\u30A4\u30C9\u306E\u6F14\u7B97\u306F\u4F7F\u308F\u306A\
    \u3044\n */\ntemplate <typename A>\nclass Imos {\n   public:\n    using S = typename\
    \ A::S;\n    using F = typename A::F;\n\n   private:\n    A a;\n    int _n, t;\n\
    \    std::vector<S> data;\n    std::vector<F> lazy;\n\n    S mapping(const F&\
    \ f, const S& x, int k) const { return acted_monoid::apply_mapping(a, f, x, k,\
    \ k + 1); }\n    F composition(const F& f, const F& g) const { return a.composition(f,\
    \ g); }\n    F id() const { return a.id(); }\n    F inv(const F& f) const { return\
    \ a.inv(f); }\n\n   public:\n    /**\n     * @param n \u8981\u7D20\u6570 \u5404\
    \u8981\u7D20\u306F S() \u3067\u521D\u671F\u5316\u3059\u308B\n     * @param a \u4F5C\
    \u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit Imos(int\
    \ n = 0, A a = A()) : Imos(n, S(), std::move(a)) {}\n    /**\n     * @param n\
    \ \u8981\u7D20\u6570\n     * @param value \u5404\u8981\u7D20\u306E\u521D\u671F\
    \u5024\n     * @param a \u4F5C\u7528\u7D20\u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\
    \n     */\n    Imos(int n, const S& value, A a = A()) : a(std::move(a)), _n(n),\
    \ t(n), data(n, value), lazy(n, this->a.id()) {}\n    /**\n     * @param value\
    \ \u5404\u8981\u7D20\u306E\u521D\u671F\u5024\n     * @param a \u4F5C\u7528\u7D20\
    \u4ED8\u304D\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit Imos(const std::vector<S>&\
    \ value, A a = A()) : a(std::move(a)), _n(value.size()), t(value.size()), data(value),\
    \ lazy(value.size(), this->a.id()) {}\n\n    /**\n     * @brief 1\u70B9\u4F5C\u7528\
    \n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param f \u4F5C\
    \u7528\u7D20\n     */\n    void apply(int k, const F& f) {\n        assert(0 <=\
    \ k && k < _n);\n        data[k] = mapping(f, data[k], k);\n    }\n    /**\n \
    \    * @brief [l, r)\u306E\u533A\u9593\u306E\u5024\u306Bf\u3092\u4F5C\u7528\u3055\
    \u305B\u308B\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\n   \
    \  * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @param\
    \ f \u4F5C\u7528\u7D20\n     */\n    void apply(int l, int r, const F& f) {\n\
    \        assert(0 <= l && l <= r && r <= _n);\n        if (l < _n) lazy[l] = composition(lazy[l],\
    \ f);\n        if (r < _n) lazy[r] = composition(lazy[r], inv(f));\n        if\
    \ (t > l) t = l;\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\
    \u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     * @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n     * @return const S& \u5024\n     */\n    const S& get(int\
    \ k) {\n        assert(0 <= k && k < _n);\n        while (t <= k) {\n        \
    \    data[t] = mapping(lazy[t], data[t], t);\n            if (t + 1 < _n) {\n\
    \                lazy[t + 1] = composition(lazy[t], lazy[t + 1]);\n          \
    \  }\n            lazy[t] = id();\n            t++;\n        }\n        return\
    \ data[k];\n    }\n};\n#line 7 \"test/aoj/dsl-5-a.test.cpp\"\n\nint main() {\n\
    \    int n, t;\n    std::cin >> n >> t;\n    // \u6642\u523B i (0 <= i < t) \u306B\
    \u5E97\u306B\u3044\u308B\u4EBA\u6570\n    Imos<acted_monoid::AddSum<int>> imos(t);\n\
    \    for (int i = 0; i < n; i++) {\n        int l, r;\n        std::cin >> l >>\
    \ r;\n        imos.apply(l, r, 1);\n    }\n    int ans = 0;\n    for (int i =\
    \ 0; i < t; i++) chmax(ans, imos.get(i));\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n\n#include <iostream>\n\n#include \"../../src/base/functions.hpp\"\n#include\
    \ \"../../src/data_structures/imos.hpp\"\n\nint main() {\n    int n, t;\n    std::cin\
    \ >> n >> t;\n    // \u6642\u523B i (0 <= i < t) \u306B\u5E97\u306B\u3044\u308B\
    \u4EBA\u6570\n    Imos<acted_monoid::AddSum<int>> imos(t);\n    for (int i = 0;\
    \ i < n; i++) {\n        int l, r;\n        std::cin >> l >> r;\n        imos.apply(l,\
    \ r, 1);\n    }\n    int ans = 0;\n    for (int i = 0; i < t; i++) chmax(ans,\
    \ imos.get(i));\n    std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - src/base/functions.hpp
  - src/base/traits.hpp
  - src/data_structures/imos.hpp
  - src/algebra/acted-monoid.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: true
  path: test/aoj/dsl-5-a.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 10:40:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl-5-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl-5-a.test.cpp
- /verify/test/aoj/dsl-5-a.test.cpp.html
title: test/aoj/dsl-5-a.test.cpp
---
