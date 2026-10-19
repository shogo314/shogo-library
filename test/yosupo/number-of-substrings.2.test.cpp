#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <iostream>
#include <string>

#include "../../src/string/suffix-automaton.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string s;
    std::cin >> s;
    std::cout << SuffixAutomaton<26, 'a'>(s).count_distinct_substrings() << '\n';
}
