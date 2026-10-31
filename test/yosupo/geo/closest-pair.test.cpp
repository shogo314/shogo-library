#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"

#include <iostream>
#include <vector>

#include "../../../src/geometry/point-pair.hpp"
#include "../../../src/geometry/vector.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<Vector<long long, 2>> p(n);
        for (auto& v : p) std::cin >> v[0] >> v[1];
        auto res = closest_point_pair_squared(p);
        std::cout << res.i << ' ' << res.j << '\n';
    }
}
