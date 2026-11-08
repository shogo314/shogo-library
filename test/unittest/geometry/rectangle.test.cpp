#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Rectangle の包含判定・面積を整数点の列挙と比較し、半開区間の境界も調べる

#include "../../../src/geometry/rectangle.hpp"

#include <cassert>
#include <iostream>
#include <random>
#include <sstream>
#include <type_traits>

static_assert(std::is_same_v<decltype(Rectangle(0, 0LL, 2, 3)), Rectangle<long long>>);
static_assert(std::is_same_v<decltype(Rectangle(0, 0.0, 2, 3)), Rectangle<double>>);
static_assert(std::is_same_v<decltype(Rectangle()), Rectangle<long long>>);
static_assert(Rectangle(1, 2, 4, 6).width() == 3);
static_assert(Rectangle(1, 2, 4, 6).height() == 4);
static_assert(Rectangle(1, 2, 4, 6).area() == 12);
static_assert(Rectangle(1, 2, 4, 6).contains(1, 2));
static_assert(!Rectangle(1, 2, 4, 6).contains(4, 2));
static_assert(!Rectangle(1, 2, 4, 6).contains(1, 6));
static_assert(Rectangle().empty());
static_assert(Rectangle(1, 2, 1, 6).empty());
static_assert(Rectangle(1, 2, 4, 2).empty());
static_assert(Rectangle(1, 2, 4, 6) == Rectangle(1, 2, 4, 6));
static_assert(Rectangle(1, 2, 1, 6) != Rectangle(2, 2, 2, 6));

int main() {
    std::mt19937 rng(314);
    for (int rep = 0; rep < 3000; ++rep) {
        auto rnd = [&] { return static_cast<long long>(rng() % 11) - 5; };
        long long left = rnd(), bottom = rnd();
        Rectangle rect(left, bottom, left + static_cast<long long>(rng() % 6), bottom + static_cast<long long>(rng() % 6));
        long long count = 0;
        for (long long x = -6; x <= 11; ++x) {
            for (long long y = -6; y <= 11; ++y) {
                bool expected = rect.left <= x && x < rect.right && rect.bottom <= y && y < rect.top;
                assert(rect.contains(x, y) == expected);
                assert(rect.contains(Vector<long long>(x, y)) == expected);
                count += expected;
            }
        }
        assert(rect.area() == count);
        assert(rect.empty() == (count == 0));
    }
    Rectangle r(0.5, -1.0, 2.0, 1.5);
    assert(r.width() == 1.5 && r.height() == 2.5 && r.area() == 3.75);
    assert(r.contains(0.5, -1.0) && !r.contains(2.0, 0.0) && !r.contains(1.0, 1.5));
    Rectangle<long long> big(-1000000000LL, -1000000000LL, 1000000000LL, 1000000000LL);
    assert(big.area() == 4000000000000000000LL);
    std::istringstream input("-2 -3 4 5");
    Rectangle<> read;
    input >> read;
    assert(input && read == Rectangle(-2LL, -3LL, 4LL, 5LL));
    std::cout << "Hello World\n";
}
