#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B"

#include <iostream>

#include "../../src/utility/range.hpp"

int main() {
    long long n, x;
    while (std::cin >> n >> x && (n != 0 || x != 0)) {
        int cnt = 0;
        for (long long a : Range(1, n + 1)) {
            for (long long b : Range(a + 1, n + 1)) {
                for (long long c : Range(b + 1, n + 1)) {
                    if (a + b + c == x) cnt++;
                }
            }
        }
        std::cout << cnt << '\n';
    }
}
