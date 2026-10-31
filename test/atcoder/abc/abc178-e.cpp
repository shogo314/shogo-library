#define PROBLEM "https://atcoder.jp/contests/abc178/tasks/abc178_e"
#define IGNORE

#include <iostream>
#include <vector>

#include "../../../src/geometry/manhattan.hpp"
#include "../../../src/geometry/vector.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<Vector<long long>> p(n);
    for (auto& x : p) std::cin >> x;
    std::cout << manhattan_farthest_pair(p).dist << '\n';
}
