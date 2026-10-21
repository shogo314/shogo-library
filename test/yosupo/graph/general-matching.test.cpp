#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"

#include "../../../src/graph/general-matching.hpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0);
    auto matching = general_matching(g);
    std::cout << matching.size() << '\n';
    for (auto& e : matching) std::cout << e.src << ' ' << e.dst << '\n';
}
