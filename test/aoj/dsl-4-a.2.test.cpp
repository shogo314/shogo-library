#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"

// Compress で座標圧縮する

#include <iostream>
#include <vector>

#include "../../src/utility/compress.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> x1(n), y1(n), x2(n), y2(n);
    Compress<long long> cx, cy;
    for (int i = 0; i < n; i++) {
        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        cx.add(x1[i]), cx.add(x2[i]);
        cy.add(y1[i]), cy.add(y2[i]);
    }
    cx.build();
    cy.build();
    int w = cx.size(), h = cy.size();
    std::vector<std::vector<int>> imos(w, std::vector<int>(h));
    for (int i = 0; i < n; i++) {
        int a = cx.id(x1[i]), b = cx.id(x2[i]);
        int c = cy.id(y1[i]), d = cy.id(y2[i]);
        imos[a][c]++, imos[a][d]--, imos[b][c]--, imos[b][d]++;
    }
    for (int i = 0; i < w; i++)
        for (int j = 1; j < h; j++) imos[i][j] += imos[i][j - 1];
    for (int i = 1; i < w; i++)
        for (int j = 0; j < h; j++) imos[i][j] += imos[i - 1][j];
    long long ans = 0;
    for (int i = 0; i + 1 < w; i++)
        for (int j = 0; j + 1 < h; j++) {
            if (imos[i][j] > 0) ans += (cx[i + 1] - cx[i]) * (cy[j + 1] - cy[j]);
        }
    std::cout << ans << '\n';
}
