#define PROBLEM "https://atcoder.jp/contests/abc482/tasks/abc482_e"
#define IGNORE

#include <iostream>
#include <vector>

#include "../../../src/graph/tree.hpp"
#include "../../../src/graph/tree_util.hpp"

int main() {
    long long n;
    std::cin >> n;
    Tree<long long> tree(n);
    tree.read();
    std::vector<long long> c(n);
    for (auto& x : c) std::cin >> x;
    // 異なるグループにある同じ色の 2 点を数える。前のグループまでに出た色の個数と照らし合わせる
    std::vector<long long> seen(n + 1);
    long long ans = 0;
    for (const auto& group : tree_diameter_endpoint_groups(tree)) {
        for (long long v : group) ans += seen[c[v]];
        for (long long v : group) seen[c[v]]++;
    }
    std::cout << ans << '\n';
}
