#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include <iostream>
#include <vector>

#include "../../src/math/quotients.hpp"

int main() {
    long long n;
    std::cin >> n;
    auto qs = enumerate_quotients(n);
    // 商の昇順に出力する
    std::cout << qs.size() << '\n';
    for (int i = static_cast<int>(qs.size()) - 1; i >= 0; i--) std::cout << qs[i].q << " \n"[i == 0];
}
