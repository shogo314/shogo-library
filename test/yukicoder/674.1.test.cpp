#define PROBLEM "https://yukicoder.me/problems/no/674"

#include <iostream>
#include <set>

#include "../../src/data_structures/monoid-unionfind.hpp"

using ll = long long;

int main() {
    ll D, Q;
    std::cin >> D >> Q;
    std::vector<std::pair<ll, ll>> AB(Q);
    std::set<ll> s;
    for (auto& [A, B] : AB) {
        std::cin >> A >> B;
        s.insert(A);
        s.insert(A - 1);
        s.insert(B);
        s.insert(B + 1);
    }
    std::vector<ll> v(s.begin(), s.end());
    std::vector<bool> f(s.size());
    using M = monoid::MinMax<int>;
    std::vector<M::S> init;
    for (long long i = 0; i < static_cast<long long>(v.size()); i++) {
        init.emplace_back(static_cast<int>(i));
    }
    MonoidUnionFind<M> uf(init);
    ll ans = 0;
    for (auto [A, B] : AB) {
        int k = std::lower_bound(v.begin(), v.end(), A) - v.begin();
        auto p = uf.prod(k);
        while (v[p.max + 1] <= B) {
            uf.merge(k, p.max + 1);
            k = p.max + 1;
            p = uf.prod(k);
        }
        if (f[p.min - 1]) {
            uf.merge(p.min - 1, p.min);
        }
        if (f[p.max + 1]) {
            uf.merge(p.max, p.max + 1);
        }
        f[p.min] = true;
        f[p.max] = true;
        p = uf.prod(k);
        if (ans < v[p.max] - v[p.min] + 1) {
            ans = v[p.max] - v[p.min] + 1;
        }
        std::cout << ans << std::endl;
    }
}
