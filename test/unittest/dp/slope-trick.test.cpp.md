---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/slope-trick.hpp
    title: Slope Trick
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
  bundledCode: "#line 1 \"test/unittest/dp/slope-trick.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ slope-trick.hpp \u306E SlopeTrick \u3092\u3001\u6574\u6570\u70B9 [-W, W] \u3067\
    \u306E\u95A2\u6570\u306E\u5024\u306E\u8868\u3067\u611A\u76F4\u306B\u6C42\u3081\
    \u305F\u3082\u306E\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// \u8868\
    \u306E\u7AEF\u306E\u8FD1\u304F\u306F\u5E73\u884C\u79FB\u52D5\u3067\u7A93\u304C\
    \u306F\u307F\u51FA\u3057\u3066\u6B63\u3057\u304F\u306A\u304F\u306A\u308B\u304C\
    \u3001\u50BE\u304D\u306F\u5DE6\u5074\u3067 0 \u4EE5\u4E0B\u3001\u53F3\u5074\u3067\
    \ 0 \u4EE5\u4E0A\u306A\u306E\u3067\u3001\u5185\u5074\u306E\u5024\u306B\u306F\u97FF\
    \u304B\u306A\u3044\n// \u3042\u308F\u305B\u3066\u3001\u5217\u3092\u975E\u6E1B\u5C11\
    \u306B\u3059\u308B\u6700\u5C0F\u30B3\u30B9\u30C8 \u03A3|a_i - b_i| \u3092\u3001\
    \u5024\u306E\u7BC4\u56F2\u3067\u306E DP \u3068\u6BD4\u3079\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/dp/slope-trick.hpp\"\
    \n\n/**\n * @file slope-trick.hpp\n * @brief Slope Trick\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <limits>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief \u51F8\u306A\u533A\u5206\
    \u7DDA\u5F62\u95A2\u6570 f \u3092\u3001\u50BE\u304D\u304C\u5909\u308F\u308B\u70B9\
    \u306E\u591A\u91CD\u96C6\u5408\u3068\u3057\u3066\u6301\u3064 (Slope Trick)\n *\n\
    \ * \u6700\u5C0F\u5024\u3092\u3068\u308B\u533A\u9593\u3088\u308A\u5DE6\u306E\u70B9\
    \u3092 L (\u6700\u5927\u30D2\u30FC\u30D7)\u3001\u53F3\u306E\u70B9\u3092 R (\u6700\
    \u5C0F\u30D2\u30FC\u30D7) \u306B\u5165\u308C\u3001\u5E73\u884C\u79FB\u52D5\u306F\
    \u307E\u3068\u3081\u3066\u8DB3\u3059\n * \u306F\u3058\u3081\u306F f(x) = 0\n *\
    \ \u4F8B:\n * SlopeTrick<long long> st;\n * for (long long a : A) {\n *     st.prefix_min();\
    \  // \u975E\u6E1B\u5C11\u306B\u3059\u308B\u306E\u3067\u3001\u524D\u306E\u5024\
    \u4EE5\u4E0B\u306A\u3089\u3069\u3053\u3067\u3082\u3088\u3044\n *     st.add_abs(a);\n\
    \ * }\n * long long cost = st.min();\n *\n * @tparam T \u5024\u306E\u578B (\u7B26\
    \u53F7\u4ED8\u304D\u6574\u6570)\n */\ntemplate <typename T>\nclass SlopeTrick\
    \ {\n    T min_f = 0, add_l = 0, add_r = 0;\n    std::priority_queue<T> L;\n \
    \   std::priority_queue<T, std::vector<T>, std::greater<T>> R;\n\n    void push_l(T\
    \ a) { L.push(a - add_l); }\n    void push_r(T a) { R.push(a - add_r); }\n   \
    \ T top_l() const { return L.empty() ? -inf() : L.top() + add_l; }\n    T top_r()\
    \ const { return R.empty() ? inf() : R.top() + add_r; }\n    T pop_l() {\n   \
    \     T a = top_l();\n        L.pop();\n        return a;\n    }\n    T pop_r()\
    \ {\n        T a = top_r();\n        R.pop();\n        return a;\n    }\n\n  \
    \ public:\n    /**\n     * @brief \u50BE\u304D\u304C\u5909\u308F\u3089\u306A\u3044\
    \u5074\u306E\u7AEF\u3092\u8868\u3059\u5024 std::numeric_limits<T>::max() / 4\n\
    \     */\n    static constexpr T inf() { return std::numeric_limits<T>::max()\
    \ / 4; }\n\n    /**\n     * @brief f \u306E\u6700\u5C0F\u5024\n     */\n    T\
    \ min() const { return min_f; }\n    /**\n     * @brief f \u304C\u6700\u5C0F\u5024\
    \u3092\u3068\u308B\u533A\u9593 [lower, upper]\u3002\u7AEF\u304C\u306A\u3051\u308C\
    \u3070 -inf()\u3001inf()\n     */\n    std::pair<T, T> argmin() const { return\
    \ {top_l(), top_r()}; }\n    /**\n     * @brief f \u306B\u5B9A\u6570 a \u3092\u8DB3\
    \u3059\n     */\n    void add_constant(T a) { min_f += a; }\n    /**\n     * @brief\
    \ f \u306B max(0, x - a) \u3092\u8DB3\u3059 O(log n)\n     */\n    void add_x_minus_a(T\
    \ a) {\n        min_f += std::max(T(0), top_l() - a);\n        push_l(a);\n  \
    \      push_r(pop_l());\n    }\n    /**\n     * @brief f \u306B max(0, a - x)\
    \ \u3092\u8DB3\u3059 O(log n)\n     */\n    void add_a_minus_x(T a) {\n      \
    \  min_f += std::max(T(0), a - top_r());\n        push_r(a);\n        push_l(pop_r());\n\
    \    }\n    /**\n     * @brief f \u306B |x - a| \u3092\u8DB3\u3059 O(log n)\n\
    \     */\n    void add_abs(T a) {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n\
    \    }\n    /**\n     * @brief f(x) \u3092 min_{y <= x} f(y) \u306B\u3059\u308B\
    \ (\u53F3\u5074\u3092\u5E73\u3089\u306B\u3059\u308B) O(1)\n     */\n    void prefix_min()\
    \ { R = {}; }\n    /**\n     * @brief f(x) \u3092 min_{y >= x} f(y) \u306B\u3059\
    \u308B (\u5DE6\u5074\u3092\u5E73\u3089\u306B\u3059\u308B) O(1)\n     */\n    void\
    \ suffix_min() { L = {}; }\n    /**\n     * @brief f(x) \u3092 min_{x - b <= y\
    \ <= x - a} f(y) \u306B\u3059\u308B (\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\
    ) O(1)\n     *\n     * \u6700\u5C0F\u5024\u3092\u3068\u308B\u533A\u9593\u3088\u308A\
    \u5DE6\u3092 a\u3001\u53F3\u3092 b \u3060\u3051\u53F3\u306B\u305A\u3089\u3059\u3002\
    a <= b \u3067\u3042\u308B\u3053\u3068\n     */\n    void shift(T a, T b) {\n \
    \       assert(a <= b);\n        add_l += a, add_r += b;\n    }\n    /**\n   \
    \  * @brief f(x) \u3092 f(x - a) \u306B\u3059\u308B (a \u3060\u3051\u53F3\u306B\
    \u305A\u3089\u3059) O(1)\n     */\n    void shift(T a) { shift(a, a); }\n    /**\n\
    \     * @brief f(x) \u306E\u5024 O(n log n)\n     */\n    T get(T x) const {\n\
    \        T res = min_f;\n        for (auto l = L; !l.empty(); l.pop()) res +=\
    \ std::max(T(0), l.top() + add_l - x);\n        for (auto r = R; !r.empty(); r.pop())\
    \ res += std::max(T(0), x - (r.top() + add_r));\n        return res;\n    }\n\
    };\n#line 9 \"test/unittest/dp/slope-trick.test.cpp\"\n\n#line 11 \"test/unittest/dp/slope-trick.test.cpp\"\
    \n#include <iostream>\n#include <random>\n#line 14 \"test/unittest/dp/slope-trick.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    // \u50BE\
    \u304D\u304C\u5909\u308F\u308B\u70B9\u306F\u3001\u306F\u3058\u3081 [-10, 10] \u306B\
    \u3042\u308A\u3001\u5E73\u884C\u79FB\u52D5 1 \u56DE\u3067 4 \u4EE5\u4E0B\u3057\
    \u304B\u52D5\u304B\u306A\u3044\u306E\u3067 [-E, E] \u306B\u53CE\u307E\u308B\n\
    \    const int W = 200, E = 70;  // \u8868\u306E\u7BC4\u56F2\u3068\u3001\u5024\
    \u3092\u6BD4\u3079\u308B\u7BC4\u56F2\n    for (int rep = 0; rep < 3000 && ok;\
    \ rep++) {\n        SlopeTrick<long long> st;\n        std::vector<long long>\
    \ f(2 * W + 1, 0);  // f[x + W]\n        int q = rng() % 15 + 1;\n        for\
    \ (int i = 0; i < q; i++) {\n            int type = rng() % 8;\n            long\
    \ long a = static_cast<long long>(rng() % 21) - 10;\n            std::vector<long\
    \ long> g = f;\n            if (type == 0) {\n                st.add_constant(a);\n\
    \                for (auto& v : g) v += a;\n            } else if (type == 1)\
    \ {\n                st.add_x_minus_a(a);\n                for (int x = -W; x\
    \ <= W; x++) g[x + W] += std::max(0LL, x - a);\n            } else if (type ==\
    \ 2) {\n                st.add_a_minus_x(a);\n                for (int x = -W;\
    \ x <= W; x++) g[x + W] += std::max(0LL, a - x);\n            } else if (type\
    \ == 3) {\n                st.add_abs(a);\n                for (int x = -W; x\
    \ <= W; x++) g[x + W] += std::abs(x - a);\n            } else if (type == 4) {\n\
    \                st.prefix_min();\n                for (int x = -W + 1; x <= W;\
    \ x++) g[x + W] = std::min(g[x + W], g[x - 1 + W]);\n            } else if (type\
    \ == 5) {\n                st.suffix_min();\n                for (int x = W -\
    \ 1; x >= -W; x--) g[x + W] = std::min(g[x + W], g[x + 1 + W]);\n            }\
    \ else {\n                long long s = static_cast<long long>(rng() % 5) - 2,\
    \ t = s + (type == 6 ? 0 : rng() % 3);\n                if (type == 6)\n     \
    \               st.shift(s);\n                else\n                    st.shift(s,\
    \ t);\n                // g(x) = min_{x - t <= y <= x - s} f(y)\n            \
    \    for (int x = -W; x <= W; x++) {\n                    long long best = SlopeTrick<long\
    \ long>::inf();\n                    for (long long y = std::max<long long>(-W,\
    \ x - t); y <= std::min<long long>(W, x - s); y++) best = std::min(best, f[y +\
    \ W]);\n                    g[x + W] = best;\n                }\n            }\n\
    \            f = g;\n            for (int x = -E; x <= E; x++) {\n           \
    \     if (st.get(x) != f[x + W]) ok = false;\n            }\n            long\
    \ long mn = *std::min_element(f.begin(), f.end());\n            if (st.min() !=\
    \ mn) ok = false;\n            // \u6700\u5C0F\u5024\u3092\u3068\u308B\u533A\u9593\
    \u3002\u50BE\u304D\u304C\u5909\u308F\u308B\u70B9\u306F [-E, E] \u306B\u53CE\u307E\
    \u308B\u306E\u3067\u3001\u305D\u3053\u3092\u8D8A\u3048\u3066\u7D9A\u304F\u306A\
    \u3089\u3001\u305D\u306E\u5074\u306F\u7AEF\u304C\u306A\u3044\n            // (\u8868\
    \u306E\u7AEF\u306E\u8FD1\u304F\u306F\u5E73\u884C\u79FB\u52D5\u3067\u7A93\u304C\
    \u306F\u307F\u51FA\u3057\u3066\u6B63\u3057\u304F\u306A\u3044\u306E\u3067\u3001\
    [-E - 1, E + 1] \u3060\u3051\u3092\u898B\u308B)\n            int lo = -E - 1,\
    \ hi = E + 1;\n            while (lo <= E + 1 && f[lo + W] != mn) lo++;\n    \
    \        while (hi >= -E - 1 && f[hi + W] != mn) hi--;\n            auto [l, r]\
    \ = st.argmin();\n            if (lo == -E - 1 ? l != -SlopeTrick<long long>::inf()\
    \ : l != lo) ok = false;\n            if (hi == E + 1 ? r != SlopeTrick<long long>::inf()\
    \ : r != hi) ok = false;\n        }\n    }\n    // \u975E\u6E1B\u5C11\u306B\u3059\
    \u308B\u6700\u5C0F\u30B3\u30B9\u30C8\n    for (int rep = 0; rep < 1000 && ok;\
    \ rep++) {\n        int n = rng() % 8 + 1;\n        std::vector<long long> a(n);\n\
    \        for (auto& x : a) x = rng() % 10;\n        SlopeTrick<long long> st;\n\
    \        for (long long x : a) {\n            st.prefix_min();\n            st.add_abs(x);\n\
    \        }\n        // dp[v]: b \u306E\u6700\u5F8C\u304C v \u306E\u3068\u304D\u306E\
    \u6700\u5C0F\u30B3\u30B9\u30C8 (b \u306F 0 \u4EE5\u4E0A 9 \u4EE5\u4E0B\u306B\u3057\
    \u3066\u3088\u3044)\n        std::vector<long long> dp(10, 0);\n        for (long\
    \ long x : a) {\n            std::vector<long long> nd(10);\n            long\
    \ long best = SlopeTrick<long long>::inf();\n            for (int v = 0; v < 10;\
    \ v++) {\n                best = std::min(best, dp[v]);\n                nd[v]\
    \ = best + std::abs(x - v);\n            }\n            dp = nd;\n        }\n\
    \        if (st.min() != *std::min_element(dp.begin(), dp.end())) ok = false;\n\
    \    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// slope-trick.hpp \u306E SlopeTrick \u3092\u3001\u6574\u6570\u70B9 [-W, W]\
    \ \u3067\u306E\u95A2\u6570\u306E\u5024\u306E\u8868\u3067\u611A\u76F4\u306B\u6C42\
    \u3081\u305F\u3082\u306E\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\
    \n// \u8868\u306E\u7AEF\u306E\u8FD1\u304F\u306F\u5E73\u884C\u79FB\u52D5\u3067\u7A93\
    \u304C\u306F\u307F\u51FA\u3057\u3066\u6B63\u3057\u304F\u306A\u304F\u306A\u308B\
    \u304C\u3001\u50BE\u304D\u306F\u5DE6\u5074\u3067 0 \u4EE5\u4E0B\u3001\u53F3\u5074\
    \u3067 0 \u4EE5\u4E0A\u306A\u306E\u3067\u3001\u5185\u5074\u306E\u5024\u306B\u306F\
    \u97FF\u304B\u306A\u3044\n// \u3042\u308F\u305B\u3066\u3001\u5217\u3092\u975E\u6E1B\
    \u5C11\u306B\u3059\u308B\u6700\u5C0F\u30B3\u30B9\u30C8 \u03A3|a_i - b_i| \u3092\
    \u3001\u5024\u306E\u7BC4\u56F2\u3067\u306E DP \u3068\u6BD4\u3079\u308B\n// \u554F\
    \u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\
    \u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include\
    \ \"../../../src/dp/slope-trick.hpp\"\n\n#include <algorithm>\n#include <iostream>\n\
    #include <random>\n#include <vector>\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    bool ok = true;\n    // \u50BE\u304D\u304C\u5909\u308F\u308B\u70B9\u306F\u3001\
    \u306F\u3058\u3081 [-10, 10] \u306B\u3042\u308A\u3001\u5E73\u884C\u79FB\u52D5\
    \ 1 \u56DE\u3067 4 \u4EE5\u4E0B\u3057\u304B\u52D5\u304B\u306A\u3044\u306E\u3067\
    \ [-E, E] \u306B\u53CE\u307E\u308B\n    const int W = 200, E = 70;  // \u8868\u306E\
    \u7BC4\u56F2\u3068\u3001\u5024\u3092\u6BD4\u3079\u308B\u7BC4\u56F2\n    for (int\
    \ rep = 0; rep < 3000 && ok; rep++) {\n        SlopeTrick<long long> st;\n   \
    \     std::vector<long long> f(2 * W + 1, 0);  // f[x + W]\n        int q = rng()\
    \ % 15 + 1;\n        for (int i = 0; i < q; i++) {\n            int type = rng()\
    \ % 8;\n            long long a = static_cast<long long>(rng() % 21) - 10;\n \
    \           std::vector<long long> g = f;\n            if (type == 0) {\n    \
    \            st.add_constant(a);\n                for (auto& v : g) v += a;\n\
    \            } else if (type == 1) {\n                st.add_x_minus_a(a);\n \
    \               for (int x = -W; x <= W; x++) g[x + W] += std::max(0LL, x - a);\n\
    \            } else if (type == 2) {\n                st.add_a_minus_x(a);\n \
    \               for (int x = -W; x <= W; x++) g[x + W] += std::max(0LL, a - x);\n\
    \            } else if (type == 3) {\n                st.add_abs(a);\n       \
    \         for (int x = -W; x <= W; x++) g[x + W] += std::abs(x - a);\n       \
    \     } else if (type == 4) {\n                st.prefix_min();\n            \
    \    for (int x = -W + 1; x <= W; x++) g[x + W] = std::min(g[x + W], g[x - 1 +\
    \ W]);\n            } else if (type == 5) {\n                st.suffix_min();\n\
    \                for (int x = W - 1; x >= -W; x--) g[x + W] = std::min(g[x + W],\
    \ g[x + 1 + W]);\n            } else {\n                long long s = static_cast<long\
    \ long>(rng() % 5) - 2, t = s + (type == 6 ? 0 : rng() % 3);\n               \
    \ if (type == 6)\n                    st.shift(s);\n                else\n   \
    \                 st.shift(s, t);\n                // g(x) = min_{x - t <= y <=\
    \ x - s} f(y)\n                for (int x = -W; x <= W; x++) {\n             \
    \       long long best = SlopeTrick<long long>::inf();\n                    for\
    \ (long long y = std::max<long long>(-W, x - t); y <= std::min<long long>(W, x\
    \ - s); y++) best = std::min(best, f[y + W]);\n                    g[x + W] =\
    \ best;\n                }\n            }\n            f = g;\n            for\
    \ (int x = -E; x <= E; x++) {\n                if (st.get(x) != f[x + W]) ok =\
    \ false;\n            }\n            long long mn = *std::min_element(f.begin(),\
    \ f.end());\n            if (st.min() != mn) ok = false;\n            // \u6700\
    \u5C0F\u5024\u3092\u3068\u308B\u533A\u9593\u3002\u50BE\u304D\u304C\u5909\u308F\
    \u308B\u70B9\u306F [-E, E] \u306B\u53CE\u307E\u308B\u306E\u3067\u3001\u305D\u3053\
    \u3092\u8D8A\u3048\u3066\u7D9A\u304F\u306A\u3089\u3001\u305D\u306E\u5074\u306F\
    \u7AEF\u304C\u306A\u3044\n            // (\u8868\u306E\u7AEF\u306E\u8FD1\u304F\
    \u306F\u5E73\u884C\u79FB\u52D5\u3067\u7A93\u304C\u306F\u307F\u51FA\u3057\u3066\
    \u6B63\u3057\u304F\u306A\u3044\u306E\u3067\u3001[-E - 1, E + 1] \u3060\u3051\u3092\
    \u898B\u308B)\n            int lo = -E - 1, hi = E + 1;\n            while (lo\
    \ <= E + 1 && f[lo + W] != mn) lo++;\n            while (hi >= -E - 1 && f[hi\
    \ + W] != mn) hi--;\n            auto [l, r] = st.argmin();\n            if (lo\
    \ == -E - 1 ? l != -SlopeTrick<long long>::inf() : l != lo) ok = false;\n    \
    \        if (hi == E + 1 ? r != SlopeTrick<long long>::inf() : r != hi) ok = false;\n\
    \        }\n    }\n    // \u975E\u6E1B\u5C11\u306B\u3059\u308B\u6700\u5C0F\u30B3\
    \u30B9\u30C8\n    for (int rep = 0; rep < 1000 && ok; rep++) {\n        int n\
    \ = rng() % 8 + 1;\n        std::vector<long long> a(n);\n        for (auto& x\
    \ : a) x = rng() % 10;\n        SlopeTrick<long long> st;\n        for (long long\
    \ x : a) {\n            st.prefix_min();\n            st.add_abs(x);\n       \
    \ }\n        // dp[v]: b \u306E\u6700\u5F8C\u304C v \u306E\u3068\u304D\u306E\u6700\
    \u5C0F\u30B3\u30B9\u30C8 (b \u306F 0 \u4EE5\u4E0A 9 \u4EE5\u4E0B\u306B\u3057\u3066\
    \u3088\u3044)\n        std::vector<long long> dp(10, 0);\n        for (long long\
    \ x : a) {\n            std::vector<long long> nd(10);\n            long long\
    \ best = SlopeTrick<long long>::inf();\n            for (int v = 0; v < 10; v++)\
    \ {\n                best = std::min(best, dp[v]);\n                nd[v] = best\
    \ + std::abs(x - v);\n            }\n            dp = nd;\n        }\n       \
    \ if (st.min() != *std::min_element(dp.begin(), dp.end())) ok = false;\n    }\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/dp/slope-trick.hpp
  isVerificationFile: true
  path: test/unittest/dp/slope-trick.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 04:34:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/dp/slope-trick.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/dp/slope-trick.test.cpp
- /verify/test/unittest/dp/slope-trick.test.cpp.html
title: test/unittest/dp/slope-trick.test.cpp
---
