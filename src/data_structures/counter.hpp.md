---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2/itp2-7-d.test.cpp
    title: test/aoj/itp2/itp2-7-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/volume0/0029.test.cpp
    title: test/aoj/volume0/0029.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/counter.test.cpp
    title: test/unittest/data_structures/counter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/associative-array.test.cpp
    title: test/yosupo/data_structure/associative-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\
      \u5408 (Counter)"
    links: []
  bundledCode: "#line 2 \"src/data_structures/counter.hpp\"\n\n/**\n * @file counter.hpp\n\
    \ * @brief \u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408\
    \ (Counter)\n */\n\n#include <cassert>\n#include <cstddef>\n#include <initializer_list>\n\
    #include <iterator>\n#include <map>\n#include <optional>\n#include <set>\n#include\
    \ <type_traits>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"\
    src/utility/traits.hpp\"\n#include <functional>\n#line 14 \"src/utility/traits.hpp\"\
    \n\n#if __cplusplus >= 202002L\n#include <ranges>\n#endif\n\nnamespace internal_traits\
    \ {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n\n// \u30B5\u30A4\u30BA\u4ED8\
    \u304D\u7BC4\u56F2\u304B\u3089\u8981\u7D20\u3092\u76F4\u63A5\u69CB\u7BC9\u3059\
    \u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u5171\u6709\u3059\u308B\
    \u3002\n#if __cplusplus >= 202002L\ntemplate <class R, class S>\nconcept sized_constructible_range\
    \ = std::ranges::input_range<R> && std::ranges::sized_range<R> &&\n          \
    \                          std::is_constructible_v<S, std::ranges::range_reference_t<R>>;\n\
    \ntemplate <class R>\nauto range_size(R& r) {\n    return std::ranges::size(r);\n\
    }\ntemplate <class R>\nauto range_begin(R& r) {\n    return std::ranges::begin(r);\n\
    }\ntemplate <class R>\nusing range_value_t = std::ranges::range_value_t<R>;\n\
    #else\nusing std::size;\ntemplate <class R>\nauto range_size(R& r) -> decltype(size(r))\
    \ {\n    return size(r);\n}\ntemplate <class R>\nauto range_begin(R& r) -> decltype(begin(r))\
    \ {\n    return begin(r);\n}\ntemplate <class R>\nusing range_value_t = typename\
    \ std::iterator_traits<decltype(range_begin(std::declval<R&>()))>::value_type;\n\
    \ntemplate <class R, class S, class = void>\nstruct is_sized_constructible_range\
    \ : std::false_type {};\ntemplate <class R, class S>\nstruct is_sized_constructible_range<R,\
    \ S, std::void_t<decltype(range_size(std::declval<R&>())), decltype(++std::declval<decltype(begin(std::declval<R&>()))&>()),\
    \ decltype(begin(std::declval<R&>()) != end(std::declval<R&>())), decltype(*begin(std::declval<R&>()))>>\n\
    \    : std::is_constructible<S, decltype(*begin(std::declval<R&>()))> {};\n#endif\n\
    }  // namespace internal_traits\n\ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
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
    #line 20 \"src/data_structures/counter.hpp\"\n\ntemplate <typename T = long long>\n\
    struct Counter {\n    using key_type = T;\n    using mapped_type = long long;\n\
    \    using value_type = std::pair<key_type, mapped_type>;\n\n   private:\n   \
    \ struct CompareFrequency {\n        bool operator()(const value_type& a, const\
    \ value_type& b) const {\n            return a.second > b.second || (a.second\
    \ == b.second && a.first < b.first);\n        }\n    };\n    std::map<key_type,\
    \ mapped_type> data;\n    std::set<value_type, CompareFrequency> frequency;\n\n\
    \   public:\n    void inc(const key_type& key, const mapped_type& t) {\n     \
    \   set(key, get(key) + t);\n    }\n    Counter() = default;\n    explicit Counter(const\
    \ key_type& x) { set(x, 1); }\n    /**\n     * @brief \u7BC4\u56F2\u306E\u8981\
    \u7D20\u3092\u6570\u3048\u308B\n     * Counter \u81EA\u8EAB\u3068 key_type (std::string\
    \ \u306A\u3069\u7BC4\u56F2\u3067\u3082\u3042\u308B\u3082\u306E) \u306F\u3053\u3061\
    \u3089\u3067\u53D7\u3051\u53D6\u3089\u306A\u3044\n     */\n    template <class\
    \ C, ENABLE_IF_T(!std::is_same_v<std::decay_t<C>, Counter> && !std::is_convertible_v<C,\
    \ key_type>),\n              class = decltype(std::begin(std::declval<C&>()),\
    \ std::end(std::declval<C&>()))>\n    explicit Counter(C&& v) {\n        for (const\
    \ key_type& a : v) {\n            inc(a, 1);\n        }\n    }\n    Counter(std::initializer_list<value_type>\
    \ init) {\n        for (const auto& p : init) {\n            inc(p.first, p.second);\n\
    \        }\n    }\n    Counter& operator+=(const Counter& o) {\n        for (const\
    \ auto& [i, c] : o.data) {\n            inc(i, c);\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator+(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res += b;\n    }\n    Counter&\
    \ operator-=(const Counter& o) {\n        // \u81EA\u5206\u81EA\u8EAB\u3092\u5F15\
    \u304F\u3068\u3001\u8D70\u67FB\u4E2D\u306E o.data \u306E\u8981\u7D20\u3092 inc\
    \ \u304C\u6D88\u3057\u3066\u3057\u307E\u3046\n        if (this == &o) {\n    \
    \        data.clear();\n            frequency.clear();\n            return *this;\n\
    \        }\n        for (const auto& [i, c] : o.data) {\n            inc(i, -c);\n\
    \        }\n        return *this;\n    }\n    friend Counter operator-(const Counter&\
    \ a, const Counter& b) {\n        Counter res(a);\n        return res -= b;\n\
    \    }\n    auto begin() const { return data.begin(); }\n    auto end() const\
    \ { return data.end(); }\n    /** @brief key \u4EE5\u4E0A\u306E\u6700\u521D\u306E\
    \u5024\u306E\u8AAD\u307F\u53D6\u308A\u5C02\u7528\u30A4\u30C6\u30EC\u30FC\u30BF\
    \ (\u306A\u3051\u308C\u3070 end()) */\n    auto lower_bound(const key_type& key)\
    \ const { return data.lower_bound(key); }\n    /** @brief key \u3088\u308A\u5927\
    \u304D\u3044\u6700\u521D\u306E\u5024\u306E\u8AAD\u307F\u53D6\u308A\u5C02\u7528\
    \u30A4\u30C6\u30EC\u30FC\u30BF (\u306A\u3051\u308C\u3070 end()) */\n    auto upper_bound(const\
    \ key_type& key) const { return data.upper_bound(key); }\n    /**\n     * @brief\
    \ \u7570\u306A\u308B\u5024\u306E\u500B\u6570 (\u91CD\u8907\u306F\u6570\u3048\u306A\
    \u3044)\n     */\n    long long size() const {\n        return static_cast<long\
    \ long>(data.size());\n    }\n    /**\n     * @brief \u91CD\u8907\u3092\u542B\u3081\
    \u305F\u8981\u7D20\u6570 (\u500B\u6570\u306E\u7DCF\u548C)\n     * @note Python\
    \ \u306E collections.Counter.total() \u3068\u540C\u3058\u3002O(\u7570\u306A\u308B\
    \u5024\u306E\u500B\u6570)\n     */\n    mapped_type total() const {\n        mapped_type\
    \ ret = 0;\n        for (const auto& [key, cnt] : data) ret += cnt;\n        return\
    \ ret;\n    }\n    mapped_type get(const key_type& key) const {\n        auto\
    \ itr = data.find(key);\n        if (itr == data.end()) return 0;\n        return\
    \ itr->second;\n    }\n    void set(const key_type& key, const mapped_type& t)\
    \ {\n        assert(t >= 0);\n        auto itr = data.find(key);\n        if (itr\
    \ != data.end()) frequency.erase(*itr);\n        if (t > 0) {\n            data[key]\
    \ = t;\n            frequency.emplace(key, t);\n        } else if (itr != data.end())\
    \ {\n            data.erase(itr);\n        }\n    }\n    struct Mode {\n     \
    \   T value;\n        long long count;\n    };\n    /**\n     * @brief \u6700\u983B\
    \u5024\u3068\u305D\u306E\u500B\u6570\u3092\u8FD4\u3059\u3002\u540C\u6570\u306A\
    \u3089\u6700\u5C0F\u306E\u5024\u3092\u9078\u3073\u3001\u7A7A\u306A\u3089 std::nullopt\
    \ \u3092\u8FD4\u3059\n     * @note O(1)\n     */\n    std::optional<Mode> mode()\
    \ const {\n        if (frequency.empty()) return std::nullopt;\n        const\
    \ auto& [value, count] = *frequency.begin();\n        return Mode{value, count};\n\
    \    }\n    /**\n     * @brief \u500B\u6570\u306E\u964D\u9806\u3001\u540C\u6570\
    \u306A\u3089\u5024\u306E\u6607\u9806\u306B\u4E26\u3079\u305F\u5185\u90E8 set \u306E\
    \ const \u53C2\u7167 (\u30B3\u30D4\u30FC\u3057\u306A\u3044)\n     * @note O(1)\u3002\
    Counter \u306E\u66F4\u65B0\u306F\u53C2\u7167\u5148\u306B\u3082\u53CD\u6620\u3055\
    \u308C\u308B\u3002\u66F4\u65B0\u3057\u305F\u5024\u306E\u8981\u7D20\u3078\u306E\
    \u30A4\u30C6\u30EC\u30FC\u30BF\u306F\u5931\u52B9\u3059\u308B\n     */\n    const\
    \ auto& by_frequency() const { return frequency; }\n    std::vector<value_type>\
    \ most_common() const {\n        return {frequency.begin(), frequency.end()};\n\
    \    }\n    /**\n     * @brief \u500B\u6570\u306E\u591A\u3044\u9806\u306B\u4E0A\
    \u4F4D k \u4EF6\u3092\u8FD4\u3059\u3002\u540C\u6570\u306A\u3089\u5024\u306E\u6607\
    \u9806\u3002k >= 0\n     * @note k \u304C\u7570\u306A\u308B\u5024\u306E\u500B\u6570\
    \u3088\u308A\u5927\u304D\u3051\u308C\u3070\u5168\u4EF6\u3092\u8FD4\u3059\u3002\
    O(min(k, size()))\n     */\n    std::vector<value_type> most_common(long long\
    \ k) const {\n        assert(k >= 0);\n        if (k > size()) k = size();\n \
    \       std::vector<value_type> result;\n        result.reserve(k);\n        auto\
    \ itr = frequency.begin();\n        for (long long i = 0; i < k; ++i, ++itr) result.push_back(*itr);\n\
    \        return result;\n    }\n    class CounterReference {\n        Counter&\
    \ base;\n        key_type key;\n\n       public:\n        CounterReference(Counter&\
    \ base, key_type key) : base(base), key(key) {}\n        CounterReference& operator=(const\
    \ mapped_type& x) {\n            base.set(key, x);\n            return *this;\n\
    \        }\n        CounterReference& operator+=(const mapped_type& x) {\n   \
    \         base.inc(key, x);\n            return *this;\n        }\n        CounterReference&\
    \ operator-=(const mapped_type& x) {\n            base.inc(key, -x);\n       \
    \     return *this;\n        }\n        operator mapped_type() const {\n     \
    \       return base.get(key);\n        }\n    };\n    mapped_type operator[](const\
    \ key_type& key) const {\n        return get(key);\n    }\n    CounterReference\
    \ operator[](const key_type& key) {\n        return CounterReference(*this, key);\n\
    \    }\n};\n\ntemplate <typename T>\nCounter(std::vector<T>) -> Counter<T>;\n"
  code: "#pragma once\n\n/**\n * @file counter.hpp\n * @brief \u5024\u306E\u500B\u6570\
    \u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408 (Counter)\n */\n\n#include <cassert>\n\
    #include <cstddef>\n#include <initializer_list>\n#include <iterator>\n#include\
    \ <map>\n#include <optional>\n#include <set>\n#include <type_traits>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"../utility/traits.hpp\"\n\ntemplate\
    \ <typename T = long long>\nstruct Counter {\n    using key_type = T;\n    using\
    \ mapped_type = long long;\n    using value_type = std::pair<key_type, mapped_type>;\n\
    \n   private:\n    struct CompareFrequency {\n        bool operator()(const value_type&\
    \ a, const value_type& b) const {\n            return a.second > b.second || (a.second\
    \ == b.second && a.first < b.first);\n        }\n    };\n    std::map<key_type,\
    \ mapped_type> data;\n    std::set<value_type, CompareFrequency> frequency;\n\n\
    \   public:\n    void inc(const key_type& key, const mapped_type& t) {\n     \
    \   set(key, get(key) + t);\n    }\n    Counter() = default;\n    explicit Counter(const\
    \ key_type& x) { set(x, 1); }\n    /**\n     * @brief \u7BC4\u56F2\u306E\u8981\
    \u7D20\u3092\u6570\u3048\u308B\n     * Counter \u81EA\u8EAB\u3068 key_type (std::string\
    \ \u306A\u3069\u7BC4\u56F2\u3067\u3082\u3042\u308B\u3082\u306E) \u306F\u3053\u3061\
    \u3089\u3067\u53D7\u3051\u53D6\u3089\u306A\u3044\n     */\n    template <class\
    \ C, ENABLE_IF_T(!std::is_same_v<std::decay_t<C>, Counter> && !std::is_convertible_v<C,\
    \ key_type>),\n              class = decltype(std::begin(std::declval<C&>()),\
    \ std::end(std::declval<C&>()))>\n    explicit Counter(C&& v) {\n        for (const\
    \ key_type& a : v) {\n            inc(a, 1);\n        }\n    }\n    Counter(std::initializer_list<value_type>\
    \ init) {\n        for (const auto& p : init) {\n            inc(p.first, p.second);\n\
    \        }\n    }\n    Counter& operator+=(const Counter& o) {\n        for (const\
    \ auto& [i, c] : o.data) {\n            inc(i, c);\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator+(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res += b;\n    }\n    Counter&\
    \ operator-=(const Counter& o) {\n        // \u81EA\u5206\u81EA\u8EAB\u3092\u5F15\
    \u304F\u3068\u3001\u8D70\u67FB\u4E2D\u306E o.data \u306E\u8981\u7D20\u3092 inc\
    \ \u304C\u6D88\u3057\u3066\u3057\u307E\u3046\n        if (this == &o) {\n    \
    \        data.clear();\n            frequency.clear();\n            return *this;\n\
    \        }\n        for (const auto& [i, c] : o.data) {\n            inc(i, -c);\n\
    \        }\n        return *this;\n    }\n    friend Counter operator-(const Counter&\
    \ a, const Counter& b) {\n        Counter res(a);\n        return res -= b;\n\
    \    }\n    auto begin() const { return data.begin(); }\n    auto end() const\
    \ { return data.end(); }\n    /** @brief key \u4EE5\u4E0A\u306E\u6700\u521D\u306E\
    \u5024\u306E\u8AAD\u307F\u53D6\u308A\u5C02\u7528\u30A4\u30C6\u30EC\u30FC\u30BF\
    \ (\u306A\u3051\u308C\u3070 end()) */\n    auto lower_bound(const key_type& key)\
    \ const { return data.lower_bound(key); }\n    /** @brief key \u3088\u308A\u5927\
    \u304D\u3044\u6700\u521D\u306E\u5024\u306E\u8AAD\u307F\u53D6\u308A\u5C02\u7528\
    \u30A4\u30C6\u30EC\u30FC\u30BF (\u306A\u3051\u308C\u3070 end()) */\n    auto upper_bound(const\
    \ key_type& key) const { return data.upper_bound(key); }\n    /**\n     * @brief\
    \ \u7570\u306A\u308B\u5024\u306E\u500B\u6570 (\u91CD\u8907\u306F\u6570\u3048\u306A\
    \u3044)\n     */\n    long long size() const {\n        return static_cast<long\
    \ long>(data.size());\n    }\n    /**\n     * @brief \u91CD\u8907\u3092\u542B\u3081\
    \u305F\u8981\u7D20\u6570 (\u500B\u6570\u306E\u7DCF\u548C)\n     * @note Python\
    \ \u306E collections.Counter.total() \u3068\u540C\u3058\u3002O(\u7570\u306A\u308B\
    \u5024\u306E\u500B\u6570)\n     */\n    mapped_type total() const {\n        mapped_type\
    \ ret = 0;\n        for (const auto& [key, cnt] : data) ret += cnt;\n        return\
    \ ret;\n    }\n    mapped_type get(const key_type& key) const {\n        auto\
    \ itr = data.find(key);\n        if (itr == data.end()) return 0;\n        return\
    \ itr->second;\n    }\n    void set(const key_type& key, const mapped_type& t)\
    \ {\n        assert(t >= 0);\n        auto itr = data.find(key);\n        if (itr\
    \ != data.end()) frequency.erase(*itr);\n        if (t > 0) {\n            data[key]\
    \ = t;\n            frequency.emplace(key, t);\n        } else if (itr != data.end())\
    \ {\n            data.erase(itr);\n        }\n    }\n    struct Mode {\n     \
    \   T value;\n        long long count;\n    };\n    /**\n     * @brief \u6700\u983B\
    \u5024\u3068\u305D\u306E\u500B\u6570\u3092\u8FD4\u3059\u3002\u540C\u6570\u306A\
    \u3089\u6700\u5C0F\u306E\u5024\u3092\u9078\u3073\u3001\u7A7A\u306A\u3089 std::nullopt\
    \ \u3092\u8FD4\u3059\n     * @note O(1)\n     */\n    std::optional<Mode> mode()\
    \ const {\n        if (frequency.empty()) return std::nullopt;\n        const\
    \ auto& [value, count] = *frequency.begin();\n        return Mode{value, count};\n\
    \    }\n    /**\n     * @brief \u500B\u6570\u306E\u964D\u9806\u3001\u540C\u6570\
    \u306A\u3089\u5024\u306E\u6607\u9806\u306B\u4E26\u3079\u305F\u5185\u90E8 set \u306E\
    \ const \u53C2\u7167 (\u30B3\u30D4\u30FC\u3057\u306A\u3044)\n     * @note O(1)\u3002\
    Counter \u306E\u66F4\u65B0\u306F\u53C2\u7167\u5148\u306B\u3082\u53CD\u6620\u3055\
    \u308C\u308B\u3002\u66F4\u65B0\u3057\u305F\u5024\u306E\u8981\u7D20\u3078\u306E\
    \u30A4\u30C6\u30EC\u30FC\u30BF\u306F\u5931\u52B9\u3059\u308B\n     */\n    const\
    \ auto& by_frequency() const { return frequency; }\n    std::vector<value_type>\
    \ most_common() const {\n        return {frequency.begin(), frequency.end()};\n\
    \    }\n    /**\n     * @brief \u500B\u6570\u306E\u591A\u3044\u9806\u306B\u4E0A\
    \u4F4D k \u4EF6\u3092\u8FD4\u3059\u3002\u540C\u6570\u306A\u3089\u5024\u306E\u6607\
    \u9806\u3002k >= 0\n     * @note k \u304C\u7570\u306A\u308B\u5024\u306E\u500B\u6570\
    \u3088\u308A\u5927\u304D\u3051\u308C\u3070\u5168\u4EF6\u3092\u8FD4\u3059\u3002\
    O(min(k, size()))\n     */\n    std::vector<value_type> most_common(long long\
    \ k) const {\n        assert(k >= 0);\n        if (k > size()) k = size();\n \
    \       std::vector<value_type> result;\n        result.reserve(k);\n        auto\
    \ itr = frequency.begin();\n        for (long long i = 0; i < k; ++i, ++itr) result.push_back(*itr);\n\
    \        return result;\n    }\n    class CounterReference {\n        Counter&\
    \ base;\n        key_type key;\n\n       public:\n        CounterReference(Counter&\
    \ base, key_type key) : base(base), key(key) {}\n        CounterReference& operator=(const\
    \ mapped_type& x) {\n            base.set(key, x);\n            return *this;\n\
    \        }\n        CounterReference& operator+=(const mapped_type& x) {\n   \
    \         base.inc(key, x);\n            return *this;\n        }\n        CounterReference&\
    \ operator-=(const mapped_type& x) {\n            base.inc(key, -x);\n       \
    \     return *this;\n        }\n        operator mapped_type() const {\n     \
    \       return base.get(key);\n        }\n    };\n    mapped_type operator[](const\
    \ key_type& key) const {\n        return get(key);\n    }\n    CounterReference\
    \ operator[](const key_type& key) {\n        return CounterReference(*this, key);\n\
    \    }\n};\n\ntemplate <typename T>\nCounter(std::vector<T>) -> Counter<T>;\n"
  dependsOn:
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/data_structures/counter.hpp
  requiredBy: []
  timestamp: '2026-11-08 20:13:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/counter.test.cpp
  - test/aoj/volume0/0029.test.cpp
  - test/aoj/itp2/itp2-7-d.test.cpp
  - test/yosupo/data_structure/associative-array.test.cpp
documentation_of: src/data_structures/counter.hpp
layout: document
title: "\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408 (Counter)"
---

値ごとの個数を `std::map` で管理する多重集合 `Counter<T>` です (Python の `collections.Counter`)。個数が 0 になった値は自動で取り除かれます。出現回数順の `std::set` も管理し、最頻値を $O(1)$ で取得できます。

```cpp
std::vector<int> v = {3, 1, 3, 2, 3};
Counter<int> c(v);
c[1] += 2;                        // 1 を 2 個追加
long long k = c[3];               // 3
auto [value, count] = *c.mode();  // 最頻値とその個数 (空でない場合)
auto top = c.most_common();       // 個数の多い順
auto top2 = c.most_common(2);     // 上位 2 件 (値, 個数)
for (auto [x, cnt] : c) { }       // 値の昇順に走査
for (auto [x, cnt] : c.by_frequency()) { }  // 個数の降順、同数なら値の昇順。コピーなし
Counter<int> d = c + Counter<int>(3);  // 3 を 1 個足した Counter
```

空の `Counter` の `mode()` は `std::nullopt` を返します。同数なら最小の値を選びます。個数の変更には `[]`・`set`・`inc` を使います。

`by_frequency()` は内部の `std::set<value_type, CompareFrequency>` の const 参照を返します (`value_type` は `{値, 個数}` の組)。保持するときは `const auto& freq = c.by_frequency();` と書きます。`begin()`・`rbegin()`・`lower_bound()` などを使え、境界検索の順序も個数の降順・同数なら値の昇順です。

参照先には `Counter` の更新が反映されます。更新した値の要素へのイテレータは失効します。参照は元の `Counter` の生存中に使ってください。

## メンバ関数

`n` は異なる値の個数です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Counter<T> c` | 空の Counter | $O(1)$ |
| `Counter<T> c(x)` | 値 `x` が 1 個 | $O(1)$ |
| `Counter<T> c{ {x, k}, ... }` | 値 `x` が `k` 個、… で初期化 | $O(m \log m)$ ($m$ は組の数) |
| `Counter<T> c(v)` | コンテナ `v` の要素を数える | $O(\lvert v \rvert \log n)$ |
| `c[x]` / `c.get(x)` | `x` の個数 (なければ 0) | $O(\log n)$ |
| `c[x] = k` / `c.set(x, k)` | `x` の個数を `k` にする (`k >= 0`) | $O(\log n)$ |
| `c[x] += k`、`c[x] -= k` / `c.inc(x, k)` | `x` の個数を増減する (負になると assert で落ちる) | $O(\log n)$ |
| `c + d`、`c += d` | 個数を足し合わせる | $O(m \log (n + m))$ ($m$ は `d` の異なる値の個数) |
| `c - d`、`c -= d` | 個数を引く (負になると assert で落ちる)。`c -= c` で空になる | $O(m \log n)$ |
| `for (auto [x, cnt] : c)` | `{値, 個数}` を値の昇順に走査 | $O(n)$ |
| `c.lower_bound(x)` / `c.upper_bound(x)` | 値が `x` 以上 / より大きい最初の要素の読み取り専用イテレータ。なければ `end()` | $O(\log n)$ |
| `c.size()` | 異なる値の個数 (重複は数えない) | $O(1)$ |
| `c.total()` | 重複を含めた要素数 (個数の総和。Python の `Counter.total()` と同じ) | $O(n)$ |
| `c.mode()` | 最頻値と個数を `std::optional<Mode>` (`Mode {value, count}`) で返す。同数なら最小の値を選び、空なら `std::nullopt` を返す | $O(1)$ |
| `c.by_frequency()` | 頻度順の内部 set の const 参照。個数の降順、同数なら値の昇順 | $O(1)$ |
| `c.most_common()` | `{値, 個数}` のリスト。個数の降順、同数なら値の昇順 | $O(n)$ |
| `c.most_common(k)` | 同じ順序で上位 `k` 件を返す (`k >= 0`)。`k > n` なら全件、`k = 0` または空なら空のリスト | $O(\min(k, n))$ |

## 関連

- 最大・最小と任意の要素の削除だけなら [削除可能な優先度付きキュー](erasable-priority-queue.hpp)
