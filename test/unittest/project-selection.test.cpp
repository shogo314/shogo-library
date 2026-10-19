#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// ProjectSelection を、すべての割り当てを試す愚直な実装とランダムに比べる
// 負のコスト、劣モジュラな 2 変数のコスト、禁止、すべて同じなら利得 を含む
// solve() の値と、assignment() の割り当てのコストが最小値と一致するかを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/project-selection.hpp"

#include <functional>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

int main() {
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 10 + 1;
        ProjectSelection<long long> ps(n);
        // 割り当て x のコスト (禁止された割り当ては std::nullopt の代わりに大きい値)
        std::vector<std::function<long long(const std::vector<bool>&)>> terms;
        const long long BIG = std::numeric_limits<long long>::max() / 4;
        auto rnd = [&](int lo, int hi) { return static_cast<long long>(lo + static_cast<int>(rng() % (hi - lo + 1))); };
        int q = rng() % 15;
        for (int i = 0; i < q; i++) {
            int type = rng() % 6;
            long long u = rng() % n, v = rng() % n;
            if (type == 0) {
                long long c0 = rnd(-10, 10), c1 = rnd(-10, 10);
                ps.add_cost(u, c0, c1);
                terms.push_back([=](const std::vector<bool>& x) { return x[u] ? c1 : c0; });
            } else if (type == 1) {
                bool a = rng() % 2;
                long long c = rnd(-10, 10);
                ps.add_cost_if(u, a, c);
                terms.push_back([=](const std::vector<bool>& x) { return x[u] == a ? c : 0; });
            } else if (type == 2 && u != v) {
                // 劣モジュラになるまで c01 を増やす
                long long c00 = rnd(-10, 10), c01 = rnd(-10, 10), c10 = rnd(-10, 10), c11 = rnd(-10, 10);
                if (c01 + c10 < c00 + c11) c01 += c00 + c11 - c01 - c10 + rnd(0, 3);
                ps.add_cost(u, v, c00, c01, c10, c11);
                terms.push_back([=](const std::vector<bool>& x) { return x[u] ? (x[v] ? c11 : c10) : (x[v] ? c01 : c00); });
            } else if (type == 3 && u != v) {
                bool a = rng() % 2, b = rng() % 2;
                long long c = a != b ? rnd(0, 10) : rnd(-10, 0);
                ps.add_cost_if(u, a, v, b, c);
                terms.push_back([=](const std::vector<bool>& x) { return x[u] == a && x[v] == b ? c : 0; });
            } else if (type == 4 && u != v) {
                bool a = rng() % 2;
                ps.forbid(u, a, v);
                terms.push_back([=](const std::vector<bool>& x) { return x[u] == a && x[v] == !a ? BIG : 0; });
            } else if (type == 5) {
                std::vector<long long> vs;
                for (int k = 0; k < n; k++)
                    if (rng() % 3 == 0) vs.push_back(k);
                bool a = rng() % 2;
                long long g = rnd(0, 10);
                ps.add_gain_if_all(vs, a, g);
                terms.push_back([=](const std::vector<bool>& x) {
                    for (long long k : vs)
                        if (x[k] != a) return 0LL;
                    return -g;
                });
            } else {
                long long c = rnd(-5, 5);
                ps.add_constant(c);
                terms.push_back([=](const std::vector<bool>&) { return c; });
            }
        }
        auto cost = [&](const std::vector<bool>& x) {
            long long s = 0;
            for (const auto& f : terms) {
                long long c = f(x);
                if (c == BIG) return BIG;
                s += c;
            }
            return s;
        };
        long long best = BIG;
        for (int mask = 0; mask < (1 << n); mask++) {
            std::vector<bool> x(n);
            for (int k = 0; k < n; k++) x[k] = mask >> k & 1;
            best = std::min(best, cost(x));
        }
        long long got = ps.solve();
        check(got == best, "solve の値");
        check(static_cast<long long>(ps.assignment().size()) == n && cost(ps.assignment()) == best, "assignment のコスト");
    }

    // 変数 0 個
    {
        ProjectSelection<long long> ps(0);
        ps.add_constant(3);
        check(ps.solve() == 3 && ps.assignment().empty(), "変数なし");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
