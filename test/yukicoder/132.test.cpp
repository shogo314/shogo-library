#define PROBLEM "https://yukicoder.me/problems/no/132"
#define ERROR "1e-9"

#include <iomanip>
#include <iostream>
#include <vector>

#include "../../src/geometry/segment-3d.hpp"

int main() {
    int n;
    std::cin >> n;
    Vector<double, 3> p;
    std::cin >> p;
    std::vector<Vector<double, 3>> q(n);
    for (auto& x : q) std::cin >> x;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) sum += distance_point_plane(q[i], q[j], q[k], p);
        }
    }
    std::cout << std::fixed << std::setprecision(10) << sum << '\n';
}
