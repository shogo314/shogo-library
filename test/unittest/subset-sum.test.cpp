#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// subset_sum、subset_sum_restore、subset_sum_max*、subset_sum_count_* を、部分集合をすべて試す愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/dp/subset-sum.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "../../src/dp/subset-sum-count.hpp"
#include "../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12;
        long long S = rng() % 300;  // 64 の倍数の前後も含む
        int amax = rng() % 2 ? 10 : 200;
        std::vector<long long> a(n);
        for (auto& x : a) x = rng() % (amax + 1);  // 0 も含む
        std::vector<long long> cnt(S + 1);
        for (int mask = 0; mask < (1 << n); mask++) {
            long long s = 0;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) s += a[i];
            }
            if (s <= S) cnt[s]++;
        }
        std::vector<bool> can = subset_sum(a, S);
        ok = ok && (long long)can.size() == S + 1;
        for (long long s = 0; s <= S && ok; s++) ok = can[s] == (cnt[s] > 0);
        // 復元: 添字が昇順で重複がなく、和が S になる
        auto r = subset_sum_restore(a, S);
        ok = ok && r.has_value() == (cnt[S] > 0);
        if (ok && r) {
            long long s = 0;
            for (int k = 0; k < (int)r->size(); k++) {
                if ((*r)[k] < 0 || (*r)[k] >= n || (k && (*r)[k - 1] >= (*r)[k]))
                    ok = false;
                else
                    s += a[(*r)[k]];
            }
            ok = ok && s == S;
        }
        // S 以下の最大値と、その復元
        long long best = 0;
        for (long long s = 0; s <= S; s++) {
            if (cnt[s] > 0) best = s;
        }
        ok = ok && subset_sum_max(a, S) == best && subset_sum_max_bitset(a, S) == best;
        ok = ok && subset_sum_max_meet_in_the_middle(a, S) == best;
        auto mr = subset_sum_max_restore(a, S);
        long long ms = 0;
        for (int k = 0; k < (int)mr.size(); k++) {
            if (mr[k] < 0 || mr[k] >= n || (k && mr[k - 1] >= mr[k]))
                ok = false;
            else
                ms += a[mr[k]];
        }
        ok = ok && ms == best;
        // 個数
        int t = S;
        auto c1 = subset_sum_count_dp<long long>(a, t);
        auto c2 = subset_sum_count_fps<mint>(a, t);
        auto c3 = subset_sum_count<mint>(a, t);
        for (int s = 0; s <= t && ok; s++) ok = c1[s] == cnt[s] && c2[s] == mint(cnt[s]) && c3[s] == mint(cnt[s]);
    }

    // 要素も S も大きいときは半分全列挙が選ばれ、復元もできる
    for (int rep = 0; rep < 200 && ok; rep++) {
        int n = rng() % 21;
        long long S = rng() % 1000000000000000000LL;
        std::vector<long long> a(n);
        for (auto& x : a) x = rng() % 100000000000000000LL;
        long long best = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            long long s = 0;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) s += a[i];
            }
            if (s <= S) best = std::max(best, s);
        }
        ok = ok && subset_sum_max(a, S) == best;
        auto mr = subset_sum_max_restore(a, S);
        long long ms = 0;
        for (int k = 0; k < (int)mr.size(); k++) {
            if (k && mr[k - 1] >= mr[k]) ok = false;
            ms += a[mr[k]];
        }
        ok = ok && ms == best;
    }

    // 例
    std::vector<long long> a = {3, 5, 9};
    auto r = subset_sum_restore(a, 14);
    ok = ok && r && *r == std::vector<int>{1, 2};
    ok = ok && !subset_sum_restore(a, 13);
    ok = ok && subset_sum_restore(a, 0) == std::vector<int>{};

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
