#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>

#include "../../../src/math/prime.hpp"

int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        std::cin >> x;
        if (is_prime(x)) ans++;
    }
    std::cout << ans << '\n';
}
