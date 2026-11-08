#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// crt (2 通り) を、小さい範囲で解を全探索したものと比較する
// 解がないときに std::nullopt になることも確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/number-theory.hpp"

#include <iostream>
#include <limits>
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

    // 正規化・逆元との積・Garner の更新が long long の上限をまたぐ場合。
    constexpr long long HI = std::numeric_limits<long long>::max(), LO = std::numeric_limits<long long>::lowest();
    auto check_big = [&](const std::vector<long long>& r, const std::vector<long long>& m, long long x, long long lcm) {
        auto a = crt(r, m);
        if (!a || a->x != x || a->lcm != lcm) ok = false;
        for (long long mod : {1LL, 1000000007LL, HI}) {
            auto b = crt(r, m, mod);
            if (!b || b->x != x % mod || b->lcm != lcm % mod) ok = false;
        }
    };
    check_big({HI - 1}, {HI}, HI - 1, HI);
    check_big({LO}, {HI}, HI - 1, HI);
    check_big({0, 1000000000000000000LL}, {3, 2000000000000000003LL}, 3000000000000000003LL, 6000000000000000009LL);
    check_big({LO, HI}, {3, 5}, 7, 15);
    // LCM 自体は long long に収まらないが、共通の解を作って mod 付き版を検証できる。
    for (int rep = 0; rep < 3000; rep++) {
        long long answer = static_cast<long long>(rng() % 1000000000) * (rng() % 1000000000);
        std::vector<long long> mods = {4000000007LL, 4000000009LL, HI - rep};
        std::vector<long long> residues;
        for (long long mod : mods) residues.push_back(answer % mod);
        auto c = crt(residues, mods, HI - 11);
        __int128 lcm = static_cast<__int128>(mods[0]) * mods[1];
        long long g = std::gcd(static_cast<long long>(lcm % mods[2]), mods[2]);
        // 3 法の積は __int128 に収まる。
        lcm = lcm / g * mods[2];
        if (!c || c->x != answer % (HI - 11) || c->lcm != lcm % (HI - 11)) ok = false;
    }
    {
        long long r1 = LO, m1 = 2, r2 = HI, m2 = 2;
        if (coprimize_simultaneous_congruence_equation(r1, m1, r2, m2) || r1 != LO || r2 != HI || m1 != 2 || m2 != 2) ok = false;
    }

    // MOD = 1 なら x も lcm も 0 (空でも)。空なら x = 0、lcm = 1 % MOD
    for (int k = 0; k <= 2; k++) {
        std::vector<long long> r(k, 1), m(k, 3);
        auto c = crt(r, m, 1);
        if (!c || c->x != 0 || c->lcm != 0) ok = false, std::cerr << "crt MOD = 1, k = " << k << std::endl;
    }
    {
        auto c = crt({}, {}, 7);
        if (!c || c->x != 0 || c->lcm != 1) ok = false, std::cerr << "crt empty" << std::endl;
    }

    if (!ok) return 1;
    std::cout << "Hello World" << std::endl;
}
