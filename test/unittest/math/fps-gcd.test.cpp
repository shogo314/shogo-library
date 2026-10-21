#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// gcd・extgcd (Half-GCD) を確かめる。gcd は最高次の係数が 1 で、素朴な互除法と一致すること
// extgcd は a f + b g = d、d の最高次の係数が 1、d が f と g を割り切ることを確かめ、d を素朴な gcd と比べる
// modinv は f h ≡ 1 (mod g) と次数を確かめ、std::nullopt になるのは gcd が定数でないときだけかを見る
// 共通因子を持つ f, g も作る。問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>

#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

template <typename mint>
FPS<mint> monic(FPS<mint> f) {
    f.normalize();
    if (!f.empty()) f /= f.back();
    return f;
}

template <typename mint>
FPS<mint> naive_gcd(FPS<mint> f, FPS<mint> g) {
    f.normalize(), g.normalize();
    while (!g.empty()) {
        FPS<mint> r = f % g;
        r.normalize();
        f = g, g = r;
    }
    return monic(f);
}

template <typename mint>
void test(std::mt19937_64& rng) {
    using F = FPS<mint>;
    auto gen = [&] { return mint(rng() % mint::mod()); };
    auto random_poly = [&](int n) {
        F f(n);
        for (auto& x : f) x = rng() % 5 == 0 ? mint(0) : gen();
        return f.normalize();
    };
    for (int rep = 0; rep < 400 && ok; rep++) {
        const int lim = rep < 300 ? 8 : 300;
        F f = random_poly(rng() % lim), g = random_poly(rng() % lim);
        if (rng() % 2) {
            // 共通因子を掛ける
            F c = random_poly(1 + rng() % (rep < 300 ? 4 : 100));
            f = (f * c).normalize(), g = (g * c).normalize();
        }
        F a, b;
        F d = extgcd(f, g, a, b);
        check(F(a * f + b * g).normalize() == d, "extgcd: a f + b g = d");
        check(d == naive_gcd(f, g), "extgcd: d と素朴な gcd");
        check(gcd(f, g) == d && gcd(g, f) == d, "gcd");
        if (!d.empty()) {
            check(d.back() == 1, "extgcd: d の最高次の係数");
            check(F(f % d).normalize().empty() && F(g % d).normalize().empty(), "extgcd: d が f と g を割り切る");
        }
        if (g.empty()) continue;
        auto h = modinv(f, g);
        bool exists = g.size() == 1 || d.size() == 1;
        check(h.has_value() == exists, "modinv: 存在の判定");
        if (h && g.size() > 1) {
            check(h->size() < g.size(), "modinv: 次数");
            check(F(*h * f % g).normalize() == F{1}, "modinv: f h ≡ 1");
        }
        if (h && g.size() == 1) check(h->empty(), "modinv: g が定数");
    }
}

int main() {
    std::mt19937_64 rng(314);
    test<modint998244353>(rng);
    test<modint1000000007>(rng);
    if (!ok) return 1;
    std::cout << "Hello World" << std::endl;
}
