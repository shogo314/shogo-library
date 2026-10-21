#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <iostream>
#include <string>

#include "../../../src/geometry/vector.hpp"

int main() {
    Vector<long long> p0, p1;
    int q;
    std::cin >> p0 >> p1 >> q;
    while (q--) {
        Vector<long long> p2;
        std::cin >> p2;
        int r = ccw(p0, p1, p2);
        std::string s = r == 1 ? "COUNTER_CLOCKWISE" : r == -1 ? "CLOCKWISE"
                                                   : r == 2    ? "ONLINE_BACK"
                                                   : r == -2   ? "ONLINE_FRONT"
                                                               : "ON_SEGMENT";
        std::cout << s << '\n';
    }
}
