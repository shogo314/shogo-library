#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A"

#include <cassert>
#include <iostream>
#include <vector>

#include "../../src/base/container_func.hpp"
#include "../../src/base/io.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::cin >> a;
    std::vector<int> b = reversed(a);  // 逆順にしたコピー
    reverse(a);                        // その場で逆順にする
    assert(a == b);
    print(a);  // 空白区切りで出力して改行
}
