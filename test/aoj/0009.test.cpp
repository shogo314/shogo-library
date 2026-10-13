#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009"

// Sieve で前計算し、n 以下の素数の個数を二分探索で求める

#include <algorithm>
#include <iostream>

#include "../../src/math/prime.hpp"

int main() {
    Sieve sv(999999);
    const auto& ps = sv.primes();
    int n;
    while (std::cin >> n) {
        std::cout << std::upper_bound(ps.begin(), ps.end(), n) - ps.begin() << '\n';
    }
}
