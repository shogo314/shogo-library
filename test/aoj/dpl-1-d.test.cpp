#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <vector>

#include "../../src/dp/longest-increasing-subsequence.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::cout << longest_increasing_subsequence(a) << std::endl;
}
