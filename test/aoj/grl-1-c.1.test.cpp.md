---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/infint.hpp
    title: "inf \u3092\u6301\u3064\u6574\u6570\u578B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/aoj/grl-1-c.1.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/math/infint.hpp\"\n\
    \n/**\n * @file infint.hpp\n * @brief inf \u3092\u6301\u3064\u6574\u6570\u578B\
    \n */\n\n#include <algorithm>\n#include <cstdlib>\n#line 11 \"src/math/infint.hpp\"\
    \n#include <limits>\n#include <ostream>\n#include <string>\n#include <string_view>\n\
    #include <type_traits>\n\n/**\n * inf\u3092\u3082\u3064\u6574\u6570\u578B\n *\
    \ T\u306F\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3067\u3042\u308A\u30012\u306E\u88DC\
    \u6570\u8868\u73FE\u3067\u8868\u3055\u308C\u308B\u3053\u3068\u3092\u671F\u5F85\
    \u3059\u308B\n */\ntemplate <typename T = long long>\nstruct infint {\n   private:\n\
    \    static_assert(std::is_integral_v<T> and std::is_signed_v<T>);\n    static_assert(std::numeric_limits<T>::min()\
    \ + 1 == -std::numeric_limits<T>::max());\n\n    T _v;\n\n    inline constexpr\
    \ static T plus_inf_value = std::numeric_limits<T>::max();       //!< \u6B63\u306E\
    \u7121\u9650\u5927\n    inline constexpr static T minus_inf_value = std::numeric_limits<T>::min()\
    \ + 1;  //!< \u8CA0\u306E\u7121\u9650\u5927\n    inline constexpr static T nan_value\
    \ = std::numeric_limits<T>::min();           //!< Not a Number\n    static std::string\
    \ str_plusinf;\n    static std::string str_minusinf;\n    static std::string str_nan;\n\
    \n   public:\n    constexpr infint() noexcept : _v(0) {}\n    constexpr infint(const\
    \ T& t) noexcept : _v(t) {}\n    constexpr infint(const infint& o) noexcept :\
    \ _v(o._v) {}\n    infint(std::string_view sv) noexcept(false) {\n        std::string\
    \ s(sv);\n        std::for_each(s.begin(), s.end(), [](char& c) {\n          \
    \  if ('A' <= c and c <= 'Z') {\n                c = c - 'A' + 'a';\n        \
    \    }\n        });\n        if (s == \"plusinf\") {\n            _v = plus_inf_value;\n\
    \        } else if (s == \"inf\") {\n            _v = plus_inf_value;\n      \
    \  } else if (s == \"minusinf\") {\n            _v = minus_inf_value;\n      \
    \  } else if (s == \"nan\") {\n            _v = nan_value;\n        } else {\n\
    \            _v = std::stoll(s);\n        }\n    }\n\n    /**\n     * \u5185\u90E8\
    \u8868\u73FE\u3092\u305D\u306E\u307E\u307E\u8FD4\u3059\n     */\n    constexpr\
    \ T val() const noexcept { return _v; }\n\n    constexpr bool is_nan() const noexcept\
    \ { return _v == nan_value; }\n    constexpr bool is_plus_inf() const noexcept\
    \ { return _v == plus_inf_value; }\n    constexpr bool is_minus_inf() const noexcept\
    \ { return _v == minus_inf_value; }\n    constexpr bool is_inf() const noexcept\
    \ { return _v == plus_inf_value; }\n    constexpr bool is_finite() const noexcept\
    \ { return minus_inf_value < _v and _v < plus_inf_value; }\n\n    constexpr infint&\
    \ operator=(const infint& o) noexcept {\n        _v = o._v;\n        return *this;\n\
    \    }\n    constexpr infint& operator=(const T& t) noexcept {\n        _v = t;\n\
    \        return *this;\n    }\n\n    constexpr infint operator+() const noexcept\
    \ { return _v; }\n    constexpr infint operator-() const noexcept {\n        if\
    \ (_v == nan_value) return _v;\n        return -_v;\n    }\n    constexpr infint&\
    \ operator*=(const infint& o) noexcept {\n        if (is_nan() or o.is_nan())\
    \ {\n            _v = nan_value;\n            return *this;\n        }\n     \
    \   if (not is_finite() or not o.is_finite()) {\n            if (_v == 0 or o._v\
    \ == 0) {\n                _v = nan_value;\n            } else if ((_v > 0) ^\
    \ (o._v > 0)) {\n                _v = minus_inf_value;\n            } else {\n\
    \                _v = plus_inf_value;\n            }\n            return *this;\n\
    \        }\n        if (_v == 0 or o._v == 0) {\n            _v = 0;\n       \
    \     return *this;\n        }\n        // \u6709\u9650\u306E\u5024\u306E\u6700\
    \u5927\u306F plus_inf_value - 1\n        if (std::abs(_v) > (plus_inf_value -\
    \ 1) / std::abs(o._v)) {\n            if ((_v > 0) ^ (o._v > 0)) {\n         \
    \       _v = minus_inf_value;\n            } else {\n                _v = plus_inf_value;\n\
    \            }\n            return *this;\n        }\n        _v *= o._v;\n  \
    \      return *this;\n    }\n    constexpr infint& operator/=(const infint& o)\
    \ noexcept {\n        if (is_nan() or o.is_nan()) {\n            _v = nan_value;\n\
    \            return *this;\n        }\n        if (not is_finite() and not o.is_finite())\
    \ {\n            _v = nan_value;\n            return *this;\n        }\n     \
    \   if (o._v == 0) {\n            _v = nan_value;\n            return *this;\n\
    \        }\n        if (not o.is_finite()) {\n            _v = 0;\n          \
    \  return *this;\n        }\n        if (not is_finite()) {\n            // \xB1\
    inf / \u6709\u9650 = \xB1inf (\u7B26\u53F7\u306F\u5546\u306E\u7B26\u53F7)\n  \
    \          if ((_v > 0) ^ (o._v > 0)) {\n                _v = minus_inf_value;\n\
    \            } else {\n                _v = plus_inf_value;\n            }\n \
    \           return *this;\n        }\n        _v /= o._v;\n        return *this;\n\
    \    }\n    constexpr infint& operator%=(const infint& o) noexcept {\n       \
    \ if (is_nan() or o.is_nan()) {\n            _v = nan_value;\n            return\
    \ *this;\n        }\n        if (not is_finite() and not o.is_finite()) {\n  \
    \          _v = nan_value;\n            return *this;\n        }\n        if (o._v\
    \ == 0) {\n            _v = nan_value;\n            return *this;\n        }\n\
    \        if (not is_finite()) {\n            // \xB1inf % \u6709\u9650 \u306F\u5B9A\
    \u307E\u3089\u306A\u3044 (\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u306E fmod \u3068\
    \u540C\u3058\u304F NaN)\n            _v = nan_value;\n            return *this;\n\
    \        }\n        if (not o.is_finite()) {\n            return *this;\n    \
    \    }\n        _v %= o._v;\n        return *this;\n    }\n    constexpr infint&\
    \ operator+=(const infint& o) noexcept {\n        if (is_nan() or o.is_nan())\
    \ {\n            _v = nan_value;\n            return *this;\n        }\n     \
    \   if (not is_finite() or not o.is_finite()) {\n            if (not is_finite()\
    \ and not o.is_finite()) {\n                if (is_plus_inf() ^ o.is_plus_inf())\
    \ {\n                    _v = nan_value;\n                }\n            } else\
    \ if (not o.is_finite()) {\n                _v = o._v;\n            }\n      \
    \      return *this;\n        }\n        if (o._v > 0) {\n            if (_v >=\
    \ plus_inf_value - o._v) {\n                _v = plus_inf_value;\n           \
    \     return *this;\n            }\n        } else if (o._v < 0) {\n         \
    \   if (_v <= minus_inf_value - o._v) {\n                _v = minus_inf_value;\n\
    \                return *this;\n            }\n        }\n        _v += o._v;\n\
    \        return *this;\n    }\n    constexpr infint& operator-=(const infint&\
    \ o) noexcept {\n        if (is_nan() or o.is_nan()) {\n            _v = nan_value;\n\
    \            return *this;\n        }\n        if (not is_finite() or not o.is_finite())\
    \ {\n            if (not is_finite() and not o.is_finite()) {\n              \
    \  if (is_plus_inf() == o.is_plus_inf()) {\n                    _v = nan_value;\n\
    \                }\n            } else if (not o.is_finite()) {\n            \
    \    _v = -o._v;\n            }\n            return *this;\n        }\n      \
    \  if (o._v > 0) {\n            if (_v <= minus_inf_value + o._v) {\n        \
    \        _v = minus_inf_value;\n                return *this;\n            }\n\
    \        } else if (o._v < 0) {\n            if (_v >= plus_inf_value + o._v)\
    \ {\n                _v = plus_inf_value;\n                return *this;\n   \
    \         }\n        }\n        _v -= o._v;\n        return *this;\n    }\n  \
    \  static std::string type_str() { return \"infint<>\"; }\n    std::string initializer_str()\
    \ const {\n        if (_v == plus_inf_value) {\n            return \"{\\\"plusinf\\\
    \"}\";\n        } else if (_v == minus_inf_value) {\n            return \"{\\\"\
    minusinf\\\"}\";\n        } else if (_v == nan_value) {\n            return \"\
    {\\\"nan\\\"}\";\n        } else {\n            return \"{\" + std::to_string(_v)\
    \ + \"}\";\n        }\n    }\n    std::string repr() const {\n        return this->type_str()\
    \ + this->initializer_str();\n    }\n    std::string to_string() const {\n   \
    \     if (_v == plus_inf_value) {\n            return str_plusinf;\n        }\
    \ else if (_v == minus_inf_value) {\n            return str_minusinf;\n      \
    \  } else if (_v == nan_value) {\n            return str_nan;\n        } else\
    \ {\n            return std::to_string(_v);\n        }\n    }\n    template <class\
    \ CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const infint& rhs) {\n        os << rhs.to_string();\n        return\
    \ os;\n    }\n    static void set_str_plusinf(std::string s) {\n        str_plusinf\
    \ = s;\n    }\n    static void set_str_minusinf(std::string s) {\n        str_minusinf\
    \ = s;\n    }\n    static void set_str_nan(std::string s) {\n        str_nan =\
    \ s;\n    }\n\n    /**\n     * \u6B63\u306E\u7121\u9650\u5927\n     */\n    constexpr\
    \ static infint plus_inf() noexcept {\n        return plus_inf_value;\n    }\n\
    \    /**\n     * \u8CA0\u306E\u7121\u9650\u5927\n     */\n    constexpr static\
    \ infint minus_inf() noexcept {\n        return minus_inf_value;\n    }\n    /**\n\
    \     * Not a Number\n     */\n    constexpr static infint nan() noexcept {\n\
    \        return nan_value;\n    }\n    /**\n     * \u6B63\u306E\u7121\u9650\u5927\
    (plus_inf \u3068\u540C\u3058)\n     */\n    constexpr static infint inf() noexcept\
    \ {\n        return plus_inf_value;\n    }\n    /**\n     * \u6B63\u306E\u7121\
    \u9650\u5927\u3067\u306A\u3044\u6700\u5927\u5024\n     */\n    constexpr static\
    \ infint max() noexcept {\n        return plus_inf_value - 1;\n    }\n    /**\n\
    \     * \u8CA0\u306E\u7121\u9650\u5927\u3067\u306A\u3044\u6700\u5C0F\u5024\n \
    \    */\n    constexpr static infint min() noexcept {\n        return minus_inf_value\
    \ + 1;\n    }\n\n    friend constexpr infint operator*(const infint& t1, const\
    \ infint& t2) noexcept {\n        infint res(t1);\n        return res *= t2;\n\
    \    }\n    friend constexpr infint operator/(const infint& t1, const infint&\
    \ t2) noexcept {\n        infint res(t1);\n        return res /= t2;\n    }\n\
    \    friend constexpr infint operator%(const infint& t1, const infint& t2) noexcept\
    \ {\n        infint res(t1);\n        return res %= t2;\n    }\n    friend constexpr\
    \ infint operator+(const infint& t1, const infint& t2) noexcept {\n        infint\
    \ res(t1);\n        return res += t2;\n    }\n    friend constexpr infint operator-(const\
    \ infint& t1, const infint& t2) noexcept {\n        infint res(t1);\n        return\
    \ res -= t2;\n    }\n    friend constexpr bool operator<(const infint& t1, const\
    \ infint& t2) noexcept {\n        if (t1.is_nan() or t2.is_nan()) return false;\n\
    \        return t1._v < t2._v;\n    }\n    friend constexpr bool operator>(const\
    \ infint& t1, const infint& t2) noexcept {\n        if (t1.is_nan() or t2.is_nan())\
    \ return false;\n        return t1._v > t2._v;\n    }\n    friend constexpr bool\
    \ operator<=(const infint& t1, const infint& t2) noexcept {\n        if (t1.is_nan()\
    \ or t2.is_nan()) return false;\n        return t1._v <= t2._v;\n    }\n    friend\
    \ constexpr bool operator>=(const infint& t1, const infint& t2) noexcept {\n \
    \       if (t1.is_nan() or t2.is_nan()) return false;\n        return t1._v >=\
    \ t2._v;\n    }\n    friend constexpr bool operator==(const infint& t1, const\
    \ infint& t2) noexcept {\n        return t1._v == t2._v;\n    }\n    friend constexpr\
    \ bool operator!=(const infint& t1, const infint& t2) noexcept {\n        return\
    \ t1._v != t2._v;\n    }\n};\ntemplate <typename T>\nstd::string infint<T>::str_plusinf\
    \ = \"inf\";\ntemplate <typename T>\nstd::string infint<T>::str_minusinf = \"\
    -inf\";\ntemplate <typename T>\nstd::string infint<T>::str_nan = \"nan\";\n#line\
    \ 7 \"test/aoj/grl-1-c.1.test.cpp\"\n\nint main() {\n    using I = infint<long\
    \ long>;\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<std::vector<I>>\
    \ d(n, std::vector<I>(n, I::inf()));\n    for (int i = 0; i < n; i++) d[i][i]\
    \ = 0;\n    for (int i = 0; i < m; i++) {\n        int s, t;\n        long long\
    \ w;\n        std::cin >> s >> t >> w;\n        d[s][t] = w;\n    }\n    // \u7121\
    \u9650\u5927\u306B\u6709\u9650\u306E\u5024\u3092\u8DB3\u3057\u3066\u3082\u7121\
    \u9650\u5927\u306E\u307E\u307E\u306A\u306E\u3067\u3001\u5230\u9054\u4E0D\u80FD\
    \u3092\u7279\u5225\u6271\u3044\u305B\u305A\u306B\u66F8\u3051\u308B\n    for (int\
    \ k = 0; k < n; k++) {\n        for (int i = 0; i < n; i++) {\n            for\
    \ (int j = 0; j < n; j++) {\n                I c = d[i][k] + d[k][j];\n      \
    \          if (c < d[i][j]) d[i][j] = c;\n            }\n        }\n    }\n  \
    \  for (int i = 0; i < n; i++) {\n        if (d[i][i] < 0) {\n            std::cout\
    \ << \"NEGATIVE CYCLE\" << '\\n';\n            return 0;\n        }\n    }\n \
    \   for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n   \
    \         if (j) std::cout << ' ';\n            if (d[i][j].is_plus_inf()) std::cout\
    \ << \"INF\";\n            else std::cout << d[i][j];\n        }\n        std::cout\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/math/infint.hpp\"\
    \n\nint main() {\n    using I = infint<long long>;\n    int n, m;\n    std::cin\
    \ >> n >> m;\n    std::vector<std::vector<I>> d(n, std::vector<I>(n, I::inf()));\n\
    \    for (int i = 0; i < n; i++) d[i][i] = 0;\n    for (int i = 0; i < m; i++)\
    \ {\n        int s, t;\n        long long w;\n        std::cin >> s >> t >> w;\n\
    \        d[s][t] = w;\n    }\n    // \u7121\u9650\u5927\u306B\u6709\u9650\u306E\
    \u5024\u3092\u8DB3\u3057\u3066\u3082\u7121\u9650\u5927\u306E\u307E\u307E\u306A\
    \u306E\u3067\u3001\u5230\u9054\u4E0D\u80FD\u3092\u7279\u5225\u6271\u3044\u305B\
    \u305A\u306B\u66F8\u3051\u308B\n    for (int k = 0; k < n; k++) {\n        for\
    \ (int i = 0; i < n; i++) {\n            for (int j = 0; j < n; j++) {\n     \
    \           I c = d[i][k] + d[k][j];\n                if (c < d[i][j]) d[i][j]\
    \ = c;\n            }\n        }\n    }\n    for (int i = 0; i < n; i++) {\n \
    \       if (d[i][i] < 0) {\n            std::cout << \"NEGATIVE CYCLE\" << '\\\
    n';\n            return 0;\n        }\n    }\n    for (int i = 0; i < n; i++)\
    \ {\n        for (int j = 0; j < n; j++) {\n            if (j) std::cout << '\
    \ ';\n            if (d[i][j].is_plus_inf()) std::cout << \"INF\";\n         \
    \   else std::cout << d[i][j];\n        }\n        std::cout << '\\n';\n    }\n\
    }\n"
  dependsOn:
  - src/math/infint.hpp
  isVerificationFile: true
  path: test/aoj/grl-1-c.1.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 07:02:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl-1-c.1.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl-1-c.1.test.cpp
- /verify/test/aoj/grl-1-c.1.test.cpp.html
title: test/aoj/grl-1-c.1.test.cpp
---
