---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-point-add-rectangle-sum.test.cpp
    title: test/yosupo-point-add-rectangle-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"src/data_structures/segtree-2d.hpp\"\n\n/**\n * @file segtree-2d.hpp\n\
    \ * @brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include\
    \ <algorithm>\n#include <tuple>\n#include <utility>\n#include <vector>\n#line\
    \ 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief \u30E2\u30CE\
    \u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\u6B21\u306E\
    \u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * -\
    \ using S: \u8981\u7D20\u306E\u578B\n * - S op(const S& a, const S& b): \u7A4D\
    \ (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n * op, e \u306F static\
    \ \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\u30FC\u30BF\u69CB\
    \u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\n#line 15 \"src/algebra/monoid.hpp\"\
    \n#include <limits>\n#include <numeric>\n#include <type_traits>\n#line 19 \"src/algebra/monoid.hpp\"\
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
    \ Op, typename T>\nMonoid(Op, T) -> Monoid<T, Op>;\n#line 13 \"src/data_structures/segtree-2d.hpp\"\
    \n\n/**\n * @brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u66F4\u65B0\
    \u30FB\u53D6\u5F97\u3059\u308B\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u3066\
    \u5727\u7E2E\u3059\u308B)\n *\n * @tparam M \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/monoid.hpp)\n */\ntemplate <typename M>\nclass SegTree2D {\npublic:\n\
    \    using S = typename M::S;\n\nprivate:\n    M m;\n    S op(const S& a, const\
    \ S& b) const { return m.op(a, b); }\n    S e() const { return m.e(); }\n\n  \
    \  int h, w, sz_x, sz_y, height_x, height_y;\n    std::vector<std::vector<int>>\
    \ y_indices;\n    std::vector<std::vector<S>> data_compressed;\n\n    S get_y(int\
    \ kx, int ky) {\n        ky += sz_y;\n        auto it = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].end(), ky);\n        if(it == y_indices[kx].end() || *it != ky)\
    \ return e();\n        return data_compressed[kx][it - y_indices[kx].begin()];\n\
    \    }\n\n    S updated_y(int kx, int ky, int child_y_idx, bool child_y_right,\
    \ const S& child_val) {\n        if(!child_y_right && child_y_idx+1 < (int)y_indices[kx].size()\
    \ && y_indices[kx][child_y_idx+1] == ky*2+1) {\n            return op(child_val,\
    \ data_compressed[kx][child_y_idx+1]);\n        }\n        if(child_y_right &&\
    \ child_y_idx-1 >= 0 && y_indices[kx][child_y_idx-1] == ky*2) {\n            return\
    \ op(data_compressed[kx][child_y_idx-1], child_val);\n        }\n        return\
    \ child_val;\n    }\n\n    void update_tree_y(int kx, int ky, const S& val) {\n\
    \        ky += sz_y;\n        int y_idx = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].end(), ky) - y_indices[kx].begin();\n        S tmp_val = val;\n\
    \        data_compressed[kx][y_idx] = tmp_val;\n        for(int i = 1; i <= height_y;\
    \ i++) {\n            int child_y_idx = y_idx;\n            y_idx = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].begin() + child_y_idx, ky >> i) - y_indices[kx].begin();\n   \
    \         tmp_val = data_compressed[kx][y_idx] = updated_y(kx, ky >> i, child_y_idx,\
    \ ky>>(i-1)&1, tmp_val);\n        }\n    }\n\n    S updated_x(int kx, int ky,\
    \ bool child_x_right, const S& child_val) {\n        if(!child_x_right) {\n  \
    \          return op(child_val, get_y(kx*2+1, ky));\n        } else {\n      \
    \      return op(get_y(kx*2, ky), child_val);\n        }\n    }\n\n    void update_tree_x(int\
    \ kx, int ky, const S& val) {\n        kx += sz_x;\n        S tmp_val = val;\n\
    \        update_tree_y(kx, ky, tmp_val);\n        for(int i = 1; i <= height_x;\
    \ i++) {\n            tmp_val = updated_x(kx >> i, ky, kx>>(i-1)&1, tmp_val);\n\
    \            update_tree_y(kx >> i, ky, tmp_val);\n        }\n    }\n\n    S prod_y(int\
    \ kx, int ly, int ry) {\n        S left_prod = e(), right_prod = e();\n      \
    \  ly += sz_y; ry += sz_y;\n        auto itr = y_indices[kx].end();\n        while(ly\
    \ < ry) {\n            if(ry & 1) {\n                --ry;\n                itr\
    \ = std::lower_bound(y_indices[kx].begin(), itr, ry);\n                right_prod\
    \ = op(data_compressed[kx][itr - y_indices[kx].begin()], right_prod);\n      \
    \      }\n            if(ly & 1) {\n                itr = std::lower_bound(y_indices[kx].begin(),\
    \ itr, ly);\n                left_prod = op(left_prod, data_compressed[kx][itr\
    \ - y_indices[kx].begin()]);\n                ++ly;\n            }\n         \
    \   ly >>= 1; ry >>= 1;\n        }\n        return op(left_prod, right_prod);\n\
    \    }\n\n    S prod_x(int lx, int rx, int ly, int ry) {\n        S left_prod\
    \ = e(), right_prod = e();\n        lx += sz_x; rx += sz_x;\n        while(lx\
    \ < rx) {\n            if(lx & 1) {\n                left_prod = op(left_prod,\
    \ prod_y(lx++, ly, ry));\n            }\n            if(rx & 1) {\n          \
    \      right_prod = op(prod_y(--rx, ly, ry), right_prod);\n            }\n   \
    \         lx >>= 1; rx >>= 1;\n        }\n        return op(left_prod, right_prod);\n\
    \    }\n\n    void construct_data(const std::vector<std::tuple<int, int>>& set_query_indices,\
    \ const std::vector<std::tuple<int, int, int, int>>& prod_query_indices) {\n \
    \       sz_x = 1; height_x = 0;\n        while(sz_x < h) { sz_x <<= 1; ++height_x;\
    \ }\n        sz_y = 1; height_y = 0;\n        while(sz_y < w) { sz_y <<= 1; ++height_y;\
    \ }\n        data_compressed.resize(sz_x*2);\n        y_indices.resize(sz_x*2);\n\
    \n        for(auto [x, y] : set_query_indices) {\n            x += sz_x;\n   \
    \         std::vector<int> x_indices_tmp;\n            for(int i = 0; i <= height_x;\
    \ ++i) {\n                x_indices_tmp.push_back(x);\n                x >>= 1;\n\
    \            }\n            y += sz_y;\n            std::vector<int> y_indices_tmp;\n\
    \            for(int i = 0; i <= height_y; ++i) {\n                y_indices_tmp.push_back(y);\n\
    \                y >>= 1;\n            }\n            for(int x : x_indices_tmp)\
    \ {\n                for(int y : y_indices_tmp) {\n                    y_indices[x].push_back(y);\n\
    \                }\n            }\n        }\n        for(auto [lx, rx, ly, ry]\
    \ : prod_query_indices) {\n            std::vector<int> x_indices_tmp;\n     \
    \       lx += sz_x; rx += sz_x;\n            while(lx < rx) {\n              \
    \  if(lx & 1) x_indices_tmp.push_back(lx++);\n                if(rx & 1) x_indices_tmp.push_back(--rx);\n\
    \                lx >>= 1; rx >>= 1;\n            }\n            ly += sz_y; ry\
    \ += sz_y;\n            std::vector<int> y_indices_tmp;\n            while(ly\
    \ < ry) {\n                if(ly & 1) y_indices_tmp.push_back(ly++);\n       \
    \         if(ry & 1) y_indices_tmp.push_back(--ry);\n                ly >>= 1;\
    \ ry >>= 1;\n            }\n            for(int x : x_indices_tmp) {\n       \
    \         for(int y : y_indices_tmp) {\n                    y_indices[x].push_back(y);\n\
    \                }\n            }\n        }\n\n        for(int x = 1; x < sz_x*2;\
    \ x++) {\n            std::sort(y_indices[x].begin(), y_indices[x].end());\n \
    \           y_indices[x].erase(std::unique(y_indices[x].begin(), y_indices[x].end()),\
    \ y_indices[x].end());\n        }\n        for(int i = 1; i < sz_x*2; ++i) {\n\
    \            data_compressed[i].assign(y_indices[i].size(), e());\n        }\n\
    \    }\n\npublic:\n    SegTree2D() = default;\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param h x\u5EA7\u6A19\u306E\u7BC4\
    \u56F2 [0, h)\n     * @param w y\u5EA7\u6A19\u306E\u7BC4\u56F2 [0, w)\n     *\
    \ @param set_query_indices set/apply \u3059\u308B\u5EA7\u6A19 (x, y) \u306E\u5217\
    \n     * @param prod_query_indices prod \u3059\u308B\u7BC4\u56F2 (lx, rx, ly,\
    \ ry) \u306E\u5217\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ SegTree2D(int h, int w, const std::vector<std::tuple<int, int>>& set_query_indices,\
    \ const std::vector<std::tuple<int, int, int, int>>& prod_query_indices, M m =\
    \ M())\n        : m(std::move(m)), h(h), w(w) {\n        construct_data(set_query_indices,\
    \ prod_query_indices);\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     * @param kx x\u5EA7\u6A19\
    \n     * @param ky y\u5EA7\u6A19\n     * @return \u8981\u7D20\u306E\u5024\n  \
    \   */\n    S get(int kx, int ky) {\n        kx += sz_x;\n        return get_y(kx,\
    \ ky);\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\
    \u306E\u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n     * @param kx x\u5EA7\u6A19\
    \n     * @param ky y\u5EA7\u6A19\n     * @param x \u4EE3\u5165\u3059\u308B\u5024\
    \n     */\n    void set(int kx, int ky, const S& x) {\n        update_tree_x(kx,\
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
    \n     */\n    S prod(int lx, int rx, int ly, int ry) {\n        return prod_x(lx,\
    \ rx, ly, ry);\n    }\n};\n\ntemplate <typename M>\nSegTree2D(int, int, std::vector<std::tuple<int,\
    \ int>>, std::vector<std::tuple<int, int, int, int>>, M) -> SegTree2D<M>;\n"
  code: "#pragma once\n\n/**\n * @file segtree-2d.hpp\n * @brief 2\u6B21\u5143\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include <algorithm>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n#include \"../algebra/monoid.hpp\"\n\n\
    /**\n * @brief 2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u66F4\u65B0\
    \u30FB\u53D6\u5F97\u3059\u308B\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u3066\
    \u5727\u7E2E\u3059\u308B)\n *\n * @tparam M \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\
    \ (algebra/monoid.hpp)\n */\ntemplate <typename M>\nclass SegTree2D {\npublic:\n\
    \    using S = typename M::S;\n\nprivate:\n    M m;\n    S op(const S& a, const\
    \ S& b) const { return m.op(a, b); }\n    S e() const { return m.e(); }\n\n  \
    \  int h, w, sz_x, sz_y, height_x, height_y;\n    std::vector<std::vector<int>>\
    \ y_indices;\n    std::vector<std::vector<S>> data_compressed;\n\n    S get_y(int\
    \ kx, int ky) {\n        ky += sz_y;\n        auto it = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].end(), ky);\n        if(it == y_indices[kx].end() || *it != ky)\
    \ return e();\n        return data_compressed[kx][it - y_indices[kx].begin()];\n\
    \    }\n\n    S updated_y(int kx, int ky, int child_y_idx, bool child_y_right,\
    \ const S& child_val) {\n        if(!child_y_right && child_y_idx+1 < (int)y_indices[kx].size()\
    \ && y_indices[kx][child_y_idx+1] == ky*2+1) {\n            return op(child_val,\
    \ data_compressed[kx][child_y_idx+1]);\n        }\n        if(child_y_right &&\
    \ child_y_idx-1 >= 0 && y_indices[kx][child_y_idx-1] == ky*2) {\n            return\
    \ op(data_compressed[kx][child_y_idx-1], child_val);\n        }\n        return\
    \ child_val;\n    }\n\n    void update_tree_y(int kx, int ky, const S& val) {\n\
    \        ky += sz_y;\n        int y_idx = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].end(), ky) - y_indices[kx].begin();\n        S tmp_val = val;\n\
    \        data_compressed[kx][y_idx] = tmp_val;\n        for(int i = 1; i <= height_y;\
    \ i++) {\n            int child_y_idx = y_idx;\n            y_idx = std::lower_bound(y_indices[kx].begin(),\
    \ y_indices[kx].begin() + child_y_idx, ky >> i) - y_indices[kx].begin();\n   \
    \         tmp_val = data_compressed[kx][y_idx] = updated_y(kx, ky >> i, child_y_idx,\
    \ ky>>(i-1)&1, tmp_val);\n        }\n    }\n\n    S updated_x(int kx, int ky,\
    \ bool child_x_right, const S& child_val) {\n        if(!child_x_right) {\n  \
    \          return op(child_val, get_y(kx*2+1, ky));\n        } else {\n      \
    \      return op(get_y(kx*2, ky), child_val);\n        }\n    }\n\n    void update_tree_x(int\
    \ kx, int ky, const S& val) {\n        kx += sz_x;\n        S tmp_val = val;\n\
    \        update_tree_y(kx, ky, tmp_val);\n        for(int i = 1; i <= height_x;\
    \ i++) {\n            tmp_val = updated_x(kx >> i, ky, kx>>(i-1)&1, tmp_val);\n\
    \            update_tree_y(kx >> i, ky, tmp_val);\n        }\n    }\n\n    S prod_y(int\
    \ kx, int ly, int ry) {\n        S left_prod = e(), right_prod = e();\n      \
    \  ly += sz_y; ry += sz_y;\n        auto itr = y_indices[kx].end();\n        while(ly\
    \ < ry) {\n            if(ry & 1) {\n                --ry;\n                itr\
    \ = std::lower_bound(y_indices[kx].begin(), itr, ry);\n                right_prod\
    \ = op(data_compressed[kx][itr - y_indices[kx].begin()], right_prod);\n      \
    \      }\n            if(ly & 1) {\n                itr = std::lower_bound(y_indices[kx].begin(),\
    \ itr, ly);\n                left_prod = op(left_prod, data_compressed[kx][itr\
    \ - y_indices[kx].begin()]);\n                ++ly;\n            }\n         \
    \   ly >>= 1; ry >>= 1;\n        }\n        return op(left_prod, right_prod);\n\
    \    }\n\n    S prod_x(int lx, int rx, int ly, int ry) {\n        S left_prod\
    \ = e(), right_prod = e();\n        lx += sz_x; rx += sz_x;\n        while(lx\
    \ < rx) {\n            if(lx & 1) {\n                left_prod = op(left_prod,\
    \ prod_y(lx++, ly, ry));\n            }\n            if(rx & 1) {\n          \
    \      right_prod = op(prod_y(--rx, ly, ry), right_prod);\n            }\n   \
    \         lx >>= 1; rx >>= 1;\n        }\n        return op(left_prod, right_prod);\n\
    \    }\n\n    void construct_data(const std::vector<std::tuple<int, int>>& set_query_indices,\
    \ const std::vector<std::tuple<int, int, int, int>>& prod_query_indices) {\n \
    \       sz_x = 1; height_x = 0;\n        while(sz_x < h) { sz_x <<= 1; ++height_x;\
    \ }\n        sz_y = 1; height_y = 0;\n        while(sz_y < w) { sz_y <<= 1; ++height_y;\
    \ }\n        data_compressed.resize(sz_x*2);\n        y_indices.resize(sz_x*2);\n\
    \n        for(auto [x, y] : set_query_indices) {\n            x += sz_x;\n   \
    \         std::vector<int> x_indices_tmp;\n            for(int i = 0; i <= height_x;\
    \ ++i) {\n                x_indices_tmp.push_back(x);\n                x >>= 1;\n\
    \            }\n            y += sz_y;\n            std::vector<int> y_indices_tmp;\n\
    \            for(int i = 0; i <= height_y; ++i) {\n                y_indices_tmp.push_back(y);\n\
    \                y >>= 1;\n            }\n            for(int x : x_indices_tmp)\
    \ {\n                for(int y : y_indices_tmp) {\n                    y_indices[x].push_back(y);\n\
    \                }\n            }\n        }\n        for(auto [lx, rx, ly, ry]\
    \ : prod_query_indices) {\n            std::vector<int> x_indices_tmp;\n     \
    \       lx += sz_x; rx += sz_x;\n            while(lx < rx) {\n              \
    \  if(lx & 1) x_indices_tmp.push_back(lx++);\n                if(rx & 1) x_indices_tmp.push_back(--rx);\n\
    \                lx >>= 1; rx >>= 1;\n            }\n            ly += sz_y; ry\
    \ += sz_y;\n            std::vector<int> y_indices_tmp;\n            while(ly\
    \ < ry) {\n                if(ly & 1) y_indices_tmp.push_back(ly++);\n       \
    \         if(ry & 1) y_indices_tmp.push_back(--ry);\n                ly >>= 1;\
    \ ry >>= 1;\n            }\n            for(int x : x_indices_tmp) {\n       \
    \         for(int y : y_indices_tmp) {\n                    y_indices[x].push_back(y);\n\
    \                }\n            }\n        }\n\n        for(int x = 1; x < sz_x*2;\
    \ x++) {\n            std::sort(y_indices[x].begin(), y_indices[x].end());\n \
    \           y_indices[x].erase(std::unique(y_indices[x].begin(), y_indices[x].end()),\
    \ y_indices[x].end());\n        }\n        for(int i = 1; i < sz_x*2; ++i) {\n\
    \            data_compressed[i].assign(y_indices[i].size(), e());\n        }\n\
    \    }\n\npublic:\n    SegTree2D() = default;\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param h x\u5EA7\u6A19\u306E\u7BC4\
    \u56F2 [0, h)\n     * @param w y\u5EA7\u6A19\u306E\u7BC4\u56F2 [0, w)\n     *\
    \ @param set_query_indices set/apply \u3059\u308B\u5EA7\u6A19 (x, y) \u306E\u5217\
    \n     * @param prod_query_indices prod \u3059\u308B\u7BC4\u56F2 (lx, rx, ly,\
    \ ry) \u306E\u5217\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ SegTree2D(int h, int w, const std::vector<std::tuple<int, int>>& set_query_indices,\
    \ const std::vector<std::tuple<int, int, int, int>>& prod_query_indices, M m =\
    \ M())\n        : m(std::move(m)), h(h), w(w) {\n        construct_data(set_query_indices,\
    \ prod_query_indices);\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     * @param kx x\u5EA7\u6A19\
    \n     * @param ky y\u5EA7\u6A19\n     * @return \u8981\u7D20\u306E\u5024\n  \
    \   */\n    S get(int kx, int ky) {\n        kx += sz_x;\n        return get_y(kx,\
    \ ky);\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\
    \u306E\u5024\u3092x\u306B\u66F4\u65B0\u3059\u308B\n     * @param kx x\u5EA7\u6A19\
    \n     * @param ky y\u5EA7\u6A19\n     * @param x \u4EE3\u5165\u3059\u308B\u5024\
    \n     */\n    void set(int kx, int ky, const S& x) {\n        update_tree_x(kx,\
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
    \n     */\n    S prod(int lx, int rx, int ly, int ry) {\n        return prod_x(lx,\
    \ rx, ly, ry);\n    }\n};\n\ntemplate <typename M>\nSegTree2D(int, int, std::vector<std::tuple<int,\
    \ int>>, std::vector<std::tuple<int, int, int, int>>, M) -> SegTree2D<M>;\n"
  dependsOn:
  - src/algebra/monoid.hpp
  isVerificationFile: false
  path: src/data_structures/segtree-2d.hpp
  requiredBy: []
  timestamp: '2026-10-11 23:34:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-point-add-rectangle-sum.test.cpp
documentation_of: src/data_structures/segtree-2d.hpp
layout: document
redirect_from:
- /library/src/data_structures/segtree-2d.hpp
- /library/src/data_structures/segtree-2d.hpp.html
title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
