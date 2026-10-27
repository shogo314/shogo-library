---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/mex-update.hpp
    title: "1\u70B9\u66F4\u65B0\u30FB\u5168\u4F53\u306E mex \u53D6\u5F97"
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
  bundledCode: "#line 1 \"test/unittest/data_structures/mex-update.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// MexUpdate \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/mex-update.hpp\"\n\n\
    /**\n * @file mex-update.hpp\n * @brief 1\u70B9\u66F4\u65B0\u30FB\u5168\u4F53\u306E\
    \ mex \u53D6\u5F97\n */\n\n#include <cassert>\n#include <limits>\n#include <map>\n\
    #include <set>\n#include <type_traits>\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass MexUpdate {\n    static_assert(std::is_integral_v<T>, \"MexUpdate:\
    \ T must be an integer type\");\n\n   public:\n    using value_type = T;\n\n \
    \  private:\n    inline constexpr static value_type e = std::numeric_limits<value_type>::max();\n\
    \n    long long n;\n    std::vector<value_type> v;\n    std::set<int> s;\n   \
    \ std::map<int, int> m;\n\n    // x \u304C 0 \u4EE5\u4E0A n \u4EE5\u4E0B\u304B\
    \ (T \u304C\u7B26\u53F7\u306A\u3057\u3067\u3082\u8B66\u544A\u304C\u51FA\u306A\u3044\
    \u3088\u3046\u306B\u6BD4\u3079\u308B)\n    bool in_range(const value_type& x)\
    \ const {\n        if constexpr (std::is_signed_v<value_type>) {\n           \
    \ if (x < 0) return false;\n        }\n        return static_cast<unsigned long\
    \ long>(x) <= static_cast<unsigned long long>(n);\n    }\n\n   public:\n    /**\n\
    \     * @brief \u9577\u3055 0 (mex \u306F 0)\n     */\n    MexUpdate() : MexUpdate(0)\
    \ {}\n    /**\n     * @brief \u9577\u3055 n \u3067\u3001\u3069\u306E\u8981\u7D20\
    \u3082\u307E\u3060\u5024\u3092\u6301\u305F\u306A\u3044 (mex \u306F 0)\u3002n =\
    \ 0 \u3067\u3082\u3088\u3044\n     */\n    explicit MexUpdate(long long n) : n(n),\
    \ v(n, e) {\n        assert(n >= 0);\n        assert(static_cast<unsigned long\
    \ long>(n) + 1 < static_cast<unsigned long long>(e));\n        std::set<int>::iterator\
    \ hint = s.end();\n        for (long long i = n; i >= 0; --i) {\n            hint\
    \ = s.emplace_hint(hint, static_cast<int>(i));\n        }\n    }\n    explicit\
    \ MexUpdate(const std::vector<value_type>& init) : n(init.size()), v(init) {\n\
    \        assert(static_cast<unsigned long long>(n) + 1 < static_cast<unsigned\
    \ long long>(e));\n        std::set<int>::iterator hint = s.end();\n        for\
    \ (long long i = n; i >= 0; --i) {\n            hint = s.emplace_hint(hint, static_cast<int>(i));\n\
    \        }\n        for (const auto& i : init) {\n            if (in_range(i))\
    \ {\n                m[i]++;\n                s.erase(i);\n            }\n   \
    \     }\n    }\n    void set(long long k, const value_type& x) {\n        assert(0\
    \ <= k && k < n);\n        if (in_range(v[k])) {\n            int v_k = v[k];\n\
    \            auto itr = m.find(v_k);\n            if (itr->second > 1) {\n   \
    \             itr->second--;\n            } else {\n                m.erase(itr);\n\
    \                s.insert(v_k);\n            }\n        }\n        if (in_range(x))\
    \ {\n            int xx = x;\n            auto itr = m.find(xx);\n           \
    \ if (itr == m.end()) {\n                m[xx]++;\n                s.erase(xx);\n\
    \            } else {\n                itr->second++;\n            }\n       \
    \ }\n        v[k] = x;\n    }\n    value_type mex() const {\n        return *s.begin();\n\
    \    }\n};\n#line 7 \"test/unittest/data_structures/mex-update.test.cpp\"\n\n\
    #include <iostream>\n#include <random>\n#line 12 \"test/unittest/data_structures/mex-update.test.cpp\"\
    \n\n// v \u306B\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u975E\u8CA0\u6574\
    \u6570\ntemplate <typename T>\nT naive_mex(const std::vector<T>& v) {\n    std::set<T>\
    \ s(v.begin(), v.end());\n    T x = 0;\n    while (s.count(x)) x++;\n    return\
    \ x;\n}\n\ntemplate <typename T>\nbool run(std::mt19937& rng) {\n    for (int\
    \ rep = 0; rep < 2000; rep++) {\n        int n = rng() % 8 + 1;\n        // \u7BC4\
    \u56F2\u5916\u306E\u5024 (\u8CA0\u306E\u5024\u3084 n \u3088\u308A\u5927\u304D\u3044\
    \u5024) \u3082\u6DF7\u305C\u308B\n        auto random_value = [&]() -> T { return\
    \ static_cast<T>(static_cast<int>(rng() % (n + 6)) - 3); };\n        std::vector<T>\
    \ v;\n        MexUpdate<T> mu;\n        if (rep % 2 == 0) {\n            // MexUpdate(n):\
    \ \u5024\u306F\u3069\u308C\u3082 mex \u306B\u5F71\u97FF\u3057\u306A\u3044\u5024\
    \u3067\u521D\u671F\u5316\u3055\u308C\u308B\n            mu = MexUpdate<T>(n);\n\
    \            v.assign(n, static_cast<T>(-1));\n            if (mu.mex() != 0)\
    \ return false;\n        } else {\n            v.resize(n);\n            for (auto&\
    \ x : v) x = random_value();\n            mu = MexUpdate<T>(v);\n        }\n \
    \       if (mu.mex() != naive_mex(v)) return false;\n        for (int t = 0; t\
    \ < 20; t++) {\n            int k = rng() % n;\n            T x = random_value();\n\
    \            mu.set(k, x);\n            v[k] = x;\n            if (mu.mex() !=\
    \ naive_mex(v)) return false;\n        }\n    }\n    return true;\n}\n\nint main()\
    \ {\n    std::mt19937 rng(314);\n    // \u7B26\u53F7\u306A\u3057\u306E\u578B\u3067\
    \u306F\u3001\u8CA0\u306E\u5024\u306F\u5927\u304D\u306A\u5024\u306B\u306A\u308B\
    \ (\u7BC4\u56F2\u5916\u306E\u5024\u3068\u3057\u3066\u6271\u308F\u308C\u308B)\n\
    \    bool ok = run<int>(rng) && run<long long>(rng) && run<unsigned int>(rng)\
    \ && run<unsigned long long>(rng);\n    // 0..n-1 \u304C\u3059\u3079\u3066\u63C3\
    \u3046\u3068 mex \u306F n\n    MexUpdate<int> full(std::vector<int>{2, 0, 1});\n\
    \    ok = ok && full.mex() == 3;\n    full.set(1, 3);\n    ok = ok && full.mex()\
    \ == 0;\n    // \u9577\u3055 0 \u3068\u65E2\u5B9A\u69CB\u7BC9\u306F mex \u304C\
    \ 0\n    ok = ok && MexUpdate<int>().mex() == 0 && MexUpdate<int>(0).mex() ==\
    \ 0;\n    ok = ok && MexUpdate<int>(std::vector<int>{}).mex() == 0 && MexUpdate<unsigned\
    \ int>().mex() == 0u;\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// MexUpdate \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../../src/data_structures/mex-update.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <set>\n#include <vector>\n\
    \n// v \u306B\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u975E\u8CA0\u6574\
    \u6570\ntemplate <typename T>\nT naive_mex(const std::vector<T>& v) {\n    std::set<T>\
    \ s(v.begin(), v.end());\n    T x = 0;\n    while (s.count(x)) x++;\n    return\
    \ x;\n}\n\ntemplate <typename T>\nbool run(std::mt19937& rng) {\n    for (int\
    \ rep = 0; rep < 2000; rep++) {\n        int n = rng() % 8 + 1;\n        // \u7BC4\
    \u56F2\u5916\u306E\u5024 (\u8CA0\u306E\u5024\u3084 n \u3088\u308A\u5927\u304D\u3044\
    \u5024) \u3082\u6DF7\u305C\u308B\n        auto random_value = [&]() -> T { return\
    \ static_cast<T>(static_cast<int>(rng() % (n + 6)) - 3); };\n        std::vector<T>\
    \ v;\n        MexUpdate<T> mu;\n        if (rep % 2 == 0) {\n            // MexUpdate(n):\
    \ \u5024\u306F\u3069\u308C\u3082 mex \u306B\u5F71\u97FF\u3057\u306A\u3044\u5024\
    \u3067\u521D\u671F\u5316\u3055\u308C\u308B\n            mu = MexUpdate<T>(n);\n\
    \            v.assign(n, static_cast<T>(-1));\n            if (mu.mex() != 0)\
    \ return false;\n        } else {\n            v.resize(n);\n            for (auto&\
    \ x : v) x = random_value();\n            mu = MexUpdate<T>(v);\n        }\n \
    \       if (mu.mex() != naive_mex(v)) return false;\n        for (int t = 0; t\
    \ < 20; t++) {\n            int k = rng() % n;\n            T x = random_value();\n\
    \            mu.set(k, x);\n            v[k] = x;\n            if (mu.mex() !=\
    \ naive_mex(v)) return false;\n        }\n    }\n    return true;\n}\n\nint main()\
    \ {\n    std::mt19937 rng(314);\n    // \u7B26\u53F7\u306A\u3057\u306E\u578B\u3067\
    \u306F\u3001\u8CA0\u306E\u5024\u306F\u5927\u304D\u306A\u5024\u306B\u306A\u308B\
    \ (\u7BC4\u56F2\u5916\u306E\u5024\u3068\u3057\u3066\u6271\u308F\u308C\u308B)\n\
    \    bool ok = run<int>(rng) && run<long long>(rng) && run<unsigned int>(rng)\
    \ && run<unsigned long long>(rng);\n    // 0..n-1 \u304C\u3059\u3079\u3066\u63C3\
    \u3046\u3068 mex \u306F n\n    MexUpdate<int> full(std::vector<int>{2, 0, 1});\n\
    \    ok = ok && full.mex() == 3;\n    full.set(1, 3);\n    ok = ok && full.mex()\
    \ == 0;\n    // \u9577\u3055 0 \u3068\u65E2\u5B9A\u69CB\u7BC9\u306F mex \u304C\
    \ 0\n    ok = ok && MexUpdate<int>().mex() == 0 && MexUpdate<int>(0).mex() ==\
    \ 0;\n    ok = ok && MexUpdate<int>(std::vector<int>{}).mex() == 0 && MexUpdate<unsigned\
    \ int>().mex() == 0u;\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/mex-update.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/mex-update.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/mex-update.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/mex-update.test.cpp
- /verify/test/unittest/data_structures/mex-update.test.cpp.html
title: test/unittest/data_structures/mex-update.test.cpp
---
