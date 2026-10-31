#define PROBLEM "https://yukicoder.me/problems/no/3672"
#define ERROR "1e-6"

#include <iomanip>
#include <iostream>

#include "../../src/geometry/sphere.hpp"

int main() {
    int t;
    std::cin >> t;
    std::cout << std::fixed << std::setprecision(10);
    while (t--) {
        Sphere<double> a, b;
        std::cin >> a >> b;
        std::cout << sphere_sphere_intersection_volume(a, b) << '\n';
    }
}
