---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/infint.hpp\"\n#include <algorithm>\n#include <iostream>\n\
    #include <limits>\n#include <ostream>\n#include <string>\n#include <string_view>\n\
    #include <type_traits>\n\n/**\n * inf\u3092\u3082\u3064\u6574\u6570\u578B\n *\
    \ T\u306F\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3067\u3042\u308A\u30012\u306E\u88DC\
    \u6570\u8868\u73FE\u3067\u8868\u3055\u308C\u308B\u3053\u3068\u3092\u671F\u5F85\
    \u3059\u308B\n */\ntemplate <typename T = long long>\nstruct infint {\n   private:\n\
    \    static_assert(std::is_integral_v<T> and std::is_signed_v<T>);\n    static_assert(std::numeric_limits<T>::min()\
    \ + 1 == -std::numeric_limits<T>::max());\n\n    T _v;\n\n    inline constexpr\
    \ static T _PlusInf = std::numeric_limits<T>::max();       //<! \u6B63\u306E\u7121\
    \u9650\u5927\n    inline constexpr static T _MinusInf = std::numeric_limits<T>::min()\
    \ + 1;  //<! \u8CA0\u306E\u7121\u9650\u5927\n    inline constexpr static T _NaN\
    \ = std::numeric_limits<T>::min();           //<! Not a Number\n    static std::string\
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
    \       }\n        if (std::abs(_v) >= _PlusInf / std::abs(o._v)) {\n        \
    \    if ((_v > 0) ^ (o._v > 0)) {\n                _v = _MinusInf;\n         \
    \   } else {\n                _v = _PlusInf;\n            }\n            return\
    \ *this;\n        }\n        _v *= o._v;\n        return *this;\n    }\n    constexpr\
    \ infint& operator/=(const infint& o) noexcept {\n        if (isNaN() or o.isNaN())\
    \ {\n            _v = _NaN;\n            return *this;\n        }\n        if\
    \ (not isfinite() and not o.isfinite()) {\n            _v = _NaN;\n          \
    \  return *this;\n        }\n        if (o._v == 0) {\n            _v = _NaN;\n\
    \            return *this;\n        }\n        if (not o.isfinite()) {\n     \
    \       _v = 0;\n            return *this;\n        }\n        _v /= o._v;\n \
    \       return *this;\n    }\n    constexpr infint& operator%=(const infint& o)\
    \ noexcept {\n        if (isNaN() or o.isNaN()) {\n            _v = _NaN;\n  \
    \          return *this;\n        }\n        if (not isfinite() and not o.isfinite())\
    \ {\n            _v = _NaN;\n            return *this;\n        }\n        if\
    \ (o._v == 0) {\n            _v = _NaN;\n            return *this;\n        }\n\
    \        if (not o.isfinite()) {\n            return *this;\n        }\n     \
    \   _v %= o._v;\n        return *this;\n    }\n    constexpr infint& operator+=(const\
    \ infint& o) noexcept {\n        if (isNaN() or o.isNaN()) {\n            _v =\
    \ _NaN;\n            return *this;\n        }\n        if (not isfinite() or not\
    \ o.isfinite()) {\n            if (not isfinite() and not o.isfinite()) {\n  \
    \              if (isPlusInf() ^ o.isPlusInf()) {\n                    _v = _NaN;\n\
    \                }\n            } else if (not o.isfinite()) {\n             \
    \   _v = o._v;\n            }\n            return *this;\n        }\n        if\
    \ (o._v > 0) {\n            if (_v >= _PlusInf - o._v) {\n                _v =\
    \ _PlusInf;\n                return *this;\n            }\n        } else if (o._v\
    \ < 0) {\n            if (_v <= _MinusInf - o._v) {\n                _v = _MinusInf;\n\
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
  code: "#pragma once\n#include <algorithm>\n#include <iostream>\n#include <limits>\n\
    #include <ostream>\n#include <string>\n#include <string_view>\n#include <type_traits>\n\
    \n/**\n * inf\u3092\u3082\u3064\u6574\u6570\u578B\n * T\u306F\u7B26\u53F7\u4ED8\
    \u304D\u6574\u6570\u3067\u3042\u308A\u30012\u306E\u88DC\u6570\u8868\u73FE\u3067\
    \u8868\u3055\u308C\u308B\u3053\u3068\u3092\u671F\u5F85\u3059\u308B\n */\ntemplate\
    \ <typename T = long long>\nstruct infint {\n   private:\n    static_assert(std::is_integral_v<T>\
    \ and std::is_signed_v<T>);\n    static_assert(std::numeric_limits<T>::min() +\
    \ 1 == -std::numeric_limits<T>::max());\n\n    T _v;\n\n    inline constexpr static\
    \ T _PlusInf = std::numeric_limits<T>::max();       //<! \u6B63\u306E\u7121\u9650\
    \u5927\n    inline constexpr static T _MinusInf = std::numeric_limits<T>::min()\
    \ + 1;  //<! \u8CA0\u306E\u7121\u9650\u5927\n    inline constexpr static T _NaN\
    \ = std::numeric_limits<T>::min();           //<! Not a Number\n    static std::string\
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
    \       }\n        if (std::abs(_v) >= _PlusInf / std::abs(o._v)) {\n        \
    \    if ((_v > 0) ^ (o._v > 0)) {\n                _v = _MinusInf;\n         \
    \   } else {\n                _v = _PlusInf;\n            }\n            return\
    \ *this;\n        }\n        _v *= o._v;\n        return *this;\n    }\n    constexpr\
    \ infint& operator/=(const infint& o) noexcept {\n        if (isNaN() or o.isNaN())\
    \ {\n            _v = _NaN;\n            return *this;\n        }\n        if\
    \ (not isfinite() and not o.isfinite()) {\n            _v = _NaN;\n          \
    \  return *this;\n        }\n        if (o._v == 0) {\n            _v = _NaN;\n\
    \            return *this;\n        }\n        if (not o.isfinite()) {\n     \
    \       _v = 0;\n            return *this;\n        }\n        _v /= o._v;\n \
    \       return *this;\n    }\n    constexpr infint& operator%=(const infint& o)\
    \ noexcept {\n        if (isNaN() or o.isNaN()) {\n            _v = _NaN;\n  \
    \          return *this;\n        }\n        if (not isfinite() and not o.isfinite())\
    \ {\n            _v = _NaN;\n            return *this;\n        }\n        if\
    \ (o._v == 0) {\n            _v = _NaN;\n            return *this;\n        }\n\
    \        if (not o.isfinite()) {\n            return *this;\n        }\n     \
    \   _v %= o._v;\n        return *this;\n    }\n    constexpr infint& operator+=(const\
    \ infint& o) noexcept {\n        if (isNaN() or o.isNaN()) {\n            _v =\
    \ _NaN;\n            return *this;\n        }\n        if (not isfinite() or not\
    \ o.isfinite()) {\n            if (not isfinite() and not o.isfinite()) {\n  \
    \              if (isPlusInf() ^ o.isPlusInf()) {\n                    _v = _NaN;\n\
    \                }\n            } else if (not o.isfinite()) {\n             \
    \   _v = o._v;\n            }\n            return *this;\n        }\n        if\
    \ (o._v > 0) {\n            if (_v >= _PlusInf - o._v) {\n                _v =\
    \ _PlusInf;\n                return *this;\n            }\n        } else if (o._v\
    \ < 0) {\n            if (_v <= _MinusInf - o._v) {\n                _v = _MinusInf;\n\
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
  path: math/infint.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/infint.hpp
layout: document
redirect_from:
- /library/math/infint.hpp
- /library/math/infint.hpp.html
title: math/infint.hpp
---
