#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H"

#include <iostream>
#include <vector>

#include "../../src/dp/knapsack.hpp"

int main() {
    int n;
    long long W;
    std::cin >> n >> W;
    std::vector<long long> v(n), w(n);
    for (int i = 0; i < n; i++) std::cin >> v[i] >> w[i];
    std::cout << knapsack_meet_in_the_middle(v, w, W) << '\n';
}
