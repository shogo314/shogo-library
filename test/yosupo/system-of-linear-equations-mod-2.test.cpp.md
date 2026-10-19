---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/f2-matrix.hpp
    title: "F2 \u306E\u884C\u5217 (mod 2)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
  bundledCode: "#line 1 \"test/yosupo/system-of-linear-equations-mod-2.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#line 2 \"src/math/f2-matrix.hpp\"\
    \n\n/**\n * @file f2-matrix.hpp\n * @brief F2 (mod 2) \u306E\u884C\u5217\n */\n\
    \n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n#include <optional>\n\
    #include <ostream>\n#line 14 \"src/math/f2-matrix.hpp\"\n#include <utility>\n\
    #line 16 \"src/math/f2-matrix.hpp\"\n\n/**\n * @brief F2 (mod 2) \u306E\u884C\u5217\
    \n *\n * \u5404\u884C\u3092 64 bit \u305A\u3064\u8A70\u3081\u3066\u6301\u3061\u3001\
    \u8DB3\u3057\u7B97 (xor)\u30FB\u7A4D\u30FB\u6D88\u53BB\u3092 64 \u8981\u7D20\u305A\
    \u3064\u307E\u3068\u3081\u3066\u884C\u3046\n * \u30D9\u30AF\u30C8\u30EB\u306F\
    \ std::vector<bool> \u3067\u53D7\u3051\u6E21\u3059\n * \u4F8B:\n * F2Matrix A(std::vector<std::string>{\"\
    110\", \"011\"});\n * auto sol = A.solve({true, false});  // Ax = b\n * A.rank();\
    \ A.kernel();\n */\nclass F2Matrix {\n   public:\n    long long n, m;  //!< \u884C\
    \u6570\u3001\u5217\u6570\n\n   private:\n    long long w;                   //\
    \ 1 \u884C\u306E 64 bit \u306E\u500B\u6570\n    std::vector<std::uint64_t> a;\
    \  // a[i * w + j / 64] \u306E j % 64 bit \u76EE\u304C (i, j) \u6210\u5206 (\u884C\
    \u304C\u591A\u304F\u3066\u3082\u4F59\u8A08\u306A\u9818\u57DF\u3092\u4F7F\u308F\
    \u306A\u3044\u3088\u3046 1 \u672C\u306E\u914D\u5217\u306B\u3059\u308B)\n\n   \
    \ // h \u884C\u30011 \u884C width \u500B\u306E 64 bit \u306E\u914D\u5217 d \u3092\
    \u3001\u5148\u982D\u304B\u3089 cols \u5217\u3092\u4F7F\u3063\u3066\u7C21\u7D04\
    \u5316\u3057\u3001\u5404\u884C\u306E\u4E3B\u6210\u5206\u306E\u5217\u3092\u8FD4\
    \u3059\n    // (\u5217\u304C cols \u3088\u308A\u591A\u3044\u90E8\u5206\u3082\u4E00\
    \u7DD2\u306B\u5909\u5F62\u3059\u308B)\n    static std::vector<long long> reduce(std::vector<std::uint64_t>&\
    \ d, long long h, long long width, long long cols) {\n        std::vector<long\
    \ long> pivots;\n        for (long long c = 0, r = 0; c < cols && r < h; c++)\
    \ {\n            const long long q = c >> 6;\n            const std::uint64_t\
    \ bit = std::uint64_t(1) << (c & 63);\n            long long p = r;\n        \
    \    while (p < h && !(d[p * width + q] & bit)) p++;\n            if (p == h)\
    \ continue;\n            if (p != r) std::swap_ranges(d.begin() + r * width, d.begin()\
    \ + (r + 1) * width, d.begin() + p * width);\n            const std::uint64_t*\
    \ pr = d.data() + r * width;\n            for (long long i = 0; i < h; i++) {\n\
    \                std::uint64_t* row = d.data() + i * width;\n                if\
    \ (i == r || !(row[q] & bit)) continue;\n                for (long long k = q;\
    \ k < width; k++) row[k] ^= pr[k];\n            }\n            pivots.push_back(c);\n\
    \            r++;\n        }\n        return pivots;\n    }\n    static bool get_bit(const\
    \ std::vector<std::uint64_t>& d, long long width, long long i, long long j) {\
    \ return d[i * width + (j >> 6)] >> (j & 63) & 1; }\n    // \u7C21\u7D04\u5316\
    \u3057\u305F d (1 \u884C width \u500B\u3001\u5148\u982D m \u5217) \u304B\u3089\
    \u3001Ax = 0 \u306E\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u3092\u4F5C\u308B\n  \
    \  std::vector<std::vector<bool>> kernel_from_reduced(const std::vector<std::uint64_t>&\
    \ d, long long width, const std::vector<long long>& pivots) const {\n        std::vector<bool>\
    \ is_pivot(m, false);\n        for (long long c : pivots) is_pivot[c] = true;\n\
    \        std::vector<std::vector<bool>> res;\n        for (long long f = 0; f\
    \ < m; f++) {\n            if (is_pivot[f]) continue;\n            std::vector<bool>\
    \ x(m, false);\n            x[f] = true;\n            for (long long i = 0; i\
    \ < static_cast<long long>(pivots.size()); i++) x[pivots[i]] = get_bit(d, width,\
    \ i, f);\n            res.push_back(x);\n        }\n        return res;\n    }\n\
    \n   public:\n    /**\n     * @brief \u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F\
    \ Ax = b \u306E\u89E3\n     * \u89E3\u5168\u4F53\u306F x + (basis \u306E\u4E00\
    \u90E8\u306E xor)\n     */\n    struct Solution {\n        std::vector<bool> x;\
    \                   //!< \u89E3\u306E 1 \u3064 (\u7279\u6B8A\u89E3)\n        std::vector<std::vector<bool>>\
    \ basis;  //!< Ax = 0 \u306E\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\n    };\n\n \
    \   /**\n     * @brief 0 \u884C 0 \u5217\u306E\u884C\u5217\n     */\n    F2Matrix()\
    \ : F2Matrix(0, 0) {}\n    /**\n     * @brief n \u884C m \u5217\u306E\u96F6\u884C\
    \u5217\n     */\n    F2Matrix(long long n, long long m) : n(n), m(m), w((m + 63)\
    \ / 64), a(n * w, 0) {}\n    /**\n     * @brief '0' \u3068 '1' \u306E\u6587\u5B57\
    \u5217\u306E\u914D\u5217\u304B\u3089\u4F5C\u308B (\u5404\u6587\u5B57\u5217\u304C\
    \ 1 \u884C)\n     */\n    explicit F2Matrix(const std::vector<std::string>& s)\
    \ : F2Matrix(s.size(), s.empty() ? 0 : s[0].size()) {\n        for (long long\
    \ i = 0; i < n; i++) {\n            assert(static_cast<long long>(s[i].size())\
    \ == m);\n            for (long long j = 0; j < m; j++) set(i, j, s[i][j] == '1');\n\
    \        }\n    }\n    /**\n     * @brief \u6574\u6570\u306E 2 \u6B21\u5143\u914D\
    \u5217\u304B\u3089\u4F5C\u308B (\u5404\u6210\u5206\u306E\u5076\u5947)\n     */\n\
    \    explicit F2Matrix(const std::vector<std::vector<int>>& v) : F2Matrix(v.size(),\
    \ v.empty() ? 0 : v[0].size()) {\n        for (long long i = 0; i < n; i++) {\n\
    \            assert(static_cast<long long>(v[i].size()) == m);\n            for\
    \ (long long j = 0; j < m; j++) set(i, j, v[i][j] & 1);\n        }\n    }\n  \
    \  /**\n     * @brief n \u6B21\u306E\u5358\u4F4D\u884C\u5217\n     */\n    static\
    \ F2Matrix identity(long long n) {\n        F2Matrix I(n, n);\n        for (long\
    \ long i = 0; i < n; i++) I.set(i, i, true);\n        return I;\n    }\n\n   \
    \ /**\n     * @brief (i, j) \u6210\u5206\n     */\n    bool get(long long i, long\
    \ long j) const {\n        assert(0 <= i && i < n && 0 <= j && j < m);\n     \
    \   return get_bit(a, w, i, j);\n    }\n    /**\n     * @brief (i, j) \u6210\u5206\
    \u3092 x \u306B\u3059\u308B\n     */\n    void set(long long i, long long j, bool\
    \ x) {\n        assert(0 <= i && i < n && 0 <= j && j < m);\n        const std::uint64_t\
    \ bit = std::uint64_t(1) << (j & 63);\n        if (x) {\n            a[i * w +\
    \ (j >> 6)] |= bit;\n        } else {\n            a[i * w + (j >> 6)] &= ~bit;\n\
    \        }\n    }\n\n    friend bool operator==(const F2Matrix& A, const F2Matrix&\
    \ B) { return A.n == B.n && A.m == B.m && A.a == B.a; }\n    friend bool operator!=(const\
    \ F2Matrix& A, const F2Matrix& B) { return !(A == B); }\n\n    /**\n     * @brief\
    \ \u8DB3\u3057\u7B97 (\u6210\u5206\u3054\u3068\u306E xor) O(nm / 64)\n     */\n\
    \    F2Matrix& operator+=(const F2Matrix& B) {\n        assert(n == B.n && m ==\
    \ B.m);\n        for (size_t k = 0; k < a.size(); k++) a[k] ^= B.a[k];\n     \
    \   return *this;\n    }\n    friend F2Matrix operator+(F2Matrix A, const F2Matrix&\
    \ B) { return A += B; }\n    /**\n     * @brief \u7A4D O(nmk / 64) (k \u306F B\
    \ \u306E\u5217\u6570)\n     */\n    friend F2Matrix operator*(const F2Matrix&\
    \ A, const F2Matrix& B) {\n        assert(A.m == B.n);\n        F2Matrix C(A.n,\
    \ B.m);\n        for (long long i = 0; i < A.n; i++) {\n            std::uint64_t*\
    \ c = C.a.data() + i * C.w;\n            // A \u306E i \u884C\u76EE\u3067 1 \u306E\
    \u5217 j \u3054\u3068\u306B\u3001B \u306E j \u884C\u76EE\u3092\u8DB3\u3059\n \
    \           for (long long q = 0; q < A.w; q++) {\n                for (std::uint64_t\
    \ x = A.a[i * A.w + q]; x; x &= x - 1) {\n                    const std::uint64_t*\
    \ row = B.a.data() + ((q << 6) + __builtin_ctzll(x)) * B.w;\n                \
    \    for (long long k = 0; k < C.w; k++) c[k] ^= row[k];\n                }\n\
    \            }\n        }\n        return C;\n    }\n    F2Matrix& operator*=(const\
    \ F2Matrix& B) { return *this = *this * B; }\n    /**\n     * @brief \u884C\u5217\
    \u3068\u5217\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D O(nm / 64)\n     */\n    friend\
    \ std::vector<bool> operator*(const F2Matrix& A, const std::vector<bool>& x) {\n\
    \        assert(static_cast<long long>(x.size()) == A.m);\n        std::vector<std::uint64_t>\
    \ xb(A.w, 0);\n        for (long long j = 0; j < A.m; j++)\n            if (x[j])\
    \ xb[j >> 6] |= std::uint64_t(1) << (j & 63);\n        std::vector<bool> res(A.n);\n\
    \        for (long long i = 0; i < A.n; i++) {\n            std::uint64_t s =\
    \ 0;\n            for (long long k = 0; k < A.w; k++) s ^= A.a[i * A.w + k] &\
    \ xb[k];\n            res[i] = __builtin_parityll(s);\n        }\n        return\
    \ res;\n    }\n    /**\n     * @brief k \u4E57 (\u6B63\u65B9\u884C\u5217) O(n^3\
    \ / 64 log k)\n     */\n    F2Matrix pow(long long k) const {\n        assert(n\
    \ == m && k >= 0);\n        F2Matrix res = identity(n), b = *this;\n        for\
    \ (; k > 0; k >>= 1) {\n            if (k & 1) res *= b;\n            b *= b;\n\
    \        }\n        return res;\n    }\n    /**\n     * @brief \u8EE2\u7F6E O(nm)\n\
    \     */\n    F2Matrix transpose() const {\n        F2Matrix T(m, n);\n      \
    \  for (long long i = 0; i < n; i++)\n            for (long long j = 0; j < m;\
    \ j++)\n                if (get(i, j)) T.set(j, i, true);\n        return T;\n\
    \    }\n\n    /**\n     * @brief \u7C21\u7D04\u5316\u3057\u305F\u884C\u5217\u3068\
    \u3001\u5404\u884C\u306E\u4E3B\u6210\u5206\u306E\u5217 (\u500B\u6570\u304C\u30E9\
    \u30F3\u30AF) O(nm min(n, m) / 64)\n     */\n    std::pair<F2Matrix, std::vector<long\
    \ long>> reduced_row_echelon() const {\n        F2Matrix A = *this;\n        std::vector<long\
    \ long> pivots = reduce(A.a, n, w, m);\n        return {A, pivots};\n    }\n \
    \   /**\n     * @brief \u30E9\u30F3\u30AF O(nm min(n, m) / 64)\n     */\n    long\
    \ long rank() const {\n        auto d = a;\n        return reduce(d, n, w, m).size();\n\
    \    }\n    /**\n     * @brief \u884C\u5217\u5F0F (\u6B63\u65B9\u884C\u5217) O(n^3\
    \ / 64)\n     */\n    bool det() const {\n        assert(n == m);\n        return\
    \ rank() == n;\n    }\n    /**\n     * @brief \u9006\u884C\u5217 (\u6B63\u65B9\
    \u884C\u5217)\u3002\u6B63\u5247\u3067\u306A\u3051\u308C\u3070 std::nullopt O(n^3\
    \ / 64)\n     */\n    std::optional<F2Matrix> inv() const {\n        assert(n\
    \ == m);\n        // [A | I] \u3092 A \u306E\u5217\u3060\u3051\u3067\u7C21\u7D04\
    \u5316\u3059\u308B\u3068 [I | A^-1] \u306B\u306A\u308B\n        const long long\
    \ w2 = (2 * n + 63) / 64;\n        std::vector<std::uint64_t> d(n * w2, 0);\n\
    \        for (long long i = 0; i < n; i++) {\n            for (long long k = 0;\
    \ k < w; k++) d[i * w2 + k] = a[i * w + k];\n            d[i * w2 + ((n + i) >>\
    \ 6)] |= std::uint64_t(1) << ((n + i) & 63);\n        }\n        if (static_cast<long\
    \ long>(reduce(d, n, w2, n).size()) < n) return std::nullopt;\n        F2Matrix\
    \ res(n, n);\n        for (long long i = 0; i < n; i++)\n            for (long\
    \ long j = 0; j < n; j++)\n                if (get_bit(d, w2, i, n + j)) res.set(i,\
    \ j, true);\n        return res;\n    }\n    /**\n     * @brief Ax = 0 \u306E\u89E3\
    \u7A7A\u9593\u306E\u57FA\u5E95 (\u9577\u3055 m \u306E\u30D9\u30AF\u30C8\u30EB\u3092\
    \ m - rank \u500B) O(nm min(n, m) / 64)\n     */\n    std::vector<std::vector<bool>>\
    \ kernel() const {\n        auto d = a;\n        std::vector<long long> pivots\
    \ = reduce(d, n, w, m);\n        return kernel_from_reduced(d, w, pivots);\n \
    \   }\n    /**\n     * @brief \u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F Ax =\
    \ b \u3092\u89E3\u304F\u3002\u89E3\u304C\u306A\u3051\u308C\u3070 std::nullopt\
    \ O(nm min(n, m) / 64)\n     */\n    std::optional<Solution> solve(const std::vector<bool>&\
    \ b) const {\n        assert(static_cast<long long>(b.size()) == n);\n       \
    \ // \u62E1\u5927\u4FC2\u6570\u884C\u5217 [A | b] \u3092\u3001A \u306E\u5217\u3060\
    \u3051\u3067\u7C21\u7D04\u5316\u3059\u308B\n        const long long w2 = (m +\
    \ 1 + 63) / 64;\n        std::vector<std::uint64_t> d(n * w2, 0);\n        for\
    \ (long long i = 0; i < n; i++) {\n            for (long long k = 0; k < w; k++)\
    \ d[i * w2 + k] = a[i * w + k];\n            if (b[i]) d[i * w2 + (m >> 6)] |=\
    \ std::uint64_t(1) << (m & 63);\n        }\n        std::vector<long long> pivots\
    \ = reduce(d, n, w2, m);\n        const long long r = pivots.size();\n       \
    \ for (long long i = r; i < n; i++) {\n            if (get_bit(d, w2, i, m)) return\
    \ std::nullopt;\n        }\n        Solution sol;\n        sol.x.assign(m, false);\n\
    \        for (long long i = 0; i < r; i++) sol.x[pivots[i]] = get_bit(d, w2, i,\
    \ m);\n        sol.basis = kernel_from_reduced(d, w2, pivots);\n        return\
    \ sol;\n    }\n\n    /**\n     * @brief \u5404\u884C\u3092 '0' \u3068 '1' \u306E\
    \u6587\u5B57\u5217\u306B\u3057\u305F\u3082\u306E\n     */\n    std::vector<std::string>\
    \ to_strings() const {\n        std::vector<std::string> res(n, std::string(m,\
    \ '0'));\n        for (long long i = 0; i < n; i++)\n            for (long long\
    \ j = 0; j < m; j++)\n                if (get(i, j)) res[i][j] = '1';\n      \
    \  return res;\n    }\n    /**\n     * @brief \u5404\u884C\u3092 '0' \u3068 '1'\
    \ \u306E\u6587\u5B57\u5217\u306B\u3057\u3066\u3001\u6539\u884C\u533A\u5207\u308A\
    \u3067\u51FA\u529B\u3059\u308B\n     */\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const F2Matrix& A) {\n        auto s = A.to_strings();\n        for (long\
    \ long i = 0; i < A.n; i++) {\n            if (i != 0) os << '\\n';\n        \
    \    os << s[i];\n        }\n        return os;\n    }\n};\n#line 8 \"test/yosupo/system-of-linear-equations-mod-2.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n, m;\n    std::cin >> n >> m;\n    std::vector<std::string> s(n);\n\
    \    for (auto& row : s) std::cin >> row;\n    std::string t;\n    std::cin >>\
    \ t;\n    std::vector<bool> b(n);\n    for (int i = 0; i < n; i++) b[i] = t[i]\
    \ == '1';\n    auto sol = F2Matrix(s).solve(b);\n    if (!sol) {\n        std::cout\
    \ << -1 << '\\n';\n        return 0;\n    }\n    auto print = [&](const std::vector<bool>&\
    \ v) {\n        std::string r(m, '0');\n        for (int j = 0; j < m; j++)\n\
    \            if (v[j]) r[j] = '1';\n        std::cout << r << '\\n';\n    };\n\
    \    std::cout << sol->basis.size() << '\\n';\n    print(sol->x);\n    for (const\
    \ auto& v : sol->basis) print(v);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"../../src/math/f2-matrix.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n, m;\n    std::cin >> n >> m;\n    std::vector<std::string> s(n);\n\
    \    for (auto& row : s) std::cin >> row;\n    std::string t;\n    std::cin >>\
    \ t;\n    std::vector<bool> b(n);\n    for (int i = 0; i < n; i++) b[i] = t[i]\
    \ == '1';\n    auto sol = F2Matrix(s).solve(b);\n    if (!sol) {\n        std::cout\
    \ << -1 << '\\n';\n        return 0;\n    }\n    auto print = [&](const std::vector<bool>&\
    \ v) {\n        std::string r(m, '0');\n        for (int j = 0; j < m; j++)\n\
    \            if (v[j]) r[j] = '1';\n        std::cout << r << '\\n';\n    };\n\
    \    std::cout << sol->basis.size() << '\\n';\n    print(sol->x);\n    for (const\
    \ auto& v : sol->basis) print(v);\n}\n"
  dependsOn:
  - src/math/f2-matrix.hpp
  isVerificationFile: true
  path: test/yosupo/system-of-linear-equations-mod-2.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 20:29:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/system-of-linear-equations-mod-2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/system-of-linear-equations-mod-2.test.cpp
- /verify/test/yosupo/system-of-linear-equations-mod-2.test.cpp.html
title: test/yosupo/system-of-linear-equations-mod-2.test.cpp
---
