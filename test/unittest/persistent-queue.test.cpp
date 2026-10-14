#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// PersistentQueue を愚直な実装 (版ごとに std::deque を持つ) とランダムに比較する
// 古い版から更新しても、ほかの版が変わらないことを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/persistent-queue.hpp"

#include <deque>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        std::vector<PersistentQueue<int>> que(1);
        std::vector<std::deque<int>> naive(1);
        for (int t = 0; t < 60; t++) {
            int ver = rng() % que.size();
            int op = rng() % 3;
            if (op == 0 || naive[ver].empty()) {
                int x = rng() % 100;
                que.push_back(que[ver].push(x));
                naive.push_back(naive[ver]);
                naive.back().push_back(x);
            } else if (op == 1) {
                que.push_back(que[ver].pop());
                naive.push_back(naive[ver]);
                naive.back().pop_front();
            } else {
                if (que[ver].front() != naive[ver].front() || que[ver].back() != naive[ver].back()) ok = false;
            }
        }
        // すべての版が、作ったときの内容のままか
        for (int i = 0; i < int(que.size()); i++) {
            const auto& d = naive[i];
            if (que[i].size() != int(d.size()) || que[i].empty() != d.empty()) ok = false;
            if (que[i].to_vector() != std::vector<int>(d.begin(), d.end())) ok = false;
            if (!d.empty() && (que[i].front() != d.front() || que[i].back() != d.back())) ok = false;
        }
    }

    // 長いキューで、先頭を 1 つずつ取り除きながら確かめる
    {
        const int n = 200000;
        PersistentQueue<int> q;
        for (int i = 0; i < n; i++) q = q.push(i);
        PersistentQueue<int> full = q;
        for (int i = 0; i < n; i++) {
            if (q.front() != i) ok = false;
            q = q.pop();
        }
        if (!q.empty() || full.size() != n || full.front() != 0 || full.back() != n - 1) ok = false;
        // 空になった版にも push できる
        q = q.push(-1);
        if (q.front() != -1 || q.size() != 1) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
