#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"

#include <iostream>

#include "../../src/math/combinatorics.hpp"
#include "../../src/math/modint.hpp"

using mint = modint1000000007;

int main() {
    int n, k;
    std::cin >> n >> k;
    // 区別できない n 個のボールを、区別できる k 個の箱に制限なく入れる: kHn
    std::cout << Combination<mint>::H(k, n) << std::endl;
}
