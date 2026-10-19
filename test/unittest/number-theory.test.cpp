#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// crt (2 通り) を、小さい範囲で解を全探索したものと比較する
// 解がないときに std::nullopt になることも確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/math/number-theory.hpp"

#include <iostream>
#include <numeric>
#include <random>
#include <vector>

int main() {
    bool ok = true;
    std::mt19937 rng(314);
    constexpr long long MOD = 1000000007;
    for (int rep = 0; rep < 20000; rep++) {
        int k = rng() % 4 + 1;
        std::vector<long long> r(k), m(k);
        for (int i = 0; i < k; i++) m[i] = rng() % 12 + 1, r[i] = static_cast<long long>(rng() % 30) - 10;
        long long lcm = 1;
        for (long long x : m) lcm = std::lcm(lcm, x);
        long long best = -1;
        for (long long x = 0; x < lcm && best == -1; x++) {
            bool good = true;
            for (int i = 0; i < k; i++) {
                if (((x - r[i]) % m[i] + m[i]) % m[i] != 0) good = false;
            }
            if (good) best = x;
        }
        auto a = crt(r, m);
        auto b = crt(r, m, MOD);
        if (best == -1) {
            if (a || b) ok = false, std::cerr << "nullopt " << rep << std::endl;
        } else {
            if (!a || a->x != best || a->lcm != lcm) ok = false, std::cerr << "crt " << rep << std::endl;
            if (!b || b->x != best % MOD || b->lcm != lcm % MOD) ok = false, std::cerr << "crt mod " << rep << std::endl;
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
