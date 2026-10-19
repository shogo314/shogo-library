#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// modint の ++・--・単項の +、合成数の法での逆元、素数判定 (internal_modint::is_prime32) を愚直な計算と比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/math/modint.hpp"

#include <cstdint>
#include <iostream>
#include <random>

bool naive_is_prime(std::uint32_t x) {
    if (x < 2) return false;
    for (std::uint64_t d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    }
    return true;
}

long long naive_inv(long long a, long long m) {
    for (long long x = 1; x < m; x++) {
        if (a * x % m == 1) return x;
    }
    return -1;
}

// ++・--・単項の + を、値を愚直に足し引きしたものと比べる
template <class M>
bool check_inc_dec(long long mod, std::mt19937_64& rng) {
    bool ok = true;
    for (int rep = 0; rep < 200; rep++) {
        long long x = (rep < 4) ? (rep < 2 ? rep : mod - 4 + rep) : static_cast<long long>(rng() % mod);
        if (x < 0 || x >= mod) x = 0;
        M a = x;
        // 前置: 変更後の自身を返す
        M& r1 = ++a;
        if (&r1 != &a || static_cast<long long>(a.val()) != (x + 1) % mod) ok = false;
        M& r2 = --a;
        if (&r2 != &a || static_cast<long long>(a.val()) != x) ok = false;
        // 後置: 変更前の値を返す
        M b = a++;
        if (static_cast<long long>(b.val()) != x || static_cast<long long>(a.val()) != (x + 1) % mod) ok = false;
        M c = a--;
        if (static_cast<long long>(c.val()) != (x + 1) % mod || static_cast<long long>(a.val()) != x) ok = false;
        // 0 から -- すると mod - 1 になる
        M z = 0;
        --z;
        if (static_cast<long long>(z.val()) != mod - 1) ok = false;
        M w = z++;
        if (static_cast<long long>(w.val()) != mod - 1 || z.val() != 0) ok = false;
        // 単項の + はそのままの値
        if ((+a).val() != a.val()) ok = false;
    }
    return ok;
}

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    if (!check_inc_dec<static_modint<998244353>>(998244353, rng)) ok = false, std::cerr << "inc/dec 998244353" << std::endl;
    if (!check_inc_dec<static_modint<7>>(7, rng)) ok = false, std::cerr << "inc/dec 7" << std::endl;
    if (!check_inc_dec<static_modint<2>>(2, rng)) ok = false, std::cerr << "inc/dec 2" << std::endl;
    using D = dynamic_modint<314>;
    for (long long m : {2LL, 3LL, 10LL, 1000000007LL}) {
        D::set_mod(m);
        if (!check_inc_dec<D>(m, rng)) ok = false, std::cerr << "inc/dec dynamic " << m << std::endl;
    }

    // 素数判定: 小さい数はすべて、大きい数は 2^32 付近と乱数で確かめる
    for (std::uint32_t x = 0; x < 200000; x++) {
        if (internal_modint::is_prime32(x) != naive_is_prime(x)) ok = false, std::cerr << "is_prime32 " << x << std::endl;
    }
    for (std::uint32_t x = 4294967295u; x > 4294967295u - 3000; x--) {
        if (internal_modint::is_prime32(x) != naive_is_prime(x)) ok = false, std::cerr << "is_prime32 " << x << std::endl;
    }
    for (int rep = 0; rep < 3000; rep++) {
        std::uint32_t x = static_cast<std::uint32_t>(rng());
        if (internal_modint::is_prime32(x) != naive_is_prime(x)) ok = false, std::cerr << "is_prime32 " << x << std::endl;
    }
    // 強擬素数 (小さい底では素数と誤判定されやすい合成数) も含める
    for (std::uint32_t x : {2047u, 3215031751u, 1373653u, 25326001u, 3825123056u, 464155845u, 1122004669u, 1795265022u, 998244353u, 1000000007u, 4294967291u}) {
        if (internal_modint::is_prime32(x) != naive_is_prime(x)) ok = false, std::cerr << "is_prime32 " << x << std::endl;
    }
    // コンパイル時にも使える
    static_assert(internal_modint::is_prime32(998244353u));
    static_assert(!internal_modint::is_prime32(1000000000u));

    // 合成数の法の static_modint では、拡張ユークリッドで逆元を求める
    {
        using M = static_modint<1000>;
        for (int a = 1; a < 1000; a++) {
            long long e = naive_inv(a, 1000);
            if (e == -1) continue;  // 互いに素でないものは逆元がない
            if (static_cast<long long>(M(a).inv().val()) != e) ok = false, std::cerr << "inv mod 1000 " << a << std::endl;
        }
    }
    {
        using M = static_modint<998244353>;
        for (int rep = 0; rep < 1000; rep++) {
            M a = static_cast<long long>(rng() % 998244352 + 1);
            if ((a * a.inv()).val() != 1) ok = false;
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
