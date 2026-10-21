#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// PotentializedUnionFind の size / groups を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/potentialized-unionfind.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 10 + 1;
        PotentializedUnionFind<group::Sum<long long>> uf(n);
        // 矛盾しない入力にするため、各頂点のポテンシャルを先に決めておく
        std::vector<long long> p(n);
        for (auto& x : p) x = static_cast<long long>(rng() % 21) - 10;
        std::vector<int> comp(n);
        for (int i = 0; i < n; i++) comp[i] = i;
        for (int t = 0; t < 15; t++) {
            int a = rng() % n, b = rng() % n;
            auto res = uf.merge(a, b, p[b] - p[a]);
            if (res.merged != (comp[a] != comp[b])) ok = false;
            int ca = comp[a], cb = comp[b];
            for (int& c : comp) {
                if (c == cb) c = ca;
            }
            for (int x = 0; x < n; x++) {
                if (uf.size(x) != static_cast<int>(std::count(comp.begin(), comp.end(), comp[x]))) ok = false;
                for (int y = 0; y < n; y++) {
                    if (comp[x] == comp[y] && uf.diff(x, y) != p[y] - p[x]) ok = false;
                }
            }
            std::vector<std::vector<long long>> expect;
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
    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
