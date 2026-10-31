#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// graph.hpp の edges() を、無向辺・有向辺・多重辺・自己ループを混ぜたグラフで愚直と比べる
// 辺 ID の昇順で 1 本ずつ返り、有向辺は追加したときの向きのままであることを確かめる
// 無向辺の向きは規定しないので、{src, dst} が追加した 2 頂点と集合として一致することだけを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>
#include <vector>

#include "../../../src/graph/graph.hpp"

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 5 + 1, m = rng() % 15;
        Graph<long long> g(n);
        struct E {
            long long u, v, w;
            bool directed;
        };
        std::vector<E> added;
        for (int i = 0; i < m; i++) {
            // 頂点数が少ないので、多重辺と自己ループがよく出る
            long long u = rng() % n, v = rng() % n, w = rng() % 100;
            bool directed = rng() % 2;
            if (directed) {
                g.add_directed_edge(u, v, w);
            } else {
                g.add_edge(u, v, w);
            }
            added.push_back({u, v, w, directed});
        }
        std::vector<Graph<long long>::Edge> es = g.edges();
        if (static_cast<long long>(es.size()) != g.m || g.m != m) ok = false;
        for (int i = 0; i < m && ok; i++) {
            const E& a = added[i];
            const auto& e = es[i];
            if (e.id != i || e.cost != a.w) ok = false;
            if (a.directed) {
                if (e.src != a.u || e.dst != a.v) ok = false;
            } else {
                if (!((e.src == a.u && e.dst == a.v) || (e.src == a.v && e.dst == a.u))) ok = false;
            }
        }
    }

    // 決まった例: 自己ループと多重辺
    {
        Graph<int> g(2);
        g.add_edge(0, 0, 5);
        g.add_edge(0, 1, 6);
        g.add_edge(1, 0, 7);
        g.add_directed_edge(1, 0, 8);
        g.add_directed_edge(1, 1, 9);
        auto es = g.edges();
        if (es.size() != 5) ok = false;
        if (es[0].src != 0 || es[0].dst != 0 || es[0].cost != 5) ok = false;
        for (int i : {1, 2}) {
            if (es[i].id != i || es[i].src + es[i].dst != 1 || es[i].src == es[i].dst) ok = false;
        }
        if (es[1].cost != 6 || es[2].cost != 7) ok = false;
        if (es[3].src != 1 || es[3].dst != 0 || es[3].cost != 8 || es[3].id != 3) ok = false;
        if (es[4].src != 1 || es[4].dst != 1 || es[4].cost != 9 || es[4].id != 4) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
