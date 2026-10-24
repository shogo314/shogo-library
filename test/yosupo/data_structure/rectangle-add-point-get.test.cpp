#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"

#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/data_structures/segtree-2d.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    // 長方形 [l, r) x [d, u) への加算を 4 隅への加算 (差分) にし、点 (x, y) の値は x 以下・y 以下の隅の和として求める
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
        }
    }
    std::vector<std::pair<long long, long long>> points;
    for (const auto& c : qs) {
        if (c.type == 0) {
            for (long long x : {c.l, c.r})
                for (long long y : {c.d, c.u}) points.emplace_back(x, y);
        }
    }
    RSumQ2D<long long> seg(points);
    for (const auto& c : qs) {
        if (c.type == 0) {
            seg.apply(c.l, c.d, c.w);
            seg.apply(c.r, c.d, -c.w);
            seg.apply(c.l, c.u, -c.w);
            seg.apply(c.r, c.u, c.w);
        } else {
            std::cout << seg.prod(0, c.l + 1, 0, c.d + 1) << '\n';
        }
    }
}
