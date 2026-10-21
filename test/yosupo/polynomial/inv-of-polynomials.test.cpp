#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_polynomials"

#include <iostream>

#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"
#include "../../../src/math/polynomial-gcd.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    FPS<mint> f(n), g(m);
    for (auto& x : f) std::cin >> x;
    for (auto& x : g) std::cin >> x;
    auto h = modinv(f, g);
    if (!h) {
        std::cout << -1 << '\n';
        return 0;
    }
    const int t = h->size();
    std::cout << t << '\n';
    for (int i = 0; i < t; i++) std::cout << (*h)[i] << (i + 1 == t ? "" : " ");
    std::cout << '\n';
}
