#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// axis-parallel-segments.hpp の count_axis_parallel_intersections を、すべての組を segments_intersect で調べたものと比べる
// 端点で接する組や、端点が同じ座標に重なる組も調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/geometry/axis-parallel-segments.hpp"

#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "../../../src/geometry/segment.hpp"

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    using P = Vector<long long>;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 12 + 1, w = rng() % 2 ? 4 : 30;
        auto rnd = [&] { return static_cast<long long>(rng() % (2 * w + 1)) - w; };
        std::vector<std::pair<P, P>> segs(n);
        std::vector<bool> vertical(n);
        for (int i = 0; i < n; i++) {
            long long a = rnd(), b = rnd(), c = rnd();
            if (b == c) c++;
            vertical[i] = rng() % 2;
            segs[i] = vertical[i] ? std::make_pair(P(a, b), P(a, c)) : std::make_pair(P(b, a), P(c, a));
        }
        long long expected = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vertical[i] && vertical[j] && segments_intersect(segs[i].first, segs[i].second, segs[j].first, segs[j].second)) expected++;
            }
        }
        if (count_axis_parallel_intersections(segs) != expected) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
