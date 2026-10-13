#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_C"

#include <iostream>
#include <vector>

#include "../../src/utility/container_func.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    int q;
    std::cin >> q;
    while (q--) {
        int b, e;
        long long k;
        std::cin >> b >> e >> k;
        std::vector<long long> sub(a.begin() + b, a.begin() + e);
        std::cout << count(sub, k) << '\n';
    }
}
