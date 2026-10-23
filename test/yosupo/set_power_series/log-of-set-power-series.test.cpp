#define PROBLEM "https://judge.yosupo.jp/problem/log_of_set_power_series"

#include <iostream>
#include <vector>

#include "../../../src/math/bitwise-transform.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<mint> b(1 << n);
    for (auto& x : b) std::cin >> x;
    auto c = set_power_series_log(b);
    for (int i = 0; i < (1 << n); i++) std::cout << c[i] << " \n"[i + 1 == (1 << n)];
}
