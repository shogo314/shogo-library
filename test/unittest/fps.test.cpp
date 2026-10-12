#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// FPS の単項の -、定数を引く -、eval、gcd、modpow を愚直な多項式演算と比較する
// FPS の + と - は結果の末尾の 0 を取り除く (仕様) ので、多項式としての比較は末尾の 0 を除いて行う
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>
#include <vector>

#include "../../src/math/fps.hpp"

using mint = static_modint<998244353>;
using F = FPS<mint>;
using P = std::vector<mint>;

P trim(P a) {
    while (!a.empty() && a.back() == 0) a.pop_back();
    return a;
}
P naive_mul(const P& a, const P& b) {
    if (a.empty() || b.empty()) return {};
    P c(a.size() + b.size() - 1);
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b.size(); j++) c[i + j] += a[i] * b[j];
    return c;
}
// 多項式の余り (b は末尾が 0 でないこと)
P naive_mod(P a, const P& b) {
    a = trim(a);
    while (a.size() >= b.size()) {
        mint c = a.back() / b.back();
        size_t s = a.size() - b.size();
        for (size_t i = 0; i < b.size(); i++) a[s + i] -= c * b[i];
        a = trim(a);
    }
    return a;
}
// 最高次の係数を 1 にする
P monic(P a) {
    a = trim(a);
    if (a.empty()) return a;
    mint c = a.back().inv();
    for (auto& x : a) x *= c;
    return a;
}
P naive_gcd(P a, P b) {
    a = trim(a), b = trim(b);
    while (!b.empty()) {
        P r = naive_mod(a, b);
        a = b;
        b = r;
    }
    return monic(a);
}
P random_poly(std::mt19937_64& rng, int n, bool nonzero_lead) {
    P a(n);
    for (auto& x : a) x = (long long)(rng() % 998244353);
    if (rng() % 4 == 0)
        for (auto& x : a) x = (long long)(rng() % 3);  // 0 を多めに含む
    if (nonzero_lead && n > 0 && a.back() == 0) a.back() = 1;
    return a;
}

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    for (int rep = 0; rep < 300; rep++) {
        int n = rng() % 8;
        P a = random_poly(rng, n, false);
        F f(a);
        // 単項の -: 各係数の符号を反転し、長さは変わらない
        F g = -f;
        if (g.size() != a.size()) ok = false;
        for (size_t i = 0; i < a.size(); i++)
            if (g[i] != -a[i]) ok = false;
        // 定数を引く: 定数項から引く (空なら長さ 1 になる)。長さはそれ以外変わらない
        mint c = (long long)(rng() % 998244353);
        F h = f - c;
        P e = a.empty() ? P{-c} : a;
        if (!a.empty()) e[0] -= c;
        if (P(h) != e) ok = false;
        F h2 = f;
        h2 -= c;
        if (P(h2) != e) ok = false;
        // 定数を足すのと打ち消し合う
        if (P(f - c + c) != (a.empty() ? P{0} : a)) ok = false;
        // eval: f(x) を愚直に計算したものと一致する
        for (int t = 0; t < 5; t++) {
            mint x = (t == 0) ? mint(0) : mint((long long)(rng() % 998244353));
            mint s = 0, pw = 1;
            for (auto& coef : a) s += coef * pw, pw *= x;
            if (f.eval(x) != s) ok = false;
        }
    }
    if (!ok) std::cerr << "unary minus / minus const / eval" << std::endl;

    // gcd: 共通因子 h を掛けた 2 つの多項式の gcd が h の定数倍になる。NTT を使う長さも含める
    for (int rep = 0; rep < 150 && ok; rep++) {
        int big = (rep % 5 == 0) ? 40 : 0;
        P h = random_poly(rng, rng() % 5 + 1 + big / 4, true);
        P x = random_poly(rng, rng() % 6 + 1 + big, true);
        P y = random_poly(rng, rng() % 6 + 1 + big, true);
        P a = trim(naive_mul(h, x)), b = trim(naive_mul(h, y));
        F d = gcd(F(a), F(b));
        if (monic(P(d)) != naive_gcd(a, b)) ok = false, std::cerr << "gcd " << rep << std::endl;
        // 引数の順を入れ替えても同じ (定数倍を除いて)
        if (monic(P(gcd(F(b), F(a)))) != naive_gcd(a, b)) ok = false;
        // 割り切る
        if (!trim(P(F(a) % d)).empty() || !trim(P(F(b) % d)).empty()) ok = false;
    }
    // 片方が 0 (空) なら、もう片方を返す
    {
        P a = {1, 2, 3};
        if (monic(P(gcd(F(a), F()))) != monic(a)) ok = false;
        if (monic(P(gcd(F(), F(a)))) != monic(a)) ok = false;
    }

    // modpow: f^n mod m を、愚直に掛けて余りを取ったものと比べる
    for (int rep = 0; rep < 200 && ok; rep++) {
        int deg_m = rng() % 6 + 1;  // m の次数は 1 以上
        if (rep % 10 == 0) deg_m = 40;
        P m = random_poly(rng, deg_m + 1, true);
        P f = random_poly(rng, rng() % 8, false);
        long long n = (rep % 3 == 0) ? (long long)(rng() % 1000000000000LL) : (long long)(rng() % 20);
        F got = modpow(F(f), n, F(m));
        // 愚直: 繰り返し二乗法を愚直な掛け算と余りで行う
        P res = naive_mod(P{1}, m), base = naive_mod(f, m);
        for (long long k = n; k > 0; k >>= 1) {
            if (k & 1) res = naive_mod(naive_mul(res, base), m);
            base = naive_mod(naive_mul(base, base), m);
        }
        if (trim(P(got)) != trim(res)) ok = false, std::cerr << "modpow " << rep << std::endl;
    }
    // n = 0 は 1
    if (P(modpow(F(P{5, 6}), 0, F(P{1, 1, 1}))) != P{1}) ok = false;

    if (ok) std::cout << "Hello World" << std::endl;
}
