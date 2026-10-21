#define PROBLEM "https://atcoder.jp/contests/abc408/tasks/abc408_g"
#define IGNORE

#include <iostream>

#include "../../../src/math/stern-brocot.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, c, d;
        std::cin >> a >> b >> c >> d;
        std::cout << stern_brocot::simplest_between(Rational<long long>(a, b), Rational<long long>(c, d)).den() << '\n';
    }
}
