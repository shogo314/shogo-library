#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/sliding-window-aggregation.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, l;
    std::cin >> n >> l;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<int> res = sliding_window_min(a, l);
    for (int i = 0; i < static_cast<int>(res.size()); i++) std::cout << res[i] << " \n"[i + 1 == static_cast<int>(res.size())];
}
