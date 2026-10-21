#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// kd-tree.hpp の KDTree の enumerate と count を、すべての点を調べたものとランダムに比べる
// 同じ座標の点、空の集合、空の長方形も調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/kd-tree.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 40, w = rng() % 2 ? 4 : 100;
        std::vector<std::pair<long long, long long>> p(n);
        for (auto& [x, y] : p) x = static_cast<long long>(rng() % (2 * w + 1)) - w, y = static_cast<long long>(rng() % (2 * w + 1)) - w;
        KDTree<long long> kd(p);
        if (kd.size() != n) ok = false;
        for (int q = 0; q < 30 && ok; q++) {
            long long xl = static_cast<long long>(rng() % (2 * w + 3)) - w - 1, xr = static_cast<long long>(rng() % (2 * w + 3)) - w - 1;
            long long yl = static_cast<long long>(rng() % (2 * w + 3)) - w - 1, yr = static_cast<long long>(rng() % (2 * w + 3)) - w - 1;
            if (rng() % 4 && xl > xr) std::swap(xl, xr);
            if (rng() % 4 && yl > yr) std::swap(yl, yr);
            std::vector<long long> expected;
            for (int i = 0; i < n; i++) {
                if (xl <= p[i].first && p[i].first < xr && yl <= p[i].second && p[i].second < yr) expected.push_back(i);
            }
            auto ids = kd.enumerate(xl, xr, yl, yr);
            std::sort(ids.begin(), ids.end());
            if (ids != expected || kd.count(xl, xr, yl, yr) != static_cast<long long>(expected.size())) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
