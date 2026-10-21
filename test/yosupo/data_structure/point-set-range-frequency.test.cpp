#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_frequency"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/counter-segtree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int& x : a) std::cin >> x;
    CounterSegTree<int> seg(a);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int k, v;
            std::cin >> k >> v;
            seg.set(k, v);
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            std::cout << seg.find(l, r, x).second << '\n';
        }
    }
}
