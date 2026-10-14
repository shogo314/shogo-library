---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/priority_counter.hpp
    title: "\u4E0A\u4F4D K \u500B\u306E\u5024\u3068\u305D\u306E\u500B\u6570"
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
  bundledCode: "#line 1 \"test/unittest/priority_counter.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ PriorityCounter (MaxCounter / MinCounter) \u3092\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/priority_counter.hpp\"\
    \n\n/**\n * @file priority_counter.hpp\n * @brief \u4E0A\u4F4D K \u500B\u306E\u5024\
    \u3068\u305D\u306E\u500B\u6570\n */\n\n#include <array>\n#include <cstddef>\n\
    #include <functional>\n#include <type_traits>\n#include <utility>\n\ntemplate\
    \ <typename T, std::size_t K = 1, class Compare = std::less<T>, std::enable_if_t<(K\
    \ >= 1), std::nullptr_t> = nullptr>\nstruct PriorityCounter {\n    using key_type\
    \ = T;\n    using mapped_type = long long;\n    using value_type = std::pair<key_type,\
    \ mapped_type>;\n    inline constexpr static std::size_t k = K;\n\n    // C++17\
    \ \u306E constexpr \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u306F\u3059\
    \u3079\u3066\u306E\u30E1\u30F3\u30D0\u306E\u521D\u671F\u5316\u304C\u5FC5\u8981\
    \u306A\u306E\u3067\u3001\u5024\u521D\u671F\u5316\u3057\u3066\u304A\u304F\n   \
    \ std::array<value_type, K> data{};\n\n    constexpr PriorityCounter() {}\n  \
    \  constexpr PriorityCounter(const key_type& x) : PriorityCounter() {\n      \
    \  data[0].first = x;\n        data[0].second = 1;\n    }\n\n    constexpr int\
    \ size() const {\n        for (std::size_t i = 0; i < k; i++) {\n            if\
    \ (data[i].second == 0) {\n                return static_cast<int>(i);\n     \
    \       }\n        }\n        return k;\n    }\n\n    constexpr void inc(const\
    \ key_type& x, const mapped_type& c = 1) {\n        bool f = false;\n        key_type\
    \ pre_key{};\n        mapped_type pre_mapped{};\n        for (std::size_t i =\
    \ 0; i < k; i++) {\n            if (f) {\n                // std::swap \u306F\
    \ C++17 \u3067\u306F constexpr \u3067\u306A\u3044\u306E\u3067\u624B\u3067\u5165\
    \u308C\u66FF\u3048\u308B\n                key_type tmp_key = data[i].first;\n\
    \                data[i].first = pre_key;\n                pre_key = tmp_key;\n\
    \                mapped_type tmp_mapped = data[i].second;\n                data[i].second\
    \ = pre_mapped;\n                pre_mapped = tmp_mapped;\n                continue;\n\
    \            }\n            if (data[i].second == 0) {\n                data[i].first\
    \ = x;\n                data[i].second += c;\n                return;\n      \
    \      }\n            if (Compare()(data[i].first, x)) {\n                pre_key\
    \ = data[i].first;\n                pre_mapped = data[i].second;\n           \
    \     data[i].first = x;\n                data[i].second = c;\n              \
    \  f = true;\n            } else if (!Compare()(x, data[i].first)) {\n       \
    \         data[i].second += c;\n                return;\n            }\n     \
    \   }\n    }\n\n    constexpr PriorityCounter& operator+=(const PriorityCounter&\
    \ o) {\n        for (std::size_t i = 0; i < k; i++) {\n            if (o.data[i].second\
    \ == 0) break;\n            this->inc(o.data[i].first, o.data[i].second);\n  \
    \      }\n        return *this;\n    }\n    constexpr friend PriorityCounter operator+(const\
    \ PriorityCounter& a, const PriorityCounter& b) {\n        PriorityCounter res(a);\n\
    \        return res += b;\n    }\n};\n\ntemplate <typename T, std::size_t K =\
    \ 1>\nusing MaxCounter = PriorityCounter<T, K>;\n\ntemplate <typename T, std::size_t\
    \ K = 1>\nusing MinCounter = PriorityCounter<T, K, std::greater<T>>;\n#line 7\
    \ \"test/unittest/priority_counter.test.cpp\"\n\n#include <algorithm>\n#line 10\
    \ \"test/unittest/priority_counter.test.cpp\"\n#include <iostream>\n#include <map>\n\
    #include <random>\n#include <vector>\n\n// \u5168\u4F53\u306E\u500B\u6570\u304B\
    \u3089\u3001Compare \u3067\u5927\u304D\u3044\u65B9\u304B\u3089 K \u500B\u306E\u5024\
    \u3068\u305D\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\ntemplate <size_t K, class\
    \ Compare>\nstd::vector<std::pair<int, long long>> top_k(const std::map<int, long\
    \ long>& m) {\n    std::vector<std::pair<int, long long>> v(m.begin(), m.end());\n\
    \    std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return Compare()(b.first,\
    \ a.first); });\n    if (v.size() > K) v.resize(K);\n    return v;\n}\n\ntemplate\
    \ <size_t K, class Compare>\nbool same(const PriorityCounter<int, K, Compare>&\
    \ pc, const std::map<int, long long>& m) {\n    auto expect = top_k<K, Compare>(m);\n\
    \    if (pc.size() != (int)expect.size()) return false;\n    for (size_t i = 0;\
    \ i < expect.size(); i++) {\n        if (pc.data[i] != expect[i]) return false;\n\
    \    }\n    // \u4F7F\u308F\u308C\u3066\u3044\u306A\u3044\u5834\u6240\u306E\u500B\
    \u6570\u306F 0\n    for (size_t i = expect.size(); i < K; i++) {\n        if (pc.data[i].second\
    \ != 0) return false;\n    }\n    return true;\n}\n\ntemplate <size_t K, class\
    \ Compare>\nbool run(std::mt19937& rng) {\n    using PC = PriorityCounter<int,\
    \ K, Compare>;\n    {\n        PC empty;\n        if (!same<K, Compare>(empty,\
    \ {})) return false;\n        PC one(7);\n        if (!same<K, Compare>(one, {{7,\
    \ 1}})) return false;\n    }\n    for (int rep = 0; rep < 2000; rep++) {\n   \
    \     PC a, b;\n        std::map<int, long long> ma, mb;\n        int q = rng()\
    \ % 12;\n        for (int t = 0; t < q; t++) {\n            int x = rng() % 8;\n\
    \            long long c = rng() % 3 + 1;\n            if (rng() % 2) {\n    \
    \            a.inc(x, c);\n                ma[x] += c;\n            } else {\n\
    \                // \u500B\u6570\u3092\u7701\u7565\u3059\u308B\u3068 1\n     \
    \           a.inc(x);\n                ma[x] += 1;\n            }\n          \
    \  if (!same<K, Compare>(a, ma)) return false;\n            int y = rng() % 8;\n\
    \            b.inc(y, 2);\n            mb[y] += 2;\n        }\n        std::map<int,\
    \ long long> sum = ma;\n        for (auto [x, c] : mb) sum[x] += c;\n        if\
    \ (!same<K, Compare>(a + b, sum)) return false;\n        a += b;\n        if (!same<K,\
    \ Compare>(a, sum)) return false;\n    }\n    return true;\n}\n\n// constexpr\
    \ \u3067\u4F7F\u3048\u308B\u3053\u3068 (C++17 \u306E\u5B9A\u6570\u5F0F\u3067 inc\u30FB\
    +\u30FBsize \u3092\u8A55\u4FA1\u3059\u308B)\nconstexpr bool constexpr_check()\
    \ {\n    MaxCounter<int, 2> a;\n    a.inc(5);\n    a.inc(1);\n    a.inc(9);  //\
    \ \u4E0A\u4F4D 2 \u500B {9, 5} \u304C\u6B8B\u308A\u30011 \u306F\u62BC\u3057\u51FA\
    \u3055\u308C\u308B\n    a.inc(5, 2);\n    MaxCounter<int, 2> b(7);\n    MaxCounter<int,\
    \ 2> c = a + b;  // {9, 7}\n    return a.size() == 2 && a.data[0] == std::pair<int,\
    \ long long>(9, 1) && a.data[1] == std::pair<int, long long>(5, 3) &&\n      \
    \     c.data[0] == std::pair<int, long long>(9, 1) && c.data[1] == std::pair<int,\
    \ long long>(7, 1) &&\n           MinCounter<int, 3>().size() == 0;\n}\nstatic_assert(constexpr_check());\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    ok = ok &&\
    \ run<1, std::less<int>>(rng);\n    ok = ok && run<2, std::less<int>>(rng);\n\
    \    ok = ok && run<3, std::less<int>>(rng);\n    ok = ok && run<5, std::less<int>>(rng);\n\
    \    ok = ok && run<1, std::greater<int>>(rng);\n    ok = ok && run<3, std::greater<int>>(rng);\n\
    \n    // \u5225\u540D: MaxCounter \u306F\u5927\u304D\u3044\u65B9\u3001MinCounter\
    \ \u306F\u5C0F\u3055\u3044\u65B9\u3092\u6B8B\u3059\n    MaxCounter<int, 2> mx;\n\
    \    MinCounter<int, 2> mn;\n    for (int x : {5, 1, 9, 5, 3}) {\n        mx.inc(x);\n\
    \        mn.inc(x);\n    }\n    ok = ok && mx.size() == 2 && mx.data[0] == std::make_pair(9,\
    \ 1LL) && mx.data[1] == std::make_pair(5, 2LL);\n    ok = ok && mn.size() == 2\
    \ && mn.data[0] == std::make_pair(1, 1LL) && mn.data[1] == std::make_pair(3, 1LL);\n\
    \n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n    else\n\
    \        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// PriorityCounter (MaxCounter / MinCounter) \u3092\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/priority_counter.hpp\"\
    \n\n#include <algorithm>\n#include <functional>\n#include <iostream>\n#include\
    \ <map>\n#include <random>\n#include <vector>\n\n// \u5168\u4F53\u306E\u500B\u6570\
    \u304B\u3089\u3001Compare \u3067\u5927\u304D\u3044\u65B9\u304B\u3089 K \u500B\u306E\
    \u5024\u3068\u305D\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\ntemplate <size_t\
    \ K, class Compare>\nstd::vector<std::pair<int, long long>> top_k(const std::map<int,\
    \ long long>& m) {\n    std::vector<std::pair<int, long long>> v(m.begin(), m.end());\n\
    \    std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return Compare()(b.first,\
    \ a.first); });\n    if (v.size() > K) v.resize(K);\n    return v;\n}\n\ntemplate\
    \ <size_t K, class Compare>\nbool same(const PriorityCounter<int, K, Compare>&\
    \ pc, const std::map<int, long long>& m) {\n    auto expect = top_k<K, Compare>(m);\n\
    \    if (pc.size() != (int)expect.size()) return false;\n    for (size_t i = 0;\
    \ i < expect.size(); i++) {\n        if (pc.data[i] != expect[i]) return false;\n\
    \    }\n    // \u4F7F\u308F\u308C\u3066\u3044\u306A\u3044\u5834\u6240\u306E\u500B\
    \u6570\u306F 0\n    for (size_t i = expect.size(); i < K; i++) {\n        if (pc.data[i].second\
    \ != 0) return false;\n    }\n    return true;\n}\n\ntemplate <size_t K, class\
    \ Compare>\nbool run(std::mt19937& rng) {\n    using PC = PriorityCounter<int,\
    \ K, Compare>;\n    {\n        PC empty;\n        if (!same<K, Compare>(empty,\
    \ {})) return false;\n        PC one(7);\n        if (!same<K, Compare>(one, {{7,\
    \ 1}})) return false;\n    }\n    for (int rep = 0; rep < 2000; rep++) {\n   \
    \     PC a, b;\n        std::map<int, long long> ma, mb;\n        int q = rng()\
    \ % 12;\n        for (int t = 0; t < q; t++) {\n            int x = rng() % 8;\n\
    \            long long c = rng() % 3 + 1;\n            if (rng() % 2) {\n    \
    \            a.inc(x, c);\n                ma[x] += c;\n            } else {\n\
    \                // \u500B\u6570\u3092\u7701\u7565\u3059\u308B\u3068 1\n     \
    \           a.inc(x);\n                ma[x] += 1;\n            }\n          \
    \  if (!same<K, Compare>(a, ma)) return false;\n            int y = rng() % 8;\n\
    \            b.inc(y, 2);\n            mb[y] += 2;\n        }\n        std::map<int,\
    \ long long> sum = ma;\n        for (auto [x, c] : mb) sum[x] += c;\n        if\
    \ (!same<K, Compare>(a + b, sum)) return false;\n        a += b;\n        if (!same<K,\
    \ Compare>(a, sum)) return false;\n    }\n    return true;\n}\n\n// constexpr\
    \ \u3067\u4F7F\u3048\u308B\u3053\u3068 (C++17 \u306E\u5B9A\u6570\u5F0F\u3067 inc\u30FB\
    +\u30FBsize \u3092\u8A55\u4FA1\u3059\u308B)\nconstexpr bool constexpr_check()\
    \ {\n    MaxCounter<int, 2> a;\n    a.inc(5);\n    a.inc(1);\n    a.inc(9);  //\
    \ \u4E0A\u4F4D 2 \u500B {9, 5} \u304C\u6B8B\u308A\u30011 \u306F\u62BC\u3057\u51FA\
    \u3055\u308C\u308B\n    a.inc(5, 2);\n    MaxCounter<int, 2> b(7);\n    MaxCounter<int,\
    \ 2> c = a + b;  // {9, 7}\n    return a.size() == 2 && a.data[0] == std::pair<int,\
    \ long long>(9, 1) && a.data[1] == std::pair<int, long long>(5, 3) &&\n      \
    \     c.data[0] == std::pair<int, long long>(9, 1) && c.data[1] == std::pair<int,\
    \ long long>(7, 1) &&\n           MinCounter<int, 3>().size() == 0;\n}\nstatic_assert(constexpr_check());\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    ok = ok &&\
    \ run<1, std::less<int>>(rng);\n    ok = ok && run<2, std::less<int>>(rng);\n\
    \    ok = ok && run<3, std::less<int>>(rng);\n    ok = ok && run<5, std::less<int>>(rng);\n\
    \    ok = ok && run<1, std::greater<int>>(rng);\n    ok = ok && run<3, std::greater<int>>(rng);\n\
    \n    // \u5225\u540D: MaxCounter \u306F\u5927\u304D\u3044\u65B9\u3001MinCounter\
    \ \u306F\u5C0F\u3055\u3044\u65B9\u3092\u6B8B\u3059\n    MaxCounter<int, 2> mx;\n\
    \    MinCounter<int, 2> mn;\n    for (int x : {5, 1, 9, 5, 3}) {\n        mx.inc(x);\n\
    \        mn.inc(x);\n    }\n    ok = ok && mx.size() == 2 && mx.data[0] == std::make_pair(9,\
    \ 1LL) && mx.data[1] == std::make_pair(5, 2LL);\n    ok = ok && mn.size() == 2\
    \ && mn.data[0] == std::make_pair(1, 1LL) && mn.data[1] == std::make_pair(3, 1LL);\n\
    \n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n    else\n\
    \        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/priority_counter.hpp
  isVerificationFile: true
  path: test/unittest/priority_counter.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/priority_counter.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/priority_counter.test.cpp
- /verify/test/unittest/priority_counter.test.cpp.html
title: test/unittest/priority_counter.test.cpp
---
