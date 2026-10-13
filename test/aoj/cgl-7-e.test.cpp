#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR "1e-6"

#include <iomanip>
#include <iostream>

#include "../../src/geometry/circle.hpp"

int main() {
    Circle c1, c2;
    std::cin >> c1 >> c2;
    auto ps = circle_circle_intersection(c1, c2);
    // 接するときは同じ点を 2 回出力する
    std::cout << std::fixed << std::setprecision(10) << ps.front() << ' ' << ps.back() << '\n';
}
