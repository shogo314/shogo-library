---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/angle.hpp
    title: "\u504F\u89D2"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/yosupo/geo/sort-points-by-argument.2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <iostream>\n#include <vector>\n\n#line\
    \ 2 \"src/geometry/angle.hpp\"\n\n/**\n * @file angle.hpp\n * @brief \u504F\u89D2\
    \n */\n\n#include <cassert>\n#include <cmath>\n#include <istream>\n#include <ostream>\n\
    #include <type_traits>\n#include <utility>\n\n/**\n * @brief 2 \u6B21\u5143\u30D9\
    \u30AF\u30C8\u30EB (x, y) \u306E\u504F\u89D2\n *\n * x \u8EF8\u6B63\u65B9\u5411\
    \u3092 0 \u3068\u3057\u3066\u53CD\u6642\u8A08\u56DE\u308A\u306B\u6E2C\u308A\u3001\
    \u5468\u56DE\u6570 turn \u3068\u5408\u308F\u305B\u3066 2\u03C0 * turn + [0, 2\u03C0\
    ) \u306E\u5024\u3068\u3057\u3066\u6BD4\u3079\u308B\u3002\u96F6\u30D9\u30AF\u30C8\
    \u30EB\u306F x \u8EF8\u6B63\u65B9\u5411\u3068\u540C\u3058\u504F\u89D2\u3068\u3057\
    \u3066\u6271\u3046\n * \u5916\u7A4D\u3067\u6BD4\u3079\u308B\u306E\u3067\u3001\u6574\
    \u6570\u578B\u306A\u3089\u8AA4\u5DEE\u306A\u304F\u6BD4\u3079\u3089\u308C\u308B\
    \ (\u5EA7\u6A19\u306E\u7D76\u5BFE\u5024\u306E 2 \u4E57\u304C T \u306B\u53CE\u307E\
    \u308B\u5FC5\u8981\u304C\u3042\u308B)\n *\n * std::sort(ps.begin(), ps.end(),\
    \ [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n */\ntemplate <typename T>\nstruct Angle {\n   \
    \ T x;                 //!< x \u5EA7\u6A19\n    T y;                 //!< y \u5EA7\
    \u6A19\n    long long turn = 0;  //!< \u5468\u56DE\u6570\n\n    /**\n     * @brief\
    \ \u504F\u89D2 0 (\u96F6\u30D9\u30AF\u30C8\u30EB)\n     */\n    constexpr Angle()\
    \ noexcept : x(), y() {}\n    /**\n     * @brief \u30D9\u30AF\u30C8\u30EB (x,\
    \ y) \u306E\u504F\u89D2\u306B 2\u03C0 * turn \u3092\u8DB3\u3057\u305F\u3082\u306E\
    \n     */\n    constexpr Angle(T x, T y, long long turn = 0) noexcept : x(x),\
    \ y(y), turn(turn) {}\n    /**\n     * @brief p[0], p[1] \u3092 x, y \u3068\u3059\
    \u308B (Vector<T, 2> \u3084 std::array<T, 2> \u304B\u3089\u4F5C\u308B)\n     */\n\
    \    template <typename P, typename = decltype(std::declval<const P&>()[0])>\n\
    \    constexpr explicit Angle(const P& p) noexcept : x(p[0]), y(p[1]) {}\n   \
    \ /**\n     * @brief p.first, p.second \u3092 x, y \u3068\u3059\u308B\n     */\n\
    \    constexpr explicit Angle(const std::pair<T, T>& p) noexcept : x(p.first),\
    \ y(p.second) {}\n\n    /**\n     * @brief \u96F6\u30D9\u30AF\u30C8\u30EB\u304B\
    \n     */\n    constexpr bool is_zero() const noexcept { return x == 0 && y ==\
    \ 0; }\n    /**\n     * @brief \u5468\u56DE\u6570\u3092\u9664\u3044\u305F\u504F\
    \u89D2\u304C [0, \u03C0) \u306A\u3089 0\u3001[\u03C0, 2\u03C0) \u306A\u3089 1\n\
    \     */\n    constexpr int half() const noexcept { return y < 0 || (y == 0 &&\
    \ x < 0); }\n    /**\n     * @brief \u504F\u89D2 (\u30E9\u30B8\u30A2\u30F3\u3001\
    2\u03C0 * turn + [0, 2\u03C0))\n     */\n    double radian() const {\n       \
    \ const double pi = std::acos(-1.0);\n        double t = std::atan2(static_cast<double>(y),\
    \ static_cast<double>(x));\n        return (t < 0 ? t + 2 * pi : t) + 2 * pi *\
    \ static_cast<double>(turn);\n    }\n    /**\n     * @brief 2\u03C0 \u3092\u8DB3\
    \u3057\u305F\u504F\u89D2\n     */\n    constexpr Angle next_turn() const noexcept\
    \ { return Angle(x, y, turn + 1); }\n    /**\n     * @brief \u03C0 \u3092\u8DB3\
    \u3057\u305F\u504F\u89D2 (\u9006\u5411\u304D\u306E\u30D9\u30AF\u30C8\u30EB)\u3002\
    \u96F6\u30D9\u30AF\u30C8\u30EB\u306B\u306F\u4F7F\u3048\u306A\u3044\n     */\n\
    \    constexpr Angle opposite() const noexcept {\n        assert(!is_zero() &&\
    \ \"Angle::opposite: zero vector\");\n        return Angle(-x, -y, turn + half());\n\
    \    }\n\n    /**\n     * @brief \u7B26\u53F7\u3092\u53CD\u8EE2\u3057\u305F\u504F\
    \u89D2 (x \u8EF8\u306B\u3064\u3044\u3066\u6298\u308A\u8FD4\u3057\u305F\u30D9\u30AF\
    \u30C8\u30EB)\n     */\n    constexpr Angle operator-() const noexcept {\n   \
    \     // \u5468\u56DE\u6570\u3092\u9664\u3044\u305F\u504F\u89D2\u304C 0 \u306A\
    \u3089 -2\u03C0 * turn\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 2\u03C0\
    \ \u3092\u8DB3\u3057\u3066 [0, 2\u03C0) \u306B\u53CE\u3081\u308B\n        bool\
    \ on_zero = y == 0 && x >= 0;\n        return Angle(x, -y, -turn - !on_zero);\n\
    \    }\n    /**\n     * @brief \u504F\u89D2\u306E\u548C (\u8907\u7D20\u6570\u3068\
    \u3057\u3066\u306E\u7A4D)\n     *\n     * \u5EA7\u6A19\u306F a \u3068 b \u306E\
    \u5EA7\u6A19\u306E\u7A4D\u306E\u5927\u304D\u3055\u306B\u306A\u308B\u3002\u96F6\
    \u30D9\u30AF\u30C8\u30EB\u306F\u504F\u89D2 0 \u3068\u3057\u3066\u6271\u3044\u3001\
    \u3082\u3046\u4E00\u65B9\u306E\u30D9\u30AF\u30C8\u30EB\u3092\u8FD4\u3059\n   \
    \  */\n    friend constexpr Angle operator+(const Angle& a, const Angle& b) noexcept\
    \ {\n        if (a.is_zero()) return Angle(b.x, b.y, a.turn + b.turn);\n     \
    \   if (b.is_zero()) return Angle(a.x, a.y, a.turn + b.turn);\n        Angle c(a.x\
    \ * b.x - a.y * b.y, a.x * b.y + a.y * b.x, a.turn + b.turn);\n        // \u5468\
    \u56DE\u6570\u3092\u9664\u3044\u305F\u504F\u89D2\u306E\u548C\u304C 2\u03C0 \u4EE5\
    \u4E0A\u306A\u3089\u7E70\u308A\u4E0A\u3052\u308B\n        // \u4E21\u65B9 [\u03C0\
    , 2\u03C0) \u306A\u3089\u5FC5\u305A\u3001\u7247\u65B9\u3060\u3051\u306A\u3089\u548C\
    \u306F [\u03C0, 3\u03C0) \u306A\u306E\u3067\u7D50\u679C\u304C [0, \u03C0) \u306E\
    \u3068\u304D\n        if (a.half() && b.half()) c.turn++;\n        if (a.half()\
    \ != b.half() && c.half() == 0) c.turn++;\n        return c;\n    }\n    /**\n\
    \     * @brief \u504F\u89D2\u306E\u5DEE (a \u304B\u3089 b \u3078\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B\u56DE\u3059\u89D2\u306F b - a)\n     */\n    friend constexpr\
    \ Angle operator-(const Angle& a, const Angle& b) noexcept { return a + (-b);\
    \ }\n    constexpr Angle& operator+=(const Angle& rhs) noexcept { return *this\
    \ = *this + rhs; }\n    constexpr Angle& operator-=(const Angle& rhs) noexcept\
    \ { return *this = *this - rhs; }\n\n    friend constexpr bool operator<(const\
    \ Angle& a, const Angle& b) noexcept {\n        if (a.turn != b.turn) return a.turn\
    \ < b.turn;\n        // \u96F6\u30D9\u30AF\u30C8\u30EB\u306F\u5916\u7A4D\u3067\
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
    \ noexcept { return !(a == b); }\n\n    /**\n     * @brief x, y \u3092\u8AAD\u3080\
    \ (\u5468\u56DE\u6570\u306F 0 \u306B\u3059\u308B)\n     */\n    template <class\
    \ CharT, class Traits>\n    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, Angle& rhs) {\n        rhs.turn = 0;\n        return is >> rhs.x\
    \ >> rhs.y;\n    }\n    /**\n     * @brief x, y \u3092\u7A7A\u767D\u533A\u5207\
    \u308A\u3067\u66F8\u304F (\u5468\u56DE\u6570\u306F\u66F8\u304B\u306A\u3044)\n\
    \     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const Angle& rhs)\
    \ {\n        return os << rhs.x << CharT(' ') << rhs.y;\n    }\n};\n\ntemplate\
    \ <typename P, typename = decltype(std::declval<const P&>()[0])>\nAngle(const\
    \ P&) -> Angle<std::remove_cv_t<std::remove_reference_t<decltype(std::declval<const\
    \ P&>()[0])>>>;\ntemplate <typename T>\nAngle(const std::pair<T, T>&) -> Angle<T>;\n\
    #line 9 \"test/yosupo/geo/sort-points-by-argument.2.test.cpp\"\n\nint main() {\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int n;\n\
    \    std::cin >> n;\n    std::vector<std::array<long long, 2>> ps(n);\n    for\
    \ (auto& [x, y] : ps) std::cin >> x >> y;\n    // Angle \u306F x \u8EF8\u6B63\u65B9\
    \u5411\u304B\u3089\u53CD\u6642\u8A08\u56DE\u308A ([0, 2\u03C0)) \u306B\u6BD4\u3079\
    \u308B\n    std::sort(ps.begin(), ps.end(), [](const auto& a, const auto& b) {\
    \ return Angle(a) < Angle(b); });\n    // \u554F\u984C\u306F x <= 0, y = 0 \u306E\
    \u534A\u76F4\u7DDA\u306E\u76F4\u5F8C\u304B\u3089 ((-\u03C0, \u03C0]) \u306A\u306E\
    \u3067\u3001y < 0 \u306E\u70B9\u3092\u5148\u982D\u306B\u79FB\u3059\n    std::stable_partition(ps.begin(),\
    \ ps.end(), [](const auto& p) { return p[1] < 0; });\n    for (const auto& [x,\
    \ y] : ps) std::cout << x << ' ' << y << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include <algorithm>\n#include <array>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../../src/geometry/angle.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n;\n    std::cin >> n;\n    std::vector<std::array<long\
    \ long, 2>> ps(n);\n    for (auto& [x, y] : ps) std::cin >> x >> y;\n    // Angle\
    \ \u306F x \u8EF8\u6B63\u65B9\u5411\u304B\u3089\u53CD\u6642\u8A08\u56DE\u308A\
    \ ([0, 2\u03C0)) \u306B\u6BD4\u3079\u308B\n    std::sort(ps.begin(), ps.end(),\
    \ [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });\n    // \u554F\
    \u984C\u306F x <= 0, y = 0 \u306E\u534A\u76F4\u7DDA\u306E\u76F4\u5F8C\u304B\u3089\
    \ ((-\u03C0, \u03C0]) \u306A\u306E\u3067\u3001y < 0 \u306E\u70B9\u3092\u5148\u982D\
    \u306B\u79FB\u3059\n    std::stable_partition(ps.begin(), ps.end(), [](const auto&\
    \ p) { return p[1] < 0; });\n    for (const auto& [x, y] : ps) std::cout << x\
    \ << ' ' << y << '\\n';\n}\n"
  dependsOn:
  - src/geometry/angle.hpp
  isVerificationFile: true
  path: test/yosupo/geo/sort-points-by-argument.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/geo/sort-points-by-argument.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/geo/sort-points-by-argument.2.test.cpp
- /verify/test/yosupo/geo/sort-points-by-argument.2.test.cpp.html
title: test/yosupo/geo/sort-points-by-argument.2.test.cpp
---
