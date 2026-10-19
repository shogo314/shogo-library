#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// longest_increasing_subsequence とその復元、長さの列を、すべての部分列を調べる愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/dp/longest-increasing-subsequence.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

template <typename Compare>
bool check(const std::vector<int>& a, bool strict, Compare comp) {
    int n = a.size();
    auto ok_pair = [&](long long i, long long j) { return strict ? comp(a[i], a[j]) : !comp(a[j], a[i]); };
    // 愚直に a[i] で終わる最長の長さを求める
    std::vector<long long> len(n);
    for (int j = 0; j < n; j++) {
        len[j] = 1;
        for (int i = 0; i < j; i++) {
            if (ok_pair(i, j)) len[j] = std::max(len[j], len[i] + 1);
        }
    }
    long long best = n == 0 ? 0 : *std::max_element(len.begin(), len.end());
    if (longest_increasing_subsequence_lengths(a, strict, comp) != len) return false;
    if (longest_increasing_subsequence(a, strict, comp) != best) return false;
    std::vector<long long> idx = longest_increasing_subsequence_restore(a, strict, comp);
    if (static_cast<long long>(idx.size()) != best) return false;
    for (long long k = 0; k < static_cast<long long>(idx.size()); k++) {
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
    ok = ok && longest_increasing_subsequence(a) == 4;
    ok = ok && longest_increasing_subsequence(a, false) == 4;
    ok = ok && longest_increasing_subsequence(std::vector<int>{2, 2, 2}, false) == 3;
    ok = ok && longest_increasing_subsequence(std::vector<int>{2, 2, 2}) == 1;
    ok = ok && longest_increasing_subsequence(a, true, std::greater<int>()) == 2;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
