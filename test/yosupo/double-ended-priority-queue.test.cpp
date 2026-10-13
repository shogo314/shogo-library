#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include <functional>
#include <iostream>

#include "../../src/data_structures/erasable-priority-queue.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    // 最大値用と最小値用の 2 つを持ち、片方から取り出したらもう片方からも削除する
    ErasablePriorityQueue<int> max_q;
    ErasablePriorityQueue<int, std::greater<int>> min_q;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        max_q.push(x);
        min_q.push(x);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int x;
            std::cin >> x;
            max_q.push(x);
            min_q.push(x);
        } else if (t == 1) {
            int x = min_q.top();
            min_q.pop();
            max_q.erase(x);
            std::cout << x << '\n';
        } else {
            int x = max_q.top();
            max_q.pop();
            min_q.erase(x);
            std::cout << x << '\n';
        }
    }
}
