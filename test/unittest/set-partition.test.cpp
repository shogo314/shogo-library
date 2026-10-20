#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// min_set_partition を、集合の分け方をすべて試す愚直な実装と比べる
// 使ってよい集合族が部分集合について閉じている場合と、閉じていない場合の両方を試す
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/dp/set-partition.hpp"

#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 8;
        std::vector<bool> feasible(1 << n);
        for (int S = 1; S < (1 << n); S++) feasible[S] = rng() % 3 == 0;
        if (rep % 2 == 0) {
            // 部分集合について閉じさせる (使ってよい集合の部分集合も使ってよい)
            for (int S = (1 << n) - 1; S > 0; S--)
                if (feasible[S])
                    for (int T = S; T > 0; T = (T - 1) & S) feasible[T] = true;
        }
        // 愚直: 要素 i に「何番目の集合か」を割り当てる分け方をすべて試す
        long long expect = n == 0 ? 0 : -1;
        std::vector<int> b(n, 0);
        while (n > 0) {
            int k = 0;
            for (int x : b) k = std::max(k, x + 1);
            std::vector<int> parts(k, 0);
            for (int i = 0; i < n; i++) parts[b[i]] |= 1 << i;
            bool good = true;
            for (int p : parts) good &= p != 0 && feasible[p];
            if (good && (expect == -1 || k < expect)) expect = k;
            int i = 0;
            while (i < n && ++b[i] == n) b[i++] = 0;
            if (i == n) break;
        }
        if (min_set_partition(n, feasible) != expect) ok = false, std::cerr << "min_set_partition" << std::endl;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
