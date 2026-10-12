#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_C"
#define ERROR "1e-4"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#include "../../src/base/container_func.hpp"

int main() {
    int n;
    std::cout << std::fixed << std::setprecision(8);
    while (std::cin >> n && n != 0) {
        std::vector<double> s(n);
        for (auto& x : s) std::cin >> x;
        double m = average(s);
        std::vector<double> d(n);
        for (int i = 0; i < n; i++) d[i] = (s[i] - m) * (s[i] - m);
        std::cout << std::sqrt(average(d)) << '\n';
    }
}
