#pragma once

/**
 * @file quotients.hpp
 * @brief 商の列挙 (floor(n / i) が同じ値になる i の区間)
 */

#include <cassert>
#include <limits>
#include <vector>

/**
 * @brief 商 q = floor(n / i) と、それをとる i の区間 [l, r)
 */
struct QuotientRange {
    long long q;  //!< 商
    long long l;  //!< 区間の左端 (含む)
    long long r;  //!< 区間の右端 (含まない)
};

/**
 * @brief i = 1, ..., n を floor(n / i) の値で区間に分け、i の昇順 (商の降順) に f(q, l, r) を呼ぶ O(sqrt(n))
 * l <= i < r なら floor(n / i) == q
 * @pre 0 <= n < std::numeric_limits<long long>::max()
 */
template <typename F>
void for_each_quotient(long long n, F f) {
    assert(0 <= n && n < std::numeric_limits<long long>::max());
    for (long long l = 1; l <= n;) {
        long long q = n / l, r = n / q + 1;
        f(q, l, r);
        l = r;
    }
}

/**
 * @brief i = 1, ..., n を floor(n / i) の値で区間に分けたもの (i の昇順、つまり商の降順) O(sqrt(n))
 * 区間の個数は 2 sqrt(n) 以下
 */
inline std::vector<QuotientRange> enumerate_quotients(long long n) {
    std::vector<QuotientRange> res;
    for_each_quotient(n, [&](long long q, long long l, long long r) { res.push_back({q, l, r}); });
    return res;
}
