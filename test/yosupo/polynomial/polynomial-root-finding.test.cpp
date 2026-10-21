#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_root_finding"

#include <iostream>

#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"
#include "../../../src/math/polynomial-roots.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    FPS<mint> f(n + 1);
    for (auto& x : f) std::cin >> x;
    auto roots = polynomial_roots(f);
    std::cout << roots.size() << '\n';
    for (size_t i = 0; i < roots.size(); i++) std::cout << roots[i] << (i + 1 == roots.size() ? "" : " ");
    std::cout << '\n';
}
