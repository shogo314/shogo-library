#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include <iostream>

#include "../../../src/math/modint.hpp"
#include "../../../src/math/prime-counting.hpp"

using mint = modint998244353;

int main() {
    long long n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << '\n';
        return 0;
    }
    // φ(p) = p - 1 なので、素数の和から素数の個数を引く
    auto cnt = prime_count_table(n);  // 個数は整数の表で足りる
    PrimeSumTable<mint> sum(n, [](long long v) { return mint(v) * mint(v + 1) / 2 - 1; }, [](long long p) { return mint(p); });
    auto phi_pe = [](long long p, long long e) {
        // p^e - p^(e - 1)
        return mint(p).pow(e) - mint(p).pow(e - 1);
    };
    std::cout << multiplicative_sum(n, [&](long long v) { return sum(v) - mint(cnt(v)); }, phi_pe) << '\n';
}
