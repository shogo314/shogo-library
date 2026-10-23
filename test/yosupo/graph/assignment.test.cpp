#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include <vector>

#include "../../../src/graph/hungarian.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<long long>> a(n, std::vector<long long>(n));
    for (auto& row : a)
        for (auto& x : row) std::cin >> x;
    auto res = hungarian(a);
    std::cout << res.cost << '\n';
    for (int i = 0; i < n; i++) std::cout << res.match[i] << " \n"[i == n - 1];
}
