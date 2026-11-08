#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"

#include <iostream>
#include <vector>

#include "../../../src/geometry/rectangle.hpp"
#include "../../../src/utility/container_func.hpp"
#include "../../../src/utility/range.hpp"
#include "../../../src/utility/vector_func.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<Rectangle<long long>> rects(n);
    std::vector<long long> xs, ys;
    for (int i = 0; i < n; i++) {
        std::cin >> rects[i];
        xs.push_back(rects[i].left), xs.push_back(rects[i].right);
        ys.push_back(rects[i].bottom), ys.push_back(rects[i].top);
    }
    // 座標圧縮
    xs = unique(xs);
    ys = unique(ys);
    int w = xs.size(), h = ys.size();
    std::vector<std::vector<int>> imos(w, std::vector<int>(h));
    for (int i = 0; i < n; i++) {
        int a = bisect_left(xs, rects[i].left), b = bisect_left(xs, rects[i].right);
        int c = bisect_left(ys, rects[i].bottom), d = bisect_left(ys, rects[i].top);
        imos[a][c]++, imos[a][d]--, imos[b][c]--, imos[b][d]++;
    }
    for (auto [i, j] : Grid(Range(w), Range(1, h))) imos[i][j] += imos[i][j - 1];
    for (auto [i, j] : Grid(Range(1, w), Range(h))) imos[i][j] += imos[i - 1][j];
    long long ans = 0;
    for (auto [i, j] : Grid(w - 1, h - 1)) {
        if (imos[i][j] > 0) ans += (xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]);
    }
    std::cout << ans << '\n';
}
