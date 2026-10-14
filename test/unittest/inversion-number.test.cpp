#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// inversion_number を、すべての組を調べる愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/others/inversion-number.hpp"

#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 40;
        int range = rng() % 10 + 1;
        std::vector<int> a(n);
        for (auto& v : a) v = rng() % range;
        long long less = 0, greater = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                less += a[j] < a[i];
                greater += a[i] < a[j];
            }
        }
        ok = ok && inversion_number(a) == less && inversion_number(a, std::greater<int>()) == greater;
    }

    // 例
    ok = ok && inversion_number(std::vector<int>{3, 1, 4, 1, 5}) == 3;
    ok = ok && inversion_number(std::vector<int>{}) == 0;
    ok = ok && inversion_number(std::vector<std::string>{"c", "b", "a"}) == 3;
    // 答えが int に収まらない
    std::vector<int> rev(100000);
    for (int i = 0; i < 100000; i++) rev[i] = 100000 - i;
    ok = ok && inversion_number(rev) == 100000LL * 99999 / 2;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
