#pragma once

/**
 * @file static-rectangle-add-rectangle-sum.hpp
 * @brief オフラインの長方形加算・長方形和
 */

#include <algorithm>
#include <vector>

#include "../data_structures/fenwick-tree.hpp"
#include "../geometry/rectangle.hpp"

/**
 * @brief 登録したすべての長方形加算を適用した後の長方形和をまとめて求める
 * @tparam T 重みと計算結果の型。座標から構築でき、加減乗算ができること
 */
template <typename T = long long>
class StaticRectangleAddRectangleSum {
    struct Update {
        Rectangle<long long> rect;
        T weight;
    };
    std::vector<Update> updates;
    std::vector<Rectangle<long long>> queries;

   public:
    void add(long long l, long long d, long long r, long long u, const T& weight) {
        updates.push_back({Rectangle<long long>(l, d, r, u), weight});
    }
    void query(long long l, long long d, long long r, long long u) {
        queries.emplace_back(l, d, r, u);
    }
    /** @brief query の登録順に返す。O((n + q) log(n + q)) 時間、O(n + q) 領域 */
    std::vector<T> solve() const {
        struct Event {
            long long x, y;
            T weight;
        };
        struct Query {
            long long x, y, index;
            int sign;
        };
        std::vector<Event> events;
        std::vector<Query> points;
        std::vector<long long> ys;
        for (const auto& [rect, w] : updates) {
            const auto& [l, d, r, u] = rect;
            if (rect.empty()) continue;
            events.push_back({l, d, w});
            events.push_back({l, u, -w});
            events.push_back({r, d, -w});
            events.push_back({r, u, w});
            ys.push_back(d);
            ys.push_back(u);
        }
        const long long q = queries.size();
        std::vector<T> result(q, T(0));
        if (events.empty() || q == 0) return result;
        for (long long i = 0; i < q; ++i) {
            const auto& [l, d, r, u] = queries[i];
            points.push_back({l, d, i, 1});
            points.push_back({l, u, i, -1});
            points.push_back({r, d, i, -1});
            points.push_back({r, u, i, 1});
        }
        std::sort(ys.begin(), ys.end());
        ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
        std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) { return a.x < b.x; });
        std::sort(points.begin(), points.end(), [](const Query& a, const Query& b) { return a.x < b.x; });
        const long long m = ys.size();
        FenwickTree<group::Sum<T>> c00(m), c10(m), c01(m), c11(m);
        long long j = 0;
        for (const auto& [x, y, index, sign] : points) {
            while (j < static_cast<long long>(events.size()) && events[j].x < x) {
                const auto& [a, b, w] = events[j++];
                const long long k = std::lower_bound(ys.begin(), ys.end(), b) - ys.begin();
                // 角 (a, b) の寄与は w * (x-a) * (y-b)。座標の積も T で計算する。
                c00.apply(k, w);
                c10.apply(k, w * T(a));
                c01.apply(k, w * T(b));
                c11.apply(k, w * T(a) * T(b));
            }
            const long long k = std::lower_bound(ys.begin(), ys.end(), y) - ys.begin();
            T value = c00.prefix_prod(k) * T(x) * T(y) - c10.prefix_prod(k) * T(y) - c01.prefix_prod(k) * T(x) + c11.prefix_prod(k);
            if (sign == 1)
                result[index] += value;
            else
                result[index] -= value;
        }
        return result;
    }
};
