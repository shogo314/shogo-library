#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"

// rectangle-union.hpp の rectangle_union_area を使う

#include <array>
#include <iostream>
#include <vector>

#include "../../../src/geometry/rectangle-union.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<std::array<long long, 4>> rects(n);
    for (auto& [l, d, r, u] : rects) std::cin >> l >> d >> r >> u;
    std::cout << rectangle_union_area(rects) << '\n';
}
