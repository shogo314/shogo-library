#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_5_A"

#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/utility/container_func.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::pair<long long, long long>> p(n);
    for (auto& [x, y] : p) std::cin >> x >> y;
    // x を優先し、同じなら y で比べるキーで並べる
    sort(p, {}, [](const std::pair<long long, long long>& e) { return std::make_pair(e.first, e.second); });
    for (const auto& [x, y] : p) std::cout << x << ' ' << y << '\n';
}
