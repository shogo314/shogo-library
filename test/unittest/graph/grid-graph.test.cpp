#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../../src/graph/grid-graph.hpp"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#if __cplusplus >= 202002L
#include <ranges>
#endif

#include "../../../src/graph/shortest-path.hpp"

using ll = long long;
using Cell = std::pair<ll, ll>;

static_assert(std::is_same_v<decltype(std::declval<const GridGraph&>().graph()), const Graph<ll>&>);
static_assert(std::is_same_v<decltype(std::declval<GridGraph&>().board()), const std::vector<std::string>&>);
static_assert(!std::is_assignable_v<decltype(std::declval<GridGraph&>().board()[0][0]), char>);
static_assert(!std::is_convertible_v<std::vector<std::string>, GridGraph>);

bool adjacent(Cell a, Cell b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second) == 1;
}

void verify(const GridGraph& maze, const std::vector<std::string>& board, char wall) {
    const ll h = board.size(), w = board.empty() ? 0 : static_cast<ll>(board.front().size());
    assert(maze.board() == board && maze.height() == h && maze.width() == w);
    std::vector<Cell> cells;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            const ll expected = board[i][j] == wall ? -1 : static_cast<ll>(cells.size());
            assert(maze.index(i, j) == expected);
            if (expected != -1) cells.emplace_back(i, j);
        }
    }
    const ll n = cells.size();
    assert(maze.size() == n && maze.graph().size() == n);

    std::set<std::pair<ll, ll>> expected_edges, actual_edges;
    for (ll u = 0; u < n; ++u) {
        assert(maze.cell(u) == cells[u]);
        assert(maze.label(u) == board[cells[u].first][cells[u].second]);
        std::set<ll> expected_neighbors, actual_neighbors;
        for (ll v = 0; v < n; ++v) {
            if (adjacent(cells[u], cells[v])) {
                expected_neighbors.insert(v);
                if (u < v) expected_edges.emplace(u, v);
            }
        }
        for (const auto& edge : maze[u]) {
            assert(edge.src == u && edge.cost == 1 && 0 <= edge.dst && edge.dst < n);
            actual_neighbors.insert(edge.dst);
        }
        assert(actual_neighbors == expected_neighbors && maze[u].size() == expected_neighbors.size());
        assert(&maze[u] == &maze.graph()[u]);
    }
    assert(maze.graph().edge_count() == static_cast<ll>(expected_edges.size()));
    std::vector<ll> edge_occurrences(maze.graph().edge_count());
    for (ll u = 0; u < n; ++u) {
        for (const auto& edge : maze[u]) {
            assert(0 <= edge.id && edge.id < maze.graph().edge_count());
            ++edge_occurrences[edge.id];
        }
    }
    for (ll count : edge_occurrences) assert(count == 2);
    for (const auto& edge : maze.graph().edges()) actual_edges.emplace(std::min(edge.src, edge.dst), std::max(edge.src, edge.dst));
    assert(actual_edges == expected_edges);

    for (char c : {'S', 'G', '.', '#', 'a', 'X', '\0'}) {
        std::vector<ll> expected;
        for (ll v = 0; v < n; ++v) {
            if (board[cells[v].first][cells[v].second] == c) expected.push_back(v);
        }
        const auto matches = maze.find_all(c);
        assert(std::vector<ll>(matches.begin(), matches.end()) == expected);
        assert(std::vector<ll>(matches.begin(), matches.end()) == expected);
        assert(maze.find(c) == (expected.empty() ? -1 : expected.front()));
        // 一時的な検索rangeがなくなっても、iteratorの走査状態は独立している。
        auto it = maze.find_all(c).begin();
        for (ll v : expected) {
            auto independent = it;
            decltype(it) assigned;
            assigned = it;
            assert(*it++ == v && *independent == v && *assigned == v);
            ++independent;
            assert(independent == it);
        }
        assert(it == matches.end());
#if __cplusplus >= 202002L
        static_assert(std::ranges::forward_range<decltype(matches)>);
        auto selected = maze.find_all(c) | std::views::take(1);
        std::vector<ll> first;
        std::ranges::copy(selected, std::back_inserter(first));
        assert(first == (expected.empty() ? std::vector<ll>{} : std::vector<ll>{expected.front()}));
#endif
    }

    // Gridを使わず、座標のマンハッタン距離だけで隣接を判定するBFSと比較する。
    const ll inf = std::numeric_limits<ll>::max() / 4;
    for (ll s = 0; s < n; ++s) {
        std::vector<ll> expected(n, inf);
        std::queue<ll> queue;
        expected[s] = 0;
        queue.push(s);
        while (!queue.empty()) {
            const ll u = queue.front();
            queue.pop();
            for (ll v = 0; v < n; ++v) {
                if (expected[v] != inf || !adjacent(cells[u], cells[v])) continue;
                expected[v] = expected[u] + 1;
                queue.push(v);
            }
        }
        const auto result = shortest_path_bfs(maze.graph(), s);
        assert(result.dist == expected);
        for (ll t = 0; t < n; ++t) {
            const auto path = result.path(t);
            assert(path.has_value() == (expected[t] != inf));
            if (path) {
                assert(path->vertices.front() == s && path->vertices.back() == t);
                assert(path->cost == expected[t] && static_cast<ll>(path->edges.size()) == expected[t]);
                for (ll i = 1; i < static_cast<ll>(path->vertices.size()); ++i) {
                    assert(adjacent(maze.cell(path->vertices[i - 1]), maze.cell(path->vertices[i])));
                }
            }
        }
    }
}

int main() {
    for (const auto& board : std::vector<std::vector<std::string>>{
             {}, {"", ""}, {"#"}, {"."}, {"S"}, {"###", "###"}, {"S#G"}, {"S", "#", "G"}, {"S..#.", ".#...", "...G."}, {"aaa", "a#a", "aaa"}}) {
        verify(GridGraph(board), board, '#');
    }
    verify(GridGraph({"S#XG", "aX.a"}, 'X'), {"S#XG", "aX.a"}, 'X');
    verify(GridGraph({"S.G"}, 'S'), {"S.G"}, 'S');
    const std::vector<std::string> binary = {std::string("a\0#", 3)};
    verify(GridGraph(binary), binary, '#');
    {
        const std::vector<std::string> expected = {"S..#.", ".#...", "...G."};
        auto input = expected;
        GridGraph maze(input);
        input.clear();
        verify(maze, expected, '#');
        const GridGraph copy(maze);
        verify(copy, expected, '#');
        GridGraph moved(std::move(maze));
        verify(moved, expected, '#');
        assert(shortest_path_bfs(moved.graph(), moved.find('S')).dist[moved.find('G')] == 5);
    }
    std::mt19937 rng(314);
    for (int rep = 0; rep < 600; ++rep) {
        const ll h = rng() % 8, w = rng() % 8;
        std::vector<std::string> board(h, std::string(w, '.'));
        for (auto& row : board) {
            for (char& c : row) c = std::string("##..aSGX")[rng() % 8];
        }
        const char wall = rep % 2 == 0 ? '#' : 'X';
        verify(GridGraph(board, wall), board, wall);
    }
    std::cout << "Hello World\n";
}
