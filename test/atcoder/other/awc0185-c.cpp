#define PROBLEM "https://atcoder.jp/contests/awc0185/tasks/awc0185_c"
#define IGNORE

#include <iostream>
#include <vector>

#include "../../../src/others/subarray-sum.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    std::cout << count_subarrays_with_sum(a, k) << '\n';
}
