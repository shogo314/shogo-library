#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include <iostream>
#include <vector>

#include "../../../src/math/divisor-transform.hpp"
#include "../../../src/math/modint.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    using mint = modint998244353;
    int n;
    std::cin >> n;
    std::vector<mint> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> b[i];
    std::vector<mint> c = gcd_convolution(a, b);
    for (int i = 1; i <= n; i++) std::cout << c[i] << " \n"[i == n];
}
