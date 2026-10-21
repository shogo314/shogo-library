#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"

#include <iostream>
#include <string>
#include <vector>

#include "../../../src/math/f2-matrix.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (auto& row : s) std::cin >> row;
    std::string t;
    std::cin >> t;
    std::vector<bool> b(n);
    for (int i = 0; i < n; i++) b[i] = t[i] == '1';
    auto sol = F2Matrix(s).solve(b);
    if (!sol) {
        std::cout << -1 << '\n';
        return 0;
    }
    auto print = [&](const std::vector<bool>& v) {
        std::string r(m, '0');
        for (int j = 0; j < m; j++)
            if (v[j]) r[j] = '1';
        std::cout << r << '\n';
    };
    std::cout << sol->basis.size() << '\n';
    print(sol->x);
    for (const auto& v : sol->basis) print(v);
}
