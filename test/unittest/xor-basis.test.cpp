#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// XorBasis を、作れる値をすべて列挙する愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "../../src/math/xor-basis.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    // 8 ビットで、作れる値を全部調べる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        XorBasis<unsigned char> xb;
        std::set<int> span = {0};
        int k = rng() % 8;
        int mask = rng() % 256;
        for (int it = 0; it < k && ok; it++) {
            int x = rng() % 256 & mask;  // 従属なものが出やすいようにビットを絞る
            bool expected = !span.count(x);
            ok = ok && xb.add(x) == expected;
            std::set<int> next = span;
            for (int y : span) next.insert(y ^ x);
            span = next;

            std::vector<int> vals(span.begin(), span.end());
            ok = ok && (1 << xb.rank()) == (int)vals.size() && (int)xb.basis().size() == xb.rank();
            for (int i = 0; i < (int)vals.size(); i++) ok = ok && xb.kth(i) == vals[i];
            for (int y = 0; y < 256; y++) {
                int mx = 0, mn = 255;
                for (int v : vals) mx = std::max(mx, y ^ v), mn = std::min(mn, y ^ v);
                int less = std::lower_bound(vals.begin(), vals.end(), y) - vals.begin();
                ok = ok && xb.contains(y) == (span.count(y) > 0) && xb.max(y) == mx && xb.min(y) == mn &&
                     xb.count_less(y) == (unsigned long long)less;
            }
            // 基底の最上位ビットは降順で異なり、ほかの基底のそのビットは 0
            auto bs = xb.basis();
            for (int i = 0; i < (int)bs.size(); i++) {
                int t = 31 - __builtin_clz(bs[i]);
                for (int j = 0; j < (int)bs.size(); j++) {
                    if (i != j && (bs[j] >> t & 1)) ok = false;
                }
                if (i > 0 && bs[i - 1] <= bs[i]) ok = false;
            }
        }
    }
    // 64 ビット: 基底が 64 個になる場合
    {
        XorBasis<> xb;
        for (int i = 0; i < 64; i++) ok = ok && xb.add((1ULL << i) | (i ? 1ULL << (i - 1) : 0));
        ok = ok && xb.rank() == 64 && !xb.add(12345) && xb.max() == ~0ULL && xb.kth(~0ULL) == ~0ULL;
        ok = ok && xb.count_less(~0ULL) == ~0ULL && xb.kth(5) == 5;
    }
    // 例
    {
        XorBasis<> xb;
        ok = ok && xb.add(5) && xb.add(3) && !xb.add(6);
        ok = ok && xb.contains(6) && !xb.contains(1) && xb.max() == 6 && xb.max(1) == 7 && xb.min(1) == 1;
        ok = ok && xb.kth(0) == 0 && xb.kth(1) == 3 && xb.kth(2) == 5 && xb.kth(3) == 6;
    }

    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
