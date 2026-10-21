#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C"
#define ERROR "1e-6"

#include <iomanip>
#include <iostream>

#include "../../../src/geometry/circle.hpp"

int main() {
    Vector a, b, c;
    std::cin >> a >> b >> c;
    Circle res = circumcircle(a, b, c);
    std::cout << std::fixed << std::setprecision(10) << res.c << ' ' << res.r << '\n';
}
