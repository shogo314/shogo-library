#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR "1e-5"

#include <iomanip>
#include <iostream>

#include "../../src/geometry/circle.hpp"

int main() {
    Vector p;
    Circle c;
    std::cin >> p >> c;
    std::cout << std::fixed << std::setprecision(10);
    for (const auto& t : tangent_points(c, p)) std::cout << t << '\n';
}
