#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include <iostream>
#include <vector>

#include "../../../src/math/linear-recurrence.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<mint> a(n);
    for (auto& x : a) std::cin >> x;
    auto c = berlekamp_massey(a);
    std::cout << c.size() << '\n';
    for (size_t i = 0; i < c.size(); i++) std::cout << c[i] << (i + 1 == c.size() ? "" : " ");
    std::cout << '\n';
}
