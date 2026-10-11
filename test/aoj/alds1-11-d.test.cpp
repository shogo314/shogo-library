#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D"

#include <iostream>
#include <vector>

#include "../../src/graph/graph_util.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n, m; std::cin >> n >> m;
    Graph<int> graph(n);
    graph.read(m, 0);
    std::vector<int> id(n);
    auto groups = connected_components(graph);
    for (int i = 0; i < (int)groups.size(); i++) {
        for (int v : groups[i]) id[v] = i;
    }
    int q; std::cin >> q;
    while (q--) {
        int s, t; std::cin >> s >> t;
        std::cout << (id[s] == id[t] ? "yes" : "no") << '\n';
    }
}
