#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/unionfind.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int s, t;
        std::cin >> s >> t;
        uf.merge(s, t);
    }
    // 連結成分ごとに番号を振る
    std::vector<int> id(n);
    auto groups = uf.groups();
    for (int i = 0; i < static_cast<int>(groups.size()); i++) {
        for (int v : groups[i]) id[v] = i;
    }
    int q;
    std::cin >> q;
    while (q--) {
        int s, t;
        std::cin >> s >> t;
        std::cout << (id[s] == id[t] ? "yes" : "no") << '\n';
    }
}
