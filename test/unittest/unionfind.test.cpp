#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// UnionFind を愚直な実装 (連結成分の番号を付け直す) とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "../../src/data_structures/unionfind.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 10 + 1;
        // デフォルトコンストラクタで作ってから代入する
        UnionFind uf;
        uf = UnionFind(n);
        std::vector<int> comp(n);
        for (int i = 0; i < n; i++) comp[i] = i;
        for (int t = 0; t < 15; t++) {
            int a = rng() % n, b = rng() % n;
            auto res = uf.merge(a, b);
            bool expect_merged = comp[a] != comp[b];
            if (res.merged != expect_merged || static_cast<bool>(res) != expect_merged) ok = false;
            int ca = comp[a], cb = comp[b];
            for (int& c : comp) {
                if (c == cb) c = ca;
            }
            if (uf.leader(a) != res.leader) ok = false;
            for (int x = 0; x < n; x++) {
                // size: 同じ連結成分の頂点数
                if (uf.size(x) != (int)std::count(comp.begin(), comp.end(), comp[x])) ok = false;
            }
            // groups: 連結成分ごとの頂点のリスト (各リストは昇順)
            std::vector<std::vector<int>> expect;
            std::vector<int> seen(n, -1);
            for (int x = 0; x < n; x++) {
                if (seen[comp[x]] == -1) {
                    seen[comp[x]] = expect.size();
                    expect.push_back({});
                }
                expect[seen[comp[x]]].push_back(x);
            }
            auto g = uf.groups();
            std::sort(g.begin(), g.end());
            std::sort(expect.begin(), expect.end());
            if (g != expect) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
