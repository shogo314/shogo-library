#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_D"

#include <iostream>

#include "../../src/data_structures/counter.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;
    Counter<long long> s;
    long long total = 0;  // 要素数 (重複を含む)
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 0) {
            long long x;
            std::cin >> x;
            s.inc(x, 1);
            total++;
            std::cout << total << '\n';
        } else if (op == 1) {
            long long x;
            std::cin >> x;
            std::cout << s[x] << '\n';
        } else if (op == 2) {
            long long x;
            std::cin >> x;
            total -= s[x];
            s[x] = 0;  // 個数を 0 にすると取り除かれる
        } else {
            long long l, r;
            std::cin >> l >> r;
            for (auto it = s.data.lower_bound(l); it != s.data.end() && it->first <= r; ++it) {
                for (long long i = 0; i < it->second; i++) std::cout << it->first << '\n';
            }
        }
    }
}
