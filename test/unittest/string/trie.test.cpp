#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Trie を、文字列の多重集合を愚直に調べる方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/trie.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    auto random_string = [&](int max_len) {
        std::string s(rng() % (max_len + 1), 'a');
        for (auto& c : s) c = 'a' + rng() % 3;
        return s;
    };
    for (int rep = 0; rep < 300 && ok; rep++) {
        Trie<3, 'a'> trie;
        std::map<std::string, int> ms;                   // 文字列 -> 個数
        std::map<std::string, int> node_of = {{"", 0}};  // ノードがある文字列 (根と、一度でも追加した文字列の接頭辞)
        for (int q = 0; q < 200 && ok; q++) {
            std::string s = random_string(5);
            int type = rng() % 3;
            if (type == 0) {
                long long v = trie.insert(s);
                ms[s]++;
                for (int len = 0; len <= static_cast<int>(s.size()); len++) node_of.emplace(s.substr(0, len), -1);
                ok = ok && trie.depth(v) == static_cast<long long>(s.size());
            } else if (type == 1) {
                bool expected = ms.count(s) && ms[s] > 0;
                ok = ok && trie.erase(s) == expected;
                if (expected) ms[s]--;
            }
            // すべての問い合わせを愚直な結果と比べる
            std::string t = random_string(5);
            long long cnt = ms.count(t) ? ms[t] : 0, pre = 0, total = 0, lcp = 0;
            for (auto& [u, c] : ms) {
                total += c;
                if (u.compare(0, t.size(), t) == 0 && u.size() >= t.size()) pre += c;
                if (c > 0) {
                    long long l = 0;
                    while (l < static_cast<long long>(std::min(u.size(), t.size())) && u[l] == t[l]) l++;
                    lcp = std::max(lcp, l);
                }
            }
            long long v = trie.find(t);
            ok = ok && (v != -1) == (node_of.count(t) > 0);
            ok = ok && trie.count(t) == cnt && trie.count_prefix(t) == pre && trie.total() == total;
            ok = ok && trie.longest_common_prefix(t) == lcp;
            if (v != -1) {
                ok = ok && trie.count_at(v) == cnt && trie.count_prefix_at(v) == pre && trie.depth(v) == static_cast<long long>(t.size());
            }
        }
        // ノードの数と、親子・深さの関係
        ok = ok && trie.size() == static_cast<long long>(node_of.size());
        for (auto& [u, x] : node_of) {
            long long v = trie.find(u);
            if (u.empty()) {
                ok = ok && v == 0 && trie.parent(v) == -1;
            } else {
                long long p = trie.find(u.substr(0, u.size() - 1));
                ok = ok && trie.parent(v) == p && trie.child(p, u.back()) == v && trie.depth(v) == static_cast<long long>(u.size());
            }
        }
    }

    // 例: すべての組の最長共通接頭辞の長さの和は、根以外のノードを通る文字列の組の個数の和
    Trie<26, 'a'> trie;
    std::vector<std::string> words = {"ab", "abc", "arc"};
    for (auto& w : words) trie.insert(w);
    long long sum = 0;
    for (long long v = 1; v < trie.size(); v++) sum += trie.count_prefix_at(v) * (trie.count_prefix_at(v) - 1) / 2;
    ok = ok && sum == 4;  // lcp(ab, abc) = 2, lcp(ab, arc) = 1, lcp(abc, arc) = 1
    // vector<int> も追加できる
    Trie<10, 0> digits;
    digits.insert(std::vector<int>{3, 1, 4});
    ok = ok && digits.count_prefix(std::vector<int>{3, 1}) == 1 && digits.find(std::vector<int>{1}) == -1;

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
