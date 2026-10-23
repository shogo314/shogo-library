#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include <algorithm>
#include <iostream>

#include "../../../src/graph/tree_util.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    Tree<int> t(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        t.add_edge(p, i);
    }
    auto id = rooted_tree_isomorphism(t, 0);
    std::cout << *std::max_element(id.begin(), id.end()) + 1 << '\n';
    for (int i = 0; i < n; i++) std::cout << id[i] << " \n"[i == n - 1];
}
