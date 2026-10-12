#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../src/geometry/vector.hpp"

int main() {
    int n; std::cin >> n;
    using P = Vector<long long>;
    std::vector<P> ps(n);
    for (auto& p : ps) std::cin >> p;
    // ArgSortComp は x 軸正方向から反時計回り ([0, 2π)) に並べる
    std::sort(ps.begin(), ps.end(), P::ArgSortComp());
    // 問題は x <= 0, y = 0 の半直線の直後から ((-π, π]) なので、y < 0 の点を先頭に移す
    std::stable_partition(ps.begin(), ps.end(), [](const P& p) { return p[1] < 0; });
    for (const auto& p : ps) std::cout << p << '\n';
}
