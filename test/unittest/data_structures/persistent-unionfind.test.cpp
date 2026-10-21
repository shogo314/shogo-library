#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// PersistentUnionFind を愚直な実装 (版ごとに連結成分の番号を持つ) とランダムに比較する
// 古い版から辺を足しても、ほかの版が変わらないことを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/persistent-unionfind.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 10 + 1;
        // デフォルトコンストラクタで作ってから代入する
        PersistentUnionFind uf0;
        uf0 = PersistentUnionFind(n);
        std::vector<PersistentUnionFind> uf{uf0};
        std::vector<std::vector<int>> comp(1, std::vector<int>(n));
        for (int i = 0; i < n; i++) comp[0][i] = i;
        for (int t = 0; t < 30; t++) {
            int ver = rng() % uf.size();
            int a = rng() % n, b = rng() % n;
            if (rng() % 2) {
                uf.push_back(uf[ver].merge(a, b));
                std::vector<int> c = comp[ver];
                int ca = c[a], cb = c[b];
                for (int& x : c) {
                    if (x == cb) x = ca;
                }
                comp.push_back(c);
            } else {
                const auto& c = comp[ver];
                if (uf[ver].same(a, b) != (c[a] == c[b])) ok = false;
                if (uf[ver].size(a) != std::count(c.begin(), c.end(), c[a])) ok = false;
                if (c[uf[ver].leader(a)] != c[a]) ok = false;
            }
        }
        // すべての版が、作ったときの連結成分のままか
        for (int i = 0; i < static_cast<int>(uf.size()); i++) {
            const auto& c = comp[i];
            for (int a = 0; a < n; a++) {
                if (uf[i].leader(uf[i].leader(a)) != uf[i].leader(a)) ok = false;
                for (int b = 0; b < n; b++) {
                    if (uf[i].same(a, b) != (c[a] == c[b])) ok = false;
                }
            }
            // groups は代表元の小さい順とは限らないので、各グループの中身だけ比べる
            auto g = uf[i].groups();
            std::vector<std::vector<long long>> expect;
            for (int a = 0; a < n; a++) {
                std::vector<long long> group;
                for (int b = 0; b < n; b++) {
                    if (c[b] == c[a]) group.push_back(b);
                }
                if (group[0] == a) expect.push_back(group);
            }
            std::sort(g.begin(), g.end());
            if (g != expect) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
