#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// lagrange_interpolation を、多項式を直接計算した値と比べる (x が標本点の場合も)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/math/lagrange-interpolation.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../src/math/modint.hpp"

using mint = static_modint<998244353>;

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 10 + 1;
        std::vector<mint> coef(n);
        for (auto& c : coef) c = rng() % mint::mod();
        auto f = [&](mint x) {
            mint r = 0;
            for (int i = n - 1; i >= 0; i--) r = r * x + coef[i];
            return r;
        };
        std::vector<mint> y(n);
        for (int i = 0; i < n; i++) y[i] = f(i);
        for (int t = 0; t < 20; t++) {
            mint x = t < 10 ? mint(t) : mint(rng() % mint::mod());
            if (lagrange_interpolation(y, x) != f(x)) ok = false;
        }
    }
    // 1^3 + ... + m^3 = (m(m+1)/2)^2 は m の 4 次式
    {
        std::vector<mint> y(5);
        for (int m = 0; m < 5; m++) y[m] = mint(m) * m * m + (m > 0 ? y[m - 1] : mint(0));
        long long m = 1000000000000LL;
        mint s = mint(m) * mint(m + 1) / 2;
        if (lagrange_interpolation(y, mint(m)) != s * s) ok = false;
    }
    if (lagrange_interpolation(std::vector<mint>{}, mint(5)) != 0) ok = false;
    if (ok) std::cout << "Hello World" << std::endl;
}
