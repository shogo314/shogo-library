#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// WaveletMatrix と WeightedWaveletMatrix を、区間を並べ替える愚直な実装とランダムに比較する
// 負の値や重複する値、値と別の重み、double の値も試す
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/wavelet-matrix.hpp"

#include <algorithm>
#include <iostream>
#include <optional>
#include <random>
#include <type_traits>
#include <vector>

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

int main() {
    std::mt19937_64 rng(314);

    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 20;
        long long range = rep % 3 == 0 ? 3 : rep % 3 == 1 ? 20
                                                          : 2000000000000000000LL;
        std::vector<long long> v(n), w(n);
        for (auto& x : v) x = static_cast<long long>(rng() % (2 * range + 1)) - range;
        for (auto& x : w) x = static_cast<long long>(rng() % 100) - 50;
        WaveletMatrix wm(v);
        WeightedWaveletMatrix wv(v);     // 値そのものを重みにする
        WeightedWaveletMatrix ww(v, w);  // 値と別の重み
        check(wm.size() == n && ww.size() == n, "size");
        for (int i = 0; i < n; i++) check(wm.get(i) == v[i] && wm[i] == v[i] && ww[i] == v[i], "get");

        auto random_value = [&]() {
            if (n > 0 && rng() % 2) return v[rng() % n] + static_cast<long long>(rng() % 3) - 1;
            return static_cast<long long>(rng() % (2 * range + 3)) - range - 1;
        };
        for (int t = 0; t < 30; t++) {
            long long l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            // 区間の要素を (値, 位置) の順に並べる
            std::vector<std::pair<long long, long long>> s;
            for (long long i = l; i < r; i++) s.push_back({v[i], i});
            std::sort(s.begin(), s.end());
            long long len = r - l;
            if (len > 0) {
                long long k = rng() % len;
                check(wm.kth_smallest(l, r, k) == s[k].first, "kth_smallest");
                check(wm.kth_largest(l, r, k) == s[len - 1 - k].first, "kth_largest");
            }
            long long x = random_value();
            long long a = random_value(), b = random_value();
            long long cnt_x = 0, cnt_ab = 0, sum_ab = 0, wsum_ab = 0;
            std::optional<long long> prev, next;
            for (long long i = l; i < r; i++) {
                if (v[i] == x) cnt_x++;
                if (a <= v[i] && v[i] < b) cnt_ab++, sum_ab += v[i], wsum_ab += w[i];
                if (v[i] < x && (!prev || *prev < v[i])) prev = v[i];
                if (v[i] >= x && (!next || v[i] < *next)) next = v[i];
            }
            check(wm.count(l, r, x) == cnt_x, "count(x)");
            check(wm.count(l, r, a, b) == cnt_ab, "count(lower, upper)");
            check(wm.prev_value(l, r, x) == prev, "prev_value");
            check(wm.next_value(l, r, x) == next, "next_value");
            check(wv.sum(l, r, a, b) == sum_ab, "sum (値が重み)");
            check(ww.sum(l, r, a, b) == wsum_ab, "sum (別の重み)");
            long long all = 0;
            for (long long i = l; i < r; i++) all += w[i];
            check(ww.sum(l, r) == all, "sum(l, r)");
            // 小さい方・大きい方から k 個の重みの和 (同じ値は前にあるものから数える)
            long long k = rng() % (len + 1), small = 0, large = 0;
            for (long long i = 0; i < k; i++) small += w[s[i].second];
            check(ww.sum_smallest(l, r, k) == small, "sum_smallest");
            for (long long i = 0; i < len - k; i++) large += w[s[i].second];
            check(ww.sum_largest(l, r, k) == all - large, "sum_largest");
        }
    }

    // double の値: 重みの型の既定は double
    {
        std::vector<double> v = {0.5, -1.25, 3.0, 0.5};
        WeightedWaveletMatrix wm(v);
        static_assert(std::is_same_v<decltype(wm.sum(0, 1)), double>);
        check(wm.kth_smallest(0, 4, 1) == 0.5 && wm.sum(0, 4, 0.0, 3.0) == 1.0 && wm.sum_smallest(0, 4, 2) == -0.75, "double");
        check(wm.count(0, 4, 0.5) == 2 && wm.prev_value(0, 4, 0.5) == -1.25 && !wm.next_value(0, 4, 3.5), "double の count / prev / next");
    }
    // int の値: 重みの型の既定は long long (和があふれない)
    {
        std::vector<int> v(3, 2000000000);
        WeightedWaveletMatrix wm(v);
        static_assert(std::is_same_v<decltype(wm.sum(0, 1)), long long>);
        check(wm.sum(0, 3) == 6000000000LL && wm.sum_largest(0, 3, 2) == 4000000000LL, "int の値の和");
    }
    // 空の列
    {
        WaveletMatrix<long long> wm;
        check(wm.size() == 0 && wm.count(0, 0, 1) == 0 && wm.count(0, 0, 0, 5) == 0 && !wm.prev_value(0, 0, 1) && !wm.next_value(0, 0, 1), "空");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
