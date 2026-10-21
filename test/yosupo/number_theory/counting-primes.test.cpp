#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include <iostream>

#include "../../../src/math/prime-counting.hpp"

int main() {
    long long n;
    std::cin >> n;
    std::cout << prime_count(n) << '\n';
}
