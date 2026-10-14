#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/vector.hpp の直線・線分の関数 (ccw、平行・直交、射影、反射、交点、距離) を、定義から確かめる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>

#include "../../src/geometry/vector.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    using P = Vector<double>;
    using L = Vector<long long>;
    auto near = [](double a, double b) { return std::abs(a - b) < 1e-7; };
    for (int rep = 0; rep < 20000 && ok; rep++) {
        auto rnd = [&] { return (long long)(rng() % 11) - 5; };
        L a(rnd(), rnd()), b(rnd(), rnd()), c(rnd(), rnd()), d(rnd(), rnd());
        auto to_p = [](const L& l) { return P((double)l[0], (double)l[1]); };
        P pa = to_p(a), pb = to_p(b), pc = to_p(c), pd = to_p(d);

        // ccw: 一直線上の場合は、c が直線上のどこにあるかで分ける
        if (a != b) {
            int r = ccw(a, b, c);
            long long cr = cross(b - a, c - a);
            if (cr > 0) ok = ok && r == 1;
            if (cr < 0) ok = ok && r == -1;
            if (cr == 0) {
                // a を 0、b を 1 としたときの c の位置 t
                long long t = dot(c - a, b - a), len = (b - a).squared_norm();
                ok = ok && r == (t < 0 ? 2 : t > len ? -2
                                                     : 0);
            }
            ok = ok && ccw(pa, pb, pc) == r;
        }
        if (a == b || c == d) continue;

        ok = ok && is_parallel(a, b, c, d) == (cross(b - a, d - c) == 0);
        ok = ok && is_orthogonal(a, b, c, d) == (dot(b - a, d - c) == 0);

        // 射影は直線上にあり、p との差が直線に垂直。反射は射影を中点とする
        P h = projection(pa, pb, pc);
        ok = ok && near(cross(pb - pa, h - pa), 0) && near(dot(pb - pa, h - pc), 0);
        P r = reflection(pa, pb, pc);
        ok = ok && near(r[0] + pc[0], 2 * h[0]) && near(r[1] + pc[1], 2 * h[1]);

        // 交点は両方の直線上にある
        auto x = line_intersection(pa, pb, pc, pd);
        if (is_parallel(a, b, c, d)) {
            ok = ok && !x;
        } else {
            ok = ok && x && near(cross(pb - pa, *x - pa), 0) && near(cross(pd - pc, *x - pc), 0);
        }

        // 点と直線の距離は、射影までの距離
        ok = ok && near(distance_point_line(a, b, c), (h - pc).abs());
        // 点と線分の距離を、線分上の点を細かく調べた最小値と比べる
        auto brute_point_segment = [&](P p1, P p2, P p) {
            double best = 1e18;
            for (int i = 0; i <= 2000; i++) best = std::min(best, (p1 + (p2 - p1) * (i / 2000.0) - p).abs());
            return best;
        };
        double dps = distance_point_segment(a, b, c);
        ok = ok && dps <= brute_point_segment(pa, pb, pc) + 1e-9 && dps >= brute_point_segment(pa, pb, pc) - 1e-2;
        // 線分どうしの距離: 交わるなら 0、そうでなければ端点と線分の距離の最小値以下
        double dss = distance_segments(a, b, c, d);
        if (segments_intersect(a, b, c, d)) {
            ok = ok && dss == 0;
        } else {
            ok = ok && dss > 0 && near(dss, std::min({distance_point_segment(a, b, c), distance_point_segment(a, b, d), distance_point_segment(c, d, a), distance_point_segment(c, d, b)}));
        }
        ok = ok && near(distance_segments(pa, pb, pc, pd), dss);
    }

    // 例
    ok = ok && ccw(L(0, 0), L(2, 0), L(1, 1)) == 1 && ccw(L(0, 0), L(2, 0), L(3, 0)) == -2;
    P h = projection(P(0.0, 0.0), P(3.0, 4.0), P(2.0, 5.0));
    ok = ok && near(h[0], 3.12) && near(h[1], 4.16);
    ok = ok && near(distance_point_line(L(0, 0), L(2, 0), L(5, 3)), 3) && near(distance_point_segment(L(0, 0), L(2, 0), L(5, 4)), 5);

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
