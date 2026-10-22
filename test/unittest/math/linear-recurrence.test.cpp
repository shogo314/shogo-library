#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// bostan_mori・linear_recurrence_kth・berlekamp_massey を愚直な計算と比べる
// NTT の使えない法 (10^9 + 7) と、最短性を全探索で確かめるための小さい法 (3) も試す
// 長さが 60 を超えると bostan_mori は NTT した値のまま進める別の経路に入るので、
// 同じ法の dynamic_modint (この経路に入らない) と、長さの境目 (2 のべき乗の前後) で比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/linear-recurrence.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

#include "../../../src/math/modint.hpp"

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

template <typename mint>
void test_mod(std::mt19937_64& rng) {
    auto gen = [&] { return mint(rng() % mint::mod()); };
    // bostan_mori: P / Q を係数ごとに割り算で求めたものと比べる (P の次数が Q 以上の場合も)
    for (int rep = 0; rep < 300 && ok; rep++) {
        int np = rng() % 6, nq = rng() % 5 + 1;
        std::vector<mint> P(np), Q(nq);
        for (auto& x : P) x = gen();
        for (auto& x : Q) x = gen();
        if (Q[0] == 0) Q[0] = 1;
        const int K = 60;
        // F = P / Q: F_k = (P_k - Σ_{j>=1} Q_j F_{k-j}) / Q_0
        std::vector<mint> F(K + 1);
        for (int k = 0; k <= K; k++) {
            mint s = k < np ? P[k] : mint(0);
            for (int j = 1; j < nq && j <= k; j++) s -= Q[j] * F[k - j];
            F[k] = s / Q[0];
        }
        for (int k = 0; k <= K; k++) check(bostan_mori(P, Q, k) == F[k], "bostan_mori");
    }
    // linear_recurrence_kth: 漸化式で順に計算したものと比べる
    for (int rep = 0; rep < 200 && ok; rep++) {
        int d = rng() % 6;
        std::vector<mint> a(d), c(d);
        for (auto& x : a) x = gen();
        for (auto& x : c) x = gen();
        std::vector<mint> seq = a;
        for (int i = d; i < 300; i++) {
            mint s = 0;
            for (int j = 1; j <= d; j++) s += c[j - 1] * seq[i - j];
            seq.push_back(s);
        }
        for (int k = 0; k < 300; k++) check(linear_recurrence_kth(a, c, k) == (k < static_cast<int>(seq.size()) ? seq[k] : mint(0)), "linear_recurrence_kth");
        // berlekamp_massey: 2d 項以上あれば、長さ d 以下の漸化式で数列全体を再現できる
        auto r = berlekamp_massey(std::vector<mint>(seq.begin(), seq.begin() + 2 * d + rng() % 5));
        check(static_cast<int>(r.size()) <= d, "berlekamp_massey の長さ");
        if (!r.empty()) {
            std::vector<mint> init(seq.begin(), seq.begin() + r.size());
            for (int k = 0; k < 100; k++) check(linear_recurrence_kth(init, r, k) == seq[k], "berlekamp_massey で復元");
        } else {
            for (int k = 0; k < 100; k++) check(seq[k] == 0, "berlekamp_massey 長さ 0 は全部 0");
        }
    }
    // 大きい k: 行列累乗と同じフィボナッチ数
    std::vector<mint> fib_a = {0, 1}, fib_c = {1, 1};
    long long k = 1000000000000000000LL;
    // 2x2 行列の累乗で F_k を求める
    mint m00 = 1, m01 = 1, m10 = 1, m11 = 0, r00 = 1, r01 = 0, r10 = 0, r11 = 1;
    for (long long e = k; e > 0; e >>= 1) {
        if (e & 1) {
            mint t00 = r00 * m00 + r01 * m10, t01 = r00 * m01 + r01 * m11, t10 = r10 * m00 + r11 * m10, t11 = r10 * m01 + r11 * m11;
            r00 = t00, r01 = t01, r10 = t10, r11 = t11;
        }
        mint t00 = m00 * m00 + m01 * m10, t01 = m00 * m01 + m01 * m11, t10 = m10 * m00 + m11 * m10, t11 = m10 * m01 + m11 * m11;
        m00 = t00, m01 = t01, m10 = t10, m11 = t11;
    }
    check(linear_recurrence_kth(fib_a, fib_c, k) == r01, "フィボナッチ 10^18");
}

// 長い P, Q で、static_modint<998244353> (NTT した値のまま進める経路) と dynamic_modint (畳み込みを繰り返す経路) を比べる
void test_ntt_path(std::mt19937_64& rng) {
    using sm = static_modint<998244353>;
    using dm = dynamic_modint<0>;
    dm::set_mod(998244353);
    const std::vector<int> sizes = {61, 63, 64, 65, 100, 127, 128, 129, 255, 256, 257, 1000};
    for (int rep = 0; rep < 60 && ok; rep++) {
        int np = rep % 3 == 0 ? rng() % 1100 : sizes[rng() % sizes.size()] - rng() % 2;
        int nq = sizes[rng() % sizes.size()];
        if (rep % 4 == 0) std::swap(np, nq);
        nq = std::max(nq, 1);
        std::vector<sm> Ps(np), Qs(nq);
        std::vector<dm> Pd(np), Qd(nq);
        for (int i = 0; i < np; i++) {
            unsigned int v = rng() % 998244353;
            Ps[i] = v, Pd[i] = v;
        }
        for (int i = 0; i < nq; i++) {
            unsigned int v = rng() % 998244353;
            if (i == 0 && v == 0) v = 1;
            Qs[i] = v, Qd[i] = v;
        }
        std::vector<long long> ks = {0, 1, 2, 3, np, nq, np + nq, 1000000000000000000LL, static_cast<long long>(rng() >> 4)};
        for (int t = 0; t < 5; t++) ks.push_back(rng() % 5000);
        for (long long k : ks) check(bostan_mori(Ps, Qs, k).val() == bostan_mori(Pd, Qd, k).val(), "bostan_mori の NTT の経路");
    }
    // linear_recurrence_kth も、d が大きいときに漸化式で順に計算したものと比べる
    for (int d : {61, 64, 65, 200}) {
        std::vector<sm> a(d), c(d);
        for (auto& x : a) x = rng() % 998244353;
        for (auto& x : c) x = rng() % 998244353;
        std::vector<sm> seq = a;
        for (int i = d; i < 3000; i++) {
            sm s = 0;
            for (int j = 1; j <= d; j++) s += c[j - 1] * seq[i - j];
            seq.push_back(s);
        }
        for (int k = 0; k < 3000; k += 7) check(linear_recurrence_kth(a, c, k) == seq[k], "linear_recurrence_kth の NTT の経路");
    }
}

int main() {
    std::mt19937_64 rng(314);
    test_mod<static_modint<998244353>>(rng);
    test_mod<static_modint<1000000007>>(rng);
    test_ntt_path(rng);

    // berlekamp_massey の最短性: mod 3 で長さ d の漸化式を全部試し、成り立つ最短の d と比べる
    using m3 = static_modint<3>;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 8;
        std::vector<m3> a(n);
        for (auto& x : a) x = rng() % 3;
        int best = -1;
        for (int d = 0; best == -1; d++) {
            int total = 1;
            for (int j = 0; j < d; j++) total *= 3;
            for (int code = 0; code < total && best == -1; code++) {
                std::vector<int> c(d);
                for (int j = 0, t = code; j < d; j++, t /= 3) c[j] = t % 3;
                bool good = true;
                for (int i = d; i < n && good; i++) {
                    m3 s = 0;
                    for (int j = 1; j <= d; j++) s += m3(c[j - 1]) * a[i - j];
                    good = s == a[i];
                }
                if (good) best = d;
            }
        }
        auto r = berlekamp_massey(a);
        check(static_cast<int>(r.size()) == best, "berlekamp_massey の最短性");
        for (int i = r.size(); i < n; i++) {
            m3 s = 0;
            for (size_t j = 1; j <= r.size(); j++) s += r[j - 1] * a[i - j];
            check(s == a[i], "berlekamp_massey が成り立つ");
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
