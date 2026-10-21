#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include <iostream>

#include "../../../src/graph/graph.hpp"
#include "../../../src/graph/graph_util.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0);
    std::cout << chromatic_number(g) << '\n';
}
