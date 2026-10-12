#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// infint の演算を、無限大・NaN を分けて __int128 で愚直に計算したものと比較する
// 境界の値 (Max()、Min() とその前後) を含む値の全組で、四則演算・剰余・比較・符号反転を確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "../../src/math/infint.hpp"

// 愚直な値: 種類と、有限のときの値
struct Naive {
    enum Kind { Finite, PlusInf, MinusInf, NaN } kind;
    __int128 v;
};

template <typename T>
struct Checker {
    using I = infint<T>;
    static constexpr __int128 MAXV = std::numeric_limits<T>::max();  // 正の無限大の内部表現
    static constexpr __int128 MINV = std::numeric_limits<T>::min();  // NaN の内部表現
    // 有限の値の範囲は [MINV + 2, MAXV - 1]
    static Naive fin(__int128 x) {
        if (x >= MAXV) return {Naive::PlusInf, 0};
        if (x <= MINV + 1) return {Naive::MinusInf, 0};
        return {Naive::Finite, x};
    }
    static Naive of(const I& a) {
        if (a.isNaN()) return {Naive::NaN, 0};
        if (a.isPlusInf()) return {Naive::PlusInf, 0};
        if (a.isMinusInf()) return {Naive::MinusInf, 0};
        return {Naive::Finite, a.val()};
    }
    static int sign(const Naive& a) {
        if (a.kind == Naive::PlusInf) return 1;
        if (a.kind == Naive::MinusInf) return -1;
        return (a.v > 0) - (a.v < 0);
    }
    static Naive inf_of_sign(int s) { return s > 0 ? Naive{Naive::PlusInf, 0} : Naive{Naive::MinusInf, 0}; }
    static bool same(const Naive& a, const Naive& b) { return a.kind == b.kind && (a.kind != Naive::Finite || a.v == b.v); }

    static Naive add(Naive a, Naive b) {
        if (a.kind == Naive::NaN || b.kind == Naive::NaN) return {Naive::NaN, 0};
        if (a.kind != Naive::Finite && b.kind != Naive::Finite) return a.kind == b.kind ? a : Naive{Naive::NaN, 0};
        if (a.kind != Naive::Finite) return a;
        if (b.kind != Naive::Finite) return b;
        return fin(a.v + b.v);
    }
    static Naive neg(Naive a) {
        if (a.kind == Naive::PlusInf) return {Naive::MinusInf, 0};
        if (a.kind == Naive::MinusInf) return {Naive::PlusInf, 0};
        if (a.kind == Naive::Finite) a.v = -a.v;
        return a;
    }
    static Naive mul(Naive a, Naive b) {
        if (a.kind == Naive::NaN || b.kind == Naive::NaN) return {Naive::NaN, 0};
        if (a.kind != Naive::Finite || b.kind != Naive::Finite) {
            if (sign(a) == 0 || sign(b) == 0) return {Naive::NaN, 0};  // 0 × ∞
            return inf_of_sign(sign(a) * sign(b));
        }
        return fin(a.v * b.v);
    }
    static Naive div(Naive a, Naive b) {
        if (a.kind == Naive::NaN || b.kind == Naive::NaN) return {Naive::NaN, 0};
        if (a.kind != Naive::Finite && b.kind != Naive::Finite) return {Naive::NaN, 0};
        if (sign(b) == 0) return {Naive::NaN, 0};
        if (b.kind != Naive::Finite) return {Naive::Finite, 0};
        if (a.kind != Naive::Finite) return inf_of_sign(sign(a) * sign(b));
        return fin(a.v / b.v);
    }
    static Naive mod(Naive a, Naive b) {
        if (a.kind == Naive::NaN || b.kind == Naive::NaN) return {Naive::NaN, 0};
        if (a.kind != Naive::Finite && b.kind != Naive::Finite) return {Naive::NaN, 0};
        if (sign(b) == 0) return {Naive::NaN, 0};
        if (a.kind != Naive::Finite) return {Naive::NaN, 0};
        if (b.kind != Naive::Finite) return a;
        return fin(a.v % b.v);
    }
    // 比較用の順序 (NaN は呼ばない)
    static __int128 key(const Naive& a) {
        if (a.kind == Naive::PlusInf) return MAXV;
        if (a.kind == Naive::MinusInf) return MINV + 1;
        return a.v;
    }

    static bool run(std::mt19937_64& rng) {
        bool ok = true;
        std::vector<I> vals = {I::PlusInf(), I::MinusInf(), I::NaN(), I::Inf(), I::Max(), I::Min(), I(0), I(1), I(-1), I(2), I(-2), I(3), I(-7)};
        for (__int128 d : {1, 2, 3}) {
            vals.push_back(I(static_cast<T>(MAXV - 1 - d)));
            vals.push_back(I(static_cast<T>(MINV + 2 + d)));
        }
        // 積がちょうど境界になる付近
        for (__int128 s : {(__int128)1 << (std::numeric_limits<T>::digits / 2), MAXV / 2, MAXV / 3}) {
            for (int d = -1; d <= 1; d++) {
                vals.push_back(I(static_cast<T>(s + d)));
                vals.push_back(I(static_cast<T>(-(s + d))));
            }
        }
        for (int i = 0; i < 12; i++) vals.push_back(I(static_cast<T>(rng() % 2000) - 1000));
        for (int i = 0; i < 12; i++) {
            T x = static_cast<T>(rng());
            if (x == std::numeric_limits<T>::min() || x == std::numeric_limits<T>::max() || x == std::numeric_limits<T>::min() + 1) x = 0;
            vals.push_back(I(x));
        }

        // 値の作り方と判定
        if (I::Max().val() != MAXV - 1 || I::Min().val() != MINV + 2) ok = false;
        if (!I::Max().isfinite() || !I::Min().isfinite()) ok = false;
        if (I().val() != 0 || !I().isfinite()) ok = false;
        if (!I::Inf().isPlusInf() || !I::Inf().isInf() || I::MinusInf().isInf() || !I::MinusInf().isMinusInf()) ok = false;
        if (I::NaN().isfinite() || I::PlusInf().isfinite() || I::MinusInf().isfinite()) ok = false;

        for (const I& a : vals) {
            Naive na = of(a);
            if (a.isfinite() != (na.kind == Naive::Finite)) ok = false;
            // 単項の + と -
            if (!same(of(+a), na)) ok = false;
            if (!same(of(-a), neg(na))) ok = false;
            for (const I& b : vals) {
                Naive nb = of(b);
                if (!same(of(a + b), add(na, nb))) ok = false;
                if (!same(of(a - b), add(na, neg(nb)))) ok = false;
                if (!same(of(a * b), mul(na, nb))) ok = false;
                if (!same(of(a / b), div(na, nb))) ok = false;
                if (!same(of(a % b), mod(na, nb))) ok = false;
                // 複合代入も同じ結果
                I c = a;
                c -= b;
                if (!same(of(c), add(na, neg(nb)))) ok = false;
                c = a;
                c *= b;
                if (!same(of(c), mul(na, nb))) ok = false;
                c = a;
                c /= b;
                if (!same(of(c), div(na, nb))) ok = false;
                c = a;
                c %= b;
                if (!same(of(c), mod(na, nb))) ok = false;
                // 比較: NaN を含むと常に false。== と != は内部表現の比較
                bool has_nan = na.kind == Naive::NaN || nb.kind == Naive::NaN;
                __int128 ka = has_nan ? 0 : key(na), kb = has_nan ? 0 : key(nb);
                if ((a < b) != (!has_nan && ka < kb)) ok = false;
                if ((a > b) != (!has_nan && ka > kb)) ok = false;
                if ((a <= b) != (!has_nan && ka <= kb)) ok = false;
                if ((a >= b) != (!has_nan && ka >= kb)) ok = false;
                if ((a == b) != (a.val() == b.val())) ok = false;
                if ((a != b) != (a.val() != b.val())) ok = false;
            }
        }
        return ok;
    }
};

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    if (!Checker<int>::run(rng)) ok = false, std::cerr << "int" << std::endl;
    if (!Checker<long long>::run(rng)) ok = false, std::cerr << "long long" << std::endl;
    if (!Checker<short>::run(rng)) ok = false, std::cerr << "short" << std::endl;

    using I = infint<long long>;
    // 文字列からの構築 (大文字小文字は問わない)
    if (!I("inf").isPlusInf() || !I("INF").isPlusInf() || !I("PlusInf").isPlusInf()) ok = false;
    if (!I("minusinf").isMinusInf() || !I("MinusINF").isMinusInf()) ok = false;
    if (!I("nan").isNaN() || !I("NaN").isNaN()) ok = false;
    if (I("123").val() != 123 || I("-45").val() != -45 || I("0").val() != 0) ok = false;

    // 文字列化と表記の変更
    if (I::Inf().to_string() != "inf" || I::MinusInf().to_string() != "-inf" || I::NaN().to_string() != "nan" || I(-42).to_string() != "-42") ok = false;
    {
        std::ostringstream os;
        os << I::Inf() << ' ' << I(7) << ' ' << I::NaN();
        if (os.str() != "inf 7 nan") ok = false;
    }
    I::set_str_plusinf("INF");
    I::set_str_minusinf("-INF");
    I::set_str_nan("?");
    {
        std::ostringstream os;
        os << I::Inf() << ' ' << I::MinusInf() << ' ' << I::NaN() << ' ' << I(5);
        if (os.str() != "INF -INF ? 5") ok = false;
    }
    I::set_str_plusinf("inf");
    I::set_str_minusinf("-inf");
    I::set_str_nan("nan");
    if (I::Inf().to_string() != "inf") ok = false;

    // repr: コンストラクタにそのまま使える文字列
    if (I::type_str() != "infint<>") ok = false;
    if (I(5).initializer_str() != "{5}" || I(-3).repr() != "infint<>{-3}") ok = false;
    if (I::Inf().repr() != "infint<>{\"plusinf\"}" || I::MinusInf().repr() != "infint<>{\"minusinf\"}" || I::NaN().repr() != "infint<>{\"nan\"}") ok = false;
    // repr の結果から作り直すと同じ値になる
    if (!I("plusinf").isPlusInf() || !I("minusinf").isMinusInf()) ok = false;

    if (ok) std::cout << "Hello World" << std::endl;
}
