#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// longest_common_substring を、すべての部分文字列を調べる愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/string/longest-common-substring.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 5000 && ok; rep++) {
        int n = rng() % 15, m = rng() % 15;
        int k = rng() % 3 + 1;
        std::string s(n, 'a'), t(m, 'a');
        for (auto& c : s) c = 'a' + rng() % k;
        for (auto& c : t) c = 'a' + rng() % k;

        long long best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long l = 0;
                while (i + l < n && j + l < m && s[i + l] == t[j + l]) l++;
                best = std::max(best, l);
            }
        }
        auto [i, j, len] = longest_common_substring(s, t);
        ok = ok && len == best && 0 <= i && i + len <= n && 0 <= j && j + len <= m;
        ok = ok && s.substr(i, len) == t.substr(j, len);
        if (len == 0) ok = ok && i == 0 && j == 0;
    }

    // 例
    {
        auto [i, j, len] = longest_common_substring(std::string("abracadabra"), std::string("cadabx"));
        ok = ok && i == 4 && j == 0 && len == 5;
    }
    {
        // 型が違う列、負の値
        auto [i, j, len] = longest_common_substring(std::vector<long long>{-5, 3, 100, 7}, std::vector<long long>{3, 100, -5});
        ok = ok && i == 1 && j == 0 && len == 2;
    }
    {
        auto [i, j, len] = longest_common_substring(std::string("abc"), std::string("xyz"));
        ok = ok && i == 0 && j == 0 && len == 0;
    }
    {
        auto [i, j, len] = longest_common_substring(std::string(""), std::string(""));
        ok = ok && i == 0 && j == 0 && len == 0;
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
