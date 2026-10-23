#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include <iostream>
#include <vector>

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
        auto hull = convex_hull(p);
        std::cout << hull.size() << '\n';
        for (const auto& v : hull) std::cout << v[0] << ' ' << v[1] << '\n';
    }
}
