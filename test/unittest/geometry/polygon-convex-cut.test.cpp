#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/polygon.hpp の convex_cut を確かめる
// 直線の両側に切った面積の和がもとの面積になることと、切った頂点が直線の左側にあることを確かめる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#include "../../../src/geometry/polygon.hpp"
#include "../../../src/geometry/vector.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    using P = Vector<double>;
    for (int rep = 0; rep < 20000 && ok; rep++) {
        std::vector<P> pts(rng() % 10 + 3);
        for (auto& x : pts) x = P(static_cast<double>(rng() % 21) - 10, static_cast<double>(rng() % 21) - 10);
        auto poly = convex_hull(pts);
        if (poly.size() < 3) continue;
        P p1(static_cast<double>(rng() % 31) - 15, static_cast<double>(rng() % 31) - 15), p2(static_cast<double>(rng() % 31) - 15, static_cast<double>(rng() % 31) - 15);
        if (p1 == p2) continue;
        auto left = convex_cut(poly, p1, p2), right = convex_cut(poly, p2, p1);
        if (std::abs(polygon_area(left) + polygon_area(right) - polygon_area(poly)) > 1e-7) ok = false;
        for (const auto& q : left) {
            if (cross(p2 - p1, q - p1) < -1e-7) ok = false;
        }
        for (const auto& q : right) {
            if (cross(p2 - p1, q - p1) > 1e-7) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
