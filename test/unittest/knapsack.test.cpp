#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// ナップサックの各関数を、選び方をすべて試す愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/dp/knapsack.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// 品物 i を 0 個以上 m[i] 個以下選ぶすべての方法を試す
long long naive(const std::vector<long long>& v, const std::vector<long long>& w, const std::vector<long long>& m,
                long long W, int i = 0) {
    if (i == static_cast<int>(v.size())) return 0;
    long long res = 0;
    for (long long c = 0; c <= m[i] && c * w[i] <= W; c++) {
        res = std::max(res, c * v[i] + naive(v, w, m, W - c * w[i], i + 1));
    }
    return res;
}

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 8;
        long long W = rng() % 30;
        int vmax = rng() % 2 ? 10 : 1000, wmax = rng() % 10 + 1;
        std::vector<long long> v(n), w(n), m(n), one(n, 1), many(n);
        for (int i = 0; i < n; i++) {
            v[i] = rng() % (vmax + 1);
            w[i] = rng() % (wmax + 1);  // 重さ 0 も含む
            m[i] = rng() % 5;
        }
        long long a = naive(v, w, one, W);
        ok = ok && knapsack_by_weight(v, w, W) == a && knapsack_by_value(v, w, W) == a;
        ok = ok && knapsack_meet_in_the_middle(v, w, W) == a && knapsack(v, w, W) == a;

        long long b = naive(v, w, m, W);
        ok = ok && bounded_knapsack_by_weight(v, w, m, W) == b && bounded_knapsack_by_value(v, w, m, W) == b;
        ok = ok && bounded_knapsack(v, w, m, W) == b;

        // 個数制限なし (重さ 0 で価値が正の品物は除く)
        for (int i = 0; i < n; i++) {
            if (w[i] == 0) v[i] = 0;
            many[i] = w[i] == 0 ? 0 : W / w[i];
        }
        ok = ok && unbounded_knapsack(v, w, W) == naive(v, w, many, W);
    }

    // 重さが大きいときは、価値についての DP か半分全列挙が選ばれる (重さについての DP では時間がかかりすぎる)
    std::vector<long long> v(40), w(40), m(40, 1000000000000LL);
    for (int i = 0; i < 40; i++) {
        v[i] = rng() % 1000000000000000LL;
        w[i] = rng() % 1000000000000000LL;
    }
    long long W = 1000000000000000LL;
    ok = ok && knapsack(v, w, W) == knapsack_meet_in_the_middle(v, w, W);
    std::vector<long long> sv(100), sw(100);
    for (int i = 0; i < 100; i++) {
        sv[i] = rng() % 100;
        sw[i] = rng() % 10000000;
    }
    ok = ok && knapsack(sv, sw, 1000000000) == knapsack_by_value(sv, sw, 1000000000);
    // 個数制限付きで、個数も重さも大きい
    std::vector<long long> bv(3), bw(3), bm(3);
    bv = {3, 5, 7}, bw = {1000000000000LL, 2000000000000LL, 3000000000000LL}, bm = {1000000, 1000000, 1000000};
    // 重さの単位を 10^12 とすると容量 10 で、1 つ目を 10 個選ぶのが最適
    ok = ok && bounded_knapsack(bv, bw, bm, 10000000000000LL) == 30;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
