#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"
#define ERROR "1e-5"

#include <iomanip>
#include <iostream>

#include "../../../src/geometry/circle.hpp"

int main() {
    Circle c1, c2;
    std::cin >> c1 >> c2;
    std::cout << std::fixed << std::setprecision(10);
    for (const auto& tangent : common_tangents(c1, c2)) std::cout << tangent.contact1 << '\n';
}
