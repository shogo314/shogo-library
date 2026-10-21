#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// range-count-distinct.hpp の RangeCountDistinct を、std::set で数えたものとすべての区間で比べる
// 空の列、空の区間、文字列の値も調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/range-count-distinct.hpp"

#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    {
        RangeCountDistinct rcd(std::vector<int>{});
        if (rcd.size() != 0 || rcd.count(0, 0) != 0) ok = false;
    }
    for (int rep = 0; rep < 500 && ok; rep++) {
        int n = rng() % 30 + 1, k = rng() % 8 + 1;
        std::vector<long long> a(n);
        std::vector<std::string> s(n);
        for (int i = 0; i < n; i++) {
            a[i] = static_cast<long long>(rng() % k) - 3;
            s[i] = std::string(rng() % 3, 'a' + rng() % 2);
        }
        RangeCountDistinct ra(a);
        RangeCountDistinct rs(s);
        for (int l = 0; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                std::set<long long> sa(a.begin() + l, a.begin() + r);
                std::set<std::string> ss(s.begin() + l, s.begin() + r);
                if (ra.count(l, r) != static_cast<long long>(sa.size())) ok = false;
                if (rs.count(l, r) != static_cast<long long>(ss.size())) ok = false;
            }
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
