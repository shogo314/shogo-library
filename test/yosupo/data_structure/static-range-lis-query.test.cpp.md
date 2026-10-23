---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/range-lis.hpp
    title: "\u533A\u9593\u306E\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/wavelet-matrix.hpp
    title: Wavelet Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_lis_query
    links:
    - https://judge.yosupo.jp/problem/static_range_lis_query
  bundledCode: "#line 1 \"test/yosupo/data_structure/static-range-lis-query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_lis_query\"\n\
    \n#include <iostream>\n#include <vector>\n\n#line 2 \"src/data_structures/range-lis.hpp\"\
    \n\n/**\n * @file range-lis.hpp\n * @brief \u533A\u9593\u306E\u6700\u9577\u5897\
    \u52A0\u90E8\u5206\u5217\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <numeric>\n#include <utility>\n#line 13 \"src/data_structures/range-lis.hpp\"\
    \n\n#line 2 \"src/data_structures/wavelet-matrix.hpp\"\n\n/**\n * @file wavelet-matrix.hpp\n\
    \ * @brief Wavelet Matrix\n */\n\n#line 10 \"src/data_structures/wavelet-matrix.hpp\"\
    \n#include <optional>\n#include <type_traits>\n#line 14 \"src/data_structures/wavelet-matrix.hpp\"\
    \n\nnamespace internal_wavelet_matrix {\n/**\n * @brief 0 \u3068 1 \u306E\u5217\
    \u3067\u3001\u3042\u308B\u4F4D\u7F6E\u3088\u308A\u524D\u306E 1 \u306E\u500B\u6570\
    \u3092 O(1) \u3067\u6C42\u3081\u308B\n */\nclass BitVector {\n    std::vector<unsigned\
    \ long long> bits;\n    std::vector<int> count;  // count[i] \u306F i * 64 \u30D3\
    \u30C3\u30C8\u76EE\u3088\u308A\u524D\u306E 1 \u306E\u500B\u6570\n\n   public:\n\
    \    BitVector() = default;\n    explicit BitVector(int n) : bits(n / 64 + 1),\
    \ count(n / 64 + 2) {}\n    void set(int i) { bits[i >> 6] |= 1ULL << (i & 63);\
    \ }\n    void build() {\n        for (int i = 0; i < static_cast<int>(bits.size());\
    \ i++) count[i + 1] = count[i] + __builtin_popcountll(bits[i]);\n    }\n    bool\
    \ get(int i) const { return bits[i >> 6] >> (i & 63) & 1; }\n    // [0, i) \u306E\
    \ 1 \u306E\u500B\u6570\n    int rank1(int i) const { return count[i >> 6] + __builtin_popcountll(bits[i\
    \ >> 6] & ((1ULL << (i & 63)) - 1)); }\n    // [0, i) \u306E 0 \u306E\u500B\u6570\
    \n    int rank0(int i) const { return i - rank1(i); }\n};\n}  // namespace internal_wavelet_matrix\n\
    \n/**\n * @brief Wavelet Matrix\n *\n * \u9759\u7684\u306A\u5217\u306B\u5BFE\u3057\
    \u3066\u3001\u533A\u9593\u306E k \u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3084\
    \u3001\u533A\u9593\u5185\u3067\u5024\u304C [lower, upper) \u306B\u3042\u308B\u8981\
    \u7D20\u306E\u500B\u6570\u3092 O(log \u03C3) \u3067\u6C42\u3081\u308B\n * \u5024\
    \u306F\u5EA7\u6A19\u5727\u7E2E\u3057\u3066\u6301\u3064\u306E\u3067\u3001\u8CA0\
    \u306E\u5024\u3084\u5927\u304D\u3044\u5024\u3082\u305D\u306E\u307E\u307E\u4F7F\
    \u3048\u308B (\u03C3 \u306F\u5024\u306E\u7A2E\u985E\u6570)\n * \u4F8B:\n * WaveletMatrix\
    \ wm(std::vector<long long>{3, 1, 4, 1, 5});\n * wm.kth_smallest(1, 4, 0);  //\
    \ 1 ([1, 4, 1] \u306E 0 \u756A\u76EE)\n * wm.count(0, 5, 2, 5);      // 2 (3 \u3068\
    \ 4)\n *\n * @tparam T \u5024\u306E\u578B (< \u3067\u6BD4\u8F03\u3067\u304D\u308B\
    \u3053\u3068)\n */\ntemplate <typename T>\nclass WaveletMatrix {\n   protected:\n\
    \    int n, height;\n    std::vector<T> vals;  // \u5EA7\u6A19\u5727\u7E2E\u3057\
    \u305F\u5024 (\u6607\u9806)\n    // bv[d] \u306F\u4E0A\u304B\u3089 d \u756A\u76EE\
    \u306E\u6BB5 (\u30D3\u30C3\u30C8 height - 1 - d) \u306E\u5217\u3001mid[d] \u306F\
    \u305D\u306E\u6BB5\u306E 0 \u306E\u500B\u6570\n    std::vector<internal_wavelet_matrix::BitVector>\
    \ bv;\n    std::vector<int> mid;\n\n    // v \u672A\u6E80\u306E\u5024\u306E\u5727\
    \u7E2E\u5F8C\u306E\u756A\u53F7\n    int compressed_lower(const T& v) const { return\
    \ std::lower_bound(vals.begin(), vals.end(), v) - vals.begin(); }\n    // \u533A\
    \u9593 [l, r) \u3092 1 \u6BB5\u4E0B\u306E\u30010 \u5074\u307E\u305F\u306F 1 \u5074\
    \u306E\u533A\u9593\u306B\u79FB\u3059\n    std::pair<int, int> down(int d, int\
    \ l, int r, bool b) const {\n        if (b) return {mid[d] + bv[d].rank1(l), mid[d]\
    \ + bv[d].rank1(r)};\n        return {bv[d].rank0(l), bv[d].rank0(r)};\n    }\n\
    \    // [l, r) \u306E\u3001\u5727\u7E2E\u5F8C\u306E\u756A\u53F7\u304C c \u672A\
    \u6E80\u306E\u8981\u7D20\u306E\u500B\u6570\n    int count_less(int l, int r, int\
    \ c) const {\n        int res = 0;\n        for (int d = 0; d < height; d++) {\n\
    \            bool b = c >> (height - 1 - d) & 1;\n            if (b) res += bv[d].rank0(r)\
    \ - bv[d].rank0(l);\n            std::tie(l, r) = down(d, l, r, b);\n        }\n\
    \        return res;\n    }\n    // [l, r) \u306E k \u756A\u76EE (0-indexed) \u306B\
    \u5C0F\u3055\u3044\u5024\u306E\u5727\u7E2E\u5F8C\u306E\u756A\u53F7\n    int kth_compressed(int\
    \ l, int r, int k) const {\n        int res = 0;\n        for (int d = 0; d <\
    \ height; d++) {\n            int zeros = bv[d].rank0(r) - bv[d].rank0(l);\n \
    \           bool b = k >= zeros;\n            if (b) {\n                k -= zeros;\n\
    \                res |= 1 << (height - 1 - d);\n            }\n            std::tie(l,\
    \ r) = down(d, l, r, b);\n        }\n        return res;\n    }\n\n   public:\n\
    \    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n \
    \    * @param v \u5217\n     */\n    explicit WaveletMatrix(const std::vector<T>&\
    \ v = {}) : n(v.size()), vals(v) {\n        std::sort(vals.begin(), vals.end());\n\
    \        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());\n    \
    \    // \u5727\u7E2E\u5F8C\u306E\u756A\u53F7 0, ..., vals.size() \u306F\u3059\u3079\
    \u3066 height \u30D3\u30C3\u30C8\u3067\u8868\u305B\u308B\u3088\u3046\u306B\u3059\
    \u308B\n        height = 1;\n        while ((1LL << height) <= static_cast<long\
    \ long>(vals.size())) height++;\n        std::vector<int> cur(n), nxt(n);\n  \
    \      for (int i = 0; i < n; i++) cur[i] = compressed_lower(v[i]);\n        bv.assign(height,\
    \ internal_wavelet_matrix::BitVector(n));\n        mid.assign(height, 0);\n  \
    \      for (int d = 0; d < height; d++) {\n            int h = height - 1 - d;\n\
    \            for (int i = 0; i < n; i++) {\n                if (cur[i] >> h &\
    \ 1) bv[d].set(i);\n            }\n            bv[d].build();\n            mid[d]\
    \ = bv[d].rank0(n);\n            // 0 \u306E\u8981\u7D20\u3092\u524D\u306B\u3001\
    1 \u306E\u8981\u7D20\u3092\u5F8C\u308D\u306B\u3001\u9806\u5E8F\u3092\u4FDD\u3063\
    \u3066\u4E26\u3079\u308B\n            int zero = 0, one = mid[d];\n          \
    \  for (int i = 0; i < n; i++) {\n                if (cur[i] >> h & 1)\n     \
    \               nxt[one++] = cur[i];\n                else\n                 \
    \   nxt[zero++] = cur[i];\n            }\n            std::swap(cur, nxt);\n \
    \       }\n    }\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\
    \n     */\n    long long size() const { return n; }\n\n    /**\n     * @brief\
    \ k \u756A\u76EE\u306E\u5024\u3092\u8FD4\u3059\n     */\n    T get(long long k)\
    \ const {\n        assert(0 <= k && k < n);\n        int i = k, c = 0;\n     \
    \   for (int d = 0; d < height; d++) {\n            bool b = bv[d].get(i);\n \
    \           if (b) c |= 1 << (height - 1 - d);\n            i = b ? mid[d] + bv[d].rank1(i)\
    \ : bv[d].rank0(i);\n        }\n        return vals[c];\n    }\n    /**\n    \
    \ * @brief k \u756A\u76EE\u306E\u5024\u3092\u8FD4\u3059\n     */\n    T operator[](long\
    \ long k) const { return get(k); }\n\n    /**\n     * @brief [l, r) \u306E\u8981\
    \u7D20\u3092\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3079\u305F\u3068\u304D\u306E\
    \ k \u756A\u76EE (0-indexed) \u306E\u5024\u3092\u8FD4\u3059\n     */\n    T kth_smallest(long\
    \ long l, long long r, long long k) const {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        assert(0 <= k && k < r - l);\n        return vals[kth_compressed(l,\
    \ r, k)];\n    }\n    /**\n     * @brief [l, r) \u306E\u8981\u7D20\u3092\u5927\
    \u304D\u3044\u9806\u306B\u4E26\u3079\u305F\u3068\u304D\u306E k \u756A\u76EE (0-indexed)\
    \ \u306E\u5024\u3092\u8FD4\u3059\n     */\n    T kth_largest(long long l, long\
    \ long r, long long k) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        assert(0 <= k && k < r - l);\n        return kth_smallest(l, r, r - l\
    \ - 1 - k);\n    }\n\n    /**\n     * @brief [l, r) \u306E\u8981\u7D20\u306E\u3046\
    \u3061\u3001\u5024\u304C x \u306E\u3082\u306E\u306E\u500B\u6570\u3092\u8FD4\u3059\
    \n     */\n    long long count(long long l, long long r, const T& x) const {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        int c = compressed_lower(x);\n\
    \        if (c == static_cast<int>(vals.size()) || x < vals[c]) return 0;\n  \
    \      return count_less(l, r, c + 1) - count_less(l, r, c);\n    }\n    /**\n\
    \     * @brief [l, r) \u306E\u8981\u7D20\u306E\u3046\u3061\u3001\u5024\u304C [lower,\
    \ upper) \u306B\u3042\u308B\u3082\u306E\u306E\u500B\u6570\u3092\u8FD4\u3059\n\
    \     */\n    long long count(long long l, long long r, const T& lower, const\
    \ T& upper) const {\n        assert(0 <= l && l <= r && r <= n);\n        if (!(lower\
    \ < upper)) return 0;\n        return count_less(l, r, compressed_lower(upper))\
    \ - count_less(l, r, compressed_lower(lower));\n    }\n\n    /**\n     * @brief\
    \ [l, r) \u306E\u8981\u7D20\u306E\u3046\u3061\u3001upper \u672A\u6E80\u3067\u6700\
    \u5927\u306E\u5024\u3092\u8FD4\u3059 (\u306A\u3051\u308C\u3070 std::nullopt)\n\
    \     */\n    std::optional<T> prev_value(long long l, long long r, const T& upper)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        int cnt = count_less(l,\
    \ r, compressed_lower(upper));\n        if (cnt == 0) return std::nullopt;\n \
    \       return vals[kth_compressed(l, r, cnt - 1)];\n    }\n    /**\n     * @brief\
    \ [l, r) \u306E\u8981\u7D20\u306E\u3046\u3061\u3001lower \u4EE5\u4E0A\u3067\u6700\
    \u5C0F\u306E\u5024\u3092\u8FD4\u3059 (\u306A\u3051\u308C\u3070 std::nullopt)\n\
    \     */\n    std::optional<T> next_value(long long l, long long r, const T& lower)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        int cnt = count_less(l,\
    \ r, compressed_lower(lower));\n        if (cnt == r - l) return std::nullopt;\n\
    \        return vals[kth_compressed(l, r, cnt)];\n    }\n};\n\ntemplate <typename\
    \ T>\nWaveletMatrix(std::vector<T>) -> WaveletMatrix<T>;\n\n/**\n * @brief \u91CD\
    \u307F\u306E\u548C\u3082\u6C42\u3081\u3089\u308C\u308B Wavelet Matrix\n *\n *\
    \ WaveletMatrix \u306E\u6A5F\u80FD\u306B\u52A0\u3048\u3066\u3001\u533A\u9593\u5185\
    \u3067\u5024\u304C [lower, upper) \u306B\u3042\u308B\u8981\u7D20\u306E\u91CD\u307F\
    \u306E\u548C\u3084\u3001\n * \u5024\u306E\u5C0F\u3055\u3044\u65B9\u304B\u3089\
    \ k \u500B\u306E\u91CD\u307F\u306E\u548C\u3092 O(log \u03C3) \u3067\u6C42\u3081\
    \u308B\u3002\u91CD\u307F\u3092\u7701\u304F\u3068\u5024\u305D\u306E\u3082\u306E\
    \u3092\u91CD\u307F\u306B\u3059\u308B\n * \u30E1\u30E2\u30EA\u306F WaveletMatrix\
    \ \u3088\u308A (log \u03C3 + 1) * (n + 1) \u500B\u306E W \u3060\u3051\u591A\u3044\
    \n * \u4F8B:\n * WeightedWaveletMatrix wm(std::vector<long long>{3, 1, 4, 1, 5});\n\
    \ * wm.sum(0, 5, 2, 5);           // 7 (3 + 4)\n * wm.sum_smallest(0, 5, 3); \
    \    // 5 (1 + 1 + 3)\n *\n * @tparam T \u5024\u306E\u578B (< \u3067\u6BD4\u8F03\
    \u3067\u304D\u308B\u3053\u3068)\n * @tparam W \u91CD\u307F\u306E\u578B (\u548C\
    \u3092\u53D6\u308B)\u3002\u7701\u7565\u3059\u308B\u3068\u3001T \u304C\u6574\u6570\
    \u306A\u3089 long long\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 T\n */\n\
    template <typename T, typename W = std::conditional_t<std::is_integral_v<T>, long\
    \ long, T>>\nclass WeightedWaveletMatrix : public WaveletMatrix<T> {\n    using\
    \ Base = WaveletMatrix<T>;\n    using Base::bv;\n    using Base::height;\n   \
    \ using Base::n;\n    // pre[d][i] \u306F\u3001\u4E0A\u304B\u3089 d \u6BB5\u76EE\
    \u307E\u3067\u5206\u3051\u305F\u5F8C\u306E\u5217 (d = 0 \u306A\u3089\u5143\u306E\
    \u5217) \u306E\u5148\u982D i \u500B\u306E\u91CD\u307F\u306E\u548C\n    std::vector<std::vector<W>>\
    \ pre;\n\n    void build_sum(const std::vector<W>& w) {\n        assert(static_cast<int>(w.size())\
    \ == n);\n        std::vector<int> order(n), nxt(n);  // \u5404\u6BB5\u306E\u5217\
    \u306E\u3001\u5143\u306E\u5217\u3067\u306E\u4F4D\u7F6E\n        for (int i = 0;\
    \ i < n; i++) order[i] = i;\n        pre.assign(height + 1, std::vector<W>(n +\
    \ 1, W(0)));\n        for (int d = 0;; d++) {\n            for (int i = 0; i <\
    \ n; i++) pre[d][i + 1] = pre[d][i] + w[order[i]];\n            if (d == height)\
    \ break;\n            int zero = 0, one = this->mid[d];\n            for (int\
    \ i = 0; i < n; i++) {\n                if (bv[d].get(i))\n                  \
    \  nxt[one++] = order[i];\n                else\n                    nxt[zero++]\
    \ = order[i];\n            }\n            std::swap(order, nxt);\n        }\n\
    \    }\n    // [l, r) \u306E\u3001\u5727\u7E2E\u5F8C\u306E\u756A\u53F7\u304C c\
    \ \u672A\u6E80\u306E\u8981\u7D20\u306E\u91CD\u307F\u306E\u548C\n    W sum_less(int\
    \ l, int r, int c) const {\n        W res(0);\n        for (int d = 0; d < height;\
    \ d++) {\n            bool b = c >> (height - 1 - d) & 1;\n            if (b)\
    \ res += pre[d + 1][bv[d].rank0(r)] - pre[d + 1][bv[d].rank0(l)];\n          \
    \  std::tie(l, r) = this->down(d, l, r, b);\n        }\n        return res;\n\
    \    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF (\u5024\u305D\u306E\u3082\u306E\u3092\u91CD\u307F\u306B\u3059\u308B)\n\
    \     *\n     * @param v \u5217\n     */\n    explicit WeightedWaveletMatrix(const\
    \ std::vector<T>& v = {}) : Base(v) { build_sum(std::vector<W>(v.begin(), v.end()));\
    \ }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n\
    \     * @param v \u5217\n     * @param w \u5404\u8981\u7D20\u306E\u91CD\u307F\n\
    \     */\n    WeightedWaveletMatrix(const std::vector<T>& v, const std::vector<W>&\
    \ w) : Base(v) { build_sum(w); }\n\n    /**\n     * @brief [l, r) \u306E\u8981\
    \u7D20\u306E\u3046\u3061\u3001\u5024\u304C [lower, upper) \u306B\u3042\u308B\u3082\
    \u306E\u306E\u91CD\u307F\u306E\u548C\u3092\u8FD4\u3059\n     */\n    W sum(long\
    \ long l, long long r, const T& lower, const T& upper) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        if (!(lower < upper)) return W(0);\n   \
    \     return sum_less(l, r, this->compressed_lower(upper)) - sum_less(l, r, this->compressed_lower(lower));\n\
    \    }\n    /**\n     * @brief [l, r) \u306E\u3059\u3079\u3066\u306E\u8981\u7D20\
    \u306E\u91CD\u307F\u306E\u548C\u3092\u8FD4\u3059\n     */\n    W sum(long long\
    \ l, long long r) const {\n        assert(0 <= l && l <= r && r <= n);\n     \
    \   return pre[0][r] - pre[0][l];\n    }\n    /**\n     * @brief [l, r) \u306E\
    \u8981\u7D20\u3092\u5024\u306E\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3079\u305F\
    \u3068\u304D\u306E\u3001\u5148\u982D k \u500B\u306E\u91CD\u307F\u306E\u548C\u3092\
    \u8FD4\u3059\n     *\n     * \u540C\u3058\u5024\u306E\u8981\u7D20\u306F\u3001\u5143\
    \u306E\u5217\u3067\u524D\u306B\u3042\u308B\u3082\u306E\u304B\u3089\u6570\u3048\
    \u308B\n     */\n    W sum_smallest(long long l_, long long r_, long long k_)\
    \ const {\n        assert(0 <= l_ && l_ <= r_ && r_ <= n);\n        assert(0 <=\
    \ k_ && k_ <= r_ - l_);\n        int l = l_, r = r_, k = k_;\n        W res(0);\n\
    \        for (int d = 0; d < height; d++) {\n            int l0 = bv[d].rank0(l),\
    \ r0 = bv[d].rank0(r);\n            bool b = k >= r0 - l0;\n            if (b)\
    \ {\n                res += pre[d + 1][r0] - pre[d + 1][l0];\n               \
    \ k -= r0 - l0;\n            }\n            std::tie(l, r) = this->down(d, l,\
    \ r, b);\n        }\n        // \u6B8B\u308A\u306E k \u500B\u306F\u540C\u3058\u5024\
    \u3067\u3001\u6700\u5F8C\u306E\u6BB5\u306E [l, r) \u306E\u5148\u982D\u306B\u4E26\
    \u3093\u3067\u3044\u308B\n        return res + pre[height][l + k] - pre[height][l];\n\
    \    }\n    /**\n     * @brief [l, r) \u306E\u8981\u7D20\u3092\u5024\u306E\u5927\
    \u304D\u3044\u9806\u306B\u4E26\u3079\u305F\u3068\u304D\u306E\u3001\u5148\u982D\
    \ k \u500B\u306E\u91CD\u307F\u306E\u548C\u3092\u8FD4\u3059\n     *\n     * \u540C\
    \u3058\u5024\u306E\u8981\u7D20\u306F\u3001\u5143\u306E\u5217\u3067\u5F8C\u308D\
    \u306B\u3042\u308B\u3082\u306E\u304B\u3089\u6570\u3048\u308B\n     */\n    W sum_largest(long\
    \ long l, long long r, long long k) const {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        assert(0 <= k && k <= r - l);\n        return sum(l, r) -\
    \ sum_smallest(l, r, r - l - k);\n    }\n};\n\ntemplate <typename T>\nWeightedWaveletMatrix(std::vector<T>)\
    \ -> WeightedWaveletMatrix<T>;\ntemplate <typename T, typename W>\nWeightedWaveletMatrix(std::vector<T>,\
    \ std::vector<W>) -> WeightedWaveletMatrix<T, W>;\n#line 15 \"src/data_structures/range-lis.hpp\"\
    \n\nnamespace internal_range_lis {\n\n// \u7F6E\u63DB p, q (\u884C -> \u5217\u3001\
    \u9577\u3055 n) \u306E unit-Monge \u7A4D r = p \u22A1 q O(n log n)\n// \u03A3\
    _P(i, j) = #{i' >= i : p[i'] < j} \u3068\u3057\u3066\u3001r \u306E \u03A3 \u306F\
    \ min_j (\u03A3_P(i, j) + \u03A3_Q(j, k))\n// \u5185\u5074\u306E\u6DFB\u5B57 j\
    \ \u3092\u534A\u5206\u306B\u5206\u3051\u3066\u518D\u5E30\u3057\u30012 \u3064\u306E\
    \u7D50\u679C\u3092\u300C\u3069\u3061\u3089\u306E min \u3092\u4F7F\u3046\u304B\u300D\
    \u306E\u5883\u754C\u306E\u968E\u6BB5\u306B\u6CBF\u3063\u3066\u76F4\u3059\n// w\
    \ \u306F\u4F5C\u696D\u7528\u30021 \u6BB5\u3067 12n + 2 \u4F7F\u3044\u3001\u6B21\
    \u306E\u6BB5\u306F\u5207\u308A\u4E0A\u3052\u305F\u534A\u5206\u306A\u306E\u3067\
    \u3001\u5408\u8A08 24n + 26 log n \u7A0B\u5EA6\u3042\u308C\u3070\u8DB3\u308A\u308B\
    \ninline void unit_monge_mul(int n, const int* p, const int* q, int* r, int* w)\
    \ {\n    if (n <= 1) {\n        if (n == 1) r[0] = 0;\n        return;\n    }\n\
    \    const int mid = n / 2;\n    // part 0: p[i] < mid \u306E\u884C\u3068 j <\
    \ mid\u3001part 1: p[i] >= mid \u306E\u884C\u3068 j >= mid\n    int* col[2] =\
    \ {w, w + n};              // \u884C -> \u5217\n    int* row[2] = {w + 2 * n,\
    \ w + 3 * n};  // \u5217 -> \u884C\n    int *f = w + 4 * n, *g = w + 5 * n + 1,\
    \ *id = w + 6 * n + 2;\n    int *pp = w + 7 * n + 2, *qq = pp + n, *rr = qq +\
    \ n, *rows = rr + n, *cols = rows + n, *next = cols + n;\n    std::fill(w, w +\
    \ 4 * n, -1);\n    for (int part = 0; part < 2; part++) {\n        const int lo\
    \ = part == 0 ? 0 : mid, hi = part == 0 ? mid : n, m = hi - lo;\n        std::fill(id,\
    \ id + n, -1);\n        for (int j = lo; j < hi; j++) id[q[j]] = 0;\n        for\
    \ (int k = 0, c = 0; k < n; k++)\n            if (id[k] != -1) id[k] = c, cols[c++]\
    \ = k;\n        for (int i = 0, c = 0; i < n; i++)\n            if (lo <= p[i]\
    \ && p[i] < hi) rows[c] = i, pp[c++] = p[i] - lo;\n        for (int j = lo; j\
    \ < hi; j++) qq[j - lo] = id[q[j]];\n        unit_monge_mul(m, pp, qq, rr, next);\n\
    \        for (int t = 0; t < m; t++) col[part][rows[t]] = cols[rr[t]], row[part][cols[rr[t]]]\
    \ = rows[t];\n    }\n    // d(i, k) = (part 1 \u3092\u4F7F\u3046\u5024) - (part\
    \ 0 \u3092\u4F7F\u3046\u5024) \u306F\u3001k \u304C\u5897\u3048\u308B\u3068\u6E1B\
    \u308A\u3001i \u304C\u5897\u3048\u308B\u3068\u6E1B\u308B (1 \u6B69\u3067 0 \u304B\
    \ 1)\n    auto right = [&](int i, int k) { return -static_cast<int>(row[1][k]\
    \ != -1 && row[1][k] < i) - static_cast<int>(row[0][k] != -1 && row[0][k] >= i);\
    \ };\n    auto up = [&](int i, int k) { return static_cast<int>(col[1][i - 1]\
    \ != -1 && col[1][i - 1] < k) + static_cast<int>(col[0][i - 1] != -1 && col[0][i\
    \ - 1] >= k); };\n    // f[i]: d(i, k) <= 0 \u3068\u306A\u308B\u6700\u5C0F\u306E\
    \ k (\u305D\u3053\u3067 d = 0)\u3001g[i]: d(i, k) >= 0 \u3068\u306A\u308B\u6700\
    \u5927\u306E k\n    int kf = 0, df = 0, kg = 0, dg = 0;\n    for (int i = n;;\
    \ i--) {\n        while (df > 0) df += right(i, kf), kf++;\n        while (kg\
    \ < n && dg + right(i, kg) >= 0) dg += right(i, kg), kg++;\n        f[i] = kf,\
    \ g[i] = kg;\n        if (i == 0) break;\n        df += up(i, kf), dg += up(i,\
    \ kg);\n    }\n    // \u884C i \u306E\u70B9\u306F\u3001\u5883\u754C\u3088\u308A\
    \u5DE6\u4E0A (d >= 0) \u306B\u3042\u308B part 0 \u306E\u70B9\u304B\u3001\u53F3\
    \u4E0B (d <= 0) \u306B\u3042\u308B part 1 \u306E\u70B9\u3092\u305D\u306E\u307E\
    \u307E\u4F7F\u3044\u3001\n    // \u3069\u3061\u3089\u3082\u5883\u754C\u3092\u307E\
    \u305F\u3050\u306A\u3089\u3001\u5883\u754C\u306E\u89D2 (d(i, k) = 1\u3001d(i +\
    \ 1, k + 1) = -1 \u3068\u306A\u308B k = g[i + 1]) \u306B\u79FB\u3059\n    for\
    \ (int i = 0; i < n; i++) {\n        if (col[0][i] != -1) {\n            r[i]\
    \ = col[0][i] + 1 <= g[i + 1] ? col[0][i] : g[i + 1];\n        } else {\n    \
    \        r[i] = col[1][i] >= f[i] ? col[1][i] : g[i + 1];\n        }\n    }\n\
    }\n\n// \u70B9\u306E\u306A\u3044\u884C\u3084\u5217\u304C\u3042\u308B\u90E8\u5206\
    \u7F6E\u63DB (\u884C -> \u5217\u3001\u306A\u3051\u308C\u3070 -1) \u306E\u7A4D\n\
    // a \u306E\u7A7A\u306E\u884C\u3092\u4E0A\u306B\u5BC4\u305B\u3066 a \u306E\u7A7A\
    \u306E\u5217\u3092\u5272\u308A\u5F53\u3066\u3001b \u306E\u7A7A\u306E\u5217\u3092\
    \u53F3\u306B\u5BC4\u305B\u3066 b \u306E\u7A7A\u306E\u884C\u3092\u5272\u308A\u5F53\
    \u3066\u305F\u7F6E\u63DB\u306E\u7A4D\u304B\u3089\u623B\u3059\ninline std::vector<int>\
    \ subunit_monge_mul(const std::vector<int>& a, const std::vector<int>& b) {\n\
    \    const int n = a.size();\n    std::vector<bool> a_col(n, false), b_col(n,\
    \ false);\n    for (int i = 0; i < n; i++) {\n        if (a[i] != -1) a_col[a[i]]\
    \ = true;\n        if (b[i] != -1) b_col[b[i]] = true;\n    }\n    std::vector<int>\
    \ ap, a_rows;\n    for (int j = 0; j < n; j++)\n        if (!a_col[j]) ap.push_back(j);\n\
    \    const int top = ap.size();\n    for (int i = 0; i < n; i++)\n        if (a[i]\
    \ != -1) ap.push_back(a[i]), a_rows.push_back(i);\n    std::vector<int> b_cols,\
    \ pos(n, -1), bp(n);\n    for (int k = 0; k < n; k++)\n        if (b_col[k]) pos[k]\
    \ = b_cols.size(), b_cols.push_back(k);\n    int cnt = b_cols.size();\n    for\
    \ (int j = 0; j < n; j++) bp[j] = b[j] != -1 ? pos[b[j]] : cnt++;\n    std::vector<int>\
    \ c(n), work(26 * n + 2048);\n    unit_monge_mul(n, ap.data(), bp.data(), c.data(),\
    \ work.data());\n    std::vector<int> res(n, -1);\n    for (int t = 0; t < static_cast<int>(a_rows.size());\
    \ t++) {\n        if (c[top + t] < static_cast<int>(b_cols.size())) res[a_rows[t]]\
    \ = b_cols[c[top + t]];\n    }\n    return res;\n}\n\n// \u7F6E\u63DB p \u306E\
    \ seaweed (Tiskin)\u3002\u5DE6\u7AEF\u306E\u884C i \u304B\u3089\u5165\u308B seaweed\
    \ \u304C\u53F3\u7AEF\u306E\u884C res[i] \u304B\u3089\u51FA\u308B (\u4E0A\u304B\
    \u3089\u5165\u308B\u3082\u306E\u306F -1)\n// \u5024\u3067\u534A\u5206\u306B\u5206\
    \u3051\u3066\u518D\u5E30\u3057\u3001\u3082\u3046\u4E00\u65B9\u306E\u5024\u306E\
    \u4F4D\u7F6E\u306F\u7D20\u901A\u308A\u3055\u305B\u3066\u30012 \u3064\u3092 subunit_monge_mul\
    \ \u3067\u3064\u306A\u3050 O(n log^2 n)\ninline std::vector<int> seaweed(const\
    \ std::vector<int>& p) {\n    const int n = p.size();\n    if (n <= 1) return\
    \ std::vector<int>(n, -1);\n    const int mid = n / 2;\n    std::vector<int> lo,\
    \ hi, lo_pos, hi_pos;\n    for (int i = 0; i < n; i++) {\n        if (p[i] < mid)\
    \ {\n            lo.push_back(p[i]), lo_pos.push_back(i);\n        } else {\n\
    \            hi.push_back(p[i] - mid), hi_pos.push_back(i);\n        }\n    }\n\
    \    lo = seaweed(lo), hi = seaweed(hi);\n    std::vector<int> a(n), b(n);\n \
    \   std::iota(a.begin(), a.end(), 0), std::iota(b.begin(), b.end(), 0);\n    for\
    \ (int i = 0; i < static_cast<int>(lo.size()); i++) a[lo_pos[i]] = lo[i] == -1\
    \ ? -1 : lo_pos[lo[i]];\n    for (int i = 0; i < static_cast<int>(hi.size());\
    \ i++) b[hi_pos[i]] = hi[i] == -1 ? -1 : hi_pos[hi[i]];\n    return subunit_monge_mul(a,\
    \ b);\n}\n\n}  // namespace internal_range_lis\n\n/**\n * @brief \u56FA\u5B9A\u3057\
    \u305F\u5217\u306B\u3064\u3044\u3066\u3001\u533A\u9593\u306E\u6700\u9577\u5897\
    \u52A0\u90E8\u5206\u5217 (\u72ED\u7FA9) \u306E\u9577\u3055\u3092\u30AA\u30F3\u30E9\
    \u30A4\u30F3\u3067\u7B54\u3048\u308B\n *\n * seaweed (Tiskin) \u3092\u5024\u306E\
    \u5206\u5272\u7D71\u6CBB\u3068 unit-Monge \u884C\u5217\u306E\u7A4D\u3067 O(n log^2\
    \ n) \u3067\u6C42\u3081\u308B\u3068\u3001\n * LIS(a[l, r)) = (r - l) - #{l <=\
    \ i < n : \u5DE6\u7AEF\u306E\u884C i \u304B\u3089\u5165\u3063\u305F seaweed \u304C\
    \u53F3\u7AEF\u306E\u884C r \u672A\u6E80\u304B\u3089\u51FA\u308B} \u306B\u306A\u308B\
    \u306E\u3067\u3001Wavelet Matrix \u3067\u6570\u3048\u308B\n * \u69CB\u7BC9 O(n\
    \ log^2 n)\u3001\u30AF\u30A8\u30EA O(log n)\n * \u4F8B:\n * RangeLIS rl(a);\n\
    \ * long long len = rl.lis(l, r);\n *\n * @tparam T \u5024\u306E\u578B (operator<\
    \ \u3067\u6BD4\u3079\u3089\u308C\u308B\u3053\u3068)\n */\ntemplate <typename T>\n\
    class RangeLIS {\n    long long n;\n    WaveletMatrix<long long> wm;\n\n    static\
    \ std::vector<long long> build(const std::vector<T>& a) {\n        const int n\
    \ = a.size();\n        // \u7F6E\u63DB\u306B\u76F4\u3059\u3002\u540C\u3058\u5024\
    \u306F\u5F8C\u308D\u306E\u3082\u306E\u307B\u3069\u5C0F\u3055\u304F\u3057\u3066\
    \u3001\u72ED\u7FA9\u306E\u5897\u52A0\u5217\u3060\u3051\u304C\u6B8B\u308B\u3088\
    \u3046\u306B\u3059\u308B\n        std::vector<int> idx(n), p(n);\n        std::iota(idx.begin(),\
    \ idx.end(), 0);\n        std::sort(idx.begin(), idx.end(), [&](int i, int j)\
    \ { return a[i] < a[j] || (!(a[j] < a[i]) && i > j); });\n        for (int k =\
    \ 0; k < n; k++) p[idx[k]] = k;\n        const auto row = internal_range_lis::seaweed(p);\n\
    \        std::vector<long long> res(n);\n        for (int i = 0; i < n; i++) res[i]\
    \ = row[i] == -1 ? n : row[i];\n        return res;\n    }\n\n   public:\n   \
    \ /**\n     * @brief \u5217 a \u304B\u3089\u4F5C\u308B\n     */\n    explicit\
    \ RangeLIS(const std::vector<T>& a) : n(a.size()), wm(build(a)) {}\n    /**\n\
    \     * @brief \u8981\u7D20\u6570\n     */\n    long long size() const { return\
    \ n; }\n    /**\n     * @brief a[l], ..., a[r-1] \u306E\u6700\u9577\u5897\u52A0\
    \u90E8\u5206\u5217 (\u72ED\u7FA9) \u306E\u9577\u3055\n     */\n    long long lis(long\
    \ long l, long long r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        return (r - l) - wm.count(l, n, 0, r);\n    }\n};\n\ntemplate <typename\
    \ T>\nRangeLIS(std::vector<T>) -> RangeLIS<T>;\n#line 7 \"test/yosupo/data_structure/static-range-lis-query.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<int> p(n);\n    for (auto&\
    \ x : p) std::cin >> x;\n    RangeLIS rl(p);\n    while (q--) {\n        int l,\
    \ r;\n        std::cin >> l >> r;\n        std::cout << rl.lis(l, r) << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_lis_query\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../src/data_structures/range-lis.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<int> p(n);\n    for (auto&\
    \ x : p) std::cin >> x;\n    RangeLIS rl(p);\n    while (q--) {\n        int l,\
    \ r;\n        std::cin >> l >> r;\n        std::cout << rl.lis(l, r) << '\\n';\n\
    \    }\n}\n"
  dependsOn:
  - src/data_structures/range-lis.hpp
  - src/data_structures/wavelet-matrix.hpp
  isVerificationFile: true
  path: test/yosupo/data_structure/static-range-lis-query.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 19:45:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/data_structure/static-range-lis-query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/static-range-lis-query.test.cpp
- /verify/test/yosupo/data_structure/static-range-lis-query.test.cpp.html
title: test/yosupo/data_structure/static-range-lis-query.test.cpp
---
