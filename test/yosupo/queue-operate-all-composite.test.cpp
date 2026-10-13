#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>

#include "../../src/math/modint.hpp"
#include "../../src/data_structures/sliding-window-aggregation.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    using mint = modint998244353;
    int q;
    std::cin >> q;
    SlidingWindowAggregation<monoid::Composite<mint>> swag;
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            mint a, b;
            std::cin >> a >> b;
            swag.push(Affine<mint>{a, b});
        } else if (t == 1) {
            swag.pop();
        } else {
            mint x;
            std::cin >> x;
            std::cout << swag.prod()(x) << '\n';
        }
    }
}
