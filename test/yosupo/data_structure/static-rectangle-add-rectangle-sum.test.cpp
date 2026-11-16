#define PROBLEM "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"

#include "../../../src/offline/static-rectangle-add-rectangle-sum.hpp"

#include <iostream>

#include "../../../src/math/modint.hpp"

int main() {
    long long n, q;
    std::cin >> n >> q;
    StaticRectangleAddRectangleSum<modint998244353> solver;
    while (n--) {
        long long l, d, r, u, w;
        std::cin >> l >> d >> r >> u >> w;
        solver.add(l, d, r, u, modint998244353(w));
    }
    while (q--) {
        long long l, d, r, u;
        std::cin >> l >> d >> r >> u;
        solver.query(l, d, r, u);
    }
    for (auto x : solver.solve()) std::cout << x << '\n';
}
