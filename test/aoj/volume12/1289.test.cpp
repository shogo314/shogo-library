#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1289"
#define ERROR "1e-2"

#include <iomanip>
#include <iostream>
#include <vector>

#include "../../../src/geometry/sphere.hpp"

int main() {
    using D = Vector<double, 3>;
    int n;
    std::cout << std::fixed << std::setprecision(4);
    while (std::cin >> n && n != 0) {
        D o, dir;
        std::cin >> dir;
        std::vector<Sphere<double>> s(n);
        for (auto& x : s) std::cin >> x;
        int last = -1;
        while (true) {
            // 光線 o + dir t (t > 0) が最初に当たる球
            int hit = -1;
            double best = 0;
            D q;
            for (int i = 0; i < n; i++) {
                if (i == last) continue;
                for (const D& x : sphere_line_intersection(s[i], o, o + dir)) {
                    double t = dot(x - o, dir);
                    if (t > 1e-9 && (hit == -1 || t < best)) hit = i, best = t, q = x;
                    if (t > 1e-9) break;  // 光線の向きに並んでいるので、最初の点だけ見ればよい
                }
            }
            if (hit == -1) break;
            // 法線について反射する
            D m = (q - s[hit].c) / (q - s[hit].c).abs();
            dir = dir - m * (2 * dot(dir, m));
            o = q, last = hit;
        }
        std::cout << o[0] << ' ' << o[1] << ' ' << o[2] << '\n';
    }
}
