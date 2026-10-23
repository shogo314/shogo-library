#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"

#include <iostream>
#include <string>

#include "../../../src/string/wildcard-matching.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s, t;
    std::cin >> s >> t;
    std::string ans(s.size() - t.size() + 1, '0');
    for (auto i : wildcard_pattern_matching(s, t, '*')) ans[i] = '1';
    std::cout << ans << '\n';
}
