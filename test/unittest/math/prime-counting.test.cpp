#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// prime_count・prime_count_table・PrimeSumTable を、篩で数えた値と比べる
// multiplicative_sum を、篩で求めた乗法的関数 (φ・μ・σ) の和と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/prime-counting.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../../src/math/modint.hpp"
#include "../../../src/math/prime.hpp"
#include "../../../src/math/quotients.hpp"

using mint = static_modint<998244353>;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

int main() {
    const long long N = 10000000;
    Sieve sv(N);
    // cnt[v]: v 以下の素数の個数、sum[v]: v 以下の素数の和、sq[v]: v 以下の素数の 2 乗の和 (mod)
    std::vector<long long> cnt(N + 1, 0);
    std::vector<__int128> sum(N + 1, 0);
    std::vector<mint> sq(N + 1, 0);
    for (long long v = 1; v <= N; v++) {
        bool p = sv.is_prime(v);
        cnt[v] = cnt[v - 1] + p;
        sum[v] = sum[v - 1] + (p ? v : 0);
        sq[v] = sq[v - 1] + (p ? mint(v) * v : mint(0));
    }

    // 小さい n はすべて、表のすべての値まで比べる
    for (long long n = 1; n <= 3000 && ok; n++) {
        check(prime_count(n) == cnt[n], "prime_count 小さい n");
        auto t = prime_count_table(n);
        for (auto [q, l, r] : enumerate_quotients(n)) check(t(q) == cnt[q], "prime_count_table");
        // values() は floor(n / k) のとる値の昇順
        std::vector<long long> qs;
        for (auto [q, l, r] : enumerate_quotients(n)) qs.insert(qs.begin(), q);
        check(t.values() == qs, "values");
    }
    check(prime_count(0) == 0 && prime_count(1) == 0 && prime_count(2) == 1, "prime_count 0, 1, 2");

    // ランダムな n (10^7 まで)。素数の和 (__int128) と 2 乗の和 (mod) も比べる
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 30 && ok; rep++) {
        long long n = rep < 3 ? N - rep : static_cast<long long>(rng() % N) + 1;
        check(prime_count(n) == cnt[n], "prime_count");
        PrimeSumTable<__int128> s(n, [](long long v) { return static_cast<__int128>(v) * (v + 1) / 2 - 1; }, [](long long p) { return static_cast<__int128>(p); });
        PrimeSumTable<mint> s2(
            n, [](long long v) { mint x = v; return x * (x + 1) * (2 * x + 1) / 6 - 1; }, [](long long p) { return mint(p) * p; });
        for (auto [q, l, r] : enumerate_quotients(n)) {
            check(s(q) == sum[q], "PrimeSumTable 素数の和");
            check(s2(q) == sq[q], "PrimeSumTable 素数の 2 乗の和");
        }
    }

    // 大きい n: 既知の値 π(10^k)
    check(prime_count(1000000000LL) == 50847534, "π(10^9)");
    check(prime_count(10000000000LL) == 455052511, "π(10^10)");

    // multiplicative_sum: φ・メビウス関数 μ・約数の和 σ を、篩で求めた値を足したものと比べる
    {
        const int N = 3000;
        // 最小素因数で割っていき、乗法的関数を素因数分解から求める
        std::vector<int> lpf(N + 1, 0);
        for (int i = 2; i <= N; i++)
            if (lpf[i] == 0)
                for (int j = i; j <= N; j += i)
                    if (lpf[j] == 0) lpf[j] = i;
        auto eval = [&](int i, auto f_pe) {
            long long r = 1;
            while (i > 1) {
                int p = lpf[i], e = 0;
                while (i % p == 0) i /= p, e++;
                r *= f_pe(p, e);
            }
            return r;
        };
        auto power = [](long long p, long long e) {
            long long r = 1;
            while (e--) r *= p;
            return r;
        };
        auto phi = [&](long long p, long long e) { return power(p, e) - power(p, e - 1); };
        auto mu = [](long long, long long e) { return e == 1 ? -1LL : 0LL; };
        auto sigma = [&](long long p, long long e) { return (power(p, e + 1) - 1) / (p - 1); };
        for (int n = 0; n <= N && ok; n += (n < 100 ? 1 : 37)) {
            long long e_phi = 0, e_mu = 0, e_sigma = 0;
            for (int i = 1; i <= n; i++) e_phi += eval(i, phi), e_mu += eval(i, mu), e_sigma += eval(i, sigma);
            if (n == 0) {
                check(multiplicative_sum(0, [](long long) { return 0LL; }, phi) == 0, "multiplicative_sum n = 0");
                continue;
            }
            PrimeSumTable<long long> cnt(n, [](long long v) { return v - 1; }, [](long long) { return 1LL; });
            PrimeSumTable<long long> sum(n, [](long long v) { return v * (v + 1) / 2 - 1; }, [](long long p) { return p; });
            check(multiplicative_sum(n, [&](long long v) { return sum(v) - cnt(v); }, phi) == e_phi, "multiplicative_sum φ");
            check(multiplicative_sum(n, [&](long long v) { return -cnt(v); }, mu) == e_mu, "multiplicative_sum μ");
            check(multiplicative_sum(n, [&](long long v) { return sum(v) + cnt(v); }, sigma) == e_sigma, "multiplicative_sum σ");
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
