#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// io.hpp の入出力を std::istringstream / std::ostringstream で検証する
// print / err は std::cout / std::cerr の出力先を一時的に差し替えて検証する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <array>
#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "../../src/base/io.hpp"

// std::cout (または std::cerr) に書かれた内容を文字列で受け取る
template <class F>
std::string capture(std::ostream& stream, F f) {
    std::ostringstream buf;
    std::streambuf* old = stream.rdbuf(buf.rdbuf());
    f();
    stream.rdbuf(old);
    return buf.str();
}

template <class T>
std::string to_str(const T& x) {
    std::ostringstream os;
    os << x;
    return os.str();
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    auto check = [&](bool cond, const char* what) {
        if (!cond) {
            if (ok) std::cerr << "failed: " << what << std::endl;
            ok = false;
        }
    };

    // 出力: 空白区切り
    check(to_str(std::make_pair(1, std::string("ab"))) == "1 ab", "<< pair");
    check(to_str(std::make_tuple(1, 'x', std::string("yz"), 2.5)) == "1 x yz 2.5", "<< tuple");
    check(to_str(std::make_tuple(7)) == "7", "<< tuple (1 要素)");
    check(to_str(std::array<int, 3>{4, 5, 6}) == "4 5 6", "<< array");
    check(to_str(std::array<int, 0>{}) == "", "<< array (空)");
    check(to_str(std::vector<int>{3, 1, 2}) == "3 1 2", "<< vector");
    check(to_str(std::vector<int>{}) == "", "<< vector (空)");
    check(to_str(std::set<int>{3, 1, 2}) == "1 2 3", "<< set");
    check(to_str(std::set<int>{}) == "", "<< set (空)");
    // ネストした型
    check(to_str(std::vector<std::pair<int, int>>{{1, 2}, {3, 4}}) == "1 2 3 4", "<< vector<pair>");
    check(to_str(std::make_pair(std::vector<int>{1, 2}, std::array<int, 2>{3, 4})) == "1 2 3 4", "<< pair<vector, array>");

    // 入力
    {
        std::istringstream is("1 ab  x 2 yz 3.5\n 4 5 6 7 8 9 10");
        std::pair<int, std::string> p;
        std::tuple<char, int, std::string, double> t;
        std::array<int, 3> a;
        std::vector<int> v(4);
        is >> p >> t >> a >> v;
        check(p == std::make_pair(1, std::string("ab")), ">> pair");
        check(t == std::make_tuple('x', 2, std::string("yz"), 3.5), ">> tuple");
        check(a == std::array<int, 3>{4, 5, 6}, ">> array");
        check(v == std::vector<int>{7, 8, 9, 10}, ">> vector");
        check(bool(is), "stream state");
    }
    {
        // ネストした型
        std::istringstream is("1 2 3 4 5 6");
        std::pair<std::vector<int>, std::array<int, 2>> p;
        p.first.resize(2);
        std::vector<std::pair<int, int>> vp(1);
        is >> p >> vp;
        check(p.first == std::vector<int>{1, 2} && p.second == std::array<int, 2>{3, 4}, ">> pair<vector, array>");
        check(vp[0] == std::make_pair(5, 6), ">> vector<pair>");
    }

    // ランダム: 書いて読み戻すと一致し、出力は愚直に空白でつないだものと一致する
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 6;
        std::vector<int> v(n);
        for (int& x : v) x = (int)(rng() % 2001) - 1000;
        std::string expect;
        for (int i = 0; i < n; i++) expect += (i ? " " : "") + std::to_string(v[i]);
        check(to_str(v) == expect, "<< vector (random)");
        std::set<int> s(v.begin(), v.end());
        std::string expect_s;
        for (auto it = s.begin(); it != s.end(); ++it) expect_s += (it == s.begin() ? "" : " ") + std::to_string(*it);
        check(to_str(s) == expect_s, "<< set (random)");
        std::istringstream is(expect);
        std::vector<int> w(n);
        is >> w;
        check(w == v, ">> vector (random)");
        std::array<int, 4> a;
        for (int& x : a) x = (int)(rng() % 2001) - 1000;
        std::istringstream is2(to_str(a));
        std::array<int, 4> b;
        is2 >> b;
        check(a == b, "array round trip");
        auto t = std::make_tuple((int)(rng() % 100), (long long)rng(), std::string(1 + rng() % 3, 'a' + rng() % 26));
        std::istringstream is3(to_str(t));
        decltype(t) u;
        is3 >> u;
        check(t == u, "tuple round trip");
    }

    // print: std::cout に空白区切りで出力して改行
    check(capture(std::cout, [] { print(); }) == "\n", "print()");
    check(capture(std::cout, [] { print(42); }) == "42\n", "print(x)");
    check(capture(std::cout, [] { print(1, "a", 2.5, 'c'); }) == "1 a 2.5 c\n", "print(x, ...)");
    check(capture(std::cout, [] { print(std::vector<int>{1, 2}, std::make_pair(3, 4)); }) == "1 2 3 4\n", "print(vector, pair)");

    // err: std::cerr に空白区切りで出力して改行
    check(capture(std::cerr, [] { err(); }) == "\n", "err()");
    check(capture(std::cerr, [] { err(42); }) == "42\n", "err(x)");
    check(capture(std::cerr, [] { err(1, "a", 2.5, 'c'); }) == "1 a 2.5 c\n", "err(x, ...)");
    check(capture(std::cerr, [] { err(std::set<int>{2, 1}); }) == "1 2\n", "err(set)");

    if (ok) std::cout << "Hello World" << std::endl;
}
