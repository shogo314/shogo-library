#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_5_A"

#include <iostream>
#include <utility>
#include <vector>

#include "../../src/base/io.hpp"
#include "../../src/utility/container_func.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::pair<long long, long long>> p(n);
    std::cin >> p;                                   // pair の vector をまとめて読む
    sort(p);                                         // x、同じなら y の昇順
    for (const auto& e : p) std::cout << e << '\n';  // pair を "x y" で出力
}
