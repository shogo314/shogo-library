#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/angle.hpp の Angle を、atan2 で求めた偏角と比べて確かめる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include "../../../src/geometry/angle.hpp"

#include <array>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/geometry/vector.hpp"

int main() {
    bool ok = true;
    const double pi = std::acos(-1.0);
    // 偏角を [0, 2π) で返す。零ベクトルは 0
    auto arg = [&](int x, int y) {
        double t = std::atan2(static_cast<double>(y), static_cast<double>(x));
        return t < 0 ? t + 2 * pi : t;
    };
    std::vector<std::pair<int, int>> ps;
    for (int x = -4; x <= 4; x++) {
        for (int y = -4; y <= 4; y++) ps.emplace_back(x, y);
    }
    for (auto [ax, ay] : ps) {
        Angle<long long> a(ax, ay);
        ok = ok && std::abs(a.radian() - arg(ax, ay)) < 1e-12;
        ok = ok && a.is_zero() == (ax == 0 && ay == 0);
        ok = ok && a.half() == (arg(ax, ay) >= pi - 1e-12);
        for (auto [bx, by] : ps) {
            Angle<long long> b(bx, by);
            double ta = arg(ax, ay), tb = arg(bx, by);
            bool lt = ta < tb - 1e-12, eq = std::abs(ta - tb) < 1e-12;
            ok = ok && (a < b) == lt && (b > a) == lt;
            ok = ok && (a == b) == eq && (a != b) == !eq;
            ok = ok && (a <= b) == (lt || eq) && (b >= a) == (lt || eq);
        }
    }

    // Vector、std::array、std::pair から作れる
    Vector<long long> v(-3, 2);
    std::array<long long, 2> w{-3, 2};
    std::pair<long long, long long> p(-3, 2);
    Angle av(v), aw(w), ap(p);
    ok = ok && av.x == -3 && av.y == 2 && aw.x == -3 && aw.y == 2 && ap.x == -3 && ap.y == 2;
    ok = ok && av == Angle<long long>(-6, 4);
    // 浮動小数点型でも使える
    ok = ok && Angle(1.0, 1.0) < Angle(-1.0, 0.0) && !(Angle(0.0, 0.0) < Angle(2.0, 0.0));

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
