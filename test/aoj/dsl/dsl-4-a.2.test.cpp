#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"

// Compress で座標圧縮する

#include <iostream>
#include <vector>

#include "../../../src/geometry/rectangle.hpp"
#include "../../../src/utility/compress.hpp"
#include "../../../src/utility/range.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<Rectangle<long long>> rects(n);
    Compress<long long> cx, cy;
    for (int i = 0; i < n; i++) {
        std::cin >> rects[i];
        cx.add(rects[i].left), cx.add(rects[i].right);
        cy.add(rects[i].bottom), cy.add(rects[i].top);
    }
    cx.build();
    cy.build();
    int w = cx.size(), h = cy.size();
    std::vector<std::vector<int>> imos(w, std::vector<int>(h));
    for (int i = 0; i < n; i++) {
        int a = cx.id(rects[i].left), b = cx.id(rects[i].right);
        int c = cy.id(rects[i].bottom), d = cy.id(rects[i].top);
        imos[a][c]++, imos[a][d]--, imos[b][c]--, imos[b][d]++;
    }
    for (auto [i, j] : Grid(Range(w), Range(1, h))) imos[i][j] += imos[i][j - 1];
    for (auto [i, j] : Grid(Range(1, w), Range(h))) imos[i][j] += imos[i - 1][j];
    long long ans = 0;
    for (auto [i, j] : Grid(w - 1, h - 1)) {
        if (imos[i][j] > 0) ans += (cx[i + 1] - cx[i]) * (cy[j + 1] - cy[j]);
    }
    std::cout << ans << '\n';
}
