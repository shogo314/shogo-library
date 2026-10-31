#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/manhattan.hpp の関数を、すべての点の組を調べる愚直な方法と比べる
// 同じ距離の点が複数あることがあるので、添字ではなく距離で比べる (添字が自分自身でないことと、距離が合うことを確かめる)
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include "../../../src/geometry/manhattan.hpp"

#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/geometry/vector.hpp"

using P = Vector<long long>;

long long dist(const P& a, const P& b) { return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]); }

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 20000 && ok; rep++) {
        const int n = rng() % 12 + 1;
        const int ws[3] = {2, 100, 1000000000};  // 小さいと同じ点や同じ距離が多い
        const int w = ws[rng() % 3];
        std::vector<P> p(n);
        for (auto& x : p) x = P(static_cast<long long>(rng() % (2 * w + 1)) - w, static_cast<long long>(rng() % (2 * w + 1)) - w);

        auto near = manhattan_nearest_points(p);
        auto far = manhattan_farthest_points(p);
        for (int i = 0; i < n && ok; i++) {
            if (n == 1) {
                if (near[i] != -1 || far[i] != -1) ok = false;
                continue;
            }
            long long lo = -1, hi = -1;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                long long d = dist(p[i], p[j]);
                if (lo == -1 || d < lo) lo = d;
                if (hi == -1 || d > hi) hi = d;
            }
            if (near[i] < 0 || near[i] >= n || near[i] == i || dist(p[i], p[near[i]]) != lo) ok = false;
            if (far[i] < 0 || far[i] >= n || far[i] == i || dist(p[i], p[far[i]]) != hi) ok = false;
        }
        if (n < 2 || !ok) continue;
        long long lo = -1, hi = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long d = dist(p[i], p[j]);
                if (lo == -1 || d < lo) lo = d;
                if (hi == -1 || d > hi) hi = d;
            }
        }
        auto c = manhattan_closest_pair(p);
        auto f = manhattan_farthest_pair(p);
        if (c.dist != lo || !(0 <= c.i && c.i < c.j && c.j < n) || dist(p[c.i], p[c.j]) != lo) ok = false;
        if (f.dist != hi || !(0 <= f.i && f.i < f.j && f.j < n) || dist(p[f.i], p[f.j]) != hi) ok = false;
    }
    // すべて同じ点
    {
        std::vector<P> p(3, P(5, -5));
        auto f = manhattan_farthest_points(p);
        auto c = manhattan_closest_pair(p), g = manhattan_farthest_pair(p);
        for (int i = 0; i < 3; i++) {
            if (f[i] == i) ok = false;
        }
        if (c.dist != 0 || c.i == c.j || g.dist != 0 || g.i == g.j) ok = false;
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
