#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "../../src/data_structures/lazy-segtree.hpp"

// x 方向に走査し、y 方向の各区間が何枚の長方形に覆われているかを持つ
// 区間加算・区間最小値とその個数 (個数は y 方向の長さ) で、覆われていない長さが分かる
int main() {
    int n;
    std::cin >> n;
    std::vector<std::array<long long, 4>> rect(n);
    std::vector<long long> ys;
    ys.reserve(2 * n);
    for (auto& [l, d, r, u] : rect) {
        std::cin >> l >> d >> r >> u;
        ys.push_back(d);
        ys.push_back(u);
    }
    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    int m = (int)ys.size() - 1;
    using A = acted_monoid::AddMinCount<int, long long>;
    std::vector<A::S> init(m);
    for (int i = 0; i < m; i++) init[i] = {0, ys[i + 1] - ys[i]};
    LazySegTree<A> seg(init);
    const long long total = ys.back() - ys.front();

    // (x, 加える値, y の区間 [lo, hi))
    std::vector<std::array<long long, 4>> events;
    events.reserve(2 * n);
    for (auto [l, d, r, u] : rect) {
        long long lo = std::lower_bound(ys.begin(), ys.end(), d) - ys.begin();
        long long hi = std::lower_bound(ys.begin(), ys.end(), u) - ys.begin();
        events.push_back({l, 1, lo, hi});
        events.push_back({r, -1, lo, hi});
    }
    std::sort(events.begin(), events.end());
    long long ans = 0;
    for (int i = 0; i < (int)events.size(); i++) {
        auto [x, v, lo, hi] = events[i];
        seg.apply((int)lo, (int)hi, (int)v);
        if (i + 1 < (int)events.size()) {
            auto [mn, cnt] = seg.all_prod();
            long long covered = total - (mn == 0 ? cnt : 0);
            ans += covered * (events[i + 1][0] - x);
        }
    }
    std::cout << ans << '\n';
}
