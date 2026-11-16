#pragma once

/**
 * @file beats-acted-monoid.hpp
 * @brief Segment Tree Beats 用の作用素付きモノイド
 *
 * 作用素付きモノイド (algebra/acted-monoid.hpp) と同じメンバを持つが、
 * mapping は std::pair<bool, S> (作用に失敗したか, 作用後の値) を返す
 * data_structures/segtree-beats.hpp に渡して使う
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <limits>
#include <numeric>
#include <optional>
#include <type_traits>
#include <utility>

#include "monoid.hpp"

namespace beats_acted_monoid {

/**
 * @brief 区間 chmin、区間和・最大値
 *
 * 作用素は chmin する値 (x <- min(x, f))
 * S(x) で値 x の1要素から作り、sum, max1 で区間和・最大値を取得する
 * 空の区間では max1 = numeric_limits<T>::lowest()
 * ChminChmaxAddSum より軽い
 *
 * @tparam T 値の型
 */
template <typename T>
struct ChminSum {
    static constexpr T lowest = std::numeric_limits<T>::lowest();

    struct S {
        T sum;
        T max1, max2;       // 最大値、2番目の最大値 (なければ lowest)
        long long max_cnt;  // 最大値の個数
        constexpr S() : sum(0), max1(lowest), max2(lowest), max_cnt(0) {}
        constexpr S(const T& x) : sum(x), max1(x), max2(lowest), max_cnt(1) {}
    };
    using F = T;

    static constexpr S op(const S& a, const S& b) {
        S res;
        res.sum = a.sum + b.sum;
        if (a.max1 == b.max1) {
            res.max1 = a.max1;
            res.max_cnt = a.max_cnt + b.max_cnt;
            res.max2 = std::max(a.max2, b.max2);
        } else if (a.max1 > b.max1) {
            res.max1 = a.max1;
            res.max_cnt = a.max_cnt;
            res.max2 = std::max(a.max2, b.max1);
        } else {
            res.max1 = b.max1;
            res.max_cnt = b.max_cnt;
            res.max2 = std::max(a.max1, b.max2);
        }
        return res;
    }
    static constexpr S e() { return S(); }
    static constexpr std::pair<bool, S> mapping(const F& f, const S& x) {
        if (x.max1 <= f) return {false, x};
        // 最大値だけが変わる (値が 1 種類なら f = lowest でも成功させる)
        if (x.max2 < f || x.max2 == lowest) {
            S res = x;
            res.sum -= (x.max1 - f) * T(x.max_cnt);
            res.max1 = f;
            return {false, res};
        }
        return {true, x};
    }
    static constexpr F composition(const F& f, const F& g) { return std::min(f, g); }
    static constexpr F id() { return std::numeric_limits<T>::max(); }
};

/**
 * @brief 区間 chmax、区間和・最小値
 *
 * 作用素は chmax する値 (x <- max(x, f))
 * S(x) で値 x の1要素から作り、sum, min1 で区間和・最小値を取得する
 * 空の区間では min1 = numeric_limits<T>::max()
 * ChminChmaxAddSum より軽い
 *
 * @tparam T 値の型
 */
template <typename T>
struct ChmaxSum {
    static constexpr T highest = std::numeric_limits<T>::max();

    struct S {
        T sum;
        T min1, min2;       // 最小値、2番目の最小値 (なければ highest)
        long long min_cnt;  // 最小値の個数
        constexpr S() : sum(0), min1(highest), min2(highest), min_cnt(0) {}
        constexpr S(const T& x) : sum(x), min1(x), min2(highest), min_cnt(1) {}
    };
    using F = T;

    static constexpr S op(const S& a, const S& b) {
        S res;
        res.sum = a.sum + b.sum;
        if (a.min1 == b.min1) {
            res.min1 = a.min1;
            res.min_cnt = a.min_cnt + b.min_cnt;
            res.min2 = std::min(a.min2, b.min2);
        } else if (a.min1 < b.min1) {
            res.min1 = a.min1;
            res.min_cnt = a.min_cnt;
            res.min2 = std::min(a.min2, b.min1);
        } else {
            res.min1 = b.min1;
            res.min_cnt = b.min_cnt;
            res.min2 = std::min(a.min1, b.min2);
        }
        return res;
    }
    static constexpr S e() { return S(); }
    static constexpr std::pair<bool, S> mapping(const F& f, const S& x) {
        if (x.min1 >= f) return {false, x};
        // 最小値だけが変わる (値が 1 種類なら f = highest でも成功させる)
        if (x.min2 > f || x.min2 == highest) {
            S res = x;
            res.sum += (f - x.min1) * T(x.min_cnt);
            res.min1 = f;
            return {false, res};
        }
        return {true, x};
    }
    static constexpr F composition(const F& f, const F& g) { return std::max(f, g); }
    static constexpr F id() { return std::numeric_limits<T>::lowest(); }
};

/**
 * @brief 区間 chmin・chmax・加算・代入、区間和・最大値・最小値
 *
 * 作用素 F = ClampAdd<T>{lb, ub, add} は x <- clamp(x + add, lb, ub) を表す (lb <= ub)
 * chmin(b), chmax(b), add(b), update(b) で作る
 * S(x) で値 x の1要素から作り、sum, max1, min1 で区間和・最大値・最小値を取得する
 * 空の区間では max1 = numeric_limits<T>::lowest(), min1 = numeric_limits<T>::max()
 *
 * @tparam T 値の型 (符号付き整数を想定する)
 */
template <typename T>
struct ChminChmaxAddSum {
    static constexpr T lowest = std::numeric_limits<T>::lowest();
    static constexpr T highest = std::numeric_limits<T>::max();

    struct S {
        T sum;
        T max1, max2;                // 最大値、2番目の最大値 (なければ lowest)
        T min1, min2;                // 最小値、2番目の最小値 (なければ highest)
        long long max_cnt, min_cnt;  // 最大値・最小値の個数
        constexpr S() : sum(0), max1(lowest), max2(lowest), min1(highest), min2(highest), max_cnt(0), min_cnt(0) {}
        constexpr S(const T& x) : sum(x), max1(x), max2(lowest), min1(x), min2(highest), max_cnt(1), min_cnt(1) {}
    };
    using F = ClampAdd<T>;

    static constexpr F chmin(const T& b) { return {lowest, b, T(0)}; }
    static constexpr F chmax(const T& b) { return {b, highest, T(0)}; }
    static constexpr F add(const T& b) { return {lowest, highest, b}; }
    static constexpr F update(const T& b) { return {b, b, T(0)}; }

    static constexpr S op(const S& a, const S& b) {
        S res;
        res.sum = a.sum + b.sum;
        if (a.max1 == b.max1) {
            res.max1 = a.max1;
            res.max_cnt = a.max_cnt + b.max_cnt;
            res.max2 = std::max(a.max2, b.max2);
        } else if (a.max1 > b.max1) {
            res.max1 = a.max1;
            res.max_cnt = a.max_cnt;
            res.max2 = std::max(a.max2, b.max1);
        } else {
            res.max1 = b.max1;
            res.max_cnt = b.max_cnt;
            res.max2 = std::max(a.max1, b.max2);
        }
        if (a.min1 == b.min1) {
            res.min1 = a.min1;
            res.min_cnt = a.min_cnt + b.min_cnt;
            res.min2 = std::min(a.min2, b.min2);
        } else if (a.min1 < b.min1) {
            res.min1 = a.min1;
            res.min_cnt = a.min_cnt;
            res.min2 = std::min(a.min2, b.min1);
        } else {
            res.min1 = b.min1;
            res.min_cnt = b.min_cnt;
            res.min2 = std::min(a.min1, b.min2);
        }
        return res;
    }
    static constexpr S e() { return S(); }
    static constexpr std::pair<bool, S> mapping(const F& f, const S& x, long long sz) {
        if (x.max_cnt == 0) return {false, x};
        S res = x;
        // 加算 (番兵には足さない)
        res.sum += f.add * T(sz);
        res.max1 += f.add;
        res.min1 += f.add;
        if (res.max2 != lowest) res.max2 += f.add;
        if (res.min2 != highest) res.min2 += f.add;
        // 値が 1 種類
        if (res.max1 == res.min1) {
            T v = std::clamp(res.max1, f.lb, f.ub);
            res.max1 = res.min1 = v;
            res.sum = v * T(sz);
            return {false, res};
        }
        // 値が 2 種類
        if (res.max1 == res.min2) {
            T hi = std::clamp(res.max1, f.lb, f.ub), lo = std::clamp(res.min1, f.lb, f.ub);
            if (hi == lo) {
                res.max1 = res.min1 = hi;
                res.max2 = lowest;
                res.min2 = highest;
                res.max_cnt = res.min_cnt = sz;
                res.sum = hi * T(sz);
            } else {
                res.max1 = res.min2 = hi;
                res.min1 = res.max2 = lo;
                res.sum = hi * T(res.max_cnt) + lo * T(res.min_cnt);
            }
            return {false, res};
        }
        // 値が 3 種類以上: 最大値と最小値だけが変わる場合以外は失敗
        if (f.ub <= res.max2 || f.lb >= res.min2) return {true, res};
        if (f.ub < res.max1) {
            res.sum -= (res.max1 - f.ub) * T(res.max_cnt);
            res.max1 = f.ub;
        }
        if (f.lb > res.min1) {
            res.sum += (f.lb - res.min1) * T(res.min_cnt);
            res.min1 = f.lb;
        }
        return {false, res};
    }
    // g を適用した後に f を適用する
    static constexpr F composition(const F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f, g); }
    static constexpr F id() { return {lowest, highest, T(0)}; }
};

/**
 * @brief 区間 chmin・chmax・加算・代入、0 乗和から K 乗和
 * @tparam T 比較する値の型 (符号付き整数)
 * @tparam K 最大次数
 * @tparam U 乗和の型 (modint も可)
 */
template <typename T = long long, long long K = 2, typename U = T>
struct ChminChmaxAddPowerSum {
    static_assert(K >= 0);
    static_assert(std::is_integral_v<T> && std::is_signed_v<T>);
    static constexpr T lowest = std::numeric_limits<T>::lowest();
    static constexpr T highest = std::numeric_limits<T>::max();
    struct S {
        std::array<U, K + 1> val{};
        T max1 = lowest, max2 = lowest, min1 = highest, min2 = highest;
        long long max_cnt = 0, min_cnt = 0;
        constexpr S() = default;
        constexpr S(const T& x) : max1(x), min1(x), max_cnt(1), min_cnt(1) {
            val[0] = U(1);
            for (long long i = 1; i <= K; ++i) val[i] = val[i - 1] * U(x);
        }
        constexpr const U& operator[](long long i) const {
            assert(0 <= i && i <= K);
            return val[i];
        }
    };
    using F = ClampAdd<T>;
    static constexpr F chmin(const T& b) { return {lowest, b, T(0)}; }
    static constexpr F chmax(const T& b) { return {b, highest, T(0)}; }
    static constexpr F add(const T& b) { return {lowest, highest, b}; }
    static constexpr F update(const T& b) { return {b, b, T(0)}; }
    static constexpr S op(const S& a, const S& b) {
        if (a.max_cnt == 0) return b;
        if (b.max_cnt == 0) return a;
        S res;
        for (long long i = 0; i <= K; ++i) res.val[i] = a.val[i] + b.val[i];
        res.max1 = std::max(a.max1, b.max1);
        res.max_cnt = (a.max1 == res.max1 ? a.max_cnt : 0) + (b.max1 == res.max1 ? b.max_cnt : 0);
        res.max2 = std::max(a.max1 == res.max1 ? a.max2 : a.max1, b.max1 == res.max1 ? b.max2 : b.max1);
        res.min1 = std::min(a.min1, b.min1);
        res.min_cnt = (a.min1 == res.min1 ? a.min_cnt : 0) + (b.min1 == res.min1 ? b.min_cnt : 0);
        res.min2 = std::min(a.min1 == res.min1 ? a.min2 : a.min1, b.min1 == res.min1 ? b.min2 : b.min1);
        return res;
    }
    static constexpr S e() { return S(); }
    static std::pair<bool, S> mapping(const F& f, const S& x, long long sz) {
        if (x.max_cnt == 0) return {false, x};
        // 全要素が同じ値になる場合は、加算や二項展開より先に処理する。
        T lo = std::clamp(x.min1 + f.add, f.lb, f.ub);
        T hi = std::clamp(x.max1 + f.add, f.lb, f.ub);
        if (lo == hi) {
            S res(lo);
            for (auto& v : res.val) v *= U(sz);
            res.max_cnt = res.min_cnt = sz;
            return {false, res};
        }
        S res = x;
        res.max1 += f.add;
        res.min1 += f.add;
        if (res.max2 != lowest) res.max2 += f.add;
        if (res.min2 != highest) res.min2 += f.add;
        if (res.max1 != res.min2 && (f.ub <= res.max2 || f.lb >= res.min2)) return {true, x};
        if (f.add != T(0)) {
            static const auto binom = [] {
                std::array<std::array<U, K + 1>, K + 1> c{};
                for (long long i = 0; i <= K; ++i) {
                    c[i][0] = c[i][i] = U(1);
                    for (long long j = 1; j < i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                }
                return c;
            }();
            std::array<U, K + 1> pw{};
            pw[0] = U(1);
            for (long long i = 1; i <= K; ++i) pw[i] = pw[i - 1] * U(f.add);
            res.val.fill(U(0));
            for (long long i = 0; i <= K; ++i)
                for (long long j = 0; j <= i; ++j) res.val[i] += binom[i][j] * pw[j] * x.val[i - j];
        }
        auto replace = [&](T before, T after, long long count) {
            U p(1), q(1);
            for (long long i = 1; i <= K; ++i) {
                p *= U(before);
                q *= U(after);
                res.val[i] += (q - p) * U(count);
            }
        };
        replace(res.max1, hi, res.max_cnt);
        replace(res.min1, lo, res.min_cnt);
        if (res.max1 == res.min2) {
            res.max2 = lo;
            res.min2 = hi;
        }
        res.max1 = hi;
        res.min1 = lo;
        return {false, res};
    }
    static constexpr F composition(const F& f, const F& g) { return monoid::ClampAddComposite<T>::op(f, g); }
    static constexpr F id() { return F(); }
};

/** @brief 非負整数への区間 AND・OR、区間最小値・最大値 */
template <typename T = long long>
struct BitwiseAndOrMinMax {
    static_assert(std::is_integral_v<T> && !std::is_same_v<T, bool>);
    static constexpr T mask = std::numeric_limits<T>::max();
    struct S {
        T min = mask, max = T(0), bit_and = mask, bit_or = T(0);
        long long size = 0;
        constexpr S() = default;
        constexpr S(T x) : min(x), max(x), bit_and(x), bit_or(x), size(1) { assert(x >= T(0)); }
    };
    struct F {
        T and_mask = mask, or_mask = T(0);
    };
    static constexpr F bit_and(T b) {
        assert(b >= T(0));
        return {b, T(0)};
    }
    static constexpr F bit_or(T b) {
        assert(b >= T(0));
        return {mask, b};
    }
    static constexpr S e() { return S(); }
    static constexpr S op(const S& a, const S& b) {
        if (a.size == 0) return b;
        if (b.size == 0) return a;
        S res;
        res.min = std::min(a.min, b.min);
        res.max = std::max(a.max, b.max);
        res.bit_and = a.bit_and & b.bit_and;
        res.bit_or = a.bit_or | b.bit_or;
        res.size = a.size + b.size;
        return res;
    }
    static constexpr std::pair<bool, S> mapping(const F& f, const S& x) {
        if (x.size == 0) return {false, x};
        T changed = static_cast<T>((mask ^ f.and_mask) | f.or_mask);
        if ((changed & (x.bit_and ^ x.bit_or)) != T(0)) return {true, x};
        S res = x;
        res.min = (res.min & f.and_mask) | f.or_mask;
        res.max = (res.max & f.and_mask) | f.or_mask;
        res.bit_and = (res.bit_and & f.and_mask) | f.or_mask;
        res.bit_or = (res.bit_or & f.and_mask) | f.or_mask;
        return {false, res};
    }
    static constexpr F composition(const F& f, const F& g) {
        return {static_cast<T>(g.and_mask & f.and_mask), static_cast<T>((g.or_mask & f.and_mask) | f.or_mask)};
    }
    static constexpr F id() { return F(); }
};

/** @brief 非負整数への区間整数除算・代入、区間和・最小値・最大値 */
template <typename T = long long, typename U = T>
struct DivUpdateSum {
    static_assert(std::is_integral_v<T> && !std::is_same_v<T, bool>);
    struct S {
        U sum = U(0);
        T min = std::numeric_limits<T>::max(), max = T(0);
        long long size = 0;
        constexpr S() = default;
        constexpr S(T x) : sum(U(x)), min(x), max(x), size(1) { assert(x >= T(0)); }
    };
    struct F {
        T divisor = T(1);
        std::optional<T> value;
    };
    static constexpr F div(T d) {
        assert(d >= T(1));
        return {d, std::nullopt};
    }
    static constexpr F update(T b) {
        assert(b >= T(0));
        return {T(1), b};
    }
    static constexpr S e() { return S(); }
    static constexpr S op(const S& a, const S& b) {
        S res;
        res.sum = a.sum + b.sum;
        res.size = a.size + b.size;
        res.min = std::min(a.min, b.min);
        res.max = std::max(a.max, b.max);
        return res;
    }
    static constexpr std::pair<bool, S> mapping(const F& f, const S& x) {
        if (x.size == 0 || (!f.value && f.divisor == T(1))) return {false, x};
        T lo = f.value ? *f.value : x.min / f.divisor;
        T hi = f.value ? *f.value : x.max / f.divisor;
        if (lo != hi) return {true, x};
        S res(lo);
        res.sum *= U(x.size);
        res.size = x.size;
        return {false, res};
    }
    static constexpr F composition(const F& f, const F& g) {
        if (f.value) return f;
        if (g.value) return update(*g.value / f.divisor);
        // 除数の積が値域を超えるなら、どの非負値も 0 になる。
        if (g.divisor > std::numeric_limits<T>::max() / f.divisor) return update(T(0));
        return div(g.divisor * f.divisor);
    }
    static constexpr F id() { return F(); }
};

/** @brief 非負整数への区間 gcd・代入、区間和・最小値・最大値 */
template <typename T = long long, typename U = T>
struct GcdUpdateSum {
    static_assert(std::is_integral_v<T> && !std::is_same_v<T, bool>);
    struct S {
        U sum = U(0);
        T min = std::numeric_limits<T>::max(), max = T(0), lcm = T(1);
        bool lcm_overflow = false;
        long long size = 0;
        constexpr S() = default;
        constexpr S(T x) : sum(U(x)), min(x), max(x), lcm(x), size(1) { assert(x >= T(0)); }
    };
    struct F {
        T factor = T(0);
        std::optional<T> value;
    };
    static constexpr F gcd(T b) {
        assert(b >= T(0));
        return {b, std::nullopt};
    }
    static constexpr F update(T b) {
        assert(b >= T(0));
        return {T(0), b};
    }
    static constexpr S e() { return S(); }
    static constexpr S op(const S& a, const S& b) {
        if (a.size == 0) return b;
        if (b.size == 0) return a;
        S res;
        res.sum = a.sum + b.sum;
        res.min = std::min(a.min, b.min);
        res.max = std::max(a.max, b.max);
        res.size = a.size + b.size;
        if (res.min == T(0)) {
            res.lcm = T(0);
        } else if (a.lcm_overflow || b.lcm_overflow) {
            res.lcm_overflow = true;
        } else {
            T v = a.lcm / std::gcd(a.lcm, b.lcm);
            if (v > std::numeric_limits<T>::max() / b.lcm)
                res.lcm_overflow = true;
            else
                res.lcm = v * b.lcm;
        }
        return res;
    }
    static constexpr std::pair<bool, S> mapping(const F& f, const S& x) {
        if (x.size == 0) return {false, x};
        if (!f.value) {
            if (f.factor == T(0)) return {false, x};
            if (x.min > T(0) && !x.lcm_overflow && f.factor % x.lcm == T(0)) return {false, x};
            if (x.min != x.max) return {true, x};
        }
        T value = f.value ? *f.value : std::gcd(x.min, f.factor);
        S res(value);
        res.sum *= U(x.size);
        res.size = x.size;
        return {false, res};
    }
    static constexpr F composition(const F& f, const F& g) {
        if (f.value) return f;
        if (g.value) return update(std::gcd(*g.value, f.factor));
        return gcd(std::gcd(f.factor, g.factor));
    }
    static constexpr F id() { return F(); }
};

}  // namespace beats_acted_monoid
