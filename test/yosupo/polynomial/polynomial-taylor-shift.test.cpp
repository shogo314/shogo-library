#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "../../../src/math/fps.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n, c;
    std::cin >> n >> c;
    FPS<mint> a(n);
    for (auto& x : a) std::cin >> x;
    auto f = taylor_shift(a, c);
    for (auto e : f) std::cout << e << ' ';
    std::cout << '\n';
    return 0;
}
