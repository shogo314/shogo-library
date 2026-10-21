#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include <iostream>

#include "../../../src/math/sqrt.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        unsigned long long a;
        long long k;
        std::cin >> a >> k;
        std::cout << kth_root(a, k) << '\n';
    }
}
