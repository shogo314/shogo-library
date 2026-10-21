#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"

#include <iostream>

#include "../../../src/base/functions.hpp"
#include "../../../src/data_structures/imos.hpp"

int main() {
    int n, t;
    std::cin >> n >> t;
    // 時刻 i (0 <= i < t) に店にいる人数
    Imos<acted_monoid::AddSum<int>> imos(t);
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        imos.apply(l, r, 1);
    }
    int ans = 0;
    for (int i = 0; i < t; i++) chmax(ans, imos.get(i));
    std::cout << ans << '\n';
}
