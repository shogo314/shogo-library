#define PROBLEM "https://yukicoder.me/problems/no/3771"

// f(A) は左から貪欲に切った個数。最後以外の部分はちょうど K 種類で、次の部分の先頭はその K 種類にない値 (M - K 通り)
// 部分の先頭の値を固定して数えると、Σ_n S_n x^n = M G(x) Q((M - K) F(x))、Q(y) = Σ_{p >= 1} p^X y^{p-1}
// F(x) = (M-1)(M-2)...(M-K+1) x^K / Π_{i=1}^{K} (1 - i x) (ちょうど K 種類の部分)
// G(x) は K 種類以下の部分で、指数型母関数 R(e^x - 1) = Σ_t r_t e^{tx} (r は R(y - 1)) から、係数は Σ_t r_t t^L
// F は x^K から始まるので Q は p <= N / K + 1 まででよく、composition は K が大きければ Horner 法になる

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../src/math/fps-composition.hpp"
#include "../../src/math/fps.hpp"
#include "../../src/math/modint.hpp"
#include "../../src/math/multipoint.hpp"

using mint = modint998244353;
using F = FPS<mint>;

int main() {
    long long n, k;
    unsigned long long m, x;
    std::cin >> n >> m >> k >> x;
    const mint mm = m % mint::mod();
    const int d = std::min(k, n);  // 種類数は長さを超えない
    std::vector<mint> fact(d + 1, 1), ifact(d + 1, 1);
    for (int i = 1; i <= d; i++) fact[i] = fact[i - 1] * i;
    ifact[d] = fact[d].inv();
    for (int i = d; i > 0; i--) ifact[i - 1] = ifact[i] * i;
    // fall[j] = (M-1)(M-2)...(M-j+1): 先頭の値を固定した、ちょうど j 種類の値の選び方と並べ方の係数
    std::vector<mint> fall(d + 1);
    fall[1] = 1;
    for (int j = 2; j <= d; j++) fall[j] = fall[j - 1] * (mm - (j - 1));
    F R(d + 1);
    for (int j = 1; j <= d; j++) R[j] = fall[j] * ifact[j];
    F r = taylor_shift(R, mint(-1));
    r.resize(d + 1);
    std::vector<mint> xs(d + 1);
    for (int t = 0; t <= d; t++) xs[t] = t;
    auto G = weighted_power_sums(xs, std::vector<mint>(r.begin(), r.end()), n + 1);
    F y(n + 1);
    if (k <= n) {
        std::vector<F> fs;
        for (int i = 1; i <= k; i++) fs.push_back(F{1, -mint(i)});
        F s = inv(polynomial_product(fs), n + 1 - k);
        const mint coef = fall[k] * (mm - mint(k));
        for (int i = 0; i + k <= n; i++) y[i + k] = s[i] * coef;
    }
    const long long P = n / k + 1;
    F Q(P);
    for (long long p = 1; p <= P; p++) Q[p - 1] = mint(p).pow(x);
    F T = (F(G) * composition(Q, y, n + 1)).pre(n + 1);
    T.resize(n + 1);
    for (int i = 1; i <= n; i++) std::cout << (T[i] * mm).val() << '\n';
}
