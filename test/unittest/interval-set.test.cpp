#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// IntervalSet を「各整数点が覆われているか」の配列による愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <optional>
#include <random>
#include <utility>
#include <vector>

#include "../../src/data_structures/interval-set.hpp"

// 座標 [LO, HI) の範囲で操作する (負の座標も使う)
constexpr int LO = -5, HI = 20;

// 覆われている点の極大な連続部分を半開区間の列にする (接する区間はまとめられる)
std::vector<std::pair<long long, long long>> runs(const std::vector<bool>& cov) {
    std::vector<std::pair<long long, long long>> res;
    for (int i = 0; i < (int)cov.size();) {
        if (!cov[i]) {
            i++;
            continue;
        }
        int j = i;
        while (j < (int)cov.size() && cov[j]) j++;
        res.push_back({i + LO, j + LO});
        i = j;
    }
    return res;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 2000 && ok; rep++) {
        IntervalSet<long long> st;
        std::vector<bool> cov(HI - LO, false);
        for (int t = 0; t < 30 && ok; t++) {
            long long l = LO + rng() % (HI - LO - 1);
            long long r = l + 1 + rng() % (HI - l - 1 + 1);
            if (r > HI) r = HI;
            if (rng() % 3 != 0) {
                st.insert(l, r);
                for (long long x = l; x < r; x++) cov[x - LO] = true;
            } else {
                st.erase(l, r);
                for (long long x = l; x < r; x++) cov[x - LO] = false;
            }
            auto expect = runs(cov);
            if (st.to_vector() != expect || st.size() != expect.size()) ok = false;

            // covered_by(k): k を含む区間
            for (long long k = LO; k < HI; k++) {
                std::optional<std::pair<long long, long long>> e;
                for (auto& iv : expect) {
                    if (iv.first <= k && k < iv.second) e = iv;
                }
                if (st.covered_by(k) != e) ok = false;
            }
            // covered_by(l, r): [l, r) を完全に含む区間
            for (long long a = LO; a < HI; a++) {
                for (long long b = a + 1; b <= HI; b++) {
                    std::optional<std::pair<long long, long long>> e;
                    for (auto& iv : expect) {
                        if (iv.first <= a && b <= iv.second) e = iv;
                    }
                    if (st.covered_by(a, b) != e) ok = false;
                }
            }
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
