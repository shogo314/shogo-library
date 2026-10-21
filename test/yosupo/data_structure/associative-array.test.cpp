#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include <iostream>

#include "../../../src/data_structures/counter.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;
    // 値 v を「キー k の個数」として持つ (0 なら取り除かれる)
    Counter<long long> a;
    while (q--) {
        int t;
        long long k;
        std::cin >> t >> k;
        if (t == 0) {
            long long v;
            std::cin >> v;
            a[k] = v;
        } else {
            std::cout << a[k] << '\n';
        }
    }
}
