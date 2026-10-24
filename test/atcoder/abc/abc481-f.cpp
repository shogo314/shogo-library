#define PROBLEM "https://atcoder.jp/contests/abc481/tasks/abc481_f"
#define IGNORE

#include <iostream>
#include <vector>

#include "../../../src/graph/graph.hpp"
#include "../../../src/graph/shortest-path.hpp"
#include "../../../src/string/trie.hpp"
#include "../../../src/utility/vector_func.hpp"

int main() {
    long long n, m;
    std::cin >> n >> m;
    Graph<long long> g(n);
    g.read(m, -1, true, true);
    // 数字に 0 がないので、辺の数が少ないほどスコアは小さい。辺の数が同じなら数字の列の辞書順で比べる
    auto d = shortest_path(g, 0, false).dist;
    Trie<9, 1> trie;
    std::vector<long long> node(n, -1), val(n);
    node[0] = 0;
    // BFS の順に、前の層の頂点の最小の数字の列に辺の数字を付け足したものから最小を選ぶ
    for (long long u : sorted_idx(d)) {
        for (auto& e : g[u]) {
            if (d[e.dst] != d[u] + 1) continue;
            long long v = trie.extend(node[u], e.cost);
            if (node[e.dst] == -1 || trie.less(v, node[e.dst])) {
                node[e.dst] = v;
                val[e.dst] = (val[u] * 10 + e.cost) % 998244353;
            }
        }
    }
    for (long long v = 1; v < n; v++) std::cout << val[v] << '\n';
}
