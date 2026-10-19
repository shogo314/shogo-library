#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <iostream>
#include <vector>

#include "../../src/math/prime.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<long long> ps = enumerate_primes(n);
    std::vector<long long> ans;
    for (int i = b; i < static_cast<int>(ps.size()); i += a) ans.push_back(ps[i]);
    std::cout << ps.size() << ' ' << ans.size() << '\n';
    for (std::size_t i = 0; i < ans.size(); i++) std::cout << ans[i] << " \n"[i + 1 == ans.size()];
    if (ans.empty()) std::cout << '\n';
}
