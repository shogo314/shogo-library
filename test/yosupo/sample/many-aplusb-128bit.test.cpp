#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include <iostream>

#include "../../../src/base/io.hpp"

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        __int128_t a, b;
        std::cin >> a >> b;
        std::cout << a + b << '\n';
    }
}
