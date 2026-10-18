#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// saturating.hpp の関数を、__int128 で計算して範囲に丸めたものと比較する
// 8 ビットの型は全組、それ以外は境界付近の値とランダムな値で調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/math/saturating.hpp"

#include <cstdint>
#include <iostream>
#include <limits>
#include <random>
#include <type_traits>
#include <utility>
#include <vector>

using i128 = __int128;
using u128 = unsigned __int128;

bool ok = true;

void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

template <class T>
i128 lo() { return (i128)std::numeric_limits<T>::min(); }
template <class T>
i128 hi() { return (i128)std::numeric_limits<T>::max(); }
template <class T>
T clamp128(i128 v) { return v < lo<T>() ? std::numeric_limits<T>::min() : v > hi<T>() ? std::numeric_limits<T>::max() : (T)v; }

// 境界付近の値とランダムな値
template <class T>
std::vector<T> samples(std::mt19937_64& rng) {
    std::vector<T> res;
    for (i128 d = 0; d < 4; d++) {
        for (i128 v : {lo<T>() + d, hi<T>() - d, d, -d, hi<T>() / 2 - 1 + d, lo<T>() / 2 - 1 + d}) {
            if (lo<T>() <= v && v <= hi<T>()) res.push_back((T)v);
        }
    }
    for (int i = 0; i < 40; i++) {
        T v = (T)rng();
        res.push_back(v);
        res.push_back((T)(v >> (rng() % (8 * sizeof(T)))));  // 小さい値も混ぜる
    }
    return res;
}

template <class T>
void check_arith(const std::vector<T>& xs) {
    for (T x : xs) {
        for (T y : xs) {
            check(saturating_add(x, y) == clamp128<T>((i128)x + y), "saturating_add");
            check(saturating_sub(x, y) == clamp128<T>((i128)x - y), "saturating_sub");
            if constexpr (std::is_unsigned_v<T> && sizeof(T) == 8) {
                u128 p = (u128)x * y;
                check(saturating_mul(x, y) == (p > (u128)std::numeric_limits<T>::max() ? std::numeric_limits<T>::max() : (T)p), "saturating_mul");
            } else {
                check(saturating_mul(x, y) == clamp128<T>((i128)x * y), "saturating_mul");
            }
            if (y != 0) check(saturating_div(x, y) == clamp128<T>((i128)x / y), "saturating_div");
            static_assert(std::is_same_v<decltype(saturating_add(x, y)), T>);
        }
    }
}

template <class R, class T>
void check_cast(const std::vector<T>& xs) {
    for (T x : xs) check(saturating_cast<R>(x) == clamp128<R>((i128)x), "saturating_cast");
    static_assert(std::is_same_v<decltype(saturating_cast<R>(T())), R>);
}
template <class T, class... Rs>
void check_cast_all(std::mt19937_64& rng) {
    auto xs = samples<T>(rng);
    (check_cast<Rs>(xs), ...);
}

// 整数型以外を渡すと候補から外れる (bool、文字型、浮動小数点数)
template <class T, class = void>
struct can_add : std::false_type {};
template <class T>
struct can_add<T, std::void_t<decltype(saturating_add(std::declval<T>(), std::declval<T>()))>> : std::true_type {};
template <class R, class T, class = void>
struct can_cast : std::false_type {};
template <class R, class T>
struct can_cast<R, T, std::void_t<decltype(saturating_cast<R>(std::declval<T>()))>> : std::true_type {};

static_assert(can_add<int>::value && can_add<unsigned long long>::value && can_add<std::int8_t>::value);
static_assert(!can_add<bool>::value && !can_add<char>::value && !can_add<char32_t>::value && !can_add<double>::value);
static_assert(can_cast<int, long long>::value && !can_cast<bool, int>::value && !can_cast<int, double>::value);

// constexpr の中でも使える
static_assert(saturating_add(100, 2000000000) == 2000000100);
static_assert(saturating_add(2000000000, 2000000000) == std::numeric_limits<int>::max());
static_assert(saturating_sub(0u, 1u) == 0u);
static_assert(saturating_mul(-3000000000LL, 4000000000LL) == std::numeric_limits<long long>::min());
static_assert(saturating_div(std::numeric_limits<int>::min(), -1) == std::numeric_limits<int>::max());
static_assert(saturating_cast<std::uint8_t>(-5) == 0 && saturating_cast<std::uint8_t>(300) == 255);
static_assert(saturating_cast<int>(std::numeric_limits<unsigned long long>::max()) == std::numeric_limits<int>::max());

int main() {
    std::mt19937_64 rng(314);

    // 8 ビットの型は全組
    {
        std::vector<std::int8_t> s;
        std::vector<std::uint8_t> u;
        for (int v = -128; v < 128; v++) s.push_back((std::int8_t)v);
        for (int v = 0; v < 256; v++) u.push_back((std::uint8_t)v);
        check_arith(s);
        check_arith(u);
    }
    check_arith(samples<short>(rng));
    check_arith(samples<unsigned short>(rng));
    check_arith(samples<int>(rng));
    check_arith(samples<unsigned>(rng));
    check_arith(samples<long>(rng));
    check_arith(samples<long long>(rng));
    check_arith(samples<unsigned long long>(rng));

#define CAST_TYPES std::int8_t, std::uint8_t, short, unsigned short, int, unsigned, long long, unsigned long long
    check_cast_all<std::int8_t, CAST_TYPES>(rng);
    check_cast_all<std::uint8_t, CAST_TYPES>(rng);
    check_cast_all<short, CAST_TYPES>(rng);
    check_cast_all<unsigned short, CAST_TYPES>(rng);
    check_cast_all<int, CAST_TYPES>(rng);
    check_cast_all<unsigned, CAST_TYPES>(rng);
    check_cast_all<long long, CAST_TYPES>(rng);
    check_cast_all<unsigned long long, CAST_TYPES>(rng);

    if (ok) std::cout << "Hello World" << std::endl;
}
