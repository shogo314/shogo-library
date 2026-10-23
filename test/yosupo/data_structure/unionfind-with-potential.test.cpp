#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include <iostream>

#include "../../../src/algebra/group.hpp"
#include "../../../src/data_structures/potentialized-unionfind.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    PotentializedUnionFind<group::Sum<mint>> uf(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            mint x;
            std::cin >> x;
            // a_u = a_v + x なので、(u のポテンシャル) - (v のポテンシャル) = x
            // 新しく統合できたか、すでに連結で矛盾しなければ 1
            std::cout << (uf.merge(v, u, x).merged || uf.diff(v, u) == x) << '\n';
        } else {
            if (uf.same(u, v)) {
                std::cout << uf.diff(v, u) << '\n';
            } else {
                std::cout << -1 << '\n';
            }
        }
    }
}
