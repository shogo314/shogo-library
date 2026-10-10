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
  bundledCode: "#line 2 \"data_structures/mex-update.hpp\"\n#include <cassert>\n#include\
    \ <limits>\n#include <map>\n#include <set>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstruct MexUpdate {\n    using value_type = T;\n\n   private:\n    inline\
    \ constexpr static value_type e = std::numeric_limits<value_type>::max();\n\n\
    \    int n;\n    std::vector<value_type> v;\n    std::set<int> s;\n    std::map<int,\
    \ size_t> m;\n\n   public:\n    MexUpdate() = default;\n    MexUpdate(int n) :\
    \ n(n), v(n, e) {\n        assert(n > 0);\n        assert(n + 1 < e);\n      \
    \  std::set<int>::iterator hint = s.end();\n        for (int i = n; i >= 0; --i)\
    \ {\n            hint = s.emplace_hint(hint, i);\n        }\n    }\n    MexUpdate(const\
    \ std::vector<value_type>& init) : n(init.size()), v(init) {\n        assert(n\
    \ > 0);\n        assert(n + 1 < e);\n        std::set<int>::iterator hint = s.end();\n\
    \        for (int i = n; i >= 0; --i) {\n            hint = s.emplace_hint(hint,\
    \ i);\n        }\n        for (const auto& i : init) {\n            if (0 <= i\
    \ and i <= n) {\n                m[i]++;\n                s.erase(i);\n      \
    \      }\n        }\n    }\n    void set(int k, const value_type& x) {\n     \
    \   assert(0 <= k and k < n);\n        if (0 <= v[k] and v[k] <= n) {\n      \
    \      int v_k = v[k];\n            auto itr = m.find(v_k);\n            if (itr->second\
    \ > 1) {\n                itr->second--;\n            } else {\n             \
    \   m.erase(itr);\n                s.insert(v_k);\n            }\n        }\n\
    \        if (0 <= x and x <= n) {\n            int xx = x;\n            auto itr\
    \ = m.find(xx);\n            if (itr == m.end()) {\n                m[xx]++;\n\
    \                s.erase(xx);\n            } else {\n                itr->second++;\n\
    \            }\n        }\n        v[k] = x;\n    }\n    value_type prod() const\
    \ {\n        return *s.begin();\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <map>\n#include\
    \ <set>\n#include <vector>\n\ntemplate <typename T>\nstruct MexUpdate {\n    using\
    \ value_type = T;\n\n   private:\n    inline constexpr static value_type e = std::numeric_limits<value_type>::max();\n\
    \n    int n;\n    std::vector<value_type> v;\n    std::set<int> s;\n    std::map<int,\
    \ size_t> m;\n\n   public:\n    MexUpdate() = default;\n    MexUpdate(int n) :\
    \ n(n), v(n, e) {\n        assert(n > 0);\n        assert(n + 1 < e);\n      \
    \  std::set<int>::iterator hint = s.end();\n        for (int i = n; i >= 0; --i)\
    \ {\n            hint = s.emplace_hint(hint, i);\n        }\n    }\n    MexUpdate(const\
    \ std::vector<value_type>& init) : n(init.size()), v(init) {\n        assert(n\
    \ > 0);\n        assert(n + 1 < e);\n        std::set<int>::iterator hint = s.end();\n\
    \        for (int i = n; i >= 0; --i) {\n            hint = s.emplace_hint(hint,\
    \ i);\n        }\n        for (const auto& i : init) {\n            if (0 <= i\
    \ and i <= n) {\n                m[i]++;\n                s.erase(i);\n      \
    \      }\n        }\n    }\n    void set(int k, const value_type& x) {\n     \
    \   assert(0 <= k and k < n);\n        if (0 <= v[k] and v[k] <= n) {\n      \
    \      int v_k = v[k];\n            auto itr = m.find(v_k);\n            if (itr->second\
    \ > 1) {\n                itr->second--;\n            } else {\n             \
    \   m.erase(itr);\n                s.insert(v_k);\n            }\n        }\n\
    \        if (0 <= x and x <= n) {\n            int xx = x;\n            auto itr\
    \ = m.find(xx);\n            if (itr == m.end()) {\n                m[xx]++;\n\
    \                s.erase(xx);\n            } else {\n                itr->second++;\n\
    \            }\n        }\n        v[k] = x;\n    }\n    value_type prod() const\
    \ {\n        return *s.begin();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structures/mex-update.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structures/mex-update.hpp
layout: document
redirect_from:
- /library/data_structures/mex-update.hpp
- /library/data_structures/mex-update.hpp.html
title: data_structures/mex-update.hpp
---
