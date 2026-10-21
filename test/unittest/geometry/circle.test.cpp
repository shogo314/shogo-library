#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/circle.hpp の関数を、定義から確かめる
// 共通部分の面積は、x 方向に細かく分けた数値積分と比べる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include "../../../src/geometry/circle.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    using P = Vector<double>;
    auto near = [](double a, double b) { return std::abs(a - b) < 1e-6; };
    auto on_circle = [&](const Circle<double>& c, const P& p) { return near((p - c.c).abs(), c.r); };
    for (int rep = 0; rep < 20000 && ok; rep++) {
        auto rnd = [&] { return static_cast<long long>(rng() % 11) - 5; };
        auto rndd = [&] { return static_cast<double>(rnd()); };
        Circle<long long> ci1(Vector<long long>(rnd(), rnd()), rng() % 5 + 1), ci2(Vector<long long>(rnd(), rnd()), rng() % 5 + 1);
        Circle<double> c1(P(static_cast<double>(ci1.c[0]), static_cast<double>(ci1.c[1])), ci1.r), c2(P(static_cast<double>(ci2.c[0]), static_cast<double>(ci2.c[1])), ci2.r);

        // 位置関係と交点の個数が対応する
        int rel = circle_relation(ci1, ci2);
        ok = ok && circle_relation(c1, c2) == rel;
        auto ps = circle_circle_intersection(c1, c2);
        if (ci1.c == ci2.c) {
            ok = ok && ps.empty();
        } else {
            int expected = rel == 4 || rel == 0 ? 0 : rel == 2 ? 2
                                                               : 1;
            ok = ok && static_cast<int>(ps.size()) == expected;
        }
        for (const auto& p : ps) ok = ok && on_circle(c1, p) && on_circle(c2, p);

        // 共通接線の本数は位置関係 (共通接線の本数) と一致し、各直線は両方の円に接する
        auto ts2 = common_tangents(c1, c2);
        ok = ok && static_cast<int>(ts2.size()) == (ci1.c == ci2.c ? 0 : rel);
        for (const auto& [p, q] : ts2) {
            P dir = p == q ? P(-(p - c1.c)[1], (p - c1.c)[0]) : q - p;
            ok = ok && on_circle(c1, p) && on_circle(c2, q) && near(dot(p - c1.c, dir), 0) && near(dot(q - c2.c, dir), 0);
        }

        // 円と直線の交点は円周上と直線上にあり、個数は中心と直線の距離で決まる
        P p1(rndd(), rndd()), p2(rndd(), rndd());
        if (p1 != p2) {
            auto qs = circle_line_intersection(c1, p1, p2);
            double d = distance_point_line(p1, p2, c1.c);
            int expected = d > c1.r + 1e-9 ? 0 : d > c1.r - 1e-9 ? 1
                                                                 : 2;
            ok = ok && static_cast<int>(qs.size()) == expected;
            for (const auto& q : qs) ok = ok && on_circle(c1, q) && near(cross(p2 - p1, q - p1), 0);
        }

        // 接点は円周上にあり、半径と接線が垂直
        P p(rndd(), rndd());
        auto ts = tangent_points(c1, p);
        double dp = (p - c1.c).abs();
        ok = ok && static_cast<int>(ts.size()) == (dp > c1.r + 1e-9 ? 2 : dp > c1.r - 1e-9 ? 1
                                                                                           : 0);
        for (const auto& t : ts) ok = ok && on_circle(c1, t) && near(dot(t - c1.c, p - t), 0);

        // 内接円は 3 辺に接し、外接円は 3 頂点を通る
        P a(rndd(), rndd()), b(rndd(), rndd()), c(rndd(), rndd());
        if (cross(b - a, c - a) != 0) {
            Circle in = incircle(a, b, c), out = circumcircle(a, b, c);
            ok = ok && near(distance_point_line(a, b, in.c), in.r) && near(distance_point_line(b, c, in.c), in.r) && near(distance_point_line(c, a, in.c), in.r);
            ok = ok && on_circle(out, a) && on_circle(out, b) && on_circle(out, c);
        }
    }

    // 2 つの円の共通部分の面積と、円と多角形 (多角形は中心が原点の正方形) の共通部分の面積
    for (int rep = 0; rep < 300 && ok; rep++) {
        auto rndd = [&] { return static_cast<double>(static_cast<long long>(rng() % 11) - 5) / 2; };
        Circle<double> c1(P(rndd(), rndd()), (rng() % 6 + 1) / 2.0), c2(P(rndd(), rndd()), (rng() % 6 + 1) / 2.0);
        double s = (rng() % 8 + 1) / 2.0;  // 正方形の辺の長さの半分
        std::vector<P> square = {P(-s, -s), P(s, -s), P(s, s), P(-s, s)};
        // x を固定したときの、円の内部の y の区間
        auto chord = [](const Circle<double>& c, double x) {
            double h2 = c.r * c.r - (x - c.c[0]) * (x - c.c[0]);
            double h = h2 > 0 ? std::sqrt(h2) : 0;
            return std::pair<double, double>(c.c[1] - h, c.c[1] + h);
        };
        const int steps = 20000;
        double lo = -10, hi = 10, dx = (hi - lo) / steps, area_cc = 0, area_cp = 0;
        for (int i = 0; i < steps; i++) {
            double x = lo + (i + 0.5) * dx;
            auto [a1, b1] = chord(c1, x);
            auto [a2, b2] = chord(c2, x);
            area_cc += std::max(0.0, std::min(b1, b2) - std::max(a1, a2)) * dx;
            if (-s <= x && x <= s) area_cp += std::max(0.0, std::min(b1, s) - std::max(a1, -s)) * dx;
        }
        ok = ok && std::abs(circle_circle_intersection_area(c1, c2) - area_cc) < 1e-3;
        ok = ok && std::abs(circle_polygon_intersection_area(c1, square) - area_cp) < 1e-3;
        // 向きを逆にしても同じ
        std::vector<P> rev(square.rbegin(), square.rend());
        ok = ok && std::abs(circle_polygon_intersection_area(c1, rev) - area_cp) < 1e-3;
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
