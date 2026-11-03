#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// manacher、palindrome_lengths を愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/manacher.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

bool is_palindrome(const std::string& s, int l, int r) {
    for (int i = l, j = r - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 5000 && ok; rep++) {
        int n = rng() % 30;
        int k = rng() % 3 + 1;
        std::string s(n, 'a');
        for (auto& c : s) c = 'a' + rng() % k;

        std::vector<long long> r(n), len(std::max(2 * n - 1, 0));
        for (int i = 0; i < n; i++) {
            while (i - r[i] >= 0 && i + r[i] < n && is_palindrome(s, i - r[i], i + r[i] + 1)) r[i]++;
        }
        for (int c = 0; c < 2 * n - 1; c++) {
            // 中心 c / 2 の回文 [l, rr)
            for (int l = c / 2, rr = (c + 1) / 2 + 1; 0 <= l && rr <= n && is_palindrome(s, l, rr); l--, rr++) {
                len[c] = rr - l;
            }
        }
        ok = ok && manacher(s) == r && palindrome_lengths(s) == len;
        ok = ok && manacher(s.begin(), s.end()) == r && palindrome_lengths(s.begin(), s.end()) == len;
    }

    // 例
    ok = ok && manacher(std::string("abaaba")) == std::vector<long long>{1, 2, 1, 1, 2, 1};
    ok = ok && palindrome_lengths(std::string("abaaba")) == std::vector<long long>{1, 0, 3, 0, 1, 6, 1, 0, 3, 0, 1};

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
