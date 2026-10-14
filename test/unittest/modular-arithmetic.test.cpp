#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// modmul・modpow・modinv を愚直な計算と比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/math/modular-arithmetic.hpp"

#include <iostream>
#include <numeric>
#include <random>

static_assert(modpow(2, 10, 1000) == 24);
static_assert(modinv(3, 7) == 5);
static_assert(modpow(3, -1, 7) == 5);
static_assert(modpow(5, 0, 1) == 0);

int main() {
    bool ok = true;
    std::mt19937_64 rng(314);

    // 小さい法で愚直に比べる (負の a も)
    for (long long m = 1; m <= 60; m++) {
        for (long long a = -70; a <= 70; a++) {
            long long r = ((a % m) + m) % m;
            long long p = 1 % m;
            for (int n = 0; n <= 20; n++) {
                if (modpow(a, n, m) != p) ok = false, std::cerr << "modpow " << a << " " << n << " " << m << std::endl;
                p = p * r % m;
            }
            for (long long b = -5; b <= 5; b++) {
                if (modmul(a, b, m) != (((a * b) % m) + m) % m) ok = false, std::cerr << "modmul " << a << " " << b << std::endl;
            }
            if (std::gcd(r, m) == 1) {
                long long x = modinv(a, m);
                if (!(0 <= x && x < m && x * r % m == 1 % m)) ok = false, std::cerr << "modinv " << a << " " << m << std::endl;
                if (modpow(a, -3, m) != modpow(x, 3, m)) ok = false, std::cerr << "modpow neg " << a << " " << m << std::endl;
            }
        }
    }

    // 大きい法 (積が long long に収まらない) で、フェルマーの小定理と逆元を確かめる
    const long long P = (1LL << 61) - 1;  // 素数
    for (int rep = 0; rep < 1000; rep++) {
        long long a = rng() % (P - 1) + 1;
        if (modpow(a, P - 1, P) != 1) ok = false, std::cerr << "fermat " << a << std::endl;
        if (modmul(a, modinv(a, P), P) != 1) ok = false, std::cerr << "inv " << a << std::endl;
        long long b = rng() % P;
        if (modmul(a, b, P) != (long long)((__int128)a * b % P)) ok = false, std::cerr << "mul " << a << std::endl;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
