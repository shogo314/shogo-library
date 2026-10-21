#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_I"
#define ERROR "1e-6"

#include <iomanip>
#include <iostream>

#include "../../../src/geometry/circle.hpp"

int main() {
    Circle c1, c2;
    std::cin >> c1 >> c2;
    std::cout << std::fixed << std::setprecision(12) << circle_circle_intersection_area(c1, c2) << '\n';
}
