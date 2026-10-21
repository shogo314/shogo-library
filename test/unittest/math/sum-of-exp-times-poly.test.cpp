#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// sum_of_exp_times_poly を直接足し合わせたものと比べる (r = 0, 1 も)
// sum_of_exp_times_poly_limit は、d = 0, 1 の公式と、L_d = S_d(n) + r^n Σ_j C(d, j) n^{d-j} L_j が成り立つかで確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/sum-of-exp-times-poly.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../../src/math/combinatorics.hpp"
#include "../../../src/math/modint.hpp"

using mint = static_modint<998244353>;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

int main() {
    std::mt19937_64 rng(314);
    auto gen_r = [&] {
        int t = rng() % 4;
        return t == 0 ? mint(0) : t == 1 ? mint(1)
                                         : mint(rng() % mint::mod());
    };
    // 有限和: i^d と、一般の多項式 f
    for (int rep = 0; rep < 2000 && ok; rep++) {
        mint r = gen_r();
        long long d = rng() % 8, n = rng() % 30;
        mint expect = 0, ri = 1;
        for (long long i = 0; i < n; i++, ri *= r) expect += ri * (i == 0 && d == 0 ? mint(1) : mint(i).pow(d));
        check(sum_of_exp_times_poly(r, d, n) == expect, "sum_of_exp_times_poly i^d");
        std::vector<mint> coef(d + 1);
        for (auto& c : coef) c = rng() % mint::mod();
        auto f = [&](long long x) {
            mint v = 0;
            for (long long k = d; k >= 0; k--) v = v * mint(x) + coef[k];
            return v;
        };
        std::vector<mint> fv(d + 1);
        for (long long k = 0; k <= d; k++) fv[k] = f(k);
        expect = 0, ri = 1;
        for (long long i = 0; i < n; i++, ri *= r) expect += ri * f(i);
        check(sum_of_exp_times_poly(r, fv, n) == expect, "sum_of_exp_times_poly f");
    }
    // n が大きくても、和の漸化式 S(n+1) = S(n) + r^n n^d が成り立つ
    for (int rep = 0; rep < 200 && ok; rep++) {
        mint r = gen_r();
        long long d = rng() % 20, n = rng() % 1000000000000000000LL;
        check(sum_of_exp_times_poly(r, d, n + 1) == sum_of_exp_times_poly(r, d, n) + r.pow(n) * mint(n).pow(d), "大きい n");
    }
    // 無限和
    using C = Combination<mint>;
    for (int rep = 0; rep < 500 && ok; rep++) {
        mint r = rng() % 5 == 0 ? mint(0) : mint(rng() % (mint::mod() - 2) + 2);  // r != 1
        long long D = rng() % 8;
        std::vector<mint> L(D + 1);
        for (long long j = 0; j <= D; j++) L[j] = sum_of_exp_times_poly_limit(r, j);
        check(L[0] == (1 - r).inv(), "limit d = 0");
        if (D >= 1) check(L[1] == r / ((1 - r) * (1 - r)), "limit d = 1");
        long long n = rng() % 20;
        mint rest = 0;
        for (long long j = 0; j <= D; j++) rest += C::C(D, j) * mint(n).pow(D - j) * L[j];
        check(L[D] == sum_of_exp_times_poly(r, D, n) + r.pow(n) * rest, "limit の分解");
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
