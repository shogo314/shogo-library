#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// PalindromicTree を、すべての部分文字列を調べる愚直な実装とランダムな短い文字列で比べる
// (異なる回文の個数、各回文の出現回数・長さ・最初の終わりの位置、各位置で終わる最長の回文、親、suffix link、子)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/palindromic-tree.hpp"

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

bool is_palindrome(const std::string& t) { return std::equal(t.begin(), t.end(), t.rbegin()); }

// 頂点 v の回文を、最初に現れた位置から取り出す
template <typename PT>
std::string str(const PT& pt, const std::string& s, long long v) {
    return s.substr(pt.first_end(v) - pt.len(v) + 1, pt.len(v));
}

int main() {
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 20 + 1, sigma = rng() % 3 + 1;
        std::string s(n, 'a');
        for (auto& c : s) c = 'a' + rng() % sigma;
        PalindromicTree<26, 'a'> pt;
        // 1 文字ずつ追加し、そのたびに最長の回文接尾辞を確かめる
        for (int i = 0; i < n; i++) {
            long long v = pt.add(s[i]);
            int best = 0;
            for (int l = 0; l <= i; l++) {
                if (is_palindrome(s.substr(l, i - l + 1))) {
                    best = i - l + 1;
                    break;
                }
            }
            check(v == pt.longest_suffix(i) && pt.len(v) == best && str(pt, s, v) == s.substr(i - best + 1, best), "add / longest_suffix");
        }
        // 愚直: 回文ごとの出現回数と、最初に現れたときの終わりの位置
        std::map<std::string, int> cnt, first;
        for (int r = 0; r < n; r++) {
            for (int l = 0; l <= r; l++) {
                std::string t = s.substr(l, r - l + 1);
                if (!is_palindrome(t)) continue;
                if (!cnt.count(t)) first[t] = r;
                cnt[t]++;
            }
        }
        check(pt.count_distinct() == static_cast<long long>(cnt.size()) && pt.size() == pt.count_distinct() + 2, "count_distinct");
        check(pt.length() == n, "length");
        auto occ = pt.occurrences();
        std::vector<std::string> strs(pt.size());
        for (long long v = 2; v < pt.size(); v++) {
            std::string t = str(pt, s, v);
            strs[v] = t;
            check(cnt.count(t) && occ[v] == cnt[t] && first[t] == pt.first_end(v), "occurrences / first_end");
            // 頂点の番号は最初に現れた終わりの位置の順
            if (v > 2) check(pt.first_end(v - 1) <= pt.first_end(v), "頂点の番号の順");
        }
        check(occ[0] == 0 && occ[1] == 0 && pt.len(0) == -1 && pt.len(1) == 0, "根");
        for (long long v = 2; v < pt.size(); v++) {
            const std::string& t = strs[v];
            // 親は両端を除いた回文
            long long p = pt.parent(v);
            if (t.size() == 1) {
                check(p == 0, "parent (長さ 1)");
            } else if (t.size() == 2) {
                check(p == 1, "parent (長さ 2)");
            } else {
                check(strs[p] == t.substr(1, t.size() - 2), "parent");
            }
            check(pt.child(p, t[0]) == v, "child");
            // suffix link は自分より短い最長の空でない回文接尾辞
            long long link = 1;
            for (size_t l = 1; l < t.size(); l++) {
                if (is_palindrome(t.substr(l))) {
                    link = -1;
                    for (long long u = 2; u < pt.size(); u++)
                        if (strs[u] == t.substr(l)) link = u;
                    break;
                }
            }
            check(pt.suffix_link(v) == link, "suffix_link");
        }
        // docs の例: suffix link の木での深さから、回文の部分文字列の個数 (重複を含む) を求める
        std::vector<long long> depth(pt.size(), 0);
        for (long long v = 2; v < pt.size(); v++) depth[v] = depth[pt.suffix_link(v)] + 1;
        long long total = 0, expect = 0;
        for (long long i = 0; i < pt.length(); i++) total += depth[pt.longest_suffix(i)];
        for (const auto& [t, c] : cnt) expect += c;
        check(total == expect, "回文の部分文字列の個数");
        // 存在しない子は -1
        check(pt.child(1, 'z') == -1 || s.find("zz") != std::string::npos, "child なし");
    }

    // 整数の列から作る
    {
        PalindromicTree<3, 0> pt(std::vector<int>{0, 1, 2, 1, 0});
        check(pt.count_distinct() == 5 && pt.len(pt.longest_suffix(4)) == 5, "整数の列");
    }
    // 長い列でも速く動く (1 文字だけの列は回文が長い)
    {
        PalindromicTree<26, 'a'> pt(std::string(1000000, 'a'));
        check(pt.count_distinct() == 1000000 && pt.occurrences()[2] == 1000000, "長い列");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
