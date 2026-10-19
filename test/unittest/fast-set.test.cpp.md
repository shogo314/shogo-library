---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/fast-set.hpp
    title: "64 \u5206\u6728 (FastSet)"
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
  bundledCode: "#line 1 \"test/unittest/fast-set.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// FastSet \u3092 std::set \u306B\u3088\u308B\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306A\u64CD\u4F5C\u5217\u3067\u6BD4\u3079\u308B\
    \n// \u6BB5\u306E\u5883\u76EE (64\u30014096\u3001262144) \u3092\u307E\u305F\u3050\
    \ n \u3082\u8A66\u3059\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/data_structures/fast-set.hpp\"\n\n/**\n *\
    \ @file fast-set.hpp\n * @brief 64 \u5206\u6728\u306B\u3088\u308B\u6574\u6570\u306E\
    \u96C6\u5408 (FastSet)\n */\n\n#include <cassert>\n#include <cstdint>\n#include\
    \ <vector>\n\n/**\n * @brief [0, n) \u306E\u6574\u6570\u306E\u96C6\u5408\u3092\
    \ 64 \u5206\u6728\u3067\u6301\u3064\n *\n * \u5404\u6BB5\u306F 64 bit \u306E\u914D\
    \u5217\u3067\u3001\u4E0A\u306E\u6BB5\u306E bit \u306F\u4E0B\u306E\u6BB5\u306E\
    \ 64 bit \u304C 0 \u3067\u306A\u3044\u304B\u3092\u8868\u3059\n * \u633F\u5165\u30FB\
    \u524A\u9664\u30FBx \u4EE5\u4E0A\u306E\u6700\u5C0F\u30FBx \u4EE5\u4E0B\u306E\u6700\
    \u5927\u3092 O(log_64 n) \u3067\u884C\u3046 (n = 10^9 \u3067\u3082 5 \u6BB5\u7A0B\
    \u5EA6)\n * \u4F8B:\n * FastSet s(n);\n * s.insert(3); s.insert(10);\n * s.next(4);\
    \  // 10\n * s.prev(4);  // 3\n */\nclass FastSet {\n    long long n, cnt = 0;\n\
    \    std::vector<std::vector<std::uint64_t>> seg;  // seg[0] \u304C\u8981\u7D20\
    \u306E bit\u3001seg[h + 1] \u306F seg[h] \u306E\u5404 64 bit \u304C 0 \u3067\u306A\
    \u3044\u304B\n\n    void build_levels() {\n        // 1 \u3064\u306E 64 bit \u306B\
    \u53CE\u307E\u308B\u307E\u3067\u6BB5\u3092\u91CD\u306D\u308B\n        do {\n \
    \           long long m = seg.empty() ? n : static_cast<long long>(seg.back().size());\n\
    \            seg.emplace_back((m + 63) / 64, 0);\n        } while (seg.back().size()\
    \ > 1);\n    }\n\n   public:\n    /**\n     * @brief [0, n) \u306E\u7A7A\u306E\
    \u96C6\u5408\n     */\n    explicit FastSet(long long n = 0) : n(n) {\n      \
    \  assert(n >= 0);\n        build_levels();\n    }\n    /**\n     * @brief v[i]\
    \ \u304C true \u306E i \u304B\u3089\u306A\u308B\u96C6\u5408 O(n)\n     */\n  \
    \  explicit FastSet(const std::vector<bool>& v) : FastSet(static_cast<long long>(v.size()))\
    \ {\n        for (long long i = 0; i < n; i++) {\n            if (v[i]) seg[0][i\
    \ >> 6] |= std::uint64_t(1) << (i & 63), cnt++;\n        }\n        for (int h\
    \ = 0; h + 1 < static_cast<int>(seg.size()); h++) {\n            for (long long\
    \ i = 0; i < static_cast<long long>(seg[h].size()); i++) {\n                if\
    \ (seg[h][i]) seg[h + 1][i >> 6] |= std::uint64_t(1) << (i & 63);\n          \
    \  }\n        }\n    }\n\n    /**\n     * @brief \u6271\u3048\u308B\u6574\u6570\
    \u306E\u7BC4\u56F2 [0, n) \u306E n\n     */\n    long long limit() const { return\
    \ n; }\n    /**\n     * @brief \u8981\u7D20\u6570\n     */\n    long long size()\
    \ const { return cnt; }\n    /**\n     * @brief \u7A7A\u304B\n     */\n    bool\
    \ empty() const { return cnt == 0; }\n\n    /**\n     * @brief x \u304C\u542B\u307E\
    \u308C\u308B\u304B O(1)\n     */\n    bool contains(long long x) const {\n   \
    \     assert(0 <= x && x < n);\n        return seg[0][x >> 6] >> (x & 63) & 1;\n\
    \    }\n    /**\n     * @brief x \u306E\u500B\u6570 (0 \u304B 1) O(1)\n     */\n\
    \    long long count(long long x) const { return contains(x); }\n    /**\n   \
    \  * @brief x \u3092\u633F\u5165\u3059\u308B\u3002\u65B0\u3057\u304F\u5165\u3063\
    \u305F\u3089 true O(log_64 n)\n     */\n    bool insert(long long x) {\n     \
    \   assert(0 <= x && x < n);\n        if (contains(x)) return false;\n       \
    \ cnt++;\n        for (auto& level : seg) {\n            level[x >> 6] |= std::uint64_t(1)\
    \ << (x & 63);\n            x >>= 6;\n        }\n        return true;\n    }\n\
    \    /**\n     * @brief x \u3092\u524A\u9664\u3059\u308B\u3002\u5165\u3063\u3066\
    \u3044\u305F\u3089 true O(log_64 n)\n     */\n    bool erase(long long x) {\n\
    \        assert(0 <= x && x < n);\n        if (!contains(x)) return false;\n \
    \       cnt--;\n        for (auto& level : seg) {\n            level[x >> 6] &=\
    \ ~(std::uint64_t(1) << (x & 63));\n            // \u540C\u3058 64 bit \u306B\u4ED6\
    \u306E\u8981\u7D20\u304C\u6B8B\u3063\u3066\u3044\u308C\u3070\u3001\u4E0A\u306E\
    \u6BB5\u306F\u5909\u308F\u3089\u306A\u3044\n            if (level[x >> 6]) break;\n\
    \            x >>= 6;\n        }\n        return true;\n    }\n\n    /**\n   \
    \  * @brief x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20 (\u306A\u3051\u308C\
    \u3070 -1) O(log_64 n)\n     */\n    long long next(long long x) const {\n   \
    \     if (x < 0) x = 0;\n        if (x >= n) return -1;\n        for (int h =\
    \ 0; h < static_cast<int>(seg.size()); h++) {\n            if ((x >> 6) == static_cast<long\
    \ long>(seg[h].size())) break;\n            std::uint64_t d = seg[h][x >> 6] >>\
    \ (x & 63);\n            if (!d) {\n                x = (x >> 6) + 1;\n      \
    \          continue;\n            }\n            // \u3053\u306E\u6BB5\u3067\u898B\
    \u3064\u304B\u3063\u305F\u306E\u3067\u3001\u4E0B\u306E\u6BB5\u3067\u306F\u6700\
    \u3082\u5C0F\u3055\u3044 bit \u3092\u305F\u3069\u308B\n            x += __builtin_ctzll(d);\n\
    \            for (int g = h - 1; g >= 0; g--) {\n                x <<= 6;\n  \
    \              x += __builtin_ctzll(seg[g][x >> 6]);\n            }\n        \
    \    return x;\n        }\n        return -1;\n    }\n    /**\n     * @brief x\
    \ \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20 (\u306A\u3051\u308C\u3070 -1)\
    \ O(log_64 n)\n     */\n    long long prev(long long x) const {\n        if (x\
    \ >= n) x = n - 1;\n        if (x < 0) return -1;\n        for (int h = 0; h <\
    \ static_cast<int>(seg.size()); h++) {\n            if (x == -1) break;\n    \
    \        std::uint64_t d = seg[h][x >> 6] << (63 - (x & 63));\n            if\
    \ (!d) {\n                x = (x >> 6) - 1;\n                continue;\n     \
    \       }\n            // \u3053\u306E\u6BB5\u3067\u898B\u3064\u304B\u3063\u305F\
    \u306E\u3067\u3001\u4E0B\u306E\u6BB5\u3067\u306F\u6700\u3082\u5927\u304D\u3044\
    \ bit \u3092\u305F\u3069\u308B\n            x -= __builtin_clzll(d);\n       \
    \     for (int g = h - 1; g >= 0; g--) {\n                x <<= 6;\n         \
    \       x += 63 - __builtin_clzll(seg[g][x >> 6]);\n            }\n          \
    \  return x;\n        }\n        return -1;\n    }\n    /**\n     * @brief \u6700\
    \u5C0F\u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n    long\
    \ long min() const { return next(0); }\n    /**\n     * @brief \u6700\u5927\u306E\
    \u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n    long long max()\
    \ const { return prev(n - 1); }\n\n    /**\n     * @brief \u8981\u7D20\u3092\u6607\
    \u9806\u306B\u4E26\u3079\u305F\u3082\u306E O(size() log_64 n)\n     */\n    std::vector<long\
    \ long> to_vector() const {\n        std::vector<long long> res;\n        res.reserve(cnt);\n\
    \        for (long long x = next(0); x != -1; x = next(x + 1)) res.push_back(x);\n\
    \        return res;\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u524A\u9664\
    \u3059\u308B O(n / 64)\n     */\n    void clear() {\n        for (auto& level\
    \ : seg) level.assign(level.size(), 0);\n        cnt = 0;\n    }\n};\n#line 8\
    \ \"test/unittest/fast-set.test.cpp\"\n\n#include <iostream>\n#include <random>\n\
    #include <set>\n#line 13 \"test/unittest/fast-set.test.cpp\"\n\nbool ok = true;\n\
    void check(bool cond, const char* what) {\n    if (!cond && ok) std::cerr << \"\
    failed: \" << what << std::endl;\n    if (!cond) ok = false;\n}\n\nlong long naive_next(const\
    \ std::set<long long>& s, long long x) {\n    auto it = s.lower_bound(x);\n  \
    \  return it == s.end() ? -1 : *it;\n}\nlong long naive_prev(const std::set<long\
    \ long>& s, long long x) {\n    auto it = s.upper_bound(x);\n    return it ==\
    \ s.begin() ? -1 : *std::prev(it);\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    std::vector<long long> sizes = {0, 1, 2, 63, 64, 65, 127, 128, 4095, 4096,\
    \ 4097, 262143, 262144, 262145};\n    for (int rep = 0; rep < 300; rep++) sizes.push_back(rng()\
    \ % 300 + 1);\n    for (long long n : sizes) {\n        if (!ok) break;\n    \
    \    // \u8981\u7D20\u304C\u5C11\u306A\u3044\u5834\u5408\u3068\u591A\u3044\u5834\
    \u5408\u3092\u6DF7\u305C\u308B\n        int density = rng() % 3;\n        std::vector<bool>\
    \ init(n);\n        std::set<long long> s;\n        for (long long i = 0; i <\
    \ n; i++) {\n            bool in = density == 0 ? rng() % 50 == 0 : density ==\
    \ 1 ? rng() % 2 == 0\n                                                       \
    \             : rng() % 50 != 0;\n            init[i] = in;\n            if (in)\
    \ s.insert(i);\n        }\n        FastSet fs = rng() % 2 ? FastSet(init) : FastSet(n);\n\
    \        if (fs.empty() && !s.empty()) {\n            for (long long x : s) fs.insert(x);\n\
    \        }\n        check(fs.limit() == n, \"limit\");\n        int q = n > 10000\
    \ ? 3000 : 1000;\n        for (int t = 0; t < q && ok; t++) {\n            //\
    \ n \u306E\u5916\u5074 (\u8CA0\u3084 n \u4EE5\u4E0A) \u3082 next / prev \u306B\
    \u6E21\u3059\n            long long x = n == 0 ? 0 : static_cast<long long>(rng()\
    \ % n);\n            long long y = static_cast<long long>(rng() % (n + 4)) - 2;\n\
    \            int type = rng() % 6;\n            if (n > 0 && type == 0) {\n  \
    \              check(fs.insert(x) == s.insert(x).second, \"insert\");\n      \
    \      } else if (n > 0 && type == 1) {\n                check(fs.erase(x) ==\
    \ (s.erase(x) == 1), \"erase\");\n            } else if (n > 0 && type == 2) {\n\
    \                check(fs.contains(x) == (s.count(x) == 1) && fs.count(x) == static_cast<long\
    \ long>(s.count(x)), \"contains\");\n            } else if (type == 3) {\n   \
    \             check(fs.next(y) == naive_next(s, y), \"next\");\n            }\
    \ else if (type == 4) {\n                check(fs.prev(y) == naive_prev(s, y),\
    \ \"prev\");\n            } else {\n                check(fs.min() == (s.empty()\
    \ ? -1 : *s.begin()) && fs.max() == (s.empty() ? -1 : *s.rbegin()), \"min / max\"\
    );\n            }\n            check(fs.size() == static_cast<long long>(s.size())\
    \ && fs.empty() == s.empty(), \"size\");\n        }\n        check(fs.to_vector()\
    \ == std::vector<long long>(s.begin(), s.end()), \"to_vector\");\n        fs.clear();\n\
    \        check(fs.empty() && fs.min() == -1 && fs.max() == -1, \"clear\");\n \
    \   }\n    // \u5927\u304D\u3044 n: 10^9 \u3067\u3082\u6570\u8981\u7D20\u3060\u3051\
    \u306A\u3089\u901F\u304F\u52D5\u304F\n    {\n        FastSet fs(1000000000);\n\
    \        fs.insert(0), fs.insert(123456789), fs.insert(999999999);\n        check(fs.next(1)\
    \ == 123456789 && fs.next(123456790) == 999999999 && fs.prev(999999998) == 123456789\
    \ && fs.prev(-5) == -1, \"10^9\");\n        fs.erase(123456789);\n        check(fs.next(1)\
    \ == 999999999 && fs.prev(999999998) == 0, \"10^9 erase\");\n    }\n\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// FastSet \u3092 std::set \u306B\u3088\u308B\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306A\u64CD\u4F5C\u5217\u3067\u6BD4\u3079\u308B\
    \n// \u6BB5\u306E\u5883\u76EE (64\u30014096\u3001262144) \u3092\u307E\u305F\u3050\
    \ n \u3082\u8A66\u3059\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include \"../../src/data_structures/fast-set.hpp\"\n\n\
    #include <iostream>\n#include <random>\n#include <set>\n#include <vector>\n\n\
    bool ok = true;\nvoid check(bool cond, const char* what) {\n    if (!cond && ok)\
    \ std::cerr << \"failed: \" << what << std::endl;\n    if (!cond) ok = false;\n\
    }\n\nlong long naive_next(const std::set<long long>& s, long long x) {\n    auto\
    \ it = s.lower_bound(x);\n    return it == s.end() ? -1 : *it;\n}\nlong long naive_prev(const\
    \ std::set<long long>& s, long long x) {\n    auto it = s.upper_bound(x);\n  \
    \  return it == s.begin() ? -1 : *std::prev(it);\n}\n\nint main() {\n    std::mt19937_64\
    \ rng(314);\n    std::vector<long long> sizes = {0, 1, 2, 63, 64, 65, 127, 128,\
    \ 4095, 4096, 4097, 262143, 262144, 262145};\n    for (int rep = 0; rep < 300;\
    \ rep++) sizes.push_back(rng() % 300 + 1);\n    for (long long n : sizes) {\n\
    \        if (!ok) break;\n        // \u8981\u7D20\u304C\u5C11\u306A\u3044\u5834\
    \u5408\u3068\u591A\u3044\u5834\u5408\u3092\u6DF7\u305C\u308B\n        int density\
    \ = rng() % 3;\n        std::vector<bool> init(n);\n        std::set<long long>\
    \ s;\n        for (long long i = 0; i < n; i++) {\n            bool in = density\
    \ == 0 ? rng() % 50 == 0 : density == 1 ? rng() % 2 == 0\n                   \
    \                                                 : rng() % 50 != 0;\n       \
    \     init[i] = in;\n            if (in) s.insert(i);\n        }\n        FastSet\
    \ fs = rng() % 2 ? FastSet(init) : FastSet(n);\n        if (fs.empty() && !s.empty())\
    \ {\n            for (long long x : s) fs.insert(x);\n        }\n        check(fs.limit()\
    \ == n, \"limit\");\n        int q = n > 10000 ? 3000 : 1000;\n        for (int\
    \ t = 0; t < q && ok; t++) {\n            // n \u306E\u5916\u5074 (\u8CA0\u3084\
    \ n \u4EE5\u4E0A) \u3082 next / prev \u306B\u6E21\u3059\n            long long\
    \ x = n == 0 ? 0 : static_cast<long long>(rng() % n);\n            long long y\
    \ = static_cast<long long>(rng() % (n + 4)) - 2;\n            int type = rng()\
    \ % 6;\n            if (n > 0 && type == 0) {\n                check(fs.insert(x)\
    \ == s.insert(x).second, \"insert\");\n            } else if (n > 0 && type ==\
    \ 1) {\n                check(fs.erase(x) == (s.erase(x) == 1), \"erase\");\n\
    \            } else if (n > 0 && type == 2) {\n                check(fs.contains(x)\
    \ == (s.count(x) == 1) && fs.count(x) == static_cast<long long>(s.count(x)), \"\
    contains\");\n            } else if (type == 3) {\n                check(fs.next(y)\
    \ == naive_next(s, y), \"next\");\n            } else if (type == 4) {\n     \
    \           check(fs.prev(y) == naive_prev(s, y), \"prev\");\n            } else\
    \ {\n                check(fs.min() == (s.empty() ? -1 : *s.begin()) && fs.max()\
    \ == (s.empty() ? -1 : *s.rbegin()), \"min / max\");\n            }\n        \
    \    check(fs.size() == static_cast<long long>(s.size()) && fs.empty() == s.empty(),\
    \ \"size\");\n        }\n        check(fs.to_vector() == std::vector<long long>(s.begin(),\
    \ s.end()), \"to_vector\");\n        fs.clear();\n        check(fs.empty() &&\
    \ fs.min() == -1 && fs.max() == -1, \"clear\");\n    }\n    // \u5927\u304D\u3044\
    \ n: 10^9 \u3067\u3082\u6570\u8981\u7D20\u3060\u3051\u306A\u3089\u901F\u304F\u52D5\
    \u304F\n    {\n        FastSet fs(1000000000);\n        fs.insert(0), fs.insert(123456789),\
    \ fs.insert(999999999);\n        check(fs.next(1) == 123456789 && fs.next(123456790)\
    \ == 999999999 && fs.prev(999999998) == 123456789 && fs.prev(-5) == -1, \"10^9\"\
    );\n        fs.erase(123456789);\n        check(fs.next(1) == 999999999 && fs.prev(999999998)\
    \ == 0, \"10^9 erase\");\n    }\n\n    if (ok) std::cout << \"Hello World\" <<\
    \ std::endl;\n}\n"
  dependsOn:
  - src/data_structures/fast-set.hpp
  isVerificationFile: true
  path: test/unittest/fast-set.test.cpp
  requiredBy: []
  timestamp: '2026-10-20 00:24:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/fast-set.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/fast-set.test.cpp
- /verify/test/unittest/fast-set.test.cpp.html
title: test/unittest/fast-set.test.cpp
---
