#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../../src/data_structures/disjoint-sparse-table.hpp"

#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "../../../src/math/modint.hpp"

struct ExplicitSum {
    struct S {
        long long value;
        explicit S(long long x) : value(x) {}
    };
    static S e() { return S(0); }
    static S op(const S& a, const S& b) { return S(a.value + b.value); }
};

struct InputRange {
    std::istringstream input{"1 2 3"};
    auto begin() { return std::istream_iterator<int>(input); }
    auto end() { return std::istream_iterator<int>(); }
    long long size() const { return 3; }
};

int main() {
    using mint = modint998244353;
    std::mt19937 rng(314);
    for (int n = 0; n <= 130; ++n) {
        std::vector<Affine<mint>> a(n);
        for (auto& f : a) f = {rng() % 10, rng() % 10};
        DisjointSparseTable<monoid::Composite<mint>> table(a);
        for (int l = 0; l <= n; ++l) {
            Affine<mint> expected;
            for (int r = l; r <= n; ++r) {
                if (table.prod(l, r) != expected) return 1;
                if (r < n) expected = monoid::Composite<mint>::op(expected, a[r]);
            }
        }
        if (table.size() != n || table.all_prod() != table.prod(0, n)) return 1;
        for (int i = 0; i < n; ++i)
            if (table.get(i) != a[i]) return 1;
    }
    auto check = [](auto&& range) {
        DisjointSparseTable st(std::forward<decltype(range)>(range), ExplicitSum{});
        return st.size() == 3 && st.all_prod().value == 6 && st.prod(1, 3).value == 5;
    };
    int raw[] = {1, 2, 3};
    const std::array<int, 3> arr = {1, 2, 3};
    if (!check(raw) || !check(arr) || !check(std::list<int>{1, 2, 3}) || !check(InputRange{})) return 1;
#if __cplusplus >= 202002L
    if (!check(std::views::iota(1, 4))) return 1;
#endif
    DisjointSparseTable<ExplicitSum> empty;
    if (empty.size() != 0 || empty.all_prod().value != 0) return 1;
    DisjointSparseTable<monoid::Sum<long long>> singleton({7});
    if (singleton.prod(0, 1) != 7 || singleton.prod(1, 1) != 0) return 1;
    DisjointSparseTable braces({1LL, 2LL, 3LL}, monoid::Sum<long long>{});
    if (braces.all_prod() != 6) return 1;
    DisjointSparseTable stateful(std::array<std::string, 3>{"a", "b", "c"},
                                 Monoid([reverse = true](const std::string& a, const std::string& b) { return reverse ? b + a : a + b; }, std::string{}));
    if (stateful.prod(0, 3) != "cba" || stateful.prod(1, 3) != "cb") return 1;
    static_assert(!std::is_constructible_v<DisjointSparseTable<ExplicitSum>, std::vector<std::string>&>);
    std::cout << "Hello World\n";
}
