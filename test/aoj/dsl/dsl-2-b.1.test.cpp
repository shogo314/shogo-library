#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"

#include <iostream>

#include "../../../src/data_structures/segtree.hpp"

int main(void) {
    int n, q;
    std::cin >> n >> q;
    SegTree<monoid::Sum<int>> seg(n);
    while (q--) {
        int com, x, y;
        std::cin >> com >> x >> y;
        if (com == 0)
            seg.apply(x - 1, y);
        else
            std::cout << seg.prod(x - 1, y) << '\n';
    }
}
