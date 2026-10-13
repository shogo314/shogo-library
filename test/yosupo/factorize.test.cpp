#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>

#include "../../src/math/prime.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int q;
    std::cin >> q;
    while (q--) {
        long long a;
        std::cin >> a;
        auto f = factorize(a);
        int k = 0;
        for (auto [p, e] : f) k += e;
        std::cout << k;
        for (auto [p, e] : f) {
            for (int i = 0; i < e; i++) std::cout << ' ' << p;
        }
        std::cout << '\n';
    }
}
