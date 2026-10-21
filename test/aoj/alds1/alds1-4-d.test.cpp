#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D"

#include <iostream>
#include <vector>

#include "../../../src/utility/binary-search.hpp"

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> w(n);
    for (auto& x : w) std::cin >> x;
    // 最大積載量 P で k 台に積めるか
    auto can = [&](long long p) {
        int cnt = 1;
        long long cur = 0;
        for (long long x : w) {
            if (x > p) return false;
            if (cur + x > p) {
                cnt++;
                cur = 0;
            }
            cur += x;
        }
        return cnt <= k;
    };
    // 積めない P (ng) と積める P (ok) の境界を二分探索する
    long long ng = 0, ok = 100000LL * 10000LL;
    std::cout << binary_search(ok, ng, can) << '\n';
}
