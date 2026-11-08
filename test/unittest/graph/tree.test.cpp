#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// tree.hpp の DoublingClimbTree(Tree&&, root) (ムーブで作るコンストラクタ) を愚直な実装とランダムに比較する
// 親のリストから作るコンストラクタは、std::vector<int> と std::vector<long long> の両方で作って比べる
// graph() で取り出した Graph に shortest_path_dijkstra を使い、dist と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/tree.hpp"

#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "../../../src/graph/shortest-path.hpp"

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1;
        int root = rng() % n;
        Tree<long long> tree(n);
        std::vector<std::vector<std::pair<int, long long>>> adj(n);
        std::vector<int> par_int;
        std::vector<long long> par_ll;
        for (int i = 1; i < n; i++) {
            int p = rng() % i;
            par_int.push_back(p);
            par_ll.push_back(p);
            long long w = rng() % 10;
            tree.add_edge(i, p, w);
            adj[i].push_back({p, w});
            adj[p].push_back({i, w});
        }
        DoublingClimbTree<long long> dt(std::move(tree), root);

        // 親のリストから作る (根は 0、padding は 0)。要素の型によらず同じ木になる
        DoublingClimbTree<int> from_int(par_int, 0);
        DoublingClimbTree<int> from_ll(par_ll, 0);
        RootedTree<int> rooted_ll(par_ll, 0);
        for (int u = 0; u < n; u++) {
            if (from_int.parent_edge(u).dst != from_ll.parent_edge(u).dst || rooted_ll.parent_edge(u).dst != from_ll.parent_edge(u).dst) ok = false;
            if (u > 0 && from_ll.parent_edge(u).dst != par_ll[u - 1]) ok = false;
            for (int v = 0; v < n; v++) {
                if (from_int.lca(u, v) != from_ll.lca(u, v)) ok = false;
            }
        }

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
        if (dt.size() != n || dt.root() != root) ok = false;
        std::vector<long long> subtree_size(n), unweighted_height(n), height(n);
        for (int u = 0; u < n; u++) {
            for (int v = u; v != -1; v = par[v]) {
                subtree_size[v]++;
                unweighted_height[v] = std::max(unweighted_height[v], static_cast<long long>(dep[u] - dep[v]));
                height[v] = std::max(height[v], wdep[u] - wdep[v]);
            }
        }
        std::vector<int> pre_pos(n), post_pos(n), child_count(n);
        if (static_cast<int>(dt.preorder().size()) != n || static_cast<int>(dt.postorder().size()) != n) ok = false;
        for (int i = 0; i < n; i++) pre_pos[dt.preorder()[i]] = i, post_pos[dt.postorder()[i]] = i;
        for (int v = 0; v < n; v++) {
            if (dt.parent_edge(v).dst != par[v] || dt.unweighted_depth(v) != dep[v] || dt.depth(v) != wdep[v]) ok = false;
            if (dt.subtree_size(v) != subtree_size[v] || dt.unweighted_height(v) != unweighted_height[v] || dt.height(v) != height[v]) ok = false;
            for (const auto& e : dt.children(v)) {
                if (par[e.dst] != v || pre_pos[v] >= pre_pos[e.dst] || post_pos[v] <= post_pos[e.dst]) ok = false;
                child_count[e.dst]++;
            }
            // hop: k 個上の祖先 (存在しなければ -1)
            int x = v;
            for (int k = 0; k <= n; k++) {
                if (dt.hop(v, k) != x) ok = false;
                if (x != -1) x = par[x];
            }
        }
        for (int v = 0; v < n; v++) {
            if (child_count[v] != (v != root)) ok = false;
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
            // graph() で Graph として渡せる
            auto sp = shortest_path_dijkstra(dt.graph(), u);
            for (int v = 0; v < n; v++) {
                if (sp.dist[v] != dt.dist(u, v)) ok = false;
            }
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
