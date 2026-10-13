#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR "1e-8"

#include <iomanip>
#include <iostream>

#include "../../src/geometry/vector.hpp"

int main() {
    int q;
    std::cin >> q;
    std::cout << std::fixed << std::setprecision(10);
    while (q--) {
        Vector<long long> p0, p1, p2, p3;
        std::cin >> p0 >> p1 >> p2 >> p3;
        std::cout << distance_segments(p0, p1, p2, p3) << '\n';
    }
}
