#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR "1e-5"

#include <iomanip>

#include "../../../src/base/io.hpp"
#include "../../../src/geometry/polygon.hpp"
#include "../../../src/geometry/vector.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<Vector<>> polygon(n);
    std::cin >> polygon;
    int q;
    std::cin >> q;
    std::cout << std::fixed << std::setprecision(10);
    while (q--) {
        Vector p1, p2;
        std::cin >> p1 >> p2;
        std::cout << polygon_area(convex_cut(polygon, p1, p2)) << '\n';
    }
}
