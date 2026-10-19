#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// geometry/vector.hpp の Vector の演算子を、成分の配列で愚直に計算した結果とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/geometry/vector.hpp"

#include <array>
#include <iostream>
#include <random>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    using P2 = Vector<long long>;
    using P3 = Vector<long long, 3>;
    for (int rep = 0; rep < 10000 && ok; rep++) {
        // 比較の結果が偏らないよう、成分は小さい範囲から選ぶ
        auto rnd = [&] { return static_cast<long long>(rng() % 5) - 2; };
        std::array<long long, 2> a = {rnd(), rnd()}, b = {rnd(), rnd()};
        P2 p(a[0], a[1]), q(b[0], b[1]);
        long long c = rnd();

        // 単項 +、単項 -、スカラーが左側の積
        P2 plus = +p, minus = -p, scaled = c * p;
        for (int i = 0; i < 2; i++) {
            if (plus[i] != a[i] || minus[i] != -a[i] || scaled[i] != c * a[i]) ok = false;
        }
        if (c * p != p * c) ok = false;

        // 比較演算子は成分の辞書式順序
        if ((p < q) != (a < b) || (p > q) != (a > b) || (p <= q) != (a <= b) || (p >= q) != (a >= b)) ok = false;
        if ((p == q) != (a == b) || (p != q) != (a != b)) ok = false;

        // 3 次元でも同じ
        std::array<long long, 3> x = {rnd(), rnd(), rnd()}, y = {rnd(), rnd(), rnd()};
        P3 u(x[0], x[1], x[2]), v(y[0], y[1], y[2]);
        P3 nu = -u, su = c * u, pu = +u;
        for (int i = 0; i < 3; i++) {
            if (nu[i] != -x[i] || su[i] != c * x[i] || pu[i] != x[i]) ok = false;
        }
        if ((u > v) != (x > y) || (u <= v) != (x <= y) || (u >= v) != (x >= y)) ok = false;
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
