#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// z_algorithm を愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/z-algorithm.hpp"

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
        std::vector<long long> z(n);
        for (int i = 0; i < n; i++) {
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        }
        ok = ok && z_algorithm(s) == z && z_algorithm(s.begin(), s.end()) == z;
    }
    ok = ok && z_algorithm(std::string("aabaab")) == std::vector<long long>{6, 1, 0, 3, 1, 0};
    ok = ok && z_algorithm(std::vector<int>{}).empty();

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
