#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function"

#include <iostream>

#include "../../../src/math/modint.hpp"
#include "../../../src/math/prime-counting.hpp"

using mint = static_modint<469762049>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        mint a, b;
        std::cin >> n >> a >> b;
        // f(p) = a + b p なので、素数の個数の a 倍と素数の和の b 倍を足す。個数は整数の表で足りる
        auto cnt = prime_count_table(n);
        PrimeSumTable<mint> sum(n, [](long long v) { return mint(v) * mint(v + 1) / 2 - 1; }, [](long long p) { return mint(p); });
        auto f_pe = [&](long long p, long long e) { return a * e + b * p; };
        std::cout << multiplicative_sum(n, [&](long long v) { return a * mint(cnt(v)) + b * sum(v); }, f_pe) << '\n';
    }
}
