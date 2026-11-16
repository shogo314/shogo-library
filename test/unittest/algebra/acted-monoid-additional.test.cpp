#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include <cassert>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

#include "../../../src/algebra/acted-monoid.hpp"
#include "../../../src/data_structures/dynamic-lazy-segtree.hpp"
#include "../../../src/data_structures/lazy-segtree.hpp"
#include "../../../src/math/modint.hpp"

std::mt19937_64 rng(314159);
long long small() { return static_cast<long long>(rng() % 11) - 5; }

template <typename T, long long K>
void test_affine() {
    using A = acted_monoid::AffinePowerSum<T, K>;
    using M = acted_monoid::AffineMinMax<>;
    for (int rep = 0; rep < 60; ++rep) {
        long long n = rng() % 25;
        std::vector<T> a(n);
        std::vector<long long> integer(n);
        for (long long i = 0; i < n; ++i) a[i] = T(integer[i] = small());
        LazySegTree<A> powers(a);
        LazySegTree<M> extrema(integer);
        for (int step = 0; step < 120; ++step) {
            long long l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            if (rng() % 3) {
                // -1, 0, 1 の倍率で符号反転・代入・加算を混ぜ、整数版もあふれないようにする。
                long long mul = static_cast<long long>(rng() % 3) - 1, add = small();
                powers.apply(l, r, {T(mul), T(add)});
                extrema.apply(l, r, {mul, add});
                for (long long i = l; i < r; ++i) {
                    a[i] = T(mul) * a[i] + T(add);
                    integer[i] = mul * integer[i] + add;
                }
            } else {
                auto s = powers.prod(l, r);
                std::array<T, K + 1> expected{};
                long long lo = std::numeric_limits<long long>::max(), hi = std::numeric_limits<long long>::lowest();
                for (long long i = l; i < r; ++i) {
                    T p(1);
                    for (long long k = 0; k <= K; ++k) {
                        expected[k] += p;
                        p *= a[i];
                    }
                    lo = std::min(lo, integer[i]);
                    hi = std::max(hi, integer[i]);
                }
                for (long long k = 0; k <= K; ++k) assert(s[k] == expected[k]);
                assert(extrema.prod(l, r) == typename M::S(lo, hi));
            }
        }
    }
    // 合成順が区別できる倍率と平行移動を使い、同じ状態に順次作用させる。
    const typename A::F f{T(2), T(3)}, g{T(-3), T(4)};
    auto s = A::op(typename A::S(T(2)), typename A::S(T(-1)));
    auto composed = A::mapping(A::composition(f, g), s);
    auto sequential = A::mapping(f, A::mapping(g, s));
    auto identity = A::mapping(A::id(), s);
    for (long long k = 0; k <= K; ++k) {
        assert(composed[k] == sequential[k]);
        assert(identity[k] == s[k]);
    }
    const typename M::F mf{-2, 3}, mg{3, -4};
    assert(M::mapping(M::composition(mf, mg), {-2, 5}) == M::mapping(mf, M::mapping(mg, {-2, 5})));
    assert(M::mapping(mf, M::e()) == M::e());
    assert(M::mapping(M::id(), {-2, 5}) == typename M::S(-2, 5));
}

void test_gcd() {
    using A = acted_monoid::AddGcd<>;
    assert(A::e().val() == 0);
    for (int rep = 0; rep < 100; ++rep) {
        long long n = rng() % 30 + 1;
        std::vector<long long> a(n);
        for (auto& x : a) x = small();
        LazySegTree<A> seg(a);
        for (int step = 0; step < 150; ++step) {
            long long l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            long long v = small();
            if (step % 3 == 0) {
                seg.apply(l, r, v);
                for (long long i = l; i < r; ++i) a[i] += v;
            } else if (step % 3 == 1) {
                long long i = rng() % n;
                seg.set(i, A::S(v));
                a[i] = v;
            } else {
                auto s = seg.prod(l, r);
                long long expected = 0;
                for (long long i = l; i < r; ++i) expected = std::gcd(expected, a[i]);
                assert(s.val() == expected && s.size == r - l);
                if (l < r) assert(s.first == a[l] && s.last == a[r - 1]);
                long long m = (l + r) / 2;
                auto joined = A::op(seg.prod(l, m), seg.prod(m, r));
                assert(joined.val() == expected && joined.first == s.first && joined.last == s.last);
            }
        }
    }
    const auto s = A::op(A::S(-15), A::S(25));
    assert(A::mapping(A::id(), s).val() == 5);
    assert(A::mapping(A::composition(2, 3), s).val() == A::mapping(2, A::mapping(3, s)).val());
    assert(A::mapping(A::inv(7), A::mapping(7, s)).val() == s.val());
    assert(A::mapping(7, A::e()).size == 0);
}

template <typename T>
void test_product() {
    using A = acted_monoid::AddProductSum<T>;
    for (int rep = 0; rep < 80; ++rep) {
        long long n = rng() % 25;
        std::vector<std::array<T, 2>> a(n);
        for (auto& x : a) x = {T(small()), T(small())};
        LazySegTree<A> seg(a);
        for (int step = 0; step < 150; ++step) {
            long long l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            typename A::F f{T(small()), T(small())};
            if (rng() % 2) {
                seg.apply(l, r, f);
                for (long long i = l; i < r; ++i)
                    for (int j = 0; j < 2; ++j) a[i][j] += f[j];
            } else {
                T sa(0), sb(0), sp(0);
                for (long long i = l; i < r; ++i) {
                    sa += a[i][0];
                    sb += a[i][1];
                    sp += a[i][0] * a[i][1];
                }
                auto s = seg.prod(l, r);
                assert(s.sum_a == sa && s.sum_b == sb && s.product_sum == sp);
            }
        }
    }
    typename A::S s(T(2), T(-3));
    const typename A::F f{T(4), T(5)}, g{T(-2), T(3)};
    auto one = A::mapping(A::composition(f, g), s, 1), two = A::mapping(f, A::mapping(g, s, 1), 1);
    assert(one.product_sum == two.product_sum && one.sum_a == two.sum_a && one.sum_b == two.sum_b);
    auto back = A::mapping(A::inv(f), A::mapping(f, s, 1), 1);
    assert(back.product_sum == s.product_sum && back.sum_a == s.sum_a && back.sum_b == s.sum_b);
    assert(A::mapping(A::id(), s, 1).product_sum == s.product_sum);
}

template <typename T, long long K>
void test_polynomial() {
    using A = acted_monoid::PolynomialAddSum<T, K>;
    for (int rep = 0; rep < 35; ++rep) {
        long long n = rng() % 20 + 1;
        std::vector<T> a(n);
        for (auto& x : a) x = T(small());
        LazySegTree<A> seg(a);
        for (int step = 0; step < 80; ++step) {
            long long l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            typename A::F f{};
            for (auto& x : f) x = T(small());
            if (rng() % 2) {
                seg.apply(l, r, f);
                for (long long i = l; i < r; ++i) {
                    T v(0);
                    for (long long k = K; k >= 0; --k) v = v * T(i) + f[k];
                    a[i] += v;
                }
            } else {
                T expected(0);
                for (long long i = l; i < r; ++i) expected += a[i];
                assert(seg.prod(l, r) == expected);
            }
        }
    }
    typename A::F f{}, g{};
    for (long long k = 0; k <= K; ++k) f[k] = T(k + 1), g[k] = T(-k - 2);
    for (long long l = 0; l < 8; ++l)
        for (long long r = l; r < 10; ++r) {
            assert(A::mapping(A::id(), T(7), l, r) == T(7));
            assert(A::mapping(A::composition(f, g), T(7), l, r) == A::mapping(f, A::mapping(g, T(7), l, r), l, r));
            assert(A::mapping(A::inv(f), A::mapping(f, T(7), l, r), l, r) == T(7));
        }
}

template <typename T>
void test_large_polynomial() {
    using A = acted_monoid::PolynomialAddSum<T, 6>;
    const typename A::F f{T(2), T(-3), T(5), T(7), T(-1), T(4), T(9)};
    const long long n = std::numeric_limits<long long>::max();
    for (long long width : {0LL, 1LL, 2LL, 9LL}) {
        T expected(0);
        for (long long i = n - width; i < n; ++i) {
            T value(0);
            for (long long k = 6; k >= 0; --k) value = value * T(i) + f[k];
            expected += value;
        }
        assert(A::mapping(f, T(0), n - width, n) == expected);
    }
    DynamicLazySegTree<A> seg(1000000000000LL);
    seg.apply(0, 1000000000000LL, f);
    const long long l = 999999999990LL, r = 999999999999LL;
    assert(seg.prod(l, r) == A::mapping(f, T(0), l, r));
}

int main() {
    {
        using A = acted_monoid::PolynomialAddSum<long long, 6>;
        const long long n = std::numeric_limits<long long>::max();
        assert(A::mapping(A::id(), 7, 0, n) == 7);
        assert(A::mapping({2, 0, 0, 0, 0, 0, 0}, 0, n - 3, n) == 6);
    }
    test_affine<long long, 2>();
    test_affine<modint998244353, 5>();
    test_affine<static_modint<12>, 3>();
    test_affine<long long, 0>();
    test_gcd();
    test_product<long long>();
    test_product<modint998244353>();
    test_product<static_modint<12>>();
    test_polynomial<long long, 0>();
    test_polynomial<long long, 3>();
    test_polynomial<modint998244353, 6>();
    test_polynomial<static_modint<12>, 6>();
    test_large_polynomial<modint998244353>();
    test_large_polynomial<static_modint<12>>();
    std::cout << "Hello World\n";
}
