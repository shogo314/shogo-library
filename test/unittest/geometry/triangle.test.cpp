#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// 頂点の全順列で同じ三角形になることと、平行移動した三角形を区別することを確かめる

#include "../../../src/geometry/triangle.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <random>
#include <type_traits>

using P2 = Vector<long long, 2>;
using P3 = Vector<long long, 3>;
constexpr Triangle example(P2(0, 0), P2(3, 0), P2(0, 4));
static_assert(std::is_same_v<std::decay_t<decltype(example)>, Triangle<long long, 2>>);
static_assert(example.p2[0] == 3 && example.p3[1] == 4);
static_assert(std::is_same_v<decltype(Triangle(P3(), P3(1, 0, 0), P3(0, 1, 0))), Triangle<long long, 3>>);

template <int Dim>
void check_permutations(const Triangle<long long, Dim>& triangle) {
    using P = Vector<long long, Dim>;
    const std::array<P, 3> points{triangle.p1, triangle.p2, triangle.p3};
    std::array<int, 3> order{0, 1, 2};
    do {
        Triangle reordered(points[order[0]], points[order[1]], points[order[2]]);
        assert(triangle == reordered && reordered == triangle && !(triangle != reordered));
    } while (std::next_permutation(order.begin(), order.end()));
    P shift;
    for (int i = 0; i < Dim; ++i) shift[i] = 100;
    const Triangle moved(triangle.p1 + shift, triangle.p2 + shift, triangle.p3 + shift);
    assert(triangle != moved && moved != triangle);
}

int main() {
    std::mt19937 rng(314);
    auto rnd = [&] { return static_cast<long long>(rng() % 11) - 5; };
    for (int rep = 0; rep < 3000; ++rep) {
        P2 a(rnd(), rnd()), b(rnd(), rnd()), c(rnd(), rnd());
        if (cross(b - a, c - a) != 0) check_permutations(Triangle(a, b, c));
        P3 d(rnd(), rnd(), rnd()), e(rnd(), rnd(), rnd()), f(rnd(), rnd(), rnd());
        if (cross(e - d, f - d) != P3()) check_permutations(Triangle(d, e, f));
    }
    const long long g = 1000000000;
    check_permutations(Triangle(P2(-g, -g), P2(g, -g), P2(0, g)));
    check_permutations(Triangle(P3(-g, -g, g), P3(g, -g, -g), P3(0, g, 0)));
    using D = Vector<double, 2>;
    const Triangle fractional(D(0.5, 0.0), D(1.5, 0.0), D(0.5, 1.0));
    static_assert(std::is_same_v<std::decay_t<decltype(fractional)>, Triangle<double, 2>>);
    assert(fractional == Triangle(D(0.5, 1.0), D(0.5, 0.0), D(1.5, 0.0)));
    assert(fractional != Triangle(D(0.5, 0.0), D(2.5, 0.0), D(0.5, 1.0)));
    using D3 = Vector<double, 3>;
    const Triangle spatial(D3(0.5, 0, 1), D3(1.5, 0, 1), D3(0.5, 1, 2));
    assert(spatial == Triangle(D3(0.5, 1, 2), D3(1.5, 0, 1), D3(0.5, 0, 1)));
    assert(spatial != Triangle(D3(0.5, 0, 1), D3(1.5, 0, 1), D3(0.5, 2, 3)));
    auto [p1, p2, p3] = fractional;
    assert(p1 == fractional.p1 && p2 == fractional.p2 && p3 == fractional.p3);
    std::cout << "Hello World\n";
}
