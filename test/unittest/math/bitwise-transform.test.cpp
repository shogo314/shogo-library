#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// 部分集合・上位集合のゼータ変換、メビウス変換、アダマール変換と AND・OR・XOR 畳み込み、部分集合畳み込みを愚直な計算とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/bitwise-transform.hpp"

#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/math/modint.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 500 && ok; rep++) {
        int k = rng() % 7;
        int n = 1 << k;
        std::vector<long long> a(n), b(n);
        for (auto& x : a) x = static_cast<long long>(rng() % 21) - 10;
        for (auto& x : b) x = static_cast<long long>(rng() % 21) - 10;

        std::vector<long long> sub(n), sup(n), had(n), ca(n), co(n), cx(n), cs(n);
        for (int s = 0; s < n; s++) {
            for (int t = 0; t < n; t++) {
                if ((t & s) == t) sub[s] += a[t];
                if ((s & t) == s) sup[s] += a[t];
                had[s] += (__builtin_popcount(s & t) % 2 ? -1 : 1) * a[t];
                ca[s & t] += a[s] * b[t];
                co[s | t] += a[s] * b[t];
                cx[s ^ t] += a[s] * b[t];
                if ((s & t) == 0) cs[s | t] += a[s] * b[t];
            }
        }
        auto c = a;
        subset_zeta(c);
        ok = ok && c == sub;
        subset_mobius(c);
        ok = ok && c == a;
        c = a;
        superset_zeta(c);
        ok = ok && c == sup;
        superset_mobius(c);
        ok = ok && c == a;
        c = a;
        walsh_hadamard(c);
        ok = ok && c == had;
        walsh_hadamard(c, true);
        ok = ok && c == a;
        ok = ok && and_convolution(a, b) == ca && or_convolution(a, b) == co && xor_convolution(a, b) == cx;
        ok = ok && subset_convolution(a, b) == cs;

        // modint でも同じ結果になる (XOR の逆変換は N の逆元を掛ける)
        using mint = modint998244353;
        std::vector<mint> ma(a.begin(), a.end()), mb(b.begin(), b.end());
        std::vector<mint> mx = xor_convolution(ma, mb), mand = and_convolution(ma, mb), mor = or_convolution(ma, mb), msub = subset_convolution(ma, mb);
        for (int i = 0; i < n; i++) {
            ok = ok && mx[i] == mint(cx[i]) && mand[i] == mint(ca[i]) && mor[i] == mint(co[i]) && msub[i] == mint(cs[i]);
        }

        // double の XOR 畳み込み
        std::vector<double> da(a.begin(), a.end()), db(b.begin(), b.end());
        std::vector<double> dx = xor_convolution(da, db);
        for (int i = 0; i < n; i++) ok = ok && std::abs(dx[i] - cx[i]) < 1e-6;
    }

    // 例
    ok = ok && xor_convolution(std::vector<long long>{1, 2, 3, 4}, std::vector<long long>{5, 6, 7, 8}) == std::vector<long long>{70, 68, 62, 60};
    ok = ok && or_convolution(std::vector<long long>{1, 2}, std::vector<long long>{3, 4}) == std::vector<long long>{3, 18};
    ok = ok && subset_convolution(std::vector<long long>{1, 2, 3, 4}, std::vector<long long>{5, 6, 7, 8}) == std::vector<long long>{5, 16, 22, 60};
    ok = ok && subset_convolution(std::vector<long long>{3}, std::vector<long long>{4}) == std::vector<long long>{12};

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
