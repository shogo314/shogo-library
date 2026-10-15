#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// maximum_subarray を、すべての区間を調べる愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/dp/maximum-subarray.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <vector>

bool ok = true;

void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

// constexpr で使えること
static_assert(maximum_subarray(std::array<int, 5>{-1, 3, -2, 4, -5}) == 5);
static_assert(maximum_subarray(std::array<int, 3>{-5, -2, -9}, 0) == 0);

int main() {
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 1000; rep++) {
        int n = rng() % 10 + 1;
        std::vector<long long> v(n);
        for (auto& x : v) x = (long long)(rng() % 21) - 10;

        // 空でない版
        long long best_nonempty = v[0];
        for (int l = 0; l < n; l++) {
            long long s = 0;
            for (int r = l; r < n; r++) {
                s += v[r];
                best_nonempty = std::max(best_nonempty, s);
            }
        }
        check(maximum_subarray(v) == best_nonempty, "maximum_subarray(c)");

        // 空の部分列を許す版: 全区間の和の最大値と init の大きい方
        long long init = (long long)(rng() % 7) - 3;
        long long best = init;
        for (int l = 0; l < n; l++) {
            long long s = init;
            for (int r = l; r < n; r++) {
                s += v[r];
                best = std::max(best, s);
            }
        }
        check(maximum_subarray(v, init) == best, "maximum_subarray(c, init)");
    }

    // 境界: 空、すべて負
    check(maximum_subarray(std::vector<int>{}, 0) == 0, "maximum_subarray 空");
    check(maximum_subarray(std::vector<int>{-5, -2, -9}) == -2, "maximum_subarray すべて負");
    check(maximum_subarray(std::vector<int>{-5, -2, -9}, 0) == 0, "maximum_subarray すべて負、空を許す");
    check(maximum_subarray(std::vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6, "maximum_subarray ドキュメントの例");

    if (ok) std::cout << "Hello World" << std::endl;
}
