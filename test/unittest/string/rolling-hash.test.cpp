#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// RHString を std::string で愚直に計算した結果とランダムに比較する
// 端の削除 (remove_prefix・remove_suffix) も、残りの文字列から作った RHString と比べる
// RollingHash2D と pattern_match_2d を、長方形を直接比べたものと比べる (std::vector<std::vector<int>> でも作る)
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/string/rolling-hash.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <string_view>
#include <utility>
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
        return t.size() == static_cast<long long>(s.size()) && t.hash1 == rh.build(s).back() && t.hash2 == rh.build(r).back();
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
        check(a.size() == static_cast<long long>(s.size()) && a.empty() == s.empty(), "size/empty");
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
        for (auto& v : x) v = static_cast<long long>(rng() % 5) - 2;
        for (auto& v : y) v = static_cast<long long>(rng() % 5) - 2;
        std::vector<long long> xy = x;
        xy.insert(xy.end(), y.begin(), y.end());
        RHString hx(rh, x), hy(rh, y), hxy(rh, xy);
        check(hx + hy == hxy, "vector<long long> concat");
        check((hx == hy) == (x == y), "vector<long long> equality");
        check(hx.is_palindrome() == std::equal(x.begin(), x.end(), x.rbegin()), "vector<long long> palindrome");
    }

    // remove_prefix / remove_suffix: s = t + u や s = u + t から t を取り除くと、u から作ったものと一致する
    // 回文の判定 (逆順のハッシュ) も一致し、ランダムな基数でも成り立つ
    RollingHash random_rh;
    for (RollingHash* r : {&rh, &random_rh}) {
        for (int rep = 0; rep < 3000 && ok; rep++) {
            std::string t = random_string(8), u = random_string(8);
            RHString a(*r, t + u), b(*r, u + t);
            a.remove_prefix(RHString(*r, t));
            b.remove_suffix(t);  // RHString を作れるもの (文字列) を直接渡す
            RHString hu(*r, u);
            check(a == hu && a.size() == static_cast<long long>(u.size()), "remove_prefix");
            check(b == hu && b.size() == static_cast<long long>(u.size()), "remove_suffix");
            check(a.is_palindrome() == is_palindrome(u) && b.is_palindrome() == is_palindrome(u), "remove 後の is_palindrome");
            // 取り除いたあとに連結しても正しい
            check(a + RHString(*r, t) == RHString(*r, u + t), "remove 後の連結");
        }
    }
    // 1 文字ずつ push_back と pop_front をして、長さ k の窓を動かす
    {
        std::string s = random_string(200);
        const int k = 5;
        RHString w(rh);
        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            w += RHString(rh, s[i]);
            if (i >= k) w.remove_prefix(s[i - k]);  // 文字を直接渡す
            int l = std::max(0, i - k + 1);
            check(w == RHString(rh, s.substr(l, i - l + 1)), "窓");
        }
    }

    // 2 次元
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int h = rng() % 6, w = rng() % 6, ph = rng() % 3 + 1, pw = rng() % 3 + 1, k = rng() % 2 + 1;
        std::vector<std::string> text(h, std::string(w, 'a')), pattern(ph, std::string(pw, 'a'));
        for (auto& row : text)
            for (auto& ch : row) ch = 'a' + rng() % k;
        for (auto& row : pattern)
            for (auto& ch : row) ch = 'a' + rng() % k;
        // 長方形どうしのハッシュが、中身が同じときに限り一致する
        RollingHash2D rh2;
        auto th = rh2.build(text);
        for (int t = 0; t < 20 && h > 0 && w > 0; t++) {
            int i1 = rng() % (h + 1), i2 = rng() % (h + 1), j1 = rng() % (w + 1), j2 = rng() % (w + 1);
            if (i1 > i2) std::swap(i1, i2);
            if (j1 > j2) std::swap(j1, j2);
            int a = rng() % (h - (i2 - i1) + 1), b = rng() % (w - (j2 - j1) + 1);
            bool same = true;
            for (int i = 0; i < i2 - i1; i++)
                for (int j = 0; j < j2 - j1; j++) same &= text[i1 + i][j1 + j] == text[a + i][b + j];
            bool eq = rh2.query(th, i1, j1, i2, j2) == rh2.query(th, a, b, a + i2 - i1, b + j2 - j1);
            if (eq != same) ok = false;
        }
        std::vector<std::pair<long long, long long>> expected;
        for (int i = 0; i + ph <= h; i++) {
            for (int j = 0; j + pw <= w; j++) {
                bool match = true;
                for (int a = 0; a < ph; a++)
                    for (int b = 0; b < pw; b++) match &= text[i + a][j + b] == pattern[a][b];
                if (match) expected.emplace_back(i, j);
            }
        }
        if (pattern_match_2d(text, pattern) != expected) ok = false;
        std::vector<std::vector<int>> ti(h, std::vector<int>(w)), pi(ph, std::vector<int>(pw));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) ti[i][j] = text[i][j] - 'a' - 1;
        for (int i = 0; i < ph; i++)
            for (int j = 0; j < pw; j++) pi[i][j] = pattern[i][j] - 'a' - 1;
        if (pattern_match_2d(ti, pi) != expected) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
