#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E"

#include <iostream>

#include "../../../src/math/combinatorics.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint1000000007;

int main() {
    int n, k;
    std::cin >> n >> k;
    // 区別できない n 個のボールを、区別できる k 個の箱に高々 1 個ずつ入れる: kCn
    std::cout << Combination<mint>::C(k, n) << std::endl;
}
