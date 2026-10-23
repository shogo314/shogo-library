#define PROBLEM "https://judge.yosupo.jp/problem/minimum_enclosing_circle"

#include <iostream>
#include <string>
#include <vector>

#include "../../../src/geometry/circle.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<Vector<long long, 2>> p(n);
    for (auto& v : p) std::cin >> v[0] >> v[1];
    auto c = minimum_enclosing_circle(p);
    std::string ans(n, '0');
    for (int i = 0; i < n; i++)
        if (c.side(p[i]) == 0) ans[i] = '1';
    std::cout << ans << '\n';
}
