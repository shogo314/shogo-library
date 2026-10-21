#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>

#include "../../../src/math/prime.hpp"

int main() {
    long long n;
    std::cin >> n;
    std::cout << totient(n) << '\n';
}
