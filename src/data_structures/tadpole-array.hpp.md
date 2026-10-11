---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\u5217"
    links: []
  bundledCode: "#line 2 \"src/data_structures/tadpole-array.hpp\"\n#include <cassert>\n\
    #include <vector>\n/**\n * @brief \u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\
    \u5217\n * \u7279\u5B9A\u306E\u4F4D\u7F6E\u3067\u30EB\u30FC\u30D7\u3059\u308B\u69CB\
    \u9020\n * @tparam T\n */\ntemplate <typename T>\nstruct TadpoleArray {\n   private:\n\
    \    std::vector<T> data;\n    size_t k;\n\n   public:\n    /**\n     * @brief\
    \ \u6700\u5F8C\u306E\u6B21\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304Ci\n\
    \     */\n    TadpoleArray(const std::vector<T>& v, int i) : data(v) {\n     \
    \   assert(0 <= i and i < static_cast<int>(data.size()));\n        k = static_cast<size_t>(i);\n\
    \    }\n    TadpoleArray() = default;\n    TadpoleArray(const TadpoleArray&) =\
    \ default;\n    T at(size_t i) const {\n        if (i < k) return data[i];\n \
    \       return data[(i - k) % (data.size() - k) + k];\n    }\n    T operator[](size_t\
    \ i) const {\n        return at(i);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n/**\n * @brief \u304A\
    \u305F\u307E\u3058\u3083\u304F\u3057\u914D\u5217\n * \u7279\u5B9A\u306E\u4F4D\u7F6E\
    \u3067\u30EB\u30FC\u30D7\u3059\u308B\u69CB\u9020\n * @tparam T\n */\ntemplate\
    \ <typename T>\nstruct TadpoleArray {\n   private:\n    std::vector<T> data;\n\
    \    size_t k;\n\n   public:\n    /**\n     * @brief \u6700\u5F8C\u306E\u6B21\u306E\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304Ci\n     */\n    TadpoleArray(const std::vector<T>&\
    \ v, int i) : data(v) {\n        assert(0 <= i and i < static_cast<int>(data.size()));\n\
    \        k = static_cast<size_t>(i);\n    }\n    TadpoleArray() = default;\n \
    \   TadpoleArray(const TadpoleArray&) = default;\n    T at(size_t i) const {\n\
    \        if (i < k) return data[i];\n        return data[(i - k) % (data.size()\
    \ - k) + k];\n    }\n    T operator[](size_t i) const {\n        return at(i);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/tadpole-array.hpp
  requiredBy: []
  timestamp: '2026-10-11 23:34:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structures/tadpole-array.hpp
layout: document
redirect_from:
- /library/src/data_structures/tadpole-array.hpp
- /library/src/data_structures/tadpole-array.hpp.html
title: "\u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\u5217"
---
