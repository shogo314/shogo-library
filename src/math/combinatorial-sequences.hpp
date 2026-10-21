#pragma once

/**
 * @file combinatorial-sequences.hpp
 * @brief 分割数・ベルヌーイ数・スターリング数・ベル数 (形式的冪級数で O(n log n))
 */

#include <vector>

#include "combinatorics.hpp"
#include "convolution.hpp"
#include "fps.hpp"

/**
 * @brief 分割数 p(0), ..., p(n) (n を正の整数の和に分ける方法の数。和の順番は区別しない) O(n log n)
 * 母関数は 1 / Π_{k >= 1} (1 - x^k)。分母は五角数定理で Σ_k (-1)^k x^{k(3k-1)/2} (k は全整数) と書ける
 */
template <typename mint>
FPS<mint> partition_numbers(long long n) {
    FPS<mint> f(n + 1, 0);
    f[0] = 1;
    for (long long k = 1;; k++) {
        const long long a = k * (3 * k - 1) / 2, b = k * (3 * k + 1) / 2;
        if (a > n) break;
        const mint s = k % 2 == 1 ? mint(-1) : mint(1);
        f[a] += s;
        if (b <= n) f[b] += s;
    }
    return inv(f, n + 1);
}

/**
 * @brief ベルヌーイ数 B_0, ..., B_n (B_1 = -1/2 とする流儀) O(n log n)
 * 指数型母関数 x / (e^x - 1) を、(e^x - 1) / x = Σ x^k / (k+1)! の逆数として求める
 */
template <typename mint>
FPS<mint> bernoulli_numbers(long long n) {
    using C = Combination<mint>;
    C::extend(n + 1);
    FPS<mint> f(n + 1);
    for (long long k = 0; k <= n; k++) f[k] = C::inverse_factorial(k + 1);
    FPS<mint> g = inv(f, n + 1);
    for (long long k = 0; k <= n; k++) g[k] *= C::factorial(k);
    return g;
}

/**
 * @brief 符号付き第 1 種スターリング数 s(n, 0), ..., s(n, n) (x (x-1) ... (x-n+1) = Σ s(n, k) x^k) O(n log n)
 * 下降階乗 f_m(x) = x (x-1) ... (x-m+1) を、f_{2m}(x) = f_m(x) f_m(x - m) と f_{m+1}(x) = f_m(x) (x - m) で倍々に作る
 * 符号なし (順列を k 個の巡回に分ける方法の数) は |s(n, k)|
 */
template <typename mint>
FPS<mint> stirling_first(long long n) {
    FPS<mint> f{1};
    long long m = 0;
    for (int bit = 62; bit >= 0; bit--) {
        if (m > 0) {
            f = f * taylor_shift(f, -mint(m));
            m *= 2;
        }
        if (n >> bit & 1) {
            f = f * FPS<mint>{-mint(m), 1};
            m++;
        }
    }
    f.resize(n + 1);
    return f;
}

/**
 * @brief 第 2 種スターリング数 S(n, 0), ..., S(n, n) (n 個の区別できる玉を k 個の区別できない空でない箱に分ける方法の数) O(n log n)
 * S(n, k) = Σ_{i=0}^{k} (-1)^{k-i} i^n / (i! (k-i)!) を畳み込みで求める
 */
template <typename mint>
FPS<mint> stirling_second(long long n) {
    using C = Combination<mint>;
    C::extend(n);
    std::vector<mint> a(n + 1), b(n + 1);
    for (long long i = 0; i <= n; i++) {
        a[i] = mint(i).pow(n) * C::inverse_factorial(i);
        b[i] = i % 2 == 0 ? C::inverse_factorial(i) : -C::inverse_factorial(i);
    }
    FPS<mint> s = convolution(a, b);
    s.resize(n + 1);
    return s;
}

/**
 * @brief ベル数 B_0, ..., B_n (n 個の区別できる要素を空でない部分集合に分ける方法の数) O(n log n)
 * 指数型母関数は exp(e^x - 1)
 */
template <typename mint>
FPS<mint> bell_numbers(long long n) {
    using C = Combination<mint>;
    C::extend(n);
    FPS<mint> g(n + 1, 0);
    for (long long k = 1; k <= n; k++) g[k] = C::inverse_factorial(k);
    FPS<mint> f = exp(g, n + 1);
    for (long long k = 0; k <= n; k++) f[k] *= C::factorial(k);
    return f;
}
