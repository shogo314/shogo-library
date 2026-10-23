#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// subarray-sum.hpp の count_subarrays_with_sum・count_subarrays_with_sum_at_most を、すべての区間の和を調べる愚直な方法と比べる
// 要素がすべて 0 以上の列 (尺取り法) と負を含む列 (マージソート) の両方で、k も負から正まで調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/others/subarray-sum.hpp"

#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 15;
        bool nonneg = rep % 2 == 0;
        std::vector<long long> a(n);
        for (auto& x : a) x = nonneg ? static_cast<long long>(rng() % 4) : static_cast<long long>(rng() % 9) - 4;
        for (long long k = -10; k <= 15; k++) {
            long long eq = 0, le = 0;
            for (int l = 0; l < n; l++) {
                long long s = 0;
                for (int r = l + 1; r <= n; r++) {
                    s += a[r - 1];
                    eq += s == k, le += s <= k;
                }
            }
            if (count_subarrays_with_sum(a, k) != eq || count_subarrays_with_sum_at_most(a, k) != le) ok = false;
        }
    }
    // 例: AtCoder AWC 0185 C の入力例 1
    if (count_subarrays_with_sum(std::vector<long long>{1, 2, 3, 2, 1, 4}, 5LL) != 3) ok = false;
    // double でも k 以下の個数は数えられる
    if (count_subarrays_with_sum_at_most(std::vector<double>{0.5, -1.5, 2.0}, 0.5) != 4) ok = false;
    if (ok) std::cout << "Hello World" << std::endl;
}
