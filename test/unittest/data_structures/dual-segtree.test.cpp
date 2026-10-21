#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// DualSegTree を愚直な実装とランダムに比較する
// 可換でない作用 (アフィン変換) と、区間の長さを使う作用 (区間加算・区間和) で確かめる
// 別名 RAddQ / RUpdateQ / RChminQ / RChmaxQ / RAffineQ も確かめる (順序や S(sz) を持たない型でも使えること)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/dual-segtree.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <type_traits>
#include <vector>

#include "../../../src/data_structures/lazy-segtree.hpp"  // 別名がかぶらないこと
#include "../../../src/data_structures/segtree-beats.hpp"
#include "../../../src/data_structures/segtree.hpp"
#include "../../../src/geometry/vector.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

static_assert(std::is_same_v<RAddQ<long long>, DualSegTree<acted_monoid::AddMin<long long>>>);
static_assert(std::is_same_v<RUpdateQ<long long>, DualSegTree<acted_monoid::UpdateMin<long long>>>);
static_assert(std::is_same_v<RChminQ<long long>, DualSegTree<acted_monoid::ChminMin<long long>>>);
static_assert(std::is_same_v<RChmaxQ<long long>, DualSegTree<acted_monoid::ChmaxMax<long long>>>);
static_assert(std::is_same_v<RAffineQ<mint>, DualSegTree<acted_monoid::AffineSum<mint>>>);

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<mint> v(n);
        DualSegTree<acted_monoid::AffineSum<mint>> seg;
        switch (rep % 3) {
            case 0:
                seg = DualSegTree<acted_monoid::AffineSum<mint>>(n);
                break;
            case 1: {
                mint x = rng() % 10;
                seg = DualSegTree<acted_monoid::AffineSum<mint>>(n, x);
                v.assign(n, x);
                break;
            }
            default:
                for (auto& x : v) x = rng() % 10;
                seg = DualSegTree<acted_monoid::AffineSum<mint>>(v);
                break;
        }
        if (seg.size() != n) ok = false;
        for (int t = 0; t < 40; t++) {
            int op = rng() % 5;
            Affine<mint> f{mint(rng() % 5), mint(rng() % 5)};
            if (op == 0) {
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) std::swap(l, r);
                seg.apply(l, r, f);
                for (int i = l; i < r; i++) v[i] = f(v[i]);
            } else if (op == 1) {
                int k = rng() % n;
                seg.apply(k, f);
                v[k] = f(v[k]);
            } else if (op == 2) {
                int k = rng() % n;
                mint x = rng() % 10;
                seg.set(k, x);
                v[k] = x;
            } else if (op == 3) {
                int k = rng() % n;
                if (seg.get(k) != v[k]) ok = false;
            } else {
                if (seg.to_vector() != v) ok = false;
            }
        }
        for (int k = 0; k < n; k++) {
            if (seg.get(k) != v[k]) ok = false;
        }
    }
    // 区間の長さを使う mapping (要素ごとに長さ 1 として作用する)
    for (int rep = 0; rep < 500 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<long long> v(n);
        DualSegTree<acted_monoid::AddSum<long long>> seg(n);
        for (int t = 0; t < 40; t++) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            long long x = static_cast<long long>(rng() % 21) - 10;
            seg.apply(l, r, x);
            for (int i = l; i < r; i++) v[i] += x;
            int k = rng() % n;
            if (seg.get(k) != v[k]) ok = false;
        }
    }
    // 別名 (区間加算・代入・chmin・chmax)
    for (int rep = 0; rep < 500 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<long long> v(n);
        for (auto& x : v) x = static_cast<long long>(rng() % 21) - 10;
        RAddQ<long long> add(v);
        RUpdateQ<long long> upd(v);
        RChminQ<long long> chmin(v);
        RChmaxQ<long long> chmax(v);
        std::vector<long long> va = v, vu = v, vmin = v, vmax = v;
        for (int t = 0; t < 40; t++) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            long long x = static_cast<long long>(rng() % 21) - 10;
            add.apply(l, r, x);
            upd.apply(l, r, x);
            chmin.apply(l, r, x);
            chmax.apply(l, r, x);
            for (int i = l; i < r; i++) va[i] += x, vu[i] = x, vmin[i] = std::min(vmin[i], x), vmax[i] = std::max(vmax[i], x);
            int k = rng() % n;
            if (add.get(k) != va[k] || upd.get(k) != vu[k] || chmin.get(k) != vmin[k] || chmax.get(k) != vmax[k]) ok = false;
        }
    }
    // 順序や S(sz) を持たない型 (std::string、Vector)
    {
        RUpdateQ<std::string> seg(5, "");
        seg.apply(1, 4, "abc");
        seg.apply(2, 3, "x");
        if (seg.to_vector() != std::vector<std::string>{"", "abc", "x", "abc", ""}) ok = false;
        using V = Vector<long long>;
        RAddQ<V> seg2(3);
        seg2.apply(0, 2, V(1, 2));
        seg2.apply(1, 3, V(10, 20));
        if (!(seg2.get(0) == V(1, 2) && seg2.get(1) == V(11, 22) && seg2.get(2) == V(10, 20))) ok = false;
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
