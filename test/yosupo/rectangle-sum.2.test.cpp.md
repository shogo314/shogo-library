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
    path: src/data_structures/merge-sort-tree.hpp
    title: "\u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u30C4\u30EA\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/rectangle-sum.2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include <algorithm>\n\
    #include <array>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"src/data_structures/merge-sort-tree.hpp\"\n\n/**\n * @file merge-sort-tree.hpp\n\
    \ * @brief \u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u30C4\u30EA\u30FC\n */\n#line\
    \ 8 \"src/data_structures/merge-sort-tree.hpp\"\n#include <cassert>\n#include\
    \ <functional>\n#include <optional>\n#line 2 \"src/algebra/group.hpp\"\n\n/**\n\
    \ * @file group.hpp\n * @brief \u7FA4\u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\
    \u30CE\u30A4\u30C9 (algebra/monoid.hpp) \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\
    \u3066\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\
    \u8868\u3059\n * - S inv(const S& a): \u9006\u5143\n */\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#line 15 \"src/algebra/monoid.hpp\"\n#include <istream>\n\
    #include <limits>\n#include <numeric>\n#include <ostream>\n#include <type_traits>\n\
    #line 21 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\u95A2\u6570 f(x)\
    \ = a * x + b\n *\n * monoid::Composite \u306E\u8981\u7D20\u3084 acted_monoid::AffineSum\
    \ \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B: Affine<mint> f{2, 3};\
    \ f(x) \u306F 2x + 3\u3002\u7701\u7565\u3059\u308B\u3068\u6052\u7B49\u5199\u50CF\
    \ {1, 0}\n */\ntemplate <typename T>\nstruct Affine {\n    T a = T(1);  //!< \u50BE\
    \u304D\n    T b = T(0);  //!< \u5207\u7247\n    constexpr T operator()(const T&\
    \ x) const { return a * x + b; }\n    friend constexpr bool operator==(const Affine&\
    \ f, const Affine& g) { return f.a == g.a && f.b == g.b; }\n    friend constexpr\
    \ bool operator!=(const Affine& f, const Affine& g) { return !(f == g); }\n  \
    \  template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Affine& f) {\n  \
    \      return is >> f.a >> f.b;\n    }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
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
    \ Op, Inv>;\n#line 14 \"src/data_structures/merge-sort-tree.hpp\"\n\n/**\n * @brief\
    \ \u533A\u9593\u306E\u95BE\u5024\u4EE5\u5185\u306E\u5024\u306E\u7A4D\n *\n * @tparam\
    \ G \u5024\u306E\u53EF\u63DB\u7FA4 (algebra/group.hpp)\n * @tparam K key_type\
    \ \u30BD\u30FC\u30C8\u306B\u4F7F\u3046\u578B\n * @tparam Comp K\u3092\u6BD4\u8F03\
    \u3059\u308B\u30D5\u30A1\u30F3\u30AF\u30BF\n */\ntemplate <typename G = group::Sum<long\
    \ long>,\n          typename K = long long,\n          class Comp = std::less<K>>\n\
    class MergeSortTree {\n   public:\n    using value_type = typename G::S;\n   \
    \ using key_type = K;\n\n    inline constexpr static auto comp = Comp();\n\n \
    \  private:\n    G g;\n    value_type op(const value_type& x, const value_type&\
    \ y) const { return g.op(x, y); }\n    value_type e() const { return g.e(); }\n\
    \    value_type inv(const value_type& x) const { return g.inv(x); }\n\n   private:\n\
    \    int n, sz, height;\n    std::vector<key_type> key_data;\n    std::vector<value_type>\
    \ cumulative_value;\n\n    void initialize(const std::vector<value_type>& value,\
    \ const std::vector<key_type>& key) {\n        n = key.size();\n        sz = 1;\n\
    \        height = 1;\n        while (sz < n) {\n            sz <<= 1;\n      \
    \      height++;\n        }\n        key_data.assign(sz * height, {});\n     \
    \   std::vector<value_type> value_data(sz * height, e());\n        cumulative_value.assign(sz\
    \ * height, {});\n        for (int i = 0; i < n; i++) {\n            key_data[(height\
    \ - 1) * sz + i] = key[i];\n            value_data[(height - 1) * sz + i] = value[i];\n\
    \            cumulative_value[(height - 1) * sz + i] = value[i];\n        }\n\
    \        int t = 1;\n        for (int h = height - 1; h > 0; h--) {\n        \
    \    for (int i = 0; i < n; i += t * 2) {\n                int j1 = h * sz + i;\n\
    \                int j2 = h * sz + std::min(n, i + t);\n                int j0\
    \ = (h - 1) * sz + i;\n                int last1 = j2;\n                int last2\
    \ = h * sz + std::min(n, i + t * 2);\n                while (j1 != last1 || j2\
    \ != last2) {\n                    if (j1 == last1 || (j2 < last2 && comp(key_data[j2],\
    \ key_data[j1]))) {\n                        key_data[j0] = key_data[j2];\n  \
    \                      value_data[j0] = value_data[j2];\n                    \
    \    j0++;\n                        j2++;\n                    } else {\n    \
    \                    key_data[j0] = key_data[j1];\n                        value_data[j0]\
    \ = value_data[j1];\n                        j0++;\n                        j1++;\n\
    \                    }\n                }\n                cumulative_value[(h\
    \ - 1) * sz + i] = value_data[(h - 1) * sz + i];\n                for (int j =\
    \ i + 1; j < std::min(n, i + t * 2); j++) {\n                    cumulative_value[(h\
    \ - 1) * sz + j] = op(cumulative_value[(h - 1) * sz + j - 1], value_data[(h -\
    \ 1) * sz + j]);\n                }\n            }\n            t <<= 1;\n   \
    \     }\n    }\n\n    value_type prod_section(int l, int r, std::optional<key_type>\
    \ a, std::optional<key_type> b) const {\n        value_type ret = cumulative_value[r\
    \ - 1];\n        if (b.has_value()) {\n            int i = std::lower_bound(key_data.begin()\
    \ + l, key_data.begin() + r, b.value(), comp) - key_data.begin();\n          \
    \  if (i != l) {\n                ret = cumulative_value[i - 1];\n           \
    \ } else {\n                ret = e();\n            }\n        }\n        if (a.has_value())\
    \ {\n            int i = std::lower_bound(key_data.begin() + l, key_data.begin()\
    \ + r, a.value(), comp) - key_data.begin();\n            if (i != l) {\n     \
    \           ret = op(ret, inv(cumulative_value[i - 1]));\n            }\n    \
    \    }\n        return ret;\n    }\n\n   public:\n    MergeSortTree() = default;\n\
    \    /**\n     * @param value_key value\u3068key\u306Epair\u306Evector\n     */\n\
    \    explicit MergeSortTree(const std::vector<std::pair<value_type, key_type>>&\
    \ value_key, G g = G()) : g(std::move(g)) {\n        std::vector<key_type> key;\n\
    \        std::vector<value_type> value;\n        key.reserve(value_key.size());\n\
    \        value.reserve(value_key.size());\n        for (size_t i = 0; i < value_key.size();\
    \ i++) {\n            value.push_back(value_key[i].first);\n            key.push_back(value_key[i].second);\n\
    \        }\n        this->initialize(value, key);\n    }\n    /**\n     * @param\
    \ value prod\u3067\u8A08\u7B97\u3059\u308B\u5BFE\u8C61\n     * @param key \u30BD\
    \u30FC\u30C8\u3059\u308B\u57FA\u6E96\n     */\n    MergeSortTree(const std::vector<value_type>&\
    \ value, const std::vector<key_type>& key, G g = G()) : g(std::move(g)) {\n  \
    \      assert(key.size() == value.size());\n        this->initialize(value, key);\n\
    \    }\n\n    /**\n     * @brief product value[i] s.t. a <= key[i] < b , i in\
    \ [l, r)\n     *\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB nullopt\u306E\
    \u5834\u5408\u306F0\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \ 0<=l<=r<=n nullopt\u306E\u5834\u5408\u306Fn\n     * @param a nullopt\u306E\u5834\
    \u5408\u306F\u8CA0\u306E\u7121\u9650\u5927\n     * @param b nullopt\u306E\u5834\
    \u5408\u306F\u6B63\u306E\u7121\u9650\u5927\n     */\n    value_type prod(std::optional<int>\
    \ l_ = std::nullopt, std::optional<int> r_ = std::nullopt, std::optional<key_type>\
    \ a = std::nullopt, std::optional<key_type> b = std::nullopt) const {\n      \
    \  int l = l_.value_or(0), r = r_.value_or(n);\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        if (a.has_value() && b.has_value() && !comp(a.value(),\
    \ b.value())) return e();\n        value_type ret = e();\n        int h = height\
    \ - 1;\n        int t = 1;\n        while (l < r) {\n            if (l & t) {\n\
    \                ret = op(ret, prod_section(h * sz + l, h * sz + l + t, a, b));\n\
    \                l += t;\n            }\n            if (r & t) {\n          \
    \      r -= t;\n                ret = op(ret, prod_section(h * sz + r, h * sz\
    \ + r + t, a, b));\n            }\n            h--;\n            t <<= 1;\n  \
    \      }\n        return ret;\n    }\n};\n#line 10 \"test/yosupo/rectangle-sum.2.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::array<int, 3>> XYW(N);\n\
    \    for (auto& [X, Y, W] : XYW) {\n        std::cin >> X >> Y >> W;\n    }\n\
    \    std::sort(XYW.begin(), XYW.end());\n    std::vector<int> v(N);\n    // {\u5024\
    , \u30AD\u30FC} \u306E\u30EA\u30B9\u30C8\u304B\u3089\u4F5C\u308B\n    std::vector<std::pair<long\
    \ long, int>> value_key(N);\n    for (int i = 0; i < N; i++) {\n        v[i] =\
    \ XYW[i][0];\n        value_key[i] = {XYW[i][2], XYW[i][1]};\n    }\n    MergeSortTree<group::Sum<long\
    \ long>, int> mstree(value_key);\n    while (Q--) {\n        int L, D, R, U;\n\
    \        std::cin >> L >> D >> R >> U;\n        int l = std::lower_bound(v.begin(),\
    \ v.end(), L) - v.begin();\n        int r = std::lower_bound(v.begin(), v.end(),\
    \ R) - v.begin();\n        std::cout << mstree.prod(l, r, D, U) << '\\n';\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <iostream>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"../../src/data_structures/merge-sort-tree.hpp\"\n\nint\
    \ main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::array<int, 3>> XYW(N);\n\
    \    for (auto& [X, Y, W] : XYW) {\n        std::cin >> X >> Y >> W;\n    }\n\
    \    std::sort(XYW.begin(), XYW.end());\n    std::vector<int> v(N);\n    // {\u5024\
    , \u30AD\u30FC} \u306E\u30EA\u30B9\u30C8\u304B\u3089\u4F5C\u308B\n    std::vector<std::pair<long\
    \ long, int>> value_key(N);\n    for (int i = 0; i < N; i++) {\n        v[i] =\
    \ XYW[i][0];\n        value_key[i] = {XYW[i][2], XYW[i][1]};\n    }\n    MergeSortTree<group::Sum<long\
    \ long>, int> mstree(value_key);\n    while (Q--) {\n        int L, D, R, U;\n\
    \        std::cin >> L >> D >> R >> U;\n        int l = std::lower_bound(v.begin(),\
    \ v.end(), L) - v.begin();\n        int r = std::lower_bound(v.begin(), v.end(),\
    \ R) - v.begin();\n        std::cout << mstree.prod(l, r, D, U) << '\\n';\n  \
    \  }\n}\n"
  dependsOn:
  - src/data_structures/merge-sort-tree.hpp
  - src/algebra/group.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: true
  path: test/yosupo/rectangle-sum.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 01:36:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/rectangle-sum.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rectangle-sum.2.test.cpp
- /verify/test/yosupo/rectangle-sum.2.test.cpp.html
title: test/yosupo/rectangle-sum.2.test.cpp
---
