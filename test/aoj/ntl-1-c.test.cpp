#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <iostream>
#include <vector>

#include "../../src/data_structures/segtree.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    SegTree<monoid::Lcm<long long>> seg(a);
    std::cout << seg.all_prod() << '\n';
}
