#define PROBLEM "https://judge.yosupo.jp/problem/aho_corasick"

#include "../../../src/string/aho-corasick.hpp"

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    AhoCorasick<26, 'a'> ac;
    std::vector<long long> id(n);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        id[i] = ac.add(s);
    }
    ac.build();
    // ノードは追加した順に作られるので、問題の番号の付け方と一致する
    std::cout << ac.size() << '\n';
    for (long long v = 1; v < ac.size(); v++) std::cout << ac.parent(v) << ' ' << ac.link(v) << '\n';
    for (int i = 0; i < n; i++) std::cout << ac.node(id[i]) << " \n"[i + 1 == n];
}
