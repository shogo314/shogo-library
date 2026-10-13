#define PROBLEM "https://atcoder.jp/contests/abc184/tasks/abc184_f"
#define IGNORE

#include <iostream>
#include <vector>

#include "../../src/others/subset-sum.hpp"

int main() {
    int n;
    long long t;
    std::cin >> n >> t;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    std::cout << subset_sum_max(a, t) << '\n';
}
