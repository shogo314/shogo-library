#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_2_64"

// convolution_u64 で解く (.1 は convolution_ll を 31 ビットずつに分けて 9 回使う)

#include <iostream>
#include <vector>

#include "../../../src/math/convolution.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<unsigned long long> a(n), b(m);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    auto c = convolution_u64(a, b);
    for (int i = 0; i < static_cast<int>(c.size()); i++) std::cout << c[i] << " \n"[i + 1 == static_cast<int>(c.size())];
}
