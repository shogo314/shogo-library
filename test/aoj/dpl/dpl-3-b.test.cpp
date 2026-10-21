#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include <iostream>
#include <vector>

#include "../../../src/dp/largest-rectangle.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> c(h, std::vector<int>(w));
    for (auto& row : c)
        for (auto& x : row) std::cin >> x;
    std::cout << largest_rectangle(h, w, [&](long long i, long long j) { return c[i][j] == 0; }) << '\n';
}
