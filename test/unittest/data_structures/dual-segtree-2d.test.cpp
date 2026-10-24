#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// DualSegTree2D の apply・get を、負の座標・重複した点・加算と chmin と初期値で愚直な実装と比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/dual-segtree-2d.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <utility>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 500 && ok; rep++) {
        int c = rng() % 12 + 1;
        std::vector<std::pair<long long, long long>> points;
        for (int i = 0; i < c; i++) points.emplace_back(static_cast<long long>(rng() % 9) - 4, static_cast<long long>(rng() % 9) - 4);
        RAddQ2D<long long> add(points, 3);
        RChminQ2D<long long> mn(points, 100);
        std::map<std::pair<long long, long long>, long long> va, vm;
        for (auto p : points) va[p] = 3, vm[p] = 100;
        for (int t = 0; t < 50; t++) {
            if (rng() % 2) {
                long long lx = static_cast<long long>(rng() % 13) - 6, rx = static_cast<long long>(rng() % 13) - 6;
                long long ly = static_cast<long long>(rng() % 13) - 6, ry = static_cast<long long>(rng() % 13) - 6;
                if (lx > rx) std::swap(lx, rx);
                if (ly > ry) std::swap(ly, ry);
                long long v = static_cast<long long>(rng() % 41) - 20;
                add.apply(lx, rx, ly, ry, v);
                mn.apply(lx, rx, ly, ry, v);
                for (auto& [p, x] : va)
                    if (lx <= p.first && p.first < rx && ly <= p.second && p.second < ry) x += v;
                for (auto& [p, x] : vm)
                    if (lx <= p.first && p.first < rx && ly <= p.second && p.second < ry) x = std::min(x, v);
            } else {
                auto p = points[rng() % c];
                if (add.get(p.first, p.second) != va[p] || mn.get(p.first, p.second) != vm[p]) ok = false;
            }
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
