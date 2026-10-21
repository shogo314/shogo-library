#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"

#include <iostream>

#include "../../../src/math/modint.hpp"
#include "../../../src/math/sum-of-exp-times-poly.hpp"

using mint = modint998244353;

int main() {
    long long r, d;
    std::cin >> r >> d;
    std::cout << sum_of_exp_times_poly_limit(mint(r), d) << '\n';
}
