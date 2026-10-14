#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>
#include <vector>

#include "../../src/data_structures/wavelet-matrix.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    WaveletMatrix wm(a);
    while (q--) {
        long long l, r, k;
        std::cin >> l >> r >> k;
        std::cout << wm.kth_smallest(l, r, k) << '\n';
    }
}
