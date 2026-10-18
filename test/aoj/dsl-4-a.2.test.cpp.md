---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/compress.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
  bundledCode: "#line 1 \"test/aoj/dsl-4-a.2.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n// Compress \u3067\u5EA7\u6A19\u5727\u7E2E\u3059\u308B\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"src/utility/compress.hpp\"\n\n/**\n * @file compress.hpp\n\
    \ * @brief \u5EA7\u6A19\u5727\u7E2E\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #line 11 \"src/utility/compress.hpp\"\n\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\
    \n *\n * \u5024\u3092 add \u3067\u767B\u9332\u3057\u3001build \u3067\u30BD\u30FC\
    \u30C8\u3068\u91CD\u8907\u9664\u53BB\u3092\u3057\u3066\u304B\u3089\u4F7F\u3046\
    \n * \u4F8B:\n * Compress<long long> cp(A);  // A \u3092\u767B\u9332\u3057\u3066\
    \ build \u307E\u3067\u884C\u3046\n * long long i = cp.id(A[0]);  // 0 <= i < cp.size()\n\
    \ *\n * @tparam T \u5024\u306E\u578B (< \u3067\u6BD4\u8F03\u3067\u304D\u308B\u3053\
    \u3068)\n */\ntemplate <typename T>\nclass Compress {\n    std::vector<T> xs;\n\
    \    bool built = false;\n\n   public:\n    Compress() = default;\n    /**\n \
    \    * @brief v \u306E\u5024\u3092\u767B\u9332\u3057\u3066 build \u3059\u308B\n\
    \     */\n    explicit Compress(const std::vector<T>& v) : xs(v) { build(); }\n\
    \n    /**\n     * @brief \u5024\u3092 1 \u3064\u767B\u9332\u3059\u308B\u3002build\
    \ \u306E\u524D\u306B\u547C\u3076\n     */\n    void add(const T& x) {\n      \
    \  assert(!built);\n        xs.push_back(x);\n    }\n    /**\n     * @brief v\
    \ \u306E\u5024\u3092\u3059\u3079\u3066\u767B\u9332\u3059\u308B\u3002build \u306E\
    \u524D\u306B\u547C\u3076\n     */\n    void add(const std::vector<T>& v) {\n \
    \       assert(!built);\n        xs.insert(xs.end(), v.begin(), v.end());\n  \
    \  }\n    /**\n     * @brief \u767B\u9332\u3057\u305F\u5024\u3092\u30BD\u30FC\u30C8\
    \u3057\u3066\u91CD\u8907\u3092\u9664\u304F O(n log n)\n     */\n    void build()\
    \ {\n        assert(!built);\n        std::sort(xs.begin(), xs.end());\n     \
    \   xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n        built = true;\n\
    \    }\n\n    /**\n     * @brief \u7570\u306A\u308B\u5024\u306E\u500B\u6570\n\
    \     */\n    long long size() const {\n        assert(built);\n        return\
    \ xs.size();\n    }\n    /**\n     * @brief \u767B\u9332\u3057\u305F\u5024 x \u306E\
    \u756A\u53F7 O(log n)\u3002\u767B\u9332\u3057\u3066\u3044\u306A\u3044\u5024\u306A\
    \u3089 assert \u3067\u843D\u3061\u308B\n     */\n    long long id(const T& x)\
    \ const {\n        const long long i = bisect_left(x);\n        assert(i < size()\
    \ && !(x < xs[i]));\n        return i;\n    }\n    /**\n     * @brief x \u4EE5\
    \u4E0A\u3067\u6700\u5C0F\u306E\u5024\u306E\u756A\u53F7 O(log n)\u3002\u306A\u3051\
    \u308C\u3070 size()\n     */\n    long long bisect_left(const T& x) const {\n\
    \        assert(built);\n        return std::lower_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin();\n    }\n    /**\n     * @brief x \u3088\u308A\u5927\u304D\u3044\
    \u6700\u5C0F\u306E\u5024\u306E\u756A\u53F7 O(log n)\u3002\u306A\u3051\u308C\u3070\
    \ size()\n     */\n    long long bisect_right(const T& x) const {\n        assert(built);\n\
    \        return std::upper_bound(xs.begin(), xs.end(), x) - xs.begin();\n    }\n\
    \    /**\n     * @brief x \u3092\u767B\u9332\u3057\u305F\u304B O(log n)\n    \
    \ */\n    bool contains(const T& x) const {\n        const long long i = bisect_left(x);\n\
    \        return i < size() && !(x < xs[i]);\n    }\n    /**\n     * @brief \u756A\
    \u53F7 i \u306E\u5024\n     */\n    const T& operator[](long long i) const {\n\
    \        assert(built && 0 <= i && i < size());\n        return xs[i];\n    }\n\
    \    /**\n     * @brief v \u306E\u5404\u5024\u3092\u756A\u53F7\u306B\u7F6E\u304D\
    \u63DB\u3048\u305F\u5217\n     */\n    std::vector<long long> ids(const std::vector<T>&\
    \ v) const {\n        std::vector<long long> res(v.size());\n        for (long\
    \ long i = 0; i < static_cast<long long>(v.size()); i++) res[i] = id(v[i]);\n\
    \        return res;\n    }\n    /**\n     * @brief \u30BD\u30FC\u30C8\u6E08\u307F\
    \u3067\u91CD\u8907\u306E\u306A\u3044\u5024\u306E\u5217\n     */\n    const std::vector<T>&\
    \ values() const {\n        assert(built);\n        return xs;\n    }\n};\n#line\
    \ 9 \"test/aoj/dsl-4-a.2.test.cpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<long long> x1(n), y1(n), x2(n), y2(n);\n    Compress<long\
    \ long> cx, cy;\n    for (int i = 0; i < n; i++) {\n        std::cin >> x1[i]\
    \ >> y1[i] >> x2[i] >> y2[i];\n        cx.add(x1[i]), cx.add(x2[i]);\n       \
    \ cy.add(y1[i]), cy.add(y2[i]);\n    }\n    cx.build();\n    cy.build();\n   \
    \ int w = cx.size(), h = cy.size();\n    std::vector<std::vector<int>> imos(w,\
    \ std::vector<int>(h));\n    for (int i = 0; i < n; i++) {\n        int a = cx.id(x1[i]),\
    \ b = cx.id(x2[i]);\n        int c = cy.id(y1[i]), d = cy.id(y2[i]);\n       \
    \ imos[a][c]++, imos[a][d]--, imos[b][c]--, imos[b][d]++;\n    }\n    for (int\
    \ i = 0; i < w; i++)\n        for (int j = 1; j < h; j++) imos[i][j] += imos[i][j\
    \ - 1];\n    for (int i = 1; i < w; i++)\n        for (int j = 0; j < h; j++)\
    \ imos[i][j] += imos[i - 1][j];\n    long long ans = 0;\n    for (int i = 0; i\
    \ + 1 < w; i++)\n        for (int j = 0; j + 1 < h; j++) {\n            if (imos[i][j]\
    \ > 0) ans += (cx[i + 1] - cx[i]) * (cy[j + 1] - cy[j]);\n        }\n    std::cout\
    \ << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n// Compress \u3067\u5EA7\u6A19\u5727\u7E2E\u3059\u308B\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"../../src/utility/compress.hpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    std::vector<long long> x1(n), y1(n),\
    \ x2(n), y2(n);\n    Compress<long long> cx, cy;\n    for (int i = 0; i < n; i++)\
    \ {\n        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];\n        cx.add(x1[i]),\
    \ cx.add(x2[i]);\n        cy.add(y1[i]), cy.add(y2[i]);\n    }\n    cx.build();\n\
    \    cy.build();\n    int w = cx.size(), h = cy.size();\n    std::vector<std::vector<int>>\
    \ imos(w, std::vector<int>(h));\n    for (int i = 0; i < n; i++) {\n        int\
    \ a = cx.id(x1[i]), b = cx.id(x2[i]);\n        int c = cy.id(y1[i]), d = cy.id(y2[i]);\n\
    \        imos[a][c]++, imos[a][d]--, imos[b][c]--, imos[b][d]++;\n    }\n    for\
    \ (int i = 0; i < w; i++)\n        for (int j = 1; j < h; j++) imos[i][j] += imos[i][j\
    \ - 1];\n    for (int i = 1; i < w; i++)\n        for (int j = 0; j < h; j++)\
    \ imos[i][j] += imos[i - 1][j];\n    long long ans = 0;\n    for (int i = 0; i\
    \ + 1 < w; i++)\n        for (int j = 0; j + 1 < h; j++) {\n            if (imos[i][j]\
    \ > 0) ans += (cx[i + 1] - cx[i]) * (cy[j + 1] - cy[j]);\n        }\n    std::cout\
    \ << ans << '\\n';\n}\n"
  dependsOn:
  - src/utility/compress.hpp
  isVerificationFile: true
  path: test/aoj/dsl-4-a.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl-4-a.2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl-4-a.2.test.cpp
- /verify/test/aoj/dsl-4-a.2.test.cpp.html
title: test/aoj/dsl-4-a.2.test.cpp
---
