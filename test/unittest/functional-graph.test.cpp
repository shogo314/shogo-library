#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// FunctionalGraph を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/functional-graph.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <vector>

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
        for (const auto& cycle : fg.cycles) {
            for (int i = 0; i < (int)cycle.size(); i++) {
                if (g[cycle[i]] != cycle[(i + 1) % cycle.size()]) ok = false;
                cnt[cycle[i]]++;
            }
        }
        for (int x = 0; x < n; x++) {
            if (cnt[x] != (on_cycle[x] ? 1 : 0)) ok = false;
            if (fg.is_cycle[x] != on_cycle[x]) ok = false;
        }

        for (int x = 0; x < n; x++) {
            // hopable: 0 回以上の移動でたどり着ける頂点の個数
            std::set<int> reach;
            int y = x;
            for (int j = 0; j <= n; j++) {
                reach.insert(y);
                y = g[y];
            }
            if (fg.hopable(x) != (int)reach.size()) ok = false;
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
