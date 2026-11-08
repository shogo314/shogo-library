#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160"

#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#include "../../../src/utility/range.hpp"

int main() {
    int w, h;
    while (std::cin >> w >> h && (w != 0 || h != 0)) {
        std::vector<std::vector<int>> c(h, std::vector<int>(w));
        const Grid grid(h, w);
        for (auto [i, j] : grid) std::cin >> c[i][j];
        int ans = 0;
        for (auto [i, j] : grid) {
            if (c[i][j] != 1) continue;
            ans++;
            // 8 方向につながる陸を塗りつぶす
            std::stack<Grid::value_type> stk;
            stk.emplace(i, j);
            c[i][j] = 0;
            while (!stk.empty()) {
                auto [y, x] = stk.top();
                stk.pop();
                for (auto [ny, nx] : grid.neighbors8(y, x)) {
                    if (c[ny][nx] == 1) {
                        c[ny][nx] = 0;
                        stk.emplace(ny, nx);
                    }
                }
            }
        }
        std::cout << ans << '\n';
    }
}
