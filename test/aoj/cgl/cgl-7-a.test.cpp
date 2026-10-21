#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

#include <iostream>

#include "../../../src/geometry/circle.hpp"

int main() {
    Circle<long long> c1, c2;
    std::cin >> c1 >> c2;
    std::cout << circle_relation(c1, c2) << '\n';
}
