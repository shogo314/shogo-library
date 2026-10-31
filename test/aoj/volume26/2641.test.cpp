#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2641"

#include <iostream>
#include <vector>

#include "../../../src/geometry/segment-3d.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<Vector<long long, 3>> c(n);
    std::vector<long long> r(n), l(n);
    for (int i = 0; i < n; i++) std::cin >> c[i] >> r[i] >> l[i];
    while (q--) {
        Vector<long long, 3> s, t;
        std::cin >> s >> t;
        long long sum = 0;
        // 接する場合も貫通の魔法が要る。座標が整数なので、距離と半径が等しくない場合の差は 1e-10 より大きい
        for (int i = 0; i < n; i++) {
            if (distance_point_segment(s, t, c[i]) <= r[i] + 1e-11) sum += l[i];
        }
        std::cout << sum << '\n';
    }
}
