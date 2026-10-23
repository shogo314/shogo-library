#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// sortable-segtree.hpp の SortableSegTree を、(キー, 値) の列をそのまま並べ替える愚直な実装とランダムな操作列で比べる
// 積の順番が分かるように、文字列の連結 (可換でない) をモノイドにする
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/data_structures/sortable-segtree.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>

struct Concat {
    using S = std::string;
    static S op(const S& a, const S& b) { return a + b; }
    static S e() { return ""; }
};

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 300 && ok; rep++) {
        const int n = rng() % 12 + 1;
        const long long key_limit = 64;
        std::vector<std::pair<long long, std::string>> a(n);
        std::set<long long> used;
        auto fresh_key = [&]() {
            long long k;
            do k = rng() % key_limit;
            while (used.count(k));
            used.insert(k);
            return k;
        };
        std::vector<long long> keys(n);
        std::vector<std::string> values(n);
        for (int i = 0; i < n; i++) {
            keys[i] = fresh_key(), values[i] = std::string(1, static_cast<char>('a' + rng() % 26));
            a[i] = {keys[i], values[i]};
        }
        SortableSegTree<Concat> st(keys, values, key_limit);
        if (st.size() != n) ok = false;
        for (int step = 0; step < 100 && ok; step++) {
            int t = rng() % 4, l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            if (t == 0) {
                int i = rng() % n;
                used.erase(a[i].first);
                a[i] = {fresh_key(), std::string(1, static_cast<char>('a' + rng() % 26))};
                st.set(i, a[i].first, a[i].second);
            } else if (t == 1) {
                std::string expect;
                for (int i = l; i < r; i++) expect += a[i].second;
                if (st.prod(l, r) != expect) ok = false;
            } else {
                std::sort(a.begin() + l, a.begin() + r);
                if (t == 3) std::reverse(a.begin() + l, a.begin() + r);
                st.sort(l, r, t == 3);
            }
        }
        std::string all;
        for (auto& [k, v] : a) all += v;
        if (st.prod(0, n) != all) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
