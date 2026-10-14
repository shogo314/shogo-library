#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// FunctionalGraph のデフォルトコンストラクタ、頂点数を渡すコンストラクタと read() を検証する
// read() は std::cin を文字列に差し替えて読ませ、vector から作ったものと結果を比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/functional-graph.hpp"

#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    FunctionalGraph empty;
    if (empty.n != 0 || !empty.g.empty()) ok = false;

    std::streambuf* original = std::cin.rdbuf();
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<int> g(n);
        for (int& v : g) v = rng() % n;
        FunctionalGraph expected(g);

        // padding は省略時 -1 (1-indexed の入力) と、0 (0-indexed の入力) の両方を試す
        for (int padding : {-1, 0}) {
            std::string input;
            for (int v : g) input += std::to_string(v - padding) + " ";
            std::istringstream iss(input);
            std::cin.rdbuf(iss.rdbuf());
            FunctionalGraph fg(n);
            if (fg.n != n || (int)fg.g.size() != n) ok = false;
            if (padding == -1)
                fg.read();
            else
                fg.read(padding);
            std::cin.rdbuf(original);

            if (fg.g != std::vector<long long>(g.begin(), g.end())) ok = false;
            for (int x = 0; x < n; x++) {
                if (fg.is_cycle[x] != expected.is_cycle[x]) ok = false;
                if (fg.hopable(x) != expected.hopable(x)) ok = false;
                for (long long k : {0LL, 1LL, (long long)n, (long long)(rng() % 1000000000000LL)}) {
                    if (fg.hop(x, k) != expected.hop(x, k)) ok = false;
                }
            }
        }
    }
    std::cin.rdbuf(original);
    if (ok) std::cout << "Hello World" << std::endl;
}
