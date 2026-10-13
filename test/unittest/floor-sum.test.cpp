#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// floor_sum を愚直な計算とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>

#include "../../src/math/floor-sum.hpp"

long long floor_div(long long a, long long b) { return a / b - ((a % b != 0) && ((a < 0) != (b < 0))); }

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 100000 && ok; rep++) {
        long long n = rng() % 30;
        long long m = rng() % 30 + 1;
        long long a = (long long)(rng() % 201) - 100;
        long long b = (long long)(rng() % 201) - 100;
        long long expected = 0;
        for (long long i = 0; i < n; i++) expected += floor_div(a * i + b, m);
        ok = ok && floor_sum(n, m, a, b) == expected;
    }
    // 大きい値
    ok = ok && floor_sum(1000000000, 1000000000, 999999999, 999999999) == 499999999500000000LL;
    ok = ok && floor_sum(0, 5, 3, 2) == 0;
    ok = ok && floor_sum(4, 10, 6, 3) == 3;

    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
