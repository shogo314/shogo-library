#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// RBST を std::vector による愚直な実装とランダムな操作列で比べる
// 積の順序が効く (可換でない) モノイドも乗せて、区間反転で逆順の積が正しく保たれるかを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/rbst.hpp"

#include <algorithm>
#include <iostream>
#include <optional>
#include <random>
#include <sstream>
#include <vector>

#include "../../src/algebra/acted-monoid.hpp"
#include "../../src/algebra/monoid.hpp"
#include "../../src/math/modint.hpp"

using mint = static_modint<998244353>;

// グローバル変数の木 (プログラムの終了時のデストラクタで、頂点の配列が先に破棄されていないことを確かめる)
RBST<acted_monoid::AddSum<long long>> global_tree;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

// gen_s / gen_f: 値・作用素を作る。act(f, x): 1 要素への作用 (作用素付きでなければ使わない)
template <typename M, typename GenS, typename GenF, typename Act>
void test_random(GenS gen_s, GenF gen_f, Act act, std::mt19937_64& rng, const char* name) {
    using S = typename M::S;
    M m;
    auto fold = [&](const std::vector<S>& a, long long l, long long r) {
        S s = m.e();
        for (long long i = l; i < r; i++) s = m.op(s, a[i]);
        return s;
    };
    for (int rep = 0; rep < 100 && ok; rep++) {
        int n = rng() % 12;
        std::vector<S> a(n);
        for (auto& x : a) x = gen_s();
        RBST<M> t(a);
        for (int q = 0; q < 200 && ok; q++) {
            long long sz = a.size();
            long long l = rng() % (sz + 1), r = rng() % (sz + 1);
            if (l > r) std::swap(l, r);
            int type = rng() % 12;
            if (type == 0) {
                long long k = rng() % (sz + 1);
                S x = gen_s();
                t.insert(k, x);
                a.insert(a.begin() + k, x);
            } else if (type == 1 && sz > 0) {
                long long k = rng() % sz;
                check(t.erase(k) == a[k], name);
                a.erase(a.begin() + k);
            } else if (type == 2 && sz > 0) {
                long long k = rng() % sz;
                S x = gen_s();
                if (rng() % 2)
                    t.set(k, x);
                else
                    t[k] = x;
                a[k] = x;
            } else if (type == 3 && sz > 0) {
                long long k = rng() % sz;
                S x = t[k];
                check(t.get(k) == a[k] && x == a[k], name);
            } else if (type == 4) {
                t.reverse(l, r);
                std::reverse(a.begin() + l, a.begin() + r);
            } else if (type == 5) {
                if constexpr (RBST<M>::acted) {
                    auto f = gen_f();
                    t.apply(l, r, f);
                    for (long long i = l; i < r; i++) a[i] = act(f, a[i]);
                }
            } else if (type == 6 && sz > 0) {
                if constexpr (RBST<M>::acted) {
                    long long k = rng() % sz;
                    auto f = gen_f();
                    t.apply(k, f);
                    a[k] = act(f, a[k]);
                }
            } else if (type == 7) {
                // 切り取った後ろ側を操作してからつなげ直す
                long long k = rng() % (sz + 1);
                RBST<M> u = t.split(k);
                check(t.size() == k && u.size() == sz - k, name);
                check(t.all_prod() == fold(a, 0, k) && u.all_prod() == fold(a, k, sz), name);
                if (u.size() >= 2) {
                    u.reverse(0, u.size());
                    std::reverse(a.begin() + k, a.end());
                }
                t.merge(std::move(u));
                check(u.empty(), name);
            } else if (type == 8) {
                // 複製を変えても元は変わらない
                RBST<M> c = t;
                if (c.size() > 0) c.set(0, gen_s());
                c.push_back(gen_s());
                check(c.size() == sz + 1, name);
                check(t.to_vector() == a, name);
                if (rng() % 2) {
                    t = c;  // 複製の代入
                    a = c.to_vector();
                }
            } else if (type == 9) {
                S x = gen_s();
                if (rng() % 2) {
                    t.push_front(x);
                    a.insert(a.begin(), x);
                } else {
                    t.push_back(x);
                    a.push_back(x);
                }
            } else if (type == 10 && sz > 0) {
                if (rng() % 2) {
                    check(t.pop_front() == a.front(), name);
                    a.erase(a.begin());
                } else {
                    check(t.pop_back() == a.back(), name);
                    a.pop_back();
                }
            } else {
                check(t.prod(l, r) == fold(a, l, r), name);
            }
            check(t.size() == static_cast<long long>(a.size()) && t.all_prod() == fold(a, 0, a.size()), name);
        }
        check(t.to_vector() == a, name);
    }
}

int main() {
    std::mt19937_64 rng(314);
    auto small = [&] { return static_cast<long long>(rng() % 21) - 10; };
    auto gen_affine = [&] { return Affine<mint>{mint(rng() % 5 + 1), mint(rng() % 5)}; };

    // 区間加算・区間和 (mapping が区間の長さを使う)
    test_random<acted_monoid::AddSum<long long>>(small, small, [](long long f, long long x) { return x + f; }, rng, "AddSum");
    // 区間代入・1 次関数の合成 (可換でない)
    test_random<acted_monoid::UpdateComposite<mint>>(
        gen_affine, [&] { return std::optional<Affine<mint>>(gen_affine()); },
        [](const std::optional<Affine<mint>>& f, const Affine<mint>& x) { return f ? *f : x; }, rng, "UpdateComposite");
    // 作用素なし・1 次関数の合成 (可換でない)
    test_random<monoid::Composite<mint>>(gen_affine, [] { return 0; }, [](int, const Affine<mint>& x) { return x; }, rng, "Composite");
    // 区間 加算と clamp・区間最小値と最大値 (mapping が区間の長さを使わない)
    {
        using P = std::pair<long long, long long>;
        auto gen_p = [&] { long long x = small(); return P{x, x}; };
        auto gen_f = [&] {
            long long lb = small(), ub = small();
            if (lb > ub) std::swap(lb, ub);
            return ClampAdd<long long>{lb, ub, small()};
        };
        test_random<acted_monoid::ClampAddMinMax<long long>>(gen_p, gen_f, [](const ClampAdd<long long>& f, const P& x) { return P{f(x.first), f(x.second)}; }, rng, "ClampAddMinMax");
    }

    // max_right / min_left: 負でない値の列で、和が w 以下となる最大の r と最小の l
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 15;
        std::vector<long long> a(n);
        for (auto& x : a) x = rng() % 5;
        RBST<acted_monoid::AddSum<long long>> t(a);
        t.reverse(0, n);
        std::reverse(a.begin(), a.end());
        for (int q = 0; q < 30; q++) {
            long long l = rng() % (n + 1), w = rng() % 15;
            long long r = l, s = 0;
            while (r < n && s + a[r] <= w) s += a[r++];
            check(t.max_right(l, [&](long long x) { return x <= w; }) == r, "max_right");
            long long rr = rng() % (n + 1), ll = rr;
            s = 0;
            while (ll > 0 && s + a[ll - 1] <= w) s += a[--ll];
            check(t.min_left(rr, [&](long long x) { return x <= w; }) == ll, "min_left");
        }
        check(t.to_vector() == a, "max_right / min_left は列を変えない");
    }

    // 長さ n で作る、出力、大きい列での速さの目安
    {
        RBST<monoid::Max<int>> t(3);
        std::ostringstream os;
        os << t;
        check(t.size() == 3 && t.get(1) == monoid::Max<int>::e(), "RBST(n)");
        RBST<acted_monoid::AddSum<long long>> u(std::vector<long long>{1, 2, 3});
        u.reverse(0, 3);
        std::ostringstream os2;
        os2 << u;
        check(os2.str() == "3 2 1", "os <<");
        RBST<acted_monoid::AddSum<long long>> big;
        for (int i = 0; i < 200000; i++) big.insert(rng() % (big.size() + 1), i);
        for (int i = 0; i < 200000; i++) big.reverse(rng() % 1000, 100000 + rng() % 100000);
        check(big.all_prod() == 199999LL * 200000 / 2, "大きい列");
    }

    for (int i = 0; i < 10; i++) global_tree.push_back(i);
    check(global_tree.all_prod() == 45, "グローバル変数の木");

    if (ok) std::cout << "Hello World" << std::endl;
}
