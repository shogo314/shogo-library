#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// range-mode.hpp の RangeMode を、区間の値を数える愚直な方法と比べる
// 返した値の出現回数が最大で、その回数と一致するかを確かめる (最頻値が複数あればどれでもよい)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/range-mode.hpp"

#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 60 + 1, kinds = rng() % 8 + 1;
        std::vector<int> a(n);
        for (auto& x : a) x = static_cast<int>(rng() % kinds) * 1000 - 3000;
        RangeMode rm(a);
        if (rm.size() != n) ok = false;
        for (int l = 0; l < n; l++) {
            std::map<int, long long> cnt;
            long long mx = 0;
            for (int r = l + 1; r <= n; r++) {
                mx = std::max(mx, ++cnt[a[r - 1]]);
                auto [v, c] = rm.mode(l, r);
                if (c != mx || cnt[v] != mx) ok = false;
            }
        }
    }
    // 文字列でも使える
    std::vector<std::string> s = {"b", "a", "b", "c", "a", "b"};
    RangeMode rs(s);
    if (rs.mode(0, 6) != std::make_pair(std::string("b"), 3LL) || rs.mode(1, 5).second != 2) ok = false;
    if (ok) std::cout << "Hello World" << std::endl;
}
