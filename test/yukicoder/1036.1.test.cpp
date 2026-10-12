#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include <iostream>
#include <vector>

#include "../../src/data_structures/segtree.hpp"

// 左端 l を固定し、gcd が 1 になる最小の右端を max_right で求める
int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    RGcdQ<long long> seg(a);
    long long ans = 0;
    for (int l = 0; l < n; l++) {
        // [l, r) の gcd が 1 でない最大の r。a[r] まで含めると gcd が 1 になる
        int r = seg.max_right(l, [](long long g) { return g != 1; });
        ans += n - r;
    }
    std::cout << ans << '\n';
}
