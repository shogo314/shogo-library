#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// 約数・倍数のゼータ変換、メビウス変換と GCD・LCM 畳み込みを愚直な計算とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "../../src/math/divisor-transform.hpp"
#include "../../src/math/modint.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 60;
        std::vector<long long> a(n + 1), b(n + 1);
        for (auto& x : a) x = (long long)(rng() % 21) - 10;
        for (auto& x : b) x = (long long)(rng() % 21) - 10;

        std::vector<long long> dz(n + 1), mz(n + 1), gc(n + 1), lc(n + 1);
        dz[0] = mz[0] = a[0];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i % j == 0) dz[i] += a[j];
                if (j % i == 0) mz[i] += a[j];
                int g = std::gcd(i, j);
                long long l = (long long)i / g * j;
                gc[g] += a[i] * b[j];
                if (l <= n) lc[l] += a[i] * b[j];
            }
        }
        auto c = a;
        divisor_zeta(c);
        ok = ok && c == dz;
        divisor_mobius(c);
        ok = ok && c == a;
        c = a;
        multiple_zeta(c);
        ok = ok && c == mz;
        multiple_mobius(c);
        ok = ok && c == a;
        ok = ok && gcd_convolution(a, b) == gc && lcm_convolution(a, b) == lc;
    }

    // modint でも使える
    using mint = modint998244353;
    std::vector<mint> a = {0, 1, 2, 3, 4}, b = {0, 5, 6, 7, 8};
    // gcd: c[1] = 全体の和 - (gcd が 2, 3, 4 の分)
    auto g = gcd_convolution(a, b);
    ok = ok && g[4] == mint(4 * 8) && g[3] == mint(3 * 7) && g[2] == mint(2 * 6 + 2 * 8 + 4 * 6);
    auto l = lcm_convolution(a, b);
    ok = ok && l[1] == mint(5) && l[2] == mint(1 * 6 + 2 * 5 + 2 * 6) && l[4] == mint(1 * 8 + 2 * 8 + 4 * 5 + 4 * 6 + 4 * 8);

    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
