#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// vector_func.hpp の演算子と関数を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

#include "../../src/utility/vector_func.hpp"

bool ok = true;

void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

int main() {
    std::mt19937_64 rng(314);
    auto rand_vec = [&](int n) {
        std::vector<long long> v(n);
        for (auto& x : v) x = static_cast<long long>(rng() % 21) - 10;
        return v;
    };

    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 8, m = rng() % 8;
        std::vector<long long> a = rand_vec(n), b = rand_vec(m);
        long long c = static_cast<long long>(rng() % 11) - 5;

        // ++ / -- (前置は変更後、後置は変更前を返す)
        {
            std::vector<long long> x = a, inc = a, dec = a;
            for (auto& e : inc) e++;
            for (auto& e : dec) e--;
            check(++x == inc && x == inc, "前置 ++");
            check(x-- == inc && x == a, "後置 --");
            check(--x == dec && x == dec, "前置 --");
            check(x++ == dec && x == a, "後置 ++");
        }

        // 要素ごとの和 (短い方は 0 で埋める)
        {
            std::vector<long long> expect(std::max(n, m));
            for (int i = 0; i < static_cast<int>(expect.size()); i++) expect[i] = (i < n ? a[i] : 0) + (i < m ? b[i] : 0);
            check(a + b == expect, "v + w");
            std::vector<long long> x = a;
            x += b;
            check(x == expect, "v += w");
        }

        // 要素ごとの積 (どちらかにない位置は 0)
        {
            std::vector<long long> expect(std::max(n, m));
            for (int i = 0; i < static_cast<int>(expect.size()); i++) expect[i] = (i < n && i < m) ? a[i] * b[i] : 0;
            check(a * b == expect, "v * w");
            std::vector<long long> x = a;
            x *= b;
            check(x == expect, "v *= w");
        }

        // スカラーとの和・積
        {
            std::vector<long long> plus = a, times = a;
            for (auto& e : plus) e += c;
            for (auto& e : times) e *= c;
            check(a + c == plus && c + a == plus, "v + c, c + v");
            check(a * c == times && c * a == times, "v * c, c * v");
            std::vector<long long> x = a;
            x += c;
            check(x == plus, "v += c");
            x = a;
            x *= c;
            check(x == times, "v *= c");
        }

        // 連結と繰り返し
        {
            std::vector<long long> cat = a;
            cat.insert(cat.end(), b.begin(), b.end());
            std::vector<long long> x = a;
            check(&extend(x, b) == &x && x == cat, "extend");
            x = a;
            x |= b;
            check(x == cat, "v |= w");
            int k = rng() % 4;
            std::vector<long long> rep_k;
            for (int i = 0; i < k; i++) rep_k.insert(rep_k.end(), a.begin(), a.end());
            check((a | k) == rep_k && (k | a) == rep_k, "v | k, k | v");
            x = a;
            x |= k;
            check(x == rep_k, "v |= k");
        }

        // assign (型の変換つき)
        {
            std::vector<int> small(b.begin(), b.end());
            std::vector<long long> x = a;
            check(&assign(x, small) == &x && x == b, "assign");
        }

        // abs
        {
            std::vector<long long> expect = a;
            for (auto& e : expect) e = std::llabs(e);
            check(abs(a) == expect, "abs");
        }

        // sorted_idx: 値の昇順 (降順) に並べた添字の並び替え
        {
            for (bool rev : {false, true}) {
                auto idx = sorted_idx(a, rev);
                std::vector<long long> perm = idx;
                std::sort(perm.begin(), perm.end());
                bool is_perm = static_cast<int>(perm.size()) == n;
                for (int i = 0; i < static_cast<int>(perm.size()) && is_perm; i++) is_perm = perm[i] == i;
                bool is_sorted = true;
                for (int i = 0; i + 1 < static_cast<int>(idx.size()); i++) {
                    if (rev ? a[idx[i]] < a[idx[i + 1]] : a[idx[i]] > a[idx[i + 1]]) is_sorted = false;
                }
                check(is_perm && is_sorted, "sorted_idx");
            }
        }

        // hamming_distance (同じ長さどうし、型が異なってもよい)
        {
            std::vector<long long> d = rand_vec(n);
            std::vector<int> e(d.begin(), d.end());
            long long hd = 0;
            for (int i = 0; i < n; i++) hd += a[i] != d[i];
            check(hamming_distance(a, d) == hd && hamming_distance(a, e) == hd, "hamming_distance");
        }

        // iota
        {
            std::vector<int> expect(n);
            for (int i = 0; i < n; i++) expect[i] = i;
            check(iota(n) == expect, "iota");
        }

        // radix_convert: 整数 -> 桁 (上位から) -> 整数
        {
            int base = rng() % 15 + 2;
            long long x = rng() % 1000000000000LL;
            std::vector<long long> digits;
            for (long long y = x; y > 0; y /= base) digits.push_back(y % base);
            std::reverse(digits.begin(), digits.end());
            check(radix_convert(x, base) == digits, "radix_convert(x, base)");
            check(radix_convert(digits, base) == x, "radix_convert(digits, base)");
        }
    }

    // 決まった値
    check(radix_convert(123, 10) == std::vector<long long>{1, 2, 3}, "radix_convert(123)");
    check(radix_convert(std::vector<long long>{1, 0, 1, 1}, 2) == 11, "radix_convert({1,0,1,1}, 2)");
    check(radix_convert(0, 10).empty() && radix_convert(std::vector<long long>{}, 10) == 0, "radix_convert 0");
    check(iota(0).empty(), "iota(0)");
    check(hamming_distance(std::vector<int>{1, 2, 3}, std::vector<int>{1, 0, 0}) == 2, "hamming_distance 決まった値");
    check((std::vector<int>{1, 2} | 0).empty(), "v | 0");

    if (ok) std::cout << "Hello World" << std::endl;
}
