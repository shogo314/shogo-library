#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

// floyd_warshall を使う

#include <iostream>
#include <limits>

#include "../../../src/graph/shortest-path.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    Graph<long long> g(n);
    g.read(m, 0, true, true);
    const long long inf = std::numeric_limits<long long>::max() / 4;
    auto d = floyd_warshall(g, inf);
    for (int i = 0; i < n; i++) {
        if (d[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << '\n';
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) std::cout << ' ';
            if (d[i][j] == inf)
                std::cout << "INF";
            else
                std::cout << d[i][j];
        }
        std::cout << '\n';
    }
}
