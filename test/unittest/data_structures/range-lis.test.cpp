#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// range-lis.hpp の RangeLIS を、区間ごとに二分探索で求めた最長増加部分列 (狭義) の長さと比べる
// 置換と、同じ値を多く含む列の両方で、すべての区間を調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/range-lis.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    auto lis = [](const std::vector<int>& a, int l, int r) {
        std::vector<int> t;
        for (int i = l; i < r; i++) {
            auto it = std::lower_bound(t.begin(), t.end(), a[i]);
            if (it == t.end()) {
                t.push_back(a[i]);
            } else {
                *it = a[i];
            }
        }
        return static_cast<long long>(t.size());
    };
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 40;
        std::vector<int> a(n);
        if (rep % 2 == 0) {
            std::iota(a.begin(), a.end(), 0);
            std::shuffle(a.begin(), a.end(), rng);
        } else {
            int kinds = rng() % 6 + 1;
            for (auto& x : a) x = static_cast<int>(rng() % kinds);
        }
        RangeLIS rl(a);
        if (rl.size() != n) ok = false;
        for (int l = 0; l <= n; l++)
            for (int r = l; r <= n; r++)
                if (rl.lis(l, r) != lis(a, l, r)) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
