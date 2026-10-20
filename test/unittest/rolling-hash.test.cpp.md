---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/rolling-hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
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
  bundledCode: "#line 1 \"test/unittest/rolling-hash.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// RHString\
    \ \u3092 std::string \u3067\u611A\u76F4\u306B\u8A08\u7B97\u3057\u305F\u7D50\u679C\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u7AEF\u306E\u524A\
    \u9664 (remove_prefix\u30FBremove_suffix) \u3082\u3001\u6B8B\u308A\u306E\u6587\
    \u5B57\u5217\u304B\u3089\u4F5C\u3063\u305F RHString \u3068\u6BD4\u3079\u308B\n\
    // \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #line 2 \"src/string/rolling-hash.hpp\"\n\n/**\n * @file rolling-hash.hpp\n *\
    \ @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n */\n\n#include\
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
    #line 18 \"src/string/rolling-hash.hpp\"\n\nstruct RHString;\n\n/**\n * @brief\
    \ \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n *\n * \u30D3\u30C3\u30C8\
    \u6F14\u7B97\u306B\u3088\u308B\u9AD8\u901F\u5316\u306E\u305F\u3081\u30CF\u30C3\
    \u30B7\u30E5\u306FMOD = 2^61-1\u3067\u8A08\u7B97\u3055\u308C\u308B\n *\n * 10^8\u500B\
    \u304F\u3089\u3044\u306A\u308999%\u306E\u78BA\u7387\u3067\u885D\u7A81\u3059\u308B\
    \u7D44\u304C\u5B58\u5728\u3057\u306A\u3044\n */\nclass RollingHash {\n    constexpr\
    \ static unsigned long long MASK30 = (1ULL << 30) - 1;\n    constexpr static unsigned\
    \ long long MASK31 = (1ULL << 31) - 1;\n    constexpr static unsigned long long\
    \ MOD = (1ULL << 61) - 1;\n\n    // a < MOD, b < MOD\u5FC5\u9808\n    constexpr\
    \ static unsigned long long add(unsigned long long a, unsigned long long b) {\n\
    \        if ((a += b) >= MOD) a -= MOD;\n        return a;\n    }\n\n    // a\
    \ < MOD, b < MOD\u5FC5\u9808\n    constexpr static unsigned long long mul(unsigned\
    \ long long a, unsigned long long b) {\n        __uint128_t c = static_cast<__uint128_t>(a)\
    \ * b;\n        return add(static_cast<unsigned long long>(c >> 61), static_cast<unsigned\
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
    };\n\n/**\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u306B\
    \u3088\u3063\u3066\u7BA1\u7406\u3055\u308C\u308B\u6587\u5B57\u5217\u578B\n */\n\
    struct RHString {\n    RollingHash& rh;\n    long long sz;              //!< \u9577\
    \u3055\n    unsigned long long hash1;  //!< \u6B63\u9806\n    unsigned long long\
    \ hash2;  //!< \u9006\u9806\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     * \u4E88\u3081RollingHash\u3092\u30A4\u30F3\u30B9\u30BF\u30F3\
    \u30B9\u5316\u3057\u3066\u304A\u304F\u5FC5\u8981\u304C\u3042\u308B\n     */\n\
    \    explicit RHString(RollingHash& rh) : rh(rh), sz(0), hash1(0), hash2(0) {}\n\
    \    RHString(RollingHash& rh, long long sz, unsigned long long hash1, unsigned\
    \ long long hash2) : rh(rh), sz(sz), hash1(hash1), hash2(hash2) {}\n    RHString(const\
    \ RHString& o) : rh(o.rh), sz(o.sz), hash1(o.hash1), hash2(o.hash2) {}\n    /**\n\
    \     * @brief vector\u306A\u3069\u3067\u521D\u671F\u5316\u3059\u308B\n     */\n\
    \    template <class R, ENABLE_IF_T(is_range_v<R> && !std::is_convertible_v<R,\
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
    \ == t2); }\n};\n#line 8 \"test/unittest/rolling-hash.test.cpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#line 15 \"test/unittest/rolling-hash.test.cpp\"\n\nint main()\
    \ {\n    std::mt19937_64 rng(314);\n    RollingHash rh(1000003);\n    bool ok\
    \ = true;\n    auto check = [&](bool cond, const char* what) {\n        if (!cond)\
    \ {\n            if (ok) std::cerr << \"failed: \" << what << std::endl;\n   \
    \         ok = false;\n        }\n    };\n    auto random_string = [&](int max_len)\
    \ {\n        std::string s(rng() % (max_len + 1), 'a');\n        for (char& c\
    \ : s) c = 'a' + rng() % 3;  // \u56DE\u6587\u3084\u4E00\u81F4\u304C\u8D77\u304D\
    \u3084\u3059\u3044\u3088\u3046\u6587\u5B57\u3092\u7D5E\u308B\n        return s;\n\
    \    };\n    auto is_palindrome = [](const std::string& s) { return std::equal(s.begin(),\
    \ s.end(), s.rbegin()); };\n    // RHString \u306E\u4E2D\u8EAB\u304C s \u3068\u4E00\
    \u81F4\u3059\u308B\u304B (\u9577\u3055\u30FB\u6B63\u9806\u306E\u30CF\u30C3\u30B7\
    \u30E5\u30FB\u9006\u9806\u306E\u30CF\u30C3\u30B7\u30E5)\n    auto same = [&](const\
    \ RHString& t, const std::string& s) {\n        std::string r(s.rbegin(), s.rend());\n\
    \        return t.size() == static_cast<long long>(s.size()) && t.hash1 == rh.build(s).back()\
    \ && t.hash2 == rh.build(r).back();\n    };\n\n    for (int rep = 0; rep < 3000\
    \ && ok; rep++) {\n        std::string s = random_string(8), t = random_string(8);\n\
    \n        // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF: \u6587\u5B57\u5217 (std::string\
    \ / const char* / string_view)\u30FBvector\u30FB1 \u6587\u5B57\u30FB\u7A7A\u30FB\
    \u30B3\u30D4\u30FC\u30FB\u30CF\u30C3\u30B7\u30E5\u5024\u304B\u3089\n        RHString\
    \ a(rh, s), b(rh, t);\n        check(same(a, s) && same(b, t), \"string constructor\"\
    );\n        check(same(RHString(rh, s.c_str()), s), \"const char* constructor\"\
    );\n        check(same(RHString(rh, std::string_view(s)), s), \"string_view constructor\"\
    );\n        std::vector<char> sv(s.begin(), s.end());\n        check(same(RHString(rh,\
    \ sv), s), \"vector constructor\");\n        RHString empty(rh);\n        check(empty.empty()\
    \ && empty.size() == 0 && same(empty, \"\"), \"empty constructor\");\n       \
    \ if (!s.empty()) check(same(RHString(rh, s[0]), s.substr(0, 1)), \"char constructor\"\
    );\n        RHString copy(a);\n        check(copy == a && same(copy, s), \"copy\
    \ constructor\");\n        RHString raw(rh, a.size(), a.hash1, a.hash2);\n   \
    \     check(raw == a, \"hash constructor\");\n\n        // \u9023\u7D50: +, +=\n\
    \        check(same(a + b, s + t), \"operator+\");\n        RHString c = a;\n\
    \        c += b;\n        check(same(c, s + t), \"operator+=\");\n        RHString\
    \ d(rh);\n        for (char ch : s) d += RHString(rh, ch);\n        check(same(d,\
    \ s) && d == a, \"operator+= char by char\");\n\n        // \u6BD4\u8F03: \u6587\
    \u5B57\u5217\u304C\u7B49\u3057\u3044\u3068\u304D\u3060\u3051\u7B49\u3057\u3044\
    \n        check((a == b) == (s == t), \"operator==\");\n        check((a != b)\
    \ == (s != t), \"operator!=\");\n        check(a + b == RHString(rh, s + t), \"\
    concat equals whole\");\n\n        // \u56DE\u6587\u5224\u5B9A\n        check(a.is_palindrome()\
    \ == is_palindrome(s), \"is_palindrome\");\n        check((a + b).is_palindrome()\
    \ == is_palindrome(s + t), \"is_palindrome concat\");\n\n        // size, empty,\
    \ clear\n        check(a.size() == static_cast<long long>(s.size()) && a.empty()\
    \ == s.empty(), \"size/empty\");\n        RHString e = a;\n        e.clear();\n\
    \        check(e.empty() && e.size() == 0 && e == empty, \"clear\");\n\n     \
    \   // assign \u3068 operator= \u306E\u5404\u7248\n        RHString f(rh);\n \
    \       f.assign(a);\n        check(f == a, \"assign(RHString)\");\n        f.assign(t);\n\
    \        check(same(f, t), \"assign(string)\");\n        f.assign(std::string_view(s));\n\
    \        check(same(f, s), \"assign(string_view)\");\n        std::vector<char>\
    \ tv(t.begin(), t.end());\n        f.assign(tv);\n        check(same(f, t), \"\
    assign(vector)\");\n        f.assign('b');\n        check(same(f, \"b\"), \"assign(char)\"\
    );\n        f = b;\n        check(f == b, \"operator=(RHString)\");\n        f\
    \ = s;\n        check(same(f, s), \"operator=(string)\");\n        f = std::string_view(t);\n\
    \        check(same(f, t), \"operator=(string_view)\");\n        f = sv;\n   \
    \     check(same(f, s), \"operator=(vector)\");\n        f = 'c';\n        check(same(f,\
    \ \"c\"), \"operator=(char)\");\n    }\n\n    // \u6574\u6570\u306E\u5217 (\u8CA0\
    \u306E\u5024\u3092\u542B\u3080) \u3067\u3082\u3001\u9023\u7D50\u3068\u6BD4\u8F03\
    \u304C\u5217\u3068\u3057\u3066\u306E\u4E00\u81F4\u3068\u5BFE\u5FDC\u3059\u308B\
    \n    for (int rep = 0; rep < 1000 && ok; rep++) {\n        std::vector<long long>\
    \ x(rng() % 6), y(rng() % 6);\n        for (auto& v : x) v = static_cast<long\
    \ long>(rng() % 5) - 2;\n        for (auto& v : y) v = static_cast<long long>(rng()\
    \ % 5) - 2;\n        std::vector<long long> xy = x;\n        xy.insert(xy.end(),\
    \ y.begin(), y.end());\n        RHString hx(rh, x), hy(rh, y), hxy(rh, xy);\n\
    \        check(hx + hy == hxy, \"vector<long long> concat\");\n        check((hx\
    \ == hy) == (x == y), \"vector<long long> equality\");\n        check(hx.is_palindrome()\
    \ == std::equal(x.begin(), x.end(), x.rbegin()), \"vector<long long> palindrome\"\
    );\n    }\n\n    // remove_prefix / remove_suffix: s = t + u \u3084 s = u + t\
    \ \u304B\u3089 t \u3092\u53D6\u308A\u9664\u304F\u3068\u3001u \u304B\u3089\u4F5C\
    \u3063\u305F\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\n    // \u56DE\u6587\u306E\
    \u5224\u5B9A (\u9006\u9806\u306E\u30CF\u30C3\u30B7\u30E5) \u3082\u4E00\u81F4\u3057\
    \u3001\u30E9\u30F3\u30C0\u30E0\u306A\u57FA\u6570\u3067\u3082\u6210\u308A\u7ACB\
    \u3064\n    RollingHash random_rh;\n    for (RollingHash* r : {&rh, &random_rh})\
    \ {\n        for (int rep = 0; rep < 3000 && ok; rep++) {\n            std::string\
    \ t = random_string(8), u = random_string(8);\n            RHString a(*r, t +\
    \ u), b(*r, u + t);\n            a.remove_prefix(RHString(*r, t));\n         \
    \   b.remove_suffix(t);  // RHString \u3092\u4F5C\u308C\u308B\u3082\u306E (\u6587\
    \u5B57\u5217) \u3092\u76F4\u63A5\u6E21\u3059\n            RHString hu(*r, u);\n\
    \            check(a == hu && a.size() == static_cast<long long>(u.size()), \"\
    remove_prefix\");\n            check(b == hu && b.size() == static_cast<long long>(u.size()),\
    \ \"remove_suffix\");\n            check(a.is_palindrome() == is_palindrome(u)\
    \ && b.is_palindrome() == is_palindrome(u), \"remove \u5F8C\u306E is_palindrome\"\
    );\n            // \u53D6\u308A\u9664\u3044\u305F\u3042\u3068\u306B\u9023\u7D50\
    \u3057\u3066\u3082\u6B63\u3057\u3044\n            check(a + RHString(*r, t) ==\
    \ RHString(*r, u + t), \"remove \u5F8C\u306E\u9023\u7D50\");\n        }\n    }\n\
    \    // 1 \u6587\u5B57\u305A\u3064 push_back \u3068 pop_front \u3092\u3057\u3066\
    \u3001\u9577\u3055 k \u306E\u7A93\u3092\u52D5\u304B\u3059\n    {\n        std::string\
    \ s = random_string(200);\n        const int k = 5;\n        RHString w(rh);\n\
    \        for (int i = 0; i < static_cast<int>(s.size()); i++) {\n            w\
    \ += RHString(rh, s[i]);\n            if (i >= k) w.remove_prefix(s[i - k]); \
    \ // \u6587\u5B57\u3092\u76F4\u63A5\u6E21\u3059\n            int l = std::max(0,\
    \ i - k + 1);\n            check(w == RHString(rh, s.substr(l, i - l + 1)), \"\
    \u7A93\");\n        }\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// RHString \u3092 std::string \u3067\u611A\u76F4\u306B\u8A08\u7B97\u3057\u305F\
    \u7D50\u679C\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u7AEF\
    \u306E\u524A\u9664 (remove_prefix\u30FBremove_suffix) \u3082\u3001\u6B8B\u308A\
    \u306E\u6587\u5B57\u5217\u304B\u3089\u4F5C\u3063\u305F RHString \u3068\u6BD4\u3079\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../src/string/rolling-hash.hpp\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <random>\n#include <string>\n#include <string_view>\n#include\
    \ <vector>\n\nint main() {\n    std::mt19937_64 rng(314);\n    RollingHash rh(1000003);\n\
    \    bool ok = true;\n    auto check = [&](bool cond, const char* what) {\n  \
    \      if (!cond) {\n            if (ok) std::cerr << \"failed: \" << what <<\
    \ std::endl;\n            ok = false;\n        }\n    };\n    auto random_string\
    \ = [&](int max_len) {\n        std::string s(rng() % (max_len + 1), 'a');\n \
    \       for (char& c : s) c = 'a' + rng() % 3;  // \u56DE\u6587\u3084\u4E00\u81F4\
    \u304C\u8D77\u304D\u3084\u3059\u3044\u3088\u3046\u6587\u5B57\u3092\u7D5E\u308B\
    \n        return s;\n    };\n    auto is_palindrome = [](const std::string& s)\
    \ { return std::equal(s.begin(), s.end(), s.rbegin()); };\n    // RHString \u306E\
    \u4E2D\u8EAB\u304C s \u3068\u4E00\u81F4\u3059\u308B\u304B (\u9577\u3055\u30FB\u6B63\
    \u9806\u306E\u30CF\u30C3\u30B7\u30E5\u30FB\u9006\u9806\u306E\u30CF\u30C3\u30B7\
    \u30E5)\n    auto same = [&](const RHString& t, const std::string& s) {\n    \
    \    std::string r(s.rbegin(), s.rend());\n        return t.size() == static_cast<long\
    \ long>(s.size()) && t.hash1 == rh.build(s).back() && t.hash2 == rh.build(r).back();\n\
    \    };\n\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        std::string\
    \ s = random_string(8), t = random_string(8);\n\n        // \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF: \u6587\u5B57\u5217 (std::string / const char* / string_view)\u30FB\
    vector\u30FB1 \u6587\u5B57\u30FB\u7A7A\u30FB\u30B3\u30D4\u30FC\u30FB\u30CF\u30C3\
    \u30B7\u30E5\u5024\u304B\u3089\n        RHString a(rh, s), b(rh, t);\n       \
    \ check(same(a, s) && same(b, t), \"string constructor\");\n        check(same(RHString(rh,\
    \ s.c_str()), s), \"const char* constructor\");\n        check(same(RHString(rh,\
    \ std::string_view(s)), s), \"string_view constructor\");\n        std::vector<char>\
    \ sv(s.begin(), s.end());\n        check(same(RHString(rh, sv), s), \"vector constructor\"\
    );\n        RHString empty(rh);\n        check(empty.empty() && empty.size() ==\
    \ 0 && same(empty, \"\"), \"empty constructor\");\n        if (!s.empty()) check(same(RHString(rh,\
    \ s[0]), s.substr(0, 1)), \"char constructor\");\n        RHString copy(a);\n\
    \        check(copy == a && same(copy, s), \"copy constructor\");\n        RHString\
    \ raw(rh, a.size(), a.hash1, a.hash2);\n        check(raw == a, \"hash constructor\"\
    );\n\n        // \u9023\u7D50: +, +=\n        check(same(a + b, s + t), \"operator+\"\
    );\n        RHString c = a;\n        c += b;\n        check(same(c, s + t), \"\
    operator+=\");\n        RHString d(rh);\n        for (char ch : s) d += RHString(rh,\
    \ ch);\n        check(same(d, s) && d == a, \"operator+= char by char\");\n\n\
    \        // \u6BD4\u8F03: \u6587\u5B57\u5217\u304C\u7B49\u3057\u3044\u3068\u304D\
    \u3060\u3051\u7B49\u3057\u3044\n        check((a == b) == (s == t), \"operator==\"\
    );\n        check((a != b) == (s != t), \"operator!=\");\n        check(a + b\
    \ == RHString(rh, s + t), \"concat equals whole\");\n\n        // \u56DE\u6587\
    \u5224\u5B9A\n        check(a.is_palindrome() == is_palindrome(s), \"is_palindrome\"\
    );\n        check((a + b).is_palindrome() == is_palindrome(s + t), \"is_palindrome\
    \ concat\");\n\n        // size, empty, clear\n        check(a.size() == static_cast<long\
    \ long>(s.size()) && a.empty() == s.empty(), \"size/empty\");\n        RHString\
    \ e = a;\n        e.clear();\n        check(e.empty() && e.size() == 0 && e ==\
    \ empty, \"clear\");\n\n        // assign \u3068 operator= \u306E\u5404\u7248\n\
    \        RHString f(rh);\n        f.assign(a);\n        check(f == a, \"assign(RHString)\"\
    );\n        f.assign(t);\n        check(same(f, t), \"assign(string)\");\n   \
    \     f.assign(std::string_view(s));\n        check(same(f, s), \"assign(string_view)\"\
    );\n        std::vector<char> tv(t.begin(), t.end());\n        f.assign(tv);\n\
    \        check(same(f, t), \"assign(vector)\");\n        f.assign('b');\n    \
    \    check(same(f, \"b\"), \"assign(char)\");\n        f = b;\n        check(f\
    \ == b, \"operator=(RHString)\");\n        f = s;\n        check(same(f, s), \"\
    operator=(string)\");\n        f = std::string_view(t);\n        check(same(f,\
    \ t), \"operator=(string_view)\");\n        f = sv;\n        check(same(f, s),\
    \ \"operator=(vector)\");\n        f = 'c';\n        check(same(f, \"c\"), \"\
    operator=(char)\");\n    }\n\n    // \u6574\u6570\u306E\u5217 (\u8CA0\u306E\u5024\
    \u3092\u542B\u3080) \u3067\u3082\u3001\u9023\u7D50\u3068\u6BD4\u8F03\u304C\u5217\
    \u3068\u3057\u3066\u306E\u4E00\u81F4\u3068\u5BFE\u5FDC\u3059\u308B\n    for (int\
    \ rep = 0; rep < 1000 && ok; rep++) {\n        std::vector<long long> x(rng()\
    \ % 6), y(rng() % 6);\n        for (auto& v : x) v = static_cast<long long>(rng()\
    \ % 5) - 2;\n        for (auto& v : y) v = static_cast<long long>(rng() % 5) -\
    \ 2;\n        std::vector<long long> xy = x;\n        xy.insert(xy.end(), y.begin(),\
    \ y.end());\n        RHString hx(rh, x), hy(rh, y), hxy(rh, xy);\n        check(hx\
    \ + hy == hxy, \"vector<long long> concat\");\n        check((hx == hy) == (x\
    \ == y), \"vector<long long> equality\");\n        check(hx.is_palindrome() ==\
    \ std::equal(x.begin(), x.end(), x.rbegin()), \"vector<long long> palindrome\"\
    );\n    }\n\n    // remove_prefix / remove_suffix: s = t + u \u3084 s = u + t\
    \ \u304B\u3089 t \u3092\u53D6\u308A\u9664\u304F\u3068\u3001u \u304B\u3089\u4F5C\
    \u3063\u305F\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\n    // \u56DE\u6587\u306E\
    \u5224\u5B9A (\u9006\u9806\u306E\u30CF\u30C3\u30B7\u30E5) \u3082\u4E00\u81F4\u3057\
    \u3001\u30E9\u30F3\u30C0\u30E0\u306A\u57FA\u6570\u3067\u3082\u6210\u308A\u7ACB\
    \u3064\n    RollingHash random_rh;\n    for (RollingHash* r : {&rh, &random_rh})\
    \ {\n        for (int rep = 0; rep < 3000 && ok; rep++) {\n            std::string\
    \ t = random_string(8), u = random_string(8);\n            RHString a(*r, t +\
    \ u), b(*r, u + t);\n            a.remove_prefix(RHString(*r, t));\n         \
    \   b.remove_suffix(t);  // RHString \u3092\u4F5C\u308C\u308B\u3082\u306E (\u6587\
    \u5B57\u5217) \u3092\u76F4\u63A5\u6E21\u3059\n            RHString hu(*r, u);\n\
    \            check(a == hu && a.size() == static_cast<long long>(u.size()), \"\
    remove_prefix\");\n            check(b == hu && b.size() == static_cast<long long>(u.size()),\
    \ \"remove_suffix\");\n            check(a.is_palindrome() == is_palindrome(u)\
    \ && b.is_palindrome() == is_palindrome(u), \"remove \u5F8C\u306E is_palindrome\"\
    );\n            // \u53D6\u308A\u9664\u3044\u305F\u3042\u3068\u306B\u9023\u7D50\
    \u3057\u3066\u3082\u6B63\u3057\u3044\n            check(a + RHString(*r, t) ==\
    \ RHString(*r, u + t), \"remove \u5F8C\u306E\u9023\u7D50\");\n        }\n    }\n\
    \    // 1 \u6587\u5B57\u305A\u3064 push_back \u3068 pop_front \u3092\u3057\u3066\
    \u3001\u9577\u3055 k \u306E\u7A93\u3092\u52D5\u304B\u3059\n    {\n        std::string\
    \ s = random_string(200);\n        const int k = 5;\n        RHString w(rh);\n\
    \        for (int i = 0; i < static_cast<int>(s.size()); i++) {\n            w\
    \ += RHString(rh, s[i]);\n            if (i >= k) w.remove_prefix(s[i - k]); \
    \ // \u6587\u5B57\u3092\u76F4\u63A5\u6E21\u3059\n            int l = std::max(0,\
    \ i - k + 1);\n            check(w == RHString(rh, s.substr(l, i - l + 1)), \"\
    \u7A93\");\n        }\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/string/rolling-hash.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/rolling-hash.test.cpp
  requiredBy: []
  timestamp: '2026-10-20 16:33:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/rolling-hash.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/rolling-hash.test.cpp
- /verify/test/unittest/rolling-hash.test.cpp.html
title: test/unittest/rolling-hash.test.cpp
---
