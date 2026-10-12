#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// functions.hpp の関数を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>

#include "../../src/base/functions.hpp"

bool ok = true;

void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

int main() {
    std::mt19937_64 rng(314);

    for (int rep = 0; rep < 20000 && ok; rep++) {
        long long a = (long long)(rng() % 21) - 10, b = (long long)(rng() % 21) - 10;

        // chmin / chmax: 更新したかを返す
        {
            long long x = a;
            bool changed = chmin(x, b);
            check(x == std::min(a, b) && changed == (b < a), "chmin");
            x = a;
            changed = chmax(x, b);
            check(x == std::max(a, b) && changed == (b > a), "chmax");
            double d = a;
            check(chmin(d, b + 0.5) == (b + 0.5 < a) && d == std::min<double>(a, b + 0.5), "chmin (型が異なる)");
        }

        // long long 同士の max / min
        check(max(a, b) == std::max(a, b) && min(a, b) == std::min(a, b), "max/min(long long, long long)");
        check(max(a, 3) == std::max(a, 3LL) && min(2, b) == std::min(2LL, b), "max/min (int と long long の混在)");

        // inrange / inrect
        {
            long long x = (long long)(rng() % 15) - 5;
            check(inrange(x, a) == (0 <= x && x < a), "inrange(x, a)");
            check(inrange(x, a, b) == (a <= x && x < b), "inrange(x, a, b)");
            long long y = (long long)(rng() % 15) - 5;
            check(inrect(x, y, a, b) == (0 <= x && x < a && 0 <= y && y < b), "inrect");
        }

        // 整数の二分探索: f(ok) が真、f(ng) が偽で単調なとき、境界の ok 側を返す
        {
            long long t = (long long)(rng() % 2001) - 1000;
            long long lo = t - (long long)(rng() % 1000) - 1, hi = t + (long long)(rng() % 1000) + 1;
            // f(x) = x <= t (ok = lo, ng = hi) -> t
            check(binary_search(lo, hi, [&](long long x) { return x <= t; }) == t, "binary_search 整数 (ok < ng)");
            // f(x) = x >= t (ok = hi, ng = lo) -> t
            check(binary_search(hi, lo, [&](long long x) { return x >= t; }) == t, "binary_search 整数 (ok > ng)");
            // 隣り合う ok, ng なら ok をそのまま返す
            check(binary_search(t, t + 1, [&](long long) { return true; }) == t, "binary_search 整数 隣接");
        }

        // 実数の二分探索 (100 回)
        {
            double t = (double)(rng() % 2000001) / 1000.0;  // [0, 2000]
            double r = binary_search(0.0, 3000.0, [&](double x) { return x * x <= t; });
            check(std::abs(r - std::sqrt(t)) < 1e-9, "binary_search 実数 sqrt");
            double r2 = binary_search(3000.0, 0.0, [&](double x) { return x * x >= t; });
            check(std::abs(r2 - std::sqrt(t)) < 1e-9, "binary_search 実数 (ok > ng)");
        }
    }

    // 決まった値
    check(binary_search(0, 1000000000, [](int x) { return (long long)x * x <= 1000000000; }) == 31622, "binary_search sqrt(1e9)");
    check(!inrange(0, 0) && inrange(0, 1) && !inrange(-1, 1), "inrange 境界");
    check(inrange(5, 5, 6) && !inrange(6, 5, 6), "inrange(x, a, b) 境界");

    if (ok) std::cout << "Hello World" << std::endl;
}
