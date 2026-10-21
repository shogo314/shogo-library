#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0029"

#include <iostream>
#include <string>

#include "../../../src/data_structures/counter.hpp"

int main() {
    Counter<std::string> c;
    std::string w, longest;
    while (std::cin >> w) {
        c[w] += 1;
        if (w.size() > longest.size()) longest = w;
    }
    // most_common は個数の多い順なので、先頭が最頻出の単語
    std::cout << c.most_common()[0].first << ' ' << longest << '\n';
}
