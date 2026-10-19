#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// CentroidDecomposition を、定義どおりの性質と愚直な実装で確かめる
// - 各重心 c は、その成分 (c から level が c より大きい頂点をたどったもの) の重心になっている
// - 重心木の親子と level、order の並びが正しい
// - subtrees が返す距離が、成分の中での BFS の距離と一致する
// - 重心ごとに c を通るパスを数えると、すべての頂点の組の距離の分布と一致する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/centroid-decomposition.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <vector>

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

int main() {
    std::mt19937 rng(314);
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 40 + 1;
        Tree<long long> tree(n);
        // 一直線・星形・ランダムな木
        for (int v = 1; v < n; v++) {
            int p = rep % 3 == 0 ? v - 1 : rep % 3 == 1 ? 0
                                                        : rng() % v;
            tree.add_edge(p, v, rng() % 10 + 1);
        }
        CentroidDecomposition cd(tree);
        check(cd.size() == n, "size");
        const auto& ord = cd.order();
        check(static_cast<long long>(ord.size()) == n, "order の長さ");
        std::vector<int> pos(n, -1);
        for (int i = 0; i < n; i++) pos[ord[i]] = i;
        check(std::count(pos.begin(), pos.end(), -1) == 0, "order はすべての頂点を含む");
        check(cd.parent(cd.root()) == -1 && cd.level(cd.root()) == 0 && ord[0] == cd.root(), "root");

        // 頂点間の距離 (重みつき) を全点から求める
        std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, -1));
        for (int s = 0; s < n; s++) {
            std::vector<int> q = {s};
            dist[s][s] = 0;
            for (int i = 0; i < static_cast<int>(q.size()); i++) {
                for (const auto& e : tree[q[i]]) {
                    if (dist[s][e.dst] == -1) dist[s][e.dst] = dist[s][q[i]] + e.cost, q.push_back(e.dst);
                }
            }
        }
        std::map<long long, long long> expect, got;
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) expect[dist[a][b]]++;
        }

        for (int c = 0; c < n; c++) {
            long long p = cd.parent(c);
            if (p != -1) check(cd.level(c) == cd.level(p) + 1 && pos[p] < pos[c], "親の level と order");
            // c の成分: c から level が c より大きい頂点をたどる
            std::vector<int> comp = {c};
            std::vector<bool> in(n, false);
            in[c] = true;
            for (int i = 0; i < static_cast<int>(comp.size()); i++) {
                for (const auto& e : tree[comp[i]]) {
                    if (!in[e.dst] && cd.level(e.dst) > cd.level(c)) in[e.dst] = true, comp.push_back(e.dst);
                }
            }
            // 成分のほかの頂点は、重心木で c の子孫になっている
            for (int v : comp) {
                long long u = v;
                while (u != -1 && u != c) u = cd.parent(u);
                check(u == c, "成分は重心木での子孫");
            }
            // subtrees: c を除いた部分木ごとに、成分の大きさの半分以下で、距離が正しい
            auto subs = cd.subtrees(tree, c);
            long long covered = 1;
            for (const auto& sub : subs) {
                check(sub.size() * 2 <= comp.size(), "重心 (部分木は成分の半分以下)");
                covered += sub.size();
                for (auto [v, d] : sub) check(in[v] && v != c && d == dist[c][v], "subtrees の距離");
            }
            check(covered == static_cast<long long>(comp.size()), "subtrees は成分全体を覆う");
            // c を通るパス: c と部分木の頂点、違う部分木の頂点どうし
            for (size_t i = 0; i < subs.size(); i++) {
                for (auto [v, d] : subs[i]) {
                    got[d]++;
                    for (size_t j = 0; j < i; j++) {
                        for (auto [u, e] : subs[j]) got[d + e]++;
                    }
                }
            }
        }
        check(got == expect, "c を通るパスの数え上げ");
        // level は O(log n)
        long long max_level = 0;
        for (int v = 0; v < n; v++) max_level = std::max(max_level, cd.level(v));
        check((1LL << max_level) <= n, "level は log n 以下");
    }
    // 頂点数 0
    {
        Tree<int> empty(0);
        CentroidDecomposition cd(empty);
        check(cd.size() == 0 && cd.order().empty(), "空の木");
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
