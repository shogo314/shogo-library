---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\
      \u5408 (Counter)"
    links: []
  bundledCode: "#line 2 \"src/data_structures/counter.hpp\"\n\n/**\n * @file counter.hpp\n\
    \ * @brief \u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408\
    \ (Counter)\n */\n\n#include <algorithm>\n#include <cassert>\n#include <cstddef>\n\
    #include <initializer_list>\n#include <iterator>\n#include <map>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename T>\nstruct Counter\
    \ {\n    using key_type = T;\n    using mapped_type = long long;\n    using value_type\
    \ = std::pair<key_type, mapped_type>;\n    std::map<key_type, mapped_type> data;\n\
    \n    void inc(const key_type& key, const mapped_type& t) {\n        data[key]\
    \ += t;\n        auto itr = data.find(key);\n        assert(itr->second >= 0);\n\
    \        if (itr->second == 0) {\n            data.erase(itr);\n        }\n  \
    \  }\n    Counter() = default;\n    explicit Counter(const key_type& x) : data{{x,\
    \ 1}} {}\n    /**\n     * @brief \u7BC4\u56F2\u306E\u8981\u7D20\u3092\u6570\u3048\
    \u308B\n     * Counter \u81EA\u8EAB\u3068 key_type (std::string \u306A\u3069\u7BC4\
    \u56F2\u3067\u3082\u3042\u308B\u3082\u306E) \u306F\u3053\u3061\u3089\u3067\u53D7\
    \u3051\u53D6\u3089\u306A\u3044\n     */\n    template <class C, std::enable_if_t<!std::is_same_v<std::decay_t<C>,\
    \ Counter> && !std::is_convertible_v<C, key_type>, std::nullptr_t> = nullptr,\n\
    \              class = decltype(std::begin(std::declval<C&>()), std::end(std::declval<C&>()))>\n\
    \    explicit Counter(C&& v) {\n        for (const key_type& a : v) {\n      \
    \      data[a]++;\n        }\n    }\n    Counter(std::initializer_list<value_type>\
    \ init) {\n        for (const auto& p : init) {\n            inc(p.first, p.second);\n\
    \        }\n    }\n    Counter& operator+=(const Counter& o) {\n        for (const\
    \ auto& [i, c] : o.data) {\n            data[i] += c;\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator+(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res += b;\n    }\n    Counter&\
    \ operator-=(const Counter& o) {\n        for (const auto& [i, c] : o.data) {\n\
    \            inc(i, -c);\n        }\n        return *this;\n    }\n    friend\
    \ Counter operator-(const Counter& a, const Counter& b) {\n        Counter res(a);\n\
    \        return res -= b;\n    }\n    auto begin() const { return data.begin();\
    \ }\n    auto end() const { return data.end(); }\n    std::size_t size() const\
    \ {\n        return data.size();\n    }\n    mapped_type get(const key_type& key)\
    \ const {\n        auto itr = data.find(key);\n        if (itr == data.end())\
    \ return 0;\n        return itr->second;\n    }\n    void set(const key_type&\
    \ key, const mapped_type& t) {\n        assert(t >= 0);\n        if (t > 0) {\n\
    \            data[key] = t;\n        } else {\n            auto itr = data.find(key);\n\
    \            if (itr != data.end()) {\n                data.erase(itr);\n    \
    \        }\n        }\n    }\n    std::vector<value_type> most_common() const\
    \ {\n        std::vector<value_type> ret;\n        ret.reserve(data.size());\n\
    \        for (const auto& [i, c] : data) {\n            ret.push_back({i, c});\n\
    \        }\n        std::sort(ret.begin(), ret.end(), [](const value_type& a,\
    \ const value_type& b) { return a.second > b.second or (a.second == b.second and\
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
    \ <vector>\n\ntemplate <typename T>\nstruct Counter {\n    using key_type = T;\n\
    \    using mapped_type = long long;\n    using value_type = std::pair<key_type,\
    \ mapped_type>;\n    std::map<key_type, mapped_type> data;\n\n    void inc(const\
    \ key_type& key, const mapped_type& t) {\n        data[key] += t;\n        auto\
    \ itr = data.find(key);\n        assert(itr->second >= 0);\n        if (itr->second\
    \ == 0) {\n            data.erase(itr);\n        }\n    }\n    Counter() = default;\n\
    \    explicit Counter(const key_type& x) : data{{x, 1}} {}\n    /**\n     * @brief\
    \ \u7BC4\u56F2\u306E\u8981\u7D20\u3092\u6570\u3048\u308B\n     * Counter \u81EA\
    \u8EAB\u3068 key_type (std::string \u306A\u3069\u7BC4\u56F2\u3067\u3082\u3042\u308B\
    \u3082\u306E) \u306F\u3053\u3061\u3089\u3067\u53D7\u3051\u53D6\u3089\u306A\u3044\
    \n     */\n    template <class C, std::enable_if_t<!std::is_same_v<std::decay_t<C>,\
    \ Counter> && !std::is_convertible_v<C, key_type>, std::nullptr_t> = nullptr,\n\
    \              class = decltype(std::begin(std::declval<C&>()), std::end(std::declval<C&>()))>\n\
    \    explicit Counter(C&& v) {\n        for (const key_type& a : v) {\n      \
    \      data[a]++;\n        }\n    }\n    Counter(std::initializer_list<value_type>\
    \ init) {\n        for (const auto& p : init) {\n            inc(p.first, p.second);\n\
    \        }\n    }\n    Counter& operator+=(const Counter& o) {\n        for (const\
    \ auto& [i, c] : o.data) {\n            data[i] += c;\n        }\n        return\
    \ *this;\n    }\n    friend Counter operator+(const Counter& a, const Counter&\
    \ b) {\n        Counter res(a);\n        return res += b;\n    }\n    Counter&\
    \ operator-=(const Counter& o) {\n        for (const auto& [i, c] : o.data) {\n\
    \            inc(i, -c);\n        }\n        return *this;\n    }\n    friend\
    \ Counter operator-(const Counter& a, const Counter& b) {\n        Counter res(a);\n\
    \        return res -= b;\n    }\n    auto begin() const { return data.begin();\
    \ }\n    auto end() const { return data.end(); }\n    std::size_t size() const\
    \ {\n        return data.size();\n    }\n    mapped_type get(const key_type& key)\
    \ const {\n        auto itr = data.find(key);\n        if (itr == data.end())\
    \ return 0;\n        return itr->second;\n    }\n    void set(const key_type&\
    \ key, const mapped_type& t) {\n        assert(t >= 0);\n        if (t > 0) {\n\
    \            data[key] = t;\n        } else {\n            auto itr = data.find(key);\n\
    \            if (itr != data.end()) {\n                data.erase(itr);\n    \
    \        }\n        }\n    }\n    std::vector<value_type> most_common() const\
    \ {\n        std::vector<value_type> ret;\n        ret.reserve(data.size());\n\
    \        for (const auto& [i, c] : data) {\n            ret.push_back({i, c});\n\
    \        }\n        std::sort(ret.begin(), ret.end(), [](const value_type& a,\
    \ const value_type& b) { return a.second > b.second or (a.second == b.second and\
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
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/counter.hpp
  requiredBy: []
  timestamp: '2026-10-12 20:22:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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

## メンバ

`n` は異なる値の個数です。

| メンバ | 説明 | 計算量 |
|---|---|---|
| `Counter<T> c` | 空の Counter | $O(1)$ |
| `Counter<T> c(x)` | 値 `x` が 1 個 | $O(1)$ |
| `Counter<T> c{ {x, k}, ... }` | 値 `x` が `k` 個、… で初期化 | |
| `Counter<T> c(v)` | コンテナ `v` の要素を数える | $O(\lvert v \rvert \log n)$ |
| `c[x]` / `c.get(x)` | `x` の個数 (なければ 0) | $O(\log n)$ |
| `c[x] = k` / `c.set(x, k)` | `x` の個数を `k` にする (`k >= 0`) | $O(\log n)$ |
| `c[x] += k`、`c[x] -= k` / `c.inc(x, k)` | `x` の個数を増減する (負になると assert で落ちる) | $O(\log n)$ |
| `c + d`、`c += d` | 個数を足し合わせる | $O(m \log (n + m))$ ($m$ は `d` の異なる値の個数) |
| `c - d`、`c -= d` | 個数を引く (負になると assert で落ちる) | $O(m \log n)$ |
| `for (auto [x, cnt] : c)` | `{値, 個数}` を値の昇順に走査 | $O(n)$ |
| `c.size()` | 異なる値の個数 | $O(1)$ |
| `c.most_common()` | `{値, 個数}` のリスト。個数の降順、同数なら値の昇順 | $O(n \log n)$ |
| `c.data` | 中身の `std::map<T, long long>` (値の昇順に走査できる) | |
