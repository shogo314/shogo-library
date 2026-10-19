#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// edit_distance と longest_common_subsequence、その復元を、再帰による愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "../../src/dp/edit-distance.hpp"
#include "../../src/dp/longest-common-subsequence.hpp"

// s[i:] と t[j:] の編集距離
int naive_edit(const std::string& s, const std::string& t, int i, int j) {
    if (i == static_cast<int>(s.size())) return t.size() - j;
    if (j == static_cast<int>(t.size())) return s.size() - i;
    int res = naive_edit(s, t, i + 1, j + 1) + (s[i] != t[j]);
    res = std::min(res, naive_edit(s, t, i + 1, j) + 1);
    res = std::min(res, naive_edit(s, t, i, j + 1) + 1);
    return res;
}

// s[i:] と t[j:] の LCS の長さ
int naive_lcs(const std::string& s, const std::string& t, int i, int j) {
    if (i == static_cast<int>(s.size()) || j == static_cast<int>(t.size())) return 0;
    int res = std::max(naive_lcs(s, t, i + 1, j), naive_lcs(s, t, i, j + 1));
    if (s[i] == t[j]) res = std::max(res, naive_lcs(s, t, i + 1, j + 1) + 1);
    return res;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 8, m = rng() % 8;
        int k = rng() % 3 + 1;
        std::string s(n, 'a'), t(m, 'a');
        for (auto& c : s) c = 'a' + rng() % k;
        for (auto& c : t) c = 'a' + rng() % k;

        ok = ok && edit_distance(s, t) == naive_edit(s, t, 0, 0);
        int len = naive_lcs(s, t, 0, 0);
        ok = ok && longest_common_subsequence(s, t) == len;

        // 復元: 長さが最長で、添字が両方とも狭義単調増加し、要素が一致する
        auto idx = longest_common_subsequence_restore(s, t);
        ok = ok && static_cast<int>(idx.size()) == len;
        for (int p = 0; p < static_cast<int>(idx.size()) && ok; p++) {
            auto [i, j] = idx[p];
            ok = 0 <= i && i < n && 0 <= j && j < m && s[i] == t[j];
            if (p > 0) ok = ok && idx[p - 1].first < i && idx[p - 1].second < j;
        }
    }

    // 例
    ok = ok && edit_distance(std::string("kitten"), std::string("sitting")) == 3;
    ok = ok && edit_distance(std::vector<int>{1, 2, 3}, std::vector<int>{2, 3, 4}) == 2;
    ok = ok && edit_distance(std::string(""), std::string("abc")) == 3;
    ok = ok && longest_common_subsequence(std::string("abcbdab"), std::string("bdcaba")) == 4;
    ok = ok && longest_common_subsequence(std::vector<int>{1, 2, 3}, std::vector<long long>{3, 1, 2}) == 2;
    ok = ok && longest_common_subsequence_restore(std::string(""), std::string("abc")).empty();

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
