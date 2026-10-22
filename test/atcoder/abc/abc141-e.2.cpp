#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"
#define IGNORE

// longest_non_overlapping_repeated_substring を使う。O(N log N)

#include <iostream>
#include <string>

#include "../../../src/string/longest-common-substring.hpp"

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::cout << std::get<2>(longest_non_overlapping_repeated_substring(s)) << '\n';
}
