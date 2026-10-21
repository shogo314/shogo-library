#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_D"
#define ERROR "1e-4"

// 最適二分探索木を、ダミーの鍵 d_0, ..., d_n を葉とする区間 DP として knuth_yao で解く
// ダミーの鍵の区間 [i, j) は鍵 k_{i+1}, ..., k_{j-1} を含み、根を k_m にすると [i, m) と [m, j) に分かれる
// 部分木の中の鍵はすべて深さが 1 増えるので、w(i, j) は区間に含まれる確率の和

#include <iomanip>
#include <iostream>
#include <vector>

#include "../../../src/dp/monge.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<double> p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> p[i];
    for (int i = 0; i <= n; i++) std::cin >> q[i];
    // 確率の累積和 (ダミーの鍵 d_i と鍵 k_i を交互に並べる)
    std::vector<double> sq(n + 2, 0), sp(n + 2, 0);
    for (int i = 0; i <= n; i++) sq[i + 1] = sq[i] + q[i];
    for (int i = 0; i <= n; i++) sp[i + 1] = sp[i] + (i == 0 ? 0 : p[i]);
    auto dp = knuth_yao(
        n + 1, [&](long long i) { return q[i]; },
        [&](long long i, long long j) { return sq[j] - sq[i] + sp[j] - sp[i + 1]; });
    std::cout << std::fixed << std::setprecision(8) << dp[0][n + 1] << '\n';
}
