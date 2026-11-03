#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// prefix_function、kmp_search を愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/kmp.hpp"

#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 5000 && ok; rep++) {
        int n = rng() % 30;
        int k = rng() % 3 + 1;
        std::string s(n, 'a');
        for (auto& c : s) c = 'a' + rng() % k;

        std::vector<long long> pi(n);
        for (int i = 0; i < n; i++) {
            for (int l = 1; l <= i; l++) {
                if (s.substr(0, l) == s.substr(i + 1 - l, l)) pi[i] = l;
            }
        }
        ok = ok && prefix_function(s) == pi && prefix_function(s.begin(), s.end()) == pi;

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

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
