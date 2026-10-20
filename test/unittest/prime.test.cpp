#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// prime.hpp の関数と Sieve を愚直な実装とランダムに比較する
// primitive_root は、位数を愚直に数えて最小の原始根を求めたものと比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/math/prime.hpp"

#include <iostream>
#include <numeric>
#include <random>
#include <utility>
#include <vector>

// constexpr で使えること
static_assert(is_prime(998244353));
static_assert(!is_prime(1));
static_assert(!is_prime(561));  // カーマイケル数

bool naive_is_prime(long long n) {
    if (n < 2) return false;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) return false;
    }
    return true;
}

std::vector<long long> naive_divisors(long long n) {
    std::vector<long long> res;
    for (long long d = 1; d <= n; d++) {
        if (n % d == 0) res.push_back(d);
    }
    return res;
}

long long naive_gcd(long long a, long long b) { return b == 0 ? a : naive_gcd(b, a % b); }

// factorize(n) の結果が、昇順の素数で、掛けると n になるか
bool check_factorize(long long n) {
    auto f = factorize(n);
    __int128 prod = 1;
    for (std::size_t i = 0; i < f.size(); i++) {
        auto [p, e] = f[i];
        if (e <= 0 || !is_prime(p)) return false;
        if (i > 0 && f[i - 1].first >= p) return false;
        for (int j = 0; j < e; j++) prod *= p;
    }
    return prod == n;
}

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    // 小さい数はすべて愚直と比べる
    const int N = 3000;
    Sieve sv(N);
    std::vector<long long> naive_primes;
    for (int n = 0; n <= N; n++) {
        bool p = naive_is_prime(n);
        if (p) naive_primes.push_back(n);
        ok = ok && is_prime(n) == p && sv.is_prime(n) == p;
        ok = ok && enumerate_primes(n) == naive_primes;
        if (n == 0) continue;
        auto d = naive_divisors(n);
        ok = ok && divisors(n) == d;
        auto sd = sv.divisors(n);
        ok = ok && std::vector<long long>(sd.begin(), sd.end()) == d;
        long long phi = 0;
        for (int k = 1; k <= n; k++) phi += naive_gcd(k, n) == 1;
        ok = ok && totient(n) == phi;
        ok = ok && check_factorize(n);
        auto f1 = factorize(n);
        auto f2 = sv.factorize(n);
        ok = ok && f1.size() == f2.size();
        for (std::size_t i = 0; ok && i < f1.size(); i++) ok = ok && f1[i].first == f2[i].first && f1[i].second == f2[i].second;
        if (n >= 2) ok = ok && sv.min_factor(n) == f1[0].first;
    }
    ok = ok && sv.primes() == naive_primes && sv.limit() == N;

    // 大きい素数と、Miller-Rabin を間違えやすい合成数
    for (long long p : {1000000007LL, 998244353LL, 2305843009213693951LL, 999999999999999989LL, 4611686018427387847LL}) {
        ok = ok && is_prime(p) && check_factorize(p) && factorize(p).size() == 1;
    }
    // 3215031751 と 3825123056546413051 は、小さい底での強擬素数
    for (long long c : std::vector<long long>{3215031751LL, 3825123056546413051LL, 1000000007LL * 998244353LL,
                                              999999937LL * 999999937LL, 4LL, 1LL << 62}) {
        ok = ok && !is_prime(c) && check_factorize(c);
    }

    // 大きい数の素因数分解
    for (int rep = 0; rep < 300; rep++) {
        long long n = rng() % 1000000000000000000LL + 1;
        ok = ok && check_factorize(n);
        // 2 つの大きい素数の積
        long long p = rng() % 1000000000 + 1, q = rng() % 1000000000 + 1;
        while (!is_prime(p)) p++;
        while (!is_prime(q)) q++;
        auto f = factorize(p * q);
        ok = ok && check_factorize(p * q) && (p == q ? f.size() == 1 && f[0].second == 2 : f.size() == 2);
        ok = ok && divisors(p * q).size() == (p == q ? 3u : 4u);
    }

    // primitive_root: m <= 2000 で、g = 1, 2, ... の位数を数えて最初に φ(m) になるもの (なければ -1)
    for (long long m = 1; m <= 2000 && ok; m++) {
        long long phi = 0;
        for (long long x = 1; x <= m; x++) phi += std::gcd(x, m) == 1;
        long long expect = m == 1 ? 0 : -1;
        for (long long g = 1; g < m && expect == -1; g++) {
            if (std::gcd(g, m) != 1) continue;
            long long order = 1, cur = g % m;
            while (cur != 1 % m) cur = cur * g % m, order++;
            if (order == phi) expect = g;
        }
        if (primitive_root(m) != expect) ok = false, std::cerr << "primitive_root " << m << std::endl;
    }
    // 大きい素数: 返した g が原始根 (p - 1 のどの素因数 q でも g^((p-1)/q) != 1) で、それより小さい数は原始根でない
    for (long long p : {998244353LL, 1000000007LL, 167772161LL, (1LL << 61) - 1, 999999999999999989LL}) {
        long long g = primitive_root(p);
        auto is_root = [&](long long h) {
            for (auto [q, e] : factorize(p - 1))
                if (modpow(h, (p - 1) / q, p) == 1) return false;
            return true;
        };
        ok = ok && g >= 2 && is_root(g);
        for (long long h = 2; h < g; h++) ok = ok && !is_root(h);
    }
    if (primitive_root(998244353) != 3) ok = false;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
