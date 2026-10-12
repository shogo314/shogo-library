---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/group.hpp
    title: "\u7FA4\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/potentialized-unionfind.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/potentialized-unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// PotentializedUnionFind \u306E size / groups \u3092\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n\
    #include <iostream>\n#include <random>\n#include <vector>\n\n#line 2 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n\n/**\n * @file potentialized-unionfind.hpp\n * @brief \u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\u4ED8\u304DUnionFind\n */\n#line 8 \"src/data_structures/potentialized-unionfind.hpp\"\
    \n#include <cassert>\n#include <functional>\n#include <stack>\n#include <utility>\n\
    #line 2 \"src/data_structures/unionfind.hpp\"\n\n/**\n * @file unionfind.hpp\n\
    \ * @brief UnionFind\n */\n\n#line 11 \"src/data_structures/unionfind.hpp\"\n\n\
    /**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u300C\u8FBA\
    \u306E\u8FFD\u52A0\u300D\u3001\u300C2\u9802\u70B9\u304C\u9023\u7D50\u304B\u306E\
    \u5224\u5B9A\u300D\u3092\u3059\u308B\n */\nstruct UnionFind {\n   protected:\n\
    \    int _n;\n    // \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\
    \u3089\u89AA\n    std::vector<int> parent_or_size;\n\n   public:\n    /**\n  \
    \   * @brief merge \u306E\u623B\u308A\u5024\n     *\n     * if (uf.merge(a, b))\
    \ \u3067\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B\u3092\u5224\u5B9A\u3067\
    \u304D\u3001\n     * auto [r, merged] = uf.merge(a, b); \u3067\u4EE3\u8868\u5143\
    \u3082\u53D7\u3051\u53D6\u308C\u308B\n     */\n    struct MergeResult {\n    \
    \    int leader;   //!< \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\n        bool\
    \ merged;  //!< \u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B (\u3082\u3068\
    \u3082\u3068\u540C\u3058\u9023\u7D50\u6210\u5206\u306A\u3089 false)\n        explicit\
    \ operator bool() const { return merged; }\n    };\n\n    UnionFind() : _n(0)\
    \ {}\n    explicit UnionFind(int n) : _n(n), parent_or_size(n, -1) {}\n\n    /**\n\
    \     * @brief \u8FBA(a,b)\u3092\u8DB3\u3059\n     * @return \u7D71\u5408\u5F8C\
    \u306E\u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\
    \u304B\n     */\n    MergeResult merge(int a, int b) {\n        assert(0 <= a\
    \ && a < _n);\n        assert(0 <= b && b < _n);\n        int x = leader(a), y\
    \ = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        return {x, true};\n    }\n    /**\n \
    \    * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\u304B\n    \
    \ */\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n     \
    \   assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n    }\n\
    \    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u4EE3\u8868\u5143\n     */\n    int leader(int a) {\n        assert(0\
    \ <= a && a < _n);\n        if (parent_or_size[a] < 0) return a;\n        int\
    \ x = a;\n        while (parent_or_size[x] >= 0) {\n            x = parent_or_size[x];\n\
    \        }\n        while (parent_or_size[a] >= 0) {\n            int t = parent_or_size[a];\n\
    \            parent_or_size[a] = x;\n            a = t;\n        }\n        return\
    \ x;\n    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\
    \u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\n     */\n    int size(int a) {\n \
    \       assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\
    \u306B\u5206\u3051\u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return\
    \ \u300C\u4E00\u3064\u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\
    \u306E\u30EA\u30B9\u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    };\n#line 2 \"src/algebra/group.hpp\"\n\n/**\n * @file group.hpp\n * @brief \u7FA4\
    \u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\
    \ \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\
    \u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - S inv(const S& a):\
    \ \u9006\u5143\n */\n\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n\
    \ * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\
    \u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\
    \u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S&\
    \ a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n\
    \ * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\
    \u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\
    \n#line 15 \"src/algebra/monoid.hpp\"\n#include <istream>\n#include <limits>\n\
    #include <numeric>\n#include <ostream>\n#include <type_traits>\n#line 21 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @brief 1\u6B21\u95A2\u6570 f(x) = a * x + b\n *\n * monoid::Composite\
    \ \u306E\u8981\u7D20\u3084 acted_monoid::AffineSum \u306E\u4F5C\u7528\u7D20\u306B\
    \u4F7F\u3046\n * \u4F8B: Affine<mint> f{2, 3}; f(x) \u306F 2x + 3\u3002\u7701\u7565\
    \u3059\u308B\u3068\u6052\u7B49\u5199\u50CF {1, 0}\n */\ntemplate <typename T>\n\
    struct Affine {\n    T a = T(1);  //!< \u50BE\u304D\n    T b = T(0);  //!< \u5207\
    \u7247\n    constexpr T operator()(const T& x) const { return a * x + b; }\n \
    \   friend constexpr bool operator==(const Affine& f, const Affine& g) { return\
    \ f.a == g.a && f.b == g.b; }\n    friend constexpr bool operator!=(const Affine&\
    \ f, const Affine& g) { return !(f == g); }\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, Affine& f) {\n        return is >> f.a >> f.b;\n    }\n    template\
    \ <class CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Affine& f) {\n        return os << f.a << CharT(' ') << f.b;\n\
    \    }\n};\n\nnamespace monoid {\n\n/**\n * @brief \u548C\n */\ntemplate <typename\
    \ T>\nstruct Sum {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a + b; }\n    static constexpr S e() { return S(0); }\n};\n\n\
    /**\n * @brief \u7A4D\n */\ntemplate <typename T>\nstruct Prod {\n    using S\
    \ = T;\n    static constexpr S op(const S& a, const S& b) { return a * b; }\n\
    \    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief \u6700\u5927\
    \u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\u5024\n */\ntemplate <typename\
    \ T>\nstruct Max {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return std::max(a, b); }\n    static constexpr S e() { return std::numeric_limits<S>::lowest();\
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
    \u95A2\u6570 (Affine) \u306E\u5408\u6210\n * op(f, g) = g\u2218f (\u5DE6\u304B\
    \u3089\u9806\u306B\u9069\u7528\u3059\u308B)\n * \u533A\u9593 [l, r) \u306E\u7A4D\
    \u306F f_{r-1}(...f_l(x)) \u3092\u8868\u3059\n */\ntemplate <typename T>\nstruct\
    \ Composite {\n    using S = Affine<T>;\n    static constexpr S op(const S& f,\
    \ const S& g) { return {g.a * f.a, g.a * f.b + g.b}; }\n    static constexpr S\
    \ e() { return {T(1), T(0)}; }\n};\n\n/**\n * @brief \u62EC\u5F27\u5217 \u5BFE\
    \u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\u3044 ')' \u3068 '(' \u306E\u500B\u6570\
    \n */\nstruct Parenthesis {\n    struct S {\n        long long close; // \u5BFE\
    \u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\u3044 ')' \u306E\u500B\u6570\n    \
    \    long long open;  // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\u3044\
    \ '(' \u306E\u500B\u6570\n        constexpr S(char c = 0) : close(c == ')'), open(c\
    \ == '(') {}\n        constexpr S(long long close, long long open) : close(close),\
    \ open(open) {}\n        /**\n         * @brief \u6B63\u3057\u3044\u62EC\u5F27\
    \u5217\u304B\n         */\n        constexpr bool is_valid() const { return close\
    \ == 0 && open == 0; }\n    };\n    static constexpr S op(const S& a, const S&\
    \ b) {\n        if(a.open >= b.close) return S(a.close, a.open - b.close + b.open);\n\
    \        return S(a.close + b.close - a.open, b.open);\n    }\n    static constexpr\
    \ S e() { return S(); }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\
    \u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n\
    \ * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\
    \u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename T, typename U =\
    \ int>\nstruct MinWith {\n    using S = std::pair<T, U>;\n    static constexpr\
    \ S op(const S& a, const S& b) { return b.first < a.first ? b : a; }\n    static\
    \ constexpr S e() { return {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n\
    \ * @brief \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\
    \u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\
    \n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\
    \u578B\n */\ntemplate <typename T, typename U = int>\nstruct MaxWith {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) { return\
    \ a.first < b.first ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MinCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if(a.first < b.first) return a;\n        if(b.first < a.first) return\
    \ b;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::max(), U(0)}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MaxCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if(a.first < b.first) return\
    \ b;\n        if(b.first < a.first) return a;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U(0)}; }\n};\n\n} // namespace monoid\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3068\u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\
    \u306B\u4F5C\u308B\u30E2\u30CE\u30A4\u30C9\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\
    \u3048\u308B\n *\n * \u4F8B: SegTree seg(v, Monoid([](int a, int b) { return std::max(a,\
    \ b); }, -1));\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\
    \u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate\
    \ <typename T, typename Op>\nstruct Monoid {\n    using S = T;\n    Op op_object;\n\
    \    S identity;\n    Monoid() = default;\n    constexpr Monoid(Op op, const S&\
    \ e) : op_object(std::move(op)), identity(e) {}\n    constexpr S op(const S& a,\
    \ const S& b) const { return op_object(a, b); }\n    constexpr S e() const { return\
    \ identity; }\n};\ntemplate <typename Op, typename T>\nMonoid(Op, T) -> Monoid<T,\
    \ Op>;\n#line 12 \"src/algebra/group.hpp\"\n\nnamespace group {\n\n/**\n * @brief\
    \ \u52A0\u6CD5\u7FA4\n */\ntemplate <typename T>\nstruct Sum : monoid::Sum<T>\
    \ {\n    using S = T;\n    static constexpr S inv(const S& a) { return -a; }\n\
    };\n\n/**\n * @brief \u4E57\u6CD5\u7FA4 (0\u3092\u542B\u307E\u306A\u3044\u4F53\
    \u306E\u5143\u306A\u3069)\n */\ntemplate <typename T>\nstruct Prod : monoid::Prod<T>\
    \ {\n    using S = T;\n    static constexpr S inv(const S& a) { return S(1) /\
    \ a; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n */\ntemplate\
    \ <typename T>\nstruct Xor : monoid::Xor<T> {\n    using S = T;\n    static constexpr\
    \ S inv(const S& a) { return a; }\n};\n\n} // namespace group\n\n/**\n * @brief\
    \ \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\u5358\u4F4D\u5143\u304B\
    \u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u7FA4\n * \u30E9\u30E0\u30C0\u5F0F\u3092\
    \u4F7F\u3048\u308B\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\
    \u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n * @tparam\
    \ Inv \u9006\u5143\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\
    \u578B\n */\ntemplate <typename T, typename Op, typename Inv>\nstruct Group {\n\
    \    using S = T;\n    Op op_object;\n    S identity;\n    Inv inv_object;\n \
    \   Group() = default;\n    constexpr Group(Op op, const S& e, Inv inv) : op_object(std::move(op)),\
    \ identity(e), inv_object(std::move(inv)) {}\n    constexpr S op(const S& a, const\
    \ S& b) const { return op_object(a, b); }\n    constexpr S e() const { return\
    \ identity; }\n    constexpr S inv(const S& a) const { return inv_object(a); }\n\
    };\ntemplate <typename Op, typename T, typename Inv>\nGroup(Op, T, Inv) -> Group<T,\
    \ Op, Inv>;\n#line 15 \"src/data_structures/potentialized-unionfind.hpp\"\n\n\
    /**\n * @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind\n * @tparam\
    \ G \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u7FA4 (algebra/group.hpp) \u975E\
    \u53EF\u63DB\u3067\u3082\u3088\u3044\n */\ntemplate <typename G>\nclass PotentializedUnionFind\
    \ {\n   public:\n    using S = typename G::S;\n    using MergeResult = UnionFind::MergeResult;\n\
    \n   private:\n    G g;\n    int _n;\n    // \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\
    \u3001\u975E\u8CA0\u306A\u3089\u89AA\n    std::vector<int> parent_or_size;\n \
    \   // \u91CD\u307F\n    std::vector<S> diff_weight;\n\n    S op(const S& a, const\
    \ S& b) const { return g.op(a, b); }\n    S e() const { return g.e(); }\n    S\
    \ inv(const S& a) const { return g.inv(a); }\n\n   public:\n    /**\n     * @param\
    \ n \u8981\u7D20\u6570\n     * @param g \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\
    \u7FA4\n     */\n    explicit PotentializedUnionFind(int n = 0, G g = G()) : g(std::move(g)),\
    \ _n(n), parent_or_size(n, -1), diff_weight(n, e()) {}\n\n    /**\n     * @brief\
    \ \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\
    \u5143\n     */\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n\
    \        if (parent_or_size[a] < 0) return a;\n        std::stack<int> stk;\n\
    \        stk.push(a);\n        while (parent_or_size[stk.top()] >= 0) {\n    \
    \        stk.push(parent_or_size[stk.top()]);\n        }\n        const int root\
    \ = stk.top();\n        stk.pop();\n        stk.pop();\n        while (!stk.empty())\
    \ {\n            diff_weight[stk.top()] = op(diff_weight[parent_or_size[stk.top()]],\
    \ diff_weight[stk.top()]);\n            parent_or_size[stk.top()] = root;\n  \
    \          stk.pop();\n        }\n        return root;\n    }\n\n    /**\n   \
    \  * @brief a \u306E\u30B0\u30EB\u30FC\u30D7\u3068 b \u306E\u30B0\u30EB\u30FC\u30D7\
    \u3092\u7D71\u5408\u3059\u308B\n     * @param w (b \u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB) - (a \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)\n     * @return\
    \ \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\
    \u5408\u3057\u305F\u304B\n     * @note \u3059\u3067\u306B\u540C\u3058\u9023\u7D50\
    \u6210\u5206\u306A\u3089\u4F55\u3082\u3057\u306A\u3044 (w \u304C\u77DB\u76FE\u3057\
    \u3066\u3044\u3066\u3082\u691C\u51FA\u3057\u306A\u3044)\u3002\n     *       \u77DB\
    \u76FE\u3092\u8ABF\u3079\u308B\u306B\u306F\u3001merged \u304C false \u306E\u3068\
    \u304D\u306B diff(a, b) == w \u304B\u3092\u78BA\u304B\u3081\u308B\n     */\n \
    \   MergeResult merge(int a, int b, S w) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        w = op(weight(a), w);\n        w =\
    \ op(w, inv(weight(b)));\n        int x = leader(a), y = leader(b);\n        if\
    \ (x == y) return {x, false};\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ {\n            std::swap(x, y);\n            w = inv(w);\n        }\n      \
    \  parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] = x;\n \
    \       diff_weight[y] = w;\n        return {x, true};\n    }\n\n    /**\n   \
    \  * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\u304B\n     */\n\
    \    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        return leader(a) == leader(b);\n    }\n\n    /**\n\
    \     * @brief (b \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB) - (a \u306E\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB)\n     */\n    S diff(int a, int b) {\n       \
    \ assert(same(a, b));\n        return op(inv(weight(a)), weight(b));\n    }\n\n\
    \    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30BA\n     */\n    int size(int a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\u5206\u3051\
    \u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\u4E00\u3064\
    \u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\
    \u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(result.begin(), result.end(),\
    \ [&](const std::vector<int>& v) { return v.empty(); }), result.end());\n    \
    \    return result;\n    }\n\n   private:\n    S weight(int a) {\n        leader(a);\n\
    \        return diff_weight[a];\n    }\n};\n\ntemplate <typename G>\nPotentializedUnionFind(int,\
    \ G) -> PotentializedUnionFind<G>;\n#line 12 \"test/unittest/potentialized-unionfind.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 10 + 1;\n     \
    \   PotentializedUnionFind<group::Sum<long long>> uf(n);\n        // \u77DB\u76FE\
    \u3057\u306A\u3044\u5165\u529B\u306B\u3059\u308B\u305F\u3081\u3001\u5404\u9802\
    \u70B9\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u5148\u306B\u6C7A\u3081\
    \u3066\u304A\u304F\n        std::vector<long long> p(n);\n        for (auto& x\
    \ : p) x = static_cast<long long>(rng() % 21) - 10;\n        std::vector<int>\
    \ comp(n);\n        for (int i = 0; i < n; i++) comp[i] = i;\n        for (int\
    \ t = 0; t < 15; t++) {\n            int a = rng() % n, b = rng() % n;\n     \
    \       auto res = uf.merge(a, b, p[b] - p[a]);\n            if (res.merged !=\
    \ (comp[a] != comp[b])) ok = false;\n            int ca = comp[a], cb = comp[b];\n\
    \            for (int& c : comp) {\n                if (c == cb) c = ca;\n   \
    \         }\n            for (int x = 0; x < n; x++) {\n                if (uf.size(x)\
    \ != (int)std::count(comp.begin(), comp.end(), comp[x])) ok = false;\n       \
    \         for (int y = 0; y < n; y++) {\n                    if (comp[x] == comp[y]\
    \ && uf.diff(x, y) != p[y] - p[x]) ok = false;\n                }\n          \
    \  }\n            std::vector<std::vector<int>> expect;\n            std::vector<int>\
    \ seen(n, -1);\n            for (int x = 0; x < n; x++) {\n                if\
    \ (seen[comp[x]] == -1) {\n                    seen[comp[x]] = expect.size();\n\
    \                    expect.push_back({});\n                }\n              \
    \  expect[seen[comp[x]]].push_back(x);\n            }\n            auto g = uf.groups();\n\
    \            std::sort(g.begin(), g.end());\n            std::sort(expect.begin(),\
    \ expect.end());\n            if (g != expect) ok = false;\n        }\n    }\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n    else std::cerr <<\
    \ \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// PotentializedUnionFind \u306E size / groups \u3092\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n\
    #include <iostream>\n#include <random>\n#include <vector>\n\n#include \"../../src/data_structures/potentialized-unionfind.hpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 10 + 1;\n     \
    \   PotentializedUnionFind<group::Sum<long long>> uf(n);\n        // \u77DB\u76FE\
    \u3057\u306A\u3044\u5165\u529B\u306B\u3059\u308B\u305F\u3081\u3001\u5404\u9802\
    \u70B9\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u5148\u306B\u6C7A\u3081\
    \u3066\u304A\u304F\n        std::vector<long long> p(n);\n        for (auto& x\
    \ : p) x = static_cast<long long>(rng() % 21) - 10;\n        std::vector<int>\
    \ comp(n);\n        for (int i = 0; i < n; i++) comp[i] = i;\n        for (int\
    \ t = 0; t < 15; t++) {\n            int a = rng() % n, b = rng() % n;\n     \
    \       auto res = uf.merge(a, b, p[b] - p[a]);\n            if (res.merged !=\
    \ (comp[a] != comp[b])) ok = false;\n            int ca = comp[a], cb = comp[b];\n\
    \            for (int& c : comp) {\n                if (c == cb) c = ca;\n   \
    \         }\n            for (int x = 0; x < n; x++) {\n                if (uf.size(x)\
    \ != (int)std::count(comp.begin(), comp.end(), comp[x])) ok = false;\n       \
    \         for (int y = 0; y < n; y++) {\n                    if (comp[x] == comp[y]\
    \ && uf.diff(x, y) != p[y] - p[x]) ok = false;\n                }\n          \
    \  }\n            std::vector<std::vector<int>> expect;\n            std::vector<int>\
    \ seen(n, -1);\n            for (int x = 0; x < n; x++) {\n                if\
    \ (seen[comp[x]] == -1) {\n                    seen[comp[x]] = expect.size();\n\
    \                    expect.push_back({});\n                }\n              \
    \  expect[seen[comp[x]]].push_back(x);\n            }\n            auto g = uf.groups();\n\
    \            std::sort(g.begin(), g.end());\n            std::sort(expect.begin(),\
    \ expect.end());\n            if (g != expect) ok = false;\n        }\n    }\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n    else std::cerr <<\
    \ \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/potentialized-unionfind.hpp
  - src/data_structures/unionfind.hpp
  - src/algebra/group.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: true
  path: test/unittest/potentialized-unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 06:02:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/potentialized-unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/potentialized-unionfind.test.cpp
- /verify/test/unittest/potentialized-unionfind.test.cpp.html
title: test/unittest/potentialized-unionfind.test.cpp
---
