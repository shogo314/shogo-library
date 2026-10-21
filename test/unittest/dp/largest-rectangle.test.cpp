#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// largest-rectangle.hpp の 3 つの関数を、すべての長方形・正方形を調べたものとランダムに比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/dp/largest-rectangle.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    if (largest_rectangle_in_histogram(std::vector<int>{}) != 0) ok = false;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 10 + 1;
        std::vector<int> hist(n);
        for (auto& x : hist) x = rng() % 6;
        long long best = 0;
        for (int l = 0; l < n; l++) {
            int mn = hist[l];
            for (int r = l; r < n; r++) {
                mn = std::min(mn, hist[r]);
                best = std::max(best, static_cast<long long>(mn) * (r - l + 1));
            }
        }
        if (largest_rectangle_in_histogram(hist) != best) ok = false;

        int h = rng() % 6, w = rng() % 6, p = rng() % 4 + 1;
        std::vector<std::vector<bool>> g(h, std::vector<bool>(w));
        for (auto& row : g)
            for (auto&& x : row) x = rng() % p != 0;
        auto f = [&](long long i, long long j) { return static_cast<bool>(g[i][j]); };
        // 左上と右下をすべて試す
        long long rect = 0, square = 0;
        for (int i1 = 0; i1 < h; i1++)
            for (int j1 = 0; j1 < w; j1++)
                for (int i2 = i1; i2 < h; i2++)
                    for (int j2 = j1; j2 < w; j2++) {
                        bool all = true;
                        for (int i = i1; i <= i2; i++)
                            for (int j = j1; j <= j2; j++) all &= static_cast<bool>(g[i][j]);
                        if (!all) continue;
                        rect = std::max(rect, static_cast<long long>(i2 - i1 + 1) * (j2 - j1 + 1));
                        if (i2 - i1 == j2 - j1) square = std::max(square, static_cast<long long>(i2 - i1 + 1));
                    }
        if (largest_rectangle(h, w, f) != rect || largest_square(h, w, f) != square) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
