#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include <iostream>
#include <vector>

#include "../../src/data_structures/segtree.hpp"

// 右端 r を固定し、gcd が 1 になる最大の左端を min_left で求める
int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    RGcdQ<long long> seg(a);
    long long ans = 0;
    for (int r = 1; r <= n; r++) {
        // [l, r) の gcd が 1 でない最小の l。a[l - 1] まで含めると gcd が 1 になる
        int l = seg.min_left(r, [](long long g) { return g != 1; });
        ans += l;
    }
    std::cout << ans << '\n';
}
