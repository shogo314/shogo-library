#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// minimum-arborescence.hpp の minimum_arborescence を、親の辺の選び方の全探索と比べる
// 負のコスト・自己ループ・多重辺・根から到達できない頂点を含むグラフで調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/minimum-arborescence.hpp"

#include <iostream>
#include <limits>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 6 + 1, m = rng() % 12, root = rng() % n;
        Graph<long long> g(n);
        std::vector<std::vector<Graph<long long>::Edge>> in(n);  // v に入る辺
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            long long w = static_cast<long long>(rng() % 21) - 5;
            g.add_directed_edge(u, v, w);
            in[v].push_back(g[u].back());
        }
        // 全探索: 根以外の各頂点に入る辺を 1 本ずつ選び、親をたどって根に着くものの最小
        const long long inf = std::numeric_limits<long long>::max();
        long long best = inf;
        std::vector<int> choice(n, 0);
        while (true) {
            bool valid = true;
            for (int v = 0; v < n; v++) valid &= v == root || !in[v].empty();
            if (!valid) break;
            long long sum = 0;
            bool tree = true;
            for (int v = 0; v < n && tree; v++) {
                if (v == root) continue;
                sum += in[v][choice[v]].cost;
                int x = v;
                for (int step = 0; step < n && x != root; step++) x = in[x][choice[x]].src;
                tree &= x == root;
            }
            if (tree) best = std::min(best, sum);
            int v = 0;
            while (v < n && (v == root || ++choice[v] == static_cast<int>(in[v].size()))) {
                if (v != root) choice[v] = 0;
                v++;
            }
            if (v == n) break;
        }
        auto res = minimum_arborescence(g, root);
        if (best == inf) {
            if (res) ok = false;
            continue;
        }
        if (!res || res->cost != best) {
            ok = false;
            continue;
        }
        // 返った辺が実際に根からの全域有向木になっていて、コストの和が cost と一致する
        long long sum = 0;
        for (int v = 0; v < n; v++) {
            const auto& e = res->parent_edge[v];
            if (v == root) {
                if (e.src != -1) ok = false;
                continue;
            }
            if (e.dst != v || e.id < 0 || e.id >= m) {
                ok = false;
                continue;
            }
            sum += e.cost;
            int x = v;
            for (int step = 0; step < n && x != root; step++) x = res->parent_edge[x].src;
            if (x != root) ok = false;
        }
        if (sum != res->cost) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
