#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A"

#include <iostream>
#include <vector>

#include "../../../src/dp/subset-sum.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<bool> can = subset_sum(a, 2000);
    int q;
    std::cin >> q;
    while (q--) {
        int m;
        std::cin >> m;
        std::cout << (can[m] ? "yes" : "no") << '\n';
    }
}
