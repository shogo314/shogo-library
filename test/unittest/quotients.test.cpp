#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// enumerate_quotients と for_each_quotient を、i ごとに商を計算する愚直な方法と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <vector>

#include "../../src/math/quotients.hpp"

int main() {
    bool ok = true;
    for (long long n = 0; n <= 3000 && ok; n++) {
        auto qs = enumerate_quotients(n);
        // 区間が 1 から n までを隙間なく覆い、区間の中で商が q に等しく、隣の区間とは商が異なる
        long long next = 1;
        for (int k = 0; k < (int)qs.size(); k++) {
            auto [q, l, r] = qs[k];
            if (l != next || l > r) ok = false;
            if (n / l != q || n / r != q) ok = false;
            if (k > 0 && qs[k - 1].q <= q) ok = false;
            next = r + 1;
        }
        if (next != n + 1) ok = false;
        // 区間の個数は 2 sqrt(n) 以下
        long long k = qs.size();
        if (k * k > 4 * n) ok = false;
        // 約数の個数の和 sum_{k <= n} d(k) = sum_{i <= n} floor(n / i)
        long long expected = 0, sum = 0;
        for (long long i = 1; i <= n; i++) expected += n / i;
        for_each_quotient(n, [&](long long q, long long l, long long r) { sum += q * (r - l + 1); });
        ok = ok && sum == expected;
    }

    // 例
    auto qs = enumerate_quotients(10);
    std::vector<long long> q, l, r;
    for (auto x : qs) q.push_back(x.q), l.push_back(x.l), r.push_back(x.r);
    ok = ok && q == std::vector<long long>{10, 5, 3, 2, 1} && l == std::vector<long long>{1, 2, 3, 4, 6};
    ok = ok && r == std::vector<long long>{1, 2, 3, 5, 10};
    // 大きい n でも区間の個数は 2 sqrt(n) 程度
    ok = ok && enumerate_quotients(1000000000000LL).size() == 1999999;

    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
