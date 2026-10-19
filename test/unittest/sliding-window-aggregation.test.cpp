#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// SlidingWindowAggregation と sliding_window_min / max を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/sliding-window-aggregation.hpp"

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

#include "../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    // 可換でないモノイド (1次関数の合成)
    for (int rep = 0; rep < 500 && ok; rep++) {
        SlidingWindowAggregation<monoid::Composite<mint>> swag;
        std::deque<Affine<mint>> dq;
        for (int t = 0; t < 100; t++) {
            int op = rng() % 4;
            if (op <= 1) {
                Affine<mint> f{mint(rng() % 5), mint(rng() % 5)};
                swag.push(f);
                dq.push_back(f);
            } else if (op == 2 && !dq.empty()) {
                swag.pop();
                dq.pop_front();
            } else if (op == 3 && rng() % 20 == 0) {
                swag.clear();
                dq.clear();
            }
            Affine<mint> expected = monoid::Composite<mint>::e();
            for (const auto& f : dq) expected = monoid::Composite<mint>::op(expected, f);
            if (swag.size() != static_cast<int>(dq.size()) || swag.empty() != dq.empty() || swag.prod() != expected) ok = false;
            if (!dq.empty() && swag.front() != dq.front()) ok = false;
        }
    }
    // スライド最小値・最大値
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 20 + 1, k = rng() % n + 1;
        std::vector<int> a(n);
        for (auto& x : a) x = rng() % 10;
        std::vector<int> mn, mx;
        for (int i = 0; i + k <= n; i++) {
            mn.push_back(*std::min_element(a.begin() + i, a.begin() + i + k));
            mx.push_back(*std::max_element(a.begin() + i, a.begin() + i + k));
        }
        ok = ok && sliding_window_min(a, k) == mn && sliding_window_max(a, k) == mx;
        ok = ok && sliding_window_min(a, k, std::greater<int>()) == mx;
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
