#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// prime_count・prime_count_table・PrimeSumTable を、篩で数えた値と比べる
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

    if (ok) std::cout << "Hello World" << std::endl;
}
