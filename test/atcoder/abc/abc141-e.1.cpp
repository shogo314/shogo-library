#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"
#define IGNORE

// 開始位置 i ごとに s[i:] の Z 配列を作ると、z[d] は位置 i と i + d から一致が続く長さ。
// 2 つの出現が重ならないのは長さが d 以下のときなので、min(z[d], d) の最大値が答え。O(N^2)

#include <algorithm>
#include <iostream>
#include <string>

#include "../../../src/string/string.hpp"

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        auto z = z_algorithm(s.begin() + i, s.end());
        for (int d = 1; d < n - i; d++) ans = std::max(ans, std::min<long long>(z[d], d));
    }
    std::cout << ans << '\n';
}
