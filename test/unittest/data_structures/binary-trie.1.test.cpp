#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// BinaryTrie の clear を、操作列の途中で呼んで std::multiset による愚直な実装と比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/binary-trie.hpp"

#include <iostream>
#include <random>
#include <set>
#include <utility>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    {
        BinaryTrie<4, unsigned> original;
        original.insert(1), original.insert(3), original.insert(3);
        original.apply_xor(7);  // 未伝搬の xor も含めてコピーする。
        auto copy = original;
        copy.insert(5);
        if (original.size() != 3 || original.count(5) != 0 || copy.size() != 4) ok = false;
        original.erase(4);
        if (copy.count(4) != 2 || original.count(4) != 0) ok = false;
        BinaryTrie<4, unsigned> assigned;
        assigned.insert(15);
        assigned = copy;
        copy.clear();
        assigned = assigned;
        if (assigned.count(4) != 2 || assigned.count(5) != 1 || assigned.count(6) != 1) ok = false;
        auto moved = std::move(assigned);
        if (moved.size() != 4) ok = false;
        if (original.count(22) != 0) ok = false;  // 下位 4 bit が同じでも別の値。
    }
    {
        BinaryTrie<0> zero;
        zero.insert(0), zero.insert(0);
        zero.apply_xor(0);
        if (zero.size() != 2 || zero.count(0) != 2 || zero.count(1) != 0 || zero.nth_element(1) != 0 ||
            zero.bisect_left(0) != 0 || zero.bisect_right(0) != 2) ok = false;
        zero.erase(1);
        if (zero.size() != 2) ok = false;
        zero.erase_one_element(0);
        if (zero.size() != 1) ok = false;
        zero.erase(0);
        if (zero.size() != 0) ok = false;
        zero.insert(0);
        zero.erase(0);
        zero.erase(0);
        if (zero.size() != 0) ok = false;
    }
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
            if (t % 10 == 0) {
                auto copied = bt;
                copied.apply_xor(3);
                copied.insert(11);
                std::multiset<unsigned> expected;
                for (unsigned x : ms) expected.insert(x ^ x_all ^ 3);
                expected.insert(11);
                for (unsigned x = 0; x < 16; x++) {
                    if (copied.count(x) != static_cast<long long>(expected.count(x))) ok = false;
                }
            }
            if (bt.size() != static_cast<int>(ms.size())) ok = false;
            for (unsigned x = 0; x < 16; x++) {
                if (bt.count(x) != static_cast<int>(ms.count(x ^ x_all))) ok = false;
            }
        }
    }
    if (ok)
        std::cout << "Hello World" << std::endl;
    else {
        std::cerr << "failed" << std::endl;
        return 1;
    }
}
