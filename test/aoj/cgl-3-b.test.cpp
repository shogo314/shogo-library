#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"

#include "../../src/base/io.hpp"
#include "../../src/geometry/vector.hpp"

int main(void) {
    int n;
    std::cin >> n;
    std::vector<Vector<>> polygon(n);
    std::cin >> polygon;
    std::cout << polygon_is_convex(polygon) << std::endl;
}