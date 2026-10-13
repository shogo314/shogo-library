#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <iostream>
#include <string>
#include <vector>

#include "../../src/string/string.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string s;
    std::cin >> s;
    std::vector<int> len = palindrome_lengths(s);
    for (int i = 0; i < (int)len.size(); i++) std::cout << len[i] << " \n"[i + 1 == (int)len.size()];
}
