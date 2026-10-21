#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <iostream>
#include <string>
#include <vector>

#include "../../../src/string/string.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string s;
    std::cin >> s;
    std::vector<long long> len = palindrome_lengths(s);
    for (long long i = 0; i < static_cast<long long>(len.size()); i++) std::cout << len[i] << " \n"[i + 1 == static_cast<long long>(len.size())];
}
