#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// hungarian.hpp の hungarian を、列の選び方の全探索と比べる
// 負のコストと、行より列が多い長方形の行列を含めて調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/hungarian.hpp"

#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 6, m = n + rng() % 3;
        if (m == 0) m = 1;
        std::vector<std::vector<long long>> a(n, std::vector<long long>(m));
        for (auto& row : a)
            for (auto& x : row) x = static_cast<long long>(rng() % 21) - 10;
        // m 個の列から並べ替えで先頭 n 個を選ぶ
        std::vector<int> perm(m);
        std::iota(perm.begin(), perm.end(), 0);
        long long best = std::numeric_limits<long long>::max();
        do {
            long long s = 0;
            for (int i = 0; i < n; i++) s += a[i][perm[i]];
            best = std::min(best, s);
        } while (std::next_permutation(perm.begin(), perm.end()));
        if (n == 0) best = 0;
        auto res = hungarian(a);
        if (res.cost != best) ok = false;
        // match が異なる列で、cost と一致する
        if (static_cast<int>(res.match.size()) != n) ok = false;
        std::vector<bool> used(m, false);
        long long s = 0;
        for (int i = 0; i < n && ok; i++) {
            long long j = res.match[i];
            if (j < 0 || j >= m || used[j]) {
                ok = false;
                break;
            }
            used[j] = true;
            s += a[i][j];
        }
        if (s != res.cost) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
