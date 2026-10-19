#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"

#include "../../src/string/longest-common-substring.hpp"

#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string s, t;
    std::cin >> s >> t;
    auto [i, j, len] = longest_common_substring(s, t);
    std::cout << i << ' ' << i + len << ' ' << j << ' ' << j + len << '\n';
}
