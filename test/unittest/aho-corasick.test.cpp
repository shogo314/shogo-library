#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// AhoCorasick を、文字列を愚直に比べる実装とランダムに比較する
// 同じパターンを複数回追加する場合や、文字の種類が少なくて重なりが多い場合も試す
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/string/aho-corasick.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

int main() {
    std::mt19937 rng(314);
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int sigma = rng() % 3 + 1;
        auto random_string = [&](int max_len) {
            std::string s(rng() % max_len + 1, 'a');
            for (char& c : s) c = 'a' + rng() % sigma;
            return s;
        };
        int m = rng() % 6 + 1;
        std::vector<std::string> pats;
        AhoCorasick<3, 'a'> ac;
        for (int i = 0; i < m; i++) {
            std::string p = !pats.empty() && rng() % 4 == 0 ? pats[rng() % pats.size()] : random_string(4);
            pats.push_back(p);
            check(ac.add(p) == i, "add の番号");
        }
        ac.build();
        check(ac.pattern_count() == m, "pattern_count");

        // ノードの構造: 各ノードの文字列を親からたどって作り、失敗リンク・遷移・match_count を確かめる
        std::vector<std::string> str(ac.size());
        for (long long v = 1; v < ac.size(); v++) {
            long long p = ac.parent(v);
            check(0 <= p && p < v, "親は先に作られている");
            for (int c = 0; c < 3; c++) {
                if (ac.next(p, 'a' + c) == v) str[v] = str[p] + static_cast<char>('a' + c);
            }
            check(ac.depth(v) == static_cast<long long>(str[v].size()), "depth");
        }
        check(ac.parent(0) == -1 && ac.link(0) == -1 && ac.depth(0) == 0, "根");
        auto find_node = [&](const std::string& s) -> long long {
            for (long long v = 0; v < ac.size(); v++) {
                if (str[v] == s) return v;
            }
            return -1;
        };
        for (int i = 0; i < m; i++) check(str[ac.node(i)] == pats[i], "node");
        for (long long v = 0; v < ac.size(); v++) {
            const std::string& s = str[v];
            // 失敗リンク: ノードのある最長の真の接尾辞
            if (v > 0) {
                long long expect = 0;
                for (size_t len = s.size() - 1; len > 0; len--) {
                    long long u = find_node(s.substr(s.size() - len));
                    if (u != -1) {
                        expect = u;
                        break;
                    }
                }
                check(ac.link(v) == expect, "link");
            }
            // 遷移: s + c の接尾辞のうち、ノードのある最長のもの
            for (int c = 0; c < 3; c++) {
                std::string t = s + static_cast<char>('a' + c);
                long long expect = 0;
                for (size_t len = t.size(); len > 0; len--) {
                    long long u = find_node(t.substr(t.size() - len));
                    if (u != -1) {
                        expect = u;
                        break;
                    }
                }
                check(ac.next(v, 'a' + c) == expect, "next");
            }
            long long mc = 0;
            for (const auto& p : pats) mc += p.size() <= s.size() && s.compare(s.size() - p.size(), p.size(), p) == 0;
            check(ac.match_count(v) == mc, "match_count");
        }

        // 照合: 愚直に全位置で比べる
        for (int t = 0; t < 5; t++) {
            std::string text = rng() % 5 == 0 ? std::string() : random_string(30);
            std::vector<long long> each(m, 0);
            std::vector<std::pair<long long, long long>> all;  // (開始位置, 番号)
            std::vector<std::tuple<long long, long long, long long>> order;  // (終わる位置, -長さ, 番号) の順に並べる
            for (long long end = 1; end <= static_cast<long long>(text.size()); end++) {
                for (int i = 0; i < m; i++) {
                    long long len = pats[i].size();
                    if (len <= end && text.compare(end - len, len, pats[i]) == 0) {
                        each[i]++;
                        order.emplace_back(end, -len, i);
                    }
                }
            }
            std::sort(order.begin(), order.end());
            for (auto [end, neg_len, i] : order) all.emplace_back(end + neg_len, i);
            long long total = 0;
            for (long long x : each) total += x;
            check(ac.count(text) == total, "count");
            check(ac.count_each(text) == each, "count_each");
            check(ac.find_all(text) == all, "find_all");
        }
    }
    // std::vector<int> の文字列と、別の文字の範囲
    {
        AhoCorasick<10, 0> ac;
        ac.add(std::vector<int>{1, 2});
        ac.add(std::vector<int>{2});
        ac.build();
        std::vector<int> text = {1, 2, 2, 1, 2};
        check(ac.count(text) == 5 && ac.count_each(text) == std::vector<long long>{2, 3}, "std::vector<int>");
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
