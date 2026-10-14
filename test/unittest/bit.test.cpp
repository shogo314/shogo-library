#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// bit.hpp の関数を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/utility/bit.hpp"

#include <iostream>
#include <random>
#include <string>

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
    }

    // 決まった値
    check(popcount(0) == 0 && popcount((1LL << 62) - 1) == 62, "popcount 境界");
    check(countl_zero(1) == 63 && countr_zero(1LL << 62) == 62, "countl_zero / countr_zero 境界");
    check(btoll("") == 0 && btoll("0") == 0 && btoll("101") == 5, "btoll 決まった値");

    if (ok) std::cout << "Hello World" << std::endl;
}
