#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// longest_increasing_subsequence を、すべての部分列を調べる愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

#include "../../src/others/longest-increasing-subsequence.hpp"

template <typename Compare>
bool check(const std::vector<int>& a, bool strict, Compare comp) {
    int n = a.size();
    auto ok_pair = [&](int i, int j) { return strict ? comp(a[i], a[j]) : !comp(a[j], a[i]); };
    // 愚直に a[i] で終わる最長の長さを求める
    std::vector<int> len(n);
    for (int j = 0; j < n; j++) {
        len[j] = 1;
        for (int i = 0; i < j; i++) {
            if (ok_pair(i, j)) len[j] = std::max(len[j], len[i] + 1);
        }
    }
    int best = n == 0 ? 0 : *std::max_element(len.begin(), len.end());
    if (longest_increasing_subsequence_lengths(a, strict, comp) != len) return false;
    std::vector<int> idx = longest_increasing_subsequence(a, strict, comp);
    if ((int)idx.size() != best) return false;
    for (int k = 0; k < (int)idx.size(); k++) {
        if (idx[k] < 0 || idx[k] >= n) return false;
        if (k > 0 && (idx[k - 1] >= idx[k] || !ok_pair(idx[k - 1], idx[k]))) return false;
    }
    return true;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 15;
        int range = rng() % 10 + 1;
        std::vector<int> a(n);
        for (auto& v : a) v = rng() % range;
        for (bool strict : {true, false}) {
            ok = ok && check(a, strict, std::less<int>());
            ok = ok && check(a, strict, std::greater<int>());
        }
    }

    // 例
    std::vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
    ok = ok && longest_increasing_subsequence(a).size() == 4;
    ok = ok && longest_increasing_subsequence(a, false).size() == 4;
    ok = ok && longest_increasing_subsequence(std::vector<int>{2, 2, 2}, false).size() == 3;
    ok = ok && longest_increasing_subsequence(std::vector<int>{2, 2, 2}).size() == 1;
    ok = ok && longest_increasing_subsequence(a, true, std::greater<int>()).size() == 2;

    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
