#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// modmul・modpow・modinv・discrete_log・sqrt_mod を愚直な計算と比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/modular-arithmetic.hpp"

#include <algorithm>
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
        if (modmul(a, b, P) != static_cast<long long>(static_cast<__int128>(a) * b % P)) ok = false, std::cerr << "mul " << a << std::endl;
    }

    // discrete_log: 小さい法で、x を 0 から順に試して最小のものと比べる (a と m が互いに素でない場合も)
    for (long long m = 1; m <= 40; m++) {
        for (long long a = -3; a < m; a++) {
            for (long long b = -3; b < m; b++) {
                long long r = ((a % m) + m) % m, t = ((b % m) + m) % m, cur = 1 % m, expect = -1;
                // a^x mod m は 2m 回以内に周期に入るので、それまで試せば十分
                for (long long x = 0; x <= 2 * m; x++, cur = cur * r % m) {
                    if (cur == t) {
                        expect = x;
                        break;
                    }
                }
                if (discrete_log(a, b, m) != expect) ok = false, std::cerr << "discrete_log " << a << " " << b << " " << m << std::endl;
            }
        }
    }
    // 大きい法: 答えを作ってから解き、a^x ≡ b となり、作った値以下であることを確かめる
    for (int rep = 0; rep < 200; rep++) {
        long long m = rng() % 1000000000 + 1, a = rng() % m, x = rng() % 1000000;
        long long b = modpow(a, x, m), y = discrete_log(a, b, m);
        if (!(0 <= y && y <= x && modpow(a, y, m) == b)) ok = false, std::cerr << "discrete_log big " << a << " " << m << std::endl;
    }

    // sqrt_mod: 小さい素数で、全ての x を試して平方根があるかと最小の根を比べる
    for (long long p = 2; p <= 300; p++) {
        bool prime = true;
        for (long long d = 2; d * d <= p; d++) prime &= p % d != 0;
        if (!prime) continue;
        for (long long a = -2; a < p; a++) {
            long long r = ((a % p) + p) % p, expect = -1;
            for (long long x = 0; x < p; x++) {
                if (x * x % p == r) {
                    expect = x;
                    break;
                }
            }
            if (sqrt_mod(a, p) != expect) ok = false, std::cerr << "sqrt_mod " << a << " " << p << std::endl;
        }
    }
    // 大きい素数 (p - 1 が 2 で何度も割れるものを含む): x^2 から平方根を求めて元に戻る
    for (long long p : {998244353LL, 1000000007LL, (1LL << 61) - 1, 4611686018427387847LL}) {
        for (int rep = 0; rep < 300; rep++) {
            long long x = rng() % p, a = modmul(x, x, p), y = sqrt_mod(a, p);
            if (!(y == std::min(x, p - x) || (x == 0 && y == 0))) ok = false, std::cerr << "sqrt_mod big " << p << std::endl;
        }
        // 平方非剰余なら -1
        long long z = 2;
        while (modpow(z, (p - 1) / 2, p) == 1) z++;
        if (sqrt_mod(z, p) != -1) ok = false, std::cerr << "sqrt_mod non-residue " << p << std::endl;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
