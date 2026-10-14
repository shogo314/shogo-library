#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// PersistentArray を愚直な実装 (版ごとに配列を持つ) とランダムに比較する
// 古い版から更新しても、ほかの版が変わらないことを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/persistent-array.hpp"

#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 20 + 1;
        std::vector<std::vector<std::string>> naive;
        std::vector<PersistentArray<std::string>> arr;
        switch (rep % 3) {
            case 0:
                arr.emplace_back(n);
                naive.emplace_back(n);
                break;
            case 1:
                arr.emplace_back(n, "x");
                naive.emplace_back(n, "x");
                break;
            default: {
                std::vector<std::string> v(n);
                for (auto& s : v) s = std::to_string(rng() % 100);
                arr.emplace_back(v);
                naive.push_back(v);
                break;
            }
        }
        for (int t = 0; t < 40; t++) {
            int ver = rng() % arr.size();
            int k = rng() % n;
            if (rng() % 2) {
                std::string x = std::to_string(rng() % 100);
                arr.push_back(arr[ver].set(k, x));
                naive.push_back(naive[ver]);
                naive.back()[k] = x;
            } else {
                if (arr[ver].get(k) != naive[ver][k] || arr[ver][k] != naive[ver][k]) ok = false;
            }
        }
        // すべての版が、作ったときの内容のままか
        for (int i = 0; i < int(arr.size()); i++) {
            if (arr[i].size() != n) ok = false;
            if (arr[i].to_vector() != naive[i]) ok = false;
        }
        std::ostringstream os, expect;
        os << arr.back();
        for (int i = 0; i < n; i++) expect << (i ? " " : "") << naive.back()[i];
        if (os.str() != expect.str()) ok = false;
    }

    // 要素数が大きくても同じ値の木は O(log n) で作れる
    {
        PersistentArray<int> big(1000000000, 7);
        auto b1 = big.set(123456789, 1);
        if (big[123456789] != 7 || b1[123456789] != 1 || b1[123456788] != 7 || b1.size() != 1000000000) ok = false;
        PersistentArray<int> empty;
        if (empty.size() != 0 || !empty.to_vector().empty()) ok = false;
        PersistentArray<int> empty2(std::vector<int>{});
        if (empty2.size() != 0 || !empty2.to_vector().empty()) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
