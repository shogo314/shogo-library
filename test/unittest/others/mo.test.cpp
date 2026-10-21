#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Mo を愚直な実装とランダムに比較する
// 左端と右端で別の操作を渡すコンストラクタ (6 引数) を、区間を deque のまま持つ形で確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/others/mo.hpp"

#include <deque>
#include <iostream>
#include <random>
#include <vector>

// 区間の要素を順番込みで区別するハッシュ
long long ordered_hash(const std::deque<int>& d) {
    long long h = 0;
    for (int x : d) h = (h * 1000003 + x + 1) % 998244353;
    return h;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 500 && ok; rep++) {
        int n = rng() % 30 + 1;
        std::vector<int> a(n);
        for (int& x : a) x = rng() % 1000;
        // 左に足すときは先頭、右に足すときは末尾に入れる。左右を取り違えると順番が崩れる
        auto add_left = [&](std::deque<int>& d, int i) { d.push_front(a[i]); };
        auto delete_left = [&](std::deque<int>& d, int i) {
            if (d.front() != a[i]) ok = false;
            d.pop_front();
        };
        // 位置は long long で渡される。int で受け取る操作 (左) と long long で受け取る操作 (右) のどちらも使える
        auto add_right = [&](std::deque<int>& d, long long i) { d.push_back(a[i]); };
        auto delete_right = [&](std::deque<int>& d, long long i) {
            if (d.back() != a[i]) ok = false;
            d.pop_back();
        };
        Mo mo(n, std::deque<int>(), add_left, delete_left, add_right, delete_right);
        int q = rng() % 30 + 1;
        std::vector<std::pair<int, int>> qs(q);
        for (auto& [l, r] : qs) {
            l = rng() % (n + 1);
            r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            mo.query(l, r);
        }
        auto res = mo.solve<long long>([](std::deque<int>& d) { return ordered_hash(d); });
        for (int i = 0; i < q; i++) {
            auto [l, r] = qs[i];
            std::deque<int> expect(a.begin() + l, a.begin() + r);
            if (res[i] != ordered_hash(expect)) ok = false;
        }
    }
    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
