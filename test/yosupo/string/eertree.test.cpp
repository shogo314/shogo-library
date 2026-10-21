#define PROBLEM "https://judge.yosupo.jp/problem/eertree"

#include <iostream>
#include <string>

#include "../../../src/string/palindromic-tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string s;
    std::cin >> s;
    PalindromicTree<26, 'a'> pt(s);
    // 問題の番号は ODD が -1、EVEN が 0、回文が 1 から。ライブラリの番号から 1 を引けばよい
    std::cout << pt.count_distinct() << '\n';
    for (long long v = 2; v < pt.size(); v++) std::cout << pt.parent(v) - 1 << ' ' << pt.suffix_link(v) - 1 << '\n';
    for (long long i = 0; i < pt.length(); i++) std::cout << pt.longest_suffix(i) - 1 << (i + 1 == pt.length() ? '\n' : ' ');
}
