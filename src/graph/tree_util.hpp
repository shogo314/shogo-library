#pragma once

/**
 * @file tree_util.hpp
 * @brief 木に関する関数
 */

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

#include "tree.hpp"

namespace internal_tree_util {

// s から各頂点への距離と、各頂点へ向かう辺 (s では Edge()) を DFS で求める
template <typename Cost>
std::pair<std::vector<Cost>, std::vector<typename Tree<Cost>::Edge>> tree_distances(const Tree<Cost>& tree, long long s, bool weighted) {
    using Edge = typename Tree<Cost>::Edge;
    long long n = tree.size();
    std::vector<Cost> dist(n);
    std::vector<Edge> prev(n);
    std::vector<long long> stk = {s};
    while (!stk.empty()) {
        long long u = stk.back();
        stk.pop_back();
        for (const auto& e : tree[u]) {
            if (e.id == prev[u].id) continue;
            prev[e.dst] = e;
            dist[e.dst] = dist[u] + (weighted ? e.cost : Cost{1});
            stk.push_back(e.dst);
        }
    }
    return {dist, prev};
}

}  // namespace internal_tree_util

/**
 * @brief 木の直径
 *
 * @param tree 木 (頂点数 1 以上)
 * @param weighted = true 重み付きか
 * @return std::vector<typename Tree<Cost>::Edge> 直径を構成する辺のリスト (端点から順に)
 */
template <typename Cost>
std::vector<typename Tree<Cost>::Edge> tree_diameter(const Tree<Cost>& tree, bool weighted = true) {
    assert(tree.size() > 0);
    auto [dist0, prev0] = internal_tree_util::tree_distances(tree, 0, weighted);
    long long u = std::max_element(dist0.begin(), dist0.end()) - dist0.begin();
    auto [dist, prev] = internal_tree_util::tree_distances(tree, u, weighted);
    long long v = std::max_element(dist.begin(), dist.end()) - dist.begin();
    std::vector<typename Tree<Cost>::Edge> path;
    for (long long w = v; w != u; w = prev[w].src) path.push_back(prev[w]);
    std::reverse(path.begin(), path.end());
    return path;
}
