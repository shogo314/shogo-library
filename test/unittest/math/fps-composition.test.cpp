#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// composition を素朴な計算と比べ、compositional_inverse は f(h) = x と h(f) = x を確かめる
// composition は、f が短いときの Horner 法と、g が x^v から始まるときに f を切り詰める場合も調べる
// 法は 998244353 と 1000000007 (NTT が使えない法) の両方で試す
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/fps-composition.hpp"

#include <iostream>
#include <random>

#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

// f(g) の x^deg 未満を Horner 法で O(|f| deg^2) で求める
template <typename mint>
FPS<mint> naive_composition(const FPS<mint>& f, const FPS<mint>& g, int deg) {
    FPS<mint> res(deg, 0);
    if (deg == 0) return res;
    for (int i = static_cast<int>(f.size()) - 1; i >= 0; i--) {
        FPS<mint> nx(deg, 0);
        for (int a = 0; a < deg; a++) {
            if (res[a] == 0) continue;
            for (int b = 0; a + b < deg && b < static_cast<int>(g.size()); b++) nx[a + b] += res[a] * g[b];
        }
        nx[0] += f[i];
        res = nx;
    }
    return res;
}

template <typename mint>
void test(std::mt19937_64& rng) {
    using F = FPS<mint>;
    auto gen = [&] { return mint(rng() % mint::mod()); };
    // composition: g の定数項は 0 でなくてもよい。f が空、deg が 0 の場合も
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % (rep < 200 ? 8 : 80), m = rng() % (rep < 200 ? 8 : 80), deg = rng() % (rep < 200 ? 8 : 80);
        F f(n), g(m);
        for (auto& x : f) x = gen();
        for (auto& x : g) x = rng() % 4 == 0 ? mint(0) : gen();
        if (rng() % 2 && m > 0) g[0] = 0;
        F res = composition(f, g, deg);
        check(res == naive_composition(f, g, deg), "composition");
    }
    {
        F f = {1, 2, 3}, g = {0, 1, 1};
        check(composition(f, g) == naive_composition(f, g, 3), "composition の deg の省略");
    }
    // g が x^v (v >= 1) から始まる。f の長さは Horner 法 (32 以下) と Kinoshita–Li の両方を通る
    for (int rep = 0; rep < 200 && ok; rep++) {
        int n = rng() % 120, v = rng() % 6 + 1, deg = rng() % 80, m = v + 1 + rng() % 40;
        F f(n), g(m, 0);
        for (auto& x : f) x = gen();
        for (int i = v; i < m; i++) g[i] = gen();
        if (rng() % 2) g[v] = gen() + 1;  // 最低次の係数は 0 でないことが多い
        check(composition(f, g, deg) == naive_composition(f, g, deg), "composition: g が x^v から始まる");
    }
    // compositional_inverse: f(h) = x と h(f) = x
    for (int rep = 0; rep < 200 && ok; rep++) {
        int n = 2 + rng() % (rep < 150 ? 10 : 300), deg = rng() % (rep < 150 ? 12 : 300);
        F f(n);
        for (auto& x : f) x = gen();
        f[0] = 0;
        while (f[1] == 0) f[1] = gen();
        F h = compositional_inverse(f, deg);
        check(static_cast<int>(h.size()) == deg, "compositional_inverse の長さ");
        F x(deg, 0);
        if (deg > 1) x[1] = 1;
        check(composition(f, h, deg) == x, "compositional_inverse: f(h) = x");
        check(composition(h, f, deg) == x, "compositional_inverse: h(f) = x");
    }
    {
        // x / (1 - x) の逆関数は x / (1 + x)
        F f = {0, 1, 1, 1, 1, 1};
        check(compositional_inverse(f) == F({0, 1, -1, 1, -1, 1}), "compositional_inverse: x / (1 - x)");
    }
}

int main() {
    std::mt19937_64 rng(314);
    test<modint998244353>(rng);
    test<modint1000000007>(rng);
    if (!ok) return 1;
    std::cout << "Hello World" << std::endl;
}
