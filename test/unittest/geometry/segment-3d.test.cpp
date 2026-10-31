#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/segment-3d.hpp の関数を愚直な方法と比べる
// 距離は、線分や平面のパラメータについて凸なので、三分探索で最小化したものと比べる
// segment_triangle_intersect は、平面を貫く場合は交点を有理数で正確に求めて三角形の内外を調べたものと、
// 同じ平面上の場合は z = 0 の平面で 2 次元の判定をしてから、行列式 ±1 の整数の行列で空間に移したものと比べる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include "../../../src/geometry/segment-3d.hpp"

#include <cmath>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/geometry/polygon.hpp"
#include "../../../src/geometry/vector.hpp"

using P = Vector<long long, 3>;
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
            check(near(distance_point_segment(p1, p2, p), e), "distance_point_segment");
            if (p1 != p2) {
                L f = minimize([&](L t) { return dist(at(p1, p2, t), to_l(p)); }, -1000, 1000);
                check(near(distance_point_line(p1, p2, p), f), "distance_point_line");
            }
        }
        // 線分どうし: s を外側、t を内側で三分探索する (距離は (s, t) について凸)
        {
            L e = minimize([&](L s) { return minimize([&](L t) { return dist(at(p1, p2, s), at(q1, q2, t)); }, 0, 1); }, 0, 1);
            check(near(distance_segments(p1, p2, q1, q2), e), "distance_segments");
        }
        // 直線どうし
        if (p1 != p2 && q1 != q2) {
            L e = minimize([&](L s) { return minimize([&](L t) { return dist(at(p1, p2, s), at(q1, q2, t)); }, -1000, 1000); }, -1000, 1000);
            check(near(distance_lines(p1, p2, q1, q2), e), "distance_lines");
        }
        // 点と平面、直線と平面
        {
            P a = rp(w), b = rp(w), c = rp(w);
            if (cross(b - a, c - a) == P()) continue;
            L e = minimize([&](L s) { return minimize([&](L t) {
                                          Vector<L, 3> x = to_l(a) + (to_l(b) - to_l(a)) * s + (to_l(c) - to_l(a)) * t;
                                          return dist(x, to_l(p));
                                      },
                                                      -1000, 1000); },
                           -1000, 1000);
            check(near(distance_point_plane(a, b, c, p), e), "distance_point_plane");
            if (p1 == p2) continue;
            auto to_d = [](const P& v) { return D(v[0], v[1], v[2]); };
            auto x = line_plane_intersection(to_d(p1), to_d(p2), to_d(a), to_d(b), to_d(c));
            const bool parallel = dot(cross(b - a, c - a), p2 - p1) == 0;
            check(x.has_value() != parallel, "line_plane_intersection (平行)");
            if (x) {
                check(distance_point_plane(to_d(a), to_d(b), to_d(c), *x) < 1e-6, "line_plane_intersection (平面上)");
                check(distance_point_line(to_d(p1), to_d(p2), *x) < 1e-6, "line_plane_intersection (直線上)");
            }
        }
    }

    // 線分と三角形: 平面を貫く (または端点が平面上にある) 場合
    for (int rep = 0; rep < 200000 && ok; rep++) {
        const int w = rng() % 2 ? 2 : 5;
        P p1 = rp(w), p2 = rp(w), a = rp(w), b = rp(w), c = rp(w);
        if (cross(b - a, c - a) == P()) continue;
        if (vol(a, b, c, p1) == 0 && vol(a, b, c, p2) == 0) continue;
        check(segment_triangle_intersect(p1, p2, a, b, c) == naive_crossing(p1, p2, a, b, c), "segment_triangle_intersect (貫く)");
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
        if (p1 != p2) expect = expect || segments_intersect(p1, p2, a, b) || segments_intersect(p1, p2, b, c) || segments_intersect(p1, p2, c, a);
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
        check(segment_triangle_intersect(lift(p1), lift(p2), lift(a), lift(b), lift(c)) == expect, "segment_triangle_intersect (同じ平面上)");
    }

    // 座標が 1e9 でも体積の計算があふれない
    const long long G = 1000000000;
    check(segment_triangle_intersect(P(0, 0, -G), P(0, 0, G), P(-G, -G, 0), P(G, -G, 0), P(0, G, 0)), "segment_triangle_intersect (1e9)");
    check(!segment_triangle_intersect(P(G, G, -G), P(G, G, G), P(-G, -G, 0), P(G, -G, 0), P(0, G, 0)), "segment_triangle_intersect (1e9, 外)");
    check(near(distance_point_line(P(-G, -G, -G), P(G, G, G), P(G, -G, 0)), std::sqrt(2.0) * G), "distance_point_line (1e9)");

    if (ok) std::cout << "Hello World" << std::endl;
}
