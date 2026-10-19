#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// PersistentLazySegTree を愚直な実装 (版ごとに配列を持つ) とランダムに比較する
// 古い版から更新しても、ほかの版が変わらないことを確かめる
// 合成が可換でない作用 (アフィン変換) と、区間の位置を使う作用 (a_i に f * i を足す) を使う
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/persistent-lazy-segtree.hpp"

#include <iostream>
#include <random>
#include <sstream>
#include <vector>

#include "../../src/math/modint.hpp"

using mint = modint998244353;

// 版を増やしながら、すべての操作を愚直な実装と比べる
// make_f は作用素を、apply_f は作用素を 1 つの値に適用した結果 (位置 i を受け取る) を作る
template <typename Seg, typename MakeS, typename MakeF, typename ApplyF>
bool random_test(std::mt19937& rng, int n, Seg seg0, std::vector<typename Seg::S> v0, MakeS make_s, MakeF make_f, ApplyF apply_f) {
    using S = typename Seg::S;
    bool ok = true;
    std::vector<Seg> seg{seg0};
    std::vector<std::vector<S>> naive{v0};
    auto naive_prod = [&](const std::vector<S>& v, int l, int r) {
        S res = seg0.prod(0, 0);
        for (int i = l; i < r; i++) res = res + v[i];
        return res;
    };
    for (int t = 0; t < 50; t++) {
        int ver = rng() % seg.size();
        int op = rng() % 7;
        int l = rng() % (n + 1), r = rng() % (n + 1);
        if (l > r) std::swap(l, r);
        if (op == 0) {
            auto f = make_f();
            seg.push_back(seg[ver].apply(l, r, f));
            naive.push_back(naive[ver]);
            for (int i = l; i < r; i++) naive.back()[i] = apply_f(f, naive.back()[i], i);
        } else if (op == 1) {
            int k = rng() % n;
            auto f = make_f();
            seg.push_back(seg[ver].apply(k, f));
            naive.push_back(naive[ver]);
            naive.back()[k] = apply_f(f, naive.back()[k], k);
        } else if (op == 2) {
            int k = rng() % n;
            S x = make_s();
            seg.push_back(seg[ver].set(k, x));
            naive.push_back(naive[ver]);
            naive.back()[k] = x;
        } else if (op == 3) {
            int src = rng() % seg.size();
            seg.push_back(seg[ver].copy(seg[src], l, r));
            naive.push_back(naive[ver]);
            for (int i = l; i < r; i++) naive.back()[i] = naive[src][i];
        } else if (op == 4) {
            if (seg[ver].prod(l, r) != naive_prod(naive[ver], l, r)) ok = false;
        } else {
            int k = rng() % n;
            if (seg[ver].get(k) != naive[ver][k] || seg[ver][k] != naive[ver][k]) ok = false;
        }
    }
    // すべての版が、作ったときの内容のままか
    for (int i = 0; i < static_cast<int>(seg.size()); i++) {
        if (seg[i].size() != n) ok = false;
        if (seg[i].to_vector() != naive[i]) ok = false;
        if (seg[i].all_prod() != naive_prod(naive[i], 0, n)) ok = false;
    }
    return ok;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;

    // アフィン変換と区間和
    using Seg = PersistentLazySegTree<acted_monoid::AffineSum<mint>>;
    for (int rep = 0; rep < 1500 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<mint> v(n);
        Seg seg;
        if (rep % 2 == 0) {
            seg = Seg(n);
        } else {
            for (auto& x : v) x = rng() % 10;
            seg = Seg(v);
        }
        ok &= random_test(
            rng, n, seg, v, [&]() { return mint(rng() % 10); },
            [&]() { return Affine<mint>{mint(rng() % 5), mint(rng() % 5)}; },
            [](const Affine<mint>& f, mint x, int) { return f(x); });
    }

    // a_i に f * i を足す作用と区間和 (mapping が区間の位置 [l, r) を使う)
    auto am = ActedMonoid(
        [](long long a, long long b) { return a + b; }, 0LL,
        [](long long f, long long x, int l, int r) { return x + f * static_cast<long long>(l + r - 1) * (r - l) / 2; },
        [](long long f, long long g) { return f + g; }, 0LL);
    for (int rep = 0; rep < 1500 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<long long> v(n);
        for (auto& x : v) x = rng() % 10;
        PersistentLazySegTree seg(v, am);
        ok &= random_test(
            rng, n, seg, v, [&]() { return static_cast<long long>(rng() % 10); },
            [&]() { return static_cast<long long>(rng() % 5); },
            [](long long f, long long x, int i) { return x + f * i; });
    }

    // 区間加算・区間和の max_right / min_left (単調な g) と出力
    for (int rep = 0; rep < 1500 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<long long> v(n);
        for (auto& x : v) x = rng() % 5;
        PersistentLazySegTree<acted_monoid::AddSum<long long>> seg(v);
        int l0 = rng() % (n + 1), r0 = rng() % (n + 1);
        if (l0 > r0) std::swap(l0, r0);
        long long f = rng() % 3;
        auto seg2 = seg.apply(l0, r0, f);
        std::vector<long long> v2 = v;
        for (int i = l0; i < r0; i++) v2[i] += f;
        for (int l = 0; l <= n; l++) {
            long long lim = rng() % 20;
            int r = l;
            long long s = 0;
            while (r < n && s + v2[r] <= lim) s += v2[r++];
            if (seg2.max_right(l, [&](long long t) { return t <= lim; }) != r) ok = false;
        }
        for (int r = 0; r <= n; r++) {
            long long lim = rng() % 20;
            int l = r;
            long long s = 0;
            while (l > 0 && s + v2[l - 1] <= lim) s += v2[--l];
            if (seg2.min_left(r, [&](long long t) { return t <= lim; }) != l) ok = false;
        }
        std::ostringstream os, expect;
        os << seg2;
        for (int i = 0; i < n; i++) expect << (i ? " " : "") << v2[i];
        if (os.str() != expect.str()) ok = false;
    }

    // 要素数が大きくても単位元の木は O(log n) で作れる
    {
        PersistentLazySegTree<acted_monoid::AddSum<long long>> big(1000000000);
        auto b1 = big.apply(0, 1000000000, 1);
        auto b2 = b1.copy(big, 10, 999999990);
        if (big.all_prod() != 0 || b1.all_prod() != 1000000000 || b2.all_prod() != 20 || b2.prod(5, 15) != 5) ok = false;
        if (b2.max_right(0, [](long long s) { return s < 10; }) != 9) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
