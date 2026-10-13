#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_10_C"

#include <iostream>

#include "../../src/utility/bit.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;
    unsigned long long s = 0;
    while (q--) {
        int op;
        std::cin >> op;
        if (op <= 3) {
            int i;
            std::cin >> i;
            unsigned long long b = 1ULL << i;
            if (op == 0) std::cout << ((s & b) ? 1 : 0) << '\n';
            if (op == 1) s |= b;
            if (op == 2) s &= ~b;
            if (op == 3) s ^= b;
        } else if (op == 4) {
            std::cout << (s == ~0ULL ? 1 : 0) << '\n';
        } else if (op == 5) {
            std::cout << (s != 0 ? 1 : 0) << '\n';
        } else if (op == 6) {
            std::cout << (s == 0 ? 1 : 0) << '\n';
        } else if (op == 7) {
            // popcount は非負の long long を受け取るので、上位 1 ビットと残りに分けて数える
            std::cout << popcount(static_cast<long long>(s >> 1)) + static_cast<int>(s & 1) << '\n';
        } else {
            std::cout << s << '\n';
        }
    }
}
