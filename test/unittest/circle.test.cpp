#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/circle.hpp の関数を、定義から確かめる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include <cmath>
#include <iostream>
#include <random>

#include "../../src/geometry/circle.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    using P = Vector<double>;
    auto near = [](double a, double b) { return std::abs(a - b) < 1e-6; };
    auto on_circle = [&](const Circle<double>& c, const P& p) { return near((p - c.c).abs(), c.r); };
    for (int rep = 0; rep < 20000 && ok; rep++) {
        auto rnd = [&] { return (long long)(rng() % 11) - 5; };
        auto rndd = [&] { return (double)rnd(); };
        Circle<long long> ci1(Vector<long long>(rnd(), rnd()), rng() % 5 + 1), ci2(Vector<long long>(rnd(), rnd()), rng() % 5 + 1);
        Circle<double> c1(P((double)ci1.c[0], (double)ci1.c[1]), ci1.r), c2(P((double)ci2.c[0], (double)ci2.c[1]), ci2.r);

        // 位置関係と交点の個数が対応する
        int rel = circle_relation(ci1, ci2);
        ok = ok && circle_relation(c1, c2) == rel;
        auto ps = circle_circle_intersection(c1, c2);
        if (ci1.c == ci2.c) {
            ok = ok && ps.empty();
        } else {
            int expected = rel == 4 || rel == 0 ? 0 : rel == 2 ? 2 : 1;
            ok = ok && (int)ps.size() == expected;
        }
        for (const auto& p : ps) ok = ok && on_circle(c1, p) && on_circle(c2, p);

        // 円と直線の交点は円周上と直線上にあり、個数は中心と直線の距離で決まる
        P p1(rndd(), rndd()), p2(rndd(), rndd());
        if (p1 != p2) {
            auto qs = circle_line_intersection(c1, p1, p2);
            double d = distance_point_line(p1, p2, c1.c);
            int expected = d > c1.r + 1e-9 ? 0 : d > c1.r - 1e-9 ? 1 : 2;
            ok = ok && (int)qs.size() == expected;
            for (const auto& q : qs) ok = ok && on_circle(c1, q) && near(cross(p2 - p1, q - p1), 0);
        }

        // 接点は円周上にあり、半径と接線が垂直
        P p(rndd(), rndd());
        auto ts = tangent_points(c1, p);
        double dp = (p - c1.c).abs();
        ok = ok && (int)ts.size() == (dp > c1.r + 1e-9 ? 2 : dp > c1.r - 1e-9 ? 1 : 0);
        for (const auto& t : ts) ok = ok && on_circle(c1, t) && near(dot(t - c1.c, p - t), 0);

        // 内接円は 3 辺に接し、外接円は 3 頂点を通る
        P a(rndd(), rndd()), b(rndd(), rndd()), c(rndd(), rndd());
        if (cross(b - a, c - a) != 0) {
            Circle in = incircle(a, b, c), out = circumcircle(a, b, c);
            ok = ok && near(distance_point_line(a, b, in.c), in.r) && near(distance_point_line(b, c, in.c), in.r) && near(distance_point_line(c, a, in.c), in.r);
            ok = ok && on_circle(out, a) && on_circle(out, b) && on_circle(out, c);
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
