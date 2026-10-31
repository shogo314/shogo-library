#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR "1e-8"

#include <iomanip>
#include <iostream>

#include "../../../src/geometry/segment.hpp"
#include "../../../src/geometry/vector.hpp"

int main() {
    Vector p1, p2;
    int q;
    std::cin >> p1 >> p2 >> q;
    std::cout << std::fixed << std::setprecision(10);
    while (q--) {
        Vector p;
        std::cin >> p;
        std::cout << reflection(p1, p2, p) << '\n';
    }
}
