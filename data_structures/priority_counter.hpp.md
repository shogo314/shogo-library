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
  bundledCode: "#line 2 \"data_structures/priority_counter.hpp\"\n#include <array>\n\
    #include <cstddef>\n#include <functional>\n#include <map>\n#include <type_traits>\n\
    #include <utility>\n\ntemplate <typename T, size_t K = 1, class Compare = std::less<T>,\
    \ std::enable_if_t<(K >= 1), std::nullptr_t> = nullptr>\nstruct PriorityCounter\
    \ {\n    using key_type = T;\n    using mapped_type = long long;\n    using value_type\
    \ = std::pair<key_type, mapped_type>;\n    inline constexpr static size_t k =\
    \ K;\n\n    std::array<value_type, K> data;\n\n    constexpr PriorityCounter()\
    \ {\n        for (size_t i = 0; i < k; i++) {\n            data[i].second = 0;\n\
    \        }\n    }\n    constexpr PriorityCounter(const key_type& x) : PriorityCounter()\
    \ {\n        data[0].first = x;\n        data[0].second = 1;\n    }\n\n    constexpr\
    \ size_t size() const {\n        for (size_t i = 0; i < k; i++) {\n          \
    \  if (data[i].second == 0) {\n                return i;\n            }\n    \
    \    }\n        return k;\n    }\n\n    constexpr void inc(const key_type& x,\
    \ const mapped_type& c = 1) {\n        bool f = false;\n        key_type pre_key;\n\
    \        mapped_type pre_mapped;\n        for (size_t i = 0; i < k; i++) {\n \
    \           if (f) {\n                std::swap(pre_key, data[i].first);\n   \
    \             std::swap(pre_mapped, data[i].second);\n                continue;\n\
    \            }\n            if (data[i].second == 0) {\n                data[i].first\
    \ = x;\n                data[i].second += c;\n                return;\n      \
    \      }\n            if (Compare()(data[i].first, x)) {\n                pre_key\
    \ = data[i].first;\n                pre_mapped = data[i].second;\n           \
    \     data[i].first = x;\n                data[i].second = c;\n              \
    \  f = true;\n            } else if (not Compare()(x, data[i].first)) {\n    \
    \            data[i].second += c;\n                return;\n            }\n  \
    \      }\n    }\n\n    constexpr PriorityCounter& operator+=(const PriorityCounter&\
    \ o) {\n        for (size_t i = 0; i < k; i++) {\n            if (o.data[i].second\
    \ == 0) break;\n            this->inc(o.data[i].first, o.data[i].second);\n  \
    \      }\n        return *this;\n    }\n    constexpr friend PriorityCounter operator+(const\
    \ PriorityCounter& a, const PriorityCounter& b) {\n        PriorityCounter res(a);\n\
    \        return res += b;\n    }\n};\n\ntemplate <typename T, size_t K = 1>\n\
    using MaxCounter = PriorityCounter<T, K>;\n\ntemplate <typename T, size_t K =\
    \ 1>\nusing MinCounter = PriorityCounter<T, K, std::greater<T>>;\n"
  code: "#pragma once\n#include <array>\n#include <cstddef>\n#include <functional>\n\
    #include <map>\n#include <type_traits>\n#include <utility>\n\ntemplate <typename\
    \ T, size_t K = 1, class Compare = std::less<T>, std::enable_if_t<(K >= 1), std::nullptr_t>\
    \ = nullptr>\nstruct PriorityCounter {\n    using key_type = T;\n    using mapped_type\
    \ = long long;\n    using value_type = std::pair<key_type, mapped_type>;\n   \
    \ inline constexpr static size_t k = K;\n\n    std::array<value_type, K> data;\n\
    \n    constexpr PriorityCounter() {\n        for (size_t i = 0; i < k; i++) {\n\
    \            data[i].second = 0;\n        }\n    }\n    constexpr PriorityCounter(const\
    \ key_type& x) : PriorityCounter() {\n        data[0].first = x;\n        data[0].second\
    \ = 1;\n    }\n\n    constexpr size_t size() const {\n        for (size_t i =\
    \ 0; i < k; i++) {\n            if (data[i].second == 0) {\n                return\
    \ i;\n            }\n        }\n        return k;\n    }\n\n    constexpr void\
    \ inc(const key_type& x, const mapped_type& c = 1) {\n        bool f = false;\n\
    \        key_type pre_key;\n        mapped_type pre_mapped;\n        for (size_t\
    \ i = 0; i < k; i++) {\n            if (f) {\n                std::swap(pre_key,\
    \ data[i].first);\n                std::swap(pre_mapped, data[i].second);\n  \
    \              continue;\n            }\n            if (data[i].second == 0)\
    \ {\n                data[i].first = x;\n                data[i].second += c;\n\
    \                return;\n            }\n            if (Compare()(data[i].first,\
    \ x)) {\n                pre_key = data[i].first;\n                pre_mapped\
    \ = data[i].second;\n                data[i].first = x;\n                data[i].second\
    \ = c;\n                f = true;\n            } else if (not Compare()(x, data[i].first))\
    \ {\n                data[i].second += c;\n                return;\n         \
    \   }\n        }\n    }\n\n    constexpr PriorityCounter& operator+=(const PriorityCounter&\
    \ o) {\n        for (size_t i = 0; i < k; i++) {\n            if (o.data[i].second\
    \ == 0) break;\n            this->inc(o.data[i].first, o.data[i].second);\n  \
    \      }\n        return *this;\n    }\n    constexpr friend PriorityCounter operator+(const\
    \ PriorityCounter& a, const PriorityCounter& b) {\n        PriorityCounter res(a);\n\
    \        return res += b;\n    }\n};\n\ntemplate <typename T, size_t K = 1>\n\
    using MaxCounter = PriorityCounter<T, K>;\n\ntemplate <typename T, size_t K =\
    \ 1>\nusing MinCounter = PriorityCounter<T, K, std::greater<T>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structures/priority_counter.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structures/priority_counter.hpp
layout: document
redirect_from:
- /library/data_structures/priority_counter.hpp
- /library/data_structures/priority_counter.hpp.html
title: data_structures/priority_counter.hpp
---
