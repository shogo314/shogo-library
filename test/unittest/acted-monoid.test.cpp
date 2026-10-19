#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// acted-monoid.hpp の作用素付きモノイドを LazySegTree に乗せて、愚直な実装とランダムに比較する
// LazySegTree の get / set / seg[k] / 1 点の apply / size / os << seg も確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/algebra/acted-monoid.hpp"

#include <algorithm>
#include <iostream>
#include <limits>
#include <optional>
#include <random>
#include <sstream>
#include <vector>

#include "../../src/data_structures/imos.hpp"
#include "../../src/data_structures/lazy-segtree.hpp"
#include "../../src/math/modint.hpp"

using mint = static_modint<998244353>;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

// value: 各要素の値 (愚直な表現 V) から S を作る
// fold: V の区間 [l, r) から期待される S を計算する
// act: V に作用素 F を適用する
// eq: S どうしの比較
template <typename A, typename V, typename GenV, typename GenF, typename ToS, typename Fold, typename Act, typename Eq>
void test_lazy(GenV gen_v, GenF gen_f, ToS to_s, Fold fold, Act act, Eq eq, std::mt19937_64& rng, const char* name) {
    using S = typename A::S;
    for (int rep = 0; rep < 200 && ok; rep++) {
        int n = rng() % 20 + 1;
        std::vector<V> a(n);
        for (auto& x : a) x = gen_v();
        std::vector<S> init(n);
        for (int i = 0; i < n; i++) init[i] = to_s(a[i], i);
        LazySegTree<A> seg(init);
        check(seg.size() == n, name);
        for (int q = 0; q < 60 && ok; q++) {
            int t = rng() % 6;
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            int k = rng() % n;
            if (t == 0) {
                auto f = gen_f();
                seg.apply(l, r, f);
                for (int i = l; i < r; i++) a[i] = act(f, a[i]);
            } else if (t == 1) {
                auto f = gen_f();
                seg.apply(k, f);
                a[k] = act(f, a[k]);
            } else if (t == 2) {
                V x = gen_v();
                if (rng() % 2)
                    seg.set(k, to_s(x, k));
                else
                    seg[k] = to_s(x, k);
                a[k] = x;
            } else if (t == 3) {
                check(eq(seg.get(k), fold(a, k, k + 1)), name);
                S s = seg[k];
                check(eq(s, fold(a, k, k + 1)), name);
            } else {
                check(eq(seg.prod(l, r), fold(a, l, r)), name);
            }
        }
        check(eq(seg.all_prod(), fold(a, 0, n)), name);
    }
}

int main() {
    std::mt19937_64 rng(314);
    auto small = [&] { return (long long)(rng() % 21) - 10; };

    // MulSum: 区間乗算・区間和
    test_lazy<acted_monoid::MulSum<mint>, mint>(
        [&] { return mint(rng() % 1000); }, [&] { return mint(rng() % 999 + 1); },
        [](mint x, int) { return x; },
        [](const std::vector<mint>& a, int l, int r) { mint s = 0; for (int i = l; i < r; i++) s += a[i]; return s; },
        [](mint f, mint x) { return f * x; },
        [](mint x, mint y) { return x == y; }, rng, "MulSum");

    // MulSum の inv: Imos (作用素が群である必要がある) で区間乗算・1 点取得
    for (int rep = 0; rep < 200 && ok; rep++) {
        int n = rng() % 20 + 1;
        std::vector<mint> a(n);
        for (auto& x : a) x = rng() % 1000;
        Imos<acted_monoid::MulSum<mint>> imos(a);
        for (int q = 0; q < 30; q++) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            mint f = rng() % 999 + 1;
            imos.apply(l, r, f);
            for (int i = l; i < r; i++) a[i] *= f;
        }
        for (int i = 0; i < n; i++) check(imos.get(i) == a[i], "MulSum::inv (Imos)");
    }
    check(acted_monoid::MulSum<mint>::inv(mint(3)) * mint(3) == mint(1), "MulSum::inv");

    // AddMax: 区間加算・区間最大値
    auto max_fold = [](const std::vector<long long>& a, int l, int r) {
        long long m = std::numeric_limits<long long>::lowest();
        for (int i = l; i < r; i++) m = std::max(m, a[i]);
        return m;
    };
    auto min_fold = [](const std::vector<long long>& a, int l, int r) {
        long long m = std::numeric_limits<long long>::max();
        for (int i = l; i < r; i++) m = std::min(m, a[i]);
        return m;
    };
    auto same = [](long long x, long long y) { return x == y; };
    auto id_s = [](long long x, int) { return x; };
    test_lazy<acted_monoid::AddMax<long long>, long long>(
        small, small, id_s, max_fold, [](long long f, long long x) { return x + f; }, same, rng, "AddMax");

    // UpdateMax: 区間代入・区間最大値
    test_lazy<acted_monoid::UpdateMax<long long>, long long>(
        small, [&] { return std::optional<long long>(small()); }, id_s, max_fold,
        [](std::optional<long long> f, long long x) { return f ? *f : x; }, same, rng, "UpdateMax");

    // ChminMin: 区間 chmin・区間最小値
    test_lazy<acted_monoid::ChminMin<long long>, long long>(
        small, small, id_s, min_fold, [](long long f, long long x) { return std::min(f, x); }, same, rng, "ChminMin");

    // ChmaxMax: 区間 chmax・区間最大値
    test_lazy<acted_monoid::ChmaxMax<long long>, long long>(
        small, small, id_s, max_fold, [](long long f, long long x) { return std::max(f, x); }, same, rng, "ChmaxMax");

    // ClampMin / ClampMax / ClampMinMax: 区間 clamp・区間最小値 / 最大値 / 組
    {
        auto gen_clamp = [&] {
            long long lb = small(), ub = small();
            if (lb > ub) std::swap(lb, ub);
            if (rng() % 4 == 0) lb = std::numeric_limits<long long>::lowest();
            if (rng() % 4 == 0) ub = std::numeric_limits<long long>::max();
            return Clamp<long long>{lb, ub};
        };
        auto clamp_act = [](const Clamp<long long>& f, long long x) { return std::min(std::max(x, f.lb), f.ub); };
        test_lazy<acted_monoid::ClampMin<long long>, long long>(small, gen_clamp, id_s, min_fold, clamp_act, same, rng, "ClampMin");
        test_lazy<acted_monoid::ClampMax<long long>, long long>(small, gen_clamp, id_s, max_fold, clamp_act, same, rng, "ClampMax");
        using P = std::pair<long long, long long>;
        test_lazy<acted_monoid::ClampMinMax<long long>, long long>(
            small, gen_clamp, [](long long x, int) { return P{x, x}; },
            [&](const std::vector<long long>& a, int l, int r) { return P{min_fold(a, l, r), max_fold(a, l, r)}; },
            clamp_act, [](const P& x, const P& y) { return x == y; }, rng, "ClampMinMax");
    }

    // ClampAddMin / ClampAddMax / ClampAddMinMax: 区間 加算と clamp・区間最小値 / 最大値 / 組
    {
        auto gen_clamp_add = [&] {
            long long lb = small(), ub = small();
            if (lb > ub) std::swap(lb, ub);
            if (rng() % 3 == 0) lb = std::numeric_limits<long long>::lowest();
            if (rng() % 3 == 0) ub = std::numeric_limits<long long>::max();
            return ClampAdd<long long>{lb, ub, small()};
        };
        auto clamp_add_act = [](const ClampAdd<long long>& f, long long x) { return std::min(std::max(x + f.add, f.lb), f.ub); };
        test_lazy<acted_monoid::ClampAddMin<long long>, long long>(small, gen_clamp_add, id_s, min_fold, clamp_add_act, same, rng, "ClampAddMin");
        test_lazy<acted_monoid::ClampAddMax<long long>, long long>(small, gen_clamp_add, id_s, max_fold, clamp_add_act, same, rng, "ClampAddMax");
        using P = std::pair<long long, long long>;
        test_lazy<acted_monoid::ClampAddMinMax<long long>, long long>(
            small, gen_clamp_add, [](long long x, int) { return P{x, x}; },
            [&](const std::vector<long long>& a, int l, int r) { return P{min_fold(a, l, r), max_fold(a, l, r)}; },
            clamp_add_act, [](const P& x, const P& y) { return x == y; }, rng, "ClampAddMinMax");
        // apply に {} を含む波括弧で作用素を渡せる
        LazySegTree<acted_monoid::ClampAddMin<long long>> seg(std::vector<long long>{3, 1, 4, 1, 5});
        seg.apply(0, 5, {{}, {}, 2});  // 加算
        seg.apply(0, 5, {4, {}});      // chmax
        seg.apply(1, 3, {{}, 5});      // chmin
        check(seg.prod(0, 5) == 4 && seg.prod(2, 3) == 5 && seg.get(4) == 7, "ClampAddMin {} の作用素");
    }

    // AddMaxWith: 区間加算・区間最大値とその位置 (同じ値なら左側)
    {
        using P = std::pair<long long, int>;
        // 位置は値と一緒に保持するので、愚直な表現も {値, 位置} にする
        test_lazy<acted_monoid::AddMaxWith<long long>, P>(
            [&] { return P(small(), -1); }, small,
            [](P x, int i) { return P(x.first, i); },
            [](const std::vector<P>& a, int l, int r) {
                P best(std::numeric_limits<long long>::lowest(), 0);
                for (int i = l; i < r; i++)
                    if (a[i].first > best.first) best = P(a[i].first, i);
                return best;
            },
            [](long long f, P x) { return P(x.first + f, x.second); },
            [](P x, P y) { return x.first == y.first && (x.first == std::numeric_limits<long long>::lowest() || x.second == y.second); },
            rng, "AddMaxWith");
    }

    // AddPowerSum: 区間加算・区間の 0 乗和から K 乗和
    {
        constexpr int K = 3;
        using A = acted_monoid::AddPowerSum<mint, K>;
        test_lazy<A, mint>(
            [&] { return mint(rng() % 100); }, [&] { return mint(rng() % 100); },
            [](mint x, int) { return A::S(x); },
            [](const std::vector<mint>& a, int l, int r) {
                // 期待値の i 乗和を愚直に計算して S に詰める
                A::S s;
                for (int i = l; i < r; i++) {
                    mint p = 1;
                    for (int j = 0; j <= K; j++) {
                        s.val[j] += p;
                        p *= a[i];
                    }
                }
                return s;
            },
            [](mint f, mint x) { return x + f; },
            [](const A::S& x, const A::S& y) {
                for (int i = 0; i <= K; i++)
                    if (x[i] != y[i]) return false;
                return true;
            },
            rng, "AddPowerSum");
        // S(x) と operator[] で i 乗和を取り出せる
        A::S s = A::op(A::S(mint(2)), A::S(mint(3)));
        check(s[0] == 2 && s[1] == 5 && s[2] == 13 && s[3] == 35, "AddPowerSum::S");
        check(A::e()[0] == 0, "AddPowerSum::e");
        check(A::id() == 0 && A::composition(2, 3) == 5, "AddPowerSum::composition");
    }

    // Rearrange: 成分の並べ替え (全単射とは限らない写像)・成分ごとの積
    auto test_rearrange = [&](auto m, auto n, const char* name) {
        using M = decltype(m);
        constexpr std::size_t N = decltype(n)::value;
        using A = acted_monoid::Rearrange<M, N>;
        using V = typename A::S;
        using F = typename A::F;
        test_lazy<A, V>(
            [&] {
                V x;
                for (auto& y : x) y = small();
                return x;
            },
            [&] {
                F f;
                for (auto& y : f) y = rng() % N;
                return f;
            },
            [](V x, int) { return x; },
            [](const std::vector<V>& a, int l, int r) {
                V s;
                for (std::size_t j = 0; j < N; j++) {
                    s[j] = M::e();
                    for (int i = l; i < r; i++) s[j] = M::op(s[j], a[i][j]);
                }
                return s;
            },
            [](F f, V x) {
                V y;
                for (std::size_t j = 0; j < N; j++) y[j] = x[f[j]];
                return y;
            },
            [](const V& x, const V& y) { return x == y; }, rng, name);
    };
    test_rearrange(monoid::Sum<long long>(), std::integral_constant<std::size_t, 3>(), "Rearrange<Sum, 3>");
    test_rearrange(monoid::Min<long long>(), std::integral_constant<std::size_t, 4>(), "Rearrange<Min, 4>");
    {
        using A = acted_monoid::Rearrange<monoid::Sum<long long>, 3>;
        // swap(0, 1) の後に swap(1, 2) を適用すると、成分 0 には元の成分 1、成分 1 には元の成分 2 が来る
        A::F f = A::composition(A::swap(1, 2), A::swap(0, 1));
        check(A::mapping(f, A::S{10, 20, 30}) == A::S{20, 30, 10}, "Rearrange::composition");
        // {1, 1, 2} は成分 0 を成分 1 で上書きする
        check(A::mapping({1, 1, 2}, A::S{10, 20, 30}) == A::S{20, 20, 30}, "Rearrange 上書き");
        check(A::mapping(A::id(), A::S{10, 20, 30}) == A::S{10, 20, 30}, "Rearrange::id");
    }

    // LazySegTree の出力
    {
        LazySegTree<acted_monoid::AddMax<long long>> seg(std::vector<long long>{3, 1, 4});
        seg.apply(0, 2, 10);
        std::ostringstream os;
        os << seg;
        check(os.str() == "13 11 4", "LazySegTree <<");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
