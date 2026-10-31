#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// io.hpp の入出力を std::istringstream / std::ostringstream で検証する
// print / err は std::cout / std::cerr の出力先を一時的に差し替えて検証する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/base/io.hpp"

#include <array>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

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
        check(static_cast<bool>(is), "stream state");
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
        for (int& x : v) x = static_cast<int>(rng() % 2001) - 1000;
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
        for (int& x : a) x = static_cast<int>(rng() % 2001) - 1000;
        std::istringstream is2(to_str(a));
        std::array<int, 4> b;
        is2 >> b;
        check(a == b, "array round trip");
        auto t = std::make_tuple(static_cast<int>(rng() % 100), static_cast<long long>(rng()), std::string(1 + rng() % 3, 'a' + rng() % 26));
        std::istringstream is3(to_str(t));
        decltype(t) u;
        is3 >> u;
        check(t == u, "tuple round trip");
    }

    // 128 bit 整数
    {
        const __uint128_t umax = ~static_cast<__uint128_t>(0);
        const __int128_t imax = static_cast<__int128_t>(umax >> 1), imin = -imax - 1;
        check(to_str(static_cast<__int128_t>(0)) == "0", "<< int128 (0)");
        check(to_str(static_cast<__int128_t>(-42)) == "-42", "<< int128 (負)");
        check(to_str(imax) == "170141183460469231731687303715884105727", "<< int128 (最大値)");
        check(to_str(imin) == "-170141183460469231731687303715884105728", "<< int128 (最小値)");
        check(to_str(umax) == "340282366920938463463374607431768211455", "<< uint128 (最大値)");
        check(to_str(std::vector<__int128_t>{1, -2}) == "1 -2", "<< vector<int128>");
        std::ostringstream w;
        w << std::setw(5) << static_cast<__int128_t>(-7);
        check(w.str() == "   -7", "<< int128 (setw)");

        std::istringstream is("170141183460469231731687303715884105727 -170141183460469231731687303715884105728 +5 340282366920938463463374607431768211455 3 -4");
        __int128_t a, b, c;
        __uint128_t d;
        std::pair<__int128_t, __int128_t> p;
        is >> a >> b >> c >> d >> p;
        check(a == imax && b == imin && c == 5 && d == umax && p == std::make_pair<__int128_t, __int128_t>(3, -4), ">> int128");
        check(static_cast<bool>(is), ">> int128 (stream state)");
        // 範囲外や数でないものは failbit
        for (std::string bad : {"170141183460469231731687303715884105728", "-170141183460469231731687303715884105729", "12a", "-", "x"}) {
            std::istringstream bs(bad);
            __int128_t x;
            bs >> x;
            check(bs.fail(), ">> int128 (不正)");
        }
        for (std::string bad : {"340282366920938463463374607431768211456", "-1"}) {
            std::istringstream bs(bad);
            __uint128_t x;
            bs >> x;
            check(bs.fail(), ">> uint128 (不正)");
        }
        std::istringstream zs("-0");
        __uint128_t z = 1;
        zs >> z;
        check(!zs.fail() && z == 0, ">> uint128 (-0)");
        // ランダム: long long の積で作った値を書いて読み戻す
        for (int rep = 0; rep < 2000; rep++) {
            __int128_t x = static_cast<__int128_t>(static_cast<long long>(rng())) * static_cast<long long>(rng() * 1000003ULL);
            if (rng() % 2) x = -x;
            std::istringstream rs(to_str(x));
            __int128_t y = 0;
            rs >> y;
            check(x == y, "int128 round trip");
            // long long に収まるなら long long と同じ表記
            if (-1000000000000000000 <= x && x <= 1000000000000000000) check(to_str(x) == std::to_string(static_cast<long long>(x)), "<< int128 (long long と比べる)");
        }
        // 先頭の 0 は桁数に数えない
        std::istringstream lz("000000000000000000000000000000000000000000000123 -0000 +00340282366920938463463374607431768211455");
        __int128_t l1, l2;
        __uint128_t l3;
        lz >> l1 >> l2 >> l3;
        check(!lz.fail() && l1 == 123 && l2 == 0 && l3 == umax, ">> int128 (先頭の 0)");
        // ランダム: 全範囲の値を 1 桁ずつ愚直に変換したものと比べる (18 桁ずつ分ける境目を通る)
        for (int rep = 0; rep < 20000; rep++) {
            __uint128_t u = 0;
            for (int k = 0; k < 4; k++) u = u << 32 | rng();
            u >>= rng() % 128;
            std::string expect;
            for (__uint128_t y = u; expect.empty() || y > 0; y /= 10) expect.insert(expect.begin(), static_cast<char>('0' + static_cast<int>(y % 10)));
            check(to_str(u) == expect, "<< uint128 (random)");
            std::istringstream us(expect);
            __uint128_t v = 0;
            us >> v;
            check(!us.fail() && u == v, ">> uint128 (random)");
            const __int128_t x = static_cast<__int128_t>(u >> 1), nx = -x;
            check(to_str(nx) == (x == 0 ? "" : "-") + to_str(static_cast<__uint128_t>(x)), "<< int128 (random 負)");
            std::istringstream ns(to_str(nx));
            __int128_t y = 0;
            ns >> y;
            check(!ns.fail() && y == nx, ">> int128 (random 負)");
            // 最大値の付近: imax - 10 + r は r <= 10 なら読めて、そうでなければ範囲外
            const int r = rng() % 21;
            std::istringstream near(to_str(static_cast<__uint128_t>(imax) - 10 + r));
            __int128_t a = 0;
            near >> a;
            check(near.fail() == (r > 10) && (r > 10 || a == imax - 10 + r), ">> int128 (最大値の付近)");
            std::istringstream near_neg("-" + to_str(static_cast<__uint128_t>(imax) - 9 + r));
            near_neg >> a;
            check(near_neg.fail() == (r > 10) && (r > 10 || a == -imax + 9 - r), ">> int128 (最小値の付近)");
        }
        check(capture(std::cout, [&] { print(imin, umax); }) == "-170141183460469231731687303715884105728 340282366920938463463374607431768211455\n", "print(int128)");
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
