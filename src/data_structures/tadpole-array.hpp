#pragma once

/**
 * @file tadpole-array.hpp
 * @brief おたまじゃくし配列
 */

#include <cassert>
#include <cstddef>
#include <vector>
/**
 * @brief おたまじゃくし配列
 * 特定の位置でループする構造
 * @tparam T
 */
template <typename T>
struct TadpoleArray {
   private:
    std::vector<T> data;
    std::size_t k;

   public:
    /**
     * @brief 最後の次のインデックスがi
     */
    TadpoleArray(const std::vector<T>& v, int i) : data(v) {
        assert(0 <= i and i < static_cast<int>(data.size()));
        k = static_cast<std::size_t>(i);
    }
    TadpoleArray() = default;
    TadpoleArray(const TadpoleArray&) = default;
    T at(std::size_t i) const {
        if (i < k) return data[i];
        return data[(i - k) % (data.size() - k) + k];
    }
    T operator[](std::size_t i) const {
        return at(i);
    }
};
