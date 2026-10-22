---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/longest-common-substring.hpp
    title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u6587\u5B57\u5217\u3068\u3001\u6700\
      \u9577\u306E\u7E70\u308A\u8FD4\u3057\u90E8\u5206\u6587\u5B57\u5217"
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_common_substring
    links:
    - https://judge.yosupo.jp/problem/longest_common_substring
  bundledCode: "#line 1 \"test/yosupo/string/longest-common-substring.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/longest_common_substring\"\n\
    \n#line 2 \"src/string/longest-common-substring.hpp\"\n\n/**\n * @file longest-common-substring.hpp\n\
    \ * @brief \u6700\u9577\u5171\u901A\u90E8\u5206\u6587\u5B57\u5217\u3068\u3001\u6700\
    \u9577\u306E\u7E70\u308A\u8FD4\u3057\u90E8\u5206\u6587\u5B57\u5217\n */\n\n#include\
    \ <algorithm>\n#include <iterator>\n#include <tuple>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"src/string/suffix-array.hpp\"\
    \n\n/**\n * @file suffix-array.hpp\n * @brief Suffix Array (SA-IS) \u3068 LCP\
    \ \u914D\u5217\n */\n\n#line 9 \"src/string/suffix-array.hpp\"\n#include <cassert>\n\
    #include <climits>\n#include <cstddef>\n#include <string>\n#line 15 \"src/string/suffix-array.hpp\"\
    \n\nnamespace internal_suffix_array {\n// s \u306E\u5024\u306F 0 \u4EE5\u4E0A\
    \ upper \u4EE5\u4E0B\ninline std::vector<int> sa_is(const std::vector<int>& s,\
    \ int upper) {\n    int n = s.size();\n    if (n == 0) return {};\n    if (n ==\
    \ 1) return {0};\n    if (n == 2) return s[0] < s[1] ? std::vector<int>{0, 1}\
    \ : std::vector<int>{1, 0};\n    std::vector<int> sa(n);\n    // ls[i]: s[i:]\
    \ < s[i + 1:] \u306A\u3089 true (S \u578B)\u3001\u305D\u3046\u3067\u306A\u3051\
    \u308C\u3070 false (L \u578B)\n    std::vector<bool> ls(n);\n    for (int i =\
    \ n - 2; i >= 0; i--) ls[i] = s[i] == s[i + 1] ? ls[i + 1] : s[i] < s[i + 1];\n\
    \    // sum_l[c]: \u5148\u982D\u304C c \u306E L \u578B\u306E\u63A5\u5C3E\u8F9E\
    \u304C\u5165\u308B\u4F4D\u7F6E\u306E\u59CB\u307E\u308A\u3001sum_s[c]: \u5148\u982D\
    \u304C c \u306E S \u578B\u306E\u63A5\u5C3E\u8F9E\u304C\u5165\u308B\u4F4D\u7F6E\
    \u306E\u59CB\u307E\u308A\n    std::vector<int> sum_l(upper + 1), sum_s(upper +\
    \ 1);\n    for (int i = 0; i < n; i++) {\n        if (!ls[i])\n            sum_s[s[i]]++;\n\
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
    \ lcp;\n}\n#line 16 \"src/string/longest-common-substring.hpp\"\n\n/**\n * @brief\
    \ s \u3068 t \u306E\u6700\u9577\u5171\u901A\u90E8\u5206\u6587\u5B57\u5217 (\u9023\
    \u7D9A\u3059\u308B\u90E8\u5206\u5217) \u3092 1 \u3064\u6C42\u3081\u308B O((n +\
    \ m) log(n + m))\n * s[i, i + len) == t[j, j + len) \u3068\u306A\u308B (i, j,\
    \ len) \u3092\u8FD4\u3059\u3002\u5171\u901A\u90E8\u5206\u304C\u306A\u3051\u308C\
    \u3070 (0, 0, 0)\n * \u8981\u7D20\u306F operator< \u3067\u6BD4\u3079\u308B\n */\n\
    template <typename R1, typename R2>\nstd::tuple<long long, long long, long long>\
    \ longest_common_substring(const R1& s, const R2& t) {\n    using T = std::decay_t<decltype(*std::begin(s))>;\n\
    \    std::vector<T> vs(std::begin(s), std::end(s)), vt(std::begin(t), std::end(t));\n\
    \    long long n = vs.size(), m = vt.size();\n    // \u5EA7\u6A19\u5727\u7E2E\u3057\
    \u3066\u3001s\u3001\u533A\u5207\u308A\u3001t \u306E\u9806\u306B\u4E26\u3079\u308B\
    \u3002\u533A\u5207\u308A\u306F 1 \u56DE\u3057\u304B\u73FE\u308C\u306A\u3044\u306E\
    \u3067\u3001LCP \u306F\u533A\u5207\u308A\u3092\u307E\u305F\u304C\u306A\u3044\n\
    \    std::vector<T> vals(vs);\n    vals.insert(vals.end(), vt.begin(), vt.end());\n\
    \    std::sort(vals.begin(), vals.end());\n    vals.erase(std::unique(vals.begin(),\
    \ vals.end(), [](const T& a, const T& b) { return !(a < b) && !(b < a); }),\n\
    \               vals.end());\n    long long sep = vals.size();\n    std::vector<int>\
    \ u;\n    u.reserve(n + m + 1);\n    for (const T& x : vs) u.push_back(std::lower_bound(vals.begin(),\
    \ vals.end(), x) - vals.begin());\n    u.push_back(sep);\n    for (const T& x\
    \ : vt) u.push_back(std::lower_bound(vals.begin(), vals.end(), x) - vals.begin());\n\
    \    std::vector<long long> sa = suffix_array(u, sep);\n    std::vector<long long>\
    \ lcp = lcp_array(u, sa);\n    // \u8F9E\u66F8\u9806\u3067\u96A3\u308A\u5408\u3046\
    \u63A5\u5C3E\u8F9E\u306E\u3046\u3061\u3001\u7247\u65B9\u304C s\u3001\u3082\u3046\
    \u7247\u65B9\u304C t \u304B\u3089\u59CB\u307E\u308B\u3082\u306E\u306E LCP \u306E\
    \u6700\u5927\n    long long i = 0, j = 0, len = 0;\n    for (long long k = 0;\
    \ k + 1 < static_cast<long long>(sa.size()); k++) {\n        long long a = sa[k],\
    \ b = sa[k + 1];\n        if (a > b) std::swap(a, b);\n        if (a < n && n\
    \ < b && lcp[k] > len) {\n            i = a, j = b - n - 1, len = lcp[k];\n  \
    \      }\n    }\n    return {i, j, len};\n}\n\n/**\n * @brief s \u306E\u4E2D\u306B\
    \ 2 \u56DE\u4EE5\u4E0A\u73FE\u308C\u308B (\u91CD\u306A\u3063\u3066\u3088\u3044\
    ) \u6700\u9577\u306E\u90E8\u5206\u6587\u5B57\u5217\u3092 1 \u3064\u6C42\u3081\u308B\
    \ O(n log n)\n * s[i, i + len) == s[j, j + len) \u304B\u3064 i < j \u3068\u306A\
    \u308B (i, j, len) \u3092\u8FD4\u3059\u30022 \u56DE\u4EE5\u4E0A\u73FE\u308C\u308B\
    \u90E8\u5206\u304C\u306A\u3051\u308C\u3070 (0, 0, 0)\n * \u8F9E\u66F8\u9806\u3067\
    \u96A3\u308A\u5408\u3046\u63A5\u5C3E\u8F9E\u306E LCP \u306E\u6700\u5927\u3002\u8981\
    \u7D20\u306F operator< \u3067\u6BD4\u3079\u308B\n */\ntemplate <typename R>\n\
    std::tuple<long long, long long, long long> longest_repeated_substring(const R&\
    \ s) {\n    using T = std::decay_t<decltype(*std::begin(s))>;\n    std::vector<T>\
    \ v(std::begin(s), std::end(s));\n    std::vector<long long> sa = suffix_array(v);\n\
    \    std::vector<long long> lcp = lcp_array(v, sa);\n    long long i = 0, j =\
    \ 0, len = 0;\n    for (long long k = 0; k < static_cast<long long>(lcp.size());\
    \ k++) {\n        if (lcp[k] > len) i = std::min(sa[k], sa[k + 1]), j = std::max(sa[k],\
    \ sa[k + 1]), len = lcp[k];\n    }\n    return {i, j, len};\n}\n\n/**\n * @brief\
    \ s \u306E\u4E2D\u306B\u91CD\u306A\u3089\u305A\u306B 2 \u56DE\u4EE5\u4E0A\u73FE\
    \u308C\u308B\u6700\u9577\u306E\u90E8\u5206\u6587\u5B57\u5217\u3092 1 \u3064\u6C42\
    \u3081\u308B O(n log n)\n * s[i, i + len) == s[j, j + len) \u304B\u3064 i + len\
    \ <= j \u3068\u306A\u308B (i, j, len) \u3092\u8FD4\u3059\u3002\u306A\u3051\u308C\
    \u3070 (0, 0, 0)\n *\n * \u9577\u3055 L \u306E\u3082\u306E\u304C\u3042\u308C\u3070\
    \ L - 1 \u306E\u3082\u306E\u3082\u3042\u308B\u306E\u3067\u3001L \u3067\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\u3002L \u3092\u56FA\u5B9A\u3057\u305F\u3089\u3001\u8F9E\
    \u66F8\u9806\u3067\u96A3\u308A\u5408\u3046 LCP \u304C\n * L \u4EE5\u4E0A\u306E\
    \u9023\u7D9A\u3057\u305F\u533A\u9593\u3054\u3068\u306B\u3001\u958B\u59CB\u4F4D\
    \u7F6E\u306E\u6700\u5C0F\u3068\u6700\u5927\u306E\u5DEE\u304C L \u4EE5\u4E0A\u304B\
    \u3092\u898B\u308B\u3002\u8981\u7D20\u306F operator< \u3067\u6BD4\u3079\u308B\n\
    \ */\ntemplate <typename R>\nstd::tuple<long long, long long, long long> longest_non_overlapping_repeated_substring(const\
    \ R& s) {\n    using T = std::decay_t<decltype(*std::begin(s))>;\n    std::vector<T>\
    \ v(std::begin(s), std::end(s));\n    const long long n = v.size();\n    std::vector<long\
    \ long> sa = suffix_array(v);\n    std::vector<long long> lcp = lcp_array(v, sa);\n\
    \    // \u9577\u3055 L \u3067\u91CD\u306A\u3089\u306A\u3044 2 \u304B\u6240\u304C\
    \u3042\u308C\u3070\u3001\u305D\u306E\u958B\u59CB\u4F4D\u7F6E (i, j) \u3092\u8FD4\
    \u3059\u3002\u306A\u3051\u308C\u3070 (-1, -1)\n    auto find = [&](long long L)\
    \ -> std::pair<long long, long long> {\n        long long lo = sa.empty() ? 0\
    \ : sa[0], hi = lo;\n        for (long long k = 0; k < n; k++) {\n           \
    \ if (k > 0 && lcp[k - 1] >= L) {\n                lo = std::min(lo, sa[k]), hi\
    \ = std::max(hi, sa[k]);\n            } else {\n                lo = hi = sa[k];\n\
    \            }\n            if (hi - lo >= L) return {lo, hi};\n        }\n  \
    \      return {-1, -1};\n    };\n    // find(ok) \u304C\u898B\u3064\u304B\u308A\
    \u3001find(ng) \u304C\u898B\u3064\u304B\u3089\u306A\u3044\n    long long ok =\
    \ 0, ng = n / 2 + 1;\n    while (ng - ok > 1) {\n        long long mid = (ok +\
    \ ng) / 2;\n        (find(mid).first != -1 ? ok : ng) = mid;\n    }\n    if (ok\
    \ == 0) return {0, 0, 0};\n    auto [i, j] = find(ok);\n    return {i, j, ok};\n\
    }\n#line 4 \"test/yosupo/string/longest-common-substring.test.cpp\"\n\n#include\
    \ <iostream>\n#line 7 \"test/yosupo/string/longest-common-substring.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::string s, t;\n    std::cin >> s >> t;\n    auto [i, j, len] = longest_common_substring(s,\
    \ t);\n    std::cout << i << ' ' << i + len << ' ' << j << ' ' << j + len << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_common_substring\"\
    \n\n#include \"../../../src/string/longest-common-substring.hpp\"\n\n#include\
    \ <iostream>\n#include <string>\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    std::string s, t;\n    std::cin >>\
    \ s >> t;\n    auto [i, j, len] = longest_common_substring(s, t);\n    std::cout\
    \ << i << ' ' << i + len << ' ' << j << ' ' << j + len << '\\n';\n}\n"
  dependsOn:
  - src/string/longest-common-substring.hpp
  - src/string/suffix-array.hpp
  isVerificationFile: true
  path: test/yosupo/string/longest-common-substring.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 14:02:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/string/longest-common-substring.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/string/longest-common-substring.test.cpp
- /verify/test/yosupo/string/longest-common-substring.test.cpp.html
title: test/yosupo/string/longest-common-substring.test.cpp
---
