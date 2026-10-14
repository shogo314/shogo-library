#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Rational を、__int128 で通分して計算する愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/math/rational.hpp"

#include <iostream>
#include <map>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using i128 = __int128;

i128 gcd128(i128 a, i128 b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        i128 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// p / q を既約にして Rational<T> と一致するか
template <typename T>
bool same(const Rational<T>& r, i128 p, i128 q) {
    if (q < 0) p = -p, q = -q;
    i128 g = gcd128(p, q);
    return (i128)r.num() == p / g && (i128)r.den() == q / g;
}

template <typename T>
bool test(std::mt19937_64& rng, long long range) {
    bool ok = true;
    auto rnd = [&](bool nonzero) {
        while (true) {
            long long x = (long long)(rng() % (2 * range + 1)) - range;
            if (!nonzero || x != 0) return x;
        }
    };
    for (int rep = 0; rep < 100000 && ok; rep++) {
        long long a = rnd(false), b = rnd(true), c = rnd(false), d = rnd(true);
        Rational<T> x(a, b), y(c, d);
        ok = ok && same(x, a, b) && x.den() > 0;
        ok = ok && same(x + y, (i128)a * d + (i128)c * b, (i128)b * d);
        ok = ok && same(x - y, (i128)a * d - (i128)c * b, (i128)b * d);
        ok = ok && same(x * y, (i128)a * c, (i128)b * d);
        if (c != 0) ok = ok && same(x / y, (i128)a * d, (i128)b * c);
        // 比較
        int sgn = (b > 0) == (d > 0) ? 1 : -1;
        i128 l = (i128)a * d * sgn, r = (i128)c * b * sgn;
        ok = ok && (x < y) == (l < r) && (x == y) == (l == r) && (x <= y) == (l <= r) && (x > y) == (l > r);
        // floor, ceil
        long long fl = a / b, rem = a % b;
        if (rem != 0 && ((rem < 0) != (b < 0))) fl--;
        ok = ok && (long long)x.floor() == fl && (long long)x.ceil() == fl + (rem != 0);
        ok = ok && x.is_integer() == (rem == 0);
        // 文字列にして読み直す
        std::stringstream ss;
        ss << x;
        Rational<T> z;
        ss >> z;
        ok = ok && z == x;
    }
    return ok;
}

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    ok = ok && test<long long>(rng, 20);
    ok = ok && test<long long>(rng, 1000000000);
    ok = ok && test<int>(rng, 30000);
    ok = ok && test<__int128>(rng, 20);
    ok = ok && test<__int128>(rng, 1000000000000000000LL);

    // __int128 で、通分すると 128 bit に収まらない値どうしの比較 (連分数展開で比べる)
    {
        using R = Rational<__int128>;
        i128 big = (i128)1 << 100;
        R x(big + 1, big), y(big + 2, big + 1);  // 1 + 1/big > 1 + 1/(big+1)
        ok = ok && y < x && !(x < y) && x != y && R(big, 3) > R(big - 1, 3);
        ok = ok && R(-big, big + 1) < R(-big + 1, big) && R(-(big + 1), 7).floor() == -(big + 1) / 7 - 1;
    }

    // 例
    using Q = Rational<>;
    ok = ok && Q(1, 3) + Q(1, 6) == Q(1, 2) && Q(2, -4) == Q(-1, 2) && Q(0, -5) == Q(0);
    ok = ok && Q(3, 2) * 2 == 3 && 1 < Q(3, 2) && Q(-7, 2).floor() == -4 && Q(-7, 2).ceil() == -3;
    ok = ok && Q(-3, 4).inv() == Q(-4, 3) && Q(-3, 4).abs() == Q(3, 4) && -Q(1, 2) == Q(-1, 2);
    ok = ok && Q(1, 3).to_string() == "1/3" && Q(-6, 3).to_string() == "-2" && Q(1, 4).to_double() == 0.25;
    // map や set のキーにできる (傾きを数える)
    std::set<Q> slopes = {Q(1, 2), Q(2, 4), Q(-1, 3), Q(3, -9)};
    ok = ok && slopes.size() == 2 && *slopes.begin() == Q(-1, 3);
    std::map<Q, int> mp;
    mp[Q(2, 6)]++, mp[Q(1, 3)]++;
    ok = ok && mp[Q(1, 3)] == 2;
    // 入力の形式
    std::stringstream ss("3/6 -4 +5/-10");
    Q a, b, c;
    ss >> a >> b >> c;
    ok = ok && a == Q(1, 2) && b == Q(-4) && c == Q(-1, 2);

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
