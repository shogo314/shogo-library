#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_2_C"

#include <iostream>
#include <vector>

#include "../../src/utility/container_func.hpp"
#include "../../src/base/io.hpp"

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> v = sorted(std::vector<int>{a, b, c});
    print(v[0], v[1], v[2]);  // 空白区切りで出力して改行
}
