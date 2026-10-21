#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B"

#include <iostream>

#include "../../../src/math/combinatorics.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint1000000007;

int main() {
    int n, k;
    std::cin >> n >> k;
    // 区別できる n 個のボールを、区別できる k 個の箱に高々 1 個ずつ入れる: kPn を定義どおり計算する
    std::cout << Combination<mint>::P_loop(k, n) << std::endl;
}
