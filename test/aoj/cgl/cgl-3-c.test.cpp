#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

#include "../../../src/base/io.hpp"
#include "../../../src/geometry/vector.hpp"

int main(void) {
    int n;
    std::cin >> n;
    std::vector<Vector<int>> polygon(n);
    std::cin >> polygon;
    int q;
    std::cin >> q;
    while (q--) {
        Vector<int> p;
        std::cin >> p;
        std::cout << polygon_contains(polygon, p) << '\n';
    }
}