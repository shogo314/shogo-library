#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// gaussian-integer.hpp を愚直な方法と比べる
// gaussian_gcd: 両方を割り切るガウス整数をすべて試して、ノルムが最大のものとノルムを比べ、両方を割り切ることも確かめる
// two_square_sum: a をすべて試したものと比べる。大きい n では、返した組がすべて解で、重複しないことを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/gaussian-integer.hpp"

#include <iostream>
#include <random>
#include <utility>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    using G = GaussianInteger<long long>;
    auto divides = [](const G& d, const G& x) { return d.norm() == 0 ? x == G(0) : x % d == G(0); };
    for (int rep = 0; rep < 3000 && ok; rep++) {
        G x(static_cast<long long>(rng() % 13) - 6, static_cast<long long>(rng() % 13) - 6);
        G y(static_cast<long long>(rng() % 13) - 6, static_cast<long long>(rng() % 13) - 6);
        long long best = 0;
        for (long long a = -12; a <= 12; a++)
            for (long long b = -12; b <= 12; b++) {
                G d(a, b);
                if (d.norm() == 0) continue;
                if (divides(d, x) && divides(d, y)) best = std::max(best, d.norm());
            }
        G g = gaussian_gcd(x, y);
        if (x == G(0) && y == G(0)) {
            if (g != G(0)) ok = false;
            continue;
        }
        if (g.norm() != best || !divides(g, x) || !divides(g, y)) ok = false;
    }
    // 割り算の余りのノルムは割る数のノルムの半分以下
    for (int rep = 0; rep < 3000 && ok; rep++) {
        G x(static_cast<long long>(rng() % 2001) - 1000, static_cast<long long>(rng() % 2001) - 1000);
        G y(static_cast<long long>(rng() % 201) - 100, static_cast<long long>(rng() % 201) - 100);
        if (y.norm() == 0) continue;
        G q = x / y, r = x % y;
        if (q * y + r != x || 2 * r.norm() > y.norm()) ok = false;
    }

    for (long long n = 0; n <= 3000 && ok; n++) {
        std::vector<std::pair<long long, long long>> expect;
        for (long long a = 0; a * a <= n; a++) {
            long long b = 0;
            while (b * b < n - a * a) b++;
            if (a * a + b * b == n) expect.emplace_back(a, b);
        }
        if (two_square_sum(n) != expect) ok = false;
    }
    for (long long n : {1000000000000000000LL, 999999999999999989LL, 5LL * 5 * 13 * 13 * 17 * 29 * 37 * 41 * 53 * 61 * 73 * 89, 2LL * 3 * 3 * 7 * 7 * 5 * 1000000007LL}) {
        auto res = two_square_sum(n);
        for (size_t i = 0; i < res.size(); i++) {
            auto [a, b] = res[i];
            if (static_cast<__int128>(a) * a + static_cast<__int128>(b) * b != n) ok = false;
            if (i > 0 && !(res[i - 1] < res[i])) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
