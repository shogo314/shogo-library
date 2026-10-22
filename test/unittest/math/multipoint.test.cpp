#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// multipoint_evaluation・polynomial_interpolation・sample_point_shift を、1 点ずつ直接計算したものと比べる
// multipoint_evaluation_geometric は、a・r が 0・1・-1 の場合も試す
// sample_point_shift は、c + k が 0 以上 n 未満の整数と重なる場合や、法を回って重なる場合も試す
// weighted_power_sums を、Σ_i w_i x_i^k を直接計算したものと比べる (点の重なりや 0 も含む)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/multipoint.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"

using mint = static_modint<998244353>;
using F = FPS<mint>;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

mint eval(const F& f, mint x) {
    mint r = 0;
    for (int i = static_cast<int>(f.size()) - 1; i >= 0; i--) r = r * x + f[i];
    return r;
}

int main() {
    std::mt19937_64 rng(314);
    auto gen = [&] { return mint(rng() % mint::mod()); };
    // multipoint_evaluation: 点が重なっても、f が 0 でもよい。32 点を超える大きさも試す
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % (rep < 200 ? 10 : 200), m = rng() % (rep < 200 ? 10 : 200);
        F f(n);
        for (auto& x : f) x = gen();
        std::vector<mint> xs(m);
        for (auto& x : xs) x = rng() % 3 == 0 ? mint(rng() % 5) : gen();
        auto res = multipoint_evaluation(f, xs);
        check(static_cast<int>(res.size()) == m, "multipoint_evaluation の長さ");
        for (int i = 0; i < m; i++) check(res[i] == eval(f, xs[i]), "multipoint_evaluation");
    }
    // polynomial_interpolation: 求めた多項式は長さ n で、すべての点を通る
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % (rep < 200 ? 10 : 200);
        std::vector<mint> xs, ys(n);
        while (static_cast<int>(xs.size()) < n) {
            mint x = rng() % 3 == 0 ? mint(rng() % 1000) : gen();
            bool dup = false;
            for (mint y : xs) dup |= y == x;
            if (!dup) xs.push_back(x);
        }
        for (auto& y : ys) y = gen();
        F f = polynomial_interpolation(xs, ys);
        check(static_cast<int>(f.size()) == n, "polynomial_interpolation の長さ");
        for (int i = 0; i < n; i++) check(eval(f, xs[i]) == ys[i], "polynomial_interpolation");
    }
    // multipoint_evaluation_geometric: f(a r^i) (0 <= i < m)
    for (int rep = 0; rep < 600 && ok; rep++) {
        int n = rng() % (rep < 400 ? 10 : 200), m = rng() % (rep < 400 ? 10 : 200);
        F f(n);
        for (auto& x : f) x = gen();
        auto pick = [&] {
            int t = rng() % 5;
            return t == 0 ? mint(0) : t == 1 ? mint(1)
                                  : t == 2   ? mint(-1)
                                             : gen();
        };
        mint a = pick(), r = pick();
        auto res = multipoint_evaluation_geometric(f, a, r, m);
        check(static_cast<int>(res.size()) == m, "multipoint_evaluation_geometric の長さ");
        mint x = a;
        for (int i = 0; i < m; i++, x *= r) check(res[i] == eval(f, x), "multipoint_evaluation_geometric");
    }
    // polynomial_interpolation_geometric: 点 a r^i を通る。r = -1 なら n <= 2 まで
    for (int rep = 0; rep < 600 && ok; rep++) {
        int n = rng() % (rep < 400 ? 10 : 300);
        mint a = gen(), r = gen();
        if (rep % 10 == 0) r = -1, n = std::min(n, 2);
        if (a == 0 || r == 0 || r == 1) continue;
        std::vector<mint> ys(n);
        for (auto& y : ys) y = gen();
        F f = polynomial_interpolation_geometric(a, r, ys);
        check(static_cast<int>(f.size()) == n, "polynomial_interpolation_geometric の長さ");
        mint x = a;
        for (int i = 0; i < n; i++, x *= r) check(eval(f, x) == ys[i], "polynomial_interpolation_geometric");
    }
    // sample_point_shift: f(0..n-1) から f(c..c+m-1)
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 12 + 1, m = rng() % 12;
        F f(n);
        for (auto& x : f) x = gen();
        std::vector<mint> ys(n);
        for (int i = 0; i < n; i++) ys[i] = eval(f, mint(i));
        int kind = rng() % 3;
        // 0 以上 n 未満と重なる c、法の近くで 0 に回り込む c、ふつうの c
        mint c = kind == 0 ? mint(rng() % 20) : kind == 1 ? mint(mint::mod() - 1 - rng() % 15)
                                                          : gen();
        auto res = sample_point_shift(ys, c, m);
        check(static_cast<int>(res.size()) == m, "sample_point_shift の長さ");
        for (int k = 0; k < m; k++) check(res[k] == eval(f, c + mint(k)), "sample_point_shift");
    }
    // weighted_power_sums
    for (int rep = 0; rep < 300 && ok; rep++) {
        int m = rng() % 15, n = rng() % 20;
        std::vector<mint> xs(m), ws(m);
        for (int i = 0; i < m; i++) xs[i] = rng() % 3 == 0 ? mint(rng() % 3) : gen(), ws[i] = gen();
        auto res = weighted_power_sums(xs, ws, n);
        check(static_cast<int>(res.size()) == n, "weighted_power_sums の長さ");
        for (int k = 0; k < n; k++) {
            mint s = 0;
            for (int i = 0; i < m; i++) s += ws[i] * xs[i].pow(k);
            check(res[k] == s, "weighted_power_sums");
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
