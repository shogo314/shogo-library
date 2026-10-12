#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160"

#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#include "../../src/base/functions.hpp"
#include "../../src/base/macro.hpp"

int main() {
    int w, h;
    while (std::cin >> w >> h && (w != 0 || h != 0)) {
        std::vector<std::vector<int>> c(h, std::vector<int>(w));
        rep(i, h) rep(j, w) std::cin >> c[i][j];
        int ans = 0;
        rep(i, h) rep(j, w) {
            if (c[i][j] != 1) continue;
            ans++;
            // 8 方向につながる陸を塗りつぶす
            std::stack<std::pair<int, int>> stk;
            stk.emplace(i, j);
            c[i][j] = 0;
            while (!stk.empty()) {
                auto [y, x] = stk.top();
                stk.pop();
                rep(dy, -1, 2) rep(dx, -1, 2) {
                    long long ny = y + dy, nx = x + dx;
                    if (inrect(ny, nx, h, w) && c[ny][nx] == 1) {
                        c[ny][nx] = 0;
                        stk.emplace(ny, nx);
                    }
                }
            }
        }
        std::cout << ans << '\n';
    }
}
