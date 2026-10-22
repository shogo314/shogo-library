#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// graph.hpp の Graph のデフォルトコンストラクタと、const でない operator[] を検証する
// コストの型を省いたときに long long になることも static_assert で確かめる (Tree も)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/graph.hpp"

#include <iostream>
#include <random>
#include <type_traits>
#include <vector>

#include "../../../src/graph/tree.hpp"

// 重みが 10^9 程度でも、重みの和や未到達を表す max / 4 があふれないように long long にしている
static_assert(std::is_same_v<decltype(Graph(3)), Graph<long long>>);
static_assert(std::is_same_v<decltype(Tree(3)), Tree<long long>>);

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    Graph<int> empty;
    if (empty.n != 0 || empty.m != 0 || !empty.g.empty()) ok = false;

    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 8 + 1, m = rng() % 12;
        Graph<long long> g(n);
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            long long w = rng() % 100;
            g.add_directed_edge(u, v, w);
            adj[u].push_back(v);
        }
        for (int v = 0; v < n; v++) {
            // const でない operator[] は隣接リストそのものへの参照を返す
            std::vector<Graph<long long>::Edge>& es = g[v];
            if (&es != &g.g[v] || es.size() != adj[v].size()) ok = false;
            for (int i = 0; i < static_cast<int>(es.size()); i++) {
                if (es[i].src != v || es[i].dst != adj[v][i] || static_cast<int>(es[i]) != adj[v][i]) ok = false;
            }
            // 参照を通して書き換えると、グラフに反映される
            for (auto& e : g[v]) e.cost += 1;
            for (int i = 0; i < static_cast<int>(es.size()); i++) {
                if (g.g[v][i].cost != es[i].cost) ok = false;
            }
        }
        // const な operator[] と同じものを指す
        const Graph<long long>& cg = g;
        for (int v = 0; v < n; v++) {
            if (&cg[v] != &g[v]) ok = false;
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
