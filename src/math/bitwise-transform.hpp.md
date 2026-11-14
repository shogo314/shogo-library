---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/bitwise-transform.test.cpp
    title: test/unittest/math/bitwise-transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution/bitwise-and-convolution.test.cpp
    title: test/yosupo/convolution/bitwise-and-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution/bitwise-xor-convolution.test.cpp
    title: test/yosupo/convolution/bitwise-xor-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_power_series/exp-of-set-power-series.test.cpp
    title: test/yosupo/set_power_series/exp-of-set-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_power_series/log-of-set-power-series.test.cpp
    title: test/yosupo/set_power_series/log-of-set-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_power_series/subset-convolution.test.cpp
    title: test/yosupo/set_power_series/subset-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u90E8\u5206\u96C6\u5408\u30FB\u4E0A\u4F4D\u96C6\u5408\u306E\u30BC\
      \u30FC\u30BF\u5909\u63DB\u3001\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3068\u30D3\
      \u30C3\u30C8\u6F14\u7B97 (AND\u30FBOR\u30FBXOR) \u306E\u7573\u307F\u8FBC\u307F\
      \u3001\u90E8\u5206\u96C6\u5408\u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "#line 2 \"src/math/bitwise-transform.hpp\"\n\n/**\n * @file bitwise-transform.hpp\n\
    \ * @brief \u90E8\u5206\u96C6\u5408\u30FB\u4E0A\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\
    \u30BF\u5909\u63DB\u3001\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3068\u30D3\u30C3\
    \u30C8\u6F14\u7B97 (AND\u30FBOR\u30FBXOR) \u306E\u7573\u307F\u8FBC\u307F\u3001\
    \u90E8\u5206\u96C6\u5408\u7573\u307F\u8FBC\u307F\n */\n\n#include <cassert>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace internal_bitwise_transform\
    \ {\n// \u9577\u3055\u304C 2 \u306E\u7D2F\u4E57\u304B\ninline bool is_power_of_two(long\
    \ long n) { return n > 0 && (n & (n - 1)) == 0; }\n}  // namespace internal_bitwise_transform\n\
    \n/**\n * @brief \u90E8\u5206\u96C6\u5408\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
    \ a[S] <- sum_{T \u2286 S} a[T] O(N log N)\n * N = a.size() \u306F 2 \u306E\u7D2F\
    \u4E57\n */\ntemplate <typename T>\nvoid subset_zeta(std::vector<T>& a) {\n  \
    \  int n = a.size();\n    assert(internal_bitwise_transform::is_power_of_two(n));\n\
    \    for (int w = 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n\
    \            if (s & w) a[s] += a[s ^ w];\n        }\n    }\n}\n\n/**\n * @brief\
    \ \u90E8\u5206\u96C6\u5408\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (subset_zeta\
    \ \u306E\u9006\u5909\u63DB) O(N log N)\n * N = a.size() \u306F 2 \u306E\u7D2F\u4E57\
    \n */\ntemplate <typename T>\nvoid subset_mobius(std::vector<T>& a) {\n    int\
    \ n = a.size();\n    assert(internal_bitwise_transform::is_power_of_two(n));\n\
    \    for (int w = 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n\
    \            if (s & w) a[s] -= a[s ^ w];\n        }\n    }\n}\n\n/**\n * @brief\
    \ \u4E0A\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\u5909\u63DB a[S] <- sum_{S\
    \ \u2286 T} a[T] O(N log N)\n * N = a.size() \u306F 2 \u306E\u7D2F\u4E57\n */\n\
    template <typename T>\nvoid superset_zeta(std::vector<T>& a) {\n    int n = a.size();\n\
    \    assert(internal_bitwise_transform::is_power_of_two(n));\n    for (int w =\
    \ 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n            if\
    \ (s & w) a[s ^ w] += a[s];\n        }\n    }\n}\n\n/**\n * @brief \u4E0A\u4F4D\
    \u96C6\u5408\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (superset_zeta \u306E\u9006\
    \u5909\u63DB) O(N log N)\n * N = a.size() \u306F 2 \u306E\u7D2F\u4E57\n */\ntemplate\
    \ <typename T>\nvoid superset_mobius(std::vector<T>& a) {\n    int n = a.size();\n\
    \    assert(internal_bitwise_transform::is_power_of_two(n));\n    for (int w =\
    \ 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n            if\
    \ (s & w) a[s ^ w] -= a[s];\n        }\n    }\n}\n\n/**\n * @brief \u30A2\u30C0\
    \u30DE\u30FC\u30EB\u5909\u63DB a[S] <- sum_T (-1)^popcount(S & T) a[T] O(N log\
    \ N)\n * N = a.size() \u306F 2 \u306E\u7D2F\u4E57\u3002inverse = true \u306A\u3089\
    \u9006\u5909\u63DB (\u6700\u5F8C\u306B N \u3067\u5272\u308B)\n */\ntemplate <typename\
    \ T>\nvoid walsh_hadamard(std::vector<T>& a, bool inverse = false) {\n    int\
    \ n = a.size();\n    assert(internal_bitwise_transform::is_power_of_two(n));\n\
    \    for (int w = 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n\
    \            if (s & w) {\n                T x = a[s ^ w], y = a[s];\n       \
    \         a[s ^ w] = x + y;\n                a[s] = x - y;\n            }\n  \
    \      }\n    }\n    if (inverse) {\n        if constexpr (std::is_integral_v<T>)\
    \ {\n            // \u7D50\u679C\u306F\u6574\u6570\u306A\u306E\u3067\u5272\u308A\
    \u5207\u308C\u308B\n            for (T& x : a) x /= T(n);\n        } else {\n\
    \            T inv_n = T(1) / T(n);\n            for (T& x : a) x *= inv_n;\n\
    \        }\n    }\n}\n\n/**\n * @brief AND \u7573\u307F\u8FBC\u307F c[k] = sum_{i\
    \ & j = k} a[i] b[j] O(N log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055\
    \ N \u3067\u3001N \u306F 2 \u306E\u7D2F\u4E57\n */\ntemplate <typename T>\nstd::vector<T>\
    \ and_convolution(std::vector<T> a, std::vector<T> b) {\n    assert(a.size() ==\
    \ b.size());\n    superset_zeta(a);\n    superset_zeta(b);\n    for (int i = 0;\
    \ i < static_cast<int>(a.size()); i++) a[i] *= b[i];\n    superset_mobius(a);\n\
    \    return a;\n}\n\n/**\n * @brief OR \u7573\u307F\u8FBC\u307F c[k] = sum_{i\
    \ | j = k} a[i] b[j] O(N log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055\
    \ N \u3067\u3001N \u306F 2 \u306E\u7D2F\u4E57\n */\ntemplate <typename T>\nstd::vector<T>\
    \ or_convolution(std::vector<T> a, std::vector<T> b) {\n    assert(a.size() ==\
    \ b.size());\n    subset_zeta(a);\n    subset_zeta(b);\n    for (int i = 0; i\
    \ < static_cast<int>(a.size()); i++) a[i] *= b[i];\n    subset_mobius(a);\n  \
    \  return a;\n}\n\n/**\n * @brief XOR \u7573\u307F\u8FBC\u307F c[k] = sum_{i ^\
    \ j = k} a[i] b[j] O(N log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055 N\
    \ \u3067\u3001N \u306F 2 \u306E\u7D2F\u4E57\u3002T \u306F N \u3067\u5272\u308C\
    \u308B\u3053\u3068 (modint\u3001\u6574\u6570\u578B\u3001\u6D6E\u52D5\u5C0F\u6570\
    \u70B9\u6570)\n */\ntemplate <typename T>\nstd::vector<T> xor_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    assert(a.size() == b.size());\n    walsh_hadamard(a);\n\
    \    walsh_hadamard(b);\n    for (int i = 0; i < static_cast<int>(a.size()); i++)\
    \ a[i] *= b[i];\n    walsh_hadamard(a, true);\n    return a;\n}\n\nnamespace internal_bitwise_transform\
    \ {\n// \u30E9\u30F3\u30AF\u4ED8\u304D\u30BC\u30FC\u30BF\u5909\u63DB\u3002f[s\
    \ * w + k] (w = n + 1) \u306F\u3001\u8981\u7D20\u6570 k \u306E\u90E8\u5206\u96C6\
    \u5408 T \u2286 s \u306B\u3064\u3044\u3066\u306E a[T] \u306E\u548C\ntemplate <typename\
    \ T>\nstd::vector<T> ranked_zeta(const std::vector<T>& a, int n) {\n    const\
    \ int len = 1 << n, w = n + 1;\n    std::vector<T> f(static_cast<long long>(len)\
    \ * w);\n    for (int s = 0; s < len; s++) f[static_cast<long long>(s) * w + __builtin_popcount(s)]\
    \ = a[s];\n    for (int bit = 1; bit < len; bit <<= 1) {\n        for (int s =\
    \ 0; s < len; s++) {\n            if (!(s & bit)) continue;\n            T* x\
    \ = &f[static_cast<long long>(s) * w];\n            const T* px = &f[static_cast<long\
    \ long>(s ^ bit) * w];\n            for (int k = 0; k < w; k++) x[k] += px[k];\n\
    \        }\n    }\n    return f;\n}\n// ranked_zeta \u306E\u9006\u5909\u63DB\u3092\
    \u3057\u3066\u3001\u5404 s \u306B\u3064\u3044\u3066\u8981\u7D20\u6570 popcount(s)\
    \ \u306E\u5024\u3092\u53D6\u308A\u51FA\u3059\ntemplate <typename T>\nstd::vector<T>\
    \ ranked_mobius(std::vector<T> f, int n) {\n    const int len = 1 << n, w = n\
    \ + 1;\n    for (int bit = 1; bit < len; bit <<= 1) {\n        for (int s = 0;\
    \ s < len; s++) {\n            if (!(s & bit)) continue;\n            T* x = &f[static_cast<long\
    \ long>(s) * w];\n            const T* px = &f[static_cast<long long>(s ^ bit)\
    \ * w];\n            for (int k = 0; k < w; k++) x[k] -= px[k];\n        }\n \
    \   }\n    std::vector<T> c(len);\n    for (int s = 0; s < len; s++) c[s] = f[static_cast<long\
    \ long>(s) * w + __builtin_popcount(s)];\n    return c;\n}\ninline int log2_exact(long\
    \ long len) {\n    assert(is_power_of_two(len));\n    int n = 0;\n    while ((1LL\
    \ << n) < len) n++;\n    return n;\n}\n}  // namespace internal_bitwise_transform\n\
    \n/**\n * @brief \u90E8\u5206\u96C6\u5408\u7573\u307F\u8FBC\u307F c[k] = sum_{i\
    \ | j = k, i & j = 0} a[i] b[j] O(N log^2 N)\n * \u30E9\u30F3\u30AF\u4ED8\u304D\
    \u30BC\u30FC\u30BF\u5909\u63DB\u3092\u3057\u3066\u3001\u96C6\u5408\u3054\u3068\
    \u306B\u8981\u7D20\u6570\u306B\u3064\u3044\u3066\u306E\u591A\u9805\u5F0F\u3068\
    \u3057\u3066\u639B\u3051\u3001\u30E9\u30F3\u30AF\u4ED8\u304D\u30E1\u30D3\u30A6\
    \u30B9\u5909\u63DB\u3067\u623B\u3059\n * @note a \u3068 b \u306E\u9577\u3055\u306F\
    \u540C\u3058 2 \u306E\u3079\u304D\n */\ntemplate <typename T>\nstd::vector<T>\
    \ subset_convolution(const std::vector<T>& a, const std::vector<T>& b) {\n   \
    \ using namespace internal_bitwise_transform;\n    assert(a.size() == b.size());\n\
    \    const int n = log2_exact(a.size()), len = 1 << n, w = n + 1;\n    auto fa\
    \ = ranked_zeta(a, n);\n    const auto fb = ranked_zeta(b, n);\n    std::vector<T>\
    \ tmp(w);\n    for (int s = 0; s < len; s++) {\n        T* x = &fa[static_cast<long\
    \ long>(s) * w];\n        const T* y = &fb[static_cast<long long>(s) * w];\n \
    \       for (int k = 0; k < w; k++) {\n            T sum = T();\n            for\
    \ (int i = 0; i <= k; i++) sum += x[i] * y[k - i];\n            tmp[k] = sum;\n\
    \        }\n        for (int k = 0; k < w; k++) x[k] = tmp[k];\n    }\n    return\
    \ ranked_mobius(std::move(fa), n);\n}\n\n/**\n * @brief \u96C6\u5408\u51AA\u7D1A\
    \u6570\u306E exp: \u03A3_m a^m / m! (\u7A4D\u306F\u90E8\u5206\u96C6\u5408\u7573\
    \u307F\u8FBC\u307F) O(N log^2 N)\n * \u30E9\u30F3\u30AF\u4ED8\u304D\u30BC\u30FC\
    \u30BF\u5909\u63DB\u3092\u3057\u3066\u3001\u96C6\u5408\u3054\u3068\u306B\u8981\
    \u7D20\u6570\u306B\u3064\u3044\u3066\u306E\u591A\u9805\u5F0F p \u306E exp \u3092\
    \ q' = p' q \u304B\u3089\u6C42\u3081\u3001\u30E9\u30F3\u30AF\u4ED8\u304D\u30E1\
    \u30D3\u30A6\u30B9\u5909\u63DB\u3067\u623B\u3059\n * @note a[0] = 0\u3002\u9577\
    \u3055\u306F 2 \u306E\u3079\u304D\u3002\u8981\u7D20\u306F\u4F53 (\u5272\u308A\u7B97\
    \u3092\u4F7F\u3046)\n */\ntemplate <typename T>\nstd::vector<T> set_power_series_exp(const\
    \ std::vector<T>& a) {\n    using namespace internal_bitwise_transform;\n    const\
    \ int n = log2_exact(a.size()), len = 1 << n, w = n + 1;\n    assert(a[0] == T(0));\n\
    \    auto f = ranked_zeta(a, n);\n    std::vector<T> inv(w + 1), q(w), ip(w);\n\
    \    for (int k = 1; k <= w; k++) inv[k] = T(1) / T(k);\n    for (int s = 0; s\
    \ < len; s++) {\n        T* p = &f[static_cast<long long>(s) * w];\n        //\
    \ q[k] = (1 / k) \u03A3_{i=1}^{k} i p[i] q[k-i]\n        for (int i = 1; i < w;\
    \ i++) ip[i] = T(i) * p[i];\n        q[0] = T(1);\n        for (int k = 1; k <\
    \ w; k++) {\n            T sum = T();\n            for (int i = 1; i <= k; i++)\
    \ sum += ip[i] * q[k - i];\n            q[k] = sum * inv[k];\n        }\n    \
    \    for (int k = 0; k < w; k++) p[k] = q[k];\n    }\n    return ranked_mobius(std::move(f),\
    \ n);\n}\n\n/**\n * @brief \u96C6\u5408\u51AA\u7D1A\u6570\u306E log (exp \u306E\
    \u9006) O(N log^2 N)\n * \u96C6\u5408\u3054\u3068\u306B\u8981\u7D20\u6570\u306B\
    \u3064\u3044\u3066\u306E\u591A\u9805\u5F0F p \u306E log \u3092 p q' = p' \u304B\
    \u3089\u6C42\u3081\u308B\n * @note a[0] = 1\u3002\u9577\u3055\u306F 2 \u306E\u3079\
    \u304D\u3002\u8981\u7D20\u306F\u4F53 (\u5272\u308A\u7B97\u3092\u4F7F\u3046)\n\
    \ */\ntemplate <typename T>\nstd::vector<T> set_power_series_log(const std::vector<T>&\
    \ a) {\n    using namespace internal_bitwise_transform;\n    const int n = log2_exact(a.size()),\
    \ len = 1 << n, w = n + 1;\n    assert(a[0] == T(1));\n    auto f = ranked_zeta(a,\
    \ n);\n    std::vector<T> inv(w + 1), q(w), iq(w);\n    for (int k = 1; k <= w;\
    \ k++) inv[k] = T(1) / T(k);\n    for (int s = 0; s < len; s++) {\n        T*\
    \ p = &f[static_cast<long long>(s) * w];\n        // p[0] = 1 \u306A\u306E\u3067\
    \u3001k q[k] = k p[k] - \u03A3_{i=1}^{k-1} i q[i] p[k-i]\n        q[0] = T();\n\
    \        for (int k = 1; k < w; k++) {\n            T sum = T(k) * p[k];\n   \
    \         for (int i = 1; i < k; i++) sum -= iq[i] * p[k - i];\n            q[k]\
    \ = sum * inv[k];\n            iq[k] = T(k) * q[k];\n        }\n        for (int\
    \ k = 0; k < w; k++) p[k] = q[k];\n    }\n    return ranked_mobius(std::move(f),\
    \ n);\n}\n"
  code: "#pragma once\n\n/**\n * @file bitwise-transform.hpp\n * @brief \u90E8\u5206\
    \u96C6\u5408\u30FB\u4E0A\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
    \u3001\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3068\u30D3\u30C3\u30C8\u6F14\u7B97\
    \ (AND\u30FBOR\u30FBXOR) \u306E\u7573\u307F\u8FBC\u307F\u3001\u90E8\u5206\u96C6\
    \u5408\u7573\u307F\u8FBC\u307F\n */\n\n#include <cassert>\n#include <type_traits>\n\
    #include <vector>\n\nnamespace internal_bitwise_transform {\n// \u9577\u3055\u304C\
    \ 2 \u306E\u7D2F\u4E57\u304B\ninline bool is_power_of_two(long long n) { return\
    \ n > 0 && (n & (n - 1)) == 0; }\n}  // namespace internal_bitwise_transform\n\
    \n/**\n * @brief \u90E8\u5206\u96C6\u5408\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
    \ a[S] <- sum_{T \u2286 S} a[T] O(N log N)\n * N = a.size() \u306F 2 \u306E\u7D2F\
    \u4E57\n */\ntemplate <typename T>\nvoid subset_zeta(std::vector<T>& a) {\n  \
    \  int n = a.size();\n    assert(internal_bitwise_transform::is_power_of_two(n));\n\
    \    for (int w = 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n\
    \            if (s & w) a[s] += a[s ^ w];\n        }\n    }\n}\n\n/**\n * @brief\
    \ \u90E8\u5206\u96C6\u5408\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (subset_zeta\
    \ \u306E\u9006\u5909\u63DB) O(N log N)\n * N = a.size() \u306F 2 \u306E\u7D2F\u4E57\
    \n */\ntemplate <typename T>\nvoid subset_mobius(std::vector<T>& a) {\n    int\
    \ n = a.size();\n    assert(internal_bitwise_transform::is_power_of_two(n));\n\
    \    for (int w = 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n\
    \            if (s & w) a[s] -= a[s ^ w];\n        }\n    }\n}\n\n/**\n * @brief\
    \ \u4E0A\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\u5909\u63DB a[S] <- sum_{S\
    \ \u2286 T} a[T] O(N log N)\n * N = a.size() \u306F 2 \u306E\u7D2F\u4E57\n */\n\
    template <typename T>\nvoid superset_zeta(std::vector<T>& a) {\n    int n = a.size();\n\
    \    assert(internal_bitwise_transform::is_power_of_two(n));\n    for (int w =\
    \ 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n            if\
    \ (s & w) a[s ^ w] += a[s];\n        }\n    }\n}\n\n/**\n * @brief \u4E0A\u4F4D\
    \u96C6\u5408\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (superset_zeta \u306E\u9006\
    \u5909\u63DB) O(N log N)\n * N = a.size() \u306F 2 \u306E\u7D2F\u4E57\n */\ntemplate\
    \ <typename T>\nvoid superset_mobius(std::vector<T>& a) {\n    int n = a.size();\n\
    \    assert(internal_bitwise_transform::is_power_of_two(n));\n    for (int w =\
    \ 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n            if\
    \ (s & w) a[s ^ w] -= a[s];\n        }\n    }\n}\n\n/**\n * @brief \u30A2\u30C0\
    \u30DE\u30FC\u30EB\u5909\u63DB a[S] <- sum_T (-1)^popcount(S & T) a[T] O(N log\
    \ N)\n * N = a.size() \u306F 2 \u306E\u7D2F\u4E57\u3002inverse = true \u306A\u3089\
    \u9006\u5909\u63DB (\u6700\u5F8C\u306B N \u3067\u5272\u308B)\n */\ntemplate <typename\
    \ T>\nvoid walsh_hadamard(std::vector<T>& a, bool inverse = false) {\n    int\
    \ n = a.size();\n    assert(internal_bitwise_transform::is_power_of_two(n));\n\
    \    for (int w = 1; w < n; w <<= 1) {\n        for (int s = 0; s < n; s++) {\n\
    \            if (s & w) {\n                T x = a[s ^ w], y = a[s];\n       \
    \         a[s ^ w] = x + y;\n                a[s] = x - y;\n            }\n  \
    \      }\n    }\n    if (inverse) {\n        if constexpr (std::is_integral_v<T>)\
    \ {\n            // \u7D50\u679C\u306F\u6574\u6570\u306A\u306E\u3067\u5272\u308A\
    \u5207\u308C\u308B\n            for (T& x : a) x /= T(n);\n        } else {\n\
    \            T inv_n = T(1) / T(n);\n            for (T& x : a) x *= inv_n;\n\
    \        }\n    }\n}\n\n/**\n * @brief AND \u7573\u307F\u8FBC\u307F c[k] = sum_{i\
    \ & j = k} a[i] b[j] O(N log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055\
    \ N \u3067\u3001N \u306F 2 \u306E\u7D2F\u4E57\n */\ntemplate <typename T>\nstd::vector<T>\
    \ and_convolution(std::vector<T> a, std::vector<T> b) {\n    assert(a.size() ==\
    \ b.size());\n    superset_zeta(a);\n    superset_zeta(b);\n    for (int i = 0;\
    \ i < static_cast<int>(a.size()); i++) a[i] *= b[i];\n    superset_mobius(a);\n\
    \    return a;\n}\n\n/**\n * @brief OR \u7573\u307F\u8FBC\u307F c[k] = sum_{i\
    \ | j = k} a[i] b[j] O(N log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055\
    \ N \u3067\u3001N \u306F 2 \u306E\u7D2F\u4E57\n */\ntemplate <typename T>\nstd::vector<T>\
    \ or_convolution(std::vector<T> a, std::vector<T> b) {\n    assert(a.size() ==\
    \ b.size());\n    subset_zeta(a);\n    subset_zeta(b);\n    for (int i = 0; i\
    \ < static_cast<int>(a.size()); i++) a[i] *= b[i];\n    subset_mobius(a);\n  \
    \  return a;\n}\n\n/**\n * @brief XOR \u7573\u307F\u8FBC\u307F c[k] = sum_{i ^\
    \ j = k} a[i] b[j] O(N log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055 N\
    \ \u3067\u3001N \u306F 2 \u306E\u7D2F\u4E57\u3002T \u306F N \u3067\u5272\u308C\
    \u308B\u3053\u3068 (modint\u3001\u6574\u6570\u578B\u3001\u6D6E\u52D5\u5C0F\u6570\
    \u70B9\u6570)\n */\ntemplate <typename T>\nstd::vector<T> xor_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    assert(a.size() == b.size());\n    walsh_hadamard(a);\n\
    \    walsh_hadamard(b);\n    for (int i = 0; i < static_cast<int>(a.size()); i++)\
    \ a[i] *= b[i];\n    walsh_hadamard(a, true);\n    return a;\n}\n\nnamespace internal_bitwise_transform\
    \ {\n// \u30E9\u30F3\u30AF\u4ED8\u304D\u30BC\u30FC\u30BF\u5909\u63DB\u3002f[s\
    \ * w + k] (w = n + 1) \u306F\u3001\u8981\u7D20\u6570 k \u306E\u90E8\u5206\u96C6\
    \u5408 T \u2286 s \u306B\u3064\u3044\u3066\u306E a[T] \u306E\u548C\ntemplate <typename\
    \ T>\nstd::vector<T> ranked_zeta(const std::vector<T>& a, int n) {\n    const\
    \ int len = 1 << n, w = n + 1;\n    std::vector<T> f(static_cast<long long>(len)\
    \ * w);\n    for (int s = 0; s < len; s++) f[static_cast<long long>(s) * w + __builtin_popcount(s)]\
    \ = a[s];\n    for (int bit = 1; bit < len; bit <<= 1) {\n        for (int s =\
    \ 0; s < len; s++) {\n            if (!(s & bit)) continue;\n            T* x\
    \ = &f[static_cast<long long>(s) * w];\n            const T* px = &f[static_cast<long\
    \ long>(s ^ bit) * w];\n            for (int k = 0; k < w; k++) x[k] += px[k];\n\
    \        }\n    }\n    return f;\n}\n// ranked_zeta \u306E\u9006\u5909\u63DB\u3092\
    \u3057\u3066\u3001\u5404 s \u306B\u3064\u3044\u3066\u8981\u7D20\u6570 popcount(s)\
    \ \u306E\u5024\u3092\u53D6\u308A\u51FA\u3059\ntemplate <typename T>\nstd::vector<T>\
    \ ranked_mobius(std::vector<T> f, int n) {\n    const int len = 1 << n, w = n\
    \ + 1;\n    for (int bit = 1; bit < len; bit <<= 1) {\n        for (int s = 0;\
    \ s < len; s++) {\n            if (!(s & bit)) continue;\n            T* x = &f[static_cast<long\
    \ long>(s) * w];\n            const T* px = &f[static_cast<long long>(s ^ bit)\
    \ * w];\n            for (int k = 0; k < w; k++) x[k] -= px[k];\n        }\n \
    \   }\n    std::vector<T> c(len);\n    for (int s = 0; s < len; s++) c[s] = f[static_cast<long\
    \ long>(s) * w + __builtin_popcount(s)];\n    return c;\n}\ninline int log2_exact(long\
    \ long len) {\n    assert(is_power_of_two(len));\n    int n = 0;\n    while ((1LL\
    \ << n) < len) n++;\n    return n;\n}\n}  // namespace internal_bitwise_transform\n\
    \n/**\n * @brief \u90E8\u5206\u96C6\u5408\u7573\u307F\u8FBC\u307F c[k] = sum_{i\
    \ | j = k, i & j = 0} a[i] b[j] O(N log^2 N)\n * \u30E9\u30F3\u30AF\u4ED8\u304D\
    \u30BC\u30FC\u30BF\u5909\u63DB\u3092\u3057\u3066\u3001\u96C6\u5408\u3054\u3068\
    \u306B\u8981\u7D20\u6570\u306B\u3064\u3044\u3066\u306E\u591A\u9805\u5F0F\u3068\
    \u3057\u3066\u639B\u3051\u3001\u30E9\u30F3\u30AF\u4ED8\u304D\u30E1\u30D3\u30A6\
    \u30B9\u5909\u63DB\u3067\u623B\u3059\n * @note a \u3068 b \u306E\u9577\u3055\u306F\
    \u540C\u3058 2 \u306E\u3079\u304D\n */\ntemplate <typename T>\nstd::vector<T>\
    \ subset_convolution(const std::vector<T>& a, const std::vector<T>& b) {\n   \
    \ using namespace internal_bitwise_transform;\n    assert(a.size() == b.size());\n\
    \    const int n = log2_exact(a.size()), len = 1 << n, w = n + 1;\n    auto fa\
    \ = ranked_zeta(a, n);\n    const auto fb = ranked_zeta(b, n);\n    std::vector<T>\
    \ tmp(w);\n    for (int s = 0; s < len; s++) {\n        T* x = &fa[static_cast<long\
    \ long>(s) * w];\n        const T* y = &fb[static_cast<long long>(s) * w];\n \
    \       for (int k = 0; k < w; k++) {\n            T sum = T();\n            for\
    \ (int i = 0; i <= k; i++) sum += x[i] * y[k - i];\n            tmp[k] = sum;\n\
    \        }\n        for (int k = 0; k < w; k++) x[k] = tmp[k];\n    }\n    return\
    \ ranked_mobius(std::move(fa), n);\n}\n\n/**\n * @brief \u96C6\u5408\u51AA\u7D1A\
    \u6570\u306E exp: \u03A3_m a^m / m! (\u7A4D\u306F\u90E8\u5206\u96C6\u5408\u7573\
    \u307F\u8FBC\u307F) O(N log^2 N)\n * \u30E9\u30F3\u30AF\u4ED8\u304D\u30BC\u30FC\
    \u30BF\u5909\u63DB\u3092\u3057\u3066\u3001\u96C6\u5408\u3054\u3068\u306B\u8981\
    \u7D20\u6570\u306B\u3064\u3044\u3066\u306E\u591A\u9805\u5F0F p \u306E exp \u3092\
    \ q' = p' q \u304B\u3089\u6C42\u3081\u3001\u30E9\u30F3\u30AF\u4ED8\u304D\u30E1\
    \u30D3\u30A6\u30B9\u5909\u63DB\u3067\u623B\u3059\n * @note a[0] = 0\u3002\u9577\
    \u3055\u306F 2 \u306E\u3079\u304D\u3002\u8981\u7D20\u306F\u4F53 (\u5272\u308A\u7B97\
    \u3092\u4F7F\u3046)\n */\ntemplate <typename T>\nstd::vector<T> set_power_series_exp(const\
    \ std::vector<T>& a) {\n    using namespace internal_bitwise_transform;\n    const\
    \ int n = log2_exact(a.size()), len = 1 << n, w = n + 1;\n    assert(a[0] == T(0));\n\
    \    auto f = ranked_zeta(a, n);\n    std::vector<T> inv(w + 1), q(w), ip(w);\n\
    \    for (int k = 1; k <= w; k++) inv[k] = T(1) / T(k);\n    for (int s = 0; s\
    \ < len; s++) {\n        T* p = &f[static_cast<long long>(s) * w];\n        //\
    \ q[k] = (1 / k) \u03A3_{i=1}^{k} i p[i] q[k-i]\n        for (int i = 1; i < w;\
    \ i++) ip[i] = T(i) * p[i];\n        q[0] = T(1);\n        for (int k = 1; k <\
    \ w; k++) {\n            T sum = T();\n            for (int i = 1; i <= k; i++)\
    \ sum += ip[i] * q[k - i];\n            q[k] = sum * inv[k];\n        }\n    \
    \    for (int k = 0; k < w; k++) p[k] = q[k];\n    }\n    return ranked_mobius(std::move(f),\
    \ n);\n}\n\n/**\n * @brief \u96C6\u5408\u51AA\u7D1A\u6570\u306E log (exp \u306E\
    \u9006) O(N log^2 N)\n * \u96C6\u5408\u3054\u3068\u306B\u8981\u7D20\u6570\u306B\
    \u3064\u3044\u3066\u306E\u591A\u9805\u5F0F p \u306E log \u3092 p q' = p' \u304B\
    \u3089\u6C42\u3081\u308B\n * @note a[0] = 1\u3002\u9577\u3055\u306F 2 \u306E\u3079\
    \u304D\u3002\u8981\u7D20\u306F\u4F53 (\u5272\u308A\u7B97\u3092\u4F7F\u3046)\n\
    \ */\ntemplate <typename T>\nstd::vector<T> set_power_series_log(const std::vector<T>&\
    \ a) {\n    using namespace internal_bitwise_transform;\n    const int n = log2_exact(a.size()),\
    \ len = 1 << n, w = n + 1;\n    assert(a[0] == T(1));\n    auto f = ranked_zeta(a,\
    \ n);\n    std::vector<T> inv(w + 1), q(w), iq(w);\n    for (int k = 1; k <= w;\
    \ k++) inv[k] = T(1) / T(k);\n    for (int s = 0; s < len; s++) {\n        T*\
    \ p = &f[static_cast<long long>(s) * w];\n        // p[0] = 1 \u306A\u306E\u3067\
    \u3001k q[k] = k p[k] - \u03A3_{i=1}^{k-1} i q[i] p[k-i]\n        q[0] = T();\n\
    \        for (int k = 1; k < w; k++) {\n            T sum = T(k) * p[k];\n   \
    \         for (int i = 1; i < k; i++) sum -= iq[i] * p[k - i];\n            q[k]\
    \ = sum * inv[k];\n            iq[k] = T(k) * q[k];\n        }\n        for (int\
    \ k = 0; k < w; k++) p[k] = q[k];\n    }\n    return ranked_mobius(std::move(f),\
    \ n);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/bitwise-transform.hpp
  requiredBy: []
  timestamp: '2026-10-23 19:55:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/math/bitwise-transform.test.cpp
  - test/yosupo/set_power_series/subset-convolution.test.cpp
  - test/yosupo/set_power_series/exp-of-set-power-series.test.cpp
  - test/yosupo/set_power_series/log-of-set-power-series.test.cpp
  - test/yosupo/convolution/bitwise-xor-convolution.test.cpp
  - test/yosupo/convolution/bitwise-and-convolution.test.cpp
documentation_of: src/math/bitwise-transform.hpp
layout: document
title: "\u90E8\u5206\u96C6\u5408\u30FB\u4E0A\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\
  \u5909\u63DB\u3001\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3068\u30D3\u30C3\u30C8\u6F14\
  \u7B97 (AND\u30FBOR\u30FBXOR) \u306E\u7573\u307F\u8FBC\u307F\u3001\u90E8\u5206\u96C6\
  \u5408\u7573\u307F\u8FBC\u307F\u3001\u96C6\u5408\u51AA\u7D1A\u6570\u306E exp\u30FB\
  log"
---

添字を集合 (ビット列) とみて、部分集合・上位集合について和をとる変換と、その逆変換です。配列 `a` の長さ $N$ は 2 の累乗 ($N = 2^n$) で、添字 $S$ は $n$ 個の要素の集合を表します。値の型 `T` は `+`、`-`、`*` が使えれば何でもよく、`long long` や modint を想定しています。

ビットごとに「$S$ と $S$ からそのビットを除いたもの」の間で足すことを繰り返して計算します。

```cpp
std::vector<long long> a = {1, 2, 3, 4}, b = {5, 6, 7, 8};
auto c = and_convolution(a, b);  // {103, 52, 73, 32}
auto d = or_convolution(a, b);   // {5, 28, 43, 184}
auto e = xor_convolution(a, b);  // {70, 68, 62, 60}
auto f = subset_convolution(a, b);  // {5, 16, 22, 60}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `subset_zeta(a)` | $a_S \leftarrow \sum_{T \subseteq S} a_T$ (その場で書き換える) | $O(N \log N)$ |
| `subset_mobius(a)` | `subset_zeta` の逆変換 | $O(N \log N)$ |
| `superset_zeta(a)` | $a_S \leftarrow \sum_{S \subseteq T} a_T$ (その場で書き換える) | $O(N \log N)$ |
| `superset_mobius(a)` | `superset_zeta` の逆変換 | $O(N \log N)$ |
| `walsh_hadamard(a, inverse = false)` | アダマール変換 $a_S \leftarrow \sum_T (-1)^{\lvert S \cap T \rvert} a_T$。`inverse = true` なら逆変換 (最後に $N$ で割る) | $O(N \log N)$ |
| `and_convolution(a, b)` | $c_k = \sum_{i \mathbin{\&} j = k} a_i b_j$ を返す | $O(N \log N)$ |
| `or_convolution(a, b)` | $c_k = \sum_{i \mid j = k} a_i b_j$ を返す | $O(N \log N)$ |
| `xor_convolution(a, b)` | $c_k = \sum_{i \oplus j = k} a_i b_j$ を返す | $O(N \log N)$ |
| `subset_convolution(a, b)` | $c_k = \sum_{i \mid j = k,\ i \mathbin{\&} j = 0} a_i b_j$ を返す ($k$ を 2 つの交わらない集合に分ける) | 時間 $O(N \log^2 N)$、メモリ $O(N \log N)$ |
| `set_power_series_exp(a)` | 集合冪級数の exp $\sum_m a^m / m!$ (積は部分集合畳み込み)。$a_0 = 0$、要素は体 | 時間 $O(N \log^2 N)$、メモリ $O(N \log N)$ |
| `set_power_series_log(a)` | 集合冪級数の log (exp の逆)。$a_0 = 1$、要素は体 | 時間 $O(N \log^2 N)$、メモリ $O(N \log N)$ |

- `a` と `b` は同じ長さで、長さが 2 の累乗でないと assert で落ちます。
- `xor_convolution` と `walsh_hadamard(a, true)` は最後に $N$ で割ります。modint や浮動小数点数では $N$ の逆数を掛け、整数型では $N$ で割ります (結果が整数なので割り切れます)。

## 例: 部分集合についての和

bit DP で「$S$ の部分集合 $T$ すべてについての $f(T)$ の和」を、すべての $S$ について求めたいとき、部分集合を列挙すると $O(3^n)$ かかります。`subset_zeta` を使えば $O(n 2^n)$ です。

```cpp
std::vector<long long> f(1 << n);
// f[T] を入れる
subset_zeta(f);  // f[S] = sum_{T ⊆ S} f[T]
```

上位集合についての和は `superset_zeta` です。「ちょうど $S$」の値が欲しいときは、「$S$ の部分集合 (上位集合) すべて」の値を求めてからメビウス変換をします (包除原理)。

## 部分集合畳み込みの仕組み

$i \mathbin{\&} j = 0$ かつ $i \mid j = k$ は、$\lvert i \rvert + \lvert j \rvert = \lvert k \rvert$ かつ $i \mid j = k$ と同じです。そこで、各集合 $S$ について要素数ごとに値を分け (`f[S][|S|] = a[S]`)、要素数ごとに部分集合のゼータ変換をしてから、$S$ ごとに要素数についての多項式として掛けます。最後にメビウス変換をして、$S$ の要素数の位置の値を取り出します (ランク付きゼータ変換)。

$n = 20$ ($N = 2^{20}$) のとき、`T` が 4 バイトの modint なら、内部の表は 2 つで約 180 MB です。

```cpp
// dp[S] = S を交わらない 2 つの集合に分けたときの、cost の積の和
auto dp = subset_convolution(cost, cost);
```

## 集合冪級数の exp・log

部分集合畳み込みと同じくランク付きゼータ変換をすると、集合ごとに要素数についての多項式 $p(z)$ になり、積は多項式の積になります。exp は $q' = p' q$、log は $p q' = p'$ から、それぞれ $O(n^2)$ で係数を求めてから、ランク付きメビウス変換で戻します。全体で $O(2^n n^2)$ です ($n = 20$ で 1.5 秒ほど)。

集合冪級数 $a$ の exp の $S$ の係数は、$S$ を交わらない空でない集合 $T_1, \dots, T_k$ に分ける方法すべてについての $a_{T_1} \cdots a_{T_k}$ の和です。連結なグラフの数え上げ (log) や、集合の分割の数え上げ (exp) に使います。

## 関連

- 部分集合や上位集合を 1 つずつ列挙するには [ビット演算](../utility/bit.hpp) の `subsets`、`supersets`
- 添字の約数・倍数についての変換は [約数・倍数のゼータ変換、メビウス変換と GCD・LCM 畳み込み](divisor-transform.hpp)
