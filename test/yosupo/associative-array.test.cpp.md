---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/counter.hpp
    title: "\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408\
      \ (Counter)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/yosupo/associative-array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n\n#include <iostream>\n\
    \n#line 2 \"src/data_structures/counter.hpp\"\n\n/**\n * @file counter.hpp\n *\
    \ @brief \u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u591A\u91CD\u96C6\u5408\
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
    \ CounterReference(*this, key);\n    }\n};\n#line 6 \"test/yosupo/associative-array.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int q;\n    std::cin >> q;\n    // \u5024 v \u3092\u300C\u30AD\u30FC k \u306E\
    \u500B\u6570\u300D\u3068\u3057\u3066\u6301\u3064 (0 \u306A\u3089\u53D6\u308A\u9664\
    \u304B\u308C\u308B)\n    Counter<long long> a;\n    while (q--) {\n        int\
    \ t;\n        long long k;\n        std::cin >> t >> k;\n        if (t == 0) {\n\
    \            long long v;\n            std::cin >> v;\n            a[k] = v;\n\
    \        } else {\n            std::cout << a[k] << '\\n';\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include <iostream>\n\n#include \"../../src/data_structures/counter.hpp\"\n\n\
    int main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int q;\n    std::cin >> q;\n    // \u5024 v \u3092\u300C\u30AD\u30FC k \u306E\
    \u500B\u6570\u300D\u3068\u3057\u3066\u6301\u3064 (0 \u306A\u3089\u53D6\u308A\u9664\
    \u304B\u308C\u308B)\n    Counter<long long> a;\n    while (q--) {\n        int\
    \ t;\n        long long k;\n        std::cin >> t >> k;\n        if (t == 0) {\n\
    \            long long v;\n            std::cin >> v;\n            a[k] = v;\n\
    \        } else {\n            std::cout << a[k] << '\\n';\n        }\n    }\n\
    }\n"
  dependsOn:
  - src/data_structures/counter.hpp
  isVerificationFile: true
  path: test/yosupo/associative-array.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 00:57:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/associative-array.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/associative-array.test.cpp
- /verify/test/yosupo/associative-array.test.cpp.html
title: test/yosupo/associative-array.test.cpp
---
