#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// bit.hpp の関数を愚直な実装とランダムに比較する
// C++17 (__builtin_* で実装) と C++20 (<bit> を呼ぶ) のどちらでも同じ結果になる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/utility/bit.hpp"

#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <type_traits>

bool ok = true;

void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

int main() {
    std::mt19937_64 rng(314);

    for (int rep = 0; rep < 100000 && ok; rep++) {
        // 0 以上の long long (ビット数もばらつかせる)
        int width = rng() % 63 + 1;
        long long a = (long long)(rng() >> (64 - width));

        int pc = 0, clz = 0, ctz = 0;
        for (int i = 0; i < 63; i++) pc += a >> i & 1;
        for (int i = 63; i >= 0 && !(a >> i & 1); i--) clz++;
        for (int i = 0; i < 64 && !(a >> i & 1); i++) ctz++;
        check(popcount(a) == pc, "popcount");
        if (a > 0) {
            check(countl_zero(a) == clz, "countl_zero");
            check(countr_zero(a) == ctz, "countr_zero");
        }

        // btoll: 2 進数の文字列 (上位桁から)
        std::string s;
        for (int i = width - 1; i >= 0; i--) s += (a >> i & 1) ? '1' : '0';
        check(btoll(s) == a, "btoll");
        // 1 を表す文字を指定する
        std::string t = s;
        for (char& c : t) c = (c == '1') ? '#' : '.';
        check(btoll(t, '#') == a, "btoll(s, one)");

        // hamming_distance: ビットごとに比べる
        long long b = (long long)(rng() >> (64 - width));
        int hd = 0;
        for (int i = 0; i < 63; i++) hd += (a >> i & 1) != (b >> i & 1);
        check(hamming_distance(a, b) == hd, "hamming_distance");
    }

    // countl_one / countr_one / bit_width / bit_ceil / bit_floor を愚直な実装と比べる
    for (int rep = 0; rep < 100000 && ok; rep++) {
        int width = rng() % 64;
        long long a = width == 0 ? 0 : (long long)(rng() >> (64 - width));
        if (rep % 4 == 0) a = (1LL << (rng() % 63)) - rng() % 2;  // 2 の累乗とその前後
        if (a < 0) a = 0;
        int clo = 0, cto = 0, bw = 0;
        for (int i = 63; i >= 0 && (a >> i & 1); i--) clo++;
        for (int i = 0; i < 64 && (a >> i & 1); i++) cto++;
        for (int i = 0; i < 63; i++) {
            if (a >> i & 1) bw = i + 1;
        }
        long long ceil = 1, floor = 0;
        while (ceil < a && ceil <= (1LL << 61)) ceil *= 2;  // a > 2^62 なら使わない
        for (int i = 0; i < 63; i++) {
            if ((1LL << i) <= a) floor = 1LL << i;
        }
        check(countl_one(a) == clo, "countl_one");
        check(countr_one(a) == cto, "countr_one");
        check(bit_width(a) == bw, "bit_width");
        if (a <= (1LL << 62)) check(bit_ceil(a) == ceil, "bit_ceil");
        check(bit_floor(a) == floor, "bit_floor");
    }

    // 0 のときは C++20 の <bit> と同じ値
    check(countl_zero(0) == 64 && countr_zero(0) == 64, "countl_zero / countr_zero(0)");
    check(countl_one(0) == 0 && countr_one(0) == 0, "countl_one / countr_one(0)");
    check(bit_width(0) == 0 && bit_ceil(0) == 1 && bit_floor(0) == 0, "bit_width / bit_ceil / bit_floor(0)");
    check(bit_ceil(1LL << 62) == (1LL << 62) && bit_ceil((1LL << 61) + 1) == (1LL << 62), "bit_ceil 上限");
    check(countr_one(std::numeric_limits<long long>::max()) == 63 && bit_width(std::numeric_limits<long long>::max()) == 63, "最大値");

    // 戻り値の型は C++17 でも C++20 でも long long
    static_assert(std::is_same_v<decltype(popcount(1)), long long>);
    static_assert(std::is_same_v<decltype(countl_zero(1)), long long>);
    static_assert(std::is_same_v<decltype(countr_zero(1)), long long>);
    static_assert(std::is_same_v<decltype(countl_one(1)), long long>);
    static_assert(std::is_same_v<decltype(countr_one(1)), long long>);
    static_assert(std::is_same_v<decltype(bit_width(1)), long long>);
    static_assert(std::is_same_v<decltype(bit_ceil(1)), long long>);
    static_assert(std::is_same_v<decltype(bit_floor(1)), long long>);
    static_assert(bit_width(5) == 3 && bit_ceil(5) == 8 && bit_floor(5) == 4 && countl_zero(0) == 64);

    // 決まった値
    check(popcount(0) == 0 && popcount((1LL << 62) - 1) == 62, "popcount 境界");
    check(countl_zero(1) == 63 && countr_zero(1LL << 62) == 62, "countl_zero / countr_zero 境界");
    check(hamming_distance(5, 3) == 2 && hamming_distance(7, 7) == 0, "hamming_distance 決まった値");
    check(btoll("") == 0 && btoll("0") == 0 && btoll("101") == 5, "btoll 決まった値");

    if (ok) std::cout << "Hello World" << std::endl;
}
