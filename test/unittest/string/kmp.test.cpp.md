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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/string/kmp.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// prefix_function\u3001\
    kmp_search \u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/string/kmp.hpp\"\n\n/**\n * @file kmp.hpp\n\
    \ * @brief \u63A5\u982D\u8F9E\u95A2\u6570\u3068 KMP \u6CD5\n */\n\n#include <cstddef>\n\
    #include <iterator>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u63A5\
    \u982D\u8F9E\u95A2\u6570 (KMP \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n * s[0, i]\
    \ \u306E\u63A5\u982D\u8F9E\u3067\u3042\u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\
    \u308B\u90E8\u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\u304F) \u306E\u6700\u9577\
    \u306E\u9577\u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\
    \u4F53\u3067 O(N)\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\
    \u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\
    \u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n * @return std::vector<long long> pi\n */\ntemplate <typename It>\nstd::vector<long\
    \ long> prefix_function(It begin, It end) {\n    long long n = end - begin;\n\
    \    std::vector<long long> pi(n);\n    for (long long i = 1; i < n; i++) {\n\
    \        long long j = pi[i - 1];\n        while (j > 0 && !(begin[i] == begin[j]))\
    \ j = pi[j - 1];\n        if (begin[i] == begin[j]) j++;\n        pi[i] = j;\n\
    \    }\n    return pi;\n}\n\n/**\n * @brief \u63A5\u982D\u8F9E\u95A2\u6570 (KMP\
    \ \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n * s[0, i] \u306E\u63A5\u982D\u8F9E\u3067\
    \u3042\u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\u308B\u90E8\u5206 (s[0, i] \u81EA\
    \u8EAB\u3092\u9664\u304F) \u306E\u6700\u9577\u306E\u9577\u3055\u3092\u5404 i \u306B\
    \u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n * @tparam R\
    \ \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\n * @return std::vector<long\
    \ long> pi\n */\ntemplate <typename R>\nstd::vector<long long> prefix_function(const\
    \ R& s) {\n    return prefix_function(std::begin(s), std::end(s));\n}\n\nnamespace\
    \ internal_kmp {\ntemplate <typename Text, typename Pattern>\nclass Matches {\n\
    \    Text text;\n    Pattern pattern;\n    std::vector<long long> pi;\n    long\
    \ long n, m;\n\n   public:\n    Matches(Text&& text, Pattern&& pattern)\n    \
    \    : text(std::forward<Text>(text)), pattern(std::forward<Pattern>(pattern)),\
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
    \ std::forward<R2>(pattern));\n}\n#line 7 \"test/unittest/string/kmp.test.cpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <random>\n#include <string>\n\
    #line 13 \"test/unittest/string/kmp.test.cpp\"\n#if __cplusplus >= 202002L\n#include\
    \ <ranges>\n#endif\n\ntemplate <class R>\nstd::vector<long long> collect(const\
    \ R& matches) {\n    return {matches.begin(), matches.end()};\n}\n\nint main()\
    \ {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int rep = 0; rep\
    \ < 5000 && ok; rep++) {\n        int n = rng() % 30;\n        int k = rng() %\
    \ 3 + 1;\n        std::string s(n, 'a');\n        for (auto& c : s) c = 'a' +\
    \ rng() % k;\n\n        std::vector<long long> pi(n);\n        for (int i = 0;\
    \ i < n; i++) {\n            for (int l = 1; l <= i; l++) {\n                if\
    \ (s.substr(0, l) == s.substr(i + 1 - l, l)) pi[i] = l;\n            }\n     \
    \   }\n        ok = ok && prefix_function(s) == pi && prefix_function(s.begin(),\
    \ s.end()) == pi;\n\n        int m = rng() % 4;\n        std::string p(m, 'a');\n\
    \        for (auto& c : p) c = 'a' + rng() % k;\n        std::vector<long long>\
    \ occ;\n        for (int i = 0; i + m <= n; i++) {\n            if (s.substr(i,\
    \ m) == p) occ.push_back(i);\n        }\n        ok = ok && collect(kmp_search(s,\
    \ p)) == occ;\n    }\n\n    // \u4F8B\n    ok = ok && prefix_function(std::string(\"\
    aabaaab\")) == std::vector<long long>{0, 1, 0, 1, 2, 2, 3};\n    ok = ok && collect(kmp_search(std::string(\"\
    aaaa\"), std::string(\"aa\"))) == std::vector<long long>{0, 1, 2};\n    ok = ok\
    \ && collect(kmp_search(std::vector<int>{1, 2, 1, 2, 1}, std::vector<int>{1, 2,\
    \ 1})) == std::vector<long long>{0, 2};\n\n    // \u5931\u6557\u30EA\u30F3\u30AF\
    \u3092\u4F55\u6BB5\u3082\u623B\u308B\u5834\u5408\u3068\u3001\u91CD\u306A\u308A\
    \u306E\u3042\u308B\u4E00\u81F4\u3092\u542B\u3080\u4E8C\u5024\u5217\u306E\u5168\
    \u63A2\u7D22\u3002\n    for (long long n = 0; n <= 8; n++) {\n        for (long\
    \ long mask = 0; mask < (1LL << n); mask++) {\n            std::string text(n,\
    \ 'a');\n            for (long long i = 0; i < n; i++) text[i] += (mask >> i)\
    \ & 1;\n            for (long long m = 0; m <= 5; m++) {\n                for\
    \ (long long bits = 0; bits < (1LL << m); bits++) {\n                    std::string\
    \ pattern(m, 'a');\n                    for (long long i = 0; i < m; i++) pattern[i]\
    \ += (bits >> i) & 1;\n                    std::vector<long long> expected;\n\
    \                    for (long long i = 0; i + m <= n; i++) {\n              \
    \          if (text.compare(i, m, pattern) == 0) expected.push_back(i);\n    \
    \                }\n                    ok = ok && collect(kmp_search(text, pattern))\
    \ == expected;\n                }\n            }\n        }\n    }\n\n    // \u7A7A\
    \u306E\u30D1\u30BF\u30FC\u30F3\u30FB\u7A7A\u306E\u5165\u529B\u30FB\u4E00\u81F4\
    \u306A\u3057\u30FB\u30D1\u30BF\u30FC\u30F3\u306E\u65B9\u304C\u9577\u3044\u5834\
    \u5408\u3002\n    ok = ok && collect(kmp_search(std::string(), std::string()))\
    \ == std::vector<long long>{0};\n    ok = ok && collect(kmp_search(std::string(\"\
    ab\"), std::string())) == std::vector<long long>{0, 1, 2};\n    ok = ok && collect(kmp_search(std::string(),\
    \ std::string(\"a\"))).empty();\n    ok = ok && collect(kmp_search(std::string(\"\
    a\"), std::string(\"aa\"))).empty();\n    ok = ok && collect(kmp_search(std::string(\"\
    aaaa\"), std::string(\"b\"))).empty();\n\n    // range \u304C\u4E00\u6642\u5165\
    \u529B\u3092\u6240\u6709\u3057\u3001\u30B3\u30D4\u30FC\u30FB\u79FB\u52D5\u5F8C\
    \u3082\u81EA\u5206\u306E\u5165\u529B\u3092\u8D70\u67FB\u3059\u308B\u3002\n   \
    \ {\n        auto make_matches = [] { return kmp_search(std::string(\"aaaa\"),\
    \ std::string(\"aa\")); };\n        const auto matches = make_matches();\n   \
    \     auto copied = matches;\n        auto moved = std::move(copied);\n      \
    \  const std::vector<long long> expected = {0, 1, 2};\n        for (int rep =\
    \ 0; rep < 2; rep++) {\n            ok = ok && collect(matches) == expected &&\
    \ collect(moved) == expected;\n        }\n        auto it = matches.begin(), independent\
    \ = it;\n        ok = ok && *it++ == 0 && *it == 1 && *independent == 0;\n   \
    \     long long pairs = 0;\n        for (long long x : matches) {\n          \
    \  for (long long y : matches) pairs += x == y;\n        }\n        ok = ok &&\
    \ pairs == 3;\n#if __cplusplus >= 202002L\n        static_assert(std::ranges::input_range<decltype(matches)>);\n\
    #endif\n    }\n    // \u5DE6\u8FBA\u5024\u3092\u30B3\u30D4\u30FC\u3057\u306A\u3044\
    \u3002\u4E00\u6642\u5165\u529B\u306F move-only \u306A\u578B\u3067\u3082\u6240\u6709\
    \u3067\u304D\u308B\u3002\n    {\n        struct Series {\n            std::vector<char>\
    \ values;\n            explicit Series(const std::string& s) : values(s.begin(),\
    \ s.end()) {}\n            Series(const Series&) = delete;\n            Series(Series&&)\
    \ = default;\n            auto begin() const { return values.begin(); }\n    \
    \        auto end() const { return values.end(); }\n        };\n        const\
    \ Series text(\"ababab\"), pattern(\"aba\");\n        ok = ok && collect(kmp_search(text,\
    \ pattern)) == std::vector<long long>{0, 2};\n        auto matches = kmp_search(Series(\"\
    ababab\"), Series(\"aba\"));\n        auto moved = std::move(matches);\n     \
    \   ok = ok && collect(moved) == std::vector<long long>{0, 2};\n    }\n    //\
    \ \u69CB\u7BC9\u6642\u306F text \u3092\u8AAD\u307E\u305A\u3001\u6700\u521D\u306E\
    \u4E00\u81F4\u3067\u7D42\u4E86\u3059\u308B\u3068\u5F8C\u308D\u3092\u6BD4\u8F03\
    \u3057\u306A\u3044\u3002\n    {\n        struct Character {\n            long\
    \ long* reads;\n            bool operator==(char c) const {\n                ++*reads;\n\
    \                return c == 'a';\n            }\n        };\n        long long\
    \ reads = 0;\n        const std::vector<Character> text(100, Character{&reads});\n\
    \        const auto matches = kmp_search(text, std::string(\"a\"));\n        ok\
    \ = ok && reads == 0;\n        for (long long pos : matches) {\n            ok\
    \ = ok && pos == 0;\n            break;\n        }\n        ok = ok && reads ==\
    \ 1;\n    }\n    assert(ok);\n\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// prefix_function\u3001kmp_search \u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\
    \u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/string/kmp.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <random>\n#include <string>\n\
    #include <vector>\n#if __cplusplus >= 202002L\n#include <ranges>\n#endif\n\ntemplate\
    \ <class R>\nstd::vector<long long> collect(const R& matches) {\n    return {matches.begin(),\
    \ matches.end()};\n}\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok\
    \ = true;\n    for (int rep = 0; rep < 5000 && ok; rep++) {\n        int n = rng()\
    \ % 30;\n        int k = rng() % 3 + 1;\n        std::string s(n, 'a');\n    \
    \    for (auto& c : s) c = 'a' + rng() % k;\n\n        std::vector<long long>\
    \ pi(n);\n        for (int i = 0; i < n; i++) {\n            for (int l = 1; l\
    \ <= i; l++) {\n                if (s.substr(0, l) == s.substr(i + 1 - l, l))\
    \ pi[i] = l;\n            }\n        }\n        ok = ok && prefix_function(s)\
    \ == pi && prefix_function(s.begin(), s.end()) == pi;\n\n        int m = rng()\
    \ % 4;\n        std::string p(m, 'a');\n        for (auto& c : p) c = 'a' + rng()\
    \ % k;\n        std::vector<long long> occ;\n        for (int i = 0; i + m <=\
    \ n; i++) {\n            if (s.substr(i, m) == p) occ.push_back(i);\n        }\n\
    \        ok = ok && collect(kmp_search(s, p)) == occ;\n    }\n\n    // \u4F8B\n\
    \    ok = ok && prefix_function(std::string(\"aabaaab\")) == std::vector<long\
    \ long>{0, 1, 0, 1, 2, 2, 3};\n    ok = ok && collect(kmp_search(std::string(\"\
    aaaa\"), std::string(\"aa\"))) == std::vector<long long>{0, 1, 2};\n    ok = ok\
    \ && collect(kmp_search(std::vector<int>{1, 2, 1, 2, 1}, std::vector<int>{1, 2,\
    \ 1})) == std::vector<long long>{0, 2};\n\n    // \u5931\u6557\u30EA\u30F3\u30AF\
    \u3092\u4F55\u6BB5\u3082\u623B\u308B\u5834\u5408\u3068\u3001\u91CD\u306A\u308A\
    \u306E\u3042\u308B\u4E00\u81F4\u3092\u542B\u3080\u4E8C\u5024\u5217\u306E\u5168\
    \u63A2\u7D22\u3002\n    for (long long n = 0; n <= 8; n++) {\n        for (long\
    \ long mask = 0; mask < (1LL << n); mask++) {\n            std::string text(n,\
    \ 'a');\n            for (long long i = 0; i < n; i++) text[i] += (mask >> i)\
    \ & 1;\n            for (long long m = 0; m <= 5; m++) {\n                for\
    \ (long long bits = 0; bits < (1LL << m); bits++) {\n                    std::string\
    \ pattern(m, 'a');\n                    for (long long i = 0; i < m; i++) pattern[i]\
    \ += (bits >> i) & 1;\n                    std::vector<long long> expected;\n\
    \                    for (long long i = 0; i + m <= n; i++) {\n              \
    \          if (text.compare(i, m, pattern) == 0) expected.push_back(i);\n    \
    \                }\n                    ok = ok && collect(kmp_search(text, pattern))\
    \ == expected;\n                }\n            }\n        }\n    }\n\n    // \u7A7A\
    \u306E\u30D1\u30BF\u30FC\u30F3\u30FB\u7A7A\u306E\u5165\u529B\u30FB\u4E00\u81F4\
    \u306A\u3057\u30FB\u30D1\u30BF\u30FC\u30F3\u306E\u65B9\u304C\u9577\u3044\u5834\
    \u5408\u3002\n    ok = ok && collect(kmp_search(std::string(), std::string()))\
    \ == std::vector<long long>{0};\n    ok = ok && collect(kmp_search(std::string(\"\
    ab\"), std::string())) == std::vector<long long>{0, 1, 2};\n    ok = ok && collect(kmp_search(std::string(),\
    \ std::string(\"a\"))).empty();\n    ok = ok && collect(kmp_search(std::string(\"\
    a\"), std::string(\"aa\"))).empty();\n    ok = ok && collect(kmp_search(std::string(\"\
    aaaa\"), std::string(\"b\"))).empty();\n\n    // range \u304C\u4E00\u6642\u5165\
    \u529B\u3092\u6240\u6709\u3057\u3001\u30B3\u30D4\u30FC\u30FB\u79FB\u52D5\u5F8C\
    \u3082\u81EA\u5206\u306E\u5165\u529B\u3092\u8D70\u67FB\u3059\u308B\u3002\n   \
    \ {\n        auto make_matches = [] { return kmp_search(std::string(\"aaaa\"),\
    \ std::string(\"aa\")); };\n        const auto matches = make_matches();\n   \
    \     auto copied = matches;\n        auto moved = std::move(copied);\n      \
    \  const std::vector<long long> expected = {0, 1, 2};\n        for (int rep =\
    \ 0; rep < 2; rep++) {\n            ok = ok && collect(matches) == expected &&\
    \ collect(moved) == expected;\n        }\n        auto it = matches.begin(), independent\
    \ = it;\n        ok = ok && *it++ == 0 && *it == 1 && *independent == 0;\n   \
    \     long long pairs = 0;\n        for (long long x : matches) {\n          \
    \  for (long long y : matches) pairs += x == y;\n        }\n        ok = ok &&\
    \ pairs == 3;\n#if __cplusplus >= 202002L\n        static_assert(std::ranges::input_range<decltype(matches)>);\n\
    #endif\n    }\n    // \u5DE6\u8FBA\u5024\u3092\u30B3\u30D4\u30FC\u3057\u306A\u3044\
    \u3002\u4E00\u6642\u5165\u529B\u306F move-only \u306A\u578B\u3067\u3082\u6240\u6709\
    \u3067\u304D\u308B\u3002\n    {\n        struct Series {\n            std::vector<char>\
    \ values;\n            explicit Series(const std::string& s) : values(s.begin(),\
    \ s.end()) {}\n            Series(const Series&) = delete;\n            Series(Series&&)\
    \ = default;\n            auto begin() const { return values.begin(); }\n    \
    \        auto end() const { return values.end(); }\n        };\n        const\
    \ Series text(\"ababab\"), pattern(\"aba\");\n        ok = ok && collect(kmp_search(text,\
    \ pattern)) == std::vector<long long>{0, 2};\n        auto matches = kmp_search(Series(\"\
    ababab\"), Series(\"aba\"));\n        auto moved = std::move(matches);\n     \
    \   ok = ok && collect(moved) == std::vector<long long>{0, 2};\n    }\n    //\
    \ \u69CB\u7BC9\u6642\u306F text \u3092\u8AAD\u307E\u305A\u3001\u6700\u521D\u306E\
    \u4E00\u81F4\u3067\u7D42\u4E86\u3059\u308B\u3068\u5F8C\u308D\u3092\u6BD4\u8F03\
    \u3057\u306A\u3044\u3002\n    {\n        struct Character {\n            long\
    \ long* reads;\n            bool operator==(char c) const {\n                ++*reads;\n\
    \                return c == 'a';\n            }\n        };\n        long long\
    \ reads = 0;\n        const std::vector<Character> text(100, Character{&reads});\n\
    \        const auto matches = kmp_search(text, std::string(\"a\"));\n        ok\
    \ = ok && reads == 0;\n        for (long long pos : matches) {\n            ok\
    \ = ok && pos == 0;\n            break;\n        }\n        ok = ok && reads ==\
    \ 1;\n    }\n    assert(ok);\n\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/string/kmp.hpp
  isVerificationFile: true
  path: test/unittest/string/kmp.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 03:47:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/string/kmp.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/string/kmp.test.cpp
- /verify/test/unittest/string/kmp.test.cpp.html
title: test/unittest/string/kmp.test.cpp
---
