#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank_mod_2"

#include <iostream>
#include <string>
#include <vector>

#include "../../../src/math/f2-matrix.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    // 列がなければ行は空なので読まない
    if (n == 0 || m == 0) {
        std::cout << 0 << '\n';
        return 0;
    }
    std::vector<std::string> s(n);
    for (auto& row : s) std::cin >> row;
    std::cout << F2Matrix(s).rank() << '\n';
}
