#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G"

#include <iostream>
#include <vector>

#include "../../src/dp/knapsack.hpp"

int main() {
    int n;
    long long W;
    std::cin >> n >> W;
    std::vector<long long> v(n), w(n), m(n);
    for (int i = 0; i < n; i++) std::cin >> v[i] >> w[i] >> m[i];
    std::cout << bounded_knapsack_by_weight(v, w, m, W) << '\n';
}
