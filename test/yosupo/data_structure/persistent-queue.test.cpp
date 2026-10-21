#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include "../../../src/data_structures/persistent-queue.hpp"

#include <iostream>
#include <vector>

int main() {
    int q;
    std::cin >> q;
    // que[i + 1] がクエリ i の後の版、que[0] が初期の版
    std::vector<PersistentQueue<int>> que(q + 1);
    for (int i = 0; i < q; i++) {
        int type, t;
        std::cin >> type >> t;
        const PersistentQueue<int>& prev = que[t + 1];
        if (type == 0) {
            int x;
            std::cin >> x;
            que[i + 1] = prev.push(x);
        } else {
            std::cout << prev.front() << '\n';
            que[i + 1] = prev.pop();
        }
    }
}
