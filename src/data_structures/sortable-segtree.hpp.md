---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/fast-set.hpp
    title: "64 \u5206\u6728 (FastSet)"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/sortable-segtree.test.cpp
    title: test/unittest/data_structures/sortable-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/point-set-range-sort-range-composite.test.cpp
    title: test/yosupo/data_structure/point-set-range-sort-range-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u533A\u9593\u30BD\u30FC\u30C8\u306E\u3067\u304D\u308B\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"src/data_structures/sortable-segtree.hpp\"\n\n/**\n * @file\
    \ sortable-segtree.hpp\n * @brief \u533A\u9593\u30BD\u30FC\u30C8\u306E\u3067\u304D\
    \u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"src/data_structures/fast-set.hpp\"\
    \n\n/**\n * @file fast-set.hpp\n * @brief 64 \u5206\u6728\u306B\u3088\u308B\u6574\
    \u6570\u306E\u96C6\u5408 (FastSet)\n */\n\n#line 9 \"src/data_structures/fast-set.hpp\"\
    \n#include <cstdint>\n#line 11 \"src/data_structures/fast-set.hpp\"\n\n/**\n *\
    \ @brief [0, n) \u306E\u6574\u6570\u306E\u96C6\u5408\u3092 64 \u5206\u6728\u3067\
    \u6301\u3064\n *\n * \u5404\u6BB5\u306F 64 bit \u306E\u914D\u5217\u3067\u3001\u4E0A\
    \u306E\u6BB5\u306E bit \u306F\u4E0B\u306E\u6BB5\u306E 64 bit \u304C 0 \u3067\u306A\
    \u3044\u304B\u3092\u8868\u3059\n * \u633F\u5165\u30FB\u524A\u9664\u30FBx \u4EE5\
    \u4E0A\u306E\u6700\u5C0F\u30FBx \u4EE5\u4E0B\u306E\u6700\u5927\u3092 O(log_64\
    \ n) \u3067\u884C\u3046 (n = 10^9 \u3067\u3082 5 \u6BB5\u7A0B\u5EA6)\n * \u4F8B\
    :\n * FastSet s(n);\n * s.insert(3); s.insert(10);\n * s.next(4);  // 10\n * s.prev(4);\
    \  // 3\n */\nclass FastSet {\n    long long n, cnt = 0;\n    std::vector<std::vector<std::uint64_t>>\
    \ seg;  // seg[0] \u304C\u8981\u7D20\u306E bit\u3001seg[h + 1] \u306F seg[h] \u306E\
    \u5404 64 bit \u304C 0 \u3067\u306A\u3044\u304B\n\n    void build_levels() {\n\
    \        // 1 \u3064\u306E 64 bit \u306B\u53CE\u307E\u308B\u307E\u3067\u6BB5\u3092\
    \u91CD\u306D\u308B\n        do {\n            long long m = seg.empty() ? n :\
    \ static_cast<long long>(seg.back().size());\n            seg.emplace_back((m\
    \ + 63) / 64, 0);\n        } while (seg.back().size() > 1);\n    }\n\n   public:\n\
    \    /**\n     * @brief [0, n) \u306E\u7A7A\u306E\u96C6\u5408\n     */\n    explicit\
    \ FastSet(long long n = 0) : n(n) {\n        assert(n >= 0);\n        build_levels();\n\
    \    }\n    /**\n     * @brief v[i] \u304C true \u306E i \u304B\u3089\u306A\u308B\
    \u96C6\u5408 O(n)\n     */\n    explicit FastSet(const std::vector<bool>& v) :\
    \ FastSet(static_cast<long long>(v.size())) {\n        for (long long i = 0; i\
    \ < n; i++) {\n            if (v[i]) seg[0][i >> 6] |= std::uint64_t(1) << (i\
    \ & 63), cnt++;\n        }\n        for (int h = 0; h + 1 < static_cast<int>(seg.size());\
    \ h++) {\n            for (long long i = 0; i < static_cast<long long>(seg[h].size());\
    \ i++) {\n                if (seg[h][i]) seg[h + 1][i >> 6] |= std::uint64_t(1)\
    \ << (i & 63);\n            }\n        }\n    }\n\n    /**\n     * @brief \u6271\
    \u3048\u308B\u6574\u6570\u306E\u7BC4\u56F2 [0, n) \u306E n\n     */\n    long\
    \ long limit() const { return n; }\n    /**\n     * @brief \u8981\u7D20\u6570\n\
    \     */\n    long long size() const { return cnt; }\n    /**\n     * @brief \u7A7A\
    \u304B\n     */\n    bool empty() const { return cnt == 0; }\n\n    /**\n    \
    \ * @brief x \u304C\u542B\u307E\u308C\u308B\u304B O(1)\n     */\n    bool contains(long\
    \ long x) const {\n        assert(0 <= x && x < n);\n        return seg[0][x >>\
    \ 6] >> (x & 63) & 1;\n    }\n    /**\n     * @brief x \u306E\u500B\u6570 (0 \u304B\
    \ 1) O(1)\n     */\n    long long count(long long x) const { return contains(x);\
    \ }\n    /**\n     * @brief x \u3092\u633F\u5165\u3059\u308B\u3002\u65B0\u3057\
    \u304F\u5165\u3063\u305F\u3089 true O(log_64 n)\n     */\n    bool insert(long\
    \ long x) {\n        assert(0 <= x && x < n);\n        if (contains(x)) return\
    \ false;\n        cnt++;\n        for (auto& level : seg) {\n            level[x\
    \ >> 6] |= std::uint64_t(1) << (x & 63);\n            x >>= 6;\n        }\n  \
    \      return true;\n    }\n    /**\n     * @brief x \u3092\u524A\u9664\u3059\u308B\
    \u3002\u5165\u3063\u3066\u3044\u305F\u3089 true O(log_64 n)\n     */\n    bool\
    \ erase(long long x) {\n        assert(0 <= x && x < n);\n        if (!contains(x))\
    \ return false;\n        cnt--;\n        for (auto& level : seg) {\n         \
    \   level[x >> 6] &= ~(std::uint64_t(1) << (x & 63));\n            // \u540C\u3058\
    \ 64 bit \u306B\u4ED6\u306E\u8981\u7D20\u304C\u6B8B\u3063\u3066\u3044\u308C\u3070\
    \u3001\u4E0A\u306E\u6BB5\u306F\u5909\u308F\u3089\u306A\u3044\n            if (level[x\
    \ >> 6]) break;\n            x >>= 6;\n        }\n        return true;\n    }\n\
    \n    /**\n     * @brief x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20 (\u306A\
    \u3051\u308C\u3070 -1) O(log_64 n)\n     */\n    long long next(long long x) const\
    \ {\n        if (x < 0) x = 0;\n        if (x >= n) return -1;\n        for (int\
    \ h = 0; h < static_cast<int>(seg.size()); h++) {\n            if ((x >> 6) ==\
    \ static_cast<long long>(seg[h].size())) break;\n            std::uint64_t d =\
    \ seg[h][x >> 6] >> (x & 63);\n            if (!d) {\n                x = (x >>\
    \ 6) + 1;\n                continue;\n            }\n            // \u3053\u306E\
    \u6BB5\u3067\u898B\u3064\u304B\u3063\u305F\u306E\u3067\u3001\u4E0B\u306E\u6BB5\
    \u3067\u306F\u6700\u3082\u5C0F\u3055\u3044 bit \u3092\u305F\u3069\u308B\n    \
    \        x += __builtin_ctzll(d);\n            for (int g = h - 1; g >= 0; g--)\
    \ {\n                x <<= 6;\n                x += __builtin_ctzll(seg[g][x >>\
    \ 6]);\n            }\n            return x;\n        }\n        return -1;\n\
    \    }\n    /**\n     * @brief x \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20\
    \ (\u306A\u3051\u308C\u3070 -1) O(log_64 n)\n     */\n    long long prev(long\
    \ long x) const {\n        if (x >= n) x = n - 1;\n        if (x < 0) return -1;\n\
    \        for (int h = 0; h < static_cast<int>(seg.size()); h++) {\n          \
    \  if (x == -1) break;\n            std::uint64_t d = seg[h][x >> 6] << (63 -\
    \ (x & 63));\n            if (!d) {\n                x = (x >> 6) - 1;\n     \
    \           continue;\n            }\n            // \u3053\u306E\u6BB5\u3067\u898B\
    \u3064\u304B\u3063\u305F\u306E\u3067\u3001\u4E0B\u306E\u6BB5\u3067\u306F\u6700\
    \u3082\u5927\u304D\u3044 bit \u3092\u305F\u3069\u308B\n            x -= __builtin_clzll(d);\n\
    \            for (int g = h - 1; g >= 0; g--) {\n                x <<= 6;\n  \
    \              x += 63 - __builtin_clzll(seg[g][x >> 6]);\n            }\n   \
    \         return x;\n        }\n        return -1;\n    }\n    /**\n     * @brief\
    \ \u6700\u5C0F\u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n\
    \    long long min() const { return next(0); }\n    /**\n     * @brief \u6700\u5927\
    \u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n    long long\
    \ max() const { return prev(n - 1); }\n\n    /**\n     * @brief \u8981\u7D20\u3092\
    \u6607\u9806\u306B\u4E26\u3079\u305F\u3082\u306E O(size() log_64 n)\n     */\n\
    \    std::vector<long long> to_vector() const {\n        std::vector<long long>\
    \ res;\n        res.reserve(cnt);\n        for (long long x = next(0); x != -1;\
    \ x = next(x + 1)) res.push_back(x);\n        return res;\n    }\n    /**\n  \
    \   * @brief \u3059\u3079\u3066\u524A\u9664\u3059\u308B O(n / 64)\n     */\n \
    \   void clear() {\n        for (auto& level : seg) level.assign(level.size(),\
    \ 0);\n        cnt = 0;\n    }\n};\n#line 2 \"src/data_structures/segtree.hpp\"\
    \n\n/**\n * @file segtree.hpp\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\
    \ */\n\n#line 9 \"src/data_structures/segtree.hpp\"\n#include <ostream>\n#line\
    \ 12 \"src/data_structures/segtree.hpp\"\n\n#line 2 \"src/algebra/monoid.hpp\"\
    \n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\
    \n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\
    \u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\
    \n * - S op(const S& a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e():\
    \ \u5358\u4F4D\u5143\n * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\
    \u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\
    \u51FA\u3059)\n */\n\n#include <algorithm>\n#include <array>\n#include <cstddef>\n\
    #include <istream>\n#include <limits>\n#include <numeric>\n#include <optional>\n\
    #line 22 \"src/algebra/monoid.hpp\"\n#include <type_traits>\n#line 24 \"src/algebra/monoid.hpp\"\
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
    \    }\n};\n\n/**\n * @brief clamp \u3059\u308B\u95A2\u6570 f(x) = min(max(x,\
    \ lb), ub)\n *\n * monoid::ClampComposite \u306E\u8981\u7D20\u3084 acted_monoid::ClampMin\
    \ \u306A\u3069\u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B: Clamp<int>\
    \ f{0, 10}; f(x) \u306F x \u3092 [0, 10] \u306B\u53CE\u3081\u308B\u3002\u7701\u7565\
    \u3059\u308B\u3068\u6052\u7B49\u5199\u50CF {\u578B\u306E\u6700\u5C0F\u5024, \u578B\
    \u306E\u6700\u5927\u5024}\n * lb, ub \u306B {} (std::nullopt) \u3092\u6E21\u3059\
    \u3068\u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057 (\u578B\u306E\u6700\u5C0F\u5024\
    \u30FB\u6700\u5927\u5024) \u306B\u306A\u308B\u3002\u4F8B: Clamp<int>{0, {}} \u306F\
    \ chmax 0\n * lb <= ub \u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\n\
    \ */\ntemplate <typename T>\nstruct Clamp {\n    T lb;  //!< \u4E0B\u9650\n  \
    \  T ub;  //!< \u4E0A\u9650\n    /// @brief \u6052\u7B49\u5199\u50CF\n    constexpr\
    \ Clamp() : lb(std::numeric_limits<T>::lowest()), ub(std::numeric_limits<T>::max())\
    \ {}\n    /// @brief 1 \u3064\u306E\u5024\u304B\u3089\u306E\u6697\u9ED9\u306E\u5909\
    \u63DB\u3092\u9632\u3050\u305F\u3081\u3001lb \u3068 ub \u306F\u4E21\u65B9\u6E21\
    \u3059\n    constexpr Clamp(std::optional<T> _lb, std::optional<T> _ub)\n    \
    \    : lb(_lb ? *_lb : std::numeric_limits<T>::lowest()), ub(_ub ? *_ub : std::numeric_limits<T>::max())\
    \ {}\n    constexpr T operator()(const T& x) const { return std::min(std::max(x,\
    \ lb), ub); }\n    friend constexpr bool operator==(const Clamp& f, const Clamp&\
    \ g) { return f.lb == g.lb && f.ub == g.ub; }\n    friend constexpr bool operator!=(const\
    \ Clamp& f, const Clamp& g) { return !(f == g); }\n    template <class CharT,\
    \ class Traits>\n    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, Clamp& f) {\n        return is >> f.lb >> f.ub;\n    }\n    template\
    \ <class CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Clamp& f) {\n        return os << f.lb << CharT(' ') << f.ub;\n\
    \    }\n};\n\n/**\n * @brief \u8DB3\u3057\u3066\u304B\u3089 clamp \u3059\u308B\
    \u95A2\u6570 f(x) = min(max(x + add, lb), ub)\n *\n * monoid::ClampAddComposite\
    \ \u306E\u8981\u7D20\u3084 acted_monoid::ClampAddMin\u3001beats_acted_monoid::ChminChmaxAddSum\
    \ \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B: ClampAdd<long long> f{0,\
    \ 10, 3}; f(x) \u306F x + 3 \u3092 [0, 10] \u306B\u53CE\u3081\u308B\u3002\u7701\
    \u7565\u3059\u308B\u3068\u6052\u7B49\u5199\u50CF {\u578B\u306E\u6700\u5C0F\u5024\
    , \u578B\u306E\u6700\u5927\u5024, 0}\n * lb <= ub \u3067\u306A\u3051\u308C\u3070\
    \u306A\u3089\u306A\u3044\u3002lb \u304C\u578B\u306E\u6700\u5C0F\u5024\u3001ub\
    \ \u304C\u578B\u306E\u6700\u5927\u5024\u306E\u3068\u304D\u306F\u3001\u305D\u308C\
    \u305E\u308C\u4E0B\u9650\u30FB\u4E0A\u9650\u304C\u306A\u3044\u3053\u3068\u3092\
    \u8868\u3059\n * lb, ub \u306B {} (std::nullopt) \u3092\u6E21\u3059\u3068\u4E0B\
    \u9650\u30FB\u4E0A\u9650\u306A\u3057\u306B\u306A\u308B\u3002\u4F8B: ClampAdd<long\
    \ long>{{}, {}, 3} \u306F 3 \u3092\u8DB3\u3059\u3001{{}, 5} \u306F chmin 5\n */\n\
    template <typename T>\nstruct ClampAdd {\n    T lb;   //!< \u4E0B\u9650\n    T\
    \ ub;   //!< \u4E0A\u9650\n    T add;  //!< clamp \u306E\u524D\u306B\u8DB3\u3059\
    \u5024\n    /// @brief \u6052\u7B49\u5199\u50CF\n    constexpr ClampAdd() : lb(std::numeric_limits<T>::lowest()),\
    \ ub(std::numeric_limits<T>::max()), add(T(0)) {}\n    /// @brief 1 \u3064\u306E\
    \u5024\u304B\u3089\u306E\u6697\u9ED9\u306E\u5909\u63DB\u3092\u9632\u3050\u305F\
    \u3081\u3001lb \u3068 ub \u306F\u4E21\u65B9\u6E21\u3059\n    constexpr ClampAdd(std::optional<T>\
    \ _lb, std::optional<T> _ub, T _add = T(0))\n        : lb(_lb ? *_lb : std::numeric_limits<T>::lowest()),\
    \ ub(_ub ? *_ub : std::numeric_limits<T>::max()), add(_add) {}\n    constexpr\
    \ T operator()(const T& x) const { return std::min(std::max(x + add, lb), ub);\
    \ }\n    friend constexpr bool operator==(const ClampAdd& f, const ClampAdd& g)\
    \ { return f.lb == g.lb && f.ub == g.ub && f.add == g.add; }\n    friend constexpr\
    \ bool operator!=(const ClampAdd& f, const ClampAdd& g) { return !(f == g); }\n\
    \    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, ClampAdd& f) {\n\
    \        return is >> f.lb >> f.ub >> f.add;\n    }\n    template <class CharT,\
    \ class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const ClampAdd& f) {\n        return os << f.lb << CharT(' ') <<\
    \ f.ub << CharT(' ') << f.add;\n    }\n};\n\nnamespace monoid {\n\n/**\n * @brief\
    \ \u548C\n */\ntemplate <typename T>\nstruct Sum {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return a + b; }\n    static constexpr\
    \ S e() { return S(0); }\n};\n\n/**\n * @brief \u7A4D\n */\ntemplate <typename\
    \ T>\nstruct Prod {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a * b; }\n    static constexpr S e() { return S(1); }\n};\n\n\
    /**\n * @brief \u6700\u5927\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\
    \u5024\n */\ntemplate <typename T>\nstruct Max {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return std::max(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::lowest(); }\n};\n\n/**\n *\
    \ @brief \u6700\u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nstruct Min {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return std::min(a, b); }\n    static constexpr\
    \ S e() { return std::numeric_limits<S>::max(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max}\n */\ntemplate <typename\
    \ T>\nstruct MinMax {\n    using S = std::pair<T, T>;\n    static constexpr S\
    \ op(const S& a, const S& b) { return {std::min(a.first, b.first), std::max(a.second,\
    \ b.second)}; }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::lowest()}; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\
    \u8AD6\u7406\u548C\n */\ntemplate <typename T>\nstruct Xor {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return a ^ b; }\n    static\
    \ constexpr S e() { return S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\u7A4D\n\
    \ */\ntemplate <typename T>\nstruct And {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return a & b; }\n    static constexpr S e() {\
    \ return ~S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\u548C\n */\ntemplate <typename\
    \ T>\nstruct Or {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a | b; }\n    static constexpr S e() { return S(0); }\n};\n\n\
    /**\n * @brief \u6700\u5927\u516C\u7D04\u6570 \u5358\u4F4D\u5143\u306F0\n */\n\
    template <typename T>\nstruct Gcd {\n    static_assert(std::is_integral_v<T>);\n\
    \    using S = T;\n    static constexpr S op(const S& a, const S& b) { return\
    \ std::gcd(a, b); }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u6700\u5C0F\u516C\u500D\u6570 \u5358\u4F4D\u5143\u306F1\n */\ntemplate\
    \ <typename T>\nstruct Lcm {\n    static_assert(std::is_integral_v<T>);\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return std::lcm(a,\
    \ b); }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief {0,\
    \ 1, ..., N-1} \u304B\u3089\u81EA\u5206\u81EA\u8EAB\u3078\u306E\u5199\u50CF\u306E\
    \u5408\u6210 (\u5909\u63DB\u30E2\u30CE\u30A4\u30C9)\n *\n * \u8981\u7D20 f \u306F\
    \ f[x] \u304C x \u306E\u884C\u304D\u5148\u3092\u8868\u3059 std::array<int, N>\u3002\
    \u5168\u5358\u5C04\u3067\u306A\u304F\u3066\u3088\u3044\n * op(f, g) = f\u2218\
    g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\u3002\u533A\u9593 [l, r) \u306E\
    \u7A4D\u306F f_l(...f_{r-1}(x)) \u3092\u8868\u3059\n * \u5DE6\u304B\u3089\u9806\
    \u306B\u9069\u7528\u3057\u305F\u3044\u5834\u5408\u306F monoid::Reverse<monoid::Mapping<N>>\
    \ \u3092\u4F7F\u3046\n * \u4F8B: SegTree<monoid::Mapping<3>> seg(n); seg.set(i,\
    \ {0, 2, 1});\n * swap(i, j) \u3067 i \u3068 j \u3092\u5165\u308C\u66FF\u3048\u308B\
    \u5199\u50CF\u3092\u4F5C\u308C\u308B\n *\n * @tparam N \u5199\u50CF\u306E\u5B9A\
    \u7FA9\u57DF\u30FB\u5024\u57DF\u306E\u5927\u304D\u3055\n */\ntemplate <std::size_t\
    \ N>\nstruct Mapping {\n    using S = std::array<int, N>;\n    static constexpr\
    \ S op(const S& f, const S& g) {\n        S h{};\n        for (std::size_t x =\
    \ 0; x < N; x++) h[x] = f[g[x]];\n        return h;\n    }\n    static constexpr\
    \ S e() {\n        S h{};\n        for (std::size_t x = 0; x < N; x++) h[x] =\
    \ static_cast<int>(x);\n        return h;\n    }\n    // i \u3068 j \u3092\u5165\
    \u308C\u66FF\u3048\u3001\u307B\u304B\u306F\u52D5\u304B\u3055\u306A\u3044\u5199\
    \u50CF (\u4E92\u63DB)\n    static constexpr S swap(long long i, long long j) {\n\
    \        S h = e();\n        h[i] = static_cast<int>(j);\n        h[j] = static_cast<int>(i);\n\
    \        return h;\n    }\n};\n\n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\
    \u5408\u6210\n * op(f, g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B\
    )\n * \u533A\u9593 [l, r) \u306E\u7A4D\u306F f_l(...f_{r-1}(x)) \u3092\u8868\u3059\
    \n * \u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3057\u305F\u3044 (f_{r-1}(...f_l(x))\
    \ \u3092\u6C42\u3081\u305F\u3044) \u5834\u5408\u306F monoid::Reverse<monoid::Composite<T>>\
    \ \u3092\u4F7F\u3046\n */\ntemplate <typename T>\nstruct Composite {\n    using\
    \ S = Affine<T>;\n    static constexpr S op(const S& f, const S& g) { return {f.a\
    \ * g.a, f.a * g.b + f.b}; }\n    static constexpr S e() { return {T(1), T(0)};\
    \ }\n};\n\n/**\n * @brief clamp \u3059\u308B\u95A2\u6570 (Clamp) \u306E\u5408\u6210\
    \n * op(f, g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n * clamp(clamp(x,\
    \ a, b), c, d) = clamp(x, clamp(a, c, d), clamp(b, c, d)) \u306A\u306E\u3067\u3001\
    \u5408\u6210\u3082 Clamp \u306B\u306A\u308B\n */\ntemplate <typename T>\nstruct\
    \ ClampComposite {\n    using S = Clamp<T>;\n    static constexpr S op(const S&\
    \ f, const S& g) { return {f(g.lb), f(g.ub)}; }\n    static constexpr S e() {\
    \ return {}; }\n};\n\n/**\n * @brief \u8DB3\u3057\u3066\u304B\u3089 clamp \u3059\
    \u308B\u95A2\u6570 (ClampAdd) \u306E\u5408\u6210\n * op(f, g) = f\u2218g (g \u3092\
    \u5148\u306B\u9069\u7528\u3059\u308B)\n * f(g(x)) = clamp(x + g.add + f.add, f(g.lb),\
    \ f(g.ub)) \u306A\u306E\u3067\u3001\u5408\u6210\u3082 ClampAdd \u306B\u306A\u308B\
    \n * \u578B\u306E\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024\u306E lb\u30FBub \u306F\
    \u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057\u3068\u3057\u3066\u6271\u3044\u3001\
    \u8DB3\u3057\u3066\u3082\u3042\u3075\u308C\u306A\u3044\u3088\u3046\u306B\u3059\
    \u308B\n */\ntemplate <typename T>\nstruct ClampAddComposite {\n    using S =\
    \ ClampAdd<T>;\n    static constexpr S op(const S& f, const S& g) {\n        T\
    \ lb = g.lb == std::numeric_limits<T>::lowest() ? f.lb : f(g.lb);\n        T ub\
    \ = g.ub == std::numeric_limits<T>::max() ? f.ub : f(g.ub);\n        return {lb,\
    \ ub, g.add + f.add};\n    }\n    static constexpr S e() { return {}; }\n};\n\n\
    /**\n * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis {\n    struct\
    \ S {\n        long long close;  // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\
    \u306A\u3044 ')' \u306E\u500B\u6570\n        long long open;   // \u5BFE\u5FDC\
    \u306E\u53D6\u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\n        constexpr\
    \ S(char c = 0) : close(c == ')'), open(c == '(') {}\n        constexpr S(long\
    \ long close, long long open) : close(close), open(open) {}\n        /**\n   \
    \      * @brief \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n         */\n    \
    \    constexpr bool is_valid() const { return close == 0 && open == 0; }\n   \
    \ };\n    static constexpr S op(const S& a, const S& b) {\n        if (a.open\
    \ >= b.close) return S(a.close, a.open - b.close + b.open);\n        return S(a.close\
    \ + b.close - a.open, b.open);\n    }\n    static constexpr S e() { return S();\
    \ }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\
    \u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\
    \u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\
    \u5024\u306E\u578B\n */\ntemplate <typename T, typename U = long long>\nstruct\
    \ MinWith {\n    using S = std::pair<T, U>;\n    static constexpr S op(const S&\
    \ a, const S& b) { return b.first < a.first ? b : a; }\n    static constexpr S\
    \ e() { return {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n * @brief \u6700\
    \u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\
    \u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\
    \u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate\
    \ <typename T, typename U = long long>\nstruct MaxWith {\n    using S = std::pair<T,\
    \ U>;\n    static constexpr S op(const S& a, const S& b) { return a.first < b.first\
    \ ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MinCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if (a.first < b.first) return a;\n        if (b.first < a.first) return\
    \ b;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::max(), U(0)}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MaxCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if (a.first < b.first) return\
    \ b;\n        if (b.first < a.first) return a;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3068\u3001\u7A7A\u3092\
    \u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5927\u5024\n * S(x) \u3067\u5024\
    \ x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\
    \u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate <typename T>\n\
    struct PrefixSumMax {\n    struct S {\n        T sum;  // \u533A\u9593\u306E\u548C\
    \n        T max;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5927\
    \u5024 (0 \u4EE5\u4E0A)\n        constexpr S() : sum(0), max(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), max(x < T(0) ? T(0) : x) {}\n        constexpr S(const\
    \ T& sum, const T& max) : sum(sum), max(max) {}\n        friend constexpr bool\
    \ operator==(const S& a, const S& b) { return a.sum == b.sum && a.max == b.max;\
    \ }\n        friend constexpr bool operator!=(const S& a, const S& b) { return\
    \ !(a == b); }\n    };\n    static constexpr S op(const S& a, const S& b) { return\
    \ S(a.sum + b.sum, std::max(a.max, a.sum + b.max)); }\n    static constexpr S\
    \ e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3068\u3001\
    \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5C0F\u5024\n * S(x)\
    \ \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\
    \u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate\
    \ <typename T>\nstruct PrefixSumMin {\n    struct S {\n        T sum;  // \u533A\
    \u9593\u306E\u548C\n        T min;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\
    \u306E\u6700\u5C0F\u5024 (0 \u4EE5\u4E0B)\n        constexpr S() : sum(0), min(0)\
    \ {}\n        constexpr S(const T& x) : sum(x), min(T(0) < x ? T(0) : x) {}\n\
    \        constexpr S(const T& sum, const T& min) : sum(sum), min(min) {}\n   \
    \     friend constexpr bool operator==(const S& a, const S& b) { return a.sum\
    \ == b.sum && a.min == b.min; }\n        friend constexpr bool operator!=(const\
    \ S& a, const S& b) { return !(a == b); }\n    };\n    static constexpr S op(const\
    \ S& a, const S& b) { return S(a.sum + b.sum, std::min(a.min, a.sum + b.min));\
    \ }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\
    \u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\
    \u5927\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\
    \u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593\
    \ {0, 0}\n */\ntemplate <typename T>\nstruct SuffixSumMax {\n    struct S {\n\
    \        T sum;  // \u533A\u9593\u306E\u548C\n        T max;  // \u7A7A\u3092\u542B\
    \u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        constexpr\
    \ S() : sum(0), max(0) {}\n        constexpr S(const T& x) : sum(x), max(x < T(0)\
    \ ? T(0) : x) {}\n        constexpr S(const T& sum, const T& max) : sum(sum),\
    \ max(max) {}\n        friend constexpr bool operator==(const S& a, const S& b)\
    \ { return a.sum == b.sum && a.max == b.max; }\n        friend constexpr bool\
    \ operator!=(const S& a, const S& b) { return !(a == b); }\n    };\n    static\
    \ constexpr S op(const S& a, const S& b) { return S(a.sum + b.sum, std::max(b.max,\
    \ a.max + b.sum)); }\n    static constexpr S e() { return S(); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 suffix\
    \ \u306E\u548C\u306E\u6700\u5C0F\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\
    \u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\
    \u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate <typename T>\nstruct SuffixSumMin\
    \ {\n    struct S {\n        T sum;  // \u533A\u9593\u306E\u548C\n        T min;\
    \  // \u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\u5C0F\u5024 (0\
    \ \u4EE5\u4E0B)\n        constexpr S() : sum(0), min(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), min(T(0) < x ? T(0) : x) {}\n        constexpr S(const\
    \ T& sum, const T& min) : sum(sum), min(min) {}\n        friend constexpr bool\
    \ operator==(const S& a, const S& b) { return a.sum == b.sum && a.min == b.min;\
    \ }\n        friend constexpr bool operator!=(const S& a, const S& b) { return\
    \ !(a == b); }\n    };\n    static constexpr S op(const S& a, const S& b) { return\
    \ S(a.sum + b.sum, std::min(b.min, a.min + b.sum)); }\n    static constexpr S\
    \ e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3001\u7A7A\
    \u3092\u542B\u3080 prefix\u30FBsuffix \u306E\u548C\u306E\u6700\u5927\u5024\u3001\
    \u7A7A\u3092\u542B\u3080\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\
    \u5927\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\
    \u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593\
    \ {0, 0, 0, 0}\n * \u9759\u7684\u306A\u5217\u306B\u5BFE\u3057\u3066\u4E00\u5EA6\
    \u3060\u3051\u6C42\u3081\u308B\u306A\u3089 dp/maximum-subarray.hpp \u306E maximum_subarray\n\
    \ */\ntemplate <typename T>\nstruct MaxSubarraySum {\n    struct S {\n       \
    \ T sum;     // \u533A\u9593\u306E\u548C\n        T prefix;  // \u7A7A\u3092\u542B\
    \u3080 prefix \u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        T\
    \ suffix;  // \u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024\
    \ (0 \u4EE5\u4E0A)\n        T best;    // \u7A7A\u3092\u542B\u3080\u9023\u7D9A\
    \u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n    \
    \    constexpr S() : sum(0), prefix(0), suffix(0), best(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), prefix(x < T(0) ? T(0) : x), suffix(prefix), best(prefix)\
    \ {}\n        constexpr S(const T& sum, const T& prefix, const T& suffix, const\
    \ T& best)\n            : sum(sum), prefix(prefix), suffix(suffix), best(best)\
    \ {}\n        friend constexpr bool operator==(const S& a, const S& b) {\n   \
    \         return a.sum == b.sum && a.prefix == b.prefix && a.suffix == b.suffix\
    \ && a.best == b.best;\n        }\n        friend constexpr bool operator!=(const\
    \ S& a, const S& b) { return !(a == b); }\n    };\n    static constexpr S op(const\
    \ S& a, const S& b) {\n        return S(a.sum + b.sum, std::max(a.prefix, a.sum\
    \ + b.prefix), std::max(b.suffix, a.suffix + b.sum),\n                 std::max({a.best,\
    \ b.best, a.suffix + b.prefix}));\n    }\n    static constexpr S e() { return\
    \ S(); }\n};\n\n/**\n * @brief \u7A4D\u306E\u9806\u5E8F\u3092\u9006\u306B\u3057\
    \u305F\u30E2\u30CE\u30A4\u30C9 op(a, b) = M::op(b, a)\n *\n * \u4F8B: SegTree<monoid::Reverse<monoid::Composite<mint>>>\
    \ seg(v); \u306E\u533A\u9593 [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x))\n *\n\
    \ * @tparam M \u3082\u3068\u306E\u30E2\u30CE\u30A4\u30C9\n */\ntemplate <typename\
    \ M>\nstruct Reverse {\n    using S = typename M::S;\n    M m;\n    constexpr\
    \ Reverse() : m() {}\n    constexpr explicit Reverse(M m) : m(std::move(m)) {}\n\
    \    constexpr S op(const S& a, const S& b) const { return m.op(b, a); }\n   \
    \ constexpr S e() const { return m.e(); }\n};\n\n}  // namespace monoid\n\n/**\n\
    \ * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\u5358\u4F4D\u5143\
    \u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u30E2\u30CE\u30A4\u30C9\n * \u30E9\
    \u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * \u4F8B: SegTree seg(v, Monoid([](int\
    \ a, int b) { return std::max(a, b); }, -1));\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u578B\n */\ntemplate <typename T, typename Op>\nstruct Monoid {\n    using\
    \ S = T;\n    Op op_object;\n    S identity;\n    Monoid() = default;\n    constexpr\
    \ Monoid(Op op, const S& e) : op_object(std::move(op)), identity(e) {}\n    constexpr\
    \ S op(const S& a, const S& b) const { return op_object(a, b); }\n    constexpr\
    \ S e() const { return identity; }\n};\ntemplate <typename Op, typename T>\nMonoid(Op,\
    \ T) -> Monoid<T, Op>;\n#line 14 \"src/data_structures/segtree.hpp\"\n\n/**\n\
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u4F8B:\n * SegTree<monoid::Max<int>>\
    \ seg(n);\n * SegTree seg(v, Monoid([](int a, int b) { return a + b; }, 0));\n\
    \ *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n */\ntemplate\
    \ <typename M>\nclass SegTree {\n   public:\n    using S = typename M::S;\n\n\
    \   private:\n    M m;\n    S op(const S& a, const S& b) const { return m.op(a,\
    \ b); }\n    S e() const { return m.e(); }\n\n    long long n, sz;\n    int height;\n\
    \    std::vector<S> data;\n    void update(long long k) { data[k] = op(data[2\
    \ * k], data[2 * k + 1]); }\n\n    class SegTreeReference {\n        SegTree&\
    \ segtree;\n        long long k;\n\n       public:\n        SegTreeReference(SegTree&\
    \ segtree, long long k) : segtree(segtree), k(k) {}\n        SegTreeReference&\
    \ operator=(const S& x) {\n            segtree.set(k, x);\n            return\
    \ *this;\n        }\n        operator S() const { return segtree.get(k); }\n \
    \   };\n\n    void construct_data() {\n        sz = 1;\n        height = 0;\n\
    \        while (sz < n) {\n            sz <<= 1;\n            height++;\n    \
    \    }\n        data.assign(sz * 2, e());\n    }\n\n   public:\n    /**\n    \
    \ * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param n\
    \ \u8981\u7D20\u6570\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ SegTree(long long n = 0, M m = M()) : m(std::move(m)), n(n) {\n        construct_data();\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     * @param m \u30E2\u30CE\
    \u30A4\u30C9\n     */\n    explicit SegTree(const std::vector<S>& v, M m = M())\
    \ : SegTree(v.size(), std::move(m)) {\n        for (long long i = 0; i < n; i++)\
    \ data[sz + i] = v[i];\n        for (long long i = sz - 1; i > 0; i--) update(i);\n\
    \    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n\
    \    long long size() const { return n; }\n\n    /**\n     * @brief \u6307\u5B9A\
    \u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n \
    \   S get(long long k) const {\n        assert(0 <= k && k < n);\n        return\
    \ data[sz + k];\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\
    \u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n     * @return S \u5024\n     */\n    S operator[](long long\
    \ k) const { return get(k); }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u3078\u306E\u53C2\u7167\u3092\u8FD4\u3059\n     *\n     * @param\
    \ k\n     * @return SegTreeReference \u8981\u7D20\u3078\u306E\u53C2\u7167 \u4EE3\
    \u5165\u3055\u308C\u308B\u3068set()\u304C\u547C\u3070\u308C\u308B\n     */\n \
    \   SegTreeReference operator[](long long k) { return SegTreeReference(*this,\
    \ k); }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n\
    \     *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\
    \u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n     * @return std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\
    \u30FC\u30E0\n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const SegTree& rhs)\
    \ {\n        for (long long i = 0; i < rhs.n; i++) {\n            if (i != 0)\
    \ os << CharT(' ');\n            os << rhs[i];\n        }\n        return os;\n\
    \    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\
    \u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n     *\n     * @param k \u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\u3057\u3044\u5024\n     */\n\
    \    void set(long long k, const S& x) {\n        assert(0 <= k && k < n);\n \
    \       k += sz;\n        data[k] = x;\n        for (int i = 1; i <= height; i++)\
    \ update(k >> i);\n    }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\
    \u8981\u7D20\u306E\u5024\u306Bx\u3092\u4F5C\u7528\u3055\u305B\u308B\n     *\n\
    \     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u4F5C\u7528\
    \u7D20\n     */\n    void apply(long long k, const S& x) { set(k, op(get(k), x));\
    \ }\n\n    /**\n     * @brief [l, r)\u306E\u533A\u9593\u306E\u7DCF\u7A4D\u3092\
    \u8FD4\u3059\n     *\n     * @param l \u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n    \
    \ * @return S \u7DCF\u7A4D\n     */\n    S prod(long long l, long long r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        S left_prod = e(), right_prod\
    \ = e();\n        l += sz;\n        r += sz;\n        while (l < r) {\n      \
    \      if (l & 1) left_prod = op(left_prod, data[l++]);\n            if (r & 1)\
    \ right_prod = op(data[--r], right_prod);\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        return op(left_prod, right_prod);\n    }\n    /**\n\
    \     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\
    \u3059\n     *\n     * @return S \u7DCF\u7A4D\n     */\n    S all_prod() const\
    \ { return data[1]; }\n\n    /**\n     * @brief (r = l or f(prod([l, r))) = true)\
    \ and (r = n or f(prod([l, r+1))) = false)\u3068\u306A\u308Br\u3092\u8FD4\u3059\
    \n     * f\u304C\u5358\u8ABF\u306A\u3089\u3001f(prod([l, r))) = true\u3068\u306A\
    \u308B\u6700\u5927\u306Er\n     *\n     * @tparam F\n     * @param l \u534A\u958B\
    \u533A\u9593\u306E\u958B\u59CB 0<=l<=n\n     * @param f \u5224\u5B9A\u95A2\u6570\
    \ f(e) = true\n     * @return long long\n     */\n    template <typename F>\n\
    \    long long max_right(long long l, F f) const {\n        assert(f(e()));\n\
    \        assert(0 <= l && l <= n);\n        if (l == n) return n;\n        l +=\
    \ sz;\n        while (l % 2 == 0) l >>= 1;\n        S sum = e();\n        while\
    \ (f(op(sum, data[l]))) {\n            sum = op(sum, data[l]);\n            l++;\n\
    \            while (l % 2 == 0) l >>= 1;\n            if (l == 1) return n;\n\
    \        }\n        while (l < sz) {\n            if (!f(op(sum, data[l * 2])))\n\
    \                l *= 2;\n            else {\n                sum = op(sum, data[l\
    \ * 2]);\n                l = l * 2 + 1;\n            }\n        }\n        return\
    \ l - sz;\n    }\n    /**\n     * @brief (l = 0 or f(prod([l, r))) = true) and\
    \ (l = r or f(prod([l-1, r))) = false)\u3068\u306A\u308Bl\u3092\u8FD4\u3059\n\
    \     * f\u304C\u5358\u8ABF\u306A\u3089\u3001f(prod([l, r))) = true\u3068\u306A\
    \u308B\u6700\u5C0F\u306El\n     *\n     * @tparam F\n     * @param r \u534A\u958B\
    \u533A\u9593\u306E\u7D42\u7AEF 0<=r<=n\n     * @param f \u5224\u5B9A\u95A2\u6570\
    \ f(e) = true\n     * @return long long\n     */\n    template <typename F>\n\
    \    long long min_left(long long r, F f) const {\n        assert(f(e()));\n \
    \       assert(0 <= r && r <= n);\n        if (r == 0) return 0;\n        r +=\
    \ sz;\n        S sum = e();\n        do {\n            r--;\n            while\
    \ (r > 1 && r % 2 == 1) r >>= 1;\n            if (!f(op(data[r], sum))) {\n  \
    \              while (r < sz) {\n                    r = r * 2 + 1;\n        \
    \            if (f(op(data[r], sum))) {\n                        sum = op(data[r],\
    \ sum);\n                        r--;\n                    }\n               \
    \ }\n                return r + 1 - sz;\n            }\n            sum = op(data[r],\
    \ sum);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\ntemplate\
    \ <typename M>\nSegTree(long long, M) -> SegTree<M>;\ntemplate <typename M>\n\
    SegTree(std::vector<typename M::S>, M) -> SegTree<M>;\n\n/**\n * @brief RangeMaxQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RMaxQ = SegTree<monoid::Max<S>>;\n\
    /**\n * @brief RangeMinQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RMinQ = SegTree<monoid::Min<S>>;\n/**\n * @brief RangeSumQuery\n *\n\
    \ * @tparam S \u578B\n */\ntemplate <typename S>\nusing RSumQ = SegTree<monoid::Sum<S>>;\n\
    /**\n * @brief RangeProdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RProdQ = SegTree<monoid::Prod<S>>;\n/**\n * @brief RangeXorQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RXorQ = SegTree<monoid::Xor<S>>;\n\
    /**\n * @brief RangeGcdQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RGcdQ = SegTree<monoid::Gcd<S>>;\n#line 14 \"src/data_structures/sortable-segtree.hpp\"\
    \n\n/**\n * @brief \u5404\u4F4D\u7F6E\u306B\u30AD\u30FC\u3068\u5024\u3092\u6301\
    \u3064\u5217\u3067\u30011 \u70B9\u306E\u5909\u66F4\u30FB\u533A\u9593\u306E\u7A4D\
    \u30FB\u533A\u9593\u3092\u30AD\u30FC\u3067\u4E26\u3079\u66FF\u3048\u308B\u64CD\
    \u4F5C\u3092\u884C\u3046\n *\n * \u4E26\u3079\u66FF\u3048\u305F\u533A\u9593\u3054\
    \u3068\u306B\u3001\u305D\u306E\u8981\u7D20\u3092\u30AD\u30FC\u306E\u4E8C\u5206\
    \u30C8\u30E9\u30A4 (\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728) \u3067\u6301\
    \u3061\u3001\u6607\u9806\u3068\u964D\u9806\u306E\u7A4D\u3092\u4FDD\u3064\u3002\
    \n * \u533A\u9593\u306E\u5148\u982D\u306E\u4F4D\u7F6E\u306B\u300C\u533A\u9593\u306E\
    \u5411\u304D\u306B\u5408\u308F\u305B\u305F\u7A4D\u300D\u3092\u7F6E\u3044\u305F\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u533A\u9593\u306E\u7A4D\u3092\u6C42\
    \u3081\u308B\u3002\n * \u4E26\u3079\u66FF\u3048\u306F\u30C8\u30E9\u30A4\u306E\u4F75\
    \u5408\u3001\u533A\u9593\u306E\u5883\u76EE\u306F\u30C8\u30E9\u30A4\u3092\u500B\
    \u6570\u3067\u5206\u3051\u308B\u3053\u3068\u3067\u4F5C\u308B\n * \u8A08\u7B97\u91CF\
    \u306F\u306A\u3089\u3057 O((N + Q) log K) (K \u306F\u30AD\u30FC\u306E\u4E0A\u9650\
    )\u3002\u30E1\u30E2\u30EA\u306F O((N + Q) log K)\n * \u4F8B:\n * SortableSegTree<monoid::Sum<long\
    \ long>> st(keys, values, 1LL << 30);\n * st.sort(l, r);         // [l, r) \u3092\
    \u30AD\u30FC\u306E\u6607\u9806\u306B\u4E26\u3079\u66FF\u3048\u308B\n * st.sort(l,\
    \ r, true);   // \u964D\u9806\n * st.prod(l, r);\n *\n * @tparam M \u30E2\u30CE\
    \u30A4\u30C9 (\u7A4D\u306E\u9806\u756A\u306F\u5217\u306E\u9806\u756A)\n */\ntemplate\
    \ <typename M>\nclass SortableSegTree {\n    using S = typename M::S;\n    struct\
    \ Node {\n        int child[2] = {0, 0};\n        int cnt = 0;\n        S asc,\
    \ desc;  // \u30AD\u30FC\u306E\u6607\u9806\u30FB\u964D\u9806\u306B\u4E26\u3079\
    \u305F\u3068\u304D\u306E\u7A4D\n    };\n    M m;\n    long long n;\n    int bits;\n\
    \    std::vector<Node> nodes;  // nodes[0] \u306F\u7A7A\u306E\u30C8\u30E9\u30A4\
    \n    std::vector<int> root;    // root[s]: s \u304B\u3089\u59CB\u307E\u308B\u533A\
    \u9593\u306E\u30C8\u30E9\u30A4\n    std::vector<bool> rev;    // rev[s]: s \u304B\
    \u3089\u59CB\u307E\u308B\u533A\u9593\u304C\u964D\u9806\u304B\n    FastSet starts;\
    \           // \u533A\u9593\u306E\u5148\u982D\n    SegTree<M> seg;\n\n    int\
    \ new_node() {\n        nodes.push_back(Node{{0, 0}, 0, m.e(), m.e()});\n    \
    \    return static_cast<int>(nodes.size()) - 1;\n    }\n    void pull(int t) {\n\
    \        const Node &a = nodes[nodes[t].child[0]], &b = nodes[nodes[t].child[1]];\n\
    \        nodes[t].cnt = a.cnt + b.cnt;\n        nodes[t].asc = m.op(a.asc, b.asc);\n\
    \        nodes[t].desc = m.op(b.desc, a.desc);\n    }\n    // \u30AD\u30FC k\u3001\
    \u5024 x \u3060\u3051\u3092\u6301\u3064\u30C8\u30E9\u30A4\n    int make(long long\
    \ k, const S& x) {\n        assert(0 <= k && k < (1LL << bits));\n        std::vector<int>\
    \ path = {new_node()};\n        for (int d = bits - 1; d >= 0; d--) {\n      \
    \      const int c = new_node();\n            nodes[path.back()].child[k >> d\
    \ & 1] = c;\n            path.push_back(c);\n        }\n        nodes[path.back()].cnt\
    \ = 1, nodes[path.back()].asc = nodes[path.back()].desc = x;\n        for (int\
    \ i = static_cast<int>(path.size()) - 2; i >= 0; i--) pull(path[i]);\n       \
    \ return path[0];\n    }\n    // 2 \u3064\u306E\u30C8\u30E9\u30A4\u3092\u4F75\u5408\
    \u3059\u308B (\u30AD\u30FC\u306F\u91CD\u306A\u3089\u306A\u3044\u3053\u3068)\n\
    \    int merge(int a, int b, int d) {\n        if (a == 0) return b;\n       \
    \ if (b == 0) return a;\n        assert(d >= 0 && \"SortableSegTree: \u30AD\u30FC\
    \u304C\u91CD\u306A\u3063\u3066\u3044\u308B\");\n        for (int c = 0; c < 2;\
    \ c++) {\n            int x = merge(nodes[a].child[c], nodes[b].child[c], d -\
    \ 1);\n            nodes[a].child[c] = x;\n        }\n        pull(a);\n     \
    \   return a;\n    }\n    // \u30AD\u30FC\u306E\u5C0F\u3055\u3044\u65B9\u304B\u3089\
    \ k \u500B\u3068\u6B8B\u308A\u306B\u5206\u3051\u308B\n    std::pair<int, int>\
    \ split(int t, int k, int d) {\n        if (t == 0 || k == 0) return {0, t};\n\
    \        if (k >= nodes[t].cnt) return {t, 0};\n        // \u3053\u3053\u306B\u6765\
    \u308B\u306A\u3089 cnt >= 2 \u306A\u306E\u3067\u8449\u3067\u306F\u306A\u3044\n\
    \        int s = new_node();\n        const int lc = nodes[t].child[0], left_cnt\
    \ = nodes[lc].cnt;\n        if (k <= left_cnt) {\n            auto [a, b] = split(lc,\
    \ k, d - 1);\n            nodes[t].child[0] = a;\n            nodes[s].child[0]\
    \ = b, nodes[s].child[1] = nodes[t].child[1];\n            nodes[t].child[1] =\
    \ 0;\n        } else {\n            auto [a, b] = split(nodes[t].child[1], k -\
    \ left_cnt, d - 1);\n            nodes[t].child[1] = a;\n            nodes[s].child[1]\
    \ = b;\n        }\n        pull(t), pull(s);\n        return {t, s};\n    }\n\
    \    // \u533A\u9593\u306E\u7A4D\u3092\u5411\u304D\u306B\u5408\u308F\u305B\u3066\
    \u8FD4\u3059\n    S value(int s) const { return rev[s] ? nodes[root[s]].desc :\
    \ nodes[root[s]].asc; }\n    // x \u304C\u533A\u9593\u306E\u5148\u982D\u306B\u306A\
    \u308B\u3088\u3046\u306B\u5206\u3051\u308B\n    void cut(long long x) {\n    \
    \    if (x >= n || starts.contains(x)) return;\n        const long long s = starts.prev(x);\n\
    \        const int len = nodes[root[s]].cnt, k = x - s;\n        int a, b;\n \
    \       if (!rev[s]) {\n            std::tie(a, b) = split(root[s], k, bits -\
    \ 1);\n        } else {\n            // \u964D\u9806\u306A\u306E\u3067\u3001\u5148\
    \u982D\u306E k \u500B\u306F\u30AD\u30FC\u306E\u5927\u304D\u3044\u65B9\u306E k\
    \ \u500B\n            std::tie(b, a) = split(root[s], len - k, bits - 1);\n  \
    \      }\n        root[s] = a, root[x] = b, rev[x] = rev[s];\n        starts.insert(x);\n\
    \        seg.set(s, value(s)), seg.set(x, value(x));\n    }\n\n   public:\n  \
    \  /**\n     * @brief \u30AD\u30FC\u3068\u5024\u306E\u5217\u304B\u3089\u4F5C\u308B\
    \n     * @param keys \u30AD\u30FC (0 <= \u30AD\u30FC < key_limit\u3001\u3059\u3079\
    \u3066\u7570\u306A\u308B\u3053\u3068)\n     * @param key_limit \u30AD\u30FC\u306E\
    \u4E0A\u9650 (1 \u70B9\u306E\u5909\u66F4\u3067\u4F7F\u3046\u30AD\u30FC\u3082\u3053\
    \u308C\u672A\u6E80\u3067\u3042\u308B\u3053\u3068)\n     */\n    SortableSegTree(const\
    \ std::vector<long long>& keys, const std::vector<S>& values, long long key_limit,\
    \ M m = M())\n        : m(m), n(keys.size()), bits(1), root(n), rev(n, false),\
    \ starts(n), seg(std::vector<S>(values), m) {\n        assert(keys.size() == values.size());\n\
    \        while ((1LL << bits) < key_limit) bits++;\n        nodes.reserve(n *\
    \ (bits + 2) + 1);\n        nodes.push_back(Node{{0, 0}, 0, this->m.e(), this->m.e()});\n\
    \        for (long long i = 0; i < n; i++) root[i] = make(keys[i], values[i]),\
    \ starts.insert(i);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\n    \
    \ */\n    long long size() const { return n; }\n    /**\n     * @brief \u4F4D\u7F6E\
    \ i \u306E\u30AD\u30FC\u3068\u5024\u3092\u5909\u3048\u308B \u306A\u3089\u3057\
    \ O(log K)\n     */\n    void set(long long i, long long k, const S& x) {\n  \
    \      assert(0 <= i && i < n);\n        cut(i), cut(i + 1);\n        root[i]\
    \ = make(k, x), rev[i] = false;\n        seg.set(i, x);\n    }\n    /**\n    \
    \ * @brief a[l] a[l+1] ... a[r-1] \u306E\u7A4D \u306A\u3089\u3057 O(log K + log\
    \ N)\n     */\n    S prod(long long l, long long r) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        if (l == r) return m.e();\n        cut(l), cut(r);\n\
    \        return seg.prod(l, r);\n    }\n    /**\n     * @brief [l, r) \u3092\u30AD\
    \u30FC\u306E\u6607\u9806 (reverse \u306A\u3089\u964D\u9806) \u306B\u4E26\u3079\
    \u66FF\u3048\u308B \u306A\u3089\u3057 O(log K + \u533A\u9593\u306E\u500B\u6570\
    )\n     */\n    void sort(long long l, long long r, bool reverse = false) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n  \
    \      cut(l), cut(r);\n        int t = 0;\n        for (long long s = l; s !=\
    \ -1 && s < r; s = starts.next(s + 1)) {\n            t = merge(t, root[s], bits\
    \ - 1);\n            if (s != l) starts.erase(s), seg.set(s, m.e()), root[s] =\
    \ 0;\n        }\n        root[l] = t, rev[l] = reverse;\n        seg.set(l, value(l));\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @file sortable-segtree.hpp\n * @brief \u533A\u9593\
    \u30BD\u30FC\u30C8\u306E\u3067\u304D\u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n */\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\n#include\
    \ \"fast-set.hpp\"\n#include \"segtree.hpp\"\n\n/**\n * @brief \u5404\u4F4D\u7F6E\
    \u306B\u30AD\u30FC\u3068\u5024\u3092\u6301\u3064\u5217\u3067\u30011 \u70B9\u306E\
    \u5909\u66F4\u30FB\u533A\u9593\u306E\u7A4D\u30FB\u533A\u9593\u3092\u30AD\u30FC\
    \u3067\u4E26\u3079\u66FF\u3048\u308B\u64CD\u4F5C\u3092\u884C\u3046\n *\n * \u4E26\
    \u3079\u66FF\u3048\u305F\u533A\u9593\u3054\u3068\u306B\u3001\u305D\u306E\u8981\
    \u7D20\u3092\u30AD\u30FC\u306E\u4E8C\u5206\u30C8\u30E9\u30A4 (\u52D5\u7684\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728) \u3067\u6301\u3061\u3001\u6607\u9806\u3068\u964D\
    \u9806\u306E\u7A4D\u3092\u4FDD\u3064\u3002\n * \u533A\u9593\u306E\u5148\u982D\u306E\
    \u4F4D\u7F6E\u306B\u300C\u533A\u9593\u306E\u5411\u304D\u306B\u5408\u308F\u305B\
    \u305F\u7A4D\u300D\u3092\u7F6E\u3044\u305F\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3067\u533A\u9593\u306E\u7A4D\u3092\u6C42\u3081\u308B\u3002\n * \u4E26\u3079\u66FF\
    \u3048\u306F\u30C8\u30E9\u30A4\u306E\u4F75\u5408\u3001\u533A\u9593\u306E\u5883\
    \u76EE\u306F\u30C8\u30E9\u30A4\u3092\u500B\u6570\u3067\u5206\u3051\u308B\u3053\
    \u3068\u3067\u4F5C\u308B\n * \u8A08\u7B97\u91CF\u306F\u306A\u3089\u3057 O((N +\
    \ Q) log K) (K \u306F\u30AD\u30FC\u306E\u4E0A\u9650)\u3002\u30E1\u30E2\u30EA\u306F\
    \ O((N + Q) log K)\n * \u4F8B:\n * SortableSegTree<monoid::Sum<long long>> st(keys,\
    \ values, 1LL << 30);\n * st.sort(l, r);         // [l, r) \u3092\u30AD\u30FC\u306E\
    \u6607\u9806\u306B\u4E26\u3079\u66FF\u3048\u308B\n * st.sort(l, r, true);   //\
    \ \u964D\u9806\n * st.prod(l, r);\n *\n * @tparam M \u30E2\u30CE\u30A4\u30C9 (\u7A4D\
    \u306E\u9806\u756A\u306F\u5217\u306E\u9806\u756A)\n */\ntemplate <typename M>\n\
    class SortableSegTree {\n    using S = typename M::S;\n    struct Node {\n   \
    \     int child[2] = {0, 0};\n        int cnt = 0;\n        S asc, desc;  // \u30AD\
    \u30FC\u306E\u6607\u9806\u30FB\u964D\u9806\u306B\u4E26\u3079\u305F\u3068\u304D\
    \u306E\u7A4D\n    };\n    M m;\n    long long n;\n    int bits;\n    std::vector<Node>\
    \ nodes;  // nodes[0] \u306F\u7A7A\u306E\u30C8\u30E9\u30A4\n    std::vector<int>\
    \ root;    // root[s]: s \u304B\u3089\u59CB\u307E\u308B\u533A\u9593\u306E\u30C8\
    \u30E9\u30A4\n    std::vector<bool> rev;    // rev[s]: s \u304B\u3089\u59CB\u307E\
    \u308B\u533A\u9593\u304C\u964D\u9806\u304B\n    FastSet starts;           // \u533A\
    \u9593\u306E\u5148\u982D\n    SegTree<M> seg;\n\n    int new_node() {\n      \
    \  nodes.push_back(Node{{0, 0}, 0, m.e(), m.e()});\n        return static_cast<int>(nodes.size())\
    \ - 1;\n    }\n    void pull(int t) {\n        const Node &a = nodes[nodes[t].child[0]],\
    \ &b = nodes[nodes[t].child[1]];\n        nodes[t].cnt = a.cnt + b.cnt;\n    \
    \    nodes[t].asc = m.op(a.asc, b.asc);\n        nodes[t].desc = m.op(b.desc,\
    \ a.desc);\n    }\n    // \u30AD\u30FC k\u3001\u5024 x \u3060\u3051\u3092\u6301\
    \u3064\u30C8\u30E9\u30A4\n    int make(long long k, const S& x) {\n        assert(0\
    \ <= k && k < (1LL << bits));\n        std::vector<int> path = {new_node()};\n\
    \        for (int d = bits - 1; d >= 0; d--) {\n            const int c = new_node();\n\
    \            nodes[path.back()].child[k >> d & 1] = c;\n            path.push_back(c);\n\
    \        }\n        nodes[path.back()].cnt = 1, nodes[path.back()].asc = nodes[path.back()].desc\
    \ = x;\n        for (int i = static_cast<int>(path.size()) - 2; i >= 0; i--) pull(path[i]);\n\
    \        return path[0];\n    }\n    // 2 \u3064\u306E\u30C8\u30E9\u30A4\u3092\
    \u4F75\u5408\u3059\u308B (\u30AD\u30FC\u306F\u91CD\u306A\u3089\u306A\u3044\u3053\
    \u3068)\n    int merge(int a, int b, int d) {\n        if (a == 0) return b;\n\
    \        if (b == 0) return a;\n        assert(d >= 0 && \"SortableSegTree: \u30AD\
    \u30FC\u304C\u91CD\u306A\u3063\u3066\u3044\u308B\");\n        for (int c = 0;\
    \ c < 2; c++) {\n            int x = merge(nodes[a].child[c], nodes[b].child[c],\
    \ d - 1);\n            nodes[a].child[c] = x;\n        }\n        pull(a);\n \
    \       return a;\n    }\n    // \u30AD\u30FC\u306E\u5C0F\u3055\u3044\u65B9\u304B\
    \u3089 k \u500B\u3068\u6B8B\u308A\u306B\u5206\u3051\u308B\n    std::pair<int,\
    \ int> split(int t, int k, int d) {\n        if (t == 0 || k == 0) return {0,\
    \ t};\n        if (k >= nodes[t].cnt) return {t, 0};\n        // \u3053\u3053\u306B\
    \u6765\u308B\u306A\u3089 cnt >= 2 \u306A\u306E\u3067\u8449\u3067\u306F\u306A\u3044\
    \n        int s = new_node();\n        const int lc = nodes[t].child[0], left_cnt\
    \ = nodes[lc].cnt;\n        if (k <= left_cnt) {\n            auto [a, b] = split(lc,\
    \ k, d - 1);\n            nodes[t].child[0] = a;\n            nodes[s].child[0]\
    \ = b, nodes[s].child[1] = nodes[t].child[1];\n            nodes[t].child[1] =\
    \ 0;\n        } else {\n            auto [a, b] = split(nodes[t].child[1], k -\
    \ left_cnt, d - 1);\n            nodes[t].child[1] = a;\n            nodes[s].child[1]\
    \ = b;\n        }\n        pull(t), pull(s);\n        return {t, s};\n    }\n\
    \    // \u533A\u9593\u306E\u7A4D\u3092\u5411\u304D\u306B\u5408\u308F\u305B\u3066\
    \u8FD4\u3059\n    S value(int s) const { return rev[s] ? nodes[root[s]].desc :\
    \ nodes[root[s]].asc; }\n    // x \u304C\u533A\u9593\u306E\u5148\u982D\u306B\u306A\
    \u308B\u3088\u3046\u306B\u5206\u3051\u308B\n    void cut(long long x) {\n    \
    \    if (x >= n || starts.contains(x)) return;\n        const long long s = starts.prev(x);\n\
    \        const int len = nodes[root[s]].cnt, k = x - s;\n        int a, b;\n \
    \       if (!rev[s]) {\n            std::tie(a, b) = split(root[s], k, bits -\
    \ 1);\n        } else {\n            // \u964D\u9806\u306A\u306E\u3067\u3001\u5148\
    \u982D\u306E k \u500B\u306F\u30AD\u30FC\u306E\u5927\u304D\u3044\u65B9\u306E k\
    \ \u500B\n            std::tie(b, a) = split(root[s], len - k, bits - 1);\n  \
    \      }\n        root[s] = a, root[x] = b, rev[x] = rev[s];\n        starts.insert(x);\n\
    \        seg.set(s, value(s)), seg.set(x, value(x));\n    }\n\n   public:\n  \
    \  /**\n     * @brief \u30AD\u30FC\u3068\u5024\u306E\u5217\u304B\u3089\u4F5C\u308B\
    \n     * @param keys \u30AD\u30FC (0 <= \u30AD\u30FC < key_limit\u3001\u3059\u3079\
    \u3066\u7570\u306A\u308B\u3053\u3068)\n     * @param key_limit \u30AD\u30FC\u306E\
    \u4E0A\u9650 (1 \u70B9\u306E\u5909\u66F4\u3067\u4F7F\u3046\u30AD\u30FC\u3082\u3053\
    \u308C\u672A\u6E80\u3067\u3042\u308B\u3053\u3068)\n     */\n    SortableSegTree(const\
    \ std::vector<long long>& keys, const std::vector<S>& values, long long key_limit,\
    \ M m = M())\n        : m(m), n(keys.size()), bits(1), root(n), rev(n, false),\
    \ starts(n), seg(std::vector<S>(values), m) {\n        assert(keys.size() == values.size());\n\
    \        while ((1LL << bits) < key_limit) bits++;\n        nodes.reserve(n *\
    \ (bits + 2) + 1);\n        nodes.push_back(Node{{0, 0}, 0, this->m.e(), this->m.e()});\n\
    \        for (long long i = 0; i < n; i++) root[i] = make(keys[i], values[i]),\
    \ starts.insert(i);\n    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\n    \
    \ */\n    long long size() const { return n; }\n    /**\n     * @brief \u4F4D\u7F6E\
    \ i \u306E\u30AD\u30FC\u3068\u5024\u3092\u5909\u3048\u308B \u306A\u3089\u3057\
    \ O(log K)\n     */\n    void set(long long i, long long k, const S& x) {\n  \
    \      assert(0 <= i && i < n);\n        cut(i), cut(i + 1);\n        root[i]\
    \ = make(k, x), rev[i] = false;\n        seg.set(i, x);\n    }\n    /**\n    \
    \ * @brief a[l] a[l+1] ... a[r-1] \u306E\u7A4D \u306A\u3089\u3057 O(log K + log\
    \ N)\n     */\n    S prod(long long l, long long r) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        if (l == r) return m.e();\n        cut(l), cut(r);\n\
    \        return seg.prod(l, r);\n    }\n    /**\n     * @brief [l, r) \u3092\u30AD\
    \u30FC\u306E\u6607\u9806 (reverse \u306A\u3089\u964D\u9806) \u306B\u4E26\u3079\
    \u66FF\u3048\u308B \u306A\u3089\u3057 O(log K + \u533A\u9593\u306E\u500B\u6570\
    )\n     */\n    void sort(long long l, long long r, bool reverse = false) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n  \
    \      cut(l), cut(r);\n        int t = 0;\n        for (long long s = l; s !=\
    \ -1 && s < r; s = starts.next(s + 1)) {\n            t = merge(t, root[s], bits\
    \ - 1);\n            if (s != l) starts.erase(s), seg.set(s, m.e()), root[s] =\
    \ 0;\n        }\n        root[l] = t, rev[l] = reverse;\n        seg.set(l, value(l));\n\
    \    }\n};\n"
  dependsOn:
  - src/data_structures/fast-set.hpp
  - src/data_structures/segtree.hpp
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/data_structures/sortable-segtree.hpp
  requiredBy: []
  timestamp: '2026-10-23 19:47:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/sortable-segtree.test.cpp
  - test/yosupo/data_structure/point-set-range-sort-range-composite.test.cpp
documentation_of: src/data_structures/sortable-segtree.hpp
layout: document
title: "\u533A\u9593\u30BD\u30FC\u30C8\u306E\u3067\u304D\u308B\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728"
---

各位置にキーと値を持つ列で、1 点の変更・区間の積・区間をキーで並べ替える操作を行います。値は [モノイド](../algebra/monoid.hpp) `M` の要素で、積は列の順番にとります。

```cpp
// キーは 0 以上 2^30 未満で、すべて異なること
SortableSegTree<monoid::Sum<long long>> st(keys, values, 1LL << 30);
st.sort(l, r);              // [l, r) をキーの昇順に並べ替える
st.sort(l, r, true);        // 降順に並べ替える
st.set(i, key, x);          // 位置 i のキーと値を変える
long long s = st.prod(l, r);
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SortableSegTree<M>(keys, values, key_limit, m = M())` | キーと値の列から作る。キーは $0$ 以上 `key_limit` 未満で、すべて異なること | $O(n \log K)$ |
| `size()` | 要素数 | $O(1)$ |
| `set(i, key, x)` | 位置 `i` のキーと値を変える (キーは今あるどのキーとも異なること) | ならし $O(\log K + \log n)$ |
| `prod(l, r)` | `a[l], ..., a[r-1]` の値の積 | ならし $O(\log K + \log n)$ |
| `sort(l, r, reverse = false)` | `[l, r)` をキーの昇順 (`reverse` なら降順) に並べ替える | ならし $O(\log K + \log n)$ |

$K$ は `key_limit` です。メモリは $O((n + q) \log K)$ です。

- 並べ替えた区間ごとに、その要素をキーの二分トライ (動的セグメント木) で持ち、キーの昇順と降順の積をそれぞれ保ちます。区間の先頭の位置に「区間の向きに合わせた積」を置いた [セグメント木](segtree.hpp) で区間の積を求めます。
- 並べ替えはトライの併合、区間の境目はトライを個数で 2 つに分けることで作ります。併合で消えるトライの頂点の数で抑えると、全体でならし $O((n + q) \log K)$ になります。
- `prod` も区間の境目を作るので、`const` ではありません。

## 関連

- 並べ替えがなければ [セグメント木](segtree.hpp)
- 区間の先頭の管理には [FastSet](fast-set.hpp) を使っています
