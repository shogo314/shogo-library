#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/data_structures/merge-sort-tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::array<int, 3>> XYW(N);
    for (auto& [X, Y, W] : XYW) {
        std::cin >> X >> Y >> W;
    }
    std::sort(XYW.begin(), XYW.end());
    std::vector<int> v(N);
    // {値, キー} のリストから作る
    std::vector<std::pair<long long, int>> value_key(N);
    for (int i = 0; i < N; i++) {
        v[i] = XYW[i][0];
        value_key[i] = {XYW[i][2], XYW[i][1]};
    }
    MergeSortTree<group::Sum<long long>, int> mstree(value_key);
    while (Q--) {
        int L, D, R, U;
        std::cin >> L >> D >> R >> U;
        int l = std::lower_bound(v.begin(), v.end(), L) - v.begin();
        int r = std::lower_bound(v.begin(), v.end(), R) - v.begin();
        std::cout << mstree.prod(l, r, D, U) << '\n';
    }
}
