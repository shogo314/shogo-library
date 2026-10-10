---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: base/traits.hpp
    title: base/traits.hpp
  - icon: ':heavy_check_mark:'
    path: data_structures/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc331/tasks/abc331_f
  bundledCode: "#line 1 \"test/atcoder/abc331-f.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc331/tasks/abc331_f\"\
    \n#define IGNORE\n\n#include <iostream>\n\n#line 2 \"string/rolling-hash.hpp\"\
    \n\n#include <string>\n#include <vector>\n#include <random>\n#include <cassert>\n\
    #include <string_view>\n#include <type_traits>\n\n#line 2 \"base/traits.hpp\"\n\
    \n#include <cstddef>\n#include <iterator>\n#include <set>\n#line 7 \"base/traits.hpp\"\
    \n#include <utility>\n\nnamespace detail {\nusing std::begin, std::end;\n\ntemplate\
    \ <class T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace detail\n\n\
    template <class T>\nstruct is_range : detail::is_range_impl<T>::type {};\ntemplate\
    \ <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\n#define\
    \ HAS_METHOD(func_name)                                                      \
    \        \\\n    namespace detail {                                          \
    \                           \\\n    template <class T, class = void>         \
    \                                              \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : detail::has_##func_name##_impl<T>::type {};                   \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace detail {              \
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
    \                                          \\\n    struct has_##func_name : detail::has_##func_name##_impl<T,\
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
    \ 11 \"string/rolling-hash.hpp\"\n\nstruct RHString;\n\n/**\n * @brief \u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n *\n * \u30D3\u30C3\u30C8\u6F14\u7B97\
    \u306B\u5BC4\u308B\u9AD8\u901F\u5316\u306E\u305F\u3081\u30CF\u30C3\u30B7\u30E5\
    \u306FMOD = 2^61-1\u3067\u8A08\u7B97\u3055\u308C\u308B\n *\n * 10^8\u500B\u304F\
    \u3089\u3044\u306A\u308999%\u306E\u78BA\u7387\u3067\u885D\u7A81\u3059\u308B\u7D44\
    \u304C\u5B58\u5728\u3057\u306A\u3044\n */\nclass RollingHash {\n    constexpr\
    \ static unsigned long long MASK30 = (1ULL << 30) - 1;\n    constexpr static unsigned\
    \ long long MASK31 = (1ULL << 31) - 1;\n    constexpr static unsigned long long\
    \ MOD = (1ULL << 61) - 1;\n\n    // a < MOD, b < MOD\u5FC5\u9808\n    constexpr\
    \ static unsigned long long add(unsigned long long a, unsigned long long b) {\n\
    \        if((a += b) >= MOD) a -= MOD;\n        return a;\n    }\n\n    // a <\
    \ MOD, b < MOD\u5FC5\u9808\n    constexpr static unsigned long long mul(unsigned\
    \ long long a, unsigned long long b) {\n        __uint128_t c = static_cast<__uint128_t>(a)\
    \ * b;\n        return add(static_cast<unsigned long long>(c >> 61), static_cast<unsigned\
    \ long long>(c & MOD));\n    }\n\n    void expand(int n) {\n        while(static_cast<int>(power.size())\
    \ <= n) power.push_back(mul(power.back(), base));\n    }\n\npublic:\n    /**\n\
    \     * @brief \u8981\u7D20\u3092[0, MOD)\u306E\u5024\u306B\u5909\u63DB\u3059\u308B\
    \n     * @note char\u306F\u7B26\u53F7\u306B\u95A2\u308F\u3089\u305A0~255\u3068\
    \u3057\u3066\u6271\u3046 \u8CA0\u306E\u6574\u6570\u306FMOD\u3067\u6B63\u898F\u5316\
    \u3059\u308B\n     */\n    template <typename T>\n    constexpr static unsigned\
    \ long long to_value(const T& x) {\n        using U = std::decay_t<T>;\n     \
    \   if constexpr (std::is_same_v<U, char> || std::is_same_v<U, signed char>) {\n\
    \            return static_cast<unsigned char>(x);\n        } else if constexpr\
    \ (std::is_integral_v<U> && std::is_signed_v<U>) {\n            long long v =\
    \ static_cast<long long>(x) % static_cast<long long>(MOD);\n            return\
    \ v < 0 ? v + MOD : v;\n        } else {\n            return static_cast<unsigned\
    \ long long>(x) % MOD;\n        }\n    }\n\n    unsigned int base; //!< \u30CF\
    \u30C3\u30B7\u30E5\u306E\u57FA\u6570\n    std::vector<unsigned long long> power;\
    \ //!< base\u306E\u7D2F\u4E57\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     *\n     * @param base \u30CF\u30C3\u30B7\u30E5\u306E\u57FA\
    \u6570 \u7701\u7565\u3059\u308B\u3068\u30E9\u30F3\u30C0\u30E0\n     */\n    RollingHash(unsigned\
    \ int base = 0) : base(base) {\n        if(base == 0) {\n            std::mt19937\
    \ mt(std::random_device{}());\n            this->base = std::uniform_int_distribution<unsigned\
    \ int>(129, ~0U)(mt);\n        }\n        power = {1};\n    }\n\n    /**\n   \
    \  * @brief \u914D\u5217/\u6587\u5B57\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\
    \u9593\u306E\u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97(O(N))\n     *\n     * @tparam\
    \ It \u30A4\u30C6\u30EC\u30FC\u30BF\n     * @param first \u914D\u5217\u306E\u958B\
    \u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n     * @param last \u914D\u5217\u306E\u7D42\
    \u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n     * @return std::vector<unsigned long\
    \ long> \u5148\u982D\u304B\u3089\u5404\u8981\u7D20\u6570\u5206\u306E\u30CF\u30C3\
    \u30B7\u30E5\n     */\n    template <typename It>\n    std::vector<unsigned long\
    \ long> build(It first, It last) {\n        std::vector<unsigned long long> res;\n\
    \        if constexpr (std::is_convertible_v<typename std::iterator_traits<It>::iterator_category,\
    \ std::random_access_iterator_tag>) {\n            res.reserve(last - first +\
    \ 1);\n        }\n        res.push_back(0);\n        for(; first != last; ++first)\
    \ {\n            res.push_back(add(mul(res.back(), base), to_value(*first)));\n\
    \        }\n        return res;\n    }\n\n    /**\n     * @brief \u914D\u5217\
    /\u6587\u5B57\u5217\u5168\u4F53\u306E\u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97\
    (O(N))\n     *\n     * @param s \u914D\u5217/\u6587\u5B57\u5217\n     * @return\
    \ std::vector<unsigned long long> \u5148\u982D\u304B\u3089\u5404\u6587\u5B57\u6570\
    \u5206\u306E\u30CF\u30C3\u30B7\u30E5\n     */\n    template <typename R>\n   \
    \ std::vector<unsigned long long> build(R&& s) {\n        using std::begin, std::end;\n\
    \        return build(begin(s), end(s));\n    }\n\n    /**\n     * @brief [l,r)\u306E\
    \u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97(O(1))\n     *\n     * @param hash \u5148\
    \u982D\u304B\u3089\u306E\u30CF\u30C3\u30B7\u30E5\n     * @param l \u533A\u9593\
    \u306E\u5DE6\u7AEF\n     * @param r \u533A\u9593\u306E\u53F3\u7AEF\n     * @return\
    \ unsigned long long [l,r)\u306E\u30CF\u30C3\u30B7\u30E5\n     */\n    unsigned\
    \ long long query(const std::vector<unsigned long long>& hash, int l, int r) {\n\
    \        expand(r - l);\n        return add(hash[r], MOD - mul(hash[l], power[r-l]));\n\
    \    }\n\n    friend RHString;\n};\n\n/**\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\
    \u30CF\u30C3\u30B7\u30E5\u306B\u3088\u3063\u3066\u7BA1\u7406\u3055\u308C\u308B\
    \u6587\u5B57\u5217\u578B\n */\nstruct RHString {\n    RollingHash& rh;\n    size_t\
    \ sz;\n    unsigned long long hash1;  //!< \u6B63\u9806\n    unsigned long long\
    \ hash2;  //!< \u9006\u9806\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     * \u4E88\u3081RollingHash\u3092\u30A4\u30F3\u30B9\u30BF\u30F3\
    \u30B9\u5316\u3057\u3066\u304A\u304F\u5FC5\u8981\u304C\u3042\u308B\n     */\n\
    \    RHString(RollingHash& rh) : rh(rh), sz(0), hash1(0), hash2(0) {}\n    RHString(RollingHash&\
    \ rh, size_t sz, unsigned long long hash1, unsigned long long hash2) : rh(rh),\
    \ sz(sz), hash1(hash1), hash2(hash2) {}\n    RHString(const RHString& o) : rh(o.rh),\
    \ sz(o.sz), hash1(o.hash1), hash2(o.hash2) {}\n    /**\n     * @brief vector\u306A\
    \u3069\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n    template <class R, std::enable_if_t<is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>, std::nullptr_t> = nullptr>\n\
    \    RHString(RollingHash& rh, R&& v) : rh(rh) {\n        using std::begin, std::end,\
    \ std::rbegin, std::rend;\n        sz = std::distance(begin(v), end(v));\n   \
    \     hash1 = rh.build(begin(v), end(v)).back();\n        hash2 = rh.build(rbegin(v),\
    \ rend(v)).back();\n    }\n    /**\n     * @brief char\u3084unsigned long long\u306A\
    \u3069\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n    template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>, std::nullptr_t>\
    \ = nullptr>\n    RHString(RollingHash& rh, T&& x) : rh(rh) {\n        sz = 1;\n\
    \        hash1 = RollingHash::to_value(x);\n        hash2 = hash1;\n    }\n  \
    \  /**\n     * @brief \u6587\u5B57\u5217(string, const char*, string_view)\u3067\
    \u521D\u671F\u5316\u3059\u308B\n     */\n    RHString(RollingHash& rh, std::string_view\
    \ s) : rh(rh) {\n        sz = std::distance(s.begin(), s.end());\n        hash1\
    \ = rh.build(s.begin(), s.end()).back();\n        hash2 = rh.build(s.rbegin(),\
    \ s.rend()).back();\n    }\n\n    /**\n     * @brief \u56DE\u6587\u304B\u5426\u304B\
    \n     */\n    bool is_palindrome() const {\n        return hash1 == hash2;\n\
    \    }\n    size_t size() const {\n        return sz;\n    }\n    void clear()\
    \ {\n        sz = 0;\n        hash1 = 0;\n        hash2 = 0;\n    }\n    bool\
    \ empty() const {\n        return sz == 0;\n    }\n    RHString& operator+=(const\
    \ RHString& o) {\n        assert(&rh == &o.rh);\n        rh.expand(sz);\n    \
    \    rh.expand(o.sz);\n        hash1 = rh.add(rh.mul(hash1, rh.power[o.sz]), o.hash1);\n\
    \        hash2 = rh.add(hash2, rh.mul(o.hash2, rh.power[sz]));\n        sz +=\
    \ o.sz;\n        return *this;\n    }\n    /**\n     * @brief \u518D\u4EE3\u5165\
    \u3059\u308B\n     * RollingHash\u306F\u540C\u3058\u3082\u306E\u3067\u3042\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n     */\n    void assign(const RHString& o) {\n\
    \        assert(&rh == &o.rh);\n        sz = o.sz;\n        hash1 = o.hash1;\n\
    \        hash2 = o.hash2;\n    }\n    /**\n     * @brief vector\u306A\u3069\u3092\
    \u518D\u4EE3\u5165\u3059\u308B\n     */\n    template <class R, std::enable_if_t<is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>, std::nullptr_t> = nullptr>\n\
    \    void assign(R&& v) {\n        using std::begin, std::end, std::rbegin, std::rend;\n\
    \        sz = std::distance(begin(v), end(v));\n        hash1 = rh.build(begin(v),\
    \ end(v)).back();\n        hash2 = rh.build(rbegin(v), rend(v)).back();\n    }\n\
    \    /**\n     * @brief char\u3084unsigned long long\u306A\u3069\u3092\u518D\u4EE3\
    \u5165\u3059\u308B\n     */\n    template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>, std::nullptr_t>\
    \ = nullptr>\n    void assign(T&& x) {\n        sz = 1;\n        hash1 = RollingHash::to_value(x);\n\
    \        hash2 = hash1;\n    }\n    /**\n     * @brief \u6587\u5B57\u5217(string,\
    \ const char*, string_view)\u3092\u518D\u4EE3\u5165\u3059\u308B\n     */\n   \
    \ void assign(std::string_view s) {\n        sz = std::distance(s.begin(), s.end());\n\
    \        hash1 = rh.build(s.begin(), s.end()).back();\n        hash2 = rh.build(s.rbegin(),\
    \ s.rend()).back();\n    }\n    /**\n     * @brief \u518D\u4EE3\u5165\u3059\u308B\
    \n     * RollingHash\u306F\u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\n     */\n    RHString& operator=(const RHString& o) {\n  \
    \      assign(o);\n        return *this;\n    }\n    /**\n     * @brief vector\u306A\
    \u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\n     */\n    template <class R, std::enable_if_t<is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>, std::nullptr_t> = nullptr>\n\
    \    RHString& operator=(R&& v) {\n        assign(v);\n        return *this;\n\
    \    }\n    /**\n     * @brief char\u3084unsigned long long\u306A\u3069\u3092\u518D\
    \u4EE3\u5165\u3059\u308B\n     */\n    template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>, std::nullptr_t>\
    \ = nullptr>\n    RHString& operator=(T&& x) {\n        assign(x);\n        return\
    \ *this;\n    }\n    /**\n     * @brief \u6587\u5B57\u5217(string, const char*,\
    \ string_view)\u3092\u518D\u4EE3\u5165\u3059\u308B\n     */\n    RHString& operator=(std::string_view\
    \ s) {\n        assign(s);\n        return *this;\n    }\n    friend RHString\
    \ operator+(const RHString& t1, const RHString& t2) {\n        RHString ret =\
    \ t1;\n        ret += t2;\n        return ret;\n    }\n    friend bool operator==(const\
    \ RHString& t1, const RHString& t2) {\n        assert(&t1.rh == &t2.rh);\n   \
    \     return t1.sz == t2.sz && t1.hash1 == t2.hash1 && t1.hash2 == t2.hash2;\n\
    \    }\n    friend bool operator!=(const RHString& t1, const RHString& t2) { return\
    \ !(t1 == t2); }\n};\n#line 2 \"data_structures/segtree.hpp\"\n\n/**\n * @file\
    \ segtree.hpp\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#line 9\
    \ \"data_structures/segtree.hpp\"\n#include <functional>\n#include <ostream>\n\
    #line 2 \"algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\
    \u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\
    \u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * -\
    \ using S: \u8981\u7D20\u306E\u578B\n * - S op(const S& a, const S& b): \u7A4D\
    \ (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n * op, e \u306F static\
    \ \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\
    \u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\n#include <algorithm>\n\
    #include <limits>\n#include <numeric>\n#line 19 \"algebra/monoid.hpp\"\n\nnamespace\
    \ monoid {\n\n/**\n * @brief \u548C\n */\ntemplate <typename T>\nstruct Sum {\n\
    \    using S = T;\n    static constexpr S op(const S& a, const S& b) { return\
    \ a + b; }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n * @brief\
    \ \u7A4D\n */\ntemplate <typename T>\nstruct Prod {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return a * b; }\n    static constexpr\
    \ S e() { return S(1); }\n};\n\n/**\n * @brief \u6700\u5927\u5024 \u5358\u4F4D\
    \u5143\u306F\u578B\u306E\u6700\u5C0F\u5024\n */\ntemplate <typename T>\nstruct\
    \ Max {\n    using S = T;\n    static constexpr S op(const S& a, const S& b) {\
    \ return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::lowest();\
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
    \ b); }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief 1\u6B21\
    \u95A2\u6570 f(x) = first * x + second \u306E\u5408\u6210\n * op(f, g) = g\u2218\
    f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3059\u308B)\n * \u533A\u9593 [l,\
    \ r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\n */\ntemplate <typename\
    \ T>\nstruct Composite {\n    using S = std::pair<T, T>;\n    static constexpr\
    \ S op(const S& f, const S& g) { return {g.first * f.first, g.first * f.second\
    \ + g.second}; }\n    static constexpr S e() { return {T(1), T(0)}; }\n};\n\n\
    /**\n * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
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
    \ Op, typename T>\nMonoid(Op, T) -> Monoid<T, Op>;\n#line 14 \"data_structures/segtree.hpp\"\
    \n\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u4F8B:\n * SegTree<monoid::Max<int>>\
    \ seg(n);\n * SegTree seg(v, Monoid([](int a, int b) { return a + b; }, 0));\n\
    \ *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n */\ntemplate\
    \ <typename M>\nclass SegTree {\npublic:\n    using S = typename M::S;\n\nprivate:\n\
    \    M m;\n    S op(const S& a, const S& b) const { return m.op(a, b); }\n   \
    \ S e() const { return m.e(); }\n\n    int n, sz, height;\n    std::vector<S>\
    \ data;\n    void update(int k) { data[k] = op(data[2 * k], data[2 * k + 1]);\
    \ }\n\n    class SegTreeReference {\n        SegTree& segtree;\n        int k;\n\
    \    public:\n        SegTreeReference(SegTree& segtree, int k) : segtree(segtree),\
    \ k(k) {}\n        SegTreeReference& operator=(const S& x) {\n            segtree.set(k,\
    \ x);\n            return *this;\n        }\n        operator S() const { return\
    \ segtree.get(k); }\n    };\n\n    void construct_data() {\n        sz = 1;\n\
    \        height = 0;\n        while (sz < n) {\n            sz <<= 1;\n      \
    \      height++;\n        }\n        data.assign(sz * 2, e());\n    }\n\npublic:\n\
    \    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n \
    \    * @param n \u8981\u7D20\u6570\n     * @param m \u30E2\u30CE\u30A4\u30C9\n\
    \     */\n    explicit SegTree(int n = 0, M m = M()) : m(std::move(m)), n(n) {\n\
    \        construct_data();\n    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n \
    \    * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit SegTree(const\
    \ std::vector<S>& v, M m = M()) : SegTree(v.size(), std::move(m)) {\n        for\
    \ (int i = 0; i < n; i++) data[sz + i] = v[i];\n        for (int i = sz - 1; i\
    \ > 0; i--) update(i);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\
    \u8FD4\u3059\n     */\n    int size() const { return n; }\n\n    /**\n     * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n \
    \    * \n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ S \u5024\n     */\n    S get(int k) const {\n        assert(0 <= k && k < n);\n\
    \        return data[sz + k];\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     * \n     * @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n \
    \   S operator[] (int k) const { return get(k); }\n    /**\n     * @brief \u6307\
    \u5B9A\u3055\u308C\u305F\u8981\u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\
    \n     * \n     * @param k \n     * @return SegTreeReference \u8981\u7D20\u3078\
    \u306E\u53C2\u7167 \u4EE3\u5165\u3055\u308C\u308B\u3068set()\u304C\u547C\u3070\
    \u308C\u308B\n     */\n    SegTreeReference operator[] (int k) { return SegTreeReference(*this,\
    \ k); }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n\
    \     * \n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\
    \u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n     * @return std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\
    \u30FC\u30E0 \n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const SegTree& rhs)\
    \ {\n        for(int i = 0; i < rhs.n; i++) {\n            if(i != 0) os << CharT('\
    \ ');\n            os << rhs[i];\n        }\n        return os;\n    }\n\n   \
    \ /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\
    x\u306B\u66F4\u65B0\u3059\u308B\n     * \n     * @param k \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\n     * @param x \u65B0\u3057\u3044\u5024\n     */\n    void set(int\
    \ k, const S& x) {\n        assert(0 <= k && k < n);\n        k += sz;\n     \
    \   data[k] = x;\n        for (int i = 1; i <= height; i++) update(k >> i);\n\
    \    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u306Bx\u3092\u4F5C\u7528\u3055\u305B\u308B\n     * \n     * @param k \u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u4F5C\u7528\u7D20\n     */\n\
    \    void apply(int k, const S& x) { set(k, op(get(k), x)); }\n\n    /**\n   \
    \  * @brief [l, r)\u306E\u533A\u9593\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n   \
    \  * \n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\n     * @param\
    \ r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n     * @return S \u7DCF\
    \u7A4D\n     */\n    S prod(int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        S left_prod = e(), right_prod = e();\n        l +=\
    \ sz;\n        r += sz;\n        while (l < r) {\n            if (l & 1) left_prod\
    \ = op(left_prod, data[l++]);\n            if (r & 1) right_prod = op(data[--r],\
    \ right_prod);\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return op(left_prod, right_prod);\n    }\n    /**\n     * @brief \u3059\u3079\
    \u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     * \n     *\
    \ @return S \u7DCF\u7A4D\n     */\n    S all_prod() const { return data[1]; }\n\
    \n    /**\n     * @brief (r = l or f(prod([l, r))) = true) and (r = n or f(prod([l,\
    \ r+1))) = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\n     * f\u304C\u5358\u8ABF\
    \u306A\u3089\u3001f(prod([l, r))) = true\u3068\u306A\u308B\u6700\u5927\u306Er\n\
    \     * \n     * @tparam F\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\
    \u59CB 0<=l<=n\n     * @param f \u5224\u5B9A\u95A2\u6570 f(e) = true\n     * @return\
    \ int\n     */\n    template <typename F>\n    int max_right(int l, F f) const\
    \ {\n        assert(f(e()));\n        assert(0 <= l && l <= n);\n        if (l\
    \ == n) return n;\n        l += sz;\n        while (l % 2 == 0) l >>= 1;\n   \
    \     S sum = e();\n        while(f(op(sum, data[l]))) {\n            sum = op(sum,\
    \ data[l]);\n            l++;\n            while (l % 2 == 0) l >>= 1;\n     \
    \       if (l == 1) return n;\n        }\n        while (l < sz) {\n         \
    \   if (!f(op(sum, data[l * 2]))) l *= 2;\n            else {\n              \
    \  sum = op(sum, data[l * 2]);\n                l = l * 2 + 1;\n            }\n\
    \        }\n        return l - sz;\n    }\n    /**\n     * @brief (l = 0 or f(prod([l,\
    \ r))) = true) and (l = r or f(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\
    \u8FD4\u3059\n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001f(prod([l, r))) = true\u3068\
    \u306A\u308B\u6700\u5C0F\u306El\n     * \n     * @tparam F\n     * @param r \u534A\
    \u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param f \u5224\u5B9A\u95A2\
    \u6570 f(e) = true\n     * @return int\n     */\n    template <typename F>\n \
    \   int min_left(int r, F f) const {\n        assert(f(e()));\n        assert(0\
    \ <= r && r <= n);\n        if (r == 0) return 0;\n        r += sz;\n        S\
    \ sum = e();\n        do {\n            r--;\n            while (r > 1 && r %\
    \ 2 == 1) r >>= 1;\n            if (!f(op(data[r], sum))) {\n                while\
    \ (r < sz) {\n                    r = r * 2 + 1;\n                    if (f(op(data[r],\
    \ sum))) {\n                        sum = op(data[r], sum);\n                \
    \        r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            sum = op(data[r], sum);\n        } while\
    \ ((r & -r) != r);\n        return 0;\n    }\n};\n\ntemplate <typename M>\nSegTree(int,\
    \ M) -> SegTree<M>;\ntemplate <typename M>\nSegTree(std::vector<typename M::S>,\
    \ M) -> SegTree<M>;\n#line 8 \"test/atcoder/abc331-f.cpp\"\n\nRollingHash rh;\n\
    struct RHMonoid {\n    using S = RHString;\n    static S op(const S& a, const\
    \ S& b) { return a + b; }\n    static S e() { return RHString(rh); }\n};\n\nint\
    \ main() {\n    int N, Q;\n    std::string S;\n    std::cin >> N >> Q >> S;\n\
    \    std::vector<RHString> init;\n    init.reserve(N);\n    for (char c : S) {\n\
    \        init.emplace_back(rh, c);\n    }\n    SegTree<RHMonoid> seg(init);\n\
    \    while (Q--) {\n        int q;\n        std::cin >> q;\n        if (q == 1)\
    \ {\n            int x;\n            char c;\n            std::cin >> x >> c;\n\
    \            seg.set(x - 1, RHString(rh, c));\n        } else {\n            int\
    \ L, R;\n            std::cin >> L >> R;\n            std::cout << (seg.prod(L\
    \ - 1, R).is_palindrome() ? \"Yes\" : \"No\") << std::endl;\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc331/tasks/abc331_f\"\n#define\
    \ IGNORE\n\n#include <iostream>\n\n#include \"../../string/rolling-hash.hpp\"\n\
    #include \"../../data_structures/segtree.hpp\"\n\nRollingHash rh;\nstruct RHMonoid\
    \ {\n    using S = RHString;\n    static S op(const S& a, const S& b) { return\
    \ a + b; }\n    static S e() { return RHString(rh); }\n};\n\nint main() {\n  \
    \  int N, Q;\n    std::string S;\n    std::cin >> N >> Q >> S;\n    std::vector<RHString>\
    \ init;\n    init.reserve(N);\n    for (char c : S) {\n        init.emplace_back(rh,\
    \ c);\n    }\n    SegTree<RHMonoid> seg(init);\n    while (Q--) {\n        int\
    \ q;\n        std::cin >> q;\n        if (q == 1) {\n            int x;\n    \
    \        char c;\n            std::cin >> x >> c;\n            seg.set(x - 1,\
    \ RHString(rh, c));\n        } else {\n            int L, R;\n            std::cin\
    \ >> L >> R;\n            std::cout << (seg.prod(L - 1, R).is_palindrome() ? \"\
    Yes\" : \"No\") << std::endl;\n        }\n    }\n}"
  dependsOn:
  - string/rolling-hash.hpp
  - base/traits.hpp
  - data_structures/segtree.hpp
  - algebra/monoid.hpp
  isVerificationFile: false
  path: test/atcoder/abc331-f.cpp
  requiredBy: []
  timestamp: '2026-10-10 21:12:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc331-f.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc331-f.cpp
- /library/test/atcoder/abc331-f.cpp.html
title: test/atcoder/abc331-f.cpp
---
