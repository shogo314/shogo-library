#define PROBLEM "https://atcoder.jp/contests/awc0073/tasks/awc0073_e"
#define IGNORE

#include <iostream>

#include "../../../src/graph/chinese-postman.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    Graph<long long> g(n);
    g.read(m, -1, true);
    std::cout << *chinese_postman(g) << '\n';
}
