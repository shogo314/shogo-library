#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// binary-search.hpp の整数版を、型の全範囲を含む境界で検証する
// ok < ng と ok > ng の両方で、答え・f に渡す値が ok と ng の間にあること・f の呼び出し回数を確かめる
// あふれないことは -fsanitize=undefined でも確かめた
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/utility/binary-search.hpp"

#include <iostream>
#include <limits>
#include <random>

bool ok = true;

void check(bool cond, const char* what) {
    if (!cond) {
        if (ok) std::cerr << "failed: " << what << std::endl;
        ok = false;
    }
}

// lo <= t < hi として、f(x) = x <= t (ok = lo, ng = hi) と f(x) = x > t (ok = hi, ng = lo) を調べる
template <typename T>
void test(T lo, T hi, T t, const char* what) {
    long long calls = 0;
    bool inside = true;
    T r1 = binary_search(lo, hi, [&](T x) {
        calls++;
        if (!(lo < x && x < hi)) inside = false;
        return x <= t;
    });
    check(r1 == t, what);
    check(inside && calls <= std::numeric_limits<T>::digits + 1, what);
    calls = 0;
    T r2 = binary_search(hi, lo, [&](T x) {
        calls++;
        if (!(lo < x && x < hi)) inside = false;
        return x > t;
    });
    check(r2 == t + 1, what);
    check(inside && calls <= std::numeric_limits<T>::digits + 1, what);
}

// 型の両端と 0 の付近を境界にして調べる
template <typename T>
void test_extreme(const char* what) {
    constexpr T mn = std::numeric_limits<T>::min(), mx = std::numeric_limits<T>::max();
    for (T t : {mn, static_cast<T>(mn + 1), static_cast<T>(mn / 2), static_cast<T>(0), static_cast<T>(1), static_cast<T>(mx / 2), static_cast<T>(mx - 2), static_cast<T>(mx - 1)}) {
        test<T>(mn, mx, t, what);
    }
    if (std::numeric_limits<T>::is_signed) {
        for (T t : {static_cast<T>(-2), static_cast<T>(-1)}) test<T>(mn, mx, t, what);
        test<T>(mn, static_cast<T>(0), static_cast<T>(-1), what);
        test<T>(static_cast<T>(-1), mx, static_cast<T>(0), what);
    }
}

// 差が 1 なら f を呼ばずに ok を返す。差が 2 なら真ん中を 1 回だけ調べる
template <typename T>
void test_small(T a, const char* what) {
    long long calls = 0;
    check(binary_search(a, static_cast<T>(a + 1), [&](T) { return calls++, false; }) == a && calls == 0, what);
    check(binary_search(static_cast<T>(a + 1), a, [&](T) { return calls++, false; }) == static_cast<T>(a + 1) && calls == 0, what);
    T m = static_cast<T>(a + 1), b = static_cast<T>(a + 2);
    check(binary_search(a, b, [&](T x) { return calls++, x != m; }) == a && calls == 1, what);
    check(binary_search(a, b, [&](T x) { return calls++, x == m; }) == m && calls == 2, what);
    check(binary_search(b, a, [&](T x) { return calls++, x != m; }) == b && calls == 3, what);
    check(binary_search(b, a, [&](T x) { return calls++, x == m; }) == m && calls == 4, what);
}

// constexpr で使える
static_assert(binary_search(0, 1000, [](long long m) { return m * m <= 500; }) == 22);
static_assert(binary_search(std::numeric_limits<long long>::max(), std::numeric_limits<long long>::min(), [](long long x) { return x >= 0; }) == 0);

int main() {
    // 通常の境界探索
    check(binary_search(0, 1000, [](long long m) { return m * m <= 500; }) == 22, "sqrt(500)");
    check(binary_search(0, 1000000000, [](int x) { return static_cast<long long>(x) * x <= 1000000000; }) == 31622, "sqrt(1e9)");
    check(binary_search(1000, 0, [](long long m) { return m * m >= 500; }) == 23, "ok > ng");

    // 負数を含む範囲を愚直と比べる
    std::mt19937_64 rng(314);
    for (int rep = 0; rep < 10000; rep++) {
        long long lo = static_cast<long long>(rng() % 2001) - 1000;
        long long hi = lo + static_cast<long long>(rng() % 1000) + 1;
        long long t = lo + static_cast<long long>(rng() % (hi - lo));
        test<long long>(lo, hi, t, "負数を含む long long");
        test<int>(static_cast<int>(lo), static_cast<int>(hi), static_cast<int>(t), "負数を含む int");
    }

    // 型の全範囲
    test_extreme<int>("int の全範囲");
    test_extreme<long long>("long long の全範囲 (LLONG_MIN, LLONG_MAX)");
    test_extreme<unsigned long long>("unsigned long long の全範囲 (0, ULLONG_MAX)");
    test_extreme<unsigned int>("unsigned int の全範囲");
    test_extreme<short>("short の全範囲");

    // 両端の差が 1 または 2
    for (long long a : {std::numeric_limits<long long>::min(), -2LL, -1LL, 0LL, std::numeric_limits<long long>::max() - 2}) test_small<long long>(a, "差が 1, 2 の long long");
    for (int a : {std::numeric_limits<int>::min(), -1, 0, std::numeric_limits<int>::max() - 2}) test_small<int>(a, "差が 1, 2 の int");
    for (unsigned long long a : {0ULL, 1ULL, std::numeric_limits<unsigned long long>::max() - 2}) test_small<unsigned long long>(a, "差が 1, 2 の unsigned long long");

    // 型が違うときは common_type にそろえる
    check(binary_search(0, std::numeric_limits<long long>::max(), [](long long x) { return x <= 3000000000LL; }) == 3000000000LL, "int と long long");
    check(binary_search(0ULL, std::numeric_limits<unsigned long long>::max(), [](unsigned long long x) { return x <= (1ULL << 63); }) == (1ULL << 63), "unsigned long long の上半分");

    if (ok) std::cout << "Hello World" << std::endl;
}
