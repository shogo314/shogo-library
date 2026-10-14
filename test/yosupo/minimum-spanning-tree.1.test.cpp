#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../src/data_structures/unionfind.hpp"
#include "../../src/graph/graph.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    Graph<long long> g(n);
    g.read(m, 0, true);
    // edges() は辺の番号順 (入力順) に並ぶ
    auto es = g.edges();
    std::stable_sort(es.begin(), es.end(), [](const auto& a, const auto& b) { return a.cost < b.cost; });
    UnionFind uf(n);
    long long sum = 0;
    std::vector<int> ids;
    for (const auto& e : es) {
        if (uf.merge(e.src, e.dst)) {
            sum += e.cost;
            ids.push_back(e.id);
        }
    }
    std::cout << sum << '\n';
    for (int i = 0; i < (int)ids.size(); i++) std::cout << ids[i] << " \n"[i + 1 == (int)ids.size()];
    if (ids.empty()) std::cout << '\n';
}
