#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// FunctionalGraph を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/functional-graph.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <type_traits>
#include <utility>
#include <vector>

static_assert(std::is_same_v<decltype(std::declval<FunctionalGraph&>().groups()), const std::vector<std::vector<long long>>&>);
static_assert(std::is_same_v<decltype(std::declval<FunctionalGraph&>().cycles()), const std::vector<std::vector<long long>>&>);

// x から k 回移動した頂点 (周期を見つけて k を縮める)
int naive_hop(const std::vector<int>& g, int x, long long k) {
    std::vector<long long> visited(g.size(), -1);
    for (long long t = 0; t < k; t++) {
        if (visited[x] != -1) {
            long long period = t - visited[x];
            long long rest = (k - t) % period;
            for (long long i = 0; i < rest; i++) x = g[x];
            return x;
        }
        visited[x] = t;
        x = g[x];
    }
    return x;
}

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<int> g(n);
        for (int& v : g) v = rng() % n;
        FunctionalGraph fg(g);
        // std::vector<long long> から作っても同じになる
        FunctionalGraph fg_ll(std::vector<long long>(g.begin(), g.end()));
        if (fg_ll.cycles() != fg.cycles()) ok = false;
        for (int x = 0; x < n; x++) {
            if (fg_ll.hop(x, 1) != g[x] || fg_ll.depth(x) != fg.depth(x)) ok = false;
        }

        // サイクル上の頂点: ある 1 <= j <= n で g^j(x) = x
        std::vector<bool> on_cycle(n);
        for (int x = 0; x < n; x++) {
            int y = x;
            for (int j = 0; j < n; j++) {
                y = g[y];
                if (y == x) on_cycle[x] = true;
            }
        }
        // cycles の各要素は g でつながったサイクルで、全体としてサイクル上の頂点をちょうど1回ずつ含む
        std::vector<int> cnt(n);
        for (const auto& cycle : fg.cycles()) {
            for (int i = 0; i < static_cast<int>(cycle.size()); i++) {
                if (g[cycle[i]] != cycle[(i + 1) % cycle.size()]) ok = false;
                cnt[cycle[i]]++;
            }
        }
        for (int x = 0; x < n; x++) {
            if (cnt[x] != (on_cycle[x] ? 1 : 0)) ok = false;
            if (fg.is_cycle(x) != on_cycle[x]) ok = false;
            int y = x, distance = 0;
            while (!on_cycle[y]) y = g[y], distance++;
            if (fg.root(x) != y || fg.depth(x) != distance) ok = false;
            if (fg.cycles()[fg.group_id(x)][fg.root_index(x)] != y) ok = false;
        }
        std::vector<int> group_count(n);
        for (long long c = 0; c < static_cast<long long>(fg.groups().size()); c++) {
            for (long long v : fg.groups()[c]) {
                if (fg.group_id(v) != c || fg.group_id(g[v]) != c) ok = false;
                group_count[v]++;
            }
        }
        for (int count : group_count) {
            if (count != 1) ok = false;
        }

        for (int x = 0; x < n; x++) {
            // hopable: 0 回以上の移動でたどり着ける頂点の個数
            std::set<int> reach;
            int y = x;
            for (int j = 0; j <= n; j++) {
                reach.insert(y);
                y = g[y];
            }
            if (fg.hopable(x) != static_cast<int>(reach.size())) ok = false;
            // hop: 小さい k と大きい k
            for (long long k = 0; k <= 3 * n; k++) {
                if (fg.hop(x, k) != naive_hop(g, x, k)) ok = false;
            }
            long long k = rng() % 1000000000000000000LL;
            if (fg.hop(x, k) != naive_hop(g, x, k)) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
