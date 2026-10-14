#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// rerooting-dp.hpp の distance_sums と connected_subgraph_count を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/rerooting-dp.hpp"

#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 10 + 1;
        Tree<long long> tree(n);
        std::vector<std::vector<std::pair<int, long long>>> adj(n);
        for (int i = 1; i < n; i++) {
            int p = rng() % i;
            long long w = rng() % 10;
            tree.add_edge(i, p, w);
            adj[i].push_back({p, w});
            adj[p].push_back({i, w});
        }

        // distance_sums: 各頂点から DFS して距離の合計を求める
        std::vector<long long> ds = distance_sums(tree);
        for (int s = 0; s < n; s++) {
            std::vector<long long> dist(n, -1);
            std::vector<int> stk = {s};
            dist[s] = 0;
            long long sum = 0;
            while (!stk.empty()) {
                int u = stk.back();
                stk.pop_back();
                sum += dist[u];
                for (auto [v, w] : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + w;
                        stk.push_back(v);
                    }
                }
            }
            if (ds[s] != sum) ok = false;
        }

        // connected_subgraph_count: 頂点集合を全列挙し、その頂点を含む連結なものを数える
        std::vector<long long> cs = connected_subgraph_count<long long>(tree);
        std::vector<long long> naive(n, 0);
        for (int mask = 1; mask < (1 << n); mask++) {
            int start = __builtin_ctz(mask);
            int seen = 1 << start;
            std::vector<int> stk = {start};
            while (!stk.empty()) {
                int u = stk.back();
                stk.pop_back();
                for (auto [v, w] : adj[u]) {
                    if ((mask >> v & 1) && !(seen >> v & 1)) {
                        seen |= 1 << v;
                        stk.push_back(v);
                    }
                }
            }
            if (seen != mask) continue;
            for (int v = 0; v < n; v++) {
                if (mask >> v & 1) naive[v]++;
            }
        }
        if (cs != naive) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
