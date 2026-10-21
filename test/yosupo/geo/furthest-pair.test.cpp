#define PROBLEM "https://judge.yosupo.jp/problem/furthest_pair"

#include <iostream>
#include <vector>

#include "../../../src/geometry/vector.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<Vector<long long>> p(n);
        for (auto& x : p) std::cin >> x;
        auto res = farthest_point_pair_squared(p);
        std::cout << res.i << ' ' << res.j << '\n';
    }
}
