#define PROBLEM "https://atcoder.jp/contests/abc331/tasks/abc331_f"
#define IGNORE

#include <iostream>

#include "../../../src/data_structures/segtree.hpp"
#include "../../../src/string/rolling-hash.hpp"

RollingHash rh;
struct RHMonoid {
    using S = RHString;
    static S op(const S& a, const S& b) { return a + b; }
    static S e() { return RHString(rh); }
};

int main() {
    int N, Q;
    std::string S;
    std::cin >> N >> Q >> S;
    std::vector<RHString> init;
    init.reserve(N);
    for (char c : S) {
        init.emplace_back(rh, c);
    }
    SegTree<RHMonoid> seg(init);
    while (Q--) {
        int q;
        std::cin >> q;
        if (q == 1) {
            int x;
            char c;
            std::cin >> x >> c;
            seg.set(x - 1, RHString(rh, c));
        } else {
            int L, R;
            std::cin >> L >> R;
            std::cout << (seg.prod(L - 1, R).is_palindrome() ? "Yes" : "No") << std::endl;
        }
    }
}