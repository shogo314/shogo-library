#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_g"
#define IGNORE

#include <algorithm>
#include <iostream>

#include "../../src/graph/graph_util.hpp"

int main(void) {
    int N, M;
    std::cin >> N >> M;
    Graph G(N);
    G.read(M, -1, false, true);

    std::vector<int> dist(N);
    std::vector<long long> ord(topological_sort(G));
    for (long long x : ord) {
        for (long long y : G[x]) dist[y] = std::max(dist[y], dist[x] + 1);
    }
    std::cout << *std::max_element(dist.begin(), dist.end()) << std::endl;
}
