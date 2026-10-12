#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// tree.hpp の DoublingClimbTree(Tree&&, root) (ムーブで作るコンストラクタ) を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "../../src/graph/tree.hpp"

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1;
        int root = rng() % n;
        Tree<long long> tree(n);
        std::vector<std::vector<std::pair<int, long long>>> adj(n);
        for (int i = 1; i < n; i++) {
            int p = rng() % i;
            long long w = rng() % 10;
            tree.add_edge(i, p, w);
            adj[i].push_back({p, w});
            adj[p].push_back({i, w});
        }
        DoublingClimbTree<long long> dt(std::move(tree), root);

        // 愚直: 根からの DFS で親・深さ (重みなし / 重み付き) を求める
        std::vector<int> par(n, -1), dep(n, 0);
        std::vector<long long> wdep(n, 0);
        std::vector<bool> seen(n);
        std::vector<int> stk = {root};
        seen[root] = true;
        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();
            for (auto [v, w] : adj[u]) {
                if (seen[v]) continue;
                seen[v] = true;
                par[v] = u;
                dep[v] = dep[u] + 1;
                wdep[v] = wdep[u] + w;
                stk.push_back(v);
            }
        }
        if (dt.n != n || dt.root != root) ok = false;
        for (int v = 0; v < n; v++) {
            if (dt.par[v].dst != par[v] || dt.unweighted_depth[v] != dep[v] || dt.depth[v] != wdep[v]) ok = false;
            // climb: k 個上の祖先 (存在しなければ -1)
            int x = v;
            for (int k = 0; k <= n; k++) {
                if (dt.climb(v, k) != x) ok = false;
                if (x != -1) x = par[x];
            }
        }
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                // lca: 深い方を親へ上げていく
                int a = u, b = v;
                while (a != b) {
                    if (dep[a] < dep[b]) std::swap(a, b);
                    a = par[a];
                }
                if (dt.lca(u, v) != a) ok = false;
                if (dt.dist(u, v) != wdep[u] + wdep[v] - 2 * wdep[a]) ok = false;
            }
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
