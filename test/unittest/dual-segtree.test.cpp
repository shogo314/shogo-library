#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// DualSegTree を愚直な実装とランダムに比較する
// 可換でない作用 (アフィン変換) と、区間の長さを使う作用 (区間加算・区間和) で確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/dual-segtree.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../src/math/modint.hpp"

using mint = modint998244353;

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
            long long x = (long long)(rng() % 21) - 10;
            seg.apply(l, r, x);
            for (int i = l; i < r; i++) v[i] += x;
            int k = rng() % n;
            if (seg.get(k) != v[k]) ok = false;
        }
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
