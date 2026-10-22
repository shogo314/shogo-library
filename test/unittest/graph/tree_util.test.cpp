#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// tree_util.hpp の tree_diameter を愚直な実装 (全点対の距離の最大) とランダムに比較する
// 重み付き・重みなしの両方で、返す辺の列が端点から順につながっていて、長さが直径と一致するかを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/tree_util.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1;
        Tree<long long> tree(n);
        std::vector<std::vector<long long>> dw(n, std::vector<long long>(n, 1LL << 60)), du = dw;
        for (int i = 0; i < n; i++) dw[i][i] = du[i][i] = 0;
        for (int i = 1; i < n; i++) {
            int p = rng() % i;
            long long w = rng() % 10;
            tree.add_edge(i, p, w);
            dw[i][p] = dw[p][i] = w;
            du[i][p] = du[p][i] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dw[i][j] = std::min(dw[i][j], dw[i][k] + dw[k][j]);
                    du[i][j] = std::min(du[i][j], du[i][k] + du[k][j]);
                }
            }
        }
        for (bool weighted : {true, false}) {
            const auto& d = weighted ? dw : du;
            long long expected = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) expected = std::max(expected, d[i][j]);
            }
            auto path = tree_diameter(tree, weighted);
            long long len = 0;
            for (int i = 0; i < static_cast<int>(path.size()); i++) {
                if (i > 0 && path[i - 1].dst != path[i].src) ok = false;
                len += weighted ? path[i].cost : 1;
            }
            if (len != expected) ok = false;
            if (!path.empty() && d[path.front().src][path.back().dst] != expected) ok = false;
            if (n == 1 && !path.empty()) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << '\n';
}
