#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/lazy-segtree.hpp"

// 区間加算・区間最小値とその位置 (AddMinWith) で解く。最小値だけを出力する
int main() {
    int n, q;
    std::cin >> n >> q;
    using A = acted_monoid::AddMinWith<long long>;
    std::vector<A::S> init(n);
    for (int i = 0; i < n; i++) init[i] = {0, i};
    LazySegTree<A> seg(init);
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 0) {
            int s, t;
            long long x;
            std::cin >> s >> t >> x;
            seg.apply(s, t + 1, x);
        } else {
            int s, t;
            std::cin >> s >> t;
            auto [v, i] = seg.prod(s, t + 1);
            if (!(s <= i && i <= t && seg.get(i).first == v)) return 1;
            std::cout << v << '\n';
        }
    }
}
