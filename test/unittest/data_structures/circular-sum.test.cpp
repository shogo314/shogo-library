#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// CircularSum を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/circular-sum.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../../src/geometry/vector.hpp"

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        long long n = rng() % 7;
        std::vector<long long> v(n);
        for (long long& x : v) x = static_cast<long long>(rng() % 2000) - 1000;
        CircularSum cs(v);
        if (cs.size() != n) ok = false;

        long long total = 0;
        for (long long x : v) total += x;
        if (cs.all_sum() != total) ok = false;

        // 愚直: l から時計回りに個数分だけ足す (r < l なら n - l + r 個)
        for (long long l = 0; l <= n; l++) {
            for (long long r = 0; r <= n; r++) {
                long long len = l <= r ? r - l : n - l + r;
                long long expected = 0;
                for (long long k = 0; k < len; k++) expected += v[(l + k) % n];
                if (cs.sum(l, r) != expected) ok = false;
            }
        }
    }

    // + と - があれば何でもよい (成分ごとの和)
    using V = Vector<long long, 3>;
    std::vector<V> w = {V(1, 2, 3), V(10, 20, 30), V(100, 200, 300)};
    CircularSum cw(w);
    if (cw.sum(2, 1) != V(101, 202, 303)) ok = false;
    if (cw.sum(1, 1) != V(0, 0, 0)) ok = false;
    if (cw.all_sum() != V(111, 222, 333)) ok = false;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
