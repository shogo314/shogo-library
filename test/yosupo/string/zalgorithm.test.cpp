#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>

#include "../../../src/string/string.hpp"

int main(void) {
    std::string s;
    std::cin >> s;
    std::vector<long long> z = z_algorithm(s);
    for (long long i = 0; i < static_cast<long long>(z.size()); i++) {
        std::cout << z[i] << " \n"[i + 1 == static_cast<long long>(z.size())];
    }
}
