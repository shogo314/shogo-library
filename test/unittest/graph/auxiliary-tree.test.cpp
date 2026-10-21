#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// AuxiliaryTree を、選んだ頂点とそのすべての組の LCA を集め、集合の中で最も近い祖先を親とする愚直な実装と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/auxiliary-tree.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <vector>

#include "../../../src/graph/tree.hpp"

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

int main() {
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 30 + 1, root = rng() % n;
        Tree<int> tree(n);
        // 根 0 の木を作ってから、頂点番号を混ぜる
        std::vector<int> perm(n);
        for (int i = 0; i < n; i++) perm[i] = i;
        std::shuffle(perm.begin(), perm.end(), rng);
        for (int v = 1; v < n; v++) tree.add_edge(perm[rng() % v], perm[v]);
        AuxiliaryTree aux(tree, root);
        const auto& hld = aux.hld();

        // 愚直: 親を根から BFS で求める
        std::vector<long long> par(n, -1), order = {root};
        std::vector<bool> seen(n, false);
        seen[root] = true;
        for (size_t i = 0; i < order.size(); i++)
            for (const auto& e : tree[order[i]])
                if (!seen[e.dst]) seen[e.dst] = true, par[e.dst] = order[i], order.push_back(e.dst);
        auto is_ancestor = [&](long long a, long long v) {  // a が v の祖先 (v 自身を含む)
            for (; v != -1; v = par[v])
                if (v == a) return true;
            return false;
        };

        int k = rng() % 8;
        std::vector<long long> vs(k);
        for (auto& v : vs) v = rng() % n;  // 重複してもよい
        auto t = aux.build(vs);

        std::set<long long> expect;
        for (long long a : vs)
            for (long long b : vs) expect.insert(hld.lca(a, b));
        check(std::set<long long>(t.vertices.begin(), t.vertices.end()) == expect && t.size() == static_cast<long long>(expect.size()), "頂点の集合");
        check(t.size() <= std::max(0, 2 * static_cast<int>(std::set<long long>(vs.begin(), vs.end()).size()) - 1), "頂点は 2k - 1 個以下");
        for (long long i = 0; i < t.size(); i++) {
            long long v = t.vertices[i];
            // 集合の中で、v 以外で最も深い祖先が親
            long long best = -1;
            for (long long u : expect)
                if (u != v && is_ancestor(u, v) && (best == -1 || hld.depth(u) > hld.depth(best))) best = u;
            if (i == 0) {
                check(t.parent[0] == -1 && best == -1, "根");
            } else {
                check(0 <= t.parent[i] && t.parent[i] < i && t.vertices[t.parent[i]] == best, "親");
            }
            if (i > 0) check(hld.index(t.vertices[i - 1]) < hld.index(v), "DFS 順");
        }
    }
    // 子から親への DP: 選んだ頂点の個数を部分木ごとに数え、元の木で数えたものと比べる
    {
        Tree<int> tree(7);
        for (auto [a, b] : std::vector<std::pair<int, int>>{{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {5, 6}}) tree.add_edge(a, b);
        AuxiliaryTree aux(tree, 0);
        auto t = aux.build({3, 4, 6});
        // 並び順は HL 分解の列の順なので、頂点ごとの親で比べる
        std::map<long long, long long> parent_of;
        for (long long i = 0; i < t.size(); i++) parent_of[t.vertices[i]] = t.parent[i] == -1 ? -1 : t.vertices[t.parent[i]];
        check((parent_of == std::map<long long, long long>{{0, -1}, {1, 0}, {3, 1}, {4, 1}, {6, 0}}), "例の親");
        std::vector<long long> cnt(t.size(), 0);
        for (long long i = 0; i < t.size(); i++) cnt[i] = t.vertices[i] == 3 || t.vertices[i] == 4 || t.vertices[i] == 6;
        for (long long i = t.size() - 1; i > 0; i--) cnt[t.parent[i]] += cnt[i];
        long long i1 = std::find(t.vertices.begin(), t.vertices.end(), 1) - t.vertices.begin();
        check(cnt[0] == 3 && cnt[i1] == 2, "例の DP");
        check(aux.build({}).size() == 0, "空");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
