#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// rectangle-union.hpp の rectangle_union_area を、単位正方形ごとに覆われているかを数えたものと比べる
// 幅や高さが 0 の長方形、重なる長方形、空のリストも調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/geometry/rectangle-union.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    if (rectangle_union_area(std::vector<std::array<long long, 4>>{}) != 0) ok = false;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 8 + 1, w = 10;
        std::vector<std::array<long long, 4>> rects(n);
        std::vector<std::vector<bool>> covered(w, std::vector<bool>(w, false));
        for (auto& [l, d, r, u] : rects) {
            l = rng() % (w + 1), r = rng() % (w + 1), d = rng() % (w + 1), u = rng() % (w + 1);
            if (l > r) std::swap(l, r);
            if (d > u) std::swap(d, u);
            for (long long x = l; x < r; x++)
                for (long long y = d; y < u; y++) covered[x][y] = true;
        }
        long long expected = 0;
        for (auto& row : covered) expected += std::count(row.begin(), row.end(), true);
        if (rectangle_union_area(rects) != expected) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
