#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// graph.hpp の Graph のデフォルトコンストラクタと、読み取り専用の operator[] を検証する
// コストの型を省いたときに long long になることも static_assert で確かめる (Tree も)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/graph.hpp"

#include <iostream>
#include <random>
#include <type_traits>
#include <utility>
#include <vector>

#include "../../../src/graph/tree.hpp"

// 重みが 10^9 程度でも、重みの和や未到達を表す max / 4 があふれないように long long にしている
static_assert(std::is_same_v<decltype(Graph(3)), Graph<long long>>);
static_assert(std::is_same_v<decltype(Tree(3)), Tree<long long>>);
static_assert(std::is_same_v<decltype(std::declval<Graph<>&>()[0]), const std::vector<Graph<>::Edge>&>);
static_assert(std::is_same_v<decltype(std::declval<Tree<>&>()[0]), const std::vector<Graph<>::Edge>&>);

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    Graph<int> empty;
    if (empty.size() != 0 || empty.edge_count() != 0) ok = false;

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
            // 隣接リストへの const 参照を返す
            const std::vector<Graph<long long>::Edge>& es = g[v];
            if (es.size() != adj[v].size()) ok = false;
            for (int i = 0; i < static_cast<int>(es.size()); i++) {
                if (es[i].src != v || es[i].dst != adj[v][i] || static_cast<int>(es[i]) != adj[v][i]) ok = false;
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
