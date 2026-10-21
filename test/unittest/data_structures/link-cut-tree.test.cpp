#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// link-cut-tree.hpp の LinkCutTree と SubtreeLinkCutTree を、森の隣接リストで愚直に求めたものとランダムに比べる
// set と apply で値を変える。LinkCutTree は可換でないモノイド (1 次関数の合成) で prod の向きも確かめる
// evert・link・cut・prod・subtree_prod で根が変わるので、愚直な側でも根を追いかけて lca・root と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/link-cut-tree.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/algebra/group.hpp"
#include "../../../src/algebra/monoid.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

struct Forest {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> root;  // 各頂点を含む木の、今の根
    explicit Forest(int n) : n(n), adj(n), root(n) {
        for (int i = 0; i < n; i++) root[i] = i;
    }
    std::vector<int> component(int v) const {
        std::vector<int> res = {v}, seen(n, 0);
        seen[v] = 1;
        for (int i = 0; i < static_cast<int>(res.size()); i++) {
            for (int u : adj[res[i]]) {
                if (!seen[u]) seen[u] = 1, res.push_back(u);
            }
        }
        return res;
    }
    void evert(int v) {
        for (int u : component(v)) root[u] = v;
    }
    bool connected(int u, int v) const {
        auto c = component(u);
        return std::find(c.begin(), c.end(), v) != c.end();
    }
    // u から v へのパス (u, ..., v)
    std::vector<int> path(int u, int v) const {
        std::vector<int> par(n, -2), que = {u};
        par[u] = -1;
        for (int i = 0; i < static_cast<int>(que.size()); i++) {
            for (int w : adj[que[i]]) {
                if (par[w] == -2) par[w] = que[i], que.push_back(w);
            }
        }
        std::vector<int> res;
        for (int x = v; x != -1; x = par[x]) res.push_back(x);
        std::reverse(res.begin(), res.end());
        return res;
    }
    void link(int u, int v) {
        int r = root[v];
        adj[u].push_back(v), adj[v].push_back(u);
        evert(r);
    }
    void cut(int u, int v) {
        adj[u].erase(std::find(adj[u].begin(), adj[u].end(), v));
        adj[v].erase(std::find(adj[v].begin(), adj[v].end(), u));
        evert(u), evert(v);
    }
    int lca(int u, int v) const {
        auto pu = path(u, root[u]), pv = path(v, root[v]);
        for (int x : pu) {
            if (std::find(pv.begin(), pv.end(), x) != pv.end()) return x;
        }
        return -1;
    }
    // p を根としたときの v の部分木
    std::vector<int> subtree(int v, int p) const {
        std::vector<int> res;
        for (int x : component(v)) {
            auto pa = path(p, x);
            if (std::find(pa.begin(), pa.end(), v) != pa.end()) res.push_back(x);
        }
        return res;
    }
};

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 10 + 1;
        std::vector<Affine<mint>> f(n);
        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) f[i] = {mint(rng() % 5 + 1), mint(rng() % 5)}, a[i] = rng() % 100;
        LinkCutTree<monoid::Composite<mint>> lct(f);
        SubtreeLinkCutTree<group::Sum<long long>> st(a);
        Forest fo(n);
        for (int q = 0; q < 300 && ok; q++) {
            int type = rng() % 8, u = rng() % n, v = rng() % n;
            if (type == 0) {
                if (u == v || fo.connected(u, v)) continue;
                lct.link(u, v), st.link(u, v), fo.link(u, v);
            } else if (type == 1) {
                if (fo.adj[u].empty()) continue;
                v = fo.adj[u][rng() % fo.adj[u].size()];
                lct.cut(u, v), st.cut(u, v), fo.cut(u, v);
            } else if (type == 2) {
                Affine<mint> g{mint(rng() % 5 + 1), mint(rng() % 5)};
                long long x = rng() % 100;
                if (rng() % 2) {
                    f[u] = g, a[u] = x;
                    lct.set(u, g), st.set(u, x);
                } else {
                    f[u] = monoid::Composite<mint>::op(f[u], g), a[u] += x;
                    lct.apply(u, g), st.apply(u, x);
                }
                if (lct.get(u) != f[u] || st.get(u) != a[u]) ok = false;
            } else if (type == 3) {
                if (lct.connected(u, v) != fo.connected(u, v) || st.connected(u, v) != fo.connected(u, v)) ok = false;
                if (!fo.connected(u, v)) continue;
                // u 側から順に合成したもの f_u∘...∘f_v
                Affine<mint> g;
                long long s = 0;
                for (int x : fo.path(u, v)) g = monoid::Composite<mint>::op(g, f[x]), s += a[x];
                if (lct.prod(u, v) != g || st.prod(u, v) != s) ok = false;
                fo.evert(u);
            } else if (type == 4) {
                if (!fo.connected(u, v)) continue;
                if (lct.lca(u, v) != fo.lca(u, v)) ok = false;
            } else if (type == 5) {
                if (lct.root(u) != fo.root[u] || st.root(u) != fo.root[u]) ok = false;
            } else if (type == 6) {
                lct.evert(u), st.evert(u), fo.evert(u);
            } else {
                if (!fo.connected(u, v)) continue;
                long long s = 0;
                for (int x : fo.subtree(v, u)) s += a[x];
                if (st.subtree_prod(v, u) != s) ok = false;
                fo.evert(u);
                // lct の根も st とそろえておく
                lct.evert(u);
            }
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
