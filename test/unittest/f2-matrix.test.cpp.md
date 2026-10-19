---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/f2-matrix.hpp
    title: "F2 \u306E\u884C\u5217 (mod 2)"
  - icon: ':heavy_check_mark:'
    path: src/math/matrix.hpp
    title: "\u884C\u5217"
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
  bundledCode: "#line 1 \"test/unittest/f2-matrix.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// F2Matrix \u3092\u3001GF(2) \u306E\u6F14\u7B97\u3092\u6E21\u3057\u305F Matrix\
    \ \u3084\u3001x \u3092\u3059\u3079\u3066\u8A66\u3059\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// 64 \u5217\u3092\u307E\
    \u305F\u3050\u5927\u304D\u3055 (65 \u5217\u306A\u3069) \u3082\u8A66\u3059\n//\
    \ \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #line 2 \"src/math/f2-matrix.hpp\"\n\n/**\n * @file f2-matrix.hpp\n * @brief F2\
    \ (mod 2) \u306E\u884C\u5217\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <cstdint>\n#include <optional>\n#include <ostream>\n#include <string>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief F2 (mod 2) \u306E\u884C\
    \u5217\n *\n * \u5404\u884C\u3092 64 bit \u305A\u3064\u8A70\u3081\u3066\u6301\u3061\
    \u3001\u8DB3\u3057\u7B97 (xor)\u30FB\u7A4D\u30FB\u6D88\u53BB\u3092 64 \u8981\u7D20\
    \u305A\u3064\u307E\u3068\u3081\u3066\u884C\u3046\n * \u30D9\u30AF\u30C8\u30EB\u306F\
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
    \    os << s[i];\n        }\n        return os;\n    }\n};\n#line 8 \"test/unittest/f2-matrix.test.cpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <sstream>\n#line 14 \"test/unittest/f2-matrix.test.cpp\"\
    \n\n#line 2 \"src/math/matrix.hpp\"\n\n/**\n * @file matrix.hpp\n * @brief \u884C\
    \u5217\n */\n\n#line 10 \"src/math/matrix.hpp\"\n#include <cmath>\n#include <cstddef>\n\
    #include <initializer_list>\n#line 15 \"src/math/matrix.hpp\"\n#include <type_traits>\n\
    #line 17 \"src/math/matrix.hpp\"\n#include <valarray>\n#line 19 \"src/math/matrix.hpp\"\
    \n\nnamespace matrix {\ntemplate <typename T>\nstruct OperatorPropertyDefault\
    \ {\n    constexpr static T zero() { return T(0); }\n    constexpr static T add(const\
    \ T& a, const T& b) { return a + b; }\n    constexpr static T neg(const T& a)\
    \ { return -a; }\n    constexpr static T one() { return T(1); }\n    constexpr\
    \ static T mul(const T& a, const T& b) { return a * b; }\n    constexpr static\
    \ T inv(const T& a) { return T(1) / a; }\n};\n}  // namespace matrix\n\n/**\n\
    \ * @brief \u884C\u5217\n * @tparam T \u578B \u884C\u5217(\u30B0\u30EA\u30C3\u30C9\
    )\u306E\u8981\u7D20\u3068\u306A\u308Bint\u3084char\n * @tparam OperatorProperty\
    \ \u884C\u5217\u306E\u8981\u7D20\u306E\u6F14\u7B97\u3092\u5B9A\u7FA9\u3059\u308B\
    \u69CB\u9020\u4F53 0,1\u3068+,*\u306A\u3089\u7701\u7565\u53EF\n *\n * @note\n\
    \ * OperatorProperty\u306E\u4F8B\uFF08\u6574\u6570\u306Exor\u3068and\u306B\u3088\
    \u308B\u74B0\uFF09\n * @code\n * struct XorOperatorProperty {\n *     constexpr\
    \ static int zero() { return 0; }\n *     constexpr static int add(const int &a,\
    \ const int &b) { return a ^ b; }\n *     constexpr static int neg(const int &a)\
    \ { return a; }\n *     constexpr static int one() { return 1; }\n *     constexpr\
    \ static int mul(const int &a, const int &b) { return a & b; }\n * };\n * @endcode\n\
    \ * constexpr\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\u304F\u3001\u307E\u305F\
    inv\u306A\u3069\u4F7F\u308F\u306A\u3044\u3082\u306E\u306F\u5B9A\u7FA9\u3057\u306A\
    \u304F\u3066\u3082\u3088\u3044\uFF08\u5FC5\u8981\u306A\u3082\u306E\u304C\u306A\
    \u304B\u3063\u305F\u3089\u30B3\u30F3\u30D1\u30A4\u30EB\u30A8\u30E9\u30FC\u304C\
    \u767A\u751F\u3059\u308B\uFF09\n */\ntemplate <class T, class OperatorProperty\
    \ = matrix::OperatorPropertyDefault<T>>\nclass Matrix {\n   public:\n    long\
    \ long n, m;\n    std::vector<std::vector<T>> v;\n\n    /**\n     * @brief \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param v \u884C\u5217(\u30B0\u30EA\
    \u30C3\u30C9)\u306E\u5143\u3068\u306A\u308B vector<string> \u3084 vector<vector<T>>\n\
    \     * @return Matrix\n     */\n    template <typename Iterable>\n    Matrix(const\
    \ std::vector<Iterable>& v_) noexcept : n(v_.size()), m(v_.size() == 0 ? 0 : v_[0].size())\
    \ {\n        v.resize(n);\n        for (long long i = 0; i < n; i++) {\n     \
    \       v[i].assign(v_[i].begin(), v_[i].end());\n        }\n    }\n\n    /**\n\
    \     * @brief \u521D\u671F\u5316\u5B50\u30EA\u30B9\u30C8\u304B\u3089\u4F5C\u308B\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * \u4F8B: Matrix<mint> A({{1,\
    \ 1}, {1, 0}});\n     * @param il \u5404\u884C\u306E\u8981\u7D20\u306E\u30EA\u30B9\
    \u30C8\n     */\n    Matrix(std::initializer_list<std::initializer_list<T>> il)\
    \ : n(il.size()), m(il.size() == 0 ? 0 : il.begin()->size()) {\n        v.reserve(n);\n\
    \        for (const auto& row : il) v.emplace_back(row);\n    }\n    /**\n   \
    \  * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param _n \u884C\
    \u5217(\u30B0\u30EA\u30C3\u30C9)\u306E\u884C\u6570\n     * @param _m \u884C\u5217\
    (\u30B0\u30EA\u30C3\u30C9)\u306E\u5217\u6570\n     * @param _val \u884C\u5217\
    (\u30B0\u30EA\u30C3\u30C9)\u306E\u8981\u7D20\u306E\u521D\u671F\u5024\n     * @return\
    \ Matrix\n     */\n    Matrix(long long _n, long long _m, T _val = OperatorProperty::zero())\
    \ : n(_n), m(_m), v(n, std::vector<T>(m, _val)) {}\n\n    auto begin() noexcept\
    \ { return v.begin(); }\n    auto end() noexcept { return v.end(); }\n    auto\
    \ begin() const noexcept { return v.begin(); }\n    auto end() const noexcept\
    \ { return v.end(); }\n\n    /**\n     * @brief \u884C\u5217(\u30B0\u30EA\u30C3\
    \u30C9)\u306E\u884C\u6570\n     * @return long long\n     */\n    [[nodiscard]]\n\
    \    long long size() const { return v.size(); }\n\n    std::vector<T>& operator[](long\
    \ long i) { return v[i]; }\n    const std::vector<T>& operator[](long long i)\
    \ const { return v[i]; }\n    Matrix& operator=(const std::vector<std::vector<T>>&\
    \ A) noexcept {\n        n = A.size();\n        m = (n == 0 ? 0 : A[0].size());\n\
    \        v = A;\n        return *this;\n    }\n    bool operator==(const Matrix&\
    \ A) const noexcept {\n        return this->v == A.v;\n    }\n    bool operator!=(const\
    \ Matrix& A) const noexcept {\n        return this->v != A.v;\n    }\n\n    /**\n\
    \     * @brief \u8EE2\u7F6E\n     * @return Matrix\n     */\n    [[nodiscard]]\n\
    \    Matrix transpose() const noexcept {\n        if (n == 0) return Matrix(v);\n\
    \        std::vector<std::vector<T>> ret(m);\n        for (long long i = 0; i\
    \ < m; i++) {\n            ret[i].resize(n);\n            for (long long j = 0;\
    \ j < n; j++) ret[i][j] = v[j][i];\n        }\n        return Matrix(ret);\n \
    \   }\n\n    /**\n     * @brief \u5DE6\u53F3\u53CD\u8EE2\n     * @return Matrix\n\
    \     */\n    [[nodiscard]]\n    Matrix rev_lr() const noexcept {\n        std::vector<std::vector<T>>\
    \ ret = v;\n        for (long long i = 0; i < n; i++) std::reverse(ret[i].begin(),\
    \ ret[i].end());\n        return Matrix(ret);\n    }\n\n    /**\n     * @brief\
    \ \u4E0A\u4E0B\u53CD\u8EE2\n     * @return Matrix\n     */\n    [[nodiscard]]\n\
    \    Matrix rev_ud() const noexcept {\n        std::vector<std::vector<T>> ret\
    \ = v;\n        reverse(ret.begin(), ret.end());\n        return Matrix(ret);\n\
    \    }\n\n    /**\n     * @brief \u6642\u8A08\u5468\u308A\u306B90\u5EA6\u56DE\u8EE2\
    \n     * @param k \u56DE\u8EE2\u3059\u308B\u56DE\u6570\n     * @return Matrix\n\
    \     */\n    [[nodiscard]]\n    Matrix rotate(long long k) const noexcept {\n\
    \        k %= 4;\n        if (k == 0) return *this;\n        if (k < 0) k += 4;\n\
    \        if (k == 2) return this->rev_lr().rev_ud();\n        std::vector<std::vector<T>>\
    \ ret(m);\n        if (k == 1) {\n            for (long long i = 0; i < m; i++)\
    \ {\n                ret[i].resize(n);\n                for (long long j = 0;\
    \ j < n; j++) ret[i][j] = v[n - j - 1][i];\n            }\n        } else {\n\
    \            for (long long i = 0; i < m; i++) {\n                ret[i].resize(n);\n\
    \                for (long long j = 0; j < n; j++) ret[i][j] = v[j][m - i - 1];\n\
    \            }\n        }\n        return Matrix(ret);\n    }\n\n    /**\n   \
    \  * @brief (i, j)\u3092((i + dy) mod n, (j + dx) mod m)\u306B\u79FB\u52D5\n \
    \    * @return Matrix\n     */\n    [[nodiscard]]\n    Matrix shift(long long\
    \ dy, long long dx) const noexcept {\n        if (n == 0 || m == 0) return *this;\n\
    \        dy = (dy % n + n) % n;\n        dx = (dx % m + m) % m;\n        std::vector<std::vector<T>>\
    \ ret = v;\n        for (long long i = 0, ni = dy; i < n; i++, ni++) {\n     \
    \       if (ni >= n) ni = 0;\n            for (long long j = 0, nj = dx; j < m;\
    \ j++, nj++) {\n                if (nj >= m) nj = 0;\n                ret[ni][nj]\
    \ = v[i][j];\n            }\n        }\n        return Matrix(ret);\n    }\n\n\
    \    /**\n     * @brief \u5DE6\u306Bk\u56DE\u30B7\u30D5\u30C8\n     * @return\
    \ Matrix\n     */\n    [[nodiscard]]\n    Matrix shift_l(long long k) const noexcept\
    \ {\n        return this->shift(0, -k);\n    }\n\n    /**\n     * @brief \u53F3\
    \u306Bk\u56DE\u30B7\u30D5\u30C8\n     * @return Matrix\n     */\n    [[nodiscard]]\n\
    \    Matrix shift_r(long long k) const noexcept {\n        return this->shift(0,\
    \ k);\n    }\n\n    /**\n     * @brief \u4E0A\u306Bk\u56DE\u30B7\u30D5\u30C8\n\
    \     * @return Matrix\n     */\n    [[nodiscard]]\n    Matrix shift_u(long long\
    \ k) const noexcept {\n        return this->shift(-k, 0);\n    }\n\n    /**\n\
    \     * @brief \u4E0B\u306Bk\u56DE\u30B7\u30D5\u30C8\n     * @return Matrix\n\
    \     */\n    [[nodiscard]]\n    Matrix shift_d(long long k) const noexcept {\n\
    \        return this->shift(k, 0);\n    }\n\n    /**\n     * @brief \u30B0\u30EA\
    \u30C3\u30C9\u3092vector<string>\u3067\u8FD4\u3059\n     * @return std::vector<std::string>\n\
    \     */\n    [[nodiscard]]\n    std::vector<std::string> vstr() const noexcept\
    \ {\n        std::vector<std::string> ret(n);\n        for (long long i = 0; i\
    \ < n; i++) {\n            ret[i].assign(v[i].begin(), v[i].end());\n        }\n\
    \        return ret;\n    }\n\n    /**\n     * @brief \u30B0\u30EA\u30C3\u30C9\
    \u306Ej\u5217\u76EE\u3092\u8FD4\u3059\n     * @param j \u8FD4\u3059\u5217\u756A\
    \u53F7(0-indexed)\n     * @return std::vector<T>\n     */\n    [[nodiscard]]\n\
    \    std::vector<T> col(long long j) const noexcept {\n        std::vector<T>\
    \ ret(n);\n        for (long long i = 0; i < n; i++) {\n            ret[i] = v[i][j];\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief \u30B0\u30EA\u30C3\
    \u30C9\u306Ei\u884C\u76EE\u3092string\u3067\u8FD4\u3059\n     * @param i \u8FD4\
    \u3059\u884C\u756A\u53F7(0-indexed)\n     * @return std::string\n     */\n   \
    \ [[nodiscard]]\n    std::string str(long long i) const noexcept {\n        std::string\
    \ ret;\n        ret.assign(v[i].begin(), v[i].end());\n        return ret;\n \
    \   }\n    /**\n     * @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u884C\u5217\
    \u306B\u884C\u5217B\u3092\u8DB3\u3059\n     * @param B \u8DB3\u3059\u884C\u5217\
    \n     * @return @c *this\n     */\n    Matrix& operator+=(const Matrix& B) {\n\
    \        if (n == 0) return (*this);\n        assert(n == B.n && m == B.m);\n\
    \        for (long long i = 0; i < n; i++)\n            for (long long j = 0;\
    \ j < m; j++)\n                (*this)[i][j] = OperatorProperty::add((*this)[i][j],\
    \ B[i][j]);\n        return (*this);\n    }\n    /**\n     * @brief \u4FDD\u6301\
    \u3057\u3066\u3044\u308B\u884C\u5217\u304B\u3089\u884C\u5217B\u3092\u5F15\u304F\
    \n     * @param B \u5F15\u304F\u884C\u5217\n     * @return @c *this\n     */\n\
    \    Matrix& operator-=(const Matrix& B) {\n        if (n == 0) return (*this);\n\
    \        assert(n == B.n && m == B.m);\n        for (long long i = 0; i < n; i++)\n\
    \            for (long long j = 0; j < m; j++)\n                (*this)[i][j]\
    \ = OperatorProperty::add((*this)[i][j], OperatorProperty::neg(B[i][j]));\n  \
    \      return (*this);\n    }\n\n    /**\n     * @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u884C\u5217\u306B\u884C\u5217B\u3092\u639B\u3051\u308B\n     * @param\
    \ B \u639B\u3051\u308B\u884C\u5217\n     * @return @c *this\n     */\n    Matrix&\
    \ operator*=(const Matrix& B) {\n        assert(m == B.n);\n        const long\
    \ long p = B.m;\n        Matrix C(n, p);\n        for (long long i = 0; i < n;\
    \ i++) {\n            for (long long k = 0; k < m; k++) {\n                for\
    \ (long long j = 0; j < p; j++) {\n                    C[i][j] = OperatorProperty::add(C[i][j],\
    \ OperatorProperty::mul((*this)[i][k], B[k][j]));\n                }\n       \
    \     }\n        }\n        v.swap(C.v);\n        m = p;\n        return (*this);\n\
    \    }\n\n    /**\n     * @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u884C\u5217\
    \u306Ek\u4E57\u3092\u6C42\u3081\u308B\n     * @param k \u6307\u6570\n     * @return\
    \ Matrix\n     */\n    [[nodiscard]]\n    Matrix pow(long long k) const {\n  \
    \      Matrix A = *this, B(n, n);\n        for (long long i = 0; i < n; i++) B[i][i]\
    \ = OperatorProperty::one();\n        while (k > 0) {\n            if (k & 1)\
    \ B *= A;\n            A *= A;\n            k >>= 1;\n        }\n        return\
    \ B;\n    }\n\n    [[nodiscard]]\n    Matrix operator+(const Matrix& B) const\
    \ { return (Matrix(*this) += B); }\n    [[nodiscard]]\n    Matrix operator-(const\
    \ Matrix& B) const { return (Matrix(*this) -= B); }\n    [[nodiscard]]\n    Matrix\
    \ operator*(const Matrix& B) const { return (Matrix(*this) *= B); }\n\n    /**\n\
    \     * @brief \u884C\u5217A\u3068\u5217\u30D9\u30AF\u30C8\u30EBB\u306E\u7A4D\n\
    \     * @param A Matrix\n     * @param B vector<T>\n     * @return vector<T> \u5217\
    \u30D9\u30AF\u30C8\u30EB\n     */\n    [[nodiscard]]\n    friend std::vector<T>\
    \ operator*(const Matrix& A, const std::vector<T>& B) {\n        assert(A.m ==\
    \ static_cast<long long>(B.size()));\n        std::vector<T> ret(A.n, OperatorProperty::zero());\n\
    \        for (long long i = 0; i < A.n; i++) {\n            for (long long j =\
    \ 0; j < A.m; j++) {\n                ret[i] = OperatorProperty::add(ret[i], OperatorProperty::mul(A[i][j],\
    \ B[j]));\n            }\n        }\n        return ret;\n    }\n\n    /**\n \
    \    * @brief \u884C\u30D9\u30AF\u30C8\u30EBA\u3068\u884C\u5217B\u306E\u7A4D\n\
    \     * @param A vector<T>\n     * @param B Matrix\n     * @return vector<T> \u884C\
    \u30D9\u30AF\u30C8\u30EB\n     */\n    [[nodiscard]]\n    friend std::vector<T>\
    \ operator*(const std::vector<T>& A, const Matrix& B) {\n        assert(static_cast<long\
    \ long>(A.size()) == B.n);\n        std::vector<T> ret(B.m, OperatorProperty::zero());\n\
    \        for (long long i = 0; i < B.n; i++) {\n            for (long long j =\
    \ 0; j < B.m; j++) {\n                ret[j] = OperatorProperty::add(ret[j], OperatorProperty::mul(A[i],\
    \ B[i][j]));\n            }\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u884C\u5217\u5F0F\n     * @return \u884C\u5217\u5F0F\n     * @note\
    \ \u5272\u308A\u7B97\u3092\u4F7F\u3046\u306E\u3067\u3001\u8981\u7D20\u306F\u4F53\
    \ (modint \u3084\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u306A\u3069) \u3067\u3042\
    \u308B\u3053\u3068\u3002\n     *       int \u3084 long long \u3067\u306F\u5272\
    \u308A\u7B97\u304C\u5207\u308A\u6368\u3066\u306B\u306A\u308A\u3001\u6B63\u3057\
    \u3044\u5024\u306B\u306A\u3089\u306A\u3044\n     */\n    [[nodiscard]]\n    T\
    \ det() const {\n        assert(n == m);\n        if (n == 0) return T(1);\n \
    \       if constexpr (std::is_same_v<OperatorProperty, matrix::OperatorPropertyDefault<T>>)\
    \ {\n            std::vector A(n, std::valarray(T(0), n));\n            for (long\
    \ long i = 0; i < n; i++)\n                for (long long j = 0; j < n; j++) A[i][j]\
    \ = this->v[i][j];\n            return forward_elimination(A);\n        } else\
    \ {\n            auto A = this->v;\n            return forward_elimination(A);\n\
    \        }\n    }\n\n    /**\n     * @brief \u9006\u884C\u5217\n     * @return\
    \ \u9006\u884C\u5217\n     * @note det \u3068\u540C\u3058\u304F\u3001\u8981\u7D20\
    \u306F\u4F53 (modint \u3084\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u306A\u3069) \u3067\
    \u3042\u308B\u3053\u3068\n     */\n    [[nodiscard]]\n    Matrix inv() const {\n\
    \        assert(n == m);\n        if (n == 0) return Matrix(n, n);\n        if\
    \ constexpr (std::is_same_v<OperatorProperty, matrix::OperatorPropertyDefault<T>>)\
    \ {\n            std::vector A(n, std::valarray(T(0), n + n));\n            for\
    \ (long long i = 0; i < n; i++) {\n                for (long long j = 0; j < n;\
    \ j++) A[i][j] = this->v[i][j];\n                A[i][n + i] = T(1);\n       \
    \     }\n            [[maybe_unused]] T d = forward_elimination(A);\n        \
    \    assert(d != T(0));\n            for (long long i = n - 1; i >= 0; i--) {\n\
    \                for (long long j = i - 1; j >= 0; j--) {\n                  \
    \  A[j] -= A[i] * A[j][i];\n                }\n            }\n            Matrix\
    \ ret(n, n);\n            for (long long i = 0; i < n; i++)\n                for\
    \ (long long j = 0; j < n; j++) ret[i][j] = A[i][n + j];\n            return ret;\n\
    \        } else {\n            std::vector A(n, std::vector<T>(n + n, OperatorProperty::zero()));\n\
    \            for (long long i = 0; i < n; i++) {\n                for (long long\
    \ j = 0; j < n; j++) A[i][j] = this->v[i][j];\n                A[i][n + i] = OperatorProperty::one();\n\
    \            }\n            [[maybe_unused]] T d = forward_elimination(A);\n \
    \           assert(d != OperatorProperty::zero());\n            for (long long\
    \ i = n - 1; i >= 0; i--) {\n                for (long long j = i - 1; j >= 0;\
    \ j--) {\n                    for (long long k = n; k < n + n; k++) {\n      \
    \                  A[j][k] = OperatorProperty::add(A[j][k], OperatorProperty::neg(OperatorProperty::mul(A[i][k],\
    \ A[j][i])));\n                    }\n                }\n            }\n     \
    \       Matrix ret(n, n);\n            for (long long i = 0; i < n; i++)\n   \
    \             for (long long j = 0; j < n; j++) ret[i][j] = A[i][n + j];\n   \
    \         return ret;\n        }\n    }\n\n    /**\n     * @brief \u9023\u7ACB\
    \u4E00\u6B21\u65B9\u7A0B\u5F0F Ax = b \u306E\u89E3\n     * \u89E3\u5168\u4F53\u306F\
    \ x + c_0 basis[0] + c_1 basis[1] + ... (c_i \u306F\u4EFB\u610F)\n     */\n  \
    \  struct Solution {\n        std::vector<T> x;                   //!< \u89E3\u306E\
    \ 1 \u3064 (\u7279\u6B8A\u89E3)\n        std::vector<std::vector<T>> basis;  //!<\
    \ Ax = 0 \u306E\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\n    };\n\n    /**\n     *\
    \ @brief \u7C21\u7D04\u5316\u3057\u305F\u884C\u5217 (\u884C\u57FA\u672C\u5909\u5F62\
    \u3067\u3001\u5404\u884C\u306E\u4E3B\u6210\u5206\u3092 1 \u306B\u3057\u3001\u4E3B\
    \u6210\u5206\u306E\u3042\u308B\u5217\u306E\u4ED6\u306E\u6210\u5206\u3092 0 \u306B\
    \u3057\u305F\u3082\u306E) \u3068\u3001\u5404\u884C\u306E\u4E3B\u6210\u5206\u306E\
    \u5217\n     * \u4E3B\u6210\u5206\u306E\u5217\u306E\u500B\u6570\u304C\u30E9\u30F3\
    \u30AF\u30020 \u3060\u3051\u306E\u884C\u306F\u4E0B\u306B\u307E\u3068\u307E\u308B\
    \n     * @note \u5272\u308A\u7B97\u3092\u4F7F\u3046\u306E\u3067\u3001\u8981\u7D20\
    \u306F\u4F53 (modint \u306A\u3069) \u3067\u3042\u308B\u3053\u3068\u3002\u6D6E\u52D5\
    \u5C0F\u6570\u70B9\u578B\u306F\u8AA4\u5DEE\u3092\u8003\u3048\u306A\u3044\u306E\
    \u3067\u4F7F\u3048\u306A\u3044\n     */\n    [[nodiscard]]\n    std::pair<Matrix,\
    \ std::vector<long long>> reduced_row_echelon() const {\n        Matrix A = *this;\n\
    \        std::vector<long long> pivots = reduce(A.v, m);\n        return {A, pivots};\n\
    \    }\n    /**\n     * @brief \u30E9\u30F3\u30AF O(nm min(n, m))\n     */\n \
    \   [[nodiscard]]\n    long long rank() const {\n        auto A = v;\n       \
    \ return reduce(A, m).size();\n    }\n    /**\n     * @brief Ax = 0 \u306E\u89E3\
    \u7A7A\u9593\u306E\u57FA\u5E95 (\u9577\u3055 m \u306E\u30D9\u30AF\u30C8\u30EB\u3092\
    \ m - rank \u500B) O(nm min(n, m))\n     */\n    [[nodiscard]]\n    std::vector<std::vector<T>>\
    \ kernel() const {\n        auto A = v;\n        std::vector<long long> pivots\
    \ = reduce(A, m);\n        return kernel_from_reduced(A, pivots);\n    }\n   \
    \ /**\n     * @brief \u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F Ax = b \u3092\u89E3\
    \u304F\u3002\u89E3\u304C\u306A\u3051\u308C\u3070 std::nullopt O(nm min(n, m))\n\
    \     */\n    [[nodiscard]]\n    std::optional<Solution> solve(const std::vector<T>&\
    \ b) const {\n        assert(static_cast<long long>(b.size()) == n);\n       \
    \ // \u62E1\u5927\u4FC2\u6570\u884C\u5217 [A | b] \u3092\u3001A \u306E\u5217\u3060\
    \u3051\u3067\u7C21\u7D04\u5316\u3059\u308B\n        std::vector<std::vector<T>>\
    \ A(n);\n        for (long long i = 0; i < n; i++) {\n            A[i] = v[i];\n\
    \            A[i].push_back(b[i]);\n        }\n        std::vector<long long>\
    \ pivots = reduce(A, m);\n        const long long r = pivots.size();\n       \
    \ // \u5DE6\u5074\u304C 0 \u306B\u306A\u3063\u305F\u884C\u306E\u53F3\u8FBA\u304C\
    \ 0 \u3067\u306A\u3051\u308C\u3070\u89E3\u306A\u3057\n        for (long long i\
    \ = r; i < n; i++) {\n            if (A[i][m] != OperatorProperty::zero()) return\
    \ std::nullopt;\n        }\n        Solution sol;\n        sol.x.assign(m, OperatorProperty::zero());\n\
    \        for (long long i = 0; i < r; i++) sol.x[pivots[i]] = A[i][m];\n     \
    \   sol.basis = kernel_from_reduced(A, pivots);\n        return sol;\n    }\n\n\
    \   private:\n    // A \u306E\u5DE6\u304B\u3089 cols \u5217\u3092\u4F7F\u3063\u3066\
    \u7C21\u7D04\u5316\u3057\u3001\u5404\u884C\u306E\u4E3B\u6210\u5206\u306E\u5217\
    \u3092\u8FD4\u3059 (\u5217\u304C cols \u3088\u308A\u591A\u3044\u90E8\u5206\u3082\
    \u4E00\u7DD2\u306B\u5909\u5F62\u3059\u308B)\n    static std::vector<long long>\
    \ reduce(std::vector<std::vector<T>>& A, long long cols) {\n        const long\
    \ long rows = A.size();\n        std::vector<long long> pivots;\n        for (long\
    \ long c = 0, r = 0; c < cols && r < rows; c++) {\n            long long p = r;\n\
    \            while (p < rows && A[p][c] == OperatorProperty::zero()) p++;\n  \
    \          if (p == rows) continue;\n            std::swap(A[r], A[p]);\n    \
    \        const long long w = A[r].size();\n            T scale = OperatorProperty::inv(A[r][c]);\n\
    \            for (long long k = c; k < w; k++) A[r][k] = OperatorProperty::mul(A[r][k],\
    \ scale);\n            for (long long i = 0; i < rows; i++) {\n              \
    \  if (i == r || A[i][c] == OperatorProperty::zero()) continue;\n            \
    \    T f = A[i][c];\n                for (long long k = c; k < w; k++) {\n   \
    \                 A[i][k] = OperatorProperty::add(A[i][k], OperatorProperty::neg(OperatorProperty::mul(f,\
    \ A[r][k])));\n                }\n            }\n            pivots.push_back(c);\n\
    \            r++;\n        }\n        return pivots;\n    }\n    // \u7C21\u7D04\
    \u5316\u3057\u305F A (\u5DE6\u304B\u3089 m \u5217) \u304B\u3089\u3001Ax = 0 \u306E\
    \u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u3092\u4F5C\u308B\n    std::vector<std::vector<T>>\
    \ kernel_from_reduced(const std::vector<std::vector<T>>& A, const std::vector<long\
    \ long>& pivots) const {\n        std::vector<bool> is_pivot(m, false);\n    \
    \    for (long long c : pivots) is_pivot[c] = true;\n        std::vector<std::vector<T>>\
    \ res;\n        // \u4E3B\u6210\u5206\u306E\u306A\u3044\u5217 (\u81EA\u7531\u5909\
    \u6570) f \u3054\u3068\u306B\u3001x_f = 1\u3001\u4ED6\u306E\u81EA\u7531\u5909\u6570\
    \u306F 0 \u3068\u3057\u305F\u89E3\n        for (long long f = 0; f < m; f++) {\n\
    \            if (is_pivot[f]) continue;\n            std::vector<T> x(m, OperatorProperty::zero());\n\
    \            x[f] = OperatorProperty::one();\n            for (long long i = 0;\
    \ i < static_cast<long long>(pivots.size()); i++) x[pivots[i]] = OperatorProperty::neg(A[i][f]);\n\
    \            res.push_back(x);\n        }\n        return res;\n    }\n\n   private:\n\
    \    /**\n     * @brief \u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5\u306E\u524D\
    \u9032\u6D88\u53BB\u3092\u884C\u3063\u3066\u4E0A\u4E09\u89D2\u884C\u5217\u3092\
    \u4F5C\u308A\u3001\u884C\u5217\u5F0F\u3092\u8FD4\u3059\n     * @param A \u884C\
    \u5217\n     * @return \u884C\u5217\u5F0F\n     * @note\n     * rank(A) < n\u306E\
    \u5834\u5408\u306F0\u3092\u8FD4\u3059\n     * \u6B63\u65B9\u884C\u5217\u3067\u306F\
    \u306A\u3044\u5834\u5408\u30010\u4EE5\u5916\u304C\u6B8B\u308B\u5DE6\u304B\u3089\
    n\u500B\u306E\u5217\u3092\u4F7F\u3063\u3066\u884C\u5217\u5F0F\u3092\u8A08\u7B97\
    \u3059\u308B\n     */\n    T forward_elimination(std::vector<std::valarray<T>>&\
    \ A) const {\n        std::vector<long long> pivot_col(n, 0);\n        T d(1);\n\
    \        for (long long i = 0; i < n; i++) {\n            if (i - 1 >= 0) pivot_col[i]\
    \ = pivot_col[i - 1] + 1;\n            while (pivot_col[i] < m) {\n          \
    \      long long pivot = i;\n                if constexpr (std::is_floating_point_v<T>)\
    \ {\n                    for (long long j = i + 1; j < n; j++)\n             \
    \           if (std::abs(A[j][pivot_col[i]]) > std::abs(A[pivot][pivot_col[i]]))\
    \ pivot = j;\n                    if (std::abs(A[pivot][pivot_col[i]]) < 1e-9)\
    \ {\n                        pivot_col[i]++;\n                        continue;\n\
    \                    }\n                } else {\n                    while (pivot\
    \ < n && A[pivot][pivot_col[i]] == T(0)) pivot++;\n                    if (pivot\
    \ == n) {\n                        pivot_col[i]++;\n                        continue;\n\
    \                    }\n                }\n                if (pivot != i) {\n\
    \                    std::swap(A[i], A[pivot]);\n                    d *= -T(1);\n\
    \                }\n                break;\n            }\n            if (pivot_col[i]\
    \ == m) return T(0);\n            T scale = A[i][pivot_col[i]];\n            d\
    \ *= scale;\n            A[i] /= scale;\n            for (long long j = i + 1;\
    \ j < n; j++) A[j] -= A[i] * A[j][pivot_col[i]];\n        }\n        return d;\n\
    \    }\n\n    /**\n     * @brief \u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5\u306E\
    \u524D\u9032\u6D88\u53BB\u3092\u884C\u3063\u3066\u4E0A\u4E09\u89D2\u884C\u5217\
    \u3092\u4F5C\u308A\u3001\u884C\u5217\u5F0F\u3092\u8FD4\u3059\n     * @param A\
    \ \u884C\u5217\n     * @return \u884C\u5217\u5F0F\n     * @note\n     * rank(A)\
    \ < n\u306E\u5834\u5408\u306F0\u3092\u8FD4\u3059\n     * \u6B63\u65B9\u884C\u5217\
    \u3067\u306F\u306A\u3044\u5834\u5408\u30010\u4EE5\u5916\u304C\u6B8B\u308B\u5DE6\
    \u304B\u3089n\u500B\u306E\u5217\u3092\u4F7F\u3063\u3066\u884C\u5217\u5F0F\u3092\
    \u8A08\u7B97\u3059\u308B\n     */\n    T forward_elimination(std::vector<std::vector<T>>&\
    \ A) const {\n        std::vector<long long> pivot_col(n, 0);\n        T d = OperatorProperty::one();\n\
    \        for (long long i = 0; i < n; i++) {\n            if (i - 1 >= 0) pivot_col[i]\
    \ = pivot_col[i - 1] + 1;\n            while (pivot_col[i] < m) {\n          \
    \      long long pivot = i;\n                while (pivot < n && A[pivot][pivot_col[i]]\
    \ == OperatorProperty::zero()) pivot++;\n                if (pivot == n) {\n \
    \                   pivot_col[i]++;\n                    continue;\n         \
    \       }\n                if (pivot != i) {\n                    std::swap(A[i],\
    \ A[pivot]);\n                    d = OperatorProperty::neg(d);\n            \
    \    }\n                break;\n            }\n            if (pivot_col[i] ==\
    \ m) return OperatorProperty::zero();\n            const long long w = A[i].size();\n\
    \            T scale = A[i][pivot_col[i]];\n            d = OperatorProperty::mul(d,\
    \ scale);\n            for (long long j = pivot_col[i]; j < w; j++) A[i][j] =\
    \ OperatorProperty::mul(A[i][j], OperatorProperty::inv(scale));\n            for\
    \ (long long j = i + 1; j < n; j++) {\n                T scale = A[j][pivot_col[i]];\n\
    \                for (long long k = pivot_col[i]; k < w; k++) {\n            \
    \        A[j][k] = OperatorProperty::add(A[j][k], OperatorProperty::neg(OperatorProperty::mul(A[i][k],\
    \ scale)));\n                }\n            }\n        }\n        return d;\n\
    \    }\n};\n#line 16 \"test/unittest/f2-matrix.test.cpp\"\n\n// xor \u3068 and\
    \ \u306B\u3088\u308B\u4F53 GF(2)\nstruct GF2 {\n    static int zero() { return\
    \ 0; }\n    static int add(const int& a, const int& b) { return a ^ b; }\n   \
    \ static int neg(const int& a) { return a; }\n    static int one() { return 1;\
    \ }\n    static int mul(const int& a, const int& b) { return a & b; }\n    static\
    \ int inv(const int& a) { return a; }\n};\nusing M2 = Matrix<int, GF2>;\n\nbool\
    \ ok = true;\nvoid check(bool cond, const char* what) {\n    if (!cond && ok)\
    \ std::cerr << \"failed: \" << what << std::endl;\n    if (!cond) ok = false;\n\
    }\n\nstd::vector<std::vector<int>> random_bits(std::mt19937_64& rng, int n, int\
    \ m) {\n    std::vector<std::vector<int>> a(n, std::vector<int>(m));\n    for\
    \ (auto& row : a)\n        for (auto& x : row) x = rng() % 2;\n    // \u30E9\u30F3\
    \u30AF\u304C\u5C0F\u3055\u3044\u884C\u5217\u3082\u4F5C\u308B (\u3042\u308B\u884C\
    \u3092\u5225\u306E\u884C\u306B\u305D\u308D\u3048\u308B)\n    if (n >= 2 && rng()\
    \ % 2) a[rng() % n] = a[rng() % n];\n    return a;\n}\nbool same(const F2Matrix&\
    \ A, const M2& B) {\n    if (A.n != B.n || A.m != B.m) return false;\n    for\
    \ (long long i = 0; i < A.n; i++)\n        for (long long j = 0; j < A.m; j++)\n\
    \            if (A.get(i, j) != (B[i][j] == 1)) return false;\n    return true;\n\
    }\nstd::vector<bool> mul(const std::vector<std::vector<int>>& a, const std::vector<bool>&\
    \ x) {\n    std::vector<bool> y(a.size(), false);\n    for (size_t i = 0; i <\
    \ a.size(); i++)\n        for (size_t j = 0; j < x.size(); j++) y[i] = y[i] ^\
    \ (a[i][j] && x[j]);\n    return y;\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    // \u5217\u6570\u3068\u3057\u3066 64 \u306E\u524D\u5F8C\u3082\u8A66\u3059\
    \n    auto gen_size = [&] {\n        int t = rng() % 4;\n        return t == 0\
    \ ? static_cast<int>(rng() % 64 + 60) : static_cast<int>(rng() % 8 + 1);\n   \
    \ };\n\n    // \u7A4D\u30FB\u8DB3\u3057\u7B97\u30FB\u8EE2\u7F6E\u30FBpow\u30FB\
    \u884C\u5217\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D\u30FBrank\u30FBdet\u30FB\
    inv \u3092 Matrix<int, GF2> \u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep\
    \ < 300 && ok; rep++) {\n        int n = gen_size(), m = gen_size(), k = gen_size();\n\
    \        auto a = random_bits(rng, n, m), b = random_bits(rng, m, k), c = random_bits(rng,\
    \ n, m);\n        F2Matrix A(a), B(b), C(c);\n        M2 Am(a), Bm(b), Cm(c);\n\
    \        check(same(A * B, Am * Bm), \"\u7A4D\");\n        check(same(A + C, M2(a)\
    \ += Cm), \"\u8DB3\u3057\u7B97\");\n        auto t = A.transpose();\n        check(t.n\
    \ == m && t.m == n, \"\u8EE2\u7F6E\u306E\u5927\u304D\u3055\");\n        for (int\
    \ i = 0; i < n; i++)\n            for (int j = 0; j < m; j++) check(t.get(j, i)\
    \ == A.get(i, j), \"\u8EE2\u7F6E\");\n        std::vector<bool> x(m);\n      \
    \  for (int j = 0; j < m; j++) x[j] = rng() % 2;\n        check(A * x == mul(a,\
    \ x), \"\u884C\u5217\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D\");\n        check(A.rank()\
    \ == Am.rank(), \"rank\");\n        auto sq = random_bits(rng, n, n);\n      \
    \  F2Matrix S(sq);\n        M2 Sm(sq);\n        check(S.det() == (Sm.det() ==\
    \ 1), \"det\");\n        auto si = S.inv();\n        check(si.has_value() == S.det(),\
    \ \"inv \u304C\u3042\u308B\u304B\");\n        if (si) check(S * *si == F2Matrix::identity(n)\
    \ && *si * S == F2Matrix::identity(n), \"inv\");\n        long long e = rng()\
    \ % 20;\n        check(same(S.pow(e), Sm.pow(e)), \"pow\");\n        // \u7C21\
    \u7D04\u5316: \u4E3B\u6210\u5206\u306E\u5217\u304C\u5897\u3048\u3066\u3044\u304D\
    \u3001\u305D\u306E\u5217\u306E\u4ED6\u306E\u6210\u5206\u306F 0\n        auto [R,\
    \ piv] = A.reduced_row_echelon();\n        check(static_cast<long long>(piv.size())\
    \ == A.rank(), \"reduced_row_echelon \u306E\u30E9\u30F3\u30AF\");\n        for\
    \ (size_t i = 0; i < piv.size(); i++) {\n            if (i > 0) check(piv[i] >\
    \ piv[i - 1], \"reduced_row_echelon \u306E\u4E3B\u6210\u5206\u306E\u5217\");\n\
    \            for (int r = 0; r < n; r++) check(R.get(r, piv[i]) == (r == static_cast<int>(i)),\
    \ \"reduced_row_echelon \u306E\u4E3B\u6210\u5206\");\n        }\n    }\n\n   \
    \ // solve\u30FBkernel: \u5217\u304C\u5C11\u306A\u3051\u308C\u3070 2^m \u901A\u308A\
    \u306E x \u3092\u3059\u3079\u3066\u8A66\u3057\u3066\u3001\u89E3\u306E\u500B\u6570\
    \u3068\u5408\u3046\u304B\u78BA\u304B\u3081\u308B\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        int n = rng() % 8 + 1, m = rng() % 10 + 1;\n \
    \       auto a = random_bits(rng, n, m);\n        F2Matrix A(a);\n        std::vector<bool>\
    \ b(n);\n        for (int i = 0; i < n; i++) b[i] = rng() % 2;\n        long long\
    \ cnt_b = 0, cnt_0 = 0;\n        std::vector<bool> zero(n, false);\n        for\
    \ (long long code = 0; code < (1LL << m); code++) {\n            std::vector<bool>\
    \ x(m);\n            for (int j = 0; j < m; j++) x[j] = code >> j & 1;\n     \
    \       auto y = mul(a, x);\n            cnt_b += y == b;\n            cnt_0 +=\
    \ y == zero;\n        }\n        long long r = A.rank();\n        check(cnt_0\
    \ == (1LL << (m - r)), \"rank \u3068\u89E3\u306E\u500B\u6570\");\n        auto\
    \ ker = A.kernel();\n        check(static_cast<long long>(ker.size()) == m - r,\
    \ \"kernel \u306E\u500B\u6570\");\n        for (const auto& v : ker) check(A *\
    \ v == zero, \"kernel \u306F Ax = 0 \u306E\u89E3\");\n        if (!ker.empty())\
    \ {\n            F2Matrix K(ker.size(), m);\n            for (size_t i = 0; i\
    \ < ker.size(); i++)\n                for (int j = 0; j < m; j++) K.set(i, j,\
    \ ker[i][j]);\n            check(K.rank() == static_cast<long long>(ker.size()),\
    \ \"kernel \u306F\u4E00\u6B21\u72EC\u7ACB\");\n        }\n        auto sol = A.solve(b);\n\
    \        if (!sol) {\n            check(cnt_b == 0, \"\u89E3\u306A\u3057\");\n\
    \        } else {\n            check(A * sol->x == b && cnt_b == (1LL << sol->basis.size()),\
    \ \"solve\");\n            for (const auto& v : sol->basis) check(A * v == zero,\
    \ \"solve \u306E\u57FA\u5E95\");\n        }\n    }\n\n    // 64 \u5217\u3092\u307E\
    \u305F\u3050\u5927\u304D\u3055\u306E solve: \u89E3\u3092\u4F5C\u3063\u3066\u304B\
    \u3089 b \u3092\u6C7A\u3081\u3001\u89E3\u304C\u898B\u3064\u304B\u308B\u304B\u78BA\
    \u304B\u3081\u308B\n    for (int rep = 0; rep < 100 && ok; rep++) {\n        int\
    \ n = rng() % 150 + 1, m = rng() % 150 + 1;\n        auto a = random_bits(rng,\
    \ n, m);\n        F2Matrix A(a);\n        std::vector<bool> x(m);\n        for\
    \ (int j = 0; j < m; j++) x[j] = rng() % 2;\n        auto b = A * x;\n       \
    \ auto sol = A.solve(b);\n        check(sol && A * sol->x == b && static_cast<long\
    \ long>(sol->basis.size()) == m - A.rank(), \"\u5927\u304D\u3044 solve\");\n \
    \   }\n\n    // \u6587\u5B57\u5217\u304B\u3089\u4F5C\u308B\u30FB\u51FA\u529B\u30FB\
    set\n    {\n        F2Matrix A(std::vector<std::string>{\"110\", \"011\"});\n\
    \        check(A.get(0, 1) && !A.get(0, 2) && A.get(1, 2), \"\u6587\u5B57\u5217\
    \u304B\u3089\u4F5C\u308B\");\n        A.set(0, 0, false);\n        std::ostringstream\
    \ os;\n        os << A;\n        check(os.str() == \"010\\n011\" && A.to_strings()\
    \ == std::vector<std::string>{\"010\", \"011\"}, \"\u51FA\u529B\");\n        check(F2Matrix().n\
    \ == 0 && F2Matrix(3, 70).rank() == 0, \"\u96F6\u884C\u5217\");\n    }\n\n   \
    \ if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// F2Matrix \u3092\u3001GF(2) \u306E\u6F14\u7B97\u3092\u6E21\u3057\u305F Matrix\
    \ \u3084\u3001x \u3092\u3059\u3079\u3066\u8A66\u3059\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// 64 \u5217\u3092\u307E\
    \u305F\u3050\u5927\u304D\u3055 (65 \u5217\u306A\u3069) \u3082\u8A66\u3059\n//\
    \ \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #include \"../../src/math/f2-matrix.hpp\"\n\n#include <iostream>\n#include <random>\n\
    #include <sstream>\n#include <string>\n#include <vector>\n\n#include \"../../src/math/matrix.hpp\"\
    \n\n// xor \u3068 and \u306B\u3088\u308B\u4F53 GF(2)\nstruct GF2 {\n    static\
    \ int zero() { return 0; }\n    static int add(const int& a, const int& b) { return\
    \ a ^ b; }\n    static int neg(const int& a) { return a; }\n    static int one()\
    \ { return 1; }\n    static int mul(const int& a, const int& b) { return a & b;\
    \ }\n    static int inv(const int& a) { return a; }\n};\nusing M2 = Matrix<int,\
    \ GF2>;\n\nbool ok = true;\nvoid check(bool cond, const char* what) {\n    if\
    \ (!cond && ok) std::cerr << \"failed: \" << what << std::endl;\n    if (!cond)\
    \ ok = false;\n}\n\nstd::vector<std::vector<int>> random_bits(std::mt19937_64&\
    \ rng, int n, int m) {\n    std::vector<std::vector<int>> a(n, std::vector<int>(m));\n\
    \    for (auto& row : a)\n        for (auto& x : row) x = rng() % 2;\n    // \u30E9\
    \u30F3\u30AF\u304C\u5C0F\u3055\u3044\u884C\u5217\u3082\u4F5C\u308B (\u3042\u308B\
    \u884C\u3092\u5225\u306E\u884C\u306B\u305D\u308D\u3048\u308B)\n    if (n >= 2\
    \ && rng() % 2) a[rng() % n] = a[rng() % n];\n    return a;\n}\nbool same(const\
    \ F2Matrix& A, const M2& B) {\n    if (A.n != B.n || A.m != B.m) return false;\n\
    \    for (long long i = 0; i < A.n; i++)\n        for (long long j = 0; j < A.m;\
    \ j++)\n            if (A.get(i, j) != (B[i][j] == 1)) return false;\n    return\
    \ true;\n}\nstd::vector<bool> mul(const std::vector<std::vector<int>>& a, const\
    \ std::vector<bool>& x) {\n    std::vector<bool> y(a.size(), false);\n    for\
    \ (size_t i = 0; i < a.size(); i++)\n        for (size_t j = 0; j < x.size();\
    \ j++) y[i] = y[i] ^ (a[i][j] && x[j]);\n    return y;\n}\n\nint main() {\n  \
    \  std::mt19937_64 rng(314);\n    // \u5217\u6570\u3068\u3057\u3066 64 \u306E\u524D\
    \u5F8C\u3082\u8A66\u3059\n    auto gen_size = [&] {\n        int t = rng() % 4;\n\
    \        return t == 0 ? static_cast<int>(rng() % 64 + 60) : static_cast<int>(rng()\
    \ % 8 + 1);\n    };\n\n    // \u7A4D\u30FB\u8DB3\u3057\u7B97\u30FB\u8EE2\u7F6E\
    \u30FBpow\u30FB\u884C\u5217\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D\u30FBrank\u30FB\
    det\u30FBinv \u3092 Matrix<int, GF2> \u3068\u6BD4\u3079\u308B\n    for (int rep\
    \ = 0; rep < 300 && ok; rep++) {\n        int n = gen_size(), m = gen_size(),\
    \ k = gen_size();\n        auto a = random_bits(rng, n, m), b = random_bits(rng,\
    \ m, k), c = random_bits(rng, n, m);\n        F2Matrix A(a), B(b), C(c);\n   \
    \     M2 Am(a), Bm(b), Cm(c);\n        check(same(A * B, Am * Bm), \"\u7A4D\"\
    );\n        check(same(A + C, M2(a) += Cm), \"\u8DB3\u3057\u7B97\");\n       \
    \ auto t = A.transpose();\n        check(t.n == m && t.m == n, \"\u8EE2\u7F6E\u306E\
    \u5927\u304D\u3055\");\n        for (int i = 0; i < n; i++)\n            for (int\
    \ j = 0; j < m; j++) check(t.get(j, i) == A.get(i, j), \"\u8EE2\u7F6E\");\n  \
    \      std::vector<bool> x(m);\n        for (int j = 0; j < m; j++) x[j] = rng()\
    \ % 2;\n        check(A * x == mul(a, x), \"\u884C\u5217\u3068\u30D9\u30AF\u30C8\
    \u30EB\u306E\u7A4D\");\n        check(A.rank() == Am.rank(), \"rank\");\n    \
    \    auto sq = random_bits(rng, n, n);\n        F2Matrix S(sq);\n        M2 Sm(sq);\n\
    \        check(S.det() == (Sm.det() == 1), \"det\");\n        auto si = S.inv();\n\
    \        check(si.has_value() == S.det(), \"inv \u304C\u3042\u308B\u304B\");\n\
    \        if (si) check(S * *si == F2Matrix::identity(n) && *si * S == F2Matrix::identity(n),\
    \ \"inv\");\n        long long e = rng() % 20;\n        check(same(S.pow(e), Sm.pow(e)),\
    \ \"pow\");\n        // \u7C21\u7D04\u5316: \u4E3B\u6210\u5206\u306E\u5217\u304C\
    \u5897\u3048\u3066\u3044\u304D\u3001\u305D\u306E\u5217\u306E\u4ED6\u306E\u6210\
    \u5206\u306F 0\n        auto [R, piv] = A.reduced_row_echelon();\n        check(static_cast<long\
    \ long>(piv.size()) == A.rank(), \"reduced_row_echelon \u306E\u30E9\u30F3\u30AF\
    \");\n        for (size_t i = 0; i < piv.size(); i++) {\n            if (i > 0)\
    \ check(piv[i] > piv[i - 1], \"reduced_row_echelon \u306E\u4E3B\u6210\u5206\u306E\
    \u5217\");\n            for (int r = 0; r < n; r++) check(R.get(r, piv[i]) ==\
    \ (r == static_cast<int>(i)), \"reduced_row_echelon \u306E\u4E3B\u6210\u5206\"\
    );\n        }\n    }\n\n    // solve\u30FBkernel: \u5217\u304C\u5C11\u306A\u3051\
    \u308C\u3070 2^m \u901A\u308A\u306E x \u3092\u3059\u3079\u3066\u8A66\u3057\u3066\
    \u3001\u89E3\u306E\u500B\u6570\u3068\u5408\u3046\u304B\u78BA\u304B\u3081\u308B\
    \n    for (int rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 8\
    \ + 1, m = rng() % 10 + 1;\n        auto a = random_bits(rng, n, m);\n       \
    \ F2Matrix A(a);\n        std::vector<bool> b(n);\n        for (int i = 0; i <\
    \ n; i++) b[i] = rng() % 2;\n        long long cnt_b = 0, cnt_0 = 0;\n       \
    \ std::vector<bool> zero(n, false);\n        for (long long code = 0; code < (1LL\
    \ << m); code++) {\n            std::vector<bool> x(m);\n            for (int\
    \ j = 0; j < m; j++) x[j] = code >> j & 1;\n            auto y = mul(a, x);\n\
    \            cnt_b += y == b;\n            cnt_0 += y == zero;\n        }\n  \
    \      long long r = A.rank();\n        check(cnt_0 == (1LL << (m - r)), \"rank\
    \ \u3068\u89E3\u306E\u500B\u6570\");\n        auto ker = A.kernel();\n       \
    \ check(static_cast<long long>(ker.size()) == m - r, \"kernel \u306E\u500B\u6570\
    \");\n        for (const auto& v : ker) check(A * v == zero, \"kernel \u306F Ax\
    \ = 0 \u306E\u89E3\");\n        if (!ker.empty()) {\n            F2Matrix K(ker.size(),\
    \ m);\n            for (size_t i = 0; i < ker.size(); i++)\n                for\
    \ (int j = 0; j < m; j++) K.set(i, j, ker[i][j]);\n            check(K.rank()\
    \ == static_cast<long long>(ker.size()), \"kernel \u306F\u4E00\u6B21\u72EC\u7ACB\
    \");\n        }\n        auto sol = A.solve(b);\n        if (!sol) {\n       \
    \     check(cnt_b == 0, \"\u89E3\u306A\u3057\");\n        } else {\n         \
    \   check(A * sol->x == b && cnt_b == (1LL << sol->basis.size()), \"solve\");\n\
    \            for (const auto& v : sol->basis) check(A * v == zero, \"solve \u306E\
    \u57FA\u5E95\");\n        }\n    }\n\n    // 64 \u5217\u3092\u307E\u305F\u3050\
    \u5927\u304D\u3055\u306E solve: \u89E3\u3092\u4F5C\u3063\u3066\u304B\u3089 b \u3092\
    \u6C7A\u3081\u3001\u89E3\u304C\u898B\u3064\u304B\u308B\u304B\u78BA\u304B\u3081\
    \u308B\n    for (int rep = 0; rep < 100 && ok; rep++) {\n        int n = rng()\
    \ % 150 + 1, m = rng() % 150 + 1;\n        auto a = random_bits(rng, n, m);\n\
    \        F2Matrix A(a);\n        std::vector<bool> x(m);\n        for (int j =\
    \ 0; j < m; j++) x[j] = rng() % 2;\n        auto b = A * x;\n        auto sol\
    \ = A.solve(b);\n        check(sol && A * sol->x == b && static_cast<long long>(sol->basis.size())\
    \ == m - A.rank(), \"\u5927\u304D\u3044 solve\");\n    }\n\n    // \u6587\u5B57\
    \u5217\u304B\u3089\u4F5C\u308B\u30FB\u51FA\u529B\u30FBset\n    {\n        F2Matrix\
    \ A(std::vector<std::string>{\"110\", \"011\"});\n        check(A.get(0, 1) &&\
    \ !A.get(0, 2) && A.get(1, 2), \"\u6587\u5B57\u5217\u304B\u3089\u4F5C\u308B\"\
    );\n        A.set(0, 0, false);\n        std::ostringstream os;\n        os <<\
    \ A;\n        check(os.str() == \"010\\n011\" && A.to_strings() == std::vector<std::string>{\"\
    010\", \"011\"}, \"\u51FA\u529B\");\n        check(F2Matrix().n == 0 && F2Matrix(3,\
    \ 70).rank() == 0, \"\u96F6\u884C\u5217\");\n    }\n\n    if (ok) std::cout <<\
    \ \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/math/f2-matrix.hpp
  - src/math/matrix.hpp
  isVerificationFile: true
  path: test/unittest/f2-matrix.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 20:29:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/f2-matrix.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/f2-matrix.test.cpp
- /verify/test/unittest/f2-matrix.test.cpp.html
title: test/unittest/f2-matrix.test.cpp
---
