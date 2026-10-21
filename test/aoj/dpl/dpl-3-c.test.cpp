#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include <iostream>
#include <vector>

#include "../../../src/dp/largest-rectangle.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<long long> h(n);
    for (auto& x : h) std::cin >> x;
    std::cout << largest_rectangle_in_histogram(h) << '\n';
}
