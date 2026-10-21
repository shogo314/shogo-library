---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/imos-2d.hpp
    title: "2 \u6B21\u5143\u306E\u3044\u3082\u3059\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"test/aoj/dsl/dsl-5-b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <algorithm>\n#include <iostream>\n\n#line 2 \"src/data_structures/imos-2d.hpp\"\
    \n\n/**\n * @file imos-2d.hpp\n * @brief 2 \u6B21\u5143\u306E\u3044\u3082\u3059\
    \u6CD5\n */\n\n#include <cassert>\n#include <vector>\n\n/**\n * @brief 2 \u6B21\
    \u5143\u306E\u3044\u3082\u3059\u6CD5 (\u9577\u65B9\u5F62\u3078\u306E\u52A0\u7B97\
    \u3092\u305F\u3081\u3066\u304A\u304D\u3001\u6700\u5F8C\u306B\u307E\u3068\u3081\
    \u3066\u5404\u30DE\u30B9\u306E\u5024\u3092\u6C42\u3081\u308B)\n *\n * add \u306F\
    \ 4 \u9685\u306B\u8DB3\u3059\u3060\u3051\u3067 O(1)\u3001build \u3067 2 \u65B9\
    \u5411\u306E\u7D2F\u7A4D\u548C\u3092\u3068\u3063\u3066 O(hw)\u3002build \u306E\
    \u5F8C\u306F get \u3067\u5024\u3092\u8AAD\u3080\n * \u4F8B:\n * Imos2D<int> imos(h,\
    \ w);\n * imos.add(0, 0, 3, 2, 1);  // \u884C [0, 3)\u3001\u5217 [0, 2) \u306B\
    \ 1 \u3092\u8DB3\u3059\n * imos.build();\n * int x = imos.get(1, 1);\n *\n * @tparam\
    \ T \u5024\u306E\u578B\n */\ntemplate <typename T>\nclass Imos2D {\n    long long\
    \ h, w;\n    std::vector<std::vector<T>> a;  // (h + 1) \xD7 (w + 1)\n    bool\
    \ built = false;\n\n   public:\n    /**\n     * @brief h \u884C w \u5217\u3067\
    \u3001\u3059\u3079\u3066 0\n     */\n    Imos2D(long long h, long long w) : h(h),\
    \ w(w), a(h + 1, std::vector<T>(w + 1, T(0))) {}\n    /**\n     * @brief \u884C\
    \u6570\n     */\n    long long height() const { return h; }\n    /**\n     * @brief\
    \ \u5217\u6570\n     */\n    long long width() const { return w; }\n    /**\n\
    \     * @brief \u884C [i1, i2)\u3001\u5217 [j1, j2) \u306E\u30DE\u30B9\u306B x\
    \ \u3092\u8DB3\u3059 O(1)\u3002build \u306E\u524D\u306B\u9650\u308B\n     */\n\
    \    void add(long long i1, long long j1, long long i2, long long j2, const T&\
    \ x) {\n        assert(!built);\n        assert(0 <= i1 && i1 <= i2 && i2 <= h\
    \ && 0 <= j1 && j1 <= j2 && j2 <= w);\n        a[i1][j1] += x, a[i1][j2] -= x,\
    \ a[i2][j1] -= x, a[i2][j2] += x;\n    }\n    /**\n     * @brief \u7D2F\u7A4D\u548C\
    \u3092\u3068\u308A\u3001\u5404\u30DE\u30B9\u306E\u5024\u3092\u6C42\u3081\u308B\
    \ O(hw)\u30021 \u56DE\u3060\u3051\u547C\u3076\n     */\n    void build() {\n \
    \       assert(!built);\n        built = true;\n        for (long long i = 0;\
    \ i <= h; i++)\n            for (long long j = 1; j <= w; j++) a[i][j] += a[i][j\
    \ - 1];\n        for (long long i = 1; i <= h; i++)\n            for (long long\
    \ j = 0; j <= w; j++) a[i][j] += a[i - 1][j];\n    }\n    /**\n     * @brief \u30DE\
    \u30B9 (i, j) \u306E\u5024 O(1)\u3002build \u306E\u5F8C\u306B\u9650\u308B\n  \
    \   */\n    T get(long long i, long long j) const {\n        assert(built);\n\
    \        assert(0 <= i && i < h && 0 <= j && j < w);\n        return a[i][j];\n\
    \    }\n};\n#line 7 \"test/aoj/dsl/dsl-5-b.test.cpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n;\n    std::cin >> n;\n    const\
    \ int m = 1000;\n    Imos2D<int> imos(m, m);\n    for (int i = 0; i < n; i++)\
    \ {\n        int x1, y1, x2, y2;\n        std::cin >> x1 >> y1 >> x2 >> y2;\n\
    \        imos.add(x1, y1, x2, y2, 1);\n    }\n    imos.build();\n    int ans =\
    \ 0;\n    for (int i = 0; i < m; i++)\n        for (int j = 0; j < m; j++) ans\
    \ = std::max(ans, imos.get(i, j));\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <algorithm>\n#include <iostream>\n\n#include \"../../../src/data_structures/imos-2d.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n;\n    std::cin >> n;\n    const int m = 1000;\n    Imos2D<int> imos(m,\
    \ m);\n    for (int i = 0; i < n; i++) {\n        int x1, y1, x2, y2;\n      \
    \  std::cin >> x1 >> y1 >> x2 >> y2;\n        imos.add(x1, y1, x2, y2, 1);\n \
    \   }\n    imos.build();\n    int ans = 0;\n    for (int i = 0; i < m; i++)\n\
    \        for (int j = 0; j < m; j++) ans = std::max(ans, imos.get(i, j));\n  \
    \  std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - src/data_structures/imos-2d.hpp
  isVerificationFile: true
  path: test/aoj/dsl/dsl-5-b.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 05:52:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/dsl-5-b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/dsl-5-b.test.cpp
- /verify/test/aoj/dsl/dsl-5-b.test.cpp.html
title: test/aoj/dsl/dsl-5-b.test.cpp
---
