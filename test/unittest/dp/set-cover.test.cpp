#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// min_set_cover を、覆える集合を個数の小さい順に広げていく愚直な実装と比べる
// 使ってよい集合族が部分集合について閉じている場合は min_set_partition とも比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/dp/set-cover.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../../src/dp/set-partition.hpp"

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % (rep < 2000 ? 9 : 13);
        const int N = 1 << n;
        std::vector<bool> feasible(N);
        // 使ってよい集合の多さを変える (少ないと覆えないことがある)
        const int density = 1 + rng() % 20;
        for (int S = 0; S < N; S++) feasible[S] = static_cast<int>(rng() % 100) < density;
        const bool closed = rep % 2 == 0;
        if (closed) {
            for (int S = N - 1; S > 0; S--)
                if (feasible[S])
                    for (int T = S; T > 0; T = (T - 1) & S) feasible[T] = true;
        }
        // 愚直: k 個で覆える集合 (の和集合) の全体を、k を 1 つずつ増やして広げる
        long long expect = n == 0 ? 0 : -1;
        std::vector<bool> reach(N, false);
        reach[0] = true;
        std::vector<int> sets;
        for (int S = 0; S < N; S++)
            if (feasible[S]) sets.push_back(S);
        for (int k = 1; k <= n && expect == -1; k++) {
            std::vector<bool> next = reach;
            for (int U = 0; U < N; U++)
                if (reach[U])
                    for (int T : sets) next[U | T] = true;
            reach = next;
            if (reach[N - 1]) expect = k;
        }
        long long res = min_set_cover(n, feasible);
        if (res != expect) ok = false, std::cerr << "min_set_cover " << rep << ' ' << res << ' ' << expect << std::endl;
        if (closed && res != min_set_partition(n, feasible)) ok = false, std::cerr << "min_set_partition との違い" << std::endl;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
