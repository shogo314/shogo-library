#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// macro.hpp のマクロの動作を検証する
// 入力マクロは std::cin の入力元を、出力マクロは std::cout の出力先を一時的に差し替えて検証する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../../src/base/macro.hpp"

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

// for 文で愚直に作った列
std::vector<ll> naive_up(ll a, ll n, ll t) {
    std::vector<ll> v;
    for (ll i = a; i < n; i += t) v.push_back(i);
    return v;
}
std::vector<ll> naive_down(ll a, ll n, ll t) {
    std::vector<ll> v;
    for (ll i = n - 1; i >= a; i -= t) v.push_back(i);
    return v;
}

// 出力マクロは return するので void 関数の中で使う
// after が書き換わらなければ、マクロの後ろは実行されていない
int after = 0;
void yes_upper() { YES after = 1; }
void no_upper() { NO after = 1; }
void yes_lower() { Yes after = 1; }
void no_lower() { No after = 1; }
void takahashi() { Takahashi after = 1; }
void aoki() { Aoki after = 1; }

template <class F>
std::string capture_cout(F f) {
    std::ostringstream buf;
    std::streambuf* old = std::cout.rdbuf(buf.rdbuf());
    f();
    std::cout.rdbuf(old);
    return buf.str();
}

int calls = 0;
ll counted(ll x) {
    calls++;
    return x;
}

int main() {
    // all
    {
        std::vector<int> v{3, 1, 2};
        std::sort(all(v));
        check(v == std::vector<int>({1, 2, 3}), "all");
    }

    // rep (1〜4 引数)
    for (ll a = -3; a <= 6; a++) {
        for (ll n = -3; n <= 8; n++) {
            {
                int cnt = 0;
                rep(n) cnt++;
                check(cnt == std::max<ll>(n, 0), "rep(n)");
            }
            {
                std::vector<ll> v;
                rep(i, n) v.push_back(i);
                check(v == naive_up(0, n, 1), "rep(i, n)");
            }
            {
                std::vector<ll> v;
                rep(i, a, n) v.push_back(i);
                check(v == naive_up(a, n, 1), "rep(i, a, n)");
            }
            for (ll t = 1; t <= 4; t++) {
                std::vector<ll> v;
                rep(i, a, n, t) v.push_back(i);
                check(v == naive_up(a, n, t), "rep(i, a, n, t)");
            }
            {
                std::vector<ll> v;
                repd(i, n) v.push_back(i);
                check(v == naive_down(0, n, 1), "repd(i, n)");
            }
            {
                std::vector<ll> v;
                repd(i, a, n) v.push_back(i);
                check(v == naive_down(a, n, 1), "repd(i, a, n)");
            }
            for (ll t = 1; t <= 4; t++) {
                std::vector<ll> v;
                repd(i, a, n, t) v.push_back(i);
                check(v == naive_down(a, n, t), "repd(i, a, n, t)");
            }
        }
        {
            std::vector<ll> v;
            rrep(i, a) v.push_back(i);
            check(v == naive_up(1, a + 1, 1), "rrep(i, n)");
        }
        {
            std::vector<ll> v;
            rrepd(i, a) v.push_back(i);
            check(v == naive_down(1, a + 1, 1), "rrepd(i, n)");
        }
    }
    {
        // rep(n) を同じスコープで入れ子にできる (ループ変数の名前が重ならない)
        int cnt = 0;
        rep(3) rep(4) cnt++;
        check(cnt == 12, "nested rep(n)");
        // 終端と増分は最初に 1 回だけ評価される
        calls = 0;
        int iter = 0;
        rep(i, 0, counted(5), counted(2)) iter++;
        check(iter == 3 && calls == 2, "rep evaluates bounds once");
        // ループ変数は long long
        rep(i, 1) static_assert(std::is_same_v<decltype(i), long long>);
    }

    // 入力マクロ
    {
        std::istringstream in(
            "1 -2 "            // LL(a, b)
            "hello world "     // STR(s, t)
            "7 "               // IN(int, x)
            "z "               // CHAR(c)
            "3 4 5 "           // VL(v, 3)
            "6 7 "             // AL(arr, 2)
            "1 2 3 4 5 6 "     // AAL(aa, 2, 3)
            "x y "             // VC(vc_, 2)
            "ab cd "           // VS(vs_, 2)
            "1 2 3 4 "         // VPL(vp, 2)
            "1 2 3 4 5 6 "     // VAL(va, 2, 3)
            "9 8 7 6 "         // VVL(vv_, 2, 2)
            "5 3 5 1 ");       // SL(st, 4)
        std::streambuf* old = std::cin.rdbuf(in.rdbuf());
        LL(a, b);
        STR(s, t);
        IN(int, x);
        CHAR(c);
        VL(v, 3);
        AL(arr, 2);
        AAL(aa, 2, 3);
        VC(vc_, 2);
        VS(vs_, 2);
        VPL(vp, 2);
        VAL(va, 2, 3);
        VVL(vv_, 2, 2);
        SL(st, 4);
        std::cin.rdbuf(old);
        check(a == 1 && b == -2 && std::is_same_v<decltype(a), ll>, "LL");
        check(s == "hello" && t == "world", "STR");
        check(x == 7 && std::is_same_v<decltype(x), int>, "IN");
        check(c == 'z', "CHAR");
        check(v == vl({3, 4, 5}), "VL");
        check(arr == al<2>{6, 7}, "AL");
        check(aa == aal<2, 3>{{{1, 2, 3}, {4, 5, 6}}}, "AAL");
        check(vc_ == vc({'x', 'y'}), "VC");
        check(vs_ == vs({"ab", "cd"}), "VS");
        check(vp == vpl({{1, 2}, {3, 4}}), "VPL");
        check(va == val<3>({{1, 2, 3}, {4, 5, 6}}), "VAL");
        check(vv_ == vvl({{9, 8}, {7, 6}}), "VVL");
        check(st == sl({1, 3, 5}), "SL");
        check(bool(in), "input stream state");
    }
    {
        // scan を直接使う
        std::istringstream in("10 abc 2.5");
        std::streambuf* old = std::cin.rdbuf(in.rdbuf());
        int p;
        std::string q;
        double r;
        scan(p, q, r);
        scan();
        std::cin.rdbuf(old);
        check(p == 10 && q == "abc" && r == 2.5, "scan");
    }

    // 出力マクロ (出力して return する)
    after = 0;
    check(capture_cout(yes_upper) == "YES\n", "YES");
    check(capture_cout(no_upper) == "NO\n", "NO");
    check(capture_cout(yes_lower) == "Yes\n", "Yes");
    check(capture_cout(no_lower) == "No\n", "No");
    check(capture_cout(takahashi) == "Takahashi\n", "Takahashi");
    check(capture_cout(aoki) == "Aoki\n", "Aoki");
    check(after == 0, "output macros return");

    if (ok) std::cout << "Hello World" << std::endl;
}
