#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// DynamicSegTree を愚直な実装とランダムに比較する
// 可換でないモノイド (1次関数の合成) を使い、要素数が大きい場合も確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/dynamic-segtree.hpp"

#include <iostream>
#include <map>
#include <random>
#include <utility>
#include <vector>

#include "../../src/math/modint.hpp"

using mint = modint998244353;
using S = Affine<mint>;
using M = monoid::Composite<mint>;

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    // 要素数が小さい場合: すべての操作を愚直な配列と比べる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1;
        DynamicSegTree<M> seg;
        seg = DynamicSegTree<M>(n);
        std::vector<S> v(n);
        auto naive_prod = [&](int l, int r) {
            S res;
            for (int i = l; i < r; i++) res = M::op(res, v[i]);
            return res;
        };
        auto random_affine = [&]() { return S{mint(rng() % 3), mint(rng() % 3)}; };
        if (seg.size() != n) ok = false;
        for (int t = 0; t < 40; t++) {
            int op = rng() % 6;
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            if (op == 0) {
                int k = rng() % n;
                S x = random_affine();
                if (rng() % 2)
                    seg.set(k, x);
                else
                    seg[k] = x;
                v[k] = x;
            } else if (op == 1) {
                int k = rng() % n;
                S x = random_affine();
                seg.apply(k, x);
                v[k] = M::op(v[k], x);
            } else if (op == 2) {
                if (seg.prod(l, r) != naive_prod(l, r)) ok = false;
            } else if (op == 3) {
                // g が単調でなくても、定義の条件を満たす r を返すか
                mint a = rng() % 3, b = rng() % 3;
                auto g = [&](const S& s) { return s == S() || s.a != a || s.b != b; };
                long long r2 = seg.max_right(l, g);
                if (!(l <= r2 && r2 <= n))
                    ok = false;
                else if (r2 != l && !g(naive_prod(l, r2)))
                    ok = false;
                else if (r2 != n && g(naive_prod(l, r2 + 1)))
                    ok = false;
            } else if (op == 4) {
                mint a = rng() % 3, b = rng() % 3;
                auto g = [&](const S& s) { return s == S() || s.a != a || s.b != b; };
                long long l2 = seg.min_left(r, g);
                if (!(0 <= l2 && l2 <= r))
                    ok = false;
                else if (l2 != r && !g(naive_prod(l2, r)))
                    ok = false;
                else if (l2 != 0 && g(naive_prod(l2 - 1, r)))
                    ok = false;
            } else {
                int k = rng() % n;
                const auto& cseg = seg;
                if (seg.get(k) != v[k] || cseg[k] != v[k] || S(seg[k]) != v[k]) ok = false;
            }
        }
        if (seg.all_prod() != naive_prod(0, n)) ok = false;
    }

    // 要素数が大きい場合: 値を持つ位置だけを map で持って比べる (和のモノイド)
    for (int rep = 0; rep < 300 && ok; rep++) {
        long long n = rep % 2 ? (long long)(rng() % 1000000000000000000ULL) + 1 : 1000000000000000000LL;
        DynamicSegTree seg(n, Monoid([](long long a, long long b) { return a + b; }, 0LL));
        std::map<long long, long long> v;
        auto random_pos = [&]() { return (long long)(rng() % n); };
        auto naive_prod = [&](long long l, long long r) {
            long long s = 0;
            for (auto it = v.lower_bound(l); it != v.end() && it->first < r; ++it) s += it->second;
            return s;
        };
        for (int t = 0; t < 60; t++) {
            int op = rng() % 5;
            long long l = random_pos(), r = random_pos();
            if (l > r) std::swap(l, r);
            if (rng() % 4 == 0) r = n;
            if (op == 0) {
                long long k = random_pos(), x = rng() % 10;
                seg.set(k, x);
                v[k] = x;
            } else if (op == 1) {
                if (seg.prod(l, r) != naive_prod(l, r)) ok = false;
            } else if (op == 2) {
                // 和が lim 以下になる最大の r
                long long lim = rng() % 30, s = 0, expect = n;
                for (auto it = v.lower_bound(l); it != v.end(); ++it) {
                    if (s + it->second > lim) {
                        expect = it->first;
                        break;
                    }
                    s += it->second;
                }
                if (seg.max_right(l, [&](long long x) { return x <= lim; }) != expect) ok = false;
            } else if (op == 3) {
                long long lim = rng() % 30, s = 0, expect = 0;
                for (auto it = v.lower_bound(r); it != v.begin();) {
                    --it;
                    if (s + it->second > lim) {
                        expect = it->first + 1;
                        break;
                    }
                    s += it->second;
                }
                if (seg.min_left(r, [&](long long x) { return x <= lim; }) != expect) ok = false;
            } else {
                long long k = v.empty() || rng() % 2 ? random_pos() : v.begin()->first;
                long long expect = v.count(k) ? v[k] : 0;
                if (seg.get(k) != expect) ok = false;
            }
        }
        if (seg.all_prod() != naive_prod(0, n) || seg.size() != n) ok = false;
    }

    // 要素数 0
    {
        DynamicSegTree<monoid::Sum<int>> empty;
        if (empty.size() != 0 || empty.prod(0, 0) != 0 || empty.all_prod() != 0) ok = false;
        if (empty.max_right(0, [](int) { return true; }) != 0 || empty.min_left(0, [](int) { return true; }) != 0) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
