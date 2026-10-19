#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include <iostream>
#include <string>
#include <vector>

#include "../../src/data_structures/fast-set.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::string t;
    std::cin >> t;
    std::vector<bool> v(n);
    for (int i = 0; i < n; i++) v[i] = t[i] == '1';
    FastSet s(v);
    while (q--) {
        int c;
        long long k;
        std::cin >> c >> k;
        if (c == 0) {
            s.insert(k);
        } else if (c == 1) {
            s.erase(k);
        } else if (c == 2) {
            std::cout << s.contains(k) << '\n';
        } else if (c == 3) {
            std::cout << s.next(k) << '\n';
        } else {
            std::cout << s.prev(k) << '\n';
        }
    }
}
