#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_5_B"

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "../../src/base/container_func.hpp"
#include "../../src/base/io.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    // 価値、重さ、型、日時、名前 (この順の辞書式順序が問題の優先順位と同じ)
    std::vector<std::tuple<long long, long long, char, long long, std::string>> items(n);
    std::cin >> items;  // tuple の vector をまとめて読む
    sort(items);
    for (const auto& t : items) std::cout << t << '\n';  // tuple を空白区切りで出力
}
