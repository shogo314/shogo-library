#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F"

#include <iostream>
#include <vector>

#include "../../src/others/knapsack.hpp"

int main() {
    int n;
    long long W;
    std::cin >> n >> W;
    std::vector<long long> v(n), w(n);
    for (int i = 0; i < n; i++) std::cin >> v[i] >> w[i];
    std::cout << knapsack_by_value(v, w, W) << '\n';
}
