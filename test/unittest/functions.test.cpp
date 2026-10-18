#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// functions.hpp と binary-search.hpp の関数を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/base/functions.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <random>
#include <type_traits>
#include <utility>
#include <vector>

#include "../../src/utility/binary-search.hpp"

bool ok = true;

void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

// midpoint の答え: (a + b) / 2 を a の側に丸める。__int128 で計算する
template <typename T>
T naive_midpoint(T a, T b) {
    __int128 s = (__int128)a + (__int128)b;
    return (T)(a <= b ? floordiv(s, 2) : ceildiv(s, 2));
}
template <typename T>
void check_midpoint(std::mt19937_64& rng) {
    std::vector<T> xs = {std::numeric_limits<T>::min(), std::numeric_limits<T>::max(), 0, 1, (T)(std::numeric_limits<T>::max() - 1), (T)(std::numeric_limits<T>::min() + 1)};
    if (std::is_signed_v<T>) xs.push_back((T)-1);
    for (int i = 0; i < 30; i++) xs.push_back((T)rng()), xs.push_back((T)((T)rng() >> (rng() % (8 * sizeof(T)))));
    for (T a : xs)
        for (T b : xs) check(midpoint(a, b) == naive_midpoint(a, b), "midpoint 整数");
    static_assert(std::is_same_v<decltype(midpoint(T(), T())), T>);
}

int main() {
    std::mt19937_64 rng(314);

    for (int rep = 0; rep < 20000 && ok; rep++) {
        long long a = (long long)(rng() % 21) - 10, b = (long long)(rng() % 21) - 10;

        // chmin / chmax: 更新したかを返す
        {
            long long x = a;
            bool changed = chmin(x, b);
            check(x == std::min(a, b) && changed == (b < a), "chmin");
            x = a;
            changed = chmax(x, b);
            check(x == std::max(a, b) && changed == (b > a), "chmax");
            double d = a;
            check(chmin(d, b + 0.5) == (b + 0.5 < a) && d == std::min<double>(a, b + 0.5), "chmin (型が異なる)");
        }

        // long long 同士の max / min
        check(max(a, b) == std::max(a, b) && min(a, b) == std::min(a, b), "max/min(long long, long long)");
        check(max(a, 3) == std::max(a, 3LL) && min(2, b) == std::min(2LL, b), "max/min (int と long long の混在)");

        // floordiv / ceildiv: 実数の floor / ceil と比べる
        if (b != 0) {
            check(floordiv(a, b) == (long long)std::floor((double)a / b), "floordiv");
            check(ceildiv(a, b) == (long long)std::ceil((double)a / b), "ceildiv");
            auto [q, r] = divmod(a, b);
            check(q == floordiv(a, b) && q * b + r == a, "divmod");
            check(r == 0 || (r < 0) == (b < 0), "divmod 余りの符号");
            check(std::abs(r) < std::abs(b), "divmod 余りの大きさ");
        }

        // inrange / inrect
        {
            long long x = (long long)(rng() % 15) - 5;
            check(inrange(x, a) == (0 <= x && x < a), "inrange(x, a)");
            check(inrange(x, a, b) == (a <= x && x < b), "inrange(x, a, b)");
            long long y = (long long)(rng() % 15) - 5;
            check(inrect(x, y, a, b) == (0 <= x && x < a && 0 <= y && y < b), "inrect");
        }

        // 整数の二分探索: f(ok) が真、f(ng) が偽で単調なとき、境界の ok 側を返す
        {
            long long t = (long long)(rng() % 2001) - 1000;
            long long lo = t - (long long)(rng() % 1000) - 1, hi = t + (long long)(rng() % 1000) + 1;
            // f(x) = x <= t (ok = lo, ng = hi) -> t
            check(binary_search(lo, hi, [&](long long x) { return x <= t; }) == t, "binary_search 整数 (ok < ng)");
            // f(x) = x >= t (ok = hi, ng = lo) -> t
            check(binary_search(hi, lo, [&](long long x) { return x >= t; }) == t, "binary_search 整数 (ok > ng)");
            // 隣り合う ok, ng なら ok をそのまま返す
            check(binary_search(t, t + 1, [&](long long) { return true; }) == t, "binary_search 整数 隣接");
        }

        // 実数の二分探索 (100 回)
        {
            double t = (double)(rng() % 2000001) / 1000.0;  // [0, 2000]
            double r = binary_search(0.0, 3000.0, [&](double x) { return x * x <= t; });
            check(std::abs(r - std::sqrt(t)) < 1e-9, "binary_search 実数 sqrt");
            double r2 = binary_search(3000.0, 0.0, [&](double x) { return x * x >= t; });
            check(std::abs(r2 - std::sqrt(t)) < 1e-9, "binary_search 実数 (ok > ng)");
        }
    }

    // 決まった値
    check(binary_search(0, 1000000000, [](int x) { return (long long)x * x <= 1000000000; }) == 31622, "binary_search sqrt(1e9)");
    check(!inrange(0, 0) && inrange(0, 1) && !inrange(-1, 1), "inrange 境界");
    check(inrange(5, 5, 6) && !inrange(6, 5, 6), "inrange(x, a, b) 境界");
    check(floordiv(7, 2) == 3 && floordiv(-7, 2) == -4 && floordiv(7, -2) == -4 && floordiv(-7, -2) == 3, "floordiv 決まった値");
    check(ceildiv(7, 2) == 4 && ceildiv(-7, 2) == -3 && ceildiv(7, -2) == -3 && ceildiv(-7, -2) == 4, "ceildiv 決まった値");
    check(floordiv(-6, 3) == -2 && ceildiv(-6, 3) == -2, "割り切れる場合");
    {
        long long n = -7;
        check(floordiv(n, 2) == -4 && ceildiv(n, 2) == -3, "long long と int の混在");
    }
    check(divmod(7, 3) == std::pair(2, 1) && divmod(-7, 3) == std::pair(-3, 2), "divmod 決まった値");
    check(divmod(7, -3) == std::pair(-3, -2) && divmod(-7, -3) == std::pair(2, -1), "divmod 決まった値 (b < 0)");
    static_assert(floordiv(-1LL, 1000000000000LL) == -1 && ceildiv(1LL, 1000000000000LL) == 1);
    static_assert(divmod(-1LL, 1000000000000LL) == std::pair(-1LL, 999999999999LL));

    // midpoint: 整数は 8 ビットの型を全組、他は境界付近とランダム。浮動小数点数とポインタは決まった値
    for (int a = -128; a < 128; a++)
        for (int b = -128; b < 128; b++) check(midpoint((std::int8_t)a, (std::int8_t)b) == naive_midpoint((std::int8_t)a, (std::int8_t)b), "midpoint int8");
    for (int a = 0; a < 256; a++)
        for (int b = 0; b < 256; b++) check(midpoint((std::uint8_t)a, (std::uint8_t)b) == naive_midpoint((std::uint8_t)a, (std::uint8_t)b), "midpoint uint8");
    check_midpoint<short>(rng);
    check_midpoint<int>(rng);
    check_midpoint<unsigned>(rng);
    check_midpoint<long long>(rng);
    check_midpoint<unsigned long long>(rng);
    {
        constexpr double M = std::numeric_limits<double>::max(), D = std::numeric_limits<double>::denorm_min();
        check(midpoint(1.0, 4.0) == 2.5 && midpoint(-3.0, 1.0) == -1.0, "midpoint double");
        check(midpoint(M, M) == M && midpoint(-M, M) == 0.0 && midpoint(M, M / 2) == M * 0.75, "midpoint double あふれない");
        check(midpoint(D, 4.0) == 2.0 && midpoint(4.0, D) == 2.0 && midpoint(D, D) == D, "midpoint double 非正規化数");
        check(midpoint(1.0f, 2.0f) == 1.5f && std::is_same_v<decltype(midpoint(1.0f, 2.0f)), float>, "midpoint float");
        for (int rep = 0; rep < 1000; rep++) {
            double a = (double)(long long)(rng() % 2000001 - 1000000) / 1024, b = (double)(long long)(rng() % 2000001 - 1000000) / 1024;
            check(midpoint(a, b) == (a + b) / 2, "midpoint double ランダム");
        }
        static int arr[10];
        check(midpoint(arr, arr + 9) == arr + 4 && midpoint(arr + 9, arr) == arr + 5 && midpoint(arr + 3, arr + 3) == arr + 3, "midpoint ポインタ");
    }
    static_assert(midpoint(1, 4) == 2 && midpoint(4, 1) == 3 && midpoint(-3, 0) == -2);
    static_assert(midpoint(std::numeric_limits<long long>::max(), std::numeric_limits<long long>::max() - 2) == std::numeric_limits<long long>::max() - 1);
    static_assert(midpoint(0u, 4294967295u) == 2147483647u && midpoint(4294967295u, 0u) == 2147483648u);
    static_assert(midpoint(1.0, 2.0) == 1.5);

    if (ok) std::cout << "Hello World" << std::endl;
}
