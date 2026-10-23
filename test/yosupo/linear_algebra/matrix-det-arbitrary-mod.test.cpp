#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_arbitrary_mod"

#include <iostream>
#include <vector>

#include "../../../src/math/matrix.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    long long mod;
    std::cin >> n >> mod;
    std::vector<std::vector<long long>> a(n, std::vector<long long>(n));
    for (auto& row : a)
        for (auto& x : row) std::cin >> x;
    std::cout << Matrix<long long>(a).det_mod(mod) << '\n';
}
