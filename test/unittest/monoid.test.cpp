#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// monoid.hpp / group.hpp のモノイド・群と SegTree の細かい機能を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/algebra/monoid.hpp"

#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "../../src/algebra/group.hpp"
#include "../../src/data_structures/potentialized-unionfind.hpp"
#include "../../src/data_structures/segtree.hpp"

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

// SegTree<M> を、配列と演算 op で愚直に計算した結果とランダムな操作列で比べる
// size・const な operator[]・all_prod・os << seg も確かめる
template <typename M, typename Op, typename Gen>
void test_segtree(Op op, typename M::S e, Gen gen, std::mt19937_64& rng, const char* name) {
    using S = typename M::S;
    for (int rep = 0; rep < 200 && ok; rep++) {
        int n = rng() % 20 + 1;
        std::vector<S> a(n);
        for (auto& x : a) x = gen();
        SegTree<M> seg(a);
        check(seg.size() == n, name);
        for (int q = 0; q < 50 && ok; q++) {
            int t = rng() % 3;
            if (t == 0) {
                int k = rng() % n;
                S x = gen();
                seg.set(k, x);
                a[k] = x;
            } else if (t == 1) {
                int k = rng() % n;
                S x = gen();
                seg.apply(k, x);
                a[k] = op(a[k], x);
            } else {
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) std::swap(l, r);
                S expect = e;
                for (int i = l; i < r; i++) expect = op(expect, a[i]);
                check(seg.prod(l, r) == expect, name);
            }
        }
        S all = e;
        for (int i = 0; i < n; i++) all = op(all, a[i]);
        check(seg.all_prod() == all, name);
        const SegTree<M>& cseg = seg;
        std::ostringstream os, expect;
        for (int i = 0; i < n; i++) {
            check(cseg[i] == a[i], name);
            if (i != 0) expect << ' ';
            expect << a[i];
        }
        os << cseg;
        check(os.str() == expect.str(), name);
    }
}

int main() {
    std::mt19937_64 rng(314);

    // And / Or: 単位元はそれぞれ全ビット 1 と 0
    check(monoid::And<unsigned>::e() == ~0u, "And::e");
    check(monoid::Or<unsigned>::e() == 0u, "Or::e");
    auto gen_bits = [&] { return (unsigned)(rng() % 64); };
    test_segtree<monoid::And<unsigned>>([](unsigned a, unsigned b) { return a & b; }, ~0u, gen_bits, rng, "And");
    test_segtree<monoid::Or<unsigned>>([](unsigned a, unsigned b) { return a | b; }, 0u, gen_bits, rng, "Or");

    // Parenthesis: 区間が正しい括弧列かを is_valid で判定する
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 16 + 1;
        std::string s(n, '(');
        for (char& c : s) c = rng() % 2 ? '(' : ')';
        std::vector<monoid::Parenthesis::S> v(s.begin(), s.end());
        SegTree<monoid::Parenthesis> seg(v);
        for (int l = 0; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                int depth = 0, min_depth = 0;
                for (int i = l; i < r; i++) {
                    depth += s[i] == '(' ? 1 : -1;
                    min_depth = std::min(min_depth, depth);
                }
                auto p = seg.prod(l, r);
                check(p.is_valid() == (depth == 0 && min_depth == 0), "Parenthesis::is_valid");
                check(p.close == -min_depth && p.open == depth - min_depth, "Parenthesis::op");
            }
        }
    }

    // Affine: ==, !=, 出力
    {
        Affine<long long> f{2, 3}, g{2, 3}, h{2, 4}, id;
        check(f == g && !(f != g), "Affine ==");
        check(f != h && !(f == h), "Affine !=");
        check(id == Affine<long long>{1, 0}, "Affine default");
        std::ostringstream os;
        os << f;
        check(os.str() == "2 3", "Affine <<");
        // Composite で合成した結果が関数の合成 a∘b と一致する。Reverse は b∘a
        for (int rep = 0; rep < 1000 && ok; rep++) {
            Affine<long long> a{(long long)(rng() % 7) - 3, (long long)(rng() % 7) - 3};
            Affine<long long> b{(long long)(rng() % 7) - 3, (long long)(rng() % 7) - 3};
            long long x = (long long)(rng() % 7) - 3;
            auto c = monoid::Composite<long long>::op(a, b);
            check(c(x) == a(b(x)), "Composite op");
            check(c == Affine<long long>{a.a * b.a, a.a * b.b + a.b}, "Affine == after op");
            auto d = monoid::Reverse<monoid::Composite<long long>>().op(a, b);
            check(d(x) == b(a(x)), "Reverse<Composite> op");
        }
    }

    // group::Xor: inv は自分自身。PotentializedUnionFind に乗せて xor のポテンシャルと比べる
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<int> pot(n);
        for (int& p : pot) p = rng() % 1024;
        std::vector<int> comp(n);
        for (int i = 0; i < n; i++) comp[i] = i;
        PotentializedUnionFind<group::Xor<int>> uf(n);
        for (int q = 0; q < 30 && ok; q++) {
            int a = rng() % n, b = rng() % n;
            if (rng() % 2) {
                uf.merge(a, b, pot[a] ^ pot[b]);
                int ca = comp[a], cb = comp[b];
                for (int& c : comp)
                    if (c == cb) c = ca;
            } else {
                check(uf.same(a, b) == (comp[a] == comp[b]), "group::Xor same");
                if (comp[a] == comp[b]) check(uf.diff(a, b) == (pot[a] ^ pot[b]), "group::Xor diff");
            }
        }
        int x = rng() % 1024;
        check(group::Xor<int>::inv(x) == x, "group::Xor::inv");
    }

    // PrefixSumMax / PrefixSumMin / SuffixSumMax / SuffixSumMin / MaxSubarraySum: 空を含む prefix・suffix・連続部分列の和
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<long long> a(n);
        for (auto& x : a) x = (long long)(rng() % 21) - 10;
        SegTree<monoid::PrefixSumMax<long long>> pmax(std::vector<monoid::PrefixSumMax<long long>::S>(a.begin(), a.end()));
        SegTree<monoid::PrefixSumMin<long long>> pmin(std::vector<monoid::PrefixSumMin<long long>::S>(a.begin(), a.end()));
        SegTree<monoid::SuffixSumMax<long long>> smax(std::vector<monoid::SuffixSumMax<long long>::S>(a.begin(), a.end()));
        SegTree<monoid::SuffixSumMin<long long>> smin(std::vector<monoid::SuffixSumMin<long long>::S>(a.begin(), a.end()));
        SegTree<monoid::MaxSubarraySum<long long>> msub(std::vector<monoid::MaxSubarraySum<long long>::S>(a.begin(), a.end()));
        for (int q = 0; q < 10 && ok; q++) {
            int k = rng() % n;
            a[k] = (long long)(rng() % 21) - 10;
            pmax.set(k, a[k]), pmin.set(k, a[k]), smax.set(k, a[k]), smin.set(k, a[k]), msub.set(k, a[k]);
            for (int l = 0; l <= n; l++) {
                for (int r = l; r <= n; r++) {
                    long long sum = 0, pre_max = 0, pre_min = 0, suf_max = 0, suf_min = 0, best = 0;
                    for (int i = l; i < r; i++) {
                        sum += a[i];
                        pre_max = std::max(pre_max, sum), pre_min = std::min(pre_min, sum);
                        long long s = 0;
                        for (int j = i; j < r; j++) {
                            s += a[j];
                            best = std::max(best, s);
                        }
                    }
                    long long s = 0;
                    for (int i = r - 1; i >= l; i--) {
                        s += a[i];
                        suf_max = std::max(suf_max, s), suf_min = std::min(suf_min, s);
                    }
                    check(pmax.prod(l, r) == monoid::PrefixSumMax<long long>::S(sum, pre_max), "PrefixSumMax");
                    check(pmin.prod(l, r) == monoid::PrefixSumMin<long long>::S(sum, pre_min), "PrefixSumMin");
                    check(smax.prod(l, r) == monoid::SuffixSumMax<long long>::S(sum, suf_max), "SuffixSumMax");
                    check(smin.prod(l, r) == monoid::SuffixSumMin<long long>::S(sum, suf_min), "SuffixSumMin");
                    check(msub.prod(l, r) == monoid::MaxSubarraySum<long long>::S(sum, pre_max, suf_max, best), "MaxSubarraySum");
                }
            }
            // max_right: l から始めて和が初めて正になる位置
            int l = rng() % (n + 1);
            long long sum = 0;
            int expect = n;
            for (int i = l; i < n; i++) {
                sum += a[i];
                if (sum > 0) {
                    expect = i;
                    break;
                }
            }
            check(pmax.max_right(l, [](const auto& s) { return s.max <= 0; }) == expect, "PrefixSumMax max_right");
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
