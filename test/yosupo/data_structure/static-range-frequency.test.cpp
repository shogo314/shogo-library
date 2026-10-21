#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/wavelet-matrix.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    WaveletMatrix wm(a);
    while (q--) {
        long long l, r, x;
        std::cin >> l >> r >> x;
        std::cout << wm.count(l, r, x) << '\n';
    }
}
