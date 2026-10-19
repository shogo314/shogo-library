#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../../src/math/stern-brocot.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    using Q = Rational<long long>;
    int t;
    std::cin >> t;
    while (t--) {
        std::string type;
        std::cin >> type;
        if (type == "ENCODE_PATH") {
            long long a, b;
            std::cin >> a >> b;
            auto path = stern_brocot::encode_path(Q(a, b));
            std::cout << path.size();
            for (auto [c, n] : path) std::cout << ' ' << c << ' ' << n;
            std::cout << '\n';
        } else if (type == "DECODE_PATH") {
            int k;
            std::cin >> k;
            std::vector<std::pair<char, long long>> path(k);
            for (auto& [c, n] : path) std::cin >> c >> n;
            Q x = stern_brocot::decode_path(path);
            std::cout << x.num() << ' ' << x.den() << '\n';
        } else if (type == "LCA") {
            long long a, b, c, d;
            std::cin >> a >> b >> c >> d;
            Q x = stern_brocot::lca(Q(a, b), Q(c, d));
            std::cout << x.num() << ' ' << x.den() << '\n';
        } else if (type == "ANCESTOR") {
            long long k, a, b;
            std::cin >> k >> a >> b;
            auto x = stern_brocot::ancestor(Q(a, b), k);
            if (x) {
                std::cout << x->num() << ' ' << x->den() << '\n';
            } else {
                std::cout << -1 << '\n';
            }
        } else {
            long long a, b;
            std::cin >> a >> b;
            auto [lo, hi] = stern_brocot::range(Q(a, b));
            std::cout << lo.first << ' ' << lo.second << ' ' << hi.first << ' ' << hi.second << '\n';
        }
    }
}
