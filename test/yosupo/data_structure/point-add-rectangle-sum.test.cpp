#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

#include "../../../src/data_structures/segtree-2d.hpp"

int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;
    std::vector<std::pair<long long, long long>> points;
    std::vector<std::tuple<int, long long, long long, long long, long long>> queries;
    for (int i = 0; i < n; i++) {
        long long x, y, w;
        std::cin >> x >> y >> w;
        points.emplace_back(x, y);
        queries.emplace_back(0, x, y, w, 0);
    }
    for (int i = 0; i < q; i++) {
        int t;
        std::cin >> t;
        if (t == 0) {
            long long x, y, w;
            std::cin >> x >> y >> w;
            points.emplace_back(x, y);
            queries.emplace_back(0, x, y, w, 0);
        } else {
            long long l, d, r, u;
            std::cin >> l >> d >> r >> u;
            queries.emplace_back(1, l, d, r, u);
        }
    }
    RSumQ2D<long long> seg(points);
    for (auto [t, a, b, c, d] : queries) {
        if (t == 0) {
            seg.apply(a, b, c);
        } else {
            std::cout << seg.prod(a, c, b, d) << '\n';
        }
    }
}
