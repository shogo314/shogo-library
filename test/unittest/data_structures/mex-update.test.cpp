#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// MexUpdate を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/mex-update.hpp"

#include <iostream>
#include <random>
#include <set>
#include <vector>

// v に含まれない最小の非負整数
template <typename T>
T naive_mex(const std::vector<T>& v) {
    std::set<T> s(v.begin(), v.end());
    T x = 0;
    while (s.count(x)) x++;
    return x;
}

template <typename T>
bool run(std::mt19937& rng) {
    for (int rep = 0; rep < 2000; rep++) {
        int n = rng() % 8 + 1;
        // 範囲外の値 (負の値や n より大きい値) も混ぜる
        auto random_value = [&]() -> T { return static_cast<T>(static_cast<int>(rng() % (n + 6)) - 3); };
        std::vector<T> v;
        MexUpdate<T> mu;
        if (rep % 2 == 0) {
            // MexUpdate(n): 値はどれも mex に影響しない値で初期化される
            mu = MexUpdate<T>(n);
            v.assign(n, static_cast<T>(-1));
            if (mu.mex() != 0) return false;
        } else {
            v.resize(n);
            for (auto& x : v) x = random_value();
            mu = MexUpdate<T>(v);
        }
        if (mu.mex() != naive_mex(v)) return false;
        for (int t = 0; t < 20; t++) {
            int k = rng() % n;
            T x = random_value();
            mu.set(k, x);
            v[k] = x;
            if (mu.mex() != naive_mex(v)) return false;
        }
    }
    return true;
}

int main() {
    std::mt19937 rng(314);
    // 符号なしの型では、負の値は大きな値になる (範囲外の値として扱われる)
    bool ok = run<int>(rng) && run<long long>(rng) && run<unsigned int>(rng) && run<unsigned long long>(rng);
    // 0..n-1 がすべて揃うと mex は n
    MexUpdate<int> full(std::vector<int>{2, 0, 1});
    ok = ok && full.mex() == 3;
    full.set(1, 3);
    ok = ok && full.mex() == 0;
    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
