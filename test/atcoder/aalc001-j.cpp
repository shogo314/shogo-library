#define PROBLEM "https://atcoder.jp/contests/aalc001/tasks/aalc001_j"
#define IGNORE

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "../../src/data_structures/lazy-segtree.hpp"

int main(void) {
    int q;
    std::cin >> q;
    std::vector<std::array<long long, 3>> qs(q);
    std::vector<long long> xs;
    for (auto& [t, l, r] : qs) {
        std::cin >> t >> l >> r;
        l--;
        xs.push_back(l);
        xs.push_back(r);
    }
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    // 座標圧縮した区間ごとに {0 の個数, 1 の個数} を持ち、反転は成分 0 と 1 の入れ替え
    using A = acted_monoid::Rearrange<monoid::Sum<long long>, 2>;
    std::vector<A::S> init;
    for (std::size_t i = 0; i + 1 < xs.size(); i++) init.push_back({xs[i + 1] - xs[i], 0});
    LazySegTree<A> seg(init);
    auto idx = [&](long long x) { return int(std::lower_bound(xs.begin(), xs.end(), x) - xs.begin()); };
    for (auto [t, l, r] : qs) {
        if (t == 1) {
            seg.apply(idx(l), idx(r), A::swap(0, 1));
        } else {
            std::cout << seg.prod(idx(l), idx(r))[1] << '\n';
        }
    }
}
