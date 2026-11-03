#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// lyndon_factorization を愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/lyndon.hpp"

#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;

    // 最長の Lyndon 文字列である接頭辞を繰り返し切り出したもの (Lyndon 分解の最初の成分はこれになる) と比べる
    auto is_lyndon = [](const std::string& w) {
        for (size_t i = 1; i < w.size(); i++)
            if (!(w < w.substr(i))) return false;
        return !w.empty();
    };
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 13;
        std::string s;
        for (int i = 0; i < n; i++) s += static_cast<char>('a' + rng() % 3);
        std::vector<long long> expect = {0};
        for (int i = 0; i < n;) {
            int len = 1;
            for (int l = 1; i + l <= n; l++)
                if (is_lyndon(s.substr(i, l))) len = l;
            i += len;
            expect.push_back(i);
        }
        ok = ok && lyndon_factorization(s) == expect;
        std::vector<int> v(s.begin(), s.end());
        ok = ok && lyndon_factorization(v) == expect;
    }

    // 例
    ok = ok && lyndon_factorization(std::string("abracadabra")) == std::vector<long long>{0, 7, 10, 11};

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
