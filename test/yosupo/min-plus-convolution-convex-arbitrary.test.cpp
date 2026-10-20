#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"

#include <iostream>
#include <vector>

#include "../../src/dp/monge.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> a(n), b(m);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    auto c = min_plus_convolution_convex_arbitrary(a, b);
    for (size_t i = 0; i < c.size(); i++) std::cout << c[i] << (i + 1 == c.size() ? '\n' : ' ');
}
