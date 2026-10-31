#define PROBLEM "https://atcoder.jp/contests/abc472/tasks/abc472_f"
#define IGNORE

#include <iomanip>
#include <iostream>
#include <vector>

#include "../../../src/data_structures/circular-sum.hpp"
#include "../../../src/geometry/vector.hpp"

int main() {
    long long n, q;
    std::cin >> n >> q;
    std::vector<Vector<long long>> p(n);
    for (auto& x : p) std::cin >> x;
    // 辺 i → i+1 の寄与の円環上の区間和に、閉じる辺 v → u の寄与を足すと、部分多角形 u, ..., v の {2S, 6S gx, 6S gy} になる
    std::vector<decltype(polygon_moment(p[0], p[0]))> e(n);
    for (long long i = 0; i < n; i++) e[i] = polygon_moment(p[i], p[(i + 1) % n]);
    CircularSum cs(e);
    std::cout << std::setprecision(15);
    while (q--) {
        long long u, v;
        std::cin >> u >> v;
        u--, v--;
        auto m = cs.sum(u, v) + polygon_moment(p[v], p[u]);
        long double a = static_cast<long double>(m[0]) * 3;
        std::cout << static_cast<long double>(m[1]) / a << ' ' << static_cast<long double>(m[2]) / a << '\n';
    }
}
