#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// AhoCorasick を、文字列を愚直に比べる実装とランダムに比較する
// 同じパターンを複数回追加する場合や、文字の種類が少なくて重なりが多い場合も試す
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/aho-corasick.hpp"

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <random>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "../../../src/utility/range.hpp"
#if __cplusplus >= 202002L
#include <ranges>
#endif

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
            std::vector<decltype(ac)::Match> all;                            // (開始位置, 番号)
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
            for (auto [end, neg_len, i] : order) all.push_back({end + neg_len, i});
            long long total = 0;
            for (long long x : each) total += x;
            check(ac.count(text) == total, "count");
            check(ac.count_each(text) == each, "count_each");
            const auto matches = ac.find_all(text);
            check(std::vector<decltype(ac)::Match>(matches.begin(), matches.end()) == all, "find_all");
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
        const auto matches = ac.find_all(text);
        check(std::vector<decltype(ac)::Match>(matches.begin(), matches.end()) ==
                  std::vector<decltype(ac)::Match>{{0, 0}, {1, 1}, {2, 1}, {3, 0}, {4, 1}},
              "std::vector<int> の列挙");
    }
    // 一致の順序、独立した走査、右辺値の所有、コピー・移動後の寿命。
    {
        AhoCorasick<> ac;
        ac.add(std::string("a"));
        ac.add(std::string("aa"));
        ac.add(std::string("a"));
        ac.build();
        using Match = decltype(ac)::Match;
        const std::vector<Match> expected = {{0, 0}, {0, 2}, {0, 1}, {1, 0}, {1, 2}};
        auto make_matches = [&] { return ac.find_all(std::string("aa")); };
        const auto matches = make_matches();
        auto copy = matches;
        auto moved = std::move(copy);
        for (int rep = 0; rep < 2; rep++) {
            check(std::vector<Match>(matches.begin(), matches.end()) == expected, "右辺値と繰り返し走査");
            check(std::vector<Match>(moved.begin(), moved.end()) == expected, "range のコピー・移動");
        }
        auto it = matches.begin(), independent = it;
        check(*it++ == expected[0] && *it == expected[1] && *independent == expected[0], "iterator のコピーと後置 increment");
        long long pairs = 0;
        for (auto x : matches) {
            for (auto y : matches) pairs += x.id == y.id;
        }
        check(pairs == 9, "入れ子の走査");
        std::forward_list<char> text = {'a', 'a'};
        const auto linked = ac.find_all(text);
        check(std::vector<Match>(linked.begin(), linked.end()) == expected, "非ランダムアクセス入力");
        auto empty = ac.find_all(std::string());
        check(empty.begin() == empty.end(), "空の入力");
#if __cplusplus >= 202002L
        static_assert(std::ranges::input_range<decltype(matches)>);
#endif
    }
    // デフォルト構築できない iterator も受け取れる。
    {
        AhoCorasick<3, 0> ac;
        ac.add(std::vector<int>{0, 1});
        ac.build();
        const auto matches = ac.find_all(Range(3));
        check(std::vector<decltype(ac)::Match>(matches.begin(), matches.end()) ==
                  std::vector<decltype(ac)::Match>{{0, 0}},
              "Range の入力");
    }
    // 入力のコピーを要求せず、最初の一致より後を読まない。
    {
        struct Character {
            long long* reads;
            operator int() const {
                ++*reads;
                return 'a';
            }
        };
        struct Text {
            std::vector<Character> chars;
            explicit Text(long long* reads) : chars(100, Character{reads}) {}
            Text(const Text&) = delete;
            auto begin() const { return chars.begin(); }
            auto end() const { return chars.end(); }
        };
        AhoCorasick<> ac;
        ac.add(std::string("a"));
        ac.build();
        long long reads = 0;
        Text text(&reads);
        const auto matches = ac.find_all(text);
        check(reads == 0, "構築時は入力を読まない");
        for (auto match : matches) {
            check(match.pos == 0 && match.id == 0, "最初の一致");
            break;
        }
        check(reads == 1, "途中終了");
    }
    {
        AhoCorasick<> ac;
        ac.build();
        const auto matches = ac.find_all(std::string("aaa"));
        check(matches.begin() == matches.end(), "パターンなし");
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
