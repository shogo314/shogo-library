#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR "1e-6"

#include <iomanip>
#include <iostream>

#include "../../src/geometry/circle.hpp"

int main() {
    Circle c;
    int q;
    std::cin >> c >> q;
    std::cout << std::fixed << std::setprecision(10);
    while (q--) {
        Vector p1, p2;
        std::cin >> p1 >> p2;
        auto ps = circle_line_intersection(c, p1, p2);
        // 接するときは同じ点を 2 回出力する
        std::cout << ps.front() << ' ' << ps.back() << '\n';
    }
}
