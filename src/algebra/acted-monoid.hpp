#pragma once

/**
 * @file acted-monoid.hpp
 * @brief 作用素付きモノイドの定義
 *
 * 作用素付きモノイドはモノイド (algebra/monoid.hpp) のメンバに加えて次のメンバを持つ型として表す
 * - using F: 作用素の型
 * - S mapping(const F& f, const S& x): 作用素の適用 f(x)
 *   区間の情報が必要な場合は mapping(f, x, sz) (sz は区間の長さ) や mapping(f, x, l, r) (区間 [l, r)) でもよい
 *   sz, l, r は long long で渡す (動的セグメント木では int に収まらないことがある)
 * - F composition(const F& f, const F& g): 作用素の合成 f∘g (gを適用した後にfを適用する)
 * - F id(): 恒等写像
 * 作用素が群をなす場合 (imos.hpp で使う) は
 * - F inv(const F& f): 逆作用素
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <limits>
#include <numeric>
#include <optional>
#include <type_traits>
#include <utility>

#include "monoid.hpp"

#if __cplusplus < 202002L
namespace internal_acted_monoid {
template <typename A, typename = void>
struct has_mapping_lr : std::false_type {};
template <typename A>
struct has_mapping_lr<A, std::void_t<decltype(std::declval<const A&>().mapping(std::declval<const typename A::F&>(), std::declval<const typename A::S&>(), 0, 0))>> : std::true_type {};
template <typename A, typename = void>
struct has_mapping_sz : std::false_type {};
template <typename A>
struct has_mapping_sz<A, std::void_t<decltype(std::declval<const A&>().mapping(std::declval<const typename A::F&>(), std::declval<const typename A::S&>(), 0))>> : std::true_type {};
}  // namespace internal_acted_monoid
#endif

namespace acted_monoid {

/**
 * @brief 区間 [l, r) を表す要素に作用素を適用する
 * mapping の引数の形の違いを吸収する
 */
template <typename A>
constexpr auto apply_mapping(const A& a, const typename A::F& f, const typename A::S& x, long long l, long long r) {
#if __cplusplus >= 202002L
    if constexpr (requires { a.mapping(f, x, l, r); }) {
#else
    if constexpr (internal_acted_monoid::has_mapping_lr<A>::value) {
#endif
        return a.mapping(f, x, l, r);
#if __cplusplus >= 202002L
    } else if constexpr (requires { a.mapping(f, x, r - l); }) {
#else
    } else if constexpr (internal_acted_monoid::has_mapping_sz<A>::value) {
#endif
        return a.mapping(f, x, r - l);
    } else {
        return a.mapping(f, x);
    }
}

/**
 * @brief 区間加算、区間和
 */
template <typename T>
struct AddSum : monoid::Sum<T> {
    using S = T;
    using F = T;
    static constexpr S mapping(const F& f, const S& x, long long sz) { return x + f * S(sz); }
    static constexpr F composition(const F& f, const F& g) { return f + g; }
    static constexpr F id() { return F(0); }
    static constexpr F inv(const F& f) { return -f; }
};

/**
 * @brief 区間の位置 i に constant + slope * i を加算、区間和
 * arithmetic_progression(l, first, step) で左端 l の初項 first、公差 step を指定する
 */
template <typename T = long long>
struct LinearAddSum : monoid::Sum<T> {
    using S = T;
    struct F {
        T constant = T(0), slope = T(0);
    };
    static constexpr F arithmetic_progression(long long l, const T& first, const T& step) {
        assert(l >= 0);
        return {first - step * T(l), step};
    }
    static constexpr S mapping(const F& f, const S& x, long long l, long long r) {
        assert(0 <= l && l <= r);
        const long long n = r - l;
        if (n == 0) return x;
        // sum i = l*n + n*(n-1)/2。整数側で 2 で割り、和・積は T で計算する。
        const T offset = n % 2 == 0 ? T(n / 2) * T(n - 1) : T(n) * T((n - 1) / 2);
        return x + f.constant * T(n) + f.slope * (T(l) * T(n) + offset);
    }
    static constexpr F composition(const F& f, const F& g) { return {f.constant + g.constant, f.slope + g.slope}; }
    static constexpr F id() { return F(); }
    static constexpr F inv(const F& f) { return {-f.constant, -f.slope}; }
};

/**
 * @brief 区間乗算、区間和
 */
template <typename T>
struct MulSum : monoid::Sum<T> {
    using S = T;
    using F = T;
    static constexpr S mapping(const F& f, const S& x) { return f * x; }
    static constexpr F composition(const F& f, const F& g) { return f * g; }
    static constexpr F id() { return F(1); }
    static constexpr F inv(const F& f) { return F(1) / f; }
};

/**
 * @brief 区間加算、区間最小値
 */
template <typename T>
struct AddMin : monoid::Min<T> {
    using S = T;
    using F = T;
    static constexpr S mapping(const F& f, const S& x) { return x + f; }
    static constexpr F composition(const F& f, const F& g) { return f + g; }
    static constexpr F id() { return F(0); }
};

/**
 * @brief 区間加算、区間最大値
 */
template <typename T>
struct AddMax : monoid::Max<T> {
    using S = T;
    using F = T;
    static constexpr S mapping(const F& f, const S& x) { return x + f; }
    static constexpr F composition(const F& f, const F& g) { return f + g; }
    static constexpr F id() { return F(0); }
};

/**
 * @brief 区間代入、区間和
 */
template <typename T>
struct UpdateSum : monoid::Sum<T> {
    using S = T;
    using F = std::optional<T>;
    static constexpr S mapping(const F& f, const S& x, long long sz) { return f ? *f * S(sz) : x; }
    static constexpr F composition(const F& f, const F& g) { return f ? f : g; }
    static constexpr F id() { return std::nullopt; }
};

/**
 * @brief 区間代入、区間最小値
 */
template <typename T>
struct UpdateMin : monoid::Min<T> {
    using S = T;
    using F = std::optional<T>;
    static constexpr S mapping(const F& f, const S& x) { return f ? *f : x; }
    static constexpr F composition(const F& f, const F& g) { return f ? f : g; }
    static constexpr F id() { return std::nullopt; }
};

/**
 * @brief 区間代入、区間最大値
 */
template <typename T>
struct UpdateMax : monoid::Max<T> {
    using S = T;
    using F = std::optional<T>;
    static constexpr S mapping(const F& f, const S& x) { return f ? *f : x; }
    static constexpr F composition(const F& f, const F& g) { return f ? f : g; }
    static constexpr F id() { return std::nullopt; }
};

/**
 * @brief 区間chmin、区間最小値
 */
template <typename T>
struct ChminMin : monoid::Min<T> {
    using S = T;
    using F = T;
    static constexpr S mapping(const F& f, const S& x) { return std::min(f, x); }
    static constexpr F composition(const F& f, const F& g) { return std::min(f, g); }
    static constexpr F id() { return std::numeric_limits<F>::max(); }
};

/**
 * @brief 区間chmax、区間最大値
 */
template <typename T>
struct ChmaxMax : monoid::Max<T> {
    using S = T;
    using F = T;
    static constexpr S mapping(const F& f, const S& x) { return std::max(f, x); }
    static constexpr F composition(const F& f, const F& g) { return std::max(f, g); }
    static constexpr F id() { return std::numeric_limits<F>::lowest(); }
};

/**
 * @brief 区間 clamp x <- min(max(x, lb), ub) (Clamp)、区間最小値
 * clamp は単調非減少なので、最小値に適用すればよい
 */
template <typename T>
struct ClampMin : monoid::Min<T> {
    using S = T;
    using F = Clamp<T>;
    static constexpr S mapping(const F& f, const S& x) { return f(x); }
    static constexpr F composition(const F& f, const F& g) { return monoid::ClampComposite<T>::op(f, g); }
    static constexpr F id() { return {}; }
};

/**
 * @brief 区間 clamp x <- min(max(x, lb), ub) (Clamp)、区間最大値
 */
template <typename T>
struct ClampMax : monoid::Max<T> {
    using S = T;
    using F = Clamp<T>;
    static constexpr S mapping(const F& f, const S& x) { return f(x); }
    static constexpr F composition(const F& f, const F& g) { return monoid::ClampComposite<T>::op(f, g); }
    static constexpr F id() { return {}; }
};

/**
 * @brief 区間 clamp x <- min(max(x, lb), ub) (Clamp)、区間最小値と最大値の組 {min, max} (monoid::MinMax)
 */
template <typename T>
struct ClampMinMax : monoid::MinMax<T> {
    using S = typename monoid::MinMax<T>::S;
    using F = Clamp<T>;
    static constexpr S mapping(const F& f, const S& x) {
        if (x.min > x.max) return x;
        return {f(x.min), f(x.max)};
    }
    static constexpr F composition(const F& f, const F& g) { return monoid::ClampComposite<T>::op(f, g); }
    static constexpr F id() { return {}; }
};

/**
 * @brief 区間 加算と clamp x <- min(max(x + add, lb), ub) (ClampAdd)、区間最小値
 * 区間加算・chmin・chmax・代入をまとめて扱える。単調非減少なので、最小値に適用すればよい
 */
template <typename T>
struct ClampAddMin : monoid::Min<T> {
    using S = T;
    using F = ClampAdd<T>;
    static constexpr S mapping(const F& f, const S& x) { return f(x); }
    static constexpr F composition(const F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f, g); }
    static constexpr F id() { return {}; }
};

/**
 * @brief 区間 加算と clamp x <- min(max(x + add, lb), ub) (ClampAdd)、区間最大値
 */
template <typename T>
struct ClampAddMax : monoid::Max<T> {
    using S = T;
    using F = ClampAdd<T>;
    static constexpr S mapping(const F& f, const S& x) { return f(x); }
    static constexpr F composition(const F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f, g); }
    static constexpr F id() { return {}; }
};

/**
 * @brief 区間 加算と clamp x <- min(max(x + add, lb), ub) (ClampAdd)、区間最小値と最大値の組 {min, max} (monoid::MinMax)
 */
template <typename T>
struct ClampAddMinMax : monoid::MinMax<T> {
    using S = typename monoid::MinMax<T>::S;
    using F = ClampAdd<T>;
    static constexpr S mapping(const F& f, const S& x) {
        if (x.min > x.max) return x;
        return {f(x.min), f(x.max)};
    }
    static constexpr F composition(const F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f, g); }
    static constexpr F id() { return {}; }
};

/**
 * @brief 区間アフィン変換 x <- a * x + b (Affine)、区間和
 */
template <typename T>
struct AffineSum : monoid::Sum<T> {
    using S = T;
    using F = Affine<T>;
    static constexpr S mapping(const F& f, const S& x, long long sz) { return f.a * x + f.b * S(sz); }
    static constexpr F composition(const F& f, const F& g) { return {f.a * g.a, f.a * g.b + f.b}; }
    static constexpr F id() { return {T(1), T(0)}; }
};

/**
 * @brief 区間代入、1次関数の合成 (monoid::Composite)
 */
template <typename T>
struct UpdateComposite : monoid::Composite<T> {
    using S = Affine<T>;
    using F = std::optional<S>;
    static constexpr S mapping(const F& f, const S& x, long long sz) {
        if (!f) return x;
        // f を sz 回合成する
        S ret = monoid::Composite<T>::e(), p = *f;
        for (; sz > 0; sz >>= 1) {
            if (sz & 1) ret = monoid::Composite<T>::op(ret, p);
            p = monoid::Composite<T>::op(p, p);
        }
        return ret;
    }
    static constexpr F composition(const F& f, const F& g) { return f ? f : g; }
    static constexpr F id() { return std::nullopt; }
};

/**
 * @brief 区間加算、区間最小値とその位置 (monoid::MinWith)
 */
template <typename T, typename U = long long>
struct AddMinWith : monoid::MinWith<T, U> {
    using S = std::pair<T, U>;
    using F = T;
    // 単位元 (位置が -1) は単位元のまま (型の最大値・最小値に足してあふれないように)
    static constexpr S mapping(const F& f, const S& x) {
        if (internal_monoid::with_is_e(x.second)) return x;
        return {x.first + f, x.second};
    }
    static constexpr F composition(const F& f, const F& g) { return f + g; }
    static constexpr F id() { return F(0); }
};

/**
 * @brief 区間加算、区間最大値とその位置 (monoid::MaxWith)
 */
template <typename T, typename U = long long>
struct AddMaxWith : monoid::MaxWith<T, U> {
    using S = std::pair<T, U>;
    using F = T;
    // 単位元 (位置が -1) は単位元のまま (型の最大値・最小値に足してあふれないように)
    static constexpr S mapping(const F& f, const S& x) {
        if (internal_monoid::with_is_e(x.second)) return x;
        return {x.first + f, x.second};
    }
    static constexpr F composition(const F& f, const F& g) { return f + g; }
    static constexpr F id() { return F(0); }
};

/**
 * @brief 区間加算、区間最小値とその個数 (monoid::MinCount)
 */
template <typename T, typename U = long long>
struct AddMinCount : monoid::MinCount<T, U> {
    using S = std::pair<T, U>;
    using F = T;
    static constexpr S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }
    static constexpr F composition(const F& f, const F& g) { return f + g; }
    static constexpr F id() { return F(0); }
};

/**
 * @brief 区間加算、区間最大値とその個数 (monoid::MaxCount)
 */
template <typename T, typename U = long long>
struct AddMaxCount : monoid::MaxCount<T, U> {
    using S = std::pair<T, U>;
    using F = T;
    static constexpr S mapping(const F& f, const S& x) { return {x.first + f, x.second}; }
    static constexpr F composition(const F& f, const F& g) { return f + g; }
    static constexpr F id() { return F(0); }
};

/**
 * @brief 区間加算、区間の0乗和からK乗和
 *
 * S(x) で値 x の1要素を表す要素を作る。S::operator[](i) で i 乗和を取得する
 */
template <typename T, int K>
struct AddPowerSum {
    struct S {
        std::array<T, K + 1> val;
        constexpr S() : val{} {}
        constexpr S(const T& x) : val{} {
            val[0] = T(1);
            for (int i = 1; i <= K; i++) val[i] = val[i - 1] * x;
        }
        constexpr const T& operator[](long long i) const { return val[i]; }
    };
    using F = T;
    static constexpr S op(const S& a, const S& b) {
        S ret;
        for (int i = 0; i <= K; i++) ret.val[i] = a.val[i] + b.val[i];
        return ret;
    }
    static constexpr S e() { return S(); }
    static S mapping(const F& f, const S& x) {
        // sum (x+f)^i = sum_j binom(i, j) f^j x^(i-j)
        static const auto binom = [] {
            std::array<std::array<T, K + 1>, K + 1> c{};
            for (int i = 0; i <= K; i++) {
                c[i][0] = c[i][i] = T(1);
                for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
            return c;
        }();
        std::array<T, K + 1> pw{};
        pw[0] = T(1);
        for (int i = 1; i <= K; i++) pw[i] = pw[i - 1] * f;
        S ret;
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= i; j++) ret.val[i] += binom[i][j] * pw[j] * x.val[i - j];
        }
        return ret;
    }
    static constexpr F composition(const F& f, const F& g) { return f + g; }
    static constexpr F id() { return F(0); }
};

/** @brief 区間アフィン変換、区間最小値・最大値 (負の倍率も許す) */
template <typename T = long long>
struct AffineMinMax : monoid::MinMax<T> {
    using S = typename monoid::MinMax<T>::S;
    using F = Affine<T>;
    static constexpr S mapping(const F& f, const S& x) {
        if (x.min > x.max) return x;
        if (f.a < T(0)) return {f(x.max), f(x.min)};
        return {f(x.min), f(x.max)};
    }
    static constexpr F composition(const F& f, const F& g) { return monoid::Composite<T>::op(f, g); }
    static constexpr F id() { return F(); }
};

/** @brief 区間アフィン変換、区間の 0 乗和から K 乗和 */
template <typename T = long long, long long K = 2>
struct AffinePowerSum : AddPowerSum<T, K> {
    static_assert(K >= 0);
    using S = typename AddPowerSum<T, K>::S;
    using F = Affine<T>;
    static S mapping(const F& f, const S& x) {
        std::array<T, K + 1> pa{}, pb{}, binom{};
        pa[0] = pb[0] = binom[0] = T(1);
        for (long long i = 1; i <= K; ++i) {
            pa[i] = pa[i - 1] * f.a;
            pb[i] = pb[i - 1] * f.b;
        }
        S res;
        for (long long i = 0; i <= K; ++i) {
            for (long long j = 0; j <= i; ++j) res.val[i] += binom[j] * pa[j] * pb[i - j] * x[j];
            if (i < K)
                for (long long j = i + 1; j >= 1; --j) binom[j] += binom[j - 1];
        }
        return res;
    }
    static constexpr F composition(const F& f, const F& g) { return monoid::Composite<T>::op(f, g); }
    static constexpr F id() { return F(); }
};

/** @brief 区間加算、区間 gcd。S::val() で gcd を取得する */
template <typename T = long long>
struct AddGcd {
    static_assert(std::is_integral_v<T> && std::is_signed_v<T>);
    struct S {
        T first = T(0), last = T(0), differences_gcd = T(0);
        long long size = 0;
        constexpr S() = default;
        constexpr S(const T& x) : first(x), last(x), size(1) {}
        constexpr T val() const { return std::gcd(first, differences_gcd); }
    };
    using F = T;
    static constexpr S op(const S& a, const S& b) {
        if (a.size == 0) return b;
        if (b.size == 0) return a;
        S res;
        res.first = a.first;
        res.last = b.last;
        res.differences_gcd = std::gcd(std::gcd(a.differences_gcd, b.differences_gcd), b.first - a.last);
        res.size = a.size + b.size;
        return res;
    }
    static constexpr S e() { return S(); }
    static constexpr S mapping(const F& f, const S& x) {
        S res = x;
        if (res.size != 0) {
            res.first += f;
            res.last += f;
        }
        return res;
    }
    static constexpr F composition(const F& f, const F& g) { return f + g; }
    static constexpr F id() { return T(0); }
    static constexpr F inv(const F& f) { return -f; }
};

/** @brief 2 列への区間加算、各列の和と要素ごとの積の和 */
template <typename T = long long>
struct AddProductSum {
    struct S {
        T sum_a = T(0), sum_b = T(0), product_sum = T(0);
        constexpr S() = default;
        constexpr S(const T& a, const T& b) : sum_a(a), sum_b(b), product_sum(a * b) {}
        constexpr S(const std::array<T, 2>& x) : S(x[0], x[1]) {}
    };
    using F = std::array<T, 2>;
    static constexpr S op(const S& a, const S& b) {
        S res;
        res.sum_a = a.sum_a + b.sum_a;
        res.sum_b = a.sum_b + b.sum_b;
        res.product_sum = a.product_sum + b.product_sum;
        return res;
    }
    static constexpr S e() { return S(); }
    static constexpr S mapping(const F& f, const S& x, long long sz) {
        S res;
        res.sum_a = x.sum_a + f[0] * T(sz);
        res.sum_b = x.sum_b + f[1] * T(sz);
        res.product_sum = x.product_sum + f[0] * x.sum_b + f[1] * x.sum_a + f[0] * f[1] * T(sz);
        return res;
    }
    static constexpr F composition(const F& f, const F& g) { return {f[0] + g[0], f[1] + g[1]}; }
    static constexpr F id() { return {T(0), T(0)}; }
    static constexpr F inv(const F& f) { return {-f[0], -f[1]}; }
};

/**
 * @brief 区間の位置 i に f[0] + f[1]*i + ... + f[K]*i^K を加算、区間和
 * 整数の因子を約分して二項係数を求めるので、偶数の法の modint でも使える
 */
template <typename T = long long, long long K = 2>
struct PolynomialAddSum : monoid::Sum<T> {
    static_assert(K >= 0);
    using S = T;
    using F = std::array<T, K + 1>;

   private:
    // [0, n) の添字の 0 乗和から K 乗和。整数の大きな積や T での除算は使わない。
    static std::array<T, K + 1> index_power_sums(long long n, long long degree) {
        assert(0 <= degree && degree <= K);
        std::array<T, K + 2> binom{};
        std::array<long long, K + 1> factors{};
        for (long long k = 1; k <= K + 1 && k <= degree + 1 && k <= n; ++k) {
            factors[k - 1] = n - k + 1;
            long long divisor = k;
            for (long long j = 0; j < k && divisor > 1; ++j) {
                long long g = std::gcd(factors[j], divisor);
                factors[j] /= g;
                divisor /= g;
            }
            assert(divisor == 1);
            T value(1);
            for (long long j = 0; j < k; ++j) value *= T(factors[j]);
            binom[k] = value;
        }
        // i^k = sum_j Stirling2(k, j) * j! * C(i, j)
        // sum_{i=0}^{n-1} C(i, j) = C(n, j+1)
        std::array<T, K + 1> stirling{}, factorial{}, sums{};
        stirling[0] = factorial[0] = T(1);
        for (long long j = 1; j <= K && j <= degree; ++j) factorial[j] = factorial[j - 1] * T(j);
        for (long long k = 0; k <= K && k <= degree; ++k) {
            for (long long j = 0; j <= k; ++j) sums[k] += stirling[j] * factorial[j] * binom[j + 1];
            if (k < K && k < degree) {
                for (long long j = k + 1; j >= 1; --j) stirling[j] = T(j) * stirling[j] + stirling[j - 1];
                stirling[0] = T(0);
            }
        }
        return sums;
    }

   public:
    static S mapping(const F& f, const S& x, long long l, long long r) {
        assert(0 <= l && l <= r);
        if (l == r) return x;
        long long degree = K;
        while (degree >= 0 && f[degree] == T(0)) --degree;
        if (degree < 0) return x;
        auto left = index_power_sums(l, degree), right = index_power_sums(r, degree);
        S res = x;
        for (long long k = 0; k <= degree; ++k) res += f[k] * (right[k] - left[k]);
        return res;
    }
    static constexpr F composition(const F& f, const F& g) {
        F res{};
        for (long long k = 0; k <= K; ++k) res[k] = f[k] + g[k];
        return res;
    }
    static constexpr F id() { return F{}; }
    static constexpr F inv(const F& f) {
        F res{};
        for (long long k = 0; k <= K; ++k) res[k] = -f[k];
        return res;
    }
};

/**
 * @brief 成分の並べ替え (monoid::Mapping)、モノイド M の N 個の直積
 *
 * 要素は M の要素を N 個並べた std::array で、積は成分ごとに M::op をとる
 * 作用素 f は monoid::Mapping<N> の要素で、mapping(f, x)[i] = x[f[i]] (成分 i に x の成分 f[i] を持ってくる)
 * f は全単射でなくてよい。例えば N = 3 で f = {1, 1, 2} は成分 0 を成分 1 で上書きする
 * 積が成分ごとなので、M によらず作用は積と可換になる
 *
 * @tparam M static な op, e を持つモノイド
 * @tparam N 成分の個数
 */
template <typename M, std::size_t N>
struct Rearrange {
    using S = std::array<typename M::S, N>;
    using F = typename monoid::Mapping<N>::S;
    static constexpr S op(const S& a, const S& b) {
        S res{};
        for (std::size_t i = 0; i < N; i++) res[i] = M::op(a[i], b[i]);
        return res;
    }
    static constexpr S e() {
        S res{};
        for (std::size_t i = 0; i < N; i++) res[i] = M::e();
        return res;
    }
    static constexpr S mapping(const F& f, const S& x) {
        S res{};
        for (std::size_t i = 0; i < N; i++) res[i] = x[f[i]];
        return res;
    }
    // mapping(f, mapping(g, x))[i] = x[g[f[i]]] なので、Mapping の積としては g∘f になる
    static constexpr F composition(const F& f, const F& g) { return monoid::Mapping<N>::op(g, f); }
    static constexpr F id() { return monoid::Mapping<N>::e(); }
    // 成分 i と j を入れ替える作用素
    static constexpr F swap(long long i, long long j) { return monoid::Mapping<N>::swap(i, j); }
};

}  // namespace acted_monoid

/**
 * @brief 関数オブジェクトから実行時に作る作用素付きモノイド
 * ラムダ式を使える
 *
 * @tparam T 要素の型
 * @tparam Op 積の関数オブジェクトの型
 * @tparam U 作用素の型
 * @tparam Mapping 作用素を適用する関数オブジェクトの型 引数は (f, x), (f, x, sz), (f, x, l, r) のいずれか
 * @tparam Composition 作用素の合成の関数オブジェクトの型
 */
template <typename T, typename Op, typename U, typename Mapping, typename Composition>
struct ActedMonoid {
    using S = T;
    using F = U;
    Op op_object;
    S identity;
    Mapping mapping_object;
    Composition composition_object;
    F lazy_identity;
    ActedMonoid() = default;
    constexpr ActedMonoid(Op op, const S& e, Mapping mapping, Composition composition, const F& id)
        : op_object(std::move(op)), identity(e), mapping_object(std::move(mapping)), composition_object(std::move(composition)), lazy_identity(id) {}
    constexpr S op(const S& a, const S& b) const { return op_object(a, b); }
    constexpr S e() const { return identity; }
    constexpr auto mapping(const F& f, const S& x, long long l, long long r) const {
        if constexpr (std::is_invocable_v<const Mapping&, const F&, const S&, long long, long long>) {
            return mapping_object(f, x, l, r);
        } else if constexpr (std::is_invocable_v<const Mapping&, const F&, const S&, long long>) {
            return mapping_object(f, x, r - l);
        } else {
            return mapping_object(f, x);
        }
    }
    constexpr F composition(const F& f, const F& g) const { return composition_object(f, g); }
    constexpr F id() const { return lazy_identity; }
};
template <typename Op, typename T, typename Mapping, typename Composition, typename U>
ActedMonoid(Op, T, Mapping, Composition, U) -> ActedMonoid<T, Op, U, Mapping, Composition>;
