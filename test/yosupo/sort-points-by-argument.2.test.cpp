#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "../../src/geometry/angle.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<std::array<long long, 2>> ps(n);
    for (auto& [x, y] : ps) std::cin >> x >> y;
    // Angle は x 軸正方向から反時計回り ([0, 2π)) に比べる
    std::sort(ps.begin(), ps.end(), [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });
    // 問題は x <= 0, y = 0 の半直線の直後から ((-π, π]) なので、y < 0 の点を先頭に移す
    std::stable_partition(ps.begin(), ps.end(), [](const auto& p) { return p[1] < 0; });
    for (const auto& [x, y] : ps) std::cout << x << ' ' << y << '\n';
}
