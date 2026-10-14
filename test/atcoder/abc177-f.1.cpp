#define PROBLEM "https://atcoder.jp/contests/abc177/tasks/abc177_f"
#define IGNORE

#include <iostream>
#include <limits>

#include "../../src/data_structures/lazy-segtree.hpp"

// 区間 [l, r) の i 番目の要素を f + i にする
struct UpdateAddIndexMin : monoid::Min<int> {
    using S = int;
    using F = int;
    static constexpr F ID = std::numeric_limits<int>::max();
    static S mapping(F f, S x, int l, int) { return f == ID ? x : f + l; }
    static F composition(F f, F g) { return f == ID ? g : f; }
    static F id() { return ID; }
};

int main(void) {
    int h, w;
    std::cin >> h >> w;
    LazySegTree<UpdateAddIndexMin> seg(std::vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        if (a == 0) {
            // unreachable to [a,b)
            seg.apply(a, b, 1000000000);
        } else {
            seg.apply(a, b, seg[a - 1] + 1 - a);
        }
        int ans = seg.all_prod();
        std::cout << (ans >= 1000000000 ? -1 : ans + i + 1) << '\n';
    }
}
