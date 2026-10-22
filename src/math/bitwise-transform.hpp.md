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
    \ a[i] *= b[i];\n    walsh_hadamard(a, true);\n    return a;\n}\n\n/**\n * @brief\
    \ \u90E8\u5206\u96C6\u5408\u7573\u307F\u8FBC\u307F c[k] = sum_{i | j = k, i &\
    \ j = 0} a[i] b[j] O(N log^2 N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055\
    \ N \u3067\u3001N \u306F 2 \u306E\u7D2F\u4E57\u3002\u30E1\u30E2\u30EA\u306F O(N\
    \ log N)\n */\ntemplate <typename T>\nstd::vector<T> subset_convolution(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    int len = a.size();\n   \
    \ assert(a.size() == b.size() && internal_bitwise_transform::is_power_of_two(len));\n\
    \    int n = 0;\n    while ((1 << n) < len) n++;\n    int w = n + 1;\n    // f[s\
    \ * w + k] \u306F\u3001\u8981\u7D20\u6570 k \u306E\u96C6\u5408\u3060\u3051\u3092\
    \u6B8B\u3057\u305F\u3082\u306E\u306E\u5024 (\u30E9\u30F3\u30AF\u4ED8\u304D\u30BC\
    \u30FC\u30BF\u5909\u63DB)\n    std::vector<T> fa(static_cast<long long>(len) *\
    \ w), fb(static_cast<long long>(len) * w);\n    for (int s = 0; s < len; s++)\
    \ {\n        int k = __builtin_popcount(s);\n        fa[static_cast<long long>(s)\
    \ * w + k] = a[s];\n        fb[static_cast<long long>(s) * w + k] = b[s];\n  \
    \  }\n    for (int bit = 1; bit < len; bit <<= 1) {\n        for (int s = 0; s\
    \ < len; s++) {\n            if (!(s & bit)) continue;\n            T* x = &fa[static_cast<long\
    \ long>(s) * w];\n            T* y = &fb[static_cast<long long>(s) * w];\n   \
    \         const T* px = &fa[static_cast<long long>(s ^ bit) * w];\n          \
    \  const T* py = &fb[static_cast<long long>(s ^ bit) * w];\n            for (int\
    \ k = 0; k < w; k++) {\n                x[k] += px[k];\n                y[k] +=\
    \ py[k];\n            }\n        }\n    }\n    // \u96C6\u5408\u3054\u3068\u306B\
    \u3001\u8981\u7D20\u6570\u306B\u3064\u3044\u3066\u306E\u591A\u9805\u5F0F\u3068\
    \u3057\u3066\u639B\u3051\u308B\n    std::vector<T> tmp(w);\n    for (int s = 0;\
    \ s < len; s++) {\n        T* x = &fa[static_cast<long long>(s) * w];\n      \
    \  const T* y = &fb[static_cast<long long>(s) * w];\n        for (int k = 0; k\
    \ < w; k++) {\n            T sum = T();\n            for (int i = 0; i <= k; i++)\
    \ sum += x[i] * y[k - i];\n            tmp[k] = sum;\n        }\n        for (int\
    \ k = 0; k < w; k++) x[k] = tmp[k];\n    }\n    for (int bit = 1; bit < len; bit\
    \ <<= 1) {\n        for (int s = 0; s < len; s++) {\n            if (!(s & bit))\
    \ continue;\n            T* x = &fa[static_cast<long long>(s) * w];\n        \
    \    const T* px = &fa[static_cast<long long>(s ^ bit) * w];\n            for\
    \ (int k = 0; k < w; k++) x[k] -= px[k];\n        }\n    }\n    std::vector<T>\
    \ c(len);\n    for (int s = 0; s < len; s++) c[s] = fa[static_cast<long long>(s)\
    \ * w + __builtin_popcount(s)];\n    return c;\n}\n"
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
    \ a[i] *= b[i];\n    walsh_hadamard(a, true);\n    return a;\n}\n\n/**\n * @brief\
    \ \u90E8\u5206\u96C6\u5408\u7573\u307F\u8FBC\u307F c[k] = sum_{i | j = k, i &\
    \ j = 0} a[i] b[j] O(N log^2 N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055\
    \ N \u3067\u3001N \u306F 2 \u306E\u7D2F\u4E57\u3002\u30E1\u30E2\u30EA\u306F O(N\
    \ log N)\n */\ntemplate <typename T>\nstd::vector<T> subset_convolution(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    int len = a.size();\n   \
    \ assert(a.size() == b.size() && internal_bitwise_transform::is_power_of_two(len));\n\
    \    int n = 0;\n    while ((1 << n) < len) n++;\n    int w = n + 1;\n    // f[s\
    \ * w + k] \u306F\u3001\u8981\u7D20\u6570 k \u306E\u96C6\u5408\u3060\u3051\u3092\
    \u6B8B\u3057\u305F\u3082\u306E\u306E\u5024 (\u30E9\u30F3\u30AF\u4ED8\u304D\u30BC\
    \u30FC\u30BF\u5909\u63DB)\n    std::vector<T> fa(static_cast<long long>(len) *\
    \ w), fb(static_cast<long long>(len) * w);\n    for (int s = 0; s < len; s++)\
    \ {\n        int k = __builtin_popcount(s);\n        fa[static_cast<long long>(s)\
    \ * w + k] = a[s];\n        fb[static_cast<long long>(s) * w + k] = b[s];\n  \
    \  }\n    for (int bit = 1; bit < len; bit <<= 1) {\n        for (int s = 0; s\
    \ < len; s++) {\n            if (!(s & bit)) continue;\n            T* x = &fa[static_cast<long\
    \ long>(s) * w];\n            T* y = &fb[static_cast<long long>(s) * w];\n   \
    \         const T* px = &fa[static_cast<long long>(s ^ bit) * w];\n          \
    \  const T* py = &fb[static_cast<long long>(s ^ bit) * w];\n            for (int\
    \ k = 0; k < w; k++) {\n                x[k] += px[k];\n                y[k] +=\
    \ py[k];\n            }\n        }\n    }\n    // \u96C6\u5408\u3054\u3068\u306B\
    \u3001\u8981\u7D20\u6570\u306B\u3064\u3044\u3066\u306E\u591A\u9805\u5F0F\u3068\
    \u3057\u3066\u639B\u3051\u308B\n    std::vector<T> tmp(w);\n    for (int s = 0;\
    \ s < len; s++) {\n        T* x = &fa[static_cast<long long>(s) * w];\n      \
    \  const T* y = &fb[static_cast<long long>(s) * w];\n        for (int k = 0; k\
    \ < w; k++) {\n            T sum = T();\n            for (int i = 0; i <= k; i++)\
    \ sum += x[i] * y[k - i];\n            tmp[k] = sum;\n        }\n        for (int\
    \ k = 0; k < w; k++) x[k] = tmp[k];\n    }\n    for (int bit = 1; bit < len; bit\
    \ <<= 1) {\n        for (int s = 0; s < len; s++) {\n            if (!(s & bit))\
    \ continue;\n            T* x = &fa[static_cast<long long>(s) * w];\n        \
    \    const T* px = &fa[static_cast<long long>(s ^ bit) * w];\n            for\
    \ (int k = 0; k < w; k++) x[k] -= px[k];\n        }\n    }\n    std::vector<T>\
    \ c(len);\n    for (int s = 0; s < len; s++) c[s] = fa[static_cast<long long>(s)\
    \ * w + __builtin_popcount(s)];\n    return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/bitwise-transform.hpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/math/bitwise-transform.test.cpp
  - test/yosupo/convolution/bitwise-and-convolution.test.cpp
  - test/yosupo/convolution/bitwise-xor-convolution.test.cpp
  - test/yosupo/set_power_series/subset-convolution.test.cpp
documentation_of: src/math/bitwise-transform.hpp
layout: document
title: "\u90E8\u5206\u96C6\u5408\u30FB\u4E0A\u4F4D\u96C6\u5408\u306E\u30BC\u30FC\u30BF\
  \u5909\u63DB\u3001\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3068\u30D3\u30C3\u30C8\u6F14\
  \u7B97 (AND\u30FBOR\u30FBXOR) \u306E\u7573\u307F\u8FBC\u307F\u3001\u90E8\u5206\u96C6\
  \u5408\u7573\u307F\u8FBC\u307F"
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

## 関連

- 部分集合や上位集合を 1 つずつ列挙するには [ビット演算](../utility/bit.hpp) の `subsets`、`supersets`
- 添字の約数・倍数についての変換は [約数・倍数のゼータ変換、メビウス変換と GCD・LCM 畳み込み](divisor-transform.hpp)
