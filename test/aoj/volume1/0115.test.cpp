#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0115"

#include <iostream>

#include "../../../src/geometry/triangle.hpp"

int main() {
    Vector<long long, 3> s, t, a, b, c;
    std::cin >> s >> t >> a >> b >> c;
    // バリアは周 (頂点を含む) でもはね返し、敵がバリア上にいても当たらない
    std::cout << (segment_triangle_intersect(Segment(s, t), Triangle(a, b, c)) ? "MISS" : "HIT") << '\n';
}
