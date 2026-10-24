#define PROBLEM "https://atcoder.jp/contests/abc481/tasks/abc481_e"
#define IGNORE

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../../src/geometry/angle.hpp"

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<Angle<long long>> a(n);
        for (auto& p : a) std::cin >> p;
        std::sort(a.begin(), a.end());
        // 2π を足した写しを後ろにつなげ、各 i について偏角が [θ_i, θ_i + π) の星を数える
        for (int i = 0; i < n; i++) a.push_back(a[i].next_turn());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, static_cast<long long>(std::lower_bound(a.begin(), a.end(), a[i].opposite()) - a.begin()) - i);
        }
        std::cout << ans << '\n';
    }
}
