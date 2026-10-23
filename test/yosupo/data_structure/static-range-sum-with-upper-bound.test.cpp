#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum_with_upper_bound"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/wavelet-matrix.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    WeightedWaveletMatrix wm(a);
    while (q--) {
        long long l, r, x;
        std::cin >> l >> r >> x;
        // x 以下は [0, x + 1)
        std::cout << wm.count(l, r, 0, x + 1) << ' ' << wm.sum(l, r, 0, x + 1) << '\n';
    }
}
