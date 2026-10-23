#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// cartesian-tree.hpp の cartesian_tree を、定義どおり (区間の最小を根にして左右を再帰) に作ったものと比べる
// 同じ値を含む列と、std::greater で最大を根にする場合も調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/cartesian-tree.hpp"

#include <functional>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 12;
        std::vector<int> a(n);
        for (auto& x : a) x = rng() % 6;
        auto check = [&](auto comp) {
            std::vector<long long> parent(n, -1), left(n, -1), right(n, -1);
            // [l, r) の最も comp で前に来る要素 (同じなら左) を根にして、親を p にする
            auto build = [&](auto self, int l, int r, long long p) -> long long {
                if (l >= r) return -1;
                int m = l;
                for (int i = l + 1; i < r; i++)
                    if (comp(a[i], a[m])) m = i;
                parent[m] = p;
                left[m] = self(self, l, m, m);
                right[m] = self(self, m + 1, r, m);
                return m;
            };
            long long root = build(build, 0, n, -1);
            auto t = cartesian_tree(a, comp);
            if (t.root != root || t.parent != parent || t.left != left || t.right != right) ok = false;
        };
        check(std::less<int>());
        check(std::greater<int>());
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
