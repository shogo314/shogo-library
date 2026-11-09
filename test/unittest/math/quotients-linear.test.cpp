#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include <cassert>
#include <iostream>
#include <limits>
#include <random>
#include <vector>
#if __cplusplus >= 202002L
#include <ranges>
#endif

#include "../../../src/math/quotients.hpp"

void check(long long n, long long m, long long a, long long b, const std::vector<QuotientRange>& expected) {
    const auto range = enumerate_quotients_linear(n, m, a, b);
    const std::vector<QuotientRange> actual(range.begin(), range.end());
    assert(actual.size() == expected.size());
    for (long long i = 0; i < static_cast<long long>(actual.size()); i++) {
        assert(actual[i].q == expected[i].q && actual[i].l == expected[i].l && actual[i].r == expected[i].r);
    }
    long long i = 0;
    for_each_quotient_linear(n, m, a, b, [&](long long q, long long l, long long r) {
        assert(i < static_cast<long long>(expected.size()));
        assert(q == expected[i].q && l == expected[i].l && r == expected[i].r);
        i++;
    });
    assert(i == static_cast<long long>(expected.size()));
}

void check_naive(long long n, long long m, long long a, long long b) {
    std::vector<QuotientRange> expected;
    for (long long x = 0; x < n; x++) {
        const long long q = static_cast<long long>(floordiv(static_cast<__int128_t>(a) * x + b, m));
        if (!expected.empty() && expected.back().q == q)
            expected.back().r = x + 1;
        else
            expected.push_back({q, x, x + 1});
    }
    check(n, m, a, b, expected);
}

#if __cplusplus >= 202002L
static_assert(std::ranges::input_range<decltype(enumerate_quotients_linear(10, 3, 1, 0))>);
#endif

int main() {
    for (long long n = 0; n <= 8; n++) {
        for (long long m = 1; m <= 6; m++) {
            for (long long a = -6; a <= 6; a++) {
                for (long long b = -6; b <= 6; b++) check_naive(n, m, a, b);
            }
        }
    }
    std::mt19937 rng(314);
    for (int t = 0; t < 10000; t++) {
        check_naive(rng() % 100, rng() % 100 + 1, static_cast<long long>(rng() % 1001) - 500,
                    static_cast<long long>(rng() % 1001) - 500);
    }
    check(10, 3, 1, 0, {{0, 0, 3}, {1, 3, 6}, {2, 6, 9}, {3, 9, 10}});
    check(4, 10, 6, 3, {{0, 0, 2}, {1, 2, 3}, {2, 3, 4}});
    const long long hi = std::numeric_limits<long long>::max(), lo = std::numeric_limits<long long>::min();
    check(hi, hi, 1, 0, {{0, 0, hi}});
    check(hi, hi, -1, 0, {{0, 0, 1}, {-1, 1, hi}});
    check(hi, 1, 0, lo, {{lo, 0, hi}});
    check_naive(100, hi, hi, hi);
    check_naive(100, hi, lo, lo);
    check_naive(2, 1, lo, 0);
    check_naive(2, hi, 1, lo);
    check_naive(100, hi, 1, lo);
    check_naive(100, hi, 1, hi);
    check_naive(2, 1, 1, hi - 1);
    check(0, 1, 1, hi, {});
    check(hi, hi, 1, hi, {{1, 0, hi}});
    const auto huge = enumerate_quotients_linear(hi, 1, 1, 0);
    auto first = huge.begin(), copy = first;
    assert((*first++).q == 0 && (*first).q == 1 && (*copy).q == 0);
    assert((*huge.begin()).q == 0);
    std::cout << "Hello World\n";
}
