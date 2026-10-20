#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include <iostream>

#include "../../src/math/prime.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int q;
    std::cin >> q;
    while (q--) {
        long long p;
        std::cin >> p;
        std::cout << primitive_root(p) << '\n';
    }
}
