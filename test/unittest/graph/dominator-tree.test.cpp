#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// dominator-tree.hpp の dominator_tree を、頂点を 1 つ取り除いて到達できるかを調べる愚直な方法と比べる
// 自己ループ・多重辺・root から到達できない頂点を含むグラフで調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/dominator-tree.hpp"

#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 8 + 1, m = rng() % 20, root = rng() % n;
        Graph<int> g(n);
        for (int i = 0; i < m; i++) g.add_directed_edge(rng() % n, rng() % n);
        // removed を通らずに root から到達できる頂点
        auto reach = [&](int removed) {
            std::vector<bool> vis(n, false);
            if (root == removed) return vis;
            std::vector<int> stk = {root};
            vis[root] = true;
            while (!stk.empty()) {
                int u = stk.back();
                stk.pop_back();
                for (const auto& e : g[u]) {
                    if (e.dst != removed && !vis[e.dst]) vis[e.dst] = true, stk.push_back(e.dst);
                }
            }
            return vis;
        };
        auto all = reach(-1);
        // dom[d][v]: d が v を支配する (d を取り除くと v に到達できない)
        std::vector<std::vector<bool>> dom(n, std::vector<bool>(n, false));
        for (int d = 0; d < n; d++) {
            auto r = reach(d);
            for (int v = 0; v < n; v++) dom[d][v] = all[v] && !r[v];
        }
        auto idom = dominator_tree(g, root);
        for (int v = 0; v < n; v++) {
            long long expect = -1;
            if (v != root && all[v]) {
                // v 以外の支配点のうち、ほかのすべての支配点に支配されるもの (v に最も近いもの)
                for (int d = 0; d < n; d++) {
                    if (d == v || !dom[d][v]) continue;
                    bool closest = true;
                    for (int e = 0; e < n; e++) {
                        if (e != v && e != d && dom[e][v] && !dom[e][d]) closest = false;
                    }
                    if (closest) expect = d;
                }
            }
            if (idom[v] != expect) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
