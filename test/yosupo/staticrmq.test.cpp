#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>

#include "../../src/algebra/monoid.hpp"
#include "../../src/data_structures/sparse-table.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    SparseTable<monoid::Min<int>> st(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << st.prod(l, r) << '\n';
    }
}
