#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// tree_util.hpp の関数を愚直な実装とランダムに比較する
// tree_diameter: 全点対の距離の最大と比べる。重み付き・重みなしの両方で、返す辺の列が端点から順につながっていて、長さが直径と一致するかを確かめる
// tree_center: 最も遠い頂点までの距離が最小の頂点の集合と比べる
// tree_diameter_endpoint_groups: 「異なるグループにある」と「距離が直径に等しい」が全点対で一致するかを確かめる
// rooted_tree_isomorphism: 部分木の括弧列による正規形と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/tree_util.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1;
        Tree<long long> tree(n);
        std::vector<std::vector<long long>> dw(n, std::vector<long long>(n, 1LL << 60)), du = dw;
        for (int i = 0; i < n; i++) dw[i][i] = du[i][i] = 0;
        for (int i = 1; i < n; i++) {
            int p = rng() % i;
            long long w = rng() % 10;
            tree.add_edge(i, p, w);
            dw[i][p] = dw[p][i] = w;
            du[i][p] = du[p][i] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dw[i][j] = std::min(dw[i][j], dw[i][k] + dw[k][j]);
                    du[i][j] = std::min(du[i][j], du[i][k] + du[k][j]);
                }
            }
        }
        for (bool weighted : {true, false}) {
            const auto& d = weighted ? dw : du;
            long long expected = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) expected = std::max(expected, d[i][j]);
            }
            auto path = tree_diameter(tree, weighted);
            long long len = 0;
            for (int i = 0; i < static_cast<int>(path.size()); i++) {
                if (i > 0 && path[i - 1].dst != path[i].src) ok = false;
                len += weighted ? path[i].cost : 1;
            }
            if (len != expected) ok = false;
            if (!path.empty() && d[path.front().src][path.back().dst] != expected) ok = false;
            if (n == 1 && !path.empty()) ok = false;
        }

        // tree_center と tree_diameter_endpoint_groups (重みなし)
        long long diam = 0, rad = 1LL << 60;
        std::vector<long long> ecc(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) ecc[i] = std::max(ecc[i], du[i][j]);
            diam = std::max(diam, ecc[i]);
            rad = std::min(rad, ecc[i]);
        }
        std::vector<long long> center;
        for (int i = 0; i < n; i++) {
            if (ecc[i] == rad) center.push_back(i);
        }
        if (tree_center(tree) != center) ok = false;
        auto groups = tree_diameter_endpoint_groups(tree);
        std::vector<int> gid(n, -1);
        for (int k = 0; k < static_cast<int>(groups.size()); k++) {
            if (groups[k].empty()) ok = false;
            for (long long v : groups[k]) {
                if (gid[v] != -1) ok = false;
                gid[v] = k;
            }
        }
        if (n == 1) {
            if (groups != std::vector<std::vector<long long>>{{0}}) ok = false;
        } else {
            if (groups.size() < 2) ok = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    bool across = gid[i] != -1 && gid[j] != -1 && gid[i] != gid[j];
                    if (across != (du[i][j] == diam)) ok = false;
                }
            }
        }
    }

    // rooted_tree_isomorphism: 部分木を括弧列 (子の括弧列を整列して並べたもの) にした正規形と比べる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1, root = rng() % n;
        Tree<int> tree(n);
        std::vector<std::vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            // 小さい木では同型な部分木がよく出るように、親を近くから選ぶことも多くする
            int p = rng() % 2 ? i - 1 : rng() % i;
            tree.add_edge(i, p);
            adj[i].push_back(p), adj[p].push_back(i);
        }
        std::vector<std::string> canon(n);
        auto dfs = [&](auto self, int u, int par) -> void {
            std::vector<std::string> cs;
            for (int v : adj[u]) {
                if (v == par) continue;
                self(self, v, u);
                cs.push_back(canon[v]);
            }
            std::sort(cs.begin(), cs.end());
            canon[u] = "(";
            for (auto& c : cs) canon[u] += c;
            canon[u] += ")";
        };
        dfs(dfs, root, -1);
        auto id = rooted_tree_isomorphism(tree, root);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((id[i] == id[j]) != (canon[i] == canon[j])) ok = false;
            }
        }
        // 番号は 0 から隙間なく振る
        std::vector<long long> sorted = id;
        std::sort(sorted.begin(), sorted.end());
        sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
        if (sorted.back() != static_cast<long long>(sorted.size()) - 1) ok = false;
    }
    if (ok) std::cout << "Hello World" << '\n';
}
