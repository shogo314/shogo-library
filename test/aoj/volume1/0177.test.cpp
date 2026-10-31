#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0177"

#include <cmath>
#include <iostream>

#include "../../../src/geometry/sphere.hpp"

int main() {
    const double deg = std::acos(-1.0) / 180;
    double a, b, c, d;
    while (std::cin >> a >> b >> c >> d && !(a == -1 && b == -1 && c == -1 && d == -1)) {
        std::cout << std::llround(great_circle_distance(a * deg, b * deg, c * deg, d * deg, 6378.1)) << '\n';
    }
}
