#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"

#include <iostream>

#include "../../../src/graph/tree_util.hpp"

int main(void) {
    int n;
    std::cin >> n;
    Tree<int> tree(n);
    tree.read(0, true);
    std::cout << tree_diameter(tree) << '\n';
}