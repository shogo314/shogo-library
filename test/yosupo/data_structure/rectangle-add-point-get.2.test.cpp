#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"

#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/data_structures/dual-segtree-2d.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    // 値を聞かれる点を先読みし、長方形への加算をそのまま作用させる
    struct Query {
        int type;
        long long l, d, r, u, w;
    };
    std::vector<Query> qs;
    for (int i = 0; i < n; i++) {
        long long l, d, r, u, w;
        std::cin >> l >> d >> r >> u >> w;
        qs.push_back({0, l, d, r, u, w});
    }
    std::vector<std::pair<long long, long long>> points;
    for (int i = 0; i < q; i++) {
        int t;
        std::cin >> t;
        if (t == 0) {
            long long l, d, r, u, w;
            std::cin >> l >> d >> r >> u >> w;
            qs.push_back({0, l, d, r, u, w});
        } else {
            long long x, y;
            std::cin >> x >> y;
            qs.push_back({1, x, y, 0, 0, 0});
            points.emplace_back(x, y);
        }
    }
    RAddQ2D<long long> seg(points);
    for (const auto& c : qs) {
        if (c.type == 0) {
            seg.apply(c.l, c.r, c.d, c.u, c.w);
        } else {
            std::cout << seg.get(c.l, c.d) << '\n';
        }
    }
}
