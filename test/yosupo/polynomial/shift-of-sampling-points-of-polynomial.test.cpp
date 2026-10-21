#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

#include <iostream>
#include <vector>

#include "../../../src/math/modint.hpp"
#include "../../../src/math/multipoint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    long long c;
    std::cin >> n >> m >> c;
    std::vector<mint> ys(n);
    for (auto& y : ys) std::cin >> y;
    auto res = sample_point_shift(ys, mint(c), m);
    for (int i = 0; i < m; i++) std::cout << res[i] << (i + 1 == m ? '\n' : ' ');
}
