#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "../../../src/data_structures/cartesian-tree.hpp"

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    auto t = cartesian_tree(a);
    for (int i = 0; i < n; i++) std::cout << (i == t.root ? i : t.parent[i]) << " \n"[i == n - 1];
}
