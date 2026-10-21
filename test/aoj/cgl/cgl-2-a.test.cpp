#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include <iostream>

#include "../../../src/geometry/vector.hpp"

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        Vector<long long> p0, p1, p2, p3;
        std::cin >> p0 >> p1 >> p2 >> p3;
        std::cout << (is_parallel(p0, p1, p2, p3) ? 2 : is_orthogonal(p0, p1, p2, p3) ? 1
                                                                                      : 0)
                  << '\n';
    }
}
