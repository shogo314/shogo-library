#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"

#include <iostream>
#include <vector>

#include "../../src/utility/container_func.hpp"
#include "../../src/utility/vector_func.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> x1(n), y1(n), x2(n), y2(n);
    std::vector<long long> xs, ys;
    for (int i = 0; i < n; i++) {
        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        xs.push_back(x1[i]), xs.push_back(x2[i]);
        ys.push_back(y1[i]), ys.push_back(y2[i]);
    }
    // 座標圧縮
    xs = unique(xs);
    ys = unique(ys);
    int w = xs.size(), h = ys.size();
    std::vector<std::vector<int>> imos(w, std::vector<int>(h));
    for (int i = 0; i < n; i++) {
        int a = bisect_left(xs, x1[i]), b = bisect_left(xs, x2[i]);
        int c = bisect_left(ys, y1[i]), d = bisect_left(ys, y2[i]);
        imos[a][c]++, imos[a][d]--, imos[b][c]--, imos[b][d]++;
    }
    for (int i = 0; i < w; i++) for (int j = 1; j < h; j++) imos[i][j] += imos[i][j - 1];
    for (int i = 1; i < w; i++) for (int j = 0; j < h; j++) imos[i][j] += imos[i - 1][j];
    long long ans = 0;
    for (int i = 0; i + 1 < w; i++) for (int j = 0; j + 1 < h; j++) {
        if (imos[i][j] > 0) ans += (xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]);
    }
    std::cout << ans << '\n';
}
