#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Compress を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/utility/compress.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 20;
        int range = rng() % 30 + 1;
        std::vector<int> a(n);
        for (auto& v : a) v = (int)(rng() % range) - range / 2;

        // コンストラクタで作る場合と、add を混ぜて作る場合
        Compress<int> c1(a);
        Compress<int> c2;
        int half = n / 2;
        for (int i = 0; i < half; i++) c2.add(a[i]);
        c2.add(std::vector<int>(a.begin() + half, a.end()));
        c2.build();

        std::vector<int> xs = a;
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        int m = xs.size();

        for (const Compress<int>* c : {&c1, &c2}) {
            ok = ok && c->size() == m && c->values() == xs;
            for (int i = 0; i < m; i++) ok = ok && (*c)[i] == xs[i] && c->id(xs[i]) == i;
            for (int x = -range; x <= range; x++) {
                int lo = 0, up = 0;
                while (lo < m && xs[lo] < x) lo++;
                while (up < m && xs[up] <= x) up++;
                bool has = std::count(a.begin(), a.end(), x) > 0;
                ok = ok && c->bisect_left(x) == lo && c->bisect_right(x) == up && c->contains(x) == has;
            }
            std::vector<long long> ids = c->ids(a);
            for (int i = 0; i < n; i++) ok = ok && xs[ids[i]] == a[i];
        }
    }

    // 例: 文字列も圧縮できる
    Compress<std::string> cs(std::vector<std::string>{"b", "a", "c", "a"});
    ok = ok && cs.size() == 3 && cs.id("c") == 2 && cs[0] == "a" && !cs.contains("d") && cs.bisect_left("bb") == 2;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
