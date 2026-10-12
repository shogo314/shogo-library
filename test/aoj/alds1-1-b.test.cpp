#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B"

#include <iostream>
#include <vector>

#include "../../src/base/container_func.hpp"

int main() {
    long long x, y;
    std::cin >> x >> y;
    std::cout << gcd(std::vector<long long>{x, y}) << '\n';  // コンテナ全体の gcd
}
