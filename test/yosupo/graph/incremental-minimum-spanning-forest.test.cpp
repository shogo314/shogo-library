#define PROBLEM "https://judge.yosupo.jp/problem/incremental_minimum_spanning_forest"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/data_structures/link-cut-tree.hpp"

// (重み, 辺の番号) の最大。辺のない頂点は (-1, -1)
struct MaxEdge {
    using S = std::pair<long long, int>;
    static S op(const S& a, const S& b) { return std::max(a, b); }
    static S e() { return {-1, -1}; }
};

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    // 頂点 0..n-1 と、辺 i を表す頂点 n + i を持ち、辺 i は u - (n + i) - v とつなぐ
    LinkCutTree<MaxEdge> lct(n + m);
    std::vector<int> eu(m), ev(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        std::cin >> u >> v >> w;
        eu[i] = u, ev[i] = v;
        lct.set(n + i, {w, i});
        int removed = -1;
        if (u == v) {
            removed = i;
        } else if (lct.connected(u, v)) {
            // u と v を結ぶパス上の最も重い辺より軽ければ入れ替える
            auto [mw, j] = lct.prod(u, v);
            if (mw < w) {
                removed = i;
            } else {
                lct.cut(eu[j], n + j);
                lct.cut(n + j, ev[j]);
                removed = j;
            }
        }
        if (removed != i) {
            lct.link(u, n + i);
            lct.link(n + i, v);
        }
        std::cout << removed << (i + 1 < m ? ' ' : '\n');
    }
}
