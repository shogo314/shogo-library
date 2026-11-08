#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../../src/data_structures/rollback-unionfind.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937 rng(314);
    RollbackUnionFind empty;
    empty.rollback(0);
    if (empty.snapshot() != 0 || !empty.groups().empty()) return 1;
    for (int rep = 0; rep < 300; ++rep) {
        int n = rng() % 20 + 1;
        RollbackUnionFind uf(n);
        std::vector<UnionFind> states{UnionFind(n)};
        for (int q = 0; q < 150; ++q) {
            if (rng() % 3 != 0) {
                int a = rng() % n, b = rng() % n;
                auto next = states.back();
                auto expect = next.merge(a, b);
                auto [root, merged] = uf.merge(a, b);
                if (merged != expect.merged || root != uf.leader(a)) return 1;
                if (merged) states.push_back(std::move(next));
            } else {
                long long t = rng() % states.size();
                uf.rollback(t);
                states.resize(t + 1);
            }
            if (uf.snapshot() != static_cast<long long>(states.size()) - 1) return 1;
            const auto& current = uf;
            for (int a = 0; a < n; ++a) {
                if (current.size(a) != states.back().size(a)) return 1;
                for (int b = 0; b < n; ++b) {
                    if (current.same(a, b) != states.back().same(a, b)) return 1;
                }
            }
            auto groups = current.groups(), expected = states.back().groups();
            std::sort(groups.begin(), groups.end());
            std::sort(expected.begin(), expected.end());
            if (groups != expected) return 1;
        }
        auto copy = uf;
        copy.rollback(0);
        if (uf.snapshot() != static_cast<long long>(states.size()) - 1) return 1;
        for (int a = 0; a < n; ++a)
            if (copy.size(a) != 1) return 1;
    }
    std::cout << "Hello World\n";
}
