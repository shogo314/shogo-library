#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// PersistentStack を愚直な実装 (版ごとに std::vector を持つ) とランダムに比較する
// 古い版から更新しても、ほかの版が変わらないことを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/persistent-stack.hpp"

#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        std::vector<PersistentStack<int>> st(1);
        std::vector<std::vector<int>> naive(1);
        for (int t = 0; t < 60; t++) {
            int ver = rng() % st.size();
            int op = rng() % 3;
            if (op == 0 || naive[ver].empty()) {
                int x = rng() % 100;
                st.push_back(st[ver].push(x));
                naive.push_back(naive[ver]);
                naive.back().push_back(x);
            } else if (op == 1) {
                st.push_back(st[ver].pop());
                naive.push_back(naive[ver]);
                naive.back().pop_back();
            } else {
                if (st[ver].top() != naive[ver].back()) ok = false;
            }
        }
        // すべての版が、作ったときの内容のままか
        for (int i = 0; i < static_cast<int>(st.size()); i++) {
            const auto& v = naive[i];
            if (st[i].size() != static_cast<int>(v.size()) || st[i].empty() != v.empty()) ok = false;
            if (st[i].to_vector() != v) ok = false;
            if (!v.empty() && st[i].top() != v.back()) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
