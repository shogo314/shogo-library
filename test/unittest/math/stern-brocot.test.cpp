#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// stern-brocot.hpp の関数を、木を 1 歩ずつたどる愚直な実装や全探索とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/stern-brocot.hpp"

#include <iostream>
#include <limits>
#include <optional>
#include <random>
#include <string>
#include <utility>
#include <vector>

using Q = Rational<long long>;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

// 根 1/1 から x まで 1 歩ずつたどった道 ("RRL" など) と、そのときの子孫の範囲
struct NaiveWalk {
    std::string path;
    long long lo_num = 0, lo_den = 1, hi_num = 1, hi_den = 0;
};
NaiveWalk naive_walk(const Q& x) {
    NaiveWalk w;
    while (true) {
        Q m(w.lo_num + w.hi_num, w.lo_den + w.hi_den);
        if (m == x) return w;
        if (m < x) {
            w.path += 'R';
            w.lo_num = m.num(), w.lo_den = m.den();
        } else {
            w.path += 'L';
            w.hi_num = m.num(), w.hi_den = m.den();
        }
    }
}
Q naive_decode(const std::string& path) {
    long long a = 0, b = 1, c = 1, d = 0;
    for (char ch : path) {
        if (ch == 'R') {
            a += c, b += d;
        } else {
            c += a, d += b;
        }
    }
    return Q(a + c, b + d);
}
std::string expand(const std::vector<std::pair<char, long long>>& path) {
    std::string s;
    for (auto [c, n] : path) s += std::string(n, c);
    return s;
}

// 分母を 1 から順に試して、区間に入る分数のうち最も単純なもの
Q naive_simplest(const Q& lo, const Q& hi, bool include_lo, bool include_hi) {
    auto in = [&](const Q& x) { return (lo < x || (include_lo && lo == x)) && (x < hi || (include_hi && x == hi)); };
    for (long long q = 1;; q++) {
        // 分子の絶対値が小さい順に試す
        for (long long a = 0; a <= 100 * q; a++) {
            for (long long p : {a, -a}) {
                Q x(p, q);
                if (x.den() == q && in(x)) return x;
            }
        }
    }
}

int main() {
    std::mt19937_64 rng(314);
    auto gen_pos = [&](long long m) { return Q(static_cast<long long>(rng() % m) + 1, static_cast<long long>(rng() % m) + 1); };
    auto gen = [&](long long m) { return Q(static_cast<long long>(rng() % (2 * m + 1)) - m, static_cast<long long>(rng() % m) + 1); };

    // 連分数: 展開して戻すと元に戻る。最後の項は 2 以上 (項が 1 つなら何でもよい)
    for (int rep = 0; rep < 3000 && ok; rep++) {
        Q x = rep < 1500 ? gen(30) : gen(1000000000000000000LL);
        auto a = stern_brocot::continued_fraction(x);
        check(a[0] == x.floor(), "continued_fraction a0");
        for (int i = 1; i < static_cast<int>(a.size()); i++) check(a[i] >= 1, "continued_fraction ai >= 1");
        if (a.size() >= 2) check(a.back() >= 2, "continued_fraction an >= 2");
        check(stern_brocot::from_continued_fraction(a) == x, "from_continued_fraction");
    }
    check((stern_brocot::continued_fraction(Q(415, 93)) == std::vector<long long>{4, 2, 6, 7}), "continued_fraction 415/93");
    check((stern_brocot::continued_fraction(Q(-7, 3)) == std::vector<long long>{-3, 1, 2}), "continued_fraction -7/3");
    // 最後の項が 1 の表し方 [0; 1, 1] = 1/2 も受け付ける
    check((stern_brocot::from_continued_fraction(std::vector<long long>{0, 1, 1}) == Q(1, 2)), "from_continued_fraction [0; 1, 1]");

    // encode_path / decode_path / depth / range: 1 歩ずつたどる愚直な実装と比べる
    for (int rep = 0; rep < 3000 && ok; rep++) {
        Q x = gen_pos(60);
        auto path = stern_brocot::encode_path(x);
        NaiveWalk w = naive_walk(x);
        check(expand(path) == w.path, "encode_path");
        for (int i = 0; i + 1 < static_cast<int>(path.size()); i++) check(path[i].first != path[i + 1].first && path[i].second > 0, "encode_path は連長圧縮");
        check(stern_brocot::decode_path(path) == x, "decode_path");
        check(stern_brocot::depth(x) == static_cast<long long>(w.path.size()), "depth");
        auto [lo, hi] = stern_brocot::range(x);
        check(lo == std::make_pair(w.lo_num, w.lo_den) && hi == std::make_pair(w.hi_num, w.hi_den), "range");
    }
    check(stern_brocot::encode_path(Q(1)).empty(), "encode_path 1/1");
    check((stern_brocot::range(Q(1)) == std::pair<std::pair<long long, long long>, std::pair<long long, long long>>{{0, 1}, {1, 0}}), "range 1/1");
    // 同じ文字が続く道や回数 0 も受け付ける
    check((stern_brocot::decode_path(std::vector<std::pair<char, long long>>{{'R', 1}, {'R', 0}, {'R', 1}, {'L', 2}}) == naive_decode("RRLL")), "decode_path 続く文字");

    // lca / ancestor: 道の文字列の共通部分・先頭部分と比べる
    for (int rep = 0; rep < 3000 && ok; rep++) {
        Q x = gen_pos(40), y = gen_pos(40);
        std::string px = naive_walk(x).path, py = naive_walk(y).path;
        size_t k = 0;
        while (k < px.size() && k < py.size() && px[k] == py[k]) k++;
        check(stern_brocot::lca(x, y) == naive_decode(px.substr(0, k)), "lca");
        for (long long d = 0; d <= static_cast<long long>(px.size()) + 2; d++) {
            auto a = stern_brocot::ancestor(x, d);
            if (d <= static_cast<long long>(px.size())) {
                check(a && *a == naive_decode(px.substr(0, d)), "ancestor");
            } else {
                check(!a, "ancestor なし");
            }
        }
    }

    // simplest_between: 開区間・閉区間・半開区間、負の区間や 0 をまたぐ区間で全探索と比べる
    for (int rep = 0; rep < 3000 && ok; rep++) {
        Q lo = gen(12), hi = gen(12);
        if (hi < lo) std::swap(lo, hi);
        for (int mask = 0; mask < 4; mask++) {
            bool il = mask & 1, ih = mask >> 1 & 1;
            if (lo == hi && !(il && ih)) continue;
            check(stern_brocot::simplest_between(lo, hi, il, ih) == naive_simplest(lo, hi, il, ih), "simplest_between");
        }
    }

    // best_approximation: 分母 n 以下の分数を全探索して、x 以下で最大・x 以上で最小のものと比べる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        Q x = gen(50);
        long long n = static_cast<long long>(rng() % 20) + 1;
        Q lower(std::numeric_limits<long long>::lowest() / 4), upper(std::numeric_limits<long long>::max() / 4);
        for (long long q = 1; q <= n; q++) {
            // x を挟む分母 q の分数は floor(x q) / q と ceil(x q) / q
            Q f((x * Q(q)).floor(), q), c((x * Q(q)).ceil(), q);
            if (lower < f) lower = f;
            if (c < upper) upper = c;
        }
        auto [l, u] = stern_brocot::best_approximation(x, n);
        check(l == lower && u == upper, "best_approximation");
    }

    // 値が 10^18 程度でもあふれない (UBSan で確かめる)
    {
        const long long big = 1000000000000000000LL;
        check(stern_brocot::simplest_between(Q(big - 1, big), Q(1)) == Q(big, big + 1), "simplest_between 10^18");
        check(stern_brocot::simplest_between(Q(1, big), Q(1, big - 1)) == Q(2, 2 * big - 1), "simplest_between 1/10^18");
        check(stern_brocot::simplest_between(Q(big - 1), Q(big)) == Q(2 * big - 1, 2), "simplest_between 大きい整数");
        for (int rep = 0; rep < 20000 && ok; rep++) {
            Q lo = gen_pos(big), hi = gen_pos(big);
            if (lo == hi) continue;
            if (hi < lo) std::swap(lo, hi);
            Q s = stern_brocot::simplest_between(lo, hi);
            check(lo < s && s < hi, "simplest_between 大きい値で区間に入る");
            // s より分母が小さい分数は区間に入らない: 分母が s.den() - 1 以下で lo に最も近い上側の分数が hi 以上
            // (lo 自身の分母が s.den() - 1 以下だと上側の分数が lo になってしまうので、そのときは確かめない)
            if (s.den() >= 2 && lo.den() > s.den() - 1) {
                auto [l, u] = stern_brocot::best_approximation(lo, s.den() - 1);
                check(!(lo < u && u < hi) && !(lo < l && l < hi), "simplest_between 大きい値で最小");
            }
        }
        // 深さが 10^18 程度の頂点
        Q x(big, 1);
        check(stern_brocot::depth(x) == big - 1, "depth 10^18");
        check(*stern_brocot::ancestor(x, big - 2) == Q(big - 1, 1), "ancestor 10^18");
        check(!stern_brocot::ancestor(x, big), "ancestor 10^18 なし");
        check(stern_brocot::lca(Q(big, 1), Q(big - 1, 2)) == Q(big / 2, 1), "lca 10^18");
    }

    // binary_search: 分母・分子の上限内の分数を全探索して、pred が true の最大と false の最小を求める愚直な実装と比べる
    {
        using P = std::pair<long long, long long>;
        auto naive = [&](long long max_den, long long max_num, auto pred) {
            Q lo(0), hi(0);
            bool has_hi = false;
            for (long long q = 1; q <= max_den; q++) {
                for (long long p = 0; p <= max_num; p++) {
                    Q x(p, q);
                    if (pred(x)) {
                        if (lo < x) lo = x;
                    } else if (!has_hi || x < hi) {
                        hi = x, has_hi = true;
                    }
                }
            }
            return std::make_pair(P{lo.num(), lo.den()}, has_hi ? P{hi.num(), hi.den()} : P{1, 0});
        };
        for (int rep = 0; rep < 3000 && ok; rep++) {
            long long max_den = rng() % 12 + 1, max_num = rng() % 12;
            Q x = gen_pos(15);
            bool strict = rng() % 2;
            auto pred = [&](const Q& y) { return strict ? y < x || y == Q(0) : y <= x; };
            auto expect = naive(max_den, max_num, pred);
            check(stern_brocot::binary_search(max_den, pred, std::optional<long long>(max_num)) == expect, "binary_search 分子の上限あり");
            // 分子の上限なし: 分子が十分大きい範囲の全探索と同じ
            check(stern_brocot::binary_search(max_den, pred) == naive(max_den, 16 * max_den, pred), "binary_search 分子の上限なし");
        }
        // pred がずっと true なら上側は +∞
        auto all = stern_brocot::binary_search(5LL, [](const Q&) { return true; }, std::optional<long long>(7));
        check(all.first == P{7, 1} && all.second == P{1, 0}, "binary_search +∞");
        // √2 の両側: 分母 10^9 以下で最も近い分数。pred を呼ぶ回数も数える
        const long long n = 1000000000;
        int calls = 0;
        auto [lo, hi] = stern_brocot::binary_search(n, [&](const Q& y) {
            calls++;
            return y.num() * y.num() <= 2 * y.den() * y.den();
        });
        Q l(lo.first, lo.second), h(hi.first, hi.second);
        // 隣り合う分数 (間に分母 n 以下の分数がない) で、√2 を挟む
        check(lo.second <= n && hi.second <= n && lo.second + hi.second > n, "binary_search √2 分母");
        check(hi.first * lo.second - lo.first * hi.second == 1, "binary_search √2 隣り合う");
        check(l * l < Q(2) && Q(2) < h * h, "binary_search √2 挟む");
        check(calls <= 200, "binary_search √2 呼ぶ回数");
        // best_approximation と一致する
        for (int rep = 0; rep < 1000 && ok; rep++) {
            Q x = gen_pos(1000000);
            long long m = rng() % 1000 + 1;
            auto [bl, bu] = stern_brocot::best_approximation(x, m);
            auto [sl, su] = stern_brocot::binary_search(m, [&](const Q& y) { return y <= x; });
            // x 自身の分母が m 以下なら、下側は x、上側は x の次の分数になる
            check(Q(sl.first, sl.second) == bl && (bl == bu || Q(su.first, su.second) == bu), "binary_search と best_approximation");
        }
    }

    // ABC408 G の入出力例: A/B < p/q < C/D となる最小の q
    {
        long long in[5][4] = {{3, 2, 2, 1}, {5, 2, 8, 3}, {1, 2, 2, 1}, {60, 191, 11, 35}, {40, 191, 71, 226}};
        long long out[5] = {3, 5, 1, 226, 4};
        for (int i = 0; i < 5; i++) check(stern_brocot::simplest_between(Q(in[i][0], in[i][1]), Q(in[i][2], in[i][3])).den() == out[i], "ABC408 G");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
