#define PROBLEM "https://atcoder.jp/contests/abc481/tasks/abc481_e"
#define IGNORE

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../../src/geometry/angle.hpp"
#include "../../../src/utility/two-pointers.hpp"

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<Angle<long long>> a(n);
        for (auto& p : a) std::cin >> p;
        std::sort(a.begin(), a.end());
        // 2π を足した写しを後ろにつなげ、各 l について偏角が [θ_l, θ_l + π) の星を数える
        for (int i = 0; i < n; i++) a.push_back(a[i].next_turn());
        auto right = two_pointers(2 * n, [&](long long l, long long r) { return a[r] < a[l].opposite(); });
        long long ans = 0;
        for (int l = 0; l < n; l++) ans = std::max(ans, right[l] - l);
        std::cout << ans << '\n';
    }
}
