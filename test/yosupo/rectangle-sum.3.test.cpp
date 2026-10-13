#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

// y 座標を Compress で圧縮し、x 座標の順に点を加えながらセグメント木で区間和を取る
// クエリの y 座標は登録していないので、lower で番号を求める

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#include "../../src/algebra/monoid.hpp"
#include "../../src/data_structures/segtree.hpp"
#include "../../src/utility/compress.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> x(n), y(n), w(n);
    for (int i = 0; i < n; i++) std::cin >> x[i] >> y[i] >> w[i];
    Compress<long long> cy(y);
    // (x 座標, 符号, y の区間の左端, 右端, クエリ番号)
    std::vector<std::tuple<long long, int, int, int, int>> events;
    for (int i = 0; i < q; i++) {
        long long l, d, r, u;
        std::cin >> l >> d >> r >> u;
        int lo = cy.lower(d), hi = cy.lower(u);
        events.emplace_back(l, -1, lo, hi, i);
        events.emplace_back(r, 1, lo, hi, i);
    }
    std::sort(events.begin(), events.end());
    std::vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    std::sort(order.begin(), order.end(), [&](int a, int b) { return x[a] < x[b]; });
    SegTree<monoid::Sum<long long>> seg(cy.size());
    std::vector<long long> ans(q);
    int p = 0;
    for (auto [ex, sign, lo, hi, i] : events) {
        // x 座標が ex 未満の点をすべて加える
        while (p < n && x[order[p]] < ex) {
            int k = cy.id(y[order[p]]);
            seg.set(k, seg.get(k) + w[order[p]]);
            p++;
        }
        ans[i] += sign * seg.prod(lo, hi);
    }
    for (int i = 0; i < q; i++) std::cout << ans[i] << '\n';
}
