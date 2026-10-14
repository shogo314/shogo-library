#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// FenwickTree を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/fenwick-tree.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../src/algebra/group.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 30;
        std::vector<long long> a(n);
        for (auto& x : a) x = (long long)(rng() % 21) - 10;
        // 配列から作る場合と、空から apply で作る場合
        FenwickTree<group::Sum<long long>> ft(a);
        FenwickTree<group::Sum<long long>> ft2(n);
        for (int i = 0; i < n; i++) ft2.apply(i, a[i]);
        ok = ok && ft.size() == n;
        for (int q = 0; q < 100; q++) {
            int t = rng() % 3;
            if (n > 0 && t == 0) {
                int i = rng() % n;
                long long x = (long long)(rng() % 21) - 10;
                a[i] += x;
                ft.apply(i, x);
                ft2.apply(i, x);
            } else if (n > 0 && t == 1) {
                int i = rng() % n;
                long long x = (long long)(rng() % 21) - 10;
                a[i] = x;
                ft.set(i, x);
                ft2.set(i, x);
            }
            for (int l = 0; l <= n; l++) {
                long long s = 0;
                for (int r = l; r <= n; r++) {
                    ok = ok && ft.prod(l, r) == s && ft2.prod(l, r) == s;
                    if (l == 0) ok = ok && ft.prefix_prod(r) == s;
                    if (r < n) s += a[r];
                }
            }
            for (int i = 0; i < n; i++) ok = ok && ft.get(i) == a[i];
        }
        ok = ok && ft.all_prod() == ft.prefix_prod(n);
    }

    // max_right: 非負の列で、和が k 以下になる最大の r
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 30;
        std::vector<int> a(n);
        for (auto& x : a) x = rng() % 4;
        FenwickTree<group::Sum<int>> ft(a);
        for (int k = 0; k <= 4 * n + 1; k++) {
            int r = 0, s = 0;
            while (r < n && s + a[r] <= k) s += a[r++];
            ok = ok && ft.max_right([&](int x) { return x <= k; }) == r;
        }
    }

    // ほかの群: xor と、ラムダ式から作る群 (mod 7 の加法)
    {
        std::vector<unsigned> a = {1, 2, 4, 8, 16};
        FenwickTree<group::Xor<unsigned>> ft(a);
        ok = ok && ft.prod(1, 4) == 14u && ft.get(2) == 4u;
        ft.set(2, 7);
        ok = ok && ft.prod(1, 4) == 13u;
        FenwickTree fg(std::vector<int>{3, 5, 6}, Group([](int x, int y) { return (x + y) % 7; }, 0, [](int x) { return (7 - x) % 7; }));
        ok = ok && fg.prod(0, 3) == 0 && fg.prod(1, 3) == 4 && fg.get(2) == 6;
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
