#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// edit_distance と longest_common_subsequence、その復元を、再帰による愚直な方法とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/dp/edit-distance.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

#include "../../../src/dp/longest-common-subsequence.hpp"

// s[i:] と t[j:] の編集距離
int naive_edit(const std::string& s, const std::string& t, int i, int j) {
    if (i == static_cast<int>(s.size())) return t.size() - j;
    if (j == static_cast<int>(t.size())) return s.size() - i;
    int res = naive_edit(s, t, i + 1, j + 1) + (s[i] != t[j]);
    res = std::min(res, naive_edit(s, t, i + 1, j) + 1);
    res = std::min(res, naive_edit(s, t, i, j + 1) + 1);
    return res;
}

// s[i:] と t[j:] の LCS の長さ
int naive_lcs(const std::string& s, const std::string& t, int i, int j) {
    if (i == static_cast<int>(s.size()) || j == static_cast<int>(t.size())) return 0;
    int res = std::max(naive_lcs(s, t, i + 1, j), naive_lcs(s, t, i, j + 1));
    if (s[i] == t[j]) res = std::max(res, naive_lcs(s, t, i + 1, j + 1) + 1);
    return res;
}

// 返された操作を実際に適用し、元の列の添字と目標の添字の整合性も確かめる。
template <class R1, class R2>
bool check_restore(const R1& s, const R2& t) {
    auto a = std::begin(s);
    auto b = std::begin(t);
    const long long n = std::end(s) - a, m = std::end(t) - b;
    const auto result = edit_distance_restore(s, t);
    if (result.distance != edit_distance(s, t) || result.distance != static_cast<long long>(result.operations.size())) return false;
    using T = typename std::iterator_traits<decltype(a)>::value_type;
    std::vector<T> current(a, std::end(s));
    long long consumed = 0;
    for (const auto& operation : result.operations) {
        auto [type, source, target] = operation;
        if (source < consumed || source > n || target < 0 || target > static_cast<long long>(current.size())) return false;
        if (type == EditDistance::Type::Insert) {
            if (target >= m) return false;
            current.insert(current.begin() + target, b[target]);
            consumed = source;
        } else {
            if (source >= n || target >= static_cast<long long>(current.size()) || current[target] != a[source]) return false;
            if (type == EditDistance::Type::Erase) {
                if (target > m) return false;
                current.erase(current.begin() + target);
            } else {
                if (target >= m) return false;
                current[target] = b[target];
            }
            consumed = source + 1;
        }
    }
    return std::equal(current.begin(), current.end(), b, std::end(t));
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 8, m = rng() % 8;
        int k = rng() % 3 + 1;
        std::string s(n, 'a'), t(m, 'a');
        for (auto& c : s) c = 'a' + rng() % k;
        for (auto& c : t) c = 'a' + rng() % k;

        ok = ok && edit_distance(s, t) == naive_edit(s, t, 0, 0);
        ok = ok && check_restore(s, t);
        int len = naive_lcs(s, t, 0, 0);
        ok = ok && longest_common_subsequence(s, t) == len;

        // 復元: 長さが最長で、添字が両方とも狭義単調増加し、要素が一致する
        auto [length, idx] = longest_common_subsequence_restore(s, t);
        ok = ok && length == len && static_cast<int>(idx.size()) == len;
        for (int p = 0; p < static_cast<int>(idx.size()) && ok; p++) {
            auto [i, j] = idx[p];
            ok = 0 <= i && i < n && 0 <= j && j < m && s[i] == t[j];
            if (p > 0) ok = ok && idx[p - 1].first < i && idx[p - 1].second < j;
        }
    }

    // 空列、末尾の挿入・削除、異なる要素型、ランダムアクセス可能な配列。
    for (const std::string& s : {std::string{}, std::string("abc"), std::string("aaaa")}) {
        for (const std::string& t : {std::string{}, std::string("xy"), std::string("abcde")}) {
            ok = ok && check_restore(s, t);
        }
    }
    ok = ok && check_restore(std::vector<int>{1, 2, 3}, std::vector<long long>{2, 4, 3, 5});
    int a[] = {1, 2, 3};
    long long b[] = {2, 3};
    ok = ok && check_restore(a, b);
    ok = ok && edit_distance_restore(std::string("abc"), std::string("abc")).operations.empty();

    // 例
    ok = ok && edit_distance(std::string("kitten"), std::string("sitting")) == 3;
    ok = ok && edit_distance(std::vector<int>{1, 2, 3}, std::vector<int>{2, 3, 4}) == 2;
    ok = ok && edit_distance(std::string(""), std::string("abc")) == 3;
    ok = ok && longest_common_subsequence(std::string("abcbdab"), std::string("bdcaba")) == 4;
    ok = ok && longest_common_subsequence(std::vector<int>{1, 2, 3}, std::vector<long long>{3, 1, 2}) == 2;
    ok = ok && longest_common_subsequence_restore(std::string(""), std::string("abc")).indices.empty();

    if (ok)
        std::cout << "Hello World" << std::endl;
    else {
        std::cerr << "failed" << std::endl;
        return 1;
    }
}
