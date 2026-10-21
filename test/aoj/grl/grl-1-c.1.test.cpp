#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <iostream>
#include <vector>

#include "../../../src/math/infint.hpp"

int main() {
    using I = infint<long long>;
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<I>> d(n, std::vector<I>(n, I::inf()));
    for (int i = 0; i < n; i++) d[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int s, t;
        long long w;
        std::cin >> s >> t >> w;
        d[s][t] = w;
    }
    // 無限大に有限の値を足しても無限大のままなので、到達不能を特別扱いせずに書ける
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                I c = d[i][k] + d[k][j];
                if (c < d[i][j]) d[i][j] = c;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << '\n';
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) std::cout << ' ';
            if (d[i][j].is_plus_inf())
                std::cout << "INF";
            else
                std::cout << d[i][j];
        }
        std::cout << '\n';
    }
}
