#pragma once

/**
 * @file polynomial-gcd.hpp
 * @brief 多項式の拡張ユークリッドの互除法と、多項式を法とする逆元 (Half-GCD)
 */

#include <cassert>
#include <optional>
#include <utility>

#include "fps.hpp"

namespace internal_polynomial_gcd {
template <typename mint>
FPS<mint> shrink(FPS<mint> f) {
    f.normalize();
    return f;
}

// x^k で割って低次の項を捨てる。長さが k 以下なら 0 (空)
template <typename mint>
FPS<mint> drop(const FPS<mint>& f, long long k) {
    if (static_cast<long long>(f.size()) <= k) return FPS<mint>();
    return FPS<mint>(f.begin() + k, f.end());
}

// 多項式を成分に持つ 2x2 行列 [[a, b], [c, d]]
template <typename mint>
struct Mat {
    FPS<mint> a, b, c, d;
    static Mat identity() { return {FPS<mint>{1}, FPS<mint>(), FPS<mint>(), FPS<mint>{1}}; }
    Mat operator*(const Mat& r) const {
        return {shrink(a * r.a + b * r.c), shrink(a * r.b + b * r.d), shrink(c * r.a + d * r.c), shrink(c * r.b + d * r.d)};
    }
    std::pair<FPS<mint>, FPS<mint>> operator*(const std::pair<FPS<mint>, FPS<mint>>& p) const {
        return {shrink(a * p.first + b * p.second), shrink(c * p.first + d * p.second)};
    }
};

// 互除法を 1 段進める: (p, q) <- (q, p % q)、m <- [[0, 1], [1, -p / q]] m
template <typename mint>
void step(Mat<mint>& m, std::pair<FPS<mint>, FPS<mint>>& p) {
    const FPS<mint> quo = p.first / p.second;
    FPS<mint> rem = shrink(p.first - p.second * quo);
    FPS<mint> c = shrink(m.a - m.c * quo), d = shrink(m.b - m.d * quo);
    m = {std::move(m.c), std::move(m.d), std::move(c), std::move(d)};
    p = {std::move(p.second), std::move(rem)};
}

// p = (f, g) (|f| = n > |g|) に対し、互除法で長さが ceil(n / 2) 以下になる直前までの変換行列
template <typename mint>
Mat<mint> half_gcd(std::pair<FPS<mint>, FPS<mint>> p) {
    const long long n = p.first.size(), m = p.second.size();
    const long long k = (n + 1) / 2;
    if (m <= k) return Mat<mint>::identity();
    // 上位の半分だけで求めた行列は、上位の約半分の商を正しく与える
    Mat<mint> m1 = half_gcd(std::make_pair(drop(p.first, k), drop(p.second, k)));
    p = m1 * p;
    if (static_cast<long long>(p.second.size()) <= k) return m1;
    step(m1, p);
    if (static_cast<long long>(p.second.size()) <= k) return m1;
    const long long l = static_cast<long long>(p.first.size()) - 1;
    const long long j = 2 * k - l;
    p = {drop(p.first, j), drop(p.second, j)};
    return half_gcd(std::move(p)) * m1;
}

// M (f, g) = (gcd(f, g), 0) となる行列 M
template <typename mint>
Mat<mint> gcd_matrix(const FPS<mint>& f, const FPS<mint>& g) {
    std::pair<FPS<mint>, FPS<mint>> p{shrink(f), shrink(g)};
    if (p.first.size() < p.second.size()) {
        Mat<mint> m = gcd_matrix(g, f);
        std::swap(m.a, m.b);
        std::swap(m.c, m.d);
        return m;
    }
    Mat<mint> res = Mat<mint>::identity();
    while (!p.second.empty()) {
        Mat<mint> m1 = half_gcd(p);
        p = m1 * p;
        if (!p.second.empty()) step(m1, p);
        res = m1 * res;
    }
    return res;
}
}  // namespace internal_polynomial_gcd

/**
 * @brief a f + b g = d (d は f と g の最大公約数で、最高次の係数が 1) となる a、b を求め、d を返す O(n log^2 n)
 * f と g がともに 0 なら d = a = b = 0。a、b は末尾の 0 を取り除いた形
 */
template <typename mint>
FPS<mint> extgcd(const FPS<mint>& f, const FPS<mint>& g, FPS<mint>& a, FPS<mint>& b) {
    using namespace internal_polynomial_gcd;
    Mat<mint> m = gcd_matrix(f, g);
    FPS<mint> d = shrink(m.a * shrink(f) + m.b * shrink(g));
    a = std::move(m.a), b = std::move(m.b);
    if (d.empty()) {
        a.clear(), b.clear();
        return d;
    }
    const mint iv = d.back().inv();
    d *= iv, a *= iv, b *= iv;
    return d;
}

/**
 * @brief f h ≡ 1 (mod g) で、次数が g より小さい h。なければ std::nullopt O(n log^2 n)
 * g は 0 でないこと。g が定数ならすべてが 0 と合同なので、h = 0 (空) を返す。h は末尾の 0 を取り除いた形
 */
template <typename mint>
std::optional<FPS<mint>> modinv(const FPS<mint>& f, const FPS<mint>& g) {
    using namespace internal_polynomial_gcd;
    const FPS<mint> gs = shrink(g);
    assert(!gs.empty());
    if (gs.size() == 1) return FPS<mint>();
    FPS<mint> a, b;
    const FPS<mint> d = extgcd(shrink(f % gs), gs, a, b);
    if (d.size() != 1) return std::nullopt;
    return shrink(a % gs);
}
