#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../../src/graph/two-sat.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string p, cnf;
    int n, m;
    std::cin >> p >> cnf >> n >> m;
    TwoSat ts(n);
    for (int k = 0; k < m; k++) {
        // 正の a は x_a が真、負の a は x_{-a} が偽 (1-indexed)
        int a, b, zero;
        std::cin >> a >> b >> zero;
        ts.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);
    }
    if (!ts.satisfiable()) {
        std::cout << "s UNSATISFIABLE\n";
        return 0;
    }
    std::cout << "s SATISFIABLE\nv";
    const auto& x = ts.answer();
    for (int i = 0; i < n; i++) std::cout << ' ' << (x[i] ? i + 1 : -(i + 1));
    std::cout << " 0\n";
}
