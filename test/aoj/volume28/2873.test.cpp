#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2873"

#include <iostream>
#include <string>

#include "../../../src/string/aho-corasick.hpp"

int main() {
    std::string s;
    int n;
    std::cin >> s >> n;
    AhoCorasick<26, 'a'> ac;
    for (int i = 0; i < n; i++) {
        std::string p;
        std::cin >> p;
        ac.add(p);
    }
    ac.build();
    // 左から読み、パターンが終わったらその文字を置き換えて、状態を根に戻す
    long long v = 0, ans = 0;
    for (char c : s) {
        v = ac.next(v, c);
        if (ac.match_count(v) > 0) {
            ans++;
            v = 0;
        }
    }
    std::cout << ans << std::endl;
}
