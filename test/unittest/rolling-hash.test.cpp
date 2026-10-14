#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// RHString を std::string で愚直に計算した結果とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/string/rolling-hash.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <string_view>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    RollingHash rh(1000003);
    bool ok = true;
    auto check = [&](bool cond, const char* what) {
        if (!cond) {
            if (ok) std::cerr << "failed: " << what << std::endl;
            ok = false;
        }
    };
    auto random_string = [&](int max_len) {
        std::string s(rng() % (max_len + 1), 'a');
        for (char& c : s) c = 'a' + rng() % 3;  // 回文や一致が起きやすいよう文字を絞る
        return s;
    };
    auto is_palindrome = [](const std::string& s) { return std::equal(s.begin(), s.end(), s.rbegin()); };
    // RHString の中身が s と一致するか (長さ・正順のハッシュ・逆順のハッシュ)
    auto same = [&](const RHString& t, const std::string& s) {
        std::string r(s.rbegin(), s.rend());
        return t.size() == (long long)s.size() && t.hash1 == rh.build(s).back() && t.hash2 == rh.build(r).back();
    };

    for (int rep = 0; rep < 3000 && ok; rep++) {
        std::string s = random_string(8), t = random_string(8);

        // コンストラクタ: 文字列 (std::string / const char* / string_view)・vector・1 文字・空・コピー・ハッシュ値から
        RHString a(rh, s), b(rh, t);
        check(same(a, s) && same(b, t), "string constructor");
        check(same(RHString(rh, s.c_str()), s), "const char* constructor");
        check(same(RHString(rh, std::string_view(s)), s), "string_view constructor");
        std::vector<char> sv(s.begin(), s.end());
        check(same(RHString(rh, sv), s), "vector constructor");
        RHString empty(rh);
        check(empty.empty() && empty.size() == 0 && same(empty, ""), "empty constructor");
        if (!s.empty()) check(same(RHString(rh, s[0]), s.substr(0, 1)), "char constructor");
        RHString copy(a);
        check(copy == a && same(copy, s), "copy constructor");
        RHString raw(rh, a.size(), a.hash1, a.hash2);
        check(raw == a, "hash constructor");

        // 連結: +, +=
        check(same(a + b, s + t), "operator+");
        RHString c = a;
        c += b;
        check(same(c, s + t), "operator+=");
        RHString d(rh);
        for (char ch : s) d += RHString(rh, ch);
        check(same(d, s) && d == a, "operator+= char by char");

        // 比較: 文字列が等しいときだけ等しい
        check((a == b) == (s == t), "operator==");
        check((a != b) == (s != t), "operator!=");
        check(a + b == RHString(rh, s + t), "concat equals whole");

        // 回文判定
        check(a.is_palindrome() == is_palindrome(s), "is_palindrome");
        check((a + b).is_palindrome() == is_palindrome(s + t), "is_palindrome concat");

        // size, empty, clear
        check(a.size() == (long long)s.size() && a.empty() == s.empty(), "size/empty");
        RHString e = a;
        e.clear();
        check(e.empty() && e.size() == 0 && e == empty, "clear");

        // assign と operator= の各版
        RHString f(rh);
        f.assign(a);
        check(f == a, "assign(RHString)");
        f.assign(t);
        check(same(f, t), "assign(string)");
        f.assign(std::string_view(s));
        check(same(f, s), "assign(string_view)");
        std::vector<char> tv(t.begin(), t.end());
        f.assign(tv);
        check(same(f, t), "assign(vector)");
        f.assign('b');
        check(same(f, "b"), "assign(char)");
        f = b;
        check(f == b, "operator=(RHString)");
        f = s;
        check(same(f, s), "operator=(string)");
        f = std::string_view(t);
        check(same(f, t), "operator=(string_view)");
        f = sv;
        check(same(f, s), "operator=(vector)");
        f = 'c';
        check(same(f, "c"), "operator=(char)");
    }

    // 整数の列 (負の値を含む) でも、連結と比較が列としての一致と対応する
    for (int rep = 0; rep < 1000 && ok; rep++) {
        std::vector<long long> x(rng() % 6), y(rng() % 6);
        for (auto& v : x) v = (long long)(rng() % 5) - 2;
        for (auto& v : y) v = (long long)(rng() % 5) - 2;
        std::vector<long long> xy = x;
        xy.insert(xy.end(), y.begin(), y.end());
        RHString hx(rh, x), hy(rh, y), hxy(rh, xy);
        check(hx + hy == hxy, "vector<long long> concat");
        check((hx == hy) == (x == y), "vector<long long> equality");
        check(hx.is_palindrome() == std::equal(x.begin(), x.end(), x.rbegin()), "vector<long long> palindrome");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
