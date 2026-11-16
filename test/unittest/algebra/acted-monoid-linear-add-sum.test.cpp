#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include <cassert>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

#include "../../../src/algebra/acted-monoid.hpp"
#include "../../../src/data_structures/dual-segtree.hpp"
#include "../../../src/data_structures/dynamic-lazy-segtree.hpp"
#include "../../../src/data_structures/imos.hpp"
#include "../../../src/data_structures/lazy-segtree.hpp"
#include "../../../src/math/modint.hpp"

template <typename T>
void test_random() {
    using A = acted_monoid::LinearAddSum<T>;
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 80; ++rep) {
        long long n = rng() % 35 + 1;
        std::vector<T> values(n, T(0));
        LazySegTree<A> seg(values);
        DynamicLazySegTree<A> dynamic(n);
        DualSegTree<A> dual(values);
        Imos<A> imos(values);
        for (int step = 0; step < 150; ++step) {
            long long l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            T first(static_cast<long long>(rng() % 31) - 15);
            T diff(static_cast<long long>(rng() % 11) - 5);
            auto f = A::arithmetic_progression(l, first, diff);
            if (step % 3 != 0) {
                seg.apply(l, r, f);
                dynamic.apply(l, r, f);
                dual.apply(l, r, f);
                imos.apply(l, r, f);
                for (long long i = l; i < r; ++i) values[i] += first + diff * T(i - l);
            } else {
                T sum(0);
                for (long long i = l; i < r; ++i) sum += values[i];
                assert(seg.prod(l, r) == sum);
                assert(dynamic.prod(l, r) == sum);
            }
            if (l < n) {
                assert(seg.get(l) == values[l]);
                assert(dynamic.get(l) == values[l]);
                assert(dual.get(l) == values[l]);
                assert(imos.get(l) == values[l]);
            }
        }
        for (long long i = 0; i < n; ++i) {
            assert(seg.get(i) == values[i]);
            assert(dynamic.get(i) == values[i]);
            assert(dual.get(i) == values[i]);
            assert(imos.get(i) == values[i]);
        }
    }
}

template <typename T>
void test_mapping() {
    using A = acted_monoid::LinearAddSum<T>;
    const typename A::F f{T(3), T(-2)}, g{T(-7), T(4)};
    for (long long l = 0; l < 20; ++l)
        for (long long r = l; r < 20; ++r) {
            T expected(5);
            for (long long i = l; i < r; ++i) expected += T(3) - T(2) * T(i);
            assert(A::mapping(f, T(5), l, r) == expected);
            assert(A::mapping(A::id(), T(5), l, r) == T(5));
            assert(A::mapping(A::composition(f, g), T(5), l, r) == A::mapping(f, A::mapping(g, T(5), l, r), l, r));
            assert(A::mapping(A::inv(f), expected, l, r) == T(5));
            long long m = (l + r) / 2;
            assert(A::mapping(f, T(0), l, r) == A::mapping(f, T(0), l, m) + A::mapping(f, T(0), m, r));
        }
    // l+r や添字の総和が long long に収まらなくても T 側で計算する。
    const long long hi = std::numeric_limits<long long>::max();
    for (long long width : {0LL, 1LL, 2LL, 3LL, 10LL}) {
        long long lo = hi - width;
        __int128_t sum = static_cast<__int128_t>(lo) * width + static_cast<__int128_t>(width) * (width - 1) / 2;
        T expected = T(3) * T(width) - T(2) * T(static_cast<__uint128_t>(sum));
        assert(A::mapping(f, T(0), lo, hi) == expected);
    }
    const long long n = 1000000000000LL;
    DynamicLazySegTree<A> large(n);
    large.apply(n - 10, n, A::arithmetic_progression(n - 10, T(2), T(3)));
    assert(large.prod(n - 10, n) == T(155));
    assert(large.get(n - 1) == T(29));
}

int main() {
    using A = acted_monoid::LinearAddSum<>;
    static_assert(A::mapping(A::arithmetic_progression(2, 3, 4), 0, 2, 5) == 21);
    test_random<long long>();
    test_random<modint998244353>();
    test_random<static_modint<12>>();
    test_mapping<__int128_t>();
    test_mapping<modint998244353>();
    test_mapping<static_modint<12>>();
    LazySegTree<A> empty(0);
    empty.apply(0, 0, {3, 4});
    assert(empty.prod(0, 0) == 0);
    std::cout << "Hello World\n";
}
