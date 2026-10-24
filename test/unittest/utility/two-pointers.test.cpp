#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// utility/two-pointers.hpp の two_pointers を、l ごとに右へ伸ばす愚直な方法と比べる
// 和が k 以下・種類数が k 以下 (状態を持つ)、差が k 以下 (状態を持たない、空の区間を含む)、円環の 3 通りを調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/utility/two-pointers.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12;
        std::vector<long long> a(n);
        for (auto& x : a) x = rng() % 5;
        long long k = static_cast<long long>(rng() % 12) - 2;

        // 和が k 以下
        long long s = 0;
        auto r1 = two_pointers(
            n, [&](long long, long long r) { return s + a[r] <= k; }, [&](long long r) { s += a[r]; }, [&](long long l) { s -= a[l]; });
        // 種類数が k 以下
        std::vector<int> cnt(5);
        long long kinds = 0;
        auto r2 = two_pointers(
            n, [&](long long, long long r) { return cnt[a[r]] > 0 || kinds < k; }, [&](long long r) { kinds += cnt[a[r]]++ == 0; },
            [&](long long l) { kinds -= --cnt[a[l]] == 0; });
        // ソートした列で差が k 以下 (k < 0 なら区間は空)
        std::vector<long long> b = a;
        std::sort(b.begin(), b.end());
        auto r3 = two_pointers(n, [&](long long l, long long r) { return b[r] - b[l] <= k; });
        ok = ok && static_cast<int>(r1.size()) == n && static_cast<int>(r2.size()) == n && static_cast<int>(r3.size()) == n;
        for (int l = 0; l < n && ok; l++) {
            long long e1 = l, t = 0;
            while (e1 < n && t + a[e1] <= k) t += a[e1++];
            long long e2 = l;
            std::set<long long> st;
            while (e2 < n && (st.count(a[e2]) || static_cast<long long>(st.size()) < k)) st.insert(a[e2++]);
            long long e3 = l;
            while (e3 < n && b[e3] - b[l] <= k) e3++;
            ok = ok && r1[l] == e1 && r2[l] == e2 && r3[l] == e3;
        }

        // 円環: 周の長さ L の円周上の相異なる点について、各点から時計回りに幅 w 未満にある点の数
        long long L = 16, w = rng() % 20;
        std::vector<long long> c(L);
        for (int i = 0; i < L; i++) c[i] = i;
        std::shuffle(c.begin(), c.end(), rng);
        c.resize(n);
        std::sort(c.begin(), c.end());
        for (int i = 0; i < n; i++) c.push_back(c[i] + L);  // 1 周ずらした写しをつなげる
        auto r4 = two_pointers(2 * n, [&](long long l, long long r) { return c[r] - c[l] < std::min(w, L); });
        for (int l = 0; l < n && ok; l++) {
            long long e4 = 0;
            for (int j = 0; j < n; j++) e4 += (c[j] - c[l] + L) % L < std::min(w, L);
            ok = ok && r4[l] - l == e4;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
