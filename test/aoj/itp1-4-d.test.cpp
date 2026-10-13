#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_D"

#include <iostream>
#include <vector>

#include "../../src/utility/container_func.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    std::cout << min(a) << ' ' << max(a) << ' ' << sum(a) << '\n';
}
