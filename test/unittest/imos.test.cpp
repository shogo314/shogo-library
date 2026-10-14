#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Imos を愚直な実装とランダムに比較する
// 区間作用・1点作用・1点取得を任意の順に混ぜる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/imos.hpp"

#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 10 + 1;
        std::vector<long long> v(n);
        Imos<acted_monoid::AddSum<long long>> imos;
        switch (rep % 3) {
            case 0:
                // Imos(n): 0 で初期化
                imos = Imos<acted_monoid::AddSum<long long>>(n);
                break;
            case 1: {
                // Imos(n, value)
                long long x = rng() % 10;
                imos = Imos<acted_monoid::AddSum<long long>>(n, x);
                v.assign(n, x);
                break;
            }
            default:
                // Imos(vector)
                for (auto& x : v) x = static_cast<long long>(rng() % 21) - 10;
                imos = Imos<acted_monoid::AddSum<long long>>(v);
                break;
        }
        for (int t = 0; t < 30; t++) {
            int op = rng() % 3;
            if (op == 0) {
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) std::swap(l, r);
                long long f = static_cast<long long>(rng() % 21) - 10;
                imos.apply(l, r, f);
                for (int i = l; i < r; i++) v[i] += f;
            } else if (op == 1) {
                int k = rng() % n;
                long long f = static_cast<long long>(rng() % 21) - 10;
                imos.apply(k, f);
                v[k] += f;
            } else {
                int k = rng() % n;
                if (imos.get(k) != v[k]) ok = false;
            }
        }
        for (int k = n - 1; k >= 0; k--) {
            if (imos.get(k) != v[k]) ok = false;
        }
    }
    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
