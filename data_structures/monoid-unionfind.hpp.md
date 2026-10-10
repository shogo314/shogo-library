---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: data_structures/unionfind.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder-674.1.test.cpp
    title: test/yukicoder-674.1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308B\
      UnionFind"
    links: []
  bundledCode: "#line 2 \"data_structures/monoid-unionfind.hpp\"\n\n/**\n * @file\
    \ monoid-unionfind.hpp\n * @brief \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\
    \u305B\u308BUnionFind\n */\n\n#include <utility>\n#include <vector>\n#line 2 \"\
    data_structures/unionfind.hpp\"\n\n/**\n * @file unionfind.hpp\n * @brief UnionFind\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#line 11 \"data_structures/unionfind.hpp\"\
    \n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u300C\
    \u8FBA\u306E\u8FFD\u52A0\u300D\u3001\u300C2\u9802\u70B9\u304C\u9023\u7D50\u304B\
    \u306E\u5224\u5B9A\u300D\u3092\u3059\u308B\n */\nstruct UnionFind {\n   protected:\n\
    \    int _n;\n    // \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\
    \u3089\u89AA\n    std::vector<int> parent_or_size;\n\n   public:\n    UnionFind()\
    \ : _n(0) {}\n    explicit UnionFind(int n) : _n(n), parent_or_size(n, -1) {}\n\
    \n    /**\n     * @brief \u8FBA(a,b)\u3092\u8DB3\u3059\n     * @return \u9023\u7D50\
    \u3057\u305F\u3082\u306E\u306E\u4EE3\u8868\u5143\n     */\n    int merge(int a,\
    \ int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n\
    \        int x = leader(a), y = leader(b);\n        if (x == y) return x;\n  \
    \      if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n       \
    \ parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] = x;\n  \
    \      return x;\n    }\n    /**\n     * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\
    \u304B\u3069\u3046\u304B\n     */\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\
    \u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    int leader(int\
    \ a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a] < 0)\
    \ return a;\n        int x = a;\n        while (parent_or_size[x] >= 0) {\n  \
    \          x = parent_or_size[x];\n        }\n        while (parent_or_size[a]\
    \ >= 0) {\n            int t = parent_or_size[a];\n            parent_or_size[a]\
    \ = x;\n            a = t;\n        }\n        return x;\n    }\n    /**\n   \
    \  * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\
    \u30B5\u30A4\u30BA\n     */\n    int size(int a) {\n        assert(0 <= a && a\
    \ < _n);\n        return -parent_or_size[leader(a)];\n    }\n    /**\n     * @brief\
    \ \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\u5206\u3051\u3001\u305D\
    \u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\u4E00\u3064\u306E\u9023\
    \u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\u30C8\u300D\
    \u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<int> leader_buf(_n), group_size(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    };\n#line 2 \"algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\
    \u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\
    \n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S& a, const S& b): \u7A4D\
    \ (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n * op, e \u306F static\
    \ \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\
    \u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\n#line 15 \"algebra/monoid.hpp\"\
    \n#include <limits>\n#include <numeric>\n#include <type_traits>\n#line 19 \"algebra/monoid.hpp\"\
    \n\nnamespace monoid {\n\n/**\n * @brief \u548C\n */\ntemplate <typename T>\n\
    struct Sum {\n    using S = T;\n    static constexpr S op(const S& a, const S&\
    \ b) { return a + b; }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u7A4D\n */\ntemplate <typename T>\nstruct Prod {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return a * b; }\n    static\
    \ constexpr S e() { return S(1); }\n};\n\n/**\n * @brief \u6700\u5927\u5024 \u5358\
    \u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\u5024\n */\ntemplate <typename T>\n\
    struct Max {\n    using S = T;\n    static constexpr S op(const S& a, const S&\
    \ b) { return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::lowest();\
    \ }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\
    \u6700\u5927\u5024\n */\ntemplate <typename T>\nstruct Min {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return std::min(a, b); }\n\
    \    static constexpr S e() { return std::numeric_limits<S>::max(); }\n};\n\n\
    /**\n * @brief \u6700\u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max}\n\
    \ */\ntemplate <typename T>\nstruct MinMax {\n    using S = std::pair<T, T>;\n\
    \    static constexpr S op(const S& a, const S& b) { return {std::min(a.first,\
    \ b.first), std::max(a.second, b.second)}; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::max(), std::numeric_limits<T>::lowest()}; }\n};\n\n\
    /**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate <typename T>\n\
    struct Xor {\n    using S = T;\n    static constexpr S op(const S& a, const S&\
    \ b) { return a ^ b; }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u8AD6\u7406\u7A4D\n */\ntemplate <typename T>\nstruct And {\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return a & b; }\n\
    \    static constexpr S e() { return ~S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\
    \u548C\n */\ntemplate <typename T>\nstruct Or {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return a | b; }\n    static constexpr\
    \ S e() { return S(0); }\n};\n\n/**\n * @brief \u6700\u5927\u516C\u7D04\u6570\
    \ \u5358\u4F4D\u5143\u306F0\n */\ntemplate <typename T>\nstruct Gcd {\n    static_assert(std::is_integral_v<T>);\n\
    \    using S = T;\n    static constexpr S op(const S& a, const S& b) { return\
    \ std::gcd(a, b); }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u6700\u5C0F\u516C\u500D\u6570 \u5358\u4F4D\u5143\u306F1\n */\ntemplate\
    \ <typename T>\nstruct Lcm {\n    static_assert(std::is_integral_v<T>);\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return std::lcm(a,\
    \ b); }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief 1\u6B21\
    \u95A2\u6570 f(x) = first * x + second \u306E\u5408\u6210\n * op(f, g) = g\u2218\
    f (\u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3059\u308B)\n * \u533A\u9593 [l,\
    \ r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\n */\ntemplate <typename\
    \ T>\nstruct Composite {\n    using S = std::pair<T, T>;\n    static constexpr\
    \ S op(const S& f, const S& g) { return {g.first * f.first, g.first * f.second\
    \ + g.second}; }\n    static constexpr S e() { return {T(1), T(0)}; }\n};\n\n\
    /**\n * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis {\n    struct\
    \ S {\n        long long close; // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u306E\u500B\u6570\n        long long open;  // \u5BFE\u5FDC\u306E\u53D6\
    \u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\n        constexpr S(char\
    \ c = 0) : close(c == ')'), open(c == '(') {}\n        constexpr S(long long close,\
    \ long long open) : close(close), open(open) {}\n        /**\n         * @brief\
    \ \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n         */\n        constexpr bool\
    \ is_valid() const { return close == 0 && open == 0; }\n    };\n    static constexpr\
    \ S op(const S& a, const S& b) {\n        if(a.open >= b.close) return S(a.close,\
    \ a.open - b.close + b.open);\n        return S(a.close + b.close - a.open, b.open);\n\
    \    }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\
    \u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\
    \u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate\
    \ <typename T, typename U = int>\nstruct MinWith {\n    using S = std::pair<T,\
    \ U>;\n    static constexpr S op(const S& a, const S& b) { return b.first < a.first\
    \ ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E\
    \ \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam\
    \ T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\
    \u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename T, typename U = int>\n\
    struct MaxWith {\n    using S = std::pair<T, U>;\n    static constexpr S op(const\
    \ S& a, const S& b) { return a.first < b.first ? b : a; }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U{}}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MinCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if(a.first < b.first) return\
    \ a;\n        if(b.first < a.first) return b;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MaxCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if(a.first < b.first) return b;\n        if(b.first < a.first) return\
    \ a;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::lowest(), U(0)}; }\n};\n\n} // namespace\
    \ monoid\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\
    \u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u30E2\u30CE\
    \u30A4\u30C9\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * \u4F8B\
    : SegTree seg(v, Monoid([](int a, int b) { return std::max(a, b); }, -1));\n *\n\
    \ * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename\
    \ Op>\nstruct Monoid {\n    using S = T;\n    Op op_object;\n    S identity;\n\
    \    Monoid() = default;\n    constexpr Monoid(Op op, const S& e) : op_object(std::move(op)),\
    \ identity(e) {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a,\
    \ b); }\n    constexpr S e() const { return identity; }\n};\ntemplate <typename\
    \ Op, typename T>\nMonoid(Op, T) -> Monoid<T, Op>;\n#line 12 \"data_structures/monoid-unionfind.hpp\"\
    \n\n/**\n * @brief \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308B\
    UnionFind\n *\n * @tparam M \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n\
    \ */\ntemplate <typename M>\nclass MonoidUnionFind : private UnionFind {\n   public:\n\
    \    using S = typename M::S;\n\n   private:\n    M m;\n    std::vector<S> val;\n\
    \    using UnionFind::_n;\n    using UnionFind::parent_or_size;\n\n   public:\n\
    \    /**\n     * @param n \u8981\u7D20\u6570 \u5404\u8981\u7D20\u306E\u5024\u306F\
    \u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\u3059\u308B\n     * @param m \u53EF\
    \u63DB\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit MonoidUnionFind(int n =\
    \ 0, M m = M()) : UnionFind(n), m(std::move(m)), val(n, this->m.e()) {}\n    /**\n\
    \     * @param v \u5404\u8981\u7D20\u306E\u521D\u671F\u5024\n     * @param m \u53EF\
    \u63DB\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit MonoidUnionFind(std::vector<S>\
    \ v, M m = M()) : UnionFind(v.size()), m(std::move(m)), val(std::move(v)) {}\n\
    \    using UnionFind::groups;\n    using UnionFind::leader;\n    using UnionFind::same;\n\
    \    using UnionFind::size;\n    int merge(int a, int b) {\n        assert(0 <=\
    \ a && a < _n);\n        assert(0 <= b && b < _n);\n        int x = leader(a),\
    \ y = leader(b);\n        if (x == y) return x;\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        val[x] = m.op(val[x], val[y]);\n    \
    \    return x;\n    }\n    /**\n     * @brief \u8981\u7D20a\u306E\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u5024\u306E\u7DCF\u7A4D\n     */\n    const S&\
    \ prod(int a) {\n        return val[leader(a)];\n    }\n};\n\ntemplate <typename\
    \ M>\nMonoidUnionFind(int, M) -> MonoidUnionFind<M>;\ntemplate <typename M>\n\
    MonoidUnionFind(std::vector<typename M::S>, M) -> MonoidUnionFind<M>;\n"
  code: "#pragma once\n\n/**\n * @file monoid-unionfind.hpp\n * @brief \u53EF\u63DB\
    \u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308BUnionFind\n */\n\n#include <utility>\n\
    #include <vector>\n#include \"unionfind.hpp\"\n#include \"../algebra/monoid.hpp\"\
    \n\n/**\n * @brief \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308B\
    UnionFind\n *\n * @tparam M \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n\
    \ */\ntemplate <typename M>\nclass MonoidUnionFind : private UnionFind {\n   public:\n\
    \    using S = typename M::S;\n\n   private:\n    M m;\n    std::vector<S> val;\n\
    \    using UnionFind::_n;\n    using UnionFind::parent_or_size;\n\n   public:\n\
    \    /**\n     * @param n \u8981\u7D20\u6570 \u5404\u8981\u7D20\u306E\u5024\u306F\
    \u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\u3059\u308B\n     * @param m \u53EF\
    \u63DB\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit MonoidUnionFind(int n =\
    \ 0, M m = M()) : UnionFind(n), m(std::move(m)), val(n, this->m.e()) {}\n    /**\n\
    \     * @param v \u5404\u8981\u7D20\u306E\u521D\u671F\u5024\n     * @param m \u53EF\
    \u63DB\u30E2\u30CE\u30A4\u30C9\n     */\n    explicit MonoidUnionFind(std::vector<S>\
    \ v, M m = M()) : UnionFind(v.size()), m(std::move(m)), val(std::move(v)) {}\n\
    \    using UnionFind::groups;\n    using UnionFind::leader;\n    using UnionFind::same;\n\
    \    using UnionFind::size;\n    int merge(int a, int b) {\n        assert(0 <=\
    \ a && a < _n);\n        assert(0 <= b && b < _n);\n        int x = leader(a),\
    \ y = leader(b);\n        if (x == y) return x;\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        val[x] = m.op(val[x], val[y]);\n    \
    \    return x;\n    }\n    /**\n     * @brief \u8981\u7D20a\u306E\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u5024\u306E\u7DCF\u7A4D\n     */\n    const S&\
    \ prod(int a) {\n        return val[leader(a)];\n    }\n};\n\ntemplate <typename\
    \ M>\nMonoidUnionFind(int, M) -> MonoidUnionFind<M>;\ntemplate <typename M>\n\
    MonoidUnionFind(std::vector<typename M::S>, M) -> MonoidUnionFind<M>;\n"
  dependsOn:
  - data_structures/unionfind.hpp
  - algebra/monoid.hpp
  isVerificationFile: false
  path: data_structures/monoid-unionfind.hpp
  requiredBy: []
  timestamp: '2026-10-10 20:42:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder-674.1.test.cpp
documentation_of: data_structures/monoid-unionfind.hpp
layout: document
redirect_from:
- /library/data_structures/monoid-unionfind.hpp
- /library/data_structures/monoid-unionfind.hpp.html
title: "\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308BUnionFind"
---
