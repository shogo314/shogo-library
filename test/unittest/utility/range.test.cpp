#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Range を愚直に作った std::vector (Python の range と同じ列) とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/utility/range.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

using ll = long long;

// Python の range(start, stop, step) と同じ列
std::vector<ll> naive_range(ll start, ll stop, ll step) {
    std::vector<ll> v;
    if (step > 0) {
        for (ll x = start; x < stop; x += step) v.push_back(x);
    } else {
        for (ll x = start; x > stop; x += step) v.push_back(x);
    }
    return v;
}

std::vector<ll> by_iteration(const Range& r) {
    std::vector<ll> v;
    for (ll x : r) v.push_back(x);
    return v;
}

// コンパイル時にも使える
static_assert(Range(0, 10, 3).size() == 4);
static_assert(Range(10, 0, -3).sum() == 22);
static_assert(Range(5).max() == 4);

int main() {
    std::mt19937_64 rng(314);
    auto rnd = [&](ll lo, ll hi) { return lo + static_cast<ll>(rng() % static_cast<unsigned long long>(hi - lo + 1)); };
    bool ok = true;
    auto check = [&](bool cond, const char* what) {
        if (!cond) {
            if (ok) std::cerr << "failed: " << what << std::endl;
            ok = false;
        }
    };

    // コンストラクタ
    check(by_iteration(Range(5)) == naive_range(0, 5, 1), "Range(stop)");
    check(by_iteration(Range(-3)).empty(), "Range(negative stop)");
    check(by_iteration(Range(2, 7)) == naive_range(2, 7, 1), "Range(start, stop)");
    check(Range().empty() && Range().size() == 0 && by_iteration(Range()).empty(), "Range()");
    {
        Range a(1, 20, 4);
        Range b(a);  // コピー
        check(by_iteration(b) == naive_range(1, 20, 4), "copy");
    }

    for (int rep = 0; rep < 20000 && ok; rep++) {
        ll start = rnd(-20, 20), stop = rnd(-20, 20), step = rnd(1, 7) * (rng() % 2 ? 1 : -1);
        Range r(start, stop, step);
        std::vector<ll> v = naive_range(start, stop, step);
        int n = v.size();

        check(r.start == start && r.stop == stop && r.step == step, "members");
        check(by_iteration(r) == v, "iteration");
        check(r.to_vector() == v, "to_vector");
        check(std::vector<ll>(r.begin(), r.end()) == v, "iterator range constructor");
        check(r.size() == n, "size");
        check(r.empty() == v.empty(), "empty");
        check(r.end() - r.begin() == n, "end - begin");
        for (int i = 0; i < n; i++) {
            check(r.at(i) == v[i] && r[i] == v[i], "at / []");
        }

        // count, contains, index, find
        for (ll x = -30; x <= 30; x++) {
            int c = std::count(v.begin(), v.end(), x);
            check(r.count(x) == c, "count");
            check(r.contains(x) == (c > 0), "contains");
            if (c > 0) {
                int idx = std::find(v.begin(), v.end(), x) - v.begin();
                check(r.index(x) == idx, "index");
                check(*r.find(x) == x && r.find(x) - r.begin() == idx, "find (found)");
            } else {
                check(r.find(x) == r.end(), "find (not found)");
            }
        }

        // lower_bound, upper_bound (step > 0 のときだけ使える)
        if (step > 0) {
            for (ll x = -30; x <= 30; x++) {
                check(r.lower_bound(x) - r.begin() == std::lower_bound(v.begin(), v.end(), x) - v.begin(), "lower_bound");
                check(r.upper_bound(x) - r.begin() == std::upper_bound(v.begin(), v.end(), x) - v.begin(), "upper_bound");
            }
        }

        // sum, min, max
        ll sum = 0;
        for (ll x : v) sum += x;
        check(r.sum() == sum, "sum");
        if (n > 0) {
            check(r.min() == *std::min_element(v.begin(), v.end()), "min");
            check(r.max() == *std::max_element(v.begin(), v.end()), "max");
        }

        // reversed, sorted
        std::vector<ll> rv(v.rbegin(), v.rend()), sv = v;
        std::sort(sv.begin(), sv.end());
        check(by_iteration(r.reversed()) == rv && r.reversed().size() == n, "reversed");
        check(by_iteration(r.sorted()) == sv && r.sorted().size() == n, "sorted");

        // clipped: 値が [l, r) の要素だけを順番を保って残す
        {
            ll l = rnd(-25, 25), rr = rnd(-25, 25);
            std::vector<ll> expect;
            for (ll x : v)
                if (l <= x && x < rr) expect.push_back(x);
            Range c = r.clipped(l, rr);
            check(by_iteration(c) == expect && c.size() == static_cast<long long>(expect.size()), "clipped");
        }

        // slice: インデックスを Range で指定する (範囲外のインデックスは無視)
        {
            ll s2 = rnd(-25, 25), t2 = rnd(-25, 25), st2 = rnd(1, 5) * (rng() % 2 ? 1 : -1);
            Range idx(s2, t2, st2);
            std::vector<ll> expect;
            for (ll i : naive_range(s2, t2, st2))
                if (0 <= i && i < n) expect.push_back(v[i]);
            Range s = r.slice(idx);
            check(by_iteration(s) == expect && s.size() == static_cast<long long>(expect.size()), "slice");
        }

        // ==, != は列として等しいか
        {
            ll start2 = rng() % 4 == 0 ? start : rnd(-20, 20);
            ll stop2 = rng() % 2 == 0 ? stop + rnd(-3, 3) : rnd(-20, 20);
            ll step2 = rng() % 2 == 0 ? step : rnd(1, 7) * (rng() % 2 ? 1 : -1);
            Range r2(start2, stop2, step2);
            bool same = v == naive_range(start2, stop2, step2);
            check((r == r2) == same && (r != r2) == !same, "== / !=");
        }

        // イテレータの各演算
        if (n > 0) {
            int i = rnd(0, n - 1), j = rnd(0, n - 1);
            auto it = r.begin() + i;
            check(*it == v[i] && it.base() == v[i], "begin + i");
            check(*(i + r.begin()) == v[i], "i + begin");
            check(*(r.end() - (n - i)) == v[i], "end - k");
            check((r.begin() + j) - it == j - i, "iterator difference");
            auto it2 = it;  // コピーコンストラクタ
            check(it2 == it && !(it2 != it), "copy / ==");
            it2 = r.begin();  // 同じ Range のイテレータの代入
            check(*it2 == v[0], "operator=");
            auto a = it;
            auto b = a++;
            check(*b == v[i] && a - b == 1, "post ++");
            auto c = ++b;
            check(c == a && *c == *a, "pre ++");
            auto d = a--;
            check(d - a == 1 && *a == v[i], "post --");
            --d;
            check(d == a, "pre --");
            auto e = it;
            e += j - i;
            check(*(e) == v[j] || j == n, "+=");
            e -= j - i;
            check(e == it, "-=");
            check(it != r.end(), "!= end");
        }
        check(r.begin() + n == r.end(), "begin + size == end");
    }

    // product_xor (負を含まない列)
    for (int rep = 0; rep < 5000 && ok; rep++) {
        ll start, stop, step;
        if (rep % 2 == 0) {
            start = rnd(0, 100), stop = rnd(0, 100), step = rnd(1, 9) * (rng() % 2 ? 1 : -1);
            if (step < 0 && stop < -1) stop = -1;
        } else {
            // 大きい値 (要素数は少なめ)
            start = rnd(0, 1000000000000LL), step = rnd(1, 1000000000LL) * (rng() % 2 ? 1 : -1);
            stop = start + step * rnd(0, 300);
            if (stop < -1) stop = -1;
        }
        Range r(start, stop, step);
        ll x = 0;
        for (ll y : naive_range(start, stop, step)) x ^= y;
        check(r.product_xor() == x, "product_xor");
    }

    // 文字列化
    {
        Range r(-3, 10, 2);
        check(Range::type_str() == "Range", "type_str");
        check(r.initializer_str() == "{-3, 10, 2}", "initializer_str");
        check(r.repr() == "Range(-3, 10, 2)", "repr");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
