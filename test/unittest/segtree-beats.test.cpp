#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// SegTreeBeats を愚直な実装とランダムに比較する
// 区間 chmin / chmax / 加算、1 点の apply / set / get / seg[k]、prod、all_prod、max_right、min_left、size、os << seg
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/segtree-beats.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

constexpr long long inf = 2e18;

// test/yosupo/range-chmin-chmax-add-range-sum.1.test.cpp と同じ作用素付きモノイド
struct Node {
    // 1番目、1番目の要素数、2番目、合計
    long long max1, max1_num, max2, min1, min1_num, min2, sum;
    Node(long long x = 0) : max1(x), max1_num(1), max2(-inf), min1(x), min1_num(1), min2(inf), sum(x) {}
};
std::ostream& operator<<(std::ostream& os, const Node& x) { return os << x.sum; }
struct Clamp {
    // clamp(x + add, lb, ub)
    long long lb, ub, add;
};
struct ChminChmaxAddSum {
    using S = Node;
    using F = Clamp;
    S op(const S& l, const S& r) const {
        S res;
        res.max1 = std::max(l.max1, r.max1);
        if (l.max1 == r.max1) {
            res.max1_num = l.max1_num + r.max1_num;
            res.max2 = std::max(l.max2, r.max2);
        } else if (l.max1 > r.max1) {
            res.max1_num = l.max1_num;
            res.max2 = std::max(l.max2, r.max1);
        } else {
            res.max1_num = r.max1_num;
            res.max2 = std::max(l.max1, r.max2);
        }
        res.min1 = std::min(l.min1, r.min1);
        if (l.min1 == r.min1) {
            res.min1_num = l.min1_num + r.min1_num;
            res.min2 = std::min(l.min2, r.min2);
        } else if (l.min1 < r.min1) {
            res.min1_num = l.min1_num;
            res.min2 = std::min(l.min2, r.min1);
        } else {
            res.min1_num = r.min1_num;
            res.min2 = std::min(l.min1, r.min2);
        }
        res.sum = l.sum + r.sum;
        return res;
    }
    S e() const {
        S res;
        res.max1 = -inf;
        res.max1_num = 0;
        res.max2 = -inf;
        res.min1 = inf;
        res.min1_num = 0;
        res.min2 = inf;
        res.sum = 0;
        return res;
    }
    std::pair<bool, S> mapping(const F& f, const S& x, int sz) const {
        S res = x;
        res.max1 += f.add;
        res.max2 += f.add;
        res.min1 += f.add;
        res.min2 += f.add;
        res.sum += f.add * sz;
        if (res.max1 == res.min1) {
            long long x = std::clamp(res.max1, f.lb, f.ub);
            res.max1 = x;
            res.max2 = -inf;
            res.min1 = x;
            res.min2 = inf;
            res.sum = x * sz;
            return {false, res};
        }
        if (res.max1 == res.min2) {
            long long xr = std::clamp(res.max1, f.lb, f.ub);
            long long xl = std::clamp(res.min1, f.lb, f.ub);
            if (xr == xl) {
                res.max1 = xr;
                res.max1_num = sz;
                res.max2 = -inf;
                res.min1 = xr;
                res.min1_num = sz;
                res.min2 = inf;
                res.sum = xr * sz;
                return {false, res};
            }
            res.max1 = xr;
            res.max2 = xl;
            res.min1 = xl;
            res.min2 = xr;
            res.sum = xr * res.max1_num + xl * res.min1_num;
            return {false, res};
        }
        if (f.ub <= res.max2) return {true, res};
        if (f.lb >= res.min2) return {true, res};
        if (f.ub < res.max1) {
            res.sum -= (res.max1 - f.ub) * res.max1_num;
            res.max1 = f.ub;
        }
        if (f.lb > res.min1) {
            res.sum += (f.lb - res.min1) * res.min1_num;
            res.min1 = f.lb;
        }
        return {false, res};
    }
    F composition(const F& f, const F& g) const {
        F res;
        res.lb = std::clamp(g.lb + f.add, f.lb, f.ub);
        res.ub = std::clamp(g.ub + f.add, f.lb, f.ub);
        res.add = f.add + g.add;
        return res;
    }
    F id() const {
        F res;
        res.lb = -inf;
        res.ub = inf;
        res.add = 0;
        return res;
    }
};

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

long long clamp_apply(const Clamp& f, long long x) { return std::clamp(x + f.add, f.lb, f.ub); }

int main() {
    std::mt19937_64 rng(314);
    auto small = [&] { return (long long)(rng() % 41) - 20; };
    auto gen_f = [&]() -> Clamp {
        long long b = small();
        switch (rng() % 3) {
            case 0:
                return Clamp{-inf, b, 0};  // chmin
            case 1:
                return Clamp{b, inf, 0};  // chmax
            default:
                return Clamp{-inf, inf, b};  // add
        }
    };
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 24 + 1;
        std::vector<long long> a(n);
        for (auto& x : a) x = small();
        std::vector<Node> init(a.begin(), a.end());
        SegTreeBeats<ChminChmaxAddSum> seg(init);
        check(seg.size() == n, "size");
        for (int q = 0; q < 80 && ok; q++) {
            int t = rng() % 8;
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            int k = rng() % n;
            if (t == 0) {
                Clamp f = gen_f();
                seg.apply(l, r, f);
                for (int i = l; i < r; i++) a[i] = clamp_apply(f, a[i]);
            } else if (t == 1) {
                Clamp f = gen_f();
                seg.apply(k, f);
                a[k] = clamp_apply(f, a[k]);
            } else if (t == 2) {
                long long x = small();
                if (rng() % 2)
                    seg.set(k, Node(x));
                else
                    seg[k] = Node(x);
                a[k] = x;
            } else if (t == 3) {
                check(seg.get(k).sum == a[k], "get");
                Node x = seg[k];
                check(x.sum == a[k] && x.max1 == a[k] && x.min1 == a[k], "seg[k]");
            } else if (t == 4) {
                Node p = seg.prod(l, r);
                long long sum = 0, mx = -inf, mn = inf;
                for (int i = l; i < r; i++) sum += a[i], mx = std::max(mx, a[i]), mn = std::min(mn, a[i]);
                check(p.sum == sum && p.max1 == mx && p.min1 == mn, "prod");
            } else if (t == 5) {
                // 最大値が x 以下である最長の区間 [l, r)
                long long x = small();
                int expect = l;
                while (expect < n && a[expect] <= x) expect++;
                check(seg.max_right(l, [&](const Node& s) { return s.max1 <= x; }) == expect, "max_right");
            } else if (t == 6) {
                // 最小値が x 以上である最長の区間 [l, r)
                long long x = small();
                int expect = r;
                while (expect > 0 && a[expect - 1] >= x) expect--;
                check(seg.min_left(r, [&](const Node& s) { return s.min1 >= x; }) == expect, "min_left");
            } else {
                long long sum = 0;
                for (long long x : a) sum += x;
                check(seg.all_prod().sum == sum, "all_prod");
            }
        }
        std::ostringstream os, expect;
        os << seg;
        for (int i = 0; i < n; i++) {
            if (i != 0) expect << ' ';
            expect << a[i];
        }
        check(os.str() == expect.str(), "os << seg");
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
