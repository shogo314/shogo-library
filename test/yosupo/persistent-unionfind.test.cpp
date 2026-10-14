#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../../src/data_structures/persistent-unionfind.hpp"

#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    // uf[i + 1] がクエリ i の後の版、uf[0] が初期の版
    std::vector<PersistentUnionFind> uf(q + 1);
    uf[0] = PersistentUnionFind(n);
    for (int i = 0; i < q; i++) {
        int t, k, u, v;
        std::cin >> t >> k >> u >> v;
        const PersistentUnionFind& prev = uf[k + 1];
        if (t == 0) {
            uf[i + 1] = prev.merge(u, v);
        } else {
            uf[i + 1] = prev;
            std::cout << prev.same(u, v) << '\n';
        }
    }
}
