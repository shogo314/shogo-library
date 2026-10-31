#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR "1e-6"

#include <iomanip>

#include "../../../src/base/io.hpp"
#include "../../../src/geometry/point-pair.hpp"
#include "../../../src/geometry/vector.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<Vector<>> polygon(n);
    std::cin >> polygon;
    std::cout << std::fixed << std::setprecision(10) << farthest_point_pair(polygon).dist << '\n';
}
