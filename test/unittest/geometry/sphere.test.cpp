#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/sphere.hpp の関数を確かめる
// 交点・交わりの円は、求めた点が球面や直線の上にあることと、個数が中心と直線の距離などから決まるものと一致することを見る
// 共通部分の体積は、中心を結ぶ直線に垂直な断面 (2 つの円の小さい方) の面積を数値積分したものと比べる
// 大円距離は、2 点の弦の長さから求めた角度と比べる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include "../../../src/geometry/sphere.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/geometry/segment-3d.hpp"
#include "../../../src/geometry/vector.hpp"

using D = Vector<double, 3>;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

int main() {
    std::mt19937 rng(314);
    std::uniform_real_distribution<double> uni(-5, 5), pos(0.1, 4);
    auto rp = [&]() { return D(uni(rng), uni(rng), uni(rng)); };
    const double pi = std::acos(-1.0);

    for (int rep = 0; rep < 20000 && ok; rep++) {
        // 球と直線
        {
            Sphere s(rp(), pos(rng));
            D p1 = rp(), p2 = rp();
            auto xs = sphere_line_intersection(s, p1, p2);
            double d = distance_point_line(p1, p2, s.c);
            check(xs.size() == (d > s.r + 1e-9 ? 0u : d >= s.r - 1e-9 ? 1u
                                                                      : 2u),
                  "sphere_line_intersection (個数)");
            for (auto& x : xs) {
                check(std::abs((x - s.c).abs() - s.r) < 1e-6, "sphere_line_intersection (球面上)");
                check(distance_point_line(p1, p2, x) < 1e-6, "sphere_line_intersection (直線上)");
            }
            if (xs.size() == 2) check(dot(p2 - p1, xs[1] - xs[0]) > 0, "sphere_line_intersection (p1 から p2 の向きの順)");
        }
        // 球と球
        {
            Sphere s1(rp(), pos(rng)), s2(rp(), pos(rng));
            if (rng() % 4 == 0) s2.c = s1.c + (s2.c - s1.c) / (s2.c - s1.c).abs() * (s1.r + s2.r);  // 外接
            auto c = sphere_sphere_intersection(s1, s2);
            double d = (s1.c - s2.c).abs();
            const bool meet = d <= s1.r + s2.r + 1e-9 && d >= std::abs(s1.r - s2.r) - 1e-9;
            check(c.has_value() == meet, "sphere_sphere_intersection (交わるか)");
            if (c) {
                check(std::abs(c->n.abs() - 1) < 1e-9 && (c->n - (s2.c - s1.c) / d).abs() < 1e-9, "sphere_sphere_intersection (法線)");
                // 円周上の点 (法線に垂直な単位ベクトルの r 倍だけ中心からずらす) は両方の球面上にある
                D t = cross(c->n, std::abs(c->n[0]) < 0.9 ? D(1.0, 0.0, 0.0) : D(0.0, 1.0, 0.0));
                t = t / t.abs();
                for (int k = 0; k < 4; k++) {
                    D u = t * std::cos(k * 1.3) + cross(c->n, t) * std::sin(k * 1.3);
                    D x = c->c + u * c->r;
                    check(std::abs((x - s1.c).abs() - s1.r) < 1e-6 && std::abs((x - s2.c).abs() - s2.r) < 1e-6, "sphere_sphere_intersection (円周上)");
                }
            }
        }
    }
    // 接する球は半径 0 の円 (中心が接点)
    {
        auto c = sphere_sphere_intersection(Sphere(D(0.0, 0.0, 0.0), 1.0), Sphere(D(3.0, 0.0, 0.0), 2.0));
        check(c && c->r == 0 && (c->c - D(1.0, 0.0, 0.0)).abs() < 1e-12, "sphere_sphere_intersection (外接)");
        auto e = sphere_sphere_intersection(Sphere(D(0.0, 0.0, 0.0), 3.0), Sphere(D(1.0, 0.0, 0.0), 2.0));
        check(e && e->r == 0 && (e->c - D(3.0, 0.0, 0.0)).abs() < 1e-12, "sphere_sphere_intersection (内接)");
        check(!sphere_sphere_intersection(Sphere(D(0.0, 0.0, 0.0), 3.0), Sphere(D(0.0, 0.0, 0.0), 2.0)), "sphere_sphere_intersection (同心)");
    }

    // 共通部分の体積
    for (int rep = 0; rep < 300 && ok; rep++) {
        Sphere s1(rp(), pos(rng)), s2(rp(), pos(rng));
        if (rep % 3 == 0) s2.c = s1.c + D(uni(rng), uni(rng), uni(rng)) / 5.0;  // 近い (内部にあることも多い)
        const double d = (s1.c - s2.c).abs();
        // 中心を結ぶ直線を x 軸、s1 の中心を原点としたときの x での断面の面積を、シンプソン則で積分する
        auto area = [&](double x) {
            double a = s1.r * s1.r - x * x, b = s2.r * s2.r - (x - d) * (x - d);
            return a <= 0 || b <= 0 ? 0.0 : pi * std::min(a, b);
        };
        const int m = 200000;
        const double lo = -s1.r, hi = s1.r, h = (hi - lo) / m;
        double sum = area(lo) + area(hi);
        for (int i = 1; i < m; i++) sum += area(lo + i * h) * (i % 2 ? 4 : 2);
        const double expect = sum * h / 3;
        check(std::abs(sphere_sphere_intersection_volume(s1, s2) - expect) < 1e-6 * std::max(1.0, expect), "sphere_sphere_intersection_volume");
    }
    check(std::abs(sphere_sphere_intersection_volume(Sphere(D(0.0, 0.0, 0.0), 1.0), Sphere(D(0.5, 0.0, 0.0), 3.0)) - pi * 4 / 3) < 1e-12, "sphere_sphere_intersection_volume (内部)");
    check(sphere_sphere_intersection_volume(Sphere(D(0.0, 0.0, 0.0), 1.0), Sphere(D(2.0, 0.0, 0.0), 1.0)) == 0, "sphere_sphere_intersection_volume (外接)");

    // 大円距離
    std::uniform_real_distribution<double> lat(-pi / 2, pi / 2), lon(-pi, pi);
    for (int rep = 0; rep < 20000 && ok; rep++) {
        double a1 = lat(rng), o1 = lon(rng), a2 = lat(rng), o2 = lon(rng), r = pos(rng);
        if (rep % 4 == 0) a2 = a1 + 1e-7, o2 = o1;  // 近い 2 点
        auto point = [](double a, double o) { return D(std::cos(a) * std::cos(o), std::cos(a) * std::sin(o), std::sin(a)); };
        const double chord = (point(a1, o1) - point(a2, o2)).abs();
        const double expect = r * 2 * std::asin(std::min(1.0, chord / 2));
        check(std::abs(great_circle_distance(a1, o1, a2, o2, r) - expect) < 1e-9 * r, "great_circle_distance");
    }
    // 北極と南極は半周、赤道上で経度が 90 度違えば 1/4 周
    check(std::abs(great_circle_distance(pi / 2, 0.0, -pi / 2, 1.0) - pi) < 1e-12, "great_circle_distance (両極)");
    check(std::abs(great_circle_distance(0.0, 0.0, 0.0, pi / 2, 2.0) - pi) < 1e-12, "great_circle_distance (赤道)");

    if (ok) std::cout << "Hello World" << std::endl;
}
