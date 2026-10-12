#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// CircularRing を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>
#include <vector>

#include "../../src/data_structures/circular-ring.hpp"

// i を n で割った非負の余り
long long pos(long long i, long long n) {
    long long r = i % n;
    return r < 0 ? r + n : r;
}

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 6 + 1;
        std::vector<int> v(n);
        for (int& x : v) x = rng() % 100;
        CircularRing<int> ring(v);
        // サイズを指定するコンストラクタは値初期化された要素を持つ
        CircularRing<int> zeros(static_cast<size_t>(n));
        const CircularRing<int>& cring = ring;
        for (int t = 0; t < 30 && ok; t++) {
            // 負の添字や大きな添字も使う
            long long i;
            switch (rng() % 3) {
                case 0: i = static_cast<long long>(rng() % 20) - 10; break;
                case 1: i = static_cast<long long>(rng() >> 2); break;
                default: i = -static_cast<long long>(rng() >> 2); break;
            }
            long long p = pos(i, n);
            if (cring.at(i) != v[p] || cring[i] != v[p] || ring.at(i) != v[p] || ring[i] != v[p]) ok = false;
            if (zeros[i] != 0) ok = false;
            // 参照を返す at / [] で書き換えると、同じ位置のすべての添字に反映される
            int x = rng() % 100;
            if (rng() % 2) ring[i] = x;
            else ring.at(i) = x;
            v[p] = x;
            if (ring[i + n] != x || ring[i - 3LL * n] != x) ok = false;
            if (ring.data != v) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
