#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// TadpoleArray を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>
#include <vector>

#include "../../src/data_structures/tadpole-array.hpp"

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 6 + 1;
        int k = rng() % n;  // 最後の次は k 番目に戻る
        std::vector<int> v(n);
        for (int& x : v) x = rng() % 100;
        TadpoleArray<int> ta(v, k);

        // 愚直: 0 から順に進み、末尾の次は k に戻る
        int p = 0;
        for (size_t i = 0; i < 200; i++) {
            if (ta.at(i) != v[p] || ta[i] != v[p]) ok = false;
            p = (p + 1 < n) ? p + 1 : k;
        }
        // 大きな添字: ループ部分の長さ n - k ごとに同じ値になる
        for (int t = 0; t < 20; t++) {
            size_t i = k + rng() % 1000000000000ULL;
            size_t period = n - k;
            if (ta[i] != ta[k + (i - k) % period]) ok = false;
            if (ta[i] != ta[i + period * (rng() % 1000)]) ok = false;
        }
        // コピーしても同じ列を表す
        TadpoleArray<int> copy(ta);
        for (size_t i = 0; i < 50; i++) {
            if (copy[i] != ta[i]) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
