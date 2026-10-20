#pragma once

/**
 * @file multipoint.hpp
 * @brief 多点評価・多項式補間・標本点のずらし
 */

#include <cassert>
#include <vector>

#include "combinatorics.hpp"
#include "convolution.hpp"
#include "fps.hpp"

namespace internal_multipoint {
// 点 xs の subproduct tree: tree[k] は頂点 k が受け持つ点 x_i について Π (x - x_i)。葉は sz + i
template <typename mint>
struct SubproductTree {
    long long n, sz;
    std::vector<FPS<mint>> tree;
    explicit SubproductTree(const std::vector<mint>& xs) : n(xs.size()), sz(1) {
        while (sz < n) sz <<= 1;
        tree.assign(2 * sz, FPS<mint>{1});
        for (long long i = 0; i < n; i++) tree[sz + i] = FPS<mint>{-xs[i], 1};
        for (long long k = sz - 1; k >= 1; k--) tree[k] = tree[2 * k] * tree[2 * k + 1];
    }
};
}  // namespace internal_multipoint

/**
 * @brief 多項式 f の、点 xs での値 f(x_0), ..., f(x_{m-1}) O((n + m) log^2 (n + m))
 * subproduct tree の根から、各頂点の多項式で割った余りを下ろしていく。余りが短くなったら直接計算する
 */
template <typename mint>
std::vector<mint> multipoint_evaluation(const FPS<mint>& f, const std::vector<mint>& xs) {
    const long long m = xs.size();
    if (m == 0) return {};
    internal_multipoint::SubproductTree<mint> t(xs);
    std::vector<mint> res(m);
    // 頂点 k に f の余り g が届いたとき、受け持つ点の値を求める
    auto rec = [&](auto&& self, long long k, long long l, long long r, FPS<mint> g) -> void {
        if (l >= m) return;
        // 次数が小さければ Horner 法で直接求める
        if (r - l <= 32) {
            for (long long i = l; i < std::min(r, m); i++) res[i] = g.eval(xs[i]);
            return;
        }
        const long long mid = (l + r) / 2;
        self(self, 2 * k, l, mid, g % t.tree[2 * k]);
        self(self, 2 * k + 1, mid, r, g % t.tree[2 * k + 1]);
    };
    FPS<mint> g = f;
    g.normalize();
    rec(rec, 1, 0, t.sz, g % t.tree[1]);
    return res;
}

/**
 * @brief 点 (x_i, y_i) (x_i は互いに異なる) をすべて通る n - 1 次以下の多項式 (長さ n) O(n log^2 n)
 * g = Π (x - x_i) とすると f = Σ y_i / g'(x_i) Π_{j != i} (x - x_j)。g'(x_i) を多点評価し、和を subproduct tree の下から組み立てる
 */
template <typename mint>
FPS<mint> polynomial_interpolation(const std::vector<mint>& xs, const std::vector<mint>& ys) {
    assert(xs.size() == ys.size());
    const long long n = xs.size();
    if (n == 0) return FPS<mint>();
    internal_multipoint::SubproductTree<mint> t(xs);
    std::vector<mint> d = multipoint_evaluation(diff(t.tree[1]), xs);
    // val[k] = Σ_{頂点 k の点 i} c_i Π_{頂点 k の点 j != i} (x - x_j)、c_i = y_i / g'(x_i)
    std::vector<FPS<mint>> val(2 * t.sz);
    for (long long i = 0; i < t.sz; i++) val[t.sz + i] = i < n ? FPS<mint>{ys[i] / d[i]} : FPS<mint>{};
    for (long long k = t.sz - 1; k >= 1; k--) {
        FPS<mint> a = val[2 * k] * t.tree[2 * k + 1], b = val[2 * k + 1] * t.tree[2 * k];
        if (a.size() < b.size()) a.resize(b.size());
        for (size_t i = 0; i < b.size(); i++) a[i] += b[i];
        val[k] = a;
    }
    FPS<mint> f = val[1];
    f.resize(n);
    return f;
}

namespace internal_multipoint {
// ys = f(0), ..., f(n-1) から f(c), ..., f(c+m-1)。c + k が 0 以上 n 未満の整数と重ならないこと
// f(c+k) = (Π_{j<n} (c+k-j)) Σ_i a_i / (c+k-i)、a_i = y_i / (i! (n-1-i)! (-1)^(n-1-i))
template <typename mint>
std::vector<mint> shift_no_overlap(const std::vector<mint>& ys, mint c, long long m) {
    using C = Combination<mint>;
    const long long n = ys.size();
    C::extend(n);
    std::vector<mint> a(n);
    for (long long i = 0; i < n; i++) {
        a[i] = ys[i] * C::inverse_factorial(i) * C::inverse_factorial(n - 1 - i);
        if ((n - 1 - i) % 2 == 1) a[i] = -a[i];
    }
    // b_t = 1 / (c - (n-1) + t) (t = 0, ..., n+m-2)。逆数はまとめて求める
    const long long len = n + m - 1;
    std::vector<mint> v(len), b(len), pre(len + 1, 1);
    for (long long t = 0; t < len; t++) v[t] = c - mint(n - 1) + mint(t), pre[t + 1] = pre[t] * v[t];
    mint inv_all = pre[len].inv();
    for (long long t = len - 1; t >= 0; t--) b[t] = inv_all * pre[t], inv_all *= v[t];
    std::vector<mint> s = convolution(a, b);
    // Π_{j<n} (c+k-j) = v[k] v[k+1] ... v[k+n-1] をずらしながら求める
    std::vector<mint> res(m);
    mint prod = 1;
    for (long long t = 0; t < n; t++) prod *= v[t];
    for (long long k = 0; k < m; k++) {
        if (k > 0) prod *= v[k + n - 1] * b[k - 1];
        res[k] = prod * s[k + n - 1];
    }
    return res;
}
}  // namespace internal_multipoint

/**
 * @brief n - 1 次以下の多項式 f の f(0), ..., f(n-1) から、f(c), f(c+1), ..., f(c+m-1) を求める O((n + m) log (n + m))
 * 法は n + m より大きい素数であること。c + k が 0 以上 n 未満の整数と重なる k は ys をそのまま使う
 */
template <typename mint>
std::vector<mint> sample_point_shift(const std::vector<mint>& ys, mint c, long long m) {
    const long long n = ys.size();
    std::vector<mint> res(m);
    if (n == 0) return res;
    // (c + k) mod p が [0, n) に入るかで区切り、入らない区間ごとに畳み込みで求める
    const long long p = mint::mod();
    long long k = 0;
    while (k < m) {
        long long x = (c.val() + k) % p;
        if (x < n) {
            res[k] = ys[x];
            k++;
            continue;
        }
        // x + len が p か n + p に届くまでは重ならない (x >= n なので次に重なるのは x が p に戻ったとき)
        long long len = std::min(m - k, p - x);
        auto part = internal_multipoint::shift_no_overlap(ys, mint(x), len);
        for (long long i = 0; i < len; i++) res[k + i] = part[i];
        k += len;
    }
    return res;
}
