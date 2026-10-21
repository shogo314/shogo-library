#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A"

#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/geometry/axis-parallel-segments.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<std::pair<Vector<long long>, Vector<long long>>> segs(n);
    for (auto& [p, q] : segs) std::cin >> p >> q;
    std::cout << count_axis_parallel_intersections(segs) << '\n';
}
