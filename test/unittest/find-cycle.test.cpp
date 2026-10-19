#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// find_cycle_directed と find_cycle_undirected をランダムなグラフで確かめる
// 閉路があるかを別の方法 (トポロジカルソート、Union-Find) で求めて比べ、返した辺の列が閉路になっているかを調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>
#include <set>
#include <tuple>
#include <vector>

#include "../../src/data_structures/unionfind.hpp"
#include "../../src/graph/graph.hpp"
#include "../../src/graph/graph_util.hpp"

// 辺の列が閉路になっているか (つながっていて、辺の番号が重複せず、どれも実在する辺)
template <typename E>
bool is_cycle(const std::vector<E>& c, const std::vector<std::tuple<int, int, int>>& es, bool directed) {
    std::set<int> ids;
    for (int k = 0; k < static_cast<int>(c.size()); k++) {
        if (c[k].dst != c[(k + 1) % c.size()].src) return false;
        if (!ids.insert(c[k].id).second) return false;
        auto [u, v, id] = es[c[k].id];
        if (id != c[k].id) return false;
        bool same = c[k].src == u && c[k].dst == v;
        bool rev = c[k].src == v && c[k].dst == u;
        if (!(same || (!directed && rev))) return false;
    }
    return true;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 5000 && ok; rep++) {
        int n = rng() % 8 + 1, m = rng() % 10;
        std::vector<std::tuple<int, int, int>> es;
        Graph<int> dg(n), ug(n);
        UnionFind uf(n);
        bool undirected_cycle = false;
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;  // 自己ループと多重辺も含む
            es.emplace_back(u, v, i);
            dg.add_directed_edge(u, v);
            ug.add_edge(u, v);
            if (!uf.merge(u, v)) undirected_cycle = true;
        }
        auto dc = find_cycle_directed(dg);
        ok = ok && dc.empty() == !has_cycle(dg) && is_cycle(dc, es, true);
        auto uc = find_cycle_undirected(ug);
        ok = ok && uc.empty() == !undirected_cycle && is_cycle(uc, es, false);
    }

    // 例: 0 -> 1 -> 2 -> 0
    Graph<int> g(3);
    g.add_directed_edge(0, 1);
    g.add_directed_edge(1, 2);
    g.add_directed_edge(2, 0);
    auto c = find_cycle_directed(g);
    ok = ok && c.size() == 3 && c[0].id == 0 && c[1].id == 1 && c[2].id == 2;
    // 多重辺は長さ 2 の閉路
    Graph<int> h(2);
    h.add_edge(0, 1);
    h.add_edge(0, 1);
    ok = ok && find_cycle_undirected(h).size() == 2;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
