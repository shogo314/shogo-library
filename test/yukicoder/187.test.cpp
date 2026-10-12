#define PROBLEM "https://yukicoder.me/problems/no/187"

#include "../../src/math/number-theory.hpp"

#include <iostream>

int main() {
    constexpr long long MOD = 1000000007;
    int N;
    std::cin >> N;
    std::vector<long long> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> x[i] >> y[i];
    }
    auto res = crt(x, y, MOD);
    if(!res) {
        std::cout << -1 << std::endl;
        return 0;
    }
    auto [ans, l] = *res;
    if([&] {
        long long tmp = l * MOD;
        for(int i = 0; i < N; ++i) {
            if(tmp % y[i] != x[i]) return false;
        }
        return true;
    }()) {
        std::cout << 0 << std::endl;
    } else if(ans == 0) std::cout << l << std::endl;
    else std::cout << ans << std::endl;
}
