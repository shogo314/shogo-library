#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>

#include "../../../src/string/string.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string t, p;
    std::cin >> t >> p;
    for (long long i : kmp_search(t, p)) std::cout << i << '\n';
}
