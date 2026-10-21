#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// F2Matrix を、GF(2) の演算を渡した Matrix や、x をすべて試す愚直な実装とランダムに比べる
// 64 列をまたぐ大きさ (65 列など) も試す
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/f2-matrix.hpp"

#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "../../../src/math/matrix.hpp"

// xor と and による体 GF(2)
struct GF2 {
    static int zero() { return 0; }
    static int add(const int& a, const int& b) { return a ^ b; }
    static int neg(const int& a) { return a; }
    static int one() { return 1; }
    static int mul(const int& a, const int& b) { return a & b; }
    static int inv(const int& a) { return a; }
};
using M2 = Matrix<int, GF2>;

bool ok = true;
void check(bool cond, const char* what) {
    if (!cond && ok) std::cerr << "failed: " << what << std::endl;
    if (!cond) ok = false;
}

std::vector<std::vector<int>> random_bits(std::mt19937_64& rng, int n, int m) {
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (auto& row : a)
        for (auto& x : row) x = rng() % 2;
    // ランクが小さい行列も作る (ある行を別の行にそろえる)
    if (n >= 2 && rng() % 2) a[rng() % n] = a[rng() % n];
    return a;
}
bool same(const F2Matrix& A, const M2& B) {
    if (A.n != B.n || A.m != B.m) return false;
    for (long long i = 0; i < A.n; i++)
        for (long long j = 0; j < A.m; j++)
            if (A.get(i, j) != (B[i][j] == 1)) return false;
    return true;
}
std::vector<bool> mul(const std::vector<std::vector<int>>& a, const std::vector<bool>& x) {
    std::vector<bool> y(a.size(), false);
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < x.size(); j++) y[i] = y[i] ^ (a[i][j] && x[j]);
    return y;
}

int main() {
    std::mt19937_64 rng(314);
    // 列数として 64 の前後も試す
    auto gen_size = [&] {
        int t = rng() % 4;
        return t == 0 ? static_cast<int>(rng() % 64 + 60) : static_cast<int>(rng() % 8 + 1);
    };

    // 積・足し算・転置・pow・行列とベクトルの積・rank・det・inv を Matrix<int, GF2> と比べる
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = gen_size(), m = gen_size(), k = gen_size();
        auto a = random_bits(rng, n, m), b = random_bits(rng, m, k), c = random_bits(rng, n, m);
        F2Matrix A(a), B(b), C(c);
        M2 Am(a), Bm(b), Cm(c);
        check(same(A * B, Am * Bm), "積");
        check(same(A + C, M2(a) += Cm), "足し算");
        auto t = A.transpose();
        check(t.n == m && t.m == n, "転置の大きさ");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) check(t.get(j, i) == A.get(i, j), "転置");
        std::vector<bool> x(m);
        for (int j = 0; j < m; j++) x[j] = rng() % 2;
        check(A * x == mul(a, x), "行列とベクトルの積");
        check(A.rank() == Am.rank(), "rank");
        auto sq = random_bits(rng, n, n);
        F2Matrix S(sq);
        M2 Sm(sq);
        check(S.det() == (Sm.det() == 1), "det");
        auto si = S.inv();
        check(si.has_value() == S.det(), "inv があるか");
        if (si) check(S * *si == F2Matrix::identity(n) && *si * S == F2Matrix::identity(n), "inv");
        long long e = rng() % 20;
        check(same(S.pow(e), Sm.pow(e)), "pow");
        // 簡約化: 主成分の列が増えていき、その列の他の成分は 0
        auto [R, piv] = A.reduced_row_echelon();
        check(static_cast<long long>(piv.size()) == A.rank(), "reduced_row_echelon のランク");
        for (size_t i = 0; i < piv.size(); i++) {
            if (i > 0) check(piv[i] > piv[i - 1], "reduced_row_echelon の主成分の列");
            for (int r = 0; r < n; r++) check(R.get(r, piv[i]) == (r == static_cast<int>(i)), "reduced_row_echelon の主成分");
        }
    }

    // solve・kernel: 列が少なければ 2^m 通りの x をすべて試して、解の個数と合うか確かめる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 8 + 1, m = rng() % 10 + 1;
        auto a = random_bits(rng, n, m);
        F2Matrix A(a);
        std::vector<bool> b(n);
        for (int i = 0; i < n; i++) b[i] = rng() % 2;
        long long cnt_b = 0, cnt_0 = 0;
        std::vector<bool> zero(n, false);
        for (long long code = 0; code < (1LL << m); code++) {
            std::vector<bool> x(m);
            for (int j = 0; j < m; j++) x[j] = code >> j & 1;
            auto y = mul(a, x);
            cnt_b += y == b;
            cnt_0 += y == zero;
        }
        long long r = A.rank();
        check(cnt_0 == (1LL << (m - r)), "rank と解の個数");
        auto ker = A.kernel();
        check(static_cast<long long>(ker.size()) == m - r, "kernel の個数");
        for (const auto& v : ker) check(A * v == zero, "kernel は Ax = 0 の解");
        if (!ker.empty()) {
            F2Matrix K(ker.size(), m);
            for (size_t i = 0; i < ker.size(); i++)
                for (int j = 0; j < m; j++) K.set(i, j, ker[i][j]);
            check(K.rank() == static_cast<long long>(ker.size()), "kernel は一次独立");
        }
        auto sol = A.solve(b);
        if (!sol) {
            check(cnt_b == 0, "解なし");
        } else {
            check(A * sol->x == b && cnt_b == (1LL << sol->basis.size()), "solve");
            for (const auto& v : sol->basis) check(A * v == zero, "solve の基底");
        }
    }

    // 64 列をまたぐ大きさの solve: 解を作ってから b を決め、解が見つかるか確かめる
    for (int rep = 0; rep < 100 && ok; rep++) {
        int n = rng() % 150 + 1, m = rng() % 150 + 1;
        auto a = random_bits(rng, n, m);
        F2Matrix A(a);
        std::vector<bool> x(m);
        for (int j = 0; j < m; j++) x[j] = rng() % 2;
        auto b = A * x;
        auto sol = A.solve(b);
        check(sol && A * sol->x == b && static_cast<long long>(sol->basis.size()) == m - A.rank(), "大きい solve");
    }

    // 文字列から作る・出力・set
    {
        F2Matrix A(std::vector<std::string>{"110", "011"});
        check(A.get(0, 1) && !A.get(0, 2) && A.get(1, 2), "文字列から作る");
        A.set(0, 0, false);
        std::ostringstream os;
        os << A;
        check(os.str() == "010\n011" && A.to_strings() == std::vector<std::string>{"010", "011"}, "出力");
        check(F2Matrix().n == 0 && F2Matrix(3, 70).rank() == 0, "零行列");
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
