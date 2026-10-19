---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/suffix-array.hpp
    title: "Suffix Array \u3068 LCP \u914D\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/yosupo/number-of-substrings.1.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#include <iostream>\n\
    #include <string>\n#include <vector>\n\n#line 2 \"src/string/suffix-array.hpp\"\
    \n\n/**\n * @file suffix-array.hpp\n * @brief Suffix Array (SA-IS) \u3068 LCP\
    \ \u914D\u5217\n */\n\n#include <algorithm>\n#include <cassert>\n#include <climits>\n\
    #include <cstddef>\n#line 13 \"src/string/suffix-array.hpp\"\n#include <type_traits>\n\
    #line 15 \"src/string/suffix-array.hpp\"\n\nnamespace internal_suffix_array {\n\
    // s \u306E\u5024\u306F 0 \u4EE5\u4E0A upper \u4EE5\u4E0B\ninline std::vector<int>\
    \ sa_is(const std::vector<int>& s, int upper) {\n    int n = s.size();\n    if\
    \ (n == 0) return {};\n    if (n == 1) return {0};\n    if (n == 2) return s[0]\
    \ < s[1] ? std::vector<int>{0, 1} : std::vector<int>{1, 0};\n    std::vector<int>\
    \ sa(n);\n    // ls[i]: s[i:] < s[i + 1:] \u306A\u3089 true (S \u578B)\u3001\u305D\
    \u3046\u3067\u306A\u3051\u308C\u3070 false (L \u578B)\n    std::vector<bool> ls(n);\n\
    \    for (int i = n - 2; i >= 0; i--) ls[i] = s[i] == s[i + 1] ? ls[i + 1] : s[i]\
    \ < s[i + 1];\n    // sum_l[c]: \u5148\u982D\u304C c \u306E L \u578B\u306E\u63A5\
    \u5C3E\u8F9E\u304C\u5165\u308B\u4F4D\u7F6E\u306E\u59CB\u307E\u308A\u3001sum_s[c]:\
    \ \u5148\u982D\u304C c \u306E S \u578B\u306E\u63A5\u5C3E\u8F9E\u304C\u5165\u308B\
    \u4F4D\u7F6E\u306E\u59CB\u307E\u308A\n    std::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\n    for (int i = 0; i < n; i++) {\n        if (!ls[i])\n            sum_s[s[i]]++;\n\
    \        else\n            sum_l[s[i] + 1]++;\n    }\n    for (int i = 0; i <=\
    \ upper; i++) {\n        sum_s[i] += sum_l[i];\n        if (i < upper) sum_l[i\
    \ + 1] += sum_s[i];\n    }\n    // LMS \u306E\u4E26\u3073 lms \u304B\u3089\u3001\
    \u8A98\u5C0E\u30BD\u30FC\u30C8\u3067\u5168\u4F53\u3092\u4E26\u3079\u308B\n   \
    \ auto induce = [&](const std::vector<int>& lms) {\n        std::fill(sa.begin(),\
    \ sa.end(), -1);\n        std::vector<int> buf(upper + 1);\n        std::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n        for (int d : lms) {\n            if (d ==\
    \ n) continue;\n            sa[buf[s[d]]++] = d;\n        }\n        std::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n        sa[buf[s[n - 1]]++] = n - 1;\n        for\
    \ (int i = 0; i < n; i++) {\n            int v = sa[i];\n            if (v >=\
    \ 1 && !ls[v - 1]) sa[buf[s[v - 1]]++] = v - 1;\n        }\n        std::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n        for (int i = n - 1; i >= 0; i--) {\n   \
    \         int v = sa[i];\n            if (v >= 1 && ls[v - 1]) sa[--buf[s[v -\
    \ 1] + 1]] = v - 1;\n        }\n    };\n    // LMS (\u5DE6\u304C L \u578B\u306E\
    \ S \u578B) \u306E\u4F4D\u7F6E\n    std::vector<int> lms_map(n + 1, -1), lms;\n\
    \    for (int i = 1; i < n; i++) {\n        if (!ls[i - 1] && ls[i]) {\n     \
    \       lms_map[i] = lms.size();\n            lms.push_back(i);\n        }\n \
    \   }\n    int m = lms.size();\n    induce(lms);\n    if (m) {\n        std::vector<int>\
    \ sorted_lms;\n        sorted_lms.reserve(m);\n        for (int v : sa) {\n  \
    \          if (lms_map[v] != -1) sorted_lms.push_back(v);\n        }\n       \
    \ // LMS \u90E8\u5206\u6587\u5B57\u5217\u306B\u756A\u53F7\u3092\u4ED8\u3051\u3001\
    \u305D\u306E\u5217\u306E Suffix Array \u3092\u518D\u5E30\u3067\u6C42\u3081\u308B\
    \n        std::vector<int> rec_s(m);\n        int rec_upper = 0;\n        rec_s[lms_map[sorted_lms[0]]]\
    \ = 0;\n        for (int i = 1; i < m; i++) {\n            int l = sorted_lms[i\
    \ - 1], r = sorted_lms[i];\n            int end_l = lms_map[l] + 1 < m ? lms[lms_map[l]\
    \ + 1] : n;\n            int end_r = lms_map[r] + 1 < m ? lms[lms_map[r] + 1]\
    \ : n;\n            bool same = true;\n            if (end_l - l != end_r - r)\
    \ {\n                same = false;\n            } else {\n                while\
    \ (l < end_l && s[l] == s[r]) l++, r++;\n                if (l == n || s[l] !=\
    \ s[r]) same = false;\n            }\n            if (!same) rec_upper++;\n  \
    \          rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n        }\n        std::vector<int>\
    \ rec_sa = sa_is(rec_s, rec_upper);\n        for (int i = 0; i < m; i++) sorted_lms[i]\
    \ = lms[rec_sa[i]];\n        induce(sorted_lms);\n    }\n    return sa;\n}\n//\
    \ \u5185\u90E8\u306E int \u306E Suffix Array \u3092\u3001\u8FD4\u3059 long long\
    \ \u306E\u5217\u306B\u76F4\u3059\ninline std::vector<long long> to_long_long(const\
    \ std::vector<int>& sa) { return std::vector<long long>(sa.begin(), sa.end());\
    \ }\n}  // namespace internal_suffix_array\n\n/**\n * @brief Suffix Array \u3092\
    \u6C42\u3081\u308B O(n + upper)\n * \u63A5\u5C3E\u8F9E s[i:] \u3092\u8F9E\u66F8\
    \u9806\u306B\u4E26\u3079\u305F\u3068\u304D\u306E\u958B\u59CB\u4F4D\u7F6E i \u306E\
    \u30EA\u30B9\u30C8\n * @tparam T \u6574\u6570\u578B (int \u3084 long long)\n *\
    \ @param s \u5024\u306F 0 \u4EE5\u4E0A upper \u4EE5\u4E0B\n */\ntemplate <typename\
    \ T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>\nstd::vector<long\
    \ long> suffix_array(const std::vector<T>& s, long long upper) {\n    assert(0\
    \ <= upper && upper < INT_MAX);\n    for ([[maybe_unused]] T x : s) assert(0 <=\
    \ static_cast<long long>(x) && static_cast<long long>(x) <= upper);\n    if constexpr\
    \ (std::is_same_v<T, int>) {\n        return internal_suffix_array::to_long_long(internal_suffix_array::sa_is(s,\
    \ static_cast<int>(upper)));\n    } else {\n        std::vector<int> s2(s.begin(),\
    \ s.end());\n        return internal_suffix_array::to_long_long(internal_suffix_array::sa_is(s2,\
    \ static_cast<int>(upper)));\n    }\n}\n\n/**\n * @brief Suffix Array \u3092\u6C42\
    \u3081\u308B O(n log n)\n * \u63A5\u5C3E\u8F9E s[i:] \u3092\u8F9E\u66F8\u9806\u306B\
    \u4E26\u3079\u305F\u3068\u304D\u306E\u958B\u59CB\u4F4D\u7F6E i \u306E\u30EA\u30B9\
    \u30C8\u3002\u5024\u3092\u5EA7\u6A19\u5727\u7E2E\u3057\u3066\u304B\u3089\u6C42\
    \u3081\u308B\n * @tparam T operator< \u3067\u6BD4\u8F03\u3067\u304D\u308B\u578B\
    \n */\ntemplate <typename T>\nstd::vector<long long> suffix_array(const std::vector<T>&\
    \ s) {\n    int n = s.size();\n    std::vector<int> idx(n);\n    for (int i =\
    \ 0; i < n; i++) idx[i] = i;\n    std::sort(idx.begin(), idx.end(), [&](int a,\
    \ int b) { return s[a] < s[b]; });\n    std::vector<int> s2(n);\n    int now =\
    \ 0;\n    for (int i = 0; i < n; i++) {\n        if (i && s[idx[i - 1]] < s[idx[i]])\
    \ now++;\n        s2[idx[i]] = now;\n    }\n    return internal_suffix_array::to_long_long(internal_suffix_array::sa_is(s2,\
    \ now));\n}\n\n/**\n * @brief \u6587\u5B57\u5217\u306E Suffix Array \u3092\u6C42\
    \u3081\u308B O(n)\n * \u63A5\u5C3E\u8F9E s[i:] \u3092\u8F9E\u66F8\u9806\u306B\u4E26\
    \u3079\u305F\u3068\u304D\u306E\u958B\u59CB\u4F4D\u7F6E i \u306E\u30EA\u30B9\u30C8\
    \n */\ninline std::vector<long long> suffix_array(const std::string& s) {\n  \
    \  int n = s.size();\n    std::vector<int> s2(n);\n    for (int i = 0; i < n;\
    \ i++) s2[i] = static_cast<unsigned char>(s[i]);\n    return internal_suffix_array::to_long_long(internal_suffix_array::sa_is(s2,\
    \ 255));\n}\n\n/**\n * @brief LCP \u914D\u5217\u3092\u6C42\u3081\u308B (Kasai\
    \ \u6CD5) O(n)\n * \u9577\u3055 n - 1 \u306E\u914D\u5217 lcp \u3092\u8FD4\u3059\
    \u3002lcp[i] \u306F s[sa[i]:] \u3068 s[sa[i + 1]:] \u306E\u6700\u9577\u5171\u901A\
    \u63A5\u982D\u8F9E\u306E\u9577\u3055\n * @tparam R std::string \u3084 std::vector\
    \ \u306A\u3069\u3001size() \u3068 operator[] \u3092\u6301\u3064\u578B\n * @tparam\
    \ I sa \u306E\u8981\u7D20\u306E\u578B (long long \u3084 int)\n * @param sa s \u306E\
    \ Suffix Array\n */\ntemplate <typename R, typename I>\nstd::vector<long long>\
    \ lcp_array(const R& s, const std::vector<I>& sa) {\n    long long n = s.size();\n\
    \    assert(static_cast<long long>(sa.size()) == n);\n    if (n == 0) return {};\n\
    \    std::vector<long long> rank(n);\n    for (long long i = 0; i < n; i++) rank[sa[i]]\
    \ = i;\n    std::vector<long long> lcp(n - 1);\n    // s[i:] \u3068\u8F9E\u66F8\
    \u9806\u3067 1 \u3064\u524D\u306E\u63A5\u5C3E\u8F9E\u3068\u306E LCP \u306F\u3001\
    s[i - 1:] \u306E\u3068\u304D\u306E\u5024\u304B\u3089 1 \u3092\u5F15\u3044\u305F\
    \u3082\u306E\u4EE5\u4E0A\u306B\u306A\u308B\n    for (long long i = 0, h = 0; i\
    \ < n; i++) {\n        if (h > 0) h--;\n        if (rank[i] == 0) continue;\n\
    \        long long j = sa[rank[i] - 1];\n        while (j + h < n && i + h < n\
    \ && s[j + h] == s[i + h]) h++;\n        lcp[rank[i] - 1] = h;\n    }\n    return\
    \ lcp;\n}\n#line 8 \"test/yosupo/number-of-substrings.1.test.cpp\"\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::string\
    \ s;\n    std::cin >> s;\n    long long n = s.size();\n    // \u90E8\u5206\u6587\
    \u5B57\u5217\u306F\u63A5\u5C3E\u8F9E\u306E\u63A5\u982D\u8F9E\u3002\u8F9E\u66F8\
    \u9806\u3067\u524D\u306E\u63A5\u5C3E\u8F9E\u3068\u5171\u901A\u3059\u308B\u63A5\
    \u982D\u8F9E\u3092\u9664\u3044\u3066\u6570\u3048\u308B\n    long long ans = n\
    \ * (n + 1) / 2;\n    for (long long h : lcp_array(s, suffix_array(s))) ans -=\
    \ h;\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"../../src/string/suffix-array.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::string s;\n    std::cin >> s;\n    long long n = s.size();\n    // \u90E8\
    \u5206\u6587\u5B57\u5217\u306F\u63A5\u5C3E\u8F9E\u306E\u63A5\u982D\u8F9E\u3002\
    \u8F9E\u66F8\u9806\u3067\u524D\u306E\u63A5\u5C3E\u8F9E\u3068\u5171\u901A\u3059\
    \u308B\u63A5\u982D\u8F9E\u3092\u9664\u3044\u3066\u6570\u3048\u308B\n    long long\
    \ ans = n * (n + 1) / 2;\n    for (long long h : lcp_array(s, suffix_array(s)))\
    \ ans -= h;\n    std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - src/string/suffix-array.hpp
  isVerificationFile: true
  path: test/yosupo/number-of-substrings.1.test.cpp
  requiredBy: []
  timestamp: '2026-10-20 00:25:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/number-of-substrings.1.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number-of-substrings.1.test.cpp
- /verify/test/yosupo/number-of-substrings.1.test.cpp.html
title: test/yosupo/number-of-substrings.1.test.cpp
---
