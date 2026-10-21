#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include <string>

#include "../../../src/dp/longest-common-subsequence.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int q;
    std::cin >> q;
    while (q--) {
        std::string x, y;
        std::cin >> x >> y;
        std::cout << longest_common_subsequence(x, y) << '\n';
    }
}
