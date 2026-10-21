---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-14-b.1.test.cpp
    title: test/aoj/alds1/alds1-14-b.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-14-c.test.cpp
    title: test/aoj/alds1/alds1-14-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/string/rolling-hash.test.cpp
    title: test/unittest/string/rolling-hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/string/enumerate-palindromes.1.test.cpp
    title: test/yosupo/string/enumerate-palindromes.1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
    links: []
  bundledCode: "#line 2 \"src/string/rolling-hash.hpp\"\n\n/**\n * @file rolling-hash.hpp\n\
    \ * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n */\n\n#include\
    \ <cassert>\n#include <iterator>\n#include <random>\n#include <string>\n#include\
    \ <string_view>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\
    \u7279\u6027\n */\n\n#include <cstddef>\n#line 10 \"src/utility/traits.hpp\"\n\
    #include <set>\n#line 13 \"src/utility/traits.hpp\"\n\nnamespace internal_traits\
    \ {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    #line 18 \"src/string/rolling-hash.hpp\"\n\nstruct RHString;\nclass RollingHash2D;\n\
    \n/**\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n *\n\
    \ * \u30D3\u30C3\u30C8\u6F14\u7B97\u306B\u3088\u308B\u9AD8\u901F\u5316\u306E\u305F\
    \u3081\u30CF\u30C3\u30B7\u30E5\u306FMOD = 2^61-1\u3067\u8A08\u7B97\u3055\u308C\
    \u308B\n *\n * 10^8\u500B\u304F\u3089\u3044\u306A\u308999%\u306E\u78BA\u7387\u3067\
    \u885D\u7A81\u3059\u308B\u7D44\u304C\u5B58\u5728\u3057\u306A\u3044\n */\nclass\
    \ RollingHash {\n    constexpr static unsigned long long MASK30 = (1ULL << 30)\
    \ - 1;\n    constexpr static unsigned long long MASK31 = (1ULL << 31) - 1;\n \
    \   constexpr static unsigned long long MOD = (1ULL << 61) - 1;\n\n    // a <\
    \ MOD, b < MOD\u5FC5\u9808\n    constexpr static unsigned long long add(unsigned\
    \ long long a, unsigned long long b) {\n        if ((a += b) >= MOD) a -= MOD;\n\
    \        return a;\n    }\n\n    // a < MOD, b < MOD\u5FC5\u9808\n    constexpr\
    \ static unsigned long long mul(unsigned long long a, unsigned long long b) {\n\
    \        __uint128_t c = static_cast<__uint128_t>(a) * b;\n        return add(static_cast<unsigned\
    \ long long>(c >> 61), static_cast<unsigned long long>(c & MOD));\n    }\n\n \
    \   void expand(long long n) {\n        while (static_cast<long long>(power.size())\
    \ <= n) power.push_back(mul(power.back(), base));\n    }\n    // base \u306E\u9006\
    \u5143\u306E\u7D2F\u4E57\u3092 n \u4E57\u307E\u3067\u7528\u610F\u3059\u308B (RHString\
    \ \u306E\u7AEF\u3092\u524A\u308B\u3068\u304D\u3060\u3051\u4F7F\u3046)\n    void\
    \ expand_inv(long long n) {\n        if (inv_power.empty()) {\n            //\
    \ MOD \u306F\u7D20\u6570\u306A\u306E\u3067 base^(MOD - 2) \u304C\u9006\u5143\n\
    \            unsigned long long inv = 1, b = base, e = MOD - 2;\n            for\
    \ (; e > 0; e >>= 1, b = mul(b, b))\n                if (e & 1) inv = mul(inv,\
    \ b);\n            inv_base = inv;\n            inv_power = {1};\n        }\n\
    \        while (static_cast<long long>(inv_power.size()) <= n) inv_power.push_back(mul(inv_power.back(),\
    \ inv_base));\n    }\n    unsigned long long inv_base = 0;\n    std::vector<unsigned\
    \ long long> inv_power;  // base \u306E\u9006\u5143\u306E\u7D2F\u4E57\n\n   public:\n\
    \    /**\n     * @brief \u8981\u7D20\u3092[0, MOD)\u306E\u5024\u306B\u5909\u63DB\
    \u3059\u308B\n     * @note char\u306F\u7B26\u53F7\u306B\u95A2\u308F\u3089\u305A\
    0~255\u3068\u3057\u3066\u6271\u3046 \u8CA0\u306E\u6574\u6570\u306FMOD\u3067\u6B63\
    \u898F\u5316\u3059\u308B\n     */\n    template <typename T>\n    constexpr static\
    \ unsigned long long to_value(const T& x) {\n        using U = std::decay_t<T>;\n\
    \        if constexpr (std::is_same_v<U, char> || std::is_same_v<U, signed char>)\
    \ {\n            return static_cast<unsigned char>(x);\n        } else if constexpr\
    \ (std::is_integral_v<U> && std::is_signed_v<U>) {\n            long long v =\
    \ static_cast<long long>(x) % static_cast<long long>(MOD);\n            return\
    \ v < 0 ? v + MOD : v;\n        } else {\n            return static_cast<unsigned\
    \ long long>(x) % MOD;\n        }\n    }\n\n    unsigned int base;           \
    \           //!< \u30CF\u30C3\u30B7\u30E5\u306E\u57FA\u6570\n    std::vector<unsigned\
    \ long long> power;  //!< base\u306E\u7D2F\u4E57\n\n    /**\n     * @brief \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param base \u30CF\u30C3\u30B7\
    \u30E5\u306E\u57FA\u6570 \u7701\u7565\u3059\u308B\u3068\u30E9\u30F3\u30C0\u30E0\
    \n     */\n    explicit RollingHash(unsigned int base = 0) : base(base) {\n  \
    \      if (base == 0) {\n            std::mt19937 mt(std::random_device{}());\n\
    \            this->base = std::uniform_int_distribution<unsigned int>(129, ~0U)(mt);\n\
    \        }\n        power = {1};\n    }\n\n    /**\n     * @brief \u914D\u5217\
    /\u6587\u5B57\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\u9593\u306E\u30CF\u30C3\
    \u30B7\u30E5\u306E\u8A08\u7B97(O(N))\n     *\n     * @tparam It \u30A4\u30C6\u30EC\
    \u30FC\u30BF\n     * @param first \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\
    \u30FC\u30BF\n     * @param last \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\
    \u30FC\u30BF\n     * @return std::vector<unsigned long long> \u5148\u982D\u304B\
    \u3089\u5404\u8981\u7D20\u6570\u5206\u306E\u30CF\u30C3\u30B7\u30E5\n     */\n\
    \    template <typename It>\n    std::vector<unsigned long long> build(It first,\
    \ It last) {\n        std::vector<unsigned long long> res;\n        if constexpr\
    \ (std::is_convertible_v<typename std::iterator_traits<It>::iterator_category,\
    \ std::random_access_iterator_tag>) {\n            res.reserve(last - first +\
    \ 1);\n        }\n        res.push_back(0);\n        for (; first != last; ++first)\
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
    \ long long query(const std::vector<unsigned long long>& hash, long long l, long\
    \ long r) {\n        assert(0 <= l && l <= r && r < static_cast<long long>(hash.size()));\n\
    \        expand(r - l);\n        return add(hash[r], MOD - mul(hash[l], power[r\
    \ - l]));\n    }\n\n    friend RHString;\n    friend RollingHash2D;\n};\n\n/**\n\
    \ * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u306B\u3088\u3063\
    \u3066\u7BA1\u7406\u3055\u308C\u308B\u6587\u5B57\u5217\u578B\n */\nstruct RHString\
    \ {\n    RollingHash& rh;\n    long long sz;              //!< \u9577\u3055\n\
    \    unsigned long long hash1;  //!< \u6B63\u9806\n    unsigned long long hash2;\
    \  //!< \u9006\u9806\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n     * \u4E88\u3081RollingHash\u3092\u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\
    \u5316\u3057\u3066\u304A\u304F\u5FC5\u8981\u304C\u3042\u308B\n     */\n    explicit\
    \ RHString(RollingHash& rh) : rh(rh), sz(0), hash1(0), hash2(0) {}\n    RHString(RollingHash&\
    \ rh, long long sz, unsigned long long hash1, unsigned long long hash2) : rh(rh),\
    \ sz(sz), hash1(hash1), hash2(hash2) {}\n    RHString(const RHString& o) : rh(o.rh),\
    \ sz(o.sz), hash1(o.hash1), hash2(o.hash2) {}\n    /**\n     * @brief vector\u306A\
    \u3069\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n    template <class R, ENABLE_IF_T(is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>)>\n    RHString(RollingHash&\
    \ rh, R&& v) : rh(rh) {\n        using std::begin, std::end, std::rbegin, std::rend;\n\
    \        sz = static_cast<long long>(std::distance(begin(v), end(v)));\n     \
    \   hash1 = rh.build(begin(v), end(v)).back();\n        hash2 = rh.build(rbegin(v),\
    \ rend(v)).back();\n    }\n    /**\n     * @brief char\u3084unsigned long long\u306A\
    \u3069\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n    template <class T, ENABLE_IF_T(std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>)>\n    RHString(RollingHash&\
    \ rh, T&& x) : rh(rh) {\n        sz = 1;\n        hash1 = RollingHash::to_value(x);\n\
    \        hash2 = hash1;\n    }\n    /**\n     * @brief \u6587\u5B57\u5217(string,\
    \ const char*, string_view)\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n   \
    \ RHString(RollingHash& rh, std::string_view s) : rh(rh) {\n        sz = static_cast<long\
    \ long>(s.size());\n        hash1 = rh.build(s.begin(), s.end()).back();\n   \
    \     hash2 = rh.build(s.rbegin(), s.rend()).back();\n    }\n\n    /**\n     *\
    \ @brief \u56DE\u6587\u304B\u5426\u304B\n     */\n    bool is_palindrome() const\
    \ {\n        return hash1 == hash2;\n    }\n    long long size() const {\n   \
    \     return sz;\n    }\n    void clear() {\n        sz = 0;\n        hash1 =\
    \ 0;\n        hash2 = 0;\n    }\n    bool empty() const {\n        return sz ==\
    \ 0;\n    }\n    /**\n     * @brief \u5148\u982D\u306E t \u3092\u53D6\u308A\u9664\
    \u304F (\u5148\u982D\u304C t \u3067\u3042\u308B\u3053\u3068\u3002\u30CF\u30C3\u30B7\
    \u30E5\u304B\u3089\u306F\u78BA\u304B\u3081\u3089\u308C\u306A\u3044\u306E\u3067\
    \u3001\u9055\u3046\u3068\u5024\u304C\u58CA\u308C\u308B) O(1) (\u7D2F\u4E57\u306E\
    \u8868\u3092\u4F38\u3070\u3059\u5206\u3092\u9664\u304F)\n     * t \u306F RHString\
    \ \u306E\u307B\u304B\u3001RHString \u3092\u4F5C\u308C\u308B\u3082\u306E (\u6587\
    \u5B57\u30FB\u6587\u5B57\u5217\u306A\u3069) \u3067\u3082\u3088\u3044\n     */\n\
    \    void remove_prefix(const RHString& t) {\n        assert(&rh == &t.rh && t.sz\
    \ <= sz);\n        // s = t + u \u304B\u3089 u: hash1(u) = hash1(s) - hash1(t)\
    \ B^|u|\u3001hash2(u) = (hash2(s) - hash2(t)) B^-|t|\n        const long long\
    \ u = sz - t.sz;\n        rh.expand(u);\n        rh.expand_inv(t.sz);\n      \
    \  hash1 = rh.add(hash1, RollingHash::MOD - rh.mul(t.hash1, rh.power[u]));\n \
    \       hash2 = rh.mul(rh.add(hash2, RollingHash::MOD - t.hash2), rh.inv_power[t.sz]);\n\
    \        sz = u;\n    }\n    /**\n     * @brief \u672B\u5C3E\u306E t \u3092\u53D6\
    \u308A\u9664\u304F (\u672B\u5C3E\u304C t \u3067\u3042\u308B\u3053\u3068\u3002\u30CF\
    \u30C3\u30B7\u30E5\u304B\u3089\u306F\u78BA\u304B\u3081\u3089\u308C\u306A\u3044\
    \u306E\u3067\u3001\u9055\u3046\u3068\u5024\u304C\u58CA\u308C\u308B) O(1) (\u7D2F\
    \u4E57\u306E\u8868\u3092\u4F38\u3070\u3059\u5206\u3092\u9664\u304F)\n     * t\
    \ \u306F RHString \u306E\u307B\u304B\u3001RHString \u3092\u4F5C\u308C\u308B\u3082\
    \u306E (\u6587\u5B57\u30FB\u6587\u5B57\u5217\u306A\u3069) \u3067\u3082\u3088\u3044\
    \n     */\n    void remove_suffix(const RHString& t) {\n        assert(&rh ==\
    \ &t.rh && t.sz <= sz);\n        // s = u + t \u304B\u3089 u: hash1(u) = (hash1(s)\
    \ - hash1(t)) B^-|t|\u3001hash2(u) = hash2(s) - hash2(t) B^|u|\n        const\
    \ long long u = sz - t.sz;\n        rh.expand(u);\n        rh.expand_inv(t.sz);\n\
    \        hash1 = rh.mul(rh.add(hash1, RollingHash::MOD - t.hash1), rh.inv_power[t.sz]);\n\
    \        hash2 = rh.add(hash2, RollingHash::MOD - rh.mul(t.hash2, rh.power[u]));\n\
    \        sz = u;\n    }\n    template <class T, ENABLE_IF_T(!std::is_same_v<std::decay_t<T>,\
    \ RHString>)>\n    void remove_prefix(T&& x) {\n        remove_prefix(RHString(rh,\
    \ std::forward<T>(x)));\n    }\n    template <class T, ENABLE_IF_T(!std::is_same_v<std::decay_t<T>,\
    \ RHString>)>\n    void remove_suffix(T&& x) {\n        remove_suffix(RHString(rh,\
    \ std::forward<T>(x)));\n    }\n    RHString& operator+=(const RHString& o) {\n\
    \        assert(&rh == &o.rh);\n        rh.expand(sz);\n        rh.expand(o.sz);\n\
    \        hash1 = rh.add(rh.mul(hash1, rh.power[o.sz]), o.hash1);\n        hash2\
    \ = rh.add(hash2, rh.mul(o.hash2, rh.power[sz]));\n        sz += o.sz;\n     \
    \   return *this;\n    }\n    /**\n     * @brief \u518D\u4EE3\u5165\u3059\u308B\
    \n     * RollingHash\u306F\u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\n     */\n    void assign(const RHString& o) {\n        assert(&rh\
    \ == &o.rh);\n        sz = o.sz;\n        hash1 = o.hash1;\n        hash2 = o.hash2;\n\
    \    }\n    /**\n     * @brief vector\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\
    \u308B\n     */\n    template <class R, ENABLE_IF_T(is_range_v<R> && !std::is_convertible_v<R,\
    \ std::string_view>)>\n    void assign(R&& v) {\n        using std::begin, std::end,\
    \ std::rbegin, std::rend;\n        sz = static_cast<long long>(std::distance(begin(v),\
    \ end(v)));\n        hash1 = rh.build(begin(v), end(v)).back();\n        hash2\
    \ = rh.build(rbegin(v), rend(v)).back();\n    }\n    /**\n     * @brief char\u3084\
    unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\n     */\n\
    \    template <class T, ENABLE_IF_T(std::is_convertible_v<T, unsigned long long>\
    \ && !std::is_convertible_v<T, std::string_view>)>\n    void assign(T&& x) {\n\
    \        sz = 1;\n        hash1 = RollingHash::to_value(x);\n        hash2 = hash1;\n\
    \    }\n    /**\n     * @brief \u6587\u5B57\u5217(string, const char*, string_view)\u3092\
    \u518D\u4EE3\u5165\u3059\u308B\n     */\n    void assign(std::string_view s) {\n\
    \        sz = static_cast<long long>(s.size());\n        hash1 = rh.build(s.begin(),\
    \ s.end()).back();\n        hash2 = rh.build(s.rbegin(), s.rend()).back();\n \
    \   }\n    /**\n     * @brief \u518D\u4EE3\u5165\u3059\u308B\n     * RollingHash\u306F\
    \u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n   \
    \  */\n    RHString& operator=(const RHString& o) {\n        assign(o);\n    \
    \    return *this;\n    }\n    /**\n     * @brief vector\u306A\u3069\u3092\u518D\
    \u4EE3\u5165\u3059\u308B\n     */\n    template <class R, ENABLE_IF_T(is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>)>\n    RHString& operator=(R&&\
    \ v) {\n        assign(v);\n        return *this;\n    }\n    /**\n     * @brief\
    \ char\u3084unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\
    \n     */\n    template <class T, ENABLE_IF_T(std::is_convertible_v<T, unsigned\
    \ long long> && !std::is_convertible_v<T, std::string_view>)>\n    RHString& operator=(T&&\
    \ x) {\n        assign(x);\n        return *this;\n    }\n    /**\n     * @brief\
    \ \u6587\u5B57\u5217(string, const char*, string_view)\u3092\u518D\u4EE3\u5165\
    \u3059\u308B\n     */\n    RHString& operator=(std::string_view s) {\n       \
    \ assign(s);\n        return *this;\n    }\n    friend RHString operator+(const\
    \ RHString& t1, const RHString& t2) {\n        RHString ret = t1;\n        ret\
    \ += t2;\n        return ret;\n    }\n    friend bool operator==(const RHString&\
    \ t1, const RHString& t2) {\n        assert(&t1.rh == &t2.rh);\n        return\
    \ t1.sz == t2.sz && t1.hash1 == t2.hash1 && t1.hash2 == t2.hash2;\n    }\n   \
    \ friend bool operator!=(const RHString& t1, const RHString& t2) { return !(t1\
    \ == t2); }\n};\n\n/**\n * @brief 2 \u6B21\u5143\u306E\u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\n *\n * \u884C\u65B9\u5411\u3068\u5217\u65B9\u5411\
    \u3067\u5225\u306E\u57FA\u6570\u3092\u4F7F\u3044\u3001\u8868\u306E\u5DE6\u4E0A\
    \u304B\u3089\u306E\u7D2F\u7A4D\u30CF\u30C3\u30B7\u30E5\u3067\u9577\u65B9\u5F62\
    \u306E\u30CF\u30C3\u30B7\u30E5\u3092 O(1) \u3067\u6C42\u3081\u308B\n * H[i][j]\
    \ = \u03A3_{a < i, b < j} v[a][b] base1^(i-1-a) base2^(j-1-b)\n */\nclass RollingHash2D\
    \ {\n    using ull = unsigned long long;\n    RollingHash rh1, rh2;  // \u884C\
    \u65B9\u5411 (\u4E0A\u4E0B) \u3068\u5217\u65B9\u5411 (\u5DE6\u53F3)\n\n    static\
    \ ull add(ull a, ull b) { return RollingHash::add(a, b); }\n    static ull sub(ull\
    \ a, ull b) { return RollingHash::add(a, RollingHash::MOD - b); }\n    static\
    \ ull mul(ull a, ull b) { return RollingHash::mul(a, b); }\n\n   public:\n   \
    \ /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n    \
    \ * @param base1 \u884C\u65B9\u5411\u306E\u57FA\u6570 \u7701\u7565\u3059\u308B\
    \u3068\u30E9\u30F3\u30C0\u30E0\n     * @param base2 \u5217\u65B9\u5411\u306E\u57FA\
    \u6570 \u7701\u7565\u3059\u308B\u3068\u30E9\u30F3\u30C0\u30E0\n     */\n    explicit\
    \ RollingHash2D(unsigned int base1 = 0, unsigned int base2 = 0) : rh1(base1),\
    \ rh2(base2) {}\n\n    /**\n     * @brief \u8868 (std::vector<std::string> \u3084\
    \ std::vector<std::vector<T>>) \u306E\u7D2F\u7A4D\u30CF\u30C3\u30B7\u30E5 O(HW)\n\
    \     *\n     * @return std::vector<std::vector<unsigned long long>> (H + 1) \u884C\
    \ (W + 1) \u5217\u306E\u8868\u3002[i][j] \u306F\u5DE6\u4E0A i \u884C j \u5217\u306E\
    \u30CF\u30C3\u30B7\u30E5\n     */\n    template <typename Grid>\n    std::vector<std::vector<ull>>\
    \ build(const Grid& grid) {\n        using std::size;\n        const long long\
    \ h = size(grid), w = h == 0 ? 0 : size(grid[0]);\n        std::vector<std::vector<ull>>\
    \ res(h + 1, std::vector<ull>(w + 1, 0));\n        const ull b1 = rh1.base, b2\
    \ = rh2.base, b12 = mul(b1, b2);\n        for (long long i = 0; i < h; i++) {\n\
    \            assert(static_cast<long long>(size(grid[i])) == w);\n           \
    \ for (long long j = 0; j < w; j++) {\n                ull v = add(mul(res[i][j\
    \ + 1], b1), mul(res[i + 1][j], b2));\n                res[i + 1][j + 1] = add(sub(v,\
    \ mul(res[i][j], b12)), RollingHash::to_value(grid[i][j]));\n            }\n \
    \       }\n        return res;\n    }\n\n    /**\n     * @brief \u884C [i1, i2)\u3001\
    \u5217 [j1, j2) \u306E\u9577\u65B9\u5F62\u306E\u30CF\u30C3\u30B7\u30E5 O(1) (\u521D\
    \u56DE\u306F\u9577\u3055\u5206)\n     */\n    ull query(const std::vector<std::vector<ull>>&\
    \ hash, long long i1, long long j1, long long i2, long long j2) {\n        assert(0\
    \ <= i1 && i1 <= i2 && i2 < static_cast<long long>(hash.size()));\n        assert(0\
    \ <= j1 && j1 <= j2 && j2 < static_cast<long long>(hash[0].size()));\n       \
    \ rh1.expand(i2 - i1);\n        rh2.expand(j2 - j1);\n        ull p1 = rh1.power[i2\
    \ - i1], p2 = rh2.power[j2 - j1];\n        ull res = sub(hash[i2][j2], mul(hash[i1][j2],\
    \ p1));\n        res = sub(res, mul(hash[i2][j1], p2));\n        return add(res,\
    \ mul(mul(hash[i1][j1], p1), p2));\n    }\n};\n\n/**\n * @brief \u8868 text \u306E\
    \u4E2D\u3067\u3001\u8868 pattern \u3068\u4E00\u81F4\u3059\u308B\u90E8\u5206\u306E\
    \u5DE6\u4E0A\u306E\u4F4D\u7F6E (\u884C, \u5217) \u3092\u3059\u3079\u3066\u6C42\
    \u3081\u308B O(HW + hw)\n *\n * 2 \u6B21\u5143\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\
    \u30CF\u30C3\u30B7\u30E5\u3067\u6BD4\u3079\u308B\u3002\u884C\u306E\u6607\u9806\
    \u3001\u540C\u3058\u884C\u306A\u3089\u5217\u306E\u6607\u9806\u306B\u4E26\u3079\
    \u308B\n * pattern \u306F 1 \u884C 1 \u5217\u4EE5\u4E0A\u3067\u3042\u308B\u3053\
    \u3068\n */\ntemplate <typename Grid1, typename Grid2>\nstd::vector<std::pair<long\
    \ long, long long>> pattern_match_2d(const Grid1& text, const Grid2& pattern)\
    \ {\n    using std::size;\n    const long long h = size(text), w = h == 0 ? 0\
    \ : size(text[0]);\n    const long long ph = size(pattern), pw = ph == 0 ? 0 :\
    \ size(pattern[0]);\n    assert(ph > 0 && pw > 0);\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    if (ph > h || pw > w) return res;\n    RollingHash2D\
    \ rh;\n    auto th = rh.build(text), pht = rh.build(pattern);\n    unsigned long\
    \ long target = rh.query(pht, 0, 0, ph, pw);\n    for (long long i = 0; i + ph\
    \ <= h; i++) {\n        for (long long j = 0; j + pw <= w; j++) {\n          \
    \  if (rh.query(th, i, j, i + ph, j + pw) == target) res.emplace_back(i, j);\n\
    \        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file rolling-hash.hpp\n * @brief \u30ED\u30FC\u30EA\
    \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n */\n\n#include <cassert>\n#include <iterator>\n\
    #include <random>\n#include <string>\n#include <string_view>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\n#include \"../utility/traits.hpp\"\n\n\
    struct RHString;\nclass RollingHash2D;\n\n/**\n * @brief \u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\n *\n * \u30D3\u30C3\u30C8\u6F14\u7B97\u306B\u3088\
    \u308B\u9AD8\u901F\u5316\u306E\u305F\u3081\u30CF\u30C3\u30B7\u30E5\u306FMOD =\
    \ 2^61-1\u3067\u8A08\u7B97\u3055\u308C\u308B\n *\n * 10^8\u500B\u304F\u3089\u3044\
    \u306A\u308999%\u306E\u78BA\u7387\u3067\u885D\u7A81\u3059\u308B\u7D44\u304C\u5B58\
    \u5728\u3057\u306A\u3044\n */\nclass RollingHash {\n    constexpr static unsigned\
    \ long long MASK30 = (1ULL << 30) - 1;\n    constexpr static unsigned long long\
    \ MASK31 = (1ULL << 31) - 1;\n    constexpr static unsigned long long MOD = (1ULL\
    \ << 61) - 1;\n\n    // a < MOD, b < MOD\u5FC5\u9808\n    constexpr static unsigned\
    \ long long add(unsigned long long a, unsigned long long b) {\n        if ((a\
    \ += b) >= MOD) a -= MOD;\n        return a;\n    }\n\n    // a < MOD, b < MOD\u5FC5\
    \u9808\n    constexpr static unsigned long long mul(unsigned long long a, unsigned\
    \ long long b) {\n        __uint128_t c = static_cast<__uint128_t>(a) * b;\n \
    \       return add(static_cast<unsigned long long>(c >> 61), static_cast<unsigned\
    \ long long>(c & MOD));\n    }\n\n    void expand(long long n) {\n        while\
    \ (static_cast<long long>(power.size()) <= n) power.push_back(mul(power.back(),\
    \ base));\n    }\n    // base \u306E\u9006\u5143\u306E\u7D2F\u4E57\u3092 n \u4E57\
    \u307E\u3067\u7528\u610F\u3059\u308B (RHString \u306E\u7AEF\u3092\u524A\u308B\u3068\
    \u304D\u3060\u3051\u4F7F\u3046)\n    void expand_inv(long long n) {\n        if\
    \ (inv_power.empty()) {\n            // MOD \u306F\u7D20\u6570\u306A\u306E\u3067\
    \ base^(MOD - 2) \u304C\u9006\u5143\n            unsigned long long inv = 1, b\
    \ = base, e = MOD - 2;\n            for (; e > 0; e >>= 1, b = mul(b, b))\n  \
    \              if (e & 1) inv = mul(inv, b);\n            inv_base = inv;\n  \
    \          inv_power = {1};\n        }\n        while (static_cast<long long>(inv_power.size())\
    \ <= n) inv_power.push_back(mul(inv_power.back(), inv_base));\n    }\n    unsigned\
    \ long long inv_base = 0;\n    std::vector<unsigned long long> inv_power;  //\
    \ base \u306E\u9006\u5143\u306E\u7D2F\u4E57\n\n   public:\n    /**\n     * @brief\
    \ \u8981\u7D20\u3092[0, MOD)\u306E\u5024\u306B\u5909\u63DB\u3059\u308B\n     *\
    \ @note char\u306F\u7B26\u53F7\u306B\u95A2\u308F\u3089\u305A0~255\u3068\u3057\u3066\
    \u6271\u3046 \u8CA0\u306E\u6574\u6570\u306FMOD\u3067\u6B63\u898F\u5316\u3059\u308B\
    \n     */\n    template <typename T>\n    constexpr static unsigned long long\
    \ to_value(const T& x) {\n        using U = std::decay_t<T>;\n        if constexpr\
    \ (std::is_same_v<U, char> || std::is_same_v<U, signed char>) {\n            return\
    \ static_cast<unsigned char>(x);\n        } else if constexpr (std::is_integral_v<U>\
    \ && std::is_signed_v<U>) {\n            long long v = static_cast<long long>(x)\
    \ % static_cast<long long>(MOD);\n            return v < 0 ? v + MOD : v;\n  \
    \      } else {\n            return static_cast<unsigned long long>(x) % MOD;\n\
    \        }\n    }\n\n    unsigned int base;                      //!< \u30CF\u30C3\
    \u30B7\u30E5\u306E\u57FA\u6570\n    std::vector<unsigned long long> power;  //!<\
    \ base\u306E\u7D2F\u4E57\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     *\n     * @param base \u30CF\u30C3\u30B7\u30E5\u306E\u57FA\u6570\
    \ \u7701\u7565\u3059\u308B\u3068\u30E9\u30F3\u30C0\u30E0\n     */\n    explicit\
    \ RollingHash(unsigned int base = 0) : base(base) {\n        if (base == 0) {\n\
    \            std::mt19937 mt(std::random_device{}());\n            this->base\
    \ = std::uniform_int_distribution<unsigned int>(129, ~0U)(mt);\n        }\n  \
    \      power = {1};\n    }\n\n    /**\n     * @brief \u914D\u5217/\u6587\u5B57\
    \u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\u9593\u306E\u30CF\u30C3\u30B7\u30E5\
    \u306E\u8A08\u7B97(O(N))\n     *\n     * @tparam It \u30A4\u30C6\u30EC\u30FC\u30BF\
    \n     * @param first \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n     * @param last \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n     * @return std::vector<unsigned long long> \u5148\u982D\u304B\u3089\u5404\
    \u8981\u7D20\u6570\u5206\u306E\u30CF\u30C3\u30B7\u30E5\n     */\n    template\
    \ <typename It>\n    std::vector<unsigned long long> build(It first, It last)\
    \ {\n        std::vector<unsigned long long> res;\n        if constexpr (std::is_convertible_v<typename\
    \ std::iterator_traits<It>::iterator_category, std::random_access_iterator_tag>)\
    \ {\n            res.reserve(last - first + 1);\n        }\n        res.push_back(0);\n\
    \        for (; first != last; ++first) {\n            res.push_back(add(mul(res.back(),\
    \ base), to_value(*first)));\n        }\n        return res;\n    }\n\n    /**\n\
    \     * @brief \u914D\u5217/\u6587\u5B57\u5217\u5168\u4F53\u306E\u30CF\u30C3\u30B7\
    \u30E5\u306E\u8A08\u7B97(O(N))\n     *\n     * @param s \u914D\u5217/\u6587\u5B57\
    \u5217\n     * @return std::vector<unsigned long long> \u5148\u982D\u304B\u3089\
    \u5404\u6587\u5B57\u6570\u5206\u306E\u30CF\u30C3\u30B7\u30E5\n     */\n    template\
    \ <typename R>\n    std::vector<unsigned long long> build(R&& s) {\n        using\
    \ std::begin, std::end;\n        return build(begin(s), end(s));\n    }\n\n  \
    \  /**\n     * @brief [l,r)\u306E\u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97(O(1))\n\
    \     *\n     * @param hash \u5148\u982D\u304B\u3089\u306E\u30CF\u30C3\u30B7\u30E5\
    \n     * @param l \u533A\u9593\u306E\u5DE6\u7AEF\n     * @param r \u533A\u9593\
    \u306E\u53F3\u7AEF\n     * @return unsigned long long [l,r)\u306E\u30CF\u30C3\u30B7\
    \u30E5\n     */\n    unsigned long long query(const std::vector<unsigned long\
    \ long>& hash, long long l, long long r) {\n        assert(0 <= l && l <= r &&\
    \ r < static_cast<long long>(hash.size()));\n        expand(r - l);\n        return\
    \ add(hash[r], MOD - mul(hash[l], power[r - l]));\n    }\n\n    friend RHString;\n\
    \    friend RollingHash2D;\n};\n\n/**\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\
    \u30CF\u30C3\u30B7\u30E5\u306B\u3088\u3063\u3066\u7BA1\u7406\u3055\u308C\u308B\
    \u6587\u5B57\u5217\u578B\n */\nstruct RHString {\n    RollingHash& rh;\n    long\
    \ long sz;              //!< \u9577\u3055\n    unsigned long long hash1;  //!<\
    \ \u6B63\u9806\n    unsigned long long hash2;  //!< \u9006\u9806\n    /**\n  \
    \   * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * \u4E88\u3081RollingHash\u3092\
    \u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\u5316\u3057\u3066\u304A\u304F\u5FC5\u8981\
    \u304C\u3042\u308B\n     */\n    explicit RHString(RollingHash& rh) : rh(rh),\
    \ sz(0), hash1(0), hash2(0) {}\n    RHString(RollingHash& rh, long long sz, unsigned\
    \ long long hash1, unsigned long long hash2) : rh(rh), sz(sz), hash1(hash1), hash2(hash2)\
    \ {}\n    RHString(const RHString& o) : rh(o.rh), sz(o.sz), hash1(o.hash1), hash2(o.hash2)\
    \ {}\n    /**\n     * @brief vector\u306A\u3069\u3067\u521D\u671F\u5316\u3059\u308B\
    \n     */\n    template <class R, ENABLE_IF_T(is_range_v<R> && !std::is_convertible_v<R,\
    \ std::string_view>)>\n    RHString(RollingHash& rh, R&& v) : rh(rh) {\n     \
    \   using std::begin, std::end, std::rbegin, std::rend;\n        sz = static_cast<long\
    \ long>(std::distance(begin(v), end(v)));\n        hash1 = rh.build(begin(v),\
    \ end(v)).back();\n        hash2 = rh.build(rbegin(v), rend(v)).back();\n    }\n\
    \    /**\n     * @brief char\u3084unsigned long long\u306A\u3069\u3067\u521D\u671F\
    \u5316\u3059\u308B\n     */\n    template <class T, ENABLE_IF_T(std::is_convertible_v<T,\
    \ unsigned long long> && !std::is_convertible_v<T, std::string_view>)>\n    RHString(RollingHash&\
    \ rh, T&& x) : rh(rh) {\n        sz = 1;\n        hash1 = RollingHash::to_value(x);\n\
    \        hash2 = hash1;\n    }\n    /**\n     * @brief \u6587\u5B57\u5217(string,\
    \ const char*, string_view)\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n   \
    \ RHString(RollingHash& rh, std::string_view s) : rh(rh) {\n        sz = static_cast<long\
    \ long>(s.size());\n        hash1 = rh.build(s.begin(), s.end()).back();\n   \
    \     hash2 = rh.build(s.rbegin(), s.rend()).back();\n    }\n\n    /**\n     *\
    \ @brief \u56DE\u6587\u304B\u5426\u304B\n     */\n    bool is_palindrome() const\
    \ {\n        return hash1 == hash2;\n    }\n    long long size() const {\n   \
    \     return sz;\n    }\n    void clear() {\n        sz = 0;\n        hash1 =\
    \ 0;\n        hash2 = 0;\n    }\n    bool empty() const {\n        return sz ==\
    \ 0;\n    }\n    /**\n     * @brief \u5148\u982D\u306E t \u3092\u53D6\u308A\u9664\
    \u304F (\u5148\u982D\u304C t \u3067\u3042\u308B\u3053\u3068\u3002\u30CF\u30C3\u30B7\
    \u30E5\u304B\u3089\u306F\u78BA\u304B\u3081\u3089\u308C\u306A\u3044\u306E\u3067\
    \u3001\u9055\u3046\u3068\u5024\u304C\u58CA\u308C\u308B) O(1) (\u7D2F\u4E57\u306E\
    \u8868\u3092\u4F38\u3070\u3059\u5206\u3092\u9664\u304F)\n     * t \u306F RHString\
    \ \u306E\u307B\u304B\u3001RHString \u3092\u4F5C\u308C\u308B\u3082\u306E (\u6587\
    \u5B57\u30FB\u6587\u5B57\u5217\u306A\u3069) \u3067\u3082\u3088\u3044\n     */\n\
    \    void remove_prefix(const RHString& t) {\n        assert(&rh == &t.rh && t.sz\
    \ <= sz);\n        // s = t + u \u304B\u3089 u: hash1(u) = hash1(s) - hash1(t)\
    \ B^|u|\u3001hash2(u) = (hash2(s) - hash2(t)) B^-|t|\n        const long long\
    \ u = sz - t.sz;\n        rh.expand(u);\n        rh.expand_inv(t.sz);\n      \
    \  hash1 = rh.add(hash1, RollingHash::MOD - rh.mul(t.hash1, rh.power[u]));\n \
    \       hash2 = rh.mul(rh.add(hash2, RollingHash::MOD - t.hash2), rh.inv_power[t.sz]);\n\
    \        sz = u;\n    }\n    /**\n     * @brief \u672B\u5C3E\u306E t \u3092\u53D6\
    \u308A\u9664\u304F (\u672B\u5C3E\u304C t \u3067\u3042\u308B\u3053\u3068\u3002\u30CF\
    \u30C3\u30B7\u30E5\u304B\u3089\u306F\u78BA\u304B\u3081\u3089\u308C\u306A\u3044\
    \u306E\u3067\u3001\u9055\u3046\u3068\u5024\u304C\u58CA\u308C\u308B) O(1) (\u7D2F\
    \u4E57\u306E\u8868\u3092\u4F38\u3070\u3059\u5206\u3092\u9664\u304F)\n     * t\
    \ \u306F RHString \u306E\u307B\u304B\u3001RHString \u3092\u4F5C\u308C\u308B\u3082\
    \u306E (\u6587\u5B57\u30FB\u6587\u5B57\u5217\u306A\u3069) \u3067\u3082\u3088\u3044\
    \n     */\n    void remove_suffix(const RHString& t) {\n        assert(&rh ==\
    \ &t.rh && t.sz <= sz);\n        // s = u + t \u304B\u3089 u: hash1(u) = (hash1(s)\
    \ - hash1(t)) B^-|t|\u3001hash2(u) = hash2(s) - hash2(t) B^|u|\n        const\
    \ long long u = sz - t.sz;\n        rh.expand(u);\n        rh.expand_inv(t.sz);\n\
    \        hash1 = rh.mul(rh.add(hash1, RollingHash::MOD - t.hash1), rh.inv_power[t.sz]);\n\
    \        hash2 = rh.add(hash2, RollingHash::MOD - rh.mul(t.hash2, rh.power[u]));\n\
    \        sz = u;\n    }\n    template <class T, ENABLE_IF_T(!std::is_same_v<std::decay_t<T>,\
    \ RHString>)>\n    void remove_prefix(T&& x) {\n        remove_prefix(RHString(rh,\
    \ std::forward<T>(x)));\n    }\n    template <class T, ENABLE_IF_T(!std::is_same_v<std::decay_t<T>,\
    \ RHString>)>\n    void remove_suffix(T&& x) {\n        remove_suffix(RHString(rh,\
    \ std::forward<T>(x)));\n    }\n    RHString& operator+=(const RHString& o) {\n\
    \        assert(&rh == &o.rh);\n        rh.expand(sz);\n        rh.expand(o.sz);\n\
    \        hash1 = rh.add(rh.mul(hash1, rh.power[o.sz]), o.hash1);\n        hash2\
    \ = rh.add(hash2, rh.mul(o.hash2, rh.power[sz]));\n        sz += o.sz;\n     \
    \   return *this;\n    }\n    /**\n     * @brief \u518D\u4EE3\u5165\u3059\u308B\
    \n     * RollingHash\u306F\u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\n     */\n    void assign(const RHString& o) {\n        assert(&rh\
    \ == &o.rh);\n        sz = o.sz;\n        hash1 = o.hash1;\n        hash2 = o.hash2;\n\
    \    }\n    /**\n     * @brief vector\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\
    \u308B\n     */\n    template <class R, ENABLE_IF_T(is_range_v<R> && !std::is_convertible_v<R,\
    \ std::string_view>)>\n    void assign(R&& v) {\n        using std::begin, std::end,\
    \ std::rbegin, std::rend;\n        sz = static_cast<long long>(std::distance(begin(v),\
    \ end(v)));\n        hash1 = rh.build(begin(v), end(v)).back();\n        hash2\
    \ = rh.build(rbegin(v), rend(v)).back();\n    }\n    /**\n     * @brief char\u3084\
    unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\n     */\n\
    \    template <class T, ENABLE_IF_T(std::is_convertible_v<T, unsigned long long>\
    \ && !std::is_convertible_v<T, std::string_view>)>\n    void assign(T&& x) {\n\
    \        sz = 1;\n        hash1 = RollingHash::to_value(x);\n        hash2 = hash1;\n\
    \    }\n    /**\n     * @brief \u6587\u5B57\u5217(string, const char*, string_view)\u3092\
    \u518D\u4EE3\u5165\u3059\u308B\n     */\n    void assign(std::string_view s) {\n\
    \        sz = static_cast<long long>(s.size());\n        hash1 = rh.build(s.begin(),\
    \ s.end()).back();\n        hash2 = rh.build(s.rbegin(), s.rend()).back();\n \
    \   }\n    /**\n     * @brief \u518D\u4EE3\u5165\u3059\u308B\n     * RollingHash\u306F\
    \u540C\u3058\u3082\u306E\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n   \
    \  */\n    RHString& operator=(const RHString& o) {\n        assign(o);\n    \
    \    return *this;\n    }\n    /**\n     * @brief vector\u306A\u3069\u3092\u518D\
    \u4EE3\u5165\u3059\u308B\n     */\n    template <class R, ENABLE_IF_T(is_range_v<R>\
    \ && !std::is_convertible_v<R, std::string_view>)>\n    RHString& operator=(R&&\
    \ v) {\n        assign(v);\n        return *this;\n    }\n    /**\n     * @brief\
    \ char\u3084unsigned long long\u306A\u3069\u3092\u518D\u4EE3\u5165\u3059\u308B\
    \n     */\n    template <class T, ENABLE_IF_T(std::is_convertible_v<T, unsigned\
    \ long long> && !std::is_convertible_v<T, std::string_view>)>\n    RHString& operator=(T&&\
    \ x) {\n        assign(x);\n        return *this;\n    }\n    /**\n     * @brief\
    \ \u6587\u5B57\u5217(string, const char*, string_view)\u3092\u518D\u4EE3\u5165\
    \u3059\u308B\n     */\n    RHString& operator=(std::string_view s) {\n       \
    \ assign(s);\n        return *this;\n    }\n    friend RHString operator+(const\
    \ RHString& t1, const RHString& t2) {\n        RHString ret = t1;\n        ret\
    \ += t2;\n        return ret;\n    }\n    friend bool operator==(const RHString&\
    \ t1, const RHString& t2) {\n        assert(&t1.rh == &t2.rh);\n        return\
    \ t1.sz == t2.sz && t1.hash1 == t2.hash1 && t1.hash2 == t2.hash2;\n    }\n   \
    \ friend bool operator!=(const RHString& t1, const RHString& t2) { return !(t1\
    \ == t2); }\n};\n\n/**\n * @brief 2 \u6B21\u5143\u306E\u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\n *\n * \u884C\u65B9\u5411\u3068\u5217\u65B9\u5411\
    \u3067\u5225\u306E\u57FA\u6570\u3092\u4F7F\u3044\u3001\u8868\u306E\u5DE6\u4E0A\
    \u304B\u3089\u306E\u7D2F\u7A4D\u30CF\u30C3\u30B7\u30E5\u3067\u9577\u65B9\u5F62\
    \u306E\u30CF\u30C3\u30B7\u30E5\u3092 O(1) \u3067\u6C42\u3081\u308B\n * H[i][j]\
    \ = \u03A3_{a < i, b < j} v[a][b] base1^(i-1-a) base2^(j-1-b)\n */\nclass RollingHash2D\
    \ {\n    using ull = unsigned long long;\n    RollingHash rh1, rh2;  // \u884C\
    \u65B9\u5411 (\u4E0A\u4E0B) \u3068\u5217\u65B9\u5411 (\u5DE6\u53F3)\n\n    static\
    \ ull add(ull a, ull b) { return RollingHash::add(a, b); }\n    static ull sub(ull\
    \ a, ull b) { return RollingHash::add(a, RollingHash::MOD - b); }\n    static\
    \ ull mul(ull a, ull b) { return RollingHash::mul(a, b); }\n\n   public:\n   \
    \ /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n    \
    \ * @param base1 \u884C\u65B9\u5411\u306E\u57FA\u6570 \u7701\u7565\u3059\u308B\
    \u3068\u30E9\u30F3\u30C0\u30E0\n     * @param base2 \u5217\u65B9\u5411\u306E\u57FA\
    \u6570 \u7701\u7565\u3059\u308B\u3068\u30E9\u30F3\u30C0\u30E0\n     */\n    explicit\
    \ RollingHash2D(unsigned int base1 = 0, unsigned int base2 = 0) : rh1(base1),\
    \ rh2(base2) {}\n\n    /**\n     * @brief \u8868 (std::vector<std::string> \u3084\
    \ std::vector<std::vector<T>>) \u306E\u7D2F\u7A4D\u30CF\u30C3\u30B7\u30E5 O(HW)\n\
    \     *\n     * @return std::vector<std::vector<unsigned long long>> (H + 1) \u884C\
    \ (W + 1) \u5217\u306E\u8868\u3002[i][j] \u306F\u5DE6\u4E0A i \u884C j \u5217\u306E\
    \u30CF\u30C3\u30B7\u30E5\n     */\n    template <typename Grid>\n    std::vector<std::vector<ull>>\
    \ build(const Grid& grid) {\n        using std::size;\n        const long long\
    \ h = size(grid), w = h == 0 ? 0 : size(grid[0]);\n        std::vector<std::vector<ull>>\
    \ res(h + 1, std::vector<ull>(w + 1, 0));\n        const ull b1 = rh1.base, b2\
    \ = rh2.base, b12 = mul(b1, b2);\n        for (long long i = 0; i < h; i++) {\n\
    \            assert(static_cast<long long>(size(grid[i])) == w);\n           \
    \ for (long long j = 0; j < w; j++) {\n                ull v = add(mul(res[i][j\
    \ + 1], b1), mul(res[i + 1][j], b2));\n                res[i + 1][j + 1] = add(sub(v,\
    \ mul(res[i][j], b12)), RollingHash::to_value(grid[i][j]));\n            }\n \
    \       }\n        return res;\n    }\n\n    /**\n     * @brief \u884C [i1, i2)\u3001\
    \u5217 [j1, j2) \u306E\u9577\u65B9\u5F62\u306E\u30CF\u30C3\u30B7\u30E5 O(1) (\u521D\
    \u56DE\u306F\u9577\u3055\u5206)\n     */\n    ull query(const std::vector<std::vector<ull>>&\
    \ hash, long long i1, long long j1, long long i2, long long j2) {\n        assert(0\
    \ <= i1 && i1 <= i2 && i2 < static_cast<long long>(hash.size()));\n        assert(0\
    \ <= j1 && j1 <= j2 && j2 < static_cast<long long>(hash[0].size()));\n       \
    \ rh1.expand(i2 - i1);\n        rh2.expand(j2 - j1);\n        ull p1 = rh1.power[i2\
    \ - i1], p2 = rh2.power[j2 - j1];\n        ull res = sub(hash[i2][j2], mul(hash[i1][j2],\
    \ p1));\n        res = sub(res, mul(hash[i2][j1], p2));\n        return add(res,\
    \ mul(mul(hash[i1][j1], p1), p2));\n    }\n};\n\n/**\n * @brief \u8868 text \u306E\
    \u4E2D\u3067\u3001\u8868 pattern \u3068\u4E00\u81F4\u3059\u308B\u90E8\u5206\u306E\
    \u5DE6\u4E0A\u306E\u4F4D\u7F6E (\u884C, \u5217) \u3092\u3059\u3079\u3066\u6C42\
    \u3081\u308B O(HW + hw)\n *\n * 2 \u6B21\u5143\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\
    \u30CF\u30C3\u30B7\u30E5\u3067\u6BD4\u3079\u308B\u3002\u884C\u306E\u6607\u9806\
    \u3001\u540C\u3058\u884C\u306A\u3089\u5217\u306E\u6607\u9806\u306B\u4E26\u3079\
    \u308B\n * pattern \u306F 1 \u884C 1 \u5217\u4EE5\u4E0A\u3067\u3042\u308B\u3053\
    \u3068\n */\ntemplate <typename Grid1, typename Grid2>\nstd::vector<std::pair<long\
    \ long, long long>> pattern_match_2d(const Grid1& text, const Grid2& pattern)\
    \ {\n    using std::size;\n    const long long h = size(text), w = h == 0 ? 0\
    \ : size(text[0]);\n    const long long ph = size(pattern), pw = ph == 0 ? 0 :\
    \ size(pattern[0]);\n    assert(ph > 0 && pw > 0);\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    if (ph > h || pw > w) return res;\n    RollingHash2D\
    \ rh;\n    auto th = rh.build(text), pht = rh.build(pattern);\n    unsigned long\
    \ long target = rh.query(pht, 0, 0, ph, pw);\n    for (long long i = 0; i + ph\
    \ <= h; i++) {\n        for (long long j = 0; j + pw <= w; j++) {\n          \
    \  if (rh.query(th, i, j, i + ph, j + pw) == target) res.emplace_back(i, j);\n\
    \        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2026-10-22 05:45:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/string/rolling-hash.test.cpp
  - test/aoj/alds1/alds1-14-c.test.cpp
  - test/aoj/alds1/alds1-14-b.1.test.cpp
  - test/yosupo/string/enumerate-palindromes.1.test.cpp
documentation_of: src/string/rolling-hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---

mod $2^{61} - 1$ のローリングハッシュです。基数は省略するとランダムに選ばれます。表 (2 次元) の長方形のハッシュを求める `RollingHash2D` と、表の中でパターンを探す `pattern_match_2d` もあります。

```cpp
RollingHash rh;
std::string s = "abcabc";
auto h = rh.build(s);                          // 接頭辞のハッシュ
bool eq = rh.query(h, 0, 3) == rh.query(h, 3, 6);  // "abc" == "abc": true

RHString t(rh, "ab"), u(rh, "a");
bool p = (t + u).is_palindrome();              // "aba" は回文: true
```

文字列だけでなく、整数の配列などにも使えます。`char` は 0〜255 として、負の整数は mod で正規化して扱います。

## `RollingHash` のメンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RollingHash(base = 0)` | 基数を指定して作る (0 ならランダム) | $O(1)$ |
| `build(s)` / `build(first, last)` | 長さ $n + 1$ の配列 `h` (`h[i]` は先頭 `i` 文字のハッシュ) | $O(n)$ |
| `query(h, l, r)` | $[l, r)$ のハッシュ (`l`、`r` は `long long`) | $O(1)$ (初回は $O(r - l)$) |
| `RollingHash::to_value(x)` | 要素を $[0, 2^{61} - 1)$ の値に変換する (static) | $O(1)$ |

## `RollingHash` のメンバ変数

| 変数 | 説明 |
|---|---|
| `base` | 基数 |
| `power` | `power[i]` は `base` の `i` 乗 (mod $2^{61} - 1$)。必要になった分だけ伸ばす |

## `RHString` のメンバ関数

ハッシュ値と長さだけを持つ文字列型です。連結と比較を $O(1)$ で行えます。同じ `RollingHash` から作ったもの同士でしか演算できません。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RHString(rh)` | 空文字列 | $O(1)$ |
| `RHString(rh, s)` | 文字列・`vector` などの列、または 1 文字 (`char` や整数) から作る | $O(n)$ |
| `t + u`、`t += u` | 連結 | $O(1)$ (初回は長さ分) |
| `t == u`、`t != u` | 一致判定 | $O(1)$ |
| `t = s`、`t.assign(s)` | 再代入 | $O(n)$ |
| `t.remove_prefix(x)` / `t.remove_suffix(x)` | 先頭 / 末尾の `x` を取り除く。`x` は `RHString` か、`RHString` を作れるもの (文字列や 1 文字)。端が本当に `x` であること (ハッシュからは確かめられず、違うと値が壊れる) | $O(1)$ (初回は長さ分) |
| `t.is_palindrome()` | 回文か | $O(1)$ |
| `t.size()`、`t.empty()`、`t.clear()` | 長さ (`long long`)・空か・空にする | $O(1)$ |

`remove_prefix`・`remove_suffix` は、連結の式を逆にたどって残りのハッシュを求めます。片方のハッシュは基数の逆元の累乗で割る必要があるので、初めて使うときに逆元を求めます (法 $2^{61} - 1$ は素数なので必ずある)。1 文字ずつ `+=` と `remove_prefix` をすれば、長さ $k$ の窓をずらしながらハッシュを持てます。

```cpp
RHString w(rh);
for (int i = 0; i < n; i++) {
    w += RHString(rh, s[i]);
    if (i >= k) w.remove_prefix(s[i - k]);  // w は s[i - k + 1, i]
}
```

## `RHString` のメンバ変数

| 変数 | 説明 |
|---|---|
| `rh` | 使う `RollingHash` への参照 |
| `sz` | 長さ (`long long`) |
| `hash1` | 正順のハッシュ |
| `hash2` | 逆順のハッシュ (回文判定に使う) |

## `RollingHash2D` のメンバ関数

行方向と列方向で別の基数を使う 2 次元のローリングハッシュです。表の左上からの累積ハッシュを作り、長方形のハッシュを求めます。表は `std::vector<std::string>` や `std::vector<std::vector<T>>` を渡します。

```cpp
std::vector<std::string> g = {"abab", "baba", "abab"};
RollingHash2D rh2;
auto h = rh2.build(g);
bool eq = rh2.query(h, 0, 0, 2, 2) == rh2.query(h, 1, 1, 3, 3);  // {"ab", "ba"} == {"ab", "ba"}: true

auto pos = pattern_match_2d(g, std::vector<std::string>{"ba", "ab"});  // {(0, 1), (1, 0), (1, 2)}
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RollingHash2D(base1 = 0, base2 = 0)` | 行方向・列方向の基数を指定して作る (0 ならランダム) | $O(1)$ |
| `build(grid)` | $(H + 1) \times (W + 1)$ の表 `h` (`h[i][j]` は左上 `i` 行 `j` 列のハッシュ) | $O(HW)$ |
| `query(h, i1, j1, i2, j2)` | 行 $[i_1, i_2)$、列 $[j_1, j_2)$ の長方形のハッシュ | $O(1)$ (初回は長さ分) |

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `pattern_match_2d(text, pattern)` | 表 `text` の中で表 `pattern` と一致する部分の左上の位置 (行, 列) をすべて返す (`std::vector<std::pair<long long, long long>>`、行の昇順、同じ行なら列の昇順)。`pattern` は 1 行 1 列以上 | $O(HW + hw)$ |

## 関連

- ハッシュを使わずに文字列を探すには [文字列アルゴリズム](string.hpp) の KMP 法・Z-algorithm
- 接尾辞の辞書順や LCP は [Suffix Array と LCP 配列](suffix-array.hpp)
