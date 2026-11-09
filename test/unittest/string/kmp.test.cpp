#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// prefix_function、kmp_search を愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/kmp.hpp"

#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#if __cplusplus >= 202002L
#include <ranges>
#endif

template <class R>
std::vector<long long> collect(const R& matches) {
    return {matches.begin(), matches.end()};
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 5000 && ok; rep++) {
        int n = rng() % 30;
        int k = rng() % 3 + 1;
        std::string s(n, 'a');
        for (auto& c : s) c = 'a' + rng() % k;

        std::vector<long long> pi(n);
        for (int i = 0; i < n; i++) {
            for (int l = 1; l <= i; l++) {
                if (s.substr(0, l) == s.substr(i + 1 - l, l)) pi[i] = l;
            }
        }
        ok = ok && prefix_function(s) == pi && prefix_function(s.begin(), s.end()) == pi;

        int m = rng() % 4;
        std::string p(m, 'a');
        for (auto& c : p) c = 'a' + rng() % k;
        std::vector<long long> occ;
        for (int i = 0; i + m <= n; i++) {
            if (s.substr(i, m) == p) occ.push_back(i);
        }
        ok = ok && collect(kmp_search(s, p)) == occ;
    }

    // 例
    ok = ok && prefix_function(std::string("aabaaab")) == std::vector<long long>{0, 1, 0, 1, 2, 2, 3};
    ok = ok && collect(kmp_search(std::string("aaaa"), std::string("aa"))) == std::vector<long long>{0, 1, 2};
    ok = ok && collect(kmp_search(std::vector<int>{1, 2, 1, 2, 1}, std::vector<int>{1, 2, 1})) == std::vector<long long>{0, 2};

    // 失敗リンクを何段も戻る場合と、重なりのある一致を含む二値列の全探索。
    for (long long n = 0; n <= 8; n++) {
        for (long long mask = 0; mask < (1LL << n); mask++) {
            std::string text(n, 'a');
            for (long long i = 0; i < n; i++) text[i] += (mask >> i) & 1;
            for (long long m = 0; m <= 5; m++) {
                for (long long bits = 0; bits < (1LL << m); bits++) {
                    std::string pattern(m, 'a');
                    for (long long i = 0; i < m; i++) pattern[i] += (bits >> i) & 1;
                    std::vector<long long> expected;
                    for (long long i = 0; i + m <= n; i++) {
                        if (text.compare(i, m, pattern) == 0) expected.push_back(i);
                    }
                    ok = ok && collect(kmp_search(text, pattern)) == expected;
                }
            }
        }
    }

    // 空のパターン・空の入力・一致なし・パターンの方が長い場合。
    ok = ok && collect(kmp_search(std::string(), std::string())) == std::vector<long long>{0};
    ok = ok && collect(kmp_search(std::string("ab"), std::string())) == std::vector<long long>{0, 1, 2};
    ok = ok && collect(kmp_search(std::string(), std::string("a"))).empty();
    ok = ok && collect(kmp_search(std::string("a"), std::string("aa"))).empty();
    ok = ok && collect(kmp_search(std::string("aaaa"), std::string("b"))).empty();

    // range が一時入力を所有し、コピー・移動後も自分の入力を走査する。
    {
        auto make_matches = [] { return kmp_search(std::string("aaaa"), std::string("aa")); };
        const auto matches = make_matches();
        auto copied = matches;
        auto moved = std::move(copied);
        const std::vector<long long> expected = {0, 1, 2};
        for (int rep = 0; rep < 2; rep++) {
            ok = ok && collect(matches) == expected && collect(moved) == expected;
        }
        auto it = matches.begin(), independent = it;
        ok = ok && *it++ == 0 && *it == 1 && *independent == 0;
        long long pairs = 0;
        for (long long x : matches) {
            for (long long y : matches) pairs += x == y;
        }
        ok = ok && pairs == 3;
#if __cplusplus >= 202002L
        static_assert(std::ranges::input_range<decltype(matches)>);
#endif
    }
    // 左辺値をコピーしない。一時入力は move-only な型でも所有できる。
    {
        struct Series {
            std::vector<char> values;
            explicit Series(const std::string& s) : values(s.begin(), s.end()) {}
            Series(const Series&) = delete;
            Series(Series&&) = default;
            auto begin() const { return values.begin(); }
            auto end() const { return values.end(); }
        };
        const Series text("ababab"), pattern("aba");
        ok = ok && collect(kmp_search(text, pattern)) == std::vector<long long>{0, 2};
        auto matches = kmp_search(Series("ababab"), Series("aba"));
        auto moved = std::move(matches);
        ok = ok && collect(moved) == std::vector<long long>{0, 2};
    }
    // 構築時は text を読まず、最初の一致で終了すると後ろを比較しない。
    {
        struct Character {
            long long* reads;
            bool operator==(char c) const {
                ++*reads;
                return c == 'a';
            }
        };
        long long reads = 0;
        const std::vector<Character> text(100, Character{&reads});
        const auto matches = kmp_search(text, std::string("a"));
        ok = ok && reads == 0;
        for (long long pos : matches) {
            ok = ok && pos == 0;
            break;
        }
        ok = ok && reads == 1;
    }
    assert(ok);

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
