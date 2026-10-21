#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include <iostream>
#include <vector>

#include "../../../src/math/linear-recurrence.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int d;
    long long k;
    std::cin >> d >> k;
    std::vector<mint> a(d), c(d);
    for (auto& x : a) std::cin >> x;
    for (auto& x : c) std::cin >> x;
    std::cout << linear_recurrence_kth(a, c, k) << '\n';
}
