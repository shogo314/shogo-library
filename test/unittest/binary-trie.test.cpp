#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// BinaryTrie の clear を、操作列の途中で呼んで std::multiset による愚直な実装と比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>
#include <set>

#include "../../src/data_structures/binary-trie.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        BinaryTrie<4, unsigned> bt;
        std::multiset<unsigned> ms;
        unsigned x_all = 0;  // 集合全体に作用させた xor
        for (int t = 0; t < 40; t++) {
            int op = rng() % 10;
            if (op == 0) {
                // clear: 要素も、それまでに作用させた xor も消える
                bt.clear();
                ms.clear();
                x_all = 0;
            } else if (op == 1) {
                unsigned x = rng() % 16;
                bt.apply_xor(x);
                x_all ^= x;
            } else if (op <= 6) {
                unsigned x = rng() % 16;
                bt.insert(x);
                // 作用済みの xor を打ち消した値で持っておく
                ms.insert(x ^ x_all);
            } else {
                unsigned x = rng() % 16;
                bt.erase_one_element(x);
                auto itr = ms.find(x ^ x_all);
                if (itr != ms.end()) ms.erase(itr);
            }
            if (bt.size() != (int)ms.size()) ok = false;
            for (unsigned x = 0; x < 16; x++) {
                if (bt.count(x) != (int)ms.count(x ^ x_all)) ok = false;
            }
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
