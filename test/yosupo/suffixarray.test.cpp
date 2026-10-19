#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include <string>
#include <vector>

#include "../../src/string/suffix-array.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string s;
    std::cin >> s;
    std::vector<long long> sa = suffix_array(s);
    for (long long i = 0; i < static_cast<long long>(sa.size()); i++) std::cout << sa[i] << " \n"[i + 1 == static_cast<long long>(sa.size())];
}
