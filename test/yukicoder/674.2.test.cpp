#define PROBLEM "https://yukicoder.me/problems/no/674"

#include <algorithm>
#include <iostream>

#include "../../src/data_structures/interval-set.hpp"

int main() {
    long long d;
    int q;
    std::cin >> d >> q;
    IntervalSet<long long> s;
    long long ans = 0;
    while (q--) {
        long long a, b;
        std::cin >> a >> b;
        // 閉区間 [a, b] を半開区間 [a, b+1) として追加する (隣接する区間は結合される)
        s.insert(a, b + 1);
        auto [l, r] = s.covered_by(a).value();
        ans = std::max(ans, r - l);
        std::cout << ans << '\n';
    }
}
