#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// bin_packing を、品物をどの瓶に入れるかをすべて試す愚直な実装と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/dp/bin-packing.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 8;
        long long C = rng() % 15 + 1;
        std::vector<long long> w(n);
        for (auto& x : w) x = rng() % (C + 2) + 1;  // C を超える品物もたまに作る
        long long expect = -1;
        if (std::all_of(w.begin(), w.end(), [&](long long x) { return x <= C; })) {
            // 品物 i を瓶 b[i] (< n) に入れる割り当てをすべて試す
            expect = n;
            std::vector<int> b(n, 0);
            while (true) {
                std::vector<long long> load(n, 0);
                for (int i = 0; i < n; i++) load[b[i]] += w[i];
                if (std::all_of(load.begin(), load.end(), [&](long long x) { return x <= C; }))
                    expect = std::min<long long>(expect, std::count_if(load.begin(), load.end(), [](long long x) { return x > 0; }));
                int i = 0;
                while (i < n && ++b[i] == n) b[i++] = 0;
                if (i == n) break;
            }
        }
        if (bin_packing(w, C) != expect) ok = false, std::cerr << "bin_packing" << std::endl;
    }
    if (bin_packing({}, 5) != 0) ok = false;
    // 同じ瓶の数なら最後の瓶が軽い方を残さないと誤る例 (ランダムでは出にくいので決め打ちで確かめる)
    if (bin_packing({3, 4, 4, 4, 2, 9, 2}, 10) != 3) ok = false, std::cerr << "bin_packing 重さの比較" << std::endl;
    if (ok) std::cout << "Hello World" << std::endl;
}
