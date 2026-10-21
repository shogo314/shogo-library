#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// LiChaoTree と DynamicLiChaoTree を、追加した直線・線分をすべて調べる愚直な実装とランダムに比べる
// 負の x や、幅 1 の範囲、空の線分も試す
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/convex-hull-trick.hpp"

#include <iostream>
#include <optional>
#include <random>
#include <tuple>
#include <vector>

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

int main() {
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 2000 && ok; rep++) {
        long long lo = static_cast<long long>(rng() % 41) - 20, w = rng() % 30 + 1, hi = lo + w;
        DynamicLiChaoTree<long long> dyn(lo, hi);
        std::vector<long long> xs;
        for (long long x = lo; x <= hi; x++) xs.push_back(x);  // 線分の右端に hi も使うので含める
        LiChaoTree<long long> st(xs);
        std::vector<std::tuple<long long, long long, long long, long long>> segs;  // a, b, l, r
        for (int q = 0; q < 40 && ok; q++) {
            int t = rng() % 3;
            long long a = static_cast<long long>(rng() % 21) - 10, b = static_cast<long long>(rng() % 201) - 100;
            if (t == 0) {
                dyn.add_line(a, b);
                st.add_line(a, b);
                segs.emplace_back(a, b, lo, hi);
            } else if (t == 1) {
                long long l = lo + rng() % (w + 1), r = lo + rng() % (w + 1);
                if (l > r) std::swap(l, r);
                dyn.add_segment(a, b, l, r);
                st.add_segment(a, b, l - lo, r - lo);
                segs.emplace_back(a, b, l, r);
            }
            for (long long x = lo; x < hi; x++) {
                std::optional<long long> expect;
                for (auto [sa, sb, sl, sr] : segs)
                    if (sl <= x && x < sr && (!expect || sa * x + sb < *expect)) expect = sa * x + sb;
                check(dyn.get_min(x) == expect, "DynamicLiChaoTree");
                check(st.get_min(x - lo) == expect, "LiChaoTree");
            }
        }
    }
    // 範囲が 10^9 程度でも使える
    {
        DynamicLiChaoTree<long long> cht(-1000000000, 1000000001);
        cht.add_line(2, 3);
        cht.add_segment(-1, 0, 0, 10);
        check(cht.get_min(5) == -5 && cht.get_min(-1000000000) == -1999999997 && cht.get_min(10) == 23, "大きい範囲");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
