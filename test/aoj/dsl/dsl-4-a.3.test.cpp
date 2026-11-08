#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"

// rectangle-union.hpp の rectangle_union_area を使う

#include <iostream>
#include <vector>

#include "../../../src/geometry/rectangle-union.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<Rectangle<long long>> rects(n);
    for (auto& rect : rects) std::cin >> rect;
    std::cout << rectangle_union_area(rects) << '\n';
}
