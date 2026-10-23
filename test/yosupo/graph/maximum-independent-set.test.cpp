#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include <iostream>

#include "../../../src/graph/graph_util.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0);
    auto s = maximum_independent_set(g);
    std::cout << s.size() << '\n';
    for (int i = 0; i < static_cast<int>(s.size()); i++) std::cout << (i ? " " : "") << s[i];
    std::cout << '\n';
}
