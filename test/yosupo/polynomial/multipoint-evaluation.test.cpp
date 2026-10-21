#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include <iostream>
#include <vector>

#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"
#include "../../../src/math/multipoint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    FPS<mint> f(n);
    for (auto& x : f) std::cin >> x;
    std::vector<mint> xs(m);
    for (auto& x : xs) std::cin >> x;
    auto res = multipoint_evaluation(f, xs);
    for (int i = 0; i < m; i++) std::cout << res[i] << (i + 1 == m ? '\n' : ' ');
}
