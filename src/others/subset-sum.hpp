#pragma once

/**
 * @file subset-sum.hpp
 * @brief 部分和問題 (作れる和の判定と復元)
 */

#include <cassert>
#include <optional>
#include <vector>

namespace internal_subset_sum {
// bits (S + 1 ビット) について bits |= bits << s を行う。新しく立ったビットごとに f(位置) を呼ぶ
template <typename F>
void shift_or(std::vector<unsigned long long>& bits, long long S, long long s, F f) {
    int words = bits.size();
    long long q = s / 64;
    int r = s % 64;
    for (long long k = words - 1; k >= q; k--) {
        unsigned long long val = bits[k - q] << r;
        if (r && k - q - 1 >= 0) val |= bits[k - q - 1] >> (64 - r);
        if (k == words - 1 && (S + 1) % 64) val &= (1ULL << ((S + 1) % 64)) - 1;  // S を超える位置は捨てる
        unsigned long long added = val & ~bits[k];
        bits[k] |= val;
        while (added) {
            f(k * 64 + __builtin_ctzll(added));
            added &= added - 1;
        }
    }
}
}  // namespace internal_subset_sum

/**
 * @brief a の部分集合 (各要素は 1 回まで) の和として、0, 1, ..., S のそれぞれを作れるか O(N S / 64)
 * @param a 0 以上の整数の列
 * @return 長さ S + 1 の列。res[s] は和 s を作れるか
 */
inline std::vector<bool> subset_sum(const std::vector<long long>& a, long long S) {
    assert(S >= 0);
    std::vector<unsigned long long> bits(S / 64 + 1);
    bits[0] = 1;
    for (long long x : a) {
        assert(x >= 0);
        if (x == 0 || x > S) continue;
        internal_subset_sum::shift_or(bits, S, x, [](long long) {});
    }
    std::vector<bool> res(S + 1);
    for (long long s = 0; s <= S; s++) res[s] = bits[s / 64] >> (s % 64) & 1;
    return res;
}

/**
 * @brief a の部分集合 (各要素は 1 回まで) で和がちょうど S になるものを 1 つ求め、その添字を昇順に返す O(N S / 64 + S)
 * @param a 0 以上の整数の列
 * @return 作れなければ std::nullopt
 */
inline std::optional<std::vector<int>> subset_sum_restore(const std::vector<long long>& a, long long S) {
    assert(S >= 0);
    std::vector<unsigned long long> bits(S / 64 + 1);
    bits[0] = 1;
    // from[s] は、和 s を初めて作れるようになったときに使った要素の添字
    std::vector<int> from(S + 1, -1);
    for (int i = 0; i < (int)a.size(); i++) {
        assert(a[i] >= 0);
        if (a[i] == 0 || a[i] > S) continue;
        internal_subset_sum::shift_or(bits, S, a[i], [&](long long s) { from[s] = i; });
    }
    if (!(bits[S / 64] >> (S % 64) & 1)) return std::nullopt;
    // s - a[from[s]] は from[s] より前の要素だけで作れていたので、添字は真に減っていく
    std::vector<int> res;
    for (long long s = S; s > 0; s -= a[res.back()]) res.push_back(from[s]);
    return std::vector<int>(res.rbegin(), res.rend());
}
