#pragma once

/**
 * @file argcmp.hpp
 * @brief 偏角ソートの比較関数
 */

#include <array>
#include <type_traits>
#include "../utility/traits.hpp"

/**
 * 偏角ソート
 * 反時計回り
 * x 軸正方向を始点とし、零ベクトルは x 軸正方向と同じ偏角として扱う
 */
template <typename T, ENABLE_IF_T(std::is_integral_v<T>)>
bool argcmp(std::array<T, 2> a, std::array<T, 2> b) {
    // 零ベクトルは外積で比べられないので、偏角 0 (x 軸正方向) として先に判定する
    const bool a_zero = a[0] == 0 && a[1] == 0;
    const bool b_zero = b[0] == 0 && b[1] == 0;
    if (b_zero) return false;  // 偏角 0 より小さいものはない
    if (a_zero) return !(b[1] == 0 && b[0] > 0);  // b の偏角が 0 より大きいか
    T a0 = std::array<T, 2>{a[1], a[0]} < std::array<T, 2>{0, 0};
    T b0 = std::array<T, 2>{b[1], b[0]} < std::array<T, 2>{0, 0};
    if (a0 < b0) {
        return true;
    } else if (b0 < a0) {
        return false;
    } else {
        return b[0] * a[1] < a[0] * b[1];
    }
}
