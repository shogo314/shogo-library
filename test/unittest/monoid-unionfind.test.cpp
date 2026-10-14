#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// MonoidUnionFind を愚直な実装とランダムに比較する
// 要素数だけを渡すコンストラクタ (各要素は単位元) と、初期値を渡すコンストラクタの両方を使う
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/monoid-unionfind.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 10 + 1;
        bool by_size = rep % 2 == 0;
        std::vector<long long> v(n, 0);
        if (!by_size) {
            for (auto& x : v) x = rng() % 100;
        }
        // MonoidUnionFind(n) は各要素を単位元 (和なら 0) で初期化する
        MonoidUnionFind<monoid::Sum<long long>> uf = by_size ? MonoidUnionFind<monoid::Sum<long long>>(n) : MonoidUnionFind<monoid::Sum<long long>>(v);
        // ラムダ式のモノイドと要素数で作る (各要素は単位元 -1)
        MonoidUnionFind muf(n, Monoid([](long long a, long long b) { return std::max(a, b); }, -1LL));
        std::vector<int> comp(n);
        for (int i = 0; i < n; i++) comp[i] = i;
        for (int t = 0; t < 15; t++) {
            int a = rng() % n, b = rng() % n;
            bool expect_merged = comp[a] != comp[b];
            if (uf.merge(a, b).merged != expect_merged) ok = false;
            if (muf.merge(a, b).merged != expect_merged) ok = false;
            int ca = comp[a], cb = comp[b];
            for (int& c : comp) {
                if (c == cb) c = ca;
            }
            for (int x = 0; x < n; x++) {
                long long sum = 0;
                for (int y = 0; y < n; y++) {
                    if (comp[y] == comp[x]) sum += v[y];
                }
                if (uf.prod(x) != sum) ok = false;
                if (muf.prod(x) != -1) ok = false;
                if (uf.size(x) != (int)std::count(comp.begin(), comp.end(), comp[x])) ok = false;
            }
        }
    }
    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
