#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// beats-acted-monoid.hpp の作用素付きモノイドを SegTreeBeats に乗せて、愚直な実装とランダムに比較する
// 別名 RChminChmaxAddSumQ も確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/algebra/beats-acted-monoid.hpp"

#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <type_traits>
#include <vector>

#include "../../src/data_structures/segtree-beats.hpp"

static_assert(std::is_same_v<RChminChmaxAddSumQ<long long>, SegTreeBeats<beats_acted_monoid::ChminChmaxAddSum<long long>>>);

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

void test_chmin_chmax_add_sum(std::mt19937_64& rng) {
    using A = beats_acted_monoid::ChminChmaxAddSum<long long>;
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 30 + 1;
        // 値の幅を狭くして、値が 1 種類・2 種類のノードもよく現れるようにする
        long long w = rep % 2 ? 5 : 1000;
        auto gen = [&] { return (long long)(rng() % (2 * w + 1)) - w; };
        std::vector<long long> a(n);
        for (auto& x : a) x = gen();
        RChminChmaxAddSumQ<long long> seg(std::vector<A::S>(a.begin(), a.end()));
        for (int q = 0; q < 100 && ok; q++) {
            int t = rng() % 6;
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            long long b = gen();
            if (t == 0) {
                seg.apply(l, r, A::chmin(b));
                for (int i = l; i < r; i++) a[i] = std::min(a[i], b);
            } else if (t == 1) {
                seg.apply(l, r, A::chmax(b));
                for (int i = l; i < r; i++) a[i] = std::max(a[i], b);
            } else if (t == 2) {
                seg.apply(l, r, A::add(b));
                for (int i = l; i < r; i++) a[i] += b;
            } else if (t == 3) {
                seg.apply(l, r, A::update(b));
                for (int i = l; i < r; i++) a[i] = b;
            } else {
                A::S s = seg.prod(l, r);
                long long sum = 0, mx = std::numeric_limits<long long>::lowest(), mn = std::numeric_limits<long long>::max();
                for (int i = l; i < r; i++) sum += a[i], mx = std::max(mx, a[i]), mn = std::min(mn, a[i]);
                check(s.sum == sum, "ChminChmaxAddSum sum");
                check(s.max1 == mx, "ChminChmaxAddSum max");
                check(s.min1 == mn, "ChminChmaxAddSum min");
            }
        }
        for (int i = 0; i < n && ok; i++) check(seg.get(i).sum == a[i], "ChminChmaxAddSum get");
    }
}

int main() {
    std::mt19937_64 rng(314);
    test_chmin_chmax_add_sum(rng);
    if (ok) std::cout << "Hello World" << std::endl;
    return ok ? 0 : 1;
}
