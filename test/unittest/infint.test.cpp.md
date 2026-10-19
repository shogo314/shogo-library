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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/infint.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// infint \u306E\u6F14\u7B97\u3092\u3001\u7121\u9650\u5927\u30FBNaN \u3092\
    \u5206\u3051\u3066 __int128 \u3067\u611A\u76F4\u306B\u8A08\u7B97\u3057\u305F\u3082\
    \u306E\u3068\u6BD4\u8F03\u3059\u308B\n// \u5883\u754C\u306E\u5024 (max()\u3001\
    min() \u3068\u305D\u306E\u524D\u5F8C) \u3092\u542B\u3080\u5024\u306E\u5168\u7D44\
    \u3067\u3001\u56DB\u5247\u6F14\u7B97\u30FB\u5270\u4F59\u30FB\u6BD4\u8F03\u30FB\
    \u7B26\u53F7\u53CD\u8EE2\u3092\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/math/infint.hpp\"\
    \n\n/**\n * @file infint.hpp\n * @brief inf \u3092\u6301\u3064\u6574\u6570\u578B\
    \n */\n\n#include <algorithm>\n#include <cstdlib>\n#include <iostream>\n#include\
    \ <limits>\n#include <ostream>\n#include <string>\n#include <string_view>\n#include\
    \ <type_traits>\n\n/**\n * inf\u3092\u3082\u3064\u6574\u6570\u578B\n * T\u306F\
    \u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3067\u3042\u308A\u30012\u306E\u88DC\u6570\
    \u8868\u73FE\u3067\u8868\u3055\u308C\u308B\u3053\u3068\u3092\u671F\u5F85\u3059\
    \u308B\n */\ntemplate <typename T = long long>\nclass infint {\n   private:\n\
    \    static_assert(std::is_integral_v<T> && std::is_signed_v<T>);\n    static_assert(std::numeric_limits<T>::min()\
    \ + 1 == -std::numeric_limits<T>::max());\n\n    T _v;\n\n    inline constexpr\
    \ static T plus_inf_value = std::numeric_limits<T>::max();       //!< \u6B63\u306E\
    \u7121\u9650\u5927\n    inline constexpr static T minus_inf_value = std::numeric_limits<T>::min()\
    \ + 1;  //!< \u8CA0\u306E\u7121\u9650\u5927\n    inline constexpr static T nan_value\
    \ = std::numeric_limits<T>::min();            //!< Not a Number\n    static std::string\
    \ str_plusinf;\n    static std::string str_minusinf;\n    static std::string str_nan;\n\
    \n   public:\n    constexpr infint() noexcept : _v(0) {}\n    constexpr infint(const\
    \ T& t) noexcept : _v(t) {}\n    constexpr infint(const infint& o) noexcept :\
    \ _v(o._v) {}\n    infint(std::string_view sv) noexcept(false) {\n        std::string\
    \ s(sv);\n        std::for_each(s.begin(), s.end(), [](char& c) {\n          \
    \  if ('A' <= c && c <= 'Z') {\n                c = c - 'A' + 'a';\n         \
    \   }\n        });\n        if (s == \"plusinf\") {\n            _v = plus_inf_value;\n\
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
    \ { return minus_inf_value < _v && _v < plus_inf_value; }\n\n    constexpr infint&\
    \ operator=(const infint& o) noexcept {\n        _v = o._v;\n        return *this;\n\
    \    }\n    constexpr infint& operator=(const T& t) noexcept {\n        _v = t;\n\
    \        return *this;\n    }\n\n    constexpr infint operator+() const noexcept\
    \ { return _v; }\n    constexpr infint operator-() const noexcept {\n        if\
    \ (_v == nan_value) return _v;\n        return -_v;\n    }\n    constexpr infint&\
    \ operator*=(const infint& o) noexcept {\n        if (is_nan() || o.is_nan())\
    \ {\n            _v = nan_value;\n            return *this;\n        }\n     \
    \   if (!is_finite() || !o.is_finite()) {\n            if (_v == 0 || o._v ==\
    \ 0) {\n                _v = nan_value;\n            } else if ((_v > 0) ^ (o._v\
    \ > 0)) {\n                _v = minus_inf_value;\n            } else {\n     \
    \           _v = plus_inf_value;\n            }\n            return *this;\n \
    \       }\n        if (_v == 0 || o._v == 0) {\n            _v = 0;\n        \
    \    return *this;\n        }\n        // \u6709\u9650\u306E\u5024\u306E\u6700\
    \u5927\u306F plus_inf_value - 1\n        if (std::abs(_v) > (plus_inf_value -\
    \ 1) / std::abs(o._v)) {\n            if ((_v > 0) ^ (o._v > 0)) {\n         \
    \       _v = minus_inf_value;\n            } else {\n                _v = plus_inf_value;\n\
    \            }\n            return *this;\n        }\n        _v *= o._v;\n  \
    \      return *this;\n    }\n    constexpr infint& operator/=(const infint& o)\
    \ noexcept {\n        if (is_nan() || o.is_nan()) {\n            _v = nan_value;\n\
    \            return *this;\n        }\n        if (!is_finite() && !o.is_finite())\
    \ {\n            _v = nan_value;\n            return *this;\n        }\n     \
    \   if (o._v == 0) {\n            _v = nan_value;\n            return *this;\n\
    \        }\n        if (!o.is_finite()) {\n            _v = 0;\n            return\
    \ *this;\n        }\n        if (!is_finite()) {\n            // \xB1inf / \u6709\
    \u9650 = \xB1inf (\u7B26\u53F7\u306F\u5546\u306E\u7B26\u53F7)\n            if\
    \ ((_v > 0) ^ (o._v > 0)) {\n                _v = minus_inf_value;\n         \
    \   } else {\n                _v = plus_inf_value;\n            }\n          \
    \  return *this;\n        }\n        _v /= o._v;\n        return *this;\n    }\n\
    \    constexpr infint& operator%=(const infint& o) noexcept {\n        if (is_nan()\
    \ || o.is_nan()) {\n            _v = nan_value;\n            return *this;\n \
    \       }\n        if (!is_finite() && !o.is_finite()) {\n            _v = nan_value;\n\
    \            return *this;\n        }\n        if (o._v == 0) {\n            _v\
    \ = nan_value;\n            return *this;\n        }\n        if (!is_finite())\
    \ {\n            // \xB1inf % \u6709\u9650 \u306F\u5B9A\u307E\u3089\u306A\u3044\
    \ (\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u306E fmod \u3068\u540C\u3058\u304F NaN)\n\
    \            _v = nan_value;\n            return *this;\n        }\n        if\
    \ (!o.is_finite()) {\n            return *this;\n        }\n        _v %= o._v;\n\
    \        return *this;\n    }\n    constexpr infint& operator+=(const infint&\
    \ o) noexcept {\n        if (is_nan() || o.is_nan()) {\n            _v = nan_value;\n\
    \            return *this;\n        }\n        if (!is_finite() || !o.is_finite())\
    \ {\n            if (!is_finite() && !o.is_finite()) {\n                if (is_plus_inf()\
    \ ^ o.is_plus_inf()) {\n                    _v = nan_value;\n                }\n\
    \            } else if (!o.is_finite()) {\n                _v = o._v;\n      \
    \      }\n            return *this;\n        }\n        if (o._v > 0) {\n    \
    \        if (_v >= plus_inf_value - o._v) {\n                _v = plus_inf_value;\n\
    \                return *this;\n            }\n        } else if (o._v < 0) {\n\
    \            if (_v <= minus_inf_value - o._v) {\n                _v = minus_inf_value;\n\
    \                return *this;\n            }\n        }\n        _v += o._v;\n\
    \        return *this;\n    }\n    constexpr infint& operator-=(const infint&\
    \ o) noexcept {\n        if (is_nan() || o.is_nan()) {\n            _v = nan_value;\n\
    \            return *this;\n        }\n        if (!is_finite() || !o.is_finite())\
    \ {\n            if (!is_finite() && !o.is_finite()) {\n                if (is_plus_inf()\
    \ == o.is_plus_inf()) {\n                    _v = nan_value;\n               \
    \ }\n            } else if (!o.is_finite()) {\n                _v = -o._v;\n \
    \           }\n            return *this;\n        }\n        if (o._v > 0) {\n\
    \            if (_v <= minus_inf_value + o._v) {\n                _v = minus_inf_value;\n\
    \                return *this;\n            }\n        } else if (o._v < 0) {\n\
    \            if (_v >= plus_inf_value + o._v) {\n                _v = plus_inf_value;\n\
    \                return *this;\n            }\n        }\n        _v -= o._v;\n\
    \        return *this;\n    }\n    static std::string type_str() { return \"infint<>\"\
    ; }\n    std::string initializer_str() const {\n        if (_v == plus_inf_value)\
    \ {\n            return \"{\\\"plusinf\\\"}\";\n        } else if (_v == minus_inf_value)\
    \ {\n            return \"{\\\"minusinf\\\"}\";\n        } else if (_v == nan_value)\
    \ {\n            return \"{\\\"nan\\\"}\";\n        } else {\n            return\
    \ \"{\" + std::to_string(_v) + \"}\";\n        }\n    }\n    std::string repr()\
    \ const {\n        return this->type_str() + this->initializer_str();\n    }\n\
    \    std::string to_string() const {\n        if (_v == plus_inf_value) {\n  \
    \          return str_plusinf;\n        } else if (_v == minus_inf_value) {\n\
    \            return str_minusinf;\n        } else if (_v == nan_value) {\n   \
    \         return str_nan;\n        } else {\n            return std::to_string(_v);\n\
    \        }\n    }\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const infint& rhs)\
    \ {\n        os << rhs.to_string();\n        return os;\n    }\n    static void\
    \ set_str_plusinf(std::string s) {\n        str_plusinf = s;\n    }\n    static\
    \ void set_str_minusinf(std::string s) {\n        str_minusinf = s;\n    }\n \
    \   static void set_str_nan(std::string s) {\n        str_nan = s;\n    }\n\n\
    \    /**\n     * \u6B63\u306E\u7121\u9650\u5927\n     */\n    constexpr static\
    \ infint plus_inf() noexcept {\n        return plus_inf_value;\n    }\n    /**\n\
    \     * \u8CA0\u306E\u7121\u9650\u5927\n     */\n    constexpr static infint minus_inf()\
    \ noexcept {\n        return minus_inf_value;\n    }\n    /**\n     * Not a Number\n\
    \     */\n    constexpr static infint nan() noexcept {\n        return nan_value;\n\
    \    }\n    /**\n     * \u6B63\u306E\u7121\u9650\u5927(plus_inf \u3068\u540C\u3058\
    )\n     */\n    constexpr static infint inf() noexcept {\n        return plus_inf_value;\n\
    \    }\n    /**\n     * \u6B63\u306E\u7121\u9650\u5927\u3067\u306A\u3044\u6700\
    \u5927\u5024\n     */\n    constexpr static infint max() noexcept {\n        return\
    \ plus_inf_value - 1;\n    }\n    /**\n     * \u8CA0\u306E\u7121\u9650\u5927\u3067\
    \u306A\u3044\u6700\u5C0F\u5024\n     */\n    constexpr static infint min() noexcept\
    \ {\n        return minus_inf_value + 1;\n    }\n\n    friend constexpr infint\
    \ operator*(const infint& t1, const infint& t2) noexcept {\n        infint res(t1);\n\
    \        return res *= t2;\n    }\n    friend constexpr infint operator/(const\
    \ infint& t1, const infint& t2) noexcept {\n        infint res(t1);\n        return\
    \ res /= t2;\n    }\n    friend constexpr infint operator%(const infint& t1, const\
    \ infint& t2) noexcept {\n        infint res(t1);\n        return res %= t2;\n\
    \    }\n    friend constexpr infint operator+(const infint& t1, const infint&\
    \ t2) noexcept {\n        infint res(t1);\n        return res += t2;\n    }\n\
    \    friend constexpr infint operator-(const infint& t1, const infint& t2) noexcept\
    \ {\n        infint res(t1);\n        return res -= t2;\n    }\n    friend constexpr\
    \ bool operator<(const infint& t1, const infint& t2) noexcept {\n        if (t1.is_nan()\
    \ || t2.is_nan()) return false;\n        return t1._v < t2._v;\n    }\n    friend\
    \ constexpr bool operator>(const infint& t1, const infint& t2) noexcept {\n  \
    \      if (t1.is_nan() || t2.is_nan()) return false;\n        return t1._v > t2._v;\n\
    \    }\n    friend constexpr bool operator<=(const infint& t1, const infint& t2)\
    \ noexcept {\n        if (t1.is_nan() || t2.is_nan()) return false;\n        return\
    \ t1._v <= t2._v;\n    }\n    friend constexpr bool operator>=(const infint& t1,\
    \ const infint& t2) noexcept {\n        if (t1.is_nan() || t2.is_nan()) return\
    \ false;\n        return t1._v >= t2._v;\n    }\n    friend constexpr bool operator==(const\
    \ infint& t1, const infint& t2) noexcept {\n        return t1._v == t2._v;\n \
    \   }\n    friend constexpr bool operator!=(const infint& t1, const infint& t2)\
    \ noexcept {\n        return t1._v != t2._v;\n    }\n};\ntemplate <typename T>\n\
    std::string infint<T>::str_plusinf = \"inf\";\ntemplate <typename T>\nstd::string\
    \ infint<T>::str_minusinf = \"-inf\";\ntemplate <typename T>\nstd::string infint<T>::str_nan\
    \ = \"nan\";\n#line 8 \"test/unittest/infint.test.cpp\"\n\n#line 11 \"test/unittest/infint.test.cpp\"\
    \n#include <random>\n#include <sstream>\n#line 14 \"test/unittest/infint.test.cpp\"\
    \n#include <vector>\n\n// \u611A\u76F4\u306A\u5024: \u7A2E\u985E\u3068\u3001\u6709\
    \u9650\u306E\u3068\u304D\u306E\u5024\nstruct Naive {\n    enum Kind { Finite,\n\
    \                PlusInf,\n                MinusInf,\n                NaN } kind;\n\
    \    __int128 v;\n};\n\ntemplate <typename T>\nstruct Checker {\n    using I =\
    \ infint<T>;\n    static constexpr __int128 MAXV = std::numeric_limits<T>::max();\
    \  // \u6B63\u306E\u7121\u9650\u5927\u306E\u5185\u90E8\u8868\u73FE\n    static\
    \ constexpr __int128 MINV = std::numeric_limits<T>::min();  // NaN \u306E\u5185\
    \u90E8\u8868\u73FE\n    // \u6709\u9650\u306E\u5024\u306E\u7BC4\u56F2\u306F [MINV\
    \ + 2, MAXV - 1]\n    static Naive fin(__int128 x) {\n        if (x >= MAXV) return\
    \ {Naive::PlusInf, 0};\n        if (x <= MINV + 1) return {Naive::MinusInf, 0};\n\
    \        return {Naive::Finite, x};\n    }\n    static Naive of(const I& a) {\n\
    \        if (a.is_nan()) return {Naive::NaN, 0};\n        if (a.is_plus_inf())\
    \ return {Naive::PlusInf, 0};\n        if (a.is_minus_inf()) return {Naive::MinusInf,\
    \ 0};\n        return {Naive::Finite, a.val()};\n    }\n    static int sign(const\
    \ Naive& a) {\n        if (a.kind == Naive::PlusInf) return 1;\n        if (a.kind\
    \ == Naive::MinusInf) return -1;\n        return (a.v > 0) - (a.v < 0);\n    }\n\
    \    static Naive inf_of_sign(int s) { return s > 0 ? Naive{Naive::PlusInf, 0}\
    \ : Naive{Naive::MinusInf, 0}; }\n    static bool same(const Naive& a, const Naive&\
    \ b) { return a.kind == b.kind && (a.kind != Naive::Finite || a.v == b.v); }\n\
    \n    static Naive add(Naive a, Naive b) {\n        if (a.kind == Naive::NaN ||\
    \ b.kind == Naive::NaN) return {Naive::NaN, 0};\n        if (a.kind != Naive::Finite\
    \ && b.kind != Naive::Finite) return a.kind == b.kind ? a : Naive{Naive::NaN,\
    \ 0};\n        if (a.kind != Naive::Finite) return a;\n        if (b.kind != Naive::Finite)\
    \ return b;\n        return fin(a.v + b.v);\n    }\n    static Naive neg(Naive\
    \ a) {\n        if (a.kind == Naive::PlusInf) return {Naive::MinusInf, 0};\n \
    \       if (a.kind == Naive::MinusInf) return {Naive::PlusInf, 0};\n        if\
    \ (a.kind == Naive::Finite) a.v = -a.v;\n        return a;\n    }\n    static\
    \ Naive mul(Naive a, Naive b) {\n        if (a.kind == Naive::NaN || b.kind ==\
    \ Naive::NaN) return {Naive::NaN, 0};\n        if (a.kind != Naive::Finite ||\
    \ b.kind != Naive::Finite) {\n            if (sign(a) == 0 || sign(b) == 0) return\
    \ {Naive::NaN, 0};  // 0 \xD7 \u221E\n            return inf_of_sign(sign(a) *\
    \ sign(b));\n        }\n        return fin(a.v * b.v);\n    }\n    static Naive\
    \ div(Naive a, Naive b) {\n        if (a.kind == Naive::NaN || b.kind == Naive::NaN)\
    \ return {Naive::NaN, 0};\n        if (a.kind != Naive::Finite && b.kind != Naive::Finite)\
    \ return {Naive::NaN, 0};\n        if (sign(b) == 0) return {Naive::NaN, 0};\n\
    \        if (b.kind != Naive::Finite) return {Naive::Finite, 0};\n        if (a.kind\
    \ != Naive::Finite) return inf_of_sign(sign(a) * sign(b));\n        return fin(a.v\
    \ / b.v);\n    }\n    static Naive mod(Naive a, Naive b) {\n        if (a.kind\
    \ == Naive::NaN || b.kind == Naive::NaN) return {Naive::NaN, 0};\n        if (a.kind\
    \ != Naive::Finite && b.kind != Naive::Finite) return {Naive::NaN, 0};\n     \
    \   if (sign(b) == 0) return {Naive::NaN, 0};\n        if (a.kind != Naive::Finite)\
    \ return {Naive::NaN, 0};\n        if (b.kind != Naive::Finite) return a;\n  \
    \      return fin(a.v % b.v);\n    }\n    // \u6BD4\u8F03\u7528\u306E\u9806\u5E8F\
    \ (NaN \u306F\u547C\u3070\u306A\u3044)\n    static __int128 key(const Naive& a)\
    \ {\n        if (a.kind == Naive::PlusInf) return MAXV;\n        if (a.kind ==\
    \ Naive::MinusInf) return MINV + 1;\n        return a.v;\n    }\n\n    static\
    \ bool run(std::mt19937_64& rng) {\n        bool ok = true;\n        std::vector<I>\
    \ vals = {I::plus_inf(), I::minus_inf(), I::nan(), I::inf(), I::max(), I::min(),\
    \ I(0), I(1), I(-1), I(2), I(-2), I(3), I(-7)};\n        for (__int128 d : {1,\
    \ 2, 3}) {\n            vals.push_back(I(static_cast<T>(MAXV - 1 - d)));\n   \
    \         vals.push_back(I(static_cast<T>(MINV + 2 + d)));\n        }\n      \
    \  // \u7A4D\u304C\u3061\u3087\u3046\u3069\u5883\u754C\u306B\u306A\u308B\u4ED8\
    \u8FD1\n        for (__int128 s : {static_cast<__int128>(1) << (std::numeric_limits<T>::digits\
    \ / 2), MAXV / 2, MAXV / 3}) {\n            for (int d = -1; d <= 1; d++) {\n\
    \                vals.push_back(I(static_cast<T>(s + d)));\n                vals.push_back(I(static_cast<T>(-(s\
    \ + d))));\n            }\n        }\n        for (int i = 0; i < 12; i++) vals.push_back(I(static_cast<T>(rng()\
    \ % 2000) - 1000));\n        for (int i = 0; i < 12; i++) {\n            T x =\
    \ static_cast<T>(rng());\n            if (x == std::numeric_limits<T>::min() ||\
    \ x == std::numeric_limits<T>::max() || x == std::numeric_limits<T>::min() + 1)\
    \ x = 0;\n            vals.push_back(I(x));\n        }\n\n        // \u5024\u306E\
    \u4F5C\u308A\u65B9\u3068\u5224\u5B9A\n        if (I::max().val() != MAXV - 1 ||\
    \ I::min().val() != MINV + 2) ok = false;\n        if (!I::max().is_finite() ||\
    \ !I::min().is_finite()) ok = false;\n        if (I().val() != 0 || !I().is_finite())\
    \ ok = false;\n        if (!I::inf().is_plus_inf() || !I::inf().is_inf() || I::minus_inf().is_inf()\
    \ || !I::minus_inf().is_minus_inf()) ok = false;\n        if (I::nan().is_finite()\
    \ || I::plus_inf().is_finite() || I::minus_inf().is_finite()) ok = false;\n\n\
    \        for (const I& a : vals) {\n            Naive na = of(a);\n          \
    \  if (a.is_finite() != (na.kind == Naive::Finite)) ok = false;\n            //\
    \ \u5358\u9805\u306E + \u3068 -\n            if (!same(of(+a), na)) ok = false;\n\
    \            if (!same(of(-a), neg(na))) ok = false;\n            for (const I&\
    \ b : vals) {\n                Naive nb = of(b);\n                if (!same(of(a\
    \ + b), add(na, nb))) ok = false;\n                if (!same(of(a - b), add(na,\
    \ neg(nb)))) ok = false;\n                if (!same(of(a * b), mul(na, nb))) ok\
    \ = false;\n                if (!same(of(a / b), div(na, nb))) ok = false;\n \
    \               if (!same(of(a % b), mod(na, nb))) ok = false;\n             \
    \   // \u8907\u5408\u4EE3\u5165\u3082\u540C\u3058\u7D50\u679C\n              \
    \  I c = a;\n                c -= b;\n                if (!same(of(c), add(na,\
    \ neg(nb)))) ok = false;\n                c = a;\n                c *= b;\n  \
    \              if (!same(of(c), mul(na, nb))) ok = false;\n                c =\
    \ a;\n                c /= b;\n                if (!same(of(c), div(na, nb)))\
    \ ok = false;\n                c = a;\n                c %= b;\n             \
    \   if (!same(of(c), mod(na, nb))) ok = false;\n                // \u6BD4\u8F03\
    : NaN \u3092\u542B\u3080\u3068\u5E38\u306B false\u3002== \u3068 != \u306F\u5185\
    \u90E8\u8868\u73FE\u306E\u6BD4\u8F03\n                bool has_nan = na.kind ==\
    \ Naive::NaN || nb.kind == Naive::NaN;\n                __int128 ka = has_nan\
    \ ? 0 : key(na), kb = has_nan ? 0 : key(nb);\n                if ((a < b) != (!has_nan\
    \ && ka < kb)) ok = false;\n                if ((a > b) != (!has_nan && ka > kb))\
    \ ok = false;\n                if ((a <= b) != (!has_nan && ka <= kb)) ok = false;\n\
    \                if ((a >= b) != (!has_nan && ka >= kb)) ok = false;\n       \
    \         if ((a == b) != (a.val() == b.val())) ok = false;\n                if\
    \ ((a != b) != (a.val() != b.val())) ok = false;\n            }\n        }\n \
    \       return ok;\n    }\n};\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    bool ok = true;\n    if (!Checker<int>::run(rng)) ok = false, std::cerr <<\
    \ \"int\" << std::endl;\n    if (!Checker<long long>::run(rng)) ok = false, std::cerr\
    \ << \"long long\" << std::endl;\n    if (!Checker<short>::run(rng)) ok = false,\
    \ std::cerr << \"short\" << std::endl;\n\n    using I = infint<long long>;\n \
    \   // \u6587\u5B57\u5217\u304B\u3089\u306E\u69CB\u7BC9 (\u5927\u6587\u5B57\u5C0F\
    \u6587\u5B57\u306F\u554F\u308F\u306A\u3044)\n    if (!I(\"inf\").is_plus_inf()\
    \ || !I(\"INF\").is_plus_inf() || !I(\"PlusInf\").is_plus_inf()) ok = false;\n\
    \    if (!I(\"minusinf\").is_minus_inf() || !I(\"MinusINF\").is_minus_inf()) ok\
    \ = false;\n    if (!I(\"nan\").is_nan() || !I(\"NaN\").is_nan()) ok = false;\n\
    \    if (I(\"123\").val() != 123 || I(\"-45\").val() != -45 || I(\"0\").val()\
    \ != 0) ok = false;\n\n    // \u6587\u5B57\u5217\u5316\u3068\u8868\u8A18\u306E\
    \u5909\u66F4\n    if (I::inf().to_string() != \"inf\" || I::minus_inf().to_string()\
    \ != \"-inf\" || I::nan().to_string() != \"nan\" || I(-42).to_string() != \"-42\"\
    ) ok = false;\n    {\n        std::ostringstream os;\n        os << I::inf() <<\
    \ ' ' << I(7) << ' ' << I::nan();\n        if (os.str() != \"inf 7 nan\") ok =\
    \ false;\n    }\n    I::set_str_plusinf(\"INF\");\n    I::set_str_minusinf(\"\
    -INF\");\n    I::set_str_nan(\"?\");\n    {\n        std::ostringstream os;\n\
    \        os << I::inf() << ' ' << I::minus_inf() << ' ' << I::nan() << ' ' <<\
    \ I(5);\n        if (os.str() != \"INF -INF ? 5\") ok = false;\n    }\n    I::set_str_plusinf(\"\
    inf\");\n    I::set_str_minusinf(\"-inf\");\n    I::set_str_nan(\"nan\");\n  \
    \  if (I::inf().to_string() != \"inf\") ok = false;\n\n    // repr: \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u305D\u306E\u307E\u307E\u4F7F\u3048\u308B\
    \u6587\u5B57\u5217\n    if (I::type_str() != \"infint<>\") ok = false;\n    if\
    \ (I(5).initializer_str() != \"{5}\" || I(-3).repr() != \"infint<>{-3}\") ok =\
    \ false;\n    if (I::inf().repr() != \"infint<>{\\\"plusinf\\\"}\" || I::minus_inf().repr()\
    \ != \"infint<>{\\\"minusinf\\\"}\" || I::nan().repr() != \"infint<>{\\\"nan\\\
    \"}\") ok = false;\n    // repr \u306E\u7D50\u679C\u304B\u3089\u4F5C\u308A\u76F4\
    \u3059\u3068\u540C\u3058\u5024\u306B\u306A\u308B\n    if (!I(\"plusinf\").is_plus_inf()\
    \ || !I(\"minusinf\").is_minus_inf()) ok = false;\n\n    if (ok) std::cout <<\
    \ \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// infint \u306E\u6F14\u7B97\u3092\u3001\u7121\u9650\u5927\u30FBNaN \u3092\
    \u5206\u3051\u3066 __int128 \u3067\u611A\u76F4\u306B\u8A08\u7B97\u3057\u305F\u3082\
    \u306E\u3068\u6BD4\u8F03\u3059\u308B\n// \u5883\u754C\u306E\u5024 (max()\u3001\
    min() \u3068\u305D\u306E\u524D\u5F8C) \u3092\u542B\u3080\u5024\u306E\u5168\u7D44\
    \u3067\u3001\u56DB\u5247\u6F14\u7B97\u30FB\u5270\u4F59\u30FB\u6BD4\u8F03\u30FB\
    \u7B26\u53F7\u53CD\u8EE2\u3092\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/math/infint.hpp\"\
    \n\n#include <iostream>\n#include <limits>\n#include <random>\n#include <sstream>\n\
    #include <string>\n#include <vector>\n\n// \u611A\u76F4\u306A\u5024: \u7A2E\u985E\
    \u3068\u3001\u6709\u9650\u306E\u3068\u304D\u306E\u5024\nstruct Naive {\n    enum\
    \ Kind { Finite,\n                PlusInf,\n                MinusInf,\n      \
    \          NaN } kind;\n    __int128 v;\n};\n\ntemplate <typename T>\nstruct Checker\
    \ {\n    using I = infint<T>;\n    static constexpr __int128 MAXV = std::numeric_limits<T>::max();\
    \  // \u6B63\u306E\u7121\u9650\u5927\u306E\u5185\u90E8\u8868\u73FE\n    static\
    \ constexpr __int128 MINV = std::numeric_limits<T>::min();  // NaN \u306E\u5185\
    \u90E8\u8868\u73FE\n    // \u6709\u9650\u306E\u5024\u306E\u7BC4\u56F2\u306F [MINV\
    \ + 2, MAXV - 1]\n    static Naive fin(__int128 x) {\n        if (x >= MAXV) return\
    \ {Naive::PlusInf, 0};\n        if (x <= MINV + 1) return {Naive::MinusInf, 0};\n\
    \        return {Naive::Finite, x};\n    }\n    static Naive of(const I& a) {\n\
    \        if (a.is_nan()) return {Naive::NaN, 0};\n        if (a.is_plus_inf())\
    \ return {Naive::PlusInf, 0};\n        if (a.is_minus_inf()) return {Naive::MinusInf,\
    \ 0};\n        return {Naive::Finite, a.val()};\n    }\n    static int sign(const\
    \ Naive& a) {\n        if (a.kind == Naive::PlusInf) return 1;\n        if (a.kind\
    \ == Naive::MinusInf) return -1;\n        return (a.v > 0) - (a.v < 0);\n    }\n\
    \    static Naive inf_of_sign(int s) { return s > 0 ? Naive{Naive::PlusInf, 0}\
    \ : Naive{Naive::MinusInf, 0}; }\n    static bool same(const Naive& a, const Naive&\
    \ b) { return a.kind == b.kind && (a.kind != Naive::Finite || a.v == b.v); }\n\
    \n    static Naive add(Naive a, Naive b) {\n        if (a.kind == Naive::NaN ||\
    \ b.kind == Naive::NaN) return {Naive::NaN, 0};\n        if (a.kind != Naive::Finite\
    \ && b.kind != Naive::Finite) return a.kind == b.kind ? a : Naive{Naive::NaN,\
    \ 0};\n        if (a.kind != Naive::Finite) return a;\n        if (b.kind != Naive::Finite)\
    \ return b;\n        return fin(a.v + b.v);\n    }\n    static Naive neg(Naive\
    \ a) {\n        if (a.kind == Naive::PlusInf) return {Naive::MinusInf, 0};\n \
    \       if (a.kind == Naive::MinusInf) return {Naive::PlusInf, 0};\n        if\
    \ (a.kind == Naive::Finite) a.v = -a.v;\n        return a;\n    }\n    static\
    \ Naive mul(Naive a, Naive b) {\n        if (a.kind == Naive::NaN || b.kind ==\
    \ Naive::NaN) return {Naive::NaN, 0};\n        if (a.kind != Naive::Finite ||\
    \ b.kind != Naive::Finite) {\n            if (sign(a) == 0 || sign(b) == 0) return\
    \ {Naive::NaN, 0};  // 0 \xD7 \u221E\n            return inf_of_sign(sign(a) *\
    \ sign(b));\n        }\n        return fin(a.v * b.v);\n    }\n    static Naive\
    \ div(Naive a, Naive b) {\n        if (a.kind == Naive::NaN || b.kind == Naive::NaN)\
    \ return {Naive::NaN, 0};\n        if (a.kind != Naive::Finite && b.kind != Naive::Finite)\
    \ return {Naive::NaN, 0};\n        if (sign(b) == 0) return {Naive::NaN, 0};\n\
    \        if (b.kind != Naive::Finite) return {Naive::Finite, 0};\n        if (a.kind\
    \ != Naive::Finite) return inf_of_sign(sign(a) * sign(b));\n        return fin(a.v\
    \ / b.v);\n    }\n    static Naive mod(Naive a, Naive b) {\n        if (a.kind\
    \ == Naive::NaN || b.kind == Naive::NaN) return {Naive::NaN, 0};\n        if (a.kind\
    \ != Naive::Finite && b.kind != Naive::Finite) return {Naive::NaN, 0};\n     \
    \   if (sign(b) == 0) return {Naive::NaN, 0};\n        if (a.kind != Naive::Finite)\
    \ return {Naive::NaN, 0};\n        if (b.kind != Naive::Finite) return a;\n  \
    \      return fin(a.v % b.v);\n    }\n    // \u6BD4\u8F03\u7528\u306E\u9806\u5E8F\
    \ (NaN \u306F\u547C\u3070\u306A\u3044)\n    static __int128 key(const Naive& a)\
    \ {\n        if (a.kind == Naive::PlusInf) return MAXV;\n        if (a.kind ==\
    \ Naive::MinusInf) return MINV + 1;\n        return a.v;\n    }\n\n    static\
    \ bool run(std::mt19937_64& rng) {\n        bool ok = true;\n        std::vector<I>\
    \ vals = {I::plus_inf(), I::minus_inf(), I::nan(), I::inf(), I::max(), I::min(),\
    \ I(0), I(1), I(-1), I(2), I(-2), I(3), I(-7)};\n        for (__int128 d : {1,\
    \ 2, 3}) {\n            vals.push_back(I(static_cast<T>(MAXV - 1 - d)));\n   \
    \         vals.push_back(I(static_cast<T>(MINV + 2 + d)));\n        }\n      \
    \  // \u7A4D\u304C\u3061\u3087\u3046\u3069\u5883\u754C\u306B\u306A\u308B\u4ED8\
    \u8FD1\n        for (__int128 s : {static_cast<__int128>(1) << (std::numeric_limits<T>::digits\
    \ / 2), MAXV / 2, MAXV / 3}) {\n            for (int d = -1; d <= 1; d++) {\n\
    \                vals.push_back(I(static_cast<T>(s + d)));\n                vals.push_back(I(static_cast<T>(-(s\
    \ + d))));\n            }\n        }\n        for (int i = 0; i < 12; i++) vals.push_back(I(static_cast<T>(rng()\
    \ % 2000) - 1000));\n        for (int i = 0; i < 12; i++) {\n            T x =\
    \ static_cast<T>(rng());\n            if (x == std::numeric_limits<T>::min() ||\
    \ x == std::numeric_limits<T>::max() || x == std::numeric_limits<T>::min() + 1)\
    \ x = 0;\n            vals.push_back(I(x));\n        }\n\n        // \u5024\u306E\
    \u4F5C\u308A\u65B9\u3068\u5224\u5B9A\n        if (I::max().val() != MAXV - 1 ||\
    \ I::min().val() != MINV + 2) ok = false;\n        if (!I::max().is_finite() ||\
    \ !I::min().is_finite()) ok = false;\n        if (I().val() != 0 || !I().is_finite())\
    \ ok = false;\n        if (!I::inf().is_plus_inf() || !I::inf().is_inf() || I::minus_inf().is_inf()\
    \ || !I::minus_inf().is_minus_inf()) ok = false;\n        if (I::nan().is_finite()\
    \ || I::plus_inf().is_finite() || I::minus_inf().is_finite()) ok = false;\n\n\
    \        for (const I& a : vals) {\n            Naive na = of(a);\n          \
    \  if (a.is_finite() != (na.kind == Naive::Finite)) ok = false;\n            //\
    \ \u5358\u9805\u306E + \u3068 -\n            if (!same(of(+a), na)) ok = false;\n\
    \            if (!same(of(-a), neg(na))) ok = false;\n            for (const I&\
    \ b : vals) {\n                Naive nb = of(b);\n                if (!same(of(a\
    \ + b), add(na, nb))) ok = false;\n                if (!same(of(a - b), add(na,\
    \ neg(nb)))) ok = false;\n                if (!same(of(a * b), mul(na, nb))) ok\
    \ = false;\n                if (!same(of(a / b), div(na, nb))) ok = false;\n \
    \               if (!same(of(a % b), mod(na, nb))) ok = false;\n             \
    \   // \u8907\u5408\u4EE3\u5165\u3082\u540C\u3058\u7D50\u679C\n              \
    \  I c = a;\n                c -= b;\n                if (!same(of(c), add(na,\
    \ neg(nb)))) ok = false;\n                c = a;\n                c *= b;\n  \
    \              if (!same(of(c), mul(na, nb))) ok = false;\n                c =\
    \ a;\n                c /= b;\n                if (!same(of(c), div(na, nb)))\
    \ ok = false;\n                c = a;\n                c %= b;\n             \
    \   if (!same(of(c), mod(na, nb))) ok = false;\n                // \u6BD4\u8F03\
    : NaN \u3092\u542B\u3080\u3068\u5E38\u306B false\u3002== \u3068 != \u306F\u5185\
    \u90E8\u8868\u73FE\u306E\u6BD4\u8F03\n                bool has_nan = na.kind ==\
    \ Naive::NaN || nb.kind == Naive::NaN;\n                __int128 ka = has_nan\
    \ ? 0 : key(na), kb = has_nan ? 0 : key(nb);\n                if ((a < b) != (!has_nan\
    \ && ka < kb)) ok = false;\n                if ((a > b) != (!has_nan && ka > kb))\
    \ ok = false;\n                if ((a <= b) != (!has_nan && ka <= kb)) ok = false;\n\
    \                if ((a >= b) != (!has_nan && ka >= kb)) ok = false;\n       \
    \         if ((a == b) != (a.val() == b.val())) ok = false;\n                if\
    \ ((a != b) != (a.val() != b.val())) ok = false;\n            }\n        }\n \
    \       return ok;\n    }\n};\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    bool ok = true;\n    if (!Checker<int>::run(rng)) ok = false, std::cerr <<\
    \ \"int\" << std::endl;\n    if (!Checker<long long>::run(rng)) ok = false, std::cerr\
    \ << \"long long\" << std::endl;\n    if (!Checker<short>::run(rng)) ok = false,\
    \ std::cerr << \"short\" << std::endl;\n\n    using I = infint<long long>;\n \
    \   // \u6587\u5B57\u5217\u304B\u3089\u306E\u69CB\u7BC9 (\u5927\u6587\u5B57\u5C0F\
    \u6587\u5B57\u306F\u554F\u308F\u306A\u3044)\n    if (!I(\"inf\").is_plus_inf()\
    \ || !I(\"INF\").is_plus_inf() || !I(\"PlusInf\").is_plus_inf()) ok = false;\n\
    \    if (!I(\"minusinf\").is_minus_inf() || !I(\"MinusINF\").is_minus_inf()) ok\
    \ = false;\n    if (!I(\"nan\").is_nan() || !I(\"NaN\").is_nan()) ok = false;\n\
    \    if (I(\"123\").val() != 123 || I(\"-45\").val() != -45 || I(\"0\").val()\
    \ != 0) ok = false;\n\n    // \u6587\u5B57\u5217\u5316\u3068\u8868\u8A18\u306E\
    \u5909\u66F4\n    if (I::inf().to_string() != \"inf\" || I::minus_inf().to_string()\
    \ != \"-inf\" || I::nan().to_string() != \"nan\" || I(-42).to_string() != \"-42\"\
    ) ok = false;\n    {\n        std::ostringstream os;\n        os << I::inf() <<\
    \ ' ' << I(7) << ' ' << I::nan();\n        if (os.str() != \"inf 7 nan\") ok =\
    \ false;\n    }\n    I::set_str_plusinf(\"INF\");\n    I::set_str_minusinf(\"\
    -INF\");\n    I::set_str_nan(\"?\");\n    {\n        std::ostringstream os;\n\
    \        os << I::inf() << ' ' << I::minus_inf() << ' ' << I::nan() << ' ' <<\
    \ I(5);\n        if (os.str() != \"INF -INF ? 5\") ok = false;\n    }\n    I::set_str_plusinf(\"\
    inf\");\n    I::set_str_minusinf(\"-inf\");\n    I::set_str_nan(\"nan\");\n  \
    \  if (I::inf().to_string() != \"inf\") ok = false;\n\n    // repr: \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u305D\u306E\u307E\u307E\u4F7F\u3048\u308B\
    \u6587\u5B57\u5217\n    if (I::type_str() != \"infint<>\") ok = false;\n    if\
    \ (I(5).initializer_str() != \"{5}\" || I(-3).repr() != \"infint<>{-3}\") ok =\
    \ false;\n    if (I::inf().repr() != \"infint<>{\\\"plusinf\\\"}\" || I::minus_inf().repr()\
    \ != \"infint<>{\\\"minusinf\\\"}\" || I::nan().repr() != \"infint<>{\\\"nan\\\
    \"}\") ok = false;\n    // repr \u306E\u7D50\u679C\u304B\u3089\u4F5C\u308A\u76F4\
    \u3059\u3068\u540C\u3058\u5024\u306B\u306A\u308B\n    if (!I(\"plusinf\").is_plus_inf()\
    \ || !I(\"minusinf\").is_minus_inf()) ok = false;\n\n    if (ok) std::cout <<\
    \ \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/math/infint.hpp
  isVerificationFile: true
  path: test/unittest/infint.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 12:08:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/infint.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/infint.test.cpp
- /verify/test/unittest/infint.test.cpp.html
title: test/unittest/infint.test.cpp
---
