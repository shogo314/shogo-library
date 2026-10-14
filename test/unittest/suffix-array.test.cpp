#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// suffix_array と lcp_array を、接尾辞をソートする愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/string/suffix-array.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

template <typename R>
bool check(const R& s, const std::vector<long long>& sa) {
    long long n = s.size();
    std::vector<long long> expected(n);
    for (long long i = 0; i < n; i++) expected[i] = i;
    std::sort(expected.begin(), expected.end(), [&](long long a, long long b) {
        return std::lexicographical_compare(s.begin() + a, s.end(), s.begin() + b, s.end());
    });
    if (sa != expected) return false;
    std::vector<long long> lcp = lcp_array(s, sa);
    if ((long long)lcp.size() != std::max(n - 1, 0LL)) return false;
    // int の Suffix Array を渡しても同じ LCP 配列になる
    if (lcp_array(s, std::vector<int>(sa.begin(), sa.end())) != lcp) return false;
    for (long long i = 0; i + 1 < n; i++) {
        long long h = 0;
        while (sa[i] + h < n && sa[i + 1] + h < n && s[sa[i] + h] == s[sa[i + 1] + h]) h++;
        if (lcp[i] != h) return false;
    }
    return true;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 40;
        int upper = rng() % 4;
        std::vector<int> a(n);
        for (auto& v : a) v = rng() % (upper + 1);
        ok = ok && check(a, suffix_array(a, upper));
        ok = ok && check(a, suffix_array(a));
        // long long の列でも、値の上限を渡す版と座標圧縮する版が使える
        std::vector<long long> a2(a.begin(), a.end());
        ok = ok && check(a2, suffix_array(a2, upper)) && check(a2, suffix_array(a2));

        std::string s(n, 'a');
        for (auto& c : s) c = 'a' + rng() % (upper + 1);
        ok = ok && check(s, suffix_array(s));

        std::vector<long long> b(n);
        for (auto& v : b) v = (long long)(rng() % 3) * 1000000000000LL - 1000000000000LL;
        ok = ok && check(b, suffix_array(b));
    }
    // 長い列 (再帰が何段も起こる)
    for (int rep = 0; rep < 20 && ok; rep++) {
        int n = rng() % 2000 + 1000;
        std::string s(n, 'a');
        int k = rng() % 3 + 1;
        for (auto& c : s) c = 'a' + rng() % k;
        if (rep % 2) {
            // 周期的な文字列
            int p = rng() % 10 + 1;
            for (int i = p; i < n; i++) s[i] = s[i - p];
        }
        ok = ok && check(s, suffix_array(s));
    }

    // 例
    ok = ok && suffix_array(std::string("abracadabra")) == std::vector<long long>{10, 7, 0, 3, 5, 8, 1, 4, 6, 9, 2};
    ok = ok && lcp_array(std::string("abracadabra"), suffix_array(std::string("abracadabra"))) == std::vector<long long>{1, 4, 1, 1, 0, 3, 0, 0, 0, 2};

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
