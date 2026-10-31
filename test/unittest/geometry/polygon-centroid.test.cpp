#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/polygon.hpp の polygon_centroid と polygon_edge_moment (PolygonMoment) を確かめる
// polygon_centroid は、頂点 0 から三角形に分けて、三角形の重心を面積で重み付けしたものと比べる
// polygon_edge_moment は、座標が 1e9 で long long をあふれる大きさでも正確なことと、CircularSum で部分多角形を求められることを確かめる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/data_structures/circular-sum.hpp"
#include "../../../src/geometry/polygon.hpp"
#include "../../../src/geometry/vector.hpp"

using P = Vector<long long>;

// 頂点 0 から三角形に分けて求めた重心
Vector<double, 2> naive_centroid(const std::vector<P>& p) {
    long double s = 0, gx = 0, gy = 0;
    for (int i = 1; i + 1 < static_cast<int>(p.size()); i++) {
        long double c = cross(p[i] - p[0], p[i + 1] - p[0]);
        s += c;
        gx += c * (p[0][0] + p[i][0] + p[i + 1][0]) / 3;
        gy += c * (p[0][1] + p[i][1] + p[i + 1][1]) / 3;
    }
    return Vector<double, 2>(static_cast<double>(gx / s), static_cast<double>(gy / s));
}

bool near(const Vector<double, 2>& a, const Vector<double, 2>& b) {
    return std::abs(a[0] - b[0]) <= 1e-6 * std::max(1.0, std::abs(b[0])) && std::abs(a[1] - b[1]) <= 1e-6 * std::max(1.0, std::abs(b[1]));
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 20000 && ok; rep++) {
        int n = rng() % 8 + 3, w = rng() % 2 ? 3 : 1000;
        std::vector<P> p(n);
        for (auto& x : p) x = P(static_cast<long long>(rng() % (2 * w + 1)) - w, static_cast<long long>(rng() % (2 * w + 1)) - w);
        if (polygon_area_doubled(p) == 0) continue;

        if (!near(polygon_centroid(p), naive_centroid(p))) ok = false;
        // 向きを逆にしても同じ
        std::vector<P> r(p.rbegin(), p.rend());
        if (!near(polygon_centroid(r), naive_centroid(p))) ok = false;

        // 辺ごとの寄与の和の area2 は面積の 2 倍、centroid は重心
        PolygonMoment<long long> m;
        std::vector<PolygonMoment<long long>> e(n);
        for (int i = 0; i < n; i++) m += e[i] = polygon_edge_moment(p[i], p[(i + 1) % n]);
        if (m.area2 != polygon_area_doubled(p)) ok = false;
        if (std::abs(m.area() - polygon_area_doubled(p) / 2.0) > 1e-9) ok = false;
        if (!near(m.centroid(), naive_centroid(p))) ok = false;
        if (m - e[0] + e[0] != m) ok = false;

        // 部分多角形 u, u+1, ..., v (円環上) を CircularSum で求める
        CircularSum cs(e);
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (u == v) continue;
                std::vector<P> sub;
                for (int i = u;; i = (i + 1) % n) {
                    sub.push_back(p[i]);
                    if (i == v) break;
                }
                auto s = cs.sum(u, v) + polygon_edge_moment(p[v], p[u]);
                if (s.area2 != polygon_area_doubled(sub)) ok = false;
                if (s.area2 == 0) continue;
                if (!near(s.centroid(), polygon_centroid(sub))) ok = false;
            }
        }
    }

    // 座標が 1e9 の正方形: mx = 6S gx = 6 * 1e18 * 5e8 = 3e27 は long long をあふれる
    const long long L = 1000000000;
    std::vector<P> sq = {P(0, 0), P(L, 0), P(L, L), P(0, L)};
    PolygonMoment<long long> m;
    for (int i = 0; i < 4; i++) m += polygon_edge_moment(sq[i], sq[(i + 1) % 4]);
    const __int128_t s2 = static_cast<__int128_t>(L) * L * 2;
    if (m.area2 != s2 || m.mx != s2 * 3 * (L / 2) || m.my != s2 * 3 * (L / 2)) ok = false;
    if (!near(polygon_centroid(sq), Vector<double, 2>(L / 2.0, L / 2.0))) ok = false;

    // 浮動小数点型の座標でも使える
    std::vector<Vector<double, 2>> tri = {Vector<double, 2>(0.0, 0.0), Vector<double, 2>(3.0, 0.0), Vector<double, 2>(0.0, 3.0)};
    if (!near(polygon_centroid(tri), Vector<double, 2>(1.0, 1.0))) ok = false;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
