#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// ErasablePriorityQueue を std::multiset とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/erasable-priority-queue.hpp"

#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <set>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 1000 && ok; rep++) {
        ErasablePriorityQueue<int> max_q;
        ErasablePriorityQueue<int, std::greater<int>> min_q;
        std::multiset<int> st;
        for (int t = 0; t < 100; t++) {
            int op = rng() % 4;
            if (op <= 1 || st.empty()) {
                int x = rng() % 10;
                max_q.push(x);
                min_q.push(x);
                st.insert(x);
            } else if (op == 2) {
                // 含まれている要素をランダムに選んで削除する
                auto it = std::next(st.begin(), rng() % st.size());
                max_q.erase(*it);
                min_q.erase(*it);
                st.erase(it);
            } else {
                if (rng() % 2) {
                    max_q.pop();
                    min_q.erase(*st.rbegin());
                    st.erase(std::prev(st.end()));
                } else {
                    min_q.pop();
                    max_q.erase(*st.begin());
                    st.erase(st.begin());
                }
            }
            if (max_q.size() != (int)st.size() || min_q.size() != (int)st.size()) ok = false;
            if (max_q.empty() != st.empty() || min_q.empty() != st.empty()) ok = false;
            if (!st.empty() && (max_q.top() != *st.rbegin() || min_q.top() != *st.begin())) ok = false;
        }
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
