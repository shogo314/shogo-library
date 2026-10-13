#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include <iostream>
#include <vector>

#include "../../src/dp/longest-increasing-subsequence.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<int> idx = longest_increasing_subsequence_restore(a);
    std::cout << idx.size() << '\n';
    for (int i = 0; i < (int)idx.size(); i++) std::cout << idx[i] << " \n"[i + 1 == (int)idx.size()];
}
