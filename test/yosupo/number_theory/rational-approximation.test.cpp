#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"

#include <iostream>

#include "../../../src/math/rational.hpp"
#include "../../../src/math/stern-brocot.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, x, y;
        std::cin >> n >> x >> y;
        Rational<long long> r(x, y);
        // x / y そのものが分子・分母ともに n 以下なら、それが答え
        if (r.num() <= n && r.den() <= n) {
            std::cout << r.num() << ' ' << r.den() << ' ' << r.num() << ' ' << r.den() << '\n';
            continue;
        }
        // 分子・分母が n 以下の分数で、x / y 以下の最大と x / y より大きい最小
        auto [lo, hi] = stern_brocot::binary_search(n, [&](const Rational<long long>& a) { return a <= r; }, n);
        std::cout << lo.first << ' ' << lo.second << ' ' << hi.first << ' ' << hi.second << '\n';
    }
}
