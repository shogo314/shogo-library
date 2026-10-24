---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/volume33/3314.test.cpp
    title: test/aoj/volume33/3314.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/f2-matrix.test.cpp
    title: test/unittest/math/f2-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/matrix.test.cpp
    title: test/unittest/math/matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/counting-spanning-tree-directed.test.cpp
    title: test/yosupo/graph/counting-spanning-tree-directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/counting-spanning-tree-undirected.test.cpp
    title: test/yosupo/graph/counting-spanning-tree-undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_algebra/characteristic-polynomial.test.cpp
    title: test/yosupo/linear_algebra/characteristic-polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_algebra/inverse-matrix.test.cpp
    title: test/yosupo/linear_algebra/inverse-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_algebra/matrix-det-arbitrary-mod.test.cpp
    title: test/yosupo/linear_algebra/matrix-det-arbitrary-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_algebra/matrix-det.test.cpp
    title: test/yosupo/linear_algebra/matrix-det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_algebra/matrix-product.test.cpp
    title: test/yosupo/linear_algebra/matrix-product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_algebra/matrix-rank.test.cpp
    title: test/yosupo/linear_algebra/matrix-rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_algebra/pow-of-matrix.test.cpp
    title: test/yosupo/linear_algebra/pow-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_algebra/system-of-linear-equations.test.cpp
    title: test/yosupo/linear_algebra/system-of-linear-equations.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1340.test.cpp
    title: test/yukicoder/1340.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/565.1.test.cpp
    title: test/yukicoder/565.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/565.2.test.cpp
    title: test/yukicoder/565.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u884C\u5217"
    links: []
  bundledCode: "#line 2 \"src/math/matrix.hpp\"\n\n/**\n * @file matrix.hpp\n * @brief\
    \ \u884C\u5217\n */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #if __cplusplus >= 202002L\n#include <concepts>\n#endif\n#include <cstddef>\n\
    #include <cstdint>\n#include <initializer_list>\n#include <optional>\n#include\
    \ <string>\n#include <type_traits>\n#include <utility>\n#include <valarray>\n\
    #include <vector>\n\nnamespace matrix {\ntemplate <typename T>\nstruct OperatorPropertyDefault\
    \ {\n    constexpr static T zero() { return T(0); }\n    constexpr static T add(const\
    \ T& a, const T& b) { return a + b; }\n    constexpr static T neg(const T& a)\
    \ { return -a; }\n    constexpr static T one() { return T(1); }\n    constexpr\
    \ static T mul(const T& a, const T& b) { return a * b; }\n    constexpr static\
    \ T inv(const T& a) { return T(1) / a; }\n};\n}  // namespace matrix\n\nnamespace\
    \ internal_matrix {\n// \u6CD5\u304C 2^31 \u672A\u6E80\u306E modint (mod() \u3068\
    \ val() \u3092\u6301\u3064\u578B) \u304B\n#if __cplusplus >= 202002L\ntemplate\
    \ <class T>\nconcept modint_like = requires(const T& x) {\n    { T::mod() } ->\
    \ std::convertible_to<std::uint32_t>;\n    { x.val() } -> std::convertible_to<std::uint32_t>;\n\
    };\ntemplate <class T>\ninline constexpr bool is_modint_like_v = modint_like<T>;\n\
    #else\ntemplate <class T, class = void>\nstruct is_modint_like : std::false_type\
    \ {};\ntemplate <class T>\nstruct is_modint_like<T, std::void_t<decltype(static_cast<std::uint32_t>(T::mod())),\n\
    \                                     decltype(static_cast<std::uint32_t>(std::declval<const\
    \ T&>().val()))>>\n    : std::true_type {};\ntemplate <class T>\ninline constexpr\
    \ bool is_modint_like_v = is_modint_like<T>::value;\n#endif\n}  // namespace internal_matrix\n\
    \n/**\n * @brief \u884C\u5217\n * @tparam T \u578B \u884C\u5217(\u30B0\u30EA\u30C3\
    \u30C9)\u306E\u8981\u7D20\u3068\u306A\u308Bint\u3084char\n * @tparam OperatorProperty\
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
    \ long p = B.m;\n        if constexpr (std::is_same_v<OperatorProperty, matrix::OperatorPropertyDefault<T>>\
    \ &&\n                      internal_matrix::is_modint_like_v<T>) {\n        \
    \    // \u7A4D\u3092 64 \u30D3\u30C3\u30C8\u306E\u307E\u307E\u8DB3\u3057\u3001\
    \u3042\u3075\u308C\u308B\u524D\u306B\u3060\u3051 mod \u3092\u53D6\u308B\n    \
    \        // \u6CD5\u304C 2^30 \u7A0B\u5EA6\u307E\u3067\u306A\u3089 4 \u884C\u305A\
    \u3064\u307E\u3068\u3081\u3066\u8DB3\u3057\u3001acc \u306E\u8AAD\u307F\u66F8\u304D\
    \u3092\u6E1B\u3089\u3059\n            const std::uint64_t mod = T::mod();\n  \
    \          const std::uint64_t lim = UINT64_MAX / ((mod - 1) * (mod - 1) + 1)\
    \ - 1;\n            std::vector<std::uint32_t> b(m * p);\n            for (long\
    \ long k = 0; k < m; k++)\n                for (long long j = 0; j < p; j++) b[k\
    \ * p + j] = B[k][j].val();\n            std::vector<std::uint64_t> acc(p);\n\
    \            for (long long i = 0; i < n; i++) {\n                std::fill(acc.begin(),\
    \ acc.end(), 0);\n                std::uint64_t cnt = 0;\n                long\
    \ long k = 0;\n                if (lim >= 4) {\n                    for (; k +\
    \ 4 <= m; k += 4) {\n                        if (cnt + 4 > lim) {\n          \
    \                  cnt = 0;\n                            for (long long j = 0;\
    \ j < p; j++) acc[j] %= mod;\n                        }\n                    \
    \    cnt += 4;\n                        const auto& r = (*this)[i];\n        \
    \                const std::uint64_t a0 = r[k].val(), a1 = r[k + 1].val(), a2\
    \ = r[k + 2].val(), a3 = r[k + 3].val();\n                        const std::uint32_t\
    \ *b0 = b.data() + k * p, *b1 = b0 + p, *b2 = b1 + p, *b3 = b2 + p;\n        \
    \                for (long long j = 0; j < p; j++) acc[j] += a0 * b0[j] + a1 *\
    \ b1[j] + a2 * b2[j] + a3 * b3[j];\n                    }\n                }\n\
    \                for (; k < m; k++) {\n                    if (cnt + 1 > lim)\
    \ {\n                        cnt = 0;\n                        for (long long\
    \ j = 0; j < p; j++) acc[j] %= mod;\n                    }\n                 \
    \   cnt++;\n                    const std::uint64_t a0 = (*this)[i][k].val();\n\
    \                    const std::uint32_t* b0 = b.data() + k * p;\n           \
    \         for (long long j = 0; j < p; j++) acc[j] += a0 * b0[j];\n          \
    \      }\n                v[i].resize(p);\n                for (long long j =\
    \ 0; j < p; j++) v[i][j] = T(acc[j] % mod);\n            }\n            m = p;\n\
    \            return (*this);\n        }\n        Matrix C(n, p);\n        for\
    \ (long long i = 0; i < n; i++) {\n            for (long long k = 0; k < m; k++)\
    \ {\n                for (long long j = 0; j < p; j++) {\n                   \
    \ C[i][j] = OperatorProperty::add(C[i][j], OperatorProperty::mul((*this)[i][k],\
    \ B[k][j]));\n                }\n            }\n        }\n        v.swap(C.v);\n\
    \        m = p;\n        return (*this);\n    }\n\n    /**\n     * @brief \u4FDD\
    \u6301\u3057\u3066\u3044\u308B\u884C\u5217\u306Ek\u4E57\u3092\u6C42\u3081\u308B\
    \n     * @param k \u6307\u6570\n     * @return Matrix\n     */\n    [[nodiscard]]\n\
    \    Matrix pow(long long k) const {\n        Matrix A = *this, B(n, n);\n   \
    \     for (long long i = 0; i < n; i++) B[i][i] = OperatorProperty::one();\n \
    \       while (k > 0) {\n            if (k & 1) B *= A;\n            A *= A;\n\
    \            k >>= 1;\n        }\n        return B;\n    }\n\n    [[nodiscard]]\n\
    \    Matrix operator+(const Matrix& B) const { return (Matrix(*this) += B); }\n\
    \    [[nodiscard]]\n    Matrix operator-(const Matrix& B) const { return (Matrix(*this)\
    \ -= B); }\n    [[nodiscard]]\n    Matrix operator*(const Matrix& B) const { return\
    \ (Matrix(*this) *= B); }\n\n    /**\n     * @brief \u884C\u5217A\u3068\u5217\u30D9\
    \u30AF\u30C8\u30EBB\u306E\u7A4D\n     * @param A Matrix\n     * @param B vector<T>\n\
    \     * @return vector<T> \u5217\u30D9\u30AF\u30C8\u30EB\n     */\n    [[nodiscard]]\n\
    \    friend std::vector<T> operator*(const Matrix& A, const std::vector<T>& B)\
    \ {\n        assert(A.m == static_cast<long long>(B.size()));\n        std::vector<T>\
    \ ret(A.n, OperatorProperty::zero());\n        for (long long i = 0; i < A.n;\
    \ i++) {\n            for (long long j = 0; j < A.m; j++) {\n                ret[i]\
    \ = OperatorProperty::add(ret[i], OperatorProperty::mul(A[i][j], B[j]));\n   \
    \         }\n        }\n        return ret;\n    }\n\n    /**\n     * @brief \u884C\
    \u30D9\u30AF\u30C8\u30EBA\u3068\u884C\u5217B\u306E\u7A4D\n     * @param A vector<T>\n\
    \     * @param B Matrix\n     * @return vector<T> \u884C\u30D9\u30AF\u30C8\u30EB\
    \n     */\n    [[nodiscard]]\n    friend std::vector<T> operator*(const std::vector<T>&\
    \ A, const Matrix& B) {\n        assert(static_cast<long long>(A.size()) == B.n);\n\
    \        std::vector<T> ret(B.m, OperatorProperty::zero());\n        for (long\
    \ long i = 0; i < B.n; i++) {\n            for (long long j = 0; j < B.m; j++)\
    \ {\n                ret[j] = OperatorProperty::add(ret[j], OperatorProperty::mul(A[i],\
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
    \        }\n    }\n\n    /**\n     * @brief \u884C\u5217\u5F0F\u3092 mod \u3067\
    \u5272\u3063\u305F\u4F59\u308A (mod \u306F\u7D20\u6570\u3067\u306A\u304F\u3066\
    \u3088\u3044) O(n^2 (n + log mod))\n     * @note \u8981\u7D20\u306F\u6574\u6570\
    \u578B\u3067\u3042\u308B\u3053\u3068\u3002\u5272\u308A\u7B97\u306E\u4EE3\u308F\
    \u308A\u306B\u30012 \u3064\u306E\u884C\u3067\u4E92\u9664\u6CD5\u306E\u3088\u3046\
    \u306B\u5F15\u304D\u5408\u3063\u3066 0 \u3092\u4F5C\u308B\n     */\n    [[nodiscard]]\n\
    \    long long det_mod(long long mod) const {\n        assert(n == m);\n     \
    \   assert(1 <= mod && mod <= (1LL << 31));\n        std::vector<std::vector<long\
    \ long>> a(n, std::vector<long long>(n));\n        for (long long i = 0; i < n;\
    \ i++)\n            for (long long j = 0; j < n; j++) a[i][j] = ((static_cast<long\
    \ long>(this->v[i][j]) % mod) + mod) % mod;\n        long long res = 1 % mod;\n\
    \        for (long long i = 0; i < n; i++) {\n            for (long long j = i\
    \ + 1; j < n; j++) {\n                // a[j][i] \u304C 0 \u306B\u306A\u308B\u307E\
    \u3067\u3001\u884C i \u304B\u3089\u884C j \u306E q \u500D\u3092\u5F15\u3044\u3066\
    \u5165\u308C\u66FF\u3048\u308B\n                while (a[j][i] != 0) {\n     \
    \               const long long q = a[i][i] / a[j][i];\n                    if\
    \ (q != 0) {\n                        for (long long k = i; k < n; k++) a[i][k]\
    \ = ((a[i][k] - q * a[j][k]) % mod + mod) % mod;\n                    }\n    \
    \                std::swap(a[i], a[j]);\n                    res = (mod - res)\
    \ % mod;\n                }\n            }\n            res = res * a[i][i] %\
    \ mod;\n            if (res == 0) return 0;\n        }\n        return res;\n\
    \    }\n\n    /**\n     * @brief \u7279\u6027\u591A\u9805\u5F0F det(xI - A) \u306E\
    \u4FC2\u6570 (\u4F4E\u6B21\u304B\u3089 n + 1 \u500B\u3001\u6700\u9AD8\u6B21\u306F\
    \ 1) O(n^3)\n     * @note \u5272\u308A\u7B97\u3092\u4F7F\u3046\u306E\u3067\u3001\
    \u8981\u7D20\u306F\u4F53 (modint \u306A\u3069) \u3067\u3042\u308B\u3053\u3068\n\
    \     *\n     * \u76F8\u4F3C\u5909\u63DB\u3067\u4E0A\u30D8\u30C3\u30BB\u30F3\u30D9\
    \u30EB\u30AF\u884C\u5217 (i > j + 1 \u3067 0) \u306B\u3057\u3066\u304B\u3089\u3001\
    \u5DE6\u4E0A\u306E k \xD7 k \u306E\u7279\u6027\u591A\u9805\u5F0F\u3092 k \u306E\
    \u5C0F\u3055\u3044\u65B9\u304B\u3089\u6C42\u3081\u308B\n     */\n    [[nodiscard]]\n\
    \    std::vector<T> characteristic_polynomial() const {\n        assert(n == m);\n\
    \        using P = OperatorProperty;\n        auto sub = [](const T& a, const\
    \ T& b) { return P::add(a, P::neg(b)); };\n        auto H = this->v;\n       \
    \ for (long long j = 0; j + 2 < n; j++) {\n            long long piv = j + 1;\n\
    \            while (piv < n && H[piv][j] == P::zero()) piv++;\n            if\
    \ (piv == n) continue;\n            if (piv != j + 1) {\n                std::swap(H[piv],\
    \ H[j + 1]);\n                for (long long i = 0; i < n; i++) std::swap(H[i][piv],\
    \ H[i][j + 1]);\n            }\n            const T iv = P::inv(H[j + 1][j]);\n\
    \            for (long long k = j + 2; k < n; k++) {\n                const T\
    \ c = P::mul(H[k][j], iv);\n                if (c == P::zero()) continue;\n  \
    \              // \u884C k \u304B\u3089\u884C j + 1 \u306E c \u500D\u3092\u5F15\
    \u304D\u3001\u5217 j + 1 \u306B\u5217 k \u306E c \u500D\u3092\u8DB3\u3059 (\u76F8\
    \u4F3C\u5909\u63DB)\n                for (long long l = 0; l < n; l++) H[k][l]\
    \ = sub(H[k][l], P::mul(c, H[j + 1][l]));\n                for (long long l =\
    \ 0; l < n; l++) H[l][j + 1] = P::add(H[l][j + 1], P::mul(c, H[l][k]));\n    \
    \        }\n        }\n        // p[k]: \u5DE6\u4E0A\u306E k \xD7 k \u306E\u7279\
    \u6027\u591A\u9805\u5F0F\n        // p[k + 1] = (x - H[k][k]) p[k] - \u03A3_{i\
    \ < k} (H[i + 1][i] ... H[k][k - 1]) H[i][k] p[i]\n        std::vector<std::vector<T>>\
    \ p(n + 1);\n        p[0] = {P::one()};\n        for (long long k = 0; k < n;\
    \ k++) {\n            std::vector<T> q(k + 2, P::zero());\n            for (long\
    \ long d = 0; d <= k; d++) {\n                q[d + 1] = P::add(q[d + 1], p[k][d]);\n\
    \                q[d] = sub(q[d], P::mul(H[k][k], p[k][d]));\n            }\n\
    \            T prod = P::one();\n            for (long long i = k - 1; i >= 0;\
    \ i--) {\n                prod = P::mul(prod, H[i + 1][i]);\n                if\
    \ (prod == P::zero()) break;\n                const T c = P::mul(prod, H[i][k]);\n\
    \                for (long long d = 0; d <= i; d++) q[d] = sub(q[d], P::mul(c,\
    \ p[i][d]));\n            }\n            p[k + 1] = std::move(q);\n        }\n\
    \        return p[n];\n    }\n\n    /**\n     * @brief \u30D1\u30FC\u30DE\u30CD\
    \u30F3\u30C8 \u03A3_\u03C3 \u03A0_i a[i][\u03C3(i)] (Ryser \u306E\u516C\u5F0F\
    ) O(2^n n)\n     * @return \u30D1\u30FC\u30DE\u30CD\u30F3\u30C8\n     * @note\
    \ \u5272\u308A\u7B97\u3092\u4F7F\u308F\u306A\u3044\u306E\u3067\u3001\u8981\u7D20\
    \u306F\u53EF\u63DB\u74B0 (long long \u3084 modint \u306A\u3069) \u3067\u3088\u3044\
    \u3002\n     *       0 \u3068 1 \u306E\u884C\u5217\u306A\u3089\u3001\u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u306E\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u500B\
    \u6570\u306B\u306A\u308B\n     *\n     * perm(A) = \u03A3_{S \u2286 \u5217} (-1)^{n\
    \ - |S|} \u03A0_i \u03A3_{j \u2208 S} a[i][j] \u3092\u3001S \u3092\u30B0\u30EC\
    \u30A4\u30B3\u30FC\u30C9\u306E\u9806\u306B\u52D5\u304B\u3057\u3066\u5404\u884C\
    \u306E\u548C\u3092 O(n) \u3067\u66F4\u65B0\u3059\u308B\n     */\n    [[nodiscard]]\n\
    \    T permanent() const {\n        assert(n == m);\n        assert(n < 63);\n\
    \        std::vector<T> row(n, OperatorProperty::zero());  // \u5404\u884C\u306E\
    \u3001S \u306B\u5165\u3063\u3066\u3044\u308B\u5217\u306E\u548C\n        T res\
    \ = OperatorProperty::zero();\n        long long size = 0;  // |S|\n        for\
    \ (long long k = 1; k < (1LL << n); k++) {\n            // \u30B0\u30EC\u30A4\u30B3\
    \u30FC\u30C9\u3067 k - 1 \u756A\u76EE\u304B\u3089 k \u756A\u76EE\u306B\u79FB\u308B\
    \u3068\u304D\u3001k \u306E\u6700\u4E0B\u4F4D\u30D3\u30C3\u30C8\u306E\u4F4D\u7F6E\
    \u306E\u5217\u304C\u51FA\u5165\u308A\u3059\u308B\n            long long j = 0;\n\
    \            while (!(k >> j & 1)) j++;\n            bool added = (k ^ (k >> 1))\
    \ >> j & 1;\n            size += added ? 1 : -1;\n            T prod = OperatorProperty::one();\n\
    \            for (long long i = 0; i < n; i++) {\n                row[i] = OperatorProperty::add(row[i],\
    \ added ? this->v[i][j] : OperatorProperty::neg(this->v[i][j]));\n           \
    \     prod = OperatorProperty::mul(prod, row[i]);\n            }\n           \
    \ res = OperatorProperty::add(res, (n - size) % 2 == 0 ? prod : OperatorProperty::neg(prod));\n\
    \        }\n        // S \u304C\u7A7A\u306E\u3068\u304D\u306E\u9805\u306F\u3001\
    n == 0 \u306A\u3089 1\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 0\n    \
    \    if (n == 0) res = OperatorProperty::one();\n        return res;\n    }\n\n\
    \    /**\n     * @brief \u9006\u884C\u5217\n     * @return \u9006\u884C\u5217\n\
    \     * @note det \u3068\u540C\u3058\u304F\u3001\u8981\u7D20\u306F\u4F53 (modint\
    \ \u3084\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u306A\u3069) \u3067\u3042\u308B\u3053\
    \u3068\n     */\n    [[nodiscard]]\n    Matrix inv() const {\n        assert(n\
    \ == m);\n        if (n == 0) return Matrix(n, n);\n        if constexpr (std::is_same_v<OperatorProperty,\
    \ matrix::OperatorPropertyDefault<T>>) {\n            std::vector A(n, std::valarray(T(0),\
    \ n + n));\n            for (long long i = 0; i < n; i++) {\n                for\
    \ (long long j = 0; j < n; j++) A[i][j] = this->v[i][j];\n                A[i][n\
    \ + i] = T(1);\n            }\n            [[maybe_unused]] T d = forward_elimination(A);\n\
    \            assert(d != T(0));\n            for (long long i = n - 1; i >= 0;\
    \ i--) {\n                for (long long j = i - 1; j >= 0; j--) {\n         \
    \           A[j] -= A[i] * A[j][i];\n                }\n            }\n      \
    \      Matrix ret(n, n);\n            for (long long i = 0; i < n; i++)\n    \
    \            for (long long j = 0; j < n; j++) ret[i][j] = A[i][n + j];\n    \
    \        return ret;\n        } else {\n            std::vector A(n, std::vector<T>(n\
    \ + n, OperatorProperty::zero()));\n            for (long long i = 0; i < n; i++)\
    \ {\n                for (long long j = 0; j < n; j++) A[i][j] = this->v[i][j];\n\
    \                A[i][n + i] = OperatorProperty::one();\n            }\n     \
    \       [[maybe_unused]] T d = forward_elimination(A);\n            assert(d !=\
    \ OperatorProperty::zero());\n            for (long long i = n - 1; i >= 0; i--)\
    \ {\n                for (long long j = i - 1; j >= 0; j--) {\n              \
    \      for (long long k = n; k < n + n; k++) {\n                        A[j][k]\
    \ = OperatorProperty::add(A[j][k], OperatorProperty::neg(OperatorProperty::mul(A[i][k],\
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
    \    }\n};\n\n/**\n * @brief \u884C\u306E\u30EA\u30B9\u30C8\u304B\u3089\u4F5C\u308B\
    \u3068\u304D\u306E\u63A8\u8AD6\u30AC\u30A4\u30C9\u3002\u8981\u7D20\u306E\u578B\
    \u306F\u5404\u884C\u306E value_type \u306B\u3059\u308B\n *\n * Matrix(std::vector<std::vector<int>>)\
    \ \u306F Matrix<int>\u3001Matrix(std::vector<std::string>) \u306F Matrix<char>\n\
    \ */\ntemplate <typename Iterable>\nMatrix(const std::vector<Iterable>&) -> Matrix<typename\
    \ Iterable::value_type>;\n"
  code: "#pragma once\n\n/**\n * @file matrix.hpp\n * @brief \u884C\u5217\n */\n\n\
    #include <algorithm>\n#include <cassert>\n#include <cmath>\n#if __cplusplus >=\
    \ 202002L\n#include <concepts>\n#endif\n#include <cstddef>\n#include <cstdint>\n\
    #include <initializer_list>\n#include <optional>\n#include <string>\n#include\
    \ <type_traits>\n#include <utility>\n#include <valarray>\n#include <vector>\n\n\
    namespace matrix {\ntemplate <typename T>\nstruct OperatorPropertyDefault {\n\
    \    constexpr static T zero() { return T(0); }\n    constexpr static T add(const\
    \ T& a, const T& b) { return a + b; }\n    constexpr static T neg(const T& a)\
    \ { return -a; }\n    constexpr static T one() { return T(1); }\n    constexpr\
    \ static T mul(const T& a, const T& b) { return a * b; }\n    constexpr static\
    \ T inv(const T& a) { return T(1) / a; }\n};\n}  // namespace matrix\n\nnamespace\
    \ internal_matrix {\n// \u6CD5\u304C 2^31 \u672A\u6E80\u306E modint (mod() \u3068\
    \ val() \u3092\u6301\u3064\u578B) \u304B\n#if __cplusplus >= 202002L\ntemplate\
    \ <class T>\nconcept modint_like = requires(const T& x) {\n    { T::mod() } ->\
    \ std::convertible_to<std::uint32_t>;\n    { x.val() } -> std::convertible_to<std::uint32_t>;\n\
    };\ntemplate <class T>\ninline constexpr bool is_modint_like_v = modint_like<T>;\n\
    #else\ntemplate <class T, class = void>\nstruct is_modint_like : std::false_type\
    \ {};\ntemplate <class T>\nstruct is_modint_like<T, std::void_t<decltype(static_cast<std::uint32_t>(T::mod())),\n\
    \                                     decltype(static_cast<std::uint32_t>(std::declval<const\
    \ T&>().val()))>>\n    : std::true_type {};\ntemplate <class T>\ninline constexpr\
    \ bool is_modint_like_v = is_modint_like<T>::value;\n#endif\n}  // namespace internal_matrix\n\
    \n/**\n * @brief \u884C\u5217\n * @tparam T \u578B \u884C\u5217(\u30B0\u30EA\u30C3\
    \u30C9)\u306E\u8981\u7D20\u3068\u306A\u308Bint\u3084char\n * @tparam OperatorProperty\
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
    \ long p = B.m;\n        if constexpr (std::is_same_v<OperatorProperty, matrix::OperatorPropertyDefault<T>>\
    \ &&\n                      internal_matrix::is_modint_like_v<T>) {\n        \
    \    // \u7A4D\u3092 64 \u30D3\u30C3\u30C8\u306E\u307E\u307E\u8DB3\u3057\u3001\
    \u3042\u3075\u308C\u308B\u524D\u306B\u3060\u3051 mod \u3092\u53D6\u308B\n    \
    \        // \u6CD5\u304C 2^30 \u7A0B\u5EA6\u307E\u3067\u306A\u3089 4 \u884C\u305A\
    \u3064\u307E\u3068\u3081\u3066\u8DB3\u3057\u3001acc \u306E\u8AAD\u307F\u66F8\u304D\
    \u3092\u6E1B\u3089\u3059\n            const std::uint64_t mod = T::mod();\n  \
    \          const std::uint64_t lim = UINT64_MAX / ((mod - 1) * (mod - 1) + 1)\
    \ - 1;\n            std::vector<std::uint32_t> b(m * p);\n            for (long\
    \ long k = 0; k < m; k++)\n                for (long long j = 0; j < p; j++) b[k\
    \ * p + j] = B[k][j].val();\n            std::vector<std::uint64_t> acc(p);\n\
    \            for (long long i = 0; i < n; i++) {\n                std::fill(acc.begin(),\
    \ acc.end(), 0);\n                std::uint64_t cnt = 0;\n                long\
    \ long k = 0;\n                if (lim >= 4) {\n                    for (; k +\
    \ 4 <= m; k += 4) {\n                        if (cnt + 4 > lim) {\n          \
    \                  cnt = 0;\n                            for (long long j = 0;\
    \ j < p; j++) acc[j] %= mod;\n                        }\n                    \
    \    cnt += 4;\n                        const auto& r = (*this)[i];\n        \
    \                const std::uint64_t a0 = r[k].val(), a1 = r[k + 1].val(), a2\
    \ = r[k + 2].val(), a3 = r[k + 3].val();\n                        const std::uint32_t\
    \ *b0 = b.data() + k * p, *b1 = b0 + p, *b2 = b1 + p, *b3 = b2 + p;\n        \
    \                for (long long j = 0; j < p; j++) acc[j] += a0 * b0[j] + a1 *\
    \ b1[j] + a2 * b2[j] + a3 * b3[j];\n                    }\n                }\n\
    \                for (; k < m; k++) {\n                    if (cnt + 1 > lim)\
    \ {\n                        cnt = 0;\n                        for (long long\
    \ j = 0; j < p; j++) acc[j] %= mod;\n                    }\n                 \
    \   cnt++;\n                    const std::uint64_t a0 = (*this)[i][k].val();\n\
    \                    const std::uint32_t* b0 = b.data() + k * p;\n           \
    \         for (long long j = 0; j < p; j++) acc[j] += a0 * b0[j];\n          \
    \      }\n                v[i].resize(p);\n                for (long long j =\
    \ 0; j < p; j++) v[i][j] = T(acc[j] % mod);\n            }\n            m = p;\n\
    \            return (*this);\n        }\n        Matrix C(n, p);\n        for\
    \ (long long i = 0; i < n; i++) {\n            for (long long k = 0; k < m; k++)\
    \ {\n                for (long long j = 0; j < p; j++) {\n                   \
    \ C[i][j] = OperatorProperty::add(C[i][j], OperatorProperty::mul((*this)[i][k],\
    \ B[k][j]));\n                }\n            }\n        }\n        v.swap(C.v);\n\
    \        m = p;\n        return (*this);\n    }\n\n    /**\n     * @brief \u4FDD\
    \u6301\u3057\u3066\u3044\u308B\u884C\u5217\u306Ek\u4E57\u3092\u6C42\u3081\u308B\
    \n     * @param k \u6307\u6570\n     * @return Matrix\n     */\n    [[nodiscard]]\n\
    \    Matrix pow(long long k) const {\n        Matrix A = *this, B(n, n);\n   \
    \     for (long long i = 0; i < n; i++) B[i][i] = OperatorProperty::one();\n \
    \       while (k > 0) {\n            if (k & 1) B *= A;\n            A *= A;\n\
    \            k >>= 1;\n        }\n        return B;\n    }\n\n    [[nodiscard]]\n\
    \    Matrix operator+(const Matrix& B) const { return (Matrix(*this) += B); }\n\
    \    [[nodiscard]]\n    Matrix operator-(const Matrix& B) const { return (Matrix(*this)\
    \ -= B); }\n    [[nodiscard]]\n    Matrix operator*(const Matrix& B) const { return\
    \ (Matrix(*this) *= B); }\n\n    /**\n     * @brief \u884C\u5217A\u3068\u5217\u30D9\
    \u30AF\u30C8\u30EBB\u306E\u7A4D\n     * @param A Matrix\n     * @param B vector<T>\n\
    \     * @return vector<T> \u5217\u30D9\u30AF\u30C8\u30EB\n     */\n    [[nodiscard]]\n\
    \    friend std::vector<T> operator*(const Matrix& A, const std::vector<T>& B)\
    \ {\n        assert(A.m == static_cast<long long>(B.size()));\n        std::vector<T>\
    \ ret(A.n, OperatorProperty::zero());\n        for (long long i = 0; i < A.n;\
    \ i++) {\n            for (long long j = 0; j < A.m; j++) {\n                ret[i]\
    \ = OperatorProperty::add(ret[i], OperatorProperty::mul(A[i][j], B[j]));\n   \
    \         }\n        }\n        return ret;\n    }\n\n    /**\n     * @brief \u884C\
    \u30D9\u30AF\u30C8\u30EBA\u3068\u884C\u5217B\u306E\u7A4D\n     * @param A vector<T>\n\
    \     * @param B Matrix\n     * @return vector<T> \u884C\u30D9\u30AF\u30C8\u30EB\
    \n     */\n    [[nodiscard]]\n    friend std::vector<T> operator*(const std::vector<T>&\
    \ A, const Matrix& B) {\n        assert(static_cast<long long>(A.size()) == B.n);\n\
    \        std::vector<T> ret(B.m, OperatorProperty::zero());\n        for (long\
    \ long i = 0; i < B.n; i++) {\n            for (long long j = 0; j < B.m; j++)\
    \ {\n                ret[j] = OperatorProperty::add(ret[j], OperatorProperty::mul(A[i],\
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
    \        }\n    }\n\n    /**\n     * @brief \u884C\u5217\u5F0F\u3092 mod \u3067\
    \u5272\u3063\u305F\u4F59\u308A (mod \u306F\u7D20\u6570\u3067\u306A\u304F\u3066\
    \u3088\u3044) O(n^2 (n + log mod))\n     * @note \u8981\u7D20\u306F\u6574\u6570\
    \u578B\u3067\u3042\u308B\u3053\u3068\u3002\u5272\u308A\u7B97\u306E\u4EE3\u308F\
    \u308A\u306B\u30012 \u3064\u306E\u884C\u3067\u4E92\u9664\u6CD5\u306E\u3088\u3046\
    \u306B\u5F15\u304D\u5408\u3063\u3066 0 \u3092\u4F5C\u308B\n     */\n    [[nodiscard]]\n\
    \    long long det_mod(long long mod) const {\n        assert(n == m);\n     \
    \   assert(1 <= mod && mod <= (1LL << 31));\n        std::vector<std::vector<long\
    \ long>> a(n, std::vector<long long>(n));\n        for (long long i = 0; i < n;\
    \ i++)\n            for (long long j = 0; j < n; j++) a[i][j] = ((static_cast<long\
    \ long>(this->v[i][j]) % mod) + mod) % mod;\n        long long res = 1 % mod;\n\
    \        for (long long i = 0; i < n; i++) {\n            for (long long j = i\
    \ + 1; j < n; j++) {\n                // a[j][i] \u304C 0 \u306B\u306A\u308B\u307E\
    \u3067\u3001\u884C i \u304B\u3089\u884C j \u306E q \u500D\u3092\u5F15\u3044\u3066\
    \u5165\u308C\u66FF\u3048\u308B\n                while (a[j][i] != 0) {\n     \
    \               const long long q = a[i][i] / a[j][i];\n                    if\
    \ (q != 0) {\n                        for (long long k = i; k < n; k++) a[i][k]\
    \ = ((a[i][k] - q * a[j][k]) % mod + mod) % mod;\n                    }\n    \
    \                std::swap(a[i], a[j]);\n                    res = (mod - res)\
    \ % mod;\n                }\n            }\n            res = res * a[i][i] %\
    \ mod;\n            if (res == 0) return 0;\n        }\n        return res;\n\
    \    }\n\n    /**\n     * @brief \u7279\u6027\u591A\u9805\u5F0F det(xI - A) \u306E\
    \u4FC2\u6570 (\u4F4E\u6B21\u304B\u3089 n + 1 \u500B\u3001\u6700\u9AD8\u6B21\u306F\
    \ 1) O(n^3)\n     * @note \u5272\u308A\u7B97\u3092\u4F7F\u3046\u306E\u3067\u3001\
    \u8981\u7D20\u306F\u4F53 (modint \u306A\u3069) \u3067\u3042\u308B\u3053\u3068\n\
    \     *\n     * \u76F8\u4F3C\u5909\u63DB\u3067\u4E0A\u30D8\u30C3\u30BB\u30F3\u30D9\
    \u30EB\u30AF\u884C\u5217 (i > j + 1 \u3067 0) \u306B\u3057\u3066\u304B\u3089\u3001\
    \u5DE6\u4E0A\u306E k \xD7 k \u306E\u7279\u6027\u591A\u9805\u5F0F\u3092 k \u306E\
    \u5C0F\u3055\u3044\u65B9\u304B\u3089\u6C42\u3081\u308B\n     */\n    [[nodiscard]]\n\
    \    std::vector<T> characteristic_polynomial() const {\n        assert(n == m);\n\
    \        using P = OperatorProperty;\n        auto sub = [](const T& a, const\
    \ T& b) { return P::add(a, P::neg(b)); };\n        auto H = this->v;\n       \
    \ for (long long j = 0; j + 2 < n; j++) {\n            long long piv = j + 1;\n\
    \            while (piv < n && H[piv][j] == P::zero()) piv++;\n            if\
    \ (piv == n) continue;\n            if (piv != j + 1) {\n                std::swap(H[piv],\
    \ H[j + 1]);\n                for (long long i = 0; i < n; i++) std::swap(H[i][piv],\
    \ H[i][j + 1]);\n            }\n            const T iv = P::inv(H[j + 1][j]);\n\
    \            for (long long k = j + 2; k < n; k++) {\n                const T\
    \ c = P::mul(H[k][j], iv);\n                if (c == P::zero()) continue;\n  \
    \              // \u884C k \u304B\u3089\u884C j + 1 \u306E c \u500D\u3092\u5F15\
    \u304D\u3001\u5217 j + 1 \u306B\u5217 k \u306E c \u500D\u3092\u8DB3\u3059 (\u76F8\
    \u4F3C\u5909\u63DB)\n                for (long long l = 0; l < n; l++) H[k][l]\
    \ = sub(H[k][l], P::mul(c, H[j + 1][l]));\n                for (long long l =\
    \ 0; l < n; l++) H[l][j + 1] = P::add(H[l][j + 1], P::mul(c, H[l][k]));\n    \
    \        }\n        }\n        // p[k]: \u5DE6\u4E0A\u306E k \xD7 k \u306E\u7279\
    \u6027\u591A\u9805\u5F0F\n        // p[k + 1] = (x - H[k][k]) p[k] - \u03A3_{i\
    \ < k} (H[i + 1][i] ... H[k][k - 1]) H[i][k] p[i]\n        std::vector<std::vector<T>>\
    \ p(n + 1);\n        p[0] = {P::one()};\n        for (long long k = 0; k < n;\
    \ k++) {\n            std::vector<T> q(k + 2, P::zero());\n            for (long\
    \ long d = 0; d <= k; d++) {\n                q[d + 1] = P::add(q[d + 1], p[k][d]);\n\
    \                q[d] = sub(q[d], P::mul(H[k][k], p[k][d]));\n            }\n\
    \            T prod = P::one();\n            for (long long i = k - 1; i >= 0;\
    \ i--) {\n                prod = P::mul(prod, H[i + 1][i]);\n                if\
    \ (prod == P::zero()) break;\n                const T c = P::mul(prod, H[i][k]);\n\
    \                for (long long d = 0; d <= i; d++) q[d] = sub(q[d], P::mul(c,\
    \ p[i][d]));\n            }\n            p[k + 1] = std::move(q);\n        }\n\
    \        return p[n];\n    }\n\n    /**\n     * @brief \u30D1\u30FC\u30DE\u30CD\
    \u30F3\u30C8 \u03A3_\u03C3 \u03A0_i a[i][\u03C3(i)] (Ryser \u306E\u516C\u5F0F\
    ) O(2^n n)\n     * @return \u30D1\u30FC\u30DE\u30CD\u30F3\u30C8\n     * @note\
    \ \u5272\u308A\u7B97\u3092\u4F7F\u308F\u306A\u3044\u306E\u3067\u3001\u8981\u7D20\
    \u306F\u53EF\u63DB\u74B0 (long long \u3084 modint \u306A\u3069) \u3067\u3088\u3044\
    \u3002\n     *       0 \u3068 1 \u306E\u884C\u5217\u306A\u3089\u3001\u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u306E\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u500B\
    \u6570\u306B\u306A\u308B\n     *\n     * perm(A) = \u03A3_{S \u2286 \u5217} (-1)^{n\
    \ - |S|} \u03A0_i \u03A3_{j \u2208 S} a[i][j] \u3092\u3001S \u3092\u30B0\u30EC\
    \u30A4\u30B3\u30FC\u30C9\u306E\u9806\u306B\u52D5\u304B\u3057\u3066\u5404\u884C\
    \u306E\u548C\u3092 O(n) \u3067\u66F4\u65B0\u3059\u308B\n     */\n    [[nodiscard]]\n\
    \    T permanent() const {\n        assert(n == m);\n        assert(n < 63);\n\
    \        std::vector<T> row(n, OperatorProperty::zero());  // \u5404\u884C\u306E\
    \u3001S \u306B\u5165\u3063\u3066\u3044\u308B\u5217\u306E\u548C\n        T res\
    \ = OperatorProperty::zero();\n        long long size = 0;  // |S|\n        for\
    \ (long long k = 1; k < (1LL << n); k++) {\n            // \u30B0\u30EC\u30A4\u30B3\
    \u30FC\u30C9\u3067 k - 1 \u756A\u76EE\u304B\u3089 k \u756A\u76EE\u306B\u79FB\u308B\
    \u3068\u304D\u3001k \u306E\u6700\u4E0B\u4F4D\u30D3\u30C3\u30C8\u306E\u4F4D\u7F6E\
    \u306E\u5217\u304C\u51FA\u5165\u308A\u3059\u308B\n            long long j = 0;\n\
    \            while (!(k >> j & 1)) j++;\n            bool added = (k ^ (k >> 1))\
    \ >> j & 1;\n            size += added ? 1 : -1;\n            T prod = OperatorProperty::one();\n\
    \            for (long long i = 0; i < n; i++) {\n                row[i] = OperatorProperty::add(row[i],\
    \ added ? this->v[i][j] : OperatorProperty::neg(this->v[i][j]));\n           \
    \     prod = OperatorProperty::mul(prod, row[i]);\n            }\n           \
    \ res = OperatorProperty::add(res, (n - size) % 2 == 0 ? prod : OperatorProperty::neg(prod));\n\
    \        }\n        // S \u304C\u7A7A\u306E\u3068\u304D\u306E\u9805\u306F\u3001\
    n == 0 \u306A\u3089 1\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 0\n    \
    \    if (n == 0) res = OperatorProperty::one();\n        return res;\n    }\n\n\
    \    /**\n     * @brief \u9006\u884C\u5217\n     * @return \u9006\u884C\u5217\n\
    \     * @note det \u3068\u540C\u3058\u304F\u3001\u8981\u7D20\u306F\u4F53 (modint\
    \ \u3084\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u306A\u3069) \u3067\u3042\u308B\u3053\
    \u3068\n     */\n    [[nodiscard]]\n    Matrix inv() const {\n        assert(n\
    \ == m);\n        if (n == 0) return Matrix(n, n);\n        if constexpr (std::is_same_v<OperatorProperty,\
    \ matrix::OperatorPropertyDefault<T>>) {\n            std::vector A(n, std::valarray(T(0),\
    \ n + n));\n            for (long long i = 0; i < n; i++) {\n                for\
    \ (long long j = 0; j < n; j++) A[i][j] = this->v[i][j];\n                A[i][n\
    \ + i] = T(1);\n            }\n            [[maybe_unused]] T d = forward_elimination(A);\n\
    \            assert(d != T(0));\n            for (long long i = n - 1; i >= 0;\
    \ i--) {\n                for (long long j = i - 1; j >= 0; j--) {\n         \
    \           A[j] -= A[i] * A[j][i];\n                }\n            }\n      \
    \      Matrix ret(n, n);\n            for (long long i = 0; i < n; i++)\n    \
    \            for (long long j = 0; j < n; j++) ret[i][j] = A[i][n + j];\n    \
    \        return ret;\n        } else {\n            std::vector A(n, std::vector<T>(n\
    \ + n, OperatorProperty::zero()));\n            for (long long i = 0; i < n; i++)\
    \ {\n                for (long long j = 0; j < n; j++) A[i][j] = this->v[i][j];\n\
    \                A[i][n + i] = OperatorProperty::one();\n            }\n     \
    \       [[maybe_unused]] T d = forward_elimination(A);\n            assert(d !=\
    \ OperatorProperty::zero());\n            for (long long i = n - 1; i >= 0; i--)\
    \ {\n                for (long long j = i - 1; j >= 0; j--) {\n              \
    \      for (long long k = n; k < n + n; k++) {\n                        A[j][k]\
    \ = OperatorProperty::add(A[j][k], OperatorProperty::neg(OperatorProperty::mul(A[i][k],\
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
    \    }\n};\n\n/**\n * @brief \u884C\u306E\u30EA\u30B9\u30C8\u304B\u3089\u4F5C\u308B\
    \u3068\u304D\u306E\u63A8\u8AD6\u30AC\u30A4\u30C9\u3002\u8981\u7D20\u306E\u578B\
    \u306F\u5404\u884C\u306E value_type \u306B\u3059\u308B\n *\n * Matrix(std::vector<std::vector<int>>)\
    \ \u306F Matrix<int>\u3001Matrix(std::vector<std::string>) \u306F Matrix<char>\n\
    \ */\ntemplate <typename Iterable>\nMatrix(const std::vector<Iterable>&) -> Matrix<typename\
    \ Iterable::value_type>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.hpp
  requiredBy: []
  timestamp: '2026-10-24 03:47:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/math/f2-matrix.test.cpp
  - test/unittest/math/matrix.test.cpp
  - test/aoj/volume33/3314.test.cpp
  - test/yosupo/graph/counting-spanning-tree-undirected.test.cpp
  - test/yosupo/graph/counting-spanning-tree-directed.test.cpp
  - test/yosupo/linear_algebra/pow-of-matrix.test.cpp
  - test/yosupo/linear_algebra/characteristic-polynomial.test.cpp
  - test/yosupo/linear_algebra/matrix-det-arbitrary-mod.test.cpp
  - test/yosupo/linear_algebra/matrix-product.test.cpp
  - test/yosupo/linear_algebra/inverse-matrix.test.cpp
  - test/yosupo/linear_algebra/matrix-rank.test.cpp
  - test/yosupo/linear_algebra/system-of-linear-equations.test.cpp
  - test/yosupo/linear_algebra/matrix-det.test.cpp
  - test/yukicoder/565.1.test.cpp
  - test/yukicoder/565.2.test.cpp
  - test/yukicoder/1340.test.cpp
documentation_of: src/math/matrix.hpp
layout: document
title: "\u884C\u5217"
---

行列 `Matrix<T, OperatorProperty>` です。線形代数の行列としても、文字のグリッド (`Matrix<char>`) としても使えます。

```cpp
Matrix<mint> A({ {1, 1}, {1, 0} });
auto F = A.pow(n);                    // フィボナッチ数列の行列累乗

std::vector<std::string> s(h);        // グリッドを読み込んで回転する
Matrix<char> g(s);
auto t = g.rotate(1).vstr();          // 時計回りに 90 度回して vector<string> に戻す
```

`OperatorProperty` には要素の演算 (`zero`、`add`、`neg`、`one`、`mul`、`inv`) を定義した型を渡します。省略すると通常の `+`、`*` になります。xor と and の環など、別の演算を使う場合は自分で定義します。使わない演算は定義しなくてもかまいません。

`OperatorProperty` を省略した modint (`mod()` と `val()` を持つ型) の積は、積を 64 ビットのまま足してあふれる前にだけ mod を取るので、1024 次の積が 0.5 秒ほどで求まります。`pow` も同じ積を使います。

## コンストラクタ・アクセス

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Matrix({ {a, b}, {c, d} })` | 初期化子リストから作る | $O(nm)$ |
| `Matrix(v)` | `vector<vector<T>>` や `vector<string>` から作る。型を省くと、要素の型は各行の `value_type` になる (`vector<vector<int>>` なら `Matrix<int>`、`vector<string>` なら `Matrix<char>`) | $O(nm)$ |
| `Matrix(n, m, val = 0)` | `n` 行 `m` 列で、要素はすべて `val` | $O(nm)$ |
| `A.size()` | 行数 (`long long`) | $O(1)$ |
| `A[i][j]` | 要素 | $O(1)$ |
| `for (auto& row : A)` | 各行を走査 | $O(n)$ |
| `A.col(j)` | `j` 列目 | $O(n)$ |
| `A.str(i)` / `A.vstr()` | `i` 行目を `string` で / 全体を `vector<string>` で返す | $O(m)$ / $O(nm)$ |
| `==`、`!=` | 比較 | $O(nm)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `n` / `m` | 行数 / 列数 (`long long`) |

## 線形代数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `A + B`、`A - B`、`+=`、`-=` | 和・差 | $O(nm)$ |
| `A * B`、`*=` | 積 | $O(nmp)$ |
| `A * x` / `x * A` | 列ベクトル / 行ベクトルとの積 (`vector<T>` を返す) | $O(nm)$ |
| `A.pow(k)` | $A^k$ | $O(n^3 \log k)$ |
| `A.det()` | 行列式 | $O(n^3)$ |
| `A.det_mod(mod)` | 行列式を `mod` で割った余り。`mod` は素数でなくてよい ($1 \le$ `mod` $\le 2^{31}$)。要素は整数型であること。割り算の代わりに 2 つの行を互除法のように引き合って消去する | $O(n^2 (n + \log \mathrm{mod}))$ |
| `A.permanent()` | パーマネント $\sum_\sigma \prod_i a_{i \sigma(i)}$ (Ryser の公式)。割り算を使わないので `long long` でもよい。0 と 1 の行列なら二部グラフの完全マッチングの個数 | $O(2^n n)$ |
| `A.inv()` | 逆行列 (正則でなければ assert で落ちる) | $O(n^3)$ |
| `A.characteristic_polynomial()` | 特性多項式 $\det(xI - A)$ の係数 (`std::vector<T>`、低次から $n + 1$ 個、最高次は 1)。ヘッセンベルク行列に変形して求める | $O(n^3)$ |

`det`、`inv`、`characteristic_polynomial` は割り算を使うので、要素は体 (`modint` や浮動小数点型など) である必要があります。`int` や `long long` のような整数型では割り算が切り捨てになり、正しい値になりません (例: `Matrix<long long>({ {2, 1}, {1, 1} }).det()` は 1 ではなく 2 を返す)。整数の行列の行列式は、十分大きい素数を法とする `modint` で計算してください。素数でない数を法とする行列式は `det_mod` で求められます。

浮動小数点型なら部分ピボット選択を行い、絶対値が $10^{-9}$ 未満を 0 とみなします。

## 連立一次方程式

```cpp
Matrix<mint> A(n, m);       // n 本の式、m 個の変数
std::vector<mint> b(n);
auto sol = A.solve(b);      // Ax = b
if (!sol) { /* 解なし */ }
sol->x;                     // 解の 1 つ (特殊解)
sol->basis;                 // Ax = 0 の解空間の基底。解全体は x + (basis の一次結合)
long long r = A.rank();
auto [R, pivots] = A.reduced_row_echelon();
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `A.solve(b)` | 連立一次方程式 $Ax = b$ の解 `Solution` (`x` と `basis`)。解がなければ `std::nullopt` | $O(nm \min(n, m))$ |
| `A.rank()` | ランク | $O(nm \min(n, m))$ |
| `A.kernel()` | $Ax = 0$ の解空間の基底 (長さ $m$ のベクトルを $m - \mathrm{rank}$ 個) | $O(nm \min(n, m))$ |
| `A.reduced_row_echelon()` | 簡約化した行列 (各行の主成分が 1 で、主成分のある列の他の成分が 0) と、各行の主成分の列 `{R, pivots}`。`pivots` の個数がランクで、0 だけの行は下にまとまる | $O(nm \min(n, m))$ |

- 解は、主成分のない列 (自由変数) を 0 にした特殊解と、自由変数を 1 つだけ 1 にした基底で表します。mod $p$ なら解の個数は $p^{\lvert basis \rvert}$ で、解が 1 つに決まるのは `basis` が空のときです。
- 要素は体である必要があり、`modint` を想定しています。浮動小数点型では 0 かどうかを `==` で判定するので、誤差のある計算には使えません。
- mod 2 の連立一次方程式は、64 要素ずつまとめて計算する [F2 の行列](f2-matrix.hpp) のほうが速いです。

## グリッド操作

いずれも新しい行列を返します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `A.transpose()` | 転置 | $O(nm)$ |
| `A.rev_lr()` / `A.rev_ud()` | 左右反転 / 上下反転 | $O(nm)$ |
| `A.rotate(k)` | 時計回りに 90 度を `k` 回 (負なら反時計回り) | $O(nm)$ |
| `A.shift(dy, dx)` | $(i, j)$ を $((i + dy) \bmod n, (j + dx) \bmod m)$ に巡回シフト | $O(nm)$ |
| `A.shift_l(k)`、`shift_r(k)`、`shift_u(k)`、`shift_d(k)` | 左・右・上・下に `k` 回巡回シフト | $O(nm)$ |

## 関連

- `det`、`inv`、`solve` で使う体の要素は [modint](modint.hpp)
- mod 2 の行列は [F2 の行列](f2-matrix.hpp)
- 行列累乗の代わりに漸化式を多項式で扱うなら [形式的冪級数](fps.hpp)
- 二部グラフの最大マッチングは [二部グラフの最大マッチング](../graph/bipartite-matching.hpp) (完全マッチングの個数は `permanent`)
