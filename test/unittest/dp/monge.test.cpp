#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// monge.hpp の関数を愚直な実装とランダムに比べる
// monotone_minima は Monge な行列で、(min, +) 畳み込みは凸列で、alien_dp は凸関数と、区間に分ける DP で確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/dp/monge.hpp"

#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <utility>
#include <vector>

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

int main() {
    std::mt19937_64 rng(314);
    auto convex = [&](int n, long long range) {
        // 差分を小さい順に並べてから足していくと凸列になる
        std::vector<long long> d(n), a(n);
        for (auto& x : d) x = static_cast<long long>(rng() % (2 * range + 1)) - range;
        std::sort(d.begin(), d.end());
        a[0] = static_cast<long long>(rng() % 100);
        for (int i = 1; i < n; i++) a[i] = a[i - 1] + d[i];
        return a;
    };

    // monotone_minima: (x_i - y_j)^2 + p_i + q_j (x, y は昇順) は Monge。最小の位置 (最も左) を愚直に求めて比べる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int h = rng() % 12, w = rng() % 12 + 1;
        std::vector<long long> x(h), y(w), p(h), q(w);
        for (auto& v : x) v = rng() % 10;  // 値の範囲を狭くして、同じ値もよく出るようにする
        for (auto& v : y) v = rng() % 10;
        for (auto& v : p) v = rng() % 5;
        for (auto& v : q) v = rng() % 5;
        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());
        auto f = [&](long long i, long long j) { return (x[i] - y[j]) * (x[i] - y[j]) + p[i] + q[j]; };
        auto res = monotone_minima(h, w, f);
        for (int i = 0; i < h; i++) {
            long long best = 0;
            for (int j = 1; j < w; j++)
                if (f(i, j) < f(i, best)) best = j;
            check(res[i] == best, "monotone_minima");
        }
    }

    // (min, +) 畳み込み: すべての組を試して比べる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 10 + 1, m = rng() % 10 + 1;
        std::vector<long long> a = convex(n, 20), b = convex(m, 20), c(m);
        for (auto& v : c) v = rng() % 100;  // 任意の列
        auto naive = [&](const std::vector<long long>& s, const std::vector<long long>& t) {
            std::vector<long long> r(s.size() + t.size() - 1, std::numeric_limits<long long>::max());
            for (size_t i = 0; i < s.size(); i++)
                for (size_t j = 0; j < t.size(); j++) r[i + j] = std::min(r[i + j], s[i] + t[j]);
            return r;
        };
        check(min_plus_convolution_convex_arbitrary(a, c) == naive(a, c), "convex_arbitrary");
        check(min_plus_convolution_convex_convex(a, b) == naive(a, b), "convex_convex");
    }

    // alien_dp: 凸関数 f について、solve(lambda) を愚直に作って f(k) が求まるか
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<long long> f = convex(n, 30);
        auto solve = [&](long long lambda) {
            std::pair<long long, long long> best = {f[0], 0};
            for (int x = 1; x < n; x++)
                if (f[x] + lambda * x < best.first) best = {f[x] + lambda * x, x};
            return best;
        };
        for (int k = 0; k < n; k++) check(alien_dp(k, -100, 100, solve) == f[k], "alien_dp 凸関数");
    }
    // alien_dp の例: 配列を連続する k 個の区間に分け、区間の和の 2 乗の合計を最小にする (k について凸)
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 10 + 1;
        std::vector<long long> v(n), s(n + 1, 0);
        for (auto& x : v) x = rng() % 10;
        for (int i = 0; i < n; i++) s[i + 1] = s[i] + v[i];
        auto cost = [&](int l, int r) { return (s[r] - s[l]) * (s[r] - s[l]); };
        const long long INF = std::numeric_limits<long long>::max() / 4;
        // 愚直: dp[k][i] = 先頭 i 個を k 個の区間に分けるときの最小
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1, INF));
        dp[0][0] = 0;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 0; j < i; j++)
                    if (dp[k - 1][j] < INF) dp[k][i] = std::min(dp[k][i], dp[k - 1][j] + cost(j, i));
        // 区間 1 つにつき lambda を足し、区間の個数の制約を外した DP (同じ値なら区間の少ない方)
        auto solve = [&](long long lambda) {
            std::vector<std::pair<long long, long long>> e(n + 1, {INF, 0});
            e[0] = {0, 0};
            for (int i = 1; i <= n; i++)
                for (int j = 0; j < i; j++) e[i] = std::min(e[i], {e[j].first + cost(j, i) + lambda, e[j].second + 1});
            return e[n];
        };
        for (int k = 1; k <= n; k++) check(alien_dp(k, -10000, 10000, solve) == dp[k][n], "alien_dp 区間に分ける");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
