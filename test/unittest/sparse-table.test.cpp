#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// SparseTable を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/sparse-table.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "../../src/algebra/monoid.hpp"

// 列 a の区間積を、すべての区間で愚直な積と比べる
template <typename M>
bool check(const std::vector<typename M::S>& a, const SparseTable<M>& st) {
    int n = a.size();
    if (st.size() != n) return false;
    for (int l = 0; l <= n; l++) {
        typename M::S s = M::e();
        for (int r = l; r <= n; r++) {
            if (!(st.prod(l, r) == s)) return false;
            if (r < n) s = M::op(s, a[r]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!(st.get(i) == a[i])) return false;
    }
    return st.all_prod() == st.prod(0, n);
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 200 && ok; rep++) {
        int n = rng() % 40;
        std::vector<int> a(n);
        for (auto& x : a) x = rng() % 64;
        ok = ok && check(a, SparseTable<monoid::Min<int>>(a));
        ok = ok && check(a, SparseTable<monoid::Max<int>>(a));
        ok = ok && check(a, SparseTable<monoid::Gcd<int>>(a));
        ok = ok && check(a, SparseTable<monoid::And<int>>(a));
        ok = ok && check(a, SparseTable<monoid::Or<int>>(a));
        std::vector<std::pair<int, int>> b(n);
        for (int i = 0; i < n; i++) b[i] = {a[i], i};
        ok = ok && check(b, SparseTable<monoid::MinWith<int>>(b));
    }

    // ラムダ式から作るモノイド
    std::vector<int> v = {5, 3, 8, 1, 9, 2};
    SparseTable st(v, Monoid([](int x, int y) { return std::max(x, y); }, 0));
    ok = ok && st.prod(0, 3) == 8 && st.prod(3, 6) == 9 && st.prod(2, 2) == 0;
    ok = ok && SparseTable<monoid::Min<int>>().size() == 0;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
