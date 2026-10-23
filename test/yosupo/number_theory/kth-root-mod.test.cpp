#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_mod"

#include <iostream>

#include "../../../src/math/prime.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long k, y, p;
        std::cin >> k >> y >> p;
        std::cout << kth_root_mod(k, y, p) << '\n';
    }
}
