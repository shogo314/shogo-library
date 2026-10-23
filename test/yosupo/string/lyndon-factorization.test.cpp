#define PROBLEM "https://judge.yosupo.jp/problem/lyndon_factorization"

#include <iostream>
#include <string>

#include "../../../src/string/string.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    auto a = lyndon_factorization(s);
    for (int i = 0; i < static_cast<int>(a.size()); i++) std::cout << a[i] << " \n"[i + 1 == static_cast<int>(a.size())];
}
