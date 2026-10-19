#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Counter を std::map による愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/data_structures/counter.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

using Model = std::map<int, long long>;

// 個数 0 の値を取り除いた map にする
Model normalize(Model m) {
    for (auto itr = m.begin(); itr != m.end();) {
        if (itr->second == 0)
            itr = m.erase(itr);
        else
            ++itr;
    }
    return m;
}

bool same(const Counter<int>& c, const Model& m) {
    Model mm = normalize(m);
    if (c.size() != static_cast<int>(mm.size())) return false;
    // total は重複を含めた要素数 (個数の総和)
    long long sum = 0;
    for (auto [x, cnt] : mm) sum += cnt;
    if (c.total() != sum) return false;
    // begin / end で走査した結果が値の昇順に一致する
    std::vector<std::pair<int, long long>> a(c.begin(), c.end()), b(mm.begin(), mm.end());
    if (a != b) return false;
    // const な [] と get
    for (int x = -1; x <= 10; x++) {
        long long expect = mm.count(x) ? mm.at(x) : 0;
        if (c[x] != expect || c.get(x) != expect) return false;
    }
    return true;
}

Model random_model(std::mt19937& rng) {
    Model m;
    int k = rng() % 6;
    for (int i = 0; i < k; i++) m[rng() % 10] += rng() % 4;
    return m;
}

Counter<int> from_model(const Model& m) {
    Counter<int> c;
    for (auto [x, cnt] : m) c[x] = cnt;
    return c;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    auto check = [&](bool cond, const char* what) {
        if (!cond && ok) {
            std::cerr << "failed: " << what << std::endl;
            ok = false;
        }
    };

    // コンストラクタ
    {
        Counter<int> empty;
        check(same(empty, {}), "default constructor");
        Counter<int> one(5);
        check(same(one, {{5, 1}}), "Counter(x)");
        std::vector<int> v = {3, 1, 3, 2, 3};
        Counter<int> from_vec(v);
        check(same(from_vec, {{1, 1}, {2, 1}, {3, 3}}), "Counter(range)");
        Counter<int> from_il{{1, 2}, {4, 0}, {7, 3}, {1, 1}};
        check(same(from_il, {{1, 3}, {7, 3}}), "Counter(initializer_list)");
        // const でない左辺値からのコピーが範囲のコンストラクタに横取りされない
        Counter<int> copy(from_vec);
        check(same(copy, {{1, 1}, {2, 1}, {3, 3}}), "copy constructor");
        // key_type が範囲でもある場合は値 1 個として数える
        Counter<std::string> s(std::string("ab"));
        check(s.size() == 1 && s["ab"] == 1, "Counter<std::string>(x)");
        Counter<char> chars(std::string("aab"));
        check(chars['a'] == 2 && chars['b'] == 1 && chars.size() == 2, "Counter<char>(string)");
        // size は異なる値の個数、total は重複を含めた要素数
        Counter<int> dup(std::vector<int>{3, 3, 3, 5});
        check(dup.size() == 2 && dup.total() == 4, "size / total");
        check(Counter<int>().total() == 0, "total of empty");
    }

    for (int rep = 0; rep < 3000 && ok; rep++) {
        Model ma = random_model(rng), mb = random_model(rng);
        Counter<int> a = from_model(ma), b = from_model(mb);
        check(same(a, ma), "operator[] =");

        // + と +=
        Model sum = ma;
        for (auto [x, cnt] : mb) sum[x] += cnt;
        check(same(a + b, sum), "operator+");
        Counter<int> c = a;
        c += b;
        check(same(c, sum), "operator+=");

        // - と -= (個数が負にならない範囲で)
        Model sub = sum;
        for (auto [x, cnt] : mb) sub[x] -= cnt;
        check(same(c - b, sub), "operator-");
        c -= b;
        check(same(c, sub), "operator-=");

        // [] による += / -= / =
        Counter<int> d = from_model(ma);
        Model md = ma;
        for (int t = 0; t < 20; t++) {
            int x = rng() % 10;
            int op = rng() % 3;
            if (op == 0) {
                long long k = rng() % 3;
                d[x] += k;
                md[x] += k;
            } else if (op == 1) {
                long long have = md.count(x) ? md[x] : 0;
                long long k = have == 0 ? 0 : rng() % (have + 1);
                d[x] -= k;
                md[x] -= k;
            } else {
                long long k = rng() % 3;
                d[x] = k;
                md[x] = k;
            }
            // 参照からの読み取り
            long long expect = normalize(md).count(x) ? normalize(md).at(x) : 0;
            check(static_cast<long long>(d[x]) == expect, "CounterReference -> mapped_type");
        }
        check(same(d, md), "operator[] += / -= / =");

        // most_common: 個数の降順、同数なら値の昇順
        Model nm = normalize(md);
        std::vector<std::pair<int, long long>> expect(nm.begin(), nm.end());
        std::stable_sort(expect.begin(), expect.end(), [](const auto& p, const auto& q) { return p.second > q.second; });
        check(d.most_common() == expect, "most_common");
    }

    // 自分自身を引くと空になる (走査中の要素を消しても壊れない)
    if (ok) {
        Counter<int> c{{1, 2}, {3, 1}, {5, 4}};
        c -= c;
        check(same(c, {}), "self operator-=");
        Counter<int> d{{1, 2}, {3, 1}};
        d += d;
        check(same(d, {{1, 4}, {3, 2}}), "self operator+=");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
