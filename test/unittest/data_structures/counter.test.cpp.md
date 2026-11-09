---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/counter.hpp
    title: "\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408\
      \ (Counter)"
  - icon: ':heavy_check_mark:'
    path: src/utility/range.hpp
    title: "Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\u3001\
      \u305D\u306E\u76F4\u7A4D\u306E Grid"
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
  bundledCode: "#line 1 \"test/unittest/data_structures/counter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Counter \u3092 std::map \u306B\u3088\u308B\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/counter.hpp\"\
    \n\n/**\n * @file counter.hpp\n * @brief \u5024\u306E\u500B\u6570\u3092\u6570\u3048\
    \u308B\u591A\u91CD\u96C6\u5408 (Counter)\n */\n\n#include <cassert>\n#include\
    \ <cstddef>\n#include <initializer_list>\n#include <iterator>\n#include <map>\n\
    #include <optional>\n#include <set>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include\
    \ <functional>\n#line 14 \"src/utility/traits.hpp\"\n\n#if __cplusplus >= 202002L\n\
    #include <concepts>\n#include <ranges>\n#endif\n\nnamespace internal_traits {\n\
    using std::begin, std::end;\n\n#if __cplusplus >= 202002L\ntemplate <class T>\n\
    \    struct is_range_impl : std::bool_constant < requires(T& t) {\n    begin(t);\n\
    \    end(t);\n}>{};\n#else\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n#endif\n\n// \u30B5\u30A4\u30BA\
    \u4ED8\u304D\u7BC4\u56F2\u304B\u3089\u8981\u7D20\u3092\u76F4\u63A5\u69CB\u7BC9\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u5171\u6709\u3059\
    \u308B\u3002\n#if __cplusplus >= 202002L\ntemplate <class R, class S>\nconcept\
    \ sized_constructible_range = std::ranges::input_range<R> && std::ranges::sized_range<R>\
    \ &&\n                                    std::is_constructible_v<S, std::ranges::range_reference_t<R>>;\n\
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
    \n#if __cplusplus >= 202002L\n#define HAS_METHOD(func_name)                  \
    \                                                 \\\n    namespace internal_traits\
    \ {                                                                 \\\n    template\
    \ <class T>                                                                  \
    \        \\\n    concept has_##func_name##_impl = requires { std::declval<T>().func_name();\
    \ };               \\\n    }                                                 \
    \                                          \\\n    template <class T>        \
    \                                                                  \\\n    struct\
    \ has_##func_name : std::bool_constant<internal_traits::has_##func_name##_impl<T>>\
    \ {}; \\\n    template <class T>                                             \
    \                             \\\n    inline constexpr bool has_##func_name##_v\
    \ = has_##func_name<T>::value;\n\n#define HAS_METHOD_ARG(func_name)          \
    \                                                        \\\n    namespace internal_traits\
    \ {                                                                    \\\n  \
    \  template <class T, class U>                                               \
    \                     \\\n    concept has_##func_name##_impl = requires { std::declval<T>().func_name(std::declval<U>());\
    \ }; \\\n    }                                                               \
    \                               \\\n    template <class T, class U>          \
    \                                                          \\\n    struct has_##func_name\
    \ : std::bool_constant<internal_traits::has_##func_name##_impl<T, U>> {}; \\\n\
    \    template <class T, class U>                                             \
    \                       \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T,\
    \ U>::value;\n#else\n#define HAS_METHOD(func_name)                           \
    \                                   \\\n    namespace internal_traits {      \
    \                                                      \\\n    template <class\
    \ T, class = void>                                                       \\\n\
    \    struct has_##func_name##_impl : std::false_type {};                     \
    \               \\\n    template <class T>                                   \
    \                                  \\\n    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
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
    #endif\n\nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\n\
    HAS_METHOD(max)\nHAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\n\
    HAS_METHOD(product)\nHAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\n\
    HAS_METHOD_ARG(lower_bound)\nHAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr)\
    \ std::enable_if_t<expr, std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
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
    \u3089\u3067\u53D7\u3051\u53D6\u3089\u306A\u3044\n     */\n#if __cplusplus >=\
    \ 202002L\n    template <class C>\n        requires(!std::same_as<std::decay_t<C>,\
    \ Counter> && !std::convertible_to<C, key_type> &&\n                 requires(C&\
    \ c) { std::begin(c); std::end(c); })\n#else\n    template <class C, ENABLE_IF_T(!std::is_same_v<std::decay_t<C>,\
    \ Counter> && !std::is_convertible_v<C, key_type>),\n              class = decltype(std::begin(std::declval<C&>()),\
    \ std::end(std::declval<C&>()))>\n#endif\n    explicit Counter(C&& v) {\n    \
    \    for (const key_type& a : v) {\n            inc(a, 1);\n        }\n    }\n\
    \    Counter(std::initializer_list<value_type> init) {\n        for (const auto&\
    \ p : init) {\n            inc(p.first, p.second);\n        }\n    }\n    Counter&\
    \ operator+=(const Counter& o) {\n        for (const auto& [i, c] : o.data) {\n\
    \            inc(i, c);\n        }\n        return *this;\n    }\n    friend Counter\
    \ operator+(const Counter& a, const Counter& b) {\n        Counter res(a);\n \
    \       return res += b;\n    }\n    Counter& operator-=(const Counter& o) {\n\
    \        // \u81EA\u5206\u81EA\u8EAB\u3092\u5F15\u304F\u3068\u3001\u8D70\u67FB\
    \u4E2D\u306E o.data \u306E\u8981\u7D20\u3092 inc \u304C\u6D88\u3057\u3066\u3057\
    \u307E\u3046\n        if (this == &o) {\n            data.clear();\n         \
    \   frequency.clear();\n            return *this;\n        }\n        for (const\
    \ auto& [i, c] : o.data) {\n            inc(i, -c);\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator-(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res -= b;\n    }\n    auto begin()\
    \ const { return data.begin(); }\n    auto end() const { return data.end(); }\n\
    \    /** @brief key \u4EE5\u4E0A\u306E\u6700\u521D\u306E\u5024\u306E\u8AAD\u307F\
    \u53D6\u308A\u5C02\u7528\u30A4\u30C6\u30EC\u30FC\u30BF (\u306A\u3051\u308C\u3070\
    \ end()) */\n    auto lower_bound(const key_type& key) const { return data.lower_bound(key);\
    \ }\n    /** @brief key \u3088\u308A\u5927\u304D\u3044\u6700\u521D\u306E\u5024\
    \u306E\u8AAD\u307F\u53D6\u308A\u5C02\u7528\u30A4\u30C6\u30EC\u30FC\u30BF (\u306A\
    \u3051\u308C\u3070 end()) */\n    auto upper_bound(const key_type& key) const\
    \ { return data.upper_bound(key); }\n    /**\n     * @brief \u7570\u306A\u308B\
    \u5024\u306E\u500B\u6570 (\u91CD\u8907\u306F\u6570\u3048\u306A\u3044)\n     */\n\
    \    long long size() const {\n        return static_cast<long long>(data.size());\n\
    \    }\n    /**\n     * @brief \u91CD\u8907\u3092\u542B\u3081\u305F\u8981\u7D20\
    \u6570 (\u500B\u6570\u306E\u7DCF\u548C)\n     * @note Python \u306E collections.Counter.total()\
    \ \u3068\u540C\u3058\u3002O(\u7570\u306A\u308B\u5024\u306E\u500B\u6570)\n    \
    \ */\n    mapped_type total() const {\n        mapped_type ret = 0;\n        for\
    \ (const auto& [key, cnt] : data) ret += cnt;\n        return ret;\n    }\n  \
    \  mapped_type get(const key_type& key) const {\n        auto itr = data.find(key);\n\
    \        if (itr == data.end()) return 0;\n        return itr->second;\n    }\n\
    \    void set(const key_type& key, const mapped_type& t) {\n        assert(t >=\
    \ 0);\n        auto itr = data.find(key);\n        if (itr != data.end()) frequency.erase(*itr);\n\
    \        if (t > 0) {\n            data[key] = t;\n            frequency.emplace(key,\
    \ t);\n        } else if (itr != data.end()) {\n            data.erase(itr);\n\
    \        }\n    }\n    struct Mode {\n        T value;\n        long long count;\n\
    \    };\n    /**\n     * @brief \u6700\u983B\u5024\u3068\u305D\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\u3002\u540C\u6570\u306A\u3089\u6700\u5C0F\u306E\u5024\u3092\
    \u9078\u3073\u3001\u7A7A\u306A\u3089 std::nullopt \u3092\u8FD4\u3059\n     * @note\
    \ O(1)\n     */\n    std::optional<Mode> mode() const {\n        if (frequency.empty())\
    \ return std::nullopt;\n        const auto& [value, count] = *frequency.begin();\n\
    \        return Mode{value, count};\n    }\n    /**\n     * @brief \u500B\u6570\
    \u306E\u964D\u9806\u3001\u540C\u6570\u306A\u3089\u5024\u306E\u6607\u9806\u306B\
    \u4E26\u3079\u305F\u5185\u90E8 set \u306E const \u53C2\u7167 (\u30B3\u30D4\u30FC\
    \u3057\u306A\u3044)\n     * @note O(1)\u3002Counter \u306E\u66F4\u65B0\u306F\u53C2\
    \u7167\u5148\u306B\u3082\u53CD\u6620\u3055\u308C\u308B\u3002\u66F4\u65B0\u3057\
    \u305F\u5024\u306E\u8981\u7D20\u3078\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\u306F\
    \u5931\u52B9\u3059\u308B\n     */\n    const auto& by_frequency() const { return\
    \ frequency; }\n    std::vector<value_type> most_common() const {\n        return\
    \ {frequency.begin(), frequency.end()};\n    }\n    /**\n     * @brief \u500B\u6570\
    \u306E\u591A\u3044\u9806\u306B\u4E0A\u4F4D k \u4EF6\u3092\u8FD4\u3059\u3002\u540C\
    \u6570\u306A\u3089\u5024\u306E\u6607\u9806\u3002k >= 0\n     * @note k \u304C\u7570\
    \u306A\u308B\u5024\u306E\u500B\u6570\u3088\u308A\u5927\u304D\u3051\u308C\u3070\
    \u5168\u4EF6\u3092\u8FD4\u3059\u3002O(min(k, size()))\n     */\n    std::vector<value_type>\
    \ most_common(long long k) const {\n        assert(k >= 0);\n        if (k > size())\
    \ k = size();\n        std::vector<value_type> result;\n        result.reserve(k);\n\
    \        auto itr = frequency.begin();\n        for (long long i = 0; i < k; ++i,\
    \ ++itr) result.push_back(*itr);\n        return result;\n    }\n    class CounterReference\
    \ {\n        Counter& base;\n        key_type key;\n\n       public:\n       \
    \ CounterReference(Counter& base, key_type key) : base(base), key(key) {}\n  \
    \      CounterReference& operator=(const mapped_type& x) {\n            base.set(key,\
    \ x);\n            return *this;\n        }\n        CounterReference& operator+=(const\
    \ mapped_type& x) {\n            base.inc(key, x);\n            return *this;\n\
    \        }\n        CounterReference& operator-=(const mapped_type& x) {\n   \
    \         base.inc(key, -x);\n            return *this;\n        }\n        operator\
    \ mapped_type() const {\n            return base.get(key);\n        }\n    };\n\
    \    mapped_type operator[](const key_type& key) const {\n        return get(key);\n\
    \    }\n    CounterReference operator[](const key_type& key) {\n        return\
    \ CounterReference(*this, key);\n    }\n};\n\ntemplate <typename T>\nCounter(std::vector<T>)\
    \ -> Counter<T>;\n#line 7 \"test/unittest/data_structures/counter.test.cpp\"\n\
    \n#include <algorithm>\n#include <iostream>\n#line 11 \"test/unittest/data_structures/counter.test.cpp\"\
    \n#include <random>\n#include <string>\n#line 16 \"test/unittest/data_structures/counter.test.cpp\"\
    \n\n#line 2 \"src/utility/range.hpp\"\n\n/**\n * @file range.hpp\n * @brief Python\
    \ \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\u3001\u305D\u306E\
    \u76F4\u7A4D\u306E Grid\n */\n\n#line 15 \"src/utility/range.hpp\"\n\nstruct Range\
    \ {\n   public:\n    using value_type = long long;\n    using const_reference\
    \ = value_type;\n    using size_type = long long;\n    using difference_type =\
    \ std::ptrdiff_t;\n\n    const value_type start;\n    const value_type stop;\n\
    \    const value_type step;\n\n   private:\n    const value_type norm_stop;\n\n\
    \    constexpr static value_type normalize(value_type _start, value_type _stop,\
    \ value_type _step) {\n        assert(_step != 0);\n        if (_step > 0) {\n\
    \            if (_start >= _stop) {\n                return _start;\n        \
    \    } else {\n                return _start + (_stop - _start + _step - 1) /\
    \ _step * _step;\n            }\n        } else {\n            if (_start <= _stop)\
    \ {\n                return _start;\n            } else {\n                return\
    \ _start - (_start - _stop - _step - 1) / _step * _step;\n            }\n    \
    \    }\n    }\n\n    constexpr Range(value_type _start, value_type _stop, value_type\
    \ _step, value_type _norm_stop)\n        : start(_start), stop(_stop), step(_step),\
    \ norm_stop(_norm_stop) {\n    }\n\n   public:\n    /**\n     * @brief start \u304B\
    \u3089 stop \u306E\u624B\u524D\u307E\u3067 step \u305A\u3064\u9032\u3080\u6574\
    \u6570\u5217\n     * @pre step != 0\n     */\n    constexpr Range(value_type _start,\
    \ value_type _stop, value_type _step)\n        : start(_start), stop(_stop), step(_step),\
    \ norm_stop(normalize(_start, _stop, _step)) {\n    }\n    constexpr Range(value_type\
    \ _start, value_type _stop)\n        : start(_start), stop(_stop), step(1), norm_stop(normalize(_start,\
    \ _stop, 1)) {}\n    explicit constexpr Range(value_type _stop)\n        : start(0),\
    \ stop(_stop), step(1), norm_stop(normalize(0, _stop, 1)) {}\n    constexpr Range()\n\
    \        : start(0), stop(0), step(1), norm_stop(0) {\n    }\n    constexpr Range(const\
    \ Range& o) = default;\n    Range& operator=(const Range& o) = delete;\n\n   \
    \ struct const_iterator {\n       public:\n        using difference_type = Range::difference_type;\n\
    \        using value_type = Range::value_type;\n        using pointer = void;\n\
    \        using reference = Range::const_reference;\n        using iterator_category\
    \ = std::random_access_iterator_tag;\n\n       private:\n        value_type first\
    \ = 0, stop = 0, step = 1, value = 0;\n\n        constexpr bool same_range(const\
    \ const_iterator& o) const noexcept {\n            return first == o.first &&\
    \ stop == o.stop && step == o.step;\n        }\n\n       public:\n        constexpr\
    \ const_iterator() noexcept = default;\n        constexpr const_iterator(const\
    \ Range& range, value_type value) noexcept\n            : first(range.start),\
    \ stop(range.stop), step(range.step), value(value) {}\n        constexpr reference\
    \ base() const noexcept {\n            return value;\n        }\n        constexpr\
    \ const_iterator& operator++() noexcept {\n            value += step;\n      \
    \      return *this;\n        }\n        constexpr const_iterator operator++(int)\
    \ noexcept {\n            const_iterator ret(*this);\n            value += step;\n\
    \            return ret;\n        }\n        constexpr const_iterator& operator+=(difference_type\
    \ _n) noexcept {\n            value += _n * step;\n            return *this;\n\
    \        }\n        constexpr friend const_iterator operator+(const const_iterator&\
    \ i, difference_type _n) noexcept {\n            const_iterator ret(i);\n    \
    \        ret += _n;\n            return ret;\n        }\n        constexpr friend\
    \ const_iterator operator+(difference_type _n, const const_iterator& i) noexcept\
    \ {\n            const_iterator ret(i);\n            ret += _n;\n            return\
    \ ret;\n        }\n        constexpr const_iterator& operator--() noexcept {\n\
    \            value -= step;\n            return *this;\n        }\n        constexpr\
    \ const_iterator operator--(int) noexcept {\n            const_iterator ret(*this);\n\
    \            value -= step;\n            return ret;\n        }\n        constexpr\
    \ const_iterator& operator-=(difference_type _n) noexcept {\n            value\
    \ -= _n * step;\n            return *this;\n        }\n        constexpr friend\
    \ const_iterator operator-(const const_iterator& i, difference_type _n) noexcept\
    \ {\n            const_iterator ret(i);\n            ret -= _n;\n            return\
    \ ret;\n        }\n        constexpr reference operator[](difference_type i) const\
    \ noexcept { return value + i * step; }\n        constexpr reference operator*()\
    \ const noexcept {\n            return value;\n        }\n        constexpr friend\
    \ bool operator!=(const const_iterator& a, const const_iterator& b) noexcept {\n\
    \            return !a.same_range(b) || a.value != b.value;\n        }\n     \
    \   constexpr friend bool operator==(const const_iterator& a, const const_iterator&\
    \ b) noexcept {\n            return !(a != b);\n        }\n        constexpr friend\
    \ bool operator<(const const_iterator& a, const const_iterator& b) noexcept {\n\
    \            assert(a.same_range(b));\n            return a.step > 0 ? a.value\
    \ < b.value : a.value > b.value;\n        }\n        constexpr friend bool operator>(const\
    \ const_iterator& a, const const_iterator& b) noexcept { return b < a; }\n   \
    \     constexpr friend bool operator<=(const const_iterator& a, const const_iterator&\
    \ b) noexcept { return !(b < a); }\n        constexpr friend bool operator>=(const\
    \ const_iterator& a, const const_iterator& b) noexcept { return !(a < b); }\n\
    \        constexpr friend difference_type operator-(const const_iterator& a, const\
    \ const_iterator& b) {\n            assert(a.same_range(b));\n            if (a.step\
    \ > 0) {\n                return (a.value - b.value) / a.step;\n            }\
    \ else {\n                return (b.value - a.value) / (-a.step);\n          \
    \  }\n        }\n    };\n\n    constexpr const_iterator begin() const noexcept\
    \ {\n        return {*this, start};\n    }\n    constexpr const_iterator end()\
    \ const noexcept {\n        return {*this, norm_stop};\n    }\n    /**\n     *\
    \ @brief x \u306E\u500B\u6570 (0 \u304B 1)\n     */\n    constexpr size_type count(value_type\
    \ x) const noexcept {\n        // step \u304C\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\
    \u306B\u5206\u304B\u3089\u306A\u3044\u3068\u304D\u3082\u3001\u3088\u304F\u4F7F\
    \u3046 step = 1 \u3067\u306F\u5272\u308A\u7B97\u3092\u3057\u306A\u3044\n     \
    \   if (step == 1) return start <= x && x < stop;\n        if (step > 0) {\n \
    \           if (start <= x && x < stop) {\n                if ((x - start) % step\
    \ == 0) {\n                    return 1;\n                }\n            }\n \
    \       } else {\n            if (stop < x && x <= start) {\n                if\
    \ ((start - x) % (-step) == 0) {\n                    return 1;\n            \
    \    }\n            }\n        }\n        return 0;\n    }\n    /**\n     * @brief\
    \ x \u304C\u542B\u307E\u308C\u308B\u304B\n     */\n    constexpr bool contains(value_type\
    \ x) const noexcept {\n        return count(x) != 0;\n    }\n    /**\n     * @brief\
    \ x \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * x \u304C\u542B\u307E\u308C\
    \u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr size_type index(value_type\
    \ x) const {\n        assert(contains(x));\n        if (step == 1) return x -\
    \ start;\n        return (x - start) / step;\n    }\n    /**\n     * @brief \u8981\
    \u7D20\u304C x \u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n     * x \u304C\u542B\u307E\
    \u308C\u306A\u3044\u3068 end() \u3092\u8FD4\u3059\n     */\n    constexpr const_iterator\
    \ find(value_type x) const noexcept {\n        if (contains(x)) {\n          \
    \  return {*this, x};\n        } else {\n            return {*this, norm_stop};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C x \u4EE5\u4E0A\u306E\
    \u6700\u5C0F\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n     * step > 0 \u3058\u3083\
    \u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr const_iterator lower_bound(value_type\
    \ x) const {\n        assert(step > 0);\n        if (norm_stop <= x) {\n     \
    \       return end();\n        } else if (x < start) {\n            return begin();\n\
    \        } else {\n            return {*this, start + (x - start + step - 1) /\
    \ step * step};\n        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C x\
    \ \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n     * step > 0 \u3058\u3083\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n\
    \    constexpr const_iterator upper_bound(value_type x) const {\n        assert(step\
    \ > 0);\n        if (norm_stop <= x) {\n            return end();\n        } else\
    \ if (x < start) {\n            return begin();\n        } else {\n          \
    \  return {*this, start + (x - start + step) / step * step};\n        }\n    }\n\
    \    /**\n     * @brief \u30B3\u30F3\u30C6\u30CA\u306E\u8981\u7D20\u6570\n   \
    \  */\n    constexpr size_type size() const noexcept {\n        if (step > 0)\
    \ {\n            return (norm_stop - start) / step;\n        } else {\n      \
    \      return (start - norm_stop) / (-step);\n        }\n    }\n    constexpr\
    \ value_type at(size_type i) const {\n        assert(0 <= i && i < size());\n\
    \        return start + i * step;\n    }\n    constexpr value_type operator[](size_type\
    \ i) const {\n        return at(i);\n    }\n    constexpr bool empty() const noexcept\
    \ {\n        return start == norm_stop;\n    }\n    constexpr value_type sum()\
    \ const noexcept {\n        return size() * (norm_stop - step + start) / 2;\n\
    \    }\n    /**\n     * @brief \u6700\u5C0F\u5024\n     * \u7A7A\u3060\u3068\u30A8\
    \u30E9\u30FC\n     */\n    constexpr value_type min() const {\n        assert(!empty());\n\
    \        if (step > 0) {\n            return start;\n        } else {\n      \
    \      return norm_stop - step;\n        }\n    }\n    /**\n     * @brief \u6700\
    \u5927\u5024\n     * \u7A7A\u3060\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr\
    \ value_type max() const {\n        assert(!empty());\n        if (step > 0) {\n\
    \            return norm_stop - step;\n        } else {\n            return start;\n\
    \        }\n    }\n    /**\n     * @brief \u7DCF xor\n     * \u8CA0\u3092\u542B\
    \u3080\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr value_type product_xor()\
    \ const noexcept {\n        if (empty()) return 0;\n        assert(min() >= 0);\n\
    \        Range sorted_range(sorted());\n        value_type res = 0;\n        std::make_unsigned_t<value_type>\
    \ t = 1;\n        while (t <= static_cast<std::make_unsigned_t<value_type>>(max()))\
    \ {\n            std::make_unsigned_t<value_type> tmp = 0, n = size(), m = t,\
    \ a = sorted_range.step, b = sorted_range.start;\n            while (true) {\n\
    \                if (a >= m) {\n                    tmp += n * (n - 1) / 2 * (a\
    \ / m);\n                    a %= m;\n                }\n                if (b\
    \ >= m) {\n                    tmp += n * (b / m);\n                    b %= m;\n\
    \                }\n                std::make_unsigned_t<value_type> y_max = a\
    \ * n + b;\n                if (y_max < m) break;\n                n = y_max /\
    \ m;\n                b = y_max % m;\n                std::swap(m, a);\n     \
    \       }\n            if (tmp % 2 == 1) {\n                res += t;\n      \
    \      }\n            t <<= 1;\n        }\n        return res;\n    }\n    /**\n\
    \     * @brief \u9006\u9806\u306B\u3057\u305F\u3082\u306E\n     */\n    constexpr\
    \ Range reversed() const noexcept {\n        return {norm_stop - step, start -\
    \ step, -step, start - step};\n    }\n    /**\n     * @brief step > 0 \u3060\u3068\
    \u305D\u306E\u307E\u307E step < 0 \u3060\u3068\u9006\u9806\u306B\u3057\u305F\u3082\
    \u306E\n     */\n    constexpr Range sorted() const noexcept {\n        if (step\
    \ > 0) {\n            return {start, norm_stop, step, norm_stop};\n        } else\
    \ {\n            return {norm_stop - step, start - step, -step, start - step};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C [l, r) \u3067\u3042\
    \u308B\u7BC4\u56F2\u3092\u8FD4\u3059\n     */\n    constexpr Range clipped(value_type\
    \ l, value_type r) const {\n        if (l >= r) return {};\n        r--;  // \u4EE5\
    \u4E0B\u3067\u306F r \u3092\u542B\u3080 [l, r] \u3068\u3057\u3066\u6271\u3046\n\
    \        if (step > 0) {\n            value_type _start = [&] {\n            \
    \    if (norm_stop <= l) {\n                    return norm_stop;\n          \
    \      } else if (l < start) {\n                    return start;\n          \
    \      } else {\n                    return start + (l - start + step - 1) / step\
    \ * step;\n                }\n            }();\n            value_type _stop =\
    \ [&] {\n                if (norm_stop <= r) {\n                    return norm_stop;\n\
    \                } else if (r < start) {\n                    return start;\n\
    \                } else {\n                    return start + (r - start + step)\
    \ / step * step;\n                }\n            }();\n            return {_start,\
    \ _stop, step, _stop};\n        } else {\n            value_type _start = [&]\
    \ {\n                if (start - step <= r) {\n                    return start;\n\
    \                } else if (r < norm_stop - step) {\n                    return\
    \ norm_stop;\n                } else {\n                    return norm_stop +\
    \ (r - norm_stop) / step * step;\n                }\n            }();\n      \
    \      value_type _stop = [&] {\n                if (start - step <= l) {\n  \
    \                  return start;\n                } else if (l < norm_stop - step)\
    \ {\n                    return norm_stop;\n                } else {\n       \
    \             return norm_stop + (l - norm_stop - 1) / step * step;\n        \
    \        }\n            }();\n            return {_start, _stop, step, _stop};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u3092 Range \u3067\u6307\
    \u5B9A\u3057\u305F\u30B3\u30F3\u30C6\u30CA\n     */\n    constexpr Range slice(const\
    \ Range& r) const {\n        if (r.empty()) return {};\n        if (r.max() <\
    \ 0) return {};\n        if (r.min() >= size()) return {};\n        Range trimmed_range(r.clipped(0,\
    \ size()));\n        if (trimmed_range.empty()) return {};\n        value_type\
    \ _step = step * trimmed_range.step;\n        value_type _start = at(trimmed_range.start);\n\
    \        value_type _stop = _start + _step * trimmed_range.size();\n        return\
    \ {_start, _stop, _step, _stop};\n    }\n\n    static std::string type_str() {\n\
    \        return \"Range\";\n    }\n    std::string initializer_str() const {\n\
    \        return \"{\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \"}\";\n    }\n    std::string repr() const\
    \ {\n        return \"Range(\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \")\";\n    }\n\n    std::vector<value_type>\
    \ to_vector() const {\n        std::vector<value_type> ret;\n        ret.reserve(size());\n\
    \        if (step > 0) {\n            for (value_type x = start; x < stop; x +=\
    \ step) {\n                ret.push_back(x);\n            }\n        } else {\n\
    \            for (value_type x = start; x > stop; x += step) {\n             \
    \   ret.push_back(x);\n            }\n        }\n        return ret;\n    }\n\
    \    constexpr friend bool operator==(const Range& a, const Range& b) noexcept\
    \ {\n        if (a.empty() && b.empty()) return true;\n        if (a.size() !=\
    \ b.size()) return false;\n        if (a.start != b.start) return false;\n   \
    \     if (a.size() == 1) return true;\n        if (a.step != b.step) return false;\n\
    \        return true;\n    }\n    constexpr friend bool operator!=(const Range&\
    \ a, const Range& b) noexcept {\n        return !(a == b);\n    }\n};\n\n/**\n\
    \ * @brief 2 \u3064\u306E Range \u306E\u76F4\u7A4D rows \xD7 cols\n * (i, j) \u3092\
    \ i \u306E\u6607\u9806\u3001\u540C\u3058 i \u3067\u306F j \u306E\u6607\u9806 (\u884C\
    \u512A\u5148) \u306B\u4E26\u3079\u305F\u3082\u306E\u3068\u3057\u3066\u6271\u3046\
    \n */\nstruct Grid {\n   public:\n    using value_type = std::pair<long long,\
    \ long long>;\n    using size_type = long long;\n    using difference_type = std::ptrdiff_t;\n\
    \n    const Range rows;\n    const Range cols;\n\n   private:\n    const long\
    \ long width;  // cols.size() (index \u3084 at \u3067\u6BCE\u56DE\u5272\u308A\u7B97\
    \u3057\u306A\u3044\u3088\u3046\u306B\u6301\u3063\u3066\u304A\u304F)\n\n   public:\n\
    \    /**\n     * @brief [0, h) \xD7 [0, w)\n     */\n    constexpr Grid(long long\
    \ h, long long w) : rows(h), cols(w), width(cols.size()) {}\n    constexpr Grid(const\
    \ Range& _rows, const Range& _cols) : rows(_rows), cols(_cols), width(cols.size())\
    \ {}\n    constexpr Grid(const Grid& o) = default;\n    Grid& operator=(const\
    \ Grid& o) = delete;\n\n    struct const_iterator {\n       public:\n        using\
    \ difference_type = Grid::difference_type;\n        using value_type = Grid::value_type;\n\
    \        using pointer = void;\n        using reference = value_type;\n      \
    \  using iterator_category = std::forward_iterator_tag;\n\n       private:\n \
    \       const Grid* rect = nullptr;\n        long long w = 0;   // cols.size()\n\
    \        long long ic = 0;  // rows \u306E\u4F55\u756A\u76EE\u304B\n        long\
    \ long jc = 0;  // cols \u306E\u4F55\u756A\u76EE\u304B\n\n       public:\n   \
    \     constexpr const_iterator() noexcept = default;\n        constexpr const_iterator(const\
    \ Grid* _rect, long long _w, long long _ic, long long _jc) noexcept\n        \
    \    : rect(_rect), w(_w), ic(_ic), jc(_jc) {}\n        constexpr value_type operator*()\
    \ const noexcept {\n            return {rect->rows.start + ic * rect->rows.step,\
    \ rect->cols.start + jc * rect->cols.step};\n        }\n        constexpr const_iterator&\
    \ operator++() noexcept {\n            if (++jc == w) {\n                jc =\
    \ 0;\n                ++ic;\n            }\n            return *this;\n      \
    \  }\n        constexpr const_iterator operator++(int) noexcept {\n          \
    \  const_iterator ret(*this);\n            ++*this;\n            return ret;\n\
    \        }\n        constexpr friend bool operator==(const const_iterator& a,\
    \ const const_iterator& b) noexcept {\n            return a.ic == b.ic && a.jc\
    \ == b.jc;\n        }\n        constexpr friend bool operator!=(const const_iterator&\
    \ a, const const_iterator& b) noexcept {\n            return !(a == b);\n    \
    \    }\n    };\n\n    constexpr const_iterator begin() const noexcept {\n    \
    \    return {this, width, width == 0 ? rows.size() : 0, 0};\n    }\n    constexpr\
    \ const_iterator end() const noexcept {\n        return {this, width, rows.size(),\
    \ 0};\n    }\n    /**\n     * @brief \u8981\u7D20\u6570 rows.size() * cols.size()\n\
    \     */\n    constexpr size_type size() const noexcept {\n        return rows.size()\
    \ * width;\n    }\n    constexpr bool empty() const noexcept {\n        return\
    \ rows.empty() || cols.empty();\n    }\n    /**\n     * @brief (i, j) \u304C\u542B\
    \u307E\u308C\u308B\u304B\n     */\n    constexpr bool contains(long long i, long\
    \ long j) const noexcept {\n        return rows.contains(i) && cols.contains(j);\n\
    \    }\n    constexpr bool contains(const value_type& p) const noexcept {\n  \
    \      return contains(p.first, p.second);\n    }\n    /**\n     * @brief (i,\
    \ j) \u306E\u884C\u512A\u5148\u3067\u306E\u4F4D\u7F6E (\u30B0\u30EA\u30C3\u30C9\
    \u306E\u9802\u70B9\u756A\u53F7\u306B\u4F7F\u3046)\n     * (i, j) \u304C\u542B\u307E\
    \u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr size_type index(long\
    \ long i, long long j) const {\n        assert(contains(i, j));\n        return\
    \ rows.index(i) * width + cols.index(j);\n    }\n    constexpr size_type index(const\
    \ value_type& p) const {\n        return index(p.first, p.second);\n    }\n  \
    \  /**\n     * @brief \u884C\u512A\u5148\u3067 k \u756A\u76EE\u306E\u8981\u7D20\
    \ (index \u306E\u9006)\n     */\n    constexpr value_type at(size_type k) const\
    \ {\n        assert(0 <= k && k < size());\n        return {rows[k / width], cols[k\
    \ % width]};\n    }\n    constexpr value_type operator[](size_type k) const {\n\
    \        return at(k);\n    }\n\n   private:\n    // \u8FD1\u508D\u306E\u65B9\u5411\
    \ (rows\u30FBcols \u306E\u4E2D\u3067\u306E\u4F4D\u7F6E\u306E\u5DEE) \u3092 Grid\
    \ \u306E\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\u3002\u5148\u982D 4 \u3064\u306F\
    \u4E0A\u4E0B\u5DE6\u53F3\u3060\u3051\u3092\u4E26\u3079\u305F\u5225\u306E\u8868\
    \n    // 4 \u8FD1\u508D\u3068 8 \u8FD1\u508D\u306E\u5883\u76EE\u304C\u5206\u304B\
    \u308B\u3088\u3046\u306B 2 \u884C\u306B\u5206\u3051\u3066\u3044\u308B\u306E\u3067\
    \u6574\u5F62\u3057\u306A\u3044\n    // clang-format off\n    static constexpr\
    \ int neighbor_dirs[12][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0},\n            \
    \                                     {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0,\
    \ 1}, {1, -1}, {1, 0}, {1, 1}};\n    // clang-format on\n\n   public:\n    /**\n\
    \     * @brief neighbors4 / neighbors8 \u306E\u623B\u308A\u5024 (\u7BC4\u56F2\
    \ for \u3067\u4F7F\u3046)\n     * \u4F5C\u308B\u3068\u304D\u306B Grid \u306B\u542B\
    \u307E\u308C\u308B\u65B9\u5411\u3092\u30D3\u30C3\u30C8\u3067\u6301\u3063\u3066\
    \u304A\u304D\u3001\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\u9806\
    \u306B\u8FD4\u3059\n     */\n    struct Neighbors {\n        long long i, j, row_step,\
    \ col_step;\n        int first;      // neighbor_dirs[first + k] \u304C\u30D3\u30C3\
    \u30C8 k \u306E\u65B9\u5411\n        unsigned mask;  // Grid \u306B\u542B\u307E\
    \u308C\u308B\u65B9\u5411\n\n        struct iterator {\n            using difference_type\
    \ = std::ptrdiff_t;\n            using value_type = Grid::value_type;\n      \
    \      using pointer = void;\n            using reference = value_type;\n    \
    \        using iterator_category = std::forward_iterator_tag;\n\n            const\
    \ Neighbors* nb = nullptr;\n            unsigned rest = 0;  // \u307E\u3060\u8FD4\
    \u3057\u3066\u3044\u306A\u3044\u65B9\u5411\n\n            constexpr value_type\
    \ operator*() const noexcept {\n                const int k = nb->first + __builtin_ctz(rest);\n\
    \                return {nb->i + neighbor_dirs[k][0] * nb->row_step, nb->j + neighbor_dirs[k][1]\
    \ * nb->col_step};\n            }\n            constexpr iterator& operator++()\
    \ noexcept {\n                rest &= rest - 1;\n                return *this;\n\
    \            }\n            constexpr iterator operator++(int) noexcept {\n  \
    \              iterator ret(*this);\n                ++*this;\n              \
    \  return ret;\n            }\n            constexpr friend bool operator==(const\
    \ iterator& a, const iterator& b) noexcept { return a.rest == b.rest; }\n    \
    \        constexpr friend bool operator!=(const iterator& a, const iterator& b)\
    \ noexcept { return a.rest != b.rest; }\n        };\n        constexpr iterator\
    \ begin() const noexcept { return {this, mask}; }\n        constexpr iterator\
    \ end() const noexcept { return {this, 0}; }\n        constexpr long long size()\
    \ const noexcept { return __builtin_popcount(mask); }\n        constexpr bool\
    \ empty() const noexcept { return mask == 0; }\n    };\n\n   private:\n    constexpr\
    \ Neighbors neighbors(long long i, long long j, int first, int last) const {\n\
    \        assert(contains(i, j));\n        unsigned mask = 0;\n        for (int\
    \ k = first; k < last; k++) {\n            if (contains(i + neighbor_dirs[k][0]\
    \ * rows.step, j + neighbor_dirs[k][1] * cols.step)) mask |= 1u << (k - first);\n\
    \        }\n        return {i, j, rows.step, cols.step, first, mask};\n    }\n\
    \n   public:\n    /**\n     * @brief (i, j) \u306E\u4E0A\u4E0B\u5DE6\u53F3\u306E\
    \u3046\u3061 Grid \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Grid \u306E\
    \u9806\u306B\u8FD4\u3059\n     * \u96A3\u306F rows\u30FBcols \u306E\u4E2D\u3067\
    \u96A3\u308A\u5408\u3046\u8981\u7D20 (i \xB1 rows.step \u306A\u3069)\u3002(i,\
    \ j) \u304C\u542B\u307E\u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n \
    \   constexpr Neighbors neighbors4(long long i, long long j) const {\n       \
    \ return neighbors(i, j, 0, 4);\n    }\n    constexpr Neighbors neighbors4(const\
    \ value_type& p) const {\n        return neighbors4(p.first, p.second);\n    }\n\
    \    /**\n     * @brief (i, j) \u3092\u56F2\u3080 8 \u3064\u306E\u3046\u3061 Grid\
    \ \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Grid \u306E\u9806\u306B\
    \u8FD4\u3059\n     */\n    constexpr Neighbors neighbors8(long long i, long long\
    \ j) const {\n        return neighbors(i, j, 4, 12);\n    }\n    constexpr Neighbors\
    \ neighbors8(const value_type& p) const {\n        return neighbors8(p.first,\
    \ p.second);\n    }\n\n    static std::string type_str() {\n        return \"\
    Grid\";\n    }\n    std::string initializer_str() const {\n        return \"{\"\
    \ + rows.initializer_str() + \", \" + cols.initializer_str() + \"}\";\n    }\n\
    \    std::string repr() const {\n        return \"Grid(\" + rows.repr() + \",\
    \ \" + cols.repr() + \")\";\n    }\n\n    constexpr friend bool operator==(const\
    \ Grid& a, const Grid& b) noexcept {\n        if (a.empty() && b.empty()) return\
    \ true;\n        return a.rows == b.rows && a.cols == b.cols;\n    }\n    constexpr\
    \ friend bool operator!=(const Grid& a, const Grid& b) noexcept {\n        return\
    \ !(a == b);\n    }\n};\n#line 18 \"test/unittest/data_structures/counter.test.cpp\"\
    \n\nusing Model = std::map<int, long long>;\n\nstatic_assert(!std::is_assignable_v<decltype((std::declval<Counter<int>&>().lower_bound(0)->second)),\
    \ long long>);\nstatic_assert(!std::is_assignable_v<decltype((std::declval<Counter<int>&>().upper_bound(0)->second)),\
    \ long long>);\nusing FrequencyReference = decltype(std::declval<Counter<int>&>().by_frequency());\n\
    static_assert(std::is_lvalue_reference_v<FrequencyReference>);\nstatic_assert(std::is_const_v<std::remove_reference_t<FrequencyReference>>);\n\
    static_assert(!std::is_assignable_v<decltype((std::declval<FrequencyReference>().begin()->second)),\
    \ long long>);\n\n// \u500B\u6570 0 \u306E\u5024\u3092\u53D6\u308A\u9664\u3044\
    \u305F map \u306B\u3059\u308B\nModel normalize(Model m) {\n    for (auto itr =\
    \ m.begin(); itr != m.end();) {\n        if (itr->second == 0)\n            itr\
    \ = m.erase(itr);\n        else\n            ++itr;\n    }\n    return m;\n}\n\
    \nbool same(const Counter<int>& c, const Model& m) {\n    Model mm = normalize(m);\n\
    \    if (c.size() != static_cast<int>(mm.size())) return false;\n    // total\
    \ \u306F\u91CD\u8907\u3092\u542B\u3081\u305F\u8981\u7D20\u6570 (\u500B\u6570\u306E\
    \u7DCF\u548C)\n    long long sum = 0;\n    for (auto [x, cnt] : mm) sum += cnt;\n\
    \    if (c.total() != sum) return false;\n    // begin / end \u3067\u8D70\u67FB\
    \u3057\u305F\u7D50\u679C\u304C\u5024\u306E\u6607\u9806\u306B\u4E00\u81F4\u3059\
    \u308B\n    std::vector<std::pair<int, long long>> a(c.begin(), c.end()), b(mm.begin(),\
    \ mm.end());\n    if (a != b) return false;\n    // \u983B\u5EA6\u9806\u306E\u8D70\
    \u67FB\u3092\u3001map \u304B\u3089\u72EC\u7ACB\u306B\u4E26\u3079\u66FF\u3048\u305F\
    \u5217\u3068\u6BD4\u3079\u308B\n    std::stable_sort(b.begin(), b.end(), [](const\
    \ auto& p, const auto& q) { return p.second > q.second; });\n    const auto& frequency\
    \ = c.by_frequency();\n    if (std::vector<std::pair<int, long long>>(frequency.begin(),\
    \ frequency.end()) != b) return false;\n    std::reverse(b.begin(), b.end());\n\
    \    if (std::vector<std::pair<int, long long>>(frequency.rbegin(), frequency.rend())\
    \ != b) return false;\n    // \u6700\u983B\u5024\u306F\u540C\u6570\u306A\u3089\
    \u6700\u5C0F\u306E\u5024\u3002\u7A7A\u306A\u3089 nullopt\n    auto mode = c.mode();\n\
    \    if (mm.empty()) {\n        if (mode) return false;\n    } else {\n      \
    \  auto best = mm.begin();\n        for (auto itr = mm.begin(); itr != mm.end();\
    \ ++itr) {\n            if (itr->second > best->second) best = itr;\n        }\n\
    \        if (!mode || mode->value != best->first || mode->count != best->second)\
    \ return false;\n    }\n    // const \u306A [] \u3068 get\n    for (int x = -1;\
    \ x <= 10; x++) {\n        long long expect = mm.count(x) ? mm.at(x) : 0;\n  \
    \      if (c[x] != expect || c.get(x) != expect) return false;\n        const\
    \ auto lower = c.lower_bound(x), upper = c.upper_bound(x);\n        const auto\
    \ expected_lower = mm.lower_bound(x), expected_upper = mm.upper_bound(x);\n  \
    \      if ((lower == c.end()) != (expected_lower == mm.end())) return false;\n\
    \        if ((upper == c.end()) != (expected_upper == mm.end())) return false;\n\
    \        if (lower != c.end() && *lower != *expected_lower) return false;\n  \
    \      if (upper != c.end() && *upper != *expected_upper) return false;\n    }\n\
    \    return true;\n}\n\nModel random_model(std::mt19937& rng) {\n    Model m;\n\
    \    int k = rng() % 6;\n    for (int i = 0; i < k; i++) m[rng() % 10] += rng()\
    \ % 4;\n    return m;\n}\n\nCounter<int> from_model(const Model& m) {\n    Counter<int>\
    \ c;\n    for (auto [x, cnt] : m) c[x] = cnt;\n    return c;\n}\n\nint main()\
    \ {\n    std::mt19937 rng(314);\n    bool ok = true;\n    auto check = [&](bool\
    \ cond, const char* what) {\n        if (!cond && ok) {\n            std::cerr\
    \ << \"failed: \" << what << std::endl;\n            ok = false;\n        }\n\
    \    };\n\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    {\n        Counter<int>\
    \ empty;\n        check(same(empty, {}), \"default constructor\");\n        Counter<int>\
    \ one(5);\n        check(same(one, {{5, 1}}), \"Counter(x)\");\n        std::vector<int>\
    \ v = {3, 1, 3, 2, 3};\n        Counter from_vec(v);\n        check(same(from_vec,\
    \ {{1, 1}, {2, 1}, {3, 3}}), \"Counter(range)\");\n        Counter<int> from_il{{1,\
    \ 2}, {4, 0}, {7, 3}, {1, 1}};\n        check(same(from_il, {{1, 3}, {7, 3}}),\
    \ \"Counter(initializer_list)\");\n        // const \u3067\u306A\u3044\u5DE6\u8FBA\
    \u5024\u304B\u3089\u306E\u30B3\u30D4\u30FC\u304C\u7BC4\u56F2\u306E\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u6A2A\u53D6\u308A\u3055\u308C\u306A\u3044\
    \n        Counter<int> copy(from_vec);\n        check(same(copy, {{1, 1}, {2,\
    \ 1}, {3, 3}}), \"copy constructor\");\n        // key_type \u304C\u7BC4\u56F2\
    \u3067\u3082\u3042\u308B\u5834\u5408\u306F\u5024 1 \u500B\u3068\u3057\u3066\u6570\
    \u3048\u308B\n        Counter<std::string> s(std::string(\"ab\"));\n        check(s.size()\
    \ == 1 && s[\"ab\"] == 1, \"Counter<std::string>(x)\");\n        Counter<char>\
    \ chars(std::string(\"aab\"));\n        check(chars['a'] == 2 && chars['b'] ==\
    \ 1 && chars.size() == 2, \"Counter<char>(string)\");\n        // size \u306F\u7570\
    \u306A\u308B\u5024\u306E\u500B\u6570\u3001total \u306F\u91CD\u8907\u3092\u542B\
    \u3081\u305F\u8981\u7D20\u6570\n        Counter<int> dup(std::vector<int>{3, 3,\
    \ 3, 5});\n        check(dup.size() == 2 && dup.total() == 4, \"size / total\"\
    );\n        check(Counter<int>().total() == 0, \"total of empty\");\n    }\n\n\
    \    for (int rep = 0; rep < 3000 && ok; rep++) {\n        Model ma = random_model(rng),\
    \ mb = random_model(rng);\n        Counter<int> a = from_model(ma), b = from_model(mb);\n\
    \        check(same(a, ma), \"operator[] =\");\n\n        // + \u3068 +=\n   \
    \     Model sum = ma;\n        for (auto [x, cnt] : mb) sum[x] += cnt;\n     \
    \   check(same(a + b, sum), \"operator+\");\n        Counter<int> c = a;\n   \
    \     c += b;\n        check(same(c, sum), \"operator+=\");\n\n        // - \u3068\
    \ -= (\u500B\u6570\u304C\u8CA0\u306B\u306A\u3089\u306A\u3044\u7BC4\u56F2\u3067\
    )\n        Model sub = sum;\n        for (auto [x, cnt] : mb) sub[x] -= cnt;\n\
    \        check(same(c - b, sub), \"operator-\");\n        c -= b;\n        check(same(c,\
    \ sub), \"operator-=\");\n\n        // [] \u306B\u3088\u308B += / -= / =\n   \
    \     Counter<int> d = from_model(ma);\n        Model md = ma;\n        for (int\
    \ t = 0; t < 20; t++) {\n            int x = rng() % 10;\n            int op =\
    \ rng() % 3;\n            if (op == 0) {\n                long long k = rng()\
    \ % 3;\n                d[x] += k;\n                md[x] += k;\n            }\
    \ else if (op == 1) {\n                long long have = md.count(x) ? md[x] :\
    \ 0;\n                long long k = have == 0 ? 0 : rng() % (have + 1);\n    \
    \            d[x] -= k;\n                md[x] -= k;\n            } else {\n \
    \               long long k = rng() % 3;\n                d[x] = k;\n        \
    \        md[x] = k;\n            }\n            check(same(d, md), \"mode after\
    \ update\");\n            // \u53C2\u7167\u304B\u3089\u306E\u8AAD\u307F\u53D6\u308A\
    \n            long long expect = normalize(md).count(x) ? normalize(md).at(x)\
    \ : 0;\n            check(static_cast<long long>(d[x]) == expect, \"CounterReference\
    \ -> mapped_type\");\n        }\n        check(same(d, md), \"operator[] += /\
    \ -= / =\");\n\n        // most_common: \u500B\u6570\u306E\u964D\u9806\u3001\u540C\
    \u6570\u306A\u3089\u5024\u306E\u6607\u9806\n        Model nm = normalize(md);\n\
    \        std::vector<std::pair<int, long long>> expect(nm.begin(), nm.end());\n\
    \        std::stable_sort(expect.begin(), expect.end(), [](const auto& p, const\
    \ auto& q) { return p.second > q.second; });\n        check(d.most_common() ==\
    \ expect, \"most_common\");\n        for (long long k = 0; k <= d.size() + 2;\
    \ ++k) {\n            auto top = expect;\n            if (k < static_cast<long\
    \ long>(top.size())) top.resize(k);\n            check(d.most_common(k) == top,\
    \ \"most_common(k)\");\n        }\n    }\n\n    // \u81EA\u5206\u81EA\u8EAB\u3092\
    \u5F15\u304F\u3068\u7A7A\u306B\u306A\u308B (\u8D70\u67FB\u4E2D\u306E\u8981\u7D20\
    \u3092\u6D88\u3057\u3066\u3082\u58CA\u308C\u306A\u3044)\n    if (ok) {\n     \
    \   Counter<int> c{{1, 2}, {3, 1}, {5, 4}};\n        c -= c;\n        check(same(c,\
    \ {}), \"self operator-=\");\n        check(c.most_common(2).empty(), \"most_common(k)\
    \ of empty\");\n        Counter<int> d{{1, 2}, {3, 1}};\n        d += d;\n   \
    \     check(same(d, {{1, 4}, {3, 2}}), \"self operator+=\");\n    }\n\n    {\n\
    \        Counter<int> c{{1, 2}, {3, 2}, {5, 1}};\n        const auto& frequency\
    \ = c.by_frequency();\n        check(*frequency.lower_bound({2, 2}) == std::make_pair(3,\
    \ 2LL), \"frequency lower_bound\");\n        check(*frequency.upper_bound({3,\
    \ 2}) == std::make_pair(5, 1LL), \"frequency upper_bound\");\n        c[5] +=\
    \ 3;\n        check(&frequency == &c.by_frequency() && *frequency.begin() == std::make_pair(5,\
    \ 4LL), \"frequency reference follows updates\");\n        c[5] = 0;\n       \
    \ check(frequency.size() == 2 && *frequency.rbegin() == std::make_pair(3, 2LL),\
    \ \"frequency reference follows erasure\");\n        c -= c;\n        check(frequency.empty(),\
    \ \"frequency reference follows clearing\");\n    }\n\n    {\n        const Range\
    \ values(0, 10, 2);\n        Counter<long long> inferred(values);\n        check(inferred.size()\
    \ == 5 && inferred.total() == 5 && inferred.get(4) == 1 && inferred.get(3) ==\
    \ 0, \"Range constructor\");\n        Counter<std::string> key(std::string(\"\
    abc\"));\n        Counter<std::string> copy(key);\n        check(copy.get(\"abc\"\
    ) == 1 && copy.total() == 1, \"range-like key and copy constructor\");\n    }\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Counter \u3092 std::map \u306B\u3088\u308B\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/data_structures/counter.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <random>\n\
    #include <string>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n#include \"../../../src/utility/range.hpp\"\n\nusing Model = std::map<int, long\
    \ long>;\n\nstatic_assert(!std::is_assignable_v<decltype((std::declval<Counter<int>&>().lower_bound(0)->second)),\
    \ long long>);\nstatic_assert(!std::is_assignable_v<decltype((std::declval<Counter<int>&>().upper_bound(0)->second)),\
    \ long long>);\nusing FrequencyReference = decltype(std::declval<Counter<int>&>().by_frequency());\n\
    static_assert(std::is_lvalue_reference_v<FrequencyReference>);\nstatic_assert(std::is_const_v<std::remove_reference_t<FrequencyReference>>);\n\
    static_assert(!std::is_assignable_v<decltype((std::declval<FrequencyReference>().begin()->second)),\
    \ long long>);\n\n// \u500B\u6570 0 \u306E\u5024\u3092\u53D6\u308A\u9664\u3044\
    \u305F map \u306B\u3059\u308B\nModel normalize(Model m) {\n    for (auto itr =\
    \ m.begin(); itr != m.end();) {\n        if (itr->second == 0)\n            itr\
    \ = m.erase(itr);\n        else\n            ++itr;\n    }\n    return m;\n}\n\
    \nbool same(const Counter<int>& c, const Model& m) {\n    Model mm = normalize(m);\n\
    \    if (c.size() != static_cast<int>(mm.size())) return false;\n    // total\
    \ \u306F\u91CD\u8907\u3092\u542B\u3081\u305F\u8981\u7D20\u6570 (\u500B\u6570\u306E\
    \u7DCF\u548C)\n    long long sum = 0;\n    for (auto [x, cnt] : mm) sum += cnt;\n\
    \    if (c.total() != sum) return false;\n    // begin / end \u3067\u8D70\u67FB\
    \u3057\u305F\u7D50\u679C\u304C\u5024\u306E\u6607\u9806\u306B\u4E00\u81F4\u3059\
    \u308B\n    std::vector<std::pair<int, long long>> a(c.begin(), c.end()), b(mm.begin(),\
    \ mm.end());\n    if (a != b) return false;\n    // \u983B\u5EA6\u9806\u306E\u8D70\
    \u67FB\u3092\u3001map \u304B\u3089\u72EC\u7ACB\u306B\u4E26\u3079\u66FF\u3048\u305F\
    \u5217\u3068\u6BD4\u3079\u308B\n    std::stable_sort(b.begin(), b.end(), [](const\
    \ auto& p, const auto& q) { return p.second > q.second; });\n    const auto& frequency\
    \ = c.by_frequency();\n    if (std::vector<std::pair<int, long long>>(frequency.begin(),\
    \ frequency.end()) != b) return false;\n    std::reverse(b.begin(), b.end());\n\
    \    if (std::vector<std::pair<int, long long>>(frequency.rbegin(), frequency.rend())\
    \ != b) return false;\n    // \u6700\u983B\u5024\u306F\u540C\u6570\u306A\u3089\
    \u6700\u5C0F\u306E\u5024\u3002\u7A7A\u306A\u3089 nullopt\n    auto mode = c.mode();\n\
    \    if (mm.empty()) {\n        if (mode) return false;\n    } else {\n      \
    \  auto best = mm.begin();\n        for (auto itr = mm.begin(); itr != mm.end();\
    \ ++itr) {\n            if (itr->second > best->second) best = itr;\n        }\n\
    \        if (!mode || mode->value != best->first || mode->count != best->second)\
    \ return false;\n    }\n    // const \u306A [] \u3068 get\n    for (int x = -1;\
    \ x <= 10; x++) {\n        long long expect = mm.count(x) ? mm.at(x) : 0;\n  \
    \      if (c[x] != expect || c.get(x) != expect) return false;\n        const\
    \ auto lower = c.lower_bound(x), upper = c.upper_bound(x);\n        const auto\
    \ expected_lower = mm.lower_bound(x), expected_upper = mm.upper_bound(x);\n  \
    \      if ((lower == c.end()) != (expected_lower == mm.end())) return false;\n\
    \        if ((upper == c.end()) != (expected_upper == mm.end())) return false;\n\
    \        if (lower != c.end() && *lower != *expected_lower) return false;\n  \
    \      if (upper != c.end() && *upper != *expected_upper) return false;\n    }\n\
    \    return true;\n}\n\nModel random_model(std::mt19937& rng) {\n    Model m;\n\
    \    int k = rng() % 6;\n    for (int i = 0; i < k; i++) m[rng() % 10] += rng()\
    \ % 4;\n    return m;\n}\n\nCounter<int> from_model(const Model& m) {\n    Counter<int>\
    \ c;\n    for (auto [x, cnt] : m) c[x] = cnt;\n    return c;\n}\n\nint main()\
    \ {\n    std::mt19937 rng(314);\n    bool ok = true;\n    auto check = [&](bool\
    \ cond, const char* what) {\n        if (!cond && ok) {\n            std::cerr\
    \ << \"failed: \" << what << std::endl;\n            ok = false;\n        }\n\
    \    };\n\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    {\n        Counter<int>\
    \ empty;\n        check(same(empty, {}), \"default constructor\");\n        Counter<int>\
    \ one(5);\n        check(same(one, {{5, 1}}), \"Counter(x)\");\n        std::vector<int>\
    \ v = {3, 1, 3, 2, 3};\n        Counter from_vec(v);\n        check(same(from_vec,\
    \ {{1, 1}, {2, 1}, {3, 3}}), \"Counter(range)\");\n        Counter<int> from_il{{1,\
    \ 2}, {4, 0}, {7, 3}, {1, 1}};\n        check(same(from_il, {{1, 3}, {7, 3}}),\
    \ \"Counter(initializer_list)\");\n        // const \u3067\u306A\u3044\u5DE6\u8FBA\
    \u5024\u304B\u3089\u306E\u30B3\u30D4\u30FC\u304C\u7BC4\u56F2\u306E\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u6A2A\u53D6\u308A\u3055\u308C\u306A\u3044\
    \n        Counter<int> copy(from_vec);\n        check(same(copy, {{1, 1}, {2,\
    \ 1}, {3, 3}}), \"copy constructor\");\n        // key_type \u304C\u7BC4\u56F2\
    \u3067\u3082\u3042\u308B\u5834\u5408\u306F\u5024 1 \u500B\u3068\u3057\u3066\u6570\
    \u3048\u308B\n        Counter<std::string> s(std::string(\"ab\"));\n        check(s.size()\
    \ == 1 && s[\"ab\"] == 1, \"Counter<std::string>(x)\");\n        Counter<char>\
    \ chars(std::string(\"aab\"));\n        check(chars['a'] == 2 && chars['b'] ==\
    \ 1 && chars.size() == 2, \"Counter<char>(string)\");\n        // size \u306F\u7570\
    \u306A\u308B\u5024\u306E\u500B\u6570\u3001total \u306F\u91CD\u8907\u3092\u542B\
    \u3081\u305F\u8981\u7D20\u6570\n        Counter<int> dup(std::vector<int>{3, 3,\
    \ 3, 5});\n        check(dup.size() == 2 && dup.total() == 4, \"size / total\"\
    );\n        check(Counter<int>().total() == 0, \"total of empty\");\n    }\n\n\
    \    for (int rep = 0; rep < 3000 && ok; rep++) {\n        Model ma = random_model(rng),\
    \ mb = random_model(rng);\n        Counter<int> a = from_model(ma), b = from_model(mb);\n\
    \        check(same(a, ma), \"operator[] =\");\n\n        // + \u3068 +=\n   \
    \     Model sum = ma;\n        for (auto [x, cnt] : mb) sum[x] += cnt;\n     \
    \   check(same(a + b, sum), \"operator+\");\n        Counter<int> c = a;\n   \
    \     c += b;\n        check(same(c, sum), \"operator+=\");\n\n        // - \u3068\
    \ -= (\u500B\u6570\u304C\u8CA0\u306B\u306A\u3089\u306A\u3044\u7BC4\u56F2\u3067\
    )\n        Model sub = sum;\n        for (auto [x, cnt] : mb) sub[x] -= cnt;\n\
    \        check(same(c - b, sub), \"operator-\");\n        c -= b;\n        check(same(c,\
    \ sub), \"operator-=\");\n\n        // [] \u306B\u3088\u308B += / -= / =\n   \
    \     Counter<int> d = from_model(ma);\n        Model md = ma;\n        for (int\
    \ t = 0; t < 20; t++) {\n            int x = rng() % 10;\n            int op =\
    \ rng() % 3;\n            if (op == 0) {\n                long long k = rng()\
    \ % 3;\n                d[x] += k;\n                md[x] += k;\n            }\
    \ else if (op == 1) {\n                long long have = md.count(x) ? md[x] :\
    \ 0;\n                long long k = have == 0 ? 0 : rng() % (have + 1);\n    \
    \            d[x] -= k;\n                md[x] -= k;\n            } else {\n \
    \               long long k = rng() % 3;\n                d[x] = k;\n        \
    \        md[x] = k;\n            }\n            check(same(d, md), \"mode after\
    \ update\");\n            // \u53C2\u7167\u304B\u3089\u306E\u8AAD\u307F\u53D6\u308A\
    \n            long long expect = normalize(md).count(x) ? normalize(md).at(x)\
    \ : 0;\n            check(static_cast<long long>(d[x]) == expect, \"CounterReference\
    \ -> mapped_type\");\n        }\n        check(same(d, md), \"operator[] += /\
    \ -= / =\");\n\n        // most_common: \u500B\u6570\u306E\u964D\u9806\u3001\u540C\
    \u6570\u306A\u3089\u5024\u306E\u6607\u9806\n        Model nm = normalize(md);\n\
    \        std::vector<std::pair<int, long long>> expect(nm.begin(), nm.end());\n\
    \        std::stable_sort(expect.begin(), expect.end(), [](const auto& p, const\
    \ auto& q) { return p.second > q.second; });\n        check(d.most_common() ==\
    \ expect, \"most_common\");\n        for (long long k = 0; k <= d.size() + 2;\
    \ ++k) {\n            auto top = expect;\n            if (k < static_cast<long\
    \ long>(top.size())) top.resize(k);\n            check(d.most_common(k) == top,\
    \ \"most_common(k)\");\n        }\n    }\n\n    // \u81EA\u5206\u81EA\u8EAB\u3092\
    \u5F15\u304F\u3068\u7A7A\u306B\u306A\u308B (\u8D70\u67FB\u4E2D\u306E\u8981\u7D20\
    \u3092\u6D88\u3057\u3066\u3082\u58CA\u308C\u306A\u3044)\n    if (ok) {\n     \
    \   Counter<int> c{{1, 2}, {3, 1}, {5, 4}};\n        c -= c;\n        check(same(c,\
    \ {}), \"self operator-=\");\n        check(c.most_common(2).empty(), \"most_common(k)\
    \ of empty\");\n        Counter<int> d{{1, 2}, {3, 1}};\n        d += d;\n   \
    \     check(same(d, {{1, 4}, {3, 2}}), \"self operator+=\");\n    }\n\n    {\n\
    \        Counter<int> c{{1, 2}, {3, 2}, {5, 1}};\n        const auto& frequency\
    \ = c.by_frequency();\n        check(*frequency.lower_bound({2, 2}) == std::make_pair(3,\
    \ 2LL), \"frequency lower_bound\");\n        check(*frequency.upper_bound({3,\
    \ 2}) == std::make_pair(5, 1LL), \"frequency upper_bound\");\n        c[5] +=\
    \ 3;\n        check(&frequency == &c.by_frequency() && *frequency.begin() == std::make_pair(5,\
    \ 4LL), \"frequency reference follows updates\");\n        c[5] = 0;\n       \
    \ check(frequency.size() == 2 && *frequency.rbegin() == std::make_pair(3, 2LL),\
    \ \"frequency reference follows erasure\");\n        c -= c;\n        check(frequency.empty(),\
    \ \"frequency reference follows clearing\");\n    }\n\n    {\n        const Range\
    \ values(0, 10, 2);\n        Counter<long long> inferred(values);\n        check(inferred.size()\
    \ == 5 && inferred.total() == 5 && inferred.get(4) == 1 && inferred.get(3) ==\
    \ 0, \"Range constructor\");\n        Counter<std::string> key(std::string(\"\
    abc\"));\n        Counter<std::string> copy(key);\n        check(copy.get(\"abc\"\
    ) == 1 && copy.total() == 1, \"range-like key and copy constructor\");\n    }\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/counter.hpp
  - src/utility/traits.hpp
  - src/utility/range.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/counter.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 04:55:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/counter.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/counter.test.cpp
- /verify/test/unittest/data_structures/counter.test.cpp.html
title: test/unittest/data_structures/counter.test.cpp
---
