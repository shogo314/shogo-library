#define PROBLEM "https://yukicoder.me/problems/no/186"

#include "../../src/math/number-theory.hpp"

#include <iostream>
#include <vector>

int main() {
    std::vector<long long> x(3), y(3);
    for (int i = 0; i < 3; ++i) std::cin >> x[i] >> y[i];
    auto res = crt(x, y);
    if(!res) std::cout << -1 << '\n';
    else if(res->x == 0) std::cout << res->lcm << '\n';
    else std::cout << res->x << '\n';
}

