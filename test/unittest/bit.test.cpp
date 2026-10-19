#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// bit.hpp の関数と列挙を愚直な実装とランダムに比較する
// C++17 (__builtin_* で実装) と C++20 (<bit> を呼ぶ) のどちらでも同じ結果になる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/utility/bit.hpp"

#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

bool ok = true;

void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

int main() {
    std::mt19937_64 rng(314);

    for (int rep = 0; rep < 100000 && ok; rep++) {
        // 0 以上の long long (ビット数もばらつかせる)
        int width = rng() % 63 + 1;
        long long a = static_cast<long long>(rng() >> (64 - width));

        int pc = 0, clz = 0, ctz = 0;
        for (int i = 0; i < 63; i++) pc += a >> i & 1;
        for (int i = 63; i >= 0 && !(a >> i & 1); i--) clz++;
        for (int i = 0; i < 64 && !(a >> i & 1); i++) ctz++;
        check(popcount(a) == pc, "popcount");
        if (a > 0) {
            check(countl_zero(a) == clz, "countl_zero");
            check(countr_zero(a) == ctz, "countr_zero");
        }

        // btoll: 2 進数の文字列 (上位桁から)
        std::string s;
        for (int i = width - 1; i >= 0; i--) s += (a >> i & 1) ? '1' : '0';
        check(btoll(s) == a, "btoll");
        // 1 を表す文字を指定する
        std::string t = s;
        for (char& c : t) c = (c == '1') ? '#' : '.';
        check(btoll(t, '#') == a, "btoll(s, one)");

        // hamming_distance: ビットごとに比べる
        long long b = static_cast<long long>(rng() >> (64 - width));
        int hd = 0;
        for (int i = 0; i < 63; i++) hd += (a >> i & 1) != (b >> i & 1);
        check(hamming_distance(a, b) == hd, "hamming_distance");
    }

    // countl_one / countr_one / bit_width / bit_ceil / bit_floor を愚直な実装と比べる
    for (int rep = 0; rep < 100000 && ok; rep++) {
        int width = rng() % 64;
        long long a = width == 0 ? 0 : static_cast<long long>(rng() >> (64 - width));
        if (rep % 4 == 0) a = (1LL << (rng() % 63)) - rng() % 2;  // 2 の累乗とその前後
        if (a < 0) a = 0;
        int clo = 0, cto = 0, bw = 0;
        for (int i = 63; i >= 0 && (a >> i & 1); i--) clo++;
        for (int i = 0; i < 64 && (a >> i & 1); i++) cto++;
        for (int i = 0; i < 63; i++) {
            if (a >> i & 1) bw = i + 1;
        }
        long long ceil = 1, floor = 0;
        while (ceil < a && ceil <= (1LL << 61)) ceil *= 2;  // a > 2^62 なら使わない
        for (int i = 0; i < 63; i++) {
            if ((1LL << i) <= a) floor = 1LL << i;
        }
        check(countl_one(a) == clo, "countl_one");
        check(countr_one(a) == cto, "countr_one");
        check(bit_width(a) == bw, "bit_width");
        if (a <= (1LL << 62)) check(bit_ceil(a) == ceil, "bit_ceil");
        check(bit_floor(a) == floor, "bit_floor");
    }

    // 1 ビットの操作・位置・変換を愚直な実装と比べる
    for (int rep = 0; rep < 100000 && ok; rep++) {
        int width = rng() % 64;
        long long a = width == 0 ? 0 : static_cast<long long>(rng() >> (64 - width));
        if (rep % 4 == 0) a = 1LL << (rng() % 63);
        int top = -1, low = -1, pc = 0;
        for (int i = 0; i < 63; i++) {
            if (a >> i & 1) {
                top = i;
                if (low < 0) low = i;
                pc++;
            }
        }
        check(has_single_bit(a) == (pc == 1), "has_single_bit");
        check(msb(a) == top && lsb(a) == low, "msb / lsb");
        check(lowbit(a) == (low < 0 ? 0 : 1LL << low), "lowbit");
        check(parity(a) == pc % 2, "parity");
        long long i = rng() % 63;
        bool on = a >> i & 1;
        check(test_bit(a, i) == on, "test_bit");
        check(set_bit(a, i) == (on ? a : a + (1LL << i)), "set_bit");
        check(reset_bit(a, i) == (on ? a - (1LL << i) : a), "reset_bit");
        check(flip_bit(a, i) == (on ? a - (1LL << i) : a + (1LL << i)), "flip_bit");

        // lltob: 桁数を省略すると先頭に 0 を付けない
        std::string s;
        for (int j = std::max(top, 0); j >= 0; j--) s += (a >> j & 1) ? '1' : '0';
        check(lltob(a) == s && btoll(lltob(a)) == a, "lltob");
        long long n = std::max(top + 1, 0) + rng() % 3;
        if (n > 63) n = 63;
        if (n == 0) n = 1;
        check(lltob(a, n) == std::string(n - s.size(), '0') + s, "lltob(a, n)");
        std::string t = lltob(a, n, '#', '.');
        check(static_cast<long long>(t.size()) == n && btoll(t, '#') == a, "lltob(a, n, one, zero)");

        // reverse_bits / rotate_left / rotate_right: n ビットの各位置を動かす
        long long rev = 0, rl = 0, rr = 0, k = static_cast<long long>(rng() % 200) - 100;
        long long km = ((k % n) + n) % n;
        for (int j = 0; j < n; j++) {
            if (a >> j & 1) {
                rev |= 1LL << (n - 1 - j);
                rl |= 1LL << ((j + km) % n);
                rr |= 1LL << ((j - km + n) % n);
            }
        }
        check(reverse_bits(a, n) == rev, "reverse_bits");
        check(rotate_left(a, k, n) == rl, "rotate_left");
        check(rotate_right(a, k, n) == rr, "rotate_right");

        // gray_code: 逆変換で戻り、隣り合う値で 1 ビットだけ変わる
        check(inverse_gray_code(gray_code(a)) == a, "inverse_gray_code");
        if (a < std::numeric_limits<long long>::max()) check(popcount(gray_code(a) ^ gray_code(a + 1)) == 1, "gray_code");

        // kth_set_bit
        if (pc > 0) {
            long long kk = rng() % pc, pos = -1;
            for (int j = 0, c = 0; j < 63; j++) {
                if (a >> j & 1) {
                    if (c == kk) pos = j;
                    c++;
                }
            }
            check(kth_set_bit(a, kk) == pos, "kth_set_bit");
        }
    }
    // xor_upto / count_bit_upto: 小さい n は 1 つずつ数える
    {
        long long x = 0;
        std::vector<long long> cnt(63, 0);
        for (long long n = 0; n < 5000 && ok; n++) {
            x ^= n;
            check(xor_upto(n) == x, "xor_upto");
            for (int i = 0; i < 63; i++) {
                cnt[i] += n >> i & 1;
                check(count_bit_upto(n, i) == cnt[i], "count_bit_upto");
            }
        }
        long long mx = std::numeric_limits<long long>::max();
        // 大きい n: count_bit_upto の和は 0..n の popcount の和で、0..n を 2 つに分けて数えても同じ
        for (int rep = 0; rep < 1000 && ok; rep++) {
            long long n = static_cast<long long>(rng() >> 1);
            if (n == mx) n--;
            long long m = static_cast<long long>(rng() % 1000);
            if (n < m) continue;
            for (int i = 0; i < 63; i++) {
                long long direct = 0;
                for (long long v = n - m + 1; v <= n; v++) direct += v >> i & 1;
                check(count_bit_upto(n, i) - (n - m < 0 ? 0 : count_bit_upto(n - m, i)) == direct, "count_bit_upto 大きい n");
            }
            long long xr = xor_upto(n - m);
            for (long long v = n - m + 1; v <= n; v++) xr ^= v;
            check(xor_upto(n) == xr, "xor_upto 大きい n");
        }
        check(count_bit_upto(mx - 1, 62) == mx - (1LL << 62), "count_bit_upto 上限");
        check(xor_upto(0) == 0 && xor_upto(3) == 0 && xor_upto(mx - 1) == mx && xor_upto(mx) == 0, "xor_upto 境界");
    }

    // subsets / supersets / bits / combinations_mask / add_one / remove_one を、すべての値を調べる愚直な方法と比べる
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 9;
        long long mask = static_cast<long long>(rng() % (1ULL << n));
        std::vector<long long> sub, sup, pos, got;
        for (long long s = (1LL << n) - 1; s >= 0; s--) {
            if ((s & mask) == s) sub.push_back(s);  // 降順
        }
        for (long long s = 0; s < (1LL << n); s++) {
            if ((s & mask) == mask) sup.push_back(s);  // 昇順
        }
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) pos.push_back(i);
        }
        got.clear();
        for (long long s : subsets(mask)) got.push_back(s);
        check(got == sub, "subsets");
        got.clear();
        for (long long s : supersets(mask, n)) got.push_back(s);
        check(got == sup, "supersets");
        got.clear();
        for (long long i : bits(mask)) got.push_back(i);
        check(got == pos, "bits");
        // add_one / remove_one: 1 つ足した (除いた) 集合と、その位置の組
        std::vector<std::pair<long long, long long>> add, rem, gp;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1)
                rem.emplace_back(i, mask ^ (1LL << i));
            else
                add.emplace_back(i, mask | (1LL << i));
        }
        for (auto [i, t] : add_one(mask, n)) gp.emplace_back(i, t);
        check(gp == add, "add_one");
        gp.clear();
        for (auto [i, t] : remove_one(mask)) gp.emplace_back(i, t);
        check(gp == rem, "remove_one");
        // subsets_of_size: mask の部分集合で要素数 k のもの (昇順)
        for (int k = 0; k <= n + 1; k++) {
            std::vector<long long> want;
            for (long long s = 0; s < (1LL << n); s++) {
                if ((s & mask) == s && __builtin_popcountll(s) == k) want.push_back(s);
            }
            got.clear();
            for (long long s : subsets_of_size(mask, k)) got.push_back(s);
            check(got == want, "subsets_of_size");
        }
        // next_combination_mask: 立っているビットの数が同じで次に大きい値
        if (mask > 0) {
            long long want = -1;
            for (long long s = mask + 1; s < (1LL << 12); s++) {
                if (__builtin_popcountll(s) == __builtin_popcountll(mask)) {
                    want = s;
                    break;
                }
            }
            check(next_combination_mask(mask) == want, "next_combination_mask");
        }
        for (int k = 0; k <= n + 1; k++) {
            std::vector<long long> comb;
            for (long long s = 0; s < (1LL << n); s++) {
                if (__builtin_popcountll(s) == k) comb.push_back(s);
            }
            got.clear();
            for (long long s : combinations_mask(n, k)) got.push_back(s);
            check(got == comb, "combinations_mask");
        }
    }
    {
        // 大きいビット幅と境界
        long long cnt = 0, last = -1;
        for (long long s : combinations_mask(62, 61)) cnt++, last = s;
        check(cnt == 62 && last == (1LL << 62) - 2, "combinations_mask(62, 61)");
        cnt = 0;
        for (long long s : supersets((1LL << 62) - 2, 62)) cnt += s;
        check(cnt == 2 * ((1LL << 62) - 2) + 1, "supersets 62 ビット");
        std::vector<long long> got;
        for (long long i : bits(std::numeric_limits<long long>::max())) got.push_back(i);
        check(static_cast<long long>(got.size()) == 63 && got.back() == 62, "bits(最大値)");
        got.clear();
        for (long long s : subsets(0)) got.push_back(s);
        check(got == std::vector<long long>{0}, "subsets(0)");
        // constexpr でも使える
        constexpr long long sum = [] {
            long long r = 0;
            for (long long s : subsets(0b1011)) r += s;
            for (long long i : bits(0b1011)) r += i;
            return r;
        }();
        static_assert(sum == 44 + 4);
        constexpr long long sum2 = [] {
            long long r = 0;
            for (auto [i, t] : add_one(0b0101, 4)) r += i * 100 + t;  // (1, 0111), (3, 1101)
            for (auto [i, t] : remove_one(0b0101)) r += i * 100 + t;  // (0, 0100), (2, 0001)
            return r;
        }();
        static_assert(sum2 == (100 + 7) + (300 + 13) + (0 + 4) + (200 + 1));
        got.clear();
        for (auto [i, t] : add_one((1LL << 62) - 2, 62)) got.push_back(i), got.push_back(t);
        check(got == std::vector<long long>{0, (1LL << 62) - 1}, "add_one 62 ビット");
    }

    {
        // subset_pairs: すべての (S, T ⊆ S) を S の昇順、T の降順に
        for (int n = 0; n <= 6 && ok; n++) {
            std::vector<std::pair<long long, long long>> want, gp;
            for (long long s = 0; s < (1LL << n); s++) {
                for (long long t = s; t >= 0; t--) {
                    if ((t & s) == t) want.emplace_back(s, t);
                }
            }
            for (auto [s, t] : subset_pairs(n)) gp.emplace_back(s, t);
            check(gp == want, "subset_pairs");
        }
        // 大きいビット幅と境界
        long long mx = std::numeric_limits<long long>::max();
        check(next_combination_mask(mx) == -1 && next_combination_mask(1LL << 62) == -1, "next_combination_mask 上限");
        check(next_combination_mask((1LL << 62) - 2) == (1LL << 62) + (1LL << 60) - 1, "next_combination_mask 62 ビット");
        std::vector<long long> got;
        for (long long s : subsets_of_size(mx, 62)) got.push_back(s);
        check(static_cast<long long>(got.size()) == 63 && got.front() == (1LL << 62) - 1 && got.back() == mx - 1, "subsets_of_size 63 ビット");
        got.clear();
        for (long long s : subsets_of_size(0b1010, 0)) got.push_back(s);
        check(got == std::vector<long long>{0}, "subsets_of_size(k = 0)");
        check(rotate_left(1, 1, 63) == 2 && rotate_left(1LL << 62, 1, 63) == 1 && rotate_right(1, 1, 63) == (1LL << 62), "rotate 63 ビット");
        check(reverse_bits(1, 63) == (1LL << 62) && inverse_gray_code(gray_code(mx)) == mx, "63 ビット");
        check(kth_set_bit(mx, 62) == 62 && kth_set_bit(1LL << 62, 0) == 62, "kth_set_bit 63 ビット");
        check(lltob(0) == "0" && lltob(5) == "101" && lltob(5, 5) == "00101" && lltob(0, 3, '#', '.') == "...", "lltob 決まった値");
        check(msb(0) == -1 && lsb(0) == -1 && lowbit(0) == 0 && msb(mx) == 62, "msb / lsb / lowbit 境界");
        constexpr long long sum = [] {
            long long r = 0;
            for (long long s : subsets_of_size(0b1101, 2)) r += s;  // 0101, 1001, 1100
            for (auto [s, t] : subset_pairs(2)) r += s * 10 + t;   // 3^2 = 9 組
            return r;
        }();
        static_assert(sum == (5 + 9 + 12) + (0 + 11 + 10 + 22 + 20 + 33 + 32 + 31 + 30));
        static_assert(has_single_bit(64) && !has_single_bit(0) && !has_single_bit(6));
        static_assert(gray_code(5) == 7 && inverse_gray_code(7) == 5 && rotate_left(0b0011, 3, 4) == 0b1001);
    }

    // 0 のときは C++20 の <bit> と同じ値
    check(countl_zero(0) == 64 && countr_zero(0) == 64, "countl_zero / countr_zero(0)");
    check(countl_one(0) == 0 && countr_one(0) == 0, "countl_one / countr_one(0)");
    check(bit_width(0) == 0 && bit_ceil(0) == 1 && bit_floor(0) == 0, "bit_width / bit_ceil / bit_floor(0)");
    check(bit_ceil(1LL << 62) == (1LL << 62) && bit_ceil((1LL << 61) + 1) == (1LL << 62), "bit_ceil 上限");
    check(countr_one(std::numeric_limits<long long>::max()) == 63 && bit_width(std::numeric_limits<long long>::max()) == 63, "最大値");

    // 戻り値の型は C++17 でも C++20 でも long long
    static_assert(std::is_same_v<decltype(popcount(1)), long long>);
    static_assert(std::is_same_v<decltype(countl_zero(1)), long long>);
    static_assert(std::is_same_v<decltype(countr_zero(1)), long long>);
    static_assert(std::is_same_v<decltype(countl_one(1)), long long>);
    static_assert(std::is_same_v<decltype(countr_one(1)), long long>);
    static_assert(std::is_same_v<decltype(bit_width(1)), long long>);
    static_assert(std::is_same_v<decltype(bit_ceil(1)), long long>);
    static_assert(std::is_same_v<decltype(bit_floor(1)), long long>);
    static_assert(bit_width(5) == 3 && bit_ceil(5) == 8 && bit_floor(5) == 4 && countl_zero(0) == 64);

    // 決まった値
    check(popcount(0) == 0 && popcount((1LL << 62) - 1) == 62, "popcount 境界");
    check(countl_zero(1) == 63 && countr_zero(1LL << 62) == 62, "countl_zero / countr_zero 境界");
    check(hamming_distance(5, 3) == 2 && hamming_distance(7, 7) == 0, "hamming_distance 決まった値");
    check(btoll("") == 0 && btoll("0") == 0 && btoll("101") == 5, "btoll 決まった値");

    if (ok) std::cout << "Hello World" << std::endl;
}
