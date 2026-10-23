#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// q-binomial.hpp の QBinomial を、漸化式 C(n, k)_q = C(n-1, k-1)_q + q^k C(n-1, k)_q で求めた表と比べる
// 小さい素数のすべての q で調べるので、q の位数が小さい (q-Lucas の定理を使う) 場合や q = 0, 1 も含む
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/q-binomial.hpp"

#include <iostream>
#include <vector>

int main() {
    bool ok = true;
    for (long long p : {2, 3, 5, 7, 11, 13, 31, 101}) {
        for (long long q = 0; q < p && ok; q++) {
            const long long n_max = p - 1;
            std::vector<std::vector<long long>> dp(n_max + 1, std::vector<long long>(n_max + 1, 0));
            for (long long n = 0; n <= n_max; n++) {
                dp[n][0] = 1;
                long long qk = 1;
                for (long long k = 1; k <= n; k++) {
                    qk = qk * q % p;
                    dp[n][k] = (dp[n - 1][k - 1] + qk * dp[n - 1][k]) % p;
                }
            }
            QBinomial qb(q, p, n_max);
            for (long long n = 0; n <= n_max; n++) {
                for (long long k = -1; k <= n + 1; k++) {
                    long long expect = 0 <= k && k <= n ? dp[n][k] : 0;
                    if (qb(n, k) != expect) ok = false;
                }
            }
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
