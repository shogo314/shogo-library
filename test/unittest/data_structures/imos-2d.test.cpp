#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// imos-2d.hpp の Imos2D を、長方形の各マスに直接足したものとランダムに比べる
// 空の長方形や、0 行・0 列のグリッドも調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/imos-2d.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int h = rng() % 7, w = rng() % 7, q = rng() % 10;
        Imos2D<long long> imos(h, w);
        if (imos.height() != h || imos.width() != w) ok = false;
        std::vector<std::vector<long long>> g(h, std::vector<long long>(w, 0));
        for (int t = 0; t < q; t++) {
            int i1 = rng() % (h + 1), i2 = rng() % (h + 1), j1 = rng() % (w + 1), j2 = rng() % (w + 1);
            if (i1 > i2) std::swap(i1, i2);
            if (j1 > j2) std::swap(j1, j2);
            long long x = static_cast<long long>(rng() % 21) - 10;
            imos.add(i1, j1, i2, j2, x);
            for (int i = i1; i < i2; i++)
                for (int j = j1; j < j2; j++) g[i][j] += x;
        }
        imos.build();
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (imos.get(i, j) != g[i][j]) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
