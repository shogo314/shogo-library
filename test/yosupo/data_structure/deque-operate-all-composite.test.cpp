#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include <iostream>

#include "../../../src/data_structures/sliding-window-aggregation.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;
    // Composite は f∘g なので、先頭から順に適用するには積の順序を逆にする
    DequeAggregation<monoid::Reverse<monoid::Composite<mint>>> dq;
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0 || t == 1) {
            mint a, b;
            std::cin >> a >> b;
            if (t == 0) {
                dq.push_front(Affine<mint>{a, b});
            } else {
                dq.push_back(Affine<mint>{a, b});
            }
        } else if (t == 2) {
            dq.pop_front();
        } else if (t == 3) {
            dq.pop_back();
        } else {
            mint x;
            std::cin >> x;
            std::cout << dq.prod()(x) << '\n';
        }
    }
}
