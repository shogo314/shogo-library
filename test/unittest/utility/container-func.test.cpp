#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// container_func.hpp の関数を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <string>
#include <vector>

#include "../../../src/utility/container_func.hpp"

bool ok = true;

void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

int main() {
    std::mt19937_64 rng(314);
    auto rand_vec = [&](int n, long long lo, long long hi) {
        std::vector<long long> v(n);
        for (auto& x : v) x = lo + static_cast<long long>(rng() % static_cast<unsigned long long>(hi - lo + 1));
        return v;
    };

    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 10 + 1;
        std::vector<long long> v = rand_vec(n, -5, 5);

        // sorted / sort (比較関数つき)
        {
            std::vector<long long> expect = v;
            std::sort(expect.begin(), expect.end(), std::greater<long long>());
            check(sorted(v, std::greater<long long>()) == expect, "sorted(c, f)");
            std::vector<long long> w = v;
            sort(w, std::greater<long long>());
            check(w == expect, "sort(c, f)");
        }

        // set / multiset に対する max / min (ソート済みのコンテナは先頭と末尾)
        {
            std::set<long long> s(v.begin(), v.end());
            std::multiset<long long> ms(v.begin(), v.end());
            long long mx = *std::max_element(v.begin(), v.end());
            long long mn = *std::min_element(v.begin(), v.end());
            check(max(s) == mx && min(s) == mn, "max/min(set)");
            check(max(ms) == mx && min(ms) == mn, "max/min(multiset)");
            check(max(v) == mx && min(v) == mn, "max/min(vector)");
        }

        // product / product_xor
        {
            std::vector<long long> small = rand_vec(n, -3, 3);
            long long p = 1, x = 0;
            for (long long a : small) p *= a, x ^= a;
            check(product(small) == p, "product(c)");
            check(product_xor(small) == x, "product_xor(c)");
            std::vector<long long> nonneg = rand_vec(n, 0, 1000000);
            long long y = 0;
            for (long long a : nonneg) y ^= a;
            check(product_xor(nonneg) == y, "product_xor(c) large");
        }

        // median: 偶数個なら中央 2 つの平均 (整数型は 0 方向に切り捨て)
        {
            std::vector<long long> w = v;
            std::sort(w.begin(), w.end());
            long long expect = n % 2 ? w[n / 2] : (w[n / 2 - 1] + w[n / 2]) / 2;
            check(median(v) == expect, "median(vector<long long>)");
            std::vector<double> d(v.begin(), v.end());
            std::vector<double> dw = d;
            std::sort(dw.begin(), dw.end());
            double dexp = n % 2 ? dw[n / 2] : (dw[n / 2 - 1] + dw[n / 2]) / 2;
            check(median(d) == dexp, "median(vector<double>)");
        }

        // index: 最初に現れる位置、なければ -1
        {
            long long x = static_cast<long long>(rng() % 13) - 6;
            long long expect = std::find(v.begin(), v.end(), x) - v.begin();
            if (expect == static_cast<long long>(v.size())) expect = -1;
            check(index(v, x) == expect, "index(c, x)");
        }

        // index_if / indices_if / count_if: f(x) が true になる位置と個数 (vector と set)
        {
            long long x = static_cast<long long>(rng() % 13) - 6;
            auto f = [&](long long e) { return e >= x; };
            std::vector<long long> pos;
            for (long long i = 0; i < static_cast<long long>(v.size()); i++) {
                if (f(v[i])) pos.push_back(i);
            }
            check(indices_if(v, f) == pos, "indices_if(vector, f)");
            check(index_if(v, f) == (pos.empty() ? -1 : pos[0]), "index_if(vector, f)");
            check(count_if(v, f) == static_cast<long long>(pos.size()), "count_if(vector, f)");
            std::set<long long> st(v.begin(), v.end());
            long long first = std::find_if(st.begin(), st.end(), f) == st.end() ? -1 : std::distance(st.begin(), std::find_if(st.begin(), st.end(), f));
            check(index_if(st, f) == first, "index_if(set, f)");
            check(count_if(st, f) == std::count_if(st.begin(), st.end(), f), "count_if(set, f)");
        }

        // mex: 含まれない最小の非負整数
        {
            std::vector<int> w(n);
            for (auto& a : w) a = static_cast<int>(rng() % 8) - 2;
            int expect = 0;
            while (std::find(w.begin(), w.end(), expect) != w.end()) expect++;
            check(mex(w) == expect, "mex(c)");
        }

        // count / find / lower_bound / upper_bound (set はメンバ関数、vector は std:: のアルゴリズム)
        {
            long long x = static_cast<long long>(rng() % 13) - 6;
            std::multiset<long long> ms(v.begin(), v.end());
            std::vector<long long> w = v;
            std::sort(w.begin(), w.end());
            check(count(ms, x) == static_cast<std::size_t>(std::count(v.begin(), v.end(), x)), "count(multiset, x)");
            check(count(v, x) == std::count(v.begin(), v.end(), x), "count(vector, x)");
            check((find(ms, x) != ms.end()) == (std::find(v.begin(), v.end(), x) != v.end()), "find(multiset, x)");
            check(find(v, x) == std::find(v.begin(), v.end(), x), "find(vector, x)");
            check(lower_bound(ms, x) == ms.lower_bound(x) && upper_bound(ms, x) == ms.upper_bound(x), "lower/upper_bound(multiset, x)");
            check(lower_bound(w, x) == std::lower_bound(w.begin(), w.end(), x), "lower_bound(vector, x)");
            check(upper_bound(w, x) == std::upper_bound(w.begin(), w.end(), x), "upper_bound(vector, x)");
            check(contains(v, x) == (std::find(v.begin(), v.end(), x) != v.end()), "contains(vector, x)");
        }
    }

    // ABC480 B のように、条件を満たす候補がちょうど 1 つか調べる
    {
        std::vector<std::string> names = {"alice", "bob", "carol"};
        auto one_diff = [](const std::string& s, const std::string& t) {
            if (s.size() != t.size()) return false;
            int d = 0;
            for (std::size_t i = 0; i < s.size(); i++) d += s[i] != t[i];
            return d == 1;
        };
        std::string t = "bab";
        check(indices_if(names, [&](const std::string& s) { return one_diff(s, t); }) == std::vector<long long>{1}, "indices_if(vector<string>)");
        check(index_if(names, [](const std::string& s) { return s.size() > 10; }) == -1, "index_if 見つからない");
        check(count_if(std::vector<int>{}, [](int) { return true; }) == 0 && indices_if(std::vector<int>{}, [](int) { return true; }).empty(), "空のコンテナ");
    }

    // 初期化子リスト版
    check(max({3, -1, 7, 2}) == 7, "max(initializer_list)");
    check(min({3, -1, 7, 2}) == -1, "min(initializer_list)");
    check(sum({3, -1, 7, 2}) == 11, "sum(initializer_list)");
    check(product({3, -1, 7, 2}) == -42, "product(initializer_list)");
    check(product_xor({3, 5, 6}) == 0, "product_xor(initializer_list)");
    check(max({5}) == 5 && min({5}) == 5, "max/min(initializer_list) 1 要素");

    // 境界: 1 要素、空
    // average: 和が負でも正しく割る (整数型は 0 方向に切り捨て)
    check(average(std::vector<long long>{-2, -4}) == -3, "average 負の和");
    check(average(std::vector<int>{-1, -2}) == -1, "average 負の和、切り捨て");
    check(average(std::vector<int>{1, 2, 4}) == 2, "average 正の和");
    check(average(std::vector<double>{-1, -2}) == -1.5, "average(vector<double>)");
    check(median(std::vector<int>{4}) == 4, "median 1 要素");
    check(median(std::vector<int>{1, 4}) == 2, "median 2 要素");
    check(mex(std::vector<int>{}) == 0, "mex 空");
    check(mex(std::vector<int>{0, 1, 2}) == 3, "mex 0..n-1 をすべて含む");
    check(product(std::vector<int>{}) == 1 && product_xor(std::vector<int>{}) == 0, "product 空");
    check(index(std::vector<int>{}, 3) == -1, "index 空");
    check(sorted(std::string("bca"), std::greater<char>()) == "cba", "sorted(string, f)");

    if (ok) std::cout << "Hello World" << std::endl;
}
