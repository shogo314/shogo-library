#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// FPS の単項の -、定数を引く -、eval、gcd、modpow、divmod を愚直な多項式演算と比較する
// sqrt は 2 乗して元に戻るか、polynomial_product は順に掛けたものと比べる
// sum_of_fractions は、分子が Σ_i nums_i Π_{j != i} dens_j、分母が Π dens_j になることを確かめる
// FPS の + と - は結果の末尾の 0 を取り除く (仕様) ので、多項式としての比較は末尾の 0 を除いて行う
// inv・exp は法が NTT に向くと NTT した値を使い回す別の経路に入るので、同じ法の dynamic_modint (この経路に入らない) と比べ、
// inv は f g が先頭 deg 項で 1 になることも確かめる (log・pow・sqrt もこの経路を通る)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/fps.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

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
    for (auto& x : a) x = static_cast<long long>(rng() % 998244353);
    if (rng() % 4 == 0)
        for (auto& x : a) x = static_cast<long long>(rng() % 3);  // 0 を多めに含む
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
        mint c = static_cast<long long>(rng() % 998244353);
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
            mint x = (t == 0) ? mint(0) : mint(static_cast<long long>(rng() % 998244353));
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
        long long n = (rep % 3 == 0) ? static_cast<long long>(rng() % 1000000000000LL) : static_cast<long long>(rng() % 20);
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

    // divmod: f = q g + r、deg r < deg g を満たし、f / g、f % g と一致する。NTT を使う長さも含める
    for (int rep = 0; rep < 300 && ok; rep++) {
        int big = (rep % 10 == 0) ? 100 : 0;
        P g = random_poly(rng, rng() % 6 + 1 + big / 2, true);
        P f = random_poly(rng, rng() % 12 + big, false);
        auto [q, r] = divmod(F(f), F(g));
        if (trim(P(r)) != naive_mod(f, g)) ok = false, std::cerr << "divmod r " << rep << std::endl;
        if (trim(naive_mul(P(q), g)) != trim(P(F(f) - F(r)))) ok = false, std::cerr << "divmod q " << rep << std::endl;
        if (trim(P(q)) != trim(P(F(f) / F(g))) || trim(P(r)) != trim(P(F(f) % F(g)))) ok = false;
    }
    // 次数が g より小さければ商は 0、余りは f (末尾の 0 を除く)
    {
        auto [q, r] = divmod(F(P{1, 2, 0}), F(P{3, 4, 5}));
        if (!trim(P(q)).empty() || P(r) != P{1, 2}) ok = false;
        auto [q0, r0] = divmod(F(), F(P{3, 4}));
        if (!trim(P(q0)).empty() || !trim(P(r0)).empty()) ok = false;
    }

    // sqrt: 平方根があるなら g^2 が先頭 n 項で f と一致し、ないなら nullopt (x^奇数 から始まる、平方非剰余)
    {
        auto gen = [&](int n) {
            F f(n);
            for (auto& x : f) x = rng() % mint::mod();
            return f;
        };
        for (int rep = 0; rep < 300 && ok; rep++) {
            int n = rng() % 30 + 1, shift = rng() % 4;
            // h^2 を作ってから x^(2 shift) を掛けると、必ず平方根がある
            F h = gen(n);
            F f = (h * h).pre(n);
            f = (f << (2 * shift)).pre(n);
            auto g = sqrt(f, n);
            if (!g || static_cast<int>(g->size()) != n || P((*g * *g).pre(n)) != P(f)) ok = false, std::cerr << "sqrt" << std::endl;
            // x^1 から始まるなら平方根はない
            F odd = f;
            odd.insert(odd.begin(), mint(0));
            odd.resize(n + 1);
            if (odd[1] != 0 && sqrt(odd, n + 1)) ok = false, std::cerr << "sqrt odd" << std::endl;
        }
        // 定数項が平方非剰余なら平方根はない (998244353 では 3 が非剰余)
        if (sqrt(F{3, 1, 4}, 3)) ok = false, std::cerr << "sqrt non-residue" << std::endl;
        // すべて 0 なら 0
        auto z = sqrt(F(5, 0), 5);
        if (!z || P(*z) != P(5, 0)) ok = false, std::cerr << "sqrt zero" << std::endl;
        auto ze = sqrt(F(), 3);
        if (!ze || P(*ze) != P(3, 0)) ok = false, std::cerr << "sqrt empty" << std::endl;
        // 平方根がないかどうかは deg によらない (x^3 や 3 x^4 は deg が小さくても nullopt)
        for (int deg = 0; deg <= 3; deg++) {
            if (sqrt(F{0, 0, 0, 1}, deg)) ok = false, std::cerr << "sqrt x^3 " << deg << std::endl;
            if (sqrt(F{0, 0, 0, 0, 3}, deg)) ok = false, std::cerr << "sqrt 3x^4 " << deg << std::endl;
        }
        // 平方根があり、先頭 deg 項が 0 だけのとき (x^4 の平方根 x^2)
        auto x4 = sqrt(F{0, 0, 0, 0, 1}, 2);
        if (!x4 || P(*x4) != P(2, 0)) ok = false, std::cerr << "sqrt x^4 short" << std::endl;
        x4 = sqrt(F{0, 0, 0, 0, 1}, 4);
        if (!x4 || P(*x4) != P{0, 0, 1, 0}) ok = false, std::cerr << "sqrt x^4" << std::endl;
    }
    // deg を負にすると f.size() (inv・log・exp・pow・sqrt)
    {
        F f{4, 3, 2, 1, 5};
        if (P(inv(f, -1)) != P(inv(f, 5))) ok = false, std::cerr << "inv deg -1" << std::endl;
        F l{1, 3, 2, 1, 5};
        if (P(log(l, -1)) != P(log(l, 5)) || P(log(l)) != P(log(l, 5))) ok = false, std::cerr << "log deg -1" << std::endl;
        F e{0, 3, 2, 1, 5};
        if (P(exp(e, -1)) != P(exp(e, 5)) || P(exp(e)) != P(exp(e, 5))) ok = false, std::cerr << "exp deg -1" << std::endl;
        if (P(pow(f, 3, -1)) != P(pow(f, 3, 5)) || P(pow(f, 0, -1)) != P(pow(f, 0, 5)) || P(pow(f, 3)) != P(pow(f, 3, 5))) ok = false, std::cerr << "pow deg -1" << std::endl;
        auto sq = sqrt(f, -1), sq5 = sqrt(f, 5);
        if (!sq || !sq5 || P(*sq) != P(*sq5) || sq->size() != 5) ok = false, std::cerr << "sqrt deg -1" << std::endl;
    }
    // polynomial_product: 順に掛けたものと同じ (空の列は 1、0 を含むと 0)
    for (int rep = 0; rep < 300 && ok; rep++) {
        int k = rng() % 8;
        std::vector<F> fs(k);
        P expect = {1};
        for (auto& f : fs) {
            f.resize(rng() % 5);
            for (auto& x : f) x = rng() % 10;
            expect = naive_mul(expect, P(f));
        }
        if (trim(P(polynomial_product(fs))) != trim(expect)) ok = false, std::cerr << "polynomial_product" << std::endl;
    }

    // sum_of_fractions (空の列は 0 / 1)
    {
        auto [num, den] = sum_of_fractions(std::vector<F>{}, std::vector<F>{});
        if (!trim(P(num)).empty() || trim(P(den)) != P{1}) ok = false, std::cerr << "sum_of_fractions empty" << std::endl;
    }
    for (int rep = 0; rep < 300 && ok; rep++) {
        int k = rng() % 8 + 1;
        std::vector<F> nums(k), dens(k);
        for (int i = 0; i < k; i++) {
            nums[i].resize(rng() % 4);
            for (auto& x : nums[i]) x = rng() % 10;
            dens[i].resize(rng() % 4 + 1);
            for (auto& x : dens[i]) x = rng() % 10;
            dens[i].back() = rng() % 9 + 1;
        }
        P expect_num = {}, expect_den = {1};
        for (int i = 0; i < k; i++) {
            P t = P(nums[i]);
            for (int j = 0; j < k; j++)
                if (j != i) t = naive_mul(t, P(dens[j]));
            if (expect_num.size() < t.size()) expect_num.resize(t.size());
            for (int a = 0; a < static_cast<int>(t.size()); a++) expect_num[a] += t[a];
            expect_den = naive_mul(expect_den, P(dens[i]));
        }
        auto [num, den] = sum_of_fractions(nums, dens);
        if (trim(P(num)) != trim(expect_num) || trim(P(den)) != trim(expect_den)) ok = false, std::cerr << "sum_of_fractions" << std::endl;
    }

    // inv・exp・log・pow・sqrt: NTT の経路 (static_modint) と、畳み込みを繰り返す経路 (dynamic_modint) が同じ結果になる
    {
        using dm = dynamic_modint<0>;
        dm::set_mod(998244353);
        using FD = FPS<dm>;
        auto to_dm = [](const F& f) {
            FD g(f.size());
            for (size_t i = 0; i < f.size(); i++) g[i] = f[i].val();
            return g;
        };
        auto same = [](const F& a, const FD& b) {
            if (a.size() != b.size()) return false;
            for (size_t i = 0; i < a.size(); i++)
                if (a[i].val() != b[i].val()) return false;
            return true;
        };
        std::vector<int> degs = {1, 2, 3, 4, 5, 7, 8, 9, 15, 16, 17, 31, 32, 33, 63, 64, 65, 127, 128, 129, 500, 1024, 1025};
        for (int deg : degs) {
            for (int rep = 0; rep < 3 && ok; rep++) {
                // f の長さは deg より短い・同じ・長いのどれも試す
                int n = std::max(1, deg + static_cast<int>(rng() % 5) - 2);
                if (rep == 0) n = std::max(1, deg / 3);
                F f(n);
                for (auto& x : f) x = rng() % mint::mod();
                if (f[0] == 0) f[0] = 1;
                F g = inv(f, deg);
                if (!same(g, inv(to_dm(f), deg))) ok = false, std::cerr << "inv ntt " << deg << std::endl;
                F one = (f * g).pre(deg);
                for (int i = 0; i < deg; i++)
                    if (one[i] != (i == 0 ? 1 : 0)) ok = false, std::cerr << "inv f g " << deg << std::endl;
                F e = f;
                e[0] = 0;
                if (!same(exp(e, deg), exp(to_dm(e), deg))) ok = false, std::cerr << "exp ntt " << deg << std::endl;
                F l = f;
                l[0] = 1;
                if (!same(log(l, deg), log(to_dm(l), deg))) ok = false, std::cerr << "log ntt " << deg << std::endl;
                long long k = rng() % 1000000;
                if (!same(pow(f, k, deg), pow(to_dm(f), k, deg))) ok = false, std::cerr << "pow ntt " << deg << std::endl;
                F sq2 = (f * f).pre(deg);
                sq2.resize(deg);
                auto sq = sqrt(sq2, deg);
                F back = sq ? (*sq * *sq).pre(deg) : F();
                back.resize(deg);
                if (!sq || P(back) != P(sq2)) ok = false, std::cerr << "sqrt ntt " << deg << std::endl;
            }
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
