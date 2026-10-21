#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

// FenwickTree で点加算と区間和を行う

#include <iostream>

#include "../../../src/algebra/group.hpp"
#include "../../../src/data_structures/fenwick-tree.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    FenwickTree<group::Sum<long long>> ft(n);
    while (q--) {
        int com, x, y;
        std::cin >> com >> x >> y;
        if (com == 0) {
            ft.apply(x - 1, y);
        } else {
            std::cout << ft.prod(x - 1, y) << '\n';
        }
    }
}
