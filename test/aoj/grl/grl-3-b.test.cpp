#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/graph/graph.hpp"
#include "../../../src/graph/lowlink.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0);
    LowLink ll(g);
    auto es = g.edges();
    std::vector<std::pair<int, int>> ans;
    for (int id : ll.bridges()) ans.emplace_back(std::min(es[id].src, es[id].dst), std::max(es[id].src, es[id].dst));
    std::sort(ans.begin(), ans.end());
    for (auto [s, t] : ans) std::cout << s << ' ' << t << '\n';
}
