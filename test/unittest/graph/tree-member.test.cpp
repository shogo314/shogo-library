#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// tree.hpp の Tree で公開しているメンバを検証する
// add_directed_edge は外から呼べないこと (RootedTree・DoublingClimbTree でも) をコンパイル時に確かめる
// add_edge と、cin を差し替えた read で作った木の辺を確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <sstream>
#include <type_traits>
#include <utility>

#include "../../../src/graph/tree.hpp"

template <typename T, typename = void>
struct has_add_directed_edge : std::false_type {};
template <typename T>
struct has_add_directed_edge<T, std::void_t<decltype(std::declval<T&>().add_directed_edge(0, 1, 1))>> : std::true_type {};
template <typename T, typename = void>
struct has_add_edge : std::false_type {};
template <typename T>
struct has_add_edge<T, std::void_t<decltype(std::declval<T&>().add_edge(0, 1, 1))>> : std::true_type {};

static_assert(has_add_directed_edge<Graph<long long>>::value);
static_assert(!has_add_directed_edge<Tree<long long>>::value);
static_assert(!has_add_directed_edge<Tree<int>>::value);
static_assert(!has_add_directed_edge<RootedTree<long long>>::value);
static_assert(!has_add_directed_edge<DoublingClimbTree<long long>>::value);
static_assert(has_add_edge<Tree<long long>>::value);
static_assert(!has_add_edge<RootedTree<long long>>::value);

int main() {
    bool ok = true;

    // add_edge: 無向辺として両方の隣接リストに入る
    {
        Tree<long long> t(4);
        t.add_edge(0, 1, 5);
        t.add_edge(1, 2);
        t.add_edge(3, 1, 7);
        if (t.size() != 4 || t.m != 3) ok = false;
        if (t[1].size() != 3 || t[0].size() != 1 || t[2].size() != 1 || t[3].size() != 1) ok = false;
        if (t[0][0].dst != 1 || t[0][0].cost != 5 || t[2][0].cost != 1 || t[3][0].cost != 7) ok = false;
        const Graph<long long>& g = t.graph();
        if (g.m != 3 || &g[1] != &t[1]) ok = false;
        if (t.set_root(0).depth[3] != 12) ok = false;
    }

    // read: n - 1 本の辺を 1-indexed・重み付きで読む
    {
        std::istringstream in("1 2 10\n2 3 20\n2 4 30\n");
        auto* old = std::cin.rdbuf(in.rdbuf());
        Tree<long long> t(4);
        t.read(-1, true);
        std::cin.rdbuf(old);
        auto es = t.edges();
        if (t.m != 3 || es.size() != 3) ok = false;
        long long expect[3][3] = {{0, 1, 10}, {1, 2, 20}, {1, 3, 30}};
        for (int i = 0; i < 3; i++) {
            // 無向辺の向きは規定しないので、端点を集合として比べる
            bool same = (es[i].src == expect[i][0] && es[i].dst == expect[i][1]) || (es[i].src == expect[i][1] && es[i].dst == expect[i][0]);
            if (!same || es[i].cost != expect[i][2]) ok = false;
        }
        if (t.build_lca(0).dist(2, 3) != 50) ok = false;
    }
    // read: 0-indexed・重みなし
    {
        std::istringstream in("0 1\n0 2\n");
        auto* old = std::cin.rdbuf(in.rdbuf());
        Tree<int> t(3);
        t.read(0);
        std::cin.rdbuf(old);
        if (t.m != 2 || t[0].size() != 2 || t[0][0].cost != 1 || t[0][1].dst != 2) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
