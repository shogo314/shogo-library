#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <iostream>

#include "../../src/math/prime.hpp"

int main() {
    long long n;
    std::cin >> n;
    std::cout << n << ':';
    for (auto [p, e] : factorize(n)) {
        for (int i = 0; i < e; i++) std::cout << ' ' << p;
    }
    std::cout << '\n';
}
