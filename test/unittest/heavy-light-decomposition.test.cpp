#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// HeavyLightDecomposition を、親を 1 つずつたどる愚直な実装とランダムに比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/heavy-light-decomposition.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "../../src/graph/graph.hpp"
#include "../../src/graph/tree.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 500 && ok; rep++) {
        int n = rng() % 30 + 1;
        int root = rng() % n;
        // ランダムな木 (細長い木も作る)
        std::vector<int> perm(n);
        for (int i = 0; i < n; i++) perm[i] = i;
        std::shuffle(perm.begin(), perm.end(), rng);
        Graph<int> g(n);
        Tree<int> t(n);
        bool line = rng() % 4 == 0;
        for (int i = 1; i < n; i++) {
            int p = line ? i - 1 : rng() % i;
            g.add_edge(perm[i], perm[p]);
            t.add_edge(perm[i], perm[p]);
        }
        HeavyLightDecomposition hld(g, root);

        // 愚直: 根からの親と深さ
        std::vector<int> par(n, -1), dep(n, 0), bfs = {root};
        for (int i = 0; i < (int)bfs.size(); i++) {
            int v = bfs[i];
            for (int u : g[v]) {
                if (u == par[v]) continue;
                par[u] = v, dep[u] = dep[v] + 1;
                bfs.push_back(u);
            }
        }
        auto naive_path = [&](int u, int v) {
            std::vector<int> a, b;
            while (u != v) {
                if (dep[u] >= dep[v])
                    a.push_back(u), u = par[u];
                else
                    b.push_back(v), v = par[v];
            }
            a.push_back(u);
            a.insert(a.end(), b.rbegin(), b.rend());
            return a;
        };

        // index は 0, ..., n-1 の並べ替えで、vertex がその逆
        std::vector<bool> seen(n);
        for (int v = 0; v < n; v++) {
            int i = hld.index(v);
            if (i < 0 || i >= n || seen[i] || hld.vertex(i) != v)
                ok = false;
            else
                seen[i] = true;
            if (hld.parent(v) != par[v] || hld.depth(v) != dep[v]) ok = false;
        }
        // 部分木: 区間 [l, r) の頂点が v の子孫と一致する
        for (int v = 0; v < n; v++) {
            auto [l, r] = hld.subtree(v);
            if (r - l != hld.subtree_size(v)) ok = false;
            for (int u = 0; u < n; u++) {
                int x = u;
                while (x != -1 && x != v) x = par[x];
                bool desc = x == v;
                if (desc != (l <= hld.index(u) && hld.index(u) < r)) ok = false;
            }
        }
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                auto p = naive_path(u, v);
                int d = p.size() - 1;
                int w = *std::min_element(p.begin(), p.end(), [&](int a, int b) { return dep[a] < dep[b]; });
                if (hld.lca(u, v) != w || hld.dist(u, v) != d) ok = false;
                for (int k = 0; k <= d + 1; k++) {
                    int expect = k <= d ? p[k] : -1;
                    if (hld.jump(u, v, k) != expect) ok = false;
                }
                // path が返す区間をつなげると、u から v への頂点の列になる
                std::vector<int> got, got_edge;
                for (auto [a, b] : hld.path(u, v)) {
                    int step = a <= b ? 1 : -1;
                    for (int i = a;; i += step) {
                        got.push_back(hld.vertex(i));
                        if (i == b) break;
                    }
                }
                if (got != p) ok = false;
                // 辺のパス: lca を除いた頂点 (その頂点と親を結ぶ辺) の列
                for (auto [a, b] : hld.path(u, v, true)) {
                    int step = a <= b ? 1 : -1;
                    for (int i = a;; i += step) {
                        got_edge.push_back(hld.vertex(i));
                        if (i == b) break;
                    }
                }
                std::vector<int> expect_edge;
                for (int x : p) {
                    if (x != w) expect_edge.push_back(x);
                }
                if (got_edge != expect_edge) ok = false;
            }
            for (int k = 0; k <= n; k++) {
                int x = u;
                for (int i = 0; i < k && x != -1; i++) x = par[x];
                if (hld.hop(u, k) != x) ok = false;
            }
        }
        // Tree や RootedTree からも同じものが作れる
        HeavyLightDecomposition h2(t, root);
        HeavyLightDecomposition h3(t.set_root(root), root);
        for (int v = 0; v < n; v++) {
            if (h2.index(v) != hld.index(v) || h3.lca(v, root) != root) ok = false;
        }
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
