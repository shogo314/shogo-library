#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>

#include "../../src/data_structures/convex-hull-trick.hpp"

// x 座標を先読みしない DynamicLiChaoTree で解く
int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    DynamicLiChaoTree<long long> cht(-1000000000, 1000000001);
    for (int i = 0; i < n; i++) {
        long long a, b;
        std::cin >> a >> b;
        cht.add_line(a, b);
    }
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 0) {
            long long a, b;
            std::cin >> a >> b;
            cht.add_line(a, b);
        } else {
            long long p;
            std::cin >> p;
            std::cout << *cht.get_min(p) << '\n';
        }
    }
}
