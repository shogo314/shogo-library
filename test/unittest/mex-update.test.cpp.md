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
  bundledCode: "#line 1 \"test/unittest/mex-update.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// MexUpdate\
    \ \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\
    \u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\
    \u3059\u308B\n\n#include <iostream>\n#include <random>\n#include <set>\n#include\
    \ <vector>\n\n#line 2 \"src/data_structures/mex-update.hpp\"\n\n/**\n * @file\
    \ mex-update.hpp\n * @brief 1\u70B9\u66F4\u65B0\u30FB\u5168\u4F53\u306E mex \u53D6\
    \u5F97\n */\n\n#include <cassert>\n#include <cstddef>\n#include <limits>\n#include\
    \ <map>\n#line 14 \"src/data_structures/mex-update.hpp\"\n\ntemplate <typename\
    \ T>\nstruct MexUpdate {\n    using value_type = T;\n\n   private:\n    inline\
    \ constexpr static value_type e = std::numeric_limits<value_type>::max();\n\n\
    \    int n;\n    std::vector<value_type> v;\n    std::set<int> s;\n    std::map<int,\
    \ std::size_t> m;\n\n   public:\n    MexUpdate() = default;\n    MexUpdate(int\
    \ n) : n(n), v(n, e) {\n        assert(n > 0);\n        assert(n + 1 < e);\n \
    \       std::set<int>::iterator hint = s.end();\n        for (int i = n; i >=\
    \ 0; --i) {\n            hint = s.emplace_hint(hint, i);\n        }\n    }\n \
    \   MexUpdate(const std::vector<value_type>& init) : n(init.size()), v(init) {\n\
    \        assert(n > 0);\n        assert(n + 1 < e);\n        std::set<int>::iterator\
    \ hint = s.end();\n        for (int i = n; i >= 0; --i) {\n            hint =\
    \ s.emplace_hint(hint, i);\n        }\n        for (const auto& i : init) {\n\
    \            if (0 <= i and i <= n) {\n                m[i]++;\n             \
    \   s.erase(i);\n            }\n        }\n    }\n    void set(int k, const value_type&\
    \ x) {\n        assert(0 <= k and k < n);\n        if (0 <= v[k] and v[k] <= n)\
    \ {\n            int v_k = v[k];\n            auto itr = m.find(v_k);\n      \
    \      if (itr->second > 1) {\n                itr->second--;\n            } else\
    \ {\n                m.erase(itr);\n                s.insert(v_k);\n         \
    \   }\n        }\n        if (0 <= x and x <= n) {\n            int xx = x;\n\
    \            auto itr = m.find(xx);\n            if (itr == m.end()) {\n     \
    \           m[xx]++;\n                s.erase(xx);\n            } else {\n   \
    \             itr->second++;\n            }\n        }\n        v[k] = x;\n  \
    \  }\n    value_type prod() const {\n        return *s.begin();\n    }\n};\n#line\
    \ 12 \"test/unittest/mex-update.test.cpp\"\n\n// v \u306B\u542B\u307E\u308C\u306A\
    \u3044\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\ntemplate <typename T>\nT naive_mex(const\
    \ std::vector<T>& v) {\n    std::set<T> s(v.begin(), v.end());\n    T x = 0;\n\
    \    while (s.count(x)) x++;\n    return x;\n}\n\ntemplate <typename T>\nbool\
    \ run(std::mt19937& rng) {\n    for (int rep = 0; rep < 2000; rep++) {\n     \
    \   int n = rng() % 8 + 1;\n        // \u7BC4\u56F2\u5916\u306E\u5024 (\u8CA0\u306E\
    \u5024\u3084 n \u3088\u308A\u5927\u304D\u3044\u5024) \u3082\u6DF7\u305C\u308B\n\
    \        auto random_value = [&]() -> T { return static_cast<T>(static_cast<int>(rng()\
    \ % (n + 6)) - 3); };\n        std::vector<T> v;\n        MexUpdate<T> mu;\n \
    \       if (rep % 2 == 0) {\n            // MexUpdate(n): \u5024\u306F\u3069\u308C\
    \u3082 mex \u306B\u5F71\u97FF\u3057\u306A\u3044\u5024\u3067\u521D\u671F\u5316\u3055\
    \u308C\u308B\n            mu = MexUpdate<T>(n);\n            v.assign(n, -1);\n\
    \            if (mu.prod() != 0) return false;\n        } else {\n           \
    \ v.resize(n);\n            for (auto& x : v) x = random_value();\n          \
    \  mu = MexUpdate<T>(v);\n        }\n        if (mu.prod() != naive_mex(v)) return\
    \ false;\n        for (int t = 0; t < 20; t++) {\n            int k = rng() %\
    \ n;\n            T x = random_value();\n            mu.set(k, x);\n         \
    \   v[k] = x;\n            if (mu.prod() != naive_mex(v)) return false;\n    \
    \    }\n    }\n    return true;\n}\n\nint main() {\n    std::mt19937 rng(314);\n\
    \    bool ok = run<int>(rng) && run<long long>(rng);\n    // 0..n-1 \u304C\u3059\
    \u3079\u3066\u63C3\u3046\u3068 mex \u306F n\n    MexUpdate<int> full(std::vector<int>{2,\
    \ 0, 1});\n    ok = ok && full.prod() == 3;\n    full.set(1, 3);\n    ok = ok\
    \ && full.prod() == 0;\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    \    else std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// MexUpdate \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include <iostream>\n#include <random>\n#include <set>\n\
    #include <vector>\n\n#include \"../../src/data_structures/mex-update.hpp\"\n\n\
    // v \u306B\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\
    \ntemplate <typename T>\nT naive_mex(const std::vector<T>& v) {\n    std::set<T>\
    \ s(v.begin(), v.end());\n    T x = 0;\n    while (s.count(x)) x++;\n    return\
    \ x;\n}\n\ntemplate <typename T>\nbool run(std::mt19937& rng) {\n    for (int\
    \ rep = 0; rep < 2000; rep++) {\n        int n = rng() % 8 + 1;\n        // \u7BC4\
    \u56F2\u5916\u306E\u5024 (\u8CA0\u306E\u5024\u3084 n \u3088\u308A\u5927\u304D\u3044\
    \u5024) \u3082\u6DF7\u305C\u308B\n        auto random_value = [&]() -> T { return\
    \ static_cast<T>(static_cast<int>(rng() % (n + 6)) - 3); };\n        std::vector<T>\
    \ v;\n        MexUpdate<T> mu;\n        if (rep % 2 == 0) {\n            // MexUpdate(n):\
    \ \u5024\u306F\u3069\u308C\u3082 mex \u306B\u5F71\u97FF\u3057\u306A\u3044\u5024\
    \u3067\u521D\u671F\u5316\u3055\u308C\u308B\n            mu = MexUpdate<T>(n);\n\
    \            v.assign(n, -1);\n            if (mu.prod() != 0) return false;\n\
    \        } else {\n            v.resize(n);\n            for (auto& x : v) x =\
    \ random_value();\n            mu = MexUpdate<T>(v);\n        }\n        if (mu.prod()\
    \ != naive_mex(v)) return false;\n        for (int t = 0; t < 20; t++) {\n   \
    \         int k = rng() % n;\n            T x = random_value();\n            mu.set(k,\
    \ x);\n            v[k] = x;\n            if (mu.prod() != naive_mex(v)) return\
    \ false;\n        }\n    }\n    return true;\n}\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = run<int>(rng) && run<long long>(rng);\n    // 0..n-1\
    \ \u304C\u3059\u3079\u3066\u63C3\u3046\u3068 mex \u306F n\n    MexUpdate<int>\
    \ full(std::vector<int>{2, 0, 1});\n    ok = ok && full.prod() == 3;\n    full.set(1,\
    \ 3);\n    ok = ok && full.prod() == 0;\n    if (ok) std::cout << \"Hello World\"\
    \ << std::endl;\n    else std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/mex-update.hpp
  isVerificationFile: true
  path: test/unittest/mex-update.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 12:42:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/mex-update.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/mex-update.test.cpp
- /verify/test/unittest/mex-update.test.cpp.html
title: test/unittest/mex-update.test.cpp
---
