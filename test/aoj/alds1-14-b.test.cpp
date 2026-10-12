#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>

#include "../../src/string/rolling-hash.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string t, p;
    std::cin >> t >> p;
    RollingHash rh;
    auto ht = rh.build(t);
    auto hp = rh.build(p);
    int n = t.size(), m = p.size();
    unsigned long long target = rh.query(hp, 0, m);
    for (int i = 0; i + m <= n; i++) {
        if (rh.query(ht, i, i + m) == target) std::cout << i << '\n';
    }
}
