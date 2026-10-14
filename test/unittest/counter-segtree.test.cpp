#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// CounterSegTree を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/counter-segtree.hpp"

#include <iostream>
#include <random>
#include <utility>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 9 + 1;
        std::vector<int> v(n);
        for (int& x : v) x = rng() % 6;
        CounterSegTree<int> seg(v);
        // key_type / mapped_type は外から使える
        static_assert(std::is_same_v<CounterSegTree<int>::key_type, int>);
        static_assert(std::is_same_v<CounterSegTree<int>::mapped_type, long long>);
        for (int t = 0; t < 20; t++) {
            if (rng() % 2) {
                int k = rng() % n, x = rng() % 6;
                seg.set(k, x);
                v[k] = x;
            }
            for (int k = 0; k < n; k++) {
                if (seg.get(k) != v[k]) ok = false;
            }
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            int x = rng() % 7;
            // lower_bound: [l, r) にある x 以上の最小の値とその個数 (なければ std::nullopt)
            int best = -1, cnt = 0, same = 0;
            for (int i = l; i < r; i++) {
                if (v[i] >= x && (best == -1 || v[i] < best)) best = v[i];
                if (v[i] == x) same++;
            }
            for (int i = l; i < r; i++) {
                if (v[i] == best) cnt++;
            }
            auto lb = seg.lower_bound(l, r, x);
            if (cnt == 0) {
                if (lb) ok = false;
            } else {
                if (!lb || lb->first != best || lb->second != cnt) ok = false;
            }
            // find: [l, r) にある x の個数
            auto f = seg.find(l, r, x);
            if (f.first != x || f.second != same) ok = false;
        }
    }
    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
