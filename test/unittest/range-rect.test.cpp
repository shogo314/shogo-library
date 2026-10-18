#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Rect (2 つの Range の直積) を、2 重ループで愚直に作った (i, j) の列とランダムに比較する
// neighbors4 / neighbors8 は、位置の差で愚直に選んだものと比べる
// Range::contains の step = 1 の近道も、愚直な判定と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/utility/range.hpp"

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <random>
#include <utility>
#include <vector>
#if __cplusplus >= 202002L
#include <ranges>
#endif

using ll = long long;
using P = std::pair<ll, ll>;

std::vector<ll> naive_range(ll start, ll stop, ll step) {
    std::vector<ll> v;
    if (step > 0) {
        for (ll x = start; x < stop; x += step) v.push_back(x);
    } else {
        for (ll x = start; x > stop; x += step) v.push_back(x);
    }
    return v;
}

// コンパイル時にも使える
static_assert(Rect(3, 4).size() == 12);
static_assert(Rect(3, 4).index(2, 1) == 9);
static_assert(Rect(3, 4)[9] == P(2, 1));
static_assert(Rect(3, 4).contains(2, 3) && !Rect(3, 4).contains(3, 0) && !Rect(3, 4).contains(0, -1));
static_assert(Rect({1, 4}, {10, 0, -5}).size() == 6);
constexpr ll sum_in_constexpr() {
    ll s = 0;
    for (auto [i, j] : Rect(3, 4)) s += i * 10 + j;
    return s;
}
static_assert(Rect(3, 4).neighbors4(0, 0).size() == 2 && Rect(3, 4).neighbors8(1, 1).size() == 8);
static_assert(*++Rect(3, 4).neighbors4(2, 3).begin() == P(2, 2));
static_assert(sum_in_constexpr() == 4 * (0 + 10 + 20) + 3 * (0 + 1 + 2 + 3));
static_assert(std::is_same_v<std::iterator_traits<Rect::const_iterator>::iterator_category, std::forward_iterator_tag>);
#if __cplusplus >= 202002L
static_assert(std::forward_iterator<Rect::const_iterator>);
static_assert(std::ranges::forward_range<Rect> && std::ranges::sized_range<Rect>);
#endif

int main() {
    std::mt19937_64 rng(314);
    auto rnd = [&](ll lo, ll hi) { return lo + (ll)(rng() % (unsigned long long)(hi - lo + 1)); };
    bool ok = true;
    auto check = [&](bool cond, const char* what) {
        if (!cond) {
            if (ok) std::cerr << "failed: " << what << std::endl;
            ok = false;
        }
    };
    auto random_range = [&]() {
        ll start = rnd(-6, 6), stop = rnd(-6, 6), step = rnd(-3, 3);
        if (step == 0) step = 1;
        if (rng() % 3 == 0) step = 1;
        return Range(start, stop, step);
    };

    for (int rep = 0; rep < 3000 && ok; rep++) {
        const Range r = random_range(), c = random_range();
        const Rect rect(r, c);
        std::vector<ll> rv = naive_range(r.start, r.stop, r.step), cv = naive_range(c.start, c.stop, c.step);
        std::vector<P> expected;
        for (ll i : rv)
            for (ll j : cv) expected.emplace_back(i, j);

        // 行優先に列挙する
        std::vector<P> got;
        for (auto [i, j] : rect) got.emplace_back(i, j);
        check(got == expected, "列挙");
        check(std::vector<P>(rect.begin(), rect.end()) == expected, "イテレータの範囲から vector を作る");
        check(std::distance(rect.begin(), rect.end()) == (ll)expected.size(), "distance");
        check(rect.size() == (ll)expected.size() && rect.empty() == expected.empty(), "size / empty");
        {
            auto it = rect.begin();
            auto old = it++;
            check(expected.empty() || (*old == expected[0] && (expected.size() == 1 ? it == rect.end() : *it == expected[1])), "後置 ++");
        }

        // at / index は互いに逆
        for (ll k = 0; k < (ll)expected.size(); k++) {
            check(rect[k] == expected[k] && rect.at(k) == expected[k], "at");
            check(rect.index(expected[k].first, expected[k].second) == k && rect.index(expected[k]) == k, "index");
        }

        // contains: 列挙した中にあるか
        for (int t = 0; t < 30; t++) {
            ll i = rnd(-8, 8), j = rnd(-8, 8);
            bool in = false;
            for (auto& p : expected) in |= p == P(i, j);
            check(rect.contains(i, j) == in && rect.contains(P(i, j)) == in, "contains");
        }

        // neighbors4 / neighbors8: 位置 (rows・cols の何番目か) の差が 1 以内のものを Rect の順に
        for (ll k = 0; k < (ll)expected.size(); k++) {
            const ll w = (ll)cv.size(), ki = k / w, kj = k % w;
            std::vector<P> e4, e8;
            for (ll t = 0; t < (ll)expected.size(); t++) {
                const ll di = std::abs(t / w - ki), dj = std::abs(t % w - kj);
                if (t == k || di > 1 || dj > 1) continue;
                e8.push_back(expected[t]);
                if (di + dj == 1) e4.push_back(expected[t]);
            }
            auto [i, j] = expected[k];
            auto n4 = rect.neighbors4(i, j), n8 = rect.neighbors8(expected[k]);
            check(std::vector<P>(n4.begin(), n4.end()) == e4 && n4.size() == (ll)e4.size(), "neighbors4");
            check(std::vector<P>(n8.begin(), n8.end()) == e8 && n8.size() == (ll)e8.size() && n8.empty() == e8.empty(), "neighbors8");
        }

        // ==: 要素の列として等しいか
        const Rect same(Range(r.start, r.stop, r.step), Range(c.start, c.stop, c.step));
        check(rect == same && !(rect != same), "== 同じもの");
        const Rect other(random_range(), random_range());
        std::vector<P> ov(other.begin(), other.end());
        check((rect == other) == (ov == expected), "== ランダム");
    }

    // Range::contains の step = 1 の近道 (コンパイル時に step が分からない場合)
    for (int rep = 0; rep < 3000 && ok; rep++) {
        const Range r(rnd(-10, 10), rnd(-10, 10), rng() % 2 ? 1 : rnd(-3, 3) | 1);
        std::vector<ll> v = naive_range(r.start, r.stop, r.step);
        for (ll x = -12; x <= 12; x++) {
            bool in = false;
            for (ll y : v) in |= y == x;
            check(r.contains(x) == in && r.count(x) == (ll)in, "Range::contains");
        }
    }

    // 決まった値
    {
        Rect g(2, 3);
        std::vector<P> v(g.begin(), g.end());
        check(v == std::vector<P>{{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}}, "Rect(2, 3)");
        check(Rect(0, 5).empty() && Rect(5, 0).empty() && Rect(-1, 3).empty() && Rect(0, 5).begin() == Rect(0, 5).end(), "空");
        check(Rect(0, 5) == Rect(3, 0), "空どうしは等しい");
        check(g.repr() == "Rect(Range(0, 2, 1), Range(0, 3, 1))" && g.initializer_str() == "{{0, 2, 1}, {0, 3, 1}}" && Rect::type_str() == "Rect", "repr");
        std::vector<P> n4, n8;
        for (auto [i, j] : g.neighbors4(1, 1)) n4.emplace_back(i, j);
        for (auto [i, j] : g.neighbors8({0, 0})) n8.emplace_back(i, j);
        check(n4 == std::vector<P>{{0, 1}, {1, 0}, {1, 2}} && n8 == std::vector<P>{{0, 1}, {1, 0}, {1, 1}}, "neighbors 決まった値");
        check(Rect(1, 1).neighbors8(0, 0).empty(), "neighbors 1 マス");
        Rect h(g);  // コピー
        check(h == g, "copy");
    }
#if __cplusplus >= 202002L
    {
        // C++20 の range として views と組み合わせられる (代入できないので、一時オブジェクトではなく変数を渡す)
        ll cnt = 0;
        const Rect g(4, 4);
        for (auto [i, j] : g | std::views::filter([](P p) { return p.first == p.second; })) cnt += i + j;
        check(cnt == 12 && std::ranges::size(Rect(3, 5)) == 15, "views");
    }
#endif

    if (ok) std::cout << "Hello World" << std::endl;
}
