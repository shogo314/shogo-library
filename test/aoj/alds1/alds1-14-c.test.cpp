#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include <iostream>
#include <string>
#include <vector>

#include "../../../src/string/rolling-hash.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> text(h);
    for (auto& s : text) std::cin >> s;
    int r, c;
    std::cin >> r >> c;
    std::vector<std::string> pattern(r);
    for (auto& s : pattern) std::cin >> s;
    for (auto [i, j] : pattern_match_2d(text, pattern)) std::cout << i << ' ' << j << '\n';
}
