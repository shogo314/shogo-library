#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

// 独立集合で頂点全体を覆う最小個数として、包除原理の min_set_cover で求める

#include <iostream>
#include <vector>

#include "../../../src/dp/set-cover.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u] |= 1 << v, adj[v] |= 1 << u;
    }
    // indep[S]: S が独立集合か (最小の頂点を除いた集合が独立で、最小の頂点がそれと隣り合わない)
    std::vector<bool> indep(1 << n, false);
    indep[0] = true;
    for (int S = 1; S < (1 << n); S++) {
        const int v = __builtin_ctz(S), rest = S & (S - 1);
        indep[S] = indep[rest] && !(adj[v] & rest);
    }
    std::cout << min_set_cover(n, indep) << '\n';
}
