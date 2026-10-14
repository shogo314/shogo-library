#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "../../src/data_structures/wavelet-matrix.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::array<long long, 3>> XYW(N);
    for (auto& [X, Y, W] : XYW) {
        std::cin >> X >> Y >> W;
    }
    std::sort(XYW.begin(), XYW.end());
    // x 座標の順に並べた点の y 座標を値、重さを重みにする
    std::vector<long long> xs(N), ys(N), ws(N);
    for (int i = 0; i < N; i++) {
        xs[i] = XYW[i][0];
        ys[i] = XYW[i][1];
        ws[i] = XYW[i][2];
    }
    WeightedWaveletMatrix wm(ys, ws);
    while (Q--) {
        long long L, D, R, U;
        std::cin >> L >> D >> R >> U;
        long long l = std::lower_bound(xs.begin(), xs.end(), L) - xs.begin();
        long long r = std::lower_bound(xs.begin(), xs.end(), R) - xs.begin();
        std::cout << wm.sum(l, r, D, U) << '\n';
    }
}
