---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/group.hpp
    title: "\u7FA4\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/potentialized-unionfind.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
  bundledCode: "#line 1 \"test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n\n#include <iostream>\n\n#line 2 \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n\
    \ * @brief \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067\
    \ mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n */\n\n#line 9 \"src/math/modint.hpp\"\
    \n#include <utility>\n#include <limits>\n#include <type_traits>\n#include <cstdint>\n\
    #include <cassert>\n\nnamespace detail {\n    static constexpr std::uint16_t prime32_bases[]\
    \ {\n        15591,  2018,  166, 7429,  8064, 16045, 10503,  4399,  1949,  1295,\
    \ 2776,  3620,   560,  3128,  5212,  2657,\n         2300,  2021, 4652, 1471,\
    \  9336,  4018,  2398, 20462, 10277,  8028, 2213,  6219,   620,  3763,  4852,\
    \  5012,\n         3185,  1333, 6227, 5298,  1074,  2391,  5113,  7061,   803,\
    \  1269, 3875,   422,   751,   580,  4729, 10239,\n          746,  2951,  556,\
    \ 2206,  3778,   481,  1522,  3476,   481,  2487, 3266,  5633,   488,  3373, \
    \ 6441,  3344,\n           17, 15105, 1490, 4154,  2036,  1882,  1813,   467,\
    \  3307, 14042, 6371,   658,  1005,   903,   737,  1887,\n         7447,  1888,\
    \ 2848, 1784,  7559,  3400,   951, 13969,  4304,   177,   41, 19875,  3110, 13221,\
    \  8726,   571,\n         7043,  6943, 1199,  352,  6435,   165,  1169,  3315,\
    \   978,   233, 3003,  2562,  2994, 10587, 10030,  2377,\n         1902,  5354,\
    \ 4447, 1555,   263, 27027,  2283,   305,   669,  1912,  601,  6186,   429,  1930,\
    \ 14873,  1784,\n         1661,   524, 3577,  236,  2360,  6146,  2850, 55637,\
    \  1753,  4178, 8466,   222,  2579,  2743,  2031,  2226,\n         2276,   374,\
    \ 2132,  813, 23788,  1610,  4422,  5159,  1725,  3597, 3366, 14336,   579,  \
    \ 165,  1375, 10018,\n        12616,  9816, 1371,  536,  1867, 10864,   857, \
    \ 2206,  5788,   434, 8085, 17618,   727,  3639,  1595,  4944,\n         2129,\
    \  2029, 8195, 8344,  6232,  9183,  8126,  1870,  3296,  7455, 8947, 25017,  \
    \ 541, 19115,   368,   566,\n         5674,   411,  522, 1027,  8215,  2050, \
    \ 6544, 10049,   614,   774, 2333,  3007, 35201,  4706,  1152,  1785,\n      \
    \   1028,  1540, 3743,  493,  4474,  2521, 26845,  8354,   864, 18915, 5465, \
    \ 2447,    42,  4511,  1660,   166,\n         1249,  6259, 2553,  304,   272,\
    \  7286,    73,  6554,   899,  2816, 5197, 13330,  7054,  2818,  3199,   811,\n\
    \          922,   350, 7514, 4452,  3449,  2663,  4708,   418,  1621,  1171, 3471,\
    \    88, 11345,   412,  1559,   194,\n    };\n\n    static constexpr bool is_SPRP(std::uint32_t\
    \ n, std::uint32_t a) noexcept {\n        std::uint32_t d = n - 1;\n        std::uint32_t\
    \ s = 0;\n        while ((d & 1) == 0) {\n            ++s;\n            d >>=\
    \ 1;\n        }\n        std::uint64_t cur = 1;\n        std::uint64_t pw = d;\n\
    \        while (pw) {\n            if (pw & 1) cur = (cur * a) % n;\n        \
    \    a = (static_cast<std::uint64_t>(a) * a) % n;\n            pw >>= 1;\n   \
    \     }\n        if (cur == 1) return true;\n        for (std::uint32_t r = 0;\
    \ r < s; ++r) {\n            if (cur == n - 1) return true;\n            cur =\
    \ (cur * cur) % n;\n        }\n        return false;\n    }\n\n    // 32\u30D3\
    \u30C3\u30C8\u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u7D20\u6570\u5224\u5B9A\
    \n    // \u53C2\u8003: M. Forisek and J. Jancina, \u201CFast Primality Testing\
    \ for Integers That Fit into a Machine Word,\u201D presented at the Conference\
    \ on Current Trends in Theory and Practice of Informatics, 2015.\n    [[nodiscard]]\n\
    \    static constexpr bool is_prime32(std::uint32_t x) noexcept {\n        if\
    \ (x == 2 || x == 3 || x == 5 || x == 7) return true;\n        if (x % 2 == 0\
    \ || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n        if (x < 121)\
    \ return (x > 1);\n        std::uint64_t h = x;\n        h = ((h >> 16) ^ h) *\
    \ 0x45d9f3b;\n        h = ((h >> 16) ^ h) * 0x45d9f3b;\n        h = ((h >> 16)\
    \ ^ h) & 0xff;\n        return is_SPRP(x, prime32_bases[h]);\n    }\n}\n\n///\
    \ @brief static_modint \u3068 dynamic_modint \u306E\u5B9F\u88C5\u3092 CRTP \u306B\
    \u3088\u3063\u3066\u884C\u3046\u305F\u3081\u306E\u30AF\u30E9\u30B9\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\n/// @tparam Modint \u3053\u306E\u30AF\u30E9\u30B9\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u7D99\u627F\u3059\u308B\u30AF\u30E9\u30B9\
    \ntemplate <class Modint>\nclass modint_base {\npublic:\n    /// @brief \u4FDD\
    \u6301\u3059\u308B\u5024\u306E\u578B\n    using value_type = std::uint32_t;\n\n\
    \    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ modint_base() noexcept\n        : m_value{ 0 } {}\n\n    /// @brief @c value\
    \ \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    ///\
    \ @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class\
    \ SignedIntegral, std::enable_if_t<std::is_integral_v<SignedIntegral> && std::is_signed_v<SignedIntegral>>*\
    \ = nullptr>\n    constexpr modint_base(SignedIntegral value) noexcept\n     \
    \   : m_value{ static_cast<value_type>((static_cast<long long>(value) % Modint::mod()\
    \ + Modint::mod()) % Modint::mod()) } {}\n\n    /// @brief @c value \u306E\u5270\
    \u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\
    \u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class UnsignedIntegral, std::enable_if_t<std::is_integral_v<UnsignedIntegral>\
    \ && std::is_unsigned_v<UnsignedIntegral>>* = nullptr>\n    constexpr modint_base(UnsignedIntegral\
    \ value) noexcept\n        : m_value{ static_cast<value_type>(value % Modint::mod())\
    \ } {}\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u53D6\
    \u5F97\u3057\u307E\u3059\u3002\n    /// @return \u4FDD\u6301\u3057\u3066\u3044\
    \u308B\u5024\n    [[nodiscard]]\n    constexpr value_type value() const noexcept\
    \ {\n        return m_value;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n\
    \    constexpr Modint& operator++() noexcept {\n        ++m_value;\n        if\
    \ (m_value == Modint::mod()) {\n            m_value = 0;\n        }\n        return\
    \ static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n\
    \    constexpr Modint operator++(int) noexcept {\n        auto x = static_cast<const\
    \ Modint&>(*this);\n        ++*this;\n        return x;\n    }\n\n    /// @brief\
    \ \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\
    \u30C8\u3057\u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n   \
    \ /// @return @c *this\n    constexpr Modint& operator--() noexcept {\n      \
    \  if (m_value == 0) {\n            m_value = Modint::mod();\n        }\n    \
    \    --m_value;\n        return static_cast<Modint&>(*this);\n    }\n\n    ///\
    \ @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\
    \u30F3\u30C8\u3057\u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\
    \n    /// @return @c *this\n    constexpr Modint operator--(int) noexcept {\n\
    \        auto x = static_cast<const Modint&>(*this);\n        --*this;\n     \
    \   return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\
    \u306B @c x \u306E\u6301\u3064\u5024\u3092\u8DB3\u3057\u3066\u3001\u5270\u4F59\
    \u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x \u8DB3\u3059\u6570\n  \
    \  /// @return @c *this\n    constexpr Modint& operator+=(const Modint& x) noexcept\
    \ {\n        m_value += x.m_value;\n        if (m_value >= Modint::mod()) {\n\
    \            m_value -= Modint::mod();\n        }\n        return static_cast<Modint&>(*this);\n\
    \    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u304B\u3089\
    \ @c x \u306E\u6301\u3064\u5024\u3092\u5F15\u3044\u3066\u3001\u5270\u4F59\u3092\
    \u53D6\u308A\u307E\u3059\u3002\n    /// @param x \u5F15\u304F\u6570\n    /// @return\
    \ @c *this\n    constexpr Modint& operator-=(const Modint& x) noexcept {\n   \
    \     m_value -= x.m_value;\n        if (m_value >= Modint::mod()) {\n       \
    \     m_value += Modint::mod();\n        }\n        return static_cast<Modint&>(*this);\n\
    \    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u306B @c x\
    \ \u306E\u6301\u3064\u5024\u3092\u639B\u3051\u3066\u3001\u5270\u4F59\u3092\u53D6\
    \u308A\u307E\u3059\u3002\n    /// @param x \u639B\u3051\u308B\u6570\n    /// @return\
    \ @c *this\n    constexpr Modint& operator*=(const Modint& x) noexcept {\n   \
    \     m_value = static_cast<value_type>(static_cast<std::uint64_t>(m_value) *\
    \ x.m_value % Modint::mod());\n        return static_cast<Modint&>(*this);\n \
    \   }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092 @c x\
    \ \u306E\u6301\u3064\u5024\u3067\u5272\u3063\u3066\u3001\u5270\u4F59\u3092\u53D6\
    \u308A\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A\
    \ @f$O(\\log x)@f$\n    /// @param x \u5272\u308B\u6570\n    /// @return @c *this\n\
    \    constexpr Modint& operator/=(const Modint& x) noexcept {\n        return\
    \ *this *= x.inv();\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u30B3\u30D4\u30FC\
    \u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @return @c *this\n    [[nodiscard]]\n\
    \    constexpr Modint operator+() const noexcept {\n        return static_cast<const\
    \ Modint&>(*this);\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u53CD\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @return \u81EA\u8EAB\u306E\u53CD\u6570\
    \n    [[nodiscard]]\n    constexpr Modint operator-() const noexcept {\n     \
    \   return 0 - static_cast<const Modint&>(*this);\n    }\n\n    /// @brief \u81EA\
    \u8EAB\u306E @c n \u4E57\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @remark\
    \ \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log n)@f$\n    /// @param n \u6307\
    \u6570\n    /// @return \u81EA\u8EAB\u306E @c n \u4E57\n    [[nodiscard]]\n  \
    \  constexpr Modint pow(unsigned long long n) const noexcept {\n        Modint\
    \ x = 1;\n        Modint y = static_cast<const Modint&>(*this);\n        while\
    \ (n) {\n            if (n & 1) {\n                x *= y;\n            }\n  \
    \          y *= y;\n            n >>= 1;\n        }\n        return x;\n    }\n\
    \n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\u3002\
    \n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ Modint inv() const noexcept {\n        long long a = Modint::mod();\n      \
    \  long long b = m_value;\n        long long x = 0;\n        long long y = 1;\n\
    \        while (b) {\n            auto t = a / b;\n            auto u = a - t\
    \ * b;\n            a = b;\n            b = u;\n            u = x - t * y;\n \
    \           x = y;\n            y = u;\n        }\n        assert(a == 1 && \"\
    The inverse element does not exist.\");\n        x %= Modint::mod();\n       \
    \ if (x < 0) {\n            x += Modint::mod();\n        }\n        return x;\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3055\u308C\u308B\u6570\n    /// @param y \u8DB3\u3059\u6570\n    ///\
    \ @return @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator+(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{ x } += y);\n\
    \    }\n\n    /// @brief @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304B\u308C\u308B\u6570\n    /// @param y \u5F15\u304F\u6570\n    ///\
    \ @return @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator-(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{ x } -= y);\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u3089\u308C\u308B\u6570\n    /// @param y \u639B\u3051\u308B\u6570\
    \n    /// @return @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator*(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{ x } *= y);\n\
    \    }\n\n    /// @brief @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u5272\u3089\u308C\u308B\u6570\n    /// @param y \u5272\u308B\u6570\n    ///\
    \ @return @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator/(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{ x } /= y);\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\u307E\u3059\
    \u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\u304C\
    \u7B49\u3057\u3051\u308C\u3070 @c true \u3001\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 @c false\n    [[nodiscard]]\n    friend constexpr bool operator==(const\
    \ Modint& x, const Modint& y) noexcept {\n        return x.m_value == y.m_value;\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u304F\u306A\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\
    \u307E\u3059\u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\
    \u5024\u304C\u7B49\u3057\u3051\u308C\u3070 @c false \u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070 @c true\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Modint& x, const Modint& y) noexcept {\n        return not (x == y);\n    }\n\
    \n    /// @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\u7B26\u53F7\
    \u4ED8\u304D\u6574\u6570\u3092\u8AAD\u307F\u53D6\u308A\u3001 @c x \u306B\u683C\
    \u7D0D\u3057\u307E\u3059\u3002\n    /// @tparam CharT \u5165\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n    /// @tparam Traits \u5165\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n   \
    \ /// @param is \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n    /// @param x \u5165\
    \u529B\u3092\u53D7\u3051\u53D6\u308B\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n   \
    \ /// @return @c is\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Modint& x) {\n  \
    \      long long tmp;\n        is >> tmp;\n        x = tmp;\n        return is;\n\
    \    }\n\n    /// @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306B @c x\
    \ \u306E\u4FDD\u6301\u3059\u308B\u5024\u3092\u51FA\u529B\u3057\u307E\u3059\u3002\
    \n    /// @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\
    \u5B57\u578B\n    /// @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n    /// @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n    /// @param x \u51FA\u529B\u3059\u308B\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\n    /// @return @c os\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Modint& x) {\n        os << x.value();\n        return os;\n\
    \    }\n\nprotected:\n    value_type m_value;\n};\n\n/// @brief \u30B3\u30F3\u30D1\
    \u30A4\u30EB\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\u56DB\
    \u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\
    \u30AF\u30E9\u30B9\n/// @tparam Mod \u6CD5\ntemplate <std::uint32_t Mod>\nclass\
    \ static_modint : public modint_base<static_modint<Mod>> {\n    static_assert(Mod\
    \ > 0 && Mod <= std::numeric_limits<std::uint32_t>::max() / 2);\n\nprivate:\n\
    \    using base_type = modint_base<static_modint<Mod>>;\n\npublic:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static constexpr\
    \ value_type mod() noexcept {\n        return Mod;\n    }\n\n    /// @brief 0\
    \ \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr static_modint()\
    \ noexcept\n        : base_type{} {}\n\n    /// @brief @c value \u306E\u5270\u4F59\
    \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\u671F\
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, std::enable_if_t<std::is_integral_v<SignedIntegral>>*\
    \ = nullptr>\n    constexpr static_modint(SignedIntegral value) noexcept\n   \
    \     : base_type{value} {}\n\n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\
    \uFF1A @f$O(\\log value)@f$\n    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n\
    \    [[nodiscard]]\n    constexpr static_modint inv() const noexcept {\n     \
    \   if constexpr (detail::is_prime32(Mod)) {\n            assert(this->m_value\
    \ != 0 && \"The inverse element of zero does not exist.\");\n            return\
    \ this->pow(Mod - 2);\n        }\n        else {\n            return base_type::inv();\n\
    \        }\n    }\n};\n\n/// @brief \u5B9F\u884C\u6642\u306B\u6CD5\u304C\u6C7A\
    \u307E\u308B\u3068\u304D\u3001\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\
    \u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n/// @tparam ID \u3053\
    \u306EID\u3054\u3068\u306B\u6CD5\u3092\u8A2D\u5B9A\u3059\u308B\u3053\u3068\u304C\
    \u3067\u304D\u307E\u3059\ntemplate <int ID>\nclass dynamic_modint : public modint_base<dynamic_modint<ID>>\
    \ {\nprivate:\n    using base_type = modint_base<dynamic_modint<ID>>;\n\npublic:\n\
    \    using typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\
    \u5F97\u3057\u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n  \
    \  static value_type mod() noexcept {\n        return modulus;\n    }\n\n    ///\
    \ @brief \u6CD5\u3092\u8A2D\u5B9A\u3057\u307E\u3059\u3002\n    /// @param m \u65B0\
    \u3057\u3044\u6CD5\n    static void set_mod(value_type m) noexcept {\n       \
    \ assert(m > 0 && m <= std::numeric_limits<value_type>::max() / 2);\n        modulus\
    \ = m;\n    }\n\n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\
    \n    constexpr dynamic_modint() noexcept\n        : base_type{} {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class SignedIntegral, std::enable_if_t<std::is_integral_v<SignedIntegral>>*\
    \ = nullptr>\n    constexpr dynamic_modint(SignedIntegral value) noexcept\n  \
    \      : base_type{value} {}\n\nprivate:\n    inline static value_type modulus\
    \ = 998244353;\n};\n\nusing modint998244353 = static_modint<998244353>;\nusing\
    \ modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    #line 2 \"src/data_structures/potentialized-unionfind.hpp\"\n\n/**\n * @file potentialized-unionfind.hpp\n\
    \ * @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind\n */\n#include\
    \ <algorithm>\n#line 9 \"src/data_structures/potentialized-unionfind.hpp\"\n#include\
    \ <functional>\n#include <stack>\n#line 12 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n#include <vector>\n#line 2 \"src/algebra/group.hpp\"\n\n/**\n * @file group.hpp\n\
    \ * @brief \u7FA4\u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\
    \u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * -\
    \ S inv(const S& a): \u9006\u5143\n */\n\n#line 2 \"src/algebra/monoid.hpp\"\n\
    \n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#line 16 \"src/algebra/monoid.hpp\"\n#include <numeric>\n\
    #line 19 \"src/algebra/monoid.hpp\"\n\nnamespace monoid {\n\n/**\n * @brief \u548C\
    \n */\ntemplate <typename T>\nstruct Sum {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return a + b; }\n    static constexpr S e() {\
    \ return S(0); }\n};\n\n/**\n * @brief \u7A4D\n */\ntemplate <typename T>\nstruct\
    \ Prod {\n    using S = T;\n    static constexpr S op(const S& a, const S& b)\
    \ { return a * b; }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n\
    \ * @brief \u6700\u5927\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\
    \u5024\n */\ntemplate <typename T>\nstruct Max {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return std::max(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::lowest(); }\n};\n\n/**\n *\
    \ @brief \u6700\u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nstruct Min {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return std::min(a, b); }\n    static constexpr\
    \ S e() { return std::numeric_limits<S>::max(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max}\n */\ntemplate <typename\
    \ T>\nstruct MinMax {\n    using S = std::pair<T, T>;\n    static constexpr S\
    \ op(const S& a, const S& b) { return {std::min(a.first, b.first), std::max(a.second,\
    \ b.second)}; }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::lowest()}; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\
    \u8AD6\u7406\u548C\n */\ntemplate <typename T>\nstruct Xor {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return a ^ b; }\n    static\
    \ constexpr S e() { return S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\u7A4D\n\
    \ */\ntemplate <typename T>\nstruct And {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return a & b; }\n    static constexpr S e() {\
    \ return ~S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\u548C\n */\ntemplate <typename\
    \ T>\nstruct Or {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a | b; }\n    static constexpr S e() { return S(0); }\n};\n\n\
    /**\n * @brief \u6700\u5927\u516C\u7D04\u6570 \u5358\u4F4D\u5143\u306F0\n */\n\
    template <typename T>\nstruct Gcd {\n    static_assert(std::is_integral_v<T>);\n\
    \    using S = T;\n    static constexpr S op(const S& a, const S& b) { return\
    \ std::gcd(a, b); }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u6700\u5C0F\u516C\u500D\u6570 \u5358\u4F4D\u5143\u306F1\n */\ntemplate\
    \ <typename T>\nstruct Lcm {\n    static_assert(std::is_integral_v<T>);\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return std::lcm(a,\
    \ b); }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief 1\u6B21\
    \u95A2\u6570 f(x) = first * x + second \u306E\u5408\u6210\n * op(f, g) = g\u2218\
    f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3059\u308B)\n * \u533A\u9593 [l,\
    \ r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\n */\ntemplate <typename\
    \ T>\nstruct Composite {\n    using S = std::pair<T, T>;\n    static constexpr\
    \ S op(const S& f, const S& g) { return {g.first * f.first, g.first * f.second\
    \ + g.second}; }\n    static constexpr S e() { return {T(1), T(0)}; }\n};\n\n\
    /**\n * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis {\n    struct\
    \ S {\n        long long close; // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u306E\u500B\u6570\n        long long open;  // \u5BFE\u5FDC\u306E\u53D6\
    \u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\n        constexpr S(char\
    \ c = 0) : close(c == ')'), open(c == '(') {}\n        constexpr S(long long close,\
    \ long long open) : close(close), open(open) {}\n        /**\n         * @brief\
    \ \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n         */\n        constexpr bool\
    \ is_valid() const { return close == 0 && open == 0; }\n    };\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        if(a.open >= b.close) return S(a.close,\
    \ a.open - b.close + b.open);\n        return S(a.close + b.close - a.open, b.open);\n\
    \    }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\
    \u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\
    \u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate\
    \ <typename T, typename U = int>\nstruct MinWith {\n    using S = std::pair<T,\
    \ U>;\n    static constexpr S op(const S& a, const S& b) { return b.first < a.first\
    \ ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E\
    \ \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam\
    \ T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\
    \u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename T, typename U = int>\n\
    struct MaxWith {\n    using S = std::pair<T, U>;\n    static constexpr S op(const\
    \ S& a, const S& b) { return a.first < b.first ? b : a; }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U{}}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MinCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if(a.first < b.first) return\
    \ a;\n        if(b.first < a.first) return b;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MaxCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if(a.first < b.first) return b;\n        if(b.first < a.first) return\
    \ a;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U(0)}; }\n};\n\n} // namespace\
    \ monoid\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\
    \u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u30E2\u30CE\
    \u30A4\u30C9\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * \u4F8B\
    : SegTree seg(v, Monoid([](int a, int b) { return std::max(a, b); }, -1));\n *\n\
    \ * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename\
    \ Op>\nstruct Monoid {\n    using S = T;\n    Op op_object;\n    S identity;\n\
    \    Monoid() = default;\n    constexpr Monoid(Op op, const S& e) : op_object(std::move(op)),\
    \ identity(e) {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a,\
    \ b); }\n    constexpr S e() const { return identity; }\n};\ntemplate <typename\
    \ Op, typename T>\nMonoid(Op, T) -> Monoid<T, Op>;\n#line 12 \"src/algebra/group.hpp\"\
    \n\nnamespace group {\n\n/**\n * @brief \u52A0\u6CD5\u7FA4\n */\ntemplate <typename\
    \ T>\nstruct Sum : monoid::Sum<T> {\n    using S = T;\n    static constexpr S\
    \ inv(const S& a) { return -a; }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7FA4 (0\u3092\
    \u542B\u307E\u306A\u3044\u4F53\u306E\u5143\u306A\u3069)\n */\ntemplate <typename\
    \ T>\nstruct Prod : monoid::Prod<T> {\n    using S = T;\n    static constexpr\
    \ S inv(const S& a) { return S(1) / a; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\
    \u8AD6\u7406\u548C\n */\ntemplate <typename T>\nstruct Xor : monoid::Xor<T> {\n\
    \    using S = T;\n    static constexpr S inv(const S& a) { return a; }\n};\n\n\
    } // namespace group\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\u3068\u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\
    \u7FA4\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam T\
    \ \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306E\u578B\n * @tparam Inv \u9006\u5143\u306E\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename\
    \ Op, typename Inv>\nstruct Group {\n    using S = T;\n    Op op_object;\n   \
    \ S identity;\n    Inv inv_object;\n    Group() = default;\n    constexpr Group(Op\
    \ op, const S& e, Inv inv) : op_object(std::move(op)), identity(e), inv_object(std::move(inv))\
    \ {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a, b);\
    \ }\n    constexpr S e() const { return identity; }\n    constexpr S inv(const\
    \ S& a) const { return inv_object(a); }\n};\ntemplate <typename Op, typename T,\
    \ typename Inv>\nGroup(Op, T, Inv) -> Group<T, Op, Inv>;\n#line 14 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n\n/**\n * @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind\n\
    \ * @tparam G \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u7FA4 (algebra/group.hpp)\
    \ \u975E\u53EF\u63DB\u3067\u3082\u3088\u3044\n */\ntemplate <typename G>\nclass\
    \ PotentializedUnionFind {\n   public:\n    using S = typename G::S;\n\n   private:\n\
    \    G g;\n    int _n;\n    // \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\
    \u8CA0\u306A\u3089\u89AA\n    std::vector<int> parent_or_size;\n    // \u91CD\u307F\
    \n    std::vector<S> diff_weight;\n\n    S op(const S& a, const S& b) const {\
    \ return g.op(a, b); }\n    S e() const { return g.e(); }\n    S inv(const S&\
    \ a) const { return g.inv(a); }\n\n   public:\n    /**\n     * @param n \u8981\
    \u7D20\u6570\n     * @param g \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u7FA4\
    \n     */\n    explicit PotentializedUnionFind(int n = 0, G g = G()) : g(std::move(g)),\
    \ _n(n), parent_or_size(n, -1), diff_weight(n, e()) {}\n\n    /**\n     * @brief\
    \ \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\
    \u5143\n     */\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n\
    \        if (parent_or_size[a] < 0) return a;\n        std::stack<int> stk;\n\
    \        stk.push(a);\n        while (parent_or_size[stk.top()] >= 0) {\n    \
    \        stk.push(parent_or_size[stk.top()]);\n        }\n        const int root\
    \ = stk.top();\n        stk.pop();\n        stk.pop();\n        while (!stk.empty())\
    \ {\n            diff_weight[stk.top()] = op(diff_weight[parent_or_size[stk.top()]],\
    \ diff_weight[stk.top()]);\n            parent_or_size[stk.top()] = root;\n  \
    \          stk.pop();\n        }\n        return root;\n    }\n\n    /**\n   \
    \  * @brief a \u306E\u30B0\u30EB\u30FC\u30D7\u3068 b \u306E\u30B0\u30EB\u30FC\u30D7\
    \u3092\u7D71\u5408\u3059\u308B\n     * @param w (b \u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB) - (a \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)\n     * @return\
    \ \u9023\u7D50\u3057\u305F\u3082\u306E\u306E\u4EE3\u8868\u5143\n     */\n    int\
    \ merge(int a, int b, S w) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        w = op(weight(a), w);\n        w = op(w, inv(weight(b)));\n\
    \        int x = leader(a), y = leader(b);\n        if (x == y) return x;\n  \
    \      if (-parent_or_size[x] < -parent_or_size[y]) {\n            std::swap(x,\
    \ y);\n            w = inv(w);\n        }\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        diff_weight[y] = w;\n        return x;\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\
    \u3046\u304B\n     */\n    bool same(int a, int b) {\n        assert(0 <= a &&\
    \ a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n\
    \    }\n\n    /**\n     * @brief (b \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    ) - (a \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)\n     */\n    S diff(int a,\
    \ int b) {\n        assert(same(a, b));\n        return op(inv(weight(a)), weight(b));\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\
    \u6210\u5206\u306E\u30B5\u30A4\u30BA\n     */\n    int size(int a) {\n       \
    \ assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n\
    \n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\
    \u5206\u3051\u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\
    \u4E00\u3064\u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\
    \u30EA\u30B9\u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(result.begin(), result.end(),\
    \ [&](const std::vector<int>& v) { return v.empty(); }), result.end());\n    \
    \    return result;\n    }\n\n   private:\n    S weight(int a) {\n        leader(a);\n\
    \        return diff_weight[a];\n    }\n};\n\ntemplate <typename G>\nPotentializedUnionFind(int,\
    \ G) -> PotentializedUnionFind<G>;\n#line 7 \"test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp\"\
    \n\nusing mint = modint998244353;\nstruct Matrix_2x2 {\n    mint a, b, c, d;\n\
    };\n\nbool operator==(const Matrix_2x2& t1, const Matrix_2x2& t2) {\n    return\
    \ t1.a == t2.a && t1.b == t2.b && t1.c == t2.c && t1.d == t2.d;\n}\n\nstruct MatrixGroup\
    \ {\n    using S = Matrix_2x2;\n    static S op(const S& f, const S& g) {\n  \
    \      return {f.a * g.a + f.b * g.c,\n                f.a * g.b + f.b * g.d,\n\
    \                f.c * g.a + f.d * g.c,\n                f.c * g.b + f.d * g.d};\n\
    \    }\n    static S e() {\n        return {1, 0, 0, 1};\n    }\n    static S\
    \ inv(const S& f) {\n        mint detinv = (f.a * f.d - f.b * f.c).inv();\n  \
    \      return {f.d * detinv, -f.b * detinv, -f.c * detinv, f.a * detinv};\n  \
    \  }\n};\n\ntemplate <typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Matrix_2x2& m) {\n\
    \    is >> m.a >> m.b >> m.c >> m.d;\n    return is;\n}\ntemplate <typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Matrix_2x2& m) {\n    os << m.a << CharT(' ') << m.b << CharT('\
    \ ') << m.c << CharT(' ') << m.d;\n    return os;\n}\n\nint main() {\n    int\
    \ N, Q;\n    std::cin >> N >> Q;\n    PotentializedUnionFind<MatrixGroup> uf(N);\n\
    \    while (Q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int u, v, x00, x01, x10, x11;\n            std::cin >> u >> v\
    \ >> x00 >> x01 >> x10 >> x11;\n            Matrix_2x2 m{x00, x01, x10, x11};\n\
    \            if (uf.same(u, v)) {\n                if (uf.diff(v, u) == m) {\n\
    \                    std::cout << 1 << std::endl;\n                } else {\n\
    \                    std::cout << 0 << std::endl;\n                }\n       \
    \     } else {\n                uf.merge(v, u, m);\n                std::cout\
    \ << 1 << std::endl;\n            }\n        } else {\n            int u, v;\n\
    \            std::cin >> u >> v;\n            if (uf.same(u, v)) {\n         \
    \       std::cout << uf.diff(v, u) << std::endl;\n            } else {\n     \
    \           std::cout << -1 << std::endl;\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n\n#include <iostream>\n\n#include \"../src/math/modint.hpp\"\n#include \"../src/data_structures/potentialized-unionfind.hpp\"\
    \n\nusing mint = modint998244353;\nstruct Matrix_2x2 {\n    mint a, b, c, d;\n\
    };\n\nbool operator==(const Matrix_2x2& t1, const Matrix_2x2& t2) {\n    return\
    \ t1.a == t2.a && t1.b == t2.b && t1.c == t2.c && t1.d == t2.d;\n}\n\nstruct MatrixGroup\
    \ {\n    using S = Matrix_2x2;\n    static S op(const S& f, const S& g) {\n  \
    \      return {f.a * g.a + f.b * g.c,\n                f.a * g.b + f.b * g.d,\n\
    \                f.c * g.a + f.d * g.c,\n                f.c * g.b + f.d * g.d};\n\
    \    }\n    static S e() {\n        return {1, 0, 0, 1};\n    }\n    static S\
    \ inv(const S& f) {\n        mint detinv = (f.a * f.d - f.b * f.c).inv();\n  \
    \      return {f.d * detinv, -f.b * detinv, -f.c * detinv, f.a * detinv};\n  \
    \  }\n};\n\ntemplate <typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Matrix_2x2& m) {\n\
    \    is >> m.a >> m.b >> m.c >> m.d;\n    return is;\n}\ntemplate <typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Matrix_2x2& m) {\n    os << m.a << CharT(' ') << m.b << CharT('\
    \ ') << m.c << CharT(' ') << m.d;\n    return os;\n}\n\nint main() {\n    int\
    \ N, Q;\n    std::cin >> N >> Q;\n    PotentializedUnionFind<MatrixGroup> uf(N);\n\
    \    while (Q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int u, v, x00, x01, x10, x11;\n            std::cin >> u >> v\
    \ >> x00 >> x01 >> x10 >> x11;\n            Matrix_2x2 m{x00, x01, x10, x11};\n\
    \            if (uf.same(u, v)) {\n                if (uf.diff(v, u) == m) {\n\
    \                    std::cout << 1 << std::endl;\n                } else {\n\
    \                    std::cout << 0 << std::endl;\n                }\n       \
    \     } else {\n                uf.merge(v, u, m);\n                std::cout\
    \ << 1 << std::endl;\n            }\n        } else {\n            int u, v;\n\
    \            std::cin >> u >> v;\n            if (uf.same(u, v)) {\n         \
    \       std::cout << uf.diff(v, u) << std::endl;\n            } else {\n     \
    \           std::cout << -1 << std::endl;\n            }\n        }\n    }\n}\n"
  dependsOn:
  - src/math/modint.hpp
  - src/data_structures/potentialized-unionfind.hpp
  - src/algebra/group.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: true
  path: test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp
  requiredBy: []
  timestamp: '2026-10-11 23:34:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp
- /verify/test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp.html
title: test/yosupo-unionfind-with-potential-non-commutative-group.test.cpp
---
