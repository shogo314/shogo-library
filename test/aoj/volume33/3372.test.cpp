#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3372"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#include "../../../src/graph/tree.hpp"
using ll = long long;

template <typename T, typename U>
inline bool chmax(T& x, const U& y) { return x < y ? (x = y, true) : false; }

int main() {
    int n;
    std::cin >> n;
    Tree tr(n);
    tr.read();
    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    auto rt = tr.set_root(0);
    Tree<ll> tr_costed(n);
    for (int u = 0; u < n; u++) {
        for (int v : rt.child[u]) {
            tr_costed.add_edge(u, v, a[v]);
        }
    }
    auto lcart = tr_costed.build_lca(0);
    std::vector<int> b(n - 1);
    std::vector<int> b_cnt(n);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> b[i];
        b[i]--;
        b_cnt[b[i]]++;
    }
    std::reverse(b.begin(), b.end());
    int init = -1;
    for (int i = 0; i < n; i++) {
        if (!b_cnt[i]) init = i;
    }
    std::tuple<ll, int, int> farthest = {a[init], init, init};
    std::vector<ll> ans = {a[init]};
    auto dist = [&](int i, int j) { return lcart.dist(i, j) + a[lcart.lca(i, j)]; };
    for (int bi : b) {
        auto [d, x, y] = farthest;
        chmax(farthest, std::make_tuple(dist(x, bi), x, bi));
        chmax(farthest, std::make_tuple(dist(y, bi), y, bi));
        ans.push_back(std::get<0>(farthest));
    }
    std::reverse(ans.begin(), ans.end());
    for (ll a : ans) {
        std::cout << a << std::endl;
    }
}
