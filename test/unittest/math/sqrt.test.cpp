#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// sqrtll を、小さい n では全部、大きい n では境界の前後で確かめる
// 問題の入力は使わず、すべて正しければ Hello World を出力する

#include "../../../src/math/sqrt.hpp"

#include <iostream>
#include <limits>
#include <random>

// s = floor(sqrt(n)) か (__int128 で 2 乗してあふれないように比べる)
bool is_floor_sqrt(long long n, long long s) {
    return s >= 0 && static_cast<__int128>(s) * s <= n && static_cast<__int128>(s + 1) * (s + 1) > n;
}

int main() {
    bool ok = true;
    for (long long n = 0; n <= 1000000; n++) {
        if (!is_floor_sqrt(n, sqrtll(n))) ok = false, std::cerr << n << std::endl;
    }
    // 平方数とその前後
    for (long long s : {1000000LL, 999999999LL, 3037000499LL}) {
        for (long long n : {s * s - 1, s * s, s * s + 1}) {
            if (!is_floor_sqrt(n, sqrtll(n))) ok = false, std::cerr << n << std::endl;
        }
    }
    const long long mx = std::numeric_limits<long long>::max();
    if (!is_floor_sqrt(mx, sqrtll(mx))) ok = false, std::cerr << "max" << std::endl;
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 100000; rep++) {
        long long n = rng() >> 1;
        if (!is_floor_sqrt(n, sqrtll(n))) ok = false, std::cerr << n << std::endl;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
