#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"

#include <iostream>
#include <vector>

#include "../../../src/geometry/manhattan-mst.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<Vector<long long, 2>> p(n);
    for (auto& v : p) std::cin >> v[0] >> v[1];
    auto mst = manhattan_mst(p);
    std::cout << mst.cost << '\n';
    for (const auto& e : mst.edges) std::cout << e.src << ' ' << e.dst << '\n';
}
