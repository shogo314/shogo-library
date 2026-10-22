#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// convolution と convolution_ll を、素朴な計算とランダムに比べる
// 直接 NTT する法 (998244353 など NTT に向く素数) と、3 つの法の中国剰余定理を使う法 (1e9+7、dynamic_modint、素数でない法) の両方を試す
// 長さは素朴な計算に切り替える境目 (60) をまたぐようにし、同じ配列どうしの畳み込み (変換を 1 回省く) も調べる
// 7340033 は 2^20 までしか直接 NTT できないので、それより長いと中国剰余定理に切り替わる。ランダムな点での値 A(x) B(x) で確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/convolution.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../../src/math/modint.hpp"

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

template <class T>
std::vector<T> naive(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.empty() || b.empty()) return {};
    std::vector<T> c(a.size() + b.size() - 1);
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b.size(); j++) c[i + j] += a[i] * b[j];
    return c;
}

template <class mint>
void test(std::mt19937_64& rng, const char* name) {
    for (int rep = 0; rep < 200 && ok; rep++) {
        int n = rng() % 200, m = rng() % 200;
        std::vector<mint> a(n), b(m);
        for (auto& x : a) x = rng();
        for (auto& x : b) x = rng();
        check(convolution(a, b) == naive(a, b), name);
        check(convolution(a, a) == naive(a, a), name);  // 同じ配列
    }
}

template <class mint>
mint eval(const std::vector<mint>& f, mint x) {
    mint r = 0;
    for (int i = static_cast<int>(f.size()) - 1; i >= 0; i--) r = r * x + f[i];
    return r;
}

int main() {
    std::mt19937_64 rng(314);
    test<modint998244353>(rng, "998244353");
    test<static_modint<469762049>>(rng, "469762049");
    test<static_modint<167772161>>(rng, "167772161");
    test<static_modint<754974721>>(rng, "754974721");
    test<static_modint<7340033>>(rng, "7340033");
    test<modint1000000007>(rng, "1000000007");
    test<static_modint<1000000>>(rng, "素数でない法");
    modint::set_mod(998244353);
    test<modint>(rng, "dynamic_modint 998244353");
    modint::set_mod(1000000007);
    test<modint>(rng, "dynamic_modint 1000000007");

    // 7340033 - 1 = 7 * 2^20 なので、長さ 2^20 を超えると中国剰余定理に切り替わる
    {
        using mint = static_modint<7340033>;
        for (int n : {300000, 600000}) {
            std::vector<mint> a(n), b(n);
            for (auto& x : a) x = rng();
            for (auto& x : b) x = rng();
            auto c = convolution(a, b);
            check(static_cast<int>(c.size()) == 2 * n - 1, "7340033 長さ");
            for (int t = 0; t < 3; t++) {
                mint x = rng();
                check(eval(c, x) == eval(a, x) * eval(b, x), "7340033 長い畳み込み");
            }
        }
    }

    // convolution_ll: 負の値や、結果が 10^18 を超えない範囲の大きな値
    for (int rep = 0; rep < 200 && ok; rep++) {
        int n = rng() % 200, m = rng() % 200;
        long long w = rep % 2 ? 1000 : 100000000;  // 結果の絶対値は 200 * 10^16 = 2 * 10^18 以下
        std::vector<long long> a(n), b(m);
        for (auto& x : a) x = static_cast<long long>(rng() % (2 * w + 1)) - w;
        for (auto& x : b) x = static_cast<long long>(rng() % (2 * w + 1)) - w;
        check(convolution_ll(a, b) == naive(a, b), "convolution_ll");
        check(convolution_ll(a, a) == naive(a, a), "convolution_ll 同じ配列");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
