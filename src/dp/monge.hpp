#pragma once

/**
 * @file monge.hpp
 * @brief Monge 性を使う DP の高速化 (monotone minima、(min, +) 畳み込み、Alien DP)
 */

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

/**
 * @brief 各行の最小値の位置 (最も左のもの) が行について単調非減少な H 行 W 列の行列の、各行の最小値の位置 O((H + W) log H)
 * select(i, j, k) (j < k) は、行 i で列 k の値が列 j の値より真に小さいなら true を返す
 * (値を返す関数があるなら monotone_minima を使う。範囲外の列を「選ばない」と決めたいときはこちらで比べ方を書く)
 */
template <typename Select>
std::vector<long long> monotone_minima_select(long long H, long long W, Select select) {
    assert(H >= 0 && W >= 1);
    std::vector<long long> res(H);
    // 行 [top, bottom) の最小の位置が列 [left, right] にあるとして、真ん中の行から決める
    auto rec = [&](auto&& self, long long top, long long bottom, long long left, long long right) -> void {
        if (top >= bottom) return;
        const long long mid = (top + bottom) / 2;
        long long best = left;
        for (long long j = left + 1; j <= right; j++)
            if (select(mid, best, j)) best = j;
        res[mid] = best;
        self(self, top, mid, left, best);
        self(self, mid + 1, bottom, best, right);
    };
    rec(rec, 0, H, 0, W - 1);
    return res;
}

/**
 * @brief 各行の最小値の位置 (最も左のもの) が行について単調非減少な H 行 W 列の行列の、各行の最小値の位置 O((H + W) log H)
 * f(i, j) は (i, j) 成分の値。Monge な行列 (f(i, j) + f(i', j') <= f(i, j') + f(i', j)、i < i'、j < j') ならこの条件を満たす
 */
template <typename F>
std::vector<long long> monotone_minima(long long H, long long W, F f) {
    return monotone_minima_select(H, W, [&](long long i, long long j, long long k) { return f(i, k) < f(i, j); });
}

/**
 * @brief c_k = min_{i + j = k} (a_i + b_j) を、a が凸 (a_{i+1} - a_i が単調非減少) のときに求める O((N + M) log (N + M))
 * b は任意。a, b は空でないこと
 */
template <typename T>
std::vector<T> min_plus_convolution_convex_arbitrary(const std::vector<T>& a, const std::vector<T>& b) {
    const long long n = a.size(), m = b.size();
    assert(n >= 1 && m >= 1);
    // 行 k、列 j の値は a_{k-j} + b_j。k - j が [0, n) の外の列は選ばない
    auto select = [&](long long k, long long j1, long long j2) {
        if (k < j2) return false;      // j2 は大きすぎる (k - j2 < 0)
        if (k - j1 >= n) return true;  // j1 は小さすぎる (k - j1 >= n)
        return a[k - j2] + b[j2] < a[k - j1] + b[j1];
    };
    std::vector<long long> arg = monotone_minima_select(n + m - 1, m, select);
    std::vector<T> c(n + m - 1);
    for (long long k = 0; k < n + m - 1; k++) c[k] = a[k - arg[k]] + b[arg[k]];
    return c;
}

/**
 * @brief c_k = min_{i + j = k} (a_i + b_j) を、a, b がともに凸のときに求める O(N + M)
 * 差分 (傾き) を小さい順に併合すればよい。a, b は空でないこと
 */
template <typename T>
std::vector<T> min_plus_convolution_convex_convex(const std::vector<T>& a, const std::vector<T>& b) {
    const long long n = a.size(), m = b.size();
    assert(n >= 1 && m >= 1);
    std::vector<T> c(n + m - 1);
    c[0] = a[0] + b[0];
    for (long long k = 1, i = 0, j = 0; k < n + m - 1; k++) {
        // 次に進める方は、増え方 (差分) の小さい方
        if (j == m - 1 || (i < n - 1 && a[i + 1] - a[i] < b[j + 1] - b[j])) {
            c[k] = c[k - 1] + (a[i + 1] - a[i]), i++;
        } else {
            c[k] = c[k - 1] + (b[j + 1] - b[j]), j++;
        }
    }
    return c;
}

/**
 * @brief Alien DP (Lagrange 緩和): ちょうど k 個選ぶときの最小値 f(k) を、f が凸 (f(x+1) - f(x) が単調非減少な整数) のときに求める
 * solve(lambda) は {min_x (f(x) + lambda x), その最小値をとる x のうち最小のもの} を返すこと
 * lambda は [lo, hi] の整数の中から二分探索する。-lo, -hi は f の傾きの最小値・最大値を含むようにとる (f(x+1) - f(x) が [-hi, -lo] に入る)
 * solve を呼ぶ回数は O(log (hi - lo))。最大化なら f の符号を反転して使う
 */
template <typename Solve>
long long alien_dp(long long k, long long lo, long long hi, Solve solve) {
    assert(lo <= hi);
    // x_min(lambda) は lambda について単調非増加。x_min(lambda) <= k となる最小の lambda を探す
    // そのとき k は最小値をとる x の範囲 [x_min(lambda), x_min(lambda - 1)] に入るので、f(k) = 最小値 - lambda k
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (solve(mid).second <= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    auto [val, x] = solve(lo);
    assert(x <= k && "alien_dp: [lo, hi] が狭い");
    return val - lo * k;
}
