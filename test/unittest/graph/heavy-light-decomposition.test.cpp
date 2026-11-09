#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// HeavyLightDecomposition を、親を 1 つずつたどる愚直な実装とランダムに比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/heavy-light-decomposition.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <random>
#include <utility>
#include <vector>
#if __cplusplus >= 202002L
#include <ranges>
#endif

#include "../../../src/graph/graph.hpp"
#include "../../../src/graph/tree.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 500 && ok; rep++) {
        int n = rng() % 30 + 1;
        int root = rng() % n;
        // ランダムな木 (細長い木も作る)
        std::vector<int> perm(n);
        for (int i = 0; i < n; i++) perm[i] = i;
        std::shuffle(perm.begin(), perm.end(), rng);
        Graph<int> g(n);
        Tree<int> t(n);
        bool line = rng() % 4 == 0;
        for (int i = 1; i < n; i++) {
            int p = line ? i - 1 : rng() % i;
            g.add_edge(perm[i], perm[p]);
            t.add_edge(perm[i], perm[p]);
        }
        HeavyLightDecomposition hld(t, root);

        // 愚直: 根からの親と深さ
        std::vector<int> par(n, -1), dep(n, 0), bfs = {root};
        for (int i = 0; i < static_cast<int>(bfs.size()); i++) {
            int v = bfs[i];
            for (int u : g[v]) {
                if (u == par[v]) continue;
                par[u] = v, dep[u] = dep[v] + 1;
                bfs.push_back(u);
            }
        }
        auto naive_path = [&](int u, int v) {
            std::vector<int> a, b;
            while (u != v) {
                if (dep[u] >= dep[v])
                    a.push_back(u), u = par[u];
                else
                    b.push_back(v), v = par[v];
            }
            a.push_back(u);
            a.insert(a.end(), b.rbegin(), b.rend());
            return a;
        };

        // index は 0, ..., n-1 の並べ替えで、vertex がその逆
        std::vector<bool> seen(n);
        for (int v = 0; v < n; v++) {
            int i = hld.index(v);
            if (i < 0 || i >= n || seen[i] || hld.vertex(i) != v)
                ok = false;
            else
                seen[i] = true;
            if (hld.parent(v) != par[v] || hld.depth(v) != dep[v]) ok = false;
        }
        // 部分木: 区間 [l, r) の頂点が v の子孫と一致する
        for (int v = 0; v < n; v++) {
            auto [l, r] = hld.subtree(v);
            if (r - l != hld.subtree_size(v)) ok = false;
            for (int u = 0; u < n; u++) {
                int x = u;
                while (x != -1 && x != v) x = par[x];
                bool desc = x == v;
                if (desc != (l <= hld.index(u) && hld.index(u) < r)) ok = false;
            }
        }
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                auto p = naive_path(u, v);
                int d = p.size() - 1;
                int w = *std::min_element(p.begin(), p.end(), [&](int a, int b) { return dep[a] < dep[b]; });
                if (hld.lca(u, v) != w || hld.dist(u, v) != d) ok = false;
                for (int k = 0; k <= d + 1; k++) {
                    int expect = k <= d ? p[k] : -1;
                    if (hld.jump(u, v, k) != expect) ok = false;
                }
                // path が返す区間をつなげると、u から v への頂点の列になる
                std::vector<int> got, got_edge;
                for (auto [l, r, reverse] : hld.path(u, v)) {
                    if (!(0 <= l && l < r && r <= n)) ok = false;
                    if (reverse) {
                        for (long long i = r; i-- > l;) got.push_back(hld.vertex(i));
                    } else {
                        for (long long i = l; i < r; i++) got.push_back(hld.vertex(i));
                    }
                }
                if (got != p) ok = false;
                // 辺のパス: lca を除いた頂点 (その頂点と親を結ぶ辺) の列
                for (auto [l, r, reverse] : hld.path(u, v, true)) {
                    if (!(0 <= l && l < r && r <= n)) ok = false;
                    if (reverse) {
                        for (long long i = r; i-- > l;) got_edge.push_back(hld.vertex(i));
                    } else {
                        for (long long i = l; i < r; i++) got_edge.push_back(hld.vertex(i));
                    }
                }
                std::vector<int> expect_edge;
                for (int x : p) {
                    if (x != w) expect_edge.push_back(x);
                }
                if (got_edge != expect_edge) ok = false;
            }
            for (int k = 0; k <= n; k++) {
                int x = u;
                for (int i = 0; i < k && x != -1; i++) x = par[x];
                if (hld.hop(u, k) != x) ok = false;
            }
        }
    }

    // 多数の light edge をまたぐパスでも、順序・退避状態・iterator のコピーを保つ。
    {
        constexpr long long n = 65535;
        Tree<> tree(n);
        for (long long v = 1; v < n; v++) tree.add_edge((v - 1) / 2, v);
        HeavyLightDecomposition hld(tree);
        for (auto [u, v] : std::vector<std::pair<long long, long long>>{{0, n - 1}, {n - 1, 0}, {n / 2, n - 1}, {n - 1, n - 1}}) {
            for (bool edge : {false, true}) {
                auto make_range = [&] { return hld.path(u, v, edge); };
                const auto range = make_range();
                auto copied = range;
                auto moved = std::move(copied);
                std::vector<HeavyLightDecomposition::PathSegment> segments(range.begin(), range.end());
                auto same = [](const auto& a, const auto& b) { return a.l == b.l && a.r == b.r && a.reverse == b.reverse; };
                // range の一時オブジェクトがなくなっても iterator は自分の走査状態を持つ。
                auto it = make_range().begin();
                for (const auto& segment : segments) {
                    auto independent = it;
                    auto assigned = range.end();
                    assigned = it;
                    ok = ok && same(*it++, segment) && same(*independent, segment) && same(*assigned, segment);
                    ++independent;
                    ++assigned;
                    ok = ok && independent == it && assigned == it;
                }
                ok = ok && it == range.end();
                for (int rep = 0; rep < 2; rep++) {
                    const std::vector<HeavyLightDecomposition::PathSegment> again(moved.begin(), moved.end());
                    ok = ok && again.size() == segments.size() && std::equal(segments.begin(), segments.end(), again.begin(), same);
                }
                ok = ok && std::distance(range.begin(), range.end()) == static_cast<long long>(segments.size());
                if (!segments.empty()) {
                    for (const auto segment : range) {
                        ok = ok && same(segment, segments.front());
                        break;
                    }
                }
                std::vector<long long> expanded, expected, down;
                for (auto [l, r, reverse] : range) {
                    if (reverse) {
                        for (long long i = r; i-- > l;) expanded.push_back(hld.vertex(i));
                    } else {
                        for (long long i = l; i < r; i++) expanded.push_back(hld.vertex(i));
                    }
                }
                long long a = u, b = v;
                while (a != b) {
                    if (hld.depth(a) >= hld.depth(b)) {
                        expected.push_back(a);
                        a = hld.parent(a);
                    } else {
                        down.push_back(b);
                        b = hld.parent(b);
                    }
                }
                if (!edge) expected.push_back(a);
                expected.insert(expected.end(), down.rbegin(), down.rend());
                ok = ok && expanded == expected;
#if __cplusplus >= 202002L
                static_assert(std::ranges::input_range<decltype(range)>);
#endif
            }
        }
    }
    assert(ok);

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
