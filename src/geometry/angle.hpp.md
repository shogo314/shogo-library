---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/angle.test.cpp
    title: test/unittest/angle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sort-points-by-argument.1.test.cpp
    title: test/yosupo/sort-points-by-argument.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sort-points-by-argument.2.test.cpp
    title: test/yosupo/sort-points-by-argument.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u504F\u89D2"
    links: []
  bundledCode: "#line 2 \"src/geometry/angle.hpp\"\n\n/**\n * @file angle.hpp\n *\
    \ @brief \u504F\u89D2\n */\n\n#include <cmath>\n#include <type_traits>\n#include\
    \ <utility>\n\n/**\n * @brief 2 \u6B21\u5143\u30D9\u30AF\u30C8\u30EB (x, y) \u306E\
    \u504F\u89D2\n *\n * x \u8EF8\u6B63\u65B9\u5411\u3092 0 \u3068\u3057\u3066\u53CD\
    \u6642\u8A08\u56DE\u308A\u306B [0, 2\u03C0) \u3067\u6BD4\u3079\u308B\u3002\u96F6\
    \u30D9\u30AF\u30C8\u30EB\u306F x \u8EF8\u6B63\u65B9\u5411\u3068\u540C\u3058\u504F\
    \u89D2\u3068\u3057\u3066\u6271\u3046\n * \u5916\u7A4D\u3067\u6BD4\u3079\u308B\u306E\
    \u3067\u3001\u6574\u6570\u578B\u306A\u3089\u8AA4\u5DEE\u306A\u304F\u6BD4\u3079\
    \u3089\u308C\u308B (\u5EA7\u6A19\u306E\u7D76\u5BFE\u5024\u306E 2 \u4E57\u304C\
    \ T \u306B\u53CE\u307E\u308B\u5FC5\u8981\u304C\u3042\u308B)\n *\n * std::sort(ps.begin(),\
    \ ps.end(), [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });\n\
    \ *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n */\ntemplate <typename T>\nstruct\
    \ Angle {\n    T x;  //!< x \u5EA7\u6A19\n    T y;  //!< y \u5EA7\u6A19\n\n  \
    \  /**\n     * @brief \u504F\u89D2 0 (\u96F6\u30D9\u30AF\u30C8\u30EB)\n     */\n\
    \    constexpr Angle() noexcept : x(), y() {}\n    /**\n     * @brief \u30D9\u30AF\
    \u30C8\u30EB (x, y) \u306E\u504F\u89D2\n     */\n    constexpr Angle(T x, T y)\
    \ noexcept : x(x), y(y) {}\n    /**\n     * @brief p[0], p[1] \u3092 x, y \u3068\
    \u3059\u308B (Vector<T, 2> \u3084 std::array<T, 2> \u304B\u3089\u4F5C\u308B)\n\
    \     */\n    template <typename P, typename = decltype(std::declval<const P&>()[0])>\n\
    \    constexpr explicit Angle(const P& p) noexcept : x(p[0]), y(p[1]) {}\n   \
    \ /**\n     * @brief p.first, p.second \u3092 x, y \u3068\u3059\u308B\n     */\n\
    \    constexpr explicit Angle(const std::pair<T, T>& p) noexcept : x(p.first),\
    \ y(p.second) {}\n\n    /**\n     * @brief \u96F6\u30D9\u30AF\u30C8\u30EB\u304B\
    \n     */\n    constexpr bool is_zero() const noexcept { return x == 0 && y ==\
    \ 0; }\n    /**\n     * @brief \u504F\u89D2\u304C [0, \u03C0) \u306A\u3089 0\u3001\
    [\u03C0, 2\u03C0) \u306A\u3089 1\n     */\n    constexpr int half() const noexcept\
    \ { return y < 0 || (y == 0 && x < 0); }\n    /**\n     * @brief \u504F\u89D2\
    \ (\u30E9\u30B8\u30A2\u30F3\u3001[0, 2\u03C0))\n     */\n    double radian() const\
    \ {\n        double t = std::atan2(static_cast<double>(y), static_cast<double>(x));\n\
    \        return t < 0 ? t + 2 * std::acos(-1.0) : t;\n    }\n\n    friend constexpr\
    \ bool operator<(const Angle& a, const Angle& b) noexcept {\n        // \u96F6\
    \u30D9\u30AF\u30C8\u30EB\u306F\u5916\u7A4D\u3067\u6BD4\u3079\u3089\u308C\u306A\
    \u3044\u306E\u3067\u3001\u504F\u89D2 0 (x \u8EF8\u6B63\u65B9\u5411) \u3068\u3057\
    \u3066\u5148\u306B\u5224\u5B9A\u3059\u308B\n        if (b.is_zero()) return false;\
    \                   // \u504F\u89D2 0 \u3088\u308A\u5C0F\u3055\u3044\u3082\u306E\
    \u306F\u306A\u3044\n        if (a.is_zero()) return !(b.y == 0 && b.x > 0);  //\
    \ b \u306E\u504F\u89D2\u304C 0 \u3088\u308A\u5927\u304D\u3044\u304B\n        if\
    \ (a.half() != b.half()) return a.half() < b.half();\n        return b.x * a.y\
    \ < a.x * b.y;\n    }\n    friend constexpr bool operator>(const Angle& a, const\
    \ Angle& b) noexcept { return b < a; }\n    friend constexpr bool operator<=(const\
    \ Angle& a, const Angle& b) noexcept { return !(b < a); }\n    friend constexpr\
    \ bool operator>=(const Angle& a, const Angle& b) noexcept { return !(a < b);\
    \ }\n    /**\n     * @brief \u504F\u89D2\u304C\u7B49\u3057\u3044\u304B (\u30D9\
    \u30AF\u30C8\u30EB\u3068\u3057\u3066\u7B49\u3057\u3044\u304B\u3067\u306F\u306A\
    \u3044)\n     */\n    friend constexpr bool operator==(const Angle& a, const Angle&\
    \ b) noexcept { return !(a < b) && !(b < a); }\n    friend constexpr bool operator!=(const\
    \ Angle& a, const Angle& b) noexcept { return !(a == b); }\n};\n\ntemplate <typename\
    \ P, typename = decltype(std::declval<const P&>()[0])>\nAngle(const P&) -> Angle<std::remove_cv_t<std::remove_reference_t<decltype(std::declval<const\
    \ P&>()[0])>>>;\ntemplate <typename T>\nAngle(const std::pair<T, T>&) -> Angle<T>;\n"
  code: "#pragma once\n\n/**\n * @file angle.hpp\n * @brief \u504F\u89D2\n */\n\n\
    #include <cmath>\n#include <type_traits>\n#include <utility>\n\n/**\n * @brief\
    \ 2 \u6B21\u5143\u30D9\u30AF\u30C8\u30EB (x, y) \u306E\u504F\u89D2\n *\n * x \u8EF8\
    \u6B63\u65B9\u5411\u3092 0 \u3068\u3057\u3066\u53CD\u6642\u8A08\u56DE\u308A\u306B\
    \ [0, 2\u03C0) \u3067\u6BD4\u3079\u308B\u3002\u96F6\u30D9\u30AF\u30C8\u30EB\u306F\
    \ x \u8EF8\u6B63\u65B9\u5411\u3068\u540C\u3058\u504F\u89D2\u3068\u3057\u3066\u6271\
    \u3046\n * \u5916\u7A4D\u3067\u6BD4\u3079\u308B\u306E\u3067\u3001\u6574\u6570\u578B\
    \u306A\u3089\u8AA4\u5DEE\u306A\u304F\u6BD4\u3079\u3089\u308C\u308B (\u5EA7\u6A19\
    \u306E\u7D76\u5BFE\u5024\u306E 2 \u4E57\u304C T \u306B\u53CE\u307E\u308B\u5FC5\
    \u8981\u304C\u3042\u308B)\n *\n * std::sort(ps.begin(), ps.end(), [](const auto&\
    \ a, const auto& b) { return Angle(a) < Angle(b); });\n *\n * @tparam T \u5EA7\
    \u6A19\u306E\u578B\n */\ntemplate <typename T>\nstruct Angle {\n    T x;  //!<\
    \ x \u5EA7\u6A19\n    T y;  //!< y \u5EA7\u6A19\n\n    /**\n     * @brief \u504F\
    \u89D2 0 (\u96F6\u30D9\u30AF\u30C8\u30EB)\n     */\n    constexpr Angle() noexcept\
    \ : x(), y() {}\n    /**\n     * @brief \u30D9\u30AF\u30C8\u30EB (x, y) \u306E\
    \u504F\u89D2\n     */\n    constexpr Angle(T x, T y) noexcept : x(x), y(y) {}\n\
    \    /**\n     * @brief p[0], p[1] \u3092 x, y \u3068\u3059\u308B (Vector<T, 2>\
    \ \u3084 std::array<T, 2> \u304B\u3089\u4F5C\u308B)\n     */\n    template <typename\
    \ P, typename = decltype(std::declval<const P&>()[0])>\n    constexpr explicit\
    \ Angle(const P& p) noexcept : x(p[0]), y(p[1]) {}\n    /**\n     * @brief p.first,\
    \ p.second \u3092 x, y \u3068\u3059\u308B\n     */\n    constexpr explicit Angle(const\
    \ std::pair<T, T>& p) noexcept : x(p.first), y(p.second) {}\n\n    /**\n     *\
    \ @brief \u96F6\u30D9\u30AF\u30C8\u30EB\u304B\n     */\n    constexpr bool is_zero()\
    \ const noexcept { return x == 0 && y == 0; }\n    /**\n     * @brief \u504F\u89D2\
    \u304C [0, \u03C0) \u306A\u3089 0\u3001[\u03C0, 2\u03C0) \u306A\u3089 1\n    \
    \ */\n    constexpr int half() const noexcept { return y < 0 || (y == 0 && x <\
    \ 0); }\n    /**\n     * @brief \u504F\u89D2 (\u30E9\u30B8\u30A2\u30F3\u3001[0,\
    \ 2\u03C0))\n     */\n    double radian() const {\n        double t = std::atan2(static_cast<double>(y),\
    \ static_cast<double>(x));\n        return t < 0 ? t + 2 * std::acos(-1.0) : t;\n\
    \    }\n\n    friend constexpr bool operator<(const Angle& a, const Angle& b)\
    \ noexcept {\n        // \u96F6\u30D9\u30AF\u30C8\u30EB\u306F\u5916\u7A4D\u3067\
    \u6BD4\u3079\u3089\u308C\u306A\u3044\u306E\u3067\u3001\u504F\u89D2 0 (x \u8EF8\
    \u6B63\u65B9\u5411) \u3068\u3057\u3066\u5148\u306B\u5224\u5B9A\u3059\u308B\n \
    \       if (b.is_zero()) return false;                   // \u504F\u89D2 0 \u3088\
    \u308A\u5C0F\u3055\u3044\u3082\u306E\u306F\u306A\u3044\n        if (a.is_zero())\
    \ return !(b.y == 0 && b.x > 0);  // b \u306E\u504F\u89D2\u304C 0 \u3088\u308A\
    \u5927\u304D\u3044\u304B\n        if (a.half() != b.half()) return a.half() <\
    \ b.half();\n        return b.x * a.y < a.x * b.y;\n    }\n    friend constexpr\
    \ bool operator>(const Angle& a, const Angle& b) noexcept { return b < a; }\n\
    \    friend constexpr bool operator<=(const Angle& a, const Angle& b) noexcept\
    \ { return !(b < a); }\n    friend constexpr bool operator>=(const Angle& a, const\
    \ Angle& b) noexcept { return !(a < b); }\n    /**\n     * @brief \u504F\u89D2\
    \u304C\u7B49\u3057\u3044\u304B (\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u7B49\
    \u3057\u3044\u304B\u3067\u306F\u306A\u3044)\n     */\n    friend constexpr bool\
    \ operator==(const Angle& a, const Angle& b) noexcept { return !(a < b) && !(b\
    \ < a); }\n    friend constexpr bool operator!=(const Angle& a, const Angle& b)\
    \ noexcept { return !(a == b); }\n};\n\ntemplate <typename P, typename = decltype(std::declval<const\
    \ P&>()[0])>\nAngle(const P&) -> Angle<std::remove_cv_t<std::remove_reference_t<decltype(std::declval<const\
    \ P&>()[0])>>>;\ntemplate <typename T>\nAngle(const std::pair<T, T>&) -> Angle<T>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/angle.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:33:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/angle.test.cpp
  - test/yosupo/sort-points-by-argument.2.test.cpp
  - test/yosupo/sort-points-by-argument.1.test.cpp
documentation_of: src/geometry/angle.hpp
layout: document
title: "\u504F\u89D2"
---

2 次元ベクトル $(x, y)$ の偏角を表す `Angle<T>` です。x 軸正方向を 0 として反時計回りに $[0, 2\pi)$ で比べます。零ベクトルは x 軸正方向と同じ偏角として扱います。外積で比べるので、整数型なら誤差なく比べられます。

```cpp
std::vector<Vector<long long>> ps(n);
std::sort(ps.begin(), ps.end(), [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });

std::vector<std::array<long long, 2>> qs(n);  // std::array や std::pair からも作れる
std::sort(qs.begin(), qs.end(), [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });

Angle a(1, 1), b(-1, 0);
bool c = a < b;          // true (π/4 < π)
double r = b.radian();   // π
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Angle()` / `Angle(x, y)` | 零ベクトル (偏角 0) / ベクトル $(x, y)$ の偏角 | $O(1)$ |
| `Angle(p)` | `p[0]`、`p[1]` (`Vector<T, 2>`、`std::array<T, 2>` など) か `p.first`、`p.second` (`std::pair<T, T>`) から作る | $O(1)$ |
| `is_zero()` | 零ベクトルか | $O(1)$ |
| `half()` | 偏角が $[0, \pi)$ なら 0、$[\pi, 2\pi)$ なら 1 | $O(1)$ |
| `radian()` | 偏角を $[0, 2\pi)$ のラジアンで返す (`double`) | $O(1)$ |
| `<`、`<=`、`>`、`>=`、`==`、`!=` | 偏角で比べる。`==` は偏角が等しいか (向きが同じなら長さが違っても等しい) | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `x` / `y` | ベクトルの座標 |

外積を計算するので、座標の絶対値の 2 乗が `T` に収まる必要があります。

## 関連

- 点・ベクトルとその他の幾何の関数は [幾何ベクトル](vector.hpp)
