#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../../src/offline/static-rectangle-add-rectangle-sum.hpp"

#include <cassert>
#include <iostream>
#include <random>

#include "../../../src/math/modint.hpp"

int main() {
    std::mt19937 rng(314);
    for (int rep = 0; rep < 200; ++rep) {
        StaticRectangleAddRectangleSum<> solver;
        long long grid[12][12] = {};
        std::vector<long long> expected;
        // 加算と問い合わせの登録を混ぜても、すべての加算がすべての問い合わせに反映される。
        struct Q {
            int l, d, r, u;
        };
        std::vector<Q> queries;
        for (int i = 0; i < 60; ++i) {
            int l = rng() % 13, r = rng() % 13, d = rng() % 13, u = rng() % 13;
            if (l > r) std::swap(l, r);
            if (d > u) std::swap(d, u);
            if (rng() % 2) {
                long long w = static_cast<long long>(rng() % 21) - 10;
                solver.add(l - 6, d - 6, r - 6, u - 6, w);
                for (int x = l; x < r; ++x)
                    for (int y = d; y < u; ++y) grid[x][y] += w;
            } else {
                solver.query(l - 6, d - 6, r - 6, u - 6);
                queries.push_back({l, d, r, u});
            }
        }
        for (auto [l, d, r, u] : queries) {
            long long sum = 0;
            for (int x = l; x < r; ++x)
                for (int y = d; y < u; ++y) sum += grid[x][y];
            expected.push_back(sum);
        }
        assert(solver.solve() == expected);
        assert(solver.solve() == expected);
    }
    StaticRectangleAddRectangleSum<> empty;
    assert(empty.solve().empty());
    empty.query(-1, -1, 1, 1);
    assert(empty.solve() == std::vector<long long>{0});
    const long long a = 4000000000LL;
    StaticRectangleAddRectangleSum<__int128_t> wide;
    wide.add(-a, -a, a, a, 3);
    wide.query(-a, -a, a, a);
    assert(wide.solve()[0] == static_cast<__int128_t>(a) * a * 12);
    StaticRectangleAddRectangleSum<modint998244353> modular;
    modular.add(-a, -a, a, a, 3);
    modular.query(-a, -a, a, a);
    assert(modular.solve()[0] == modint998244353(a) * modint998244353(a) * 12);
    std::cout << "Hello World\n";
}
