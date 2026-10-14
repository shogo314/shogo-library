#pragma once

/**
 * @file persistent-segtree.hpp
 * @brief 永続セグメント木
 */

#include <cassert>
#include <memory>
#include <ostream>
#include <utility>
#include <vector>

#include "../algebra/monoid.hpp"

/**
 * @brief 永続セグメント木
 *
 * 更新すると新しい版を返し、元の版は変わらない。同じ木から作った版はノードを共有する
 * 例:
 * PersistentSegTree<monoid::Sum<long long>> s0(n);
 * auto s1 = s0.set(3, 10);  // s0 はそのまま
 * s1.prod(0, 5);            // 10
 *
 * @tparam M モノイド (algebra/monoid.hpp)
 */
template <typename M>
class PersistentSegTree {
   public:
    using S = typename M::S;

   private:
    // すべての版のノードを持つ。ノードは削除しない
    struct Pool {
        M m;
        std::vector<S> val;
        std::vector<int> left, right;  // 葉では -1
        explicit Pool(M m) : m(std::move(m)) {}
        int make_leaf(const S& x) {
            val.push_back(x);
            left.push_back(-1);
            right.push_back(-1);
            return int(val.size()) - 1;
        }
        int make_node(int l, int r) {
            val.push_back(m.op(val[l], val[r]));
            left.push_back(l);
            right.push_back(r);
            return int(val.size()) - 1;
        }
    };

    std::shared_ptr<Pool> pool;
    int n, sz, root;

    S op(const S& a, const S& b) const { return pool->m.op(a, b); }
    S e() const { return pool->m.e(); }

    PersistentSegTree(std::shared_ptr<Pool> pool, int n, int sz, int root) : pool(std::move(pool)), n(n), sz(sz), root(root) {}

    void init_size() {
        sz = 1;
        while (sz < n) sz <<= 1;
    }
    int build(const std::vector<S>& v, int a, int b) {
        if (b - a == 1) return pool->make_leaf(a < n ? v[a] : e());
        int mid = (a + b) / 2;
        int l = build(v, a, mid);
        int r = build(v, mid, b);
        return pool->make_node(l, r);
    }
    int set_rec(int t, int a, int b, int k, const S& x) const {
        if (b - a == 1) return pool->make_leaf(x);
        int mid = (a + b) / 2;
        int l = pool->left[t], r = pool->right[t];
        if (k < mid)
            l = set_rec(l, a, mid, k, x);
        else
            r = set_rec(r, mid, b, k, x);
        return pool->make_node(l, r);
    }
    S prod_rec(int t, int a, int b, int l, int r) const {
        if (r <= a || b <= l) return e();
        if (l <= a && b <= r) return pool->val[t];
        int mid = (a + b) / 2;
        return op(prod_rec(pool->left[t], a, mid, l, r), prod_rec(pool->right[t], mid, b, l, r));
    }
    // [a, b) のうち l 以降で、sum に掛けると f が偽になる最初の位置 (なければ b)
    template <typename F>
    int max_right_rec(int t, int a, int b, int l, F& f, S& sum) const {
        if (b <= l) return b;
        if (l <= a) {
            S s = op(sum, pool->val[t]);
            if (f(s)) {
                sum = s;
                return b;
            }
            if (b - a == 1) return a;
        }
        int mid = (a + b) / 2;
        int x = max_right_rec(pool->left[t], a, mid, l, f, sum);
        if (x < mid) return x;
        return max_right_rec(pool->right[t], mid, b, l, f, sum);
    }
    // [a, b) のうち r より前で、sum に左から掛けると f が偽になる最後の位置 + 1 (なければ a)
    template <typename F>
    int min_left_rec(int t, int a, int b, int r, F& f, S& sum) const {
        if (r <= a) return a;
        if (b <= r) {
            S s = op(pool->val[t], sum);
            if (f(s)) {
                sum = s;
                return a;
            }
            if (b - a == 1) return b;
        }
        int mid = (a + b) / 2;
        int x = min_left_rec(pool->right[t], mid, b, r, f, sum);
        if (x > mid) return x;
        return min_left_rec(pool->left[t], a, mid, r, f, sum);
    }

   public:
    /**
     * @brief コンストラクタ
     *
     * すべての要素を単位元で初期化する。単位元の部分木は共有するので、n が大きくても O(log n) で作れる
     *
     * @param n 要素数
     * @param m モノイド
     */
    explicit PersistentSegTree(int n = 0, M m = M()) : pool(std::make_shared<Pool>(std::move(m))), n(n) {
        assert(0 <= n);
        init_size();
        root = pool->make_leaf(e());
        for (int w = 1; w < sz; w <<= 1) root = pool->make_node(root, root);
    }
    /**
     * @brief コンストラクタ
     *
     * @param v 初期の要素
     * @param m モノイド
     */
    explicit PersistentSegTree(const std::vector<S>& v, M m = M()) : pool(std::make_shared<Pool>(std::move(m))), n(v.size()) {
        init_size();
        root = build(v, 0, sz);
    }

    /**
     * @brief 要素数を返す
     */
    int size() const { return n; }

    /**
     * @brief 指定された要素の値を返す
     *
     * @param k インデックス
     * @return S 値
     */
    S get(int k) const {
        assert(0 <= k && k < n);
        int t = root, a = 0, b = sz;
        while (b - a > 1) {
            int mid = (a + b) / 2;
            if (k < mid) {
                t = pool->left[t];
                b = mid;
            } else {
                t = pool->right[t];
                a = mid;
            }
        }
        return pool->val[t];
    }
    /**
     * @brief 指定された要素の値を返す
     *
     * @param k インデックス
     * @return S 値
     */
    S operator[](int k) const { return get(k); }

    /**
     * @brief 内容を出力する
     *
     * @tparam CharT 出力ストリームの文字型
     * @tparam Traits 出力ストリームの文字型特性
     * @param os 出力ストリーム
     * @param rhs 永続セグメント木
     * @return std::basic_ostream<CharT, Traits>& 出力ストリーム
     */
    template <class CharT, class Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const PersistentSegTree& rhs) {
        for (int i = 0; i < rhs.n; i++) {
            if (i != 0) os << CharT(' ');
            os << rhs[i];
        }
        return os;
    }

    /**
     * @brief 指定された要素の値をxにした新しい版を返す
     *
     * @param k インデックス
     * @param x 新しい値
     * @return PersistentSegTree 新しい版 (自身は変わらない)
     */
    PersistentSegTree set(int k, const S& x) const {
        assert(0 <= k && k < n);
        return PersistentSegTree(pool, n, sz, set_rec(root, 0, sz, k, x));
    }
    /**
     * @brief 指定された要素の値にxを作用させた新しい版を返す
     *
     * @param k インデックス
     * @param x 作用素
     * @return PersistentSegTree 新しい版 (自身は変わらない)
     */
    PersistentSegTree apply(int k, const S& x) const { return set(k, op(get(k), x)); }

    /**
     * @brief [l, r)の区間の総積を返す
     *
     * @param l 半開区間の開始
     * @param r 半開区間の終端 0<=l<=r<=n
     * @return S 総積
     */
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return prod_rec(root, 0, sz, l, r);
    }
    /**
     * @brief すべての要素の総積を返す
     *
     * @return S 総積
     */
    S all_prod() const { return pool->val[root]; }

    /**
     * @brief (r = l or f(prod([l, r))) = true) and (r = n or f(prod([l, r+1))) = false)となるrを返す
     * fが単調なら、f(prod([l, r))) = trueとなる最大のr
     *
     * @tparam F
     * @param l 半開区間の開始 0<=l<=n
     * @param f 判定関数 f(e) = true
     * @return int
     */
    template <typename F>
    int max_right(int l, F f) const {
        assert(f(e()));
        assert(0 <= l && l <= n);
        if (l == n) return n;
        S sum = e();
        int r = max_right_rec(root, 0, sz, l, f, sum);
        return r < n ? r : n;
    }
    /**
     * @brief (l = 0 or f(prod([l, r))) = true) and (l = r or f(prod([l-1, r))) = false)となるlを返す
     * fが単調なら、f(prod([l, r))) = trueとなる最小のl
     *
     * @tparam F
     * @param r 半開区間の終端 0<=r<=n
     * @param f 判定関数 f(e) = true
     * @return int
     */
    template <typename F>
    int min_left(int r, F f) const {
        assert(f(e()));
        assert(0 <= r && r <= n);
        if (r == 0) return 0;
        S sum = e();
        return min_left_rec(root, 0, sz, r, f, sum);
    }

    /**
     * @brief すべての要素を並べた列を返す
     */
    std::vector<S> to_vector() const {
        std::vector<S> res(n);
        for (int i = 0; i < n; i++) res[i] = get(i);
        return res;
    }
};

template <typename M>
PersistentSegTree(int, M) -> PersistentSegTree<M>;
template <typename M>
PersistentSegTree(std::vector<typename M::S>, M) -> PersistentSegTree<M>;
