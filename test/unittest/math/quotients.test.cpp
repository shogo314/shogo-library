#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// enumerate_quotients と for_each_quotient を、i ごとに商を計算する愚直な方法と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/quotients.hpp"

#include <cassert>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>
#if __cplusplus >= 202002L
#include <ranges>
#endif

#if __cplusplus >= 202002L
static_assert(std::ranges::input_range<decltype(enumerate_quotients(10))>);
#endif

int main() {
    bool ok = true;
    for (long long n = 0; n <= 3000 && ok; n++) {
        auto range = enumerate_quotients(n);
        std::vector<QuotientRange> qs(range.begin(), range.end());
        // 区間が 1 から n までを隙間なく覆い、区間の中で商が q に等しく、隣の区間とは商が異なる
        long long next = 1;
        for (int k = 0; k < static_cast<int>(qs.size()); k++) {
            auto [q, l, r] = qs[k];
            if (l != next || l >= r) ok = false;
            if (n / l != q || n / (r - 1) != q) ok = false;
            if (k > 0 && qs[k - 1].q <= q) ok = false;
            next = r;
        }
        if (next != n + 1) ok = false;
        // 区間の個数は 2 sqrt(n) 以下
        long long k = qs.size();
        if (k * k > 4 * n) ok = false;
        // 約数の個数の和 sum_{k <= n} d(k) = sum_{i <= n} floor(n / i)
        long long expected = 0, sum = 0;
        for (long long i = 1; i <= n; i++) expected += n / i;
        for_each_quotient(n, [&](long long q, long long l, long long r) { sum += q * (r - l); });
        ok = ok && sum == expected;
    }

    // 例
    auto qs = enumerate_quotients(10);
    std::vector<long long> q, l, r;
    for (auto x : qs) q.push_back(x.q), l.push_back(x.l), r.push_back(x.r);
    ok = ok && q == std::vector<long long>{10, 5, 3, 2, 1} && l == std::vector<long long>{1, 2, 3, 4, 6};
    ok = ok && r == std::vector<long long>{2, 3, 4, 6, 11};
    // 大きい n でも区間の個数は 2 sqrt(n) 程度
    auto large = enumerate_quotients(1000000000000LL);
    ok = ok && std::distance(large.begin(), large.end()) == 1999999;
    const auto huge = enumerate_quotients(std::numeric_limits<long long>::max() - 1);
    auto first = huge.begin(), copy = first;
    assert((*first++).l == 1 && (*first).l == 2 && (*copy).l == 1);
    assert((*huge.begin()).l == 1);

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
