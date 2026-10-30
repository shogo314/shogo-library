#define PROBLEM "https://atcoder.jp/contests/abc479/tasks/abc479_f"
#define IGNORE

#include <cstdlib>
#include <iostream>
#include <vector>

#include "../../../src/others/inversion-number.hpp"
#include "../../../src/utility/vector_func.hpp"

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> s(n), t(n);
    for (auto& x : s) std::cin >> x;
    for (auto& x : t) std::cin >> x;
    // 各人の S・T での順位 (値は相異なるので置換になる)
    std::vector<long long> rs = rank(s), rt = rank(t);
    // 順序の入れ替えは、隣り合う人の交換 1 回ずつ
    long long ans = inversion_number(select(rt, argsort(s)));
    // 交換を除くと、x - (順位) が左の空きマスの数になり、各人が独立に動く
    for (long long i = 0; i < n; i++) ans += std::llabs((t[i] - rt[i]) - (s[i] - rs[i]));
    std::cout << ans << '\n';
}
