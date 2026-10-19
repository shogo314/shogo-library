#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// PersistentSegTree を愚直な実装 (版ごとに配列を持つ) とランダムに比較する
// 古い版から更新しても、ほかの版が変わらないことを確かめる (区間コピーを含む)
// 可換でないモノイド (1次関数の合成) と、ラムダ式から作るモノイドを使う
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/persistent-segtree.hpp"

#include <iostream>
#include <random>
#include <sstream>
#include <vector>

#include "../../src/math/modint.hpp"

using mint = modint998244353;
using S = Affine<mint>;
using M = monoid::Composite<mint>;

S naive_prod(const std::vector<S>& v, int l, int r) {
    S res;
    for (int i = l; i < r; i++) res = M::op(res, v[i]);
    return res;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    auto random_affine = [&]() { return S{mint(rng() % 3), mint(rng() % 3)}; };
    for (int rep = 0; rep < 1500 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<std::vector<S>> naive(1, std::vector<S>(n));
        std::vector<PersistentSegTree<M>> seg;
        if (rep % 2 == 0) {
            seg.emplace_back(n);
        } else {
            for (auto& x : naive[0]) x = random_affine();
            seg.emplace_back(naive[0]);
        }
        for (int t = 0; t < 40 && ok; t++) {
            int ver = rng() % seg.size();
            int op = rng() % 7;
            if (op == 6) {
                int src = rng() % seg.size();
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) std::swap(l, r);
                seg.push_back(seg[ver].copy(seg[src], l, r));
                naive.push_back(naive[ver]);
                for (int i = l; i < r; i++) naive.back()[i] = naive[src][i];
            } else if (op == 0) {
                int k = rng() % n;
                S x = random_affine();
                seg.push_back(seg[ver].set(k, x));
                naive.push_back(naive[ver]);
                naive.back()[k] = x;
            } else if (op == 1) {
                int k = rng() % n;
                S x = random_affine();
                seg.push_back(seg[ver].apply(k, x));
                naive.push_back(naive[ver]);
                naive.back()[k] = M::op(naive.back()[k], x);
            } else if (op == 2) {
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) std::swap(l, r);
                if (seg[ver].prod(l, r) != naive_prod(naive[ver], l, r)) ok = false;
            } else if (op == 3) {
                // f が単調でなくても、定義の条件を満たす r を返すか
                int l = rng() % (n + 1);
                mint a = rng() % 3, b = rng() % 3;
                auto f = [&](const S& s) { return s == S() || s.a != a || s.b != b; };
                int r = seg[ver].max_right(l, f);
                if (!(l <= r && r <= n))
                    ok = false;
                else if (r != l && !f(naive_prod(naive[ver], l, r)))
                    ok = false;
                else if (r != n && f(naive_prod(naive[ver], l, r + 1)))
                    ok = false;
            } else if (op == 4) {
                int r = rng() % (n + 1);
                mint a = rng() % 3, b = rng() % 3;
                auto f = [&](const S& s) { return s == S() || s.a != a || s.b != b; };
                int l = seg[ver].min_left(r, f);
                if (!(0 <= l && l <= r))
                    ok = false;
                else if (l != r && !f(naive_prod(naive[ver], l, r)))
                    ok = false;
                else if (l != 0 && f(naive_prod(naive[ver], l - 1, r)))
                    ok = false;
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
    }

    // 和の max_right / min_left (単調な f) と、ラムダ式から作るモノイド・出力
    for (int rep = 0; rep < 1500 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<int> v(n);
        for (auto& x : v) x = rng() % 5;
        PersistentSegTree seg(v, Monoid([](int a, int b) { return a + b; }, 0));
        int k = rng() % n, x = rng() % 5;
        auto seg2 = seg.set(k, x);
        std::vector<int> v2 = v;
        v2[k] = x;
        for (int l = 0; l <= n; l++) {
            int lim = rng() % 15;
            int r = l, s = 0;
            while (r < n && s + v2[r] <= lim) s += v2[r++];
            if (seg2.max_right(l, [&](int t) { return t <= lim; }) != r) ok = false;
        }
        for (int r = 0; r <= n; r++) {
            int lim = rng() % 15;
            int l = r, s = 0;
            while (l > 0 && s + v[l - 1] <= lim) s += v[--l];
            if (seg.min_left(r, [&](int t) { return t <= lim; }) != l) ok = false;
        }
        std::ostringstream os, expect;
        os << seg2;
        for (int i = 0; i < n; i++) expect << (i ? " " : "") << v2[i];
        if (os.str() != expect.str()) ok = false;
    }

    // 要素数が大きくても単位元の木は O(log n) で作れる
    {
        PersistentSegTree<monoid::Sum<long long>> big(1000000000);
        auto b1 = big.set(999999999, 5).set(0, 3);
        if (big.all_prod() != 0 || b1.all_prod() != 8 || b1.prod(1, 999999999) != 0) ok = false;
        if (b1.copy(big, 1, 1000000000).all_prod() != 3 || big.copy(b1, 0, 1).all_prod() != 3) ok = false;
        if (b1.max_right(0, [](long long s) { return s < 8; }) != 999999999) ok = false;
        PersistentSegTree<monoid::Sum<long long>> empty;
        if (empty.size() != 0 || empty.prod(0, 0) != 0) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
