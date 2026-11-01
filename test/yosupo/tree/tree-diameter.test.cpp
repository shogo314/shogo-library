#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include <vector>

#include "../../../src/graph/tree_util.hpp"

int main() {
    int n;
    std::cin >> n;
    Tree<long long> tree(n);
    tree.read(0, true);
    auto [length, path, edges] = tree_diameter_restore(tree);
    std::cout << length << ' ' << path.size() << '\n';
    for (int i = 0; i < static_cast<int>(path.size()); i++) std::cout << path[i] << " \n"[i + 1 == static_cast<int>(path.size())];
}
