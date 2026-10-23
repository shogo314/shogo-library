#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include <iostream>

#include "../../../src/data_structures/binary-trie.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    BinaryTrie<30> s;
    for (int i = 0; i < n; i++) {
        unsigned long long a;
        std::cin >> a;
        s.insert(a);
    }
    while (q--) {
        int t;
        unsigned long long x;
        std::cin >> t >> x;
        if (t == 0) {
            if (s.count(x) == 0) s.insert(x);
        } else if (t == 1) {
            s.erase(x);
        } else if (t == 2) {
            if (static_cast<long long>(x) > s.size()) {
                std::cout << -1 << '\n';
            } else {
                std::cout << s.nth_element(x - 1) << '\n';
            }
        } else if (t == 3) {
            std::cout << s.bisect_right(x) << '\n';
        } else if (t == 4) {
            long long k = s.bisect_right(x);
            if (k == 0) {
                std::cout << -1 << '\n';
            } else {
                std::cout << s.nth_element(k - 1) << '\n';
            }
        } else {
            long long k = s.bisect_left(x);
            if (k == s.size()) {
                std::cout << -1 << '\n';
            } else {
                std::cout << s.nth_element(k) << '\n';
            }
        }
    }
}
