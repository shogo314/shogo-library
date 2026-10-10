#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include <iostream>

#include "../geometry/vector.hpp"

int main() {
    int q; std::cin >> q;
    while(q--) {
        Vector<long long> p0, p1, p2, p3; std::cin >> p0 >> p1 >> p2 >> p3;
        std::cout << (segments_intersect(p0, p1, p2, p3) ? 1 : 0) << std::endl;
    }
}