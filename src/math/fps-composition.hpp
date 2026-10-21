#pragma once

/**
 * @file fps-composition.hpp
 * @brief 形式的冪級数の合成と、合成についての逆関数
 */

#include <algorithm>
#include <cassert>
#include <vector>

#include "fps.hpp"

/**
 * @brief f(g(x)) の x^deg 未満の項 O(n^2 + n sqrt(n) log n) (n = max(|f|, deg))
 * f は多項式として扱うので、g の定数項は 0 でなくてもよい。deg を省略するか負の値を渡すと max(|f|, |g|)
 * k = ceil(sqrt(|f|)) として f = Σ_j (Σ_{i<k} f_{jk+i} x^i) x^{jk} と分け、g^i (i < k) と g^k を使って Horner 法で求める
 */
template <typename mint>
FPS<mint> composition(const FPS<mint>& f, const FPS<mint>& g, long long deg = -1) {
    if (deg < 0) deg = std::max(f.size(), g.size());
    if (deg == 0) return FPS<mint>();
    const long long m = f.size();
    if (m == 0) return FPS<mint>(deg, 0);
    long long k = 1;
    while (k * k < m) k++;
    // gp[i] = g^i (i <= k) の x^deg 未満
    std::vector<FPS<mint>> gp(k + 1);
    gp[0] = FPS<mint>(deg, 0);
    gp[0][0] = 1;
    const FPS<mint> gd = g.pre(deg);
    for (long long i = 1; i <= k; i++) {
        gp[i] = (gp[i - 1] * gd).pre(deg);
        gp[i].resize(deg);
    }
    FPS<mint> res(deg, 0);
    for (long long j = (m - 1) / k; j >= 0; j--) {
        // res <- res * g^k + Σ_{i<k} f_{jk+i} g^i
        res = (res * gp[k]).pre(deg);
        res.resize(deg);
        for (long long i = 0; i < k && j * k + i < m; i++) {
            const mint c = f[j * k + i];
            if (c == 0) continue;
            for (long long t = 0; t < deg; t++) res[t] += c * gp[i][t];
        }
    }
    return res;
}

/**
 * @brief f(h(x)) = x となる h の x^deg 未満の項 O(n^2) (n = deg)
 * f_0 = 0、f_1 != 0 であること。deg を省略するか負の値を渡すと |f|
 * ニュートン法で、h <- h - (f(h) - x) / f'(h) と x^{2m} 未満まで正しい h を作っていく
 */
template <typename mint>
FPS<mint> compositional_inverse(const FPS<mint>& f, long long deg = -1) {
    assert(f.size() >= 2 && f[0] == 0 && f[1] != 0);
    if (deg < 0) deg = f.size();
    if (deg == 0) return FPS<mint>();
    FPS<mint> h = {0, f[1].inv()};
    for (long long m = 2; m < deg; m <<= 1) {
        // h の定数項は 0 なので、f の x^{2m} 以上の項は x^{2m} 未満に効かない
        const FPS<mint> fm = f.pre(m << 1);
        FPS<mint> fh = composition(fm, h, m << 1);
        FPS<mint> dfh = composition(diff(fm), h, m << 1);
        fh -= FPS<mint>{0, 1};
        h -= (fh * inv(dfh, m << 1)).pre(m << 1);
    }
    h.resize(deg);
    return h;
}
