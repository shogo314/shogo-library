#define PROBLEM "https://judge.yosupo.jp/problem/q_binomial_coefficient_prime_mod"

#include <algorithm>
#include <cstdio>
#include <vector>

#include "../../../src/math/q-binomial.hpp"

int main() {
    // 問い合わせが 10^6 個あるので scanf と printf を使う
    int t;
    long long m, q;
    if (std::scanf("%d %lld %lld", &t, &m, &q) != 3) return 0;
    std::vector<long long> n(t), k(t);
    long long n_max = 0;
    for (int i = 0; i < t; i++) {
        if (std::scanf("%lld %lld", &n[i], &k[i]) != 2) return 0;
        n_max = std::max(n_max, n[i]);
    }
    QBinomial qb(q, m, n_max);
    for (int i = 0; i < t; i++) std::printf("%lld\n", qb(n[i], k[i]));
}
