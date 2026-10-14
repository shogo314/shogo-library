#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// z_algorithm、prefix_function、kmp_search、manacher、palindrome_lengths を愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/string/string.hpp"

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

        std::vector<long long> z(n), pi(n), r(n), len(std::max(2 * n - 1, 0));
        for (int i = 0; i < n; i++) {
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            for (int l = 1; l <= i; l++) {
                if (s.substr(0, l) == s.substr(i + 1 - l, l)) pi[i] = l;
            }
            while (i - r[i] >= 0 && i + r[i] < n && is_palindrome(s, i - r[i], i + r[i] + 1)) r[i]++;
        }
        for (int c = 0; c < 2 * n - 1; c++) {
            // 中心 c / 2 の回文 [l, rr)
            for (int l = c / 2, rr = (c + 1) / 2 + 1; 0 <= l && rr <= n && is_palindrome(s, l, rr); l--, rr++) {
                len[c] = rr - l;
            }
        }
        ok = ok && z_algorithm(s) == z && prefix_function(s) == pi;
        ok = ok && manacher(s) == r && palindrome_lengths(s) == len;
        ok = ok && prefix_function(s.begin(), s.end()) == pi && manacher(s.begin(), s.end()) == r;

        int m = rng() % 4;
        std::string p(m, 'a');
        for (auto& c : p) c = 'a' + rng() % k;
        std::vector<long long> occ;
        for (int i = 0; i + m <= n; i++) {
            if (s.substr(i, m) == p) occ.push_back(i);
        }
        ok = ok && kmp_search(s, p) == occ;
    }

    // 例
    ok = ok && prefix_function(std::string("aabaaab")) == std::vector<long long>{0, 1, 0, 1, 2, 2, 3};
    ok = ok && kmp_search(std::string("aaaa"), std::string("aa")) == std::vector<long long>{0, 1, 2};
    ok = ok && kmp_search(std::vector<int>{1, 2, 1, 2, 1}, std::vector<int>{1, 2, 1}) == std::vector<long long>{0, 2};
    ok = ok && manacher(std::string("abaaba")) == std::vector<long long>{1, 2, 1, 1, 2, 1};
    ok = ok && palindrome_lengths(std::string("abaaba")) == std::vector<long long>{1, 0, 3, 0, 1, 6, 1, 0, 3, 0, 1};

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
