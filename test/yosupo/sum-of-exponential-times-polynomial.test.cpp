#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial"

#include <iostream>

#include "../../src/math/modint.hpp"
#include "../../src/math/sum-of-exp-times-poly.hpp"

using mint = modint998244353;

int main() {
    long long r, d, n;
    std::cin >> r >> d >> n;
    std::cout << sum_of_exp_times_poly(mint(r), d, n) << '\n';
}
