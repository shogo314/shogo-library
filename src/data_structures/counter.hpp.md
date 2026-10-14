---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0029.test.cpp
    title: test/aoj/0029.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2-7-d.test.cpp
    title: test/aoj/itp2-7-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/counter.test.cpp
    title: test/unittest/counter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/associative-array.test.cpp
    title: test/yosupo/associative-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\
      \u5408 (Counter)"
    links: []
  bundledCode: "#line 2 \"src/data_structures/counter.hpp\"\n\n/**\n * @file counter.hpp\n\
    \ * @brief \u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408\
    \ (Counter)\n */\n\n#include <algorithm>\n#include <cassert>\n#include <cstddef>\n\
    #include <initializer_list>\n#include <iterator>\n#include <map>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"src/utility/traits.hpp\"\n\n\
    /**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 10 \"src/utility/traits.hpp\"\
    \n#include <set>\n#line 13 \"src/utility/traits.hpp\"\n\nnamespace internal_traits\
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
    #line 19 \"src/data_structures/counter.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Counter {\n    using key_type = T;\n    using mapped_type = long long;\n   \
    \ using value_type = std::pair<key_type, mapped_type>;\n    std::map<key_type,\
    \ mapped_type> data;\n\n    void inc(const key_type& key, const mapped_type& t)\
    \ {\n        data[key] += t;\n        auto itr = data.find(key);\n        assert(itr->second\
    \ >= 0);\n        if (itr->second == 0) {\n            data.erase(itr);\n    \
    \    }\n    }\n    Counter() = default;\n    explicit Counter(const key_type&\
    \ x) : data{{x, 1}} {}\n    /**\n     * @brief \u7BC4\u56F2\u306E\u8981\u7D20\u3092\
    \u6570\u3048\u308B\n     * Counter \u81EA\u8EAB\u3068 key_type (std::string \u306A\
    \u3069\u7BC4\u56F2\u3067\u3082\u3042\u308B\u3082\u306E) \u306F\u3053\u3061\u3089\
    \u3067\u53D7\u3051\u53D6\u3089\u306A\u3044\n     */\n    template <class C, ENABLE_IF_T(!std::is_same_v<std::decay_t<C>,\
    \ Counter> && !std::is_convertible_v<C, key_type>),\n              class = decltype(std::begin(std::declval<C&>()),\
    \ std::end(std::declval<C&>()))>\n    explicit Counter(C&& v) {\n        for (const\
    \ key_type& a : v) {\n            data[a]++;\n        }\n    }\n    Counter(std::initializer_list<value_type>\
    \ init) {\n        for (const auto& p : init) {\n            inc(p.first, p.second);\n\
    \        }\n    }\n    Counter& operator+=(const Counter& o) {\n        for (const\
    \ auto& [i, c] : o.data) {\n            data[i] += c;\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator+(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res += b;\n    }\n    Counter&\
    \ operator-=(const Counter& o) {\n        // \u81EA\u5206\u81EA\u8EAB\u3092\u5F15\
    \u304F\u3068\u3001\u8D70\u67FB\u4E2D\u306E o.data \u306E\u8981\u7D20\u3092 inc\
    \ \u304C\u6D88\u3057\u3066\u3057\u307E\u3046\n        if (this == &o) {\n    \
    \        data.clear();\n            return *this;\n        }\n        for (const\
    \ auto& [i, c] : o.data) {\n            inc(i, -c);\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator-(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res -= b;\n    }\n    auto begin()\
    \ const { return data.begin(); }\n    auto end() const { return data.end(); }\n\
    \    /**\n     * @brief \u7570\u306A\u308B\u5024\u306E\u500B\u6570 (\u91CD\u8907\
    \u306F\u6570\u3048\u306A\u3044)\n     */\n    long long size() const {\n     \
    \   return static_cast<long long>(data.size());\n    }\n    /**\n     * @brief\
    \ \u91CD\u8907\u3092\u542B\u3081\u305F\u8981\u7D20\u6570 (\u500B\u6570\u306E\u7DCF\
    \u548C)\n     * @note Python \u306E collections.Counter.total() \u3068\u540C\u3058\
    \u3002O(\u7570\u306A\u308B\u5024\u306E\u500B\u6570)\n     */\n    mapped_type\
    \ total() const {\n        mapped_type ret = 0;\n        for (const auto& [key,\
    \ cnt] : data) ret += cnt;\n        return ret;\n    }\n    mapped_type get(const\
    \ key_type& key) const {\n        auto itr = data.find(key);\n        if (itr\
    \ == data.end()) return 0;\n        return itr->second;\n    }\n    void set(const\
    \ key_type& key, const mapped_type& t) {\n        assert(t >= 0);\n        if\
    \ (t > 0) {\n            data[key] = t;\n        } else {\n            auto itr\
    \ = data.find(key);\n            if (itr != data.end()) {\n                data.erase(itr);\n\
    \            }\n        }\n    }\n    std::vector<value_type> most_common() const\
    \ {\n        std::vector<value_type> ret;\n        ret.reserve(data.size());\n\
    \        for (const auto& [i, c] : data) {\n            ret.push_back({i, c});\n\
    \        }\n        std::sort(ret.begin(), ret.end(), [](const value_type& a,\
    \ const value_type& b) { return a.second > b.second || (a.second == b.second &&\
    \ a.first < b.first); });\n        return ret;\n    }\n    class CounterReference\
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
    \ CounterReference(*this, key);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file counter.hpp\n * @brief \u5024\u306E\u500B\u6570\
    \u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408 (Counter)\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cstddef>\n#include <initializer_list>\n#include\
    \ <iterator>\n#include <map>\n#include <type_traits>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"../utility/traits.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Counter {\n    using key_type = T;\n    using mapped_type = long long;\n   \
    \ using value_type = std::pair<key_type, mapped_type>;\n    std::map<key_type,\
    \ mapped_type> data;\n\n    void inc(const key_type& key, const mapped_type& t)\
    \ {\n        data[key] += t;\n        auto itr = data.find(key);\n        assert(itr->second\
    \ >= 0);\n        if (itr->second == 0) {\n            data.erase(itr);\n    \
    \    }\n    }\n    Counter() = default;\n    explicit Counter(const key_type&\
    \ x) : data{{x, 1}} {}\n    /**\n     * @brief \u7BC4\u56F2\u306E\u8981\u7D20\u3092\
    \u6570\u3048\u308B\n     * Counter \u81EA\u8EAB\u3068 key_type (std::string \u306A\
    \u3069\u7BC4\u56F2\u3067\u3082\u3042\u308B\u3082\u306E) \u306F\u3053\u3061\u3089\
    \u3067\u53D7\u3051\u53D6\u3089\u306A\u3044\n     */\n    template <class C, ENABLE_IF_T(!std::is_same_v<std::decay_t<C>,\
    \ Counter> && !std::is_convertible_v<C, key_type>),\n              class = decltype(std::begin(std::declval<C&>()),\
    \ std::end(std::declval<C&>()))>\n    explicit Counter(C&& v) {\n        for (const\
    \ key_type& a : v) {\n            data[a]++;\n        }\n    }\n    Counter(std::initializer_list<value_type>\
    \ init) {\n        for (const auto& p : init) {\n            inc(p.first, p.second);\n\
    \        }\n    }\n    Counter& operator+=(const Counter& o) {\n        for (const\
    \ auto& [i, c] : o.data) {\n            data[i] += c;\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator+(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res += b;\n    }\n    Counter&\
    \ operator-=(const Counter& o) {\n        // \u81EA\u5206\u81EA\u8EAB\u3092\u5F15\
    \u304F\u3068\u3001\u8D70\u67FB\u4E2D\u306E o.data \u306E\u8981\u7D20\u3092 inc\
    \ \u304C\u6D88\u3057\u3066\u3057\u307E\u3046\n        if (this == &o) {\n    \
    \        data.clear();\n            return *this;\n        }\n        for (const\
    \ auto& [i, c] : o.data) {\n            inc(i, -c);\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator-(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res -= b;\n    }\n    auto begin()\
    \ const { return data.begin(); }\n    auto end() const { return data.end(); }\n\
    \    /**\n     * @brief \u7570\u306A\u308B\u5024\u306E\u500B\u6570 (\u91CD\u8907\
    \u306F\u6570\u3048\u306A\u3044)\n     */\n    long long size() const {\n     \
    \   return static_cast<long long>(data.size());\n    }\n    /**\n     * @brief\
    \ \u91CD\u8907\u3092\u542B\u3081\u305F\u8981\u7D20\u6570 (\u500B\u6570\u306E\u7DCF\
    \u548C)\n     * @note Python \u306E collections.Counter.total() \u3068\u540C\u3058\
    \u3002O(\u7570\u306A\u308B\u5024\u306E\u500B\u6570)\n     */\n    mapped_type\
    \ total() const {\n        mapped_type ret = 0;\n        for (const auto& [key,\
    \ cnt] : data) ret += cnt;\n        return ret;\n    }\n    mapped_type get(const\
    \ key_type& key) const {\n        auto itr = data.find(key);\n        if (itr\
    \ == data.end()) return 0;\n        return itr->second;\n    }\n    void set(const\
    \ key_type& key, const mapped_type& t) {\n        assert(t >= 0);\n        if\
    \ (t > 0) {\n            data[key] = t;\n        } else {\n            auto itr\
    \ = data.find(key);\n            if (itr != data.end()) {\n                data.erase(itr);\n\
    \            }\n        }\n    }\n    std::vector<value_type> most_common() const\
    \ {\n        std::vector<value_type> ret;\n        ret.reserve(data.size());\n\
    \        for (const auto& [i, c] : data) {\n            ret.push_back({i, c});\n\
    \        }\n        std::sort(ret.begin(), ret.end(), [](const value_type& a,\
    \ const value_type& b) { return a.second > b.second || (a.second == b.second &&\
    \ a.first < b.first); });\n        return ret;\n    }\n    class CounterReference\
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
    \ CounterReference(*this, key);\n    }\n};\n"
  dependsOn:
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/data_structures/counter.hpp
  requiredBy: []
  timestamp: '2026-10-15 07:35:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/counter.test.cpp
  - test/aoj/itp2-7-d.test.cpp
  - test/aoj/0029.test.cpp
  - test/yosupo/associative-array.test.cpp
documentation_of: src/data_structures/counter.hpp
layout: document
title: "\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408 (Counter)"
---

値ごとの個数を `std::map` で管理する多重集合 `Counter<T>` です (Python の `collections.Counter`)。個数が 0 になった値は自動で取り除かれます。

```cpp
std::vector<int> v = {3, 1, 3, 2, 3};
Counter<int> c(v);
c[1] += 2;                        // 1 を 2 個追加
long long k = c[3];               // 3
auto top = c.most_common();       // 個数の多い順
for (auto [x, cnt] : c) { }       // 値の昇順に走査
Counter<int> d = c + Counter<int>(3);  // 3 を 1 個足した Counter
```

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
| `c.size()` | 異なる値の個数 (重複は数えない) | $O(1)$ |
| `c.total()` | 重複を含めた要素数 (個数の総和。Python の `Counter.total()` と同じ) | $O(n)$ |
| `c.most_common()` | `{値, 個数}` のリスト。個数の降順、同数なら値の昇順 | $O(n \log n)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `data` | 中身の `std::map<T, long long>` (値の昇順に走査できる) |

## 関連

- 最大・最小と任意の要素の削除だけなら [削除可能な優先度付きキュー](erasable-priority-queue.hpp)
