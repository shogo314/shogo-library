#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// sparse_inv・sparse_log・sparse_exp・sparse_pow を FPS の inv・log・exp・pow と比べ、sparse_sqrt は 2 乗して元に戻るかを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/sparse-fps.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"

using mint = static_modint<998244353>;
using F = FPS<mint>;
using P = std::vector<mint>;

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    // 0 でない項が少ない列 (f_0 は c にする)
    auto sparse = [&](int n, mint c) {
        F f(n, 0);
        if (n > 0) f[0] = c;
        int k = rng() % 4;
        for (int t = 0; t < k && n > 1; t++) f[rng() % (n - 1) + 1] = rng() % mint::mod();
        return f;
    };
    for (int rep = 0; rep < 500 && ok; rep++) {
        int n = rng() % 40 + 1, m = rng() % 40 + 1;
        F a = sparse(n, rng() % (mint::mod() - 1) + 1);
        if (P(sparse_inv(a, m)) != P(inv(a, m))) ok = false, std::cerr << "inv" << std::endl;
        F b = sparse(n, 1);
        if (P(sparse_log(b, m)) != P(log(b, m))) ok = false, std::cerr << "log" << std::endl;
        F c = sparse(n, 0);
        if (P(sparse_exp(c, m)) != P(exp(c, m))) ok = false, std::cerr << "exp" << std::endl;
        // pow: 先頭に 0 が並ぶ場合と、指数が大きい場合も
        F d = sparse(n, rng() % 3 == 0 ? mint(0) : mint(rng() % mint::mod()));
        long long e = rng() % 3 == 0 ? static_cast<long long>(rng() % 1000000000000000000ULL) : static_cast<long long>(rng() % 10);
        if (P(sparse_pow(d, e, m)) != P(pow(d, e, m))) ok = false, std::cerr << "pow " << e << std::endl;
        // sqrt: 平方根があるなら 2 乗して元に戻り、FPS の sqrt と平方根の有無が一致する
        auto s = sparse_sqrt(d, m);
        auto t = sqrt(d, m);
        if (s.has_value() != t.has_value()) ok = false, std::cerr << "sqrt の有無" << std::endl;
        if (s) {
            F dm = d;
            dm.resize(m);
            if (P((*s * *s).pre(m)) != P(dm)) ok = false, std::cerr << "sqrt^2" << std::endl;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
