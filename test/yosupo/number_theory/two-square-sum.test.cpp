#define PROBLEM "https://judge.yosupo.jp/problem/two_square_sum"

#include <iostream>

#include "../../../src/math/gaussian-integer.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;
    while (q--) {
        long long n;
        std::cin >> n;
        auto res = two_square_sum(n);
        std::cout << res.size() << '\n';
        for (auto [a, b] : res) std::cout << a << ' ' << b << '\n';
    }
}
