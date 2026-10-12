#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_B"

#include <iostream>
#include <vector>

#include "../../src/data_structures/segtree.hpp"

// 最小値・最大値とその位置を持つ。値は位置の要素と一致するはず
int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    using MinM = monoid::MinWith<long long>;
    using MaxM = monoid::MaxWith<long long>;
    std::vector<MinM::S> init(n);
    for (int i = 0; i < n; i++) init[i] = {a[i], i};
    SegTree<MinM> seg_min(init);
    SegTree<MaxM> seg_max(init);
    int q;
    std::cin >> q;
    while (q--) {
        int com, b, e;
        std::cin >> com >> b >> e;
        auto [v, i] = (com == 0 ? seg_min.prod(b, e) : seg_max.prod(b, e));
        if (!(b <= i && i < e && a[i] == v)) return 1;
        std::cout << v << '\n';
    }
}
