---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/edit-distance.hpp
    title: "\u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\
      \u30F3\u8DDD\u96E2)"
  - icon: ':heavy_check_mark:'
    path: src/dp/longest-common-subsequence.hpp
    title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (LCS)"
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
  bundledCode: "#line 1 \"test/unittest/dp/edit-distance.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ edit_distance \u3068 longest_common_subsequence\u3001\u305D\u306E\u5FA9\u5143\
    \u3092\u3001\u518D\u5E30\u306B\u3088\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\
    \u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/dp/edit-distance.hpp\"\
    \n\n/**\n * @file edit-distance.hpp\n * @brief \u7DE8\u96C6\u8DDD\u96E2 (\u30EC\
    \u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2)\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iterator>\n#include <vector>\n\n\
    /**\n * @brief s \u3092 t \u306B\u5909\u3048\u308B\u306E\u306B\u5FC5\u8981\u306A\
    \u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\u63DB\u306E\u6700\u5C0F\u56DE\u6570\
    \ O(nm)\n * \u8981\u7D20\u306F == \u3067\u6BD4\u3079\u308B\u3002\u30E1\u30E2\u30EA\
    \u306F O(m)\n */\ntemplate <typename R1, typename R2>\nlong long edit_distance(const\
    \ R1& s, const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n\
    \    long long n = std::end(s) - a, m = std::end(t) - b;\n    // dp[j] \u306F\
    \ s[0, i) \u3068 t[0, j) \u306E\u7DE8\u96C6\u8DDD\u96E2\n    std::vector<long\
    \ long> dp(m + 1);\n    for (long long j = 0; j <= m; j++) dp[j] = j;\n    for\
    \ (long long i = 1; i <= n; i++) {\n        long long diag = dp[0];  // s[0, i\
    \ - 1) \u3068 t[0, j - 1) \u306E\u7DE8\u96C6\u8DDD\u96E2\n        dp[0] = i;\n\
    \        for (long long j = 1; j <= m; j++) {\n            long long up = dp[j];\n\
    \            dp[j] = std::min({dp[j] + 1, dp[j - 1] + 1, diag + (a[i - 1] == b[j\
    \ - 1] ? 0 : 1)});\n            diag = up;\n        }\n    }\n    return dp[m];\n\
    }\n\n/**\n * @brief \u7DE8\u96C6\u8DDD\u96E2\u3068\u3001s \u3092 t \u306B\u5909\
    \u3048\u308B\u64CD\u4F5C\u5217\n */\nstruct EditDistance {\n    enum class Type\
    \ { Insert,\n                      Erase,\n                      Replace };\n\
    \    struct Operation {\n        Type type;\n        long long source_index; \
    \ //!< \u5143\u306E s \u306E\u6DFB\u5B57\u3002\u633F\u5165\u3067\u306F\u9699\u9593\
    \u306E\u4F4D\u7F6E [0, |s|]\n        long long target_index;  //!< t \u306E\u6DFB\
    \u5B57\u3002\u524A\u9664\u3067\u306F\u9699\u9593\u306E\u4F4D\u7F6E [0, |t|]\n\
    \    };\n    long long distance;\n    std::vector<Operation> operations;\n};\n\
    \n/**\n * @brief \u7DE8\u96C6\u8DDD\u96E2\u3068\u3001\u305D\u306E\u6700\u5C0F\u56DE\
    \u6570\u306E\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\u63DB\u3092\u6C42\u3081\
    \u308B\n * \u6642\u9593\u30FB\u30E1\u30E2\u30EA O(nm)\u3002\u4E00\u81F4\u3059\u308B\
    \u8981\u7D20\u3092\u901A\u904E\u3059\u308B\u64CD\u4F5C\u306F\u542B\u3081\u306A\
    \u3044\u3002\n * \u64CD\u4F5C\u9806\u306B\u3001\u5909\u66F4\u4E2D\u306E\u5217\u306E\
    \ target_index \u306E\u4F4D\u7F6E\u3078\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\
    \u63DB\u3059\u308B\u3002\n * \u633F\u5165\u30FB\u7F6E\u63DB\u3059\u308B\u5024\u306F\
    \ t[target_index]\u3002\n */\ntemplate <typename R1, typename R2>\nEditDistance\
    \ edit_distance_restore(const R1& s, const R2& t) {\n    auto a = std::begin(s);\n\
    \    auto b = std::begin(t);\n    const long long n = std::end(s) - a, m = std::end(t)\
    \ - b;\n    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m\
    \ + 1));\n    for (long long i = 0; i <= n; ++i) dp[i][0] = i;\n    for (long\
    \ long j = 0; j <= m; ++j) dp[0][j] = j;\n    for (long long i = 1; i <= n; ++i)\
    \ {\n        for (long long j = 1; j <= m; ++j) {\n            dp[i][j] = std::min({dp[i\
    \ - 1][j] + 1, dp[i][j - 1] + 1,\n                                 dp[i - 1][j\
    \ - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)});\n        }\n    }\n    EditDistance\
    \ result{dp[n][m], {}};\n    result.operations.reserve(result.distance);\n   \
    \ long long i = n, j = m;\n    while (i > 0 || j > 0) {\n        if (i > 0 &&\
    \ j > 0 && dp[i][j] == dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)) {\n\
    \            if (!(a[i - 1] == b[j - 1])) result.operations.push_back({EditDistance::Type::Replace,\
    \ i - 1, j - 1});\n            --i, --j;\n        } else if (i > 0 && dp[i][j]\
    \ == dp[i - 1][j] + 1) {\n            result.operations.push_back({EditDistance::Type::Erase,\
    \ i - 1, j});\n            --i;\n        } else {\n            assert(j > 0);\n\
    \            result.operations.push_back({EditDistance::Type::Insert, i, j - 1});\n\
    \            --j;\n        }\n    }\n    std::reverse(result.operations.begin(),\
    \ result.operations.end());\n    return result;\n}\n#line 7 \"test/unittest/dp/edit-distance.test.cpp\"\
    \n\n#line 9 \"test/unittest/dp/edit-distance.test.cpp\"\n#include <iostream>\n\
    #line 11 \"test/unittest/dp/edit-distance.test.cpp\"\n#include <random>\n#include\
    \ <string>\n#line 14 \"test/unittest/dp/edit-distance.test.cpp\"\n\n#line 2 \"\
    src/dp/longest-common-subsequence.hpp\"\n\n/**\n * @file longest-common-subsequence.hpp\n\
    \ * @brief \u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (LCS)\n */\n\n#line 10 \"\
    src/dp/longest-common-subsequence.hpp\"\n#include <utility>\n#line 12 \"src/dp/longest-common-subsequence.hpp\"\
    \n\n/**\n * @brief s \u3068 t \u306E\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
    \u306E\u9577\u3055 O(nm)\n * \u8981\u7D20\u306F == \u3067\u6BD4\u3079\u308B\u3002\
    \u30E1\u30E2\u30EA\u306F O(m)\n */\ntemplate <typename R1, typename R2>\nlong\
    \ long longest_common_subsequence(const R1& s, const R2& t) {\n    auto a = std::begin(s);\n\
    \    auto b = std::begin(t);\n    long long n = std::end(s) - a, m = std::end(t)\
    \ - b;\n    // dp[j] \u306F s[0, i) \u3068 t[0, j) \u306E LCS \u306E\u9577\u3055\
    \n    std::vector<long long> dp(m + 1);\n    for (long long i = 1; i <= n; i++)\
    \ {\n        long long diag = 0;  // s[0, i - 1) \u3068 t[0, j - 1) \u306E LCS\
    \ \u306E\u9577\u3055\n        for (long long j = 1; j <= m; j++) {\n         \
    \   long long up = dp[j];\n            dp[j] = a[i - 1] == b[j - 1] ? diag + 1\
    \ : std::max(dp[j], dp[j - 1]);\n            diag = up;\n        }\n    }\n  \
    \  return dp[m];\n}\n\n/**\n * @brief \u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
    \u306E\u5FA9\u5143\u306E\u7D50\u679C\n *\n * auto [length, indices] = longest_common_subsequence_restore(s,\
    \ t); \u306E\u3088\u3046\u306B\u53D7\u3051\u53D6\u308C\u308B\n */\nstruct LongestCommonSubsequence\
    \ {\n    long long length;                                      //!< \u9577\u3055\
    \n    std::vector<std::pair<long long, long long>> indices;  //!< s[i] == t[j]\
    \ \u3068\u3057\u3066\u9078\u3093\u3060\u6DFB\u5B57\u306E\u7D44 (i, j) \u306E\u6607\
    \u9806\u306E\u30EA\u30B9\u30C8\n};\n\n/**\n * @brief s \u3068 t \u306E\u6700\u9577\
    \u5171\u901A\u90E8\u5206\u5217\u3092 1 \u3064\u6C42\u3081\u308B O(nm)\n * \u9577\
    \u3055\u3068\u3001s[i] == t[j] \u3068\u3057\u3066\u9078\u3093\u3060\u6DFB\u5B57\
    \u306E\u7D44 (i, j) \u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u30EA\u30B9\u30C8\
    \u3092\u8FD4\u3059\u3002\u30E1\u30E2\u30EA\u306F O(nm)\n */\ntemplate <typename\
    \ R1, typename R2>\nLongestCommonSubsequence longest_common_subsequence_restore(const\
    \ R1& s, const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n\
    \    long long n = std::end(s) - a, m = std::end(t) - b;\n    // dp[i][j] \u306F\
    \ s[0, i) \u3068 t[0, j) \u306E LCS \u306E\u9577\u3055\n    std::vector<std::vector<int>>\
    \ dp(n + 1, std::vector<int>(m + 1));\n    for (long long i = 1; i <= n; i++)\
    \ {\n        for (long long j = 1; j <= m; j++) {\n            dp[i][j] = a[i\
    \ - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]);\n\
    \        }\n    }\n    // \u5F8C\u308D\u304B\u3089\u305F\u3069\u308B\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    for (long long i = n, j = m; i > 0 && j > 0;) {\n\
    \        if (a[i - 1] == b[j - 1]) {\n            res.emplace_back(i - 1, j -\
    \ 1);\n            i--, j--;\n        } else if (dp[i - 1][j] >= dp[i][j - 1])\
    \ {\n            i--;\n        } else {\n            j--;\n        }\n    }\n\
    \    std::reverse(res.begin(), res.end());\n    return {static_cast<long long>(res.size()),\
    \ res};\n}\n#line 16 \"test/unittest/dp/edit-distance.test.cpp\"\n\n// s[i:] \u3068\
    \ t[j:] \u306E\u7DE8\u96C6\u8DDD\u96E2\nint naive_edit(const std::string& s, const\
    \ std::string& t, int i, int j) {\n    if (i == static_cast<int>(s.size())) return\
    \ t.size() - j;\n    if (j == static_cast<int>(t.size())) return s.size() - i;\n\
    \    int res = naive_edit(s, t, i + 1, j + 1) + (s[i] != t[j]);\n    res = std::min(res,\
    \ naive_edit(s, t, i + 1, j) + 1);\n    res = std::min(res, naive_edit(s, t, i,\
    \ j + 1) + 1);\n    return res;\n}\n\n// s[i:] \u3068 t[j:] \u306E LCS \u306E\u9577\
    \u3055\nint naive_lcs(const std::string& s, const std::string& t, int i, int j)\
    \ {\n    if (i == static_cast<int>(s.size()) || j == static_cast<int>(t.size()))\
    \ return 0;\n    int res = std::max(naive_lcs(s, t, i + 1, j), naive_lcs(s, t,\
    \ i, j + 1));\n    if (s[i] == t[j]) res = std::max(res, naive_lcs(s, t, i + 1,\
    \ j + 1) + 1);\n    return res;\n}\n\n// \u8FD4\u3055\u308C\u305F\u64CD\u4F5C\u3092\
    \u5B9F\u969B\u306B\u9069\u7528\u3057\u3001\u5143\u306E\u5217\u306E\u6DFB\u5B57\
    \u3068\u76EE\u6A19\u306E\u6DFB\u5B57\u306E\u6574\u5408\u6027\u3082\u78BA\u304B\
    \u3081\u308B\u3002\ntemplate <class R1, class R2>\nbool check_restore(const R1&\
    \ s, const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n\
    \    const long long n = std::end(s) - a, m = std::end(t) - b;\n    const auto\
    \ result = edit_distance_restore(s, t);\n    if (result.distance != edit_distance(s,\
    \ t) || result.distance != static_cast<long long>(result.operations.size())) return\
    \ false;\n    using T = typename std::iterator_traits<decltype(a)>::value_type;\n\
    \    std::vector<T> current(a, std::end(s));\n    long long consumed = 0;\n  \
    \  for (const auto& operation : result.operations) {\n        auto [type, source,\
    \ target] = operation;\n        if (source < consumed || source > n || target\
    \ < 0 || target > static_cast<long long>(current.size())) return false;\n    \
    \    if (type == EditDistance::Type::Insert) {\n            if (target >= m) return\
    \ false;\n            current.insert(current.begin() + target, b[target]);\n \
    \           consumed = source;\n        } else {\n            if (source >= n\
    \ || target >= static_cast<long long>(current.size()) || current[target] != a[source])\
    \ return false;\n            if (type == EditDistance::Type::Erase) {\n      \
    \          if (target > m) return false;\n                current.erase(current.begin()\
    \ + target);\n            } else {\n                if (target >= m) return false;\n\
    \                current[target] = b[target];\n            }\n            consumed\
    \ = source + 1;\n        }\n    }\n    return std::equal(current.begin(), current.end(),\
    \ b, std::end(t));\n}\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok\
    \ = true;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng()\
    \ % 8, m = rng() % 8;\n        int k = rng() % 3 + 1;\n        std::string s(n,\
    \ 'a'), t(m, 'a');\n        for (auto& c : s) c = 'a' + rng() % k;\n        for\
    \ (auto& c : t) c = 'a' + rng() % k;\n\n        ok = ok && edit_distance(s, t)\
    \ == naive_edit(s, t, 0, 0);\n        ok = ok && check_restore(s, t);\n      \
    \  int len = naive_lcs(s, t, 0, 0);\n        ok = ok && longest_common_subsequence(s,\
    \ t) == len;\n\n        // \u5FA9\u5143: \u9577\u3055\u304C\u6700\u9577\u3067\u3001\
    \u6DFB\u5B57\u304C\u4E21\u65B9\u3068\u3082\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\
    \u3057\u3001\u8981\u7D20\u304C\u4E00\u81F4\u3059\u308B\n        auto [length,\
    \ idx] = longest_common_subsequence_restore(s, t);\n        ok = ok && length\
    \ == len && static_cast<int>(idx.size()) == len;\n        for (int p = 0; p <\
    \ static_cast<int>(idx.size()) && ok; p++) {\n            auto [i, j] = idx[p];\n\
    \            ok = 0 <= i && i < n && 0 <= j && j < m && s[i] == t[j];\n      \
    \      if (p > 0) ok = ok && idx[p - 1].first < i && idx[p - 1].second < j;\n\
    \        }\n    }\n\n    // \u7A7A\u5217\u3001\u672B\u5C3E\u306E\u633F\u5165\u30FB\
    \u524A\u9664\u3001\u7570\u306A\u308B\u8981\u7D20\u578B\u3001\u30E9\u30F3\u30C0\
    \u30E0\u30A2\u30AF\u30BB\u30B9\u53EF\u80FD\u306A\u914D\u5217\u3002\n    for (const\
    \ std::string& s : {std::string{}, std::string(\"abc\"), std::string(\"aaaa\"\
    )}) {\n        for (const std::string& t : {std::string{}, std::string(\"xy\"\
    ), std::string(\"abcde\")}) {\n            ok = ok && check_restore(s, t);\n \
    \       }\n    }\n    ok = ok && check_restore(std::vector<int>{1, 2, 3}, std::vector<long\
    \ long>{2, 4, 3, 5});\n    int a[] = {1, 2, 3};\n    long long b[] = {2, 3};\n\
    \    ok = ok && check_restore(a, b);\n    ok = ok && edit_distance_restore(std::string(\"\
    abc\"), std::string(\"abc\")).operations.empty();\n\n    // \u4F8B\n    ok = ok\
    \ && edit_distance(std::string(\"kitten\"), std::string(\"sitting\")) == 3;\n\
    \    ok = ok && edit_distance(std::vector<int>{1, 2, 3}, std::vector<int>{2, 3,\
    \ 4}) == 2;\n    ok = ok && edit_distance(std::string(\"\"), std::string(\"abc\"\
    )) == 3;\n    ok = ok && longest_common_subsequence(std::string(\"abcbdab\"),\
    \ std::string(\"bdcaba\")) == 4;\n    ok = ok && longest_common_subsequence(std::vector<int>{1,\
    \ 2, 3}, std::vector<long long>{3, 1, 2}) == 2;\n    ok = ok && longest_common_subsequence_restore(std::string(\"\
    \"), std::string(\"abc\")).indices.empty();\n\n    if (ok)\n        std::cout\
    \ << \"Hello World\" << std::endl;\n    else {\n        std::cerr << \"failed\"\
    \ << std::endl;\n        return 1;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// edit_distance \u3068 longest_common_subsequence\u3001\u305D\u306E\u5FA9\
    \u5143\u3092\u3001\u518D\u5E30\u306B\u3088\u308B\u611A\u76F4\u306A\u65B9\u6CD5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/dp/edit-distance.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <iterator>\n#include <random>\n\
    #include <string>\n#include <vector>\n\n#include \"../../../src/dp/longest-common-subsequence.hpp\"\
    \n\n// s[i:] \u3068 t[j:] \u306E\u7DE8\u96C6\u8DDD\u96E2\nint naive_edit(const\
    \ std::string& s, const std::string& t, int i, int j) {\n    if (i == static_cast<int>(s.size()))\
    \ return t.size() - j;\n    if (j == static_cast<int>(t.size())) return s.size()\
    \ - i;\n    int res = naive_edit(s, t, i + 1, j + 1) + (s[i] != t[j]);\n    res\
    \ = std::min(res, naive_edit(s, t, i + 1, j) + 1);\n    res = std::min(res, naive_edit(s,\
    \ t, i, j + 1) + 1);\n    return res;\n}\n\n// s[i:] \u3068 t[j:] \u306E LCS \u306E\
    \u9577\u3055\nint naive_lcs(const std::string& s, const std::string& t, int i,\
    \ int j) {\n    if (i == static_cast<int>(s.size()) || j == static_cast<int>(t.size()))\
    \ return 0;\n    int res = std::max(naive_lcs(s, t, i + 1, j), naive_lcs(s, t,\
    \ i, j + 1));\n    if (s[i] == t[j]) res = std::max(res, naive_lcs(s, t, i + 1,\
    \ j + 1) + 1);\n    return res;\n}\n\n// \u8FD4\u3055\u308C\u305F\u64CD\u4F5C\u3092\
    \u5B9F\u969B\u306B\u9069\u7528\u3057\u3001\u5143\u306E\u5217\u306E\u6DFB\u5B57\
    \u3068\u76EE\u6A19\u306E\u6DFB\u5B57\u306E\u6574\u5408\u6027\u3082\u78BA\u304B\
    \u3081\u308B\u3002\ntemplate <class R1, class R2>\nbool check_restore(const R1&\
    \ s, const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n\
    \    const long long n = std::end(s) - a, m = std::end(t) - b;\n    const auto\
    \ result = edit_distance_restore(s, t);\n    if (result.distance != edit_distance(s,\
    \ t) || result.distance != static_cast<long long>(result.operations.size())) return\
    \ false;\n    using T = typename std::iterator_traits<decltype(a)>::value_type;\n\
    \    std::vector<T> current(a, std::end(s));\n    long long consumed = 0;\n  \
    \  for (const auto& operation : result.operations) {\n        auto [type, source,\
    \ target] = operation;\n        if (source < consumed || source > n || target\
    \ < 0 || target > static_cast<long long>(current.size())) return false;\n    \
    \    if (type == EditDistance::Type::Insert) {\n            if (target >= m) return\
    \ false;\n            current.insert(current.begin() + target, b[target]);\n \
    \           consumed = source;\n        } else {\n            if (source >= n\
    \ || target >= static_cast<long long>(current.size()) || current[target] != a[source])\
    \ return false;\n            if (type == EditDistance::Type::Erase) {\n      \
    \          if (target > m) return false;\n                current.erase(current.begin()\
    \ + target);\n            } else {\n                if (target >= m) return false;\n\
    \                current[target] = b[target];\n            }\n            consumed\
    \ = source + 1;\n        }\n    }\n    return std::equal(current.begin(), current.end(),\
    \ b, std::end(t));\n}\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok\
    \ = true;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng()\
    \ % 8, m = rng() % 8;\n        int k = rng() % 3 + 1;\n        std::string s(n,\
    \ 'a'), t(m, 'a');\n        for (auto& c : s) c = 'a' + rng() % k;\n        for\
    \ (auto& c : t) c = 'a' + rng() % k;\n\n        ok = ok && edit_distance(s, t)\
    \ == naive_edit(s, t, 0, 0);\n        ok = ok && check_restore(s, t);\n      \
    \  int len = naive_lcs(s, t, 0, 0);\n        ok = ok && longest_common_subsequence(s,\
    \ t) == len;\n\n        // \u5FA9\u5143: \u9577\u3055\u304C\u6700\u9577\u3067\u3001\
    \u6DFB\u5B57\u304C\u4E21\u65B9\u3068\u3082\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\
    \u3057\u3001\u8981\u7D20\u304C\u4E00\u81F4\u3059\u308B\n        auto [length,\
    \ idx] = longest_common_subsequence_restore(s, t);\n        ok = ok && length\
    \ == len && static_cast<int>(idx.size()) == len;\n        for (int p = 0; p <\
    \ static_cast<int>(idx.size()) && ok; p++) {\n            auto [i, j] = idx[p];\n\
    \            ok = 0 <= i && i < n && 0 <= j && j < m && s[i] == t[j];\n      \
    \      if (p > 0) ok = ok && idx[p - 1].first < i && idx[p - 1].second < j;\n\
    \        }\n    }\n\n    // \u7A7A\u5217\u3001\u672B\u5C3E\u306E\u633F\u5165\u30FB\
    \u524A\u9664\u3001\u7570\u306A\u308B\u8981\u7D20\u578B\u3001\u30E9\u30F3\u30C0\
    \u30E0\u30A2\u30AF\u30BB\u30B9\u53EF\u80FD\u306A\u914D\u5217\u3002\n    for (const\
    \ std::string& s : {std::string{}, std::string(\"abc\"), std::string(\"aaaa\"\
    )}) {\n        for (const std::string& t : {std::string{}, std::string(\"xy\"\
    ), std::string(\"abcde\")}) {\n            ok = ok && check_restore(s, t);\n \
    \       }\n    }\n    ok = ok && check_restore(std::vector<int>{1, 2, 3}, std::vector<long\
    \ long>{2, 4, 3, 5});\n    int a[] = {1, 2, 3};\n    long long b[] = {2, 3};\n\
    \    ok = ok && check_restore(a, b);\n    ok = ok && edit_distance_restore(std::string(\"\
    abc\"), std::string(\"abc\")).operations.empty();\n\n    // \u4F8B\n    ok = ok\
    \ && edit_distance(std::string(\"kitten\"), std::string(\"sitting\")) == 3;\n\
    \    ok = ok && edit_distance(std::vector<int>{1, 2, 3}, std::vector<int>{2, 3,\
    \ 4}) == 2;\n    ok = ok && edit_distance(std::string(\"\"), std::string(\"abc\"\
    )) == 3;\n    ok = ok && longest_common_subsequence(std::string(\"abcbdab\"),\
    \ std::string(\"bdcaba\")) == 4;\n    ok = ok && longest_common_subsequence(std::vector<int>{1,\
    \ 2, 3}, std::vector<long long>{3, 1, 2}) == 2;\n    ok = ok && longest_common_subsequence_restore(std::string(\"\
    \"), std::string(\"abc\")).indices.empty();\n\n    if (ok)\n        std::cout\
    \ << \"Hello World\" << std::endl;\n    else {\n        std::cerr << \"failed\"\
    \ << std::endl;\n        return 1;\n    }\n}\n"
  dependsOn:
  - src/dp/edit-distance.hpp
  - src/dp/longest-common-subsequence.hpp
  isVerificationFile: true
  path: test/unittest/dp/edit-distance.test.cpp
  requiredBy: []
  timestamp: '2026-11-08 23:25:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/dp/edit-distance.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/dp/edit-distance.test.cpp
- /verify/test/unittest/dp/edit-distance.test.cpp.html
title: test/unittest/dp/edit-distance.test.cpp
---
