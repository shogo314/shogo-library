---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-1-c.test.cpp
    title: test/aoj/grl-1-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/infint.test.cpp
    title: test/unittest/infint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "inf \u3092\u6301\u3064\u6574\u6570\u578B"
    links: []
  bundledCode: "#line 2 \"src/math/infint.hpp\"\n\n/**\n * @file infint.hpp\n * @brief\
    \ inf \u3092\u6301\u3064\u6574\u6570\u578B\n */\n\n#include <algorithm>\n#include\
    \ <cstdlib>\n#include <iostream>\n#include <limits>\n#include <ostream>\n#include\
    \ <string>\n#include <string_view>\n#include <type_traits>\n\n/**\n * inf\u3092\
    \u3082\u3064\u6574\u6570\u578B\n * T\u306F\u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u3067\u3042\u308A\u30012\u306E\u88DC\u6570\u8868\u73FE\u3067\u8868\u3055\u308C\
    \u308B\u3053\u3068\u3092\u671F\u5F85\u3059\u308B\n */\ntemplate <typename T =\
    \ long long>\nstruct infint {\n   private:\n    static_assert(std::is_integral_v<T>\
    \ and std::is_signed_v<T>);\n    static_assert(std::numeric_limits<T>::min() +\
    \ 1 == -std::numeric_limits<T>::max());\n\n    T _v;\n\n    inline constexpr static\
    \ T _PlusInf = std::numeric_limits<T>::max();       //!< \u6B63\u306E\u7121\u9650\
    \u5927\n    inline constexpr static T _MinusInf = std::numeric_limits<T>::min()\
    \ + 1;  //!< \u8CA0\u306E\u7121\u9650\u5927\n    inline constexpr static T _NaN\
    \ = std::numeric_limits<T>::min();           //!< Not a Number\n    static std::string\
    \ str_plusinf;\n    static std::string str_minusinf;\n    static std::string str_nan;\n\
    \n   public:\n    constexpr infint() noexcept : _v(0) {}\n    constexpr infint(const\
    \ T& t) noexcept : _v(t) {}\n    constexpr infint(const infint& o) noexcept :\
    \ _v(o._v) {}\n    infint(std::string_view sv) noexcept(false) {\n        std::string\
    \ s(sv);\n        std::for_each(s.begin(), s.end(), [](char& c) {\n          \
    \  if ('A' <= c and c <= 'Z') {\n                c = c - 'A' + 'a';\n        \
    \    }\n        });\n        if (s == \"plusinf\") {\n            _v = _PlusInf;\n\
    \        } else if (s == \"inf\") {\n            _v = _PlusInf;\n        } else\
    \ if (s == \"minusinf\") {\n            _v = _MinusInf;\n        } else if (s\
    \ == \"nan\") {\n            _v = _NaN;\n        } else {\n            _v = std::stoll(s);\n\
    \        }\n    }\n\n    /**\n     * \u5185\u90E8\u8868\u73FE\u3092\u305D\u306E\
    \u307E\u307E\u8FD4\u3059\n     */\n    constexpr T val() const noexcept { return\
    \ _v; }\n\n    constexpr bool isNaN() const noexcept { return _v == _NaN; }\n\
    \    constexpr bool isPlusInf() const noexcept { return _v == _PlusInf; }\n  \
    \  constexpr bool isMinusInf() const noexcept { return _v == _MinusInf; }\n  \
    \  constexpr bool isInf() const noexcept { return _v == _PlusInf; }\n    constexpr\
    \ bool isfinite() const noexcept { return _MinusInf < _v and _v < _PlusInf; }\n\
    \n    constexpr infint& operator=(const infint& o) noexcept {\n        _v = o._v;\n\
    \        return *this;\n    }\n    constexpr infint& operator=(const T& t) noexcept\
    \ {\n        _v = t;\n        return *this;\n    }\n\n    constexpr infint operator+()\
    \ const noexcept { return _v; }\n    constexpr infint operator-() const noexcept\
    \ {\n        if (_v == _NaN) return _v;\n        return -_v;\n    }\n    constexpr\
    \ infint& operator*=(const infint& o) noexcept {\n        if (isNaN() or o.isNaN())\
    \ {\n            _v = _NaN;\n            return *this;\n        }\n        if\
    \ (not isfinite() or not o.isfinite()) {\n            if (_v == 0 or o._v == 0)\
    \ {\n                _v = _NaN;\n            } else if ((_v > 0) ^ (o._v > 0))\
    \ {\n                _v = _MinusInf;\n            } else {\n                _v\
    \ = _PlusInf;\n            }\n            return *this;\n        }\n        if\
    \ (_v == 0 or o._v == 0) {\n            _v = 0;\n            return *this;\n \
    \       }\n        // \u6709\u9650\u306E\u5024\u306E\u6700\u5927\u306F _PlusInf\
    \ - 1\n        if (std::abs(_v) > (_PlusInf - 1) / std::abs(o._v)) {\n       \
    \     if ((_v > 0) ^ (o._v > 0)) {\n                _v = _MinusInf;\n        \
    \    } else {\n                _v = _PlusInf;\n            }\n            return\
    \ *this;\n        }\n        _v *= o._v;\n        return *this;\n    }\n    constexpr\
    \ infint& operator/=(const infint& o) noexcept {\n        if (isNaN() or o.isNaN())\
    \ {\n            _v = _NaN;\n            return *this;\n        }\n        if\
    \ (not isfinite() and not o.isfinite()) {\n            _v = _NaN;\n          \
    \  return *this;\n        }\n        if (o._v == 0) {\n            _v = _NaN;\n\
    \            return *this;\n        }\n        if (not o.isfinite()) {\n     \
    \       _v = 0;\n            return *this;\n        }\n        if (not isfinite())\
    \ {\n            // \xB1inf / \u6709\u9650 = \xB1inf (\u7B26\u53F7\u306F\u5546\
    \u306E\u7B26\u53F7)\n            if ((_v > 0) ^ (o._v > 0)) {\n              \
    \  _v = _MinusInf;\n            } else {\n                _v = _PlusInf;\n   \
    \         }\n            return *this;\n        }\n        _v /= o._v;\n     \
    \   return *this;\n    }\n    constexpr infint& operator%=(const infint& o) noexcept\
    \ {\n        if (isNaN() or o.isNaN()) {\n            _v = _NaN;\n           \
    \ return *this;\n        }\n        if (not isfinite() and not o.isfinite()) {\n\
    \            _v = _NaN;\n            return *this;\n        }\n        if (o._v\
    \ == 0) {\n            _v = _NaN;\n            return *this;\n        }\n    \
    \    if (not isfinite()) {\n            // \xB1inf % \u6709\u9650 \u306F\u5B9A\
    \u307E\u3089\u306A\u3044 (\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u306E fmod \u3068\
    \u540C\u3058\u304F NaN)\n            _v = _NaN;\n            return *this;\n \
    \       }\n        if (not o.isfinite()) {\n            return *this;\n      \
    \  }\n        _v %= o._v;\n        return *this;\n    }\n    constexpr infint&\
    \ operator+=(const infint& o) noexcept {\n        if (isNaN() or o.isNaN()) {\n\
    \            _v = _NaN;\n            return *this;\n        }\n        if (not\
    \ isfinite() or not o.isfinite()) {\n            if (not isfinite() and not o.isfinite())\
    \ {\n                if (isPlusInf() ^ o.isPlusInf()) {\n                    _v\
    \ = _NaN;\n                }\n            } else if (not o.isfinite()) {\n   \
    \             _v = o._v;\n            }\n            return *this;\n        }\n\
    \        if (o._v > 0) {\n            if (_v >= _PlusInf - o._v) {\n         \
    \       _v = _PlusInf;\n                return *this;\n            }\n       \
    \ } else if (o._v < 0) {\n            if (_v <= _MinusInf - o._v) {\n        \
    \        _v = _MinusInf;\n                return *this;\n            }\n     \
    \   }\n        _v += o._v;\n        return *this;\n    }\n    constexpr infint&\
    \ operator-=(const infint& o) noexcept {\n        if (isNaN() or o.isNaN()) {\n\
    \            _v = _NaN;\n            return *this;\n        }\n        if (not\
    \ isfinite() or not o.isfinite()) {\n            if (not isfinite() and not o.isfinite())\
    \ {\n                if (isPlusInf() == o.isPlusInf()) {\n                   \
    \ _v = _NaN;\n                }\n            } else if (not o.isfinite()) {\n\
    \                _v = -o._v;\n            }\n            return *this;\n     \
    \   }\n        if (o._v > 0) {\n            if (_v <= _MinusInf + o._v) {\n  \
    \              _v = _MinusInf;\n                return *this;\n            }\n\
    \        } else if (o._v < 0) {\n            if (_v >= _PlusInf + o._v) {\n  \
    \              _v = _PlusInf;\n                return *this;\n            }\n\
    \        }\n        _v -= o._v;\n        return *this;\n    }\n    static std::string\
    \ type_str() { return \"infint<>\"; }\n    std::string initializer_str() const\
    \ {\n        if (_v == _PlusInf) {\n            return \"{\\\"plusinf\\\"}\";\n\
    \        } else if (_v == _MinusInf) {\n            return \"{\\\"minusinf\\\"\
    }\";\n        } else if (_v == _NaN) {\n            return \"{\\\"nan\\\"}\";\n\
    \        } else {\n            return \"{\" + std::to_string(_v) + \"}\";\n  \
    \      }\n    }\n    std::string repr() const {\n        return this->type_str()\
    \ + this->initializer_str();\n    }\n    std::string to_string() const {\n   \
    \     if (_v == _PlusInf) {\n            return str_plusinf;\n        } else if\
    \ (_v == _MinusInf) {\n            return str_minusinf;\n        } else if (_v\
    \ == _NaN) {\n            return str_nan;\n        } else {\n            return\
    \ std::to_string(_v);\n        }\n    }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const infint& rhs) {\n        os << rhs.to_string();\n        return\
    \ os;\n    }\n    static void set_str_plusinf(std::string s) {\n        str_plusinf\
    \ = s;\n    }\n    static void set_str_minusinf(std::string s) {\n        str_minusinf\
    \ = s;\n    }\n    static void set_str_nan(std::string s) {\n        str_nan =\
    \ s;\n    }\n\n    /**\n     * \u6B63\u306E\u7121\u9650\u5927\n     */\n    constexpr\
    \ static infint PlusInf() noexcept {\n        return _PlusInf;\n    }\n    /**\n\
    \     * \u8CA0\u306E\u7121\u9650\u5927\n     */\n    constexpr static infint MinusInf()\
    \ noexcept {\n        return _MinusInf;\n    }\n    /**\n     * Not a Number\n\
    \     */\n    constexpr static infint NaN() noexcept {\n        return _NaN;\n\
    \    }\n    /**\n     * \u6B63\u306E\u7121\u9650\u5927(PlusInf\u3068\u540C\u3058\
    )\n     */\n    constexpr static infint Inf() noexcept {\n        return _PlusInf;\n\
    \    }\n    /**\n     * \u6B63\u306E\u7121\u9650\u5927\u3067\u306A\u3044\u6700\
    \u5927\u5024\n     */\n    constexpr static infint Max() noexcept {\n        return\
    \ _PlusInf - 1;\n    }\n    /**\n     * \u8CA0\u306E\u7121\u9650\u5927\u3067\u306A\
    \u3044\u6700\u5C0F\u5024\n     */\n    constexpr static infint Min() noexcept\
    \ {\n        return _MinusInf + 1;\n    }\n\n    friend constexpr infint operator*(const\
    \ infint& t1, const infint& t2) noexcept {\n        infint res(t1);\n        return\
    \ res *= t2;\n    }\n    friend constexpr infint operator/(const infint& t1, const\
    \ infint& t2) noexcept {\n        infint res(t1);\n        return res /= t2;\n\
    \    }\n    friend constexpr infint operator%(const infint& t1, const infint&\
    \ t2) noexcept {\n        infint res(t1);\n        return res %= t2;\n    }\n\
    \    friend constexpr infint operator+(const infint& t1, const infint& t2) noexcept\
    \ {\n        infint res(t1);\n        return res += t2;\n    }\n    friend constexpr\
    \ infint operator-(const infint& t1, const infint& t2) noexcept {\n        infint\
    \ res(t1);\n        return res -= t2;\n    }\n    friend constexpr bool operator<(const\
    \ infint& t1, const infint& t2) noexcept {\n        if (t1.isNaN() or t2.isNaN())\
    \ return false;\n        return t1._v < t2._v;\n    }\n    friend constexpr bool\
    \ operator>(const infint& t1, const infint& t2) noexcept {\n        if (t1.isNaN()\
    \ or t2.isNaN()) return false;\n        return t1._v > t2._v;\n    }\n    friend\
    \ constexpr bool operator<=(const infint& t1, const infint& t2) noexcept {\n \
    \       if (t1.isNaN() or t2.isNaN()) return false;\n        return t1._v <= t2._v;\n\
    \    }\n    friend constexpr bool operator>=(const infint& t1, const infint& t2)\
    \ noexcept {\n        if (t1.isNaN() or t2.isNaN()) return false;\n        return\
    \ t1._v >= t2._v;\n    }\n    friend constexpr bool operator==(const infint& t1,\
    \ const infint& t2) noexcept {\n        return t1._v == t2._v;\n    }\n    friend\
    \ constexpr bool operator!=(const infint& t1, const infint& t2) noexcept {\n \
    \       return t1._v != t2._v;\n    }\n};\ntemplate <typename T>\nstd::string\
    \ infint<T>::str_plusinf = \"inf\";\ntemplate <typename T>\nstd::string infint<T>::str_minusinf\
    \ = \"-inf\";\ntemplate <typename T>\nstd::string infint<T>::str_nan = \"nan\"\
    ;\n"
  code: "#pragma once\n\n/**\n * @file infint.hpp\n * @brief inf \u3092\u6301\u3064\
    \u6574\u6570\u578B\n */\n\n#include <algorithm>\n#include <cstdlib>\n#include\
    \ <iostream>\n#include <limits>\n#include <ostream>\n#include <string>\n#include\
    \ <string_view>\n#include <type_traits>\n\n/**\n * inf\u3092\u3082\u3064\u6574\
    \u6570\u578B\n * T\u306F\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3067\u3042\u308A\
    \u30012\u306E\u88DC\u6570\u8868\u73FE\u3067\u8868\u3055\u308C\u308B\u3053\u3068\
    \u3092\u671F\u5F85\u3059\u308B\n */\ntemplate <typename T = long long>\nstruct\
    \ infint {\n   private:\n    static_assert(std::is_integral_v<T> and std::is_signed_v<T>);\n\
    \    static_assert(std::numeric_limits<T>::min() + 1 == -std::numeric_limits<T>::max());\n\
    \n    T _v;\n\n    inline constexpr static T _PlusInf = std::numeric_limits<T>::max();\
    \       //!< \u6B63\u306E\u7121\u9650\u5927\n    inline constexpr static T _MinusInf\
    \ = std::numeric_limits<T>::min() + 1;  //!< \u8CA0\u306E\u7121\u9650\u5927\n\
    \    inline constexpr static T _NaN = std::numeric_limits<T>::min();         \
    \  //!< Not a Number\n    static std::string str_plusinf;\n    static std::string\
    \ str_minusinf;\n    static std::string str_nan;\n\n   public:\n    constexpr\
    \ infint() noexcept : _v(0) {}\n    constexpr infint(const T& t) noexcept : _v(t)\
    \ {}\n    constexpr infint(const infint& o) noexcept : _v(o._v) {}\n    infint(std::string_view\
    \ sv) noexcept(false) {\n        std::string s(sv);\n        std::for_each(s.begin(),\
    \ s.end(), [](char& c) {\n            if ('A' <= c and c <= 'Z') {\n         \
    \       c = c - 'A' + 'a';\n            }\n        });\n        if (s == \"plusinf\"\
    ) {\n            _v = _PlusInf;\n        } else if (s == \"inf\") {\n        \
    \    _v = _PlusInf;\n        } else if (s == \"minusinf\") {\n            _v =\
    \ _MinusInf;\n        } else if (s == \"nan\") {\n            _v = _NaN;\n   \
    \     } else {\n            _v = std::stoll(s);\n        }\n    }\n\n    /**\n\
    \     * \u5185\u90E8\u8868\u73FE\u3092\u305D\u306E\u307E\u307E\u8FD4\u3059\n \
    \    */\n    constexpr T val() const noexcept { return _v; }\n\n    constexpr\
    \ bool isNaN() const noexcept { return _v == _NaN; }\n    constexpr bool isPlusInf()\
    \ const noexcept { return _v == _PlusInf; }\n    constexpr bool isMinusInf() const\
    \ noexcept { return _v == _MinusInf; }\n    constexpr bool isInf() const noexcept\
    \ { return _v == _PlusInf; }\n    constexpr bool isfinite() const noexcept { return\
    \ _MinusInf < _v and _v < _PlusInf; }\n\n    constexpr infint& operator=(const\
    \ infint& o) noexcept {\n        _v = o._v;\n        return *this;\n    }\n  \
    \  constexpr infint& operator=(const T& t) noexcept {\n        _v = t;\n     \
    \   return *this;\n    }\n\n    constexpr infint operator+() const noexcept {\
    \ return _v; }\n    constexpr infint operator-() const noexcept {\n        if\
    \ (_v == _NaN) return _v;\n        return -_v;\n    }\n    constexpr infint& operator*=(const\
    \ infint& o) noexcept {\n        if (isNaN() or o.isNaN()) {\n            _v =\
    \ _NaN;\n            return *this;\n        }\n        if (not isfinite() or not\
    \ o.isfinite()) {\n            if (_v == 0 or o._v == 0) {\n                _v\
    \ = _NaN;\n            } else if ((_v > 0) ^ (o._v > 0)) {\n                _v\
    \ = _MinusInf;\n            } else {\n                _v = _PlusInf;\n       \
    \     }\n            return *this;\n        }\n        if (_v == 0 or o._v ==\
    \ 0) {\n            _v = 0;\n            return *this;\n        }\n        //\
    \ \u6709\u9650\u306E\u5024\u306E\u6700\u5927\u306F _PlusInf - 1\n        if (std::abs(_v)\
    \ > (_PlusInf - 1) / std::abs(o._v)) {\n            if ((_v > 0) ^ (o._v > 0))\
    \ {\n                _v = _MinusInf;\n            } else {\n                _v\
    \ = _PlusInf;\n            }\n            return *this;\n        }\n        _v\
    \ *= o._v;\n        return *this;\n    }\n    constexpr infint& operator/=(const\
    \ infint& o) noexcept {\n        if (isNaN() or o.isNaN()) {\n            _v =\
    \ _NaN;\n            return *this;\n        }\n        if (not isfinite() and\
    \ not o.isfinite()) {\n            _v = _NaN;\n            return *this;\n   \
    \     }\n        if (o._v == 0) {\n            _v = _NaN;\n            return\
    \ *this;\n        }\n        if (not o.isfinite()) {\n            _v = 0;\n  \
    \          return *this;\n        }\n        if (not isfinite()) {\n         \
    \   // \xB1inf / \u6709\u9650 = \xB1inf (\u7B26\u53F7\u306F\u5546\u306E\u7B26\u53F7\
    )\n            if ((_v > 0) ^ (o._v > 0)) {\n                _v = _MinusInf;\n\
    \            } else {\n                _v = _PlusInf;\n            }\n       \
    \     return *this;\n        }\n        _v /= o._v;\n        return *this;\n \
    \   }\n    constexpr infint& operator%=(const infint& o) noexcept {\n        if\
    \ (isNaN() or o.isNaN()) {\n            _v = _NaN;\n            return *this;\n\
    \        }\n        if (not isfinite() and not o.isfinite()) {\n            _v\
    \ = _NaN;\n            return *this;\n        }\n        if (o._v == 0) {\n  \
    \          _v = _NaN;\n            return *this;\n        }\n        if (not isfinite())\
    \ {\n            // \xB1inf % \u6709\u9650 \u306F\u5B9A\u307E\u3089\u306A\u3044\
    \ (\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u306E fmod \u3068\u540C\u3058\u304F NaN)\n\
    \            _v = _NaN;\n            return *this;\n        }\n        if (not\
    \ o.isfinite()) {\n            return *this;\n        }\n        _v %= o._v;\n\
    \        return *this;\n    }\n    constexpr infint& operator+=(const infint&\
    \ o) noexcept {\n        if (isNaN() or o.isNaN()) {\n            _v = _NaN;\n\
    \            return *this;\n        }\n        if (not isfinite() or not o.isfinite())\
    \ {\n            if (not isfinite() and not o.isfinite()) {\n                if\
    \ (isPlusInf() ^ o.isPlusInf()) {\n                    _v = _NaN;\n          \
    \      }\n            } else if (not o.isfinite()) {\n                _v = o._v;\n\
    \            }\n            return *this;\n        }\n        if (o._v > 0) {\n\
    \            if (_v >= _PlusInf - o._v) {\n                _v = _PlusInf;\n  \
    \              return *this;\n            }\n        } else if (o._v < 0) {\n\
    \            if (_v <= _MinusInf - o._v) {\n                _v = _MinusInf;\n\
    \                return *this;\n            }\n        }\n        _v += o._v;\n\
    \        return *this;\n    }\n    constexpr infint& operator-=(const infint&\
    \ o) noexcept {\n        if (isNaN() or o.isNaN()) {\n            _v = _NaN;\n\
    \            return *this;\n        }\n        if (not isfinite() or not o.isfinite())\
    \ {\n            if (not isfinite() and not o.isfinite()) {\n                if\
    \ (isPlusInf() == o.isPlusInf()) {\n                    _v = _NaN;\n         \
    \       }\n            } else if (not o.isfinite()) {\n                _v = -o._v;\n\
    \            }\n            return *this;\n        }\n        if (o._v > 0) {\n\
    \            if (_v <= _MinusInf + o._v) {\n                _v = _MinusInf;\n\
    \                return *this;\n            }\n        } else if (o._v < 0) {\n\
    \            if (_v >= _PlusInf + o._v) {\n                _v = _PlusInf;\n  \
    \              return *this;\n            }\n        }\n        _v -= o._v;\n\
    \        return *this;\n    }\n    static std::string type_str() { return \"infint<>\"\
    ; }\n    std::string initializer_str() const {\n        if (_v == _PlusInf) {\n\
    \            return \"{\\\"plusinf\\\"}\";\n        } else if (_v == _MinusInf)\
    \ {\n            return \"{\\\"minusinf\\\"}\";\n        } else if (_v == _NaN)\
    \ {\n            return \"{\\\"nan\\\"}\";\n        } else {\n            return\
    \ \"{\" + std::to_string(_v) + \"}\";\n        }\n    }\n    std::string repr()\
    \ const {\n        return this->type_str() + this->initializer_str();\n    }\n\
    \    std::string to_string() const {\n        if (_v == _PlusInf) {\n        \
    \    return str_plusinf;\n        } else if (_v == _MinusInf) {\n            return\
    \ str_minusinf;\n        } else if (_v == _NaN) {\n            return str_nan;\n\
    \        } else {\n            return std::to_string(_v);\n        }\n    }\n\
    \    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const infint& rhs)\
    \ {\n        os << rhs.to_string();\n        return os;\n    }\n    static void\
    \ set_str_plusinf(std::string s) {\n        str_plusinf = s;\n    }\n    static\
    \ void set_str_minusinf(std::string s) {\n        str_minusinf = s;\n    }\n \
    \   static void set_str_nan(std::string s) {\n        str_nan = s;\n    }\n\n\
    \    /**\n     * \u6B63\u306E\u7121\u9650\u5927\n     */\n    constexpr static\
    \ infint PlusInf() noexcept {\n        return _PlusInf;\n    }\n    /**\n    \
    \ * \u8CA0\u306E\u7121\u9650\u5927\n     */\n    constexpr static infint MinusInf()\
    \ noexcept {\n        return _MinusInf;\n    }\n    /**\n     * Not a Number\n\
    \     */\n    constexpr static infint NaN() noexcept {\n        return _NaN;\n\
    \    }\n    /**\n     * \u6B63\u306E\u7121\u9650\u5927(PlusInf\u3068\u540C\u3058\
    )\n     */\n    constexpr static infint Inf() noexcept {\n        return _PlusInf;\n\
    \    }\n    /**\n     * \u6B63\u306E\u7121\u9650\u5927\u3067\u306A\u3044\u6700\
    \u5927\u5024\n     */\n    constexpr static infint Max() noexcept {\n        return\
    \ _PlusInf - 1;\n    }\n    /**\n     * \u8CA0\u306E\u7121\u9650\u5927\u3067\u306A\
    \u3044\u6700\u5C0F\u5024\n     */\n    constexpr static infint Min() noexcept\
    \ {\n        return _MinusInf + 1;\n    }\n\n    friend constexpr infint operator*(const\
    \ infint& t1, const infint& t2) noexcept {\n        infint res(t1);\n        return\
    \ res *= t2;\n    }\n    friend constexpr infint operator/(const infint& t1, const\
    \ infint& t2) noexcept {\n        infint res(t1);\n        return res /= t2;\n\
    \    }\n    friend constexpr infint operator%(const infint& t1, const infint&\
    \ t2) noexcept {\n        infint res(t1);\n        return res %= t2;\n    }\n\
    \    friend constexpr infint operator+(const infint& t1, const infint& t2) noexcept\
    \ {\n        infint res(t1);\n        return res += t2;\n    }\n    friend constexpr\
    \ infint operator-(const infint& t1, const infint& t2) noexcept {\n        infint\
    \ res(t1);\n        return res -= t2;\n    }\n    friend constexpr bool operator<(const\
    \ infint& t1, const infint& t2) noexcept {\n        if (t1.isNaN() or t2.isNaN())\
    \ return false;\n        return t1._v < t2._v;\n    }\n    friend constexpr bool\
    \ operator>(const infint& t1, const infint& t2) noexcept {\n        if (t1.isNaN()\
    \ or t2.isNaN()) return false;\n        return t1._v > t2._v;\n    }\n    friend\
    \ constexpr bool operator<=(const infint& t1, const infint& t2) noexcept {\n \
    \       if (t1.isNaN() or t2.isNaN()) return false;\n        return t1._v <= t2._v;\n\
    \    }\n    friend constexpr bool operator>=(const infint& t1, const infint& t2)\
    \ noexcept {\n        if (t1.isNaN() or t2.isNaN()) return false;\n        return\
    \ t1._v >= t2._v;\n    }\n    friend constexpr bool operator==(const infint& t1,\
    \ const infint& t2) noexcept {\n        return t1._v == t2._v;\n    }\n    friend\
    \ constexpr bool operator!=(const infint& t1, const infint& t2) noexcept {\n \
    \       return t1._v != t2._v;\n    }\n};\ntemplate <typename T>\nstd::string\
    \ infint<T>::str_plusinf = \"inf\";\ntemplate <typename T>\nstd::string infint<T>::str_minusinf\
    \ = \"-inf\";\ntemplate <typename T>\nstd::string infint<T>::str_nan = \"nan\"\
    ;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/infint.hpp
  requiredBy: []
  timestamp: '2026-10-13 12:42:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/infint.test.cpp
  - test/aoj/grl-1-c.test.cpp
documentation_of: src/math/infint.hpp
layout: document
title: "inf \u3092\u6301\u3064\u6574\u6570\u578B"
---

正の無限大・負の無限大・NaN を持つ符号付き整数型 `infint<T = long long>` です。オーバーフローする演算は無限大に飽和します。最短路の距離など「到達不能」を表したい値に使えます。

```cpp
using I = infint<>;
I a = I::Inf(), b = 5;
I c = a + b;               // inf
I d = I::Max() + b;        // inf (オーバーフローは飽和する)
I e = a - a;               // nan
std::cout << c << ' ' << -c << ' ' << e << '\n';  // "inf -inf nan"
```

内部では `T` の最大値を正の無限大、最小値 + 1 を負の無限大、最小値を NaN として表します。

## 値の作り方

| 書き方 | 値 |
|---|---|
| `infint<T>(x)` | 整数 `x` |
| `infint<T>("inf")`、`"plusinf"` / `"minusinf"` / `"nan"` | 正の無限大 / 負の無限大 / NaN (大文字小文字は問わない)。それ以外の文字列は整数として読む |
| `Inf()`、`PlusInf()` / `MinusInf()` / `NaN()` | 正の無限大 / 負の無限大 / NaN |
| `Max()` / `Min()` | 無限大でない最大値 / 最小値 |

## 演算

| 演算 | 動作 |
|---|---|
| `+`、`-`、`*` (と複合代入) | 有限の値どうしでオーバーフローすれば ±無限大。$\infty - \infty$、$0 \times \infty$ は NaN |
| `/`、`%` | 0 で割ると NaN。無限大どうしは NaN。無限大 ÷ 有限は ±無限大、無限大 % 有限は NaN。有限 ÷ 無限大は 0、有限 % 無限大は元の値 |
| 単項 `-` | 符号反転 (無限大は反対の無限大に) |
| `<`、`<=`、`>`、`>=` | NaN を含むと常に `false` |
| `==`、`!=` | 内部表現の比較 (NaN どうしは等しい) |
| `NaN` を含む演算 | 結果は NaN |

## メンバ関数

| 関数 | 説明 |
|---|---|
| `val()` | 内部表現の値 |
| `isfinite()` | 有限か |
| `isPlusInf()`、`isInf()` / `isMinusInf()` / `isNaN()` | 正の無限大か (`isInf` も正の無限大のみ) / 負の無限大か / NaN か |
| `to_string()`、`os << x` | 文字列にする。無限大などの表記は `set_str_plusinf(s)`、`set_str_minusinf(s)`、`set_str_nan(s)` で変えられる (初期値 `inf`、`-inf`、`nan`) |
| `repr()` | `infint<>{"plusinf"}` のような、コンストラクタにそのまま使える文字列 |
