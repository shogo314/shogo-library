#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_F"

#include <iostream>

#include "../../src/math/combinatorics.hpp"
#include "../../src/math/modint.hpp"

using mint = modint1000000007;

int main() {
    int n, k;
    std::cin >> n >> k;
    // 区別できない n 個のボールを、区別できる k 個の箱に 1 個以上ずつ入れる: (n-1)C(k-1) を定義どおり計算する
    std::cout << Combination<mint>::C_loop(n - 1, k - 1) << std::endl;
}
