#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0022"

#include <iostream>
#include <vector>

#include "../../src/base/container_func.hpp"

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<long long> a(n);
        for (auto& x : a) std::cin >> x;
        // 1 項以上の連続部分列の和の最大値
        std::cout << maximum_subarray(a) << '\n';
    }
}
