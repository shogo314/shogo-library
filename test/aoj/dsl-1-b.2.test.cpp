#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"

#include <functional>
#include <iostream>

#include "../../src/data_structures/potentialized-unionfind.hpp"

// ポテンシャルの群をラムダ式 (関数オブジェクト) から作る
int main() {
    int n, q;
    std::cin >> n >> q;
    PotentializedUnionFind uf(n, Group(std::plus<long long>{}, 0LL, [](long long a) { return -a; }));
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int x, y;
            long long z;
            std::cin >> x >> y >> z;
            uf.merge(x, y, z);
        } else {
            int x, y;
            std::cin >> x >> y;
            if (uf.same(x, y))
                std::cout << uf.diff(x, y) << '\n';
            else
                std::cout << '?' << '\n';
        }
    }
}
