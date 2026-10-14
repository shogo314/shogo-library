#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// PriorityCounter (MaxCounter / MinCounter) を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/priority_counter.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <vector>

// 全体の個数から、Compare で大きい方から K 個の値とその個数を求める
template <size_t K, class Compare>
std::vector<std::pair<int, long long>> top_k(const std::map<int, long long>& m) {
    std::vector<std::pair<int, long long>> v(m.begin(), m.end());
    std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return Compare()(b.first, a.first); });
    if (v.size() > K) v.resize(K);
    return v;
}

template <size_t K, class Compare>
bool same(const PriorityCounter<int, K, Compare>& pc, const std::map<int, long long>& m) {
    auto expect = top_k<K, Compare>(m);
    if (pc.size() != (int)expect.size()) return false;
    for (size_t i = 0; i < expect.size(); i++) {
        if (pc.data[i] != expect[i]) return false;
    }
    // 使われていない場所の個数は 0
    for (size_t i = expect.size(); i < K; i++) {
        if (pc.data[i].second != 0) return false;
    }
    return true;
}

template <size_t K, class Compare>
bool run(std::mt19937& rng) {
    using PC = PriorityCounter<int, K, Compare>;
    {
        PC empty;
        if (!same<K, Compare>(empty, {})) return false;
        PC one(7);
        if (!same<K, Compare>(one, {{7, 1}})) return false;
    }
    for (int rep = 0; rep < 2000; rep++) {
        PC a, b;
        std::map<int, long long> ma, mb;
        int q = rng() % 12;
        for (int t = 0; t < q; t++) {
            int x = rng() % 8;
            long long c = rng() % 3 + 1;
            if (rng() % 2) {
                a.inc(x, c);
                ma[x] += c;
            } else {
                // 個数を省略すると 1
                a.inc(x);
                ma[x] += 1;
            }
            if (!same<K, Compare>(a, ma)) return false;
            int y = rng() % 8;
            b.inc(y, 2);
            mb[y] += 2;
        }
        std::map<int, long long> sum = ma;
        for (auto [x, c] : mb) sum[x] += c;
        if (!same<K, Compare>(a + b, sum)) return false;
        a += b;
        if (!same<K, Compare>(a, sum)) return false;
    }
    return true;
}

// constexpr で使えること (C++17 の定数式で inc・+・size を評価する)
constexpr bool constexpr_check() {
    MaxCounter<int, 2> a;
    a.inc(5);
    a.inc(1);
    a.inc(9);  // 上位 2 個 {9, 5} が残り、1 は押し出される
    a.inc(5, 2);
    MaxCounter<int, 2> b(7);
    MaxCounter<int, 2> c = a + b;  // {9, 7}
    return a.size() == 2 && a.data[0] == std::pair<int, long long>(9, 1) && a.data[1] == std::pair<int, long long>(5, 3) &&
           c.data[0] == std::pair<int, long long>(9, 1) && c.data[1] == std::pair<int, long long>(7, 1) &&
           MinCounter<int, 3>().size() == 0;
}
static_assert(constexpr_check());

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    ok = ok && run<1, std::less<int>>(rng);
    ok = ok && run<2, std::less<int>>(rng);
    ok = ok && run<3, std::less<int>>(rng);
    ok = ok && run<5, std::less<int>>(rng);
    ok = ok && run<1, std::greater<int>>(rng);
    ok = ok && run<3, std::greater<int>>(rng);

    // 別名: MaxCounter は大きい方、MinCounter は小さい方を残す
    MaxCounter<int, 2> mx;
    MinCounter<int, 2> mn;
    for (int x : {5, 1, 9, 5, 3}) {
        mx.inc(x);
        mn.inc(x);
    }
    ok = ok && mx.size() == 2 && mx.data[0] == std::make_pair(9, 1LL) && mx.data[1] == std::make_pair(5, 2LL);
    ok = ok && mn.size() == 2 && mn.data[0] == std::make_pair(1, 1LL) && mn.data[1] == std::make_pair(3, 1LL);

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
