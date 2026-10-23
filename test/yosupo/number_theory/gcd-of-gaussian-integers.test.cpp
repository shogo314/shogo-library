#define PROBLEM "https://judge.yosupo.jp/problem/gcd_of_gaussian_integers"

#include <iostream>

#include "../../../src/math/gaussian-integer.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long a1, b1, a2, b2;
        std::cin >> a1 >> b1 >> a2 >> b2;
        auto g = gaussian_gcd(GaussianInteger<long long>(a1, b1), GaussianInteger<long long>(a2, b2));
        std::cout << g.a << ' ' << g.b << '\n';
    }
}
