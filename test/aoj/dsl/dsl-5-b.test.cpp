#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <algorithm>
#include <iostream>

#include "../../../src/data_structures/imos-2d.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    const int m = 1000;
    Imos2D<int> imos(m, m);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        imos.add(x1, y1, x2, y2, 1);
    }
    imos.build();
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) ans = std::max(ans, imos.get(i, j));
    std::cout << ans << '\n';
}
