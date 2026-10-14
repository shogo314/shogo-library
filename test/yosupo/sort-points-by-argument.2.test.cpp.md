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
  bundledCode: "#line 1 \"test/yosupo/sort-points-by-argument.2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <iostream>\n#include <vector>\n\n#line\
    \ 2 \"src/geometry/angle.hpp\"\n\n/**\n * @file angle.hpp\n * @brief \u504F\u89D2\
    \n */\n\n#include <cmath>\n#include <type_traits>\n#include <utility>\n\n/**\n\
    \ * @brief 2 \u6B21\u5143\u30D9\u30AF\u30C8\u30EB (x, y) \u306E\u504F\u89D2\n\
    \ *\n * x \u8EF8\u6B63\u65B9\u5411\u3092 0 \u3068\u3057\u3066\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B [0, 2\u03C0) \u3067\u6BD4\u3079\u308B\u3002\u96F6\u30D9\u30AF\
    \u30C8\u30EB\u306F x \u8EF8\u6B63\u65B9\u5411\u3068\u540C\u3058\u504F\u89D2\u3068\
    \u3057\u3066\u6271\u3046\n * \u5916\u7A4D\u3067\u6BD4\u3079\u308B\u306E\u3067\u3001\
    \u6574\u6570\u578B\u306A\u3089\u8AA4\u5DEE\u306A\u304F\u6BD4\u3079\u3089\u308C\
    \u308B (\u5EA7\u6A19\u306E\u7D76\u5BFE\u5024\u306E 2 \u4E57\u304C T \u306B\u53CE\
    \u307E\u308B\u5FC5\u8981\u304C\u3042\u308B)\n *\n * std::sort(ps.begin(), ps.end(),\
    \ [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n */\ntemplate <typename T>\nstruct Angle {\n   \
    \ T x; //!< x \u5EA7\u6A19\n    T y; //!< y \u5EA7\u6A19\n\n    /**\n     * @brief\
    \ \u504F\u89D2 0 (\u96F6\u30D9\u30AF\u30C8\u30EB)\n     */\n    constexpr Angle()\
    \ noexcept : x(), y() {}\n    /**\n     * @brief \u30D9\u30AF\u30C8\u30EB (x,\
    \ y) \u306E\u504F\u89D2\n     */\n    constexpr Angle(T x, T y) noexcept : x(x),\
    \ y(y) {}\n    /**\n     * @brief p[0], p[1] \u3092 x, y \u3068\u3059\u308B (Vector<T,\
    \ 2> \u3084 std::array<T, 2> \u304B\u3089\u4F5C\u308B)\n     */\n    template\
    \ <typename P, typename = decltype(std::declval<const P&>()[0])>\n    constexpr\
    \ explicit Angle(const P& p) noexcept : x(p[0]), y(p[1]) {}\n    /**\n     * @brief\
    \ p.first, p.second \u3092 x, y \u3068\u3059\u308B\n     */\n    constexpr explicit\
    \ Angle(const std::pair<T, T>& p) noexcept : x(p.first), y(p.second) {}\n\n  \
    \  /**\n     * @brief \u96F6\u30D9\u30AF\u30C8\u30EB\u304B\n     */\n    constexpr\
    \ bool is_zero() const noexcept { return x == 0 && y == 0; }\n    /**\n     *\
    \ @brief \u504F\u89D2\u304C [0, \u03C0) \u306A\u3089 0\u3001[\u03C0, 2\u03C0)\
    \ \u306A\u3089 1\n     */\n    constexpr int half() const noexcept { return y\
    \ < 0 || (y == 0 && x < 0); }\n    /**\n     * @brief \u504F\u89D2 (\u30E9\u30B8\
    \u30A2\u30F3\u3001[0, 2\u03C0))\n     */\n    double radian() const {\n      \
    \  double t = std::atan2(static_cast<double>(y), static_cast<double>(x));\n  \
    \      return t < 0 ? t + 2 * std::acos(-1.0) : t;\n    }\n\n    friend constexpr\
    \ bool operator<(const Angle& a, const Angle& b) noexcept {\n        // \u96F6\
    \u30D9\u30AF\u30C8\u30EB\u306F\u5916\u7A4D\u3067\u6BD4\u3079\u3089\u308C\u306A\
    \u3044\u306E\u3067\u3001\u504F\u89D2 0 (x \u8EF8\u6B63\u65B9\u5411) \u3068\u3057\
    \u3066\u5148\u306B\u5224\u5B9A\u3059\u308B\n        if (b.is_zero()) return false;\
    \  // \u504F\u89D2 0 \u3088\u308A\u5C0F\u3055\u3044\u3082\u306E\u306F\u306A\u3044\
    \n        if (a.is_zero()) return !(b.y == 0 && b.x > 0);  // b \u306E\u504F\u89D2\
    \u304C 0 \u3088\u308A\u5927\u304D\u3044\u304B\n        if (a.half() != b.half())\
    \ return a.half() < b.half();\n        return b.x * a.y < a.x * b.y;\n    }\n\
    \    friend constexpr bool operator>(const Angle& a, const Angle& b) noexcept\
    \ { return b < a; }\n    friend constexpr bool operator<=(const Angle& a, const\
    \ Angle& b) noexcept { return !(b < a); }\n    friend constexpr bool operator>=(const\
    \ Angle& a, const Angle& b) noexcept { return !(a < b); }\n    /**\n     * @brief\
    \ \u504F\u89D2\u304C\u7B49\u3057\u3044\u304B (\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u7B49\u3057\u3044\u304B\u3067\u306F\u306A\u3044)\n     */\n    friend constexpr\
    \ bool operator==(const Angle& a, const Angle& b) noexcept { return !(a < b) &&\
    \ !(b < a); }\n    friend constexpr bool operator!=(const Angle& a, const Angle&\
    \ b) noexcept { return !(a == b); }\n};\n\ntemplate <typename P, typename = decltype(std::declval<const\
    \ P&>()[0])>\nAngle(const P&) -> Angle<std::remove_cv_t<std::remove_reference_t<decltype(std::declval<const\
    \ P&>()[0])>>>;\ntemplate <typename T>\nAngle(const std::pair<T, T>&) -> Angle<T>;\n\
    #line 9 \"test/yosupo/sort-points-by-argument.2.test.cpp\"\n\nint main() {\n \
    \   std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int n;\
    \ std::cin >> n;\n    std::vector<std::array<long long, 2>> ps(n);\n    for (auto&\
    \ [x, y] : ps) std::cin >> x >> y;\n    // Angle \u306F x \u8EF8\u6B63\u65B9\u5411\
    \u304B\u3089\u53CD\u6642\u8A08\u56DE\u308A ([0, 2\u03C0)) \u306B\u6BD4\u3079\u308B\
    \n    std::sort(ps.begin(), ps.end(), [](const auto& a, const auto& b) { return\
    \ Angle(a) < Angle(b); });\n    // \u554F\u984C\u306F x <= 0, y = 0 \u306E\u534A\
    \u76F4\u7DDA\u306E\u76F4\u5F8C\u304B\u3089 ((-\u03C0, \u03C0]) \u306A\u306E\u3067\
    \u3001y < 0 \u306E\u70B9\u3092\u5148\u982D\u306B\u79FB\u3059\n    std::stable_partition(ps.begin(),\
    \ ps.end(), [](const auto& p) { return p[1] < 0; });\n    for (const auto& [x,\
    \ y] : ps) std::cout << x << ' ' << y << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include <algorithm>\n#include <array>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../src/geometry/angle.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n; std::cin >> n;\n    std::vector<std::array<long\
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
  path: test/yosupo/sort-points-by-argument.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 07:04:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sort-points-by-argument.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sort-points-by-argument.2.test.cpp
- /verify/test/yosupo/sort-points-by-argument.2.test.cpp.html
title: test/yosupo/sort-points-by-argument.2.test.cpp
---
