#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_B"

#include <iostream>
#include <vector>

#include "../../src/data_structures/segtree.hpp"

// 最小値と最大値の組 {min, max} を 1 本のセグメント木で持つ
int main() {
    int n;
    std::cin >> n;
    using M = monoid::MinMax<long long>;
    std::vector<M::S> a(n);
    for (auto& [mn, mx] : a) {
        std::cin >> mn;
        mx = mn;
    }
    SegTree<M> seg(a);
    int q;
    std::cin >> q;
    while (q--) {
        int com, b, e;
        std::cin >> com >> b >> e;
        auto [mn, mx] = seg.prod(b, e);
        std::cout << (com == 0 ? mn : mx) << '\n';
    }
}
