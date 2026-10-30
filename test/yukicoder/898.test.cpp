#define PROBLEM "https://yukicoder.me/problems/no/898"

#include <array>
#include <iostream>

#include "../../src/graph/tree.hpp"
using ll = long long;

int main() {
    int n;
    std::cin >> n;
    Tree<ll> tr(n);
    tr.read(0, true);
    DoublingClimbTree<ll> dct(tr, 0);
    int q;
    std::cin >> q;
    while (q--) {
        std::array<int, 3> xyz;
        for (int i = 0; i < 3; i++) std::cin >> xyz[i];
        int lca01 = dct.lca(xyz[0], xyz[1]);
        int lca02 = dct.lca(xyz[0], xyz[2]);
        int lca12 = dct.lca(xyz[1], xyz[2]);
        int center = lca01 ^ lca02 ^ lca12;
        std::cout << dct.dist(xyz[0], center) + dct.dist(xyz[1], center) + dct.dist(xyz[2], center) << std::endl;
    }
}
