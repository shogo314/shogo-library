#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "../../src/data_structures/persistent-segtree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::array<int, 3>> XYW(N);
    for (auto& [X, Y, W] : XYW) {
        std::cin >> X >> Y >> W;
    }
    std::sort(XYW.begin(), XYW.end());
    std::vector<int> xs(N), ys(N);
    for (int i = 0; i < N; i++) {
        xs[i] = XYW[i][0];
        ys[i] = XYW[i][1];
    }
    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    auto y_index = [&](int y) { return int(std::lower_bound(ys.begin(), ys.end(), y) - ys.begin()); };
    // seg[i] は x 座標の小さい方から i 個の点を、y 座標の位置に足した版
    std::vector<PersistentSegTree<monoid::Sum<long long>>> seg(N + 1);
    seg[0] = PersistentSegTree<monoid::Sum<long long>>(ys.size());
    for (int i = 0; i < N; i++) {
        seg[i + 1] = seg[i].apply(y_index(XYW[i][1]), XYW[i][2]);
    }
    while (Q--) {
        int L, D, R, U;
        std::cin >> L >> D >> R >> U;
        int l = std::lower_bound(xs.begin(), xs.end(), L) - xs.begin();
        int r = std::lower_bound(xs.begin(), xs.end(), R) - xs.begin();
        int d = y_index(D), u = y_index(U);
        std::cout << seg[r].prod(d, u) - seg[l].prod(d, u) << '\n';
    }
}
