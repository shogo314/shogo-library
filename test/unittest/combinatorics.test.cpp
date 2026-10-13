#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Combination の inverse・factorial・inverse_factorial・P・C・H を愚直な計算と比較する
// dynamic_modint で法を変えたときに前計算がやり直されることも確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>
#include <vector>

#include "../../src/math/combinatorics.hpp"
#include "../../src/math/modint.hpp"

// 愚直: パスカルの三角形 (mod m)
std::vector<std::vector<long long>> pascal(int n, long long m) {
    std::vector<std::vector<long long>> c(n + 1, std::vector<long long>(n + 1, 0));
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1 % m;
        for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
    }
    return c;
}

template <class M>
bool check(long long m, int lim) {
    using C = Combination<M>;
    bool ok = true;
    auto c = pascal(2 * lim, m);
    long long f = 1;
    for (int n = 0; n <= lim; n++) {
        if (n > 0) f = f * n % m;
        if ((long long)C::factorial(n).val() != f) ok = false;
        if ((C::factorial(n) * C::inverse_factorial(n)).val() != 1 % m) ok = false;
        if (n > 0 && (C::inv(n) * M(n)).val() != 1 % m) ok = false;
    }
    for (int n = 0; n <= lim; n++) {
        for (int r = -1; r <= lim + 1; r++) {
            long long ec = (r < 0 || r > n) ? 0 : c[n][r];
            if ((long long)C::C(n, r).val() != ec) ok = false;
            // nPr = nCr * r!
            long long ep = 0;
            if (r >= 0 && r <= n) {
                ep = ec;
                for (int i = 1; i <= r; i++) ep = ep * i % m;
            }
            if ((long long)C::P(n, r).val() != ep) ok = false;
            // nHr = (n+r-1)Cr (Combination は n < mod の範囲でのみ正しいので、n+r-1 < m に限る)
            if (n >= 1 && r >= 0 && r <= lim && n + r - 1 < m) {
                long long eh = c[n + r - 1][r];
                if ((long long)C::H(n, r).val() != eh) ok = false;
            }
        }
    }
    return ok;
}

int main() {
    bool ok = true;
    if (!check<static_modint<998244353>>(998244353, 60)) ok = false, std::cerr << "998244353" << std::endl;
    if (!check<static_modint<1000000007>>(1000000007, 60)) ok = false, std::cerr << "1000000007" << std::endl;

    // dynamic_modint: 法を変えるたびに前計算をやり直す。前の法より大きい n を先に使ってから小さい法に戻す
    using D = dynamic_modint<271>;
    for (long long m : {13LL, 1000000007LL, 7LL, 998244353LL, 101LL}) {
        D::set_mod(m);
        int lim = (int)std::min<long long>(m - 1, 60);  // n < m の範囲で正しい
        if (!check<D>(m, lim)) ok = false, std::cerr << "dynamic " << m << std::endl;
    }

    // 大きい n に先に extend しておいても結果は同じ
    {
        using M = static_modint<998244353>;
        Combination<M>::extend(100000);
        std::mt19937_64 rng(314);
        for (int rep = 0; rep < 1000; rep++) {
            int n = rng() % 100000 + 1;
            if ((Combination<M>::inv(n) * M(n)).val() != 1) ok = false;
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
