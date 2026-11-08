#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// 3 次元の直線・線分・平面・三角形の関数を愚直な方法と比べる
// 距離は、線分や平面のパラメータについて凸なので、三分探索で最小化したものと比べる
// segment_triangle_intersect は、平面を貫く場合は交点を有理数で正確に求めて三角形の内外を調べたものと、
// 同じ平面上の場合は z = 0 の平面で 2 次元の判定をしてから、行列式 ±1 の整数の行列で空間に移したものと比べる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include "../../../src/geometry/plane.hpp"

#include <cmath>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/geometry/polygon.hpp"
#include "../../../src/geometry/triangle.hpp"
#include "../../../src/geometry/vector.hpp"

using P = Vector<long long, 3>;

constexpr Plane horizontal(P(0, 0, 0), P(1, 0, 0), P(0, 1, 0));
static_assert(std::is_same_v<std::decay_t<decltype(horizontal)>, Plane<long long>>);
static_assert(horizontal == Plane(P(3, 4, 0), P(3, 5, 0), P(4, 4, 0)));
static_assert(horizontal != Plane(P(0, 0, 1), P(1, 0, 1), P(0, 1, 1)));
static_assert(horizontal != Plane(P(0, 0, 0), P(1, 0, 0), P(0, 0, 1)));
static_assert(is_parallel(horizontal, Plane(P(0, 0, 1), P(0, 1, 1), P(1, 0, 1))));
static_assert(!is_parallel(horizontal, Plane(P(0, 0, 0), P(1, 0, 0), P(0, 0, 1))));
static_assert(horizontal.contains(P(3, -4, 0)));
static_assert(!horizontal.contains(P(3, -4, 1)));
using D = Vector<double, 3>;
using L = long double;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}
bool near(double a, double b) { return std::abs(a - b) <= 1e-6 * std::max(1.0, std::abs(b)); }

// [lo, hi] で凸な関数の最小値
L minimize(const std::function<L(L)>& f, L lo, L hi) {
    for (int i = 0; i < 80; i++) {
        L m1 = (2 * lo + hi) / 3, m2 = (lo + 2 * hi) / 3;
        if (f(m1) < f(m2))
            hi = m2;
        else
            lo = m1;
    }
    return f((lo + hi) / 2);
}
Vector<L, 3> at(const P& p, const P& q, L t) { return Vector<L, 3>(p[0] + (q[0] - p[0]) * t, p[1] + (q[1] - p[1]) * t, p[2] + (q[2] - p[2]) * t); }
L dist(const Vector<L, 3>& a, const Vector<L, 3>& b) {
    L s = 0;
    for (int i = 0; i < 3; i++) s += (a[i] - b[i]) * (a[i] - b[i]);
    return std::sqrt(s);
}
Vector<L, 3> to_l(const P& p) { return Vector<L, 3>(p[0], p[1], p[2]); }

// 平面を貫く場合の愚直な判定: 交点を p1 * den + (p2 - p1) * num (の 1/den) として正確に求める
__int128_t vol(const P& a, const P& b, const P& c, const P& d) {
    __int128_t m[3][3];
    for (int i = 0; i < 3; i++) m[0][i] = b[i] - a[i], m[1][i] = c[i] - a[i], m[2][i] = d[i] - a[i];
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}
bool naive_crossing(const P& p1, const P& p2, const P& a, const P& b, const P& c) {
    __int128_t v1 = vol(a, b, c, p1), v2 = vol(a, b, c, p2);
    if ((v1 > 0 && v2 > 0) || (v1 < 0 && v2 < 0)) return false;
    // 交点は p1 + (p2 - p1) * v1 / (v1 - v2)。den 倍した座標で三角形の内外を調べる
    __int128_t num = v1, den = v1 - v2;
    if (den < 0) num = -num, den = -den;
    using W = Vector<__int128_t, 3>;
    auto scale = [&](const P& p) { return W(p[0] * den, p[1] * den, p[2] * den); };
    W q(p1[0] * den + (p2[0] - p1[0]) * num, p1[1] * den + (p2[1] - p1[1]) * num, p1[2] * den + (p2[2] - p1[2]) * num);
    W A = scale(a), B = scale(b), C = scale(c);
    W n = cross(B - A, C - A);
    __int128_t x = dot(n, cross(B - A, q - A)), y = dot(n, cross(C - B, q - B)), z = dot(n, cross(A - C, q - C));
    return x >= 0 && y >= 0 && z >= 0;
}

int main() {
    std::mt19937 rng(314);
    auto rnd = [&](int w) { return static_cast<long long>(rng() % (2 * w + 1)) - w; };
    auto rp = [&](int w) { return P(rnd(w), rnd(w), rnd(w)); };

    for (int rep = 0; rep < 400 && ok; rep++) {
        const int w = rng() % 2 ? 3 : 100;
        P p1 = rp(w), p2 = rp(w), q1 = rp(w), q2 = rp(w), p = rp(w);
        if (rng() % 4 == 0) q2 = q1 + (p2 - p1) * (rng() % 3);  // 平行
        // 点と線分・直線
        {
            L e = minimize([&](L t) { return dist(at(p1, p2, t), to_l(p)); }, 0, 1);
            check(near(distance_point_segment(Segment(p1, p2), p), e), "distance_point_segment");
            if (p1 != p2) {
                L f = minimize([&](L t) { return dist(at(p1, p2, t), to_l(p)); }, -1000, 1000);
                check(near(distance_point_line(Line(p1, p2), p), f), "distance_point_line");
            }
        }
        // 線分どうし: s を外側、t を内側で三分探索する (距離は (s, t) について凸)
        {
            L e = minimize([&](L s) { return minimize([&](L t) { return dist(at(p1, p2, s), at(q1, q2, t)); }, 0, 1); }, 0, 1);
            check(near(distance_segments(Segment(p1, p2), Segment(q1, q2)), e), "distance_segments");
        }
        // 直線どうし
        if (p1 != p2 && q1 != q2) {
            L e = minimize([&](L s) { return minimize([&](L t) { return dist(at(p1, p2, s), at(q1, q2, t)); }, -1000, 1000); }, -1000, 1000);
            check(near(distance_lines(Line(p1, p2), Line(q1, q2)), e), "distance_lines");
        }
        // 点と平面、直線と平面
        {
            P a = rp(w), b = rp(w), c = rp(w);
            if (cross(b - a, c - a) == P()) continue;
            const Plane plane(a, b, c);
            const Plane same(a + (b - a) * 2, a + (c - a) * 3, a - (b - a) - (c - a));
            check(plane == same && same == plane && plane == Plane(c, b, a), "Plane equality");
            P normal = cross(b - a, c - a);
            check(plane.contains(a) && plane.contains(b) && plane.contains(c), "Plane contains defining points");
            check(plane.contains(a + (b - a) * 3 - (c - a) * 2), "Plane contains affine combination");
            check(!plane.contains(a + normal) && !plane.contains(a - normal), "Plane excludes points off plane");
            check(plane.contains(Line(a, b)) && plane.contains(Line(c, c + b - a)), "Plane contains line");
            check(plane.contains(Line(b, a)), "Plane contains reversed line");
            check(!plane.contains(Line(a + normal, b + normal)), "Plane excludes parallel line");
            check(!plane.contains(Line(a, a + normal)) && !plane.contains(Line(a + normal, a)), "Plane excludes crossing line");
            const Plane shifted(a + normal, b + normal, c + normal);
            check(is_parallel(plane, same) && is_parallel(plane, shifted) && is_parallel(shifted, plane), "parallel planes");
            check(is_parallel(Line(a, b), plane) && is_parallel(plane, Line(c + normal, c + normal + b - a)), "parallel line and plane");
            check(!is_parallel(Line(a, a + normal), plane) && !is_parallel(plane, Line(a, a + normal)), "line crossing plane");
            check(is_parallel(Line(a, b), Line(c, c - (b - a) * 3)), "parallel lines");
            check(!is_parallel(Line(a, b), Line(a, c)), "nonparallel lines");
            check(plane != Plane(a + normal, b + normal, c + normal), "Plane parallel and distinct");
            L e = minimize([&](L s) { return minimize([&](L t) {
                                          Vector<L, 3> x = to_l(a) + (to_l(b) - to_l(a)) * s + (to_l(c) - to_l(a)) * t;
                                          return dist(x, to_l(p));
                                      },
                                                      -1000, 1000); },
                           -1000, 1000);
            check(near(distance_point_plane(Plane(a, b, c), p), e), "distance_point_plane");
            if (p1 == p2) continue;
            auto to_d = [](const P& v) { return D(v[0], v[1], v[2]); };
            auto x = line_plane_intersection(Line(to_d(p1), to_d(p2)), Plane(to_d(a), to_d(b), to_d(c)));
            const bool parallel = dot(cross(b - a, c - a), p2 - p1) == 0;
            check(is_parallel(Line(p1, p2), plane) == parallel, "is_parallel and intersection");
            check(x.has_value() != parallel, "line_plane_intersection (平行)");
            if (x) {
                check(distance_point_plane(Plane(to_d(a), to_d(b), to_d(c)), *x) < 1e-6, "line_plane_intersection (平面上)");
                check(distance_point_line(Line(to_d(p1), to_d(p2)), *x) < 1e-6, "line_plane_intersection (直線上)");
            }
        }
    }

    // 線分と三角形: 平面を貫く (または端点が平面上にある) 場合
    for (int rep = 0; rep < 200000 && ok; rep++) {
        const int w = rng() % 2 ? 2 : 5;
        P p1 = rp(w), p2 = rp(w), a = rp(w), b = rp(w), c = rp(w);
        if (cross(b - a, c - a) == P()) continue;
        if (vol(a, b, c, p1) == 0 && vol(a, b, c, p2) == 0) continue;
        check(segment_triangle_intersect(Segment(p1, p2), Triangle(a, b, c)) == naive_crossing(p1, p2, a, b, c), "segment_triangle_intersect (貫く)");
    }
    // 同じ平面上の場合: z = 0 で 2 次元の判定をして、行列式 ±1 の行列と平行移動で空間に移す
    for (int rep = 0; rep < 100000 && ok; rep++) {
        const int w = rng() % 2 ? 2 : 6;
        using V2 = Vector<long long, 2>;
        auto r2 = [&]() { return V2(rnd(w), rnd(w)); };
        V2 p1 = r2(), p2 = r2(), a = r2(), b = r2(), c = r2();
        if (cross(b - a, c - a) == 0) continue;
        std::vector<V2> tri = {a, b, c};
        if (cross(b - a, c - a) < 0) tri = {a, c, b};
        bool expect = polygon_contains(tri, p1) > 0 || polygon_contains(tri, p2) > 0;
        if (p1 != p2) expect = expect || segments_intersect(Segment(p1, p2), Segment(a, b)) || segments_intersect(Segment(p1, p2), Segment(b, c)) || segments_intersect(Segment(p1, p2), Segment(c, a));
        // 基本変形 (ある行に別の行の整数倍を足す) を何回か掛けた行列
        long long m[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        for (int k = 0; k < 4; k++) {
            int i = rng() % 3, j = (i + 1 + rng() % 2) % 3;
            long long f = rnd(2);
            for (int col = 0; col < 3; col++) m[i][col] += f * m[j][col];
        }
        P shift = rp(10);
        auto lift = [&](const V2& v) {
            P r;
            for (int i = 0; i < 3; i++) r[i] = m[i][0] * v[0] + m[i][1] * v[1] + shift[i];
            return r;
        };
        check(segment_triangle_intersect(Segment(lift(p1), lift(p2)), Triangle(lift(a), lift(b), lift(c))) == expect, "segment_triangle_intersect (同じ平面上)");
    }

    // 3 次元の型推論と、同じ直線・線分の判定。ねじれの位置も区別する
    {
        Line line(P(0, 0, 0), P(1, 2, 3));
        static_assert(std::is_same_v<decltype(line), Line<long long, 3>>);
        Segment segment(P(0, 0, 0), P(1, 2, 3));
        static_assert(std::is_same_v<decltype(segment), Segment<long long, 3>>);
        check(line == Line(P(3, 6, 9), P(-2, -4, -6)), "Line equality");
        check(line != Line(P(0, 0, 1), P(1, 2, 4)), "Line parallel and distinct");
        check(line != Line(P(0, 1, 0), P(1, 1, 0)), "Line skew");
        check(segment == Segment(P(1, 2, 3), P(0, 0, 0)), "Segment equality");
        check(segment != Segment(P(0, 0, 0), P(2, 4, 6)), "Segment distinct");
    }

    // 座標が 1e9 でも体積の計算があふれない
    const long long G = 1000000000;
    const Plane large(P(-G, -G, 0), P(G, -G, 0), P(0, G, 0));
    check(large == Plane(P(0, 0, 0), P(G, G, 0), P(-G, G, 0)), "Plane equality (1e9)");
    check(large != Plane(P(-G, -G, G), P(G, -G, G), P(0, G, G)), "Plane distinct (1e9)");
    const Plane large_shifted(P(-G, -G, G), P(0, G, G), P(G, -G, G));
    check(is_parallel(large, large_shifted), "parallel planes (1e9)");
    check(is_parallel(Line(P(-G, G, G), P(G, G, G)), large), "parallel line and plane (1e9)");
    check(!is_parallel(Line(P(-G, -G, -G), P(G, G, G)), large), "nonparallel line and plane (1e9)");
    check(is_parallel(Line(P(-G, -G, -G), P(G, G, G)), Line(P(G, G, G), P(0, 0, 0))), "parallel lines (1e9)");
    check(near(distance_point_plane(large, P(G, G, G)), G), "distance_point_plane (1e9)");
    check(large.contains(P(G, G, 0)) && !large.contains(P(G, G, G)), "Plane contains point (1e9)");
    check(large.contains(Line(P(-G, G, 0), P(G, G, 0))), "Plane contains line (1e9)");
    check(!large.contains(Line(P(-G, G, G), P(G, G, G))), "Plane excludes line (1e9)");
    const Plane floating(D(0, 0, 0.5), D(1, 0, 0.5), D(0, 1, 0.5));
    static_assert(std::is_same_v<std::decay_t<decltype(floating)>, Plane<double>>);
    check(floating == Plane(D(2, 3, 0.5), D(3, 3, 0.5), D(2, 4, 0.5)), "Plane equality (double)");
    check(floating.contains(D(2, -3, 0.5)) && !floating.contains(D(2, -3, 0.500001)), "Plane contains point (double)");
    check(floating.contains(Line(D(1, 2, 0.5), D(3, 4, 0.5))), "Plane contains line (double)");
    check(!floating.contains(Line(D(1, 2, 1.5), D(3, 4, 1.5))), "Plane excludes line (double)");
    check(!line_plane_intersection(Line(D(0, 0, 0.5), D(1, 0, 0.5)), floating), "line contained in plane");
    check(!line_plane_intersection(Line(D(0, 0, 1.5), D(1, 0, 1.5)), floating), "line parallel to plane");
    check(is_parallel(floating, floating) && is_parallel(Line(D(0, 0, 1.5), D(1, 0, 1.5)), floating), "parallel (double)");
    check(!is_parallel(floating, Line(D(0, 0, 0), D(0, 0, 1))), "nonparallel (double)");
    check(segment_triangle_intersect(Segment(P(0, 0, -G), P(0, 0, G)), Triangle(P(-G, -G, 0), P(G, -G, 0), P(0, G, 0))), "segment_triangle_intersect (1e9)");
    check(!segment_triangle_intersect(Segment(P(G, G, -G), P(G, G, G)), Triangle(P(-G, -G, 0), P(G, -G, 0), P(0, G, 0))), "segment_triangle_intersect (1e9, 外)");
    check(near(distance_point_line(Line(P(-G, -G, -G), P(G, G, G)), P(G, -G, 0)), std::sqrt(2.0) * G), "distance_point_line (1e9)");

    if (ok) std::cout << "Hello World" << std::endl;
}
