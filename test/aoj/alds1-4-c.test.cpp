#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C"

#include <iostream>
#include <string>
#include <vector>

#include "../../src/string/trie.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    // 文字は A, C, G, T だけなので、0, 1, 2, 3 に直してノードを小さくする
    Trie<4, 0> trie;
    auto convert = [](const std::string& s) {
        std::vector<int> res;
        for (char c : s) res.push_back(c == 'A' ? 0 : c == 'C' ? 1
                                           : c == 'G'          ? 2
                                                               : 3);
        return res;
    };
    while (n--) {
        std::string op, s;
        std::cin >> op >> s;
        if (op == "insert")
            trie.insert(convert(s));
        else
            std::cout << (trie.count(convert(s)) > 0 ? "yes" : "no") << '\n';
    }
}
