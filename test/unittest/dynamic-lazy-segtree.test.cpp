#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// DynamicLazySegTree を愚直な実装とランダムに比較する
// 合成が可換でない作用 (アフィン変換) と、区間の位置を使う作用 (a_i に f * i を足す) を使い、
// 要素数が int に収まらないほど大きい場合も確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/dynamic-lazy-segtree.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "../../src/math/modint.hpp"

using mint = modint998244353;

// l 以上 r 未満の整数の和
mint index_sum(long long l, long long r) {
    if (l >= r) return 0;
    mint a = l, b = r - 1, c = r - l;
    return (a + b) * c / 2;
}

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    // 要素数が小さい場合: アフィン変換と区間和を、すべての操作で愚直な配列と比べる
    using Seg = DynamicLazySegTree<acted_monoid::AffineSum<mint>>;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1;
        Seg seg;
        seg = Seg(n);
        std::vector<mint> v(n);
        auto naive_prod = [&](int l, int r) {
            mint s = 0;
            for (int i = l; i < r; i++) s += v[i];
            return s;
        };
        if (seg.size() != n) ok = false;
        for (int t = 0; t < 40; t++) {
            int op = rng() % 7;
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            Affine<mint> f{mint(rng() % 5), mint(rng() % 5)};
            if (op == 0) {
                seg.apply(l, r, f);
                for (int i = l; i < r; i++) v[i] = f(v[i]);
            } else if (op == 1) {
                int k = rng() % n;
                seg.apply(k, f);
                v[k] = f(v[k]);
            } else if (op == 2) {
                int k = rng() % n;
                mint x = rng() % 10;
                if (rng() % 2)
                    seg.set(k, x);
                else
                    seg[k] = x;
                v[k] = x;
            } else if (op == 3) {
                if (seg.prod(l, r) != naive_prod(l, r)) ok = false;
            } else if (op == 4) {
                // g が単調でなくても、定義の条件を満たす r を返すか
                mint c = rng() % 10;
                auto g = [&](mint s) { return s == 0 || s != c; };
                long long r2 = seg.max_right(l, g);
                if (!(l <= r2 && r2 <= n))
                    ok = false;
                else if (r2 != l && !g(naive_prod(l, r2)))
                    ok = false;
                else if (r2 != n && g(naive_prod(l, r2 + 1)))
                    ok = false;
            } else if (op == 5) {
                mint c = rng() % 10;
                auto g = [&](mint s) { return s == 0 || s != c; };
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
                if (seg.get(k) != v[k] || cseg[k] != v[k] || mint(seg[k]) != v[k]) ok = false;
            }
        }
        if (seg.all_prod() != naive_prod(0, n)) ok = false;
    }

    // 要素数が大きい場合: a_i に f * i を足す作用と区間和 (mapping が区間の位置 [l, r) を使う)
    // 作用の列を持っておき、区間和は各作用との共通部分から求める
    auto am = ActedMonoid(
        [](mint a, mint b) { return a + b; }, mint(0),
        [](mint f, mint x, long long l, long long r) { return x + f * index_sum(l, r); },
        [](mint f, mint g) { return f + g; }, mint(0));
    for (int rep = 0; rep < 300 && ok; rep++) {
        long long n = rep % 2 ? (long long)(rng() % 1000000000000000000ULL) + 1 : 1000000000000000000LL;
        DynamicLazySegTree seg(n, am);
        std::vector<std::array<long long, 3>> ops;  // l, r, f
        auto naive_prod = [&](long long l, long long r) {
            mint s = 0;
            for (auto [a, b, f] : ops) s += mint(f) * index_sum(std::max(a, l), std::min(b, r));
            return s;
        };
        auto random_pos = [&]() { return (long long)(rng() % n); };
        for (int t = 0; t < 40; t++) {
            long long l = random_pos(), r = random_pos();
            if (l > r) std::swap(l, r);
            if (rng() % 4 == 0) r = n;
            int op = rng() % 4;
            if (op == 0) {
                long long f = rng() % 5;
                seg.apply(l, r, f);
                ops.push_back({l, r, f});
            } else if (op == 1) {
                if (seg.prod(l, r) != naive_prod(l, r)) ok = false;
            } else if (op == 2) {
                long long k = random_pos();
                if (seg.get(k) != naive_prod(k, k + 1)) ok = false;
            } else {
                long long k = random_pos();
                long long f = rng() % 5;
                seg.apply(k, f);
                ops.push_back({k, k + 1, f});
            }
        }
        if (seg.all_prod() != naive_prod(0, n) || seg.size() != n) ok = false;
    }

    // 要素数が大きい場合の max_right / min_left: 区間加算と区間和 (加える値は 0 以上なので和は単調)
    for (int rep = 0; rep < 300 && ok; rep++) {
        long long n = 1000000000000000000LL;
        DynamicLazySegTree<acted_monoid::AddSum<long long>> seg(n);
        // 区間に 1 を足すと和がすぐ大きくなるので、短い区間だけに足す
        std::vector<std::array<long long, 3>> ops;
        for (int t = 0; t < 10; t++) {
            long long l = rng() % n, len = rng() % 5 + 1, f = rng() % 3;
            long long r = std::min(n, l + len);
            seg.apply(l, r, f);
            ops.push_back({l, r, f});
        }
        long long l = rng() % 2 ? 0 : (long long)(rng() % n);
        long long lim = rng() % 10;
        // 和が lim を超える最初の位置を、作用の端点を順に見て求める
        std::vector<long long> pts;
        for (auto [a, b, f] : ops) {
            for (long long p = std::max(a, l); p < b; p++) pts.push_back(p);
        }
        std::sort(pts.begin(), pts.end());
        pts.erase(std::unique(pts.begin(), pts.end()), pts.end());
        long long s = 0, expect = n;
        for (long long p : pts) {
            long long x = 0;
            for (auto [a, b, f] : ops) {
                if (a <= p && p < b) x += f;
            }
            if (s + x > lim) {
                expect = p;
                break;
            }
            s += x;
        }
        if (seg.max_right(l, [&](long long x) { return x <= lim; }) != expect) ok = false;
        // min_left は、max_right の結果の右端から戻ると l 以下の位置になるか、
        // あるいは和が lim を超える位置の直後になる
        long long r = expect;
        long long l2 = seg.min_left(r, [&](long long x) { return x <= lim; });
        if (!(0 <= l2 && l2 <= r) || seg.prod(l2, r) > lim || (l2 > 0 && seg.prod(l2 - 1, r) <= lim)) ok = false;
    }

    // 要素数 0
    {
        DynamicLazySegTree<acted_monoid::AddSum<long long>> empty;
        if (empty.size() != 0 || empty.prod(0, 0) != 0 || empty.all_prod() != 0) ok = false;
        if (empty.max_right(0, [](long long) { return true; }) != 0 || empty.min_left(0, [](long long) { return true; }) != 0) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
