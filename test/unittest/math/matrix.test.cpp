#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// Matrix の +・-・==・シフト系・col・str・初期化子リスト・代入・走査と、
// OperatorProperty を自分で定義した場合 (GF(2) と、既定の演算を継承したもの) の det と inv を愚直な計算と比較する
// solve・rank・kernel・reduced_row_echelon を、変数の値をすべて試す愚直な実装と比較する (mod 3 と GF(2))
// permanent を、すべての順列の和と比較する (long long・modint・GF(2))
// characteristic_polynomial を、行列式を順列で展開した多項式と比較する (mod 998244353・mod 3)
// det_mod を、順列で展開した行列式と比較する (素数でない mod も)
// modint の積 (64 ビットで足してから mod を取る経路) と pow を、long long での愚直な積と比較する (法が 2^31 に近いものや 1 も)
// 行のリストから作るときの推論ガイドを static_assert で確かめる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/math/matrix.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <type_traits>
#include <vector>

#include "../../../src/math/modint.hpp"

using mint = static_modint<998244353>;

// 推論ガイド: 要素の型は各行の value_type
static_assert(std::is_same_v<decltype(Matrix(std::vector<std::vector<long long>>())), Matrix<long long>>);
static_assert(std::is_same_v<decltype(Matrix(std::vector<std::string>())), Matrix<char>>);
using VV = std::vector<std::vector<long long>>;

// xor と and による体 GF(2)
struct GF2 {
    static int zero() { return 0; }
    static int add(const int& a, const int& b) { return a ^ b; }
    static int neg(const int& a) { return a; }
    static int one() { return 1; }
    static int mul(const int& a, const int& b) { return a & b; }
    static int inv(const int& a) { return a; }  // 0 でない元は 1 だけ
};
// 既定の演算を継承した別の型 (行列式・逆行列は valarray を使わない汎用の経路を通る)
struct ModProp : matrix::OperatorPropertyDefault<mint> {};

VV random_vv(std::mt19937_64& rng, int n, int m, int lo, int hi) {
    VV a(n, std::vector<long long>(m));
    for (auto& row : a)
        for (auto& x : row) x = lo + static_cast<long long>(rng() % (hi - lo + 1));
    return a;
}

// GF(2) の行列式 (愚直なガウスの消去法)
int naive_det_gf2(std::vector<std::vector<int>> a) {
    int n = a.size();
    for (int c = 0, r = 0; c < n; c++) {
        int p = r;
        while (p < n && a[p][c] == 0) p++;
        if (p == n) return 0;
        std::swap(a[p], a[r]);
        for (int i = 0; i < n; i++)
            if (i != r && a[i][c])
                for (int j = 0; j < n; j++) a[i][j] ^= a[r][j];
        r++;
    }
    return 1;
}

// mod p の行列式 (余因子展開。n は小さいこと)
mint naive_det(const std::vector<std::vector<mint>>& a) {
    int n = a.size();
    if (n == 0) return 1;
    mint res = 0;
    for (int j = 0; j < n; j++) {
        std::vector<std::vector<mint>> b;
        for (int i = 1; i < n; i++) {
            std::vector<mint> row;
            for (int k = 0; k < n; k++)
                if (k != j) row.push_back(a[i][k]);
            b.push_back(row);
        }
        mint t = a[0][j] * naive_det(b);
        res += (j % 2 == 0) ? t : -t;
    }
    return res;
}

// 連立一次方程式: p^m 通りの x をすべて試して、解の集合と solve・rank・kernel の結果が合うか確かめる
// T は mod p の要素 (P は演算)。to_t は整数から要素を作る
template <typename T, typename P, typename ToT>
bool check_linear(std::mt19937_64& rng, int p, ToT to_t) {
    for (int rep = 0; rep < 500; rep++) {
        int n = rng() % 5 + 1, m = rng() % 5 + 1;
        std::vector<std::vector<T>> a(n, std::vector<T>(m));
        for (auto& row : a)
            for (auto& x : row) x = to_t(rng() % p);
        // ランクが小さい行列も作る (ある行を別の行の定数倍にする)
        if (n >= 2 && rng() % 2) {
            int i = rng() % n, j = rng() % n;
            T c = to_t(rng() % p);
            for (int k = 0; k < m; k++) a[i][k] = P::mul(c, a[j][k]);
        }
        std::vector<T> b(n);
        for (auto& x : b) x = to_t(rng() % p);
        Matrix<T, P> A(a);
        auto apply = [&](const std::vector<T>& x) {
            std::vector<T> y(n, P::zero());
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) y[i] = P::add(y[i], P::mul(a[i][j], x[j]));
            return y;
        };
        // すべての x を試して、Ax = b と Ax = 0 の解を数える
        long long total = 1;
        for (int j = 0; j < m; j++) total *= p;
        long long cnt_b = 0, cnt_0 = 0;
        std::vector<T> zero(n, P::zero());
        for (long long code = 0; code < total; code++) {
            std::vector<T> x(m);
            long long c = code;
            for (int j = 0; j < m; j++) x[j] = to_t(c % p), c /= p;
            auto y = apply(x);
            cnt_b += y == b;
            cnt_0 += y == zero;
        }
        // rank: Ax = 0 の解は p^(m - rank) 個
        long long r = A.rank(), pw = 1;
        for (int j = 0; j < m - r; j++) pw *= p;
        if (pw != cnt_0) return false;
        // kernel: m - rank 個で、どれも Ax = 0 を満たし、一次独立
        auto ker = A.kernel();
        if (static_cast<long long>(ker.size()) != m - r) return false;
        for (const auto& v : ker)
            if (apply(v) != zero) return false;
        if (!ker.empty() && Matrix<T, P>(ker).rank() != static_cast<long long>(ker.size())) return false;
        // solve: 解がなければ nullopt、あれば特殊解が解で、基底の個数から解の個数が合う
        auto sol = A.solve(b);
        if (!sol) {
            if (cnt_b != 0) return false;
        } else {
            if (apply(sol->x) != b || sol->basis.size() != ker.size()) return false;
            if (cnt_b != pw) return false;
            for (const auto& v : sol->basis)
                if (apply(v) != zero) return false;
        }
        // reduced_row_echelon: 主成分は 1 で、その列の他の成分は 0。主成分の列は増えていく
        auto [R, piv] = A.reduced_row_echelon();
        if (static_cast<long long>(piv.size()) != r) return false;
        for (int i = 0; i < r; i++) {
            if (i > 0 && piv[i] <= piv[i - 1]) return false;
            for (int k = 0; k < n; k++)
                if (R[k][piv[i]] != (k == i ? P::one() : P::zero())) return false;
        }
    }
    return true;
}

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    // 初期化子リスト・代入・走査・==
    {
        Matrix<long long> A({{1, 2, 3}, {4, 5, 6}});
        if (A.n != 2 || A.m != 3 || A[1][2] != 6 || A.size() != 2) ok = false;
        long long s = 0;
        for (auto& row : A)
            for (auto& x : row) s += x, x *= 2;  // 書き換えもできる
        const Matrix<long long>& C = A;
        long long s2 = 0;
        for (const auto& row : C)
            for (long long x : row) s2 += x;
        if (s != 21 || s2 != 42) ok = false;
        Matrix<long long> B(1, 1);
        B = VV{{2, 4, 6}, {8, 10, 12}};
        if (B.n != 2 || B.m != 3) ok = false;
        if (!(A == B) || A != B) ok = false;
        B[0][0] = 0;
        if (A == B || !(A != B)) ok = false;
        Matrix<long long> Z(2, 3, 7);
        if (Z[1][2] != 7) ok = false;
    }

    for (int rep = 0; rep < 300; rep++) {
        int n = rng() % 5 + 1, m = rng() % 5 + 1;
        VV a = random_vv(rng, n, m, -100, 100), b = random_vv(rng, n, m, -100, 100);
        Matrix<long long> A(a), B(b);
        // + と -
        Matrix<long long> S = A + B, D = A - B, S2 = A, D2 = A;
        S2 += B;
        D2 -= B;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (S[i][j] != a[i][j] + b[i][j] || S2[i][j] != S[i][j]) ok = false;
                if (D[i][j] != a[i][j] - b[i][j] || D2[i][j] != D[i][j]) ok = false;
            }
        // shift: (i, j) を ((i + dy) mod n, (j + dx) mod m) に移す
        int dy = static_cast<int>(rng() % 21) - 10, dx = static_cast<int>(rng() % 21) - 10;
        Matrix<long long> T = A.shift(dy, dx);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (T[((i + dy) % n + n) % n][((j + dx) % m + m) % m] != a[i][j]) ok = false;
        int k = rng() % 12;
        if (A.shift_r(k) != A.shift(0, k) || A.shift_l(k) != A.shift(0, -k)) ok = false;
        if (A.shift_d(k) != A.shift(k, 0) || A.shift_u(k) != A.shift(-k, 0)) ok = false;
        // 左右・上下に逆向きにずらすと戻る
        if (A.shift_r(k).shift_l(k) != A || A.shift_d(k).shift_u(k) != A) ok = false;
        // col
        int j0 = rng() % m;
        std::vector<long long> col = A.col(j0);
        if (static_cast<int>(col.size()) != n) ok = false;
        for (int i = 0; i < n; i++)
            if (col[i] != a[i][j0]) ok = false;
    }
    // str と vstr (文字のグリッド)
    {
        std::vector<std::string> g = {"abc", "def"};
        Matrix<char> G(g);
        if (G.str(0) != "abc" || G.str(1) != "def" || G.vstr() != g) ok = false;
        if (G.shift_r(1).str(0) != "cab" || G.shift_d(1).str(0) != "def") ok = false;
        std::vector<char> c = G.col(2);
        if (c != std::vector<char>{'c', 'f'}) ok = false;
    }
    if (!ok) std::cerr << "basic" << std::endl;

    // GF(2): 行列式と逆行列
    for (int rep = 0; rep < 500; rep++) {
        int n = rng() % 7 + 1;
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        for (auto& row : a)
            for (auto& x : row) x = rng() % 2;
        Matrix<int, GF2> A(a);
        int d = A.det();
        if (d != naive_det_gf2(a)) ok = false, std::cerr << "gf2 det" << std::endl;
        auto Ai_opt = A.inv();
        if (Ai_opt.has_value() != (d == 1)) ok = false, std::cerr << "gf2 inv nullopt" << std::endl;
        if (d == 1 && Ai_opt) {
            Matrix<int, GF2> Ai = *Ai_opt;
            Matrix<int, GF2> P = A * Ai, Q = Ai * A;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (P[i][j] != (i == j ? 1 : 0) || Q[i][j] != (i == j ? 1 : 0)) ok = false;
                    // 掛け算も愚直に確かめる
                    int s = 0;
                    for (int t = 0; t < n; t++) s ^= a[i][t] & Ai[t][j];
                    if (s != (i == j ? 1 : 0)) ok = false;
                }
        }
    }
    if (!ok) std::cerr << "gf2" << std::endl;

    // mod p: 既定の経路 (valarray) と、OperatorProperty を継承した汎用の経路の結果が一致し、余因子展開とも一致する
    for (int rep = 0; rep < 300; rep++) {
        int n = rng() % 6 + 1;
        std::vector<std::vector<mint>> a(n, std::vector<mint>(n));
        bool small = rng() % 2;
        for (auto& row : a)
            for (auto& x : row) x = small ? static_cast<long long>(rng() % 3) : static_cast<long long>(rng() % 998244353);
        Matrix<mint> A(a);
        Matrix<mint, ModProp> B(a);
        mint e = naive_det(a);
        if (A.det() != e || B.det() != e) ok = false, std::cerr << "mod det" << std::endl;
        auto Ai_opt = A.inv();
        auto Bi_opt = B.inv();
        if (Ai_opt.has_value() != (e != 0) || Bi_opt.has_value() != (e != 0)) ok = false, std::cerr << "mod inv nullopt" << std::endl;
        if (e != 0 && Ai_opt && Bi_opt) {
            Matrix<mint> Ai = *Ai_opt;
            Matrix<mint, ModProp> Bi = *Bi_opt;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (Ai[i][j] != Bi[i][j]) ok = false;
                    mint s = 0;
                    for (int t = 0; t < n; t++) s += a[i][t] * Bi[t][j];
                    if (s != (i == j ? 1 : 0)) ok = false;
                }
        }
    }
    if (!ok) std::cerr << "mod" << std::endl;

    // 正則でない行列の inv は nullopt (浮動小数点、0 x 0 は単位行列)
    {
        if (Matrix<double>({{1., 2.}, {2., 4.}}).inv()) ok = false, std::cerr << "inv singular double" << std::endl;
        auto di = Matrix<double>({{2., 0.}, {0., 4.}}).inv();
        if (!di || std::abs((*di)[0][0] - 0.5) > 1e-12 || std::abs((*di)[1][1] - 0.25) > 1e-12) ok = false, std::cerr << "inv double" << std::endl;
        if (Matrix<mint>({{0, 0}, {0, 0}}).inv()) ok = false, std::cerr << "inv zero" << std::endl;
        auto ei = Matrix<mint>(0, 0).inv();
        if (!ei || ei->size() != 0) ok = false, std::cerr << "inv empty" << std::endl;
    }

    // 連立一次方程式 (mod 3 と GF(2))
    using mint3 = static_modint<3>;
    if (!check_linear<mint3, matrix::OperatorPropertyDefault<mint3>>(rng, 3, [](long long x) { return mint3(x); })) ok = false, std::cerr << "linear mod 3" << std::endl;
    if (!check_linear<int, GF2>(rng, 2, [](long long x) { return static_cast<int>(x); })) ok = false, std::cerr << "linear GF(2)" << std::endl;
    // 0 行の方程式や、列のない行列
    {
        Matrix<mint> A(2, 3);
        auto sol = A.solve({0, 0});
        if (!sol || sol->basis.size() != 3 || A.rank() != 0) ok = false;
        if (A.solve({1, 0})) ok = false;
    }

    // パーマネント
    for (int rep = 0; rep < 300 && ok; rep++) {
        int n = rng() % 8;
        VV a(n, std::vector<long long>(n));
        std::vector<std::vector<mint>> am(n, std::vector<mint>(n));
        std::vector<std::vector<int>> a2(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = static_cast<long long>(rng() % 11) - 5;
                am[i][j] = rng();
                a2[i][j] = rng() % 2;
            }
        }
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 0);
        long long expect = 0;
        mint expect_m = 0;
        int expect_2 = 0;
        do {
            long long p = 1;
            mint pm = 1;
            int p2 = 1;
            for (int i = 0; i < n; i++) p *= a[i][perm[i]], pm *= am[i][perm[i]], p2 &= a2[i][perm[i]];
            expect += p, expect_m += pm, expect_2 ^= p2;
        } while (std::next_permutation(perm.begin(), perm.end()));
        if (Matrix<long long>(a).permanent() != expect) ok = false, std::cerr << "permanent long long" << std::endl;
        if (Matrix<mint>(am).permanent() != expect_m) ok = false, std::cerr << "permanent modint" << std::endl;
        if (Matrix<int, GF2>(a2).permanent() != expect_2) ok = false, std::cerr << "permanent GF(2)" << std::endl;
    }

    // characteristic_polynomial: det(xI - A) を、すべての順列について Π (x δ - a) の多項式を足して求めたものと比べる
    // mod 3 では 0 が多く出るので、ヘッセンベルク化で軸を入れ替える場合や、副対角が 0 になる場合も通る
    auto check_charpoly = [&](auto zero_mint, int mod_range, const char* name) {
        using M = decltype(zero_mint);
        for (int rep = 0; rep < 300 && ok; rep++) {
            int n = rng() % 6;
            std::vector<std::vector<M>> a(n, std::vector<M>(n));
            for (auto& row : a)
                for (auto& x : row) x = rng() % mod_range;
            std::vector<M> expect(n + 1, M(0));
            std::vector<int> perm(n);
            std::iota(perm.begin(), perm.end(), 0);
            do {
                // 置換の符号
                int sign = 1;
                for (int i = 0; i < n; i++)
                    for (int j = i + 1; j < n; j++)
                        if (perm[i] > perm[j]) sign = -sign;
                std::vector<M> poly = {M(1)};
                for (int i = 0; i < n; i++) {
                    // (x δ_{i, perm[i]} - a[i][perm[i]]) を掛ける
                    std::vector<M> next(poly.size() + 1, M(0));
                    for (int d = 0; d < static_cast<int>(poly.size()); d++) {
                        if (perm[i] == i) next[d + 1] += poly[d];
                        next[d] -= poly[d] * a[i][perm[i]];
                    }
                    poly = next;
                }
                for (int d = 0; d <= n; d++) expect[d] += sign * poly[d];
            } while (std::next_permutation(perm.begin(), perm.end()));
            if (Matrix<M>(a).characteristic_polynomial() != expect) ok = false, std::cerr << "characteristic_polynomial " << name << std::endl;
        }
    };
    check_charpoly(mint(0), 1000000, "mod 998244353");
    check_charpoly(static_modint<3>(0), 3, "mod 3");

    // det_mod: 順列で展開した行列式を mod で割った余りと比べる。mod は素数でないものも、要素は負の値も含める
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 6;
        long long mod = rng() % 30 + 1;
        std::vector<std::vector<long long>> a(n, std::vector<long long>(n));
        for (auto& row : a)
            for (auto& x : row) x = static_cast<long long>(rng() % 21) - 10;
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 0);
        long long expect = 0;
        do {
            long long p = 1;
            for (int i = 0; i < n; i++) p *= a[i][perm[i]];
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (perm[i] > perm[j]) p = -p;
            expect += p;
        } while (std::next_permutation(perm.begin(), perm.end()));
        expect = (expect % mod + mod) % mod;
        if (Matrix<long long>(a).det_mod(mod) != expect) ok = false, std::cerr << "det_mod" << std::endl;
    }

    // modint の積: 長方形・空の行列・自分自身との積 (A *= A) も試す
    auto check_product = [&](auto zero, const char* name) {
        using M = decltype(zero);
        const unsigned long long mod = M::mod();
        auto naive = [&](const std::vector<std::vector<unsigned long long>>& a, const std::vector<std::vector<unsigned long long>>& b, int p) {
            int n = a.size(), m = b.size();
            std::vector<std::vector<unsigned long long>> c(n, std::vector<unsigned long long>(p));
            for (int i = 0; i < n; i++)
                for (int k = 0; k < m; k++)
                    for (int j = 0; j < p; j++) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
            return c;
        };
        auto to_matrix = [&](const std::vector<std::vector<unsigned long long>>& a, int cols) {
            Matrix<M> A(a.size(), cols);
            for (int i = 0; i < static_cast<int>(a.size()); i++)
                for (int j = 0; j < cols; j++) A[i][j] = M(a[i][j]);
            return A;
        };
        auto same = [&](const Matrix<M>& A, const std::vector<std::vector<unsigned long long>>& c, int cols) {
            if (A.n != static_cast<long long>(c.size()) || A.m != cols) return false;
            for (int i = 0; i < A.n; i++)
                for (int j = 0; j < cols; j++)
                    if (A[i][j].val() != c[i][j]) return false;
            return true;
        };
        auto random_mat = [&](int n, int m) {
            std::vector<std::vector<unsigned long long>> a(n, std::vector<unsigned long long>(m));
            for (auto& row : a)
                for (auto& x : row) x = rng() % 4 == 0 ? mod - 1 : rng() % mod;  // 最大の値を多めに入れてあふれを試す
            return a;
        };
        for (int rep = 0; rep < 300 && ok; rep++) {
            int n = rng() % 8, m = rng() % 60, p = rng() % 8;
            auto a = random_mat(n, m), b = random_mat(m, p);
            if (!same(to_matrix(a, m) * to_matrix(b, p), naive(a, b, p), p)) ok = false, std::cerr << "product " << name << std::endl;
            auto c = random_mat(n, n);
            Matrix<M> C = to_matrix(c, n);
            C *= C;
            if (!same(C, naive(c, c, n), n)) ok = false, std::cerr << "product (A *= A) " << name << std::endl;
            long long e = rng() % 10;
            auto expect = std::vector<std::vector<unsigned long long>>(n, std::vector<unsigned long long>(n));
            for (int i = 0; i < n; i++) expect[i][i] = 1 % mod;
            for (int t = 0; t < e; t++) expect = naive(expect, c, n);
            if (!same(to_matrix(c, n).pow(e), expect, n)) ok = false, std::cerr << "pow " << name << std::endl;
        }
    };
    check_product(mint(0), "mod 998244353");
    check_product(static_modint<1000000007>(0), "mod 1000000007");
    check_product(static_modint<2147483647>(0), "mod 2147483647");
    check_product(static_modint<1>(0), "mod 1");
    check_product(static_modint<2>(0), "mod 2");
    dynamic_modint<0>::set_mod(2000000011);
    check_product(dynamic_modint<0>(0), "mod 2000000011 (dynamic)");

    if (ok) std::cout << "Hello World" << std::endl;
}
