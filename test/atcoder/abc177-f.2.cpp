#define PROBLEM "https://atcoder.jp/contests/abc177/tasks/abc177_f"
#define IGNORE

#include <iostream>
#include <limits>

#include "../../src/data_structures/lazy-segtree.hpp"

int main(void) {
    int h, w;
    std::cin >> h >> w;
    int id = std::numeric_limits<int>::max();
    LazySegTree seg(std::vector<int>(w, 0), ActedMonoid([](int a, int b) { return std::min(a, b); }, id, [&](int f, int x, int l, int) { return f == id ? x : f + l; }, [&](int f, int g) { return f == id ? g : f; }, id));
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
