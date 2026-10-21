#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_B"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/segtree.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    RMinQ<long long> seg_min(a);
    RMaxQ<long long> seg_max(a);
    int q;
    std::cin >> q;
    while (q--) {
        int com, b, e;
        std::cin >> com >> b >> e;
        if (com == 0) {
            std::cout << seg_min.prod(b, e) << '\n';
        } else {
            std::cout << seg_max.prod(b, e) << '\n';
        }
    }
}
