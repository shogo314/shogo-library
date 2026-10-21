#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// polynomial_roots を、小さい素数の法ではすべての値を代入する愚直な実装と比べる
// 998244353 では、決めた根 (重根や 0 も) が見つかり、見つかった値がすべて根であることを確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/math/polynomial-roots.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "../../src/math/fps.hpp"
#include "../../src/math/modint.hpp"

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

template <typename mint>
mint eval(const FPS<mint>& f, mint x) {
    mint r = 0;
    for (int i = static_cast<int>(f.size()) - 1; i >= 0; i--) r = r * x + f[i];
    return r;
}

template <typename mint>
void test_small(std::mt19937_64& rng) {
    const int p = mint::mod();
    for (int rep = 0; rep < 1000 && ok; rep++) {
        // ランダムな多項式と、根を決めて掛けた多項式
        FPS<mint> f;
        if (rep % 2 == 0) {
            f.resize(rng() % 8 + 1);
            for (auto& c : f) c = rng() % p;
        } else {
            f = {mint(rng() % (p - 1) + 1)};
            int k = rng() % 6;
            for (int i = 0; i < k; i++) f = f * FPS<mint>{-mint(rng() % p), 1};
        }
        std::vector<mint> expect;
        bool zero = true;
        for (auto c : f) zero &= c == 0;
        if (!zero) {
            FPS<mint> g = f;
            g.normalize();
            if (g.size() > 1)
                for (int x = 0; x < p; x++)
                    if (eval(f, mint(x)) == 0) expect.push_back(mint(x));
        }
        check(polynomial_roots(f) == expect, "小さい法");
    }
}

int main() {
    std::mt19937_64 rng(314);
    test_small<static_modint<13>>(rng);
    test_small<static_modint<101>>(rng);

    using mint = static_modint<998244353>;
    for (int rep = 0; rep < 300 && ok; rep++) {
        std::set<unsigned> want;
        FPS<mint> f = {1};
        int k = rng() % 12;
        for (int i = 0; i < k; i++) {
            mint r = rng() % 3 == 0 ? mint(rng() % 3) : mint(rng() % mint::mod());  // 0 や重根も出す
            want.insert(r.val());
            int e = rng() % 3 + 1;
            for (int t = 0; t < e; t++) f = f * FPS<mint>{-r, 1};
        }
        // 根を持つかもしれない別の因子も掛ける
        FPS<mint> q(rng() % 5 + 1);
        for (auto& c : q) c = rng() % mint::mod();
        if (q.back() == 0) q.back() = 1;
        f = f * q;
        auto roots = polynomial_roots(f);
        std::set<unsigned> got;
        for (auto r : roots) {
            check(eval(f, r) == 0, "見つかった値は根");
            got.insert(r.val());
        }
        check(got.size() == roots.size(), "相異なる");
        for (auto r : want) check(got.count(r), "決めた根が見つかる");
        check(std::is_sorted(roots.begin(), roots.end(), [](mint a, mint b) { return a.val() < b.val(); }), "昇順");
    }
    // 定数・0 の多項式は根なし (空)
    check(polynomial_roots(FPS<mint>{5}).empty() && polynomial_roots(FPS<mint>{0, 0}).empty(), "定数");
    if (ok) std::cout << "Hello World" << std::endl;
}
