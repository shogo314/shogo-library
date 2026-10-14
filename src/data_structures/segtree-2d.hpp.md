---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point-add-rectangle-sum.test.cpp
    title: test/yosupo/point-add-rectangle-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"src/data_structures/segtree-2d.hpp\"\n\n/**\n * @file segtree-2d.hpp\n\
    \ * @brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n\
    \ * @brief \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\
    \u30C9\u306F\u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\
    \u3066\u8868\u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S&\
    \ a, const S& b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n\
    \ * op, e \u306F static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\
    \u30FC\u30BF\u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\
    \n#line 15 \"src/algebra/monoid.hpp\"\n#include <array>\n#include <cstddef>\n\
    #include <istream>\n#include <limits>\n#include <numeric>\n#include <ostream>\n\
    #include <type_traits>\n#line 23 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief\
    \ 1\u6B21\u95A2\u6570 f(x) = a * x + b\n *\n * monoid::Composite \u306E\u8981\u7D20\
    \u3084 acted_monoid::AffineSum \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n *\
    \ \u4F8B: Affine<mint> f{2, 3}; f(x) \u306F 2x + 3\u3002\u7701\u7565\u3059\u308B\
    \u3068\u6052\u7B49\u5199\u50CF {1, 0}\n */\ntemplate <typename T>\nstruct Affine\
    \ {\n    T a = T(1);  //!< \u50BE\u304D\n    T b = T(0);  //!< \u5207\u7247\n\
    \    constexpr T operator()(const T& x) const { return a * x + b; }\n    friend\
    \ constexpr bool operator==(const Affine& f, const Affine& g) { return f.a ==\
    \ g.a && f.b == g.b; }\n    friend constexpr bool operator!=(const Affine& f,\
    \ const Affine& g) { return !(f == g); }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
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
    \u50CF (\u4E92\u63DB)\n    static constexpr S swap(int i, int j) {\n        S\
    \ h = e();\n        h[i] = j;\n        h[j] = i;\n        return h;\n    }\n};\n\
    \n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\u5408\u6210\n * op(f, g)\
    \ = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n * \u533A\u9593 [l,\
    \ r) \u306E\u7A4D\u306F f_l(...f_{r-1}(x)) \u3092\u8868\u3059\n * \u5DE6\u304B\
    \u3089\u9806\u306B\u9069\u7528\u3057\u305F\u3044 (f_{r-1}(...f_l(x)) \u3092\u6C42\
    \u3081\u305F\u3044) \u5834\u5408\u306F monoid::Reverse<monoid::Composite<T>> \u3092\
    \u4F7F\u3046\n */\ntemplate <typename T>\nstruct Composite {\n    using S = Affine<T>;\n\
    \    static constexpr S op(const S& f, const S& g) { return {f.a * g.a, f.a *\
    \ g.b + f.b}; }\n    static constexpr S e() { return {T(1), T(0)}; }\n};\n\n/**\n\
    \ * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
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
    \u5024\u306E\u578B\n */\ntemplate <typename T, typename U = int>\nstruct MinWith\
    \ {\n    using S = std::pair<T, U>;\n    static constexpr S op(const S& a, const\
    \ S& b) { return b.first < a.first ? b : a; }\n    static constexpr S e() { return\
    \ {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n * @brief \u6700\u5927\u5024\
    \u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\
    \u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\
    \u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate <typename\
    \ T, typename U = int>\nstruct MaxWith {\n    using S = std::pair<T, U>;\n   \
    \ static constexpr S op(const S& a, const S& b) { return a.first < b.first ? b\
    \ : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
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
    \ U(0)}; }\n};\n\n/**\n * @brief \u7A4D\u306E\u9806\u5E8F\u3092\u9006\u306B\u3057\
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
    \ T) -> Monoid<T, Op>;\n#line 15 \"src/data_structures/segtree-2d.hpp\"\n\n/**\n\
    \ * @brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u66F4\u65B0\u30FB\
    \u53D6\u5F97\u3059\u308B\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u3066\u5727\
    \u7E2E\u3059\u308B)\n *\n * @tparam M \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\n\
    \ */\ntemplate <typename M>\nclass SegTree2D {\n   public:\n    using S = typename\
    \ M::S;\n\n   private:\n    M m;\n    S op(const S& a, const S& b) const { return\
    \ m.op(a, b); }\n    S e() const { return m.e(); }\n\n    int h, w, sz_x, sz_y,\
    \ height_x, height_y;\n    std::vector<std::vector<int>> y_indices;\n    std::vector<std::vector<S>>\
    \ data_compressed;\n\n    S get_y(int kx, int ky) {\n        ky += sz_y;\n   \
    \     auto it = std::lower_bound(y_indices[kx].begin(), y_indices[kx].end(), ky);\n\
    \        if (it == y_indices[kx].end() || *it != ky) return e();\n        return\
    \ data_compressed[kx][it - y_indices[kx].begin()];\n    }\n\n    S updated_y(int\
    \ kx, int ky, int child_y_idx, bool child_y_right, const S& child_val) {\n   \
    \     if (!child_y_right && child_y_idx + 1 < (int)y_indices[kx].size() && y_indices[kx][child_y_idx\
    \ + 1] == ky * 2 + 1) {\n            return op(child_val, data_compressed[kx][child_y_idx\
    \ + 1]);\n        }\n        if (child_y_right && child_y_idx - 1 >= 0 && y_indices[kx][child_y_idx\
    \ - 1] == ky * 2) {\n            return op(data_compressed[kx][child_y_idx - 1],\
    \ child_val);\n        }\n        return child_val;\n    }\n\n    void update_tree_y(int\
    \ kx, int ky, const S& val) {\n        ky += sz_y;\n        int y_idx = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].end(), ky) - y_indices[kx].begin();\n        S tmp_val = val;\n\
    \        data_compressed[kx][y_idx] = tmp_val;\n        for (int i = 1; i <= height_y;\
    \ i++) {\n            int child_y_idx = y_idx;\n            y_idx = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].begin() + child_y_idx, ky >> i) - y_indices[kx].begin();\n   \
    \         tmp_val = data_compressed[kx][y_idx] = updated_y(kx, ky >> i, child_y_idx,\
    \ ky >> (i - 1) & 1, tmp_val);\n        }\n    }\n\n    S updated_x(int kx, int\
    \ ky, bool child_x_right, const S& child_val) {\n        if (!child_x_right) {\n\
    \            return op(child_val, get_y(kx * 2 + 1, ky));\n        } else {\n\
    \            return op(get_y(kx * 2, ky), child_val);\n        }\n    }\n\n  \
    \  void update_tree_x(int kx, int ky, const S& val) {\n        kx += sz_x;\n \
    \       S tmp_val = val;\n        update_tree_y(kx, ky, tmp_val);\n        for\
    \ (int i = 1; i <= height_x; i++) {\n            tmp_val = updated_x(kx >> i,\
    \ ky, kx >> (i - 1) & 1, tmp_val);\n            update_tree_y(kx >> i, ky, tmp_val);\n\
    \        }\n    }\n\n    S prod_y(int kx, int ly, int ry) {\n        S left_prod\
    \ = e(), right_prod = e();\n        ly += sz_y;\n        ry += sz_y;\n       \
    \ auto itr = y_indices[kx].end();\n        while (ly < ry) {\n            if (ry\
    \ & 1) {\n                --ry;\n                itr = std::lower_bound(y_indices[kx].begin(),\
    \ itr, ry);\n                right_prod = op(data_compressed[kx][itr - y_indices[kx].begin()],\
    \ right_prod);\n            }\n            if (ly & 1) {\n                itr\
    \ = std::lower_bound(y_indices[kx].begin(), itr, ly);\n                left_prod\
    \ = op(left_prod, data_compressed[kx][itr - y_indices[kx].begin()]);\n       \
    \         ++ly;\n            }\n            ly >>= 1;\n            ry >>= 1;\n\
    \        }\n        return op(left_prod, right_prod);\n    }\n\n    S prod_x(int\
    \ lx, int rx, int ly, int ry) {\n        S left_prod = e(), right_prod = e();\n\
    \        lx += sz_x;\n        rx += sz_x;\n        while (lx < rx) {\n       \
    \     if (lx & 1) {\n                left_prod = op(left_prod, prod_y(lx++, ly,\
    \ ry));\n            }\n            if (rx & 1) {\n                right_prod\
    \ = op(prod_y(--rx, ly, ry), right_prod);\n            }\n            lx >>= 1;\n\
    \            rx >>= 1;\n        }\n        return op(left_prod, right_prod);\n\
    \    }\n\n    void construct_data(const std::vector<std::tuple<int, int>>& set_query_indices,\
    \ const std::vector<std::tuple<int, int, int, int>>& prod_query_indices) {\n \
    \       sz_x = 1;\n        height_x = 0;\n        while (sz_x < h) {\n       \
    \     sz_x <<= 1;\n            ++height_x;\n        }\n        sz_y = 1;\n   \
    \     height_y = 0;\n        while (sz_y < w) {\n            sz_y <<= 1;\n   \
    \         ++height_y;\n        }\n        data_compressed.resize(sz_x * 2);\n\
    \        y_indices.resize(sz_x * 2);\n\n        for (auto [x, y] : set_query_indices)\
    \ {\n            x += sz_x;\n            std::vector<int> x_indices_tmp;\n   \
    \         for (int i = 0; i <= height_x; ++i) {\n                x_indices_tmp.push_back(x);\n\
    \                x >>= 1;\n            }\n            y += sz_y;\n           \
    \ std::vector<int> y_indices_tmp;\n            for (int i = 0; i <= height_y;\
    \ ++i) {\n                y_indices_tmp.push_back(y);\n                y >>= 1;\n\
    \            }\n            for (int x : x_indices_tmp) {\n                for\
    \ (int y : y_indices_tmp) {\n                    y_indices[x].push_back(y);\n\
    \                }\n            }\n        }\n        for (auto [lx, rx, ly, ry]\
    \ : prod_query_indices) {\n            std::vector<int> x_indices_tmp;\n     \
    \       lx += sz_x;\n            rx += sz_x;\n            while (lx < rx) {\n\
    \                if (lx & 1) x_indices_tmp.push_back(lx++);\n                if\
    \ (rx & 1) x_indices_tmp.push_back(--rx);\n                lx >>= 1;\n       \
    \         rx >>= 1;\n            }\n            ly += sz_y;\n            ry +=\
    \ sz_y;\n            std::vector<int> y_indices_tmp;\n            while (ly <\
    \ ry) {\n                if (ly & 1) y_indices_tmp.push_back(ly++);\n        \
    \        if (ry & 1) y_indices_tmp.push_back(--ry);\n                ly >>= 1;\n\
    \                ry >>= 1;\n            }\n            for (int x : x_indices_tmp)\
    \ {\n                for (int y : y_indices_tmp) {\n                    y_indices[x].push_back(y);\n\
    \                }\n            }\n        }\n\n        for (int x = 1; x < sz_x\
    \ * 2; x++) {\n            std::sort(y_indices[x].begin(), y_indices[x].end());\n\
    \            y_indices[x].erase(std::unique(y_indices[x].begin(), y_indices[x].end()),\
    \ y_indices[x].end());\n        }\n        for (int i = 1; i < sz_x * 2; ++i)\
    \ {\n            data_compressed[i].assign(y_indices[i].size(), e());\n      \
    \  }\n    }\n\n   public:\n    SegTree2D() = default;\n    /**\n     * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param h x\u5EA7\u6A19\
    \u306E\u7BC4\u56F2 [0, h)\n     * @param w y\u5EA7\u6A19\u306E\u7BC4\u56F2 [0,\
    \ w)\n     * @param set_query_indices set/apply \u3059\u308B\u5EA7\u6A19 (x, y)\
    \ \u306E\u5217\n     * @param prod_query_indices prod \u3059\u308B\u7BC4\u56F2\
    \ (lx, rx, ly, ry) \u306E\u5217\n     * @param m \u30E2\u30CE\u30A4\u30C9\n  \
    \   */\n    explicit SegTree2D(int h, int w, const std::vector<std::tuple<int,\
    \ int>>& set_query_indices, const std::vector<std::tuple<int, int, int, int>>&\
    \ prod_query_indices, M m = M())\n        : m(std::move(m)), h(h), w(w) {\n  \
    \      construct_data(set_query_indices, prod_query_indices);\n    }\n\n    /**\n\
    \     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\
    \u3059\n     * @param kx x\u5EA7\u6A19\n     * @param ky y\u5EA7\u6A19\n     *\
    \ @return \u8981\u7D20\u306E\u5024\n     */\n    S get(int kx, int ky) {\n   \
    \     assert(0 <= kx && kx < h && 0 <= ky && ky < w);\n        kx += sz_x;\n \
    \       return get_y(kx, ky);\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n  \
    \   * @param kx x\u5EA7\u6A19\n     * @param ky y\u5EA7\u6A19\n     * @param x\
    \ \u4EE3\u5165\u3059\u308B\u5024\n     */\n    void set(int kx, int ky, const\
    \ S& x) {\n        assert(0 <= kx && kx < h && 0 <= ky && ky < w);\n        update_tree_x(kx,\
    \ ky, x);\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\
    \u7D20\u306E\u5024\u306Bx\u3092\u4F5C\u7528\u3055\u305B\u308B\n     *\n     *\
    \ @param kx x\u5EA7\u6A19\n     * @param ky y\u5EA7\u6A19\n     * @param x \u4F5C\
    \u7528\u7D20\n     */\n    void apply(int kx, int ky, const S& x) {\n        set(kx,\
    \ ky, op(get(kx, ky), x));\n    }\n\n    /**\n     * @brief [lx, rx)x[ly, ry)\u306E\
    \u7BC4\u56F2\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n \
    \    * @param lx x\u5EA7\u6A19\u306E\u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \n     * @param rx x\u5EA7\u6A19\u306E\u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \n     * @param ly y\u5EA7\u6A19\u306E\u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \n     * @param ry y\u5EA7\u6A19\u306E\u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \n     */\n    S prod(int lx, int rx, int ly, int ry) {\n        assert(0 <= lx\
    \ && lx <= rx && rx <= h);\n        assert(0 <= ly && ly <= ry && ry <= w);\n\
    \        return prod_x(lx, rx, ly, ry);\n    }\n};\n\ntemplate <typename M>\n\
    SegTree2D(int, int, std::vector<std::tuple<int, int>>, std::vector<std::tuple<int,\
    \ int, int, int>>, M) -> SegTree2D<M>;\n\n/**\n * @brief RangeMaxQuery\n *\n *\
    \ @tparam S \u578B\n */\ntemplate <typename S>\nusing RMaxQ2D = SegTree2D<monoid::Max<S>>;\n\
    /**\n * @brief RangeMinQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RMinQ2D = SegTree2D<monoid::Min<S>>;\n/**\n * @brief RangeSumQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RSumQ2D = SegTree2D<monoid::Sum<S>>;\n"
  code: "#pragma once\n\n/**\n * @file segtree-2d.hpp\n * @brief 2\u6B21\u5143\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#include \"../algebra/monoid.hpp\"\
    \n\n/**\n * @brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u66F4\u65B0\
    \u30FB\u53D6\u5F97\u3059\u308B\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u3066\
    \u5727\u7E2E\u3059\u308B)\n *\n * @tparam M \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/monoid.hpp)\n */\ntemplate <typename M>\nclass SegTree2D {\n   public:\n\
    \    using S = typename M::S;\n\n   private:\n    M m;\n    S op(const S& a, const\
    \ S& b) const { return m.op(a, b); }\n    S e() const { return m.e(); }\n\n  \
    \  int h, w, sz_x, sz_y, height_x, height_y;\n    std::vector<std::vector<int>>\
    \ y_indices;\n    std::vector<std::vector<S>> data_compressed;\n\n    S get_y(int\
    \ kx, int ky) {\n        ky += sz_y;\n        auto it = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].end(), ky);\n        if (it == y_indices[kx].end() || *it != ky)\
    \ return e();\n        return data_compressed[kx][it - y_indices[kx].begin()];\n\
    \    }\n\n    S updated_y(int kx, int ky, int child_y_idx, bool child_y_right,\
    \ const S& child_val) {\n        if (!child_y_right && child_y_idx + 1 < (int)y_indices[kx].size()\
    \ && y_indices[kx][child_y_idx + 1] == ky * 2 + 1) {\n            return op(child_val,\
    \ data_compressed[kx][child_y_idx + 1]);\n        }\n        if (child_y_right\
    \ && child_y_idx - 1 >= 0 && y_indices[kx][child_y_idx - 1] == ky * 2) {\n   \
    \         return op(data_compressed[kx][child_y_idx - 1], child_val);\n      \
    \  }\n        return child_val;\n    }\n\n    void update_tree_y(int kx, int ky,\
    \ const S& val) {\n        ky += sz_y;\n        int y_idx = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].end(), ky) - y_indices[kx].begin();\n        S tmp_val = val;\n\
    \        data_compressed[kx][y_idx] = tmp_val;\n        for (int i = 1; i <= height_y;\
    \ i++) {\n            int child_y_idx = y_idx;\n            y_idx = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].begin() + child_y_idx, ky >> i) - y_indices[kx].begin();\n   \
    \         tmp_val = data_compressed[kx][y_idx] = updated_y(kx, ky >> i, child_y_idx,\
    \ ky >> (i - 1) & 1, tmp_val);\n        }\n    }\n\n    S updated_x(int kx, int\
    \ ky, bool child_x_right, const S& child_val) {\n        if (!child_x_right) {\n\
    \            return op(child_val, get_y(kx * 2 + 1, ky));\n        } else {\n\
    \            return op(get_y(kx * 2, ky), child_val);\n        }\n    }\n\n  \
    \  void update_tree_x(int kx, int ky, const S& val) {\n        kx += sz_x;\n \
    \       S tmp_val = val;\n        update_tree_y(kx, ky, tmp_val);\n        for\
    \ (int i = 1; i <= height_x; i++) {\n            tmp_val = updated_x(kx >> i,\
    \ ky, kx >> (i - 1) & 1, tmp_val);\n            update_tree_y(kx >> i, ky, tmp_val);\n\
    \        }\n    }\n\n    S prod_y(int kx, int ly, int ry) {\n        S left_prod\
    \ = e(), right_prod = e();\n        ly += sz_y;\n        ry += sz_y;\n       \
    \ auto itr = y_indices[kx].end();\n        while (ly < ry) {\n            if (ry\
    \ & 1) {\n                --ry;\n                itr = std::lower_bound(y_indices[kx].begin(),\
    \ itr, ry);\n                right_prod = op(data_compressed[kx][itr - y_indices[kx].begin()],\
    \ right_prod);\n            }\n            if (ly & 1) {\n                itr\
    \ = std::lower_bound(y_indices[kx].begin(), itr, ly);\n                left_prod\
    \ = op(left_prod, data_compressed[kx][itr - y_indices[kx].begin()]);\n       \
    \         ++ly;\n            }\n            ly >>= 1;\n            ry >>= 1;\n\
    \        }\n        return op(left_prod, right_prod);\n    }\n\n    S prod_x(int\
    \ lx, int rx, int ly, int ry) {\n        S left_prod = e(), right_prod = e();\n\
    \        lx += sz_x;\n        rx += sz_x;\n        while (lx < rx) {\n       \
    \     if (lx & 1) {\n                left_prod = op(left_prod, prod_y(lx++, ly,\
    \ ry));\n            }\n            if (rx & 1) {\n                right_prod\
    \ = op(prod_y(--rx, ly, ry), right_prod);\n            }\n            lx >>= 1;\n\
    \            rx >>= 1;\n        }\n        return op(left_prod, right_prod);\n\
    \    }\n\n    void construct_data(const std::vector<std::tuple<int, int>>& set_query_indices,\
    \ const std::vector<std::tuple<int, int, int, int>>& prod_query_indices) {\n \
    \       sz_x = 1;\n        height_x = 0;\n        while (sz_x < h) {\n       \
    \     sz_x <<= 1;\n            ++height_x;\n        }\n        sz_y = 1;\n   \
    \     height_y = 0;\n        while (sz_y < w) {\n            sz_y <<= 1;\n   \
    \         ++height_y;\n        }\n        data_compressed.resize(sz_x * 2);\n\
    \        y_indices.resize(sz_x * 2);\n\n        for (auto [x, y] : set_query_indices)\
    \ {\n            x += sz_x;\n            std::vector<int> x_indices_tmp;\n   \
    \         for (int i = 0; i <= height_x; ++i) {\n                x_indices_tmp.push_back(x);\n\
    \                x >>= 1;\n            }\n            y += sz_y;\n           \
    \ std::vector<int> y_indices_tmp;\n            for (int i = 0; i <= height_y;\
    \ ++i) {\n                y_indices_tmp.push_back(y);\n                y >>= 1;\n\
    \            }\n            for (int x : x_indices_tmp) {\n                for\
    \ (int y : y_indices_tmp) {\n                    y_indices[x].push_back(y);\n\
    \                }\n            }\n        }\n        for (auto [lx, rx, ly, ry]\
    \ : prod_query_indices) {\n            std::vector<int> x_indices_tmp;\n     \
    \       lx += sz_x;\n            rx += sz_x;\n            while (lx < rx) {\n\
    \                if (lx & 1) x_indices_tmp.push_back(lx++);\n                if\
    \ (rx & 1) x_indices_tmp.push_back(--rx);\n                lx >>= 1;\n       \
    \         rx >>= 1;\n            }\n            ly += sz_y;\n            ry +=\
    \ sz_y;\n            std::vector<int> y_indices_tmp;\n            while (ly <\
    \ ry) {\n                if (ly & 1) y_indices_tmp.push_back(ly++);\n        \
    \        if (ry & 1) y_indices_tmp.push_back(--ry);\n                ly >>= 1;\n\
    \                ry >>= 1;\n            }\n            for (int x : x_indices_tmp)\
    \ {\n                for (int y : y_indices_tmp) {\n                    y_indices[x].push_back(y);\n\
    \                }\n            }\n        }\n\n        for (int x = 1; x < sz_x\
    \ * 2; x++) {\n            std::sort(y_indices[x].begin(), y_indices[x].end());\n\
    \            y_indices[x].erase(std::unique(y_indices[x].begin(), y_indices[x].end()),\
    \ y_indices[x].end());\n        }\n        for (int i = 1; i < sz_x * 2; ++i)\
    \ {\n            data_compressed[i].assign(y_indices[i].size(), e());\n      \
    \  }\n    }\n\n   public:\n    SegTree2D() = default;\n    /**\n     * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param h x\u5EA7\u6A19\
    \u306E\u7BC4\u56F2 [0, h)\n     * @param w y\u5EA7\u6A19\u306E\u7BC4\u56F2 [0,\
    \ w)\n     * @param set_query_indices set/apply \u3059\u308B\u5EA7\u6A19 (x, y)\
    \ \u306E\u5217\n     * @param prod_query_indices prod \u3059\u308B\u7BC4\u56F2\
    \ (lx, rx, ly, ry) \u306E\u5217\n     * @param m \u30E2\u30CE\u30A4\u30C9\n  \
    \   */\n    explicit SegTree2D(int h, int w, const std::vector<std::tuple<int,\
    \ int>>& set_query_indices, const std::vector<std::tuple<int, int, int, int>>&\
    \ prod_query_indices, M m = M())\n        : m(std::move(m)), h(h), w(w) {\n  \
    \      construct_data(set_query_indices, prod_query_indices);\n    }\n\n    /**\n\
    \     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\
    \u3059\n     * @param kx x\u5EA7\u6A19\n     * @param ky y\u5EA7\u6A19\n     *\
    \ @return \u8981\u7D20\u306E\u5024\n     */\n    S get(int kx, int ky) {\n   \
    \     assert(0 <= kx && kx < h && 0 <= ky && ky < w);\n        kx += sz_x;\n \
    \       return get_y(kx, ky);\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\
    \u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n  \
    \   * @param kx x\u5EA7\u6A19\n     * @param ky y\u5EA7\u6A19\n     * @param x\
    \ \u4EE3\u5165\u3059\u308B\u5024\n     */\n    void set(int kx, int ky, const\
    \ S& x) {\n        assert(0 <= kx && kx < h && 0 <= ky && ky < w);\n        update_tree_x(kx,\
    \ ky, x);\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\
    \u7D20\u306E\u5024\u306Bx\u3092\u4F5C\u7528\u3055\u305B\u308B\n     *\n     *\
    \ @param kx x\u5EA7\u6A19\n     * @param ky y\u5EA7\u6A19\n     * @param x \u4F5C\
    \u7528\u7D20\n     */\n    void apply(int kx, int ky, const S& x) {\n        set(kx,\
    \ ky, op(get(kx, ky), x));\n    }\n\n    /**\n     * @brief [lx, rx)x[ly, ry)\u306E\
    \u7BC4\u56F2\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n     *\n \
    \    * @param lx x\u5EA7\u6A19\u306E\u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \n     * @param rx x\u5EA7\u6A19\u306E\u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \n     * @param ly y\u5EA7\u6A19\u306E\u534A\u958B\u533A\u9593\u306E\u958B\u59CB\
    \n     * @param ry y\u5EA7\u6A19\u306E\u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF\
    \n     */\n    S prod(int lx, int rx, int ly, int ry) {\n        assert(0 <= lx\
    \ && lx <= rx && rx <= h);\n        assert(0 <= ly && ly <= ry && ry <= w);\n\
    \        return prod_x(lx, rx, ly, ry);\n    }\n};\n\ntemplate <typename M>\n\
    SegTree2D(int, int, std::vector<std::tuple<int, int>>, std::vector<std::tuple<int,\
    \ int, int, int>>, M) -> SegTree2D<M>;\n\n/**\n * @brief RangeMaxQuery\n *\n *\
    \ @tparam S \u578B\n */\ntemplate <typename S>\nusing RMaxQ2D = SegTree2D<monoid::Max<S>>;\n\
    /**\n * @brief RangeMinQuery\n *\n * @tparam S \u578B\n */\ntemplate <typename\
    \ S>\nusing RMinQ2D = SegTree2D<monoid::Min<S>>;\n/**\n * @brief RangeSumQuery\n\
    \ *\n * @tparam S \u578B\n */\ntemplate <typename S>\nusing RSumQ2D = SegTree2D<monoid::Sum<S>>;\n"
  dependsOn:
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/data_structures/segtree-2d.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point-add-rectangle-sum.test.cpp
documentation_of: src/data_structures/segtree-2d.hpp
layout: document
title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

可換モノイド ([algebra/monoid.hpp](../algebra/monoid.hpp)) を乗せる2次元セグメント木です。更新する座標と取得する範囲をすべて先読みして、必要なノードだけを持ちます。

```cpp
std::vector<std::tuple<int, int>> sets = { {0, 1}, {2, 3} };        // set/apply する座標 (x, y)
std::vector<std::tuple<int, int, int, int>> prods = { {0, 3, 0, 4} }; // prod する範囲 (lx, rx, ly, ry)
RSumQ2D<long long> seg(3, 4, sets, prods);                         // x は [0, 3)、y は [0, 4)
seg.apply(0, 1, 5);
seg.apply(2, 3, 7);
seg.prod(0, 3, 0, 4);  // 12
```

座標が大きい場合は、先に座標圧縮してから使います。先読みしていない座標への `set`・`apply` や、先読みしていない範囲への `prod` の結果は保証されません。

## 別名

| 別名 | 実体 | 用途 |
|---|---|---|
| `RMaxQ2D<S>` | `SegTree2D<monoid::Max<S>>` | 矩形の最大値 |
| `RMinQ2D<S>` | `SegTree2D<monoid::Min<S>>` | 矩形の最小値 |
| `RSumQ2D<S>` | `SegTree2D<monoid::Sum<S>>` | 矩形和 |

## メンバ関数

$q$ を先読みしたクエリの数、$H$, $W$ を x, y 座標の範囲とします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SegTree2D(h, w, set_query_indices, prod_query_indices, m = M())` | x 座標 $[0, h)$、y 座標 $[0, w)$。すべて単位元で初期化 | $O(q \log H \log W \log q)$ |
| `get(x, y)` | $(x, y)$ の値 | $O(\log q)$ |
| `set(x, y, v)` | $(x, y)$ を `v` に更新 | $O(\log H \log W \log q)$ |
| `apply(x, y, v)` | $(x, y)$ を `op(get(x, y), v)` に更新 | $O(\log H \log W \log q)$ |
| `prod(lx, rx, ly, ry)` | $[l_x, r_x) \times [l_y, r_y)$ の積 | $O(\log H \log W \log q)$ |

## 関連

- 1次元なら [セグメント木](segtree.hpp)
- 更新がなく、点の重みの矩形和なら [マージソートツリー](merge-sort-tree.hpp) でも求められる
