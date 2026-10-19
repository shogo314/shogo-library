#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// FastSet を std::set による愚直な実装とランダムな操作列で比べる
// 段の境目 (64、4096、262144) をまたぐ n も試す
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/fast-set.hpp"

#include <iostream>
#include <random>
#include <set>
#include <vector>

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

long long naive_next(const std::set<long long>& s, long long x) {
    auto it = s.lower_bound(x);
    return it == s.end() ? -1 : *it;
}
long long naive_prev(const std::set<long long>& s, long long x) {
    auto it = s.upper_bound(x);
    return it == s.begin() ? -1 : *std::prev(it);
}

int main() {
    std::mt19937_64 rng(314);
    std::vector<long long> sizes = {0, 1, 2, 63, 64, 65, 127, 128, 4095, 4096, 4097, 262143, 262144, 262145};
    for (int rep = 0; rep < 300; rep++) sizes.push_back(rng() % 300 + 1);
    for (long long n : sizes) {
        if (!ok) break;
        // 要素が少ない場合と多い場合を混ぜる
        int density = rng() % 3;
        std::vector<bool> init(n);
        std::set<long long> s;
        for (long long i = 0; i < n; i++) {
            bool in = density == 0 ? rng() % 50 == 0 : density == 1 ? rng() % 2 == 0
                                                                    : rng() % 50 != 0;
            init[i] = in;
            if (in) s.insert(i);
        }
        FastSet fs = rng() % 2 ? FastSet(init) : FastSet(n);
        if (fs.empty() && !s.empty()) {
            for (long long x : s) fs.insert(x);
        }
        check(fs.limit() == n, "limit");
        int q = n > 10000 ? 3000 : 1000;
        for (int t = 0; t < q && ok; t++) {
            // n の外側 (負や n 以上) も next / prev に渡す
            long long x = n == 0 ? 0 : static_cast<long long>(rng() % n);
            long long y = static_cast<long long>(rng() % (n + 4)) - 2;
            int type = rng() % 6;
            if (n > 0 && type == 0) {
                check(fs.insert(x) == s.insert(x).second, "insert");
            } else if (n > 0 && type == 1) {
                check(fs.erase(x) == (s.erase(x) == 1), "erase");
            } else if (n > 0 && type == 2) {
                check(fs.contains(x) == (s.count(x) == 1) && fs.count(x) == static_cast<long long>(s.count(x)), "contains");
            } else if (type == 3) {
                check(fs.next(y) == naive_next(s, y), "next");
            } else if (type == 4) {
                check(fs.prev(y) == naive_prev(s, y), "prev");
            } else {
                check(fs.min() == (s.empty() ? -1 : *s.begin()) && fs.max() == (s.empty() ? -1 : *s.rbegin()), "min / max");
            }
            check(fs.size() == static_cast<long long>(s.size()) && fs.empty() == s.empty(), "size");
        }
        check(fs.to_vector() == std::vector<long long>(s.begin(), s.end()), "to_vector");
        fs.clear();
        check(fs.empty() && fs.min() == -1 && fs.max() == -1, "clear");
    }
    // 大きい n: 10^9 でも数要素だけなら速く動く
    {
        FastSet fs(1000000000);
        fs.insert(0), fs.insert(123456789), fs.insert(999999999);
        check(fs.next(1) == 123456789 && fs.next(123456790) == 999999999 && fs.prev(999999998) == 123456789 && fs.prev(-5) == -1, "10^9");
        fs.erase(123456789);
        check(fs.next(1) == 999999999 && fs.prev(999999998) == 0, "10^9 erase");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
