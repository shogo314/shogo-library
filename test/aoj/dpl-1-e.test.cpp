#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"

#include <iostream>
#include <string>

#include "../../src/dp/edit-distance.hpp"

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << edit_distance(s, t) << std::endl;
}
