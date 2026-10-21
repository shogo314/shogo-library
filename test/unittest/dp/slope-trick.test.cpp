#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// slope-trick.hpp の SlopeTrick を、整数点 [-W, W] での関数の値の表で愚直に求めたものとランダムに比べる
// 表の端の近くは平行移動で窓がはみ出して正しくなくなるが、傾きは左側で 0 以下、右側で 0 以上なので、内側の値には響かない
// あわせて、列を非減少にする最小コスト Σ|a_i - b_i| を、値の範囲での DP と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/dp/slope-trick.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    // 傾きが変わる点は、はじめ [-10, 10] にあり、平行移動 1 回で 4 以下しか動かないので [-E, E] に収まる
    const int W = 200, E = 70;  // 表の範囲と、値を比べる範囲
    for (int rep = 0; rep < 3000 && ok; rep++) {
        SlopeTrick<long long> st;
        std::vector<long long> f(2 * W + 1, 0);  // f[x + W]
        int q = rng() % 15 + 1;
        for (int i = 0; i < q; i++) {
            int type = rng() % 8;
            long long a = static_cast<long long>(rng() % 21) - 10;
            std::vector<long long> g = f;
            if (type == 0) {
                st.add_constant(a);
                for (auto& v : g) v += a;
            } else if (type == 1) {
                st.add_x_minus_a(a);
                for (int x = -W; x <= W; x++) g[x + W] += std::max(0LL, x - a);
            } else if (type == 2) {
                st.add_a_minus_x(a);
                for (int x = -W; x <= W; x++) g[x + W] += std::max(0LL, a - x);
            } else if (type == 3) {
                st.add_abs(a);
                for (int x = -W; x <= W; x++) g[x + W] += std::abs(x - a);
            } else if (type == 4) {
                st.prefix_min();
                for (int x = -W + 1; x <= W; x++) g[x + W] = std::min(g[x + W], g[x - 1 + W]);
            } else if (type == 5) {
                st.suffix_min();
                for (int x = W - 1; x >= -W; x--) g[x + W] = std::min(g[x + W], g[x + 1 + W]);
            } else {
                long long s = static_cast<long long>(rng() % 5) - 2, t = s + (type == 6 ? 0 : rng() % 3);
                if (type == 6)
                    st.shift(s);
                else
                    st.shift(s, t);
                // g(x) = min_{x - t <= y <= x - s} f(y)
                for (int x = -W; x <= W; x++) {
                    long long best = SlopeTrick<long long>::inf();
                    for (long long y = std::max<long long>(-W, x - t); y <= std::min<long long>(W, x - s); y++) best = std::min(best, f[y + W]);
                    g[x + W] = best;
                }
            }
            f = g;
            for (int x = -E; x <= E; x++) {
                if (st.get(x) != f[x + W]) ok = false;
            }
            long long mn = *std::min_element(f.begin(), f.end());
            if (st.min() != mn) ok = false;
            // 最小値をとる区間。傾きが変わる点は [-E, E] に収まるので、そこを越えて続くなら、その側は端がない
            // (表の端の近くは平行移動で窓がはみ出して正しくないので、[-E - 1, E + 1] だけを見る)
            int lo = -E - 1, hi = E + 1;
            while (lo <= E + 1 && f[lo + W] != mn) lo++;
            while (hi >= -E - 1 && f[hi + W] != mn) hi--;
            auto [l, r] = st.argmin();
            if (lo == -E - 1 ? l != -SlopeTrick<long long>::inf() : l != lo) ok = false;
            if (hi == E + 1 ? r != SlopeTrick<long long>::inf() : r != hi) ok = false;
        }
    }
    // 非減少にする最小コスト
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 8 + 1;
        std::vector<long long> a(n);
        for (auto& x : a) x = rng() % 10;
        SlopeTrick<long long> st;
        for (long long x : a) {
            st.prefix_min();
            st.add_abs(x);
        }
        // dp[v]: b の最後が v のときの最小コスト (b は 0 以上 9 以下にしてよい)
        std::vector<long long> dp(10, 0);
        for (long long x : a) {
            std::vector<long long> nd(10);
            long long best = SlopeTrick<long long>::inf();
            for (int v = 0; v < 10; v++) {
                best = std::min(best, dp[v]);
                nd[v] = best + std::abs(x - v);
            }
            dp = nd;
        }
        if (st.min() != *std::min_element(dp.begin(), dp.end())) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
