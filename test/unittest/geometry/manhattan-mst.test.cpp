#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// manhattan-mst.hpp の manhattan_mst を、完全グラフを作って minimum_spanning_tree にかけたものと比べる
// 返した辺が全域木になっていて、辺の重みが距離と一致し、総和が最小かを確かめる。同じ点や一直線上の点も含む
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/geometry/manhattan-mst.hpp"

#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/data_structures/unionfind.hpp"

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    using P = Vector<long long, 2>;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1, w = rep % 2 == 0 ? 5 : 1000;
        std::vector<P> p(n);
        for (auto& v : p) v = P(static_cast<long long>(rng() % w) - w / 2, static_cast<long long>(rng() % w) - w / 2);
        auto dist = [&](int i, int j) { return std::abs(p[i][0] - p[j][0]) + std::abs(p[i][1] - p[j][1]); };
        Graph<long long> g(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) g.add_edge(i, j, dist(i, j));
        auto expect = minimum_spanning_tree(g);
        auto res = manhattan_mst(p);
        if (res.cost != expect.cost || static_cast<int>(res.edges.size()) != n - 1) ok = false;
        UnionFind uf(n);
        long long sum = 0;
        for (const auto& e : res.edges) {
            if (e.cost != dist(e.src, e.dst)) ok = false;
            sum += e.cost;
            uf.merge(e.src, e.dst);
        }
        if (sum != res.cost || uf.size(0) != n) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
