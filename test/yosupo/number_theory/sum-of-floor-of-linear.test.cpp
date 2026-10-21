#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <iostream>

#include "../../../src/math/floor-sum.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, m, a, b;
        std::cin >> n >> m >> a >> b;
        std::cout << floor_sum(n, m, a, b) << '\n';
    }
}
