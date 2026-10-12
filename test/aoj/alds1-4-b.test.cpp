#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B"

#include <cassert>
#include <iostream>
#include <set>
#include <vector>

#include "../../src/base/container_func.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    for (auto& x : s) std::cin >> x;
    std::set<int> st(s.begin(), s.end());
    int q;
    std::cin >> q;
    int c = 0;
    while (q--) {
        int t;
        std::cin >> t;
        // S はソート済み (重複あり) なので、t の個数は bisect_right - bisect_left
        bool found = bisect_right(s, t) - bisect_left(s, t) > 0;
        // std::set ではメンバ関数の find を使う contains とも一致するはず
        assert(found == contains(st, t));
        if (found) c++;
    }
    std::cout << c << '\n';
}
