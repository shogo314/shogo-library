#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// chinese-postman.hpp の chinese_postman を、辺を何回通るかをすべて試す愚直な実装と比べる
// 各辺を 1 回か 2 回通るとしてよい (3 回以上通るなら 2 回減らしても条件を満たす) ので、
// 2 回通る辺の集合を全探索し、すべての頂点の次数が偶数になるものの最小を求める
// 自己ループ・多重辺・辺を持たない頂点・連結でないグラフも調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/chinese-postman.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../../src/data_structures/unionfind.hpp"

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    {
        Graph<long long> g(3);
        if (chinese_postman(g) != 0LL) ok = false;
    }
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 7 + 1, m = rng() % 11;
        Graph<long long> g(n);
        std::vector<int> us(m), vs(m);
        std::vector<long long> ws(m);
        UnionFind uf(n);
        for (int i = 0; i < m; i++) {
            us[i] = rng() % n, vs[i] = rng() % n, ws[i] = rng() % 10;
            g.add_edge(us[i], vs[i], ws[i]);
            uf.merge(us[i], vs[i]);
        }
        bool connected = true;
        int some = m > 0 ? us[0] : -1;
        for (int i = 0; i < m; i++) connected &= uf.same(us[i], some);
        long long best = -1;
        if (connected) {
            for (int S = 0; S < (1 << m); S++) {
                std::vector<int> deg(n, 0);
                long long cost = 0;
                for (int i = 0; i < m; i++) {
                    int times = (S >> i & 1) ? 2 : 1;
                    deg[us[i]] += times, deg[vs[i]] += times;
                    cost += times * ws[i];
                }
                bool even = true;
                for (int v = 0; v < n; v++) even &= deg[v] % 2 == 0;
                if (even && (best == -1 || cost < best)) best = cost;
            }
        }
        auto res = chinese_postman(g);
        if (!connected) {
            if (res) ok = false;
        } else if (!res || *res != best) {
            ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
