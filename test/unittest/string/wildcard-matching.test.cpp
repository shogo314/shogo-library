#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// wildcard-matching.hpp の wildcard_pattern_matching を、位置ごとに 1 文字ずつ比べる愚直な方法と比べる
// 文字列と、int の列 (ワイルドカードは -1) で調べる。pattern が空のときや text より長いときも含む
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/wildcard-matching.hpp"

#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 12, m = rng() % 6;
        std::vector<int> s(n), t(m);
        for (auto& x : s) x = rng() % 4 == 0 ? -1 : static_cast<int>(rng() % 2);
        for (auto& x : t) x = rng() % 4 == 0 ? -1 : static_cast<int>(rng() % 2);
        std::vector<long long> expect;
        for (int i = 0; i + m <= n; i++) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (s[i + j] != -1 && t[j] != -1 && s[i + j] != t[j]) match = false;
            if (match) expect.push_back(i);
        }
        if (wildcard_pattern_matching(s, t, -1) != expect) ok = false;
        std::string ss, tt;
        for (int x : s) ss += x == -1 ? '*' : static_cast<char>('a' + x);
        for (int x : t) tt += x == -1 ? '*' : static_cast<char>('a' + x);
        if (wildcard_pattern_matching(ss, tt, '*') != expect) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
