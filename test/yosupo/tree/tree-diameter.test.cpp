#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include <vector>

#include "../../../src/graph/tree.hpp"

int main() {
    int n;
    std::cin >> n;
    Tree<long long> tree(n);
    tree.read(0, true);
    auto path = tree.diameter();
    long long x = 0;
    std::vector<int> vs;
    if (path.empty()) {
        vs.push_back(0);  // n = 1
    } else {
        vs.push_back(path[0].src);
        for (const auto& e : path) {
            x += e.cost;
            vs.push_back(e.dst);
        }
    }
    std::cout << x << ' ' << vs.size() << '\n';
    for (int i = 0; i < static_cast<int>(vs.size()); i++) std::cout << vs[i] << " \n"[i + 1 == static_cast<int>(vs.size())];
}
