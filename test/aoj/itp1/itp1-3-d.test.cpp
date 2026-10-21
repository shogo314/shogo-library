#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"

// c の約数を列挙し、a 以上 b 以下のものを数える

#include <iostream>

#include "../../../src/math/prime.hpp"

int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;
    int ans = 0;
    for (long long d : divisors(c)) {
        if (a <= d && d <= b) ans++;
    }
    std::cout << ans << '\n';
}
