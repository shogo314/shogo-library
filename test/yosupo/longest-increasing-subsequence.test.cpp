#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../../src/dp/longest-increasing-subsequence.hpp"

#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<long long> idx = longest_increasing_subsequence_restore(a);
    std::cout << idx.size() << '\n';
    for (long long i = 0; i < (long long)idx.size(); i++) std::cout << idx[i] << " \n"[i + 1 == (long long)idx.size()];
}
