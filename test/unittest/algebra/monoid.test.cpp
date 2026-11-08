#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// monoid.hpp / group.hpp のモノイド・群と SegTree の細かい機能を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/algebra/monoid.hpp"

#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <limits>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "../../../src/algebra/group.hpp"
#include "../../../src/data_structures/dual-segtree.hpp"
#include "../../../src/data_structures/fenwick-tree.hpp"
#include "../../../src/data_structures/imos.hpp"
#include "../../../src/data_structures/lazy-segtree.hpp"
#include "../../../src/data_structures/link-cut-tree.hpp"
#include "../../../src/data_structures/monoid-unionfind.hpp"
#include "../../../src/data_structures/persistent-lazy-segtree.hpp"
#include "../../../src/data_structures/persistent-segtree.hpp"
#include "../../../src/data_structures/potentialized-unionfind.hpp"
#include "../../../src/data_structures/rbst.hpp"
#include "../../../src/data_structures/segtree-beats.hpp"
#include "../../../src/data_structures/segtree.hpp"
#include "../../../src/data_structures/sortable-segtree.hpp"
#include "../../../src/data_structures/sparse-table.hpp"

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

struct ExplicitSum {
    struct S {
        long long value;
        S() : value(0) {}
        explicit S(long long x) : value(x) {}
    };
    static S op(const S& a, const S& b) { return S(a.value + b.value); }
    static S e() { return S(0); }
};

struct ExplicitAddSum : ExplicitSum {
    using F = long long;
    static S mapping(F f, const S& x, long long len) { return S(x.value + f * len); }
    static F composition(F f, F g) { return f + g; }
    static F id() { return 0; }
    static F inv(F f) { return -f; }
};

struct ExplicitGroup : ExplicitSum {
    static S inv(const S& x) { return S(-x.value); }
};

struct ExplicitMin : ExplicitSum {
    static S op(const S& a, const S& b) { return S(std::min(a.value, b.value)); }
    static S e() { return S(std::numeric_limits<long long>::max()); }
};

struct ExplicitBeats : ExplicitAddSum {
    static std::pair<bool, S> mapping(F f, const S& x, long long len) { return {false, ExplicitAddSum::mapping(f, x, len)}; }
};

// begin は一度だけ。イテレータの後置 ++ は値を返さず、終端の型も異なる。
struct SizedInputRange {
    int values[3] = {2, -5, 4};
    int pos = 0;
    bool begun = false;
    struct Sentinel {};
    struct Iterator {
        using value_type = int;
        using difference_type = long long;
        using iterator_category = std::input_iterator_tag;
        SizedInputRange* range;
        int operator*() const { return range->values[range->pos]; }
        Iterator& operator++() {
            ++range->pos;
            return *this;
        }
        void operator++(int) { ++*this; }
        friend bool operator==(Iterator it, Sentinel) { return it.range->pos == 3; }
        friend bool operator!=(Iterator it, Sentinel s) { return !(it == s); }
        friend bool operator==(Sentinel s, Iterator it) { return it == s; }
        friend bool operator!=(Sentinel s, Iterator it) { return !(it == s); }
    };
    Iterator begin() {
        check(!begun, "sized input range is traversed once");
        begun = true;
        return {this};
    }
    Sentinel end() const { return {}; }
    long long size() const { return 3; }
};

template <template <typename> class Tree, typename M>
void test_converting_tree(M m) {
    auto verify_range = [&](auto&& r) {
        Tree tree(std::forward<decltype(r)>(r), m);
        check(tree.size() == 3 && tree.get(0).value == 2 && tree.get(1).value == -5 && tree.get(2).value == 4,
              "tree family sized range / CTAD");
    };
    int raw[] = {2, -5, 4};
    const std::array<int, 3> arr = {2, -5, 4};
    verify_range(raw);
    verify_range(arr);
    verify_range(std::list<int>{2, -5, 4});
    verify_range(std::deque<int>{2, -5, 4});
    verify_range(SizedInputRange{});
    Tree<M> empty_array(std::array<int, 0>{});
    check(empty_array.size() == 0, "tree family empty array");
    static_assert(!std::is_constructible_v<Tree<M>, std::forward_list<int>&>);
    static_assert(!std::is_constructible_v<Tree<M>, std::array<std::string, 3>&>);
#if __cplusplus >= 202002L
    verify_range(std::views::iota(0, 3) | std::views::transform([&](int i) { return raw[i]; }));
#endif
    static_assert(std::is_constructible_v<Tree<M>, const std::vector<int>&, M>);
    static_assert(!std::is_constructible_v<Tree<M>, const std::vector<std::string>&, M>);
    Tree seg(std::vector<int>{2, -5, 4}, m);
    check(seg.size() == 3 && seg.get(0).value == 2 && seg.get(1).value == -5 && seg.get(2).value == 4,
          "segtree family explicit conversion / CTAD");
    Tree<M> empty(std::vector<int>{});
    check(empty.size() == 0, "segtree family conversion empty");
    Tree<M> same(std::vector<typename M::S>{typename M::S(7)});
    check(same.get(0).value == 7, "segtree family vector<S>");
    Tree<M> list({typename M::S(8), typename M::S(9)});
    check(list.get(1).value == 9, "segtree family initializer list");
}

template <class R>
void test_segtree_range(R&& r) {
    SegTree seg(std::forward<R>(r), ExplicitSum{});
    check(seg.size() == 3 && seg.prod(0, 3).value == 1 && seg.prod(1, 3).value == -1, "SegTree sized range / CTAD");
    seg.set(1, ExplicitSum::S(3));
    check(seg.all_prod().value == 9, "SegTree sized range update");
}

int main() {
    {
        int a[] = {2, -5, 4};
        const std::array<int, 3> b = {2, -5, 4};
        test_segtree_range(a);
        test_segtree_range(b);
        test_segtree_range(std::list<int>{2, -5, 4});
        test_segtree_range(std::deque<int>{2, -5, 4});
        SegTree<ExplicitSum> empty(std::array<int, 0>{});
        check(empty.size() == 0 && empty.all_prod().value == 0, "SegTree empty range");
        SegTree braces({ExplicitSum::S(2), ExplicitSum::S(-5), ExplicitSum::S(4)}, ExplicitSum{});
        check(braces.all_prod().value == 1, "SegTree initializer list / CTAD");
        SegTree<ExplicitSum> original(a);
        auto copied = original;
        auto moved = std::move(copied);
        check(moved.all_prod().value == 1 && original.all_prod().value == 1, "SegTree copy / move");
        SegTree sized(3LL, ExplicitSum{});
        check(sized.size() == 3 && sized.all_prod().value == 0, "SegTree size / CTAD");
        static_assert(!std::is_constructible_v<SegTree<ExplicitSum>, std::forward_list<int>&>);
        static_assert(!std::is_constructible_v<SegTree<ExplicitSum>, std::array<std::string, 3>&>);
#if __cplusplus >= 202002L
        test_segtree_range(std::views::all(a));
        test_segtree_range(std::views::iota(0, 3) | std::views::transform([&](int i) { return a[i]; }));
        SegTree view(a | std::views::take(2), ExplicitSum{});
        check(view.size() == 2 && view.all_prod().value == -3, "SegTree partial view");
#endif
    }

    test_converting_tree<SegTree>(ExplicitSum{});
    test_converting_tree<RBST>(ExplicitSum{});
    test_converting_tree<RBST>(ExplicitAddSum{});
    test_converting_tree<FenwickTree>(ExplicitGroup{});
    test_converting_tree<SparseTable>(ExplicitMin{});
    test_converting_tree<LinkCutTree>(ExplicitSum{});
    test_converting_tree<SubtreeLinkCutTree>(ExplicitGroup{});
    {
        auto verify = [](auto&& r) {
            MonoidUnionFind uf(std::forward<decltype(r)>(r), ExplicitSum{});
            uf.merge(0, 1);
            check(uf.prod(0).value == -3 && uf.prod(2).value == 4, "MonoidUnionFind sized range / CTAD");
        };
        int raw[] = {2, -5, 4};
        verify(raw);
        verify(std::list<int>{2, -5, 4});
        verify(SizedInputRange{});
        std::vector<ExplicitSum::S> owned{ExplicitSum::S(7)};
        const auto* ptr = owned.data();
        MonoidUnionFind moved(std::move(owned), ExplicitSum{});
        check(&moved.prod(0) == ptr, "MonoidUnionFind moves vector storage");
        Imos from_range(SizedInputRange{}, ExplicitAddSum{});
        from_range.apply(0, 2, 3);
        check(from_range.get(0).value == 5 && from_range.get(1).value == -2 && from_range.get(2).value == 4,
              "Imos sized input range / CTAD");
        Imos from_list(std::list<int>{2, -5, 4}, ExplicitAddSum{});
        check(from_list.get(1).value == -5, "Imos list");
        Imos<ExplicitAddSum> empty_range(std::array<int, 0>{});
        static_assert(!std::is_constructible_v<Imos<ExplicitAddSum>, std::forward_list<int>&>);
        static_assert(!std::is_constructible_v<MonoidUnionFind<ExplicitSum>, const std::vector<std::string>&>);
        MonoidUnionFind uf(std::vector<int>{2, -5, 4}, ExplicitSum{});
        uf.merge(0, 1);
        check(uf.prod(0).value == -3 && uf.prod(2).value == 4, "MonoidUnionFind conversion / CTAD");
        MonoidUnionFind<ExplicitSum> empty(std::vector<int>{});
        check(empty.groups().empty(), "MonoidUnionFind conversion empty");
        Imos imos(std::vector<int>{2, -5, 4}, ExplicitAddSum{});
        imos.apply(0, 2, 3);
        check(imos.get(0).value == 5 && imos.get(1).value == -2 && imos.get(2).value == 4, "Imos conversion / CTAD");
        Imos<ExplicitAddSum> empty_imos(std::vector<int>{});
        static_assert(!std::is_constructible_v<Imos<ExplicitAddSum>, const std::vector<std::string>&>);
    }

    test_converting_tree<LazySegTree>(ExplicitAddSum{});
    test_converting_tree<DualSegTree>(ExplicitAddSum{});
    test_converting_tree<PersistentSegTree>(ExplicitSum{});
    test_converting_tree<PersistentLazySegTree>(ExplicitAddSum{});
    test_converting_tree<SegTreeBeats>(ExplicitBeats{});
    {
        auto verify = [](auto&& keys, auto&& values) {
            SortableSegTree tree(std::forward<decltype(keys)>(keys), std::forward<decltype(values)>(values), 3, ExplicitSum{});
            tree.sort(0, 3);
            check(tree.prod(0, 1).value == -5 && tree.prod(0, 3).value == 1, "SortableSegTree sized ranges / sort / CTAD");
        };
        int keys[] = {2, 0, 1};
        verify(keys, std::list<int>{2, -5, 4});
        verify(std::list<int>{2, 0, 1}, SizedInputRange{});
        SortableSegTree braces({2, 0, 1}, {ExplicitSum::S(2), ExplicitSum::S(-5), ExplicitSum::S(4)}, 3, ExplicitSum{});
        check(braces.prod(0, 3).value == 1, "SortableSegTree initializer lists / CTAD");
        SortableSegTree sorted(std::vector<long long>{2, 0, 1}, std::vector<int>{2, -5, 4}, 3, ExplicitSum{});
        sorted.sort(0, 3);
        check(sorted.prod(0, 1).value == -5 && sorted.prod(0, 3).value == 1, "SortableSegTree conversion / CTAD / sort");
        SortableSegTree<ExplicitSum> empty(std::vector<long long>{}, std::vector<int>{}, 1);
        check(empty.size() == 0, "SortableSegTree conversion empty");
    }

    {
        static_assert(std::is_constructible_v<SegTree<ExplicitSum>, const std::vector<int>&>);
        static_assert(!std::is_constructible_v<SegTree<ExplicitSum>, const std::vector<std::string>&>);
        SegTree seg(std::vector<int>{2, -5, 4}, ExplicitSum{});
        check(seg.prod(0, 3).value == 1 && seg.prod(1, 3).value == -1, "SegTree explicit conversion / CTAD");
        SegTree<ExplicitSum> empty(std::vector<int>{});
        check(empty.size() == 0 && empty.all_prod().value == 0, "SegTree conversion empty");
        SegTree<monoid::Sum<long long>> ordinary({1, 2, 3});
        check(ordinary.all_prod() == 6, "SegTree initializer list");
        SegTree<monoid::Sum<long long>> widened(std::vector<int>{1, 2, 3});
        check(widened.all_prod() == 6, "SegTree arithmetic conversion");
    }

    std::mt19937_64 rng(314);

    // And / Or: 単位元はそれぞれ全ビット 1 と 0
    check(monoid::And<unsigned>::e() == ~0u, "And::e");
    check(monoid::Or<unsigned>::e() == 0u, "Or::e");
    auto gen_bits = [&] { return static_cast<unsigned>(rng() % 64); };
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
            Affine<long long> a{static_cast<long long>(rng() % 7) - 3, static_cast<long long>(rng() % 7) - 3};
            Affine<long long> b{static_cast<long long>(rng() % 7) - 3, static_cast<long long>(rng() % 7) - 3};
            long long x = static_cast<long long>(rng() % 7) - 3;
            auto c = monoid::Composite<long long>::op(a, b);
            check(c(x) == a(b(x)), "Composite op");
            check(c == Affine<long long>{a.a * b.a, a.a * b.b + a.b}, "Affine == after op");
            auto d = monoid::Reverse<monoid::Composite<long long>>().op(a, b);
            check(d(x) == b(a(x)), "Reverse<Composite> op");
        }
    }

    // Clamp: ==, !=, 入出力, 既定値は恒等写像
    {
        Clamp<long long> f{2, 5}, g{2, 5}, h{2, 6}, id;
        check(f == g && !(f != g), "Clamp ==");
        check(f != h && !(f == h), "Clamp !=");
        check(id(std::numeric_limits<long long>::lowest()) == std::numeric_limits<long long>::lowest() && id(std::numeric_limits<long long>::max()) == std::numeric_limits<long long>::max(), "Clamp default");
        check(f(1) == 2 && f(3) == 3 && f(9) == 5, "Clamp ()");
        // {} を渡すと下限・上限なし。1 つの値からは暗黙に変換しない
        check((Clamp<long long>{0, {}} == Clamp<long long>{0, std::numeric_limits<long long>::max()}), "Clamp {lb, {}}");
        check((Clamp<long long>{{}, 0} == Clamp<long long>{std::numeric_limits<long long>::lowest(), 0}), "Clamp {{}, ub}");
        check((Clamp<long long>{{}, {}} == Clamp<long long>{}), "Clamp {{}, {}}");
        static_assert(!std::is_convertible_v<long long, Clamp<long long>>);
        static_assert(std::is_trivially_copyable_v<Clamp<long long>>);
        static_assert(Clamp<int>{0, {}}(-5) == 0);
        std::ostringstream os;
        os << f;
        check(os.str() == "2 5", "Clamp <<");
        std::istringstream is("-3 4");
        is >> f;
        check(f == Clamp<long long>{-3, 4}, "Clamp >>");
        // ClampComposite で合成した結果が関数の合成 a∘b と一致する。Reverse は b∘a
        auto gen_clamp = [&] {
            long long lb = static_cast<long long>(rng() % 11) - 5, ub = static_cast<long long>(rng() % 11) - 5;
            if (lb > ub) std::swap(lb, ub);
            if (rng() % 4 == 0) lb = std::numeric_limits<long long>::lowest();
            if (rng() % 4 == 0) ub = std::numeric_limits<long long>::max();
            return Clamp<long long>{lb, ub};
        };
        for (int rep = 0; rep < 1000 && ok; rep++) {
            auto a = gen_clamp(), b = gen_clamp();
            auto c = monoid::ClampComposite<long long>::op(a, b);
            auto d = monoid::Reverse<monoid::ClampComposite<long long>>().op(a, b);
            check(c.lb <= c.ub, "ClampComposite lb <= ub");
            check(monoid::ClampComposite<long long>::op(a, monoid::ClampComposite<long long>::e()) == a, "ClampComposite e");
            check(monoid::ClampComposite<long long>::op(monoid::ClampComposite<long long>::e(), a) == a, "ClampComposite e");
            for (long long x = -7; x <= 7; x++) {
                check(c(x) == a(b(x)), "ClampComposite op");
                check(d(x) == b(a(x)), "Reverse<ClampComposite> op");
            }
        }
        // SegTree に乗せて、区間の関数を右から順に適用した結果と比べる
        test_segtree<monoid::ClampComposite<long long>>(
            [](const Clamp<long long>& a, const Clamp<long long>& b) { return monoid::ClampComposite<long long>::op(a, b); },
            Clamp<long long>{}, gen_clamp, rng, "ClampComposite");
    }

    // ClampAdd: ==, !=, 入出力, 既定値は恒等写像
    {
        constexpr long long lowest = std::numeric_limits<long long>::lowest(), highest = std::numeric_limits<long long>::max();
        ClampAdd<long long> f{2, 5, 1}, g{2, 5, 1}, h{2, 5, 0}, id;
        check(f == g && !(f != g), "ClampAdd ==");
        check(f != h && !(f == h), "ClampAdd !=");
        check(id == ClampAdd<long long>{lowest, highest, 0} && id(lowest) == lowest && id(highest) == highest, "ClampAdd default");
        check(f(0) == 2 && f(2) == 3 && f(9) == 5, "ClampAdd ()");
        // {} を渡すと下限・上限なし。add は省略すると 0。1 つの値からは暗黙に変換しない
        check((ClampAdd<long long>{{}, {}, 3} == ClampAdd<long long>{lowest, highest, 3}), "ClampAdd {{}, {}, add}");
        check((ClampAdd<long long>{{}, 5} == ClampAdd<long long>{lowest, 5, 0}), "ClampAdd {{}, ub}");
        check((ClampAdd<long long>{5, {}} == ClampAdd<long long>{5, highest, 0}), "ClampAdd {lb, {}}");
        static_assert(!std::is_convertible_v<long long, ClampAdd<long long>>);
        static_assert(std::is_trivially_copyable_v<ClampAdd<long long>>);
        static_assert(ClampAdd<int>{{}, 10, 3}(9) == 10);
        std::ostringstream os;
        os << f;
        check(os.str() == "2 5 1", "ClampAdd <<");
        std::istringstream is("-3 4 -1");
        is >> f;
        check(f == ClampAdd<long long>{-3, 4, -1}, "ClampAdd >>");
        // ClampAddComposite で合成した結果が関数の合成 a∘b と一致する。Reverse は b∘a
        // 下限・上限なし (型の最小値・最大値) に足してもあふれない (UBSan で確かめる)
        auto gen_clamp_add = [&] {
            long long lb = static_cast<long long>(rng() % 11) - 5, ub = static_cast<long long>(rng() % 11) - 5;
            if (lb > ub) std::swap(lb, ub);
            if (rng() % 3 == 0) lb = lowest;
            if (rng() % 3 == 0) ub = highest;
            return ClampAdd<long long>{lb, ub, static_cast<long long>(rng() % 7) - 3};
        };
        for (int rep = 0; rep < 1000 && ok; rep++) {
            auto a = gen_clamp_add(), b = gen_clamp_add();
            auto c = monoid::ClampAddComposite<long long>::op(a, b);
            auto d = monoid::Reverse<monoid::ClampAddComposite<long long>>().op(a, b);
            check(c.lb <= c.ub, "ClampAddComposite lb <= ub");
            check(monoid::ClampAddComposite<long long>::op(a, monoid::ClampAddComposite<long long>::e()) == a, "ClampAddComposite e");
            check(monoid::ClampAddComposite<long long>::op(monoid::ClampAddComposite<long long>::e(), a) == a, "ClampAddComposite e");
            for (long long x = -9; x <= 9; x++) {
                check(c(x) == a(b(x)), "ClampAddComposite op");
                check(d(x) == b(a(x)), "Reverse<ClampAddComposite> op");
            }
        }
        // SegTree に乗せる (加算が積み重なってもあふれない範囲で)
        test_segtree<monoid::ClampAddComposite<long long>>(
            [](const ClampAdd<long long>& a, const ClampAdd<long long>& b) { return monoid::ClampAddComposite<long long>::op(a, b); },
            ClampAdd<long long>{}, gen_clamp_add, rng, "ClampAddComposite");
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

    // PrefixSumMax / PrefixSumMin / PrefixSumMinMax / SuffixSumMax / SuffixSumMin / MaxSubarraySum: 空を含む prefix・suffix・連続部分列の和
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 12 + 1;
        std::vector<long long> a(n);
        for (auto& x : a) x = static_cast<long long>(rng() % 21) - 10;
        SegTree<monoid::PrefixSumMax<long long>> pmax(std::vector<monoid::PrefixSumMax<long long>::S>(a.begin(), a.end()));
        SegTree<monoid::PrefixSumMin<long long>> pmin(std::vector<monoid::PrefixSumMin<long long>::S>(a.begin(), a.end()));
        using PM = monoid::PrefixSumMinMax<>;
        SegTree<PM> pminmax(a);
        SegTree<monoid::SuffixSumMax<long long>> smax(std::vector<monoid::SuffixSumMax<long long>::S>(a.begin(), a.end()));
        SegTree<monoid::SuffixSumMin<long long>> smin(std::vector<monoid::SuffixSumMin<long long>::S>(a.begin(), a.end()));
        SegTree<monoid::MaxSubarraySum<long long>> msub(std::vector<monoid::MaxSubarraySum<long long>::S>(a.begin(), a.end()));
        for (int q = 0; q < 10 && ok; q++) {
            int k = rng() % n;
            a[k] = static_cast<long long>(rng() % 21) - 10;
            pminmax.set(k, a[k]);
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
                    check(pminmax.prod(l, r) == PM::S(sum, pre_min, pre_max), "PrefixSumMinMax");
                    check(PM::op(PM::e(), pminmax.prod(l, r)) == pminmax.prod(l, r) &&
                              PM::op(pminmax.prod(l, r), PM::e()) == pminmax.prod(l, r),
                          "PrefixSumMinMax identity");
                    int m = (l + r) / 2;
                    check(PM::op(pminmax.prod(l, m), pminmax.prod(m, r)) == pminmax.prod(l, r), "PrefixSumMinMax concatenate");
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

    // MinWith / MaxWith: 空区間は位置 -1。値が型の最大値 (最小値) の要素があっても単位元として働き、同じ値なら左側
    {
        using Mn = monoid::MinWith<long long>;
        using Mx = monoid::MaxWith<long long>;
        constexpr long long INF = std::numeric_limits<long long>::max(), NINF = std::numeric_limits<long long>::lowest();
        check(Mn::e() == std::pair<long long, long long>(INF, -1) && Mx::e() == std::pair<long long, long long>(NINF, -1), "MinWith/MaxWith::e");
        check(Mn::op(Mn::e(), {INF, 3}) == std::pair<long long, long long>(INF, 3) && Mn::op({INF, 3}, Mn::e()) == std::pair<long long, long long>(INF, 3), "MinWith e は単位元");
        check(Mx::op(Mx::e(), {NINF, 3}) == std::pair<long long, long long>(NINF, 3) && Mx::op({NINF, 3}, Mx::e()) == std::pair<long long, long long>(NINF, 3), "MaxWith e は単位元");
        for (int rep = 0; rep < 200 && ok; rep++) {
            int n = rng() % 20 + 1;
            std::vector<long long> a(n);
            for (auto& x : a) x = rng() % 3 == 0 ? (rng() % 2 ? INF : NINF) : static_cast<long long>(rng() % 5);
            std::vector<std::pair<long long, long long>> init(n);
            for (int i = 0; i < n; i++) init[i] = {a[i], i};
            SegTree<Mn> mn(init);
            SegTree<Mx> mx(init);
            for (int q = 0; q < 30; q++) {
                int l = rng() % (n + 1), r = rng() % (n + 1);
                if (l > r) std::swap(l, r);
                std::pair<long long, long long> emn(INF, -1), emx(NINF, -1);
                for (int i = l; i < r; i++) {
                    if (emn.second == -1 || a[i] < emn.first) emn = {a[i], i};
                    if (emx.second == -1 || a[i] > emx.first) emx = {a[i], i};
                }
                check(mn.prod(l, r) == emn, "MinWith prod");
                check(mx.prod(l, r) == emx, "MaxWith prod");
            }
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
