#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_mod_2"

#include <iostream>
#include <string>
#include <vector>

#include "../../../src/math/f2-matrix.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (auto& row : s) std::cin >> row;
    std::cout << F2Matrix(s).det() << '\n';
}
