#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../../src/data_structures/binary-trie.hpp"

#include <assert.h>

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main(void) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned long long> dist(0, UINT64_MAX);
    std::vector<unsigned long long> pool;
    for (int i = 0; i < 24; ++i) {
        pool.push_back(dist(gen));
    }
    pool.push_back(UINT64_MAX);

    auto randgen_from_pool = [&]() {
        return pool[dist(gen) % pool.size()];
    };

    std::vector<unsigned long long> A;
    BinaryTrie<64> BT;
    for (int i = 0; i < 10000; ++i) {
        unsigned long long x = randgen_from_pool();
        A.push_back(x);
        BT.insert(x);
    }
    for (int i = 0; i < 10000; ++i) {
        int q = dist(gen) % 8;
        unsigned long long x = randgen_from_pool();
        switch (q) {
            case 0:
                A.push_back(x);
                BT.insert(x);
                break;
            case 1:
                A.erase(std::remove_if(A.begin(), A.end(), [&](unsigned long long a) { return a == x; }), A.end());
                BT.erase(x);
                break;
            case 2:
                if (std::find(A.begin(), A.end(), x) != A.end()) {
                    A.erase(std::find(A.begin(), A.end(), x));
                }
                BT.erase_one_element(x);
                break;
            case 3:
                for (auto& a : A) a ^= x;
                BT.apply_xor(x);
                break;
            case 4:
                std::sort(A.begin(), A.end());
                assert(std::lower_bound(A.begin(), A.end(), x) - A.begin() == BT.bisect_left(x));
                assert(std::upper_bound(A.begin(), A.end(), x) - A.begin() == BT.bisect_right(x));
                break;
            case 5:
                if (x >= A.size()) break;
                std::sort(A.begin(), A.end());
                assert(A[x] == BT.nth_element(x));
                break;
            case 6:
                assert(static_cast<int>(std::count(A.begin(), A.end(), x)) == BT.count(x));
                break;
            case 7:
                assert(static_cast<int>(A.size()) == BT.size());
            default:
                break;
        }
    }
    std::cout << "Hello World\n";
}
