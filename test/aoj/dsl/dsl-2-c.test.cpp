#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/data_structures/kd-tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<std::pair<long long, long long>> p(n);
    for (auto& [x, y] : p) std::cin >> x >> y;
    KDTree<long long> kd(p);
    int q;
    std::cin >> q;
    while (q--) {
        long long sx, tx, sy, ty;
        std::cin >> sx >> tx >> sy >> ty;
        // 閉区間なので、半開区間に直す
        auto ids = kd.enumerate(sx, tx + 1, sy, ty + 1);
        std::sort(ids.begin(), ids.end());
        for (long long i : ids) std::cout << i << '\n';
        std::cout << '\n';
    }
}
