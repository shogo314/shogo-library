#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_o"
#define IGNORE

// 二部グラフの完全マッチングの個数を Matrix::permanent で数える

#include <iostream>
#include <vector>

#include "../../../src/math/matrix.hpp"
#include "../../../src/math/modint.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<modint1000000007>> a(n, std::vector<modint1000000007>(n));
    for (auto& row : a) {
        for (auto& x : row) {
            int b;
            std::cin >> b;
            x = b;
        }
    }
    std::cout << Matrix<modint1000000007>(a).permanent() << '\n';
}
