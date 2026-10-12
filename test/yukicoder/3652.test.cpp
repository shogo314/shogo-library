#define PROBLEM "https://yukicoder.me/problems/no/3652"

#include <iostream>
#include <string>
#include <vector>

#include "../../src/data_structures/segtree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    using S = monoid::Parenthesis::S;
    std::vector<S> v(s.begin(), s.end());
    SegTree<monoid::Parenthesis> seg(v);
    while (q--) {
        int type, a, b;
        std::cin >> type >> a >> b;
        if (type == 1) {
            seg.set(a - 1, S(b == 1 ? '(' : ')'));
        } else {
            // 対応の取れていない ')' と '(' 以外はすべて消せる
            S p = seg.prod(a - 1, b);
            std::cout << (b - a + 1) - (p.close + p.open) << '\n';
        }
    }
}
