#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// monoid::Mapping (写像の合成) と group::Permutation (置換の合成) を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "../../src/algebra/group.hpp"
#include "../../src/data_structures/potentialized-unionfind.hpp"
#include "../../src/data_structures/segtree.hpp"

// std::array の == は C++17 では constexpr でないので、要素ごとに比べる
template <std::size_t N>
constexpr bool equal(const std::array<int, N>& a, const std::array<int, N>& b) {
    for (std::size_t i = 0; i < N; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}
// constexpr で使えること: op(f, g) = f∘g。(1, 1, 0) を適用してから (0, 2, 1) を適用すると (2, 2, 0)
static_assert(equal(monoid::Mapping<3>::op({0, 2, 1}, {1, 1, 0}), {2, 2, 0}));
static_assert(equal(monoid::Reverse<monoid::Mapping<3>>().op({1, 1, 0}, {0, 2, 1}), {2, 2, 0}));
static_assert(equal(monoid::Mapping<3>::e(), {0, 1, 2}));
static_assert(equal(group::Permutation<3>::inv({1, 2, 0}), {2, 0, 1}));
static_assert(equal(monoid::Mapping<3>::swap(1, 2), {0, 2, 1}));
static_assert(equal(monoid::Mapping<4>::swap(3, 0), {3, 1, 2, 0}));
static_assert(equal(monoid::Mapping<3>::swap(1, 1), {0, 1, 2}));
static_assert(equal(group::Permutation<3>::swap(0, 1), {1, 0, 2}));

template <std::size_t N>
std::array<int, N> random_mapping(std::mt19937& rng, bool bijective) {
    std::array<int, N> f;
    if (bijective) {
        std::iota(f.begin(), f.end(), 0);
        std::shuffle(f.begin(), f.end(), rng);
    } else {
        for (auto& v : f) v = rng() % N;
    }
    return f;
}

// SegTree<monoid::Mapping<N>> の区間積が、区間の写像を右から順に適用した結果と一致するか
template <std::size_t N>
bool check_segtree(std::mt19937& rng) {
    using S = std::array<int, N>;
    for (int rep = 0; rep < 200; rep++) {
        int n = rng() % 20 + 1;
        std::vector<S> a(n);
        for (auto& f : a) f = random_mapping<N>(rng, rng() % 2);
        SegTree<monoid::Mapping<N>> seg(a);
        for (int q = 0; q < 50; q++) {
            if (rng() % 2) {
                int i = rng() % n;
                a[i] = random_mapping<N>(rng, rng() % 2);
                seg.set(i, a[i]);
            } else {
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) std::swap(l, r);
                S got = seg.prod(l, r);
                for (int x = 0; x < (int)N; x++) {
                    int y = x;
                    for (int i = r - 1; i >= l; i--) y = a[i][y];
                    if (got[x] != y) return false;
                }
            }
        }
    }
    return true;
}

// group::Permutation の逆置換と、非可換な群として PotentializedUnionFind に乗せたときの diff
template <std::size_t N>
bool check_permutation(std::mt19937& rng) {
    using G = group::Permutation<N>;
    using S = std::array<int, N>;
    for (int rep = 0; rep < 1000; rep++) {
        S f = random_mapping<N>(rng, true);
        if (G::op(f, G::inv(f)) != G::e() || G::op(G::inv(f), f) != G::e()) return false;
    }
    for (int rep = 0; rep < 200; rep++) {
        int n = rng() % 10 + 1;
        // 各頂点に置換 p[v] を決め、それと矛盾しない情報だけを merge する
        std::vector<S> p(n);
        for (auto& f : p) f = random_mapping<N>(rng, true);
        PotentializedUnionFind<G> uf(n);
        std::vector<int> root(n);
        std::iota(root.begin(), root.end(), 0);
        for (int q = 0; q < 30; q++) {
            int a = rng() % n, b = rng() % n;
            // diff(a, b) は p[a]^{-1}・p[b] (op の順で p[a] の逆元の後に p[b])
            S w = G::op(G::inv(p[a]), p[b]);
            uf.merge(a, b, w);
            int ra = root[a], rb = root[b];
            for (int& r : root)
                if (r == rb) r = ra;
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    bool same = root[u] == root[v];
                    if (uf.same(u, v) != same) return false;
                    if (same && uf.diff(u, v) != G::op(G::inv(p[u]), p[v])) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    ok = ok && check_segtree<1>(rng);
    ok = ok && check_segtree<3>(rng);
    ok = ok && check_segtree<5>(rng);
    ok = ok && check_permutation<3>(rng);
    ok = ok && check_permutation<5>(rng);

    // 例: (0, 2, 1) を区間に並べる。偶数個なら恒等写像、奇数個なら (0, 2, 1)
    SegTree<monoid::Mapping<3>> seg(4);
    for (int i = 0; i < 4; i++) seg.set(i, monoid::Mapping<3>::swap(1, 2));
    ok = ok && seg.prod(0, 4) == std::array<int, 3>{0, 1, 2};
    ok = ok && seg.prod(1, 4) == std::array<int, 3>{0, 2, 1};

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
