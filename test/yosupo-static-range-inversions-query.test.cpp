#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../others/mo.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n);
    for (int& x : a) std::cin >> x;
    // 座標圧縮
    std::vector<int> xs = a;
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    for (int& x : a) x = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    int m = xs.size();

    // 区間内の値の個数を持つ Fenwick Tree
    std::vector<int> bit(m + 1);
    int total = 0;
    auto add = [&](int i, int v) {
        total += v;
        for (i++; i <= m; i += i & -i) bit[i] += v;
    };
    auto count_less = [&](int i) {
        int ret = 0;
        for (; i > 0; i -= i & -i) ret += bit[i];
        return ret;
    };
    auto count_greater = [&](int i) { return total - count_less(i + 1); };

    Mo mo(n, 0LL,
        [&](long long& inv, int i) { inv += count_less(a[i]); add(a[i], 1); },
        [&](long long& inv, int i) { add(a[i], -1); inv -= count_less(a[i]); },
        [&](long long& inv, int i) { inv += count_greater(a[i]); add(a[i], 1); },
        [&](long long& inv, int i) { add(a[i], -1); inv -= count_greater(a[i]); });
    for (int i = 0; i < q; i++) {
        int l, r; std::cin >> l >> r;
        mo.query(l, r);
    }
    for (long long ans : mo.solve<long long>([](long long& inv) { return inv; })) {
        std::cout << ans << '\n';
    }
}
