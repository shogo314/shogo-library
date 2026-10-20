#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include <iostream>
#include <vector>

#include "../../src/math/fps.hpp"
#include "../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<FPS<mint>> fs(n);
    long long total = 0;
    for (auto& f : fs) {
        int d;
        std::cin >> d;
        total += d;
        f.resize(d + 1);
        for (auto& x : f) std::cin >> x;
    }
    FPS<mint> g = polynomial_product(fs);
    g.resize(total + 1);
    for (long long i = 0; i <= total; i++) std::cout << g[i] << (i == total ? '\n' : ' ');
}
