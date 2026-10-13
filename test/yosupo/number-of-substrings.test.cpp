#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <iostream>
#include <string>
#include <vector>

#include "../../src/string/suffix-array.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string s;
    std::cin >> s;
    long long n = s.size();
    // 部分文字列は接尾辞の接頭辞。辞書順で前の接尾辞と共通する接頭辞を除いて数える
    long long ans = n * (n + 1) / 2;
    for (int h : lcp_array(s, suffix_array(s))) ans -= h;
    std::cout << ans << '\n';
}
