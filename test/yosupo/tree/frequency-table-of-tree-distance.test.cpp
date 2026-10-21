#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include <iostream>
#include <vector>

#include "../../../src/graph/centroid-decomposition.hpp"
#include "../../../src/math/convolution.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n;
    std::cin >> n;
    Tree<int> tree(n);
    tree.read(0);
    CentroidDecomposition cd(tree);
    std::vector<long long> ans(n, 0);
    // cnt[d] は距離 d の頂点の個数。自分自身との畳み込みで、距離の和ごとの組の個数になる
    auto add = [&](const std::vector<long long>& cnt, long long sign) {
        auto sq = convolution_ll(cnt, cnt);
        for (long long d = 0; d < static_cast<long long>(sq.size()) && d < n; d++) ans[d] += sign * sq[d];
    };
    for (long long c : cd.order()) {
        std::vector<long long> all = {1};  // c 自身
        for (const auto& sub : cd.subtrees(tree, c)) {
            std::vector<long long> cnt;
            for (auto [v, d] : sub) {
                if (static_cast<long long>(cnt.size()) <= d) cnt.resize(d + 1);
                if (static_cast<long long>(all.size()) <= d) all.resize(d + 1);
                cnt[d]++;
                all[d]++;
            }
            // 同じ部分木の中の 2 頂点を結ぶパスは c を通らないので引く
            add(cnt, -1);
        }
        add(all, 1);
    }
    // 順序付きの組を数えたので 2 で割る
    for (long long d = 1; d < n; d++) std::cout << ans[d] / 2 << " \n"[d + 1 == n];
}
