#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/point-pair.hpp の farthest_point_pair を確かめる
// 重複点や一直線上の点を含む整数座標で、すべての点の組を調べたものと比べる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include "../../../src/geometry/point-pair.hpp"

#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/geometry/vector.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 20000 && ok; rep++) {
        int n = rng() % 10 + 2, w = rng() % 2 ? 3 : 1000;
        std::vector<Vector<long long>> p(n);
        bool line = rng() % 4 == 0;  // すべて一直線上
        for (auto& x : p) {
            long long a = static_cast<long long>(rng() % (2 * w + 1)) - w;
            x = line ? Vector<long long>(a, 2 * a + 1) : Vector<long long>(a, static_cast<long long>(rng() % (2 * w + 1)) - w);
        }
        long long best = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) best = std::max(best, (p[i] - p[j]).squared_norm());
        }
        auto res = farthest_point_pair_squared(p);
        if (res.squared_dist != best || res.i == res.j || res.i < 0 || res.i >= n || res.j < 0 || res.j >= n) ok = false;
        if (ok && (p[res.i] - p[res.j]).squared_norm() != best) ok = false;
        if (ok && std::abs(farthest_point_pair(p).dist - std::sqrt(static_cast<double>(best))) > 1e-9) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
