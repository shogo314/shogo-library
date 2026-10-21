#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <iostream>

#include "../../../src/base/functions.hpp"

int main() {
    long long a, b;
    std::cin >> a >> b;
    long long x, y;
    // extgcd の解は |x| + |y| が最小で、同じなら x <= y を満たす (問題が要求する解と一致する)
    extgcd(a, b, x, y);
    std::cout << x << ' ' << y << '\n';
}
