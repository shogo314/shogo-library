#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include <cassert>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

#include "../../../src/algebra/beats-acted-monoid.hpp"
#include "../../../src/data_structures/segtree-beats.hpp"
#include "../../../src/math/modint.hpp"

std::mt19937_64 rng(314159);

template <long long K, typename U>
void test_power_sum() {
    using A = beats_acted_monoid::ChminChmaxAddPowerSum<long long, K, U>;
    for (int rep = 0; rep < 100; ++rep) {
        int n = rng() % 40;
        std::vector<long long> values(n);
        for (auto& x : values) x = static_cast<long long>(rng() % 21) - 10;
        SegTreeBeats<A> seg(values);
        for (int step = 0; step < 250; ++step) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            long long b = static_cast<long long>(rng() % 31) - 15;
            int type = rng() % 7;
            if (type < 4) {
                auto f = type == 0 ? A::chmin(b) : type == 1 ? A::chmax(b)
                                               : type == 2   ? A::add(b)
                                                             : A::update(b);
                seg.apply(l, r, f);
                for (int i = l; i < r; ++i) values[i] = f(values[i]);
            } else if (type == 4 && l < n) {
                seg.set(l, typename A::S(b));
                values[l] = b;
            } else {
                auto s = seg.prod(l, r);
                std::array<U, K + 1> expected{};
                long long lo = A::highest, hi = A::lowest;
                for (int i = l; i < r; ++i) {
                    lo = std::min(lo, values[i]);
                    hi = std::max(hi, values[i]);
                    U p(1);
                    for (long long j = 0; j <= K; ++j) {
                        expected[j] += p;
                        p *= U(values[i]);
                    }
                }
                for (long long j = 0; j <= K; ++j) assert(s[j] == expected[j]);
                assert(s.min1 == lo && s.max1 == hi);
            }
        }
        for (int i = 0; i < n; ++i) {
            auto s = seg.get(i);
            U p(1);
            for (long long j = 0; j <= K; ++j) {
                assert(s[j] == p);
                p *= U(values[i]);
            }
        }
    }
}

template <typename T>
void test_bitwise() {
    using A = beats_acted_monoid::BitwiseAndOrMinMax<T>;
    for (int rep = 0; rep < 100; ++rep) {
        int n = rng() % 40;
        std::vector<T> values(n);
        for (auto& x : values) x = static_cast<T>(rng()) & A::mask;
        SegTreeBeats<A> seg(values);
        for (int step = 0; step < 300; ++step) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            T b = static_cast<T>(rng()) & A::mask;
            int type = rng() % 5;
            if (type < 2) {
                seg.apply(l, r, type == 0 ? A::bit_and(b) : A::bit_or(b));
                for (int i = l; i < r; ++i) values[i] = type == 0 ? values[i] & b : values[i] | b;
            } else if (type == 2 && l < n) {
                seg.set(l, typename A::S(b));
                values[l] = b;
            } else {
                auto s = seg.prod(l, r);
                T lo = A::mask, hi = 0, ba = A::mask, bo = 0;
                for (int i = l; i < r; ++i) {
                    lo = std::min(lo, values[i]);
                    hi = std::max(hi, values[i]);
                    ba &= values[i];
                    bo |= values[i];
                }
                assert(s.min == lo && s.max == hi && s.bit_and == ba && s.bit_or == bo && s.size == r - l);
            }
        }
    }
}

template <typename A, bool is_div>
void test_reducing() {
    for (int rep = 0; rep < 150; ++rep) {
        int n = rng() % 40;
        std::vector<long long> values(n);
        for (auto& x : values) x = rng() % 100000;
        SegTreeBeats<A> seg(values);
        for (int step = 0; step < 300; ++step) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            long long b = rng() % 100000;
            int type = rng() % 6;
            if (type == 0) {
                seg.apply(l, r, A::update(b));
                for (int i = l; i < r; ++i) values[i] = b;
            } else if (type < 4) {
                if constexpr (is_div) {
                    b = rng() % 20 + 1;
                    seg.apply(l, r, A::div(b));
                    for (int i = l; i < r; ++i) values[i] /= b;
                } else {
                    // 0 と 1 も混ぜ、恒等作用・0 からの増加・多種類からの一様化を確かめる。
                    if (type == 1) b = rng() % 2;
                    seg.apply(l, r, A::gcd(b));
                    for (int i = l; i < r; ++i) values[i] = std::gcd(values[i], b);
                }
            } else if (type == 4 && l < n) {
                seg.set(l, typename A::S(b));
                values[l] = b;
            } else {
                auto s = seg.prod(l, r);
                long long sum = 0, lo = std::numeric_limits<long long>::max(), hi = 0;
                for (int i = l; i < r; ++i) {
                    sum += values[i];
                    lo = std::min(lo, values[i]);
                    hi = std::max(hi, values[i]);
                }
                assert(s.sum == decltype(s.sum)(sum));
                assert(s.min == lo && s.max == hi && s.size == r - l);
            }
        }
        for (int i = 0; i < n; ++i) assert(seg.get(i).sum == decltype(seg.get(i).sum)(values[i]));
    }
}

void test_limits() {
    constexpr long long m = std::numeric_limits<long long>::max();
    using D = beats_acted_monoid::DivUpdateSum<long long, __int128_t>;
    // 除数の積が型の上限を越える合成と、0 の代入を区別する。
    SegTreeBeats<D> div(std::vector<long long>(8, m));
    div.apply(0, 8, D::div(m));
    div.apply(0, 8, D::div(2));
    assert(div.prod(1, 7).sum == 0);
    div.apply(0, 8, D::update(m));
    div.apply(0, 8, D::div(1));
    assert(div.prod(1, 7).sum == static_cast<__int128_t>(m) * 6);
    using G = beats_acted_monoid::GcdUpdateSum<long long, __int128_t>;
    SegTreeBeats<G> gcd({G::S(m), G::S(m - 1), G::S(0)});
    assert(gcd.prod(0, 2).lcm_overflow);
    gcd.apply(0, 3, G::gcd(6));
    assert(gcd.get(0).sum == 1 && gcd.get(1).sum == 6 && gcd.get(2).sum == 6);
    gcd.apply(0, 3, G::update(0));
    gcd.apply(0, 3, G::gcd(m));
    assert(gcd.prod(1, 3).sum == static_cast<__int128_t>(m) * 2);
    using B = beats_acted_monoid::BitwiseAndOrMinMax<unsigned long long>;
    SegTreeBeats<B> bits({B::S(0), B::S(B::mask)});
    bits.apply(0, 2, B::bit_or(B::mask));
    assert(bits.get(0).min == B::mask);
    bits.apply(0, 2, B::bit_and(0));
    assert(bits.get(1).max == 0);
    using P = beats_acted_monoid::ChminChmaxAddPowerSum<long long, 4, modint998244353>;
    SegTreeBeats<P> power({P::S(-1000000000LL), P::S(1000000000LL), P::S(3)});
    power.apply(0, 3, P::update(-1000000000LL));
    modint998244353 v(-1000000000LL);
    assert(power.prod(1, 3)[4] == v * v * v * v * modint998244353(2));
}

// 除数の積が型の上限を超える合成も、各更新を順に適用した値と比較する。
template <typename T, bool is_div>
void test_composition() {
    using A = std::conditional_t<is_div, beats_acted_monoid::DivUpdateSum<T, __int128_t>, beats_acted_monoid::GcdUpdateSum<T, __int128_t>>;
    const T limit = std::numeric_limits<T>::max();
    std::vector<T> xs = {T(0), T(1), T(2), T(3), static_cast<T>(limit / 2), static_cast<T>(limit - 1), limit};
    std::vector<typename A::F> fs = {A::id()};
    for (T x : xs) {
        fs.push_back(A::update(x));
        if constexpr (is_div) {
            if (x != 0) fs.push_back(A::div(x));
        } else {
            fs.push_back(A::gcd(x));
        }
    }
    auto eval = [](const typename A::F& f, T x) {
        auto [fail, result] = A::mapping(f, typename A::S(x));
        assert(!fail);
        return result.min;
    };
    for (const auto& f : fs)
        for (const auto& g : fs)
            for (T x : xs) {
                assert(eval(A::composition(f, g), x) == eval(f, eval(g, x)));
            }
    auto s = A::op(typename A::S(1), typename A::S(2));
    assert(!A::mapping(A::id(), s).first);
}

int main() {
    test_power_sum<0, long long>();
    test_power_sum<2, long long>();
    test_power_sum<5, modint998244353>();
    test_bitwise<long long>();
    test_bitwise<unsigned long long>();
    test_bitwise<unsigned char>();
    test_reducing<beats_acted_monoid::DivUpdateSum<>, true>();
    test_reducing<beats_acted_monoid::GcdUpdateSum<>, false>();
    test_reducing<beats_acted_monoid::DivUpdateSum<long long, modint998244353>, true>();
    test_reducing<beats_acted_monoid::GcdUpdateSum<long long, modint998244353>, false>();
    test_limits();
    test_composition<long long, true>();
    test_composition<unsigned long long, true>();
    test_composition<unsigned char, true>();
    test_composition<long long, false>();
    test_composition<unsigned long long, false>();
    test_composition<unsigned char, false>();
    std::cout << "Hello World\n";
}
