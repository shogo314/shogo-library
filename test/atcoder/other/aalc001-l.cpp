#define PROBLEM "https://atcoder.jp/contests/aalc001/tasks/aalc001_l"
#define IGNORE

#include <iostream>
#include <vector>

#include "../../../src/data_structures/lazy-segtree.hpp"

int main(void) {
    int n, q;
    std::cin >> n >> q;
    // 成分 0, 1, 2 が配列 A, B, C で、入れ替えは成分の入れ替え
    using M = monoid::PrefixSumMax<long long>;
    using A = acted_monoid::Rearrange<M, 3>;
    std::vector<A::S> init(n);
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            long long x;
            std::cin >> x;
            init[i][j] = M::S(x);
        }
    }
    LazySegTree<A> seg(init);
    while (q--) {
        int t;
        std::cin >> t;
        if (t <= 3) {
            int l, r;
            std::cin >> l >> r;
            l--;
            if (t == 1) seg.apply(l, r, A::swap(0, 1));
            if (t == 2) seg.apply(l, r, A::swap(1, 2));
            if (t == 3) seg.apply(l, r, A::swap(2, 0));
        } else {
            int i;
            std::cin >> i;
            i--;
            // A[i..j] の和が初めて正になる j
            int j = seg.max_right(i, [](const A::S& s) { return s[0].max <= 0; });
            std::cout << j + 1 << '\n';
        }
    }
}
