#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// 分割数・ベルヌーイ数・スターリング数・ベル数を、O(n^2) の漸化式で 1 つずつ求めたものと比べる
// large_factorial を、1 から順に掛けた値とウィルソンの定理で確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/combinatorial-sequences.hpp"

#include <iostream>
#include <vector>

#include "../../../src/math/combinatorics.hpp"
#include "../../../src/math/modint.hpp"

using mint = static_modint<998244353>;
using C = Combination<mint>;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

int main() {
    const int N = 80;
    // 分割数: 使う数を 1, 2, ... と増やしながら数える
    std::vector<mint> p(N + 1, 0);
    p[0] = 1;
    for (int k = 1; k <= N; k++)
        for (int i = k; i <= N; i++) p[i] += p[i - k];
    // ベルヌーイ数: Σ_{k=0}^{m} C(m+1, k) B_k = 0 (m >= 1)
    std::vector<mint> B(N + 1);
    B[0] = 1;
    for (int m = 1; m <= N; m++) {
        mint s = 0;
        for (int k = 0; k < m; k++) s += C::C(m + 1, k) * B[k];
        B[m] = -s / mint(m + 1);
    }
    // スターリング数: s(n+1, k) = s(n, k-1) - n s(n, k)、S(n+1, k) = k S(n, k) + S(n, k-1)
    std::vector<std::vector<mint>> s1(N + 1, std::vector<mint>(N + 1, 0)), s2 = s1;
    s1[0][0] = s2[0][0] = 1;
    for (int n = 0; n < N; n++) {
        for (int k = 0; k <= n + 1; k++) {
            s1[n + 1][k] = (k > 0 ? s1[n][k - 1] : mint(0)) - mint(n) * s1[n][k];
            s2[n + 1][k] = mint(k) * s2[n][k] + (k > 0 ? s2[n][k - 1] : mint(0));
        }
    }
    for (int n = 0; n <= N && ok; n++) {
        auto pn = partition_numbers<mint>(n);
        auto bn = bernoulli_numbers<mint>(n);
        auto bell = bell_numbers<mint>(n);
        check(static_cast<int>(pn.size()) == n + 1 && static_cast<int>(bn.size()) == n + 1 && static_cast<int>(bell.size()) == n + 1, "長さ");
        for (int i = 0; i <= n; i++) {
            check(pn[i] == p[i], "partition_numbers");
            check(bn[i] == B[i], "bernoulli_numbers");
            mint b = 0;
            for (int k = 0; k <= i; k++) b += s2[i][k];
            check(bell[i] == b, "bell_numbers");
        }
        auto f = stirling_first<mint>(n), g = stirling_second<mint>(n);
        check(static_cast<int>(f.size()) == n + 1 && static_cast<int>(g.size()) == n + 1, "スターリング数の長さ");
        for (int k = 0; k <= n; k++) {
            check(f[k] == s1[n][k], "stirling_first");
            check(g[k] == s2[n][k], "stirling_second");
        }
    }
    // よく知られた値
    check(partition_numbers<mint>(100)[100] == mint(190569292), "p(100) = 190569292");
    check(bernoulli_numbers<mint>(1)[1] == -mint(2).inv(), "B_1 = -1/2");
    check(bell_numbers<mint>(10)[10] == mint(115975), "B_10 = 115975");
    // large_factorial: 1 から順に掛けた値と比べる (v が変わる境目の前後も含む)。NTT に向かない法 10^9 + 7 でも調べる
    {
        mint f = 1;
        long long next = 0;
        std::vector<long long> ns = {0, 1, 2, 5, 6, 7, 12, 19, 20, 21, 71, 72, 73, 1000, 4096, 65535, 65536, 65537, 200000};
        for (long long n = 0; n <= 200000 && ok; n++) {
            if (n > 0) f *= mint(n);
            if (next < static_cast<long long>(ns.size()) && ns[next] == n) {
                check(large_factorial<mint>(n) == f, "large_factorial");
                next++;
            }
        }
        using mint2 = static_modint<1000000007>;
        mint2 g = 1;
        for (long long n = 1; n <= 100000; n++) g *= mint2(n);
        check(large_factorial<mint2>(100000) == g, "large_factorial mod 10^9 + 7");
        // ウィルソンの定理 (p - 1)! ≡ -1
        check(large_factorial<mint>(998244352) == mint(-1), "large_factorial (p - 1)!");
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
