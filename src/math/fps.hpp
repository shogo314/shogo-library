#pragma once

/**
 * @file fps.hpp
 * @brief 形式的冪級数
 */

#include <algorithm>
#include <cassert>
#include <optional>
#include <queue>
#include <utility>
#include <vector>

#include "combinatorics.hpp"
#include "convolution.hpp"
#include "modular-arithmetic.hpp"

template <typename mint>
struct FPS : std::vector<mint> {
    using std::vector<mint>::vector;

    // constructor
    FPS(const std::vector<mint>& r) : std::vector<mint>(r) {}

    // core operator
    inline FPS pre(long long siz) const {
        return FPS(begin(*this), begin(*this) + std::min(static_cast<long long>(this->size()), siz));
    }
    inline FPS rev() const {
        FPS res = *this;
        reverse(begin(res), end(res));
        return res;
    }
    inline FPS& normalize() {
        while (!this->empty() && this->back() == 0) this->pop_back();
        return *this;
    }

    // basic operator
    inline FPS operator-() const noexcept {
        FPS res = (*this);
        for (int i = 0; i < static_cast<int>(res.size()); ++i) res[i] = -res[i];
        return res;
    }
    inline FPS operator+(const mint& v) const { return FPS(*this) += v; }
    inline FPS operator+(const FPS& r) const { return FPS(*this) += r; }
    inline FPS operator-(const mint& v) const { return FPS(*this) -= v; }
    inline FPS operator-(const FPS& r) const { return FPS(*this) -= r; }
    inline FPS operator*(const mint& v) const { return FPS(*this) *= v; }
    inline FPS operator*(const FPS& r) const { return FPS(*this) *= r; }
    inline FPS operator/(const mint& v) const { return FPS(*this) /= v; }
    inline FPS operator<<(long long x) const { return FPS(*this) <<= x; }
    inline FPS operator>>(long long x) const { return FPS(*this) >>= x; }
    inline FPS& operator+=(const mint& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] += v;
        return *this;
    }
    inline FPS& operator+=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < static_cast<int>(r.size()); ++i) (*this)[i] += r[i];
        return this->normalize();
    }
    inline FPS& operator-=(const mint& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= v;
        return *this;
    }
    inline FPS& operator-=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < static_cast<int>(r.size()); ++i) (*this)[i] -= r[i];
        return this->normalize();
    }
    inline FPS& operator*=(const mint& v) {
        for (int i = 0; i < static_cast<int>(this->size()); ++i) (*this)[i] *= v;
        return *this;
    }
    inline FPS& operator*=(const FPS& r) {
        return *this = convolution((*this), r);
    }
    inline FPS& operator/=(const mint& v) {
        assert(v != 0);
        mint iv = v.inv();
        for (int i = 0; i < static_cast<int>(this->size()); ++i) (*this)[i] *= iv;
        return *this;
    }
    inline FPS& operator<<=(long long x) {
        FPS res(x, 0);
        res.insert(res.end(), begin(*this), end(*this));
        return *this = res;
    }
    inline FPS& operator>>=(long long x) {
        if (static_cast<long long>(this->size()) <= x) return *this = FPS<mint>(1, 0);
        FPS res;
        res.insert(res.end(), begin(*this) + x, end(*this));
        return *this = res;
    }
    inline mint eval(const mint& v) {
        mint res = 0;
        for (int i = static_cast<int>(this->size()) - 1; i >= 0; --i) {
            res *= v;
            res += (*this)[i];
        }
        return res;
    }
    inline friend FPS gcd(const FPS& f, const FPS& g) {
        if (g.empty()) return f;
        return gcd(g, f % g);
    }

    // advanced operation
    // df/dx
    inline friend FPS diff(const FPS& f) {
        int n = static_cast<int>(f.size());
        if (n == 0) return FPS();
        FPS res(n - 1);
        for (int i = 1; i < n; ++i) res[i - 1] = f[i] * i;
        return res;
    }

    // \int f dx
    inline friend FPS intg(const FPS& f) {
        int n = static_cast<int>(f.size());
        FPS res(n + 1, 0);
        for (int i = 0; i < n; ++i) res[i + 1] = f[i] / (i + 1);
        return res;
    }

    // inv(f), f[0] must not be 0
    inline friend FPS inv(const FPS& f, long long deg) {
        assert(!f.empty() && f[0] != 0);
        if (deg < 0) deg = static_cast<long long>(f.size());
        if (deg == 0) return FPS();
        FPS res({mint(1) / f[0]});
        for (long long i = 1; i < deg; i <<= 1) {
            res = (res + res - res * res * f.pre(i << 1)).pre(i << 1);
        }
        res.resize(deg);
        return res;
    }
    inline friend FPS inv(const FPS& f) {
        return inv(f, f.size());
    }

    // division, r must be normalized (r.back() must not be 0)
    inline FPS& operator/=(const FPS& r) {
        assert(!r.empty());
        assert(r.back() != 0);
        this->normalize();
        if (this->size() < r.size()) {
            this->clear();
            return *this;
        }
        const long long need = static_cast<long long>(this->size()) - static_cast<long long>(r.size()) + 1;
        *this = ((*this).rev().pre(need) * inv(r.rev(), need)).pre(need).rev();
        return *this;
    }
    inline FPS& operator%=(const FPS& r) {
        return *this = divmod(*this, r).second;
    }
    inline FPS operator/(const FPS& r) const { return FPS(*this) /= r; }
    inline FPS operator%(const FPS& r) const { return FPS(*this) %= r; }
    // {f / g, f % g}, g must be normalized (g.back() must not be 0)
    inline friend std::pair<FPS, FPS> divmod(const FPS& f, const FPS& g) {
        assert(!g.empty());
        assert(g.back() != 0);
        FPS q = f / g;
        FPS r = f - q * g;
        return {q, r};
    }

    // log(f) = \int f'/f dx, f[0] must be 1
    inline friend FPS log(const FPS& f, long long deg) {
        assert(!f.empty() && f[0] == 1);
        FPS res = intg(diff(f) * inv(f, deg));
        res.resize(deg);
        return res;
    }
    inline friend FPS log(const FPS& f) {
        return log(f, f.size());
    }

    // exp(f), f[0] must be 0
    inline friend FPS exp(const FPS& f, long long deg) {
        assert(f.empty() || f[0] == 0);
        FPS res(1, 1);
        for (long long i = 1; i < deg; i <<= 1) {
            res = res * (f.pre(i << 1) - log(res, i << 1) + 1).pre(i << 1);
        }
        res.resize(deg);
        return res;
    }
    inline friend FPS exp(const FPS& f) {
        return exp(f, f.size());
    }

    // pow(f) = exp(e * log f)
    inline friend FPS pow(const FPS& f, long long e, long long deg) {
        if (e == 0) {
            auto ret = FPS(deg, 0);
            if (deg > 0) ret[0] = 1;
            return ret;
        }
        long long i = 0;
        while (i < static_cast<long long>(f.size()) && f[i] == 0) ++i;
        if (i == static_cast<long long>(f.size())) return FPS(deg, 0);
        if ((i >= 1 && e >= deg) || i * e >= deg) return FPS(deg, 0);
        mint k = f[i];
        FPS res = exp(log((f >> i) / k, deg) * e, deg) * k.pow(e) << (e * i);
        res.resize(deg);
        return res;
    }
    inline friend FPS pow(const FPS& f, long long e) {
        return pow(f, e, f.size());
    }

    // sqrt(f) の先頭 deg 項 (g^2 = f)。平方根がなければ std::nullopt
    // 最初の 0 でない項 f_i x^i は、i が偶数で f_i が平方剰余であること。法は素数であること
    inline friend std::optional<FPS> sqrt(const FPS& f, long long deg) {
        long long i = 0;
        while (i < static_cast<long long>(f.size()) && f[i] == 0) ++i;
        if (i == static_cast<long long>(f.size()) || i / 2 >= deg) return FPS(deg, 0);
        if (i % 2 == 1) return std::nullopt;
        long long r = sqrt_mod(f[i].val(), mint::mod());
        if (r == -1) return std::nullopt;
        // x^i を外した g = f / x^i (g_0 != 0) の平方根をニュートン法で求める: h <- (h + g / h) / 2
        const FPS g = f >> i;
        const long long d = deg - i / 2;
        FPS h({mint(r)});
        const mint inv2 = mint(2).inv();
        for (long long k = 1; k < d; k <<= 1) {
            h = (h + (g.pre(k << 1) * inv(h, k << 1)).pre(k << 1)) * inv2;
        }
        h.resize(d);
        h <<= i / 2;
        return h;
    }
    inline friend std::optional<FPS> sqrt(const FPS& f) {
        return sqrt(f, f.size());
    }

    inline friend FPS taylor_shift(FPS f, mint a) {
        using C = Combination<mint>;
        int n = f.size();
        C::extend(n);
        for (int i = 0; i < n; i++) f[i] *= C::factorial(i);
        std::reverse(f.begin(), f.end());
        FPS<mint> g(n, 1);
        for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * C::inv(i);
        f = (f * g).pre(n);
        std::reverse(f.begin(), f.end());
        for (int i = 0; i < n; i++) f[i] *= C::inverse_factorial(i);
        return f;
    }
};

template <typename mint>
FPS<mint> modpow(const FPS<mint>& f, long long n, const FPS<mint>& m) {
    if (n == 0) return FPS<mint>(1, 1);
    auto t = modpow(f, n / 2, m);
    t = (t * t) % m;
    if (n & 1) t = (t * f) % m;
    return t;
}

/**
 * @brief 多項式の列の積 f_0 f_1 ... f_{n-1} O(N log^2 N) (N は次数の和)
 * 次数の小さいものから 2 つずつ掛けていく。fs が空なら 1
 */
template <typename mint>
FPS<mint> polynomial_product(std::vector<FPS<mint>> fs) {
    if (fs.empty()) return FPS<mint>(1, 1);
    auto larger = [&](int a, int b) { return fs[a].size() > fs[b].size(); };
    std::priority_queue<int, std::vector<int>, decltype(larger)> pq(larger);
    for (int i = 0; i < static_cast<int>(fs.size()); i++) pq.push(i);
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        // 空の多項式 (0) との積は 0
        fs[a] = fs[a].empty() || fs[b].empty() ? FPS<mint>() : fs[a] * fs[b];
        FPS<mint>().swap(fs[b]);
        pq.push(a);
    }
    return fs[pq.top()];
}
