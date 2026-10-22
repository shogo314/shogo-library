#define PROBLEM "https://yukicoder.me/problems/no/3770"

// 指数型母関数で Σ_k S_k x^k / k! = Σ_A e^{x f(A)} = H(e^x - 1)、H(y) = Σ_j C(M, j) u(j) y^j
// u(j) は決まった j 種類の値をすべて含む列の個数で、u(j) / j! = Σ_i (-1)^i (M - i)^N / i! × 1 / (j - i)!
// P(z) = H(z - 1) とおくと H(e^x - 1) = Σ_t p_t e^{tx} なので、S_k = Σ_t p_t t^k (重み付きの累乗和)

#include <iostream>
#include <vector>

#include "../../src/math/fps.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/math/multipoint.hpp"

using mint = modint998244353;

int main() {
    unsigned long long n, m;
    int k;
    std::cin >> n >> m >> k;
    std::vector<mint> fact(k + 1, 1), ifact(k + 1, 1);
    for (int i = 1; i <= k; i++) fact[i] = fact[i - 1] * i;
    ifact[k] = fact[k].inv();
    for (int i = k; i > 0; i--) ifact[i - 1] = ifact[i] * i;
    const mint mm = m % mint::mod();
    FPS<mint> a(k + 1), e(k + 1);
    for (int i = 0; i <= k; i++) {
        a[i] = (mm - i).pow(n) * ifact[i] * (i % 2 ? -1 : 1);
        e[i] = ifact[i];
    }
    FPS<mint> u = (a * e).pre(k + 1);
    u.resize(k + 1);
    // C(M, j) u(j) = M (M - 1) ... (M - j + 1) × (u(j) / j!)
    FPS<mint> h(k + 1);
    mint falling = 1;
    for (int j = 0; j <= k; j++) {
        h[j] = falling * u[j];
        falling *= mm - j;
    }
    FPS<mint> p = taylor_shift(h, mint(-1));
    p.resize(k + 1);
    std::vector<mint> xs(k + 1);
    for (int t = 0; t <= k; t++) xs[t] = t;
    auto s = weighted_power_sums(xs, std::vector<mint>(p.begin(), p.end()), k + 1);
    for (int i = 1; i <= k; i++) std::cout << s[i].val() << '\n';
}
