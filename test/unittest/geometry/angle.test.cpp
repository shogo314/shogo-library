#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/angle.hpp の Angle を、atan2 で求めた偏角と比べて確かめる
// 問題の入力は使わず、すべて成り立ったら Hello World を出力する

#include "../../../src/geometry/angle.hpp"

#include <array>
#include <cmath>
#include <iostream>
#include <sstream>
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

    // 周回数を付けたときの比較、和・差・符号反転・opposite・next_turn を radian と比べる
    for (auto [ax, ay] : ps) {
        for (int at = -1; at <= 1; at++) {
            Angle<long long> a(ax, ay, at);
            double ta = a.radian();
            ok = ok && std::abs(ta - (arg(ax, ay) + 2 * pi * at)) < 1e-9;
            ok = ok && std::abs(a.next_turn().radian() - (ta + 2 * pi)) < 1e-9;
            ok = ok && std::abs((-a).radian() + ta) < 1e-9;
            if (!a.is_zero()) ok = ok && std::abs(a.opposite().radian() - (ta + pi)) < 1e-9;
            for (auto [bx, by] : ps) {
                for (int bt = -1; bt <= 1; bt++) {
                    Angle<long long> b(bx, by, bt);
                    double tb = b.radian();
                    bool lt = ta < tb - 1e-9, eq = std::abs(ta - tb) < 1e-9;
                    ok = ok && (a < b) == lt && (a == b) == eq;
                    ok = ok && std::abs((a + b).radian() - (ta + tb)) < 1e-9;
                    ok = ok && std::abs((a - b).radian() - (ta - tb)) < 1e-9;
                    Angle<long long> c = a;
                    c += b;
                    ok = ok && c == a + b;
                    c -= b;
                    ok = ok && c == a;
                }
            }
        }
    }
    // [θ, θ + π) の判定は a <= b && b < a.opposite() でも b - a < π でも書ける
    {
        Angle<long long> a(1, 1), on(2, 2), in(-1, 1), out(-1, -1), back(-3, -3);
        ok = ok && a <= on && on < a.opposite() && a <= in && in < a.opposite();
        ok = ok && !(back < a.opposite()) && !(out < a.opposite());
        ok = ok && on - a < Angle<long long>(-1, 0) && in - a < Angle<long long>(-1, 0);
        ok = ok && !(back - a < Angle<long long>(-1, 0)) && !(out - a < Angle<long long>(-1, 0));
    }
    // 入出力は x y (周回数は読み書きしない)
    {
        std::istringstream is("3 -4 -5 6");
        Angle<long long> a(0, 0, 5), b;
        is >> a >> b;
        ok = ok && a.x == 3 && a.y == -4 && a.turn == 0 && b.x == -5 && b.y == 6;
        std::ostringstream os;
        os << Angle<long long>(-1, 2, 3);
        ok = ok && os.str() == "-1 2";
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
