#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// TwoSat をすべての割り当てを試す愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/two-sat.hpp"

#include <iostream>
#include <random>
#include <vector>

// 条件の種類: 0 = clause, 1 = imply, 2 = fix, 3 = nand
struct Cond {
    int type, i;
    bool f;
    int j;
    bool g;
    bool holds(const std::vector<bool>& x) const {
        bool a = x[i] == f, b = x[j] == g;
        if (type == 0) return a || b;
        if (type == 1) return !a || b;
        if (type == 2) return a;
        return !(a && b);
    }
};

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    int sat_count = 0;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 8 + 1;
        int m = rng() % (3 * n);
        std::vector<Cond> cs(m);
        TwoSat ts(n);
        for (auto& c : cs) {
            c = {static_cast<int>(rng() % 4), static_cast<int>(rng() % n), static_cast<bool>(rng() % 2), static_cast<int>(rng() % n), static_cast<bool>(rng() % 2)};
            if (c.type == 0) ts.add_clause(c.i, c.f, c.j, c.g);
            if (c.type == 1) ts.add_imply(c.i, c.f, c.j, c.g);
            if (c.type == 2) ts.add_fix(c.i, c.f);
            if (c.type == 3) ts.add_nand(c.i, c.f, c.j, c.g);
        }
        bool expected = false;
        for (int mask = 0; mask < (1 << n) && !expected; mask++) {
            std::vector<bool> x(n);
            for (int k = 0; k < n; k++) x[k] = mask >> k & 1;
            bool all = true;
            for (const auto& c : cs) all = all && c.holds(x);
            expected = all;
        }
        bool got = ts.satisfiable();
        ok = ok && got == expected && ts.size() == n;
        if (got) {
            sat_count++;
            const auto& x = ts.answer();
            for (const auto& c : cs) ok = ok && c.holds(x);
        }
    }
    // 充足可能な場合と不可能な場合の両方を試せていること
    ok = ok && 100 < sat_count && sat_count < 2900;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
