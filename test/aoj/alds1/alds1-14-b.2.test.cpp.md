---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/kmp.hpp
    title: "KMP \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/alds1/alds1-14-b.2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #include <iostream>\n#include <string>\n\n#line 2 \"src/string/kmp.hpp\"\n\n/**\n\
    \ * @file kmp.hpp\n * @brief \u63A5\u982D\u8F9E\u95A2\u6570\u3068 KMP \u6CD5\n\
    \ */\n\n#include <cstddef>\n#include <iterator>\n#include <utility>\n#include\
    \ <vector>\n\n/**\n * @brief \u63A5\u982D\u8F9E\u95A2\u6570 (KMP \u6CD5\u306E\u5931\
    \u6557\u95A2\u6570)\n * s[0, i] \u306E\u63A5\u982D\u8F9E\u3067\u3042\u308A\u63A5\
    \u5C3E\u8F9E\u3067\u3082\u3042\u308B\u90E8\u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\
    \u304F) \u306E\u6700\u9577\u306E\u9577\u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\
    \u6C42\u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n * @tparam It \u914D\u5217\u306E\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\
    \u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long long> pi\n */\ntemplate\
    \ <typename It>\nstd::vector<long long> prefix_function(It begin, It end) {\n\
    \    long long n = end - begin;\n    std::vector<long long> pi(n);\n    for (long\
    \ long i = 1; i < n; i++) {\n        long long j = pi[i - 1];\n        while (j\
    \ > 0 && !(begin[i] == begin[j])) j = pi[j - 1];\n        if (begin[i] == begin[j])\
    \ j++;\n        pi[i] = j;\n    }\n    return pi;\n}\n\n/**\n * @brief \u63A5\u982D\
    \u8F9E\u95A2\u6570 (KMP \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n * s[0, i] \u306E\
    \u63A5\u982D\u8F9E\u3067\u3042\u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\u308B\
    \u90E8\u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\u304F) \u306E\u6700\u9577\u306E\
    \u9577\u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\
    \u3067 O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\
    \n * @return std::vector<long long> pi\n */\ntemplate <typename R>\nstd::vector<long\
    \ long> prefix_function(const R& s) {\n    return prefix_function(std::begin(s),\
    \ std::end(s));\n}\n\nnamespace internal_kmp {\ntemplate <typename Text, typename\
    \ Pattern>\nclass Matches {\n    Text text;\n    Pattern pattern;\n    std::vector<long\
    \ long> pi;\n    long long n, m;\n\n   public:\n    Matches(Text&& text, Pattern&&\
    \ pattern)\n        : text(std::forward<Text>(text)), pattern(std::forward<Pattern>(pattern)),\
    \ pi(prefix_function(this->pattern)), n(std::end(std::as_const(this->text)) -\
    \ std::begin(std::as_const(this->text))), m(pi.size()) {}\n\n    class iterator\
    \ {\n        const Matches* range = nullptr;\n        long long i = 0, j = 0,\
    \ pos = -1;\n\n       public:\n        using value_type = long long;\n       \
    \ using difference_type = std::ptrdiff_t;\n        using reference = value_type;\n\
    \        using pointer = void;\n        using iterator_category = std::input_iterator_tag;\n\
    \n        iterator() = default;\n        explicit iterator(const Matches* range)\
    \ : range(range) { ++*this; }\n        value_type operator*() const { return pos;\
    \ }\n        iterator& operator++() {\n            if (range->m == 0) {\n    \
    \            pos = i;\n                i = i == range->n ? -1 : i + 1;\n     \
    \           return *this;\n            }\n            auto t = std::begin(std::as_const(range->text));\n\
    \            auto p = std::begin(std::as_const(range->pattern));\n           \
    \ while (i < range->n) {\n                while (j > 0 && !(t[i] == p[j])) j =\
    \ range->pi[j - 1];\n                if (t[i] == p[j]) j++;\n                i++;\n\
    \                if (j == range->m) {\n                    pos = i - range->m;\n\
    \                    j = range->pi[j - 1];\n                    return *this;\n\
    \                }\n            }\n            pos = -1;\n            return *this;\n\
    \        }\n        iterator operator++(int) {\n            auto previous = *this;\n\
    \            ++*this;\n            return previous;\n        }\n        bool operator==(const\
    \ iterator& other) const {\n            if (pos == -1 || other.pos == -1) return\
    \ pos == other.pos;\n            return range == other.range && pos == other.pos;\n\
    \        }\n        bool operator!=(const iterator& other) const { return !(*this\
    \ == other); }\n    };\n\n    iterator begin() const { return iterator(this);\
    \ }\n    iterator end() const { return iterator(); }\n};\n}  // namespace internal_kmp\n\
    \n/**\n * @brief KMP \u6CD5\u306B\u3088\u308B\u4E00\u81F4\u4F4D\u7F6E\u306E\u9045\
    \u5EF6\u5217\u6319\u3002\u69CB\u7BC9 O(|pattern|)\u3001\u5168\u8D70\u67FB O(|text|\
    \ + |pattern|)\u3001\u8FFD\u52A0\u9818\u57DF O(|pattern|)\n * pattern \u304C\u7A7A\
    \u306A\u3089 0, 1, ..., |text| \u3092\u8FD4\u3059\u3002\u5DE6\u8FBA\u5024\u306E\
    \u5165\u529B\u306F\u53C2\u7167\u3057\u3001\u53F3\u8FBA\u5024\u306F\u6240\u6709\
    \u3059\u308B\n * @pre \u4E21\u65B9\u306E\u5165\u529B\u306B\u30E9\u30F3\u30C0\u30E0\
    \u30A2\u30AF\u30BB\u30B9\u53EF\u80FD\u306A iterator \u304C\u3042\u308B\u3053\u3068\
    \n * @pre \u8D70\u67FB\u4E2D\u306F range \u3068\u53C2\u7167\u3059\u308B\u5165\u529B\
    \u3092\u6709\u52B9\u306A\u307E\u307E\u4FDD\u6301\u3057\u3001\u5909\u66F4\u3057\
    \u306A\u3044\u3053\u3068\n */\ntemplate <typename R1, typename R2>\nauto kmp_search(R1&&\
    \ text, R2&& pattern) {\n    return internal_kmp::Matches<R1, R2>(std::forward<R1>(text),\
    \ std::forward<R2>(pattern));\n}\n#line 7 \"test/aoj/alds1/alds1-14-b.2.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::string t, p;\n    std::cin >> t >> p;\n    for (long long i : kmp_search(t,\
    \ p)) std::cout << i << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../../../src/string/kmp.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::string t, p;\n    std::cin >> t >> p;\n    for (long long i : kmp_search(t,\
    \ p)) std::cout << i << '\\n';\n}\n"
  dependsOn:
  - src/string/kmp.hpp
  isVerificationFile: true
  path: test/aoj/alds1/alds1-14-b.2.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 03:47:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1/alds1-14-b.2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1/alds1-14-b.2.test.cpp
- /verify/test/aoj/alds1/alds1-14-b.2.test.cpp.html
title: test/aoj/alds1/alds1-14-b.2.test.cpp
---
