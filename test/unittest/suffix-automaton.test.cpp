#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// SuffixAutomaton を、すべての部分文字列を数える愚直な実装とランダムに比べる
// 異なる部分文字列の個数、contains、出現回数、状態数の上限、len・link・next の性質、整数の列
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/string/suffix-automaton.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

// 部分文字列ごとの出現回数
std::map<std::string, long long> naive_counts(const std::string& s) {
    std::map<std::string, long long> res;
    for (size_t i = 0; i < s.size(); i++)
        for (size_t j = i + 1; j <= s.size(); j++) res[s.substr(i, j - i)]++;
    return res;
}

int main() {
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 15, k = rng() % 3 + 1;
        std::string s;
        for (int i = 0; i < n; i++) s += static_cast<char>('a' + rng() % k);
        // 一度に作る場合と、1 文字ずつ extend し途中でも確かめる場合
        SuffixAutomaton<26, 'a'> sa(s), inc;
        std::string pre;
        for (char c : s) {
            inc.extend(c);
            pre += c;
            auto cnt = naive_counts(pre);
            check(inc.count_distinct_substrings() == static_cast<long long>(cnt.size()), "extend の途中の異なる部分文字列の個数");
            for (const auto& [t, c2] : cnt) check(inc.count_occurrences(t) == c2, "extend の途中の出現回数");
        }
        auto cnt = naive_counts(s);
        check(sa.length() == n && inc.length() == n, "length");
        check(sa.count_distinct_substrings() == static_cast<long long>(cnt.size()), "異なる部分文字列の個数");
        check(sa.size() <= std::max(2 * n, 1), "状態数");
        // 長さ 0 から n + 1 の文字列をいくつか試す (部分文字列のものも、そうでないものも)
        for (int q = 0; q < 30; q++) {
            std::string t;
            if (n > 0 && rng() % 2) {
                int i = rng() % n, j = i + rng() % (n - i) + 1;
                t = s.substr(i, j - i);
            } else {
                int len = rng() % (n + 2);
                for (int i = 0; i < len; i++) t += static_cast<char>('a' + rng() % k);
            }
            long long e = t.empty() ? n + 1 : (cnt.count(t) ? cnt[t] : 0);
            check(sa.contains(t) == (e > 0), "contains");
            check(sa.count_occurrences(t) == e, "count_occurrences");
            check(inc.count_occurrences(t) == e, "extend で作った count_occurrences");
            check((sa.find(t) == -1) == (e == 0), "find");
        }
        // 各状態の部分文字列の長さは len(link(v)) + 1 以上 len(v) 以下
        for (const auto& [t, c] : cnt) {
            long long v = sa.find(t);
            check(sa.len(sa.link(v)) < static_cast<long long>(t.size()) && static_cast<long long>(t.size()) <= sa.len(v), "len と link");
            check(sa.occurrences(v) == c, "occurrences(v)");
        }
        check(sa.link(0) == -1 && sa.len(0) == 0, "初期状態");
        check(sa.len(sa.last_state()) == n, "last_state");
        if (n > 0) check(sa.next(0, s[0]) == sa.find(s.substr(0, 1)), "next");
    }
    // 整数の列 (Base = 0)
    {
        std::vector<int> v = {3, 1, 3, 1, 3};
        SuffixAutomaton<4, 0> sa(v);
        check(sa.count_distinct_substrings() == 9, "整数の列の異なる部分文字列の個数");
        check(sa.count_occurrences(std::vector<int>{3, 1, 3}) == 2, "整数の列の出現回数");
    }
    // docs の例
    {
        SuffixAutomaton<26, 'a'> sa(std::string("abcbc"));
        check(sa.count_distinct_substrings() == 12 && sa.count_occurrences(std::string("bc")) == 2, "docs の例");
    }
    // 長い文字列でも状態数は 2n - 1 以下
    {
        std::string s;
        for (int i = 0; i < 200000; i++) s += static_cast<char>('a' + rng() % 2);
        SuffixAutomaton<26, 'a'> sa(s);
        check(sa.size() <= 2 * 200000 - 1, "長い文字列の状態数");
        check(sa.count_occurrences(std::string("a")) + sa.count_occurrences(std::string("b")) == 200000, "長い文字列の出現回数");
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
