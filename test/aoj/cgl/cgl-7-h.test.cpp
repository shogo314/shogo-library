#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H"
#define ERROR "1e-5"

#include <iomanip>

#include "../../../src/base/io.hpp"
#include "../../../src/geometry/circle.hpp"

int main() {
    int n;
    double r;
    std::cin >> n >> r;
    std::vector<Vector<>> polygon(n);
    std::cin >> polygon;
    std::cout << std::fixed << std::setprecision(10) << circle_polygon_intersection_area(Circle(Vector(0.0, 0.0), r), polygon) << '\n';
}
