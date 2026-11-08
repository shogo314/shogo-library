#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

// rectangle-union.hpp の rectangle_union_area を使う

#include <iostream>
#include <vector>

#include "../../../src/geometry/rectangle-union.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<Rectangle<long long>> rects(n);
    for (auto& rect : rects) std::cin >> rect;
    std::cout << rectangle_union_area(rects) << '\n';
}
