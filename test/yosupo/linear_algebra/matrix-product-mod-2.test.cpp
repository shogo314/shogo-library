#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"

#include <iostream>
#include <string>
#include <vector>

#include "../../../src/math/f2-matrix.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> a(n), b(m);
    for (auto& row : a) std::cin >> row;
    for (auto& row : b) std::cin >> row;
    std::cout << F2Matrix(a) * F2Matrix(b) << '\n';
}
