#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// SegTree2D の set・apply・get・prod を、負の座標・重複した点・Max のモノイドで愚直な実装と比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/segtree-2d.hpp"

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
        int c = rng() % 12;
        std::vector<std::pair<long long, long long>> points;
        for (int i = 0; i < c; i++) points.emplace_back(static_cast<long long>(rng() % 9) - 4, static_cast<long long>(rng() % 9) - 4);
        RSumQ2D<long long> sum(points);
        RMaxQ2D<long long> mx(points);
        std::map<std::pair<long long, long long>, long long> vs, vm;
        for (int t = 0; t < 50; t++) {
            int op = rng() % 4;
            if (op <= 1 && c > 0) {
                auto [x, y] = points[rng() % c];
                long long v = static_cast<long long>(rng() % 21) - 10;
                if (op == 0) {
                    sum.set(x, y, v);
                    mx.set(x, y, v);
                    vs[{x, y}] = v;
                    vm[{x, y}] = v;
                } else {
                    sum.apply(x, y, v);
                    mx.apply(x, y, v);
                    vs[{x, y}] += v;
                    vm[{x, y}] = vm.count({x, y}) ? std::max(vm[{x, y}], v) : v;
                }
            } else if (op == 2) {
                long long x = static_cast<long long>(rng() % 11) - 5, y = static_cast<long long>(rng() % 11) - 5;
                long long es = vs.count({x, y}) ? vs[{x, y}] : 0;
                long long em = vm.count({x, y}) ? vm[{x, y}] : monoid::Max<long long>().e();
                if (sum.get(x, y) != es || mx.get(x, y) != em) ok = false;
            } else {
                long long lx = static_cast<long long>(rng() % 13) - 6, rx = static_cast<long long>(rng() % 13) - 6;
                long long ly = static_cast<long long>(rng() % 13) - 6, ry = static_cast<long long>(rng() % 13) - 6;
                if (lx > rx) std::swap(lx, rx);
                if (ly > ry) std::swap(ly, ry);
                long long es = 0, em = monoid::Max<long long>().e();
                for (auto [p, v] : vs)
                    if (lx <= p.first && p.first < rx && ly <= p.second && p.second < ry) es += v;
                for (auto [p, v] : vm)
                    if (lx <= p.first && p.first < rx && ly <= p.second && p.second < ry) em = std::max(em, v);
                if (sum.prod(lx, rx, ly, ry) != es || mx.prod(lx, rx, ly, ry) != em) ok = false;
            }
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
