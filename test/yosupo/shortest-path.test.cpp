#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../src/graph/graph.hpp"

int main() {
    int n, m, s, t; std::cin >> n >> m >> s >> t;
    Graph<long long> g(n); g.read(m, 0, true, true);
    auto sp = g.shortest_path(s);
    if(sp.dist[t] == -1) {
        std::cout << -1 << '\n';
        return 0;
    }
    auto route = sp.path(t);
    std::cout << sp.dist[t] << ' ' << route.size() << '\n';
    for(auto& e : route) {
        std::cout << e.src << ' ' << e.dst << '\n';
    }
}

