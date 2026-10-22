#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include <iostream>

#include "../../../src/math/fps.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    FPS<mint> f(n), g(m);
    for (auto& x : f) std::cin >> x;
    for (auto& x : g) std::cin >> x;
    auto [q, r] = divmod(f, g);
    std::cout << q.size() << ' ' << r.size() << '\n';
    for (int i = 0; i < static_cast<int>(q.size()); i++) std::cout << q[i] << (i + 1 == static_cast<int>(q.size()) ? "" : " ");
    std::cout << '\n';
    for (int i = 0; i < static_cast<int>(r.size()); i++) std::cout << r[i] << (i + 1 == static_cast<int>(r.size()) ? "" : " ");
    std::cout << '\n';
}
